void sub_107DC();
void sub_107C0();
void sub_135EB();
void sub_10EF5();
void sub_13326();
void sub_13A39();
void sub_10EF5();
void sub_10EF5();
void sub_1465C();

void sub_10875() { std::cout << "ignore---" << std::endl; }

void sub_10DC5()
{
    WORD _cs = seg000 ;
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    _ASSERT(_bp == 12);                           //call cs:off_10DD3[bp]
    sub_1F325();
}

void sub_109A7()
{
    WORD _cs = seg000 ;
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    _ASSERT(_bp == 12);                           //call cs:off_109B5[bp]
    sub_20568();
}
void sub_205ED();

void sub_10A73() // draw status bar health indicator
{
    WORD _cs = seg000 ;
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    _ASSERT(_bp == 12);                           //call cs:off_10A81[bp]
    sub_205ED();
}

void sub_20627();
void sub_2217E();

void sub_205ED()
{
    _push(_ds);                                   //push ds
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _si = 0x0000;                                 //mov si, 0
    _di = memory16(_ds, 0x4259);                  //mov di, word_2C789
    _di += 0x1e00;                                //add di, 1E00h
    _ax = 0x3824;                                 //mov ax, 3824h
    _ds = _ax;                                    //mov ds, ax
    _cx = 0x0140;                                 //mov cx, 140h
    sub_20627();                                  //call sub_20627
    _ds = _pop();                                 //pop ds
    _push(_ds);                                   //push ds
    _si = 0x0000;                                 //mov si, 0
    _di = memory16(_ds, 0x425B);                  //mov di, word_2C78B
    _di += 0x1e00;                                //add di, 1E00h
    _ax = 0x3824;                                 //mov ax, 3824h
    _ds = _ax;                                    //mov ds, ax
    _cx = 0x0140;                                 //mov cx, 140h
    sub_20627();                                  //call sub_20627
    _ax = _pop();                                 //pop ax
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
}

void sub_20627()
{
    _dx = 0x03c4;                                 //mov dx, 3C4h
    _push(_cx);                                   //push cx
    _push(_di);                                   //push di
    _ax = 0x0102;                                 //mov ax, 102h
    _out(_dx, _ax);                               //out dx, ax
    _rep_movsb<MemVideo, MemAuto, DirAuto>();      //rep movsb
    _di = _pop();                                 //pop di
    _cx = _pop();                                 //pop cx
    _push(_cx);                                   //push cx
    _push(_di);                                   //push di
    _ax = 0x0202;                                 //mov ax, 202h
    _out(_dx, _ax);                               //out dx, ax
    _rep_movsb<MemVideo, MemAuto, DirAuto>();      //rep movsb
    _di = _pop();                                 //pop di
    _cx = _pop();                                 //pop cx
    _push(_cx);                                   //push cx
    _push(_di);                                   //push di
    _ax = 0x0402;                                 //mov ax, 402h
    _out(_dx, _ax);                               //out dx, ax
    _rep_movsb<MemVideo, MemAuto, DirAuto>();      //rep movsb
    _di = _pop();                                 //pop di
    _cx = _pop();                                 //pop cx
    _ax = 0x0802;                                 //mov ax, 802h
    _out(_dx, _ax);                               //out dx, ax
    _rep_movsb<MemVideo, MemAuto, DirAuto>();      //rep movsb
    _ax = 0x0f02;                                 //mov ax, 0F02h
    _out(_dx, _ax);                               //out dx, ax
}

void sub_2217E()
{
    _push(_ds);                                   //push ds
    _ax = memory16(_ds, 0x4255);                  //mov ax, seg_2C785
    _es = _ax;                                    //mov es, ax
    _si = 0x0000;                                 //mov si, 0
    _di = 0x3c00;                                 //mov di, 3C00h
    _ax = 0x3824;                                 //mov ax, 3824h
    _ds = _ax;                                    //mov ds, ax
    _cx = 0x0140;                                 //mov cx, 140h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();      //rep movsw
    _ax = _pop();                                 //pop ax
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
}

void sub_24185();
void sub_24130();

void sub_24178()
{
    sub_24185();                                  //call sub_24185
    sub_24130();                                  //call sub_24130
    sub_24185();                                  //call sub_24185
    sub_24130();                                  //call sub_24130
}

void sub_24185()
{
    _push(_ds);                                   //push ds
    _ax = 0xb800;                                 //mov ax, 0B800h
    _es = _ax;                                    //mov es, ax
    _si = 0x0000;                                 //mov si, 0
    _di = memory16(_ds, 0x98BE);                  //mov di, word_31DEE
    _ax = 0x3824;                                 //mov ax, 3824h
    _ds = _ax;                                    //mov ds, ax
    _cx = 0x0008;                                 //mov cx, 8
loc_2419A:                                        //loc_2419A:
    _push(_cx);                                   //push cx
    _cx = 0x50;                                   //mov cx, 50h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();      //rep movsw
    _di += 0x1f60;
    _flags.sign = (short)(_di) < 0;      //add di, 1F60h
    if (_flags.sign)                              //jns short loc_241AA
      goto loc_241AA;
    _di -= 0x7f60;                                //sub di, 7F60h
loc_241AA:                                        //loc_241AA:
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_2419A
      goto loc_2419A;
    _ax = _pop();                                 //pop ax
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
}

void sub_24130()
{
    _push(_ax);                                   //push ax
    _push(_bx);                                   //push bx
    _ax = 0x0583;                                 //mov ax, 583h
    _bx = memory16(_ds, 0x4255);                  //mov bx, seg_2C785
    _xchg(_bh, _bl);                              //xchg bh, bl
    memory16(_ds, 0x4255) = _bx;                  //mov seg_2C785, bx
    _interrupt(0x10);                             //int 10h
    _bx = _pop();                                 //pop bx
    _ax = _pop();                                 //pop ax
}

void sub_116A9() // draw score
{
    sub_10E6F();                                  //call sub_10E6F
    memory16(_ds, 0x8E7A) = memory16(_ds, 0x8E7A) ^ 1;
    sub_10E6F();                                  //call sub_10E6F
    memory16(_ds, 0x8E7A) = memory16(_ds, 0x8E7A) ^ 1;
}

void sub_208DC();

void sub_10E6F()
{
    WORD _cs = seg000 ;
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    _ASSERT(_bp == 12);                           //call cs:off_10E7D[bp]
    sub_208DC();
}

void sub_208DC()
{
    WORD _cs = seg001 ;
    _di = 0x1e03;                                 //mov di, 1E03h
    if (memory16(_ds, 0x8E7A) == 0)               //jz short loc_208E9
      goto loc_208E9;
    _di = 0x1e1e;                                 //mov di, 1E1Eh
loc_208E9:                                        //loc_208E9:
    _si = 0x0500;                                 //mov si, 500h
    _cx = 0x0007;                                 //mov cx, 7
loc_208EF:                                        //loc_208EF:
    _al = _al ^ _al;                              //xor al, al
    sub_20919();                                  //call near ptr sub_20919
    _di += 1;                                     //inc di
    if (--_cx)                                    //loop loc_208EF
      goto loc_208EF;
}

void sub_116BA();
void sub_10762();
void sub_1077C();
void sub_1078E();
void sub_10BA5();
void sub_10E91();
void sub_11022();
void sub_12BCC();
void sub_135EB();

void sub_116BA() // draw health - overflow!
{
    WORD _cs = seg000 ;
    _si = 0x8fb2;                                 //mov si, 8FB2h
    sub_10762();                                  //call sub_10762
    _sync();
    _si = 0x8ffe;                                 //mov si, 8FFEh
    sub_10762();                                  //call sub_10762
    _sync();
    _si = 0x904a;                                 //mov si, 904Ah
    sub_10762();                                  //call sub_10762
    _sync();
    _si = 0x9096;                                 //mov si, 9096h
    sub_10762();                                  //call sub_10762
    _sync();
    _si = 0x90e2;                                 //mov si, 90E2h
    sub_10762();                                  //call sub_10762
    _sync();
    _si = 0x9f00;                                 //mov si, 9F00h
    _di = 0x8fb2;                                 //mov di, 8FB2h
    sub_1077C();                                  //call sub_1077C
    memory16(_ds, _si) = 8;                       //mov word ptr [si], 8
    memory16(_ds, _si + 2) = 17169;               //mov word ptr [si+2], 4311h
    memory16(_ds, _si + 4) = 2131;                //mov word ptr [si+4], 853h
    memory16(_ds, _si + 12) = 1914;               //mov word ptr [si+0Ch], 77Ah
    memory16(_ds, _si + 14) = 0;                  //mov word ptr [si+0Eh], 0
    memory16(_ds, _si + 18) = 0xa0;               //mov word ptr [si+12h], 0A0h
    memory16(_ds, _si + 22) = 0xb0;               //mov word ptr [si+16h], 0B0h
    _bx = 0x3292;                                 //mov bx, 3292h
    _cx = 0x0004;                                 //mov cx, 4
loc_11709:                                        //loc_11709:
    _sync();
    sub_11022();                                  //call sub_11022
    _sync();
    _di = 0x8fb2;                                 //mov di, 8FB2h
    sub_1078E();                                  //call sub_1078E
    _sync();
    memory16(_ds, _si) = 0xc4;                    //mov word ptr [si], 0C4h
    memory16(_ds, _si + 2) = 18265;               //mov word ptr [si+2], 4759h
    memory16(_ds, _si + 4) = 1889;                //mov word ptr [si+4], 761h
    _di = memory16(_ds, _bx);                     //mov di, [bx]
    _bx += 0x0002;                                //add bx, 2
    _ax = memory16(_cs, _di);                     //mov ax, cs:[di]
    memory16(_ds, _si + 12) = _ax;                //mov [si+0Ch], ax
    _ax = memory16(_cs, _di + 2);                 //mov ax, cs:[di+2]
    memory16(_ds, _si + 14) = _ax;                //mov [si+0Eh], ax
    _di += 0x0004;                                //add di, 4
    memory16(_ds, _si + 16) = _di;                //mov [si+10h], di
    memory16(_ds, _si + 18) = 0xa0;               //mov word ptr [si+12h], 0A0h
    memory16(_ds, _si + 22) = 0xb0;               //mov word ptr [si+16h], 0B0h
    _ax = _cx;                                    //mov ax, cx
    _ax -= 1;                                     //dec ax
    memory16(_ds, _si + 34) = _ax;                //mov [si+22h], ax
    if (--_cx)                                    //loop loc_11709
      goto loc_11709;
    memory16(_ds, 0x9134) = 0;                    //mov word_31664, 0
    memory16(_ds, 0x914C) = 0;                    //mov word_3167C, 0
    memory16(_ds, 0x9138) = 0;                    //mov word_31668, 0
    memory16(_ds, 0x913C) = 0;                    //mov word_3166C, 0
    memory16(_ds, 0x9140) = 0;                    //mov word_31670, 0
    memory16(_ds, 0x9144) = 0;                    //mov word_31674, 0
    memory16(_ds, 0x9148) = 0;                    //mov word_31678, 0
    sub_12BCC();                                  //call sub_12BCC
    _cx = 0x0e;                                   //mov cx, 0Eh
    _di = 0x916a;                                 //mov di, 916Ah
    _ax = _ax ^ _ax;                              //xor ax, ax
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    sub_135EB();                                  //call sub_135EB
    memory16(_ds, 0x912E) = 8;                    //mov word_3165E, 8
    memory16(_ds, 0x9130) = 8;                    //mov word_31660, 8
    memory16(_ds, 0x9132) = 1;                    //mov word_31662, 1
    memory16(_ds, 0x8E7E) = 0;                    //mov word_313AE, 0
    memory16(_ds, 0x9150) = 0;                    //mov word_31680, 0
    memory16(_ds, 0x8E80) = 0;                    //mov word_313B0, 0
    memory16(_ds, 0x8E82) = 0;                    //mov word_313B2, 0
    memory16(_ds, 0x9152) = 0;                    //mov word_31682, 0
    memory16(_ds, 0x9154) = 0;                    //mov word_31684, 0
    memory16(_ds, 0x9156) = 0;                    //mov word_31686, 0
    memory16(_ds, 0x9158) = 0;                    //mov word_31688, 0
    memory16(_ds, 0x915E) = 0;                    //mov word_3168E, 0
    memory16(_ds, 0x9160) = 0;                    //mov word_31690, 0
    memory16(_ds, 0x8E84) = 0;                    //mov word_313B4, 0
    memory16(_ds, 0x9162) = 0;                    //mov word_31692, 0
    _di = 0x921c;                                 //mov di, 921Ch
    _cx = 0x0007;                                 //mov cx, 7
    _al = _al ^ _al;                              //xor al, al
    _rep_stosb<MemAuto, DirAuto>();               //rep stosb
    memory16(_ds, 0x9164) = 0;                    //mov word_31694, 0
    memory16(_ds, 0x9186) = 0x27;                 //mov word_316B6, 27h
    memory16(_ds, 0x9188) = 0;                    //mov word_316B8, 0
    memory(_ds, 0x9223) = 0;                      //mov byte_31753, 0
    memory(_ds, 0x9224) = 0;                      //mov byte_31754, 0
    memory16(_ds, 0x918A) = 0xff;                 //mov word_316BA, 0FFh
    memory16(_ds, 0x918C) = 1;                    //mov word_316BC, 1
    memory(_ds, 0x9225) = 0;                      //mov byte_31755, 0
    memory16(_ds, 0x91B0) = 3;                    //mov word_316E0, 3
    _sync();
   sub_10E91();                                  //call sub_10E91
    _sync();
    memory(_ds, 0x8FAF) = 0xff;                   //mov byte_314DF, 0FFh
    sub_10BA5();                                  //call sub_10BA5
    _sync();
}

void sub_10762()
{
    memory16(_ds, _si) = 0;                       //mov word ptr [si], 0
    memory16(_ds, _si + 10) = _si;                //mov [si+0Ah], si
    memory16(_ds, _si + 8) = _si;                 //mov [si+8], si
    memory16(_ds, _si + 2) = 1889;                //mov word ptr [si+2], 761h
    memory16(_ds, _si + 4) = 1889;                //mov word ptr [si+4], 761h
    memory16(_ds, _si + 6) = 1889;                //mov word ptr [si+6], 761h
}

void sub_1077C()
{
    _push(_bx);                                   //push bx
    _bx = memory16(_ds, _di + 10);                //mov bx, [di+0Ah]
    memory16(_ds, _di + 10) = _si;                //mov [di+0Ah], si
    memory16(_ds, _si + 10) = _bx;                //mov [si+0Ah], bx
    memory16(_ds, _si + 8) = _di;                 //mov [si+8], di
    memory16(_ds, _bx + 8) = _si;                 //mov [bx+8], si
    _bx = _pop();                                 //pop bx
}

void sub_1078E()
{
    _push(_bx);                                   //push bx
    _bx = memory16(_ds, _di + 8);                 //mov bx, [di+8]
    memory16(_ds, _di + 8) = _si;                 //mov [di+8], si
    memory16(_ds, _si + 8) = _bx;                 //mov [si+8], bx
    memory16(_ds, _si + 10) = _di;                //mov [si+0Ah], di
    memory16(_ds, _bx + 10) = _si;                //mov [bx+0Ah], si
    _bx = _pop();                                 //pop bx
}


void sub_11022()
{
    if (memory16(_ds, 0x8E7C) == 0)               //jz short loc_11041
      goto loc_11041;
    _si = memory16(_ds, 0x8E7C);                  //mov si, word_313AC
    _push(memory16(_ds, _si + 8));                //push word ptr [si+8]
    memory16(_ds, 0x8E7C) = _pop();               //pop word_313AC
loc_11034:                                        //loc_11034:
    memory(_ds, _si + 38) = 0;                    //mov byte ptr [si+26h], 0
    memory(_ds, _si + 74) = 0;                    //mov byte ptr [si+4Ah], 0
    memory(_ds, _si + 75) = 0;                    //mov byte ptr [si+4Bh], 0
    return;                                       //retn
loc_11041:                                        //loc_11041:
    _si = 0x9096;                                 //mov si, 9096h
loc_11044:                                        //loc_11044:
    _si = memory16(_ds, _si + 10);                //mov si, [si+0Ah]
    if (memory16(_ds, _si) == 4)                  //jz short loc_1106D
      goto loc_1106D;
    if (memory16(_ds, _si) == 0x0c)               //jz short loc_1106D
      goto loc_1106D;
    if (memory16(_ds, _si) == 0x10)               //jz short loc_1106D
      goto loc_1106D;
    if (memory16(_ds, _si) != 0)                  //jnz short loc_11044
      goto loc_11044;
    _si = memory16(_ds, 0x90A0);                  //mov si, word_315D0
    if (memory16(_ds, _si) != 0)                  //jnz short loc_1106D
      goto loc_1106D;
    _si = memory16(_ds, 0x90EC);                  //mov si, word_3161C
    if (memory16(_ds, _si) == 0)                  //jz short loc_11072
      goto loc_11072;
loc_1106D:                                        //loc_1106D:
    sub_107DC();                                  //call sub_107DC
    goto loc_11034;                               //jmp short loc_11034
loc_11072:                                        //loc_11072:
    _si = memory16(_ds, 0x9054);                  //mov si, word_31584
loc_11076:                                        //loc_11076:
    if ((short)memory16(_ds, _si) >= (short)0xc8) //jge short loc_1106D
      goto loc_1106D;
    if (memory16(_ds, _si) == 4)                  //jz short loc_1106D
      goto loc_1106D;
    _si = memory16(_ds, _si + 10);                //mov si, [si+0Ah]
    if (memory16(_ds, _si) != 0)                  //jnz short loc_11076
      goto loc_11076;
    _si = memory16(_ds, 0x9054);                  //mov si, word_31584
    goto loc_1106D;                               //jmp short loc_1106D
}

void sub_12BCC()
{
    if (memory16(_ds, 0x9134) == 0)               //jz short loc_12BDC
      goto loc_12BDC;
    _push(_si);                                   //push si
    _si = memory16(_ds, 0x9136);                  //mov si, word_31666
    sub_107C0();                                  //call sub_107C0
    _si = _pop();                                 //pop si
loc_12BDC:                                        //loc_12BDC:
    memory16(_ds, 0x9134) = 0x94;                 //mov word_31664, 94h
    _push(_si);                                   //push si
    sub_11022();                                  //call sub_11022
    _di = 0x8ffe;                                 //mov di, 8FFEh
    sub_1077C();                                  //call sub_1077C
    memory16(_ds, 0x9136) = _si;                  //mov word_31666, si
    memory16(_ds, _si) = 0x94;                    //mov word ptr [si], 94h
    memory16(_ds, _si + 2) = 14303;               //mov word ptr [si+2], 37DFh
    memory16(_ds, _si + 6) = 37172;               //mov word ptr [si+6], 9134h
    memory16(_ds, _si + 4) = 1889;                //mov word ptr [si+4], 761h
    memory16(_ds, _si + 52) = 0;                  //mov word ptr [si+34h], 0
    memory16(_ds, _si + 36) = 2;                  //mov word ptr [si+24h], 2
    memory16(_ds, _si + 54) = 1;                  //mov word ptr [si+36h], 1
    memory16(_ds, _si + 72) = 0xffff;             //mov word ptr [si+48h], 0FFFFh
    _di = _si;                                    //mov di, si
    _si = _pop();                                 //pop si
    memory16(_ds, 0x9130) = 8;                    //mov word_31660, 8
}

void sub_135EB()
{
    if (memory16(_ds, 0x9162) != 0)               //jnz short locret_13614
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

void sub_107DC()
{
    _push(_di);                                   //push di
    _push(_bx);                                   //push bx
    _di = memory16(_ds, _si + 8);                 //mov di, [si+8]
    _bx = memory16(_ds, _si + 10);                //mov bx, [si+0Ah]
    memory16(_ds, _di + 10) = _bx;                //mov [di+0Ah], bx
    memory16(_ds, _bx + 8) = _di;                 //mov [bx+8], di
    _bx = _pop();                                 //pop bx
    _di = _pop();                                 //pop di
}

void sub_107C0()
{
    memory16(_ds, _si) = 4;                       //mov word ptr [si], 4
    memory16(_ds, _si + 2) = 3883;                //mov word ptr [si+2], 0F2Bh
    memory16(_ds, _si + 4) = 1889;                //mov word ptr [si+4], 761h
    memory16(_ds, _si + 6) = 1889;                //mov word ptr [si+6], 761h
    memory(_ds, _si + 38) = 0;                    //mov byte ptr [si+26h], 0
    memory(_ds, _si + 74) = 0;                    //mov byte ptr [si+4Ah], 0
}

void sub_208F9();

void sub_10E91()
{
    WORD _cs = seg000 ;
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    _ASSERT(_bp == 12);                           //call cs:off_10E9F[bp]
    sub_208F9();
}

void sub_208F9()
{
    WORD _cs = seg001 ;
    _ax = memory16(_ds, 0x918A);                  //mov ax, word_316BA
    if ((short)_ax <= (short)0x0009)              //jle short loc_20904
      goto loc_20904;
    _ax = 0x0009;                                 //mov ax, 9
loc_20904:                                        //loc_20904:
    _si = 0x0640;                                 //mov si, 640h
    _di = 0x1e39;                                 //mov di, 1E39h
    if (memory16(_ds, 0x8E7A) == 0)               //jz short loc_20914
      goto loc_20914;
    _di = 0x1e3e;                                 //mov di, 1E3Eh
loc_20914:                                        //loc_20914:
    sub_20919();                                  //call near ptr sub_20919
}

void sub_1373D();
void sub_11689();

void sub_1373D()
{
    _si = memory16(_ds, 0x9054);                  //mov si, word_31584
    _cx = _cx ^ _cx;                              //xor cx, cx
loc_13743:                                        //loc_13743:
    _ax = memory16(_ds, _si);                     //mov ax, [si]
    if (!(_ax & _ax))                             //jz short loc_1375B
      goto loc_1375B;
    if (_ax == 0x50)                              //jz short loc_13754
      goto loc_13754;
    if (_ax == 0x54)                              //jz short loc_13754
      goto loc_13754;
    _cx += 1;                                     //inc cx
loc_13754:                                        //loc_13754:
    sub_11689();                                  //call sub_11689
    _si = _di;                                    //mov si, di
    goto loc_13743;                               //jmp short loc_13743
loc_1375B:                                        //loc_1375B:
    memory16(_ds, 0x8F32) = _cx;                  //mov word_31462, cx
}

void sub_11689()
{
    _di = memory16(_ds, _si + 10);                //mov di, [si+0Ah]
    if (memory(_ds, _si + 38) == 0)               //jz short locret_116A8
      goto locret_116A8;
    _di = memory16(_ds, _si + 68);                //mov di, [si+44h]
loc_11695:                                        //loc_11695:
    _di = memory16(_ds, _di + 10);                //mov di, [di+0Ah]
    if (memory16(_ds, _di) == 0)                  //jz short locret_116A8
      goto locret_116A8;
    if (memory(_ds, _di + 38) == 0)               //jz short locret_116A8
      goto locret_116A8;
    if (_si == memory16(_ds, _di + 68))           //jz short loc_11695
      goto loc_11695;
locret_116A8:                                     //locret_116A8:
    return;
}

void sub_1655B();

void sub_10FF0()
{
    WORD _cs = seg000 ;
    memory16(_ds, 0x8E74) = _bx;                  //mov word_313A4, bx
    _bx = memory16(_ds, 0x991C);                  //mov bx, word_31E4C
    _bx <<= 1;                                    //shl bx, 1
    _push(memory16(_cs, _bx + 4098));             //push word ptr cs:[bx+1002h]
    _bx = memory16(_ds, 0x8E74);                  //mov bx, word_313A4
    
    switch(_pop())
    {
        case 0x655b: sub_1655B(); break;
        default:
            _ASSERT(0);
    }
}

void sub_13682();
void sub_136FC();
void sub_1370B();

void sub_13682()
{
    _si = memory16(_ds, 0x8FBC);                  //mov si, word_314EC
    //std::cout << "sub_13682 temp override===" << std::endl;
    sub_136FC();                                  //call sub_136FC
    _si = memory16(_ds, 0x9054);                  //mov si, word_31584
    sub_136FC();                                  //call sub_136FC
    _si = memory16(_ds, 0x9008);                  //mov si, word_31538
    _al = memory(_ds, 0x8F5B);                    //mov al, byte_3148B
    memory(_ds, 0x8FAE) = _al;                    //mov byte_314DE, al
    memory(_ds, 0x8F5B) = 0;                      //mov byte_3148B, 0
    sub_136FC();                                  //call sub_136FC
    _si = memory16(_ds, 0x90A0);                  //mov si, word_315D0
    sub_136FC();                                  //call sub_136FC
    _si = memory16(_ds, 0x90EC);                  //mov si, word_3161C
    sub_136FC();                                  //call sub_136FC
    _si = memory16(_ds, 0x8FBC);                  //mov si, word_314EC
    sub_1370B();                                  //call sub_1370B
    _si = memory16(_ds, 0x9008);                  //mov si, word_31538
    sub_1370B();                                  //call sub_1370B
    _si = memory16(_ds, 0x9054);                  //mov si, word_31584
    sub_1370B();                                  //call sub_1370B
    _si = memory16(_ds, 0x90A0);                  //mov si, word_315D0
    sub_1370B();                                  //call sub_1370B
    _si = memory16(_ds, 0x90EC);                  //mov si, word_3161C
    sub_1370B();                                  //call sub_1370B
    _si = 0x8e8c;                                 //mov si, 8E8Ch
    _cx = 0x0008;                                 //mov cx, 8
loc_136D9:                                        //loc_136D9:
    _ax = memory16(_ds, _si);                     //mov ax, [si]
    if (!(_ax & _ax))                             //jz short loc_136F6
      goto loc_136F6;
    _di = memory16(_ds, 0x9054);                  //mov di, word_31584
loc_136E3:                                        //loc_136E3:
    if (memory16(_ds, _di) == 0)                  //jz short loc_136F2
      goto loc_136F2;
    if (_ax == memory16(_ds, _di + 54))           //jz short loc_136F6
      goto loc_136F6;
    _di = memory16(_ds, _di + 10);                //mov di, [di+0Ah]
    goto loc_136E3;                               //jmp short loc_136E3
loc_136F2:                                        //loc_136F2:
    memory16(_ds, _si) = 0;                       //mov word ptr [si], 0
loc_136F6:                                        //loc_136F6:
    _si += 0x0004;                                //add si, 4
    if (--_cx)                                    //loop loc_136D9
      goto loc_136D9;
}

void sub_10EF5()
{
    _push(_es);                                   //push es
    _push(_cx);                                   //push cx
    _push(_si);                                   //push si
    _ax = memory16(_ds, _si + 18);                //mov ax, [si+12h]
    _bx = memory16(_ds, _si + 22);                //mov bx, [si+16h]
    _si = memory16(_ds, _si + 12);                //mov si, [si+0Ch]
    _cx = 0x449b;                                 //mov cx, 449Bh
    if (!(_si & 0x0001))                          //jz short loc_10F0E
      goto loc_10F0E;
    _cx = 0x5489;                                 //mov cx, 5489h
    _si -= 1;                                     //dec si
loc_10F0E:                                        //loc_10F0E:
    _es = _cx;                                    //mov es, cx
    _ax = _ax - memory16(_es, _si);               //sub ax, es:[si]
    _bx = _bx - memory16(_es, _si + 2);           //sub bx, es:[si+2]
    _ax <<= 1;                                    //shl ax, 1
    _bx <<= 1;                                    //shl bx, 1
    _ax = _ax + memory16(_es, _si + 4);           //add ax, es:[si+4]
    _bx = _bx + memory16(_es, _si + 6);           //add bx, es:[si+6]
    _sar(_ax, 1);                                 //sar ax, 1
    _sar(_bx, 1);                                 //sar bx, 1
    _si = _pop();                                 //pop si
    _cx = _pop();                                 //pop cx
    _es = _pop();                                 //pop es
}

void sub_13326()
{
    WORD _cs = seg000 ;
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    memory16(_ds, 0x8E8A) = 6;                    //mov word_313BA, 6
    sub_11022();                                  //call sub_11022
    _di = 0x9096;                                 //mov di, 9096h
    sub_1077C();                                  //call sub_1077C
    memory16(_ds, _si) = 0x0c;                    //mov word ptr [si], 0Ch
    memory16(_ds, _si + 2) = 14744;               //mov word ptr [si+2], 3998h
    memory16(_ds, _si + 4) = _dx;                 //mov [si+4], dx
    memory16(_ds, _si + 18) = _ax;                //mov [si+12h], ax
    memory16(_ds, _si + 22) = _bx;                //mov [si+16h], bx
    _ax = memory16(_cs, _bp);                     //mov ax, cs:[bp+0]
    memory16(_ds, _si + 12) = _ax;                //mov [si+0Ch], ax
    _ax = memory16(_cs, _bp + 2);                 //mov ax, cs:[bp+2]
    memory16(_ds, _si + 14) = _ax;                //mov [si+0Eh], ax
    _bp += 0x0004;                                //add bp, 4
    memory16(_ds, _si + 16) = _bp;                //mov [si+10h], bp
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
}

void sub_13AB2();

void sub_13A39()
{
    _push(_di);                                   //push di
    _di = memory16(_ds, _di + 68);                //mov di, [di+44h]
    _bx = _di;                                    //mov bx, di
loc_13A3F:                                        //loc_13A3F:
    memory16(_ds, _bx + 4) = 2233;                //mov word ptr [bx+4], 8B9h
    if (memory16(_ds, _bx + 70) == 0)             //jz short loc_13A4F
      goto loc_13A4F;
    _bx = memory16(_ds, _bx + 70);                //mov bx, [bx+46h]
    goto loc_13A3F;                               //jmp short loc_13A3F
loc_13A4F:                                        //loc_13A4F:
    _flags.carry = memory16(_ds, _di + 36) < _ax; //sub [di+24h], ax
    memory16(_ds, _di + 36) -= _ax;
    if (!_flags.carry && (memory16(_ds, _di + 36) != 0))
      goto loc_13A8C;
    _push(memory16(_ds, _di + 70));               //push word ptr [di+46h]
loc_13A57:                                        //loc_13A57:
    _bx = _pop();                                 //pop bx
    if (!(_bx & _bx))                             //jz short loc_13A89
      goto loc_13A89;
    if ((char)memory(_ds, _bx + 38) < 0 /*CHECK*/)//js short loc_13A7D
      goto loc_13A7D;
    _push(_bx);                                   //push bx
    _push(_si);                                   //push si
    _si = _bx;                                    //mov si, bx
    sub_10EF5();                                  //call sub_10EF5
    _si = _pop();                                 //pop si
    _bp = 0x1230;                                 //mov bp, 1230h
    if (memory(_ds, _di + 39) == 0)               //jz short loc_13A76
      goto loc_13A76;
    _bp = 0x124c;                                 //mov bp, 124Ch
loc_13A76:                                        //loc_13A76:
    _dx = 0x0853;                                 //mov dx, 853h
    sub_13326();                                  //call sub_13326
    _bx = _pop();                                 //pop bx
loc_13A7D:                                        //loc_13A7D:
    _push(memory16(_ds, _bx + 70));               //push word ptr [bx+46h]
    _push(_si);                                   //push si
    _si = _bx;                                    //mov si, bx
    sub_107C0();                                  //call sub_107C0
    _si = _pop();                                 //pop si
    goto loc_13A57;                               //jmp short loc_13A57
loc_13A89:                                        //loc_13A89:
    sub_13AB2();                                  //call sub_13AB2
loc_13A8C:                                        //loc_13A8C:
    _di = _pop();                                 //pop di
}

void sub_13AB2()
{
    WORD _cs = seg000 ;
    _push(_si);                                   //push si
    _si = _di;                                    //mov si, di
    sub_10EF5();                                  //call sub_10EF5
    _si = _pop();                                 //pop si
    _bp = 0x1230;                                 //mov bp, 1230h
    if (memory(_ds, _di + 39) == 0)               //jz short loc_13AC5
      goto loc_13AC5;
    _bp = 0x124c;                                 //mov bp, 124Ch
loc_13AC5:                                        //loc_13AC5:
    _dx = 0x0853;                                 //mov dx, 853h
    sub_13326();                                  //call sub_13326
    _ax = memory16(_ds, _di + 54);                //mov ax, [di+36h]
    if (!(_ax & _ax))                             //jz short loc_13B41
      goto loc_13B41;
    _bx = 0x8e8c;                                 //mov bx, 8E8Ch
    _cx = 0x0008;                                 //mov cx, 8
loc_13AD8:                                        //loc_13AD8:
    if (_ax == memory16(_ds, _bx))                //jz short loc_13AE3
      goto loc_13AE3;
    _bx += 0x0004;                                //add bx, 4
    if (--_cx)                                    //loop loc_13AD8
      goto loc_13AD8;
    goto loc_13B41;                               //jmp short loc_13B41
loc_13AE3:                                        //loc_13AE3:
    memory16(_ds, _bx + 2) -= 1;                  //dec word ptr [bx+2]
    if (memory16(_ds, _bx + 2) != 0)              //jnz short loc_13B41
      goto loc_13B41;
    memory16(_ds, _bx) = 0;                       //mov word ptr [bx], 0
    _push(_si);                                   //push si
    sub_11022();                                  //call sub_11022
    _push(_di);                                   //push di
    _di = 0x9096;                                 //mov di, 9096h
    sub_1077C();                                  //call sub_1077C
    _di = _pop();                                 //pop di
    _bx = 0x11f2;                                 //mov bx, 11F2h
    memory16(_ds, _si) = 0x60;                    //mov word ptr [si], 60h
    if (memory(_ds, _di + 39) == 0)               //jz short loc_13B0C
      goto loc_13B0C;
    _bx = 0x11b4;                                 //mov bx, 11B4h
    memory16(_ds, _si) = 0x18;                    //mov word ptr [si], 18h
loc_13B0C:                                        //loc_13B0C:
    memory16(_ds, _si + 26) = 7;                  //mov word ptr [si+1Ah], 7
    memory16(_ds, _si + 2) = 10463;               //mov word ptr [si+2], 28DFh
    memory16(_ds, _si + 4) = 2131;                //mov word ptr [si+4], 853h
    _ax = memory16(_cs, _bx);                     //mov ax, cs:[bx]
    memory16(_ds, _si + 12) = _ax;                //mov [si+0Ch], ax
    _ax = memory16(_cs, _bx + 2);                 //mov ax, cs:[bx+2]
    memory16(_ds, _si + 14) = _ax;                //mov [si+0Eh], ax
    _bx += 0x0004;                                //add bx, 4
    memory16(_ds, _si + 16) = _bx;                //mov [si+10h], bx
    _ax = memory16(_ds, _di + 18);                //mov ax, [di+12h]
    memory16(_ds, _si + 18) = _ax;                //mov [si+12h], ax
    _ax = memory16(_ds, _di + 22);                //mov ax, [di+16h]
    memory16(_ds, _si + 22) = _ax;                //mov [si+16h], ax
    sub_14191();                                  //call sub_14191
    memory16(_ds, _si + 28) = _ax;                //mov [si+1Ch], ax
    _si = _pop();                                 //pop si
loc_13B41:                                        //loc_13B41:
    _ax = memory16(_ds, _di + 52);                //mov ax, [di+34h]
    _flags.carry = (memory16(_ds, 0x9152) + _ax) >= 0x10000;
    memory16(_ds, 0x9152) += _ax;
    memory16(_ds, 0x9154) = memory16(_ds, 0x9154) + 0 + _flags.carry;;
    _push(_si);                                   //push si
    _si = _di;                                    //mov si, di
    sub_107C0();                                  //call sub_107C0
    _si = _pop();                                 //pop si
}

void sub_14675();
void sub_1472D();

void sub_14675()
{
    if (memory16(_ds, 0x8E80) != 0)               //jnz short loc_14690
      goto loc_14690;
    if (memory(_ds, 0x9224) != 0)                 //jnz short loc_14690
      goto loc_14690;
    if (memory16(_ds, 0x991E) == 0)               //jz short loc_1469B
      goto loc_1469B;
    memory16(_ds, 0x991E) -= 1;                   //dec word_31E4E
    goto loc_1469B;                               //jmp short loc_1469B
loc_14690:                                        //loc_14690:
    if (memory16(_ds, 0x991E) == 0x10)            //jz short loc_1469B
      goto loc_1469B;
    memory16(_ds, 0x991E) += 1;                   //inc word_31E4E
loc_1469B:                                        //loc_1469B:
    if (memory16(_ds, 0x9150) == 0)               //jz short loc_146B6
      goto loc_146B6;
    memory16(_ds, 0x9150) -= 1;                   //dec word_31680
    _dx = 0xdd;                                   //mov dx, 0DDh
    _cx = memory16(_ds, 0x9150);                  //mov cx, word_31680
    _ax = 0x0126;                                 //mov ax, 126h
    _bx = 0x0008;                                 //mov bx, 8
    sub_1465C();                                  //call sub_1465C
loc_146B6:                                        //loc_146B6:
    if (memory16(_ds, 0x8E84) == 0)               //jz short loc_146E4
      goto loc_146E4;
    memory16(_ds, 0x8E84) -= 1;                   //dec word_313B4
    _dx = 0x88;                                   //mov dx, 88h
    _cx = memory16(_ds, 0x8E84);                  //mov cx, word_313B4
    _ax = 0x98;                                   //mov ax, 98h
    _bx = 0x0008;                                 //mov bx, 8
    sub_1465C();                                  //call sub_1465C
    if (memory16(_ds, 0x8E84) != 0)               //jnz short loc_146E4
      goto loc_146E4;
    memory16(_ds, 0x8E82) = 0xffff;               //mov word_313B2, 0FFFFh
    memory16(_ds, 0x8E88) = 0x18;                 //mov word_313B8, 18h
loc_146E4:                                        //loc_146E4:
    if (memory16(_ds, 0x9162) == 0)               //jz short loc_14709
      goto loc_14709;
    memory16(_ds, 0x9162) -= 1;                   //dec word_31692
    _dx = 0xaa;                                   //mov dx, 0AAh
    _cx = memory16(_ds, 0x9162);                  //mov cx, word_31692
    _ax = 0x98;                                   //mov ax, 98h
    _bx = 0xa0;                                   //mov bx, 0A0h
    sub_1465C();                                  //call sub_1465C
    if (memory16(_ds, 0x9162) != 0)               //jnz short loc_14709
      goto loc_14709;
    sub_1472D();                                  //call sub_1472D
loc_14709:                                        //loc_14709:
    if (memory(_ds, 0x8F59) & 0x80)               //jnz short loc_14717
      goto loc_14717;
    _ax = memory16(_ds, 0x9130);                  //mov ax, word_31660
    memory16(_ds, 0x912E) = _ax;                  //mov word_3165E, ax
    return;                                       //retn
loc_14717:                                        //loc_14717:
    _ax = memory16(_ds, 0x9132);                  //mov ax, word_31662
    memory16(_ds, 0x912E) -= _ax;                 //sub word_3165E, ax
    if ((short)memory16(_ds, 0x912E) > 0 /*CHECK*/)      //jg short locret_1472C
      goto locret_1472C;
    _ax = memory16(_ds, 0x9130);                  //mov ax, word_31660
    memory16(_ds, 0x912E) += _ax;                 //add word_3165E, ax
    memory(_ds, 0x8F5B) = 0xff;                   //mov byte_3148B, 0FFh
locret_1472C:                                     //locret_1472C:
    return;
}


void sub_1465C()
{
    _dx += 1;                                     //inc dx
    _push(_ax);                                   //push ax
    _push(_dx);                                   //push dx
    _ax = 0x0a;                                   //mov ax, 0Ah
    _ax = _cx * _al;                              //mul cx
    _cx = _pop();                                 //pop cx
    _div(_cx);                                    //div cx
    _si = _ax;                                    //mov si, ax
    _si <<= 1;                                    //shl si, 1
    _si = memory16(_ds, _si + 12898);             //mov si, [si+3262h]
    _cx = _pop();                                 //pop cx
    _dx = _bx;                                    //mov dx, bx
    sub_10875();                               //jmp sub_10875
}

void sub_1472D()
{
    _push(_si);                                   //push si
    _si = memory16(_ds, 0x9008);                  //mov si, word_31538
loc_14732:                                        //loc_14732:
    if (memory16(_ds, _si) == 0)                  //jz short loc_14740
      goto loc_14740;
    _push(memory16(_ds, _si + 10));               //push word ptr [si+0Ah]
    sub_137A9();                                  //call sub_137A9
    _si = _pop();                                 //pop si
    goto loc_14732;                               //jmp short loc_14732
loc_14740:                                        //loc_14740:
    _ax = memory16(_ds, 0x91B4);                  //mov ax, word_316E4
    memory16(_ds, 0x9008) = _ax;                  //mov word_31538, ax
    _ax = memory16(_ds, 0x91B6);                  //mov ax, word_316E6
    memory16(_ds, 0x9006) = _ax;                  //mov word_31536, ax
    _si = 0x91b8;                                 //mov si, 91B8h
    _di = 0x9134;                                 //mov di, 9134h
    _cx = 0x0e;                                   //mov cx, 0Eh
    _rep_movsw<MemAuto, MemAuto, DirAuto>();      //rep movsw
    _si = _pop();                                 //pop si
}


void sub_13589()
{
    _push(_es);                                   //push es
    _push(_di);                                   //push di
    _di = memory16(_ds, _si + 12);                //mov di, [si+0Ch]
    _di -= 0x0008;                                //sub di, 8
    _ax = 0x449b;                                 //mov ax, 449Bh
    if (!(_di & 0x0001))                          //jz short loc_1359E
      goto loc_1359E;
    _di -= 1;                                     //dec di
    _ax = 0x5489;                                 //mov ax, 5489h
loc_1359E:                                        //loc_1359E:
    _es = _ax;                                    //mov es, ax
    _ax = memory16(_ds, _si + 18);                //mov ax, [si+12h]
    _ax = _ax + memory16(_es, _di);               //add ax, es:[di]
    _ax = _ax - memory16(_es, _di + 8);           //sub ax, es:[di+8]
    memory16(_ds, _si + 40) = _ax;                //mov [si+28h], ax
    _ax = _ax + memory16(_es, _di + 4);           //add ax, es:[di+4]
    _ax -= 1;                                     //dec ax
    memory16(_ds, _si + 44) = _ax;                //mov [si+2Ch], ax
    _ax = memory16(_ds, _si + 22);                //mov ax, [si+16h]
    _ax = _ax + memory16(_es, _di + 2);           //add ax, es:[di+2]
    _ax = _ax - memory16(_es, _di + 10);          //sub ax, es:[di+0Ah]
    memory16(_ds, _si + 42) = _ax;                //mov [si+2Ah], ax
    _ax = _ax + memory16(_es, _di + 6);           //add ax, es:[di+6]
    _ax -= 1;                                     //dec ax
    memory16(_ds, _si + 46) = _ax;                //mov [si+2Eh], ax
    _di = _pop();                                 //pop di
    _es = _pop();                                 //pop es
}

void sub_11BEA();
void sub_10F96();
void sub_11C18();
void sub_10F2F();

void sub_11BEA()
{
    int check = _sp;
    _push(_si);                                   //push si
    _si += 0x28;                                  //add si, 28h
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    memory16(_ds, 0xFCE2) = _ax;                  //mov word_38212, ax
    memory16(_ds, 0x8EB4) = _ax;                  //mov word_313E4, ax
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    memory16(_ds, 0xFCE6) = _ax;                  //mov word_38216, ax
    memory16(_ds, 0x8EB6) = _ax;                  //mov word_313E6, ax
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    memory16(_ds, 0xFCEA) = _ax;                  //mov word_3821A, ax
    memory16(_ds, 0x8EB8) = _ax;                  //mov word_313E8, ax
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    memory16(_ds, 0xFCEE) = _ax;                  //mov word_3821E, ax
    memory16(_ds, 0x8EBA) = _ax;                  //mov word_313EA, ax
    _di = memory16(_ds, 0x9054);                  //mov di, word_31584
    sub_11C18();    //TODO:setzero                              //call sub_11C18
    // TODO!!!!!!!!!!!
    if (!_flags.zero)                             //jnz short loc_11C16
      goto loc_11C16;
    sub_10F96();    //TODO:setzero                              //call sub_10F96

loc_11C16:                                        //loc_11C16:
    _si = _pop();                                 //pop si
    _ASSERT(check == _sp);
}

void sub_714A()
{
    _ax = 0;
    _flags.zero = true;
}

void sub_10F96()
{
    WORD _cs = seg000 ;
    memory16(_ds, 0x8E74) = _bx;                  //mov word_313A4, bx
    _bx = memory16(_ds, 0x991C);                  //mov bx, word_31E4C
    _bx <<= 1;                                    //shl bx, 1
    _push(memory16(_cs, _bx + 4008));             //push word ptr cs:[bx+0FA8h]
    _ASSERT(_bx == 2); // seg000:0faa = 0x714a
    _bx = memory16(_ds, 0x8E74);                  //mov bx, word_313A4
    
    switch(_pop())
    {
        case 0x714A: sub_714A(); break;
        default:
            _ASSERT(0);
    }
}

void sub_11C18()
{
    if (memory16(_ds, _di) == 0)                  //jz short locret_11C4E
    {
      _flags.zero = true;
      goto locret_11C4E;
    }
    _ax = memory16(_ds, _di + 40);                //mov ax, [di+28h]
    memory16(_ds, 0xFCF2) = _ax;                  //mov word_38222, ax
    _ax = memory16(_ds, _di + 42);                //mov ax, [di+2Ah]
    memory16(_ds, 0xFCF6) = _ax;                  //mov word_38226, ax
    _ax = memory16(_ds, _di + 44);                //mov ax, [di+2Ch]
    memory16(_ds, 0xFCFA) = _ax;                  //mov word_3822A, ax
    _ax = memory16(_ds, _di + 46);                //mov ax, [di+2Eh]
    memory16(_ds, 0xFCFE) = _ax;                  //mov word_3822E, ax
    sub_10F2F();                                  //call sub_10F2F
    if (!_flags.zero)                             //jnz short loc_11C48
      goto loc_11C48;
    if (memory16(_ds, _di) != 0xb8)               //jnz short loc_11C43
      goto loc_11C43;
    _di = memory16(_ds, _di + 70);                //mov di, [di+46h]
loc_11C43:                                        //loc_11C43:
    _di = memory16(_ds, _di + 10);                //mov di, [di+0Ah]
    sub_11C18();                               //jmp short sub_11C18
    return;
loc_11C48:                                        //loc_11C48:
    if (memory16(_ds, _di) == 0xb8)               //jz short loc_11C43
      goto loc_11C43;
    _flags.zero = false;
locret_11C4E:                                     //locret_11C4E:
    return;
}

void sub_10F2F()
{
    _ax = memory16(_ds, 0xFCFA);                  //mov ax, word_3822A
    if ((short)_ax < (short)memory16(_ds, 0xFCE2))//jl short loc_10F57
      goto loc_10F57;
    _ax = memory16(_ds, 0xFCF2);                  //mov ax, word_38222
    if ((short)_ax > (short)memory16(_ds, 0xFCEA))//jg short loc_10F57
      goto loc_10F57;
    _ax = memory16(_ds, 0xFCFE);                  //mov ax, word_3822E
    if ((short)_ax < (short)memory16(_ds, 0xFCE6))//jl short loc_10F57
      goto loc_10F57;
    _ax = memory16(_ds, 0xFCF6);                  //mov ax, word_38226
    if ((short)_ax > (short)memory16(_ds, 0xFCEE))//jg short loc_10F57
      goto loc_10F57;
    _ax = _ax ^ _ax;                              //xor ax, ax
    _ax -= 1;                                     //dec ax
    _flags.zero = _ax == 0;
    return;                                       //retn
loc_10F57:                                        //loc_10F57:
    _ax = _ax ^ _ax;                              //xor ax, ax
    _flags.zero = true;
}

void sub_144F3()
{
    _ax = memory16(_ds, _si + 18);                //mov ax, [si+12h]
    memory16(_ds, 0x8F34) = _ax;                  //mov word_31464, ax
    _ax = memory16(_ds, _si + 22);                //mov ax, [si+16h]
    memory16(_ds, 0x8F36) = _ax;                  //mov word_31466, ax
    if (memory(_ds, 0x8F59) & 4)                  //jnz short loc_14518
      goto loc_14518;
    if (memory(_ds, 0x8F59) & 8)                  //jnz short loc_14532
      goto loc_14532;
    _ax = memory16(_ds, 0x919E);                  //mov ax, word_316CE
    if (!(_ax & _ax))                             //jz short loc_1454A
      goto loc_1454A;
    if ((short)_ax < 0)                         //js short loc_14546
      goto loc_14546;
    goto loc_1452C;                               //jmp short loc_1452C
loc_14518:                                        //loc_14518:
    if ((short)memory16(_ds, 0x919E) <= (short)0) //jle short loc_14525
      goto loc_14525;
    memory16(_ds, 0x919E) = 0;                    //mov word_316CE, 0
loc_14525:                                        //loc_14525:
    if ((short)memory16(_ds, 0x919E) <= (short)0xfffa)
      goto loc_1454A;
loc_1452C:                                        //loc_1452C:
    memory16(_ds, 0x919E) -= 1;                   //dec word_316CE
    goto loc_1454A;                               //jmp short loc_1454A
loc_14532:                                        //loc_14532:
    if ((short)memory16(_ds, 0x919E) >= (short)0) //jge short loc_1453F
      goto loc_1453F;
    memory16(_ds, 0x919E) = 0;                    //mov word_316CE, 0
loc_1453F:                                        //loc_1453F:
    if ((short)memory16(_ds, 0x919E) >= (short)6) //jge short loc_1454A
      goto loc_1454A;
loc_14546:                                        //loc_14546:
    memory16(_ds, 0x919E) += 1;                   //inc word_316CE
loc_1454A:                                        //loc_1454A:
    _ax = memory16(_ds, 0x918C);                  //mov ax, word_316BC
    memory16(_ds, 0x919A) = _ax;                  //mov word_316CA, ax
    if (!(memory(_ds, 0x8F59) & 1))               //jz short loc_14576
      goto loc_14576;
    if ((short)memory16(_ds, _si + 22) <= (short)0x10)
      goto loc_14569;
    memory16(_ds, _si + 22) -= 3;                 //sub word ptr [si+16h], 3
    _ax = memory16(_ds, 0x915E);                  //mov ax, word_3168E
    memory16(_ds, _si + 22) -= _ax;               //sub [si+16h], ax
    goto loc_14576;                               //jmp short loc_14576
loc_14569:                                        //loc_14569:
    memory16(_ds, _si + 22) = 0x10;               //mov word ptr [si+16h], 10h
    memory16(_ds, 0x919A) = 1;                    //mov word_316CA, 1
    goto loc_145A4;                               //jmp short loc_145A4
loc_14576:                                        //loc_14576:
    if (!(memory(_ds, 0x8F59) & 2))               //jz short loc_145A4
      goto loc_145A4;
    if ((short)memory16(_ds, _si + 22) >= (short)0xb0)
      goto loc_14590;
    memory16(_ds, _si + 22) += 3;                 //add word ptr [si+16h], 3
    _ax = memory16(_ds, 0x915E);                  //mov ax, word_3168E
    memory16(_ds, _si + 22) += _ax;               //add [si+16h], ax
    goto loc_145A4;                               //jmp short loc_145A4
loc_14590:                                        //loc_14590:
    _ax = memory16(_ds, 0x9190);                  //mov ax, word_316C0
    if (_ax == memory16(_ds, 0x91AA))             //jz short loc_145A4
      goto loc_145A4;
    memory16(_ds, 0x919A) = 0xffff;               //mov word_316CA, 0FFFFh
    memory16(_ds, _si + 22) = 0xb0;               //mov word ptr [si+16h], 0B0h
loc_145A4:                                        //loc_145A4:
    _ax = memory16(_ds, 0x919E);                  //mov ax, word_316CE
    if (!(_ax & _ax))                             //jz short loc_145C3
      goto loc_145C3;
    if ((short)_ax < 0)                         //js short loc_145B9
      goto loc_145B9;
    if (!(memory(_ds, 0x8F59) & 8))               //jz short loc_145C3
      goto loc_145C3;
    _ax = 0x0006;                                 //mov ax, 6
    goto loc_145C3;                               //jmp short loc_145C3
loc_145B9:                                        //loc_145B9:
    if (!(memory(_ds, 0x8F59) & 4))               //jz short loc_145C3
      goto loc_145C3;
    _ax = 0xfffa;                                 //mov ax, 0FFFAh
loc_145C3:                                        //loc_145C3:
    if (memory16(_ds, 0x915E) != 0)               //jnz short loc_145CC
      goto loc_145CC;
    _sar(_ax, 1);                                 //sar ax, 1
loc_145CC:                                        //loc_145CC:
    if ((short)memory16(_ds, 0x915E) < (short)2)  //jl short loc_145D9
      goto loc_145D9;
    _bx = _ax;                                    //mov bx, ax
    _sar(_bx, 1);                                 //sar bx, 1
    _ax += _bx;                                   //add ax, bx
loc_145D9:                                        //loc_145D9:
    memory16(_ds, _si + 18) += _ax;               //add [si+12h], ax
    if ((short)memory16(_ds, _si + 18) >= (short)0x10)
      goto loc_145E7;
    memory16(_ds, _si + 18) = 0x10;               //mov word ptr [si+12h], 10h
loc_145E7:                                        //loc_145E7:
    if ((short)memory16(_ds, _si + 18) <= (short)302)//jle short locret_145F3
      goto locret_145F3;
    memory16(_ds, _si + 18) = 302;                //mov word ptr [si+12h], 12Eh
locret_145F3:                                     //locret_145F3:
    return;
}

void sub_11E29();
void sub_11D1E();
void sub_11E02();

void sub_11E29()
{
    int check = _sp;
    _ax = memory16(_ds, _si + 18);                //mov ax, [si+12h]
    _ax -= 0x0e;                                  //sub ax, 0Eh
    _dx = memory16(_ds, _si + 22);                //mov dx, [si+16h]
    _dx -= 0x0e;                                  //sub dx, 0Eh
    _bx = _ax;                                    //mov bx, ax
    _bx &= 0x0f;                                  //and bx, 0Fh
    _bx <<= 1;                                    //shl bx, 1
    _push(memory16(_ds, _bx + 12954));            //push word ptr [bx+329Ah]
    _cx = 0x19;                                   //mov cx, 19h
    sub_11D1E();                                  //call sub_11D1E
    _di = _pop();                                 //pop di
    _push(_si);                                   //push si
    _si = 0x9920;                                 //mov si, 9920h
    _cx = 0x4b;                                   //mov cx, 4Bh
loc_11E4E:                                        //loc_11E4E:
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _ax = _ax & memory16(_ds, _di);               //and ax, [di]
    if (_ax != 0)                                 //jnz short loc_11E5C
      goto loc_11E5C;
    _di += 0x0002;                                //add di, 2
    if (--_cx)                                    //loop loc_11E4E
      goto loc_11E4E;
    _si = _pop();                                 //pop si
    _ax = _ax ^ _ax;                              //xor ax, ax
    _flags.zero = _ax == 0;
    return;                                       //retn
loc_11E5C:                                        //loc_11E5C:
    _si = _pop();                                 //pop si
    _ax = _ax ^ _ax;                              //xor ax, ax
    _ax -= 1;                                     //dec ax
    _ASSERT(check == _sp);
    _flags.zero = _ax == 0;
}

void sub_11D1E()
{
    int check = _sp;
    _push(_si);                                   //push si
    _si = 0x0000;                                 //mov si, 0
    _si = _si + memory16(_ds, 0x918E);            //add si, word_316BE
    _dx = _dx + memory16(_ds, 0x9196);            //add dx, word_316C6
    _bx = _dx;                                    //mov bx, dx
    _bx &= 0x0f;                                  //and bx, 0Fh
    _dx >>= 1;                                    //shr dx, 1
    _dx >>= 1;                                    //shr dx, 1
    _dx >>= 1;                                    //shr dx, 1
    _dx >>= 1;                                    //shr dx, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax &= 0xfe;                                  //and ax, 0FEh
    _si += _ax;                                   //add si, ax
    _ax = 0x28;                                   //mov ax, 28h
    _ax = _dx * _al;                              //mul dx
    _si += _ax;                                   //add si, ax
    _dx = 0x0004;                                 //mov dx, 4
    _di = 0x9920;                                 //mov di, 9920h
    _push(_bx);                                   //push bx
    sub_11E02();                                  //call sub_11E02
    _bx = _pop();                                 //pop bx
    _di = 0x9922;                                 //mov di, 9922h
    _push(_bx);                                   //push bx
    sub_11E02();                                  //call sub_11E02
    _bx = _pop();                                 //pop bx
    _di = 0x9924;                                 //mov di, 9924h
    _push(_bx);                                   //push bx
    sub_11E02();                                  //call sub_11E02
    _bx = _pop();                                 //pop bx
    _di -= 0x0004;                                //sub di, 4
    _si += 0x22;                                  //add si, 22h
    _cx += _bx;                                   //add cx, bx
    _cx -= 0x10;                                  //sub cx, 10h
    if ((short)_cx <= (short)0)            //jle short loc_11D97
      goto loc_11D97;
loc_11D71:                                        //loc_11D71:
    _bx = _bx ^ _bx;                              //xor bx, bx
    _push(_di);                                   //push di
    sub_11E02();                                  //call sub_11E02
    _di = _pop();                                 //pop di
    _bx = _bx ^ _bx;                              //xor bx, bx
    _di += 0x0002;                                //add di, 2
    _push(_di);                                   //push di
    sub_11E02();                                  //call sub_11E02
    _di = _pop();                                 //pop di
    _bx = _bx ^ _bx;                              //xor bx, bx
    _di += 0x0002;                                //add di, 2
    _push(_di);                                   //push di
    sub_11E02();                                  //call sub_11E02
    _di = _pop();                                 //pop di
    _di += 0x5c;                                  //add di, 5Ch
    _si += 0x22;                                  //add si, 22h
    _cx -= 0x10;                                  //sub cx, 10h
    _sync();
    if ((short)_cx > 0 /*CHECK*/)                        //jg short loc_11D71
      goto loc_11D71;
loc_11D97:                                        //loc_11D97:
    _si = _pop();                                 //pop si
    _ASSERT(check == _sp);

}

void sub_11E02()
{
    int check = _sp;
    _push(_cx);                                   //push cx
    _push(_bx);                                   //push bx
    _bx -= 0x10;                                  //sub bx, 10h
    _bx = -_bx;                                   //neg bx
    if ((short)_cx <= (short)_bx)                 //jle short loc_11E0F
      goto loc_11E0F;
    _cx = _bx;                                    //mov cx, bx
loc_11E0F:                                        //loc_11E0F:
    _bx = _pop();                                 //pop bx
    if (!(_cx & _cx))                             //jz short loc_11E27
      goto loc_11E27;
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _push(_si);                                   //push si
    _si = 0x5538;                                 //mov si, 5538h
    _ax >>= 1;                                    //shr ax, 1
    _si += _ax;                                   //add si, ax
    _si += _bx;                                   //add si, bx
    _si += _bx;                                   //add si, bx
loc_11E21:                                        //loc_11E21:
    _movsw<MemAuto, MemAuto, DirAuto>();          //movsw
    _di += _dx;                                   //add di, dx
    if (--_cx)                                    //loop loc_11E21
      goto loc_11E21;
    _si = _pop();                                 //pop si
loc_11E27:                                        //loc_11E27:
    _cx = _pop();                                 //pop cx
    _ASSERT(check == _sp);
}

void sub_141e2()
{
    WORD _cs = seg000;
    _di = memory16(_cs, _di);
    _ax = memory16(_cs, _di);
    _di += 2;
    memory16(_ds, _si+0x0c) = _ax;
    _ax = memory16(_cs, _di);
    _di += 2;
    memory16(_ds, _si+0x0e) = _ax;
    memory16(_ds, _si+0x10) = _di;
}

void sub_141B1()
{
    WORD ptr = -1;
    WORD _cs = seg000 ;
    memory16(_ds, _si + 14) -= 1;                 //dec word ptr [si+0Eh]
    if ((short)memory16(_ds, _si + 14) < 0)       //js short loc_141DC
      goto loc_141DC;
    if (memory16(_ds, _si + 14) != 0)             //jnz short locret_141DB
      goto locret_141DB;
    _di = memory16(_ds, _si + 16);                //mov di, [si+10h]
    _ax = memory16(_cs, _di);                     //mov ax, cs:[di]
    _di += 0x0002;                                //add di, 2
    if (_ax & _ax)                                //jnz short loc_141CC
      goto loc_141CC;
    _di += 0x0002;                                //add di, 2
    //goto word ptr cs:[di-2];                      //jmp word ptr cs:[di-2]
    ptr = memory16(_cs, _di-2);
    switch (ptr)
    {
        case 0x41e2: sub_141e2(); break;
        default:
            std::cout << "sub_141B1 goto cs:di-2, cs=" << std::hex << (int)_cs << ", ptr=" << std::hex << (int)(ptr) << std::endl;
            //_ASSERT(0);
    }
loc_141CC:                                        //loc_141CC:
    memory16(_ds, _si + 12) = _ax;                //mov [si+0Ch], ax
    _ax = memory16(_cs, _di);                     //mov ax, cs:[di]
    _di += 0x0002;                                //add di, 2
    memory16(_ds, _si + 14) = _ax;                //mov [si+0Eh], ax
    memory16(_ds, _si + 16) = _di;                //mov [si+10h], di
locret_141DB:                                     //locret_141DB:
    return;                                       //retn
loc_141DC:                                        //loc_141DC:
    memory16(_ds, _si + 14) = 0;                  //mov word ptr [si+0Eh], 0
}

void sub_20653();

void sub_10A95()
{
    WORD _cs = seg000 ;
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    _ASSERT(_bp == 12);                           //call cs:off_10AA3[bp]
    sub_20653();
}

void sub_10EDD();
void sub_10EE1();
void sub_11CCC();
void sub_13A36();
void sub_10F96();

void sub_20653()
{
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0700;                                 //mov ax, 700h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _al = 0x08;                                   //mov al, 8
    _out(_dx, _al);                               //out dx, al
    _si = 0x9c80;                                 //mov si, 9C80h
    _cx = 0x50;                                   //mov cx, 50h
loc_2066C:                                        //loc_2066C:
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    //gggg
    if ((short)_ax < 0)                           //js short loc_206EA
      goto loc_206EA;
    _bx = _ax;                                    //mov bx, ax
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _dx = _ax;                                    //mov dx, ax
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _bx += _ax;                                   //add bx, ax
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _dx += _ax;                                   //add dx, ax
    if (_bx >= 0x013c)                            //jnb short loc_206E3
      goto loc_206E3;
    if (_dx >= 0xbc)                              //jnb short loc_206E3
      goto loc_206E3;
    memory16(_ds, _si - 8) = _bx;                 //mov [si-8], bx
    memory16(_ds, _si - 6) = _dx;                 //mov [si-6], dx
    _push(_bx);                                   //push bx
    _push(_dx);                                   //push dx
    _push(_cx);                                   //push cx
    _ax = _bx;                                    //mov ax, bx
    _bx = _dx;                                    //mov bx, dx
    sub_10EDD();                                  //call sub_10EDD
    if (_flags.zero)                              //jz short loc_206B3
      goto loc_206B3;
    _push(_es);                                   //push es
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
    _ax = memory16(_es, 180952);                  //mov ax, es:word_2C2D8
    _push(_si);                                   //push si
    sub_10EE1();                                  //call sub_10EE1
    _si = _pop();                                 //pop si
    _es = _pop();                                 //pop es
    _cx = _pop();                                 //pop cx
    _sp += 0x0004;                                //add sp, 4
    goto loc_206E3;                               //jmp short loc_206E3
loc_206B3:                                        //loc_206B3:
    _cx = _pop();                                 //pop cx
    _dx = _pop();                                 //pop dx
    _di = memory16(_ds, 0x425B);                  //mov di, word_2C78B
    _ax = 0x28;                                   //mov ax, 28h
    _ax = _dx * _al;                              //mul dx
    _di += _ax;                                   //add di, ax
    _ax = _pop();                                 //pop ax
    _push(_cx);                                   //push cx
    _cx = _ax;                                    //mov cx, ax
    _cx &= 0x0007;                                //and cx, 7
    _ax = _ax ^ _cx;                              //xor ax, cx
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _di += _ax;                                   //add di, ax
    _al = 0xc0;                                   //mov al, 0C0h
    _al >>= _cl;                                  //shr al, cl
    _cx = _pop();                                 //pop cx
    _dx = 0x03cf;                                 //mov dx, 3CFh
    _out(_dx, _al);                               //out dx, al
    memory(_es, _di) &= _al;                      //and es:[di], al
    memory(_es, _di + 40) &= _al;                 //and es:[di+28h], al
    goto loc_206ED;                               //jmp short loc_206ED
loc_206E3:                                        //loc_206E3:
    memory16(_ds, _si - 8) = 0xffff;              //mov word ptr [si-8], 0FFFFh
    goto loc_206ED;                               //jmp short loc_206ED
loc_206EA:                                        //loc_206EA:
    _si += 0x0006;                                //add si, 6
loc_206ED:                                        //loc_206ED:
    if (--_cx)                                    //loop loc_206F1
      goto loc_206F1;
    goto loc_206F4;                               //jmp short loc_206F4
loc_206F1:                                        //loc_206F1:
    goto loc_2066C;                               //jmp loc_2066C
loc_206F4:                                        //loc_206F4:
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0001;                                 //mov ax, 1
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0xff08;                                 //mov ax, 0FF08h
    _out(_dx, _ax);                               //out dx, ax
}

void sub_10EDD()
{
    sub_11CCC();                                  //call sub_11CCC
}

void sub_10EE1()
{
    sub_13A36();                                  //call sub_13A36
}

void sub_11CCC()
{
    _di = memory16(_ds, 0x9054);                  //mov di, word_31584
    memory16(_ds, 0x8EB4) = _ax;                  //mov word_313E4, ax
    memory16(_ds, 0x8EB8) = _ax;                  //mov word_313E8, ax
    memory16(_ds, 0x8EB6) = _bx;                  //mov word_313E6, bx
    memory16(_ds, 0x8EBA) = _bx;                  //mov word_313EA, bx
loc_11CDE:                                        //loc_11CDE:
    if (memory16(_ds, _di) == 0)                  //jz short loc_11D0C
      goto loc_11D0C;
    if ((short)_ax < (short)memory16(_ds, _di + 40))//jl short loc_11CFE
      goto loc_11CFE;
    if ((short)_ax > (short)memory16(_ds, _di + 44))//jg short loc_11CFE
      goto loc_11CFE;
    if ((short)_bx < (short)memory16(_ds, _di + 42))//jl short loc_11CFE
      goto loc_11CFE;
    if ((short)_bx > (short)memory16(_ds, _di + 46))//jg short loc_11CFE
      goto loc_11CFE;
    if (memory16(_ds, _di) == 0xb8)               //jz short loc_11D07
    {
        _flags.zero = true;
      goto loc_11D07;
    }
    _flags.zero = false;
    return;                                       //retn
loc_11CFE:                                        //loc_11CFE:
    if (memory16(_ds, _di) != 0xb8)               //jnz short loc_11D07
      goto loc_11D07;
    _di = memory16(_ds, _di + 70);                //mov di, [di+46h]
loc_11D07:                                        //loc_11D07:
    _di = memory16(_ds, _di + 10);                //mov di, [di+0Ah]
    goto loc_11CDE;                               //jmp short loc_11CDE
loc_11D0C:                                        //loc_11D0C:
    memory16(_ds, 0xFCE2) = _ax;                  //mov word_38212, ax
    memory16(_ds, 0xFCE6) = _bx;                  //mov word_38216, bx
    memory16(_ds, 0xFCEA) = _ax;                  //mov word_3821A, ax
    memory16(_ds, 0xFCEE) = _bx;                  //mov word_3821E, bx
    sub_10F96();                                  //call sub_10F96
}

void sub_13615();
void sub_10FB4();
void sub_10FD2();

void sub_13A36()
{
    WORD ptr = memory16(_ds, _di+6);
    _ASSERT(0);
    //goto word ptr [di+6];                         //jmp word ptr [di+6]
}

void sub_13615()
{
    int check = _sp;
    _si = 0xd274;                                 //mov si, 0D274h
    _bx = memory16(_ds, 0x9192);                  //mov bx, word_316C2
    _cx = memory16(_ds, 0x9190);                  //mov cx, word_316C0
loc_13620:                                        //loc_13620:
    _ax = memory16(_ds, _si);                     //mov ax, [si]
    if ((short)_ax < 0)                         //js short loc_13643
      goto loc_13643;
    if ((short)_bx <= (short)_ax)                 //jle short loc_1363E
      goto loc_1363E;
    if ((short)_cx > (short)_ax)                  //jg short loc_1363E
      goto loc_1363E;
    _bx = memory16(_ds, _si + 2);                 //mov bx, [si+2]
    _push(_si);                                   //push si
    sub_10FB4();                                  //call sub_10FB4
    _si = _pop();                                 //pop si
    _bx = memory16(_ds, 0x9192);                  //mov bx, word_316C2
    _cx = memory16(_ds, 0x9190);                  //mov cx, word_316C0
loc_1363E:                                        //loc_1363E:
    _si += 0x0e;                                  //add si, 0Eh
    goto loc_13620;                               //jmp short loc_13620
loc_13643:                                        //loc_13643:
    if ((short)_cx >= (short)_bx)                 //jge short locret_13681
      goto locret_13681;
    memory16(_ds, 0x9192) = _cx;                  //mov word_316C2, cx
    _si = 0xda9e;                                 //mov si, 0DA9Eh
    _bx = memory16(_ds, 0x9194);                  //mov bx, word_316C4
    _cx = memory16(_ds, 0x9190);                  //mov cx, word_316C0
loc_13656:                                        //loc_13656:
    _ax = memory16(_ds, _si);                     //mov ax, [si]
    if ((short)_ax < 0)                         //js short loc_13679
      goto loc_13679;
    if ((short)_bx <= (short)_ax)                 //jle short loc_13674
      goto loc_13674;
    if ((short)_cx > (short)_ax)                  //jg short loc_13674
      goto loc_13674;
    _bx = memory16(_ds, _si + 2);                 //mov bx, [si+2]
    _push(_si);                                   //push si
    sub_10FD2();                                  //call sub_10FD2
    _si = _pop();                                 //pop si
    _bx = memory16(_ds, 0x9194);                  //mov bx, word_316C4
    _cx = memory16(_ds, 0x9190);                  //mov cx, word_316C0
loc_13674:                                        //loc_13674:
    _si += 0x0e;                                  //add si, 0Eh
    goto loc_13656;                               //jmp short loc_13656
loc_13679:                                        //loc_13679:
    if ((short)_cx >= (short)_bx)                 //jge short locret_13681
      goto locret_13681;
    memory16(_ds, 0x9194) = _cx;                  //mov word_316C4, cx
locret_13681:                                     //locret_13681:
    _ASSERT(check == _sp);
    return;
}

void sub_13389();

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

void sub_170F1()
{
    _bx <<= 1;                                    //shl bx, 1
    switch (_bx)                                  //jmp cs:off_170F8[bx]
    {
        case 0: sub_13360(); return;
      case 2: goto loc_1710E;
      case 4: goto loc_17114;
      case 6: goto loc_1711A;
      case 8: goto loc_17120;
      case 10: goto loc_17126;
      case 12: goto loc_1712C;
      case 14: goto loc_17132;
      case 16: goto loc_17138;
      case 18: goto loc_1713E;
      case 20: goto loc_17144;
      default:
        _ASSERT(0);
    }
loc_1710E:                                        //loc_1710E:
    _bx = 0x6285;                                 //mov bx, 6285h
    sub_13389();                               //jmp sub_13389
    return;
loc_17114:                                        //loc_17114:
    _bx = 0x6297;                                 //mov bx, 6297h
    sub_13389();                               //jmp sub_13389
    return;
loc_1711A:                                        //loc_1711A:
    _bx = 0x62a9;                                 //mov bx, 62A9h
    sub_13389();                               //jmp sub_13389
    return;
loc_17120:                                        //loc_17120:
    _bx = 0x62bb;                                 //mov bx, 62BBh
    sub_13389();                               //jmp sub_13389
    return;
loc_17126:                                        //loc_17126:
    _bx = 0x62cd;                                 //mov bx, 62CDh
    sub_13389();                               //jmp sub_13389
    return;
loc_1712C:                                        //loc_1712C:
    _bx = 0x62df;                                 //mov bx, 62DFh
    sub_13389();                               //jmp sub_13389
    return;
loc_17132:                                        //loc_17132:
    _bx = 0x62f1;                                 //mov bx, 62F1h
    sub_13389();                               //jmp sub_13389
    return;
loc_17138:                                        //loc_17138:
    _bx = 0x6313;                                 //mov bx, 6313h
    sub_13389();                               //jmp sub_13389
    return;
loc_1713E:                                        //loc_1713E:
    _bx = 0x6325;                                 //mov bx, 6325h
    sub_13389();                               //jmp sub_13389
    return;
loc_17144:                                        //loc_17144:
    _bx = 0x6337;                                 //mov bx, 6337h
    sub_13389();                               //jmp sub_13389
    return;
}

void sub_10FB4()
{
    WORD _cs = seg000 ;
    memory16(_ds, 0x8E74) = _bx;                  //mov word_313A4, bx
    _bx = memory16(_ds, 0x991C);                  //mov bx, word_31E4C
    _bx <<= 1;                                    //shl bx, 1
    _push(memory16(_cs, _bx + 4038));             //push word ptr cs:[bx+0FC6h]
    _bx = memory16(_ds, 0x8E74);                  //mov bx, word_313A4
    
    switch (_pop())
    {
        case 0x70F1: sub_170F1(); break;
        default:
            _ASSERT(0);
    }
}

void sub_135CE();
void sub_16F7F();
void sub_16F00();
void sub_16FE0();
void sub_1705B();

void sub_16EEF()
{
    _bx <<= 1;
    switch (_bx) // jmp cs:off_16EF6[bx]
    {
        case 0: sub_135CE(); break;
        case 2: sub_16F7F(); break;
        case 4: sub_16F00(); break;
        case 6: sub_16FE0(); break;
        case 8: sub_1705B(); break;
        default: _ASSERT(0);
    }
}

void sub_10FD2()
{
    WORD _cs = seg000 ;
    memory16(_ds, 0x8E74) = _bx;                  //mov word_313A4, bx
    _bx = memory16(_ds, 0x991C);                  //mov bx, word_31E4C
    _bx <<= 1;                                    //shl bx, 1
    _push(memory16(_cs, _bx + 4068));             //push word ptr cs:[bx+0FE4h]
    _bx = memory16(_ds, 0x8E74);                  //mov bx, word_313A4
    
    switch (_pop())
    {
        case 0x6eef: sub_16EEF(); break;
        default:
            _ASSERT(0);
    }
}

void sub_1758F()
{
    WORD _cs = seg000 ;
    memory16(_ds, 0x8EAC) = 3000;                 //mov word_313DC, 0BB8h
    memory16(_ds, 0x8EAE) = 600;                  //mov word_313DE, 258h
    memory16(_ds, 0x91A8) = 0;                    //mov word_316D8, 0
    memory16(_ds, 0x91AA) = 4607;                 //mov word_316DA, 11FFh
    memory(_ds, 0x922C) = 0;                      //mov byte_3175C, 0
    memory16(_ds, 0x91FE) = 0;                    //mov word_3172E, 0
    sub_11022();                                  //call sub_11022
    _di = 0x904a;                                 //mov di, 904Ah
    sub_1077C();                                  //call sub_1077C
    memory16(_ds, _si) = 0x50;                    //mov word ptr [si], 50h
    memory16(_ds, _si + 2) = 29380;               //mov word ptr [si+2], 72C4h
    memory16(_ds, _si + 4) = 29984;               //mov word ptr [si+4], 7520h
    memory16(_ds, _si + 6) = 29005;               //mov word ptr [si+6], 714Dh
    memory16(_ds, _si + 72) = 0;                  //mov word ptr [si+48h], 0
    memory(_ds, _si + 74) = 0xff;                 //mov byte ptr [si+4Ah], 0FFh
    memory(_ds, _si + 75) = 0xff;                 //mov byte ptr [si+4Bh], 0FFh
    memory16(_ds, _si + 22) = 0x10;               //mov word ptr [si+16h], 10h
    _ax = memory(_cs, 0x6278);                    //mov ax, cs:word_16278
    memory16(_ds, _si + 36) = _ax;                //mov [si+24h], ax
    memory16(_ds, _si + 26) = 0;                  //mov word ptr [si+1Ah], 0
    memory16(_ds, _si + 66) = 0;                  //mov word ptr [si+42h], 0
    memory(_ds, 0x922B) = 0;                      //mov byte_3175B, 0
    memory(_ds, 0x9226) = 0;                      //mov byte_31756, 0
    memory(_ds, 0x9227) = 0;                      //mov byte_31757, 0
    memory(_ds, 0x9228) = 0;                      //mov byte_31758, 0
    memory(_ds, 0x9229) = 0;                      //mov byte_31759, 0
    memory(_ds, 0x922A) = 0;                      //mov byte_3175A, 0
    _di = 0x91d4;                                 //mov di, 91D4h
    _cx = 0x10;                                   //mov cx, 10h
    _ax = _ax ^ _ax;                              //xor ax, ax
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    memory16(_ds, 0x91F4) = 0xd272;               //mov word_31724, 0D272h
    memory16(_ds, 0x91F6) = 27210;                //mov word_31726, 6A4Ah
    memory16(_ds, 0x91F8) = 0xba5d;               //mov word_31728, 0BA5Dh
    memory16(_ds, 0x91FA) = 9490;                 //mov word_3172A, 2512h
    memory16(_ds, 0x91FC) = 0xe51a;               //mov word_3172C, 0E51Ah
    _ax = 0x0001;                                 //mov ax, 1
    _dx = _dx ^ _dx;                              //xor dx, dx
    _ax = memory16(_ds, 0x991A) * _al;            //mul word_31E4A
    memory16(_ds, 0x8E76) = _ax;                  //mov word_313A6, ax
    _ax = 0x0002;                                 //mov ax, 2
    _dx = _dx ^ _dx;                              //xor dx, dx
    _ax = memory16(_ds, 0x991A) * _al;            //mul word_31E4A
    memory16(_ds, 0x8E78) = _ax;                  //mov word_313A8, ax
    memory16(_ds, 0x8E72) = 13411;                //mov word_313A2, 3463h
}

void sub_13389()
{
    WORD _cs = seg000 ;
    _di = _si;                                    //mov di, si
    _cx = memory16(_ds, _di + 4);                 //mov cx, [di+4]
    memory16(_ds, 0xFCFA) = 0;                    //mov word_3822A, 0
    if (_cx == 0)                                 //jcxz short loc_13398
      goto loc_13398;
    goto loc_1339B;                               //jmp short loc_1339B
loc_13398:                                        //loc_13398:
    goto locret_13528;                            //jmp locret_13528
loc_1339B:                                        //loc_1339B:
    sub_11022();                                  //call sub_11022
    _push(_di);                                   //push di
    _di = 0x904a;                                 //mov di, 904Ah
    sub_1077C();                                  //call sub_1077C
    _di = _pop();                                 //pop di
    _bp = _bx;                                    //mov bp, bx
    memory16(_ds, 0xFCDA) = _si;                  //mov word_3820A, si
loc_133AC:                                        //loc_133AC:
    _ax = memory16(_cs, _bp);                     //mov ax, cs:[bp+0]
    memory16(_ds, _si) = _ax;                     //mov [si], ax
    _ax = memory16(_cs, _bp + 4);                 //mov ax, cs:[bp+4]
    memory16(_ds, _si + 2) = _ax;                 //mov [si+2], ax
    _ax = memory16(_cs, _bp + 6);                 //mov ax, cs:[bp+6]
    memory16(_ds, _si + 4) = _ax;                 //mov [si+4], ax
    _ax = memory16(_cs, _bp + 8);                 //mov ax, cs:[bp+8]
    memory16(_ds, _si + 6) = _ax;                 //mov [si+6], ax
    _push(_bx);                                   //push bx
    _bx = memory16(_cs, _bp + 10);                //mov bx, cs:[bp+0Ah]
    _ax = memory16(_cs, _bx);                     //mov ax, cs:[bx]
    memory16(_ds, _si + 12) = _ax;                //mov [si+0Ch], ax
    _bx += 0x0002;                                //add bx, 2
    _ax = memory16(_cs, _bx);                     //mov ax, cs:[bx]
    memory16(_ds, _si + 14) = _ax;                //mov [si+0Eh], ax
    _bx += 0x0002;                                //add bx, 2
    memory16(_ds, _si + 16) = _bx;                //mov [si+10h], bx
    _bx = _pop();                                 //pop bx
    _ax = memory16(_ds, 0xFCFA);                  //mov ax, word_3822A
    memory16(_ds, _si + 18) = _ax;                //mov [si+12h], ax
    memory16(_ds, _si + 20) = 0;                  //mov word ptr [si+14h], 0
    memory16(_ds, _si + 22) = 0;                  //mov word ptr [si+16h], 0
    memory16(_ds, _si + 24) = 0;                  //mov word ptr [si+18h], 0
    memory16(_ds, _si + 28) = 0;                  //mov word ptr [si+1Ch], 0
    memory16(_ds, _si + 30) = 0;                  //mov word ptr [si+1Eh], 0
    _ax = memory16(_cs, _bp + 2);                 //mov ax, cs:[bp+2]
    memory16(_ds, _si + 52) = _ax;                //mov [si+34h], ax
    memory16(_ds, _si + 26) = 0;                  //mov word ptr [si+1Ah], 0
    if ((short)memory16(_ds, _di + 8) >= (short)0x64)//jge short loc_13426
      goto loc_13426;
    memory16(_ds, 0xFCFA) = -memory16(_ds, 0xFCFA);//neg word_3822A
    _ax = memory16(_ds, 0xFCFA);                  //mov ax, word_3822A
    memory16(_ds, _si + 26) = _ax;                //mov [si+1Ah], ax
    memory16(_ds, 0xFCFA) = -memory16(_ds, 0xFCFA);//neg word_3822A
    memory16(_ds, _si + 18) = 0;                  //mov word ptr [si+12h], 0
loc_13426:                                        //loc_13426:
    if (_si == memory16(_ds, 0xFCDA))             //jz short loc_13433
      goto loc_13433;
    _ax = memory16(_cs, _bp + 2);                 //mov ax, cs:[bp+2]
    memory16(_ds, _si + 26) -= _ax;               //sub [si+1Ah], ax
loc_13433:                                        //loc_13433:
    _push(_bx);                                   //push bx
    _bx = memory16(_ds, _di + 6);                 //mov bx, [di+6]
    _bx -= 1;                                     //dec bx
    _bx <<= 1;                                    //shl bx, 1
    _bx = memory16(_ds, _bx + -8656);             //mov bx, [bx-21D0h]
    memory16(_ds, _si + 56) = _bx;                //mov [si+38h], bx
    if (memory16(_ds, _bx) != 0x0a)               //jnz short loc_13461
      goto loc_13461;
    _ax = memory16(_ds, _bx + 2);                 //mov ax, [bx+2]
    memory16(_ds, _si + 18) = _ax;                //mov [si+12h], ax
    _ax = memory16(_ds, _bx + 4);                 //mov ax, [bx+4]
    memory16(_ds, _si + 22) = _ax;                //mov [si+16h], ax
    if ((short)memory16(_ds, _di + 8) < (short)0x64)//jl short loc_1345E
      goto loc_1345E;
    _ax = memory16(_ds, 0xFCFA);                  //mov ax, word_3822A
    memory16(_ds, _si + 18) += _ax;               //add [si+12h], ax
loc_1345E:                                        //loc_1345E:
    _bx += 0x0006;                                //add bx, 6
loc_13461:                                        //loc_13461:
    memory16(_ds, _si + 58) = _bx;                //mov [si+3Ah], bx
    _bx = _pop();                                 //pop bx
    _ax = memory16(_ds, _di + 12);                //mov ax, [di+0Ch]
    memory16(_ds, _si + 66) = _ax;                //mov [si+42h], ax
    _ax = memory16(_ds, _di + 10);                //mov ax, [di+0Ah]
    _xchg(_al, _ah);                              //xchg al, ah
    memory16(_ds, _si + 72) = _ax;                //mov [si+48h], ax
    sub_14191();                                  //call sub_14191
    memory(_ds, _si + 72) = _al;                  //mov [si+48h], al
    _ax = memory16(_ds, 0x8E78);                  //mov ax, word_313A8
    memory16(_ds, _si + 36) = _ax;                //mov [si+24h], ax
    _ax = memory16(_ds, 0x8EB2);                  //mov ax, word_313E2
    memory16(_ds, _si + 54) = _ax;                //mov [si+36h], ax
    _al = memory(_cs, _bp + 14);                  //mov al, cs:[bp+0Eh]
    memory(_ds, _si + 39) = _al;                  //mov [si+27h], al
    if (memory(_ds, _si + 39) != 0)               //jnz short loc_1349E
      goto loc_1349E;
    _ax = memory16(_ds, 0x8E76);                  //mov ax, word_313A6
    memory16(_ds, _si + 36) = _ax;                //mov [si+24h], ax
    _ax = memory16(_ds, 0x8EB0);                  //mov ax, word_313E0
    memory16(_ds, _si + 54) = _ax;                //mov [si+36h], ax
loc_1349E:                                        //loc_1349E:
    _al = memory(_cs, _bp + 15);                  //mov al, cs:[bp+0Fh]
    memory(_ds, _si + 38) = _al;                  //mov [si+26h], al
    sub_13589();                                  //call sub_13589
    _ax = memory16(_ds, 0xFCDA);                  //mov ax, word_3820A
    memory16(_ds, _si + 68) = _ax;                //mov [si+44h], ax
    _bp += 0x10;                                  //add bp, 10h
    if (memory16(_cs, _bp) == 0)                  //jz short loc_134C8
      goto loc_134C8;
    _push(_di);                                   //push di
    _di = _si;                                    //mov di, si
    sub_11022();                                  //call sub_11022
    memory16(_ds, _di + 70) = _si;                //mov [di+46h], si
    sub_1077C();                                  //call sub_1077C
    _di = _pop();                                 //pop di
    goto loc_133AC;                               //jmp loc_133AC
loc_134C8:                                        //loc_134C8:
    _ax = memory16(_ds, _di + 8);                 //mov ax, [di+8]
loc_134CB:                                        //loc_134CB:
    if ((short)_ax < (short)0x64)                 //jl short loc_134D5
      goto loc_134D5;
    _ax -= 0x64;                                  //sub ax, 64h
    goto loc_134CB;                               //jmp short loc_134CB
loc_134D5:                                        //loc_134D5:
    memory16(_ds, 0xFCFA) += _ax;                 //add word_3822A, ax
    memory16(_ds, _si + 70) = 0;                  //mov word ptr [si+46h], 0
    if (--_cx)                                    //loop loc_134E2
      goto loc_134E2;
    goto loc_134E5;                               //jmp short loc_134E5
loc_134E2:                                        //loc_134E2:
    goto loc_1339B;                               //jmp loc_1339B
loc_134E5:                                        //loc_134E5:
    _ax = memory16(_ds, 0x8EB2);                  //mov ax, word_313E2
    if (memory(_ds, _si + 39) != 0)               //jnz short loc_134F1
      goto loc_134F1;
    _ax = memory16(_ds, 0x8EB0);                  //mov ax, word_313E0
loc_134F1:                                        //loc_134F1:
    _bx = 0x8e8c;                                 //mov bx, 8E8Ch
    _cx = 0x0008;                                 //mov cx, 8
loc_134F7:                                        //loc_134F7:
    if (_ax == memory16(_ds, _bx))                //jz short loc_13502
      goto loc_13502;
    _bx += 0x0004;                                //add bx, 4
    if (--_cx)                                    //loop loc_134F7
      goto loc_134F7;
    goto loc_1350A;                               //jmp short loc_1350A
loc_13502:                                        //loc_13502:
    _ax = memory16(_ds, _di + 4);                 //mov ax, [di+4]
    memory16(_ds, _bx + 2) += _ax;                //add [bx+2], ax
    goto locret_13528;                            //jmp short locret_13528
loc_1350A:                                        //loc_1350A:
    _bx = 0x8e8c;                                 //mov bx, 8E8Ch
    _cx = 0x0008;                                 //mov cx, 8
loc_13510:                                        //loc_13510:
    if (memory16(_ds, _bx) == 0)                  //jz short loc_1351C
      goto loc_1351C;
    _bx += 0x0004;                                //add bx, 4
    if (--_cx)                                    //loop loc_13510
      goto loc_13510;
    goto locret_13528;                            //jmp short locret_13528
loc_1351C:                                        //loc_1351C:
    memory16(_ds, _bx) = _ax;                     //mov [bx], ax
    _ax = memory16(_ds, _di + 4);                 //mov ax, [di+4]
    memory16(_ds, _bx + 2) = _ax;                 //mov [bx+2], ax
    memory16(_ds, 0x91AC) += 1;                   //inc word_316DC
locret_13528:                                     //locret_13528:
    return;
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

void sub_1655B()
{
    WORD _cs = seg000 ;
    if (memory(_ds, 0x922C) != 0)                 //jnz short loc_16590
      goto loc_16590;
    _ax = memory16(_ds, 0x9190);                  //mov ax, word_316C0
    _ax = _ax + memory16(_ds, 0x9F16);            //add ax, word_32446
    if ((short)_ax >= (short)0x0a80)              //jge short loc_16590
      goto loc_16590;
    memory(_ds, 0x8FB0) = 0xff;                   //mov byte_314E0, 0FFh
    memory(_ds, 0x922C) = 0xff;                   //mov byte_3175C, 0FFh
    memory16(_ds, 0x9190) = 2496;                 //mov word_316C0, 9C0h
    memory16(_ds, 0x91AA) = 2496;                 //mov word_316DA, 9C0h
    memory16(_ds, 0x918E) = 6240;                 //mov word_316BE, 1860h
    memory16(_ds, 0x9196) = 0;                    //mov word_316C6, 0
loc_16590:                                        //loc_16590:
    if ((short)memory16(_ds, 0x9190) < (short)2624)//jl short loc_165DC
      goto loc_165DC;
    if ((short)memory16(_ds, 0x9190) > (short)3344)//jg short loc_165DC
      goto loc_165DC;
    if ((short)memory16(_ds, 0x91AA) >= (short)3344)//jge short loc_165AE
      goto loc_165AE;
    memory16(_ds, 0x91AA) = 3344;                 //mov word_316DA, 0D10h
loc_165AE:                                        //loc_165AE:
    _STOP_("call near ptr byte_166AB+15Ch");      //call near ptr byte_166AB+15Ch
    _di = 0x91d4;                                 //mov di, 91D4h
    _si = 0x65f6;                                 //mov si, 65F6h
    _cx = 0x10;                                   //mov cx, 10h
loc_165BA:                                        //loc_165BA:
    if (memory16(_ds, _di) == 0)                  //jz short loc_165D4
      goto loc_165D4;
    _bx = 0x0000;                                 //mov bx, 0
    _bx = _bx + memory16(_cs, _si);               //add bx, cs:[si]
    memory16(_ds, _di) -= 1;                      //dec word ptr [di]
    _bp = memory16(_ds, _di);                     //mov bp, [di]
    _bp &= 0x0003;                                //and bp, 3
    _bp <<= 1;                                    //shl bp, 1
    _ax = memory16(_cs, _bp + _si + 2);           //mov ax, cs:[bp+si+2]
    memory16(_ds, _bx) = _ax;                     //mov [bx], ax
loc_165D4:                                        //loc_165D4:
    _di += 0x0002;                                //add di, 2
    _si += 0x0a;                                  //add si, 0Ah
    if (--_cx)                                    //loop loc_165BA
      goto loc_165BA;
loc_165DC:                                        //loc_165DC:
    memory(_ds, 0x9226) = 0;                      //mov byte_31756, 0
    memory(_ds, 0x9227) = 0;                      //mov byte_31757, 0
    memory(_ds, 0x9228) = 0;                      //mov byte_31758, 0
    memory(_ds, 0x9229) = 0;                      //mov byte_31759, 0
    memory(_ds, 0x922A) = 0;                      //mov byte_3175A, 0
}

void sub_172C4()
{
    WORD _cs = seg000 ;
    if ((short)memory16(_ds, 0x9190) <= (short)448)//jle short loc_172CF
      goto loc_172CF;
    goto loc_17515;                               //jmp loc_17515
loc_172CF:                                        //loc_172CF:
    if (memory(_ds, 0x922B) == 0)                 //jz short loc_172D9
      goto loc_172D9;
    goto loc_1736A;                               //jmp loc_1736A
loc_172D9:                                        //loc_172D9:
    memory(_ds, 0x922B) = 0xff;                   //mov byte_3175B, 0FFh
    _cx = 0x0007;                                 //mov cx, 7
    _bp = _si;                                    //mov bp, si
loc_172E3:                                        //loc_172E3:
    _push(_si);                                   //push si
    sub_11022();                                  //call sub_11022
    _di = _si;                                    //mov di, si
    _si = _pop();                                 //pop si
    if (_cx != 0x0007)                            //jnz short loc_172FD
      goto loc_172FD;
    _push(_si);                                   //push si
    _si = _di;                                    //mov si, di
    _di = 0x904a;                                 //mov di, 904Ah
    sub_1077C();                                  //call sub_1077C
    _di = _si;                                    //mov di, si
    _si = _pop();                                 //pop si
    goto loc_17308;                               //jmp short loc_17308
loc_172FD:                                        //loc_172FD:
    _push(_si);                                   //push si
    _si = _di;                                    //mov si, di
    _di = _bp;                                    //mov di, bp
    sub_1077C();                                  //call sub_1077C
    _di = _si;                                    //mov di, si
    _si = _pop();                                 //pop si
loc_17308:                                        //loc_17308:
    memory16(_ds, _di) = 0xfc;                    //mov word ptr [di], 0FCh
    if (_cx & _cx)                                //jnz short loc_17314
      goto loc_17314;
    memory16(_ds, _di) = 256;                     //mov word ptr [di], 100h
loc_17314:                                        //loc_17314:
    memory16(_ds, _di + 2) = 29149;               //mov word ptr [di+2], 71DDh
    memory16(_ds, _di + 4) = 2131;                //mov word ptr [di+4], 853h
    memory16(_ds, _di + 6) = 15001;               //mov word ptr [di+6], 3A99h
    memory16(_ds, _di + 12) = 11791;              //mov word ptr [di+0Ch], 2E0Fh
    memory16(_ds, _di + 14) = 0;                  //mov word ptr [di+0Eh], 0
    memory16(_ds, _di + 72) = 0;                  //mov word ptr [di+48h], 0
    memory16(_ds, _di + 16) = _bp;                //mov [di+10h], bp
    _bp = _di;                                    //mov bp, di
    memory(_ds, _di + 39) = 0;                    //mov byte ptr [di+27h], 0
    memory(_ds, _di + 74) = 0xff;                 //mov byte ptr [di+4Ah], 0FFh
    memory16(_ds, _di + 22) = 0xff9c;             //mov word ptr [di+16h], 0FF9Ch
    memory16(_ds, _di + 40) = 1000;               //mov word ptr [di+28h], 3E8h
    memory16(_ds, _di + 44) = 1000;               //mov word ptr [di+2Ch], 3E8h
    _cx -= 1;                                     //dec cx
    if ((short)_cx >= 0)                          //jns short loc_172E3
      goto loc_172E3;
    memory16(_ds, _si + 28) = 0;                  //mov word ptr [si+1Ch], 0
    memory16(_ds, _si + 30) = 0;                  //mov word ptr [si+1Eh], 0
    memory16(_ds, _si + 60) = 0;                  //mov word ptr [si+3Ch], 0
    memory16(_ds, _si + 62) = 0;                  //mov word ptr [si+3Eh], 0
    memory16(_ds, _si + 64) = 0;                  //mov word ptr [si+40h], 0
loc_1736A:                                        //loc_1736A:
    if ((short)memory16(_ds, 0x91AA) > (short)448)//jg short loc_17378
      goto loc_17378;
    memory16(_ds, 0x91AA) = 448;                  //mov word_316DA, 1C0h
loc_17378:                                        //loc_17378:
    memory16(_ds, _si + 40) = 0x80;               //mov word ptr [si+28h], 80h
    memory16(_ds, _si + 44) = 0xc8;               //mov word ptr [si+2Ch], 0C8h
    _ax = memory16(_ds, _si + 22);                //mov ax, [si+16h]
    _ax = _ax - memory16(_ds, 0x9190);            //sub ax, word_316C0
    _ax += 0x0004;                                //add ax, 4
    memory16(_ds, _si + 42) = _ax;                //mov [si+2Ah], ax
    _ax += 0x50;                                  //add ax, 50h
    memory16(_ds, _si + 46) = _ax;                //mov [si+2Eh], ax
    if (memory16(_ds, _si + 26) != 0)             //jnz short loc_173B6
      goto loc_173B6;
    _ax = 0x30;                                   //mov ax, 30h
    if ((short)memory16(_ds, 0x9190) <= (short)_ax)//jle short loc_173A7
      goto loc_173A7;
    goto loc_174B3;                               //jmp loc_174B3
loc_173A7:                                        //loc_173A7:
    memory16(_ds, _si + 26) = 1;                  //mov word ptr [si+1Ah], 1
    memory16(_ds, _si + 32) = 0;                  //mov word ptr [si+20h], 0
    memory16(_ds, _si + 34) = 0xaa;               //mov word ptr [si+22h], 0AAh
loc_173B6:                                        //loc_173B6:
    if ((short)memory16(_ds, _si + 26) < 0 /*CHECK*/)//js short loc_173D3
      goto loc_173D3;
    if ((short)memory16(_ds, _si + 66) >= (short)0x0b)
      goto loc_173DC;
    if (memory16(_ds, _si + 66) != 0)             //jnz short loc_173CE
      goto loc_173CE;
    memory16(_ds, 0x8E8A) = 1;                    //mov word_313BA, 1
loc_173CE:                                        //loc_173CE:
    memory16(_ds, _si + 66) += 1;                 //inc word ptr [si+42h]
    goto loc_173DC;                               //jmp short loc_173DC
loc_173D3:                                        //loc_173D3:
    if (memory16(_ds, _si + 66) == 0)             //jz short loc_173DC
      goto loc_173DC;
    memory16(_ds, _si + 66) -= 1;                 //dec word ptr [si+42h]
loc_173DC:                                        //loc_173DC:
    memory16(_ds, _si + 26) += 1;                 //inc word ptr [si+1Ah]
    if (memory16(_ds, _si + 26) == 0)             //jz short loc_173DC
      goto loc_173DC;
    if ((short)memory16(_ds, _si + 26) < (short)0x64)//jl short loc_173EC
      goto loc_173EC;
    memory16(_ds, _si + 26) = 0xffd8;             //mov word ptr [si+1Ah], 0FFD8h
loc_173EC:                                        //loc_173EC:
    _ax = memory16(_ds, 0x919C);                  //mov ax, word_316CC
    _ax &= 0x7f;                                  //and ax, 7Fh
    if (!(_ax & 0x40))                            //jz short loc_173FC
      goto loc_173FC;
    _ax -= 0x7f;                                  //sub ax, 7Fh
    _ax = -_ax;                                   //neg ax
loc_173FC:                                        //loc_173FC:
    _cbw();                                       //cbw
    _ax += 0x20;                                  //add ax, 20h
    memory16(_ds, _si + 28) = _ax;                //mov [si+1Ch], ax
    _ax = memory16(_ds, 0x919C);                  //mov ax, word_316CC
    _ax += 0x50;                                  //add ax, 50h
    _ax &= 0xff;                                  //and ax, 0FFh
    if (!(_ax & 0x80))                            //jz short loc_17413
      goto loc_17413;
    _al = (~_al);                                 //not al
loc_17413:                                        //loc_17413:
    _ax -= 0x40;                                  //sub ax, 40h
    _cwd();                                       //cwd
    _dh = _dl;                                    //mov dh, dl
    _dl = _ah;                                    //mov dl, ah
    _ah = _al;                                    //mov ah, al
    _al = _al ^ _al;                              //xor al, al
    _flags.carry = !!(_ah & 0x80);                //shl ah, 1
    _ah <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = !!(_ah & 0x80);                //shl ah, 1
    _ah <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    memory16(_ds, _si + 60) = _ax;                //mov [si+3Ch], ax
    memory16(_ds, _si + 62) = _dx;                //mov [si+3Eh], dx
    _ax = memory16(_ds, 0x919C);                  //mov ax, word_316CC
    _ax += 0xa0;                                  //add ax, 0A0h
    _ax &= 0x01ff;                                //and ax, 1FFh
    if (!(_ax & 0x0100))                          //jz short loc_1743E
      goto loc_1743E;
    _ax = _ax ^ 0x01ff;                           //xor ax, 1FFh
loc_1743E:                                        //loc_1743E:
    _ax -= 0x80;                                  //sub ax, 80h
    _cl = 0x05;                                   //mov cl, 5
    _ax <<= _cl;                                  //shl ax, cl
    memory16(_ds, _si + 64) = _ax;                //mov [si+40h], ax
    _ax = memory16(_ds, _si + 32);                //mov ax, [si+20h]
    _ax = _ax + memory16(_ds, _si + 22);          //add ax, [si+16h]
    if ((short)_ax >= (short)0x10)                //jge short loc_1745B
      goto loc_1745B;
    _ax = 0x10;                                   //mov ax, 10h
    memory16(_ds, _si + 34) = 0;                  //mov word ptr [si+22h], 0
loc_1745B:                                        //loc_1745B:
    if ((short)_ax <= (short)0x01e0)              //jle short loc_17468
      goto loc_17468;
    _ax = 0x01e0;                                 //mov ax, 1E0h
    memory16(_ds, _si + 34) = 0;                  //mov word ptr [si+22h], 0
loc_17468:                                        //loc_17468:
    memory16(_ds, _si + 22) = _ax;                //mov [si+16h], ax
    memory16(_ds, _si + 34) -= 1;                 //dec word ptr [si+22h]
    if ((short)memory16(_ds, _si + 34) >= 0)      //jns short loc_174A9
      goto loc_174A9;
    if (memory16(_ds, _si + 32) != 0xffff)        //jnz short loc_17482
      goto loc_17482;
    memory16(_ds, _si + 32) = 0;                  //mov word ptr [si+20h], 0
    memory16(_ds, _si + 34) = 0xaa;               //mov word ptr [si+22h], 0AAh
    goto loc_174A9;                               //jmp short loc_174A9
loc_17482:                                        //loc_17482:
    if (memory16(_ds, _si + 32) != 1)             //jnz short loc_17494
      goto loc_17494;
    memory16(_ds, _si + 32) = 0;                  //mov word ptr [si+20h], 0
    memory16(_ds, _si + 34) = 0x3c;               //mov word ptr [si+22h], 3Ch
    goto loc_174A9;                               //jmp short loc_174A9
loc_17494:                                        //loc_17494:
    memory16(_ds, _si + 34) = 0x32;               //mov word ptr [si+22h], 32h
    memory16(_ds, _si + 32) = 1;                  //mov word ptr [si+20h], 1
    if (memory16(_ds, _si + 22) == 0x10)          //jz short loc_174A9
      goto loc_174A9;
    memory16(_ds, _si + 32) = 0xffff;             //mov word ptr [si+20h], 0FFFFh
loc_174A9:                                        //loc_174A9:
    _ax = 0x1e;                                   //mov ax, 1Eh
    _ax = _ax - memory16(_ds, _si + 36);          //sub ax, [si+24h]
    memory(_ds, 0x91FE) += _al;                   //add byte ptr word_3172E, al
loc_174B3:                                        //loc_174B3:
    _bx = memory16(_ds, 0x919C);                  //mov bx, word_316CC
    _bx &= 0x0c;                                  //and bx, 0Ch
    _bx >>= 1;                                    //shr bx, 1
    _bx = memory16(_cs, _bx + 30436);             //mov bx, cs:[bx+76E4h]
    _di = 0x769e;                                 //mov di, 769Eh
    _ax = memory16(_cs, _bx);                     //mov ax, cs:[bx]
    memory16(_cs, _di) = _ax;                     //mov cs:[di], ax
    _ax = memory16(_cs, _bx + 2);                 //mov ax, cs:[bx+2]
    memory16(_cs, _di + 2) = _ax;                 //mov cs:[di+2], ax
    _di += 0x0004;                                //add di, 4
    _bx += 0x0004;                                //add bx, 4
    _ax = memory16(_cs, _bx);                     //mov ax, cs:[bx]
    memory16(_cs, _di) = _ax;                     //mov cs:[di], ax
    _ax = memory16(_cs, _bx + 2);                 //mov ax, cs:[bx+2]
    memory16(_cs, _di + 2) = _ax;                 //mov cs:[di+2], ax
    _bx += 0x0004;                                //add bx, 4
    _di += 0x0008;                                //add di, 8
    _ax = memory16(_cs, _bx);                     //mov ax, cs:[bx]
    memory16(_cs, _di) = _ax;                     //mov cs:[di], ax
    _ax = memory16(_cs, _bx + 2);                 //mov ax, cs:[bx+2]
    memory16(_cs, _di + 2) = _ax;                 //mov cs:[di+2], ax
    _di += 0x0004;                                //add di, 4
    _bx += 0x0004;                                //add bx, 4
    _ax = memory16(_cs, _bx);                     //mov ax, cs:[bx]
    memory16(_cs, _di) = _ax;                     //mov cs:[di], ax
    _ax = memory16(_cs, _bx + 2);                 //mov ax, cs:[bx+2]
    memory16(_cs, _di + 2) = _ax;                 //mov cs:[di+2], ax
    if (memory16(_ds, _si + 26) == 0)             //jz short loc_17515
      goto loc_17515;
    return;                                       //retn
loc_17515:                                        //loc_17515:
    memory16(_ds, _si + 40) = 1000;               //mov word ptr [si+28h], 3E8h
    memory16(_ds, _si + 44) = 1000;               //mov word ptr [si+2Ch], 3E8h
}

void sub_1EC6F();
void sub_1EBD0()
{
    memory(_ds, 0x8F52) = 0;                      //mov byte_31482, 0
    goto loc_1EBDC;                               //jmp short loc_1EBDC
loc_1EBD7:                                        //loc_1EBD7:
    memory(_ds, 0x8F52) = 0xff;                   //mov byte_31482, 0FFh
loc_1EBDC:                                        //loc_1EBDC:
    _bp = 0xa000;                                 //mov bp, 0A000h
    _es = _bp;                                    //mov es, bp
loc_1EBE1:                                        //loc_1EBE1:
    if ((short)_dx > (short)0xfff0)               //jg short loc_1EBF2
      goto loc_1EBF2;
    _si += _ax;                                   //add si, ax
    _si += _ax;                                   //add si, ax
    _dx += 0x10;                                  //add dx, 10h
    _bx -= 1;                                     //dec bx
    if (_bx != 0)                                 //jnz short loc_1EBE1
      goto loc_1EBE1;
    goto loc_1EC6A;                               //jmp short loc_1EC6A
loc_1EBF2:                                        //loc_1EBF2:
    _di = memory16(_ds, 0x425B);                  //mov di, word_2C78B
    _bp = _di;                                    //mov bp, di
    _bp += 0x1ba8;                                //add bp, 1BA8h
    _cx >>= 1;                                    //shr cx, 1
    _cx >>= 1;                                    //shr cx, 1
    _di += _cx;                                   //add di, cx
    _cx = _ax;                                    //mov cx, ax
    if ((short)_dx >= 0)                        //jns short loc_1EC21
      goto loc_1EC21;
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
loc_1EC0A:                                        //loc_1EC0A:
    _push(_cx);                                   //push cx
    _cx = 0x10;                                   //mov cx, 10h
    _cx += _dx;                                   //add cx, dx
    sub_1EC6F();                                  //call sub_1EC6F
    _di += 0x0002;                                //add di, 2
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_1EC0A
      goto loc_1EC0A;
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
    _dx += 0x10;                                  //add dx, 10h
    _bx -= 1;                                     //dec bx
    if (_bx == 0)                                 //jz short loc_1EC6A
      goto loc_1EC6A;
loc_1EC21:                                        //loc_1EC21:
    _ax = 0x28;                                   //mov ax, 28h
    _ax = _dx * _al;                              //mul dx
    _di += _ax;                                   //add di, ax
loc_1EC28:                                        //loc_1EC28:
    if ((short)_di >= (short)_bp)                 //jge short loc_1EC48
      goto loc_1EC48;
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
loc_1EC2E:                                        //loc_1EC2E:
    _push(_cx);                                   //push cx
    _cx = 0x10;                                   //mov cx, 10h
    _dx = _dx ^ _dx;                              //xor dx, dx
    sub_1EC6F();                                  //call sub_1EC6F
    _di += 0x0002;                                //add di, 2
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_1EC2E
      goto loc_1EC2E;
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
    _di += 0x0280;                                //add di, 280h
    _bx -= 1;                                     //dec bx
    if (_bx != 0)                                 //jnz short loc_1EC28
      goto loc_1EC28;
    goto loc_1EC6A;                               //jmp short loc_1EC6A
loc_1EC48:                                        //loc_1EC48:
    _push(_di);                                   //push di
    _di -= _bp;                                   //sub di, bp
    _ax = _di;                                    //mov ax, di
    _di = _pop();                                 //pop di
    _dx = _dx ^ _dx;                              //xor dx, dx
    _bp = 0x28;                                   //mov bp, 28h
    _div(_bp);                                    //div bp
    _ax -= 0x0f;                                  //sub ax, 0Fh
    _ax = -_ax;                                   //neg ax
    _ASSERT(0);
    if (_ax <= 0)                                  //jle short loc_1EC6A
      goto loc_1EC6A;
loc_1EC5C:                                        //loc_1EC5C:
    _push(_cx);                                   //push cx
    _cx = _ax;                                    //mov cx, ax
    _dx = _dx ^ _dx;                              //xor dx, dx
    sub_1EC6F();                                  //call sub_1EC6F
    _di += 0x0002;                                //add di, 2
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_1EC5C
      goto loc_1EC5C;
loc_1EC6A:                                        //loc_1EC6A:
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
}
void sub_10941()
{
    WORD _cs = seg000 ;
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    _ASSERT(_bp == 12);                           //call cs:off_1094F[bp]
    sub_1EBD0();
}

void sub_17520()
{
    WORD _cs = seg000 ;
    if ((short)memory16(_ds, 0x9190) >= (short)640)//jge short locret_17568
      goto locret_17568;
    _ax = 0x0006;                                 //mov ax, 6
    _bx = 0x0007;                                 //mov bx, 7
    _dx = memory16(_ds, _si + 22);                //mov dx, [si+16h]
    _dx = _dx - memory16(_ds, 0x9190);            //sub dx, word_316C0
    _cx = 0x38;                                   //mov cx, 38h
    _push(_si);                                   //push si
    _si = 0x7660;                                 //mov si, 7660h
    sub_10941();                                  //call sub_10941
    _si = _pop();                                 //pop si
    _bx = memory16(_ds, 0x91FE);                  //mov bx, word_3172E
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx &= 0x0006;                                //and bx, 6
    _cx = 0x98;                                   //mov cx, 98h
    _dx = memory16(_ds, _si + 22);                //mov dx, [si+16h]
    _dx = _dx - memory16(_ds, 0x9190);            //sub dx, word_316C0
    _dx += 0x42;                                  //add dx, 42h
    _push(_si);                                   //push si
    _si = memory16(_cs, _bx + 30460);             //mov si, cs:[bx+76FCh]
    sub_10875();                                  //call sub_10875
    _si = _pop();                                 //pop si
locret_17568:                                     //locret_17568:
    return;
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


void sub_1EC6F()
{
    std::cout << "sub_1EC6F - unconfirmed ss operation\n";
    WORD _ss = seg008;
    
    WORD _cs = seg000 ;
    _push(_ax);                                   //push ax
    _ax = memory16(_cs, _si);                     //mov ax, cs:[si]
    _si += 0x0002;                                //add si, 2
    _flags.carry = _ax & 1;                       //shr ax, 1
    _ax >>= 1;
    if (_ax != 0)                                 //jnz short loc_1EC7D
      goto loc_1EC7D;
    goto loc_1EDCF;                               //jmp loc_1EDCF
loc_1EC7D:                                        //loc_1EC7D:
    if (_flags.carry)                             //jb short loc_1ECD8
      goto loc_1ECD8;
    if (memory(_ds, 0x8F52) == 0)                 //jz short loc_1ECAE
      goto loc_1ECAE;
    _push(_dx);                                   //push dx
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0700;                                 //mov ax, 700h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
loc_1EC94:                                        //loc_1EC94:
    memory(_es, _di) = _al;                       //mov es:[di], al
    memory(_es, _di + 1) = _al;                   //mov es:[di+1], al
    _di += 0x28;                                  //add di, 28h
    if (--_cx)                                    //loop loc_1EC94
      goto loc_1EC94;
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0001;                                 //mov ax, 1
    _out(_dx, _ax);                               //out dx, ax
    _dx = _pop();                                 //pop dx
    goto loc_1EDCF;                               //jmp loc_1EDCF
loc_1ECAE:                                        //loc_1ECAE:
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
    _push(_dx);                                   //push dx
    _push(_ds);                                   //push ds
    _si = _ax;                                    //mov si, ax
    _si -= _dx;                                   //sub si, dx
    _si -= _dx;                                   //sub si, dx
    _ax = 0xa400;                                 //mov ax, 0A400h
    _ds = _ax;                                    //mov ds, ax
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0105;                                 //mov ax, 105h
    _out(_dx, _ax);                               //out dx, ax
loc_1ECC5:                                        //loc_1ECC5:
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += 0x26;                                  //add di, 26h
    if (--_cx)                                    //loop loc_1ECC5
      goto loc_1ECC5;
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _ds = _pop();                                 //pop ds
    _dx = _pop();                                 //pop dx
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
    goto loc_1EDCF;                               //jmp loc_1EDCF
loc_1ECD8:                                        //loc_1ECD8:
    if (memory(_ds, 0x8F52) == 0)                 //jz short loc_1ED27
      goto loc_1ED27;
    _push(_dx);                                   //push dx
    _push(_si);                                   //push si
    _si = _ax;                                    //mov si, ax
    _si -= _dx;                                   //sub si, dx
    _si -= _dx;                                   //sub si, dx
    _si += 0x5538;                                //add si, 5538h
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0700;                                 //mov ax, 700h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _al = 0x08;                                   //mov al, 8
    _out(_dx, _al);                               //out dx, al
    _dx += 1;                                     //inc dx
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
loc_1ECFC:                                        //loc_1ECFC:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _out(_dx, _al);                               //out dx, al
    _ah = memory(_es, _di);                       //mov ah, es:[di]
    memory(_es, _di) = _al;                       //mov es:[di], al
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _out(_dx, _al);                               //out dx, al
    _ah = memory(_es, _di + 1);                   //mov ah, es:[di+1]
    memory(_es, _di + 1) = _al;                   //mov es:[di+1], al
    _di += 0x28;                                  //add di, 28h
    if (--_cx)                                    //loop loc_1ECFC
      goto loc_1ECFC;
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
    _dx -= 1;                                     //dec dx
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0001;                                 //mov ax, 1
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0xff08;                                 //mov ax, 0FF08h
    _out(_dx, _ax);                               //out dx, ax
    _si = _pop();                                 //pop si
    _dx = _pop();                                 //pop dx
    goto loc_1EDCF;                               //jmp loc_1EDCF
loc_1ED27:                                        //loc_1ED27:
    _push(_cx);                                   //push cx
    _push(_dx);                                   //push dx
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _si = _ax;                                    //mov si, ax
    _si -= _dx;                                   //sub si, dx
    _si -= _dx;                                   //sub si, dx
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _al = 0x08;                                   //mov al, 8
    _out(_dx, _al);                               //out dx, al
    _dx += 1;                                     //inc dx
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
    _si += 0x5538;                                //add si, 5538h
loc_1ED43:                                        //loc_1ED43:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _out(_dx, _al);                               //out dx, al
    memory(_es, _di) &= _al;                      //and es:[di], al
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _out(_dx, _al);                               //out dx, al
    memory(_es, _di + 1) &= _al;                  //and es:[di+1], al
    _di += 0x28;                                  //add di, 28h
    if (--_cx)                                    //loop loc_1ED43
      goto loc_1ED43;
    _dx -= 1;                                     //dec dx
    _ax = 0x0001;                                 //mov ax, 1
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0xff08;                                 //mov ax, 0FF08h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x1003;                                 //mov ax, 1003h
    _out(_dx, _ax);                               //out dx, ax
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
    _push(_ds);                                   //push ds
    _ax = 0xa400;                                 //mov ax, 0A400h
    _ds = _ax;                                    //mov ds, ax
    memory(_ss, 496) = 0;                      //mov ss:byte_447B0, 0
    memory(_ss, 497) = 1;                      //mov ss:byte_447B0+1, 1
loc_1ED75:                                        //loc_1ED75:
    _dx = 0x03c4;                                 //mov dx, 3C4h
    _ah = memory(_ss, 497);                    //mov ah, ss:byte_447B0+1
    _al = 0x02;                                   //mov al, 2
    _out(_dx, _ax);                               //out dx, ax
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ah = memory(_ss, 496);                    //mov ah, ss:byte_447B0
    _al = 0x04;                                   //mov al, 4
    _out(_dx, _ax);                               //out dx, ax
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
loc_1ED8E:                                        //loc_1ED8E:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _ah = memory(_es, _di);                       //mov ah, es:[di]
    memory(_es, _di) = _al;                       //mov es:[di], al
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _ah = memory(_es, _di + 1);                   //mov ah, es:[di+1]
    memory(_es, _di + 1) = _al;                   //mov es:[di+1], al
    _di += 0x28;                                  //add di, 28h
    if (--_cx)                                    //loop loc_1ED8E
      goto loc_1ED8E;
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
#warning kokotina!
    memory(_ss, 496) += 1;                     //inc ss:byte_447B0
    memory(_ss, 497) <<= 1;                    //shl ss:byte_447B0+1, 1
    if ((char)memory(_ss, 496) < (char)4)      //jl short loc_1ED75
      goto loc_1ED75;
    _dx = 0x03c4;                                 //mov dx, 3C4h
    _ax = 0x0f02;                                 //mov ax, 0F02h
    _out(_dx, _ax);                               //out dx, ax
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0003;                                 //mov ax, 3
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0004;                                 //mov ax, 4
    _out(_dx, _ax);                               //out dx, ax
    _ds = _pop();                                 //pop ds
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
    _dx = _pop();                                 //pop dx
    _cx = _pop();                                 //pop cx
loc_1EDCF:                                        //loc_1EDCF:
    _ax = _pop();                                 //pop ax
}

void sub_14871()
{
    WORD _cs = seg000 ;
    _ax = memory16(_ds, _si + 66);                //mov ax, [si+42h]
    memory16(_ds, 0xFCFE) = _ax;                  //mov word_3822E, ax
    if (!(_ax & _ax))                             //jz short locret_1489D
      goto locret_1489D;
    if (memory16(_ds, _si + 26) != 0)             //jnz short loc_14884
      goto loc_14884;
    goto loc_1499F;                               //jmp loc_1499F
loc_14884:                                        //loc_14884:
    if ((short)memory16(_ds, _si + 26) >= 0 /*CHECK*/)
      goto loc_1489E;
    _ax = memory16(_ds, _si + 26);                //mov ax, [si+1Ah]
    memory16(_ds, 0xFCFE) += _ax;                 //add word_3822E, ax
    if ((short)memory16(_ds, 0xFCFE) <= (short)0) //jle short loc_14897
      goto loc_14897;
    goto loc_1499F;                               //jmp loc_1499F
loc_14897:                                        //loc_14897:
    _ax = memory16(_ds, 0xFCFE);                  //mov ax, word_3822E
    memory16(_ds, _si + 26) = _ax;                //mov [si+1Ah], ax
locret_1489D:                                     //locret_1489D:
    return;                                       //retn
loc_1489E:                                        //loc_1489E:
    _di = 0x6116;                                 //mov di, 6116h
    _ax = memory16(_ds, _si + 18);                //mov ax, [si+12h]
    memory16(_ds, 0xFCE2) = _ax;                  //mov word_38212, ax
    _ax = memory16(_ds, _si + 20);                //mov ax, [si+14h]
    memory16(_ds, 0xFCE4) = _ax;                  //mov word_38214, ax
    _ax = memory16(_ds, _si + 22);                //mov ax, [si+16h]
    memory16(_ds, 0xFCE6) = _ax;                  //mov word_38216, ax
    _ax = memory16(_ds, _si + 24);                //mov ax, [si+18h]
    memory16(_ds, 0xFCE8) = _ax;                  //mov word_38218, ax
    _ax = memory16(_ds, _si + 28);                //mov ax, [si+1Ch]
    memory16(_ds, 0xFCEE) = _ax;                  //mov word_3821E, ax
    _ax = memory16(_ds, _si + 30);                //mov ax, [si+1Eh]
    memory16(_ds, 0xFCF0) = _ax;                  //mov word_38220, ax
    _ax = memory16(_ds, _si + 60);                //mov ax, [si+3Ch]
    memory16(_ds, 0xFCF2) = _ax;                  //mov word_38222, ax
    _ax = memory16(_ds, _si + 62);                //mov ax, [si+3Eh]
    memory16(_ds, 0xFCF4) = _ax;                  //mov word_38224, ax
    _ax = memory16(_ds, _si + 64);                //mov ax, [si+40h]
    _cwd();                                       //cwd
    memory16(_ds, 0xFCF6) = _ax;                  //mov word_38226, ax
    memory16(_ds, 0xFCF8) = _dx;                  //mov word_38228, dx
    goto loc_1492D;                               //jmp short loc_1492D
loc_148DE:                                        //loc_148DE:
    _bx = memory16(_ds, 0xFCEE);                  //mov bx, word_3821E
    _ah = memory(_cs, _bx + _di);                 //mov ah, cs:[bx+di]
    _cwd();                                       //cwd
    _flags.carry = !!(_ah & 0x80);                //shl ah, 1
    _ah <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = !!(_ah & 0x80);                //shl ah, 1
    _ah <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = (memory(_ds, 0xFCE9) + _ah) >= 0x100;
    memory(_ds, 0xFCE9) += _ah;
    memory16(_ds, 0xFCE6) = memory16(_ds, 0xFCE6) + _dx + _flags.carry;;
    _ah = memory(_cs, _bx + _di + 64);            //mov ah, cs:[bx+di+40h]
    _cwd();                                       //cwd
    _flags.carry = !!(_ah & 0x80);                //shl ah, 1
    _ah <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = !!(_ah & 0x80);                //shl ah, 1
    _ah <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = (memory(_ds, 0xFCE5) + _ah) >= 0x100;
    memory(_ds, 0xFCE5) += _ah;
    memory16(_ds, 0xFCE2) = memory16(_ds, 0xFCE2) + _dx + _flags.carry;;
    _ax = memory16(_ds, 0xFCF2);                  //mov ax, word_38222
    _flags.carry = (memory16(_ds, 0xFCF0) + _ax) > 0x10000;
    memory16(_ds, 0xFCF0) += _ax;                 //add word_38220, ax
    _ax = memory16(_ds, 0xFCF4);                  //mov ax, word_38224
    memory16(_ds, 0xFCEE) = memory16(_ds, 0xFCEE) + _ax + _flags.carry;
    memory16(_ds, 0xFCEE) &= 0xff;                //and word_3821E, 0FFh
    _ax = memory16(_ds, 0xFCF6);                  //mov ax, word_38226
    _flags.carry = (memory16(_ds, 0xFCF2) + _ax) > 0x10000;
    memory16(_ds, 0xFCF2) += _ax;                 //add word_38222, ax
    _ax = memory16(_ds, 0xFCF8);                  //mov ax, word_38228
    memory16(_ds, 0xFCF4) = memory16(_ds, 0xFCF4) + _ax + _flags.carry;
loc_1492D:                                        //loc_1492D:
    memory16(_ds, 0xFCFE) -= 1;                   //dec word_3822E
    if ((short)memory16(_ds, 0xFCFE) < 0)         //js short loc_1496E
      goto loc_1496E;
    memory16(_ds, _si + 26) -= 1;                 //dec word ptr [si+1Ah]
    if ((short)memory16(_ds, _si + 26) >= 0)      //jns short loc_148DE
      goto loc_148DE;
    memory16(_ds, 0xFCFE) += 1;                   //inc word_3822E
    _ax = memory16(_ds, 0xFCE2);                  //mov ax, word_38212
    memory16(_ds, _si + 18) = _ax;                //mov [si+12h], ax
    _ax = memory16(_ds, 0xFCE4);                  //mov ax, word_38214
    memory16(_ds, _si + 20) = _ax;                //mov [si+14h], ax
    _ax = memory16(_ds, 0xFCE6);                  //mov ax, word_38216
    memory16(_ds, _si + 22) = _ax;                //mov [si+16h], ax
    _ax = memory16(_ds, 0xFCE8);                  //mov ax, word_38218
    memory16(_ds, _si + 24) = _ax;                //mov [si+18h], ax
    _ax = memory16(_ds, 0xFCEE);                  //mov ax, word_3821E
    memory16(_ds, _si + 28) = _ax;                //mov [si+1Ch], ax
    _ax = memory16(_ds, 0xFCF0);                  //mov ax, word_38220
    memory16(_ds, _si + 30) = _ax;                //mov [si+1Eh], ax
    _ax = memory16(_ds, 0xFCF2);                  //mov ax, word_38222
    memory16(_ds, _si + 60) = _ax;                //mov [si+3Ch], ax
    _ax = memory16(_ds, 0xFCF4);                  //mov ax, word_38224
    memory16(_ds, _si + 62) = _ax;                //mov [si+3Eh], ax
    goto loc_1499F;                               //jmp short loc_1499F
loc_1496E:                                        //loc_1496E:
    _ax = memory16(_ds, 0xFCE2);                  //mov ax, word_38212
    memory16(_ds, _si + 18) = _ax;                //mov [si+12h], ax
    _ax = memory16(_ds, 0xFCE4);                  //mov ax, word_38214
    memory16(_ds, _si + 20) = _ax;                //mov [si+14h], ax
    _ax = memory16(_ds, 0xFCE6);                  //mov ax, word_38216
    memory16(_ds, _si + 22) = _ax;                //mov [si+16h], ax
    _ax = memory16(_ds, 0xFCE8);                  //mov ax, word_38218
    memory16(_ds, _si + 24) = _ax;                //mov [si+18h], ax
    _ax = memory16(_ds, 0xFCEE);                  //mov ax, word_3821E
    memory16(_ds, _si + 28) = _ax;                //mov [si+1Ch], ax
    _ax = memory16(_ds, 0xFCF0);                  //mov ax, word_38220
    memory16(_ds, _si + 30) = _ax;                //mov [si+1Eh], ax
    _ax = memory16(_ds, 0xFCF2);                  //mov ax, word_38222
    memory16(_ds, _si + 60) = _ax;                //mov [si+3Ch], ax
    _ax = memory16(_ds, 0xFCF4);                  //mov ax, word_38224
    memory16(_ds, _si + 62) = _ax;                //mov [si+3Eh], ax
    return;                                       //retn
loc_1499F:                                        //loc_1499F:
    _di = memory16(_ds, _si + 58);                //mov di, [si+3Ah]
    _bx = memory16(_ds, _di);                     //mov bx, [di]
    switch (_bx)                                  //jmp cs:off_149A9[bx]
    {
      case 0: goto loc_149B5;
      case 2: goto loc_14A06;
      case 4: goto loc_14A36;
      case 6: goto loc_14A4F;
      case 8: goto loc_149F9;
      case 10: goto loc_149F1;
      default:
        _ASSERT(0);
    }
loc_149B5:                                        //loc_149B5:
    _ax = memory16(_ds, _si + 54);                //mov ax, [si+36h]
    if (!(_ax & _ax))                             //jz short loc_149D6
      goto loc_149D6;
    _di = 0x8e8c;                                 //mov di, 8E8Ch
    _cx = 0x0008;                                 //mov cx, 8
loc_149C2:                                        //loc_149C2:
    if (_ax == memory16(_ds, _di))                //jz short loc_149CD
      goto loc_149CD;
    _di += 0x0004;                                //add di, 4
    if (--_cx)                                    //loop loc_149C2
      goto loc_149C2;
    goto loc_149D6;                               //jmp short loc_149D6
loc_149CD:                                        //loc_149CD:
    memory16(_ds, _di) = 0;                       //mov word ptr [di], 0
    memory16(_ds, _di + 2) = 0;                   //mov word ptr [di+2], 0
loc_149D6:                                        //loc_149D6:
    if (memory(_ds, _si + 38) != 0)               //jnz short loc_149E0
      goto loc_149E0;
    sub_107C0();                                  //call sub_107C0
    return;                                       //retn
loc_149E0:                                        //loc_149E0:
    _di = memory16(_ds, _si + 68);                //mov di, [si+44h]
loc_149E3:                                        //loc_149E3:
    _push(memory16(_ds, _di + 70));               //push word ptr [di+46h]
    _si = _di;                                    //mov si, di
    sub_107C0();                                  //call sub_107C0
    _di = _pop();                                 //pop di
    if (_di & _di)                                //jnz short loc_149E3
      goto loc_149E3;
    return;                                       //retn
loc_149F1:                                        //loc_149F1:
    _di += 0x0006;                                //add di, 6
    memory16(_ds, _si + 58) = _di;                //mov [si+3Ah], di
    goto loc_1499F;                               //jmp short loc_1499F
loc_149F9:                                        //loc_149F9:
    _ax = memory16(_ds, _di + 2);                 //mov ax, [di+2]
    _di = memory16(_ds, _si + 56);                //mov di, [si+38h]
    _di += _ax;                                   //add di, ax
    memory16(_ds, _si + 58) = _di;                //mov [si+3Ah], di
    goto loc_1499F;                               //jmp short loc_1499F
loc_14A06:                                        //loc_14A06:
    _ax = memory16(_ds, _di + 2);                 //mov ax, [di+2]
    memory16(_ds, _si + 28) = _ax;                //mov [si+1Ch], ax
    memory16(_ds, _si + 30) = 0;                  //mov word ptr [si+1Eh], 0
    _ax = memory16(_ds, _di + 4);                 //mov ax, [di+4]
    _cwd();                                       //cwd
    _dl = _ah;                                    //mov dl, ah
    _ah = _al;                                    //mov ah, al
    _al = _al ^ _al;                              //xor al, al
    memory16(_ds, _si + 60) = _ax;                //mov [si+3Ch], ax
    memory16(_ds, _si + 62) = _dx;                //mov [si+3Eh], dx
    _ax = memory16(_ds, _di + 6);                 //mov ax, [di+6]
    memory16(_ds, _si + 64) = _ax;                //mov [si+40h], ax
    _ax = memory16(_ds, _di + 8);                 //mov ax, [di+8]
    memory16(_ds, _si + 26) = _ax;                //mov [si+1Ah], ax
    _di += 0x0a;                                  //add di, 0Ah
    memory16(_ds, _si + 58) = _di;                //mov [si+3Ah], di
    goto loc_1489E;                               //jmp loc_1489E
loc_14A36:                                        //loc_14A36:
    _ax = memory16(_ds, _di + 2);                 //mov ax, [di+2]
    _di += 0x0004;                                //add di, 4
    memory16(_ds, _si + 58) = _di;                //mov [si+3Ah], di
    memory16(_ds, 0xFCFE) -= _ax;                 //sub word_3822E, ax
    if ((short)memory16(_ds, 0xFCFE) <= 0)
      goto loc_14A48;
    goto loc_1499F;                               //jmp loc_1499F
loc_14A48:                                        //loc_14A48:
    _ax = memory16(_ds, 0xFCFE);                  //mov ax, word_3822E
    memory16(_ds, _si + 26) = _ax;                //mov [si+1Ah], ax
    return;                                       //retn
loc_14A4F:                                        //loc_14A4F:
    sub_14191();                                  //call sub_14191
    _ax &= 0x0e;                                  //and ax, 0Eh
    _bx = _ax;                                    //mov bx, ax
    _dx = memory16(_ds, _bx + _di + 2);           //mov dx, [bx+di+2]
    if ((short)_dx < 0)                         //js short loc_14A4F
      goto loc_14A4F;
    _di = memory16(_ds, _si + 56);                //mov di, [si+38h]
    _di += _dx;                                   //add di, dx
    memory16(_ds, _si + 58) = _di;                //mov [si+3Ah], di
    goto loc_1499F;                               //jmp loc_1499F
}

void sub_11BB4()
{
    if (!(_ax & _ax))                             //jz short loc_11BCF
      goto loc_11BCF;
    if (!(_bx & _bx))                             //jz short loc_11BE2
      goto loc_11BE2;
    if (_ax == _bx)                               //jz short loc_11BE6
      goto loc_11BE6;
    if ((short)_ax > (short)_bx)                  //jg short loc_11BD3
      goto loc_11BD3;
    _ax >>= 1;                                    //shr ax, 1
    _dx = _ax;                                    //mov dx, ax
    _ax = _ax ^ _ax;                              //xor ax, ax
    _div(_bx);                                    //div bx
    if ((short)_ax >= (short)0x3504)              //jge short loc_11BE6
      goto loc_11BE6;
loc_11BCF:                                        //loc_11BCF:
    _ax = 0x0004;                                 //mov ax, 4
    return;                                       //retn
loc_11BD3:                                        //loc_11BD3:
    _bx >>= 1;                                    //shr bx, 1
    _dx = _bx;                                    //mov dx, bx
    _bx = _ax;                                    //mov bx, ax
    _ax = _ax ^ _ax;                              //xor ax, ax
    _div(_bx);                                    //div bx
    if ((short)_ax >= (short)0x3504)              //jge short loc_11BE6
      goto loc_11BE6;
loc_11BE2:                                        //loc_11BE2:
    _ax = 0x0002;                                 //mov ax, 2
    return;                                       //retn
loc_11BE6:                                        //loc_11BE6:
    _ax = 0x0003;                                 //mov ax, 3
}

void sub_11BA2()
{
    if ((short)_ax >= 0)                        //jns short sub_11BB4
    {
      sub_11BB4();
        return;
    }
    _ax = -_ax;                                   //neg ax
    sub_11BB4();                                  //call sub_11BB4
    _ax -= 0x0008;                                //sub ax, 8
    _ax = -_ax;                                   //neg ax
    _ax &= 0x0007;                                //and ax, 7
}

void sub_11B90()
{
    if ((short)_bx >= 0)                        //jns short sub_11BA2
    {
      sub_11BA2();
    return;
    }
    _bx = -_bx;                                   //neg bx
    sub_11BA2();                                  //call sub_11BA2
    _ax -= 0x0004;                                //sub ax, 4
    _ax = -_ax;                                   //neg ax
    _ax &= 0x0007;                                //and ax, 7
}

void sub_11ED3()
{
    _push(_si);                                   //push si
    sub_11022();                                  //call sub_11022
    _di = 0x9096;                                 //mov di, 9096h
    sub_1077C();                                  //call sub_1077C
    _di = _si;                                    //mov di, si
    _si = _pop();                                 //pop si
    memory16(_ds, _di) = 0x14;                    //mov word ptr [di], 14h
    memory16(_ds, _di + 2) = 8013;                //mov word ptr [di+2], 1F4Dh
    memory16(_ds, _di + 4) = 2131;                //mov word ptr [di+4], 853h
    memory16(_ds, _di + 12) = _bp;                //mov [di+0Ch], bp
    memory16(_ds, _di + 14) = 0;                  //mov word ptr [di+0Eh], 0
    memory16(_ds, _di + 18) = _ax;                //mov [di+12h], ax
    memory16(_ds, _di + 22) = _bx;                //mov [di+16h], bx
    memory16(_ds, _di + 28) = _cx;                //mov [di+1Ch], cx
    memory16(_ds, _di + 66) = _dx;                //mov [di+42h], dx
    memory16(_ds, _di + 40) = 1000;               //mov word ptr [di+28h], 3E8h
    memory16(_ds, _di + 44) = 1000;               //mov word ptr [di+2Ch], 3E8h
}

void sub_14865()
{
    sub_14871();                                  //call sub_14871
    if (memory16(_ds, _si) == 4)                  //jz short locret_14870
      goto locret_14870;
    sub_13589();                               //jmp sub_13589
    return;
locret_14870:                                     //locret_14870:
    return;
}

void sub_1480B()
{
    sub_141B1();                                  //call sub_141B1
    sub_14865();                                  //call sub_14865
    if (memory16(_ds, _si) == 4)                  //jz short locret_14864
      goto locret_14864;
    if (memory(_ds, _si + 73) == 0)               //jz short locret_14864
      goto locret_14864;
    _al = memory(_ds, _si + 73);                  //mov al, [si+49h]
loc_1481F:                                        //loc_1481F:
    if (_al < 0x64)                               //jb short loc_14827
      goto loc_14827;
    _al -= 0x64;                                  //sub al, 64h
    goto loc_1481F;                               //jmp short loc_1481F
loc_14827:                                        //loc_14827:
    _flags.carry = (memory(_ds, _si + 72) + _al) >= 0x100;
    memory(_ds, _si + 72) += _al;
    if (!_flags.carry)                            //jnb short locret_14864
      goto locret_14864;
    sub_14191();                                  //call sub_14191
    _al &= 0x3f;                                  //and al, 3Fh
    memory(_ds, _si + 72) = _al;                  //mov [si+48h], al
    if (memory(_ds, _si + 73) >= 0x64)            //jnb short loc_14842
      goto loc_14842;
    sub_14191();                                  //call sub_14191
    _ax &= 0x0007;                                //and ax, 7
    goto loc_14852;                               //jmp short loc_14852
loc_14842:                                        //loc_14842:
    _ax = memory16(_ds, 0x9F12);                  //mov ax, word_32442
    _ax = _ax - memory16(_ds, _si + 18);          //sub ax, [si+12h]
    _dx = memory16(_ds, 0x9F16);                  //mov dx, word_32446
    _dx = _dx - memory16(_ds, _si + 22);          //sub dx, [si+16h]
    sub_11B90();                                  //call sub_11B90
loc_14852:                                        //loc_14852:
    _cx = _ax;                                    //mov cx, ax
    _ax = memory16(_ds, _si + 18);                //mov ax, [si+12h]
    _bx = memory16(_ds, _si + 22);                //mov bx, [si+16h]
    _dx = 0x0006;                                 //mov dx, 6
    _bp = memory16(_ds, 0x8E72);                  //mov bp, word_313A2
    sub_11ED3();                                  //call sub_11ED3
locret_14864:                                     //locret_14864:
    return;
}
