void start();
void sub_10115();
void sub_10155();
void sub_10171();
void sub_1017D();
void sub_10185();
void loc_1018D();
void sub_101A5();
void sub_10300();
void sub_10345();
void sub_1041A();
void sub_1043A();
void sub_1063F();
void sub_10724();
void sub_10779();
void sub_10965();
void sub_109AF();
void sub_10BEE();
void loc_10C93();
void sub_10D50();
void sub_10DE9();
void sub_10E7A();
void sub_11006();
void sub_11121();
void sub_113CA();
void sub_11452();
void sub_1166F();
void sub_11747();
void sub_1199B();
void sub_119F4();
void sub_11CEA();
void sub_12008();
void sub_122BF();
void sub_122D0();
void sub_1234E();
void sub_123E2();
void loc_13C0C();
void sub_13C21();
void sub_13C3B();
void sub_13C4F();
void sub_13C6F();
void sub_13CA1();
void sub_13CBD();
void sub_13CDF();
void sub_13E36();
void sub_13E4C();
void sub_13E72();
void sub_13E83();
void sub_13E92();
void sub_13EAF();
void sub_13F5B();
void sub_13F7A();
void sub_13FD5();
void sub_1402F();
void sub_1405E();
void sub_14104();
void loc_14132();
void sub_1413C();
void sub_1414C();
void sub_1415D();
void sub_14169();
void sub_14175();
void sub_14183();
void sub_141D3();
void sub_1420C();
void sub_14230();
void sub_14255();
void sub_142F2();
void sub_1432B();
void sub_1433D();
void sub_143BC();
void sub_14439();
void loc_14494();
void sub_1449F();
void sub_144B8();
void sub_14554();
void sub_145F4();
void sub_1463B();
void sub_1464E();
void sub_14668();
void sub_1466C();
void sub_14698();
void sub_146BA();
void sub_14822();
void sub_1485F();
void sub_14892();
void sub_14958();
void sub_14993();
void sub_149DB();
void sub_149F6();
void sub_14A7F();
void loc_14AA7();
void sub_14AE1();
void sub_14B2B();
void sub_14B57();
void sub_14B5E();
void sub_14B7B();
void sub_14BA4();
void sub_15045();
void sub_15068();
void sub_150E0();
void sub_1510D();
void sub_15140();
void sub_1515F();
void sub_1517A();
void sub_151A8();
void sub_151B8();
void sub_151C1();
void sub_15208();
void loc_15265();
void sub_1539D();
void sub_153B5();
void sub_153D8();
void sub_15409();
void sub_15441();
void sub_1547D();
void sub_15513();
void loc_15661();
void sub_1566D();
void sub_156FB();
void loc_15776();
void sub_15779();
void sub_157FD();
void sub_15844();
void sub_15943();
void sub_159F2();
void sub_15AA2();
void loc_15C58();
void sub_15CB6();
void sub_15CE3();
void sub_15D80();
void sub_15D98();
void loc_15E83();
void sub_15E9E();
void sub_15F8B();
void sub_15FCA();
void sub_16035();
void sub_1608C();
void sub_160DE();
void sub_16129();
void sub_16197();
void loc_1620D();
void sub_162FA();
void sub_16324();
void loc_16388();
void sub_163F4();
void sub_1643D();
void sub_1647D();
void sub_1666C();
void sub_166BC();
void sub_166BF();
void sub_166F1();
void sub_16721();
void sub_1674D();
void sub_16781();
void loc_167DA();
void sub_16809();
void sub_1683C();
void sub_16859();
void sub_16867();
void sub_168AB();
void sub_16903();
void sub_1691E();
void sub_16940();
void sub_16965();
void sub_1697C();
void sub_16999();
void sub_169B6();
void sub_16A19();
void loc_16A58();
void sub_16A7B();
void sub_16AAB();
void sub_16B04();
void sub_16B25();
void sub_16B6A();
void sub_16B89();
void sub_16BA4();
void sub_16C12();
void sub_16C42();
void sub_16C78();
void sub_16CBE();
void sub_16CE4();
void sub_16D11();
void sub_16D73();
void sub_16DB0();
void sub_16DF7();
void sub_16E2D();
void sub_16E94();
void sub_16EB2();
void sub_16EDB();
void sub_16EEA();
void sub_16F0B();
void sub_16F0E();
void sub_16F40();
void sub_172BC();
void sub_172F8();
void sub_17311();
void sub_1735D();
void sub_17364();
void loc_17371();
void sub_173A8();
void sub_17517();
void sub_1756B();
void loc_175C6();
void sub_17645();
void sub_1766A();
void sub_17689();
void loc_17964();
void sub_17970();
void sub_17995();
void sub_179DC();
void sub_17A03();
void loc_17A40();
void sub_17A62();
void sub_17A97();
void sub_17AA9();
void sub_17B72();
void loc_17B9D();
void sub_17CA4();
void sub_17CC9();
void sub_17CEB();
void sub_17D0D();
void sub_17D2E();
void loc_17D3C();
void sub_17D4D();
void sub_17D70();
void sub_17D97();
void sub_17DA9();
void sub_17DB7();
void sub_17EEC();
void sub_17F37();
void sub_1802F();
void sub_1805B();
void sub_18070();
void sub_18081();
void sub_18092();
void sub_180D0();
void sub_180DE();
void start()  // Entry function
{
    WORD _cs = _seg000;

    _flags.interrupt = true;                    //sti
    _dx = _dseg;                                //mov dx, seg dseg
    memory16(_cs, 0x1A3) = _dx;                 //mov cs:word_101A3, dx
    _ah = 0x30;                                 //mov ah, 30h
    _interrupt(33);                             //int 21h
    _bp = memory16(_ds, 0x2);                   //mov bp, ds:2
    _bx = memory16(_ds, 0x2C);                  //mov bx, ds:2Ch
    _ds = _dx;                                  //mov ds, dx
    memory16(_ds, 0x86) = _ax;                  //mov word_18726, ax
    memory16(_ds, 0x84) = _es;                  //mov word_18724, es
    memory16(_ds, 0x80) = _bx;                  //mov word ptr dword_1871E+2, bx
    memory16(_ds, 0x9C) = _bp;                  //mov word_1873C, bp
    memory16(_ds, 0x8A) = 0xffff;               //mov word_1872A, 0FFFFh
    sub_10155();                                //call sub_10155
    _les(_di, _ds, 0x7E);                       //les di, dword_1871E
    _ax = _di;                                  //mov ax, di
    _bx = _ax;                                  //mov bx, ax
    _cx = 0x7fff;                               //mov cx, 7FFFh
loc_1003A:                                      //loc_1003A:
    if (memory16(_es, _di) != 0x3738)           //jnz short loc_1005A
        goto loc_1005A;
    _dx = memory16(_es, _di + 2);               //mov dx, es:[di+2]
    if (_dl != 0x3d)                            //jnz short loc_1005A
        goto loc_1005A;
    _dh &= 0xdf;                                //and dh, 0DFh
    memory16(_ds, 0x8A) += 1;                   //inc word_1872A
    if (_dh != 0x59)                            //jnz short loc_1005A
        goto loc_1005A;
    memory16(_ds, 0x8A) += 1;                   //inc word_1872A
loc_1005A:                                      //loc_1005A:
    _repne_scasb();                             //repne scasb
    if (_cx == 0)                               //jcxz short loc_100C5
        goto loc_100C5;
    _bx += 1;                                   //inc bx
    if (memory(_es, _di) != _al)                //jnz short loc_1003A
        goto loc_1003A;
    _ch |= 0x80;                                //or ch, 80h
    _cx = -_cx;                                 //neg cx
    memory16(_ds, 0x7E) = _cx;                  //mov word ptr dword_1871E, cx
    _cx = 0x0001;                               //mov cx, 1
    _bx <<= _cl;                                //shl bx, cl
    _bx += 0x0008;                              //add bx, 8
    _bx &= 0xfff8;                              //and bx, 0FFF8h
    memory16(_ds, 0x82) = _bx;                  //mov word_18722, bx
    _push(_cs);                                 //push cs
    off_18FF8();                                //call off_18FF8
    _dx = _ds;                                  //mov dx, ds
    _bp -= _dx;                                 //sub bp, dx
    _di = memory16(_ds, 0x47E);                 //mov di, word_18B1E
    if (_di >= 0x0100)                          //jnb short loc_10097
        goto loc_10097;
    _di = 0x0100;                               //mov di, 100h
    memory16(_ds, 0x47E) = _di;                 //mov word_18B1E, di
loc_10097:                                      //loc_10097:
    _flags.carry = (_di + 0x0b75) >= 0x10000;   //add di, 0B75h
    _di += 0x0b75;
    if (_flags.carry)                           //jb short loc_100C5
        goto loc_100C5;
    _flags.carry = (_di + memory16(_ds, 0x41A)) >= 0x10000;
    _di = _di + memory16(_ds, 0x41A);
    if (_flags.carry)                           //jb short loc_100C5
        goto loc_100C5;
    _cl = 0x04;                                 //mov cl, 4
    _di >>= _cl;                                //shr di, cl
    _di += 1;                                   //inc di
    if (_bp < _di)                              //jb short loc_100C5
        goto loc_100C5;
    if (memory16(_ds, 0x47E) == 0x0000)         //jz short loc_100BA
        goto loc_100BA;
    if (memory16(_ds, 0x41A) != 0x0000)         //jnz short loc_100C8
        goto loc_100C8;
loc_100BA:                                      //loc_100BA:
    _di = 0x1000;                               //mov di, 1000h
    if (_bp > _di)                              //ja short loc_100C8
        goto loc_100C8;
    _di = _bp;                                  //mov di, bp
    goto loc_100C8;                             //jmp short loc_100C8
loc_100C5:                                      //loc_100C5:
    {loc_1018D(); return; };                    //
loc_100C8:                                      //loc_100C8:
    _bx = _di;                                  //mov bx, di
    _bx += _dx;                                 //add bx, dx
    memory16(_ds, 0x94) = _bx;                  //mov word_18734, bx
    memory16(_ds, 0x98) = _bx;                  //mov word_18738, bx
    _ax = memory16(_ds, 0x84);                  //mov ax, word_18724
    _bx -= _ax;                                 //sub bx, ax
    _es = _ax;                                  //mov es, ax
    _ah = 0x4a;                                 //mov ah, 4Ah
    _push(_di);                                 //push di
    _interrupt(33);                             //int 21h
    _di = _pop();                               //pop di
    _di <<= _cl;                                //shl di, cl
    _ss = _dx;                                  //mov ss, dx
    _sp = _di;                                  //mov sp, di
    sub_149F6();                                //call sub_149F6
    sub_14AE1();                                //call sub_14AE1
    _ax = _ax ^ _ax;                            //xor ax, ax
    _es = memory16(_cs, 0x1A3);                 //mov es, cs:word_101A3
    _di = 0x0966;                               //mov di, 966h
    _cx = 0x0b75;                               //mov cx, 0B75h
    _cx -= _di;                                 //sub cx, di
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    off_18FFC();                                //call off_18FFC
    _push(memory16(_ds, 0x7C));                 //push word_1871C
    _push(memory16(_ds, 0x7A));                 //push word_1871A
    _push(memory16(_ds, 0x78));                 //push word_18718
    sub_101A5();                                //call sub_101A5
    _push(_ax);                                 //push ax
    sub_1402F();                                //call sub_1402F
}

void sub_10115()
{
    WORD _cs = _seg000;

    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    sub_10171();                                //call sub_10171
    _push(_cs);                                 //push cs
    off_18FFA();                                //call off_18FFA
    _ax = _ax ^ _ax;                            //xor ax, ax
    _si = _ax;                                  //mov si, ax
    _cx = 0x002f;                               //mov cx, 2Fh
    _flags.direction = false;                   //cld
loc_1012B:                                      //loc_1012B:
    _flags.carry = (_al + memory(_ds, _si)) >= 0x100;//add al, [si]
    _al = _al + memory(_ds, _si);
    _ah = _ah + 0x00 + _flags.carry;            //adc ah, 0
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_1012B
        goto loc_1012B;
    _ax -= 0x0d36;                              //sub ax, 0D36h
    if (_ax == 0)                               //jz short loc_10143
        goto loc_10143;
    _cx = 0x0019;                               //mov cx, 19h
    _dx = 0x002f;                               //mov dx, 2Fh
    sub_10185();                                //call sub_10185
loc_10143:                                      //loc_10143:
    _bp = _sp;                                  //mov bp, sp
    _ah = 0x4c;                                 //mov ah, 4Ch
    _al = _stack16(_bp + 2);                    //mov al, [bp+2]
    _interrupt(33);                             //int 21h
}

void sub_10155()
{
    WORD _cs = _seg000;

    _push(_ds);                                 //push ds
    _ax = 0x3500;                               //mov ax, 3500h
    _interrupt(33);                             //int 21h
    memory16(_ds, 0x74) = _bx;                  //mov word_18713+1, bx
    memory16(_ds, 0x76) = _es;                  //mov word ptr unk_18716, es
    _ax = 0x2500;                               //mov ax, 2500h
    _dx = _cs;                                  //mov dx, cs
    _ds = _dx;                                  //mov ds, dx
    _dx = 0x014c;                               //mov dx, 14Ch
    _interrupt(33);                             //int 21h
    _ds = _pop();                               //pop ds
}

void sub_10171()
{
    _push(_ds);                                 //push ds
    _ax = 0x2500;                               //mov ax, 2500h
    _lds(_dx, _ds, 0x74);                       //lds dx, dword ptr word_18713+1
    _interrupt(33);                             //int 21h
    _ds = _pop();                               //pop ds
}

void sub_1017D()
{
    memory16(_ds, 0x8A) = 0x0000;               //mov word_1872A, 0
}

void sub_10185()
{
    _ah = 0x40;                                 //mov ah, 40h
    _bx = 0x0002;                               //mov bx, 2
    _interrupt(33);                             //int 21h
}

void loc_1018D()
{
    WORD _cs = _seg000;

    _cx = 0x001e;                               //mov cx, 1Eh
    _dx = _STOP_;                               //mov dx, offset unk_186F6
loc_10194:                                      //loc_10194:
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    sub_10185();                                //call sub_10185
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    sub_10115();                                //call sub_10115
    _STOP_("word_101A3 dw 0");                  //word_101A3 dw 0
}

void sub_101A5()
{
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0004;                              //sub sp, 4
    _stack16(_bp + var_4) = 0x0001;             //mov [bp+var_4], 1
    _stack16(_bp + var_2) = 0x0003;             //mov [bp+var_2], 3
    _ax = 0x2470;                               //mov ax, 2470h
    _push(_ax);                                 //push ax
    sub_1420C();                                //call sub_1420C
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_101CD
        goto loc_101CD;
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1402F();                                //call sub_1402F
    _STOP_("db 2 dup(44h)");                    //db 2 dup(44h)
loc_101CD:                                      //loc_101CD:
    _push(_ds);                                 //push ds
    _ax = 0x02b2;                               //mov ax, 2B2h
    _push(_ax);                                 //push ax
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_2]
    _push(_ax);                                 //push ax
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_4]
    _push(_ax);                                 //push ax
    sub_15AA2();                                //call sub_15AA2
    _sp += 0x000c;                              //add sp, 0Ch
    sub_1539D();                                //call sub_1539D
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_101F9
        goto loc_101F9;
    _ax = 0x02b3;                               //mov ax, 2B3h
    _push(_ax);                                 //push ax
    sub_13E36();                                //call sub_13E36
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    goto loc_102FA;                             //jmp loc_102FA
loc_101F9:                                      //loc_101F9:
    sub_1043A();                                //call sub_1043A
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_10203
        goto loc_10203;
    goto loc_102F5;                             //jmp loc_102F5
loc_10203:                                      //loc_10203:
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, 0x24E) = _ax;                 //mov word_188EE, ax
    memory16(_ds, 0x9D8) = _ax;                 //mov word_19078, ax
    sub_10300();                                //call sub_10300
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_10254
        goto loc_10254;
    _di = 0x0001;                               //mov di, 1
    goto loc_1024F;                             //jmp short loc_1024F
loc_10217:                                      //loc_10217:
    _si = _si ^ _si;                            //xor si, si
    goto loc_1023C;                             //jmp short loc_1023C
loc_1021B:                                      //loc_1021B:
    _ax = _di;                                  //mov ax, di
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _bx += _si;                                 //add bx, si
    _al = memory(_ds, _bx + 216);               //mov al, [bx+0D8h]
    _push(_ax);                                 //push ax
    _ax = _di;                                  //mov ax, di
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _bx += _si;                                 //add bx, si
    _ax = _pop();                               //pop ax
    memory(_ds, _bx + 202) = _al;               //mov [bx+0CAh], al
    _si += 1;                                   //inc si
loc_1023C:                                      //loc_1023C:
    if ((short)_si < (short)0x000e)             //jl short loc_1021B
        goto loc_1021B;
    _ax = _di;                                  //mov ax, di
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    memory16(_ds, _bx + 172) -= 1;              //dec word ptr [bx+0ACh]
    _di += 1;                                   //inc di
loc_1024F:                                      //loc_1024F:
    if ((short)_di < (short)0x0003)             //jl short loc_10217
        goto loc_10217;
loc_10254:                                      //loc_10254:
    sub_13C21();                                //call sub_13C21
    if (!(_ax & 0x0001))                        //jz short loc_10263
        goto loc_10263;
    sub_10724();                                //call sub_10724
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_102C5
        goto loc_102C5;
loc_10263:                                      //loc_10263:
    _di = 0x0001;                               //mov di, 1
    goto loc_102C0;                             //jmp short loc_102C0
loc_10268:                                      //loc_10268:
    _si = _si ^ _si;                            //xor si, si
    goto loc_102AD;                             //jmp short loc_102AD
loc_1026C:                                      //loc_1026C:
    _ax = _di;                                  //mov ax, di
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _bx += _si;                                 //add bx, si
    _al = memory(_ds, _bx + 202);               //mov al, [bx+0CAh]
    _push(_ax);                                 //push ax
    _ax = _di;                                  //mov ax, di
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _bx += _si;                                 //add bx, si
    _ax = _pop();                               //pop ax
    memory(_ds, _bx + 188) = _al;               //mov [bx+0BCh], al
    _ax = _di;                                  //mov ax, di
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _bx += _si;                                 //add bx, si
    _al = memory(_ds, _bx + 216);               //mov al, [bx+0D8h]
    _push(_ax);                                 //push ax
    _ax = _di;                                  //mov ax, di
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _bx += _si;                                 //add bx, si
    _ax = _pop();                               //pop ax
    memory(_ds, _bx + 202) = _al;               //mov [bx+0CAh], al
    _si += 1;                                   //inc si
loc_102AD:                                      //loc_102AD:
    if ((short)_si < (short)0x000e)             //jl short loc_1026C
        goto loc_1026C;
    _ax = _di;                                  //mov ax, di
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    memory16(_ds, _bx + 172) -= 1;              //dec word ptr [bx+0ACh]
    _di += 1;                                   //inc di
loc_102C0:                                      //loc_102C0:
    if ((short)_di < (short)0x0003)             //jl short loc_10268
        goto loc_10268;
loc_102C5:                                      //loc_102C5:
    sub_10BEE();                                //call sub_10BEE
    memory16(_ds, 0x98C) = 0x0040;              //mov word_1902C, 40h
    memory16(_ds, 0x98E) = 0x00e2;              //mov word_1902E, 0E2h
    memory16(_ds, 0x9E4) = 0x00ad;              //mov word_19084, 0ADh
    memory16(_ds, 0x9E6) = 0x00ad;              //mov word_19086, 0ADh
loc_102E0:                                      //loc_102E0:
    sub_109AF();                                //call sub_109AF
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_102F5
        goto loc_102F5;
    sub_12008();                                //call sub_12008
    _ax = memory16(_ds, 0x9D8);                 //mov ax, word_19078
    _ax = _ax ^ 0x0001;                         //xor ax, 1
    memory16(_ds, 0x9D8) = _ax;                 //mov word_19078, ax
    goto loc_102E0;                             //jmp short loc_102E0
loc_102F5:                                      //loc_102F5:
    sub_15CE3();                                //call sub_15CE3
loc_102FA:                                      //loc_102FA:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_10300()
{
    const int var_10 = -16;                     //var_10  = word ptr -10h
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0010;                              //sub sp, 10h
    _stack16(_bp + var_10) = 0x0000;            //mov [bp+var_10], 0
    _FIXME_;                                    //lea ax, [bp+var_10]
    _push(_ax);                                 //push ax
    _FIXME_;                                    //lea ax, [bp+var_10]
    _push(_ax);                                 //push ax
    _ax = 0x0033;                               //mov ax, 33h
    _push(_ax);                                 //push ax
    sub_14230();                                //call sub_14230
    _sp += 0x0006;                              //add sp, 6
    if (_stack16(_bp + var_10) != 0x0000)       //jnz short loc_10327
        goto loc_10327;
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_10341;                             //jmp short loc_10341
loc_10327:                                      //loc_10327:
    _stack16(_bp + var_10) = 0x0002;            //mov [bp+var_10], 2
    _FIXME_;                                    //lea ax, [bp+var_10]
    _push(_ax);                                 //push ax
    _FIXME_;                                    //lea ax, [bp+var_10]
    _push(_ax);                                 //push ax
    _ax = 0x0033;                               //mov ax, 33h
    _push(_ax);                                 //push ax
    sub_14230();                                //call sub_14230
    _sp += 0x0006;                              //add sp, 6
    _ax = 0x0001;                               //mov ax, 1
loc_10341:                                      //loc_10341:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
}

void sub_10345()
{
    const int var_C = -12;                      //var_C  = word ptr -0Ch
    const int var_A = -10;                      //var_A  = word ptr -0Ah
    const int var_8 = -8;                       //var_8  = word ptr -8
    const int var_6 = -6;                       //var_6  = word ptr -6
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x000c;                              //sub sp, 0Ch
    _bx = _stack16(_bp + arg_0);                //mov bx, [bp+arg_0]
    _bx = memory16(_ds, _bx);                   //mov bx, [bx]
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    _ax += 0x0004;                              //add ax, 4
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _stack16(_bp + var_4) = _ax;                //mov [bp+var_4], ax
    _bx = _stack16(_bp + arg_0);                //mov bx, [bp+arg_0]
    _bx = memory16(_ds, _bx);                   //mov bx, [bx]
    _ax = memory16(_ds, _bx + 2);               //mov ax, [bx+2]
    _ax += 1;                                   //inc ax
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    _stack16(_bp + var_6) = 0x0000;             //mov [bp+var_6], 0
    goto loc_1040B;                             //jmp loc_1040B
loc_10372:                                      //loc_10372:
    _bx = _stack16(_bp + var_6);                //mov bx, [bp+var_6]
    _bx <<= 1;                                  //shl bx, 1
    _bx = _bx + _stack16(_bp + arg_0);          //add bx, [bp+arg_0]
    _si = memory16(_ds, _bx);                   //mov si, [bx]
    _ax = _stack16(_bp + var_2);                //mov ax, [bp+var_2]
    _ax -= 1;                                   //dec ax
    _push(_ax);                                 //push ax
    _push(memory16(_ds, _si));                  //push word ptr [si]
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    sub_16324();                                //call sub_16324
    _sp += 0x0008;                              //add sp, 8
    _push(_ax);                                 //push ax
    sub_144B8();                                //call sub_144B8
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    _bx = _stack16(_bp + var_6);                //mov bx, [bp+var_6]
    _bx += 1;                                   //inc bx
    _bx <<= 1;                                  //shl bx, 1
    _bx = _bx + _stack16(_bp + arg_0);          //add bx, [bp+arg_0]
    memory16(_ds, _bx) = _ax;                   //mov [bx], ax
    _bx = _stack16(_bp + var_6);                //mov bx, [bp+var_6]
    _bx += 1;                                   //inc bx
    _bx <<= 1;                                  //shl bx, 1
    _bx = _bx + _stack16(_bp + arg_0);          //add bx, [bp+arg_0]
    _di = memory16(_ds, _bx);                   //mov di, [bx]
    _stack16(_bp + var_8) = 0x0000;             //mov [bp+var_8], 0
    goto loc_103BB;                             //jmp short loc_103BB
loc_103B2:                                      //loc_103B2:
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_ds, _di) = _al;                     //mov [di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _stack16(_bp + var_8) += 1;                 //inc [bp+var_8]
loc_103BB:                                      //loc_103BB:
    if ((short)_stack16(_bp + var_8) < (short)0x0004)//jl short loc_103B2
        goto loc_103B2;
    _stack16(_bp + var_8) = 0x0000;             //mov [bp+var_8], 0
    goto loc_10400;                             //jmp short loc_10400
loc_103C8:                                      //loc_103C8:
    _stack16(_bp + var_C) = 0x0000;             //mov [bp+var_C], 0
    _stack16(_bp + var_A) = 0x0000;             //mov [bp+var_A], 0
    goto loc_103F5;                             //jmp short loc_103F5
loc_103D4:                                      //loc_103D4:
    _al = memory(_ds, _si);                     //mov al, [si]
    _ah = 0x00;                                 //mov ah, 0
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _al = _al + _stack16(_bp + var_C);          //add al, byte ptr [bp+var_C]
    memory(_ds, _di) = _al;                     //mov [di], al
    _di += 1;                                   //inc di
    _al = memory(_ds, _si);                     //mov al, [si]
    _ah = 0x00;                                 //mov ah, 0
    _ax &= 0x0003;                              //and ax, 3
    _cx = 0x0006;                               //mov cx, 6
    _ax <<= _cl;                                //shl ax, cl
    _stack16(_bp + var_C) = _ax;                //mov [bp+var_C], ax
    _si += 1;                                   //inc si
    _stack16(_bp + var_A) += 1;                 //inc [bp+var_A]
loc_103F5:                                      //loc_103F5:
    _ax = _stack16(_bp + var_A);                //mov ax, [bp+var_A]
    if ((short)_ax < (short)_stack16(_bp + var_4))//jl short loc_103D4
        goto loc_103D4;
    _stack16(_bp + var_8) += 1;                 //inc [bp+var_8]
loc_10400:                                      //loc_10400:
    _ax = _stack16(_bp + var_8);                //mov ax, [bp+var_8]
    if ((short)_ax < (short)_stack16(_bp + var_2))//jl short loc_103C8
        goto loc_103C8;
    _stack16(_bp + var_6) += 1;                 //inc [bp+var_6]
loc_1040B:                                      //loc_1040B:
    if ((short)_stack16(_bp + var_6) >= (short)0x0003)
        goto loc_10414;
    goto loc_10372;                             //jmp loc_10372
loc_10414:                                      //loc_10414:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_1041A()
{
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_144B8();                                //call sub_144B8
    _sp = _bp;                                  //mov sp, bp
    _si = _ax;                                  //mov si, ax
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_si);                                 //push si
    _push(memory16(_ds, 0xA50));                //push word_190F0
    sub_1464E();                                //call sub_1464E
    _sp = _bp;                                  //mov sp, bp
    _ax = _si;                                  //mov ax, si
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
}

void sub_1043A()
{
    _push(_si);                                 //push si
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _ax = 0x02cb;                               //mov ax, 2CBh
    _push(_ax);                                 //push ax
    sub_145F4();                                //call sub_145F4
    _sp += 0x0004;                              //add sp, 4
    memory16(_ds, 0xA50) = _ax;                 //mov word_190F0, ax
    if (_ax != 0xffff)                          //jnz short loc_10463
        goto loc_10463;
    _push(_ds);                                 //push ds
    _ax = 0x02d2;                               //mov ax, 2D2h
    _push(_ax);                                 //push ax
    sub_163F4();                                //call sub_163F4
    _sp += 0x0004;                              //add sp, 4
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_1063D;                             //jmp loc_1063D
loc_10463:                                      //loc_10463:
    _ax = 0x0046;                               //mov ax, 46h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x9DA) = _ax;                 //mov word_1907A, ax
    _ax = 0x0046;                               //mov ax, 46h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0xA38) = _ax;                 //mov word_190D8, ax
    _ax = 0x001a;                               //mov ax, 1Ah
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x9BA) = _ax;                 //mov word_1905A, ax
    _ax = 0x010a;                               //mov ax, 10Ah
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x9EE) = _ax;                 //mov word_1908E, ax
    _ax = 0x010a;                               //mov ax, 10Ah
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x9F6) = _ax;                 //mov word_19096, ax
    _ax = 0x0132;                               //mov ax, 132h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x9FE) = _ax;                 //mov word_1909E, ax
    _ax = 0x0132;                               //mov ax, 132h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0xA06) = _ax;                 //mov word_190A6, ax
    _ax = 0x010a;                               //mov ax, 10Ah
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x994) = _ax;                 //mov word_19034, ax
    _ax = 0x010a;                               //mov ax, 10Ah
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x99C) = _ax;                 //mov word_1903C, ax
    _ax = 0x0132;                               //mov ax, 132h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x9A4) = _ax;                 //mov word_19044, ax
    _ax = 0x0132;                               //mov ax, 132h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x9AC) = _ax;                 //mov word_1904C, ax
    _ax = 0x00ca;                               //mov ax, 0CAh
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x9B4) = _ax;                 //mov word_19054, ax
    _ax = 0x0146;                               //mov ax, 146h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0xA18) = _ax;                 //mov word_190B8, ax
    _ax = 0x0146;                               //mov ax, 146h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0xA20) = _ax;                 //mov word_190C0, ax
    _ax = 0x0146;                               //mov ax, 146h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0xA28) = _ax;                 //mov word_190C8, ax
    _ax = 0x0146;                               //mov ax, 146h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0xA30) = _ax;                 //mov word_190D0, ax
    _ax = 0x00b6;                               //mov ax, 0B6h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x966) = _ax;                 //mov word_19006, ax
    _ax = 0x00b6;                               //mov ax, 0B6h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x96E) = _ax;                 //mov word_1900E, ax
    _ax = 0x00b6;                               //mov ax, 0B6h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x976) = _ax;                 //mov word_19016, ax
    _ax = 0x00b6;                               //mov ax, 0B6h
    _push(_ax);                                 //push ax
    sub_1041A();                                //call sub_1041A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x97E) = _ax;                 //mov word_1901D+1, ax
    _push(memory16(_ds, 0xA50));                //push word_190F0
    sub_13CBD();                                //call sub_13CBD
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    _si = _si ^ _si;                            //xor si, si
    goto loc_105A5;                             //jmp short loc_105A5
loc_10560:                                      //loc_10560:
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += 0x0994;                              //add ax, 994h
    _push(_ax);                                 //push ax
    sub_10345();                                //call sub_10345
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += 0x09ee;                              //add ax, 9EEh
    _push(_ax);                                 //push ax
    sub_10345();                                //call sub_10345
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += 0x0a18;                              //add ax, 0A18h
    _push(_ax);                                 //push ax
    sub_10345();                                //call sub_10345
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += 0x0966;                              //add ax, 966h
    _push(_ax);                                 //push ax
    sub_10345();                                //call sub_10345
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    _si += 1;                                   //inc si
loc_105A5:                                      //loc_105A5:
    if ((short)_si < (short)0x0004)             //jl short loc_10560
        goto loc_10560;
    _ax = 0x000f;                               //mov ax, 0Fh
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_16035();                                //call sub_16035
    _sp += 0x0004;                              //add sp, 4
    _ax = 0x0007;                               //mov ax, 7
    _push(_ax);                                 //push ax
    _ax = 0x0070;                               //mov ax, 70h
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    sub_16324();                                //call sub_16324
    _sp += 0x0008;                              //add sp, 8
    _push(_ax);                                 //push ax
    sub_144B8();                                //call sub_144B8
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0x9C2) = _ax;                 //mov word_19062, ax
    sub_122BF();                                //call sub_122BF
    _ax = 0x0007;                               //mov ax, 7
    _push(_ax);                                 //push ax
    _ax = 0x0070;                               //mov ax, 70h
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    sub_16A19();                                //call sub_16A19
    _sp += 0x0008;                              //add sp, 8
    _ax = memory16(_ds, 0x9C2);                 //mov ax, word_19062
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = 0x0007;                               //mov ax, 7
    _push(_ax);                                 //push ax
    _ax = 0x0070;                               //mov ax, 70h
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    sub_16D73();                                //call sub_16D73
    _sp += 0x000c;                              //add sp, 0Ch
    _push(memory16(_ds, 0x9C2));                //push word_19062
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_16035();                                //call sub_16035
    _sp += 0x0004;                              //add sp, 4
    _ax = 0x0007;                               //mov ax, 7
    _push(_ax);                                 //push ax
    _ax = 0x0070;                               //mov ax, 70h
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    sub_16A19();                                //call sub_16A19
    _sp += 0x0008;                              //add sp, 8
    _ax = 0x0001;                               //mov ax, 1
loc_1063D:                                      //loc_1063D:
    _si = _pop();                               //pop si
}

void sub_1063F()
{
    _push(_si);                                 //push si
    _push(_di);                                 //push di
loc_10641:                                      //loc_10641:
    sub_1432B();                                //call sub_1432B
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_1064B
        goto loc_1064B;
    goto loc_1071E;                             //jmp loc_1071E
loc_1064B:                                      //loc_1064B:
    memory16(_ds, 0x9E2) += 1;                  //inc word_19082
    _bx = memory16(_ds, 0x9D6);                 //mov bx, word_19076
    _bx <<= 1;                                  //shl bx, 1
    if (memory16(_ds, _bx + 2536) != 0xffff)    //jnz short loc_10683
        goto loc_10683;
    _ax = memory16(_ds, 0x9D6);                 //mov ax, word_19076
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    memory16(_ds, _bx + 2508) = 0x0000;         //mov word ptr [bx+9CCh], 0
    _ax = 0x0001;                               //mov ax, 1
    _ax = _ax - memory16(_ds, 0x9D6);           //sub ax, word_19076
    memory16(_ds, 0x9D6) = _ax;                 //mov word_19076, ax
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    memory16(_ds, _bx + 2508) = 0x0001;         //mov word ptr [bx+9CCh], 1
loc_10683:                                      //loc_10683:
    sub_10E7A();                                //call sub_10E7A
    _si = memory16(_ds, 0x98C);                 //mov si, word_1902C
    _di = memory16(_ds, 0x98E);                 //mov di, word_1902E
    sub_122BF();                                //call sub_122BF
    _bx = memory16(_ds, 0x9BE);                 //mov bx, word_1905E
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = _si;                                  //mov ax, si
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2452));           //push word ptr [bx+994h]
    _push(memory16(_ds, 0x9E4));                //push word_19084
    _push(_si);                                 //push si
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
    _bx = memory16(_ds, 0x9C0);                 //mov bx, word_19060
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = _di;                                  //mov ax, di
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2542));           //push word ptr [bx+9EEh]
    _push(memory16(_ds, 0x9E6));                //push word_19086
    _push(_di);                                 //push di
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
    if ((short)_si >= (short)0x0006)            //jge short loc_106EE
        goto loc_106EE;
    _push(memory16(_ds, 0x9DA));                //push word_1907A
    _ax = memory16(_ds, 0x9E4);                 //mov ax, word_19084
    _ax += 0xfffe;                              //add ax, 0FFFEh
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
loc_106EE:                                      //loc_106EE:
    if ((short)_di <= (short)0x0113)            //jle short loc_10709
        goto loc_10709;
    _push(memory16(_ds, 0xA38));                //push word_190D8
    _ax = memory16(_ds, 0x9E6);                 //mov ax, word_19086
    _ax += 0xfffe;                              //add ax, 0FFFEh
    _push(_ax);                                 //push ax
    _ax = 0x0138;                               //mov ax, 138h
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
loc_10709:                                      //loc_10709:
    _push(memory16(_ds, 0x9B4));                //push word_19054
    _ax = 0x0067;                               //mov ax, 67h
    _push(_ax);                                 //push ax
    _ax = 0x009e;                               //mov ax, 9Eh
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
    goto loc_10641;                             //jmp loc_10641
loc_1071E:                                      //loc_1071E:
    sub_14104();                                //call sub_14104
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_10724()
{
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _di = 0x0201;                               //mov di, 201h
    memory16(_ds, 0xA42) = 0x7d00;              //mov word_190E2, 7D00h
    _si = _si ^ _si;                            //xor si, si
    _al = 0x7f;                                 //mov al, 7Fh
    _dx = _di;                                  //mov dx, di
    _out(_dx, _al);                             //out dx, al
loc_10736:                                      //loc_10736:
    _dx = _di;                                  //mov dx, di
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x01)                             //jnz short loc_10747
        goto loc_10747;
    if ((short)_si >= (short)memory16(_ds, 0xA42))//jge short loc_10747
        goto loc_10747;
    _si += 1;                                   //inc si
    goto loc_10736;                             //jmp short loc_10736
loc_10747:                                      //loc_10747:
    _si |= _si;                                 //or si, si
    if ((short)_si < (short))                   //jl short loc_10762
        goto loc_10762;
    _si = _si ^ _si;                            //xor si, si
loc_1074D:                                      //loc_1074D:
    _dx = _di;                                  //mov dx, di
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x01))                          //jz short loc_1075E
        goto loc_1075E;
    if ((short)_si >= (short)memory16(_ds, 0xA42))//jge short loc_1075E
        goto loc_1075E;
    _si += 1;                                   //inc si
    goto loc_1074D;                             //jmp short loc_1074D
loc_1075E:                                      //loc_1075E:
    _si |= _si;                                 //or si, si
    if ((short)_si >= 0)                        //jge short loc_10766
        goto loc_10766;
loc_10762:                                      //loc_10762:
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_10776;                             //jmp short loc_10776
loc_10766:                                      //loc_10766:
    memory16(_ds, 0xA44) = _si;                 //mov word_190E4, si
    _ax = _si;                                  //mov ax, si
    _sar(_ax, 1);                               //sar ax, 1
    _ax += _si;                                 //add ax, si
    memory16(_ds, 0xA42) = _ax;                 //mov word_190E2, ax
    _ax = 0x0001;                               //mov ax, 1
loc_10776:                                      //loc_10776:
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_10779()
{
    const int var_8 = -8;                       //var_8  = word ptr -8
    const int var_6 = -6;                       //var_6  = word ptr -6
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_1 = -1;                       //var_1  = byte ptr -1
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0008;                              //sub sp, 8
    _stack16(_bp + var_6) = 0x0068;             //mov [bp+var_6], 68h
    _stack16(_bp + var_4) = 0x0070;             //mov [bp+var_4], 70h
    _di = 0x0028;                               //mov di, 28h
    _si = _si ^ _si;                            //xor si, si
    goto loc_107AB;                             //jmp short loc_107AB
loc_10792:                                      //loc_10792:
    _push(memory16(_ds, 0x9C2));                //push word_19062
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _di;                                 //add ax, di
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + var_6));               //push [bp+var_6]
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    _si += 1;                                   //inc si
loc_107AB:                                      //loc_107AB:
    if ((short)_si < (short)0x0007)             //jl short loc_10792
        goto loc_10792;
    sub_122BF();                                //call sub_122BF
    _si = _si ^ _si;                            //xor si, si
    goto loc_107F4;                             //jmp short loc_107F4
loc_107B7:                                      //loc_107B7:
    _ax = _si;                                  //mov ax, si
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = memory16(_ds, _bx + 170);             //mov ax, [bx+0AAh]
    _dx = 0x000e;                               //mov dx, 0Eh
    _mul(_dx);                                  //mul dx
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _dx = _ax;                                  //mov dx, ax
    _ax = _pop();                               //pop ax
    _ax += _dx;                                 //add ax, dx
    _ax += 0x00ae;                              //add ax, 0AEh
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _di;                                 //add ax, di
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + var_4));               //push [bp+var_4]
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _si += 1;                                   //inc si
loc_107F4:                                      //loc_107F4:
    if ((short)_si < (short)0x0007)             //jl short loc_107B7
        goto loc_107B7;
    _push(memory16(_ds, 0x9C2));                //push word_19062
    _push(_di);                                 //push di
    _push(_stack16(_bp + var_6));               //push [bp+var_6]
    sub_1234E();                                //call sub_1234E
    _sp += 0x0006;                              //add sp, 6
    _si = _si ^ _si;                            //xor si, si
    _stack16(_bp + var_1) = 0x0000;             //mov [bp+var_1], 0
loc_1080D:                                      //loc_1080D:
    sub_1063F();                                //call sub_1063F
    _stack16(_bp + var_1) = _al;                //mov [bp+var_1], al
    if (_al == 0x0d)                            //jz short loc_10882
        goto loc_10882;
    sub_1432B();                                //call sub_1432B
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_10825
        goto loc_10825;
    sub_14104();                                //call sub_14104
    _stack16(_bp + var_1) = _al;                //mov [bp+var_1], al
loc_10825:                                      //loc_10825:
    _ax = 0x0fa0;                               //mov ax, 0FA0h
    _push(_ax);                                 //push ax
    sub_14B2B();                                //call sub_14B2B
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    sub_14B57();                                //call sub_14B57
    sub_122BF();                                //call sub_122BF
    _push(memory16(_ds, 0x9C2));                //push word_19062
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _di;                                 //add ax, di
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + var_6));               //push [bp+var_6]
    sub_1234E();                                //call sub_1234E
    _sp += 0x0006;                              //add sp, 6
    if (_stack16(_bp + var_1) == 0x0032)        //jz short loc_10858
        goto loc_10858;
    if (_stack16(_bp + var_1) != 0x0050)        //jnz short loc_10863
        goto loc_10863;
loc_10858:                                      //loc_10858:
    _si += 1;                                   //inc si
    _ax = _si;                                  //mov ax, si
    _bx = 0x0007;                               //mov bx, 7
    _cwd();                                     //cwd
    _idiv(_bx);                                 //idiv bx
    _si = _dx;                                  //mov si, dx
loc_10863:                                      //loc_10863:
    if (_stack16(_bp + var_1) == 0x0038)        //jz short loc_10872
        goto loc_10872;
    if (_stack16(_bp + var_1) == 0x0048)        //jz short loc_10872
        goto loc_10872;
    goto loc_10919;                             //jmp loc_10919
loc_10872:                                      //loc_10872:
    _ax = _si;                                  //mov ax, si
    _ax += 0x0006;                              //add ax, 6
    _bx = 0x0007;                               //mov bx, 7
    _cwd();                                     //cwd
    _idiv(_bx);                                 //idiv bx
    _si = _dx;                                  //mov si, dx
    goto loc_10919;                             //jmp loc_10919
loc_10882:                                      //loc_10882:
    _ax = _si;                                  //mov ax, si
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    if ((short)memory16(_ds, _bx + 172) > (short)0x0000)
        goto loc_10895;
    goto loc_10934;                             //jmp loc_10934
loc_10895:                                      //loc_10895:
    _ax = _si;                                  //mov ax, si
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    memory16(_ds, _bx + 170) += 1;              //inc word ptr [bx+0AAh]
    _ax = memory16(_ds, _bx + 170);             //mov ax, [bx+0AAh]
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    _cwd();                                     //cwd
    _idiv(memory16(_ds, _bx + 172));            //idiv word ptr [bx+0ACh]
    _ax = _si;                                  //mov ax, si
    _bx = 0x003c;                               //mov bx, 3Ch
    _push(_dx);                                 //push dx
    _mul(_bx);                                  //mul bx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 170) = _ax;             //mov [bx+0AAh], ax
    _push(memory16(_ds, 0x9C2));                //push word_19062
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _di;                                 //add ax, di
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + var_6));               //push [bp+var_6]
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    _ax = _si;                                  //mov ax, si
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = memory16(_ds, _bx + 170);             //mov ax, [bx+0AAh]
    _dx = 0x000e;                               //mov dx, 0Eh
    _mul(_dx);                                  //mul dx
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _dx = _ax;                                  //mov dx, ax
    _ax = _pop();                               //pop ax
    _ax += _dx;                                 //add ax, dx
    _ax += 0x00ae;                              //add ax, 0AEh
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _di;                                 //add ax, di
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + var_4));               //push [bp+var_4]
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
loc_10919:                                      //loc_10919:
    _push(memory16(_ds, 0x9C2));                //push word_19062
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _di;                                 //add ax, di
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + var_6));               //push [bp+var_6]
    sub_1234E();                                //call sub_1234E
    _sp += 0x0006;                              //add sp, 6
    goto loc_1080D;                             //jmp loc_1080D
loc_10934:                                      //loc_10934:
    _stack16(_bp + var_8) = 0x0000;             //mov [bp+var_8], 0
    goto loc_10957;                             //jmp short loc_10957
loc_1093B:                                      //loc_1093B:
    _push(memory16(_ds, 0x9C2));                //push word_19062
    _ax = _stack16(_bp + var_8);                //mov ax, [bp+var_8]
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _di;                                 //add ax, di
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + var_6));               //push [bp+var_6]
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    _stack16(_bp + var_8) += 1;                 //inc [bp+var_8]
loc_10957:                                      //loc_10957:
    if ((short)_stack16(_bp + var_8) < (short)0x0007)//jl short loc_1093B
        goto loc_1093B;
    _ax = _si;                                  //mov ax, si
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_10965()
{
    const int var_2 = -2;                       //var_2  = byte ptr -2
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 1;                                   //dec sp
    _sp -= 1;                                   //dec sp
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_2]
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x02b0;                               //mov ax, 2B0h
    _push(_ax);                                 //push ax
    _cx = 0x0002;                               //mov cx, 2
    sub_1466C();                                //call sub_1466C
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_13C3B();                                //call sub_13C3B
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    _si = _ax;                                  //mov si, ax
    _ax = _si;                                  //mov ax, si
    _al &= 0xff;                                //and al, 0FFh
    _stack16(_bp + var_2) = _al;                //mov [bp+var_2], al
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_2]
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _ax = 0x00c8;                               //mov ax, 0C8h
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _ax = _si;                                  //mov ax, si
    _cx = 0x0008;                               //mov cx, 8
    _sar(_ax, _cl);                             //sar ax, cl
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
}

void sub_109AF()
{
    const int var_2 = -2;                       //var_2  = word ptr -2
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 1;                                   //dec sp
    _sp -= 1;                                   //dec sp
    _bx = memory16(_ds, 0x9BE);                 //mov bx, word_1905E
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0x98C);                 //mov ax, word_1902C
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2452));           //push word ptr [bx+994h]
    _push(memory16(_ds, 0x9E4));                //push word_19084
    _push(memory16(_ds, 0x98C));                //push word_1902C
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    _bx = memory16(_ds, 0x9C0);                 //mov bx, word_19060
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0x98E);                 //mov ax, word_1902E
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2542));           //push word ptr [bx+9EEh]
    _push(memory16(_ds, 0x9E6));                //push word_19086
    _push(memory16(_ds, 0x98E));                //push word_1902E
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    _ax = 0x00c7;                               //mov ax, 0C7h
    _push(_ax);                                 //push ax
    _ax = 0x0138;                               //mov ax, 138h
    _push(_ax);                                 //push ax
    _ax = 0x000b;                               //mov ax, 0Bh
    _push(_ax);                                 //push ax
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    sub_15FCA();                                //call sub_15FCA
    _sp += 0x0008;                              //add sp, 8
    _push(memory16(_ds, 0x9B4));                //push word_19054
    _ax = 0x0067;                               //mov ax, 67h
    _push(_ax);                                 //push ax
    _ax = 0x009e;                               //mov ax, 9Eh
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
    _si = _si ^ _si;                            //xor si, si
    goto loc_10A7B;                             //jmp short loc_10A7B
loc_10A30:                                      //loc_10A30:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2494) = _ax;            //mov [bx+9BEh], ax
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2504) = _ax;            //mov [bx+9C8h], ax
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2506) = _ax;            //mov [bx+9CAh], ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    memory16(_ds, _bx + 2508) = _si;            //mov [bx+9CCh], si
    _ax = _si;                                  //mov ax, si
    _ax -= 1;                                   //dec ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2536) = _ax;            //mov [bx+9E8h], ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2532) = 0x00ad;         //mov word ptr [bx+9E4h], 0ADh
    _si += 1;                                   //inc si
loc_10A7B:                                      //loc_10A7B:
    if ((short)_si < (short)0x0002)             //jl short loc_10A30
        goto loc_10A30;
    memory16(_ds, 0x9D6) = 0x0001;              //mov word_19076, 1
loc_10A86:                                      //loc_10A86:
    sub_10779();                                //call sub_10779
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    if (_ax == 0x0004)                          //jz short loc_10A94
        goto loc_10A94;
    goto loc_10B82;                             //jmp loc_10B82
loc_10A94:                                      //loc_10A94:
    _di = 0x009e;                               //mov di, 9Eh
    _push(_ds);                                 //push ds
    _ax = 0x02ed;                               //mov ax, 2EDh
    _push(_ax);                                 //push ax
    _ax = 0x0028;                               //mov ax, 28h
    _push(_ax);                                 //push ax
    _ax = 0x0068;                               //mov ax, 68h
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _ax = 0x0028;                               //mov ax, 28h
    _push(_ax);                                 //push ax
    sub_10965();                                //call sub_10965
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _push(_ds);                                 //push ds
    _ax = 0x02fa;                               //mov ax, 2FAh
    _push(_ax);                                 //push ax
    _ax = 0x0030;                               //mov ax, 30h
    _push(_ax);                                 //push ax
    _ax = 0x0068;                               //mov ax, 68h
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _ax = 0x0030;                               //mov ax, 30h
    _push(_ax);                                 //push ax
    sub_10965();                                //call sub_10965
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _push(_ds);                                 //push ds
    _ax = 0x0307;                               //mov ax, 307h
    _push(_ax);                                 //push ax
    _ax = 0x0038;                               //mov ax, 38h
    _push(_ax);                                 //push ax
    _ax = 0x0068;                               //mov ax, 68h
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _ax = 0x0038;                               //mov ax, 38h
    _push(_ax);                                 //push ax
    sub_10965();                                //call sub_10965
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, _di + 4) = _ax;               //mov [di+4], ax
    _di = 0x00a4;                               //mov di, 0A4h
    _push(_ds);                                 //push ds
    _ax = 0x0314;                               //mov ax, 314h
    _push(_ax);                                 //push ax
    _ax = 0x0040;                               //mov ax, 40h
    _push(_ax);                                 //push ax
    _ax = 0x0068;                               //mov ax, 68h
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _ax = 0x0040;                               //mov ax, 40h
    _push(_ax);                                 //push ax
    sub_10965();                                //call sub_10965
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _push(_ds);                                 //push ds
    _ax = 0x0321;                               //mov ax, 321h
    _push(_ax);                                 //push ax
    _ax = 0x0048;                               //mov ax, 48h
    _push(_ax);                                 //push ax
    _ax = 0x0068;                               //mov ax, 68h
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _ax = 0x0048;                               //mov ax, 48h
    _push(_ax);                                 //push ax
    sub_10965();                                //call sub_10965
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _push(_ds);                                 //push ds
    _ax = 0x032e;                               //mov ax, 32Eh
    _push(_ax);                                 //push ax
    _ax = 0x0050;                               //mov ax, 50h
    _push(_ax);                                 //push ax
    _ax = 0x0068;                               //mov ax, 68h
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _ax = 0x0050;                               //mov ax, 50h
    _push(_ax);                                 //push ax
    sub_10965();                                //call sub_10965
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, _di + 4) = _ax;               //mov [di+4], ax
    _si = _si ^ _si;                            //xor si, si
    goto loc_10B7D;                             //jmp short loc_10B7D
loc_10B62:                                      //loc_10B62:
    _push(memory16(_ds, 0x9C2));                //push word_19062
    _ax = _si;                                  //mov ax, si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += 0x0028;                              //add ax, 28h
    _push(_ax);                                 //push ax
    _ax = 0x0068;                               //mov ax, 68h
    _push(_ax);                                 //push ax
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    _si += 1;                                   //inc si
loc_10B7D:                                      //loc_10B7D:
    if ((short)_si < (short)0x0007)             //jl short loc_10B62
        goto loc_10B62;
loc_10B82:                                      //loc_10B82:
    if (_stack16(_bp + var_2) != 0x0005)        //jnz short loc_10BC3
        goto loc_10BC3;
    _push(_ds);                                 //push ds
    _ax = 0x033b;                               //mov ax, 33Bh
    _push(_ax);                                 //push ax
    _ax = 0x0028;                               //mov ax, 28h
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    sub_14104();                                //call sub_14104
    sub_10724();                                //call sub_10724
    _si = _si ^ _si;                            //xor si, si
    goto loc_10BBE;                             //jmp short loc_10BBE
loc_10BA4:                                      //loc_10BA4:
    _push(memory16(_ds, 0x9C2));                //push word_19062
    _ax = 0x0028;                               //mov ax, 28h
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x002a;                               //mov dx, 2Ah
    _mul(_dx);                                  //mul dx
    _ax += 0x0028;                              //add ax, 28h
    _push(_ax);                                 //push ax
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    _si += 1;                                   //inc si
loc_10BBE:                                      //loc_10BBE:
    if ((short)_si < (short)0x0004)             //jl short loc_10BA4
        goto loc_10BA4;
loc_10BC3:                                      //loc_10BC3:
    if ((short)_stack16(_bp + var_2) <= (short)0x0000)
        goto loc_10BD2;
    if ((short)_stack16(_bp + var_2) >= (short)0x0006)
        goto loc_10BD2;
    goto loc_10A86;                             //jmp loc_10A86
loc_10BD2:                                      //loc_10BD2:
    if (_stack16(_bp + var_2) != 0x0006)        //jnz short loc_10BDC
        goto loc_10BDC;
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_10BE8;                             //jmp short loc_10BE8
loc_10BDC:                                      //loc_10BDC:
    _ax = memory16(_ds, 0x15E);                 //mov ax, word_187FE
    _ax = _ax ^ 0x0001;                         //xor ax, 1
    memory16(_ds, 0x24E) = _ax;                 //mov word_188EE, ax
    _ax = 0x0001;                               //mov ax, 1
loc_10BE8:                                      //loc_10BE8:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_10BEE()
{
    sub_122BF();                                //call sub_122BF
    sub_15D80();                                //call sub_15D80
    _ax = 0x00c7;                               //mov ax, 0C7h
    _push(_ax);                                 //push ax
    _ax = 0x0138;                               //mov ax, 138h
    _push(_ax);                                 //push ax
    _ax = 0x000b;                               //mov ax, 0Bh
    _push(_ax);                                 //push ax
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    sub_15FCA();                                //call sub_15FCA
    _sp += 0x0008;                              //add sp, 8
    _push(memory16(_ds, 0x9B4));                //push word_19054
    _ax = 0x0067;                               //mov ax, 67h
    _push(_ax);                                 //push ax
    _ax = 0x009e;                               //mov ax, 9Eh
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
    _push(_ds);                                 //push ds
    _ax = 0x035a;                               //mov ax, 35Ah
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _ax = 0x005a;                               //mov ax, 5Ah
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _push(_ds);                                 //push ds
    _ax = 0x036c;                               //mov ax, 36Ch
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _ax = 0x0028;                               //mov ax, 28h
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _push(_ds);                                 //push ds
    _ax = 0x036e;                               //mov ax, 36Eh
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _ax = 0x010e;                               //mov ax, 10Eh
    _push(_ax);                                 //push ax
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
}

void loc_10C93()
{
    _FIXME_ = 0x0000;                           //mov word ptr [bp-4], 0
    goto loc_10D37;                             //jmp loc_10D37
loc_10C9B:                                      //loc_10C9B:
    _ax = _stack16(_bp + -4);                   //mov ax, [bp-4]
    _ax += 1;                                   //inc ax
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    if (memory16(_ds, _bx + 170) == 0x0000)     //jz short loc_10CB0
        goto loc_10CB0;
    goto loc_10D34;                             //jmp loc_10D34
loc_10CB0:                                      //loc_10CB0:
    _ax = _stack16(_bp + -4);                   //mov ax, [bp-4]
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _si = _ax;                                  //mov si, ax
    _si += 0x009e;                              //add si, 9Eh
    _ax = _stack16(_bp + -4);                   //mov ax, [bp-4]
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _di = _ax;                                  //mov di, ax
    _di += 0x09c8;                              //add di, 9C8h
    _al = _stack16(_bp + -2);                   //mov al, [bp-2]
    _ah = 0x00;                                 //mov ah, 0
    if (_ax != memory16(_ds, _si))              //jnz short loc_10CD9
        goto loc_10CD9;
    memory16(_ds, _di) = 0xfffe;                //mov word ptr [di], 0FFFEh
loc_10CD9:                                      //loc_10CD9:
    _al = _stack16(_bp + -2);                   //mov al, [bp-2]
    _ah = 0x00;                                 //mov ah, 0
    _dx = memory16(_ds, _si);                   //mov dx, [si]
    _dx += 0x0080;                              //add dx, 80h
    if (_ax != _dx)                             //jnz short loc_10CEC
        goto loc_10CEC;
    memory16(_ds, _di) = 0x0000;                //mov word ptr [di], 0
loc_10CEC:                                      //loc_10CEC:
    _al = _stack16(_bp + -2);                   //mov al, [bp-2]
    _ah = 0x00;                                 //mov ah, 0
    if (_ax != memory16(_ds, _si + 2))          //jnz short loc_10CFB
        goto loc_10CFB;
    memory16(_ds, _di + 2) = 0x0002;            //mov word ptr [di+2], 2
loc_10CFB:                                      //loc_10CFB:
    _al = _stack16(_bp + -2);                   //mov al, [bp-2]
    _ah = 0x00;                                 //mov ah, 0
    _dx = memory16(_ds, _si + 2);               //mov dx, [si+2]
    _dx += 0x0080;                              //add dx, 80h
    if (_ax != _dx)                             //jnz short loc_10D10
        goto loc_10D10;
    memory16(_ds, _di + 2) = 0x0000;            //mov word ptr [di+2], 0
loc_10D10:                                      //loc_10D10:
    _al = _stack16(_bp + -2);                   //mov al, [bp-2]
    _ah = 0x00;                                 //mov ah, 0
    if (_ax != memory16(_ds, _si + 4))          //jnz short loc_10D1F
        goto loc_10D1F;
    memory16(_ds, _di + 4) = 0x0001;            //mov word ptr [di+4], 1
loc_10D1F:                                      //loc_10D1F:
    _al = _stack16(_bp + -2);                   //mov al, [bp-2]
    _ah = 0x00;                                 //mov ah, 0
    _dx = memory16(_ds, _si + 4);               //mov dx, [si+4]
    _dx += 0x0080;                              //add dx, 80h
    if (_ax != _dx)                             //jnz short loc_10D34
        goto loc_10D34;
    memory16(_ds, _di + 4) = 0x0000;            //mov word ptr [di+4], 0
loc_10D34:                                      //loc_10D34:
    _FIXME_ += 1;                               //inc word ptr [bp-4]
loc_10D37:                                      //loc_10D37:
    if ((short)_FIXME_ >= (short)0x0002)        //jge short loc_10D40
        goto loc_10D40;
    goto loc_10C9B;                             //jmp loc_10C9B
loc_10D40:                                      //loc_10D40:
    _al = 0x20;                                 //mov al, 20h
    _out(32, _al);                              //out 20h, al
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_10D50()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _di = 0x0201;                               //mov di, 201h
    _si = _si ^ _si;                            //xor si, si
    _dx = _di;                                  //mov dx, di
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x10)                             //jnz short loc_10D67
        goto loc_10D67;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_10D69;                             //jmp short loc_10D69
loc_10D67:                                      //loc_10D67:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_10D69:                                      //loc_10D69:
    _push(_ax);                                 //push ax
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2508) = _ax;            //mov [bx+9CCh], ax
    _al = 0xff;                                 //mov al, 0FFh
    _dx = _di;                                  //mov dx, di
    _out(_dx, _al);                             //out dx, al
loc_10D7E:                                      //loc_10D7E:
    _dx = _di;                                  //mov dx, di
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x01)                             //jnz short loc_10D8F
        goto loc_10D8F;
    if ((short)_si >= (short)memory16(_ds, 0xA42))//jge short loc_10D8F
        goto loc_10D8F;
    _si += 1;                                   //inc si
    goto loc_10D7E;                             //jmp short loc_10D7E
loc_10D8F:                                      //loc_10D8F:
    _si = _si ^ _si;                            //xor si, si
loc_10D91:                                      //loc_10D91:
    _dx = _di;                                  //mov dx, di
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x01))                          //jz short loc_10DA2
        goto loc_10DA2;
    if ((short)_si >= (short)memory16(_ds, 0xA42))//jge short loc_10DA2
        goto loc_10DA2;
    _si += 1;                                   //inc si
    goto loc_10D91;                             //jmp short loc_10D91
loc_10DA2:                                      //loc_10DA2:
    _ax = memory16(_ds, 0xA44);                 //mov ax, word_190E4
    _sar(_ax, 1);                               //sar ax, 1
    if ((short)_ax >= (short)_si)               //jge short loc_10DB0
        goto loc_10DB0;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_10DB2;                             //jmp short loc_10DB2
loc_10DB0:                                      //loc_10DB0:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_10DB2:                                      //loc_10DB2:
    _ax <<= 1;                                  //shl ax, 1
    _push(_ax);                                 //push ax
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2506) = _ax;            //mov [bx+9CAh], ax
    if ((short)_si >= (short)memory16(_ds, 0xA42))//jge short loc_10DCF
        goto loc_10DCF;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_10DD1;                             //jmp short loc_10DD1
loc_10DCF:                                      //loc_10DCF:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_10DD1:                                      //loc_10DD1:
    _ax = -_ax;                                 //neg ax
    _ax <<= 1;                                  //shl ax, 1
    _push(_ax);                                 //push ax
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2504) = _ax;            //mov [bx+9C8h], ax
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_10DE9()
{
    const int var_10 = -16;                     //var_10  = word ptr -10h
    const int var_E = -14;                      //var_E  = word ptr -0Eh
    const int var_C = -12;                      //var_C  = word ptr -0Ch
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0010;                              //sub sp, 10h
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _stack16(_bp + var_10) = 0x0003;            //mov [bp+var_10], 3
    _FIXME_;                                    //lea ax, [bp+var_10]
    _push(_ax);                                 //push ax
    _FIXME_;                                    //lea ax, [bp+var_10]
    _push(_ax);                                 //push ax
    _ax = 0x0033;                               //mov ax, 33h
    _push(_ax);                                 //push ax
    sub_14230();                                //call sub_14230
    _sp += 0x0006;                              //add sp, 6
    _ax = _stack16(_bp + var_E);                //mov ax, [bp+var_E]
    _ax &= 0x0001;                              //and ax, 1
    _push(_ax);                                 //push ax
    _ax = _di;                                  //mov ax, di
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2508) = _ax;            //mov [bx+9CCh], ax
    _stack16(_bp + var_10) = 0x000b;            //mov [bp+var_10], 0Bh
    _FIXME_;                                    //lea ax, [bp+var_10]
    _push(_ax);                                 //push ax
    _FIXME_;                                    //lea ax, [bp+var_10]
    _push(_ax);                                 //push ax
    _ax = 0x0033;                               //mov ax, 33h
    _push(_ax);                                 //push ax
    sub_14230();                                //call sub_14230
    _sp += 0x0006;                              //add sp, 6
    _si = _stack16(_bp + var_C);                //mov si, [bp+var_C]
    _si |= _si;                                 //or si, si
    if ((short)_si <= (short))                  //jle short loc_10E43
        goto loc_10E43;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_10E45;                             //jmp short loc_10E45
loc_10E43:                                      //loc_10E43:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_10E45:                                      //loc_10E45:
    _ax <<= 1;                                  //shl ax, 1
    _push(_ax);                                 //push ax
    _ax = _di;                                  //mov ax, di
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2506) = _ax;            //mov [bx+9CAh], ax
    _si |= _si;                                 //or si, si
    if ((short)_si >= 0)                        //jge short loc_10E5F
        goto loc_10E5F;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_10E61;                             //jmp short loc_10E61
loc_10E5F:                                      //loc_10E5F:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_10E61:                                      //loc_10E61:
    _ax = -_ax;                                 //neg ax
    _ax <<= 1;                                  //shl ax, 1
    _push(_ax);                                 //push ax
    _ax = _di;                                  //mov ax, di
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2504) = _ax;            //mov [bx+9C8h], ax
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_10E7A()
{
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0004;                              //sub sp, 4
    _si = _si ^ _si;                            //xor si, si
    goto loc_10FF8;                             //jmp loc_10FF8
loc_10E87:                                      //loc_10E87:
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    if (memory16(_ds, _bx + 2508) == 0x0000)    //jz short loc_10EAC
        goto loc_10EAC;
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    if (memory16(_ds, _bx + 2536) != 0xffff)    //jnz short loc_10EAC
        goto loc_10EAC;
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2536) = 0x0000;         //mov word ptr [bx+9E8h], 0
loc_10EAC:                                      //loc_10EAC:
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _di = memory16(_ds, _bx + 2504);            //mov di, [bx+9C8h]
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _di = _di + memory16(_ds, _bx + 2506);      //add di, [bx+9CAh]
    _stack16(_bp + var_4) = _di;                //mov [bp+var_4], di
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _di = _di + memory16(_ds, _bx + 2444);      //add di, [bx+98Ch]
    _ax = _si;                                  //mov ax, si
    _dx = 0x009b;                               //mov dx, 9Bh
    _mul(_dx);                                  //mul dx
    _ax += 0x0003;                              //add ax, 3
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    if ((short)_stack16(_bp + var_4) <= (short)0x0000)
        goto loc_10EFB;
    _ax += 0x0077;                              //add ax, 77h
    if ((short)_ax > (short)_di)                //jg short loc_10F00
        goto loc_10F00;
    _ax = _stack16(_bp + var_2);                //mov ax, [bp+var_2]
    _ax += 0x0077;                              //add ax, 77h
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2444) = _ax;            //mov [bx+98Ch], ax
    goto loc_10F15;                             //jmp short loc_10F15
loc_10EFB:                                      //loc_10EFB:
    if ((short)_di <= (short)_stack16(_bp + var_2))//jle short loc_10F0A
        goto loc_10F0A;
loc_10F00:                                      //loc_10F00:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2444) = _di;            //mov [bx+98Ch], di
    goto loc_10F15;                             //jmp short loc_10F15
loc_10F0A:                                      //loc_10F0A:
    _ax = _stack16(_bp + var_2);                //mov ax, [bp+var_2]
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2444) = _ax;            //mov [bx+98Ch], ax
loc_10F15:                                      //loc_10F15:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    if (memory16(_ds, _bx + 2536) != 0xfffe)    //jnz short loc_10F3E
        goto loc_10F3E;
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2532) = 0x00ad;         //mov word ptr [bx+9E4h], 0ADh
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2494) = 0x0000;         //mov word ptr [bx+9BEh], 0
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2536) = 0xffff;         //mov word ptr [bx+9E8h], 0FFFFh
loc_10F3E:                                      //loc_10F3E:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    if (memory16(_ds, _bx + 2536) != 0xffff)    //jnz short loc_10F95
        goto loc_10F95;
    if (_stack16(_bp + var_4) == 0x0000)        //jz short loc_10F89
        goto loc_10F89;
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 2448);            //mov ax, [bx+990h]
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _ax = _ax - memory16(_ds, _bx + 2444);      //sub ax, [bx+98Ch]
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_10F65
        goto loc_10F65;
    _ax = -_ax;                                 //neg ax
loc_10F65:                                      //loc_10F65:
    if ((short)_ax > (short)0x0004)             //jg short loc_10F6D
        goto loc_10F6D;
    goto loc_10FF7;                             //jmp loc_10FF7
loc_10F6D:                                      //loc_10F6D:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2494) = memory16(_ds, _bx + 2494) ^ 0x0001;
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 2444);            //mov ax, [bx+98Ch]
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2448) = _ax;            //mov [bx+990h], ax
    goto loc_10FF7;                             //jmp short loc_10FF7
loc_10F89:                                      //loc_10F89:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2494) = 0x0000;         //mov word ptr [bx+9BEh], 0
    goto loc_10FF7;                             //jmp short loc_10FF7
loc_10F95:                                      //loc_10F95:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    if ((short)memory16(_ds, _bx + 2536) <= (short)0x0012)
        goto loc_10FA5;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_10FA7;                             //jmp short loc_10FA7
loc_10FA5:                                      //loc_10FA5:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_10FA7:                                      //loc_10FA7:
    _ax += 0x0002;                              //add ax, 2
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2494) = _ax;            //mov [bx+9BEh], ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    if (memory16(_ds, _bx + 2536) != 0x0013)    //jnz short loc_10FC6
        goto loc_10FC6;
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2532) -= 0x0004;        //sub word ptr [bx+9E4h], 4
loc_10FC6:                                      //loc_10FC6:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 2536);            //mov ax, [bx+9E8h]
    memory16(_ds, _bx + 2536) += 1;             //inc word ptr [bx+9E8h]
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 612);             //mov ax, [bx+264h]
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2532) += _ax;           //add [bx+9E4h], ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    if ((short)memory16(_ds, _bx + 2536) <= (short)0x0025)
        goto loc_10FF7;
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2536) = 0xfffe;         //mov word ptr [bx+9E8h], 0FFFEh
loc_10FF7:                                      //loc_10FF7:
    _si += 1;                                   //inc si
loc_10FF8:                                      //loc_10FF8:
    if ((short)_si >= (short)0x0002)            //jge short loc_11000
        goto loc_11000;
    goto loc_10E87;                             //jmp loc_10E87
loc_11000:                                      //loc_11000:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_11006()
{
    const int var_2 = -2;                       //var_2  = word ptr -2
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 1;                                   //dec sp
    _sp -= 1;                                   //dec sp
    _di = memory16(_ds, 0x988);                 //mov di, word_19028
    _si = memory16(_ds, 0x9B6);                 //mov si, word_19056
    if ((short)_di <= (short)0x013f)            //jle short loc_1101E
        goto loc_1101E;
    _di = 0x013f;                               //mov di, 13Fh
loc_1101E:                                      //loc_1101E:
    if ((short)_di >= (short)0xfec1)            //jge short loc_11027
        goto loc_11027;
    _di = 0xfec1;                               //mov di, 0FEC1h
loc_11027:                                      //loc_11027:
    if ((short)_si <= (short)0x013f)            //jle short loc_11030
        goto loc_11030;
    _si = 0x013f;                               //mov si, 13Fh
loc_11030:                                      //loc_11030:
    if ((short)_si >= (short)0xfec1)            //jge short loc_11039
        goto loc_11039;
    _si = 0xfec1;                               //mov si, 0FEC1h
loc_11039:                                      //loc_11039:
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    memory16(_ds, 0xA3A) = _ax;                 //mov word_190DA, ax
    _ax = memory16(_ds, 0x98A);                 //mov ax, word_1902A
    memory16(_ds, 0x9C4) = _ax;                 //mov word_19064, ax
    memory16(_ds, 0xA40) += _di;                //add word_190E0, di
    memory16(_ds, 0x9EC) += _si;                //add word_1908C, si
    if ((short)memory16(_ds, 0xA40) >= (short)0x0140)//jge short loc_11083
        goto loc_11083;
    memory16(_ds, 0xA40) = 0x0140;              //mov word_190E0, 140h
    _ax = _di;                                  //mov ax, di
    _ax = -_ax;                                 //neg ax
    _di = _ax;                                  //mov di, ax
    _ax = _di;                                  //mov ax, di
    _cx = 0x0004;                               //mov cx, 4
    _sar(_ax, _cl);                             //sar ax, cl
    _di -= _ax;                                 //sub di, ax
    _ax = _si;                                  //mov ax, si
    _sar(_ax, _cl);                             //sar ax, cl
    _si -= _ax;                                 //sub si, ax
    if (memory16(_ds, 0x9D6) != 0x0001)         //jnz short loc_11083
        goto loc_11083;
    memory16(_ds, 0x9D6) = 0x0002;              //mov word_19076, 2
    memory16(_ds, 0x9DC) = 0x0000;              //mov word_1907C, 0
loc_11083:                                      //loc_11083:
    if ((short)memory16(_ds, 0xA40) <= (short)0x46c0)//jle short loc_110B9
        goto loc_110B9;
    memory16(_ds, 0xA40) = 0x46c0;              //mov word_190E0, 46C0h
    _ax = _di;                                  //mov ax, di
    _ax = -_ax;                                 //neg ax
    _di = _ax;                                  //mov di, ax
    _ax = _di;                                  //mov ax, di
    _cx = 0x0004;                               //mov cx, 4
    _sar(_ax, _cl);                             //sar ax, cl
    _di -= _ax;                                 //sub di, ax
    _ax = _si;                                  //mov ax, si
    _sar(_ax, _cl);                             //sar ax, cl
    _si -= _ax;                                 //sub si, ax
    if (memory16(_ds, 0x9D6) != 0x0000)         //jnz short loc_110B9
        goto loc_110B9;
    memory16(_ds, 0x9D6) = 0x0002;              //mov word_19076, 2
    memory16(_ds, 0x9DC) = 0x0000;              //mov word_1907C, 0
loc_110B9:                                      //loc_110B9:
    if ((short)memory16(_ds, 0x9EC) >= (short)0x0340)//jge short loc_110DC
        goto loc_110DC;
    memory16(_ds, 0x9EC) = 0x0340;              //mov word_1908C, 340h
    _ax = _si;                                  //mov ax, si
    _ax = -_ax;                                 //neg ax
    _si = _ax;                                  //mov si, ax
    _ax = _di;                                  //mov ax, di
    _cx = 0x0004;                               //mov cx, 4
    _sar(_ax, _cl);                             //sar ax, cl
    _di -= _ax;                                 //sub di, ax
    _ax = _si;                                  //mov ax, si
    _sar(_ax, _cl);                             //sar ax, cl
    _si -= _ax;                                 //sub si, ax
loc_110DC:                                      //loc_110DC:
    if ((short)memory16(_ds, 0x9EC) <= (short)0x2c80)//jle short loc_110F7
        goto loc_110F7;
    memory16(_ds, 0x9EC) = 0x2c80;              //mov word_1908C, 2C80h
    _ax = _si;                                  //mov ax, si
    _ax = -_ax;                                 //neg ax
    _si = _ax;                                  //mov si, ax
    _stack16(_bp + var_2) = 0x0000;             //mov [bp+var_2], 0
    goto loc_110FC;                             //jmp short loc_110FC
loc_110F7:                                      //loc_110F7:
    _stack16(_bp + var_2) = 0x0001;             //mov [bp+var_2], 1
loc_110FC:                                      //loc_110FC:
    _si += 1;                                   //inc si
    _ax = memory16(_ds, 0xA40);                 //mov ax, word_190E0
    _cx = 0x0006;                               //mov cx, 6
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_ds, 0x9C6) = _ax;                 //mov word_19066, ax
    _ax = memory16(_ds, 0x9EC);                 //mov ax, word_1908C
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_ds, 0x98A) = _ax;                 //mov word_1902A, ax
    memory16(_ds, 0x988) = _di;                 //mov word_19028, di
    memory16(_ds, 0x9B6) = _si;                 //mov word_19056, si
    _ax = _stack16(_bp + var_2);                //mov ax, [bp+var_2]
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_11121()
{
    const int var_6 = -6;                       //var_6  = word ptr -6
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0006;                              //sub sp, 6
    _si = _si ^ _si;                            //xor si, si
    goto loc_1125C;                             //jmp loc_1125C
loc_1112E:                                      //loc_1112E:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _di = memory16(_ds, 0x9C6);                 //mov di, word_19066
    _ax = memory16(_ds, _bx + 2444);            //mov ax, [bx+98Ch]
    _di -= _ax;                                 //sub di, ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x0007;                               //mov dx, 7
    _mul(_dx);                                  //mul dx
    _di -= _ax;                                 //sub di, ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0x98A);                 //mov ax, word_1902A
    _dx = memory16(_ds, _bx + 2532);            //mov dx, [bx+9E4h]
    _ax -= _dx;                                 //sub ax, dx
    _sar(_ax, 1);                               //sar ax, 1
    _stack16(_bp + var_6) = _ax;                //mov [bp+var_6], ax
    _ax = _di;                                  //mov ax, di
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _mul(_di);                                  //mul di
    _push(_ax);                                 //push ax
    _ax = _stack16(_bp + var_6);                //mov ax, [bp+var_6]
    _mul(_stack16(_bp + var_6));                //mul [bp+var_6]
    _dx = _pop();                               //pop dx
    _dx += _ax;                                 //add dx, ax
    _stack16(_bp + var_4) = _dx;                //mov [bp+var_4], dx
    if ((short)_dx < (short)0x006e)             //jl short loc_11174
        goto loc_11174;
    goto loc_11243;                             //jmp loc_11243
loc_11174:                                      //loc_11174:
    _ax = memory16(_ds, 0x9E2);                 //mov ax, word_19082
    _ax &= 0x000f;                              //and ax, 0Fh
    _dx = 0x0008;                               //mov dx, 8
    _dx -= _ax;                                 //sub dx, ax
    _stack16(_bp + var_2) = _dx;                //mov [bp+var_2], dx
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    if ((short)memory16(_ds, _bx + 2536) <= (short)0xffff)
        goto loc_111BA;
    _ax = memory16(_ds, 0x9B6);                 //mov ax, word_19056
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11196
        goto loc_11196;
    _ax = -_ax;                                 //neg ax
loc_11196:                                      //loc_11196:
    _ax = -_ax;                                 //neg ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _bx = memory16(_ds, _bx + 2536);            //mov bx, [bx+9E8h]
    _bx <<= 1;                                  //shl bx, 1
    _dx = memory16(_ds, _bx + 612);             //mov dx, [bx+264h]
    _bx = 0x0003;                               //mov bx, 3
    _cx = memory16(_ds, 0x9BC);                 //mov cx, word_1905C
    _bx <<= _cl;                                //shl bx, cl
    _cx = _bx;                                  //mov cx, bx
    _dx <<= _cl;                                //shl dx, cl
    _ax += _dx;                                 //add ax, dx
    memory16(_ds, 0x9B6) = _ax;                 //mov word_19056, ax
    goto loc_111C8;                             //jmp short loc_111C8
loc_111BA:                                      //loc_111BA:
    _ax = memory16(_ds, 0x9B6);                 //mov ax, word_19056
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_111C3
        goto loc_111C3;
    _ax = -_ax;                                 //neg ax
loc_111C3:                                      //loc_111C3:
    _ax = -_ax;                                 //neg ax
    memory16(_ds, 0x9B6) = _ax;                 //mov word_19056, ax
loc_111C8:                                      //loc_111C8:
    _ax = _stack16(_bp + var_2);                //mov ax, [bp+var_2]
    memory16(_ds, 0x9B6) += _ax;                //add word_19056, ax
    _ax = _di;                                  //mov ax, di
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_111D7
        goto loc_111D7;
    _ax = -_ax;                                 //neg ax
loc_111D7:                                      //loc_111D7:
    _mul(_di);                                  //mul di
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = memory16(_ds, _bx + 2506);            //mov ax, [bx+9CAh]
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    _ax = _ax + memory16(_ds, _bx + 2504);      //add ax, [bx+9C8h]
    _cx = memory16(_ds, 0x9BC);                 //mov cx, word_1905C
    _cx += 0x0004;                              //add cx, 4
    _ax <<= _cl;                                //shl ax, cl
    _dx = _pop();                               //pop dx
    _dx += _ax;                                 //add dx, ax
    _dx = _dx + _stack16(_bp + var_2);          //add dx, [bp+var_2]
    memory16(_ds, 0x988) += _dx;                //add word_19028, dx
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    if (memory16(_ds, _bx + 2526) != 0x0000)    //jnz short loc_1125B
        goto loc_1125B;
    memory16(_ds, 0xA4D) = 0x00c8;              //mov word_190ED, 0C8h
    memory16(_ds, 0xA4B) = 0x0000;              //mov word_190EB, 0
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2526) = 0x0001;         //mov word ptr [bx+9DEh], 1
    _ax = memory16(_ds, 0x9D6);                 //mov ax, word_19076
    if (_ax == _si)                             //jz short loc_1123D
        goto loc_1123D;
    memory16(_ds, 0x9D6) = _si;                 //mov word_19076, si
    memory16(_ds, 0x9DC) = 0x0000;              //mov word_1907C, 0
    goto loc_1125B;                             //jmp short loc_1125B
loc_1123D:                                      //loc_1123D:
    memory16(_ds, 0x9DC) += 1;                  //inc word_1907C
    goto loc_1125B;                             //jmp short loc_1125B
loc_11243:                                      //loc_11243:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    if (memory16(_ds, _bx + 2526) == 0x0000)    //jz short loc_1125B
        goto loc_1125B;
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, 0x9BC) = _ax;                 //mov word_1905C, ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2526) = _ax;            //mov [bx+9DEh], ax
loc_1125B:                                      //loc_1125B:
    _si += 1;                                   //inc si
loc_1125C:                                      //loc_1125C:
    if ((short)_si >= (short)0x0002)            //jge short loc_11264
        goto loc_11264;
    goto loc_1112E;                             //jmp loc_1112E
loc_11264:                                      //loc_11264:
    _si = 0x0001;                               //mov si, 1
    if ((short)memory16(_ds, 0x98A) <= (short)0x005b)//jle short loc_112BB
        goto loc_112BB;
    if ((short)memory16(_ds, 0xA3A) >= (short)0x0080)//jge short loc_11295
        goto loc_11295;
    if ((short)memory16(_ds, 0x9C6) <= (short)0x007f)//jle short loc_11295
        goto loc_11295;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11286
        goto loc_11286;
    _ax = -_ax;                                 //neg ax
loc_11286:                                      //loc_11286:
    _ax = -_ax;                                 //neg ax
    _sar(_ax, 1);                               //sar ax, 1
    memory16(_ds, 0x988) = _ax;                 //mov word_19028, ax
    memory16(_ds, 0xA40) = 0x1fc0;              //mov word_190E0, 1FC0h
    goto loc_112B9;                             //jmp short loc_112B9
loc_11295:                                      //loc_11295:
    if ((short)memory16(_ds, 0xA3A) <= (short)0x009f)//jle short loc_112BB
        goto loc_112BB;
    if ((short)memory16(_ds, 0x9C6) >= (short)0x00a0)//jge short loc_112BB
        goto loc_112BB;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_112AE
        goto loc_112AE;
    _ax = -_ax;                                 //neg ax
loc_112AE:                                      //loc_112AE:
    _sar(_ax, 1);                               //sar ax, 1
    memory16(_ds, 0x988) = _ax;                 //mov word_19028, ax
    memory16(_ds, 0xA40) = 0x2800;              //mov word_190E0, 2800h
loc_112B9:                                      //loc_112B9:
    _si = _si ^ _si;                            //xor si, si
loc_112BB:                                      //loc_112BB:
    _si |= _si;                                 //or si, si
    if (_si != 0)                               //jnz short loc_112C2
        goto loc_112C2;
    goto loc_113C4;                             //jmp loc_113C4
loc_112C2:                                      //loc_112C2:
    if ((short)memory16(_ds, 0x98A) > (short)0x0051)//jg short loc_112CC
        goto loc_112CC;
    goto loc_113C4;                             //jmp loc_113C4
loc_112CC:                                      //loc_112CC:
    if ((short)memory16(_ds, 0x9C6) > (short)0x007f)//jg short loc_112D6
        goto loc_112D6;
    goto loc_113C4;                             //jmp loc_113C4
loc_112D6:                                      //loc_112D6:
    if ((short)memory16(_ds, 0x9C6) < (short)0x00a0)//jl short loc_112E1
        goto loc_112E1;
    goto loc_113C4;                             //jmp loc_113C4
loc_112E1:                                      //loc_112E1:
    if ((short)memory16(_ds, 0x98A) <= (short)0x005b)//jle short loc_11310
        goto loc_11310;
    if ((short)memory16(_ds, 0x9C6) >= (short)0x0094)//jge short loc_11301
        goto loc_11301;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_112F9
        goto loc_112F9;
    _ax = -_ax;                                 //neg ax
loc_112F9:                                      //loc_112F9:
    _ax = -_ax;                                 //neg ax
    memory16(_ds, 0x988) = _ax;                 //mov word_19028, ax
    goto loc_113C4;                             //jmp loc_113C4
loc_11301:                                      //loc_11301:
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_1130A
        goto loc_1130A;
    _ax = -_ax;                                 //neg ax
loc_1130A:                                      //loc_1130A:
    memory16(_ds, 0x988) = _ax;                 //mov word_19028, ax
    goto loc_113C4;                             //jmp loc_113C4
loc_11310:                                      //loc_11310:
    if ((short)memory16(_ds, 0x9C6) <= (short)0x0093)//jle short loc_11330
        goto loc_11330;
    _bx = 0x005b;                               //mov bx, 5Bh
    _bx = _bx - memory16(_ds, 0x98A);           //sub bx, word_1902A
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 592);             //mov ax, [bx+250h]
    _dx = 0x00a1;                               //mov dx, 0A1h
    _dx = _dx - memory16(_ds, 0x9C6);           //sub dx, word_19066
    if ((short)_ax <= (short)_dx)               //jle short loc_11357
        goto loc_11357;
loc_11330:                                      //loc_11330:
    if ((short)memory16(_ds, 0x9C6) < (short)0x0094)//jl short loc_1133B
        goto loc_1133B;
    goto loc_113C4;                             //jmp loc_113C4
loc_1133B:                                      //loc_1133B:
    _bx = 0x005b;                               //mov bx, 5Bh
    _bx = _bx - memory16(_ds, 0x98A);           //sub bx, word_1902A
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 592);             //mov ax, [bx+250h]
    _dx = memory16(_ds, 0x9C6);                 //mov dx, word_19066
    _dx += 0xff7b;                              //add dx, 0FF7Bh
    if ((short)_ax <= (short)_dx)               //jle short loc_11357
        goto loc_11357;
    goto loc_113C4;                             //jmp loc_113C4
loc_11357:                                      //loc_11357:
    if ((short)memory16(_ds, 0x9B6) <= (short)0x0000)//jle short loc_11398
        goto loc_11398;
    _di = memory16(_ds, 0x9C6);                 //mov di, word_19066
    _di += 0xff6f;                              //add di, 0FF6Fh
    if ((short)_di >= (short)0xfffb)            //jge short loc_11379
        goto loc_11379;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11374
        goto loc_11374;
    _ax = -_ax;                                 //neg ax
loc_11374:                                      //loc_11374:
    _ax = -_ax;                                 //neg ax
    memory16(_ds, 0x988) = _ax;                 //mov word_19028, ax
loc_11379:                                      //loc_11379:
    if ((short)_di <= (short)0x0005)            //jle short loc_1138A
        goto loc_1138A;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11387
        goto loc_11387;
    _ax = -_ax;                                 //neg ax
loc_11387:                                      //loc_11387:
    memory16(_ds, 0x988) = _ax;                 //mov word_19028, ax
loc_1138A:                                      //loc_1138A:
    _ax = memory16(_ds, 0x9B6);                 //mov ax, word_19056
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11393
        goto loc_11393;
    _ax = -_ax;                                 //neg ax
loc_11393:                                      //loc_11393:
    _ax = -_ax;                                 //neg ax
    memory16(_ds, 0x9B6) = _ax;                 //mov word_19056, ax
loc_11398:                                      //loc_11398:
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_113A1
        goto loc_113A1;
    _ax = -_ax;                                 //neg ax
loc_113A1:                                      //loc_113A1:
    if ((short)_ax <= (short)0x0020)            //jle short loc_113AE
        goto loc_113AE;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _sar(_ax, 1);                               //sar ax, 1
    memory16(_ds, 0x988) = _ax;                 //mov word_19028, ax
loc_113AE:                                      //loc_113AE:
    _ax = memory16(_ds, 0x9B6);                 //mov ax, word_19056
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_113B7
        goto loc_113B7;
    _ax = -_ax;                                 //neg ax
loc_113B7:                                      //loc_113B7:
    if ((short)_ax <= (short)0x0020)            //jle short loc_113C4
        goto loc_113C4;
    _ax = memory16(_ds, 0x9B6);                 //mov ax, word_19056
    _sar(_ax, 1);                               //sar ax, 1
    memory16(_ds, 0x9B6) = _ax;                 //mov word_19056, ax
loc_113C4:                                      //loc_113C4:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_113CA()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    _si += 0xfffc;                              //add si, 0FFFCh
    _di = _stack16(_bp + arg_2);                //mov di, [bp+arg_2]
    _di += 0xfffb;                              //add di, 0FFFBh
    if ((short)_si >= (short)0x0004)            //jge short loc_113E3
        goto loc_113E3;
    _si = 0x0004;                               //mov si, 4
loc_113E3:                                      //loc_113E3:
    if ((short)_si <= (short)0x0110)            //jle short loc_113EC
        goto loc_113EC;
    _si = 0x0110;                               //mov si, 110h
loc_113EC:                                      //loc_113EC:
    if ((short)_di >= (short)0x000b)            //jge short loc_113F4
        goto loc_113F4;
    _di = 0x000b;                               //mov di, 0Bh
loc_113F4:                                      //loc_113F4:
    if ((short)_di <= (short)0x00a7)            //jle short loc_113FD
        goto loc_113FD;
    _di = 0x00a7;                               //mov di, 0A7h
loc_113FD:                                      //loc_113FD:
    if ((short)_stack16(_bp + arg_0) >= (short)0x0008)
        goto loc_11410;
    _push(memory16(_ds, 0x9DA));                //push word_1907A
    _push(_di);                                 //push di
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp = _bp;                                  //mov sp, bp
loc_11410:                                      //loc_11410:
    if ((short)_stack16(_bp + arg_0) <= (short)0x0117)
        goto loc_11425;
    _push(memory16(_ds, 0xA38));                //push word_190D8
    _push(_di);                                 //push di
    _ax = 0x0138;                               //mov ax, 138h
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp = _bp;                                  //mov sp, bp
loc_11425:                                      //loc_11425:
    if ((short)_stack16(_bp + arg_2) >= (short)0x0011)
        goto loc_11439;
    _push(memory16(_ds, 0x9BA));                //push word_1905A
    _ax = 0x000b;                               //mov ax, 0Bh
    _push(_ax);                                 //push ax
    _push(_si);                                 //push si
    sub_122D0();                                //call sub_122D0
    _sp = _bp;                                  //mov sp, bp
loc_11439:                                      //loc_11439:
    if ((short)_stack16(_bp + arg_2) <= (short)0x00ab)
        goto loc_1144E;
    _push(memory16(_ds, 0x9BA));                //push word_1905A
    _ax = 0x00c7;                               //mov ax, 0C7h
    _push(_ax);                                 //push ax
    _push(_si);                                 //push si
    sub_122D0();                                //call sub_122D0
    _sp = _bp;                                  //mov sp, bp
loc_1144E:                                      //loc_1144E:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_11452()
{
    const int var_2 = -2;                       //var_2  = word ptr -2
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 1;                                   //dec sp
    _sp -= 1;                                   //dec sp
    _si = memory16(_ds, 0x98C);                 //mov si, word_1902C
    _di = memory16(_ds, 0x98E);                 //mov di, word_1902E
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax -= _si;                                 //sub ax, si
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_1146C
        goto loc_1146C;
    _ax = -_ax;                                 //neg ax
loc_1146C:                                      //loc_1146C:
    if ((short)_ax >= (short)0x0029)            //jge short loc_11483
        goto loc_11483;
    _ax = memory16(_ds, 0x98A);                 //mov ax, word_1902A
    _ax = _ax - memory16(_ds, 0x9E4);           //sub ax, word_19084
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_1147E
        goto loc_1147E;
    _ax = -_ax;                                 //neg ax
loc_1147E:                                      //loc_1147E:
    if ((short)_ax < (short)0x0021)             //jl short loc_114AD
        goto loc_114AD;
loc_11483:                                      //loc_11483:
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax -= _di;                                 //sub ax, di
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_1148E
        goto loc_1148E;
    _ax = -_ax;                                 //neg ax
loc_1148E:                                      //loc_1148E:
    if ((short)_ax >= (short)0x0029)            //jge short loc_114A5
        goto loc_114A5;
    _ax = memory16(_ds, 0x98A);                 //mov ax, word_1902A
    _ax = _ax - memory16(_ds, 0x9E6);           //sub ax, word_19086
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_114A0
        goto loc_114A0;
    _ax = -_ax;                                 //neg ax
loc_114A0:                                      //loc_114A0:
    if ((short)_ax < (short)0x0021)             //jl short loc_114AD
        goto loc_114AD;
loc_114A5:                                      //loc_114A5:
    if ((short)memory16(_ds, 0x9C4) <= (short)0x00ab)//jle short loc_114B2
        goto loc_114B2;
loc_114AD:                                      //loc_114AD:
    _ax = 0x0001;                               //mov ax, 1
    goto loc_114B4;                             //jmp short loc_114B4
loc_114B2:                                      //loc_114B2:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_114B4:                                      //loc_114B4:
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    sub_122BF();                                //call sub_122BF
    if (memory16(_ds, 0xA0E) == 0x0000)         //jz short loc_114E9
        goto loc_114E9;
    _bx = memory16(_ds, 0xA3C);                 //mov bx, word_190DC
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0xA3A);                 //mov ax, word_190DA
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2406));           //push word ptr [bx+966h]
    _push(memory16(_ds, 0x9C4));                //push word_19064
    _push(memory16(_ds, 0xA3A));                //push word_190DA
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    goto loc_1152C;                             //jmp short loc_1152C
loc_114E9:                                      //loc_114E9:
    if (_stack16(_bp + var_2) == 0x0000)        //jz short loc_1152C
        goto loc_1152C;
    _bx = memory16(_ds, 0xA3C);                 //mov bx, word_190DC
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0xA3A);                 //mov ax, word_190DA
    _ax += 0xfffc;                              //add ax, 0FFFCh
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2584));           //push word ptr [bx+0A18h]
    _ax = memory16(_ds, 0x9C4);                 //mov ax, word_19064
    _ax += 0xfffb;                              //add ax, 0FFFBh
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0xA3A);                 //mov ax, word_190DA
    _ax += 0xfffc;                              //add ax, 0FFFCh
    _push(_ax);                                 //push ax
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    _push(memory16(_ds, 0x9C4));                //push word_19064
    _push(memory16(_ds, 0xA3A));                //push word_190DA
    sub_113CA();                                //call sub_113CA
    _sp += 0x0004;                              //add sp, 4
loc_1152C:                                      //loc_1152C:
    _ax = _stack16(_bp + var_2);                //mov ax, [bp+var_2]
    memory16(_ds, 0xA0E) = _ax;                 //mov word_190AE, ax
    _ax = memory16(_ds, 0x986);                 //mov ax, word_19026
    memory16(_ds, 0x986) -= 1;                  //dec word_19026
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_11573
        goto loc_11573;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11546
        goto loc_11546;
    _ax = -_ax;                                 //neg ax
loc_11546:                                      //loc_11546:
    _dx = memory16(_ds, 0x9B6);                 //mov dx, word_19056
    _dx |= _dx;                                 //or dx, dx
    if ((short)_dx >= 0)                        //jge short loc_11550
        goto loc_11550;
    _dx = -_dx;                                 //neg dx
loc_11550:                                      //loc_11550:
    _ax += _dx;                                 //add ax, dx
    _cx = 0x0006;                               //mov cx, 6
    _sar(_ax, _cl);                             //sar ax, cl
    _dx = 0x000c;                               //mov dx, 0Ch
    _dx -= _ax;                                 //sub dx, ax
    _dx |= _dx;                                 //or dx, dx
    if ((short)_dx >= 0)                        //jge short loc_11562
        goto loc_11562;
    _dx = -_dx;                                 //neg dx
loc_11562:                                      //loc_11562:
    memory16(_ds, 0x986) = _dx;                 //mov word_19026, dx
    memory16(_ds, 0xA3C) += 1;                  //inc word_190DC
    _ax = memory16(_ds, 0xA3C);                 //mov ax, word_190DC
    _ax &= 0x0003;                              //and ax, 3
    memory16(_ds, 0xA3C) = _ax;                 //mov word_190DC, ax
loc_11573:                                      //loc_11573:
    _bx = memory16(_ds, 0x9BE);                 //mov bx, word_1905E
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = _si;                                  //mov ax, si
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2452));           //push word ptr [bx+994h]
    _push(memory16(_ds, 0x9E4));                //push word_19084
    _push(_si);                                 //push si
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
    _bx = memory16(_ds, 0x9C0);                 //mov bx, word_19060
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = _di;                                  //mov ax, di
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2542));           //push word ptr [bx+9EEh]
    _push(memory16(_ds, 0x9E6));                //push word_19086
    _push(_di);                                 //push di
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
    if (memory16(_ds, 0xA0E) == 0x0000)         //jz short loc_115E6
        goto loc_115E6;
    _bx = memory16(_ds, 0xA3C);                 //mov bx, word_190DC
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2406));           //push word ptr [bx+966h]
    _push(memory16(_ds, 0x98A));                //push word_1902A
    _push(memory16(_ds, 0x9C6));                //push word_19066
    sub_1234E();                                //call sub_1234E
    _sp += 0x0006;                              //add sp, 6
    goto loc_11615;                             //jmp short loc_11615
loc_115E6:                                      //loc_115E6:
    _bx = memory16(_ds, 0xA3C);                 //mov bx, word_190DC
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax += 0xfffc;                              //add ax, 0FFFCh
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2584));           //push word ptr [bx+0A18h]
    _ax = memory16(_ds, 0x98A);                 //mov ax, word_1902A
    _ax += 0xfffb;                              //add ax, 0FFFBh
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax += 0xfffc;                              //add ax, 0FFFCh
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
loc_11615:                                      //loc_11615:
    _push(memory16(_ds, 0x98A));                //push word_1902A
    _push(memory16(_ds, 0x9C6));                //push word_19066
    sub_113CA();                                //call sub_113CA
    _sp += 0x0004;                              //add sp, 4
    if ((short)_si >= (short)0x0006)            //jge short loc_1163C
        goto loc_1163C;
    _push(memory16(_ds, 0x9DA));                //push word_1907A
    _ax = memory16(_ds, 0x9E4);                 //mov ax, word_19084
    _ax += 0xfffe;                              //add ax, 0FFFEh
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
loc_1163C:                                      //loc_1163C:
    if ((short)_di <= (short)0x0113)            //jle short loc_11657
        goto loc_11657;
    _push(memory16(_ds, 0xA38));                //push word_190D8
    _ax = memory16(_ds, 0x9E6);                 //mov ax, word_19086
    _ax += 0xfffe;                              //add ax, 0FFFEh
    _push(_ax);                                 //push ax
    _ax = 0x0138;                               //mov ax, 138h
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
loc_11657:                                      //loc_11657:
    _push(memory16(_ds, 0x9B4));                //push word_19054
    _ax = 0x0067;                               //mov ax, 67h
    _push(_ax);                                 //push ax
    _ax = 0x009e;                               //mov ax, 9Eh
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_1166F()
{
    sub_122BF();                                //call sub_122BF
    if (memory16(_ds, 0xA0E) == 0x0000)         //jz short loc_116A1
        goto loc_116A1;
    _bx = memory16(_ds, 0xA3C);                 //mov bx, word_190DC
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2406));           //push word ptr [bx+966h]
    _push(memory16(_ds, 0x98A));                //push word_1902A
    _push(memory16(_ds, 0x9C6));                //push word_19066
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
    goto loc_116D0;                             //jmp short loc_116D0
loc_116A1:                                      //loc_116A1:
    _bx = memory16(_ds, 0xA3C);                 //mov bx, word_190DC
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax += 0xfffc;                              //add ax, 0FFFCh
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2584));           //push word ptr [bx+0A18h]
    _ax = memory16(_ds, 0x98A);                 //mov ax, word_1902A
    _ax += 0xfffb;                              //add ax, 0FFFBh
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax += 0xfffc;                              //add ax, 0FFFCh
    _push(_ax);                                 //push ax
    sub_123E2();                                //call sub_123E2
    _sp += 0x0006;                              //add sp, 6
loc_116D0:                                      //loc_116D0:
    _bx = memory16(_ds, 0x9BE);                 //mov bx, word_1905E
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0x98C);                 //mov ax, word_1902C
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2452));           //push word ptr [bx+994h]
    _push(memory16(_ds, 0x9E4));                //push word_19084
    _push(memory16(_ds, 0x98C));                //push word_1902C
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
    _bx = memory16(_ds, 0x9C0);                 //mov bx, word_19060
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, 0x98E);                 //mov ax, word_1902E
    _ax &= 0x0003;                              //and ax, 3
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _push(memory16(_ds, _bx + 2542));           //push word ptr [bx+9EEh]
    _push(memory16(_ds, 0x9E6));                //push word_19086
    _push(memory16(_ds, 0x98E));                //push word_1902E
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
    _ax = 0x00c7;                               //mov ax, 0C7h
    _push(_ax);                                 //push ax
    _ax = 0x0138;                               //mov ax, 138h
    _push(_ax);                                 //push ax
    _ax = 0x000b;                               //mov ax, 0Bh
    _push(_ax);                                 //push ax
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    sub_15FCA();                                //call sub_15FCA
    _sp += 0x0008;                              //add sp, 8
    _push(memory16(_ds, 0x9B4));                //push word_19054
    _ax = 0x0067;                               //mov ax, 67h
    _push(_ax);                                 //push ax
    _ax = 0x009e;                               //mov ax, 9Eh
    _push(_ax);                                 //push ax
    sub_122D0();                                //call sub_122D0
    _sp += 0x0006;                              //add sp, 6
}

void sub_11747()
{
    const int var_A = -10;                      //var_A  = word ptr -0Ah
    const int var_8 = -8;                       //var_8  = word ptr -8
    const int var_6 = -6;                       //var_6  = word ptr -6
    const int var_4 = -4;                       //var_4  = byte ptr -4
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x000a;                              //sub sp, 0Ah
    if ((short)memory16(_ds, 0x9DC) <= (short)0x0002)//jle short loc_1175F
        goto loc_1175F;
    _si = 0x0001;                               //mov si, 1
    _si = _si - memory16(_ds, 0x9D6);           //sub si, word_19076
    goto loc_1176E;                             //jmp short loc_1176E
loc_1175F:                                      //loc_1175F:
    if ((short)memory16(_ds, 0x9C6) >= (short)0x0096)//jge short loc_1176C
        goto loc_1176C;
    _si = 0x0001;                               //mov si, 1
    goto loc_1176E;                             //jmp short loc_1176E
loc_1176C:                                      //loc_1176C:
    _si = _si ^ _si;                            //xor si, si
loc_1176E:                                      //loc_1176E:
    sub_11452();                                //call sub_11452
    _ax = memory16(_ds, 0x9B6);                 //mov ax, word_19056
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_1177A
        goto loc_1177A;
    _ax = -_ax;                                 //neg ax
loc_1177A:                                      //loc_1177A:
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _stack16(_bp + var_6) = _ax;                //mov [bp+var_6], ax
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_1178C
        goto loc_1178C;
    _ax = -_ax;                                 //neg ax
loc_1178C:                                      //loc_1178C:
    _di = _ax;                                  //mov di, ax
    _sar(_di, 1);                               //sar di, 1
    _sar(_di, 1);                               //sar di, 1
    _sar(_di, 1);                               //sar di, 1
    _stack16(_bp + var_8) = 0x0014;             //mov [bp+var_8], 14h
loc_11799:                                      //loc_11799:
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, 0x9D2) = _ax;                 //mov word_19072, ax
    memory16(_ds, 0x9CC) = _ax;                 //mov word_1906C, ax
    sub_14B57();                                //call sub_14B57
    sub_10E7A();                                //call sub_10E7A
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_117B0
        goto loc_117B0;
    _ax = -_ax;                                 //neg ax
loc_117B0:                                      //loc_117B0:
    if ((short)_ax <= (short)_di)               //jle short loc_117C8
        goto loc_117C8;
    if ((short)memory16(_ds, 0x988) >= (short)0x0000)//jge short loc_117C4
        goto loc_117C4;
    _ax = _di;                                  //mov ax, di
    _ax = -_ax;                                 //neg ax
    memory16(_ds, 0x988) = _ax;                 //mov word_19028, ax
    goto loc_117C8;                             //jmp short loc_117C8
loc_117C4:                                      //loc_117C4:
    memory16(_ds, 0x988) = _di;                 //mov word_19028, di
loc_117C8:                                      //loc_117C8:
    _ax = memory16(_ds, 0x9B6);                 //mov ax, word_19056
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_117D1
        goto loc_117D1;
    _ax = -_ax;                                 //neg ax
loc_117D1:                                      //loc_117D1:
    if ((short)_ax <= (short)_stack16(_bp + var_6))//jle short loc_117ED
        goto loc_117ED;
    if ((short)memory16(_ds, 0x9B6) >= (short)0x0000)//jge short loc_117E7
        goto loc_117E7;
    _ax = _stack16(_bp + var_6);                //mov ax, [bp+var_6]
    _ax = -_ax;                                 //neg ax
    memory16(_ds, 0x9B6) = _ax;                 //mov word_19056, ax
    goto loc_117ED;                             //jmp short loc_117ED
loc_117E7:                                      //loc_117E7:
    _ax = _stack16(_bp + var_6);                //mov ax, [bp+var_6]
    memory16(_ds, 0x9B6) = _ax;                 //mov word_19056, ax
loc_117ED:                                      //loc_117ED:
    sub_11121();                                //call sub_11121
    if (memory16(_ds, 0x24E) == 0x0000)         //jz short loc_11811
        goto loc_11811;
    if (_si != memory16(_ds, 0xA14))            //jnz short loc_11808
        goto loc_11808;
    _ax = 0x1388;                               //mov ax, 1388h
    _push(_ax);                                 //push ax
    sub_14B2B();                                //call sub_14B2B
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    goto loc_11811;                             //jmp short loc_11811
loc_11808:                                      //loc_11808:
    _ax = 0x0064;                               //mov ax, 64h
    _push(_ax);                                 //push ax
    sub_14B2B();                                //call sub_14B2B
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
loc_11811:                                      //loc_11811:
    sub_11006();                                //call sub_11006
    sub_11452();                                //call sub_11452
    _ax = _stack16(_bp + var_8);                //mov ax, [bp+var_8]
    _stack16(_bp + var_8) -= 1;                 //dec [bp+var_8]
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax <= (short))                  //jle short loc_11824
        goto loc_11824;
    goto loc_11799;                             //jmp loc_11799
loc_11824:                                      //loc_11824:
    if (memory16(_ds, 0x9E8) == 0xffff)         //jz short loc_1182E
        goto loc_1182E;
    goto loc_11799;                             //jmp loc_11799
loc_1182E:                                      //loc_1182E:
    if (memory16(_ds, 0x9EA) == 0xffff)         //jz short loc_11838
        goto loc_11838;
    goto loc_11799;                             //jmp loc_11799
loc_11838:                                      //loc_11838:
    sub_14B57();                                //call sub_14B57
    _ax = _si;                                  //mov ax, si
    _dx = 0x00e6;                               //mov dx, 0E6h
    _mul(_dx);                                  //mul dx
    _ax += 0x0028;                              //add ax, 28h
    _stack16(_bp + var_A) = _ax;                //mov [bp+var_A], ax
    if (_si != memory16(_ds, 0xA14))            //jnz short loc_118BF
        goto loc_118BF;
    _ax = 0x0007;                               //mov ax, 7
    _push(_ax);                                 //push ax
    _ax = _stack16(_bp + var_A);                //mov ax, [bp+var_A]
    _ax += 0x000f;                              //add ax, 0Fh
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + var_A));               //push [bp+var_A]
    sub_16A19();                                //call sub_16A19
    _sp += 0x0008;                              //add sp, 8
    _ax = 0x000a;                               //mov ax, 0Ah
    _push(_ax);                                 //push ax
    _FIXME_;                                    //lea ax, [bp+var_4]
    _push(_ax);                                 //push ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2576) += 1;             //inc word ptr [bx+0A10h]
    _ax = memory16(_ds, _bx + 2576);            //mov ax, [bx+0A10h]
    _push(_ax);                                 //push ax
    sub_14439();                                //call sub_14439
    _sp += 0x0006;                              //add sp, 6
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + var_A));               //push [bp+var_A]
    sub_16C42();                                //call sub_16C42
    _sp += 0x0008;                              //add sp, 8
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    if ((short)memory16(_ds, _bx + 2576) <= (short)0x000e)
        goto loc_1190D;
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 2576);            //mov ax, [bx+0A10h]
    _bx = 0x0001;                               //mov bx, 1
    _bx -= _si;                                 //sub bx, si
    _bx <<= 1;                                  //shl bx, 1
    _ax = _ax - memory16(_ds, _bx + 2576);      //sub ax, [bx+0A10h]
    if ((short)_ax <= (short)0x0001)            //jle short loc_1190D
        goto loc_1190D;
    memory16(_ds, 0x9D4) = 0x0001;              //mov word_19074, 1
    goto loc_1190D;                             //jmp short loc_1190D
loc_118BF:                                      //loc_118BF:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_16B04();                                //call sub_16B04
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _ax -= _si;                                 //sub ax, si
    _dx = 0x00e6;                               //mov dx, 0E6h
    _mul(_dx);                                  //mul dx
    _ax += 0x0023;                              //add ax, 23h
    _push(_ax);                                 //push ax
    sub_16129();                                //call sub_16129
    _sp += 0x0006;                              //add sp, 6
    _ax = 0x000f;                               //mov ax, 0Fh
    _push(_ax);                                 //push ax
    sub_16B04();                                //call sub_16B04
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = _stack16(_bp + var_A);                //mov ax, [bp+var_A]
    _ax += 0xfffb;                              //add ax, 0FFFBh
    _push(_ax);                                 //push ax
    sub_16129();                                //call sub_16129
    _sp += 0x0006;                              //add sp, 6
    memory16(_ds, 0xA14) = _si;                 //mov word_190B4, si
loc_1190D:                                      //loc_1190D:
    _ax = 0x0064;                               //mov ax, 64h
    _push(_ax);                                 //push ax
    sub_13F7A();                                //call sub_13F7A
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    sub_1166F();                                //call sub_1166F
    _ax = _si;                                  //mov ax, si
    _dx = 0x00a5;                               //mov dx, 0A5h
    _mul(_dx);                                  //mul dx
    _ax += 0x0040;                              //add ax, 40h
    memory16(_ds, 0xA3A) = _ax;                 //mov word_190DA, ax
    memory16(_ds, 0x9C6) = _ax;                 //mov word_19066, ax
    _cx = 0x0006;                               //mov cx, 6
    _ax <<= _cl;                                //shl ax, cl
    memory16(_ds, 0xA40) = _ax;                 //mov word_190E0, ax
    _ax = 0x0087;                               //mov ax, 87h
    memory16(_ds, 0x9C4) = _ax;                 //mov word_19064, ax
    memory16(_ds, 0x98A) = _ax;                 //mov word_1902A, ax
    _ax <<= _cl;                                //shl ax, cl
    memory16(_ds, 0x9EC) = _ax;                 //mov word_1908C, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, 0x9E0) = _ax;                 //mov word_19080, ax
    memory16(_ds, 0x9DE) = _ax;                 //mov word_1907E, ax
    memory16(_ds, 0x9DC) = _ax;                 //mov word_1907C, ax
    memory16(_ds, 0x9B6) = _ax;                 //mov word_19056, ax
    memory16(_ds, 0x988) = _ax;                 //mov word_19028, ax
    memory16(_ds, 0xA0E) = _ax;                 //mov word_190AE, ax
    memory16(_ds, 0xA3C) = _ax;                 //mov word_190DC, ax
    memory16(_ds, 0x986) = _cx;                 //mov word_19026, cx
    _ax = 0x0001;                               //mov ax, 1
    memory16(_ds, 0x9BC) = _ax;                 //mov word_1905C, ax
    memory16(_ds, 0xA4B) = _ax;                 //mov word_190EB, ax
    memory16(_ds, 0x9D6) = 0x0002;              //mov word_19076, 2
    _ax = memory16(_ds, 0x9E2);                 //mov ax, word_19082
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11972
        goto loc_11972;
    _ax = -_ax;                                 //neg ax
loc_11972:                                      //loc_11972:
    _bx = 0x0005;                               //mov bx, 5
    _cwd();                                     //cwd
    _idiv(_bx);                                 //idiv bx
    memory16(_ds, 0xA3E) = _dx;                 //mov word_190DE, dx
    _bx = memory16(_ds, 0xA14);                 //mov bx, word_190B4
    _bx <<= 1;                                  //shl bx, 1
    if (memory16(_ds, _bx + 2576) != 0x000e)    //jnz short loc_1198F
        goto loc_1198F;
    memory16(_ds, 0xA3E) = 0x0005;              //mov word_190DE, 5
loc_1198F:                                      //loc_1198F:
    memory16(_ds, 0x9B8) = 0x0000;              //mov word_19058, 0
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_1199B()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _si = _ax;                                  //mov si, ax
    _si += 0x09c8;                              //add si, 9C8h
    _bx = _stack16(_bp + arg_0);                //mov bx, [bp+arg_0]
    _bx <<= 1;                                  //shl bx, 1
    _di = memory16(_ds, _bx + 2444);            //mov di, [bx+98Ch]
    _ax = _di;                                  //mov ax, di
    _ax = _ax - _stack16(_bp + arg_2);          //sub ax, [bp+arg_2]
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_119C2
        goto loc_119C2;
    _ax = -_ax;                                 //neg ax
loc_119C2:                                      //loc_119C2:
    if ((short)_ax >= (short)_stack16(_bp + arg_4))//jge short loc_119D5
        goto loc_119D5;
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
    memory16(_ds, _si + 2) = 0x0000;            //mov word ptr [si+2], 0
    _ax = 0x0001;                               //mov ax, 1
    goto loc_119F0;                             //jmp short loc_119F0
loc_119D5:                                      //loc_119D5:
    if ((short)_di >= (short)_stack16(_bp + arg_2))//jge short loc_119E5
        goto loc_119E5;
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
    memory16(_ds, _si + 2) = 0x0002;            //mov word ptr [si+2], 2
    goto loc_119EE;                             //jmp short loc_119EE
loc_119E5:                                      //loc_119E5:
    memory16(_ds, _si) = 0xfffe;                //mov word ptr [si], 0FFFEh
    memory16(_ds, _si + 2) = 0x0000;            //mov word ptr [si+2], 0
loc_119EE:                                      //loc_119EE:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_119F0:                                      //loc_119F0:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_119F4()
{
    const int var_6 = -6;                       //var_6  = word ptr -6
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0006;                              //sub sp, 6
    memory16(_ds, 0x9CC) = 0x0000;              //mov word_1906C, 0
    _ax = memory16(_ds, 0x98A);                 //mov ax, word_1902A
    if ((short)_ax >= (short)memory16(_ds, 0xA4D))//jge short loc_11A0E
        goto loc_11A0E;
    memory16(_ds, 0xA4D) = _ax;                 //mov word_190ED, ax
loc_11A0E:                                      //loc_11A0E:
    _ax = memory16(_ds, 0x9E2);                 //mov ax, word_19082
    _bx = 0x000a;                               //mov bx, 0Ah
    _cwd();                                     //cwd
    _idiv(_bx);                                 //idiv bx
    _ax = 0x0005;                               //mov ax, 5
    _ax -= _dx;                                 //sub ax, dx
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    if (memory16(_ds, 0xA4B) != 0x0000)         //jnz short loc_11A29
        goto loc_11A29;
    goto loc_11B3E;                             //jmp loc_11B3E
loc_11A29:                                      //loc_11A29:
    if (!(memory16(_ds, 0xA14) & 0x0001))       //jz short loc_11A34
        goto loc_11A34;
    goto loc_11B3E;                             //jmp loc_11B3E
loc_11A34:                                      //loc_11A34:
    _ax = memory16(_ds, 0xA3E);                 //mov ax, word_190DE
    if (_ax <= 0x0005)                          //jbe short loc_11A3F
        goto loc_11A3F;
    goto loc_11B37;                             //jmp loc_11B37
loc_11A3F:                                      //loc_11A3F:
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    switch (_bx)                                //jmp cs:off_11A48[bx]
    {
      case 0: goto loc_11A54;
      case 2: goto loc_11A6A;
      case 4: goto loc_11A80;
      case 6: goto loc_11A96;
      case 8: goto loc_11ABB;
      case 10: goto loc_11AF6;
      default:
        _ASSERT(0);
    }
loc_11A54:                                      //loc_11A54:
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x0037;                               //mov ax, 37h
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _si = _ax;                                  //mov si, ax
    goto loc_11B37;                             //jmp loc_11B37
loc_11A6A:                                      //loc_11A6A:
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x0054;                               //mov ax, 54h
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _si = _ax;                                  //mov si, ax
    goto loc_11B37;                             //jmp loc_11B37
loc_11A80:                                      //loc_11A80:
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x0050;                               //mov ax, 50h
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _si = _ax;                                  //mov si, ax
    goto loc_11B37;                             //jmp loc_11B37
loc_11A96:                                      //loc_11A96:
    if (memory16(_ds, 0x9B8) != 0x0000)         //jnz short loc_11AE3
        goto loc_11AE3;
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x002c;                               //mov ax, 2Ch
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _si = _ax;                                  //mov si, ax
    _ax = _si;                                  //mov ax, si
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_11AB9
        goto loc_11AB9;
    goto loc_11B37;                             //jmp loc_11B37
loc_11AB9:                                      //loc_11AB9:
    goto loc_11ADB;                             //jmp short loc_11ADB
loc_11ABB:                                      //loc_11ABB:
    if (memory16(_ds, 0x9B8) != 0x0000)         //jnz short loc_11AE3
        goto loc_11AE3;
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x005a;                               //mov ax, 5Ah
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _si = _ax;                                  //mov si, ax
    _ax = _si;                                  //mov ax, si
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_11B37
        goto loc_11B37;
loc_11ADB:                                      //loc_11ADB:
    memory16(_ds, 0x9B8) = 0x0001;              //mov word_19058, 1
    goto loc_11B37;                             //jmp short loc_11B37
loc_11AE3:                                      //loc_11AE3:
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x003a;                               //mov ax, 3Ah
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_11B34;                             //jmp short loc_11B34
loc_11AF6:                                      //loc_11AF6:
    if (memory16(_ds, 0x9B8) != 0x0000)         //jnz short loc_11B1C
        goto loc_11B1C;
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_11B18
        goto loc_11B18;
    memory16(_ds, 0x9B8) = 0x0001;              //mov word_19058, 1
loc_11B18:                                      //loc_11B18:
    _si = _si ^ _si;                            //xor si, si
    goto loc_11B37;                             //jmp short loc_11B37
loc_11B1C:                                      //loc_11B1C:
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x9B8);                 //mov ax, word_19058
    memory16(_ds, 0x9B8) += 1;                  //inc word_19058
    _ax += 0x0008;                              //add ax, 8
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
loc_11B34:                                      //loc_11B34:
    _si = 0x0001;                               //mov si, 1
loc_11B37:                                      //loc_11B37:
    memory16(_ds, 0x9CC) = _si;                 //mov word_1906C, si
    goto loc_11CE4;                             //jmp loc_11CE4
loc_11B3E:                                      //loc_11B3E:
    if ((short)memory16(_ds, 0x9B6) > (short)0x0000)//jg short loc_11B48
        goto loc_11B48;
    goto loc_11CD3;                             //jmp loc_11CD3
loc_11B48:                                      //loc_11B48:
    if ((short)memory16(_ds, 0x9C6) < (short)0x008c)//jl short loc_11B53
        goto loc_11B53;
    goto loc_11CD3;                             //jmp loc_11CD3
loc_11B53:                                      //loc_11B53:
    _ax = memory16(_ds, 0x9B6);                 //mov ax, word_19056
    _cx = 0x0006;                               //mov cx, 6
    _sar(_ax, _cl);                             //sar ax, cl
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_11B66
        goto loc_11B66;
    _stack16(_bp + var_6) = 0x0000;             //mov [bp+var_6], 0
    goto loc_11B7C;                             //jmp short loc_11B7C
loc_11B66:                                      //loc_11B66:
    _ax = 0x008c;                               //mov ax, 8Ch
    _ax = _ax - memory16(_ds, 0x98A);           //sub ax, word_1902A
    _bx = memory16(_ds, 0x9B6);                 //mov bx, word_19056
    _cx = 0x0006;                               //mov cx, 6
    _sar(_bx, _cl);                             //sar bx, cl
    _cwd();                                     //cwd
    _idiv(_bx);                                 //idiv bx
    _stack16(_bp + var_6) = _ax;                //mov [bp+var_6], ax
loc_11B7C:                                      //loc_11B7C:
    if ((short)_stack16(_bp + var_6) < (short)0x0001)//jl short loc_11B8E
        goto loc_11B8E;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _cx = 0x0006;                               //mov cx, 6
    _sar(_ax, _cl);                             //sar ax, cl
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_11B94
        goto loc_11B94;
loc_11B8E:                                      //loc_11B8E:
    _di = memory16(_ds, 0x9C6);                 //mov di, word_19066
    goto loc_11BA8;                             //jmp short loc_11BA8
loc_11B94:                                      //loc_11B94:
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _cx = 0x0006;                               //mov cx, 6
    _sar(_ax, _cl);                             //sar ax, cl
    _mul(_stack16(_bp + var_6));                //mul [bp+var_6]
    _di = _ax;                                  //mov di, ax
    _di = _di + memory16(_ds, 0x9C6);           //add di, word_19066
    _di += 0xfffc;                              //add di, 0FFFCh
loc_11BA8:                                      //loc_11BA8:
    _ax = memory16(_ds, 0x98C);                 //mov ax, word_1902C
    _ax = _ax - memory16(_ds, 0x9C6);           //sub ax, word_19066
    _stack16(_bp + var_4) = _ax;                //mov [bp+var_4], ax
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11BBB
        goto loc_11BBB;
    _ax = -_ax;                                 //neg ax
loc_11BBB:                                      //loc_11BBB:
    if ((short)_ax >= (short)0x0080)            //jge short loc_11C18
        goto loc_11C18;
    if ((short)memory16(_ds, 0xA4D) >= (short)0x004b)//jge short loc_11C18
        goto loc_11C18;
    if ((short)memory16(_ds, 0x98A) >= (short)0x009e)//jge short loc_11BD4
        goto loc_11BD4;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_11BD6;                             //jmp short loc_11BD6
loc_11BD4:                                      //loc_11BD4:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_11BD6:                                      //loc_11BD6:
    _push(_ax);                                 //push ax
    if ((short)memory16(_ds, 0x988) >= (short)0x0000)//jge short loc_11BE3
        goto loc_11BE3;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_11BE5;                             //jmp short loc_11BE5
loc_11BE3:                                      //loc_11BE3:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_11BE5:                                      //loc_11BE5:
    _dx = _pop();                               //pop dx
    _dx = _dx ^ _ax;                            //xor dx, ax
    if (_dx == 0)                               //jz short loc_11C01
        goto loc_11C01;
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax += 0xfff1;                              //add ax, 0FFF1h
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_11CE4;                             //jmp loc_11CE4
loc_11C01:                                      //loc_11C01:
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax += 0x000f;                              //add ax, 0Fh
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_11CE4;                             //jmp loc_11CE4
loc_11C18:                                      //loc_11C18:
    if ((short)memory16(_ds, 0x98A) > (short)0x0082)//jg short loc_11C23
        goto loc_11C23;
    goto loc_11CA6;                             //jmp loc_11CA6
loc_11C23:                                      //loc_11C23:
    _ax = _stack16(_bp + var_4);                //mov ax, [bp+var_4]
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11C2C
        goto loc_11C2C;
    _ax = -_ax;                                 //neg ax
loc_11C2C:                                      //loc_11C2C:
    if ((short)_ax <= (short)0x0006)            //jle short loc_11C62
        goto loc_11C62;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11C3A
        goto loc_11C3A;
    _ax = -_ax;                                 //neg ax
loc_11C3A:                                      //loc_11C3A:
    if ((short)_ax >= (short)0x0400)            //jge short loc_11C62
        goto loc_11C62;
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x98C);                 //mov ax, word_1902C
    _ax += 0xffc4;                              //add ax, 0FFC4h
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _dx = memory16(_ds, 0x9C6);                 //mov dx, word_19066
    _dx -= _ax;                                 //sub dx, ax
    _push(_dx);                                 //push dx
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_11CE4;                             //jmp loc_11CE4
loc_11C62:                                      //loc_11C62:
    _ax = 0x000a;                               //mov ax, 0Ah
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x98C);                 //mov ax, word_1902C
    _ax += 0xffc4;                              //add ax, 0FFC4h
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _dx = memory16(_ds, 0x9C6);                 //mov dx, word_19066
    _dx = _dx + _stack16(_bp + var_2);          //add dx, [bp+var_2]
    _ax += _dx;                                 //add ax, dx
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    if ((short)memory16(_ds, 0x98C) >= (short)0x0069)//jge short loc_11C9F
        goto loc_11C9F;
    if (memory16(_ds, 0x9D6) != 0x0000)         //jnz short loc_11C9A
        goto loc_11C9A;
    if ((short)memory16(_ds, 0x9DC) >= (short)0x0002)//jge short loc_11C9F
        goto loc_11C9F;
loc_11C9A:                                      //loc_11C9A:
    _ax = 0x0001;                               //mov ax, 1
    goto loc_11CA1;                             //jmp short loc_11CA1
loc_11C9F:                                      //loc_11C9F:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_11CA1:                                      //loc_11CA1:
    memory16(_ds, 0x9CC) = _ax;                 //mov word_1906C, ax
    goto loc_11CE4;                             //jmp short loc_11CE4
loc_11CA6:                                      //loc_11CA6:
    if ((short)_di >= (short)0x0003)            //jge short loc_11CB2
        goto loc_11CB2;
    _ax = 0x0006;                               //mov ax, 6
    _ax -= _di;                                 //sub ax, di
    _di = _ax;                                  //mov di, ax
loc_11CB2:                                      //loc_11CB2:
    if ((short)_di <= (short)0x007b)            //jle short loc_11CBE
        goto loc_11CBE;
    _ax = 0x00f6;                               //mov ax, 0F6h
    _ax -= _di;                                 //sub ax, di
    _di = _ax;                                  //mov di, ax
loc_11CBE:                                      //loc_11CBE:
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = _di;                                  //mov ax, di
    _ax = _ax + _stack16(_bp + var_2);          //add ax, [bp+var_2]
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_11CE4;                             //jmp short loc_11CE4
loc_11CD3:                                      //loc_11CD3:
    _ax = 0x0008;                               //mov ax, 8
    _push(_ax);                                 //push ax
    _ax = 0x0038;                               //mov ax, 38h
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
loc_11CE4:                                      //loc_11CE4:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_11CEA()
{
    const int var_6 = -6;                       //var_6  = word ptr -6
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0006;                              //sub sp, 6
    memory16(_ds, 0x9D2) = 0x0000;              //mov word_19072, 0
    _ax = memory16(_ds, 0x98A);                 //mov ax, word_1902A
    if ((short)_ax >= (short)memory16(_ds, 0xA4D))//jge short loc_11D04
        goto loc_11D04;
    memory16(_ds, 0xA4D) = _ax;                 //mov word_190ED, ax
loc_11D04:                                      //loc_11D04:
    _ax = memory16(_ds, 0x9E2);                 //mov ax, word_19082
    _bx = 0x000a;                               //mov bx, 0Ah
    _cwd();                                     //cwd
    _idiv(_bx);                                 //idiv bx
    _ax = 0x0005;                               //mov ax, 5
    _ax -= _dx;                                 //sub ax, dx
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    if (memory16(_ds, 0xA4B) != 0x0000)         //jnz short loc_11D1F
        goto loc_11D1F;
    goto loc_11E56;                             //jmp loc_11E56
loc_11D1F:                                      //loc_11D1F:
    _ax = memory16(_ds, 0xA14);                 //mov ax, word_190B4
    _ax &= 0x0001;                              //and ax, 1
    if (_ax == 0x0001)                          //jz short loc_11D2D
        goto loc_11D2D;
    goto loc_11E56;                             //jmp loc_11E56
loc_11D2D:                                      //loc_11D2D:
    _ax = memory16(_ds, 0xA3E);                 //mov ax, word_190DE
    if (_ax <= 0x0005)                          //jbe short loc_11D38
        goto loc_11D38;
    goto loc_11E4F;                             //jmp loc_11E4F
loc_11D38:                                      //loc_11D38:
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    switch (_bx)                                //jmp cs:off_11D41[bx]
    {
      case 0: goto loc_11D4D;
      case 2: goto loc_11D64;
      case 4: goto loc_11D7B;
      case 6: goto loc_11D92;
      case 8: goto loc_11DCD;
      case 10: goto loc_11E0A;
      default:
        _ASSERT(0);
    }
loc_11D4D:                                      //loc_11D4D:
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x00e8;                               //mov ax, 0E8h
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _si = _ax;                                  //mov si, ax
    goto loc_11E4F;                             //jmp loc_11E4F
loc_11D64:                                      //loc_11D64:
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x00ca;                               //mov ax, 0CAh
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _si = _ax;                                  //mov si, ax
    goto loc_11E4F;                             //jmp loc_11E4F
loc_11D7B:                                      //loc_11D7B:
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x00d0;                               //mov ax, 0D0h
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _si = _ax;                                  //mov si, ax
    goto loc_11E4F;                             //jmp loc_11E4F
loc_11D92:                                      //loc_11D92:
    if (memory16(_ds, 0x9B8) != 0x0000)         //jnz short loc_11DB8
        goto loc_11DB8;
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x00fa;                               //mov ax, 0FAh
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _si = _ax;                                  //mov si, ax
    _ax = _si;                                  //mov ax, si
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_11DB6
        goto loc_11DB6;
    goto loc_11E4F;                             //jmp loc_11E4F
loc_11DB6:                                      //loc_11DB6:
    goto loc_11DEE;                             //jmp short loc_11DEE
loc_11DB8:                                      //loc_11DB8:
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x00dc;                               //mov ax, 0DCh
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_11E4C;                             //jmp loc_11E4C
loc_11DCD:                                      //loc_11DCD:
    if (memory16(_ds, 0x9B8) != 0x0000)         //jnz short loc_11DF6
        goto loc_11DF6;
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x00be;                               //mov ax, 0BEh
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _si = _ax;                                  //mov si, ax
    _ax = _si;                                  //mov ax, si
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_11E4F
        goto loc_11E4F;
loc_11DEE:                                      //loc_11DEE:
    memory16(_ds, 0x9B8) = 0x0001;              //mov word_19058, 1
    goto loc_11E4F;                             //jmp short loc_11E4F
loc_11DF6:                                      //loc_11DF6:
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x00e6;                               //mov ax, 0E6h
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_11E4C;                             //jmp short loc_11E4C
loc_11E0A:                                      //loc_11E0A:
    if (memory16(_ds, 0x9B8) != 0x0000)         //jnz short loc_11E31
        goto loc_11E31;
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = 0x0115;                               //mov ax, 115h
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_11E2D
        goto loc_11E2D;
    memory16(_ds, 0x9B8) = 0x0001;              //mov word_19058, 1
loc_11E2D:                                      //loc_11E2D:
    _si = _si ^ _si;                            //xor si, si
    goto loc_11E4F;                             //jmp short loc_11E4F
loc_11E31:                                      //loc_11E31:
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x9B8);                 //mov ax, word_19058
    memory16(_ds, 0x9B8) += 1;                  //inc word_19058
    _dx = 0x0110;                               //mov dx, 110h
    _dx -= _ax;                                 //sub dx, ax
    _push(_dx);                                 //push dx
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
loc_11E4C:                                      //loc_11E4C:
    _si = 0x0001;                               //mov si, 1
loc_11E4F:                                      //loc_11E4F:
    memory16(_ds, 0x9D2) = _si;                 //mov word_19072, si
    goto loc_12002;                             //jmp loc_12002
loc_11E56:                                      //loc_11E56:
    if ((short)memory16(_ds, 0x9B6) > (short)0x0000)//jg short loc_11E60
        goto loc_11E60;
    goto loc_11FF0;                             //jmp loc_11FF0
loc_11E60:                                      //loc_11E60:
    if ((short)memory16(_ds, 0x9C6) > (short)0x007d)//jg short loc_11E6A
        goto loc_11E6A;
    goto loc_11FF0;                             //jmp loc_11FF0
loc_11E6A:                                      //loc_11E6A:
    _ax = memory16(_ds, 0x9B6);                 //mov ax, word_19056
    _cx = 0x0006;                               //mov cx, 6
    _sar(_ax, _cl);                             //sar ax, cl
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_11E7D
        goto loc_11E7D;
    _stack16(_bp + var_6) = 0x0000;             //mov [bp+var_6], 0
    goto loc_11E93;                             //jmp short loc_11E93
loc_11E7D:                                      //loc_11E7D:
    _ax = 0x008c;                               //mov ax, 8Ch
    _ax = _ax - memory16(_ds, 0x98A);           //sub ax, word_1902A
    _bx = memory16(_ds, 0x9B6);                 //mov bx, word_19056
    _cx = 0x0006;                               //mov cx, 6
    _sar(_bx, _cl);                             //sar bx, cl
    _cwd();                                     //cwd
    _idiv(_bx);                                 //idiv bx
    _stack16(_bp + var_6) = _ax;                //mov [bp+var_6], ax
loc_11E93:                                      //loc_11E93:
    if ((short)_stack16(_bp + var_6) < (short)0x0001)//jl short loc_11EA5
        goto loc_11EA5;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _cx = 0x0006;                               //mov cx, 6
    _sar(_ax, _cl);                             //sar ax, cl
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_11EAB
        goto loc_11EAB;
loc_11EA5:                                      //loc_11EA5:
    _di = memory16(_ds, 0x9C6);                 //mov di, word_19066
    goto loc_11EBF;                             //jmp short loc_11EBF
loc_11EAB:                                      //loc_11EAB:
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _cx = 0x0006;                               //mov cx, 6
    _sar(_ax, _cl);                             //sar ax, cl
    _mul(_stack16(_bp + var_6));                //mul [bp+var_6]
    _di = _ax;                                  //mov di, ax
    _di = _di + memory16(_ds, 0x9C6);           //add di, word_19066
    _di += 0xfffc;                              //add di, 0FFFCh
loc_11EBF:                                      //loc_11EBF:
    _ax = memory16(_ds, 0x98E);                 //mov ax, word_1902E
    _ax = _ax - memory16(_ds, 0x9C6);           //sub ax, word_19066
    _stack16(_bp + var_4) = _ax;                //mov [bp+var_4], ax
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11ED2
        goto loc_11ED2;
    _ax = -_ax;                                 //neg ax
loc_11ED2:                                      //loc_11ED2:
    if ((short)_ax >= (short)0x0080)            //jge short loc_11F31
        goto loc_11F31;
    if ((short)memory16(_ds, 0xA4D) >= (short)0x004b)//jge short loc_11F31
        goto loc_11F31;
    if ((short)memory16(_ds, 0x98A) >= (short)0x009e)//jge short loc_11EEB
        goto loc_11EEB;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_11EED;                             //jmp short loc_11EED
loc_11EEB:                                      //loc_11EEB:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_11EED:                                      //loc_11EED:
    _push(_ax);                                 //push ax
    if ((short)memory16(_ds, 0x988) >= (short)0x0000)//jge short loc_11EFA
        goto loc_11EFA;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_11EFC;                             //jmp short loc_11EFC
loc_11EFA:                                      //loc_11EFA:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_11EFC:                                      //loc_11EFC:
    _dx = _pop();                               //pop dx
    _dx = _dx ^ _ax;                            //xor dx, ax
    if (_dx == 0)                               //jz short loc_11F19
        goto loc_11F19;
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax += 0x000f;                              //add ax, 0Fh
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_12002;                             //jmp loc_12002
loc_11F19:                                      //loc_11F19:
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x9C6);                 //mov ax, word_19066
    _ax += 0xfff1;                              //add ax, 0FFF1h
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_12002;                             //jmp loc_12002
loc_11F31:                                      //loc_11F31:
    if ((short)memory16(_ds, 0x98A) > (short)0x0082)//jg short loc_11F3C
        goto loc_11F3C;
    goto loc_11FC0;                             //jmp loc_11FC0
loc_11F3C:                                      //loc_11F3C:
    _ax = _stack16(_bp + var_4);                //mov ax, [bp+var_4]
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11F45
        goto loc_11F45;
    _ax = -_ax;                                 //neg ax
loc_11F45:                                      //loc_11F45:
    if ((short)_ax <= (short)0x0006)            //jle short loc_11F7A
        goto loc_11F7A;
    _ax = memory16(_ds, 0x988);                 //mov ax, word_19028
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_11F53
        goto loc_11F53;
    _ax = -_ax;                                 //neg ax
loc_11F53:                                      //loc_11F53:
    if ((short)_ax >= (short)0x0400)            //jge short loc_11F7A
        goto loc_11F7A;
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x98E);                 //mov ax, word_1902E
    _ax += 0xff26;                              //add ax, 0FF26h
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _ax = _ax + memory16(_ds, 0x9C6);           //add ax, word_19066
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_12002;                             //jmp loc_12002
loc_11F7A:                                      //loc_11F7A:
    _ax = 0x000a;                               //mov ax, 0Ah
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x98E);                 //mov ax, word_1902E
    _ax += 0xff26;                              //add ax, 0FF26h
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _dx = memory16(_ds, 0x9C6);                 //mov dx, word_19066
    _dx = _dx - _stack16(_bp + var_2);          //sub dx, [bp+var_2]
    _dx -= _ax;                                 //sub dx, ax
    _push(_dx);                                 //push dx
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    if ((short)memory16(_ds, 0x98E) <= (short)0x00af)//jle short loc_11FB9
        goto loc_11FB9;
    if (memory16(_ds, 0x9D6) != 0x0001)         //jnz short loc_11FB4
        goto loc_11FB4;
    if ((short)memory16(_ds, 0x9DC) >= (short)0x0002)//jge short loc_11FB9
        goto loc_11FB9;
loc_11FB4:                                      //loc_11FB4:
    _ax = 0x0001;                               //mov ax, 1
    goto loc_11FBB;                             //jmp short loc_11FBB
loc_11FB9:                                      //loc_11FB9:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_11FBB:                                      //loc_11FBB:
    memory16(_ds, 0x9D2) = _ax;                 //mov word_19072, ax
    goto loc_12002;                             //jmp short loc_12002
loc_11FC0:                                      //loc_11FC0:
    if ((short)_di >= (short)0x009e)            //jge short loc_11FCD
        goto loc_11FCD;
    _ax = 0x013c;                               //mov ax, 13Ch
    _ax -= _di;                                 //sub ax, di
    _di = _ax;                                  //mov di, ax
loc_11FCD:                                      //loc_11FCD:
    if ((short)_di <= (short)0x0115)            //jle short loc_11FDA
        goto loc_11FDA;
    _ax = 0x022a;                               //mov ax, 22Ah
    _ax -= _di;                                 //sub ax, di
    _di = _ax;                                  //mov di, ax
loc_11FDA:                                      //loc_11FDA:
    _ax = 0x0003;                               //mov ax, 3
    _push(_ax);                                 //push ax
    _ax = _di;                                  //mov ax, di
    _ax = _ax - _stack16(_bp + var_2);          //sub ax, [bp+var_2]
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
    goto loc_12002;                             //jmp short loc_12002
loc_11FF0:                                      //loc_11FF0:
    _ax = 0x0008;                               //mov ax, 8
    _push(_ax);                                 //push ax
    _ax = 0x00d3;                               //mov ax, 0D3h
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_1199B();                                //call sub_1199B
    _sp += 0x0006;                              //add sp, 6
loc_12002:                                      //loc_12002:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_12008()
{
    WORD _cs = _seg000;

    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0004;                              //sub sp, 4
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, 0x9B6) = _ax;                 //mov word_19056, ax
    memory16(_ds, 0x988) = _ax;                 //mov word_19028, ax
    memory16(_ds, 0xA0E) = _ax;                 //mov word_190AE, ax
    memory16(_ds, 0xA3C) = _ax;                 //mov word_190DC, ax
    memory16(_ds, 0x9DC) = _ax;                 //mov word_1907C, ax
    memory16(_ds, 0x986) = 0x0006;              //mov word_19026, 6
    memory16(_ds, 0xA4D) = 0x00c8;              //mov word_190ED, 0C8h
    _si = _ax;                                  //mov si, ax
    goto loc_120EC;                             //jmp loc_120EC
loc_12032:                                      //loc_12032:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 2444);            //mov ax, [bx+98Ch]
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2448) = _ax;            //mov [bx+990h], ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2532) = 0x00ad;         //mov word ptr [bx+9E4h], 0ADh
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2536) = 0xffff;         //mov word ptr [bx+9E8h], 0FFFFh
    _ax = _ax ^ _ax;                            //xor ax, ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2494) = _ax;            //mov [bx+9BEh], ax
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2508) = _ax;            //mov [bx+9CCh], ax
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2504) = _ax;            //mov [bx+9C8h], ax
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _bx + 2506) = _ax;            //mov [bx+9CAh], ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2576) = _ax;            //mov [bx+0A10h], ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2526) = _ax;            //mov [bx+9DEh], ax
    _ax = _si;                                  //mov ax, si
    _ax += 1;                                   //inc ax
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = memory16(_ds, _bx + 170);             //mov ax, [bx+0AAh]
    _push(_ax);                                 //push ax
    _ax = _si;                                  //mov ax, si
    _ax += 1;                                   //inc ax
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = memory16(_ds, _bx + 172);             //mov ax, [bx+0ACh]
    _ax -= 1;                                   //dec ax
    _dx = _pop();                               //pop dx
    if ((short)_dx >= (short)_ax)               //jge short loc_120EB
        goto loc_120EB;
    _ax = 0x0002;                               //mov ax, 2
    _ax -= _si;                                 //sub ax, si
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = memory16(_ds, _bx + 170);             //mov ax, [bx+0AAh]
    _push(_ax);                                 //push ax
    _ax = 0x0002;                               //mov ax, 2
    _ax -= _si;                                 //sub ax, si
    _dx = 0x003c;                               //mov dx, 3Ch
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _ax = memory16(_ds, _bx + 172);             //mov ax, [bx+0ACh]
    _ax -= 1;                                   //dec ax
    _dx = _pop();                               //pop dx
    if (_dx != _ax)                             //jnz short loc_120EB
        goto loc_120EB;
    memory16(_ds, 0x9D8) = _si;                 //mov word_19078, si
loc_120EB:                                      //loc_120EB:
    _si += 1;                                   //inc si
loc_120EC:                                      //loc_120EC:
    if ((short)_si >= (short)0x0002)            //jge short loc_120F4
        goto loc_120F4;
    goto loc_12032;                             //jmp loc_12032
loc_120F4:                                      //loc_120F4:
    _ax = memory16(_ds, 0xA44);                 //mov ax, word_190E4
    _sar(_ax, 1);                               //sar ax, 1
    _ax = _ax + memory16(_ds, 0xA44);           //add ax, word_190E4
    memory16(_ds, 0xA42) = _ax;                 //mov word_190E2, ax
    _ax = memory16(_ds, 0x9D8);                 //mov ax, word_19078
    _dx = 0x00a5;                               //mov dx, 0A5h
    _mul(_dx);                                  //mul dx
    _ax += 0x0040;                              //add ax, 40h
    memory16(_ds, 0xA3A) = _ax;                 //mov word_190DA, ax
    memory16(_ds, 0x9C6) = _ax;                 //mov word_19066, ax
    _cx = 0x0006;                               //mov cx, 6
    _ax <<= _cl;                                //shl ax, cl
    memory16(_ds, 0xA40) = _ax;                 //mov word_190E0, ax
    _ax = 0x0087;                               //mov ax, 87h
    memory16(_ds, 0x9C4) = _ax;                 //mov word_19064, ax
    memory16(_ds, 0x98A) = _ax;                 //mov word_1902A, ax
    _ax <<= _cl;                                //shl ax, cl
    memory16(_ds, 0x9EC) = _ax;                 //mov word_1908C, ax
    _ax = memory16(_ds, 0x9D8);                 //mov ax, word_19078
    _ax += 0x0002;                              //add ax, 2
    memory16(_ds, 0xA14) = _ax;                 //mov word_190B4, ax
    memory16(_ds, 0x9D6) = 0x0002;              //mov word_19076, 2
    _ax = 0x0001;                               //mov ax, 1
    memory16(_ds, 0x9BC) = _ax;                 //mov word_1905C, ax
    memory16(_ds, 0xA4B) = _ax;                 //mov word_190EB, ax
    memory16(_ds, 0x9D4) = 0x0000;              //mov word_19074, 0
    _ax = _ax ^ _ax;                            //xor ax, ax
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    _stack16(_bp + var_4) = _ax;                //mov [bp+var_4], ax
    _ax = memory16(_ds, 0xE6);                  //mov ax, word_18786
    _dx = 0x000e;                               //mov dx, 0Eh
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _al = memory(_ds, _bx + 238);               //mov al, [bx+0EEh]
    _ah = 0x00;                                 //mov ah, 0
    if (_ax == 0x0020)                          //jz short loc_12175
        goto loc_12175;
    if (_ax == 0x0043)                          //jz short loc_1217C
        goto loc_1217C;
    if (_ax == 0x004a)                          //jz short loc_1216E
        goto loc_1216E;
    goto loc_12181;                             //jmp short loc_12181
loc_1216E:                                      //loc_1216E:
    _stack16(_bp + var_4) = 0x0001;             //mov [bp+var_4], 1
    goto loc_12181;                             //jmp short loc_12181
loc_12175:                                      //loc_12175:
    _stack16(_bp + var_4) = 0x0002;             //mov [bp+var_4], 2
    goto loc_12181;                             //jmp short loc_12181
loc_1217C:                                      //loc_1217C:
    _stack16(_bp + var_4) = 0x0003;             //mov [bp+var_4], 3
loc_12181:                                      //loc_12181:
    _ax = memory16(_ds, 0x122);                 //mov ax, word_187C2
    _dx = 0x000e;                               //mov dx, 0Eh
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _al = memory(_ds, _bx + 298);               //mov al, [bx+12Ah]
    _ah = 0x00;                                 //mov ah, 0
    if (_ax == 0x0020)                          //jz short loc_121A9
        goto loc_121A9;
    if (_ax == 0x0043)                          //jz short loc_121B0
        goto loc_121B0;
    if (_ax == 0x004a)                          //jz short loc_121A2
        goto loc_121A2;
    goto loc_121B5;                             //jmp short loc_121B5
loc_121A2:                                      //loc_121A2:
    _stack16(_bp + var_2) = 0x0001;             //mov [bp+var_2], 1
    goto loc_121B5;                             //jmp short loc_121B5
loc_121A9:                                      //loc_121A9:
    _stack16(_bp + var_2) = 0x0002;             //mov [bp+var_2], 2
    goto loc_121B5;                             //jmp short loc_121B5
loc_121B0:                                      //loc_121B0:
    _stack16(_bp + var_2) = 0x0003;             //mov [bp+var_2], 3
loc_121B5:                                      //loc_121B5:
    _ax = 0x0009;                               //mov ax, 9
    _push(_ax);                                 //push ax
    sub_1413C();                                //call sub_1413C
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    memory16(_ds, 0xA49) = _dx;                 //mov word_190E9, dx
    memory16(_ds, 0xA47) = _ax;                 //mov word_190E7, ax
    _ax = 0x0c5d;                               //mov ax, 0C5Dh
    _dx = _cs;                                  //mov dx, cs
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = 0x0009;                               //mov ax, 9
    _push(_ax);                                 //push ax
    sub_1414C();                                //call sub_1414C
    _sp += 0x0006;                              //add sp, 6
    sub_10BEE();                                //call sub_10BEE
    _si = _si ^ _si;                            //xor si, si
loc_121DB:                                      //loc_121DB:
    if (memory16(_ds, 0x9D4) == 0x0000)         //jz short loc_121E5
        goto loc_121E5;
    goto loc_12298;                             //jmp loc_12298
loc_121E5:                                      //loc_121E5:
    _ax = memory16(_ds, 0x9E2);                 //mov ax, word_19082
    _dx = 0x0005;                               //mov dx, 5
    _mul(_dx);                                  //mul dx
    _ax += 1;                                   //inc ax
    memory16(_ds, 0x9E2) = _ax;                 //mov word_19082, ax
    _ax = _stack16(_bp + var_4);                //mov ax, [bp+var_4]
    _ax -= 1;                                   //dec ax
    if (_ax > 0x0002)                           //ja short loc_12224
        goto loc_12224;
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    switch (_bx)                                //jmp cs:off_12203[bx]
    {
      case 0: goto loc_12209;
      case 2: goto loc_12213;
      case 4: goto loc_12221;
      default:
        _ASSERT(0);
    }
loc_12209:                                      //loc_12209:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_10D50();                                //call sub_10D50
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    goto loc_12224;                             //jmp short loc_12224
loc_12213:                                      //loc_12213:
    _si |= _si;                                 //or si, si
    if (_si == 0)                               //jz short loc_12224
        goto loc_12224;
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_10DE9();                                //call sub_10DE9
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    goto loc_12224;                             //jmp short loc_12224
loc_12221:                                      //loc_12221:
    sub_119F4();                                //call sub_119F4
loc_12224:                                      //loc_12224:
    _ax = _stack16(_bp + var_2);                //mov ax, [bp+var_2]
    _ax -= 1;                                   //dec ax
    if (_ax > 0x0002)                           //ja short loc_12259
        goto loc_12259;
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    switch (_bx)                                //jmp cs:off_12236[bx]
    {
      case 0: goto loc_1223C;
      case 2: goto loc_12247;
      case 4: goto loc_12256;
      default:
        _ASSERT(0);
    }
loc_1223C:                                      //loc_1223C:
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_10D50();                                //call sub_10D50
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    goto loc_12259;                             //jmp short loc_12259
loc_12247:                                      //loc_12247:
    _si |= _si;                                 //or si, si
    if (_si == 0)                               //jz short loc_12259
        goto loc_12259;
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_10DE9();                                //call sub_10DE9
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
    goto loc_12259;                             //jmp short loc_12259
loc_12256:                                      //loc_12256:
    sub_11CEA();                                //call sub_11CEA
loc_12259:                                      //loc_12259:
    _ax = 0x0001;                               //mov ax, 1
    _ax -= _si;                                 //sub ax, si
    _si = _ax;                                  //mov si, ax
    sub_10E7A();                                //call sub_10E7A
    if (memory16(_ds, 0xA4B) == 0x0000)         //jz short loc_12275
        goto loc_12275;
    sub_11121();                                //call sub_11121
    sub_11452();                                //call sub_11452
    _di = 0x0001;                               //mov di, 1
    goto loc_12284;                             //jmp short loc_12284
loc_12275:                                      //loc_12275:
    _di |= _di;                                 //or di, di
    if (_di == 0)                               //jz short loc_12284
        goto loc_12284;
    sub_11121();                                //call sub_11121
    sub_11006();                                //call sub_11006
    _di = _ax;                                  //mov di, ax
    sub_11452();                                //call sub_11452
loc_12284:                                      //loc_12284:
    _di |= _di;                                 //or di, di
    if (_di == 0)                               //jz short loc_12292
        goto loc_12292;
    if ((short)memory16(_ds, 0x9DC) > (short)0x0002)//jg short loc_12292
        goto loc_12292;
    goto loc_121DB;                             //jmp loc_121DB
loc_12292:                                      //loc_12292:
    sub_11747();                                //call sub_11747
    goto loc_121DB;                             //jmp loc_121DB
loc_12298:                                      //loc_12298:
    sub_1166F();                                //call sub_1166F
    _push(memory16(_ds, 0xA49));                //push word_190E9
    _push(memory16(_ds, 0xA47));                //push word_190E7
    _ax = 0x0009;                               //mov ax, 9
    _push(_ax);                                 //push ax
    sub_1414C();                                //call sub_1414C
    _sp += 0x0006;                              //add sp, 6
loc_122AD:                                      //loc_122AD:
    sub_1432B();                                //call sub_1432B
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_122B9
        goto loc_122B9;
    sub_14104();                                //call sub_14104
    goto loc_122AD;                             //jmp short loc_122AD
loc_122B9:                                      //loc_122B9:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_122BF()
{
    _dx = 0x03da;                               //mov dx, 3DAh
loc_122C2:                                      //loc_122C2:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_122C2
        goto loc_122C2;
    _dx = 0x03da;                               //mov dx, 3DAh
loc_122CA:                                      //loc_122CA:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_122CA
        goto loc_122CA;
}

void sub_122D0()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x000c;                              //sub sp, 0Ch
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    _cl = _al;                                  //mov cl, al
    _al &= 0xfe;                                //and al, 0FEh
    _dx = 0x0028;                               //mov dx, 28h
    _mul(_dx);                                  //mul dx
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _di += _ax;                                 //add di, ax
    _si = _stack16(_bp + arg_4);                //mov si, [bp+arg_4]
    _bx = memory16(_ds, _si);                   //mov bx, [si]
    _bx += 0x0004;                              //add bx, 4
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _al += 1;                                   //inc al
    _al >>= 1;                                  //shr al, 1
    _si += 0x0004;                              //add si, 4
    _dx = 0x0050;                               //mov dx, 50h
    _dx -= _bx;                                 //sub dx, bx
    if (!(_cl & 0x01))                          //jz short loc_12330
        goto loc_12330;
    _di += 0x2000;                              //add di, 2000h
loc_12316:                                      //loc_12316:
    _cx = _bx;                                  //mov cx, bx
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _di += _dx;                                 //add di, dx
    _cx = _bx;                                  //mov cx, bx
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di -= _bx;                                 //sub di, bx
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _al -= 1;                                   //dec al
    if (_FIXME_)                                //jg short loc_12316
        goto loc_12316;
    goto loc_12348;                             //jmp short loc_12348
loc_12330:                                      //loc_12330:
    _cx = _bx;                                  //mov cx, bx
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di -= _bx;                                 //sub di, bx
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _cx = _bx;                                  //mov cx, bx
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _di += _dx;                                 //add di, dx
    _al -= 1;                                   //dec al
    if (_FIXME_)                                //jg short loc_12330
        goto loc_12330;
loc_12348:                                      //loc_12348:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_1234E()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x000c;                              //sub sp, 0Ch
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    _cl = _al;                                  //mov cl, al
    _al &= 0xfe;                                //and al, 0FEh
    _dx = 0x0028;                               //mov dx, 28h
    _mul(_dx);                                  //mul dx
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _di += _ax;                                 //add di, ax
    _si = _stack16(_bp + arg_4);                //mov si, [bp+arg_4]
    _bx = memory16(_ds, _si);                   //mov bx, [si]
    _bx += 0x0004;                              //add bx, 4
    _bx >>= 1;                                  //shr bx, 1
    _bl >>= 1;                                  //shr bl, 1
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _al += 1;                                   //inc al
    _al >>= 1;                                  //shr al, 1
    _ah = _al;                                  //mov ah, al
    _si += 0x0004;                              //add si, 4
    _dx = 0x0050;                               //mov dx, 50h
    _dx -= _bx;                                 //sub dx, bx
    if (!(_cl & 0x01))                          //jz short loc_123BA
        goto loc_123BA;
    _di += 0x2000;                              //add di, 2000h
loc_12396:                                      //loc_12396:
    _cl = _bl;                                  //mov cl, bl
loc_12398:                                      //loc_12398:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_12398
        goto loc_12398;
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _di += _dx;                                 //add di, dx
    _cl = _bl;                                  //mov cl, bl
loc_123A7:                                      //loc_123A7:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_123A7
        goto loc_123A7;
    _di -= _bx;                                 //sub di, bx
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _ah -= 1;                                   //dec ah
    if (_FIXME_)                                //jg short loc_12396
        goto loc_12396;
    goto loc_123DC;                             //jmp short loc_123DC
loc_123BA:                                      //loc_123BA:
    _cl = _bl;                                  //mov cl, bl
loc_123BC:                                      //loc_123BC:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_123BC
        goto loc_123BC;
    _di -= _bx;                                 //sub di, bx
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _cl = _bl;                                  //mov cl, bl
loc_123CB:                                      //loc_123CB:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_123CB
        goto loc_123CB;
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _di += _dx;                                 //add di, dx
    _ah -= 1;                                   //dec ah
    if (_FIXME_)                                //jg short loc_123BA
        goto loc_123BA;
loc_123DC:                                      //loc_123DC:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_123E2()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x000c;                              //sub sp, 0Ch
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    _cl = _al;                                  //mov cl, al
    _al &= 0xfe;                                //and al, 0FEh
    _dx = 0x0028;                               //mov dx, 28h
    _mul(_dx);                                  //mul dx
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _di += _ax;                                 //add di, ax
    _si = _stack16(_bp + arg_4);                //mov si, [bp+arg_4]
    _bx = memory16(_ds, _si);                   //mov bx, [si]
    _bx += 0x0004;                              //add bx, 4
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _al += 1;                                   //inc al
    _al >>= 1;                                  //shr al, 1
    _ah = _al;                                  //mov ah, al
    _al = _al ^ _al;                            //xor al, al
    _dx = 0x0050;                               //mov dx, 50h
    _dx -= _bx;                                 //sub dx, bx
    if (!(_cl & 0x01))                          //jz short loc_12443
        goto loc_12443;
    _di += 0x2000;                              //add di, 2000h
loc_12429:                                      //loc_12429:
    _cx = _bx;                                  //mov cx, bx
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _di += _dx;                                 //add di, dx
    _cx = _bx;                                  //mov cx, bx
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di -= _bx;                                 //sub di, bx
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _ah -= 1;                                   //dec ah
    if (_FIXME_)                                //jg short loc_12429
        goto loc_12429;
    goto loc_1245B;                             //jmp short loc_1245B
loc_12443:                                      //loc_12443:
    _cx = _bx;                                  //mov cx, bx
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di -= _bx;                                 //sub di, bx
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _cx = _bx;                                  //mov cx, bx
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di = _di ^ 0x2000;                         //xor di, 2000h
    _di += _dx;                                 //add di, dx
    _ah -= 1;                                   //dec ah
    if (_FIXME_)                                //jg short loc_12443
        goto loc_12443;
loc_1245B:                                      //loc_1245B:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void loc_13C0C()
{
    _ax = _stack16(_bp + 4);                    //mov ax, [bp+4]
    _bx = memory16(_ds, 0x370);                 //mov bx, word_18A10
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 2642) = _ax;            //mov [bx+0A52h], ax
    memory16(_ds, 0x370) += 1;                  //inc word_18A10
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_13C1F:                                      //loc_13C1F:
    _bp = _pop();                               //pop bp
}

void sub_13C21()
{
    _interrupt(17);                             //int 11h
}

void sub_13C3B()
{
    const int arg_0 = 4;                        //arg_0  = byte ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ah = _stack16(_bp + arg_0);                //mov ah, [bp+arg_0]
    _interrupt(22);                             //int 16h
    if (!_flags.zero)                           //jnz short loc_13C4D
        goto loc_13C4D;
    if (_stack16(_bp + arg_0) != 0x0001)        //jnz short loc_13C4D
        goto loc_13C4D;
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_13C4D:                                      //loc_13C4D:
    _bp = _pop();                               //pop bp
}

void sub_13C4F()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _dx = _sp;                                  //mov dx, sp
    _dx -= 0x0100;                              //sub dx, 100h
    if (_ax >= _dx)                             //jnb short loc_13C64
        goto loc_13C64;
    memory16(_ds, 0x8E) = _ax;                  //mov word_1872E, ax
    goto loc_13C6D;                             //jmp short loc_13C6D
loc_13C64:                                      //loc_13C64:
    memory16(_ds, 0x88) = 0x0008;               //mov word_18728, 8
    _ax = 0xffff;                               //mov ax, 0FFFFh
loc_13C6D:                                      //loc_13C6D:
    _bp = _pop();                               //pop bp
}

void sub_13C6F()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    const int arg_2 = 6;                        //arg_2  = word ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _dx = _stack16(_bp + arg_2);                //mov dx, [bp+arg_2]
    _flags.carry = (_ax + memory16(_ds, 0x8E)) >= 0x10000;
    _ax = _ax + memory16(_ds, 0x8E);
    _dx = _dx + 0x0000 + _flags.carry;          //adc dx, 0
    _cx = _ax;                                  //mov cx, ax
    _flags.carry = (_cx + 0x0100) >= 0x10000;   //add cx, 100h
    _cx += 0x0100;
    _dx = _dx + 0x0000 + _flags.carry;          //adc dx, 0
    _dx |= _dx;                                 //or dx, dx
    if (_dx != 0)                               //jnz short loc_13C96
        goto loc_13C96;
    if (_cx >= _sp)                             //jnb short loc_13C96
        goto loc_13C96;
    _xchg(_ax, memory16(_ds, 0x8E));            //xchg ax, word_1872E
    goto loc_13C9F;                             //jmp short loc_13C9F
loc_13C96:                                      //loc_13C96:
    memory16(_ds, 0x88) = 0x0008;               //mov word_18728, 8
    _ax = 0xffff;                               //mov ax, 0FFFFh
loc_13C9F:                                      //loc_13C9F:
    _bp = _pop();                               //pop bp
}

void sub_13CA1()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_13C4F();                                //call sub_13C4F
    _cx = _pop();                               //pop cx
    _bp = _pop();                               //pop bp
}

void sub_13CBD()
{
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    _ah = 0x3e;                                 //mov ah, 3Eh
    _bx = _si;                                  //mov bx, si
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_13CD8
        goto loc_13CD8;
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 1000) = 0xffff;         //mov word ptr [bx+3E8h], 0FFFFh
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_13CDC;                             //jmp short loc_13CDC
loc_13CD8:                                      //loc_13CD8:
    _push(_ax);                                 //push ax
    sub_142F2();                                //call sub_142F2
loc_13CDC:                                      //loc_13CDC:
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
}

void sub_13CDF()
{
    const int var_3 = -3;                       //var_3  = byte ptr -3
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0004;                              //sub sp, 4
    _stack16(_bp + var_3) = 0x0000;             //mov [bp+var_3], 0
    sub_150E0();                                //call sub_150E0
    _ah = 0x00;                                 //mov ah, 0
    _si = _ax;                                  //mov si, ax
    sub_150E0();                                //call sub_150E0
    _cx = 0x0008;                               //mov cx, 8
    _ax >>= _cl;                                //shr ax, cl
    _ah = 0x00;                                 //mov ah, 0
    _di = _ax;                                  //mov di, ax
loc_13CFE:                                      //loc_13CFE:
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    _stack16(_bp + arg_2) -= 1;                 //dec [bp+arg_2]
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_13D0B
        goto loc_13D0B;
    goto loc_13E04;                             //jmp loc_13E04
loc_13D0B:                                      //loc_13D0B:
    _bx = _stack16(_bp + arg_4);                //mov bx, [bp+arg_4]
    _stack16(_bp + arg_4) += 1;                 //inc [bp+arg_4]
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _stack16(_bp + var_3) = _al;                //mov [bp+var_3], al
    _ah = 0x00;                                 //mov ah, 0
    if (_ax > 0x000d)                           //ja short loc_13D70
        goto loc_13D70;
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    switch (_bx)                                //jmp cs:off_13D26[bx]
    {
      case 0: goto loc_13D42;
      case 2: goto loc_13D70;
      case 4: goto loc_13D70;
      case 6: goto loc_13D70;
      case 8: goto loc_13D70;
      case 10: goto loc_13D70;
      case 12: goto loc_13D70;
      case 14: goto loc_13D47;
      case 16: goto loc_13D51;
      case 18: goto loc_13D70;
      case 20: goto loc_13D66;
      case 22: goto loc_13D70;
      case 24: goto loc_13D70;
      case 26: goto loc_13D5D;
      default:
        _ASSERT(0);
    }
loc_13D42:                                      //loc_13D42:
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_13E18;                             //jmp loc_13E18
loc_13D47:                                      //loc_13D47:
    _ah = 0x0e;                                 //mov ah, 0Eh
    _al = 0x07;                                 //mov al, 7
    sub_13E83();                                //call sub_13E83
    goto loc_13DC4;                             //jmp loc_13DC4
loc_13D51:                                      //loc_13D51:
    _al = memory(_ds, 0x372);                   //mov al, byte ptr word_18A12
    _ah = 0x00;                                 //mov ah, 0
    if ((short)_ax >= (short)_si)               //jge short loc_13DC4
        goto loc_13DC4;
    _si -= 1;                                   //dec si
    goto loc_13DC4;                             //jmp short loc_13DC4
loc_13D5D:                                      //loc_13D5D:
    _al = memory(_ds, 0x372);                   //mov al, byte ptr word_18A12
    _ah = 0x00;                                 //mov ah, 0
    _si = _ax;                                  //mov si, ax
    goto loc_13DC4;                             //jmp short loc_13DC4
loc_13D66:                                      //loc_13D66:
    _al = memory(_ds, 0x374);                   //mov al, byte ptr word_18A14
    _ah = 0x00;                                 //mov ah, 0
    _si = _ax;                                  //mov si, ax
    _si += 1;                                   //inc si
    goto loc_13DC4;                             //jmp short loc_13DC4
loc_13D70:                                      //loc_13D70:
    if (memory(_ds, 0x37B) != 0x00)             //jnz short loc_13DA3
        goto loc_13DA3;
    if (memory16(_ds, 0x381) == 0x0000)         //jz short loc_13DA3
        goto loc_13DA3;
    _ah = memory(_ds, 0x376);                   //mov ah, byte_18A16
    _al = _stack16(_bp + var_3);                //mov al, [bp+var_3]
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    _ax = _si;                                  //mov ax, si
    _ax += 1;                                   //inc ax
    _push(_ax);                                 //push ax
    _ax = _di;                                  //mov ax, di
    _ax += 1;                                   //inc ax
    _push(_ax);                                 //push ax
    sub_15045();                                //call sub_15045
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_2]
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    sub_15068();                                //call sub_15068
    goto loc_13DC3;                             //jmp short loc_13DC3
loc_13DA3:                                      //loc_13DA3:
    _ax = _si;                                  //mov ax, si
    _dl = _al;                                  //mov dl, al
    _ax = _di;                                  //mov ax, di
    _dh = _al;                                  //mov dh, al
    _ah = 0x02;                                 //mov ah, 2
    _bh = 0x00;                                 //mov bh, 0
    sub_13E83();                                //call sub_13E83
    _bl = memory(_ds, 0x376);                   //mov bl, byte_18A16
    _al = _stack16(_bp + var_3);                //mov al, [bp+var_3]
    _ah = 0x09;                                 //mov ah, 9
    _bh = 0x00;                                 //mov bh, 0
    _cx = 0x0001;                               //mov cx, 1
    sub_13E83();                                //call sub_13E83
loc_13DC3:                                      //loc_13DC3:
    _si += 1;                                   //inc si
loc_13DC4:                                      //loc_13DC4:
    _al = memory(_ds, 0x374);                   //mov al, byte ptr word_18A14
    _ah = 0x00;                                 //mov ah, 0
    if ((short)_ax < (short)_si)                //jl short loc_13DD0
        goto loc_13DD0;
    goto loc_13CFE;                             //jmp loc_13CFE
loc_13DD0:                                      //loc_13DD0:
    _al = memory(_ds, 0x372);                   //mov al, byte ptr word_18A12
    _ah = 0x00;                                 //mov ah, 0
    _si = _ax;                                  //mov si, ax
    _di += 1;                                   //inc di
    _ax = _di;                                  //mov ax, di
    _dl = memory(_ds, 0x375);                   //mov dl, byte ptr word_18A14+1
    _dh = 0x00;                                 //mov dh, 0
    if ((short)_ax > (short)_dx)                //jg short loc_13DE7
        goto loc_13DE7;
    goto loc_13CFE;                             //jmp loc_13CFE
loc_13DE7:                                      //loc_13DE7:
    _al = 0x06;                                 //mov al, 6
    _push(_ax);                                 //push ax
    _push(memory16(_ds, 0x372));                //push word_18A12
    _push(memory16(_ds, 0x373));                //push word_18A12+1
    _push(memory16(_ds, 0x374));                //push word_18A14
    _push(memory16(_ds, 0x375));                //push word_18A14+1
    _al = 0x01;                                 //mov al, 1
    _push(_ax);                                 //push ax
    sub_146BA();                                //call sub_146BA
    _di -= 1;                                   //dec di
    goto loc_13CFE;                             //jmp loc_13CFE
loc_13E04:                                      //loc_13E04:
    _ax = _si;                                  //mov ax, si
    _dl = _al;                                  //mov dl, al
    _ax = _di;                                  //mov ax, di
    _dh = _al;                                  //mov dh, al
    _ah = 0x02;                                 //mov ah, 2
    _bh = 0x00;                                 //mov bh, 0
    sub_13E83();                                //call sub_13E83
    _al = _stack16(_bp + var_3);                //mov al, [bp+var_3]
    _ah = 0x00;                                 //mov ah, 0
loc_13E18:                                      //loc_13E18:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(6);                            //retn 6
    return;
}

void sub_13E36()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_14B5E();                                //call sub_14B5E
    _cx = _pop();                               //pop cx
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_13CDF();                                //call sub_13CDF
    _bp = _pop();                               //pop bp
}

void sub_13E4C()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    const int arg_2 = 6;                        //arg_2  = dword ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
loc_13E4F:                                      //loc_13E4F:
    _bx = _stack16(_bp + arg_0);                //mov bx, [bp+arg_0]
    if (memory(_ds, _bx) == 0x00)               //jz short loc_13E6B
        goto loc_13E6B;
    _stack16(_bp + arg_0) += 1;                 //inc [bp+arg_0]
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _FIXME_;                                    //les bx, [bp+arg_2]
    memory16(_ds, _bp + arg_2) += 1;            //inc word ptr [bp+arg_2]
    if (_al == memory(_es, _bx))                //jz short loc_13E4F
        goto loc_13E4F;
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_13E6E;                             //jmp short loc_13E6E
loc_13E6B:                                      //loc_13E6B:
    _ax = 0x0001;                               //mov ax, 1
loc_13E6E:                                      //loc_13E6E:
    _bp = _pop();                               //pop bp
    _stackReduce(6);                            //retn 6
    return;
}

void sub_13E72()
{
    _ax = 0x1130;                               //mov ax, 1130h
    _bh = 0x00;                                 //mov bh, 0
    _dl = 0xff;                                 //mov dl, 0FFh
    sub_13E83();                                //call sub_13E83
    _al = _dl;                                  //mov al, dl
    _al += 1;                                   //inc al
    _ah = 0x00;                                 //mov ah, 0
}

void sub_13E83()
{
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    memory16(_ds, 0xA92) = _bp;                 //mov word_19132, bp
    _interrupt(16);                             //int 10h
    _bp = memory16(_ds, 0xA92);                 //mov bp, word_19132
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_13E92()
{
    _ah = 0x0f;                                 //mov ah, 0Fh
    sub_13E83();                                //call sub_13E83
    _push(_ax);                                 //push ax
    sub_13EAF();                                //call sub_13EAF
    _cx = _pop();                               //pop cx
    _ah = 0x08;                                 //mov ah, 8
    _bh = 0x00;                                 //mov bh, 0
    sub_13E83();                                //call sub_13E83
    _ah &= 0x7f;                                //and ah, 7Fh
    memory(_ds, 0x377) = _ah;                   //mov byte_18A17, ah
    memory(_ds, 0x376) = _ah;                   //mov byte_18A16, ah
}

void sub_13EAF()
{
    const int arg_0 = 4;                        //arg_0  = byte ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _al = _stack16(_bp + arg_0);                //mov al, [bp+arg_0]
    if (_al <= 0x03)                            //jbe short loc_13EBF
        goto loc_13EBF;
    if (_al == 0x07)                            //jz short loc_13EBF
        goto loc_13EBF;
    _al = 0x03;                                 //mov al, 3
loc_13EBF:                                      //loc_13EBF:
    memory(_ds, 0x378) = _al;                   //mov byte_18A18, al
    _ah = 0x0f;                                 //mov ah, 0Fh
    sub_13E83();                                //call sub_13E83
    _al = _al;                                  //mov al, al
    if (_al == memory(_ds, 0x378))              //jz short loc_13EDF
        goto loc_13EDF;
    _al = memory(_ds, 0x378);                   //mov al, byte_18A18
    _ah = 0x00;                                 //mov ah, 0
    sub_13E83();                                //call sub_13E83
    _ah = 0x0f;                                 //mov ah, 0Fh
    sub_13E83();                                //call sub_13E83
    memory(_ds, 0x378) = _al;                   //mov byte_18A18, al
loc_13EDF:                                      //loc_13EDF:
    memory(_ds, 0x37A) = _ah;                   //mov byte_18A1A, ah
    if (memory(_ds, 0x378) <= 0x03)             //jbe short loc_13EF6
        goto loc_13EF6;
    if (memory(_ds, 0x378) == 0x07)             //jz short loc_13EF6
        goto loc_13EF6;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_13EF8;                             //jmp short loc_13EF8
loc_13EF6:                                      //loc_13EF6:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_13EF8:                                      //loc_13EF8:
    memory(_ds, 0x37B) = _al;                   //mov byte_18A1B, al
    memory(_ds, 0x379) = 0x19;                  //mov byte_18A19, 19h
    if (memory(_ds, 0x378) == 0x07)             //jz short loc_13F26
        goto loc_13F26;
    _dx = 0xf000;                               //mov dx, 0F000h
    _ax = 0xffea;                               //mov ax, 0FFEAh
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = 0x0383;                               //mov ax, 383h
    _push(_ax);                                 //push ax
    sub_13E4C();                                //call sub_13E4C
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_13F26
        goto loc_13F26;
    sub_13E72();                                //call sub_13E72
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_13F26
        goto loc_13F26;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_13F28;                             //jmp short loc_13F28
loc_13F26:                                      //loc_13F26:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_13F28:                                      //loc_13F28:
    memory(_ds, 0x37C) = _al;                   //mov byte_18A1C, al
    if (memory(_ds, 0x378) != 0x07)             //jnz short loc_13F37
        goto loc_13F37;
    _ax = 0xb000;                               //mov ax, 0B000h
    goto loc_13F3A;                             //jmp short loc_13F3A
loc_13F37:                                      //loc_13F37:
    _ax = 0xb800;                               //mov ax, 0B800h
loc_13F3A:                                      //loc_13F3A:
    memory16(_ds, 0x37F) = _ax;                 //mov word_18A1F, ax
    memory16(_ds, 0x37D) = 0x0000;              //mov word_18A1D, 0
    _al = 0x00;                                 //mov al, 0
    memory(_ds, 0x373) = _al;                   //mov byte ptr word_18A12+1, al
    memory(_ds, 0x372) = _al;                   //mov byte ptr word_18A12, al
    _al = memory(_ds, 0x37A);                   //mov al, byte_18A1A
    _al += 0xff;                                //add al, 0FFh
    memory(_ds, 0x374) = _al;                   //mov byte ptr word_18A14, al
    memory(_ds, 0x375) = 0x18;                  //mov byte ptr word_18A14+1, 18h
    _bp = _pop();                               //pop bp
}

void sub_13F5B()
{
    _cx = 0x002c;                               //mov cx, 2Ch
    _dx = 0x038a;                               //mov dx, 38Ah
    goto loc_13F6D;                             //jmp short loc_13F6D
    _cx = 0x002b;                               //mov cx, 2Bh
    _dx = 0x03b6;                               //mov dx, 3B6h
    _STOP_("goto $+2");                         //jmp short $+2
loc_13F6D:                                      //loc_13F6D:
    _ah = 0x40;                                 //mov ah, 40h
    _bx = 0x0002;                               //mov bx, 2
    _interrupt(33);                             //int 21h
    {loc_1018D(); return; };                    //
}

void sub_13F7A()
{
    WORD _cs = _seg000;

    _sp -= 1;                                   //dec sp
    _sp -= 1;                                   //dec sp
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _cx = _stack16(_bp + 6);                    //mov cx, [bp+6]
    _ax = memory16(_cs, 0x3F78);                //mov ax, cs:word_13F78
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_13FB1
        goto loc_13FB1;
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    _bx = memory16(_es, 0x6C);                  //mov bx, es:6Ch
    sub_13FD5();                                //call sub_13FD5
    _bx = _bx - memory16(_es, 0x6C);            //sub bx, es:6Ch
    _bx = -_bx;                                 //neg bx
    _ax = 0x0037;                               //mov ax, 37h
    _mul(_bx);                                  //mul bx
    if (_cx <= _ax)                             //jbe short loc_13FC9
        goto loc_13FC9;
    _cx -= _ax;                                 //sub cx, ax
    _ax = memory16(_cs, 0x3F78);                //mov ax, cs:word_13F78
loc_13FB1:                                      //loc_13FB1:
    _bx = _bx ^ _bx;                            //xor bx, bx
    _es = _bx;                                  //mov es, bx
    _dl = memory(_es, _bx);                     //mov dl, es:[bx]
    if (_cx == 0)                               //jcxz short loc_13FC9
        goto loc_13FC9;
loc_13FBA:                                      //loc_13FBA:
    _si = _cx;                                  //mov si, cx
    _cx = _ax;                                  //mov cx, ax
loc_13FBE:                                      //loc_13FBE:
    if (_dl != memory(_es, _bx))                //jnz short $+2
        _STOP_("goto $+2");
loc_13FC3:                                      //loc_13FC3:
    if (--_cx)                                  //loop loc_13FBE
        goto loc_13FBE;
    _cx = _si;                                  //mov cx, si
    if (--_cx)                                  //loop loc_13FBA
        goto loc_13FBA;
loc_13FC9:                                      //loc_13FC9:
    _ax = memory16(_cs, 0x3F78);                //mov ax, cs:word_13F78
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _bp = _pop();                               //pop bp
    _sp += 1;                                   //inc sp
    _sp += 1;                                   //inc sp
}

void sub_13FD5()
{
    WORD _cs = _seg000;

    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_es);                                 //push es
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    _bx = 0x006c;                               //mov bx, 6Ch
    _al = memory(_es, _bx);                     //mov al, es:[bx]
    _cx = 0xffff;                               //mov cx, 0FFFFh
loc_13FE7:                                      //loc_13FE7:
    _dl = memory(_es, _bx);                     //mov dl, es:[bx]
    if (_al == _dl)                             //jz short loc_13FE7
        goto loc_13FE7;
loc_13FEE:                                      //loc_13FEE:
    if (_dl != memory(_es, _bx))                //jnz short loc_13FF5
        goto loc_13FF5;
    if (--_cx)                                  //loop loc_13FEE
        goto loc_13FEE;
loc_13FF5:                                      //loc_13FF5:
    _cx = -_cx;                                 //neg cx
    _cx -= 1;                                   //dec cx
    _ax = 0x0037;                               //mov ax, 37h
    _xchg(_ax, _cx);                            //xchg ax, cx
    _dx = _dx ^ _dx;                            //xor dx, dx
    _div(_cx);                                  //div cx
    memory16(_cs, 0x3F78) = _ax;                //mov cs:word_13F78, ax
loc_14004:                                      //loc_14004:
    _al = memory(_es, _bx);                     //mov al, es:[bx]
    _cx = 0xffff;                               //mov cx, 0FFFFh
loc_1400A:                                      //loc_1400A:
    _dl = memory(_es, _bx);                     //mov dl, es:[bx]
    if (_al == _dl)                             //jz short loc_1400A
        goto loc_1400A;
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _ax = 0x0037;                               //mov ax, 37h
    _push(_ax);                                 //push ax
    sub_13F7A();                                //call sub_13F7A
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    if (_dl == memory(_es, _bx))                //jz short loc_14029
        goto loc_14029;
    memory16(_cs, 0x3F78) -= 1;                 //dec cs:word_13F78
    goto loc_14004;                             //jmp short loc_14004
loc_14029:                                      //loc_14029:
    _es = _pop();                               //pop es
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_1402F()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
loc_14032:                                      //loc_14032:
    _ax = memory16(_ds, 0x370);                 //mov ax, word_18A10
    memory16(_ds, 0x370) -= 1;                  //dec word_18A10
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_14049
        goto loc_14049;
    _bx = memory16(_ds, 0x370);                 //mov bx, word_18A10
    _bx <<= 1;                                  //shl bx, 1
    _indirectCall(memory16(_ds, _bx + 2642));   //call word ptr [bx+0A52h]
    goto loc_14032;                             //jmp short loc_14032
loc_14049:                                      //loc_14049:
    off_18A82();                                //call off_18A82
    off_18A84();                                //call off_18A84
    off_18A86();                                //call off_18A86
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_10115();                                //call sub_10115
}

void sub_1405E()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    if (_stack16(_bp + arg_0) != 0x0000)        //jnz short loc_1406C
        goto loc_1406C;
    goto loc_14100;                             //jmp loc_14100
loc_1406C:                                      //loc_1406C:
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _di += 0xfffe;                              //add di, 0FFFEh
    _si = memory16(_ds, 0x47C);                 //mov si, word_18B1C
    goto loc_1408D;                             //jmp short loc_1408D
loc_14078:                                      //loc_14078:
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    if (_ax > _si)                              //ja short loc_1408A
        goto loc_1408A;
    if (_di > _si)                              //ja short loc_14098
        goto loc_14098;
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    if (_ax > _di)                              //ja short loc_14098
        goto loc_14098;
loc_1408A:                                      //loc_1408A:
    _si = memory16(_ds, _si + 2);               //mov si, [si+2]
loc_1408D:                                      //loc_1408D:
    if (_di <= _si)                             //jbe short loc_14078
        goto loc_14078;
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    if (_ax <= _di)                             //jbe short loc_14078
        goto loc_14078;
loc_14098:                                      //loc_14098:
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    _ax += _di;                                 //add ax, di
    if (_ax != memory16(_ds, _si + 2))          //jnz short loc_140B3
        goto loc_140B3;
    _bx = memory16(_ds, _si + 2);               //mov bx, [si+2]
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    memory16(_ds, _di) += _ax;                  //add [di], ax
    _bx = memory16(_ds, _si + 2);               //mov bx, [si+2]
    _ax = memory16(_ds, _bx + 2);               //mov ax, [bx+2]
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    goto loc_140B9;                             //jmp short loc_140B9
loc_140B3:                                      //loc_140B3:
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
loc_140B9:                                      //loc_140B9:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _ax += _si;                                 //add ax, si
    if (_ax != _di)                             //jnz short loc_140CF
        goto loc_140CF;
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    memory16(_ds, _si) += _ax;                  //add [si], ax
    _ax = memory16(_ds, _di + 2);               //mov ax, [di+2]
    memory16(_ds, _si + 2) = _ax;               //mov [si+2], ax
    _di = _si;                                  //mov di, si
    goto loc_140D2;                             //jmp short loc_140D2
loc_140CF:                                      //loc_140CF:
    memory16(_ds, _si + 2) = _di;               //mov [si+2], di
loc_140D2:                                      //loc_140D2:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    sub_13C6F();                                //call sub_13C6F
    _sp = _bp;                                  //mov sp, bp
    _dx = memory16(_ds, _di);                   //mov dx, [di]
    _dx += _di;                                 //add dx, di
    if (_ax != _dx)                             //jnz short loc_140FC
        goto loc_140FC;
    _si = _di;                                  //mov si, di
    goto loc_140EA;                             //jmp short loc_140EA
loc_140E7:                                      //loc_140E7:
    _si = memory16(_ds, _si + 2);               //mov si, [si+2]
loc_140EA:                                      //loc_140EA:
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    if (_ax != _di)                             //jnz short loc_140E7
        goto loc_140E7;
    _ax = memory16(_ds, _di + 2);               //mov ax, [di+2]
    memory16(_ds, _si + 2) = _ax;               //mov [si+2], ax
    _push(_di);                                 //push di
    sub_13CA1();                                //call sub_13CA1
    _cx = _pop();                               //pop cx
loc_140FC:                                      //loc_140FC:
    memory16(_ds, 0x47C) = _si;                 //mov word_18B1C, si
loc_14100:                                      //loc_14100:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_14104()
{
    _ax = 0x0700;                               //mov ax, 700h
    _xchg(_al, memory(_ds, 0x410));             //xchg al, byte_18AB0
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_14111
        goto loc_14111;
    _interrupt(33);                             //int 21h
loc_14111:                                      //loc_14111:
    _ah = _ah ^ _ah;                            //xor ah, ah
}

void loc_14132()
{
    _al = _stack16(_bp + 4);                    //mov al, [bp+4]
    memory(_ds, 0x410) = _al;                   //mov byte_18AB0, al
    _ah = _ah ^ _ah;                            //xor ah, ah
loc_1413A:                                      //loc_1413A:
    _bp = _pop();                               //pop bp
}

void sub_1413C()
{
    const int arg_0 = 4;                        //arg_0  = byte ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ah = 0x35;                                 //mov ah, 35h
    _al = _stack16(_bp + arg_0);                //mov al, [bp+arg_0]
    _interrupt(33);                             //int 21h
    _ax = _bx;                                  //mov ax, bx
    _dx = _es;                                  //mov dx, es
    _bp = _pop();                               //pop bp
}

void sub_1414C()
{
    const int arg_0 = 4;                        //arg_0  = byte ptr  4
    const int arg_2 = 6;                        //arg_2  = dword ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ah = 0x25;                                 //mov ah, 25h
    _al = _stack16(_bp + arg_0);                //mov al, [bp+arg_0]
    _push(_ds);                                 //push ds
    _FIXME_;                                    //lds dx, [bp+arg_2]
    _interrupt(33);                             //int 21h
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_1415D()
{
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_1402F();                                //call sub_1402F
}

void sub_14169()
{
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_1405E();                                //call sub_1405E
    _cx = _pop();                               //pop cx
    _bp = _pop();                               //pop bp
}

void sub_14175()
{
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_144B8();                                //call sub_144B8
    _cx = _pop();                               //pop cx
    _dx = _ds;                                  //mov dx, ds
    _bp = _pop();                               //pop bp
}

void sub_14183()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    const int arg_6 = 14;                       //arg_6  = word ptr  0Eh
    const int arg_8 = 16;                       //arg_8  = word ptr  10h
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    sub_14993();                                //call sub_14993
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_1419F
        goto loc_1419F;
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_141CF;                             //jmp short loc_141CF
loc_1419F:                                      //loc_1419F:
    _di = _stack16(_bp + arg_4);                //mov di, [bp+arg_4]
    _di = _di - _stack16(_bp + arg_0);          //sub di, [bp+arg_0]
    _di += 1;                                   //inc di
    _si = _stack16(_bp + arg_2);                //mov si, [bp+arg_2]
    goto loc_141C7;                             //jmp short loc_141C7
loc_141AB:                                      //loc_141AB:
    _ax = _stack16(_bp + arg_8);                //mov ax, [bp+arg_8]
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_si);                                 //push si
    sub_15045();                                //call sub_15045
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_di);                                 //push di
    sub_14958();                                //call sub_14958
    _ax = _di;                                  //mov ax, di
    _ax <<= 1;                                  //shl ax, 1
    _stack16(_bp + arg_8) += _ax;               //add [bp+arg_8], ax
    _si += 1;                                   //inc si
loc_141C7:                                      //loc_141C7:
    if ((short)_si <= (short)_stack16(_bp + arg_6))//jle short loc_141AB
        goto loc_141AB;
    _ax = 0x0001;                               //mov ax, 1
loc_141CF:                                      //loc_141CF:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_141D3()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    const int arg_6 = 14;                       //arg_6  = word ptr  0Eh
    const int arg_8 = 16;                       //arg_8  = word ptr  10h
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _di = _stack16(_bp + arg_4);                //mov di, [bp+arg_4]
    _di = _di - _stack16(_bp + arg_0);          //sub di, [bp+arg_0]
    _di += 1;                                   //inc di
    _si = _stack16(_bp + arg_2);                //mov si, [bp+arg_2]
    goto loc_14200;                             //jmp short loc_14200
loc_141E4:                                      //loc_141E4:
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_si);                                 //push si
    sub_15045();                                //call sub_15045
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = _stack16(_bp + arg_8);                //mov ax, [bp+arg_8]
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_di);                                 //push di
    sub_14958();                                //call sub_14958
    _ax = _di;                                  //mov ax, di
    _ax <<= 1;                                  //shl ax, 1
    _stack16(_bp + arg_8) += _ax;               //add [bp+arg_8], ax
    _si += 1;                                   //inc si
loc_14200:                                      //loc_14200:
    if ((short)_si <= (short)_stack16(_bp + arg_6))//jle short loc_141E4
        goto loc_141E4;
    _ax = 0x0001;                               //mov ax, 1
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_1420C()
{
    WORD _cs = _seg000;

    const int arg_0 = 4;                        //arg_0  = word ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _dx = _cs;                                  //mov dx, cs
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_1547D();                                //call near ptr sub_1547D
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
}

void sub_14230()
{
    const int var_8 = -8;                       //var_8  = byte ptr -8
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    const int arg_2 = 6;                        //arg_2  = word ptr  6
    const int arg_4 = 8;                        //arg_4  = word ptr  8
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0008;                              //sub sp, 8
    _FIXME_;                                    //lea ax, [bp+var_8]
    _push(_ax);                                 //push ax
    sub_149DB();                                //call sub_149DB
    _cx = _pop();                               //pop cx
    _FIXME_;                                    //lea ax, [bp+var_8]
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_14255();                                //call sub_14255
    _sp += 0x0008;                              //add sp, 8
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
}

void sub_14255()
{
    const int var_10 = -16;                     //var_10  = word ptr -10h
    const int var_E = -14;                      //var_E  = dword ptr -0Eh
    const int var_A = -10;                      //var_A  = byte ptr -0Ah
    const int var_9 = -9;                       //var_9  = byte ptr -9
    const int var_8 = -8;                       //var_8  = byte ptr -8
    const int var_7 = -7;                       //var_7  = word ptr -7
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    const int arg_6 = 14;                       //arg_6  = word ptr  0Eh
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x000e;                              //sub sp, 0Eh
    _push(_ds);                                 //push ds
    _FIXME_;                                    //lea cx, [bp+var_A]
    memory16(_ds, _bp + arg_14) = _cx;          //mov word ptr [bp+var_E], cx
    memory16(_ds, _bp + arg_16) = _ss;          //mov word ptr [bp+var_E+2], ss
    _stack16(_bp + var_A) = 0x0055;             //mov [bp+var_A], 55h
    _stack16(_bp + var_9) = 0x00cd;             //mov [bp+var_9], 0CDh
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _stack16(_bp + var_8) = _al;                //mov [bp+var_8], al
    _stack16(_bp + var_7) = 0xcb5d;             //mov [bp+var_7], 0CB5Dh
    if (_al < 0x25)                             //jb short loc_14293
        goto loc_14293;
    if (_al > 0x26)                             //ja short loc_14293
        goto loc_14293;
    _stack16(_bp + var_7) = 0x36;               //mov byte ptr [bp+var_7], 36h
    _stack16(_bp + var_E) = 0x068f;             //mov [bp+var_7+1], 68Fh
    _stack16(_bp + var_4) = _cx;                //mov [bp+var_4], cx
    _stack16(_bp + var_2) = 0xcb5d;             //mov [bp+var_2], 0CB5Dh
loc_14293:                                      //loc_14293:
    _si = _stack16(_bp + arg_6);                //mov si, [bp+arg_6]
    _push(memory16(_ds, _si));                  //push word ptr [si]
    _push(memory16(_ds, _si + 6));              //push word ptr [si+6]
    _si = _stack16(_bp + arg_2);                //mov si, [bp+arg_2]
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _bx = memory16(_ds, _si + 2);               //mov bx, [si+2]
    _cx = memory16(_ds, _si + 4);               //mov cx, [si+4]
    _dx = memory16(_ds, _si + 6);               //mov dx, [si+6]
    _di = memory16(_ds, _si + 10);              //mov di, [si+0Ah]
    _si = memory16(_ds, _si + 8);               //mov si, [si+8]
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
    switch (_bp + arg_14)                       //call [bp+var_E]
    {
      case 0: loc_11A6A(); break;
      case 2: loc_11A80(); break;
      case 4: loc_11A96(); break;
      case 6: loc_11ABB(); break;
      case 8: loc_11AF6(); break;
      default:
        _ASSERT(0);
    }
    _pushf();                                   //pushf
    _pushf();                                   //pushf
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ds = _stack16(_bp + var_10);               //mov ds, [bp+var_10]
    _si = _stack16(_bp + arg_6);                //mov si, [bp+arg_6]
    memory16(_ds, _si) = _pop();                //pop word ptr [si]
    memory16(_ds, _si + 6) = _pop();            //pop word ptr [si+6]
    _si = _stack16(_bp + arg_4);                //mov si, [bp+arg_4]
    memory16(_ds, _si + 8) = _pop();            //pop word ptr [si+8]
    memory16(_ds, _si + 14) = _pop();           //pop word ptr [si+0Eh]
    memory16(_ds, _si + 12) = _pop();           //pop word ptr [si+0Ch]
    memory16(_ds, _si + 12) &= 0x0001;          //and word ptr [si+0Ch], 1
    memory16(_ds, _si + 10) = _di;              //mov [si+0Ah], di
    memory16(_ds, _si + 6) = _dx;               //mov [si+6], dx
    memory16(_ds, _si + 4) = _cx;               //mov [si+4], cx
    memory16(_ds, _si + 2) = _bx;               //mov [si+2], bx
    memory16(_ds, _si) = _ax;                   //mov [si], ax
    _ds = _pop();                               //pop ds
    if (memory16(_ds, _si + 12) == 0)           //jz short loc_142EC
        goto loc_142EC;
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    sub_142F2();                                //call sub_142F2
    _ax = _pop();                               //pop ax
loc_142EC:                                      //loc_142EC:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_142F2()
{
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    _si |= _si;                                 //or si, si
    if ((short)_si < (short))                   //jl short loc_14311
        goto loc_14311;
    if (_si <= 0x0058)                          //jbe short loc_14305
        goto loc_14305;
loc_14302:                                      //loc_14302:
    _si = 0x0057;                               //mov si, 57h
loc_14305:                                      //loc_14305:
    memory16(_ds, 0x41C) = _si;                 //mov word_18ABC, si
    _al = memory(_ds, _si + 1054);              //mov al, [si+41Eh]
    _cbw();                                     //cbw
    _xchg(_ax, _si);                            //xchg ax, si
    goto loc_1431E;                             //jmp short loc_1431E
loc_14311:                                      //loc_14311:
    _si = -_si;                                 //neg si
    if (_si > 0x0022)                           //ja short loc_14302
        goto loc_14302;
    memory16(_ds, 0x41C) = 0xffff;              //mov word_18ABC, 0FFFFh
loc_1431E:                                      //loc_1431E:
    _ax = _si;                                  //mov ax, si
    memory16(_ds, 0x88) = _ax;                  //mov word_18728, ax
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
    _stackReduce(2);                            //retn 2
    return;
}

void sub_1432B()
{
    _ah = 0x0b;                                 //mov ah, 0Bh
    _interrupt(33);                             //int 21h
    _cbw();                                     //cbw
}

void sub_1433D()
{
    const int arg_0 = 10;                       //arg_0  = word ptr  0Ah
    const int arg_2 = 12;                       //arg_2  = word ptr  0Ch
    const int arg_4 = 14;                       //arg_4  = word ptr  0Eh
    const int arg_6 = 16;                       //arg_6  = word ptr  10h
    _cx = _cx ^ _cx;                            //xor cx, cx
loc_1433F:                                      //loc_1433F:
    _push(_bp);                                 //push bp
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _bp = _sp;                                  //mov bp, sp
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _dx = _stack16(_bp + arg_2);                //mov dx, [bp+arg_2]
    _bx = _stack16(_bp + arg_4);                //mov bx, [bp+arg_4]
    _bp = _stack16(_bp + arg_6);                //mov bp, [bp+arg_6]
    _si = _si ^ _si;                            //xor si, si
    if (_cl & 0x01)                             //jnz short loc_14376
        goto loc_14376;
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (!_flags.sign)                           //jns short loc_14364
        goto loc_14364;
    _dx = -_dx;                                 //neg dx
    _FIXME_;                                    //neg ax
    _ax = -_ax;
    _dx -= _si + _flags.carry;                  //sbb dx, si
    _cl |= 0x04;                                //or cl, 4
loc_14364:                                      //loc_14364:
    _flags.sign = !!(_bp & 0x8000);             //or bp, bp
    _bp |= _bp;
    if (!_flags.sign)                           //jns short loc_14376
        goto loc_14376;
    _bp = -_bp;                                 //neg bp
    _FIXME_;                                    //neg bx
    _bx = -_bx;
    _bp -= _si + _flags.carry;                  //sbb bp, si
    if (_cl & 0x02)                             //jnz short loc_14376
        goto loc_14376;
    _cl = _cl ^ 0x04;                           //xor cl, 4
loc_14376:                                      //loc_14376:
    _di = _bp;                                  //mov di, bp
    _di |= _dx;                                 //or di, dx
    if (_di != 0)                               //jnz short loc_14382
        goto loc_14382;
    _div(_bx);                                  //div bx
    _xchg(_si, _dx);                            //xchg si, dx
    goto loc_143A2;                             //jmp short loc_143A2
loc_14382:                                      //loc_14382:
    _push(_cx);                                 //push cx
    _cx = 0x0020;                               //mov cx, 20h
    _di = _si;                                  //mov di, si
loc_14388:                                      //loc_14388:
    _flags.carry = !!(_ax & 0x8000);            //shl ax, 1
    _ax <<= 1;
    _rcl(_dx, 1);                               //rcl dx, 1
    _ASSERT(0); /* unk previous */ _rcl(_si, 1);//rcl si, 1
    _ASSERT(0); /* unk previous */ _rcl(_di, 1);//rcl di, 1
    if (_di < _bp)                              //jb short loc_1439F
        goto loc_1439F;
    if (_di > _bp)                              //ja short loc_1439A
        goto loc_1439A;
    if (_si < _bx)                              //jb short loc_1439F
        goto loc_1439F;
loc_1439A:                                      //loc_1439A:
    _flags.carry = _si < _bx;                   //sub si, bx
    _si -= _bx;
    _di -= _bp + _flags.carry;                  //sbb di, bp
    _ax += 1;                                   //inc ax
loc_1439F:                                      //loc_1439F:
    if (--_cx)                                  //loop loc_14388
        goto loc_14388;
    _cx = _pop();                               //pop cx
loc_143A2:                                      //loc_143A2:
    if (!(_cl & 0x02))                          //jz short loc_143AA
        goto loc_143AA;
    _xchg(_ax, _si);                            //xchg ax, si
    _dx = _di;                                  //mov dx, di
loc_143AA:                                      //loc_143AA:
    if (!(_cl & 0x04))                          //jz short loc_143B6
        goto loc_143B6;
    _dx = -_dx;                                 //neg dx
    _FIXME_;                                    //neg ax
    _ax = -_ax;
    _dx -= 0x0000 + _flags.carry;               //sbb dx, 0
loc_143B6:                                      //loc_143B6:
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _bp = _pop();                               //pop bp
    _stackReduce(8);                            //retf 8
    return;
}

void sub_143BC()
{
    const int var_22 = -34;                     //var_22  = byte ptr -22h
    const int arg_0 = 8;                        //arg_0  = byte ptr  8
    const int arg_2 = 10;                       //arg_2  = byte ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    const int arg_6 = 14;                       //arg_6  = word ptr  0Eh
    const int arg_8 = 16;                       //arg_8  = word ptr  10h
    const int arg_A = 18;                       //arg_A  = word ptr  12h
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0022;                              //sub sp, 22h
    _push(_es);                                 //push es
    _di = _stack16(_bp + arg_6);                //mov di, [bp+arg_6]
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _bx = _stack16(_bp + arg_4);                //mov bx, [bp+arg_4]
    if (_bx > 0x0024)                           //ja short loc_1442A
        goto loc_1442A;
    if (_bl < 0x02)                             //jb short loc_1442A
        goto loc_1442A;
    _ax = _stack16(_bp + arg_8);                //mov ax, [bp+arg_8]
    _cx = _stack16(_bp + arg_A);                //mov cx, [bp+arg_A]
    _cx |= _cx;                                 //or cx, cx
    if ((short)_cx >= 0)                        //jge short loc_143F2
        goto loc_143F2;
    if (_stack16(_bp + arg_2) == 0x0000)        //jz short loc_143F2
        goto loc_143F2;
    memory(_ds, _di) = 0x2d;                    //mov byte ptr [di], 2Dh
    _di += 1;                                   //inc di
    _cx = -_cx;                                 //neg cx
    _FIXME_;                                    //neg ax
    _ax = -_ax;
    _cx -= 0x0000 + _flags.carry;               //sbb cx, 0
loc_143F2:                                      //loc_143F2:
    _FIXME_;                                    //lea si, [bp+var_22]
    if (_cx == 0)                               //jcxz short loc_14406
        goto loc_14406;
loc_143F7:                                      //loc_143F7:
    _xchg(_ax, _cx);                            //xchg ax, cx
    _dx = 0;                                    //sub dx, dx
    _div(_bx);                                  //div bx
    _xchg(_ax, _cx);                            //xchg ax, cx
    _div(_bx);                                  //div bx
    memory(_ds, _si) = _dl;                     //mov [si], dl
    _si += 1;                                   //inc si
    if (_cx == 0)                               //jcxz short loc_1440D
        goto loc_1440D;
    goto loc_143F7;                             //jmp short loc_143F7
loc_14406:                                      //loc_14406:
    _dx = 0;                                    //sub dx, dx
    _div(_bx);                                  //div bx
    memory(_ds, _si) = _dl;                     //mov [si], dl
    _si += 1;                                   //inc si
loc_1440D:                                      //loc_1440D:
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_14406
        goto loc_14406;
    _FIXME_;                                    //lea cx, [bp+var_22]
    _cx = -_cx;                                 //neg cx
    _cx += _si;                                 //add cx, si
    _flags.direction = false;                   //cld
loc_14419:                                      //loc_14419:
    _si -= 1;                                   //dec si
    _al = memory(_ds, _si);                     //mov al, [si]
    _flags.carry = _al < 0x0a;                  //sub al, 0Ah
    _al -= 0x0a;
    if (!_flags.carry)                          //jnb short loc_14424
        goto loc_14424;
    _al += 0x3a;                                //add al, 3Ah
    goto loc_14427;                             //jmp short loc_14427
loc_14424:                                      //loc_14424:
    _al = _al + _stack16(_bp + arg_0);          //add al, [bp+arg_0]
loc_14427:                                      //loc_14427:
    _stosb<MemAuto, DirAuto>();                 //stosb
    if (--_cx)                                  //loop loc_14419
        goto loc_14419;
loc_1442A:                                      //loc_1442A:
    _al = 0x00;                                 //mov al, 0
    _stosb<MemAuto, DirAuto>();                 //stosb
    _es = _pop();                               //pop es
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(12);                           //retn 0Ch
    return;
}

void sub_14439()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    const int arg_2 = 6;                        //arg_2  = word ptr  6
    const int arg_4 = 8;                        //arg_4  = word ptr  8
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    if (_stack16(_bp + arg_4) != 0x000a)        //jnz short loc_14448
        goto loc_14448;
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _cwd();                                     //cwd
    goto loc_1444D;                             //jmp short loc_1444D
loc_14448:                                      //loc_14448:
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_1444D:                                      //loc_1444D:
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _al = 0x01;                                 //mov al, 1
    _push(_ax);                                 //push ax
    _al = 0x61;                                 //mov al, 61h
    _push(_ax);                                 //push ax
    sub_143BC();                                //call sub_143BC
    _bp = _pop();                               //pop bp
}

void loc_14494()
{
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_14496:                                      //loc_14496:
    _push(_ax);                                 //push ax
    _al = 0x61;                                 //mov al, 61h
    _push(_ax);                                 //push ax
    sub_143BC();                                //call sub_143BC
    _bp = _pop();                               //pop bp
}

void sub_1449F()
{
    _push(_si);                                 //push si
    _xchg(_ax, _si);                            //xchg ax, si
    _xchg(_ax, _dx);                            //xchg ax, dx
    if (!(_ax & _ax))                           //jz short loc_144A8
        goto loc_144A8;
    _mul(_bx);                                  //mul bx
loc_144A8:                                      //loc_144A8:
    _xchg(_ax, _cx);                            //xchg ax, cx
    if (!(_ax & _ax))                           //jz short loc_144B1
        goto loc_144B1;
    _mul(_si);                                  //mul si
    _cx += _ax;                                 //add cx, ax
loc_144B1:                                      //loc_144B1:
    _xchg(_ax, _si);                            //xchg ax, si
    _mul(_bx);                                  //mul bx
    _dx += _cx;                                 //add dx, cx
    _si = _pop();                               //pop si
}

void sub_144B8()
{
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0004;                              //sub sp, 4
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _di |= _di;                                 //or di, di
    if (_di != 0)                               //jnz short loc_144CC
        goto loc_144CC;
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_1454E;                             //jmp loc_1454E
loc_144CC:                                      //loc_144CC:
    _ax = _di;                                  //mov ax, di
    _ax += 0x0005;                              //add ax, 5
    _ax &= 0xfffe;                              //and ax, 0FFFEh
    _di = _ax;                                  //mov di, ax
    _ax = memory16(_ds, 0x47C);                 //mov ax, word_18B1C
    _stack16(_bp + var_4) = _ax;                //mov [bp+var_4], ax
    _bx = _stack16(_bp + var_4);                //mov bx, [bp+var_4]
    _si = memory16(_ds, _bx + 2);               //mov si, [bx+2]
loc_144E2:                                      //loc_144E2:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    if (_ax < _di)                              //jb short loc_14515
        goto loc_14515;
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _dx = _di;                                  //mov dx, di
    _dx += 0x0004;                              //add dx, 4
    if (_ax > _dx)                              //ja short loc_144FE
        goto loc_144FE;
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _bx = _stack16(_bp + var_4);                //mov bx, [bp+var_4]
    memory16(_ds, _bx + 2) = _ax;               //mov [bx+2], ax
    goto loc_14508;                             //jmp short loc_14508
loc_144FE:                                      //loc_144FE:
    memory16(_ds, _si) -= _di;                  //sub [si], di
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _ax += _si;                                 //add ax, si
    _si = _ax;                                  //mov si, ax
    memory16(_ds, _si) = _di;                   //mov [si], di
loc_14508:                                      //loc_14508:
    _ax = _stack16(_bp + var_4);                //mov ax, [bp+var_4]
    memory16(_ds, 0x47C) = _ax;                 //mov word_18B1C, ax
    _ax = _si;                                  //mov ax, si
    _ax += 0x0002;                              //add ax, 2
    goto loc_1454E;                             //jmp short loc_1454E
loc_14515:                                      //loc_14515:
    if (_si != memory16(_ds, 0x47C))            //jnz short loc_1451D
        goto loc_1451D;
    goto loc_14525;                             //jmp short loc_14525
loc_1451D:                                      //loc_1451D:
    _stack16(_bp + var_4) = _si;                //mov [bp+var_4], si
    _si = memory16(_ds, _si + 2);               //mov si, [si+2]
    goto loc_144E2;                             //jmp short loc_144E2
loc_14525:                                      //loc_14525:
    _ax = _di;                                  //mov ax, di
    _dx = _dx ^ _dx;                            //xor dx, dx
    _ax &= 0xffff;                              //and ax, 0FFFFh
    _dx &= 0x0000;                              //and dx, 0
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    sub_13C6F();                                //call sub_13C6F
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    if (_stack16(_bp + var_2) != 0xffff)        //jnz short loc_14544
        goto loc_14544;
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_1454E;                             //jmp short loc_1454E
loc_14544:                                      //loc_14544:
    _si = _stack16(_bp + var_2);                //mov si, [bp+var_2]
    memory16(_ds, _si) = _di;                   //mov [si], di
    _ax = _si;                                  //mov ax, si
    _ax += 0x0002;                              //add ax, 2
loc_1454E:                                      //loc_1454E:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_14554()
{
    const int var_6 = -6;                       //var_6  = word ptr -6
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    const int arg_6 = 14;                       //arg_6  = word ptr  0Eh
    const int arg_8 = 16;                       //arg_8  = word ptr  10h
    const int arg_A = 18;                       //arg_A  = word ptr  12h
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0006;                              //sub sp, 6
    _si = _stack16(_bp + arg_2);                //mov si, [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_si);                                 //push si
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    sub_14993();                                //call sub_14993
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_14590
        goto loc_14590;
    _push(_stack16(_bp + arg_8));               //push [bp+arg_8]
    _push(_stack16(_bp + arg_A));               //push [bp+arg_A]
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    _ax = _ax - _stack16(_bp + arg_0);          //sub ax, [bp+arg_0]
    _ax = _ax + _stack16(_bp + arg_8);          //add ax, [bp+arg_8]
    _push(_ax);                                 //push ax
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    _ax -= _si;                                 //sub ax, si
    _ax = _ax + _stack16(_bp + arg_A);          //add ax, [bp+arg_A]
    _push(_ax);                                 //push ax
    sub_14993();                                //call sub_14993
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_14594
        goto loc_14594;
loc_14590:                                      //loc_14590:
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_145EE;                             //jmp short loc_145EE
loc_14594:                                      //loc_14594:
    _stack16(_bp + var_6) = _si;                //mov [bp+var_6], si
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    _stack16(_bp + var_4) = _ax;                //mov [bp+var_4], ax
    _stack16(_bp + var_2) = 0x0001;             //mov [bp+var_2], 1
    if ((short)_si >= (short)_stack16(_bp + arg_A))//jge short loc_145B5
        goto loc_145B5;
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    _stack16(_bp + var_6) = _ax;                //mov [bp+var_6], ax
    _stack16(_bp + var_4) = _si;                //mov [bp+var_4], si
    _stack16(_bp + var_2) = 0xffff;             //mov [bp+var_2], 0FFFFh
loc_145B5:                                      //loc_145B5:
    _di = _stack16(_bp + var_6);                //mov di, [bp+var_6]
    goto loc_145E1;                             //jmp short loc_145E1
loc_145BA:                                      //loc_145BA:
    _push(_stack16(_bp + arg_8));               //push [bp+arg_8]
    _ax = _di;                                  //mov ax, di
    _ax -= _si;                                 //sub ax, si
    _ax = _ax + _stack16(_bp + arg_A);          //add ax, [bp+arg_A]
    _push(_ax);                                 //push ax
    sub_15045();                                //call sub_15045
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_di);                                 //push di
    sub_15045();                                //call sub_15045
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    _ax = _ax - _stack16(_bp + arg_0);          //sub ax, [bp+arg_0]
    _ax += 1;                                   //inc ax
    _push(_ax);                                 //push ax
    sub_14958();                                //call sub_14958
    _di = _di + _stack16(_bp + var_2);          //add di, [bp+var_2]
loc_145E1:                                      //loc_145E1:
    _ax = _stack16(_bp + var_4);                //mov ax, [bp+var_4]
    _ax = _ax + _stack16(_bp + var_2);          //add ax, [bp+var_2]
    if (_ax != _di)                             //jnz short loc_145BA
        goto loc_145BA;
    _ax = 0x0001;                               //mov ax, 1
loc_145EE:                                      //loc_145EE:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_145F4()
{
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _al = 0x01;                                 //mov al, 1
    _cx = _stack16(_bp + arg_2);                //mov cx, [bp+arg_2]
    if (_cx & 0x0002)                           //jnz short loc_1460D
        goto loc_1460D;
    _al = 0x02;                                 //mov al, 2
    if (_cx & 0x0004)                           //jnz short loc_1460D
        goto loc_1460D;
    _al = 0x00;                                 //mov al, 0
loc_1460D:                                      //loc_1460D:
    _dx = _stack16(_bp + arg_0);                //mov dx, [bp+arg_0]
    _cl = 0xf0;                                 //mov cl, 0F0h
    _cl = _cl & _stack16(_bp + arg_2);          //and cl, byte ptr [bp+arg_2]
    _al |= _cl;                                 //or al, cl
    _ah = 0x3d;                                 //mov ah, 3Dh
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_14634
        goto loc_14634;
    _si = _ax;                                  //mov si, ax
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    _ax &= 0xf8ff;                              //and ax, 0F8FFh
    _ax |= 0x8000;                              //or ax, 8000h
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 1000) = _ax;            //mov [bx+3E8h], ax
    _ax = _si;                                  //mov ax, si
    goto loc_14638;                             //jmp short loc_14638
loc_14634:                                      //loc_14634:
    _push(_ax);                                 //push ax
    sub_142F2();                                //call sub_142F2
loc_14638:                                      //loc_14638:
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
}

void sub_1463B()
{
    const int arg_0 = 4;                        //arg_0  = byte ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _FIXME_;                                    //lea ax, [bp+arg_0]
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    sub_13CDF();                                //call sub_13CDF
    _bp = _pop();                               //pop bp
}

void sub_1464E()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    const int arg_2 = 6;                        //arg_2  = word ptr  6
    const int arg_4 = 8;                        //arg_4  = word ptr  8
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ah = 0x3f;                                 //mov ah, 3Fh
    _bx = _stack16(_bp + arg_0);                //mov bx, [bp+arg_0]
    _cx = _stack16(_bp + arg_4);                //mov cx, [bp+arg_4]
    _dx = _stack16(_bp + arg_2);                //mov dx, [bp+arg_2]
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_14662
        goto loc_14662;
    goto loc_14666;                             //jmp short loc_14666
loc_14662:                                      //loc_14662:
    _push(_ax);                                 //push ax
    sub_142F2();                                //call sub_142F2
loc_14666:                                      //loc_14666:
    _bp = _pop();                               //pop bp
}

void sub_14668()
{
    _STOP_("goto off_18FFE");                   //jmp off_18FFE
}

void sub_1466C()
{
    const int arg_0 = 6;                        //arg_0  = dword ptr  6
    const int arg_4 = 10;                       //arg_4  = dword ptr  0Ah
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_ds);                                 //push ds
    _FIXME_;                                    //lds si, [bp+arg_0]
    _FIXME_;                                    //les di, [bp+arg_4]
    _ax = _ds;                                  //mov ax, ds
    _dx = _es;                                  //mov dx, es
    if (_ax > _dx)                              //ja short loc_1468F
        goto loc_1468F;
    if (_si > _di)                              //ja short loc_1468F
        goto loc_1468F;
    _flags.direction = false;                   //cld
loc_14685:                                      //loc_14685:
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _flags.direction = false;                   //cld
    _ds = _pop();                               //pop ds
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _bp = _pop();                               //pop bp
    _stackReduce(8);                            //retf 8
    return;
loc_1468F:                                      //loc_1468F:
    _si += _cx;                                 //add si, cx
    _di += _cx;                                 //add di, cx
    _si -= 1;                                   //dec si
    _di -= 1;                                   //dec di
    _flags.direction = true;                    //std
    goto loc_14685;                             //jmp short loc_14685
}

void sub_14698()
{
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = word ptr  0Ah
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _si = _stack16(_bp + arg_4);                //mov si, [bp+arg_4]
    _cx = memory16(_ds, _si);                   //mov cx, [si]
    _cl = 0x20;                                 //mov cl, 20h
    goto loc_146AD;                             //jmp short loc_146AD
loc_146A5:                                      //loc_146A5:
    memory16(_ds, _si) = _cx;                   //mov [si], cx
    _si += 0x0002;                              //add si, 2
    _stack16(_bp + arg_2) += 1;                 //inc [bp+arg_2]
loc_146AD:                                      //loc_146AD:
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    if ((short)_ax <= (short)_stack16(_bp + arg_0))//jle short loc_146A5
        goto loc_146A5;
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
    _stackReduce(6);                            //retn 6
    return;
}

void sub_146BA()
{
    const int var_A0 = -160;                    //var_A0  = byte ptr -0A0h
    const int arg_0 = 4;                        //arg_0  = byte ptr  4
    const int arg_2 = 6;                        //arg_2  = byte ptr  6
    const int arg_4 = 8;                        //arg_4  = byte ptr  8
    const int arg_6 = 10;                       //arg_6  = byte ptr  0Ah
    const int arg_8 = 12;                       //arg_8  = byte ptr  0Ch
    const int arg_A = 14;                       //arg_A  = byte ptr  0Eh
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x00a0;                              //sub sp, 0A0h
    if (memory(_ds, 0x37B) == 0x00)             //jz short loc_146CB
        goto loc_146CB;
    goto loc_14803;                             //jmp loc_14803
loc_146CB:                                      //loc_146CB:
    if (memory16(_ds, 0x381) != 0x0000)         //jnz short loc_146D5
        goto loc_146D5;
    goto loc_14803;                             //jmp loc_14803
loc_146D5:                                      //loc_146D5:
    if (_stack16(_bp + arg_0) == 0x0001)        //jz short loc_146DE
        goto loc_146DE;
    goto loc_14803;                             //jmp loc_14803
loc_146DE:                                      //loc_146DE:
    _stack16(_bp + arg_8) += 1;                 //inc [bp+arg_8]
    _stack16(_bp + arg_6) += 1;                 //inc [bp+arg_6]
    _stack16(_bp + arg_4) += 1;                 //inc [bp+arg_4]
    _stack16(_bp + arg_2) += 1;                 //inc [bp+arg_2]
    if (_stack16(_bp + arg_A) == 0x0006)        //jz short loc_146F3
        goto loc_146F3;
    goto loc_1477B;                             //jmp loc_1477B
loc_146F3:                                      //loc_146F3:
    _al = _stack16(_bp + arg_6);                //mov al, [bp+arg_6]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_2);                //mov al, [bp+arg_2]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_4);                //mov al, [bp+arg_4]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_6);                //mov al, [bp+arg_6]
    _ah = 0x00;                                 //mov ah, 0
    _ax += 1;                                   //inc ax
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    sub_14554();                                //call sub_14554
    _sp += 0x000c;                              //add sp, 0Ch
    _FIXME_;                                    //lea ax, [bp+var_A0]
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_2);                //mov al, [bp+arg_2]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_2);                //mov al, [bp+arg_2]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    sub_14183();                                //call sub_14183
    _sp += 0x000a;                              //add sp, 0Ah
    _FIXME_;                                    //lea ax, [bp+var_A0]
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_4);                //mov al, [bp+arg_4]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    sub_14698();                                //call sub_14698
    _FIXME_;                                    //lea ax, [bp+var_A0]
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_2);                //mov al, [bp+arg_2]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_4);                //mov al, [bp+arg_4]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_2);                //mov al, [bp+arg_2]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    sub_141D3();                                //call sub_141D3
    _sp += 0x000a;                              //add sp, 0Ah
    goto loc_14801;                             //jmp loc_14801
loc_1477B:                                      //loc_1477B:
    _al = _stack16(_bp + arg_6);                //mov al, [bp+arg_6]
    _ah = 0x00;                                 //mov ah, 0
    _ax += 1;                                   //inc ax
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_2);                //mov al, [bp+arg_2]
    _ah = 0x00;                                 //mov ah, 0
    _ax -= 1;                                   //dec ax
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_4);                //mov al, [bp+arg_4]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_6);                //mov al, [bp+arg_6]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    sub_14554();                                //call sub_14554
    _sp += 0x000c;                              //add sp, 0Ch
    _FIXME_;                                    //lea ax, [bp+var_A0]
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_6);                //mov al, [bp+arg_6]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_6);                //mov al, [bp+arg_6]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    sub_14183();                                //call sub_14183
    _sp += 0x000a;                              //add sp, 0Ah
    _FIXME_;                                    //lea ax, [bp+var_A0]
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_4);                //mov al, [bp+arg_4]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    sub_14698();                                //call sub_14698
    _FIXME_;                                    //lea ax, [bp+var_A0]
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_6);                //mov al, [bp+arg_6]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_4);                //mov al, [bp+arg_4]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_6);                //mov al, [bp+arg_6]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _ah = 0x00;                                 //mov ah, 0
    _push(_ax);                                 //push ax
    sub_141D3();                                //call sub_141D3
    _sp += 0x000a;                              //add sp, 0Ah
loc_14801:                                      //loc_14801:
    goto loc_1481C;                             //jmp short loc_1481C
loc_14803:                                      //loc_14803:
    _bh = memory(_ds, 0x376);                   //mov bh, byte_18A16
    _ah = _stack16(_bp + arg_A);                //mov ah, [bp+arg_A]
    _al = _stack16(_bp + arg_0);                //mov al, [bp+arg_0]
    _ch = _stack16(_bp + arg_6);                //mov ch, [bp+arg_6]
    _cl = _stack16(_bp + arg_8);                //mov cl, [bp+arg_8]
    _dh = _stack16(_bp + arg_2);                //mov dh, [bp+arg_2]
    _dl = _stack16(_bp + arg_4);                //mov dl, [bp+arg_4]
    sub_13E83();                                //call sub_13E83
loc_1481C:                                      //loc_1481C:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _stackReduce(12);                           //retn 0Ch
    return;
}

void sub_14822()
{
    const int var_2 = -2;                       //var_2  = byte ptr -2
    const int var_1 = -1;                       //var_1  = byte ptr -1
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 1;                                   //dec sp
    _sp -= 1;                                   //dec sp
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    _si >>= 1;                                  //shr si, 1
    _ax = _si;                                  //mov ax, si
    _dl = memory(_ds, 0x37A);                   //mov dl, byte_18A1A
    _dh = 0x00;                                 //mov dh, 0
    _bx = _dx;                                  //mov bx, dx
    _dx = _dx ^ _dx;                            //xor dx, dx
    _div(_bx);                                  //div bx
    _stack16(_bp + var_2) = _al;                //mov [bp+var_2], al
    _al = _stack16(_bp + var_2);                //mov al, [bp+var_2]
    _ah = 0x00;                                 //mov ah, 0
    _dl = memory(_ds, 0x37A);                   //mov dl, byte_18A1A
    _dh = 0x00;                                 //mov dh, 0
    _mul(_dx);                                  //mul dx
    _dx = _si;                                  //mov dx, si
    _dl -= _al;                                 //sub dl, al
    _stack16(_bp + var_1) = _dl;                //mov [bp+var_1], dl
    _ah = _stack16(_bp + var_2);                //mov ah, [bp+var_2]
    _al = _stack16(_bp + var_1);                //mov al, [bp+var_1]
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
    _stackReduce(4);                            //retn 4
    return;
}

void sub_1485F()
{
    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _si = _stack16(_bp + arg_2);                //mov si, [bp+arg_2]
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _bx = _stack16(_bp + arg_0);                //mov bx, [bp+arg_0]
    if (_ax == memory16(_ds, _bx))              //jz short loc_14878
        goto loc_14878;
    _dx = memory16(_ds, _si);                   //mov dx, [si]
    _bh = 0x00;                                 //mov bh, 0
    _ah = 0x02;                                 //mov ah, 2
    sub_13E83();                                //call sub_13E83
loc_14878:                                      //loc_14878:
    _bx = _stack16(_bp + arg_0);                //mov bx, [bp+arg_0]
    memory16(_ds, _bx) = _dx;                   //mov [bx], dx
    _dl += 1;                                   //inc dl
    _al = _dl;                                  //mov al, dl
    if (_al < memory(_ds, 0x37A))               //jb short loc_1488B
        goto loc_1488B;
    _dh += 1;                                   //inc dh
    _dl = 0x00;                                 //mov dl, 0
loc_1488B:                                      //loc_1488B:
    memory16(_ds, _si) = _dx;                   //mov [si], dx
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
    _stackReduce(4);                            //retn 4
    return;
}

void sub_14892()
{
    const int var_A = -10;                      //var_A  = word ptr -0Ah
    const int var_8 = -8;                       //var_8  = word ptr -8
    const int var_6 = -6;                       //var_6  = word ptr -6
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = dword ptr  0Ah
    const int arg_6 = 14;                       //arg_6  = dword ptr  0Eh
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x000a;                              //sub sp, 0Ah
    sub_150E0();                                //call sub_150E0
    _di = _ax;                                  //mov di, ax
    _ax = _di;                                  //mov ax, di
    _stack16(_bp + var_6) = _ax;                //mov [bp+var_6], ax
    _ax = memory16(_ds, _bp + arg_8);           //mov ax, word ptr [bp+arg_6+2]
    if (_ax != memory16(_ds, 0x37F))            //jnz short loc_148B2
        goto loc_148B2;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_148B4;                             //jmp short loc_148B4
loc_148B2:                                      //loc_148B2:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_148B4:                                      //loc_148B4:
    _stack16(_bp + var_4) = _ax;                //mov [bp+var_4], ax
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_148C7
        goto loc_148C7;
    _push(memory16(_ds, _bp + arg_8));          //push word ptr [bp+arg_6+2]
    _push(memory16(_ds, _bp + arg_6));          //push word ptr [bp+arg_6]
    sub_14822();                                //call sub_14822
    _stack16(_bp + var_A) = _ax;                //mov [bp+var_A], ax
loc_148C7:                                      //loc_148C7:
    _ax = memory16(_ds, _bp + arg_4);           //mov ax, word ptr [bp+arg_2+2]
    if (_ax != memory16(_ds, 0x37F))            //jnz short loc_148D5
        goto loc_148D5;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_148D7;                             //jmp short loc_148D7
loc_148D5:                                      //loc_148D5:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_148D7:                                      //loc_148D7:
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_148EA
        goto loc_148EA;
    _push(memory16(_ds, _bp + arg_4));          //push word ptr [bp+arg_2+2]
    _push(memory16(_ds, _bp + arg_2));          //push word ptr [bp+arg_2]
    sub_14822();                                //call sub_14822
    _stack16(_bp + var_8) = _ax;                //mov [bp+var_8], ax
loc_148EA:                                      //loc_148EA:
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _stack16(_bp + arg_0) -= 1;                 //dec [bp+arg_0]
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_14947
        goto loc_14947;
    if (_stack16(_bp + var_2) == 0x0000)        //jz short loc_14910
        goto loc_14910;
    _FIXME_;                                    //lea ax, [bp+var_8]
    _push(_ax);                                 //push ax
    _FIXME_;                                    //lea ax, [bp+var_6]
    _push(_ax);                                 //push ax
    sub_1485F();                                //call sub_1485F
    _bh = 0x00;                                 //mov bh, 0
    _ah = 0x08;                                 //mov ah, 8
    sub_13E83();                                //call sub_13E83
    _si = _ax;                                  //mov si, ax
    goto loc_1491A;                             //jmp short loc_1491A
loc_14910:                                      //loc_14910:
    _FIXME_;                                    //les bx, [bp+arg_2]
    _si = memory16(_es, _bx);                   //mov si, es:[bx]
    memory16(_ds, _bp + arg_2) += 0x0002;       //add word ptr [bp+arg_2], 2
loc_1491A:                                      //loc_1491A:
    if (_stack16(_bp + var_4) == 0x0000)        //jz short loc_1493B
        goto loc_1493B;
    _FIXME_;                                    //lea ax, [bp+var_A]
    _push(_ax);                                 //push ax
    _FIXME_;                                    //lea ax, [bp+var_6]
    _push(_ax);                                 //push ax
    sub_1485F();                                //call sub_1485F
    _ax = _si;                                  //mov ax, si
    _bl = _ah;                                  //mov bl, ah
    _cx = 0x0001;                               //mov cx, 1
    _bh = 0x00;                                 //mov bh, 0
    _ah = 0x09;                                 //mov ah, 9
    sub_13E83();                                //call sub_13E83
    goto loc_14945;                             //jmp short loc_14945
loc_1493B:                                      //loc_1493B:
    _FIXME_;                                    //les bx, [bp+arg_6]
    memory16(_es, _bx) = _si;                   //mov es:[bx], si
    memory16(_ds, _bp + arg_6) += 0x0002;       //add word ptr [bp+arg_6], 2
loc_14945:                                      //loc_14945:
    goto loc_148EA;                             //jmp short loc_148EA
loc_14947:                                      //loc_14947:
    _dx = _di;                                  //mov dx, di
    _bh = 0x00;                                 //mov bh, 0
    _ah = 0x02;                                 //mov ah, 2
    sub_13E83();                                //call sub_13E83
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(10);                           //retn 0Ah
    return;
}

void sub_14958()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    const int arg_2 = 6;                        //arg_2  = word ptr  6
    const int arg_4 = 8;                        //arg_4  = word ptr  8
    const int arg_6 = 10;                       //arg_6  = word ptr  0Ah
    const int arg_8 = 12;                       //arg_8  = word ptr  0Ch
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    if (memory(_ds, 0x37B) != 0x00)             //jnz short loc_1497D
        goto loc_1497D;
    if (memory16(_ds, 0x381) == 0x0000)         //jz short loc_1497D
        goto loc_1497D;
    _push(_stack16(_bp + arg_8));               //push [bp+arg_8]
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_15068();                                //call sub_15068
    goto loc_1498F;                             //jmp short loc_1498F
loc_1497D:                                      //loc_1497D:
    _push(_stack16(_bp + arg_8));               //push [bp+arg_8]
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_14892();                                //call sub_14892
loc_1498F:                                      //loc_1498F:
    _bp = _pop();                               //pop bp
    _stackReduce(10);                           //retn 0Ah
    return;
}

void sub_14993()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    const int arg_2 = 6;                        //arg_2  = word ptr  6
    const int arg_4 = 8;                        //arg_4  = word ptr  8
    const int arg_6 = 10;                       //arg_6  = word ptr  0Ah
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _al = memory(_ds, 0x37A);                   //mov al, byte_18A1A
    _ah = 0x00;                                 //mov ah, 0
    _cx = _ax;                                  //mov cx, ax
    _al = memory(_ds, 0x379);                   //mov al, byte_18A19
    _ah = 0x00;                                 //mov ah, 0
    _dx = _ax;                                  //mov dx, ax
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    if (_ax > _cx)                              //ja short loc_149D5
        goto loc_149D5;
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    if (_ax > _cx)                              //ja short loc_149D5
        goto loc_149D5;
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    if ((short)_ax > (short)_stack16(_bp + arg_2))//jg short loc_149D5
        goto loc_149D5;
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    if (_ax > _dx)                              //ja short loc_149D5
        goto loc_149D5;
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    if (_ax > _dx)                              //ja short loc_149D5
        goto loc_149D5;
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    if ((short)_ax > (short)_stack16(_bp + arg_0))//jg short loc_149D5
        goto loc_149D5;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_149D7;                             //jmp short loc_149D7
loc_149D5:                                      //loc_149D5:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_149D7:                                      //loc_149D7:
    _bp = _pop();                               //pop bp
    _stackReduce(8);                            //retn 8
    return;
}

void sub_149DB()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    memory16(_ds, _si) = _es;                   //mov word ptr [si], es
    memory16(_ds, _si + 2) = _cs;               //mov word ptr [si+2], cs
    memory16(_ds, _si + 4) = _ss;               //mov word ptr [si+4], ss
    memory16(_ds, _si + 6) = _ds;               //mov word ptr [si+6], ds
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
}

void sub_149F6()
{
    WORD _cs = _seg000;

    memory16(_cs, 0x49F0) = _pop();             //pop cs:word_149F0
    memory16(_cs, 0x49F2) = _ds;                //mov cs:word_149F2, ds
    _flags.direction = false;                   //cld
    _es = memory16(_ds, 0x84);                  //mov es, word_18724
    _si = 0x0080;                               //mov si, 80h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _lods(memory(_es, _si));                    //lods byte ptr es:[si]
    _ax += 1;                                   //inc ax
    _bp = _es;                                  //mov bp, es
    _xchg(_dx, _si);                            //xchg dx, si
    _xchg(_ax, _bx);                            //xchg ax, bx
    _si = memory16(_ds, 0x7E);                  //mov si, word ptr dword_1871E
    _si += 0x0002;                              //add si, 2
    _cx = 0x0001;                               //mov cx, 1
    if (memory(_ds, 0x86) < 0x03)               //jb short loc_14A34
        goto loc_14A34;
    _es = memory16(_ds, 0x80);                  //mov es, word ptr dword_1871E+2
    _di = _si;                                  //mov di, si
    _cl = 0x7f;                                 //mov cl, 7Fh
    _al = _al ^ _al;                            //xor al, al
    _repne_scasb();                             //repne scasb
    if (_cx == 0)                               //jcxz short loc_14AA7
        { loc_14AA7(); return; }
    _cl = _cl ^ 0x7f;                           //xor cl, 7Fh
loc_14A34:                                      //loc_14A34:
    _sp -= 0x0002;                              //sub sp, 2
    _ax = 0x0001;                               //mov ax, 1
    _ax += _bx;                                 //add ax, bx
    _ax += _cx;                                 //add ax, cx
    _ax &= 0xfffe;                              //and ax, 0FFFEh
    _di = _sp;                                  //mov di, sp
    _flags.carry = _di < _ax;                   //sub di, ax
    _di -= _ax;
    if (_flags.carry)                           //jb short loc_14AA7
        { loc_14AA7(); return; }
    _sp = _di;                                  //mov sp, di
    _ax = _es;                                  //mov ax, es
    _ds = _ax;                                  //mov ds, ax
    _ax = _ss;                                  //mov ax, ss
    _es = _ax;                                  //mov es, ax
    _push(_cx);                                 //push cx
    _cx -= 1;                                   //dec cx
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _al = _al ^ _al;                            //xor al, al
    _stosb<MemAuto, DirAuto>();                 //stosb
    _ds = _bp;                                  //mov ds, bp
    _xchg(_si, _dx);                            //xchg si, dx
    _xchg(_bx, _cx);                            //xchg bx, cx
    _ax = _bx;                                  //mov ax, bx
    _dx = _ax;                                  //mov dx, ax
    _bx += 1;                                   //inc bx
loc_14A63:                                      //loc_14A63:
    sub_14A7F();                                //call sub_14A7F
    if (_FIXME_)                                //ja short loc_14A6F
        goto loc_14A6F;
loc_14A68:                                      //loc_14A68:
    if (_FIXME_)                                //jb short loc_14AAA
        _STOP_("goto loc_14AAA");
    sub_14A7F();                                //call sub_14A7F
    if (_FIXME_)                                //ja short loc_14A68
        goto loc_14A68;
loc_14A6F:                                      //loc_14A6F:
    if (_al == 0x20)                            //jz short loc_14A7B
        goto loc_14A7B;
    if (_al == 0x0d)                            //jz short loc_14A7B
        goto loc_14A7B;
    if (_al != 0x09)                            //jnz short loc_14A63
        goto loc_14A63;
loc_14A7B:                                      //loc_14A7B:
    _al = _al ^ _al;                            //xor al, al
    goto loc_14A63;                             //jmp short loc_14A63
    _STOP_("sp-trace-fail");                    //sub_149F6 endp_failed
    _STOP_("continues");                        //sub_14A7F proc near
}

void sub_14A7F()
{
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_14A8A
        goto loc_14A8A;
    _dx += 1;                                   //inc dx
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_14A8A
        goto loc_14A8A;
    _bx += 1;                                   //inc bx
loc_14A8A:                                      //loc_14A8A:
    _xchg(_ah, _al);                            //xchg ah, al
    _al = _al ^ _al;                            //xor al, al
    _flags.carry = true;                        //stc
    if (_cx == 0)                               //jcxz short locret_14AA6
        goto locret_14AA6;
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _cx -= 1;                                   //dec cx
    _al -= 0x22;                                //sub al, 22h
    if (_al == 0)                               //jz short locret_14AA6
        goto locret_14AA6;
    _al += 0x22;                                //add al, 22h
    if (_al != 0x5c)                            //jnz short loc_14AA4
        goto loc_14AA4;
    if (memory(_ds, _si) != 0x22)               //jnz short loc_14AA4
        goto loc_14AA4;
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _cx -= 1;                                   //dec cx
loc_14AA4:                                      //loc_14AA4:
    _si |= _si;                                 //or si, si
locret_14AA6:                                   //locret_14AA6:
    return;
}

void loc_14AA7()
{
loc_14AA7:
    WORD _cs = _seg000;

    {loc_1018D(); return; };                    //
loc_14AAA:                                      //loc_14AAA:
    _cx = _pop();                               //pop cx
    _cx += _dx;                                 //add cx, dx
    _ds = memory16(_cs, 0x49F2);                //mov ds, cs:word_149F2
    memory16(_ds, 0x78) = _bx;                  //mov word_18718, bx
    _bx += 1;                                   //inc bx
    _bx += _bx;                                 //add bx, bx
    _si = _sp;                                  //mov si, sp
    _bp = _sp;                                  //mov bp, sp
    _flags.carry = _bp < _bx;                   //sub bp, bx
    _bp -= _bx;
    if (_flags.carry)                           //jb short loc_14AA7
        goto loc_14AA7;
    _sp = _bp;                                  //mov sp, bp
    memory16(_ds, 0x7A) = _bp;                  //mov word_1871A, bp
loc_14AC7:                                      //loc_14AC7:
    if (_cx == 0)                               //jcxz short loc_14AD7
        goto loc_14AD7;
    _stack16(_bp + 0) = _si;                    //mov [bp+0], si
    _bp += 0x0002;                              //add bp, 2
loc_14ACF:                                      //loc_14ACF:
    _lods(memory(_ss, _si));                    //lods byte ptr ss:[si]
    _al |= _al;                                 //or al, al
    if (--_cx && _al != 0)                      //loopne loc_14ACF
        goto loc_14ACF;
    if (_al == 0)                               //jz short loc_14AC7
        goto loc_14AC7;
loc_14AD7:                                      //loc_14AD7:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _stack16(_bp + 0) = _ax;                    //mov [bp+0], ax
    _STOP_("goto cs:word_149F0");               //jmp cs:word_149F0
}

void sub_14AE1()
{
    _cx = memory16(_ds, 0x7E);                  //mov cx, word ptr dword_1871E
    _push(_cx);                                 //push cx
    sub_144B8();                                //call sub_144B8
    _cx = _pop();                               //pop cx
    _di = _ax;                                  //mov di, ax
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_14B14
        goto loc_14B14;
    _push(_ds);                                 //push ds
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _ds = memory16(_ds, 0x80);                  //mov ds, word ptr dword_1871E+2
    _si = _si ^ _si;                            //xor si, si
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ds = _pop();                               //pop ds
    _di = _ax;                                  //mov di, ax
    _push(_es);                                 //push es
    _push(memory16(_ds, 0x82));                 //push word_18722
    sub_144B8();                                //call sub_144B8
    _sp += 0x0002;                              //add sp, 2
    _bx = _ax;                                  //mov bx, ax
    _es = _pop();                               //pop es
    memory16(_ds, 0x7C) = _ax;                  //mov word_1871C, ax
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_14B17
        goto loc_14B17;
loc_14B14:                                      //loc_14B14:
    {loc_1018D(); return; };                    //
loc_14B17:                                      //loc_14B17:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _cx = 0xffff;                               //mov cx, 0FFFFh
loc_14B1C:                                      //loc_14B1C:
    memory16(_ds, _bx) = _di;                   //mov [bx], di
    _bx += 0x0002;                              //add bx, 2
    _repne_scasb();                             //repne scasb
    if (memory(_es, _di) != _al)                //jnz short loc_14B1C
        goto loc_14B1C;
    memory16(_ds, _bx) = _ax;                   //mov [bx], ax
}

void sub_14B2B()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _bx = _stack16(_bp + arg_0);                //mov bx, [bp+arg_0]
    _ax = 0x34dd;                               //mov ax, 34DDh
    _dx = 0x0012;                               //mov dx, 12h
    if (_dx >= _bx)                             //jnb short loc_14B55
        goto loc_14B55;
    _div(_bx);                                  //div bx
    _bx = _ax;                                  //mov bx, ax
    _in(_al, 97);                               //in al, 61h
    if (_al & 0x03)                             //jnz short loc_14B4D
        goto loc_14B4D;
    _al |= 0x03;                                //or al, 3
    _out(97, _al);                              //out 61h, al
    _al = 0xb6;                                 //mov al, 0B6h
    _out(67, _al);                              //out 43h, al
loc_14B4D:                                      //loc_14B4D:
    _al = _bl;                                  //mov al, bl
    _out(66, _al);                              //out 42h, al
    _al = _bh;                                  //mov al, bh
    _out(66, _al);                              //out 42h, al
loc_14B55:                                      //loc_14B55:
    _bp = _pop();                               //pop bp
}

void sub_14B57()
{
    _in(_al, 97);                               //in al, 61h
    _al &= 0xfc;                                //and al, 0FCh
    _out(97, _al);                              //out 61h, al
}

void sub_14B5E()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ax = _ds;                                  //mov ax, ds
    _es = _ax;                                  //mov es, ax
    _flags.direction = false;                   //cld
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _al = _al ^ _al;                            //xor al, al
    _cx = 0xffff;                               //mov cx, 0FFFFh
    _repne_scasb();                             //repne scasb
    _ax = _cx;                                  //mov ax, cx
    _ax = (~_ax);                               //not ax
    _ax -= 1;                                   //dec ax
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_14B7B()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _dx = _stack16(_bp + arg_0);                //mov dx, [bp+arg_0]
    _cx = 0x0f04;                               //mov cx, 0F04h
    _bx = 0x0487;                               //mov bx, 487h
    _flags.direction = false;                   //cld
    _al = _dh;                                  //mov al, dh
    _al >>= _cl;                                //shr al, cl
    _xlat();                                    //xlat
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al = _dh;                                  //mov al, dh
    _al &= _ch;                                 //and al, ch
    _xlat();                                    //xlat
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al = _dl;                                  //mov al, dl
    _al >>= _cl;                                //shr al, cl
    _xlat();                                    //xlat
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al = _dl;                                  //mov al, dl
    _al &= _ch;                                 //and al, ch
    _xlat();                                    //xlat
    _stosb<MemAuto, DirAuto>();                 //stosb
    _bp = _pop();                               //pop bp
    _stackReduce(2);                            //retn 2
    return;
}

void sub_14BA4()
{
    const int var_92 = -146;                    //var_92  = word ptr -92h
    const int var_90 = -144;                    //var_90  = byte ptr -90h
    const int var_8F = -143;                    //var_8F  = byte ptr -8Fh
    const int var_8E = -142;                    //var_8E  = word ptr -8Eh
    const int var_8C = -140;                    //var_8C  = word ptr -8Ch
    const int var_8A = -138;                    //var_8A  = byte ptr -8Ah
    const int var_89 = -137;                    //var_89  = byte ptr -89h
    const int var_88 = -136;                    //var_88  = word ptr -88h
    const int var_86 = -134;                    //var_86  = word ptr -86h
    const int var_84 = -132;                    //var_84  = byte ptr -84h
    const int var_83 = -131;                    //var_83  = byte ptr -83h
    const int var_54 = -84;                     //var_54  = word ptr -54h
    const int var_51 = -81;                     //var_51  = byte ptr -51h
    const int var_50 = -80;                     //var_50  = byte ptr -50h
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0092;                              //sub sp, 92h
    _stack16(_bp + var_54) = 0x0000;            //mov [bp+var_54], 0
    _stack16(_bp + var_51) = 0x0050;            //mov [bp+var_51], 50h
    _push(_es);                                 //push es
    _flags.direction = false;                   //cld
    _FIXME_;                                    //lea di, [bp+var_50]
    _stack16(_bp + var_92) = _di;               //mov [bp+var_92], di
loc_14BBF:                                      //loc_14BBF:
    _di = _stack16(_bp + var_92);               //mov di, [bp+var_92]
loc_14BC3:                                      //loc_14BC3:
    _si = _stack16(_bp + arg_2);                //mov si, [bp+arg_2]
loc_14BC6:                                      //loc_14BC6:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_14BDF
        goto loc_14BDF;
    if (_al == 0x25)                            //jz short loc_14BE2
        goto loc_14BE2;
loc_14BCF:                                      //loc_14BCF:
    memory(_ds, _di) = _al;                     //mov [di], al
    _di += 1;                                   //inc di
    _stack16(_bp + var_51) -= 1;                //dec [bp+var_51]
    if (_FIXME_)                                //jg short loc_14BC6
        goto loc_14BC6;
    _STOP_("call $+3");                         //call $+3
    goto loc_15015;                             //jmp loc_15015
    goto loc_14BC6;                             //jmp short loc_14BC6
loc_14BDF:                                      //loc_14BDF:
    goto loc_14FE2;                             //jmp loc_14FE2
loc_14BE2:                                      //loc_14BE2:
    _stack16(_bp + var_86) = _si;               //mov [bp+var_86], si
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    if (_al == 0x25)                            //jz short loc_14BCF
        goto loc_14BCF;
    _stack16(_bp + var_92) = _di;               //mov [bp+var_92], di
    _cx = 0;                                    //sub cx, cx
    _stack16(_bp + var_88) = _cx;               //mov [bp+var_88], cx
    _stack16(_bp + var_8A) = _cl;               //mov [bp+var_8A], cl
    _stack16(_bp + var_89) = _cl;               //mov [bp+var_89], cl
    _stack16(_bp + var_8E) = 0xffff;            //mov [bp+var_8E], 0FFFFh
    _stack16(_bp + var_8C) = 0xffff;            //mov [bp+var_8C], 0FFFFh
    goto loc_14C0C;                             //jmp short loc_14C0C
loc_14C0B:                                      //loc_14C0B:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
loc_14C0C:                                      //loc_14C0C:
    _cbw();                                     //cbw
    _dx = _ax;                                  //mov dx, ax
    _xchg(_ax, _bx);                            //xchg ax, bx
    _bl -= 0x20;                                //sub bl, 20h
    if (_bl >= 0x60)                            //jnb short loc_14C5D
        goto loc_14C5D;
    _bl = memory(_ds, _bx + 1175);              //mov bl, [bx+497h]
    _ax = _bx;                                  //mov ax, bx
    if (_ax <= 0x0016)                          //jbe short loc_14C26
        goto loc_14C26;
    goto loc_14FCD;                             //jmp loc_14FCD
loc_14C26:                                      //loc_14C26:
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    switch (_bx)                                //jmp cs:off_14C2F[bx]
    {
      case 0: goto loc_14C78;
      case 2: goto loc_14C60;
      case 4: goto loc_14CB6;
      case 6: goto loc_14C6C;
      case 8: goto loc_14CDA;
      case 10: goto loc_14CE3;
      case 12: goto loc_14D19;
      case 14: goto loc_14D22;
      case 16: goto loc_14C9E;
      case 18: goto loc_14D50;
      case 20: goto loc_14D2B;
      case 22: goto loc_14D2F;
      case 24: goto loc_14D33;
      case 26: goto loc_14DA1;
      case 28: goto loc_14E54;
      case 30: goto loc_14DF3;
      case 32: goto loc_14E13;
      case 34: goto loc_14FA1;
      case 36: goto loc_14FCD;
      case 38: goto loc_14FCD;
      case 40: goto loc_14FCD;
      case 42: goto loc_14C8A;
      case 44: goto loc_14C94;
      default:
        _ASSERT(0);
    }
loc_14C5D:                                      //loc_14C5D:
    goto loc_14FCD;                             //jmp loc_14FCD
loc_14C60:                                      //loc_14C60:
    if (_ch > 0x00)                             //ja short loc_14C5D
        goto loc_14C5D;
    _stack16(_bp + var_8A) |= 0x0001;           //or [bp+var_8A], 1
    goto loc_14C0B;                             //jmp short loc_14C0B
loc_14C6C:                                      //loc_14C6C:
    if (_ch > 0x00)                             //ja short loc_14C5D
        goto loc_14C5D;
    _stack16(_bp + var_8A) |= 0x0002;           //or [bp+var_8A], 2
    goto loc_14C0B;                             //jmp short loc_14C0B
loc_14C78:                                      //loc_14C78:
    if (_ch > 0x00)                             //ja short loc_14C5D
        goto loc_14C5D;
    if (_stack16(_bp + var_89) == 0x002b)       //jz short loc_14C0B
        goto loc_14C0B;
    _stack16(_bp + var_89) = _dl;               //mov [bp+var_89], dl
    goto loc_14C0B;                             //jmp short loc_14C0B
loc_14C8A:                                      //loc_14C8A:
    _stack16(_bp + var_8A) &= 0x00df;           //and [bp+var_8A], 0DFh
    _ch = 0x05;                                 //mov ch, 5
    goto loc_14C0B;                             //jmp loc_14C0B
loc_14C94:                                      //loc_14C94:
    _stack16(_bp + var_8A) |= 0x0020;           //or [bp+var_8A], 20h
    _ch = 0x05;                                 //mov ch, 5
    goto loc_14C0B;                             //jmp loc_14C0B
loc_14C9E:                                      //loc_14C9E:
    if (_ch > 0x00)                             //ja short loc_14CE3
        goto loc_14CE3;
    if (_stack16(_bp + var_8A) & 0x0002)        //jnz short loc_14CCA
        goto loc_14CCA;
    _stack16(_bp + var_8A) |= 0x0008;           //or [bp+var_8A], 8
    _ch = 0x01;                                 //mov ch, 1
    goto loc_14CCA;                             //jmp short loc_14CCA
loc_14CB3:                                      //loc_14CB3:
    goto loc_14FCD;                             //jmp loc_14FCD
loc_14CB6:                                      //loc_14CB6:
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    _stack16(_bp + arg_0) += 0x0002;            //add [bp+arg_0], 2
    if (_ch >= 0x02)                            //jnb short loc_14CCD
        goto loc_14CCD;
    _stack16(_bp + var_8E) = _ax;               //mov [bp+var_8E], ax
    _ch = 0x03;                                 //mov ch, 3
loc_14CCA:                                      //loc_14CCA:
    goto loc_14C0B;                             //jmp loc_14C0B
loc_14CCD:                                      //loc_14CCD:
    if (_ch != 0x04)                            //jnz short loc_14CB3
        goto loc_14CB3;
    _stack16(_bp + var_8C) = _ax;               //mov [bp+var_8C], ax
    _ch += 1;                                   //inc ch
    goto loc_14CCA;                             //jmp short loc_14CCA
loc_14CDA:                                      //loc_14CDA:
    if (_ch >= 0x04)                            //jnb short loc_14CB3
        goto loc_14CB3;
    _ch = 0x04;                                 //mov ch, 4
    goto loc_14CCA;                             //jmp short loc_14CCA
loc_14CE3:                                      //loc_14CE3:
    _xchg(_ax, _dx);                            //xchg ax, dx
    _al -= 0x30;                                //sub al, 30h
    _cbw();                                     //cbw
    if (_ch > 0x02)                             //ja short loc_14D01
        goto loc_14D01;
    _ch = 0x02;                                 //mov ch, 2
    _xchg(_ax, _stack16(_bp + var_8E));         //xchg ax, [bp+var_8E]
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax < (short))                   //jl short loc_14CCA
        goto loc_14CCA;
    _dx = 0x000a;                               //mov dx, 0Ah
    _mul(_dx);                                  //mul dx
    _stack16(_bp + var_8E) += _ax;              //add [bp+var_8E], ax
    goto loc_14CCA;                             //jmp short loc_14CCA
loc_14D01:                                      //loc_14D01:
    if (_ch != 0x04)                            //jnz short loc_14CB3
        goto loc_14CB3;
    _xchg(_ax, _stack16(_bp + var_8C));         //xchg ax, [bp+var_8C]
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax < (short))                   //jl short loc_14CCA
        goto loc_14CCA;
    _dx = 0x000a;                               //mov dx, 0Ah
    _mul(_dx);                                  //mul dx
    _stack16(_bp + var_8C) += _ax;              //add [bp+var_8C], ax
    goto loc_14CCA;                             //jmp short loc_14CCA
loc_14D19:                                      //loc_14D19:
    _stack16(_bp + var_8A) |= 0x0010;           //or [bp+var_8A], 10h
    _ch = 0x05;                                 //mov ch, 5
    goto loc_14CCA;                             //jmp short loc_14CCA
loc_14D22:                                      //loc_14D22:
    _stack16(_bp + var_8A) &= 0x00ef;           //and [bp+var_8A], 0EFh
    _ch = 0x05;                                 //mov ch, 5
    goto loc_14CCA;                             //jmp short loc_14CCA
loc_14D2B:                                      //loc_14D2B:
    _bh = 0x08;                                 //mov bh, 8
    goto loc_14D39;                             //jmp short loc_14D39
loc_14D2F:                                      //loc_14D2F:
    _bh = 0x0a;                                 //mov bh, 0Ah
    goto loc_14D3E;                             //jmp short loc_14D3E
loc_14D33:                                      //loc_14D33:
    _bh = 0x10;                                 //mov bh, 10h
    _bl = 0xe9;                                 //mov bl, 0E9h
    _bl += _dl;                                 //add bl, dl
loc_14D39:                                      //loc_14D39:
    _stack16(_bp + var_89) = 0x0000;            //mov [bp+var_89], 0
loc_14D3E:                                      //loc_14D3E:
    _stack16(_bp + var_8F) = 0x0000;            //mov [bp+var_8F], 0
    _stack16(_bp + var_90) = _dl;               //mov [bp+var_90], dl
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    _dx = 0;                                    //sub dx, dx
    goto loc_14D61;                             //jmp short loc_14D61
loc_14D50:                                      //loc_14D50:
    _bh = 0x0a;                                 //mov bh, 0Ah
    _stack16(_bp + var_8F) = 0x0001;            //mov [bp+var_8F], 1
    _stack16(_bp + var_90) = _dl;               //mov [bp+var_90], dl
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    _cwd();                                     //cwd
loc_14D61:                                      //loc_14D61:
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _stack16(_bp + arg_2) = _si;                //mov [bp+arg_2], si
    if (!(_stack16(_bp + var_8A) & 0x0010))     //jz short loc_14D71
        goto loc_14D71;
    _dx = memory16(_ds, _di);                   //mov dx, [di]
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
loc_14D71:                                      //loc_14D71:
    _stack16(_bp + arg_0) = _di;                //mov [bp+arg_0], di
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax |= _dx;                                 //or ax, dx
    if (_ax == 0)                               //jz short loc_14D7F
        goto loc_14D7F;
    _stack16(_bp + var_8A) |= 0x0004;           //or [bp+var_8A], 4
loc_14D7F:                                      //loc_14D7F:
    _FIXME_;                                    //lea di, [bp+var_83]
    _push(_di);                                 //push di
    _al = _bh;                                  //mov al, bh
    _cbw();                                     //cbw
    _push(_ax);                                 //push ax
    _al = _stack16(_bp + var_8F);               //mov al, [bp+var_8F]
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    sub_143BC();                                //call sub_143BC
    _push(_ss);                                 //push ss
    _es = _pop();                               //pop es
    _dx = _stack16(_bp + var_8C);               //mov dx, [bp+var_8C]
    _dx |= _dx;                                 //or dx, dx
    if ((short)_dx > 0)                         //jg short loc_14D9E
        goto loc_14D9E;
    goto loc_14E86;                             //jmp loc_14E86
loc_14D9E:                                      //loc_14D9E:
    goto loc_14E95;                             //jmp loc_14E95
loc_14DA1:                                      //loc_14DA1:
    _stack16(_bp + var_90) = _dl;               //mov [bp+var_90], dl
    _stack16(_bp + arg_2) = _si;                //mov [bp+arg_2], si
    _FIXME_;                                    //lea di, [bp+var_84]
    _bx = _stack16(_bp + arg_0);                //mov bx, [bp+arg_0]
    _push(memory16(_ds, _bx));                  //push word ptr [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _stack16(_bp + arg_0) = _bx;                //mov [bp+arg_0], bx
    if (!(_stack16(_bp + var_8A) & 0x0020))     //jz short loc_14DCC
        goto loc_14DCC;
    _push(memory16(_ds, _bx));                  //push word ptr [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _stack16(_bp + arg_0) = _bx;                //mov [bp+arg_0], bx
    _push(_ss);                                 //push ss
    _es = _pop();                               //pop es
    sub_14B7B();                                //call sub_14B7B
    _al = 0x3a;                                 //mov al, 3Ah
    _stosb<MemAuto, DirAuto>();                 //stosb
loc_14DCC:                                      //loc_14DCC:
    _push(_ss);                                 //push ss
    _es = _pop();                               //pop es
    sub_14B7B();                                //call sub_14B7B
    memory(_ds, _di) = 0x00;                    //mov byte ptr [di], 0
    _stack16(_bp + var_8F) = 0x0000;            //mov [bp+var_8F], 0
    _stack16(_bp + var_8A) &= 0x00fb;           //and [bp+var_8A], 0FBh
    _FIXME_;                                    //lea cx, [bp+var_84]
    _di -= _cx;                                 //sub di, cx
    _xchg(_cx, _di);                            //xchg cx, di
    _dx = _stack16(_bp + var_8C);               //mov dx, [bp+var_8C]
    if ((short)_dx > (short)_cx)                //jg short loc_14DF0
        goto loc_14DF0;
    _dx = _cx;                                  //mov dx, cx
loc_14DF0:                                      //loc_14DF0:
    goto loc_14E86;                             //jmp loc_14E86
loc_14DF3:                                      //loc_14DF3:
    _stack16(_bp + arg_2) = _si;                //mov [bp+arg_2], si
    _stack16(_bp + var_90) = _dl;               //mov [bp+var_90], dl
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    _stack16(_bp + arg_0) += 0x0002;            //add [bp+arg_0], 2
    _push(_ss);                                 //push ss
    _es = _pop();                               //pop es
    _FIXME_;                                    //lea di, [bp+var_83]
    _ah = 0x00;                                 //mov ah, 0
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _cx = 0x0001;                               //mov cx, 1
    goto loc_14EC5;                             //jmp loc_14EC5
loc_14E13:                                      //loc_14E13:
    _stack16(_bp + arg_2) = _si;                //mov [bp+arg_2], si
    _stack16(_bp + var_90) = _dl;               //mov [bp+var_90], dl
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    if (_stack16(_bp + var_8A) & 0x0020)        //jnz short loc_14E30
        goto loc_14E30;
    _di = memory16(_ds, _di);                   //mov di, [di]
    _stack16(_bp + arg_0) += 0x0002;            //add [bp+arg_0], 2
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _di |= _di;                                 //or di, di
    goto loc_14E3A;                             //jmp short loc_14E3A
loc_14E30:                                      //loc_14E30:
    _les(_di, _ds, _di);                        //les di, [di]
    _stack16(_bp + arg_0) += 0x0004;            //add [bp+arg_0], 4
    _ax = _es;                                  //mov ax, es
    _ax |= _di;                                 //or ax, di
loc_14E3A:                                      //loc_14E3A:
    if (_ax != 0)                               //jnz short loc_14E41
        goto loc_14E41;
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _di = 0x0480;                               //mov di, 480h
loc_14E41:                                      //loc_14E41:
    _STOP_("call $+3");                         //call $+3
    goto loc_14FF5;                             //jmp loc_14FF5
    if (_cx <= _stack16(_bp + var_8C))          //jbe short loc_14E51
        goto loc_14E51;
    _cx = _stack16(_bp + var_8C);               //mov cx, [bp+var_8C]
loc_14E51:                                      //loc_14E51:
    goto loc_14EC5;                             //jmp short loc_14EC5
loc_14E54:                                      //loc_14E54:
    _stack16(_bp + arg_2) = _si;                //mov [bp+arg_2], si
    _stack16(_bp + var_90) = _dl;               //mov [bp+var_90], dl
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _cx = _stack16(_bp + var_8C);               //mov cx, [bp+var_8C]
    _cx |= _cx;                                 //or cx, cx
    if ((short)_cx >= 0)                        //jge short loc_14E69
        goto loc_14E69;
    _cx = 0x0006;                               //mov cx, 6
loc_14E69:                                      //loc_14E69:
    _push(_di);                                 //push di
    _push(_cx);                                 //push cx
    _FIXME_;                                    //lea bx, [bp+var_83]
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _ax = 0x0001;                               //mov ax, 1
    _al = _al & _stack16(_bp + var_8A);         //and al, [bp+var_8A]
    _push(_ax);                                 //push ax
    sub_14668();                                //call sub_14668
    _stack16(_bp + arg_0) += 0x0008;            //add [bp+arg_0], 8
    _push(_ss);                                 //push ss
    _es = _pop();                               //pop es
    _FIXME_;                                    //lea di, [bp+var_83]
loc_14E86:                                      //loc_14E86:
    if (!(_stack16(_bp + var_8A) & 0x0008))     //jz short loc_14EA3
        goto loc_14EA3;
    _dx = _stack16(_bp + var_8E);               //mov dx, [bp+var_8E]
    _dx |= _dx;                                 //or dx, dx
    if ((short)_dx <= (short))                  //jle short loc_14EA3
        goto loc_14EA3;
loc_14E95:                                      //loc_14E95:
    _STOP_("call $+3");                         //call $+3
    goto loc_14FF5;                             //jmp loc_14FF5
    _dx -= _cx;                                 //sub dx, cx
    if (_FIXME_)                                //jle short loc_14EA3
        goto loc_14EA3;
    _stack16(_bp + var_88) = _dx;               //mov [bp+var_88], dx
loc_14EA3:                                      //loc_14EA3:
    _al = _stack16(_bp + var_89);               //mov al, [bp+var_89]
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_14EBF
        goto loc_14EBF;
    if (memory(_es, _di) == 0x2d)               //jz short loc_14EBF
        goto loc_14EBF;
    _di -= 1;                                   //dec di
    _flags.carry = _stack16(_bp + var_88) < 0x0001;//sub [bp+var_88], 1
    _stack16(_bp + var_88) -= 0x0001;
    _stack16(_bp + var_88) = _stack16(_bp + var_88) + 0x0000 + _flags.carry;
    memory(_es, _di) = _al;                     //mov es:[di], al
loc_14EBF:                                      //loc_14EBF:
    _STOP_("call $+3");                         //call $+3
    goto loc_14FF5;                             //jmp loc_14FF5
loc_14EC5:                                      //loc_14EC5:
    _si = _di;                                  //mov si, di
    _di = _stack16(_bp + var_92);               //mov di, [bp+var_92]
    _bx = _stack16(_bp + var_8E);               //mov bx, [bp+var_8E]
    _al = 0x05;                                 //mov al, 5
    _al = _al & _stack16(_bp + var_8A);         //and al, [bp+var_8A]
    if (_al != 0x05)                            //jnz short loc_14F10
        goto loc_14F10;
    _ah = _stack16(_bp + var_90);               //mov ah, [bp+var_90]
    if (_ah != 0x6f)                            //jnz short loc_14EF1
        goto loc_14EF1;
    if ((short)_stack16(_bp + var_88) > (short)0x0000)
        goto loc_14F10;
    _stack16(_bp + var_88) = 0x0001;            //mov [bp+var_88], 1
    goto loc_14F10;                             //jmp short loc_14F10
loc_14EF1:                                      //loc_14EF1:
    if (_ah == 0x78)                            //jz short loc_14EFB
        goto loc_14EFB;
    if (_ah != 0x58)                            //jnz short loc_14F10
        goto loc_14F10;
loc_14EFB:                                      //loc_14EFB:
    _stack16(_bp + var_8A) |= 0x0040;           //or [bp+var_8A], 40h
    _bx -= 0x0002;                              //sub bx, 2
    _stack16(_bp + var_88) -= 0x0002;           //sub [bp+var_88], 2
    if (_FIXME_)                                //jge short loc_14F10
        goto loc_14F10;
    _stack16(_bp + var_88) = 0x0000;            //mov [bp+var_88], 0
loc_14F10:                                      //loc_14F10:
    _cx = _cx + _stack16(_bp + var_88);         //add cx, [bp+var_88]
    if (_stack16(_bp + var_8A) & 0x0002)        //jnz short loc_14F2A
        goto loc_14F2A;
    goto loc_14F26;                             //jmp short loc_14F26
loc_14F1D:                                      //loc_14F1D:
    _al = 0x20;                                 //mov al, 20h
    _STOP_("call $+3");                         //call $+3
    goto loc_15007;                             //jmp loc_15007
    _bx -= 1;                                   //dec bx
loc_14F26:                                      //loc_14F26:
    if ((short)_bx > (short)_cx)                //jg short loc_14F1D
        goto loc_14F1D;
loc_14F2A:                                      //loc_14F2A:
    if (!(_stack16(_bp + var_8A) & 0x0040))     //jz short loc_14F43
        goto loc_14F43;
    _al = 0x30;                                 //mov al, 30h
    _STOP_("call $+3");                         //call $+3
    goto loc_15007;                             //jmp loc_15007
    _al = _stack16(_bp + var_90);               //mov al, [bp+var_90]
    _STOP_("call $+3");                         //call $+3
    goto loc_15007;                             //jmp loc_15007
loc_14F43:                                      //loc_14F43:
    _dx = _stack16(_bp + var_88);               //mov dx, [bp+var_88]
    _dx |= _dx;                                 //or dx, dx
    if ((short)_dx <= (short))                  //jle short loc_14F78
        goto loc_14F78;
    _cx -= _dx;                                 //sub cx, dx
    _bx -= _dx;                                 //sub bx, dx
    _al = memory(_es, _si);                     //mov al, es:[si]
    if (_al == 0x2d)                            //jz short loc_14F5E
        goto loc_14F5E;
    if (_al == 0x20)                            //jz short loc_14F5E
        goto loc_14F5E;
    if (_al != 0x2b)                            //jnz short loc_14F68
        goto loc_14F68;
loc_14F5E:                                      //loc_14F5E:
    _lods(memory(_es, _si));                    //lods byte ptr es:[si]
    _STOP_("call $+3");                         //call $+3
    goto loc_15007;                             //jmp loc_15007
    _cx -= 1;                                   //dec cx
    _bx -= 1;                                   //dec bx
loc_14F68:                                      //loc_14F68:
    _xchg(_cx, _dx);                            //xchg cx, dx
    if (_cx == 0)                               //jcxz short loc_14F76
        goto loc_14F76;
loc_14F6C:                                      //loc_14F6C:
    _al = 0x30;                                 //mov al, 30h
    _STOP_("call $+3");                         //call $+3
    goto loc_15007;                             //jmp loc_15007
    if (--_cx)                                  //loop loc_14F6C
        goto loc_14F6C;
loc_14F76:                                      //loc_14F76:
    _xchg(_cx, _dx);                            //xchg cx, dx
loc_14F78:                                      //loc_14F78:
    _bx -= _cx;                                 //sub bx, cx
    if (_cx == 0)                               //jcxz short loc_14F8E
        goto loc_14F8E;
loc_14F7C:                                      //loc_14F7C:
    _lods(memory(_es, _si));                    //lods byte ptr es:[si]
    memory(_ds, _di) = _al;                     //mov [di], al
    _di += 1;                                   //inc di
    _stack16(_bp + var_51) -= 1;                //dec [bp+var_51]
    if (_FIXME_)                                //jg short loc_14F8C
        goto loc_14F8C;
    _STOP_("call $+3");                         //call $+3
    goto loc_15015;                             //jmp loc_15015
loc_14F8C:                                      //loc_14F8C:
    if (--_cx)                                  //loop loc_14F7C
        goto loc_14F7C;
loc_14F8E:                                      //loc_14F8E:
    _bx |= _bx;                                 //or bx, bx
    if ((short)_bx <= (short))                  //jle short loc_14F9E
        goto loc_14F9E;
    _cx = _bx;                                  //mov cx, bx
loc_14F94:                                      //loc_14F94:
    _al = 0x20;                                 //mov al, 20h
    _STOP_("call $+3");                         //call $+3
    goto loc_15007;                             //jmp short loc_15007
    if (--_cx)                                  //loop loc_14F94
        goto loc_14F94;
loc_14F9E:                                      //loc_14F9E:
    goto loc_14BC3;                             //jmp loc_14BC3
loc_14FA1:                                      //loc_14FA1:
    _stack16(_bp + arg_2) = _si;                //mov [bp+arg_2], si
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    if (_stack16(_bp + var_8A) & 0x0020)        //jnz short loc_14FB8
        goto loc_14FB8;
    _di = memory16(_ds, _di);                   //mov di, [di]
    _stack16(_bp + arg_0) += 0x0002;            //add [bp+arg_0], 2
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    goto loc_14FBE;                             //jmp short loc_14FBE
loc_14FB8:                                      //loc_14FB8:
    _les(_di, _ds, _di);                        //les di, [di]
    _stack16(_bp + arg_0) += 0x0004;            //add [bp+arg_0], 4
loc_14FBE:                                      //loc_14FBE:
    _ax = 0x0050;                               //mov ax, 50h
    _al = _al - _stack16(_bp + var_51);         //sub al, [bp+var_51]
    _ax = _ax + _stack16(_bp + var_54);         //add ax, [bp+var_54]
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    goto loc_14BBF;                             //jmp loc_14BBF
loc_14FCD:                                      //loc_14FCD:
    _si = _stack16(_bp + var_86);               //mov si, [bp+var_86]
    _di = _stack16(_bp + var_92);               //mov di, [bp+var_92]
    _al = 0x25;                                 //mov al, 25h
loc_14FD7:                                      //loc_14FD7:
    _STOP_("call $+3");                         //call $+3
    goto loc_15007;                             //jmp short loc_15007
    _STOP_("db 90h");                           //db 90h
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_14FD7
        goto loc_14FD7;
loc_14FE2:                                      //loc_14FE2:
    if ((short)_stack16(_bp + var_51) >= (short)0x0050)
        goto loc_14FEE;
    _STOP_("call $+3");                         //call $+3
    goto loc_15015;                             //jmp short loc_15015
loc_14FEE:                                      //loc_14FEE:
    _es = _pop();                               //pop es
    _ax = _stack16(_bp + var_54);               //mov ax, [bp+var_54]
    goto loc_1503D;                             //jmp short loc_1503D
    _STOP_("db 90h");                           //db 90h
loc_14FF5:                                      //loc_14FF5:
    _push(_di);                                 //push di
    _cx = 0xffff;                               //mov cx, 0FFFFh
    _al = 0x00;                                 //mov al, 0
    _repne_scasb();                             //repne scasb
    _cx = (~_cx);                               //not cx
    _cx -= 1;                                   //dec cx
    _di = _pop();                               //pop di
    _ax = _pop();                               //pop ax
    _ax += 0x0003;                              //add ax, 3
    _STOP_("goto ax");                          //jmp ax
loc_15007:                                      //loc_15007:
    memory(_ds, _di) = _al;                     //mov [di], al
    _di += 1;                                   //inc di
    _stack16(_bp + var_51) -= 1;                //dec [bp+var_51]
    if (_FIXME_)                                //jle short loc_15015
        goto loc_15015;
    _ax = _pop();                               //pop ax
    _ax += 0x0003;                              //add ax, 3
    _STOP_("goto ax");                          //jmp ax
loc_15015:                                      //loc_15015:
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_es);                                 //push es
    _FIXME_;                                    //lea ax, [bp+var_50]
    _di -= _ax;                                 //sub di, ax
    _FIXME_;                                    //lea ax, [bp+var_50]
    _push(_ax);                                 //push ax
    _push(_di);                                 //push di
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _STOP_("");                                 //call ss:off_186AE[bp]
    _stack16(_bp + var_51) = 0x0050;            //mov [bp+var_51], 50h
    _stack16(_bp + var_54) += _di;              //add [bp+var_54], di
    _FIXME_;                                    //lea di, [bp+var_50]
    _es = _pop();                               //pop es
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _ax += 0x0003;                              //add ax, 3
    _STOP_("goto ax");                          //jmp ax
loc_1503D:                                      //loc_1503D:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(8);                            //retn 8
    return;
}

void sub_15045()
{
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    const int arg_2 = 6;                        //arg_2  = word ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _ax -= 1;                                   //dec ax
    _dl = memory(_ds, 0x37A);                   //mov dl, byte_18A1A
    _dh = 0x00;                                 //mov dh, 0
    _mul(_dx);                                  //mul dx
    _ax = _ax + memory16(_ds, 0x37D);           //add ax, word_18A1D
    _dx = _stack16(_bp + arg_2);                //mov dx, [bp+arg_2]
    _dx -= 1;                                   //dec dx
    _ax += _dx;                                 //add ax, dx
    _ax <<= 1;                                  //shl ax, 1
    _dx = memory16(_ds, 0x37F);                 //mov dx, word_18A1F
    _bp = _pop();                               //pop bp
    _stackReduce(4);                            //retn 4
    return;
}

void sub_15068()
{
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = dword ptr  0Ah
    const int arg_6 = 14;                       //arg_6  = dword ptr  0Eh
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 1;                                   //dec sp
    _sp -= 1;                                   //dec sp
    _al = memory(_ds, 0x37C);                   //mov al, byte_18A1C
    _ah = 0x00;                                 //mov ah, 0
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    _push(_ds);                                 //push ds
    _cx = _stack16(_bp + arg_0);                //mov cx, [bp+arg_0]
    if (_cx == 0)                               //jcxz short loc_150D7
        goto loc_150D7;
    _FIXME_;                                    //les di, [bp+arg_6]
    _FIXME_;                                    //lds si, [bp+arg_2]
    _flags.direction = false;                   //cld
    if (_si >= _di)                             //jnb short loc_15092
        goto loc_15092;
    _ax = _cx;                                  //mov ax, cx
    _ax -= 1;                                   //dec ax
    _ax <<= 1;                                  //shl ax, 1
    _si += _ax;                                 //add si, ax
    _di += _ax;                                 //add di, ax
    _flags.direction = true;                    //std
loc_15092:                                      //loc_15092:
    if (_stack16(_bp + var_2) != 0x0000)        //jnz short loc_1509C
        goto loc_1509C;
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    goto loc_150D7;                             //jmp short loc_150D7
loc_1509C:                                      //loc_1509C:
    _dx = 0x03da;                               //mov dx, 3DAh
    _ax = _es;                                  //mov ax, es
    _bx = _ds;                                  //mov bx, ds
    if (_ax == _bx)                             //jz short loc_150B8
        goto loc_150B8;
loc_150A7:                                      //loc_150A7:
    _flags.interrupt = false;                   //cli
loc_150A8:                                      //loc_150A8:
    _in(_al, _dx);                              //in al, dx
    _ror(_al, 1);                               //ror al, 1
    _flags.carry = !!(_al & 0x80);
    if (_flags.carry)                           //jb short loc_150A8
        goto loc_150A8;
loc_150AD:                                      //loc_150AD:
    _in(_al, _dx);                              //in al, dx
    _ror(_al, 1);                               //ror al, 1
    _flags.carry = !!(_al & 0x80);
    if (!_flags.carry)                          //jnb short loc_150AD
        goto loc_150AD;
    _movsw<MemAuto, MemAuto, DirAuto>();        //movsw
    _flags.interrupt = true;                    //sti
    if (--_cx)                                  //loop loc_150A7
        goto loc_150A7;
    goto loc_150D7;                             //jmp short loc_150D7
loc_150B8:                                      //loc_150B8:
    _flags.interrupt = false;                   //cli
loc_150B9:                                      //loc_150B9:
    _in(_al, _dx);                              //in al, dx
    _ror(_al, 1);                               //ror al, 1
    _flags.carry = !!(_al & 0x80);
    if (_flags.carry)                           //jb short loc_150B9
        goto loc_150B9;
loc_150BE:                                      //loc_150BE:
    _in(_al, _dx);                              //in al, dx
    _ror(_al, 1);                               //ror al, 1
    _flags.carry = !!(_al & 0x80);
    if (!_flags.carry)                          //jnb short loc_150BE
        goto loc_150BE;
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _flags.interrupt = true;                    //sti
    _bx = _ax;                                  //mov bx, ax
loc_150C7:                                      //loc_150C7:
    _in(_al, _dx);                              //in al, dx
    _ror(_al, 1);                               //ror al, 1
    _flags.carry = !!(_al & 0x80);
    if (_flags.carry)                           //jb short loc_150C7
        goto loc_150C7;
loc_150CC:                                      //loc_150CC:
    _in(_al, _dx);                              //in al, dx
    _ror(_al, 1);                               //ror al, 1
    _flags.carry = !!(_al & 0x80);
    if (!_flags.carry)                          //jnb short loc_150CC
        goto loc_150CC;
    _ax = _bx;                                  //mov ax, bx
    _stosw<MemAuto, DirAuto>();                 //stosw
    _flags.interrupt = true;                    //sti
    if (--_cx)                                  //loop loc_150B8
        goto loc_150B8;
loc_150D7:                                      //loc_150D7:
    _ds = _pop();                               //pop ds
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(10);                           //retn 0Ah
    return;
}

void sub_150E0()
{
    _ah = 0x03;                                 //mov ah, 3
    _bh = 0x00;                                 //mov bh, 0
    sub_13E83();                                //call sub_13E83
    _ax = _dx;                                  //mov ax, dx
}

void sub_1510D()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _di = _stack16(_bp + arg_0);                //mov di, [bp+arg_0]
    _si = 0x0ab8;                               //mov si, 0AB8h
    memory(_ds, 0xAB8) = 0x00;                  //mov byte_19158, 0
loc_1511D:                                      //loc_1511D:
    _si -= 1;                                   //dec si
    _ax = _di;                                  //mov ax, di
    _bx = 0x000a;                               //mov bx, 0Ah
    _dx = _dx ^ _dx;                            //xor dx, dx
    _div(_bx);                                  //div bx
    _dl += 0x30;                                //add dl, 30h
    memory(_ds, _si) = _dl;                     //mov [si], dl
    _ax = _di;                                  //mov ax, di
    _dx = _dx ^ _dx;                            //xor dx, dx
    _div(_bx);                                  //div bx
    _di = _ax;                                  //mov di, ax
    _di |= _di;                                 //or di, di
    if (_di != 0)                               //jnz short loc_1511D
        goto loc_1511D;
    _ax = _si;                                  //mov ax, si
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(2);                            //retn 2
    return;
}

void sub_15140()
{
    const int arg_0 = 8;                        //arg_0  = dword ptr  8
    const int arg_4 = 12;                       //arg_4  = dword ptr  0Ch
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _FIXME_;                                    //lds si, [bp+arg_0]
    _FIXME_;                                    //les di, [bp+arg_4]
loc_1514C:                                      //loc_1514C:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz short loc_1514C
        goto loc_1514C;
    _ds = _pop();                               //pop ds
    _dx = memory16(_ds, _bp + arg_6);           //mov dx, word ptr [bp+arg_4+2]
    _ax = memory16(_ds, _bp + arg_4);           //mov ax, word ptr [bp+arg_4]
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(8);                            //retn 8
    return;
}

void sub_1515F()
{
    const int arg_0 = 8;                        //arg_0  = dword ptr  8
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _FIXME_;                                    //les di, [bp+arg_0]
    _cx = 0xffff;                               //mov cx, 0FFFFh
    _al = _al ^ _al;                            //xor al, al
    _flags.direction = false;                   //cld
    _repne_scasb();                             //repne scasb
    _di -= 1;                                   //dec di
    _ax = _di;                                  //mov ax, di
    _dx = _es;                                  //mov dx, es
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(4);                            //retn 4
    return;
}

void sub_1517A()
{
    const int arg_0 = 8;                        //arg_0  = dword ptr  8
    const int arg_4 = 12;                       //arg_4  = dword ptr  0Ch
    const int arg_8 = 16;                       //arg_8  = dword ptr  10h
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _FIXME_;                                    //les di, [bp+arg_8]
    _FIXME_;                                    //lds si, [bp+arg_4]
    _ax = _ds;                                  //mov ax, ds
    _ax |= _si;                                 //or ax, si
    if (_ax == 0)                               //jz short loc_15193
        goto loc_15193;
loc_1518C:                                      //loc_1518C:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz short loc_1518C
        goto loc_1518C;
    _di -= 1;                                   //dec di
loc_15193:                                      //loc_15193:
    _FIXME_;                                    //lds si, [bp+arg_0]
loc_15196:                                      //loc_15196:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz short loc_15196
        goto loc_15196;
    _di -= 1;                                   //dec di
    _ds = _pop();                               //pop ds
    _ax = _di;                                  //mov ax, di
    _dx = _es;                                  //mov dx, es
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(12);                           //retn 0Ch
    return;
}

void sub_151A8()
{
    const int arg_0 = 4;                        //arg_0  = dword ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _FIXME_;                                    //lds dx, [bp+arg_0]
    _ah = 0x09;                                 //mov ah, 9
    _interrupt(33);                             //int 21h
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    _stackReduce(4);                            //retn 4
    return;
}

void sub_151B8()
{
    _bx = memory16(_ds, 0xAAC);                 //mov bx, word_1914C
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(33);                             //int 21h
}

void sub_151C1()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = dword ptr  0Ah
    const int arg_6 = 14;                       //arg_6  = dword ptr  0Eh
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _FIXME_;                                    //lds dx, [bp+arg_6]
    _ax = 0x3d00;                               //mov ax, 3D00h
    _interrupt(33);                             //int 21h
    _ds = _pop();                               //pop ds
    if (!_flags.carry)                          //jnb short loc_151D7
        goto loc_151D7;
    _ax = 0xfffd;                               //mov ax, 0FFFDh
    goto loc_15202;                             //jmp short loc_15202
loc_151D7:                                      //loc_151D7:
    memory16(_ds, 0xAAC) = _ax;                 //mov word_1914C, ax
    _bx = _ax;                                  //mov bx, ax
    _cx = _cx ^ _cx;                            //xor cx, cx
    _dx = _dx ^ _dx;                            //xor dx, dx
    _ax = 0x4202;                               //mov ax, 4202h
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_151F4
        goto loc_151F4;
    _ax &= _ax;                                 //and ax, ax
    if (_ax == 0)                               //jz short loc_151F4
        goto loc_151F4;
    _dx &= _dx;                                 //and dx, dx
    if (_dx != 0)                               //jnz short loc_151F4
        goto loc_151F4;
    if (_ax <= 0x3c00)                          //jbe short loc_151FC
        goto loc_151FC;
loc_151F4:                                      //loc_151F4:
    sub_151B8();                                //call sub_151B8
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    goto loc_15202;                             //jmp short loc_15202
loc_151FC:                                      //loc_151FC:
    _FIXME_;                                    //les di, [bp+arg_2]
    _stosw<MemAuto, DirAuto>();                 //stosw
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_15202:                                      //loc_15202:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(10);                           //retn 0Ah
    return;
}

void sub_15208()
{
    const int arg_0 = 4;                        //arg_0  = dword ptr  4
    const int arg_4 = 8;                        //arg_4  = word ptr  8
    const int arg_6 = 10;                       //arg_6  = word ptr  0Ah
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _bx = memory16(_ds, 0xAAC);                 //mov bx, word_1914C
    _cx = _cx ^ _cx;                            //xor cx, cx
    _dx = _stack16(_bp + arg_6);                //mov dx, [bp+arg_6]
    _ax = 0x4200;                               //mov ax, 4200h
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_15231
        goto loc_15231;
    _push(_ds);                                 //push ds
    _bx = memory16(_ds, 0xAAC);                 //mov bx, word_1914C
    _cx = _stack16(_bp + arg_4);                //mov cx, [bp+arg_4]
    _FIXME_;                                    //lds dx, [bp+arg_0]
    _ah = 0x3f;                                 //mov ah, 3Fh
    _interrupt(33);                             //int 21h
    _ds = _pop();                               //pop ds
    if (_flags.carry)                           //jb short loc_15231
        goto loc_15231;
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_1523D;                             //jmp short loc_1523D
loc_15231:                                      //loc_15231:
    sub_151B8();                                //call sub_151B8
    memory16(_ds, 0xA9E) = 0xfff4;              //mov word_1913E, 0FFF4h
    _ax = 0x0001;                               //mov ax, 1
loc_1523D:                                      //loc_1523D:
    _bp = _pop();                               //pop bp
    _stackReduce(8);                            //retn 8
    return;
}

void loc_15265()
{
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    switch (_bx)                                //jmp cs:off_1526E[bx]
    {
      case 0: goto loc_1533B;
      case 2: goto loc_15331;
      case 4: goto loc_1531F;
      case 6: goto loc_15315;
      case 8: goto loc_1530B;
      case 10: goto loc_15301;
      case 12: goto loc_152F7;
      case 14: goto loc_152ED;
      case 16: goto loc_152E2;
      case 18: goto loc_152D7;
      case 20: goto loc_152CC;
      case 22: goto loc_152B9;
      case 24: goto loc_152AF;
      case 26: goto loc_152A4;
      case 28: goto loc_15299;
      case 30: goto loc_1528E;
      default:
        _ASSERT(0);
    }
loc_1528E:                                      //loc_1528E:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x0738;                           //mov word ptr [bp-8], 738h
    goto loc_1535D;                             //jmp loc_1535D
loc_15299:                                      //loc_15299:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x0741;                           //mov word ptr [bp-8], 741h
    goto loc_1535D;                             //jmp loc_1535D
loc_152A4:                                      //loc_152A4:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x075e;                           //mov word ptr [bp-8], 75Eh
    goto loc_1535D;                             //jmp loc_1535D
loc_152AF:                                      //loc_152AF:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x077d;                           //mov word ptr [bp-8], 77Dh
    goto loc_152C1;                             //jmp short loc_152C1
loc_152B9:                                      //loc_152B9:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x079c;                           //mov word ptr [bp-8], 79Ch
loc_152C1:                                      //loc_152C1:
    _FIXME_ = _ds;                              //mov word ptr [bp-2], ds
    _FIXME_ = 0x0501;                           //mov word ptr [bp-4], 501h
    goto loc_1535D;                             //jmp loc_1535D
loc_152CC:                                      //loc_152CC:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x07b9;                           //mov word ptr [bp-8], 7B9h
    goto loc_1535D;                             //jmp loc_1535D
loc_152D7:                                      //loc_152D7:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x07da;                           //mov word ptr [bp-8], 7DAh
    goto loc_1535D;                             //jmp short loc_1535D
loc_152E2:                                      //loc_152E2:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x07f5;                           //mov word ptr [bp-8], 7F5h
    goto loc_1535D;                             //jmp short loc_1535D
    _STOP_("db 90h");                           //db 90h
loc_152ED:                                      //loc_152ED:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x0811;                           //mov word ptr [bp-8], 811h
    goto loc_15327;                             //jmp short loc_15327
loc_152F7:                                      //loc_152F7:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x0827;                           //mov word ptr [bp-8], 827h
    goto loc_1535D;                             //jmp short loc_1535D
loc_15301:                                      //loc_15301:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x0846;                           //mov word ptr [bp-8], 846h
    goto loc_1535D;                             //jmp short loc_1535D
loc_1530B:                                      //loc_1530B:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x0870;                           //mov word ptr [bp-8], 870h
    goto loc_1535D;                             //jmp short loc_1535D
loc_15315:                                      //loc_15315:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x087f;                           //mov word ptr [bp-8], 87Fh
    goto loc_1535D;                             //jmp short loc_1535D
loc_1531F:                                      //loc_1531F:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x0892;                           //mov word ptr [bp-8], 892h
loc_15327:                                      //loc_15327:
    _FIXME_ = _ds;                              //mov word ptr [bp-2], ds
    _FIXME_ = 0x04f8;                           //mov word ptr [bp-4], 4F8h
    goto loc_1535D;                             //jmp short loc_1535D
loc_15331:                                      //loc_15331:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x08a6;                           //mov word ptr [bp-8], 8A6h
    goto loc_1535D;                             //jmp short loc_1535D
loc_1533B:                                      //loc_1533B:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x08ba;                           //mov word ptr [bp-8], 8BAh
    goto loc_1535D;                             //jmp short loc_1535D
loc_15345:                                      //loc_15345:
    _FIXME_ = _ds;                              //mov word ptr [bp-6], ds
    _FIXME_ = 0x08d0;                           //mov word ptr [bp-8], 8D0h
    _push(memory16(_ds, _bp + 8));              //push word ptr [bp+8]
    sub_1510D();                                //call sub_1510D
    _bx = _ax;                                  //mov bx, ax
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _FIXME_ = _es;                              //mov word ptr [bp-2], es
    _stack16(_bp + -4) = _bx;                   //mov [bp-4], bx
loc_1535D:                                      //loc_1535D:
    _ax = _stack16(_bp + -4);                   //mov ax, [bp-4]
    _ax = _ax | _stack16(_bp + -2);             //or ax, [bp-2]
    if (_ax == 0)                               //jz short loc_1538A
        goto loc_1538A;
    _push(_ds);                                 //push ds
    _ax = 0x0ac5;                               //mov ax, 0AC5h
    _push(_ax);                                 //push ax
    _push(_FIXME_);                             //push word ptr [bp-6]
    _push(_FIXME_);                             //push word ptr [bp-8]
    _push(_FIXME_);                             //push word ptr [bp-2]
    _push(_FIXME_);                             //push word ptr [bp-4]
    sub_1517A();                                //call sub_1517A
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x08e1;                               //mov ax, 8E1h
    _push(_ax);                                 //push ax
    sub_15140();                                //call sub_15140
    _ax = _STOP_;                               //mov ax, offset unk_19165
    _dx = _ds;                                  //mov dx, ds
    goto loc_15398;                             //jmp short loc_15398
loc_1538A:                                      //loc_1538A:
    _push(_ds);                                 //push ds
    _ax = 0x0ac5;                               //mov ax, 0AC5h
    _push(_ax);                                 //push ax
    _push(_FIXME_);                             //push word ptr [bp-6]
    _push(_FIXME_);                             //push word ptr [bp-8]
    sub_15140();                                //call sub_15140
loc_15398:                                      //loc_15398:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_1539D()
{
    WORD _cs = _seg000;

    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _si = memory16(_ds, 0xA9E);                 //mov si, word_1913E
    memory16(_ds, 0xA9E) = 0x0000;              //mov word_1913E, 0
    _ax = _si;                                  //mov ax, si
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void sub_153B5()
{
    WORD _cs = _seg000;

    if (memory16(_ds, 0x616) == 0x0000)         //jz short loc_153C6
        goto loc_153C6;
    _push(_ds);                                 //push ds
    _ax = 0x08e3;                               //mov ax, 8E3h
    _push(_ax);                                 //push ax
    sub_151A8();                                //call sub_151A8
    goto loc_153CE;                             //jmp short loc_153CE
loc_153C6:                                      //loc_153C6:
    _push(_ds);                                 //push ds
    _ax = 0x0907;                               //mov ax, 907h
    _push(_ax);                                 //push ax
    sub_151A8();                                //call sub_151A8
loc_153CE:                                      //loc_153CE:
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_1415D();                                //call near ptr sub_1415D
}

void sub_153D8()
{
    WORD _cs = _seg000;

    const int arg_0 = 4;                        //arg_0  = dword ptr  4
    const int arg_4 = 8;                        //arg_4  = word ptr  8
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_cs);                                 //push cs
    sub_14175();                                //call near ptr sub_14175
    _cx = _pop();                               //pop cx
    _cx = _ax;                                  //mov cx, ax
    _cx |= _dx;                                 //or cx, dx
    if (_cx == 0)                               //jz short loc_153F7
        goto loc_153F7;
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_153F7
        goto loc_153F7;
    _bx = _ds;                                  //mov bx, ds
    if (_bx != _dx)                             //jnz short loc_153F7
        goto loc_153F7;
    _cx = _cx ^ _cx;                            //xor cx, cx
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_153F7:                                      //loc_153F7:
    _FIXME_;                                    //les bx, [bp+arg_0]
    memory16(_es, _bx) = _ax;                   //mov es:[bx], ax
    memory16(_es, _bx + 2) = _dx;               //mov es:[bx+2], dx
    _ax = 0x0001;                               //mov ax, 1
    if (_cx == 0)                               //jcxz short loc_15407
        goto loc_15407;
    _ax -= 1;                                   //dec ax
loc_15407:                                      //loc_15407:
    _bp = _pop();                               //pop bp
}

void sub_15409()
{
    WORD _cs = _seg000;

    const int arg_0 = 4;                        //arg_0  = dword ptr  4
    const int arg_4 = 8;                        //arg_4  = word ptr  8
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _FIXME_;                                    //les bx, [bp+arg_0]
    _ax = memory16(_es, _bx);                   //mov ax, es:[bx]
    _ax = _ax | memory16(_es, _bx + 2);         //or ax, es:[bx+2]
    if (_ax == 0)                               //jz short loc_15431
        goto loc_15431;
    if (_stack16(_bp + arg_4) == 0x0000)        //jz short loc_15431
        goto loc_15431;
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _FIXME_;                                    //les bx, [bp+arg_0]
    _push(memory16(_es, _bx + 2));              //push word ptr es:[bx+2]
    _push(memory16(_es, _bx));                  //push word ptr es:[bx]
    _push(_cs);                                 //push cs
    sub_14169();                                //call near ptr sub_14169
    _sp = _bp;                                  //mov sp, bp
loc_15431:                                      //loc_15431:
    _FIXME_;                                    //les bx, [bp+arg_0]
    memory16(_es, _bx + 2) = 0x0000;            //mov word ptr es:[bx+2], 0
    memory16(_es, _bx) = 0x0000;                //mov word ptr es:[bx], 0
    _bp = _pop();                               //pop bp
}

void sub_15441()
{
    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = dword ptr  0Ah
    const int arg_6 = 14;                       //arg_6  = word ptr  0Eh
    const int arg_8 = 16;                       //arg_8  = word ptr  10h
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _si = _stack16(_bp + arg_6);                //mov si, [bp+arg_6]
    _FIXME_;                                    //les bx, [bp+arg_2]
    _si = _si + memory16(_es, _bx);             //add si, es:[bx]
    _ax = _si;                                  //mov ax, si
    _ax &= 0x000f;                              //and ax, 0Fh
    memory16(_es, _bx) -= _ax;                  //sub es:[bx], ax
    _dx = _stack16(_bp + arg_8);                //mov dx, [bp+arg_8]
    _ax = _si;                                  //mov ax, si
    _cl = 0x04;                                 //mov cl, 4
    _ax >>= _cl;                                //shr ax, cl
    _dx += _ax;                                 //add dx, ax
    _si &= 0x000f;                              //and si, 0Fh
    if (_si == 0)                               //jz short loc_15475
        goto loc_15475;
    _cx = _stack16(_bp + arg_0);                //mov cx, [bp+arg_0]
    _push(_ds);                                 //push ds
    _ds = _dx;                                  //mov ds, dx
    _es = _dx;                                  //mov es, dx
    _di = _di ^ _di;                            //xor di, di
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ds = _pop();                               //pop ds
loc_15475:                                      //loc_15475:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _stackReduce(10);                           //retn 0Ah
    return;
}

void sub_1547D()
{
    WORD _cs = _seg000;

    const int var_6 = -6;                       //var_6  = dword ptr -6
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_0 = 12;                       //arg_0  = dword ptr  0Ch
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0006;                              //sub sp, 6
    if (memory16(_ds, 0x616) == 0x0000)         //jz short loc_1549B
        goto loc_1549B;
    _ax = 0xfff5;                               //mov ax, 0FFF5h
    memory16(_ds, 0xA9E) = _ax;                 //mov word_1913E, ax
    goto loc_1550C;                             //jmp short loc_1550C
    _STOP_("db 90h");                           //db 90h
loc_1549B:                                      //loc_1549B:
    _FIXME_;                                    //les bx, [bp+arg_0]
    if (memory16(_es, _bx) != 0x6b70)           //jnz short loc_154DC
        goto loc_154DC;
    _FIXME_;                                    //les di, [bp+arg_0]
    _cx = 0xffff;                               //mov cx, 0FFFFh
    _al = 0x1a;                                 //mov al, 1Ah
    _flags.direction = false;                   //cld
    _repne_scasb();                             //repne scasb
    memory16(_ds, _bp + arg_6) = _di;           //mov word ptr [bp+var_6], di
    memory16(_ds, _bp + arg_8) = _es;           //mov word ptr [bp+var_6+2], es
    _FIXME_;                                    //les bx, [bp+var_6]
    _ax = memory16(_es, _bx + 2);               //mov ax, es:[bx+2]
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    _FIXME_;                                    //or ax, ax
    _ax |= _ax;
    if (_flags.carry)                           //jb short loc_154DC
        goto loc_154DC;
    if (_ax <= 0x0005)                          //jbe short loc_154CB
        goto loc_154CB;
    goto loc_154DC;                             //jmp short loc_154DC
loc_154CB:                                      //loc_154CB:
    _FIXME_;                                    //les bx, [bp+var_6]
    if (memory(_es, _bx + 6) < 0x01)            //jb short loc_154DC
        goto loc_154DC;
    if (memory(_es, _bx + 8) <= 0x01)           //jbe short loc_154E4
        goto loc_154E4;
loc_154DC:                                      //loc_154DC:
    _ax = 0xfffc;                               //mov ax, 0FFFCh
    memory16(_ds, 0xA9E) = _ax;                 //mov word_1913E, ax
    goto loc_1550C;                             //jmp short loc_1550C
loc_154E4:                                      //loc_154E4:
    _push(memory16(_ds, _bp + arg_2));          //push word ptr [bp+arg_0+2]
    _push(memory16(_ds, _bp + arg_0));          //push word ptr [bp+arg_0]
    _push(memory16(_ds, _bp + arg_8));          //push word ptr [bp+var_6+2]
    _push(memory16(_ds, _bp + arg_6));          //push word ptr [bp+var_6]
    _FIXME_;                                    //les bx, [bp+var_6]
    _push(memory16(_es, _bx + 4));              //push word ptr es:[bx+4]
    sub_15441();                                //call sub_15441
    _bx = _stack16(_bp + var_2);                //mov bx, [bp+var_2]
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 1566) = _dx;            //mov [bx+61Eh], dx
    memory16(_ds, _bx + 1564) = _ax;            //mov [bx+61Ch], ax
    _ax = _stack16(_bp + var_2);                //mov ax, [bp+var_2]
loc_1550C:                                      //loc_1550C:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void sub_15513()
{
    WORD _cs = _seg000;

    const int var_12 = -18;                     //var_12  = word ptr -12h
    const int var_10 = -16;                     //var_10  = dword ptr -10h
    const int var_C = -12;                      //var_C  = dword ptr -0Ch
    const int var_8 = -8;                       //var_8  = word ptr -8
    const int var_6 = -6;                       //var_6  = word ptr -6
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_0 = 12;                       //arg_0  = dword ptr  0Ch
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0012;                              //sub sp, 12h
    _FIXME_;                                    //les bx, [bp+arg_0]
    if (memory16(_es, _bx) != 0x4b50)           //jnz short loc_1554D
        goto loc_1554D;
    _FIXME_;                                    //les di, [bp+arg_0]
    _cx = 0xffff;                               //mov cx, 0FFFFh
    _al = 0x1a;                                 //mov al, 1Ah
    _flags.direction = false;                   //cld
    _repne_scasb();                             //repne scasb
    memory16(_ds, _bp + arg_16) = _di;          //mov word ptr [bp+var_10], di
    memory16(_ds, _bp + arg_18) = _es;          //mov word ptr [bp+var_10+2], es
    _FIXME_;                                    //les bx, [bp+var_10]
    if (memory(_es, _bx + 8) < 0x01)            //jb short loc_1554D
        goto loc_1554D;
    if (memory(_es, _bx + 10) <= 0x01)          //jbe short loc_15556
        goto loc_15556;
loc_1554D:                                      //loc_1554D:
    _ax = 0xfff3;                               //mov ax, 0FFF3h
    memory16(_ds, 0xA9E) = _ax;                 //mov word_1913E, ax
    goto loc_1563D;                             //jmp loc_1563D
loc_15556:                                      //loc_15556:
    _FIXME_;                                    //les bx, [bp+var_10]
    _bx += 0x0002;                              //add bx, 2
    memory16(_ds, _bp + arg_14) = _es;          //mov word ptr [bp+var_C+2], es
    memory16(_ds, _bp + arg_12) = _bx;          //mov word ptr [bp+var_C], bx
    _stack16(_bp + var_8) = 0x056b;             //mov [bp+var_8], 56Bh
    _stack16(_bp + var_2) = 0xffff;             //mov [bp+var_2], 0FFFFh
    _stack16(_bp + var_4) = 0x0000;             //mov [bp+var_4], 0
    goto loc_155B1;                             //jmp short loc_155B1
loc_15573:                                      //loc_15573:
    _FIXME_;                                    //les bx, [bp+var_C]
    _dx = memory16(_es, _bx + 2);               //mov dx, es:[bx+2]
    _ax = memory16(_es, _bx);                   //mov ax, es:[bx]
    _bx = _stack16(_bp + var_8);                //mov bx, [bp+var_8]
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
    if (_dx != memory16(_es, _bx + 2))          //jnz short loc_15591
        goto loc_15591;
    if (_ax == memory16(_es, _bx))              //jz short loc_155B7
        goto loc_155B7;
loc_15591:                                      //loc_15591:
    if (_stack16(_bp + var_2) >= 0x0000)        //jnb short loc_155AA
        goto loc_155AA;
    _bx = _stack16(_bp + var_8);                //mov bx, [bp+var_8]
    if (memory(_ds, _bx) != 0x00)               //jnz short loc_155AA
        goto loc_155AA;
    _ax = _stack16(_bp + var_4);                //mov ax, [bp+var_4]
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    _ax = _bx;                                  //mov ax, bx
    _stack16(_bp + var_6) = _ax;                //mov [bp+var_6], ax
loc_155AA:                                      //loc_155AA:
    _stack16(_bp + var_8) += 0x000f;            //add [bp+var_8], 0Fh
    _stack16(_bp + var_4) += 1;                 //inc [bp+var_4]
loc_155B1:                                      //loc_155B1:
    if (_stack16(_bp + var_4) < 0x000a)         //jb short loc_15573
        goto loc_15573;
loc_155B7:                                      //loc_155B7:
    if (_stack16(_bp + var_4) < 0x000a)         //jb short loc_155EC
        goto loc_155EC;
    if (_stack16(_bp + var_2) != 0xffff)        //jnz short loc_155CC
        goto loc_155CC;
    _ax = 0xfff5;                               //mov ax, 0FFF5h
    memory16(_ds, 0xA9E) = _ax;                 //mov word_1913E, ax
    goto loc_1563D;                             //jmp short loc_1563D
loc_155CC:                                      //loc_155CC:
    _FIXME_;                                    //les bx, [bp+var_C]
    _dx = memory16(_es, _bx + 2);               //mov dx, es:[bx+2]
    _ax = memory16(_es, _bx);                   //mov ax, es:[bx]
    _bx = _stack16(_bp + var_6);                //mov bx, [bp+var_6]
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
    memory16(_es, _bx + 2) = _dx;               //mov es:[bx+2], dx
    memory16(_es, _bx) = _ax;                   //mov es:[bx], ax
    _ax = _stack16(_bp + var_2);                //mov ax, [bp+var_2]
    _stack16(_bp + var_4) = _ax;                //mov [bp+var_4], ax
loc_155EC:                                      //loc_155EC:
    _ax = _stack16(_bp + var_4);                //mov ax, [bp+var_4]
    _dx = 0x000f;                               //mov dx, 0Fh
    _mul(_dx);                                  //mul dx
    _ax += 0x0561;                              //add ax, 561h
    _stack16(_bp + var_12) = _ax;               //mov [bp+var_12], ax
    _bx = _ax;                                  //mov bx, ax
    _push(memory16(_ds, _bx + 8));              //push word ptr [bx+8]
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    sub_15409();                                //call sub_15409
    _sp += 0x0006;                              //add sp, 6
    _bx = _stack16(_bp + var_12);               //mov bx, [bp+var_12]
    memory16(_ds, _bx + 2) = 0x0000;            //mov word ptr [bx+2], 0
    memory16(_ds, _bx) = 0x0000;                //mov word ptr [bx], 0
    _push(memory16(_ds, _bp + arg_2));          //push word ptr [bp+arg_0+2]
    _push(memory16(_ds, _bp + arg_0));          //push word ptr [bp+arg_0]
    _push(memory16(_ds, _bp + arg_18));         //push word ptr [bp+var_10+2]
    _push(memory16(_ds, _bp + arg_16));         //push word ptr [bp+var_10]
    _FIXME_;                                    //les bx, [bp+var_10]
    _push(memory16(_es, _bx + 6));              //push word ptr es:[bx+6]
    sub_15441();                                //call sub_15441
    _bx = _stack16(_bp + var_12);               //mov bx, [bp+var_12]
    memory16(_ds, _bx + 6) = _dx;               //mov [bx+6], dx
    memory16(_ds, _bx + 4) = _ax;               //mov [bx+4], ax
    memory16(_ds, _bx + 8) = 0x0000;            //mov word ptr [bx+8], 0
    _ax = _stack16(_bp + var_4);                //mov ax, [bp+var_4]
    _ax += 1;                                   //inc ax
loc_1563D:                                      //loc_1563D:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void loc_15661()
{
    _ax = _stack16(_bp + 10);                   //mov ax, [bp+0Ah]
    memory16(_ds, 0x55F) = _ax;                 //mov word_18BFF, ax
loc_15667:                                      //loc_15667:
    _ax = _si;                                  //mov ax, si
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void sub_1566D()
{
    WORD _cs = _seg000;

    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = dword ptr  0Ah
    const int arg_6 = 14;                       //arg_6  = dword ptr  0Eh
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _FIXME_;                                    //les bx, [bp+arg_2]
    memory16(_es, _bx) = 0x0000;                //mov word ptr es:[bx], 0
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _ax -= 1;                                   //dec ax
    if (_ax > 0x0009)                           //ja short loc_156E8
        goto loc_156E8;
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    switch (_bx)                                //jmp cs:off_15690[bx]
    {
      case 0: goto loc_156A4;
      case 2: goto loc_156AE;
      case 4: goto loc_156DE;
      case 6: goto loc_156DE;
      case 8: goto loc_156C2;
      case 10: goto loc_156DE;
      case 12: goto loc_156D4;
      case 14: goto loc_156AE;
      case 16: goto loc_156B8;
      case 18: goto loc_156D4;
      default:
        _ASSERT(0);
    }
loc_156A4:                                      //loc_156A4:
    _FIXME_;                                    //les bx, [bp+arg_6]
    memory16(_es, _bx) = 0x0004;                //mov word ptr es:[bx], 4
    goto loc_156F8;                             //jmp short loc_156F8
loc_156AE:                                      //loc_156AE:
    _FIXME_;                                    //les bx, [bp+arg_6]
    memory16(_es, _bx) = 0x0005;                //mov word ptr es:[bx], 5
    goto loc_156F8;                             //jmp short loc_156F8
loc_156B8:                                      //loc_156B8:
    _FIXME_;                                    //les bx, [bp+arg_6]
    memory16(_es, _bx) = 0x0002;                //mov word ptr es:[bx], 2
    goto loc_156F8;                             //jmp short loc_156F8
loc_156C2:                                      //loc_156C2:
    _FIXME_;                                    //les bx, [bp+arg_2]
    memory16(_es, _bx) = 0x0003;                //mov word ptr es:[bx], 3
    _FIXME_;                                    //les bx, [bp+arg_6]
    memory16(_es, _bx) = 0x0003;                //mov word ptr es:[bx], 3
    goto loc_156F8;                             //jmp short loc_156F8
loc_156D4:                                      //loc_156D4:
    _FIXME_;                                    //les bx, [bp+arg_6]
    memory16(_es, _bx) = 0x0000;                //mov word ptr es:[bx], 0
    goto loc_156F8;                             //jmp short loc_156F8
loc_156DE:                                      //loc_156DE:
    _FIXME_;                                    //les bx, [bp+arg_6]
    memory16(_es, _bx) = 0x0001;                //mov word ptr es:[bx], 1
    goto loc_156F8;                             //jmp short loc_156F8
loc_156E8:                                      //loc_156E8:
    _FIXME_;                                    //les bx, [bp+arg_2]
    memory16(_es, _bx) = 0xffff;                //mov word ptr es:[bx], 0FFFFh
    _FIXME_;                                    //les bx, [bp+arg_6]
    memory16(_es, _bx) = 0xffff;                //mov word ptr es:[bx], 0FFFFh
loc_156F8:                                      //loc_156F8:
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_156FB()
{
    WORD _cs = _seg000;

    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    const int arg_2 = 6;                        //arg_2  = word ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0004;                              //sub sp, 4
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_4]
    _push(_ax);                                 //push ax
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_2]
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_cs);                                 //push cs
    sub_1566D();                                //call near ptr sub_1566D
    _sp += 0x000a;                              //add sp, 0Ah
    if (_stack16(_bp + arg_2) == 0x0000)        //jz short loc_15740
        goto loc_15740;
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    if ((short)_ax < (short)_stack16(_bp + var_2))//jl short loc_15728
        goto loc_15728;
    if ((short)_ax <= (short)_stack16(_bp + var_4))//jle short loc_15740
        goto loc_15740;
loc_15728:                                      //loc_15728:
    if ((short)_stack16(_bp + var_4) >= (short)0x0000)
        goto loc_15736;
    memory16(_ds, 0xA9E) = 0xfff1;              //mov word_1913E, 0FFF1h
    goto loc_1573C;                             //jmp short loc_1573C
loc_15736:                                      //loc_15736:
    memory16(_ds, 0xA9E) = 0xfff6;              //mov word_1913E, 0FFF6h
loc_1573C:                                      //loc_1573C:
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_15743;                             //jmp short loc_15743
loc_15740:                                      //loc_15740:
    _ax = 0x0001;                               //mov ax, 1
loc_15743:                                      //loc_15743:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _stackReduce(4);                            //retn 4
    return;
}

void loc_15776()
{
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_15779()
{
    WORD _cs = _seg000;

    memory16(_ds, 0x418) = _cs;                 //mov word ptr dword_18AB6+2, cs
    memory16(_ds, 0x416) = 0x53b5;              //mov word ptr dword_18AB6, 53B5h
    memory16(_ds, 0x414) = _cs;                 //mov word ptr dword_18AB2+2, cs
    memory16(_ds, 0x412) = 0x53b5;              //mov word ptr dword_18AB2, 53B5h
    memory16(_ds, 0x5F9) = 0x0000;              //mov word ptr dword_18C97+2, 0
    memory16(_ds, 0x5F7) = 0x0000;              //mov word ptr dword_18C97, 0
    memory16(_ds, 0x607) = 0x0000;              //mov word_18CA7, 0
    memory16(_ds, 0x605) = 0x0000;              //mov word_18CA5, 0
    memory16(_ds, 0x5FD) = 0x0000;              //mov word_18C9D, 0
    memory16(_ds, 0x5FB) = 0x0000;              //mov word_18C9B, 0
    memory16(_ds, 0x603) = 0x0000;              //mov word_18CA3, 0
    memory16(_ds, 0x601) = 0x0000;              //mov word_18CA1, 0
    memory16(_ds, 0xB5F) = 0x0000;              //mov word ptr dword_191FD+2, 0
    memory16(_ds, 0xB5D) = 0x0000;              //mov word ptr dword_191FD, 0
    memory16(_ds, 0xB61) = 0x0000;              //mov word_19201, 0
    memory16(_ds, 0x61A) = 0x0000;              //mov word_18CBA, 0
    memory16(_ds, 0x616) = 0x0000;              //mov word_18CB6, 0
}

void sub_157FD()
{
    const int var_64 = -100;                    //var_64  = byte ptr -64h
    const int arg_0 = 4;                        //arg_0  = word ptr  4
    const int arg_2 = 6;                        //arg_2  = dword ptr  6
    const int arg_6 = 10;                       //arg_6  = word ptr  0Ah
    const int arg_8 = 12;                       //arg_8  = word ptr  0Ch
    const int arg_A = 14;                       //arg_A  = word ptr  0Eh
    const int arg_C = 16;                       //arg_C  = word ptr  10h
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0064;                              //sub sp, 64h
    _FIXME_;                                    //les bx, [bp+arg_2]
    memory16(_es, _bx) = 0x0000;                //mov word ptr es:[bx], 0
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_64]
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_C));               //push [bp+arg_C]
    _push(_stack16(_bp + arg_A));               //push [bp+arg_A]
    _push(_stack16(_bp + arg_8));               //push [bp+arg_8]
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    sub_1517A();                                //call sub_1517A
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_64]
    _push(_ax);                                 //push ax
    _push(memory16(_ds, _bp + arg_4));          //push word ptr [bp+arg_2+2]
    _push(memory16(_ds, _bp + arg_2));          //push word ptr [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    sub_151C1();                                //call sub_151C1
    memory16(_ds, 0xA9E) = _ax;                 //mov word_1913E, ax
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_1583C
        goto loc_1583C;
    _ax = 0x0001;                               //mov ax, 1
    goto loc_1583E;                             //jmp short loc_1583E
loc_1583C:                                      //loc_1583C:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_1583E:                                      //loc_1583E:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _stackReduce(14);                           //retn 0Eh
    return;
}

void sub_15844()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = word ptr  0Ah
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _si = _stack16(_bp + arg_4);                //mov si, [bp+arg_4]
    _push(_ds);                                 //push ds
    _ax = 0x0501;                               //mov ax, 501h
    _push(_ax);                                 //push ax
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 1588);            //mov ax, [bx+634h]
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x0941;                               //mov ax, 941h
    _push(_ax);                                 //push ax
    sub_1517A();                                //call sub_1517A
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _dx = memory16(_ds, _bx + 1566);            //mov dx, [bx+61Eh]
    _ax = memory16(_ds, _bx + 1564);            //mov ax, [bx+61Ch]
    memory16(_ds, 0x418) = _dx;                 //mov word ptr dword_18AB6+2, dx
    memory16(_ds, 0x416) = _ax;                 //mov word ptr dword_18AB6, ax
    _dx |= _ax;                                 //or dx, ax
    if (_dx == 0)                               //jz short loc_15892
        goto loc_15892;
    memory16(_ds, 0x5FD) = 0x0000;              //mov word_18C9D, 0
    memory16(_ds, 0x5FB) = 0x0000;              //mov word_18C9B, 0
    memory16(_ds, 0x5FF) = 0x0000;              //mov word_18C9F, 0
    goto loc_1593B;                             //jmp loc_1593B
loc_15892:                                      //loc_15892:
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_ds);                                 //push ds
    _ax = 0x0501;                               //mov ax, 501h
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x05ff;                               //mov ax, 5FFh
    _push(_ax);                                 //push ax
    _ax = 0xfffc;                               //mov ax, 0FFFCh
    _push(_ax);                                 //push ax
    sub_157FD();                                //call sub_157FD
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_158C6
        goto loc_158C6;
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x0501;                               //mov ax, 501h
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x05ff;                               //mov ax, 5FFh
    _push(_ax);                                 //push ax
    _ax = 0xfffc;                               //mov ax, 0FFFCh
    _push(_ax);                                 //push ax
    sub_157FD();                                //call sub_157FD
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_15922
        goto loc_15922;
loc_158C6:                                      //loc_158C6:
    _push(memory16(_ds, 0x5FF));                //push word_18C9F
    _push(_ds);                                 //push ds
    _ax = 0x05fb;                               //mov ax, 5FBh
    _push(_ax);                                 //push ax
    sub_153D8();                                //call sub_153D8
    _sp = _bp;                                  //mov sp, bp
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_158E3
        goto loc_158E3;
    sub_151B8();                                //call sub_151B8
    memory16(_ds, 0xA9E) = 0xfffb;              //mov word_1913E, 0FFFBh
    goto loc_15922;                             //jmp short loc_15922
loc_158E3:                                      //loc_158E3:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(memory16(_ds, 0x5FF));                //push word_18C9F
    _push(memory16(_ds, 0x5FD));                //push word_18C9D
    _push(memory16(_ds, 0x5FB));                //push word_18C9B
    sub_15208();                                //call sub_15208
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_15914
        goto loc_15914;
    _push(memory16(_ds, 0x5FD));                //push word_18C9D
    _push(memory16(_ds, 0x5FB));                //push word_18C9B
    _push(_cs);                                 //push cs
    sub_1547D();                                //call near ptr sub_1547D
    _sp = _bp;                                  //mov sp, bp
    if (_ax == _si)                             //jz short loc_15926
        goto loc_15926;
    sub_151B8();                                //call sub_151B8
    memory16(_ds, 0xA9E) = 0xfffc;              //mov word_1913E, 0FFFCh
loc_15914:                                      //loc_15914:
    _push(memory16(_ds, 0x5FF));                //push word_18C9F
    _push(_ds);                                 //push ds
    _ax = 0x05fb;                               //mov ax, 5FBh
    _push(_ax);                                 //push ax
    sub_15409();                                //call sub_15409
    _sp = _bp;                                  //mov sp, bp
loc_15922:                                      //loc_15922:
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_1593E;                             //jmp short loc_1593E
loc_15926:                                      //loc_15926:
    _bx = _si;                                  //mov bx, si
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _les(_bx, _ds, _bx + 1564);                 //les bx, [bx+61Ch]
    memory16(_ds, 0x418) = _es;                 //mov word ptr dword_18AB6+2, es
    memory16(_ds, 0x416) = _bx;                 //mov word ptr dword_18AB6, bx
    sub_151B8();                                //call sub_151B8
loc_1593B:                                      //loc_1593B:
    _ax = 0x0001;                               //mov ax, 1
loc_1593E:                                      //loc_1593E:
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
    _stackReduce(6);                            //retn 6
    return;
}

void sub_15943()
{
    WORD _cs = _seg000;

    _push(_si);                                 //push si
    _ax = memory16(_ds, 0xAC3);                 //mov ax, word_19163
    _ax -= 1;                                   //dec ax
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _bx = _bx + memory16(_ds, 0xB4F);           //add bx, word_191EF
    _al = memory(_ds, _bx + 1600);              //mov al, [bx+640h]
    _ah = 0x00;                                 //mov ah, 0
    _si = _ax;                                  //mov si, ax
    _ax = memory16(_ds, 0xAC3);                 //mov ax, word_19163
    _ax -= 0x0003;                              //sub ax, 3
    if (_ax > 0x0002)                           //ja short loc_159BD
        goto loc_159BD;
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    switch (_bx)                                //jmp cs:off_1596F[bx]
    {
      case 0: goto loc_15989;
      case 2: goto loc_159A3;
      case 4: goto loc_15975;
      default:
        _ASSERT(0);
    }
loc_15975:                                      //loc_15975:
    _bx = 0x0b3e;                               //mov bx, 0B3Eh
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _bx = 0x06eb;                               //mov bx, 6EBh
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _cx = 0x0011;                               //mov cx, 11h
    _push(_cs);                                 //push cs
    sub_1466C();                                //call near ptr sub_1466C
    goto loc_159EB;                             //jmp short loc_159EB
    _STOP_("db 90h");                           //db 90h
loc_15989:                                      //loc_15989:
    if (memory16(_ds, 0xB4F) == 0x0001)         //jz short loc_159DA
        goto loc_159DA;
loc_15990:                                      //loc_15990:
    _bx = 0x0b3e;                               //mov bx, 0B3Eh
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _bx = 0x06da;                               //mov bx, 6DAh
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _cx = 0x0011;                               //mov cx, 11h
    _push(_cs);                                 //push cs
    sub_1466C();                                //call near ptr sub_1466C
    goto loc_159EB;                             //jmp short loc_159EB
loc_159A3:                                      //loc_159A3:
    if (memory16(_ds, 0xB4F) != 0x0001)         //jnz short loc_15990
        goto loc_15990;
    _bx = 0x0b3e;                               //mov bx, 0B3Eh
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _bx = 0x06c9;                               //mov bx, 6C9h
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _cx = 0x0011;                               //mov cx, 11h
    _push(_cs);                                 //push cs
    sub_1466C();                                //call near ptr sub_1466C
    goto loc_159EB;                             //jmp short loc_159EB
loc_159BD:                                      //loc_159BD:
    if (_si == 0x0001)                          //jz short loc_159C7
        goto loc_159C7;
    if (_si != 0x0004)                          //jnz short loc_159DA
        goto loc_159DA;
loc_159C7:                                      //loc_159C7:
    _bx = 0x0b3e;                               //mov bx, 0B3Eh
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _bx = 0x06fc;                               //mov bx, 6FCh
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _cx = 0x0011;                               //mov cx, 11h
    _push(_cs);                                 //push cs
    sub_1466C();                                //call near ptr sub_1466C
    goto loc_159EB;                             //jmp short loc_159EB
loc_159DA:                                      //loc_159DA:
    _bx = 0x0b3e;                               //mov bx, 0B3Eh
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _bx = 0x06b8;                               //mov bx, 6B8h
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _cx = 0x0011;                               //mov cx, 11h
    _push(_cs);                                 //push cs
    sub_1466C();                                //call near ptr sub_1466C
loc_159EB:                                      //loc_159EB:
    _ax = _si;                                  //mov ax, si
    memory(_ds, 0xB3E) = _al;                   //mov byte_191DE, al
    _si = _pop();                               //pop si
}

void sub_159F2()
{
    WORD _cs = _seg000;

    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    if (memory16(_ds, 0x616) != 0x0000)         //jnz short loc_15A04
        goto loc_15A04;
    _push(_cs);                                 //push cs
    sub_153B5();                                //call near ptr sub_153B5
loc_15A04:                                      //loc_15A04:
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _push(memory16(_ds, 0xB2D));                //push word_191CD
    _push(memory16(_ds, 0xB2B));                //push word_191CB
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_15D98();                                //call near ptr sub_15D98
    _sp += 0x000a;                              //add sp, 0Ah
    sub_15943();                                //call sub_15943
    if (memory(_ds, 0xB3E) == 0x01)             //jz short loc_15A2D
        goto loc_15A2D;
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_16197();                                //call near ptr sub_16197
    _cx = _pop();                               //pop cx
loc_15A2D:                                      //loc_15A2D:
    memory(_ds, 0x60F) = 0x00;                  //mov byte_18CAF, 0
    _push(_cs);                                 //push cs
    sub_162FA();                                //call near ptr sub_162FA
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_16B04();                                //call near ptr sub_16B04
    _cx = _pop();                               //pop cx
    _push(_cs);                                 //push cs
    sub_162FA();                                //call near ptr sub_162FA
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x070d;                               //mov ax, 70Dh
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_1608C();                                //call near ptr sub_1608C
    _sp += 0x0006;                              //add sp, 6
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_1666C();                                //call near ptr sub_1666C
    _sp += 0x0008;                              //add sp, 8
    _push(_cs);                                 //push cs
    sub_162FA();                                //call near ptr sub_162FA
    _push(_ax);                                 //push ax
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_16035();                                //call near ptr sub_16035
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_15F8B();                                //call near ptr sub_15F8B
    _sp += 0x0006;                              //add sp, 6
    _ax = 0x0001;                               //mov ax, 1
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_1647D();                                //call near ptr sub_1647D
    _sp += 0x0006;                              //add sp, 6
    _ax = 0x0002;                               //mov ax, 2
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_1643D();                                //call near ptr sub_1643D
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_15E9E();                                //call near ptr sub_15E9E
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_15AA2()
{
    WORD _cs = _seg000;

    const int var_8 = -8;                       //var_8  = dword ptr -8
    const int var_4 = -4;                       //var_4  = dword ptr -4
    const int arg_0 = 12;                       //arg_0  = dword ptr  0Ch
    const int arg_4 = 16;                       //arg_4  = dword ptr  10h
    const int arg_8 = 20;                       //arg_8  = word ptr  14h
    const int arg_A = 22;                       //arg_A  = word ptr  16h
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x0008;                              //sub sp, 8
    memory16(_ds, _bp + arg_6) = _cs;           //mov word ptr [bp+var_4+2], cs
    memory16(_ds, _bp + arg_4) = 0x6f70;        //mov word ptr [bp+var_4], 6F70h
    _FIXME_;                                    //les bx, [bp+var_4]
    _dx = memory16(_es, _bx);                   //mov dx, es:[bx]
    _dx += _bx;                                 //add dx, bx
    _cx = 0x0004;                               //mov cx, 4
    _dx >>= _cl;                                //shr dx, cl
    _ax = _cs;                                  //mov ax, cs
    _dx += _ax;                                 //add dx, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, 0x414) = _dx;                 //mov word ptr dword_18AB2+2, dx
    memory16(_ds, 0x412) = _ax;                 //mov word ptr dword_18AB2, ax
    _FIXME_;                                    //les bx, [bp+arg_0]
    _push(memory16(_es, _bx));                  //push word ptr es:[bx]
    _FIXME_;                                    //les bx, [bp+arg_4]
    _push(memory16(_es, _bx));                  //push word ptr es:[bx]
    sub_156FB();                                //call sub_156FB
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_15AE8
        goto loc_15AE8;
    goto loc_15B8E;                             //jmp loc_15B8E
loc_15AE8:                                      //loc_15AE8:
    _push(memory16(_ds, _bp + arg_6));          //push word ptr [bp+arg_4+2]
    _push(memory16(_ds, _bp + arg_4));          //push word ptr [bp+arg_4]
    _push(memory16(_ds, _bp + arg_2));          //push word ptr [bp+arg_0+2]
    _push(memory16(_ds, _bp + arg_0));          //push word ptr [bp+arg_0]
    _push(_ds);                                 //push ds
    _ax = 0x0b3c;                               //mov ax, 0B3Ch
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_168AB();                                //call near ptr sub_168AB
    _sp += 0x000c;                              //add sp, 0Ch
    _FIXME_;                                    //les bx, [bp+arg_0]
    if ((short)memory16(_es, _bx) >= (short)0x0000)//jge short loc_15B17
        goto loc_15B17;
    memory16(_ds, 0xA9E) = 0xfffe;              //mov word_1913E, 0FFFEh
    memory16(_es, _bx) = 0xfffe;                //mov word ptr es:[bx], 0FFFEh
    goto loc_15BF3;                             //jmp loc_15BF3
loc_15B17:                                      //loc_15B17:
    _FIXME_;                                    //les bx, [bp+arg_0]
    _ax = memory16(_es, _bx);                   //mov ax, es:[bx]
    memory16(_ds, 0xAC3) = _ax;                 //mov word_19163, ax
    _FIXME_;                                    //les bx, [bp+arg_4]
    _ax = memory16(_es, _bx);                   //mov ax, es:[bx]
    memory16(_ds, 0xB4F) = _ax;                 //mov word_191EF, ax
    _ax = _stack16(_bp + arg_8);                //mov ax, [bp+arg_8]
    _ax = _ax | _stack16(_bp + arg_A);          //or ax, [bp+arg_A]
    if (_ax != 0)                               //jnz short loc_15B38
        goto loc_15B38;
    memory(_ds, 0x50E) = 0x00;                  //mov byte_18BAE, 0
    goto loc_15B7E;                             //jmp short loc_15B7E
loc_15B38:                                      //loc_15B38:
    _push(_ds);                                 //push ds
    _ax = 0x050e;                               //mov ax, 50Eh
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_A));               //push [bp+arg_A]
    _push(_stack16(_bp + arg_8));               //push [bp+arg_8]
    sub_15140();                                //call sub_15140
    if (memory(_ds, 0x50E) == 0x00)             //jz short loc_15B7E
        goto loc_15B7E;
    _push(_ds);                                 //push ds
    _ax = 0x050e;                               //mov ax, 50Eh
    _push(_ax);                                 //push ax
    sub_1515F();                                //call sub_1515F
    memory16(_ds, _bp + arg_10) = _dx;          //mov word ptr [bp+var_8+2], dx
    memory16(_ds, _bp + arg_8) = _ax;           //mov word ptr [bp+var_8], ax
    _FIXME_;                                    //les bx, [bp+var_8]
    _bx -= 1;                                   //dec bx
    if (memory(_es, _bx) == 0x3a)               //jz short loc_15B7E
        goto loc_15B7E;
    _bx = _ax;                                  //mov bx, ax
    _bx -= 1;                                   //dec bx
    if (memory(_es, _bx) == 0x5c)               //jz short loc_15B7E
        goto loc_15B7E;
    _bx = _ax;                                  //mov bx, ax
    memory(_es, _bx) = 0x5c;                    //mov byte ptr es:[bx], 5Ch
    memory16(_ds, _bp + arg_8) += 1;            //inc word ptr [bp+var_8]
    _bx = memory16(_ds, _bp + arg_8);           //mov bx, word ptr [bp+var_8]
    memory(_es, _bx) = 0x00;                    //mov byte ptr es:[bx], 0
loc_15B7E:                                      //loc_15B7E:
    _push(memory16(_ds, 0xB3C));                //push word_191DC
    _push(_ds);                                 //push ds
    _ax = 0x050e;                               //mov ax, 50Eh
    _push(_ax);                                 //push ax
    sub_15844();                                //call sub_15844
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_15B9A
        goto loc_15B9A;
loc_15B8E:                                      //loc_15B8E:
    _ax = memory16(_ds, 0xA9E);                 //mov ax, word_1913E
    _FIXME_;                                    //les bx, [bp+arg_0]
    memory16(_es, _bx) = _ax;                   //mov es:[bx], ax
    goto loc_15BF3;                             //jmp short loc_15BF3
loc_15B9A:                                      //loc_15B9A:
    _push(_cs);                                 //push cs
    sub_166F1();                                //call near ptr sub_166F1
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _di = 0x0b29;                               //mov di, 0B29h
    _si = memory16(_ds, 0x609);                 //mov si, word ptr dword_18CA9
    _ds = memory16(_ds, 0x60B);                 //mov ds, word ptr dword_18CA9+2
    _cx = 0x0013;                               //mov cx, 13h
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = 0x0b51;                               //mov di, 0B51h
    _cx = 0x0016;                               //mov cx, 16h
    _al = _al ^ _al;                            //xor al, al
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _ax = _es;                                  //mov ax, es
    _ds = _ax;                                  //mov ds, ax
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _push(memory16(_ds, 0x55F));                //push word_18BFF
    _push(_ds);                                 //push ds
    _ax = 0x0b5d;                               //mov ax, 0B5Dh
    _push(_ax);                                 //push ax
    sub_153D8();                                //call sub_153D8
    _sp += 0x0006;                              //add sp, 6
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_15BF8
        goto loc_15BF8;
    memory16(_ds, 0xA9E) = 0xfffb;              //mov word_1913E, 0FFFBh
    _FIXME_;                                    //les bx, [bp+arg_0]
    memory16(_es, _bx) = 0xfffb;                //mov word ptr es:[bx], 0FFFBh
    _push(memory16(_ds, 0x5FF));                //push word_18C9F
    _push(_ds);                                 //push ds
    _ax = 0x05fb;                               //mov ax, 5FBh
    _push(_ax);                                 //push ax
    sub_15409();                                //call sub_15409
    _sp += 0x0006;                              //add sp, 6
loc_15BF3:                                      //loc_15BF3:
    sub_15779();                                //call sub_15779
    goto loc_15C2F;                             //jmp short loc_15C2F
loc_15BF8:                                      //loc_15BF8:
    _les(_bx, _ds, 0xB5D);                      //les bx, dword_191FD
    memory16(_ds, 0x603) = _es;                 //mov word_18CA3, es
    memory16(_ds, 0x601) = _bx;                 //mov word_18CA1, bx
    _ax = memory16(_ds, 0x55F);                 //mov ax, word_18BFF
    memory16(_ds, 0xB61) = _ax;                 //mov word_19201, ax
    memory16(_ds, 0xB65) = _ds;                 //mov word_19205, ds
    memory16(_ds, 0xB63) = 0x0a9e;              //mov word_19203, 0A9Eh
    _push(_ds);                                 //push ds
    _ax = 0x0b51;                               //mov ax, 0B51h
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_16940();                                //call near ptr sub_16940
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
    memory16(_ds, 0x616) = 0x0001;              //mov word_18CB6, 1
    _push(_cs);                                 //push cs
    sub_159F2();                                //call near ptr sub_159F2
    memory16(_ds, 0xA9E) = 0x0000;              //mov word_1913E, 0
loc_15C2F:                                      //loc_15C2F:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void loc_15C58()
{
    WORD _cs = _seg000;

    _ax = memory16(_ds, 0x5F7);                 //mov ax, word ptr dword_18C97
    _ax = _ax | memory16(_ds, 0x5F9);           //or ax, word ptr dword_18C97+2
    if (_ax == 0)                               //jz short loc_15C79
        goto loc_15C79;
    _les(_bx, _ds, 0x5F7);                      //les bx, dword_18C97
    memory16(_ds, 0x414) = _es;                 //mov word ptr dword_18AB2+2, es
    memory16(_ds, 0x412) = _bx;                 //mov word ptr dword_18AB2, bx
    memory16(_ds, 0x5F9) = 0x0000;              //mov word ptr dword_18C97+2, 0
    memory16(_ds, 0x5F7) = 0x0000;              //mov word ptr dword_18C97, 0
loc_15C79:                                      //loc_15C79:
    _ax = _stack16(_bp + 12);                   //mov ax, [bp+0Ch]
    memory16(_ds, 0xB4F) = _ax;                 //mov word_191EF, ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_1674D();                                //call near ptr sub_1674D
    _cx = _pop();                               //pop cx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _di = 0x0b29;                               //mov di, 0B29h
    _si = memory16(_ds, 0x609);                 //mov si, word ptr dword_18CA9
    _ds = memory16(_ds, 0x60B);                 //mov ds, word ptr dword_18CA9+2
    _cx = 0x0013;                               //mov cx, 13h
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ax = _es;                                  //mov ax, es
    _ds = _ax;                                  //mov ds, ax
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _push(_cs);                                 //push cs
    sub_159F2();                                //call near ptr sub_159F2
loc_15CA4:                                      //loc_15CA4:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    return;                                     //retf
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _ax = memory16(_ds, 0xB4F);                 //mov ax, word_191EF
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_15CB6()
{
    WORD _cs = _seg000;

    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_cs);                                 //push cs
    sub_16781();                                //call near ptr sub_16781
    _ax = memory16(_ds, 0x5F7);                 //mov ax, word ptr dword_18C97
    _ax = _ax | memory16(_ds, 0x5F9);           //or ax, word ptr dword_18C97+2
    if (_ax != 0)                               //jnz short loc_15CE0
        goto loc_15CE0;
    _les(_bx, _ds, 0x412);                      //les bx, dword_18AB2
    memory16(_ds, 0x5F9) = _es;                 //mov word ptr dword_18C97+2, es
    memory16(_ds, 0x5F7) = _bx;                 //mov word ptr dword_18C97, bx
    memory16(_ds, 0x414) = _cs;                 //mov word ptr dword_18AB2+2, cs
    memory16(_ds, 0x412) = 0x53b5;              //mov word ptr dword_18AB2, 53B5h
loc_15CE0:                                      //loc_15CE0:
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_15CE3()
{
    WORD _cs = _seg000;

    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    if (memory16(_ds, 0x616) != 0x0000)         //jnz short loc_15CF6
        goto loc_15CF6;
    goto loc_15D7B;                             //jmp loc_15D7B
loc_15CF6:                                      //loc_15CF6:
    _push(_cs);                                 //push cs
    sub_15CB6();                                //call near ptr sub_15CB6
    _push(memory16(_ds, 0x55F));                //push word_18BFF
    _push(_ds);                                 //push ds
    _ax = 0x0601;                               //mov ax, 601h
    _push(_ax);                                 //push ax
    sub_15409();                                //call sub_15409
    _sp += 0x0006;                              //add sp, 6
    _ax = memory16(_ds, 0x5FB);                 //mov ax, word_18C9B
    _ax = _ax | memory16(_ds, 0x5FD);           //or ax, word_18C9D
    if (_ax == 0)                               //jz short loc_15D35
        goto loc_15D35;
    _push(memory16(_ds, 0x5FF));                //push word_18C9F
    _push(_ds);                                 //push ds
    _ax = 0x05fb;                               //mov ax, 5FBh
    _push(_ax);                                 //push ax
    sub_15409();                                //call sub_15409
    _sp += 0x0006;                              //add sp, 6
    _bx = memory16(_ds, 0xB3C);                 //mov bx, word_191DC
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 1566) = 0x0000;         //mov word ptr [bx+61Eh], 0
    memory16(_ds, _bx + 1564) = 0x0000;         //mov word ptr [bx+61Ch], 0
loc_15D35:                                      //loc_15D35:
    sub_15779();                                //call sub_15779
    _di = _di ^ _di;                            //xor di, di
    _si = 0x0561;                               //mov si, 561h
    goto loc_15D76;                             //jmp short loc_15D76
loc_15D3F:                                      //loc_15D3F:
    if (memory(_ds, _si + 10) == 0x00)          //jz short loc_15D72
        goto loc_15D72;
    if (memory16(_ds, _si + 8) == 0x0000)       //jz short loc_15D72
        goto loc_15D72;
    _push(memory16(_ds, _si + 8));              //push word ptr [si+8]
    _ax = _si;                                  //mov ax, si
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    sub_15409();                                //call sub_15409
    _sp += 0x0006;                              //add sp, 6
    memory16(_ds, _si + 2) = 0x0000;            //mov word ptr [si+2], 0
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
    memory16(_ds, _si + 6) = 0x0000;            //mov word ptr [si+6], 0
    memory16(_ds, _si + 4) = 0x0000;            //mov word ptr [si+4], 0
    memory16(_ds, _si + 8) = 0x0000;            //mov word ptr [si+8], 0
loc_15D72:                                      //loc_15D72:
    _di += 1;                                   //inc di
    _si += 0x000f;                              //add si, 0Fh
loc_15D76:                                      //loc_15D76:
    if (_di < 0x000a)                           //jb short loc_15D3F
        goto loc_15D3F;
loc_15D7B:                                      //loc_15D7B:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void sub_15D80()
{
    WORD _cs = _seg000;

    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_cs);                                 //push cs
    sub_16965();                                //call sub_16965
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_15E9E();                                //call near ptr sub_15E9E
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_15D98()
{
    WORD _cs = _seg000;

    const int arg_0 = 12;                       //arg_0  = word ptr  0Ch
    const int arg_2 = 14;                       //arg_2  = word ptr  0Eh
    const int arg_4 = 16;                       //arg_4  = word ptr  10h
    const int arg_6 = 18;                       //arg_6  = word ptr  12h
    const int arg_8 = 20;                       //arg_8  = word ptr  14h
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _di = _stack16(_bp + arg_2);                //mov di, [bp+arg_2]
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    _si |= _si;                                 //or si, si
    if ((short)_si < (short))                   //jl short loc_15DD1
        goto loc_15DD1;
    _di |= _di;                                 //or di, di
    if ((short)_di < (short))                   //jl short loc_15DD1
        goto loc_15DD1;
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    if (_ax > memory16(_ds, 0xB2B))             //ja short loc_15DD1
        goto loc_15DD1;
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    if (_ax > memory16(_ds, 0xB2D))             //ja short loc_15DD1
        goto loc_15DD1;
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    if ((short)_ax < (short)_si)                //jl short loc_15DD1
        goto loc_15DD1;
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    if ((short)_ax >= (short)_di)               //jge short loc_15DD9
        goto loc_15DD9;
loc_15DD1:                                      //loc_15DD1:
    memory16(_ds, 0xA9E) = 0xfff5;              //mov word_1913E, 0FFF5h
    goto loc_15E0C;                             //jmp short loc_15E0C
loc_15DD9:                                      //loc_15DD9:
    memory16(_ds, 0xA94) = _si;                 //mov word_19134, si
    memory16(_ds, 0xA96) = _di;                 //mov word_19136, di
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    memory16(_ds, 0xA98) = _ax;                 //mov word_19138, ax
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    memory16(_ds, 0xA9A) = _ax;                 //mov word_1913A, ax
    _ax = _stack16(_bp + arg_8);                //mov ax, [bp+arg_8]
    memory16(_ds, 0xA9C) = _ax;                 //mov word_1913C, ax
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_cs);                                 //push cs
    sub_16721();                                //call near ptr sub_16721
    _sp = _bp;                                  //mov sp, bp
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_15E9E();                                //call near ptr sub_15E9E
    _sp = _bp;                                  //mov sp, bp
loc_15E0C:                                      //loc_15E0C:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void loc_15E83()
{
    WORD _cs = _seg000;

    _push(_FIXME_);                             //push word ptr [bp-2]
    _push(_FIXME_);                             //push word ptr [bp-4]
    _push(_cs);                                 //push cs
    sub_16035();                                //call near ptr sub_16035
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
loc_15E8F:                                      //loc_15E8F:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_15E9E();                                //call near ptr sub_15E9E
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_15E9E()
{
    WORD _cs = _seg000;

    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_cs);                                 //push cs
    sub_1697C();                                //call near ptr sub_1697C
    _sp = _bp;                                  //mov sp, bp
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    memory16(_ds, 0x612) = _ax;                 //mov word_18CB2, ax
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    memory16(_ds, 0x614) = _ax;                 //mov word_18CB4, ax
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_15F8B()
{
    WORD _cs = _seg000;

    const int arg_0 = 12;                       //arg_0  = word ptr  0Ch
    const int arg_2 = 14;                       //arg_2  = word ptr  0Eh
    const int arg_4 = 16;                       //arg_4  = word ptr  10h
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _di = _stack16(_bp + arg_4);                //mov di, [bp+arg_4]
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    if (_si > 0x0004)                           //ja short loc_15FA6
        goto loc_15FA6;
    if (_di <= 0x0003)                          //jbe short loc_15FAE
        goto loc_15FAE;
loc_15FA6:                                      //loc_15FA6:
    memory16(_ds, 0xA9E) = 0xfff5;              //mov word_1913E, 0FFF5h
    goto loc_15FC5;                             //jmp short loc_15FC5
loc_15FAE:                                      //loc_15FAE:
    memory16(_ds, 0xB67) = _si;                 //mov word_19207, si
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    memory16(_ds, 0xB69) = _ax;                 //mov word_19209, ax
    memory16(_ds, 0xB6B) = _di;                 //mov word_1920B, di
    _push(_di);                                 //push di
    _push(_ax);                                 //push ax
    _push(_si);                                 //push si
    _push(_cs);                                 //push cs
    sub_16BA4();                                //call near ptr sub_16BA4
    _sp = _bp;                                  //mov sp, bp
loc_15FC5:                                      //loc_15FC5:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void sub_15FCA()
{
    WORD _cs = _seg000;

    const int arg_0 = 12;                       //arg_0  = word ptr  0Ch
    const int arg_2 = 14;                       //arg_2  = word ptr  0Eh
    const int arg_4 = 16;                       //arg_4  = word ptr  10h
    const int arg_6 = 18;                       //arg_6  = word ptr  12h
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _di = _stack16(_bp + arg_2);                //mov di, [bp+arg_2]
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    _push(_di);                                 //push di
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_cs);                                 //push cs
    sub_169B6();                                //call near ptr sub_169B6
    _sp = _bp;                                  //mov sp, bp
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_di);                                 //push di
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_cs);                                 //push cs
    sub_169B6();                                //call near ptr sub_169B6
    _sp = _bp;                                  //mov sp, bp
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    _push(_si);                                 //push si
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_cs);                                 //push cs
    sub_169B6();                                //call near ptr sub_169B6
    _sp = _bp;                                  //mov sp, bp
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    _push(_si);                                 //push si
    _push(_cs);                                 //push cs
    sub_169B6();                                //call near ptr sub_169B6
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void sub_16035()
{
    WORD _cs = _seg000;

    const int arg_0 = 12;                       //arg_0  = word ptr  0Ch
    const int arg_2 = 14;                       //arg_2  = word ptr  0Eh
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _di = _stack16(_bp + arg_2);                //mov di, [bp+arg_2]
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    if (_si > 0x000b)                           //ja short loc_1604F
        goto loc_1604F;
    _di |= _di;                                 //or di, di
    if ((short)_di >= 0)                        //jge short loc_16057
        goto loc_16057;
loc_1604F:                                      //loc_1604F:
    memory16(_ds, 0xA9E) = 0xfff5;              //mov word_1913E, 0FFF5h
    goto loc_16067;                             //jmp short loc_16067
loc_16057:                                      //loc_16057:
    memory16(_ds, 0xAAE) = _si;                 //mov word_1914E, si
    memory16(_ds, 0xAB0) = _di;                 //mov word_19150, di
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_cs);                                 //push cs
    sub_16C12();                                //call near ptr sub_16C12
    _sp = _bp;                                  //mov sp, bp
loc_16067:                                      //loc_16067:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void sub_1608C()
{
    WORD _cs = _seg000;

    const int arg_0 = 12;                       //arg_0  = dword ptr  0Ch
    const int arg_4 = 16;                       //arg_4  = word ptr  10h
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _push(_cs);                                 //push cs
    sub_162FA();                                //call near ptr sub_162FA
    if (_ax >= _stack16(_bp + arg_4))           //jnb short loc_160A8
        goto loc_160A8;
    memory16(_ds, 0xA9E) = 0xfff5;              //mov word_1913E, 0FFF5h
    goto loc_160D9;                             //jmp short loc_160D9
loc_160A8:                                      //loc_160A8:
    memory16(_ds, 0xAAE) = 0x000c;              //mov word_1914E, 0Ch
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    memory16(_ds, 0xAB0) = _ax;                 //mov word_19150, ax
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _FIXME_;                                    //lds si, [bp+arg_0]
    _ax = _ds;                                  //mov ax, ds
    _es = _ax;                                  //mov es, ax
    _di = 0x0b6d;                               //mov di, 0B6Dh
    _cx = 0x0008;                               //mov cx, 8
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ds = _ax;                                  //mov ds, ax
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(memory16(_ds, _bp + arg_2));          //push word ptr [bp+arg_0+2]
    _push(memory16(_ds, _bp + arg_0));          //push word ptr [bp+arg_0]
    _push(_cs);                                 //push cs
    sub_16809();                                //call near ptr sub_16809
    _sp = _bp;                                  //mov sp, bp
loc_160D9:                                      //loc_160D9:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void sub_160DE()
{
    WORD _cs = _seg000;

    const int arg_0 = 4;                        //arg_0  = word ptr  4
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _dx = _dx ^ _dx;                            //xor dx, dx
    _ax = 0x2710;                               //mov ax, 2710h
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _dx = _dx ^ _dx;                            //xor dx, dx
    _bx = memory16(_ds, 0xB37);                 //mov bx, word_191D7
    _cx = _cx ^ _cx;                            //xor cx, cx
    _push(_cs);                                 //push cs
    sub_1449F();                                //call near ptr sub_1449F
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_1433D();                                //call near ptr sub_1433D
    _bp = _pop();                               //pop bp
    _stackReduce(2);                            //retn 2
    return;
}

void sub_16129()
{
    WORD _cs = _seg000;

    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    sub_160DE();                                //call sub_160DE
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _ax = 0x0168;                               //mov ax, 168h
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_cs);                                 //push cs
    sub_16A7B();                                //call near ptr sub_16A7B
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_16197()
{
    WORD _cs = _seg000;

    const int arg_0 = 10;                       //arg_0  = word ptr  0Ah
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    if (_si > 0x000f)                           //ja short loc_161CA
        goto loc_161CA;
    _ax = _si;                                  //mov ax, si
    memory(_ds, 0x60F) = _al;                   //mov byte_18CAF, al
    _si |= _si;                                 //or si, si
    if (_si != 0)                               //jnz short loc_161B9
        goto loc_161B9;
    memory(_ds, 0xB3F) = 0x00;                  //mov byte_191DF, 0
    goto loc_161C0;                             //jmp short loc_161C0
loc_161B9:                                      //loc_161B9:
    _al = memory(_ds, _si + 2879);              //mov al, [si+0B3Fh]
    memory(_ds, 0xB3F) = _al;                   //mov byte_191DF, al
loc_161C0:                                      //loc_161C0:
    _al = memory(_ds, 0xB3F);                   //mov al, byte_191DF
    _cbw();                                     //cbw
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_16B25();                                //call near ptr sub_16B25
    _cx = _pop();                               //pop cx
loc_161CA:                                      //loc_161CA:
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void loc_1620D()
{
    WORD _cs = _seg000;

    _FIXME_;                                    //les bx, [bp-16h]
    _al = memory(_es, _bx);                     //mov al, es:[bx]
    _ah = 0x00;                                 //mov ah, 0
    if ((short)_ax <= (short)0x0010)            //jle short loc_16221
        goto loc_16221;
    _FIXME_ = 0x0010;                           //mov word ptr [bp-18h], 10h
    goto loc_1622C;                             //jmp short loc_1622C
loc_16221:                                      //loc_16221:
    _FIXME_;                                    //les bx, [bp-16h]
    _al = memory(_es, _bx);                     //mov al, es:[bx]
    _ah = 0x00;                                 //mov ah, 0
    _stack16(_bp + -24) = _ax;                  //mov [bp-18h], ax
loc_1622C:                                      //loc_1622C:
    _FIXME_ = 0x0000;                           //mov word ptr [bp-1Ah], 0
    goto loc_16257;                             //jmp short loc_16257
loc_16233:                                      //loc_16233:
    _FIXME_;                                    //les bx, [bp-16h]
    _bx = _bx + _stack16(_bp + -26);            //add bx, [bp-1Ah]
    _al = memory(_es, _bx + 1);                 //mov al, es:[bx+1]
    _cbw();                                     //cbw
    if ((short)_ax <= (short)0xffff)            //jle short loc_16254
        goto loc_16254;
    _bx = _stack16(_bp + -22);                  //mov bx, [bp-16h]
    _bx = _bx + _stack16(_bp + -26);            //add bx, [bp-1Ah]
    _al = memory(_es, _bx + 1);                 //mov al, es:[bx+1]
    _bx = _stack16(_bp + -26);                  //mov bx, [bp-1Ah]
    memory(_ds, _bx + 2879) = _al;              //mov [bx+0B3Fh], al
loc_16254:                                      //loc_16254:
    _FIXME_ += 1;                               //inc word ptr [bp-1Ah]
loc_16257:                                      //loc_16257:
    _ax = _stack16(_bp + -26);                  //mov ax, [bp-1Ah]
    if (_ax < _stack16(_bp + -24))              //jb short loc_16233
        goto loc_16233;
    _FIXME_;                                    //les bx, [bp-16h]
    _al = memory(_es, _bx + 1);                 //mov al, es:[bx+1]
    _cbw();                                     //cbw
    if (_ax == 0xffff)                          //jz short loc_16271
        goto loc_16271;
    memory(_ds, 0x60F) = 0x00;                  //mov byte_18CAF, 0
loc_16271:                                      //loc_16271:
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_ss);                                 //push ss
    _es = _pop();                               //pop es
    _si = 0x0b3e;                               //mov si, 0B3Eh
    _FIXME_;                                    //lea di, [bp-12h]
    _cx = 0x0011;                               //mov cx, 11h
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _al = memory(_ds, 0x618);                   //mov al, byte_18CB8
    _stack16(_bp + -1) = _al;                   //mov [bp-1], al
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp-12h]
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_16B89();                                //call near ptr sub_16B89
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
loc_16294:                                      //loc_16294:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    return;                                     //retf
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _di = _stack16(_bp + 14);                   //mov di, [bp+0Eh]
    _si = _stack16(_bp + 12);                   //mov si, [bp+0Ch]
    if (memory16(_ds, 0x616) == 0x0000)         //jz short loc_162D8
        goto loc_162D8;
    _al = memory(_ds, 0xB3E);                   //mov al, byte_191DE
    _ah = 0x00;                                 //mov ah, 0
    _ax -= 1;                                   //dec ax
    if (_ax < _si)                              //jb short loc_162D8
        goto loc_162D8;
    _di |= _di;                                 //or di, di
    if ((short)_di < (short))                   //jl short loc_162D8
        goto loc_162D8;
    _ax = _di;                                  //mov ax, di
    memory(_ds, _si + 2879) = _al;              //mov [si+0B3Fh], al
    _si |= _si;                                 //or si, si
    if (_si != 0)                               //jnz short loc_162D0
        goto loc_162D0;
    memory(_ds, 0x60F) = 0x00;                  //mov byte_18CAF, 0
loc_162D0:                                      //loc_162D0:
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_cs);                                 //push cs
    sub_16B6A();                                //call near ptr sub_16B6A
    _sp = _bp;                                  //mov sp, bp
loc_162D8:                                      //loc_162D8:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    return;                                     //retf
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _FIXME_;                                    //les bx, [bp+8]
    _push(_es);                                 //push es
    _push(_bx);                                 //push bx
    _bx = 0x0b3e;                               //mov bx, 0B3Eh
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _cx = 0x0011;                               //mov cx, 11h
    _push(_cs);                                 //push cs
    sub_1466C();                                //call near ptr sub_1466C
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_162FA()
{
    WORD _cs = _seg000;

    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    if (memory16(_ds, 0x616) == 0x0000)         //jz short loc_1631F
        goto loc_1631F;
    _ax = memory16(_ds, 0xAC3);                 //mov ax, word_19163
    _ax -= 1;                                   //dec ax
    _dx = 0x0006;                               //mov dx, 6
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    _bx = _bx + memory16(_ds, 0xB4F);           //add bx, word_191EF
    _al = memory(_ds, _bx + 1660);              //mov al, [bx+67Ch]
    _ah = 0x00;                                 //mov ah, 0
    goto loc_16321;                             //jmp short loc_16321
loc_1631F:                                      //loc_1631F:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_16321:                                      //loc_16321:
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_16324()
{
    WORD _cs = _seg000;

    const int arg_0 = 10;                       //arg_0  = word ptr  0Ah
    const int arg_2 = 12;                       //arg_2  = word ptr  0Ch
    const int arg_4 = 14;                       //arg_4  = word ptr  0Eh
    const int arg_6 = 16;                       //arg_6  = word ptr  10h
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_6));               //push [bp+arg_6]
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_cs);                                 //push cs
    sub_16859();                                //call sub_16859
    _sp = _bp;                                  //mov sp, bp
    _si = _ax;                                  //mov si, ax
    _ax = _si;                                  //mov ax, si
    if (_ax != 0xffff)                          //jnz short loc_16353
        goto loc_16353;
    memory16(_ds, 0xA9E) = 0xfff5;              //mov word_1913E, 0FFF5h
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_16355;                             //jmp short loc_16355
loc_16353:                                      //loc_16353:
    _ax = _si;                                  //mov ax, si
loc_16355:                                      //loc_16355:
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void loc_16388()
{
    WORD _cs = _seg000;

    _ax = _stack16(_bp + 12);                   //mov ax, [bp+0Ch]
    _ax = _ax + memory16(_ds, 0xA94);           //add ax, word_19134
    _ax = _ax + _stack16(_bp + -2);             //add ax, [bp-2]
    if (_ax > memory16(_ds, 0xB2B))             //ja short loc_163D0
        goto loc_163D0;
    _ax = _stack16(_bp + 12);                   //mov ax, [bp+0Ch]
    _ax = _ax + memory16(_ds, 0xA94);           //add ax, word_19134
    if ((short)_ax < (short))                   //jl short loc_163D0
        goto loc_163D0;
    _si |= _si;                                 //or si, si
    if (_si <= 0)                               //jbe short loc_163D0
        goto loc_163D0;
    _ax = _stack16(_bp + 14);                   //mov ax, [bp+0Eh]
    _ax = _ax + memory16(_ds, 0xA96);           //add ax, word_19136
    if ((short)_ax < (short))                   //jl short loc_163D0
        goto loc_163D0;
    _FIXME_;                                    //les bx, [bp+10h]
    memory16(_es, _bx + 2) = _si;               //mov es:[bx+2], si
    _push(memory16(_ds, _bp + 20));             //push word ptr [bp+14h]
    _push(memory16(_ds, _bp + 18));             //push word ptr [bp+12h]
    _push(_bx);                                 //push bx
    _push(memory16(_ds, _bp + 14));             //push word ptr [bp+0Eh]
    _push(memory16(_ds, _bp + 12));             //push word ptr [bp+0Ch]
    _push(_cs);                                 //push cs
    sub_16DB0();                                //call near ptr sub_16DB0
    _sp += 0x000a;                              //add sp, 0Ah
    _FIXME_;                                    //les bx, [bp+10h]
    memory16(_es, _bx + 2) = _di;               //mov es:[bx+2], di
loc_163D0:                                      //loc_163D0:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    return;                                     //retf
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _FIXME_;                                    //les bx, [bp+8]
    _push(_es);                                 //push es
    _push(_bx);                                 //push bx
    _bx = 0x0ab9;                               //mov bx, 0AB9h
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _cx = 0x000a;                               //mov cx, 0Ah
    _push(_cs);                                 //push cs
    sub_1466C();                                //call near ptr sub_1466C
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_163F4()
{
    WORD _cs = _seg000;

    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(memory16(_ds, 0x614));                //push word_18CB4
    _push(memory16(_ds, 0x612));                //push word_18CB2
    _push(_cs);                                 //push cs
    sub_16C42();                                //call near ptr sub_16C42
    _sp = _bp;                                  //mov sp, bp
    if (memory16(_ds, 0xABF) != 0x0000)         //jnz short loc_1643A
        goto loc_1643A;
    if (memory16(_ds, 0xABB) != 0x0000)         //jnz short loc_1643A
        goto loc_1643A;
    _push(memory16(_ds, 0x614));                //push word_18CB4
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_cs);                                 //push cs
    sub_16CE4();                                //call near ptr sub_16CE4
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
    _ax = _ax + memory16(_ds, 0x612);           //add ax, word_18CB2
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    sub_15E9E();                                //call near ptr sub_15E9E
    _sp = _bp;                                  //mov sp, bp
loc_1643A:                                      //loc_1643A:
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_1643D()
{
    WORD _cs = _seg000;

    const int arg_0 = 12;                       //arg_0  = word ptr  0Ch
    const int arg_2 = 14;                       //arg_2  = word ptr  0Eh
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _di = _stack16(_bp + arg_2);                //mov di, [bp+arg_2]
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    _si |= _si;                                 //or si, si
    if ((short)_si < (short))                   //jl short loc_16460
        goto loc_16460;
    if ((short)_si > (short)0x0002)             //jg short loc_16460
        goto loc_16460;
    _di |= _di;                                 //or di, di
    if ((short)_di < (short))                   //jl short loc_16460
        goto loc_16460;
    if ((short)_di <= (short)0x0002)            //jle short loc_16468
        goto loc_16468;
loc_16460:                                      //loc_16460:
    memory16(_ds, 0xA9E) = 0xfff5;              //mov word_1913E, 0FFF5h
    goto loc_16478;                             //jmp short loc_16478
loc_16468:                                      //loc_16468:
    memory16(_ds, 0xABF) = _si;                 //mov word_1915F, si
    memory16(_ds, 0xAC1) = _di;                 //mov word_19161, di
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_cs);                                 //push cs
    sub_1683C();                                //call near ptr sub_1683C
    _sp = _bp;                                  //mov sp, bp
loc_16478:                                      //loc_16478:
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void sub_1647D()
{
    WORD _cs = _seg000;

    const int var_C = -12;                      //var_C  = word ptr -0Ch
    const int var_A = -10;                      //var_A  = word ptr -0Ah
    const int var_8 = -8;                       //var_8  = word ptr -8
    const int var_6 = -6;                       //var_6  = word ptr -6
    const int var_4 = -4;                       //var_4  = word ptr -4
    const int var_2 = -2;                       //var_2  = word ptr -2
    const int arg_0 = 12;                       //arg_0  = word ptr  0Ch
    const int arg_2 = 14;                       //arg_2  = word ptr  0Eh
    const int arg_4 = 16;                       //arg_4  = word ptr  10h
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _sp -= 0x000c;                              //sub sp, 0Ch
    _si = _stack16(_bp + arg_0);                //mov si, [bp+arg_0]
    if ((short)_si > (short)0x000a)             //jg short loc_164AC
        goto loc_164AC;
    _si |= _si;                                 //or si, si
    if ((short)_si < (short))                   //jl short loc_164AC
        goto loc_164AC;
    _si |= _si;                                 //or si, si
    if (_si == 0)                               //jz short loc_164B5
        goto loc_164B5;
    _ax = _si;                                  //mov ax, si
    _ax -= 1;                                   //dec ax
    _dx = 0x000f;                               //mov dx, 0Fh
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    if (memory(_ds, _bx + 1387) != 0x00)        //jnz short loc_164B5
        goto loc_164B5;
loc_164AC:                                      //loc_164AC:
    memory16(_ds, 0xA9E) = 0xfff2;              //mov word_1913E, 0FFF2h
    goto loc_16642;                             //jmp loc_16642
loc_164B5:                                      //loc_164B5:
    _si |= _si;                                 //or si, si
    if (_si != 0)                               //jnz short loc_164BC
        goto loc_164BC;
    goto loc_16649;                             //jmp loc_16649
loc_164BC:                                      //loc_164BC:
    if (_si != memory16(_ds, 0xAB9))            //jnz short loc_164C5
        goto loc_164C5;
    goto loc_16649;                             //jmp loc_16649
loc_164C5:                                      //loc_164C5:
    _ax = _si;                                  //mov ax, si
    _ax -= 1;                                   //dec ax
    _dx = 0x000f;                               //mov dx, 0Fh
    _mul(_dx);                                  //mul dx
    _di = _ax;                                  //mov di, ax
    _di += 0x0561;                              //add di, 561h
    if (_si != memory16(_ds, 0x61A))            //jnz short loc_164DC
        goto loc_164DC;
    goto loc_1662F;                             //jmp loc_1662F
loc_164DC:                                      //loc_164DC:
    if (memory16(_ds, 0x61A) == 0x0000)         //jz short loc_1652E
        goto loc_1652E;
    _ax = memory16(_ds, 0x61A);                 //mov ax, word_18CBA
    _ax -= 1;                                   //dec ax
    _dx = 0x000f;                               //mov dx, 0Fh
    _mul(_dx);                                  //mul dx
    _bx = _ax;                                  //mov bx, ax
    if (memory16(_ds, _bx + 1385) == 0x0000)    //jz short loc_1652E
        goto loc_1652E;
    _ax = memory16(_ds, 0x61A);                 //mov ax, word_18CBA
    _ax -= 1;                                   //dec ax
    _dx = 0x000f;                               //mov dx, 0Fh
    _mul(_dx);                                  //mul dx
    _ax += 0x0561;                              //add ax, 561h
    _stack16(_bp + var_2) = _ax;                //mov [bp+var_2], ax
    _bx = _ax;                                  //mov bx, ax
    _push(memory16(_ds, _bx + 8));              //push word ptr [bx+8]
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    sub_15409();                                //call sub_15409
    _sp += 0x0006;                              //add sp, 6
    _bx = _stack16(_bp + var_2);                //mov bx, [bp+var_2]
    memory16(_ds, _bx + 2) = 0x0000;            //mov word ptr [bx+2], 0
    memory16(_ds, _bx) = 0x0000;                //mov word ptr [bx], 0
    memory16(_ds, _bx + 6) = 0x0000;            //mov word ptr [bx+6], 0
    memory16(_ds, _bx + 4) = 0x0000;            //mov word ptr [bx+4], 0
    memory16(_ds, _bx + 8) = 0x0000;            //mov word ptr [bx+8], 0
loc_1652E:                                      //loc_1652E:
    _ax = memory16(_ds, _di + 4);               //mov ax, [di+4]
    _ax = _ax | memory16(_ds, _di + 6);         //or ax, [di+6]
    if (_ax == 0)                               //jz short loc_16539
        goto loc_16539;
    goto loc_1662B;                             //jmp loc_1662B
loc_16539:                                      //loc_16539:
    _push(_ds);                                 //push ds
    _ax = 0x04f8;                               //mov ax, 4F8h
    _push(_ax);                                 //push ax
    _ax = _di;                                  //mov ax, di
    _ax += 0x000a;                              //add ax, 0Ah
    _dx = _ds;                                  //mov dx, ds
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x0946;                               //mov ax, 946h
    _push(_ax);                                 //push ax
    sub_1517A();                                //call sub_1517A
    _push(_ds);                                 //push ds
    _ax = 0x050e;                               //mov ax, 50Eh
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x04f8;                               //mov ax, 4F8h
    _push(_ax);                                 //push ax
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_C]
    _push(_ax);                                 //push ax
    _ax = 0xfff3;                               //mov ax, 0FFF3h
    _push(_ax);                                 //push ax
    sub_157FD();                                //call sub_157FD
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_16595
        goto loc_16595;
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x04f8;                               //mov ax, 4F8h
    _push(_ax);                                 //push ax
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_C]
    _push(_ax);                                 //push ax
    _ax = 0xfff3;                               //mov ax, 0FFF3h
    _push(_ax);                                 //push ax
    sub_157FD();                                //call sub_157FD
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_16595
        goto loc_16595;
    if (memory16(_ds, 0xA9E) == 0xfffd)         //jz short loc_1658C
        goto loc_1658C;
    goto loc_16642;                             //jmp loc_16642
loc_1658C:                                      //loc_1658C:
    memory16(_ds, 0xA9E) = 0xfff8;              //mov word_1913E, 0FFF8h
    goto loc_16642;                             //jmp loc_16642
loc_16595:                                      //loc_16595:
    _ax = _stack16(_bp + var_C);                //mov ax, [bp+var_C]
    _ax += 0x0010;                              //add ax, 10h
    _push(_ax);                                 //push ax
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_A]
    _push(_ax);                                 //push ax
    sub_153D8();                                //call sub_153D8
    _sp += 0x0006;                              //add sp, 6
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_165B7
        goto loc_165B7;
    sub_151B8();                                //call sub_151B8
    memory16(_ds, 0xA9E) = 0xfff7;              //mov word_1913E, 0FFF7h
    goto loc_16642;                             //jmp loc_16642
loc_165B7:                                      //loc_165B7:
    _dx = _stack16(_bp + var_8);                //mov dx, [bp+var_8]
    _ax = _stack16(_bp + var_A);                //mov ax, [bp+var_A]
    _ax += 0x000f;                              //add ax, 0Fh
    _cx = 0x0004;                               //mov cx, 4
    _ax >>= _cl;                                //shr ax, cl
    _dx += _ax;                                 //add dx, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _stack16(_bp + var_4) = _dx;                //mov [bp+var_4], dx
    _stack16(_bp + var_6) = _ax;                //mov [bp+var_6], ax
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + var_C));               //push [bp+var_C]
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    sub_15208();                                //call sub_15208
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_165F0
        goto loc_165F0;
    _ax = _stack16(_bp + var_C);                //mov ax, [bp+var_C]
    _ax += 0x0010;                              //add ax, 10h
    _push(_ax);                                 //push ax
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_A]
    _push(_ax);                                 //push ax
    sub_15409();                                //call sub_15409
    _sp += 0x0006;                              //add sp, 6
    goto loc_16642;                             //jmp short loc_16642
loc_165F0:                                      //loc_165F0:
    sub_151B8();                                //call sub_151B8
    _push(_stack16(_bp + var_4));               //push [bp+var_4]
    _push(_stack16(_bp + var_6));               //push [bp+var_6]
    _push(_cs);                                 //push cs
    sub_15513();                                //call near ptr sub_15513
    _cx = _pop();                               //pop cx
    _cx = _pop();                               //pop cx
    if (_ax == _si)                             //jz short loc_16617
        goto loc_16617;
    _ax = _stack16(_bp + var_C);                //mov ax, [bp+var_C]
    _ax += 0x0010;                              //add ax, 10h
    _push(_ax);                                 //push ax
    _push(_ss);                                 //push ss
    _FIXME_;                                    //lea ax, [bp+var_A]
    _push(_ax);                                 //push ax
    sub_15409();                                //call sub_15409
    _sp += 0x0006;                              //add sp, 6
    goto loc_1663C;                             //jmp short loc_1663C
loc_16617:                                      //loc_16617:
    _dx = _stack16(_bp + var_8);                //mov dx, [bp+var_8]
    _ax = _stack16(_bp + var_A);                //mov ax, [bp+var_A]
    memory16(_ds, _di + 2) = _dx;               //mov [di+2], dx
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _ax = _stack16(_bp + var_C);                //mov ax, [bp+var_C]
    _ax += 0x0010;                              //add ax, 10h
    memory16(_ds, _di + 8) = _ax;               //mov [di+8], ax
loc_1662B:                                      //loc_1662B:
    memory16(_ds, 0x61A) = _si;                 //mov word_18CBA, si
loc_1662F:                                      //loc_1662F:
    _les(_bx, _ds, _di + 4);                    //les bx, [di+4]
    memory16(_ds, 0x607) = _es;                 //mov word_18CA7, es
    memory16(_ds, 0x605) = _bx;                 //mov word_18CA5, bx
    goto loc_16649;                             //jmp short loc_16649
loc_1663C:                                      //loc_1663C:
    memory16(_ds, 0xA9E) = 0xfff3;              //mov word_1913E, 0FFF3h
loc_16642:                                      //loc_16642:
    _si = _si ^ _si;                            //xor si, si
    _stack16(_bp + arg_4) = 0x0001;             //mov [bp+arg_4], 1
loc_16649:                                      //loc_16649:
    memory16(_ds, 0xAB9) = _si;                 //mov word_19159, si
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    memory16(_ds, 0xABB) = _ax;                 //mov word_1915B, ax
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    memory16(_ds, 0xABD) = _ax;                 //mov word_1915D, ax
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_si);                                 //push si
    _push(_cs);                                 //push cs
    sub_16C78();                                //call near ptr sub_16C78
    _sp += 0x0006;                              //add sp, 6
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
}

void sub_1666C()
{
    WORD _cs = _seg000;

    const int arg_0 = 8;                        //arg_0  = word ptr  8
    const int arg_2 = 10;                       //arg_2  = word ptr  0Ah
    const int arg_4 = 12;                       //arg_4  = word ptr  0Ch
    const int arg_6 = 14;                       //arg_6  = word ptr  0Eh
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _bp = _sp;                                  //mov bp, sp
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    if (_ax > memory16(_ds, 0xB2B))             //ja short loc_166A9
        goto loc_166A9;
    _ax = _stack16(_bp + arg_2);                //mov ax, [bp+arg_2]
    if (_ax > memory16(_ds, 0xB2B))             //ja short loc_166A9
        goto loc_166A9;
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    if (_ax > memory16(_ds, 0xB2D))             //ja short loc_166A9
        goto loc_166A9;
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    if (_ax > memory16(_ds, 0xB2D))             //ja short loc_166A9
        goto loc_166A9;
    _push(_ax);                                 //push ax
    _push(_stack16(_bp + arg_4));               //push [bp+arg_4]
    _push(_stack16(_bp + arg_2));               //push [bp+arg_2]
    _push(_stack16(_bp + arg_0));               //push [bp+arg_0]
    _push(_cs);                                 //push cs
    sub_16CBE();                                //call near ptr sub_16CBE
    _sp = _bp;                                  //mov sp, bp
loc_166A9:                                      //loc_166A9:
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
}

void sub_166BC()
{
    _push(_es);                                 //push es
    _push(_bx);                                 //push bx
    return;                                     //retf
    _STOP_("sp-trace-fail");                    //sub_166BC endp_failed
    _STOP_("continues");                        //sub_166BF proc near
}

void sub_166BF()
{
    if (memory(_ds, 0x955) != 0xff)             //jnz short locret_166F0
        goto locret_166F0;
    _ah = 0x0f;                                 //mov ah, 0Fh
    _interrupt(16);                             //int 10h
    memory(_ds, 0x955) = _al;                   //mov byte ptr word_18FF5, al
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    _bx = 0x0010;                               //mov bx, 10h
    _al = memory(_es, _bx);                     //mov al, es:[bx]
    memory(_ds, 0x956) = _al;                   //mov byte ptr word_18FF5+1, al
    if (memory(_ds, 0x94E) == 0x05)             //jz short locret_166F0
        goto locret_166F0;
    if (memory(_ds, 0x94E) == 0x07)             //jz short locret_166F0
        goto locret_166F0;
    _al &= 0xcf;                                //and al, 0CFh
    _al |= 0x10;                                //or al, 10h
    memory(_es, _bx) = _al;                     //mov es:[bx], al
locret_166F0:                                   //locret_166F0:
    return;
}

void sub_166F1()
{
    WORD _cs = _seg000;

    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    memory(_ds, 0x955) = 0xff;                  //mov byte ptr word_18FF5, 0FFh
    _al = _al ^ _al;                            //xor al, al
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = memory(_ds, 0x94D);                   //mov cl, byte ptr word_18FEC+1
    _les(_bx, _ds, 0x416);                      //les bx, dword_18AB6
    _si = 0x0000;                               //mov si, 0
    dword_18AB2();                              //call dword_18AB2
    memory16(_ds, 0x60B) = _es;                 //mov word ptr dword_18CA9+2, es
    memory16(_ds, 0x609) = _bx;                 //mov word ptr dword_18CA9, bx
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16721()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = word ptr  0Ah
    const int arg_6 = 12;                       //arg_6  = word ptr  0Ch
    const int arg_8 = 14;                       //arg_8  = byte ptr  0Eh
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _cx = _stack16(_bp + arg_4);                //mov cx, [bp+arg_4]
    _dx = _stack16(_bp + arg_6);                //mov dx, [bp+arg_6]
    if (_stack16(_bp + arg_8) != 0x0000)        //jnz short loc_16741
        goto loc_16741;
    _ah |= 0x80;                                //or ah, 80h
loc_16741:                                      //loc_16741:
    _si = 0x0038;                               //mov si, 38h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_1674D()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = byte ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    sub_166BF();                                //call sub_166BF
    _al = _stack16(_bp + arg_0);                //mov al, [bp+arg_0]
    if (_al >= 0x0a)                            //jnb short loc_16771
        goto loc_16771;
    memory(_ds, 0x94D) = _al;                   //mov byte ptr word_18FEC+1, al
    _push(memory16(_ds, 0x955));                //push word_18FF5
    _push(_cs);                                 //push cs
    sub_166F1();                                //call near ptr sub_166F1
    memory16(_ds, 0x955) = _pop();              //pop word_18FF5
loc_16771:                                      //loc_16771:
    _les(_bx, _ds, 0x951);                      //les bx, dword_18FF1
    _si = 0x0002;                               //mov si, 2
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16781()
{
    WORD _cs = _seg000;

    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    if (memory(_ds, 0x955) == 0xff)             //jz short loc_167B4
        goto loc_167B4;
    _si = 0x0006;                               //mov si, 6
    dword_18AB2();                              //call dword_18AB2
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    _bx = 0x0010;                               //mov bx, 10h
    _al = memory(_ds, 0x956);                   //mov al, byte ptr word_18FF5+1
    memory(_es, _bx) = _al;                     //mov es:[bx], al
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al = memory(_ds, 0x955);                   //mov al, byte ptr word_18FF5
    _interrupt(16);                             //int 10h
    memory(_ds, 0x955) = 0xff;                  //mov byte ptr word_18FF5, 0FFh
loc_167B4:                                      //loc_167B4:
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void loc_167DA()
{
    WORD _cs = _seg000;

    _ah = 0x05;                                 //mov ah, 5
    _interrupt(16);                             //int 10h
loc_167DE:                                      //loc_167DE:
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    return;                                     //retf
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _al = _stack16(_bp + 6);                    //mov al, [bp+6]
    _ah = _ah ^ _ah;                            //xor ah, ah
    _push(_ax);                                 //push ax
    _si = 0x0032;                               //mov si, 32h
    dword_18AB2();                              //call dword_18AB2
    _bx = memory16(_es, _bx + 10);              //mov bx, es:[bx+0Ah]
    _ax = _pop();                               //pop ax
    _push(_cs);                                 //push cs
    sub_166BC();                                //call near ptr sub_166BC
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16809()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = dword ptr  6
    const int arg_4 = 10;                       //arg_4  = byte ptr  0Ah
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ah = _stack16(_bp + arg_4);                //mov ah, [bp+arg_4]
    memory(_ds, 0x60E) = _ah;                   //mov byte_18CAE, ah
    _al = memory(_ds, 0x60D);                   //mov al, byte_18CAD
    _si = 0x001e;                               //mov si, 1Eh
    dword_18AB2();                              //call dword_18AB2
    memory(_ds, 0x611) = 0x0c;                  //mov byte_18CB1, 0Ch
    _FIXME_;                                    //les bx, [bp+arg_0]
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _si = 0x0020;                               //mov si, 20h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_1683C()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = byte ptr  6
    const int arg_2 = 8;                        //arg_2  = byte ptr  8
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ah = _stack16(_bp + arg_0);                //mov ah, [bp+arg_0]
    _al = _stack16(_bp + arg_2);                //mov al, [bp+arg_2]
    _si = 0x002a;                               //mov si, 2Ah
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16859()
{
    WORD _cs = _seg000;

    const int arg_6 = 10;                       //arg_6  = word ptr  0Ah
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_6);                //mov ax, [bp+arg_6]
    _STOP_("sp-trace-fail");                    //sub_16859 endp_failed
    _STOP_("continues");                        //sub_16867 proc far
}

void sub_16867()
{
    WORD _cs = _seg000;

    _ax = _ax - _stack16(_bp + 6);              //sub ax, [bp+6]
    if ((short)_ax >= 0)                        //jns short loc_1686E
        goto loc_1686E;
    _ax = -_ax;                                 //neg ax
loc_1686E:                                      //loc_1686E:
    _ax += 1;                                   //inc ax
    _ax += 0x0007;                              //add ax, 7
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _push(_ax);                                 //push ax
    _si = 0x0032;                               //mov si, 32h
    dword_18AB2();                              //call dword_18AB2
    _bx = memory16(_es, _bx + 8);               //mov bx, es:[bx+8]
    _push(_cs);                                 //push cs
    sub_166BC();                                //call near ptr sub_166BC
    _bx = _pop();                               //pop bx
    _mul(_bx);                                  //mul bx
    _cx = _stack16(_bp + 12);                   //mov cx, [bp+0Ch]
    _cx = _cx - _stack16(_bp + 8);              //sub cx, [bp+8]
    if ((short)_cx >= 0)                        //jns short loc_16895
        goto loc_16895;
    _cx = -_cx;                                 //neg cx
loc_16895:                                      //loc_16895:
    _cx += 1;                                   //inc cx
    _mul(_cx);                                  //mul cx
    _flags.carry = (_ax + 0x0006) >= 0x10000;   //add ax, 6
    _ax += 0x0006;
    if (_flags.carry)                           //jb short loc_168A1
        goto loc_168A1;
    _dx &= _dx;                                 //and dx, dx
    if (_dx == 0)                               //jz short loc_168A6
        goto loc_168A6;
loc_168A1:                                      //loc_168A1:
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _dx = _ax;                                  //mov dx, ax
loc_168A6:                                      //loc_168A6:
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    return;                                     //retf
    _STOP_("sp-trace-fail");                    //sub_16867 endp_failed
    _STOP_("continues");                        //sub_168AB proc far
}

void sub_168AB()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = dword ptr  6
    const int arg_4 = 10;                       //arg_4  = dword ptr  0Ah
    const int arg_8 = 14;                       //arg_8  = dword ptr  0Eh
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    memory(_ds, 0x94C) = 0xff;                  //mov byte ptr word_18FEC, 0FFh
    memory(_ds, 0x94D) = 0x00;                  //mov byte ptr word_18FEC+1, 0
    _FIXME_;                                    //les di, [bp+arg_4]
    _al = memory(_es, _di);                     //mov al, es:[di]
    memory(_ds, 0x94E) = _al;                   //mov byte_18FEE, al
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz short loc_168DB
        goto loc_168DB;
    _bp += 0x0004;                              //add bp, 4
    sub_1691E();                                //call sub_1691E
    _bp -= 0x0004;                              //sub bp, 4
    _al = memory(_ds, 0x94C);                   //mov al, byte ptr word_18FEC
    goto loc_168F6;                             //jmp short loc_168F6
loc_168DB:                                      //loc_168DB:
    _FIXME_;                                    //les di, [bp+arg_8]
    _al = memory(_es, _di);                     //mov al, es:[di]
    memory(_ds, 0x94D) = _al;                   //mov byte ptr word_18FEC+1, al
    _FIXME_;                                    //les di, [bp+arg_4]
    _bl = memory(_es, _di);                     //mov bl, es:[di]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx += 0x6dd3;                              //add bx, 6DD3h
    _al = memory(_cs, _bx);                     //mov al, cs:[bx]
    memory(_ds, 0x94C) = _al;                   //mov byte ptr word_18FEC, al
loc_168F6:                                      //loc_168F6:
    _FIXME_;                                    //les di, [bp+arg_0]
    _ah = _ah ^ _ah;                            //xor ah, ah
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16903()
{
    WORD _cs = _seg000;

    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(memory16(_ds, 0x94C));                //push word_18FEC
    sub_1691E();                                //call sub_1691E
    memory16(_ds, 0x94C) = _pop();              //pop word_18FEC
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_1691E()
{
    _push(_bp);                                 //push bp
    sub_16DF7();                                //call sub_16DF7
    _bp = _pop();                               //pop bp
    _FIXME_;                                    //les di, [bp+6]
    _al = memory(_ds, 0x94E);                   //mov al, byte_18FEE
    _ah = _ah ^ _ah;                            //xor ah, ah
    if (_al != 0xff)                            //jnz short loc_16931
        goto loc_16931;
    _ah = _al;                                  //mov ah, al
loc_16931:                                      //loc_16931:
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al = memory(_ds, 0x94D);                   //mov al, byte ptr word_18FEC+1
    _FIXME_;                                    //les di, [bp+0Ah]
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
}

void sub_16940()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = dword ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    sub_166BF();                                //call sub_166BF
    _FIXME_;                                    //les bx, [bp+arg_0]
    memory16(_ds, 0x951) = _bx;                 //mov word ptr dword_18FF1, bx
    memory16(_ds, 0x953) = _es;                 //mov word ptr dword_18FF1+2, es
    _si = 0x0002;                               //mov si, 2
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16965()
{
    WORD _cs = _seg000;

    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
loc_16970:                                      //loc_16970:
    _si = 0x0004;                               //mov si, 4
    _STOP_("sp-trace-fail");                    //sub_16965 endp_failed
    _STOP_("continues");                        //call dword_18AB2
}

void sub_1697C()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _si = 0x0008;                               //mov si, 8
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16999()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _si = 0x000a;                               //mov si, 0Ah
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_169B6()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = word ptr  0Ah
    const int arg_6 = 12;                       //arg_6  = word ptr  0Ch
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _cx = _stack16(_bp + arg_4);                //mov cx, [bp+arg_4]
    _dx = _stack16(_bp + arg_6);                //mov dx, [bp+arg_6]
    _si = 0x000c;                               //mov si, 0Ch
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16A19()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = word ptr  0Ah
    const int arg_6 = 12;                       //arg_6  = word ptr  0Ch
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _cx = _stack16(_bp + arg_4);                //mov cx, [bp+arg_4]
    _dx = _stack16(_bp + arg_6);                //mov dx, [bp+arg_6]
    _si = 0x0012;                               //mov si, 12h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void loc_16A58()
{
    if (_bx >= _dx)                             //jnb short loc_16A5E
        goto loc_16A5E;
    _xchg(_bx, _dx);                            //xchg bx, dx
loc_16A5E:                                      //loc_16A5E:
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _si = 0x0008;                               //mov si, 8
    dword_18AB2();                              //call dword_18AB2
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _cx = _stack16(_bp + 14);                   //mov cx, [bp+0Eh]
    _dx = _stack16(_bp + 16);                   //mov dx, [bp+10h]
    _si = 0x0010;                               //mov si, 10h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16A7B()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = word ptr  0Ah
    const int arg_6 = 12;                       //arg_6  = word ptr  0Ch
    const int arg_8 = 14;                       //arg_8  = word ptr  0Eh
    const int arg_A = 16;                       //arg_A  = word ptr  10h
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _si = 0x0008;                               //mov si, 8
    dword_18AB2();                              //call dword_18AB2
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    _bx = _stack16(_bp + arg_6);                //mov bx, [bp+arg_6]
    _cx = _stack16(_bp + arg_8);                //mov cx, [bp+arg_8]
    _dx = _stack16(_bp + arg_A);                //mov dx, [bp+arg_A]
    _si = 0x0014;                               //mov si, 14h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16AAB()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = word ptr  0Ah
    const int arg_6 = 12;                       //arg_6  = word ptr  0Ch
    const int arg_8 = 14;                       //arg_8  = word ptr  0Eh
    const int arg_A = 16;                       //arg_A  = word ptr  10h
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _si = 0x0008;                               //mov si, 8
    dword_18AB2();                              //call dword_18AB2
    _ax = _stack16(_bp + arg_4);                //mov ax, [bp+arg_4]
    _bx = _stack16(_bp + arg_6);                //mov bx, [bp+arg_6]
    _cx = _stack16(_bp + arg_8);                //mov cx, [bp+arg_8]
    _dx = _stack16(_bp + arg_A);                //mov dx, [bp+arg_A]
    _si = 0x0016;                               //mov si, 16h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16B04()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = byte ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _al = _stack16(_bp + arg_0);                //mov al, [bp+arg_0]
    memory(_ds, 0x60D) = _al;                   //mov byte_18CAD, al
    _ah = memory(_ds, 0x60E);                   //mov ah, byte_18CAE
    _si = 0x001e;                               //mov si, 1Eh
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16B25()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = byte ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _bl = _stack16(_bp + arg_0);                //mov bl, [bp+arg_0]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _si = 0x001a;                               //mov si, 1Ah
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16B6A()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _ah = _ah ^ _ah;                            //xor ah, ah
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _si = 0x001a;                               //mov si, 1Ah
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16B89()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = dword ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _FIXME_;                                    //les bx, [bp+arg_0]
    _bx += 1;                                   //inc bx
    _si = 0x001c;                               //mov si, 1Ch
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16BA4()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = byte ptr  0Ah
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    memory(_ds, 0x610) = _al;                   //mov byte_18CB0, al
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _cl = _stack16(_bp + arg_4);                //mov cl, [bp+arg_4]
    memory(_ds, 0x950) = _cl;                   //mov byte_18FF0, cl
    _ch = _ch ^ _ch;                            //xor ch, ch
    _si = 0x0022;                               //mov si, 22h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16C12()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = byte ptr  6
    const int arg_2 = 8;                        //arg_2  = byte ptr  8
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ah = _stack16(_bp + arg_2);                //mov ah, [bp+arg_2]
    memory(_ds, 0x60E) = _ah;                   //mov byte_18CAE, ah
    _al = memory(_ds, 0x60D);                   //mov al, byte_18CAD
    _si = 0x001e;                               //mov si, 1Eh
    dword_18AB2();                              //call dword_18AB2
    _al = _stack16(_bp + arg_0);                //mov al, [bp+arg_0]
    memory(_ds, 0x611) = _al;                   //mov byte_18CB1, al
    _ah = _al;                                  //mov ah, al
    _si = 0x0020;                               //mov si, 20h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16C42()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = dword ptr  0Ah
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _si = 0x0008;                               //mov si, 8
    dword_18AB2();                              //call dword_18AB2
    _FIXME_;                                    //les bx, [bp+arg_4]
    _di = _bx;                                  //mov di, bx
    _al = _al ^ _al;                            //xor al, al
    _cx = 0xffff;                               //mov cx, 0FFFFh
    _flags.direction = false;                   //cld
    _repne_scasb();                             //repne scasb
    _cx = _di;                                  //mov cx, di
    _cx -= _bx;                                 //sub cx, bx
    _cx -= 1;                                   //dec cx
    _si = 0x0026;                               //mov si, 26h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16C78()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = byte ptr  6
    const int arg_2 = 8;                        //arg_2  = byte ptr  8
    const int arg_4 = 10;                       //arg_4  = byte ptr  0Ah
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _les(_bx, _ds, 0x609);                      //les bx, dword_18CA9
    _bx = memory16(_es, _bx + 16);              //mov bx, es:[bx+10h]
    _bx &= 0x7f7f;                              //and bx, 7F7Fh
    _dl = _stack16(_bp + arg_4);                //mov dl, [bp+arg_4]
    _al = _bh;                                  //mov al, bh
    _mul(_dl);                                  //mul dl
    _cx = _ax;                                  //mov cx, ax
    _al = _bl;                                  //mov al, bl
    _mul(_dl);                                  //mul dl
    _bx = _ax;                                  //mov bx, ax
    _al = _stack16(_bp + arg_0);                //mov al, [bp+arg_0]
    _ah = _stack16(_bp + arg_2);                //mov ah, [bp+arg_2]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz short loc_16CB2
        goto loc_16CB2;
    _cl = _dl;                                  //mov cl, dl
    _ch = _ch ^ _ch;                            //xor ch, ch
    _bx = _cx;                                  //mov bx, cx
    _dx = memory16(_ds, 0x607);                 //mov dx, word_18CA7
loc_16CB2:                                      //loc_16CB2:
    _si = 0x0024;                               //mov si, 24h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16CBE()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = word ptr  0Ah
    const int arg_6 = 12;                       //arg_6  = word ptr  0Ch
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _stack16(_bp + arg_0);                //mov ax, [bp+arg_0]
    _bx = _stack16(_bp + arg_2);                //mov bx, [bp+arg_2]
    _cx = _stack16(_bp + arg_4);                //mov cx, [bp+arg_4]
    _dx = _stack16(_bp + arg_6);                //mov dx, [bp+arg_6]
    _ah |= 0x80;                                //or ah, 80h
    _si = 0x0024;                               //mov si, 24h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16CE4()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = dword ptr  6
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _FIXME_;                                    //les bx, [bp+arg_0]
    _di = _bx;                                  //mov di, bx
    _al = _al ^ _al;                            //xor al, al
    _cx = 0xffff;                               //mov cx, 0FFFFh
    _flags.direction = false;                   //cld
    _repne_scasb();                             //repne scasb
    _cx = _di;                                  //mov cx, di
    _cx -= _bx;                                 //sub cx, bx
    _cx -= 1;                                   //dec cx
    _si = 0x0028;                               //mov si, 28h
    dword_18AB2();                              //call dword_18AB2
    _ax = _bx;                                  //mov ax, bx
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16D11()
{
    WORD _cs = _seg000;

    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _cx = 0x0001;                               //mov cx, 1
    _push(_cs);                                 //push cs
    _es = _pop();                               //pop es
    _bx = 0x6d0f;                               //mov bx, 6D0Fh
    _si = 0x0028;                               //mov si, 28h
    dword_18AB2();                              //call dword_18AB2
    _ax = _cx;                                  //mov ax, cx
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16D73()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = word ptr  0Ah
    const int arg_6 = 12;                       //arg_6  = word ptr  0Ch
    const int arg_8 = 14;                       //arg_8  = dword ptr  0Eh
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _FIXME_;                                    //les bx, [bp+arg_8]
    _cx = _stack16(_bp + arg_0);                //mov cx, [bp+arg_0]
    _dx = _stack16(_bp + arg_2);                //mov dx, [bp+arg_2]
    _si = _stack16(_bp + arg_4);                //mov si, [bp+arg_4]
    _di = _stack16(_bp + arg_6);                //mov di, [bp+arg_6]
    if (_cx < _si)                              //jb short loc_16D93
        goto loc_16D93;
    _xchg(_si, _cx);                            //xchg si, cx
loc_16D93:                                      //loc_16D93:
    if (_dx < _di)                              //jb short loc_16D99
        goto loc_16D99;
    _xchg(_di, _dx);                            //xchg di, dx
loc_16D99:                                      //loc_16D99:
    _si -= _cx;                                 //sub si, cx
    memory16(_es, _bx) = _si;                   //mov es:[bx], si
    _di -= _dx;                                 //sub di, dx
    memory16(_es, _bx + 2) = _di;               //mov es:[bx+2], di
    _si = 0x0034;                               //mov si, 34h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16DB0()
{
    WORD _cs = _seg000;

    const int arg_0 = 6;                        //arg_0  = word ptr  6
    const int arg_2 = 8;                        //arg_2  = word ptr  8
    const int arg_4 = 10;                       //arg_4  = dword ptr  0Ah
    const int arg_8 = 14;                       //arg_8  = byte ptr  0Eh
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _push(_ds);                                 //push ds
    _ds = memory16(_cs, 0x1A3);                 //mov ds, cs:word_101A3
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _FIXME_;                                    //les bx, [bp+arg_4]
    _cx = _stack16(_bp + arg_0);                //mov cx, [bp+arg_0]
    _dx = _stack16(_bp + arg_2);                //mov dx, [bp+arg_2]
    _al = _stack16(_bp + arg_8);                //mov al, [bp+arg_8]
    _si = 0x0036;                               //mov si, 36h
    dword_18AB2();                              //call dword_18AB2
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
}

void sub_16DF7()
{
    WORD _cs = _seg000;

    memory(_ds, 0x94C) = 0xff;                  //mov byte ptr word_18FEC, 0FFh
    memory(_ds, 0x94E) = 0xff;                  //mov byte_18FEE, 0FFh
    memory(_ds, 0x94D) = 0x00;                  //mov byte ptr word_18FEC+1, 0
    sub_16E2D();                                //call sub_16E2D
    _bl = memory(_ds, 0x94E);                   //mov bl, byte_18FEE
    if (_bl == 0xff)                            //jz short locret_16E2C
        goto locret_16E2C;
    _bh = _bh ^ _bh;                            //xor bh, bh
    _al = memory(_cs, _bx + 28115);             //mov al, cs:[bx+6DD3h]
    memory(_ds, 0x94C) = _al;                   //mov byte ptr word_18FEC, al
    _al = memory(_cs, _bx + 28127);             //mov al, cs:[bx+6DDFh]
    memory(_ds, 0x94D) = _al;                   //mov byte ptr word_18FEC+1, al
    _al = memory(_cs, _bx + 28139);             //mov al, cs:[bx+6DEBh]
    memory(_ds, 0x94F) = _al;                   //mov byte_18FEF, al
locret_16E2C:                                   //locret_16E2C:
    return;
}

void sub_16E2D()
{
    _ah = 0x0f;                                 //mov ah, 0Fh
    _interrupt(16);                             //int 10h
    if (_al == 0x07)                            //jz short loc_16E66
        goto loc_16E66;
    sub_16F0B();                                //call sub_16F0B
    if (_FIXME_)                                //jnb short loc_16E40
        goto loc_16E40;
    memory(_ds, 0x94E) = 0x06;                  //mov byte_18FEE, 6
    return;                                     //retn
loc_16E40:                                      //loc_16E40:
    sub_16E94();                                //call sub_16E94
    if (!_flags.carry)                          //jnb short loc_16E49
        goto loc_16E49;
loc_16E45:                                      //loc_16E45:
    sub_16EB2();                                //call sub_16EB2
    return;                                     //retn
loc_16E49:                                      //loc_16E49:
    sub_16F40();                                //call sub_16F40
    _ax &= _ax;                                 //and ax, ax
    if (_ax == 0)                               //jz short loc_16E56
        goto loc_16E56;
    memory(_ds, 0x94E) = 0x0a;                  //mov byte_18FEE, 0Ah
    return;                                     //retn
loc_16E56:                                      //loc_16E56:
    memory(_ds, 0x94E) = 0x01;                  //mov byte_18FEE, 1
    sub_16EEA();                                //call sub_16EEA
    if (!_flags.carry)                          //jnb short locret_16E65
        goto locret_16E65;
    memory(_ds, 0x94E) = 0x02;                  //mov byte_18FEE, 2
locret_16E65:                                   //locret_16E65:
    return;                                     //retn
loc_16E66:                                      //loc_16E66:
    sub_16E94();                                //call sub_16E94
    if (_flags.carry)                           //jb short loc_16E45
        goto loc_16E45;
    sub_16F0E();                                //call sub_16F0E
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz short loc_16E78
        goto loc_16E78;
    memory(_ds, 0x94E) = 0x07;                  //mov byte_18FEE, 7
    return;                                     //retn
loc_16E78:                                      //loc_16E78:
    _si = 0xb800;                               //mov si, 0B800h
    _es = _si;                                  //mov es, si
    _si = _si ^ _si;                            //xor si, si
    _ax = memory16(_es, _si);                   //mov ax, es:[si]
    _ax = (~_ax);                               //not ax
    memory16(_es, _si) = (~memory16(_es, _si)); //not word ptr es:[si]
    if (_ax != memory16(_es, _si))              //jnz short locret_16E93
        goto locret_16E93;
    memory(_ds, 0x94E) = 0x01;                  //mov byte_18FEE, 1
locret_16E93:                                   //locret_16E93:
    return;
}

void sub_16E94()
{
    _ax = 0x1200;                               //mov ax, 1200h
    _bl = 0x10;                                 //mov bl, 10h
    _bh = 0xff;                                 //mov bh, 0FFh
    _cl = 0x0f;                                 //mov cl, 0Fh
    _interrupt(16);                             //int 10h
    if ((char)_cl >= (char)0x0c)                //jge short loc_16EB0
        goto loc_16EB0;
    if ((char)_bh > (char)0x01)                 //jg short loc_16EB0
        goto loc_16EB0;
    if ((char)_bl > (char)0x03)                 //jg short loc_16EB0
        goto loc_16EB0;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_16EB0:                                      //loc_16EB0:
    _flags.carry = false;                       //clc
}

void sub_16EB2()
{
    memory(_ds, 0x94E) = 0x04;                  //mov byte_18FEE, 4
    if (_bh == 0x01)                            //jz short loc_16ED5
        goto loc_16ED5;
    sub_16EDB();                                //call sub_16EDB
    if (_FIXME_)                                //jb short locret_16ED4
        goto locret_16ED4;
    _bl &= _bl;                                 //and bl, bl
    if (_bl == 0)                               //jz short locret_16ED4
        goto locret_16ED4;
    memory(_ds, 0x94E) = 0x03;                  //mov byte_18FEE, 3
    sub_16EEA();                                //call sub_16EEA
    if (!_flags.carry)                          //jnb short locret_16ED4
        goto locret_16ED4;
    memory(_ds, 0x94E) = 0x09;                  //mov byte_18FEE, 9
locret_16ED4:                                   //locret_16ED4:
    return;                                     //retn
loc_16ED5:                                      //loc_16ED5:
    memory(_ds, 0x94E) = 0x05;                  //mov byte_18FEE, 5
}

void sub_16EDB()
{
    if (_cl < 0x02)                             //jb short locret_16EE9
        goto locret_16EE9;
    _cmc();                                     //cmc
    if (_cl >= 0x06)                            //jnb short locret_16EE9
        goto locret_16EE9;
locret_16EE9:                                   //locret_16EE9:
    return;
}

void sub_16EEA()
{
    _ax = 0x1a00;                               //mov ax, 1A00h
    _interrupt(16);                             //int 10h
    if (_al != 0x1a)                            //jnz short loc_16F09
        goto loc_16F09;
    if (_bl == 0x07)                            //jz short loc_16F07
        goto loc_16F07;
    if (_bl == 0x08)                            //jz short loc_16F07
        goto loc_16F07;
    if (_bl < 0x0b)                             //jb short loc_16F09
        goto loc_16F09;
    if (_bl > 0x0c)                             //ja short loc_16F09
        goto loc_16F09;
loc_16F07:                                      //loc_16F07:
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_16F09:                                      //loc_16F09:
    _flags.carry = false;                       //clc
}

void sub_16F0B()
{
    _al = _al ^ _al;                            //xor al, al
}

void sub_16F0E()
{
    _dx = 0x03ba;                               //mov dx, 3BAh
    _bl = _bl ^ _bl;                            //xor bl, bl
    _in(_al, _dx);                              //in al, dx
    _al &= 0x80;                                //and al, 80h
    _ah = _al;                                  //mov ah, al
    _cx = 0x8000;                               //mov cx, 8000h
loc_16F1B:                                      //loc_16F1B:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x80;                                //and al, 80h
    if (_al == _ah)                             //jz short loc_16F29
        goto loc_16F29;
    _bl += 1;                                   //inc bl
    if (_bl >= 0x0a)                            //jnb short loc_16F2E
        goto loc_16F2E;
loc_16F29:                                      //loc_16F29:
    if (--_cx)                                  //loop loc_16F1B
        goto loc_16F1B;
    _al = _al ^ _al;                            //xor al, al
    return;                                     //retn
loc_16F2E:                                      //loc_16F2E:
    _cx = 0x8000;                               //mov cx, 8000h
loc_16F31:                                      //loc_16F31:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x30;                                //and al, 30h
    if (_al != 0x10)                            //jnz short loc_16F3D
        goto loc_16F3D;
    if (--_cx)                                  //loop loc_16F31
        goto loc_16F31;
    _al = 0x02;                                 //mov al, 2
    return;                                     //retn
loc_16F3D:                                      //loc_16F3D:
    _al = 0x01;                                 //mov al, 1
}

void sub_16F40()
{
    _al = 0x06;                                 //mov al, 6
loc_16F42:                                      //loc_16F42:
    _cx = _cx ^ _cx;                            //xor cx, cx
    _STOP_("sp-trace-fail");                    //sub_16F40 endp_failed
    _STOP_("continues");                        //xor dx, dx
}

void sub_172BC()
{
    sub_17517();                                //call sub_17517
    if (_FIXME_)                                //jb short locret_172CF
        goto locret_172CF;
    memory16(_ds, 0x2BA) = _ax;                 //mov word_1895A, ax
    memory16(_ds, 0x2BC) = _bx;                 //mov word_1895C, bx
    _si = 0x0008;                               //mov si, 8
    dword_186E9();                              //call dword_186E9
locret_172CF:                                   //locret_172CF:
    return;
}

void sub_172F8()
{
    sub_17517();                                //call sub_17517
    if (_FIXME_)                                //jb short locret_17310
        goto locret_17310;
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _cx = _ax;                                  //mov cx, ax
    _dx = _bx;                                  //mov dx, bx
    _xchg(_ax, memory16(_ds, 0x2BA));           //xchg ax, word_1895A
    _xchg(_bx, memory16(_ds, 0x2BC));           //xchg bx, word_1895C
    sub_1735D();                                //call sub_1735D
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
locret_17310:                                   //locret_17310:
    return;
}

void sub_17311()
{
    sub_18092();                                //call sub_18092
    if (_FIXME_)                                //jnb short locret_1731D
        goto locret_1731D;
    _si = 0x0012;                               //mov si, 12h
    dword_186E9();                              //call dword_186E9
locret_1731D:                                   //locret_1731D:
    return;
}

void sub_1735D()
{
    if (memory(_ds, 0x292) >= 0x03)             //jnb short loc_17371
        { loc_17371(); return; }
    _STOP_("sp-trace-fail");                    //sub_1735D endp_failed
    _STOP_("continues");                        //sub_17364 proc near
}

void sub_17364()
{
    sub_17EEC();                                //call sub_17EEC
    if (_FIXME_)                                //jnb short locret_17370
        goto locret_17370;
    _si = 0x000c;                               //mov si, 0Ch
    dword_186E9();                              //call dword_186E9
locret_17370:                                   //locret_17370:
    return;
}

void loc_17371()
{
    sub_173A8();                                //call sub_173A8
    _di = _ax;                                  //mov di, ax
    _di -= _cx;                                 //sub di, cx
    if ((short)_di >= 0)                        //jns short loc_1737C
        goto loc_1737C;
    _di = -_di;                                 //neg di
loc_1737C:                                      //loc_1737C:
    _si = _bx;                                  //mov si, bx
    _si -= _dx;                                 //sub si, dx
    if ((short)_si >= 0)                        //jns short loc_17384
        goto loc_17384;
    _si = -_si;                                 //neg si
loc_17384:                                      //loc_17384:
    _di = memory16(_ds, 0x97D);                 //mov di, word_1901D
    if (_di >= _si)                             //jnb short loc_1739B
        goto loc_1739B;
    _ax -= _di;                                 //sub ax, di
    _cx -= _di;                                 //sub cx, di
    sub_173A8();                                //call sub_173A8
    _di <<= 1;                                  //shl di, 1
    _ax += _di;                                 //add ax, di
    _cx += _di;                                 //add cx, di
    {sub_173A8(); return; };                    //
loc_1739B:                                      //loc_1739B:
    _bx -= _di;                                 //sub bx, di
    _dx -= _di;                                 //sub dx, di
    sub_173A8();                                //call sub_173A8
    _di <<= 1;                                  //shl di, 1
    _bx += _di;                                 //add bx, di
    _dx += _di;                                 //add dx, di
}

void sub_173A8()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    sub_17364();                                //call sub_17364
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_17517()
{
    if (memory(_ds, 0x426) == 0x00)             //jz short locret_1758C
        _STOP_("goto locret_1758C");
    if (memory(_ds, 0x426) == 0x02)             //jz short loc_17535
        goto loc_17535;
    if (memory16(_ds, 0x42F) != 0x0000)         //jnz short loc_17546
        goto loc_17546;
    memory16(_ds, 0x431) = _ax;                 //mov word_18AD1, ax
    memory16(_ds, 0x433) = _bx;                 //mov word_18AD3, bx
    {sub_1756B(); return; };                    //
loc_17535:                                      //loc_17535:
    _dl = memory(_ds, 0x73);                    //mov dl, byte ptr word_18713
    sub_180DE();                                //call sub_180DE
    if (!_flags.carry)                          //jnb short locret_17545
        goto locret_17545;
    _si = 0x0030;                               //mov si, 30h
    dword_186E9();                              //call dword_186E9
locret_17545:                                   //locret_17545:
    return;                                     //retn
loc_17546:                                      //loc_17546:
    if (_ax != memory16(_ds, 0x431))            //jnz short sub_1756B
        { sub_1756B(); return; }
    if (_bx != memory16(_ds, 0x433))            //jnz short sub_1756B
        { sub_1756B(); return; }
    if (memory16(_ds, 0x42F) == 0x0001)         //jz short loc_1758B
        _STOP_("goto loc_1758B");
    sub_1756B();                                //call sub_1756B
    _ax = 0x8001;                               //mov ax, 8001h
    _bx = _ax;                                  //mov bx, ax
    sub_1756B();                                //call sub_1756B
    memory16(_ds, 0x42F) = 0x0000;              //mov word_18ACF, 0
}

void sub_1756B()
{
    memory16(_ds, 0x42F) += 1;                  //inc word_18ACF
    _di = memory16(_ds, 0x429);                 //mov di, word_18AC9
    if (_di >= memory16(_ds, 0x427))            //jnb short loc_1758D
        goto loc_1758D;
    _di <<= 1;                                  //shl di, 1
    _di <<= 1;                                  //shl di, 1
    _les(_si, _ds, 0x42B);                      //les si, dword_18ACB
    _di += _si;                                 //add di, si
    _stosw<MemAuto, DirAuto>();                 //stosw
    memory16(_es, _di) = _bx;                   //mov es:[di], bx
    memory16(_ds, 0x429) += 1;                  //inc word_18AC9
loc_1758B:                                      //loc_1758B:
    _flags.carry = true;                        //stc
locret_1758C:                                   //locret_1758C:
    return;                                     //retn
loc_1758D:                                      //loc_1758D:
    _push(_es);                                 //push es
    _push(_bx);                                 //push bx
    _les(_bx, _ds, 0x51);                       //les bx, dword_186F1
    memory16(_es, _bx) = 0xfffa;                //mov word ptr es:[bx], 0FFFAh
    _bx = _pop();                               //pop bx
    _es = _pop();                               //pop es
    _flags.carry = true;                        //stc
}

void loc_175C6()
{
    _bx = memory16(_ds, 0x2D0);                 //mov bx, word_18970
    _push(_bx);                                 //push bx
    _ax = memory16(_ds, 0x2CA);                 //mov ax, word_1896A
    sub_172F8();                                //call sub_172F8
    _ax = memory16(_ds, 0x2CE);                 //mov ax, word_1896E
    _bx = _pop();                               //pop bx
    _push(_ax);                                 //push ax
    sub_172F8();                                //call sub_172F8
    _ax = _pop();                               //pop ax
    _bx = memory16(_ds, 0x2CC);                 //mov bx, word_1896C
    _push(_bx);                                 //push bx
    sub_172F8();                                //call sub_172F8
    _bx = _pop();                               //pop bx
    _ax = memory16(_ds, 0x2CA);                 //mov ax, word_1896A
    sub_172F8();                                //call sub_172F8
    _ax = memory16(_ds, 0x2CE);                 //mov ax, word_1896E
    _bx = memory16(_ds, 0x2CC);                 //mov bx, word_1896C
    _push(_ax);                                 //push ax
    sub_172BC();                                //call sub_172BC
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _cx |= _cx;                                 //or cx, cx
    if (_cx == 0)                               //jz short loc_1763A
        goto loc_1763A;
    _push(_dx);                                 //push dx
    _dx = _cx;                                  //mov dx, cx
    _di = _dx;                                  //mov di, dx
    _dx <<= 1;                                  //shl dx, 1
    _dx += _di;                                 //add dx, di
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    if (memory(_ds, 0x6B) == 0x00)              //jz short loc_1761E
        goto loc_1761E;
    _cx = _dx;                                  //mov cx, dx
    _cx = -_cx;                                 //neg cx
    _di = _pop();                               //pop di
    _di &= _di;                                 //and di, di
    if (_di != 0)                               //jnz short loc_1761D
        goto loc_1761D;
    sub_1766A();                                //call sub_1766A
    goto loc_1763A;                             //jmp short loc_1763A
loc_1761D:                                      //loc_1761D:
    _push(_di);                                 //push di
loc_1761E:                                      //loc_1761E:
    _ax += _cx;                                 //add ax, cx
    _bx -= _dx;                                 //sub bx, dx
    _push(_ax);                                 //push ax
    sub_172F8();                                //call sub_172F8
    _ax = _pop();                               //pop ax
    _bx = memory16(_ds, 0x2D0);                 //mov bx, word_18970
    _bx -= _dx;                                 //sub bx, dx
    _push(_bx);                                 //push bx
    sub_172F8();                                //call sub_172F8
    _bx = _pop();                               //pop bx
    _di = _pop();                               //pop di
    _di &= _di;                                 //and di, di
    if (_di == 0)                               //jz short loc_1763A
        goto loc_1763A;
    sub_17645();                                //call sub_17645
loc_1763A:                                      //loc_1763A:
    _ax = memory16(_ds, 0x73);                  //mov ax, word_18713
    _si = 0x001e;                               //mov si, 1Eh
    dword_186E9();                              //call dword_186E9
}

void sub_17645()
{
    _ax = memory16(_ds, 0x2CA);                 //mov ax, word_1896A
    _ax += _cx;                                 //add ax, cx
    sub_172F8();                                //call sub_172F8
    _ax = memory16(_ds, 0x2CA);                 //mov ax, word_1896A
    _bx = memory16(_ds, 0x2D0);                 //mov bx, word_18970
    _push(_bx);                                 //push bx
    sub_172F8();                                //call sub_172F8
    _bx = _pop();                               //pop bx
    _ax = memory16(_ds, 0x2CE);                 //mov ax, word_1896E
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    sub_172BC();                                //call sub_172BC
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _ax += _cx;                                 //add ax, cx
    _bx -= _dx;                                 //sub bx, dx
    {sub_172F8(); return; };                    //
}

void sub_1766A()
{
    _ax = memory16(_ds, 0x2CA);                 //mov ax, word_1896A
    _bx = memory16(_ds, 0x2D0);                 //mov bx, word_18970
    _push(_bx);                                 //push bx
    _push(_ax);                                 //push ax
    sub_172BC();                                //call sub_172BC
    _ax = _pop();                               //pop ax
    _bx = _pop();                               //pop bx
    _bx -= _dx;                                 //sub bx, dx
    _ax += _cx;                                 //add ax, cx
    _push(_bx);                                 //push bx
    sub_172F8();                                //call sub_172F8
    _ax = memory16(_ds, 0x2CE);                 //mov ax, word_1896E
    _ax += _cx;                                 //add ax, cx
    _bx = _pop();                               //pop bx
    {sub_172F8(); return; };                    //
}

void sub_17689()
{
    if ((short)_ax < (short)_cx)                //jl short loc_1768E
        goto loc_1768E;
    _xchg(_ax, _cx);                            //xchg ax, cx
loc_1768E:                                      //loc_1768E:
    if ((short)_bx >= (short)_dx)               //jge short loc_17694
        goto loc_17694;
    _xchg(_bx, _dx);                            //xchg bx, dx
loc_17694:                                      //loc_17694:
    _ax += 1;                                   //inc ax
    _cx -= 1;                                   //dec cx
    _bx -= 1;                                   //dec bx
    _dx += 1;                                   //inc dx
    sub_17311();                                //call sub_17311
    _flags.carry = true;                        //stc
}

void loc_17964()
{
    sub_17995();                                //call sub_17995
    sub_17A62();                                //call sub_17A62
    _ax = _stack16(_bp + -20);                  //mov ax, [bp-14h]
    _STOP_("db 80h, 7Eh, 0E8h");                //db 80h, 7Eh, 0E8h
}

void sub_17970()
{
    WORD _cs = _seg000;

    _dh = _dh + _stack16(_bp + _si + 18);       //add dh, [bp+si+12h]
    _FIXME_ += 1;                               //inc word ptr [bp-12h]
    _bx = _stack16(_bp + -22);                  //mov bx, [bp-16h]
    if (_bx != _stack16(_bp + -18))             //jnz short loc_17985
        goto loc_17985;
    _FIXME_ = 0x0000;                           //mov word ptr [bp-12h], 0
    _imul(_bx);                                 //imul bx
loc_17985:                                      //loc_17985:
    _stack16(_bp + -10) += _ax;                 //add [bp-0Ah], ax
    _ax = _stack16(_bp + -10);                  //mov ax, [bp-0Ah]
    if ((short)_ax < (short)_stack16(_bp + -14))//jl short loc_17964
        { loc_17964(); return; }
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _push(_cs);                                 //push cs
    _ds = _pop();                               //pop ds
    return;                                     //retn
    _STOP_("sp-trace-fail");                    //sub_17970 endp_failed
    _STOP_("continues");                        //sub_17995 proc near
}

void sub_17995()
{
    _FIXME_ = 0x0000;                           //mov word ptr [bp-6], 0
    _bx = _stack16(_bp + -2);                   //mov bx, [bp-2]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _cx = memory16(_ds, _bx);                   //mov cx, [bx]
loc_179A1:                                      //loc_179A1:
    _ax = _stack16(_bp + -10);                  //mov ax, [bp-0Ah]
loc_179A4:                                      //loc_179A4:
    _bx += 0x0004;                              //add bx, 4
    _di = _cx;                                  //mov di, cx
    _dx = memory16(_ds, _bx);                   //mov dx, [bx]
    _cx = _dx;                                  //mov cx, dx
    if (_dh == 0x80)                            //jz short loc_179CC
        goto loc_179CC;
    if ((short)_dx < (short)_di)                //jl short loc_179B8
        goto loc_179B8;
    _xchg(_dx, _di);                            //xchg dx, di
loc_179B8:                                      //loc_179B8:
    if ((short)_ax < (short)_dx)                //jl short loc_179A4
        goto loc_179A4;
    if ((short)_ax >= (short)_di)               //jge short loc_179A4
        goto loc_179A4;
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    sub_179DC();                                //call sub_179DC
    sub_17A03();                                //call sub_17A03
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    goto loc_179A1;                             //jmp short loc_179A1
loc_179CC:                                      //loc_179CC:
    if (_dl != 0x01)                            //jnz short locret_179DB
        goto locret_179DB;
    _bx += 0x0004;                              //add bx, 4
    _cx = memory16(_ds, _bx);                   //mov cx, [bx]
    if (_ch != 0x80)                            //jnz short loc_179A1
        goto loc_179A1;
locret_179DB:                                   //locret_179DB:
    return;
}

void sub_179DC()
{
    _si = memory16(_ds, _bx + -6);              //mov si, [bx-6]
    _di = memory16(_ds, _bx + -4);              //mov di, [bx-4]
    _cx = memory16(_ds, _bx + -2);              //mov cx, [bx-2]
    _dx = memory16(_ds, _bx);                   //mov dx, [bx]
    if ((short)_dx < (short)_di)                //jl short loc_179EF
        goto loc_179EF;
    _xchg(_cx, _si);                            //xchg cx, si
    _xchg(_dx, _di);                            //xchg dx, di
loc_179EF:                                      //loc_179EF:
    _ax = _cx;                                  //mov ax, cx
    _di -= _dx;                                 //sub di, dx
    if (_di == 0)                               //jz short locret_17A02
        goto locret_17A02;
    _ax = _stack16(_bp + -10);                  //mov ax, [bp-0Ah]
    _ax -= _dx;                                 //sub ax, dx
    _si -= _cx;                                 //sub si, cx
    _imul(_si);                                 //imul si
    _idiv(_di);                                 //idiv di
    _ax += _cx;                                 //add ax, cx
locret_17A02:                                   //locret_17A02:
    return;
}

void sub_17A03()
{
    _dx = _ax;                                  //mov dx, ax
    _si = _stack16(_bp + -4);                   //mov si, [bp-4]
    _ax = _stack16(_bp + -6);                   //mov ax, [bp-6]
    if (_ax >= _stack16(_bp + -16))             //jnb short locret_17A32
        goto locret_17A32;
    _FIXME_ += 1;                               //inc word ptr [bp-6]
    _ax &= _ax;                                 //and ax, ax
    if (_ax == 0)                               //jz short loc_17A2C
        goto loc_17A2C;
loc_17A17:                                      //loc_17A17:
    _ax -= 1;                                   //dec ax
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _cx = memory16(_ds, _bx + _si);             //mov cx, [bx+si]
    _ax += 1;                                   //inc ax
    if ((short)_cx < (short)_dx)                //jl short loc_17A2C
        goto loc_17A2C;
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + _si) = _cx;             //mov [bx+si], cx
    _ax -= 1;                                   //dec ax
    if (_ax != 0)                               //jnz short loc_17A17
        goto loc_17A17;
loc_17A2C:                                      //loc_17A2C:
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + _si) = _dx;             //mov [bx+si], dx
locret_17A32:                                   //locret_17A32:
    return;
}

void loc_17A40()
{
loc_17A40:
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    if (_ah != 0x80)                            //jnz short loc_17A50
        goto loc_17A50;
    if (_al == 0x01)                            //jz short loc_17A40
        goto loc_17A40;
    return;                                     //retn
loc_17A50:                                      //loc_17A50:
    if ((short)_ax >= (short)_stack16(_bp + -12))//jge short loc_17A58
        goto loc_17A58;
    _stack16(_bp + -12) = _ax;                  //mov [bp-0Ch], ax
loc_17A58:                                      //loc_17A58:
    if ((short)_ax < (short)_stack16(_bp + -14))//jl short loc_17A40
        goto loc_17A40;
    _stack16(_bp + -14) = _ax;                  //mov [bp-0Eh], ax
    goto loc_17A40;                             //jmp short loc_17A40
}

void sub_17A62()
{
    WORD _cs = _seg000;

    _si = _stack16(_bp + -4);                   //mov si, [bp-4]
    _ax = _ax ^ _ax;                            //xor ax, ax
    _cx = _stack16(_bp + -6);                   //mov cx, [bp-6]
    if (_cx == 0)                               //jcxz short locret_17A92
        goto locret_17A92;
loc_17A6C:                                      //loc_17A6C:
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _push(_ax);                                 //push ax
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _ax = memory16(_ds, _bx + _si);             //mov ax, [bx+si]
    _bx = _stack16(_bp + -10);                  //mov bx, [bp-0Ah]
    _push(_cs);                                 //push cs
    _ds = _pop();                               //pop ds
    if (_ax & 0x0001)                           //jnz short loc_17A85
        goto loc_17A85;
    sub_17A97();                                //call sub_17A97
    goto loc_17A88;                             //jmp short loc_17A88
loc_17A85:                                      //loc_17A85:
    sub_17AA9();                                //call sub_17AA9
loc_17A88:                                      //loc_17A88:
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _ax = _pop();                               //pop ax
    _ax += 1;                                   //inc ax
    if (_ax < _stack16(_bp + -6))               //jb short loc_17A6C
        goto loc_17A6C;
locret_17A92:                                   //locret_17A92:
    return;
}

void sub_17A97()
{
    if (memory16(_ds, 0xBE0) == 0x0000)         //jz short loc_17AA1
        goto loc_17AA1;
    sub_17B72();                                //call sub_17B72
loc_17AA1:                                      //loc_17AA1:
    memory16(_ds, 0xB03) = _ax;                 //mov word_191A3, ax
    memory16(_ds, 0xB05) = _bx;                 //mov word_191A5, bx
}

void sub_17AA9()
{
    if (memory16(_ds, 0xBE0) == 0x0000)         //jz short loc_17AB3
        goto loc_17AB3;
    sub_17B72();                                //call sub_17B72
loc_17AB3:                                      //loc_17AB3:
    _cx = _ax;                                  //mov cx, ax
    _dx = _bx;                                  //mov dx, bx
    _xchg(_cx, memory16(_ds, 0xB03));           //xchg cx, word_191A3
    _xchg(_dx, memory16(_ds, 0xB05));           //xchg dx, word_191A5
    if (_ax < _cx)                              //jb short loc_17AC4
        goto loc_17AC4;
    _xchg(_ax, _cx);                            //xchg ax, cx
loc_17AC4:                                      //loc_17AC4:
    if (memory(_ds, 0x97F) != 0x00)             //jnz short loc_17ACE
        goto loc_17ACE;
    {sub_17311(); return; };                    //
loc_17ACE:                                      //loc_17ACE:
    _si = 0x000c;                               //mov si, 0Ch
    dword_186E9();                              //call dword_186E9
}

void sub_17B72()
{
    _al = _al ^ _al;                            //xor al, al
}

void loc_17B9D()
{
    _stack16(_bp + -40) = _ax;                  //mov [bp-28h], ax
    if (memory16(_ds, _bp + 18) & 0xffff)       //jnz short loc_17BAA
        goto loc_17BAA;
    memory16(_ds, _bp + 18) += 1;               //inc word ptr [bp+12h]
loc_17BAA:                                      //loc_17BAA:
    if (memory16(_ds, _bp + 16) & 0xffff)       //jnz short loc_17BB4
        goto loc_17BB4;
    memory16(_ds, _bp + 16) += 1;               //inc word ptr [bp+10h]
loc_17BB4:                                      //loc_17BB4:
    _ax = _stack16(_bp + 16);                   //mov ax, [bp+10h]
    _bx = _stack16(_bp + 18);                   //mov bx, [bp+12h]
    if (_ax > _bx)                              //ja short loc_17BC0
        goto loc_17BC0;
    _ax = _bx;                                  //mov ax, bx
loc_17BC0:                                      //loc_17BC0:
    _mul(_ax);                                  //mul ax
    _bx = 0x0064;                               //mov bx, 64h
    sub_17DA9();                                //call sub_17DA9
    if (_FIXME_)                                //jnb short loc_17BCD
        goto loc_17BCD;
    goto loc_17C9E;                             //jmp loc_17C9E
loc_17BCD:                                      //loc_17BCD:
    _stack16(_bp + -36) = _ax;                  //mov [bp-24h], ax
    _stack16(_bp + -34) = _dx;                  //mov [bp-22h], dx
    _bx = _stack16(_bp + 18);                   //mov bx, [bp+12h]
    sub_17D97();                                //call sub_17D97
    sub_17D97();                                //call sub_17D97
    _stack16(_bp + -8) = _ax;                   //mov [bp-8], ax
    _stack16(_bp + -6) = _dx;                   //mov [bp-6], dx
    _ax = _ax ^ _ax;                            //xor ax, ax
    _stack16(_bp + -2) = _ax;                   //mov [bp-2], ax
    _stack16(_bp + -20) = _ax;                  //mov [bp-14h], ax
    _stack16(_bp + -18) = _ax;                  //mov [bp-12h], ax
    _ax = _stack16(_bp + -36);                  //mov ax, [bp-24h]
    _dx = _stack16(_bp + -34);                  //mov dx, [bp-22h]
    _bx = _stack16(_bp + 16);                   //mov bx, [bp+10h]
    _stack16(_bp + -4) = _bx;                   //mov [bp-4], bx
    sub_17D97();                                //call sub_17D97
    sub_17D97();                                //call sub_17D97
    _stack16(_bp + -12) = _ax;                  //mov [bp-0Ch], ax
    _stack16(_bp + -10) = _dx;                  //mov [bp-0Ah], dx
    sub_17DA9();                                //call sub_17DA9
    if (_FIXME_)                                //jnb short loc_17C0D
        goto loc_17C0D;
    goto loc_17C9E;                             //jmp loc_17C9E
loc_17C0D:                                      //loc_17C0D:
    _si = _dx;                                  //mov si, dx
    _di = _ax;                                  //mov di, ax
    sub_17DA9();                                //call sub_17DA9
    if (_FIXME_)                                //jnb short loc_17C19
        goto loc_17C19;
    goto loc_17C9E;                             //jmp loc_17C9E
loc_17C19:                                      //loc_17C19:
    _flags.carry = _ax < _stack16(_bp + -36);   //sub ax, [bp-24h]
    _ax = _ax - _stack16(_bp + -36);
    _dx -= _stack16(_bp + -34) + _flags.carry;  //sbb dx, [bp-22h]
    _stack16(_bp + -16) = _ax;                  //mov [bp-10h], ax
    _stack16(_bp + -14) = _dx;                  //mov [bp-0Eh], dx
    _flags.carry = !!(_di & 0x8000);            //shl di, 1
    _di <<= 1;
    _rcl(_si, 1);                               //rcl si, 1
    _stack16(_bp + -24) = _di;                  //mov [bp-18h], di
    _stack16(_bp + -22) = _si;                  //mov [bp-16h], si
loc_17C2F:                                      //loc_17C2F:
    sub_17D0D();                                //call sub_17D0D
    sub_17CA4();                                //call sub_17CA4
    _ax = _stack16(_bp + -16);                  //mov ax, [bp-10h]
    _bx = _stack16(_bp + -14);                  //mov bx, [bp-0Eh]
    _flags.carry = (_ax + _ax) >= 0x10000;      //add ax, ax
    _ax += _ax;
    _bx = _bx + _bx + _flags.carry;             //adc bx, bx
    _flags.carry = (_ax + _stack16(_bp + -28)) >= 0x10000;
    _ax = _ax + _stack16(_bp + -28);
    _bx = _bx + _stack16(_bp + -26) + _flags.carry;//adc bx, [bp-1Ah]
    _flags.carry = (_ax + _stack16(_bp + -28)) >= 0x10000;
    _ax = _ax + _stack16(_bp + -28);
    _bx = _bx + _stack16(_bp + -26) + _flags.carry;//adc bx, [bp-1Ah]
    if ((short)_bx < (short)_stack16(_bp + -30))//jl short loc_17C5A
        goto loc_17C5A;
    if (_bx != _stack16(_bp + -30))             //jnz short loc_17C57
        goto loc_17C57;
    if (_ax < _stack16(_bp + -32))              //jb short loc_17C5A
        goto loc_17C5A;
loc_17C57:                                      //loc_17C57:
    sub_17CEB();                                //call sub_17CEB
loc_17C5A:                                      //loc_17C5A:
    sub_17CC9();                                //call sub_17CC9
    _ax = _stack16(_bp + -18);                  //mov ax, [bp-12h]
    if ((short)_ax < (short)_stack16(_bp + -22))//jl short loc_17C2F
        goto loc_17C2F;
    if (_ax != _stack16(_bp + -22))             //jnz short loc_17C6F
        goto loc_17C6F;
    _ax = _stack16(_bp + -20);                  //mov ax, [bp-14h]
    if (_ax < _stack16(_bp + -24))              //jb short loc_17C2F
        goto loc_17C2F;
loc_17C6F:                                      //loc_17C6F:
    sub_17D0D();                                //call sub_17D0D
    sub_17CA4();                                //call sub_17CA4
    _ax = _stack16(_bp + -28);                  //mov ax, [bp-1Ch]
    _bx = _stack16(_bp + -26);                  //mov bx, [bp-1Ah]
    _flags.carry = _bx & 1;                     //shr bx, 1
    _bx >>= 1;
    _rcr(_ax, 1);                               //rcr ax, 1
    _flags.carry = (_ax + _stack16(_bp + -16)) >= 0x10000;
    _ax = _ax + _stack16(_bp + -16);
    _bx = _bx + _stack16(_bp + -14) + _flags.carry;//adc bx, [bp-0Eh]
    if ((short)_bx > (short)_stack16(_bp + -30))//jg short loc_17C94
        goto loc_17C94;
    if (_bx != _stack16(_bp + -30))             //jnz short loc_17C91
        goto loc_17C91;
    if (_ax > _stack16(_bp + -32))              //ja short loc_17C94
        goto loc_17C94;
loc_17C91:                                      //loc_17C91:
    sub_17CC9();                                //call sub_17CC9
loc_17C94:                                      //loc_17C94:
    sub_17CEB();                                //call sub_17CEB
    if (!(_FIXME_ & 0x8000))                    //jz short loc_17C6F
        goto loc_17C6F;
loc_17C9E:                                      //loc_17C9E:
    _sp = _bp;                                  //mov sp, bp
    _bp = _pop();                               //pop bp
    _stackReduce(20);                           //retn 14h
    return;
}

void sub_17CA4()
{
    _ax = _stack16(_bp + -20);                  //mov ax, [bp-14h]
    _ax = _ax + _stack16(_bp + -8);             //add ax, [bp-8]
    _stack16(_bp + -28) = _ax;                  //mov [bp-1Ch], ax
    _ax = _stack16(_bp + -18);                  //mov ax, [bp-12h]
    _ax = _ax + _stack16(_bp + -6) + _flags.carry; _ASSERT(0);
    _stack16(_bp + -26) = _ax;                  //mov [bp-1Ah], ax
    _ax = _stack16(_bp + -24);                  //mov ax, [bp-18h]
    _ax = _ax - _stack16(_bp + -12);            //sub ax, [bp-0Ch]
    _stack16(_bp + -32) = _ax;                  //mov [bp-20h], ax
    _ax = _stack16(_bp + -22);                  //mov ax, [bp-16h]
    _FIXME_;                                    //sbb ax, [bp-0Ah]
    _stack16(_bp + -30) = _ax;                  //mov [bp-1Eh], ax
}

void sub_17CC9()
{
    _FIXME_ += 1;                               //inc word ptr [bp-2]
    _ax = _stack16(_bp + -28);                  //mov ax, [bp-1Ch]
    _stack16(_bp + -16) += _ax;                 //add [bp-10h], ax
    _ax = _stack16(_bp + -26);                  //mov ax, [bp-1Ah]
    _stack16(_bp + -14) = _stack16(_bp + -14) + _ax + _flags.carry; _ASSERT(0);
    _ax = _stack16(_bp + -28);                  //mov ax, [bp-1Ch]
    _ax = _ax + _stack16(_bp + -8);             //add ax, [bp-8]
    _stack16(_bp + -20) = _ax;                  //mov [bp-14h], ax
    _ax = _stack16(_bp + -26);                  //mov ax, [bp-1Ah]
    _ax = _ax + _stack16(_bp + -6) + _flags.carry; _ASSERT(0);
    _stack16(_bp + -18) = _ax;                  //mov [bp-12h], ax
}

void sub_17CEB()
{
    _FIXME_ -= 1;                               //dec word ptr [bp-4]
    _ax = _stack16(_bp + -32);                  //mov ax, [bp-20h]
    _stack16(_bp + -16) -= _ax;                 //sub [bp-10h], ax
    _ax = _stack16(_bp + -30);                  //mov ax, [bp-1Eh]
    _FIXME_;                                    //sbb [bp-0Eh], ax
    _ax = _stack16(_bp + -32);                  //mov ax, [bp-20h]
    _ax = _ax - _stack16(_bp + -12);            //sub ax, [bp-0Ch]
    _stack16(_bp + -24) = _ax;                  //mov [bp-18h], ax
    _ax = _stack16(_bp + -30);                  //mov ax, [bp-1Eh]
    _FIXME_;                                    //sbb ax, [bp-0Ah]
    _stack16(_bp + -22) = _ax;                  //mov [bp-16h], ax
}

void sub_17D0D()
{
    _dx = _stack16(_bp + 14);                   //mov dx, [bp+0Eh]
    _si = _stack16(_bp + -2);                   //mov si, [bp-2]
    _di = _stack16(_bp + -4);                   //mov di, [bp-4]
    if (memory16(_ds, _bp + 12) & 0x8000)       //jnz short loc_17D3C
        { loc_17D3C(); return; }
    sub_17D2E();                                //call sub_17D2E
    _si = -_si;                                 //neg si
    sub_17D2E();                                //call sub_17D2E
    _si = -_si;                                 //neg si
    _di = -_di;                                 //neg di
    sub_17D2E();                                //call sub_17D2E
    _si = -_si;                                 //neg si
    _STOP_("sp-trace-fail");                    //sub_17D0D endp_failed
    _STOP_("continues");                        //sub_17D2E proc near
}

void sub_17D2E()
{
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _si = _si + _stack16(_bp + 22);             //add si, [bp+16h]
    _di = _di + _stack16(_bp + 20);             //add di, [bp+14h]
    sub_17DB7();                                //call sub_17DB7
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
}

void loc_17D3C()
{
    sub_17D4D();                                //call sub_17D4D
    _si = -_si;                                 //neg si
    sub_17D4D();                                //call sub_17D4D
    _si = -_si;                                 //neg si
    _di = -_di;                                 //neg di
    sub_17D4D();                                //call sub_17D4D
    _si = -_si;                                 //neg si
}

void sub_17D4D()
{
    _ax = _si;                                  //mov ax, si
    _bx = _di;                                  //mov bx, di
    sub_17D70();                                //call sub_17D70
    if (_stack16(_bp + -42) != 0x00)            //jnz short loc_17D65
        goto loc_17D65;
    if ((short)_ax < (short)_stack16(_bp + -38))//jl short locret_17D64
        goto locret_17D64;
    if ((short)_ax <= (short)_stack16(_bp + -40))//jle short sub_17D2E
        { sub_17D2E(); return; }
locret_17D64:                                   //locret_17D64:
    return;                                     //retn
loc_17D65:                                      //loc_17D65:
    if ((short)_ax >= (short)_stack16(_bp + -38))//jge short sub_17D2E
        { sub_17D2E(); return; }
    if ((short)_ax <= (short)_stack16(_bp + -40))//jle short sub_17D2E
        { sub_17D2E(); return; }
}

void sub_17D70()
{
    _bx = -_bx;                                 //neg bx
    _flags.sign = !!(_ah & 0x80);               //or ah, ah
    _ah |= _ah;
    if (_flags.sign)                            //js short loc_17D85
        goto loc_17D85;
    _flags.sign = !!(_bh & 0x80);               //or bh, bh
    _bh |= _bh;
    if (_flags.sign)                            //js short loc_17D7F
        goto loc_17D7F;
    _bx -= _ax;                                 //sub bx, ax
    _ax = _bx;                                  //mov ax, bx
    return;                                     //retn
loc_17D7F:                                      //loc_17D7F:
    _ax += 0x1770;                              //add ax, 1770h
    _ax += _bx;                                 //add ax, bx
    return;                                     //retn
loc_17D85:                                      //loc_17D85:
    _flags.sign = !!(_bh & 0x80);               //or bh, bh
    _bh |= _bh;
    if (_flags.sign)                            //js short loc_17D91
        goto loc_17D91;
    _ax = -_ax;                                 //neg ax
    _ax += 0x07d0;                              //add ax, 7D0h
    _ax -= _bx;                                 //sub ax, bx
    return;                                     //retn
loc_17D91:                                      //loc_17D91:
    _ax += 0x0fa0;                              //add ax, 0FA0h
    _ax -= _bx;                                 //sub ax, bx
}

void sub_17D97()
{
    _bx |= _bx;                                 //or bx, bx
    _flags.carry = true;                        //stc
    if (_bx == 0)                               //jz short locret_17DA8
        goto locret_17DA8;
    _cx = _cx ^ _cx;                            //xor cx, cx
    _xchg(_cx, _dx);                            //xchg cx, dx
    _xchg(_ax, _cx);                            //xchg ax, cx
    _div(_bx);                                  //div bx
    _xchg(_ax, _cx);                            //xchg ax, cx
    _div(_bx);                                  //div bx
    _xchg(_cx, _dx);                            //xchg cx, dx
locret_17DA8:                                   //locret_17DA8:
    return;
}

void sub_17DA9()
{
    _cx = _ax;                                  //mov cx, ax
    _ax = _dx;                                  //mov ax, dx
    _mul(_bx);                                  //mul bx
    if (_flags.carry)                           //jb short locret_17DB6
        goto locret_17DB6;
    _xchg(_ax, _cx);                            //xchg ax, cx
    _mul(_bx);                                  //mul bx
    _dx += _cx;                                 //add dx, cx
locret_17DB6:                                   //locret_17DB6:
    return;
}

void sub_17DB7()
{
    _ax = _si;                                  //mov ax, si
    _bx = _di;                                  //mov bx, di
    {sub_172BC(); return; };                    //
}

void sub_17EEC()
{
    memory(_ds, 0x5C) = 0x01;                   //mov byte_186FC, 1
    sub_180DE();                                //call sub_180DE
    if (!_flags.carry)                          //jnb short loc_17F02
        goto loc_17F02;
    _xchg(_ax, _cx);                            //xchg ax, cx
    _xchg(_bx, _dx);                            //xchg bx, dx
    sub_180DE();                                //call sub_180DE
    _xchg(_ax, _cx);                            //xchg ax, cx
    _xchg(_bx, _dx);                            //xchg bx, dx
    if (!_flags.carry)                          //jnb short loc_17F02
        goto loc_17F02;
    return;                                     //retn
loc_17F02:                                      //loc_17F02:
    memory16(_ds, 0xF54) = _ax;                 //mov ds:0F54h, ax
    memory16(_ds, 0xF56) = _bx;                 //mov ds:0F56h, bx
    memory16(_ds, 0xF58) = _cx;                 //mov ds:0F58h, cx
    memory16(_ds, 0xF5A) = _dx;                 //mov ds:0F5Ah, dx
    sub_17F37();                                //call sub_17F37
    if (memory(_ds, 0x5C) == 0x00)              //jz short loc_17F2C
        goto loc_17F2C;
    _ax = memory16(_ds, 0xF54);                 //mov ax, ds:0F54h
    _bx = memory16(_ds, 0xF56);                 //mov bx, ds:0F56h
    _cx = memory16(_ds, 0xF58);                 //mov cx, ds:0F58h
    _dx = memory16(_ds, 0xF5A);                 //mov dx, ds:0F5Ah
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_17F2C:                                      //loc_17F2C:
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _bx = _ax;                                  //mov bx, ax
    _cx = _ax;                                  //mov cx, ax
    _dx = _ax;                                  //mov dx, ax
    _flags.carry = false;                       //clc
}

void sub_17F37()
{
    _bx = 0x0f54;                               //mov bx, 0F54h
    sub_1802F();                                //call sub_1802F
    _ch = _al;                                  //mov ch, al
    _bx = 0x0f58;                               //mov bx, 0F58h
    sub_1802F();                                //call sub_1802F
    _al |= _ch;                                 //or al, ch
    if (_al != 0)                               //jnz short loc_17F4A
        goto loc_17F4A;
    return;                                     //retn
loc_17F4A:                                      //loc_17F4A:
    _ax = memory16(_ds, 0xF58);                 //mov ax, ds:0F58h
    _ax = _ax - memory16(_ds, 0xF54);           //sub ax, ds:0F54h
    memory16(_ds, 0xF50) = _ax;                 //mov ds:0F50h, ax
    if (_ax == 0)                               //jz short loc_17F60
        goto loc_17F60;
    _ax = memory16(_ds, 0xF5A);                 //mov ax, ds:0F5Ah
    _ax = _ax - memory16(_ds, 0xF56);           //sub ax, ds:0F56h
    memory16(_ds, 0xF52) = _ax;                 //mov ds:0F52h, ax
loc_17F60:                                      //loc_17F60:
    _bx = 0x0f54;                               //mov bx, 0F54h
    sub_1802F();                                //call sub_1802F
    _ch = _al;                                  //mov ch, al
    _bx = 0x0f58;                               //mov bx, 0F58h
    sub_1802F();                                //call sub_1802F
    _dl = _al;                                  //mov dl, al
    _al |= _ch;                                 //or al, ch
    if (_al != 0)                               //jnz short loc_17F75
        goto loc_17F75;
    return;                                     //retn
loc_17F75:                                      //loc_17F75:
    _dl &= _ch;                                 //and dl, ch
    if (_dl == 0)                               //jz short loc_17F7F
        goto loc_17F7F;
    memory(_ds, 0x5C) = 0x00;                   //mov byte_186FC, 0
    return;                                     //retn
loc_17F7F:                                      //loc_17F7F:
    _ch &= _ch;                                 //and ch, ch
    if (_ch != 0)                               //jnz short loc_17F86
        goto loc_17F86;
    sub_1805B();                                //call sub_1805B
loc_17F86:                                      //loc_17F86:
    memory(_ds, 0x5C) = 0x02;                   //mov byte_186FC, 2
    if (memory16(_ds, 0xF50) != 0x0000)         //jnz short loc_17FB0
        goto loc_17FB0;
    _ax = memory16(_ds, 0xF56);                 //mov ax, ds:0F56h
    if ((short)_ax >= (short)memory16(_ds, 0x63))//jge short loc_17FA1
        goto loc_17FA1;
    _ax = memory16(_ds, 0x63);                  //mov ax, word_18703
    memory16(_ds, 0xF56) = _ax;                 //mov ds:0F56h, ax
loc_17FA1:                                      //loc_17FA1:
    _ax = memory16(_ds, 0x67);                  //mov ax, word_18707
    if ((short)_ax >= (short)memory16(_ds, 0xF56))//jge short loc_17FAD
        goto loc_17FAD;
    memory16(_ds, 0xF56) = _ax;                 //mov ds:0F56h, ax
loc_17FAD:                                      //loc_17FAD:
    goto loc_18025;                             //jmp short loc_18025
loc_17FB0:                                      //loc_17FB0:
    if (memory16(_ds, 0xF52) != 0x0000)         //jnz short loc_17FD5
        goto loc_17FD5;
    _ax = memory16(_ds, 0xF54);                 //mov ax, ds:0F54h
    if ((short)_ax >= (short)memory16(_ds, 0x61))//jge short loc_17FC6
        goto loc_17FC6;
    _ax = memory16(_ds, 0x61);                  //mov ax, word_18701
    memory16(_ds, 0xF54) = _ax;                 //mov ds:0F54h, ax
loc_17FC6:                                      //loc_17FC6:
    _ax = memory16(_ds, 0x65);                  //mov ax, word_18705
    if ((short)_ax >= (short)memory16(_ds, 0xF54))//jge short loc_17FD2
        goto loc_17FD2;
    memory16(_ds, 0xF54) = _ax;                 //mov ds:0F54h, ax
loc_17FD2:                                      //loc_17FD2:
    goto loc_18025;                             //jmp short loc_18025
    _STOP_("db 90h");                           //db 90h
loc_17FD5:                                      //loc_17FD5:
    _ax = memory16(_ds, 0xF54);                 //mov ax, ds:0F54h
    if ((short)_ax >= (short)memory16(_ds, 0x61))//jge short loc_17FEB
        goto loc_17FEB;
    _ax = memory16(_ds, 0x61);                  //mov ax, word_18701
    _push(_ax);                                 //push ax
    sub_18081();                                //call sub_18081
    memory16(_ds, 0xF54) = _pop();              //pop word ptr ds:0F54h
    goto loc_18025;                             //jmp short loc_18025
loc_17FEB:                                      //loc_17FEB:
    _ax = memory16(_ds, 0x65);                  //mov ax, word_18705
    if ((short)_ax >= (short)memory16(_ds, 0xF54))//jge short loc_17FFE
        goto loc_17FFE;
    _push(_ax);                                 //push ax
    sub_18081();                                //call sub_18081
    memory16(_ds, 0xF54) = _pop();              //pop word ptr ds:0F54h
    goto loc_18025;                             //jmp short loc_18025
loc_17FFE:                                      //loc_17FFE:
    _ax = memory16(_ds, 0xF56);                 //mov ax, ds:0F56h
    if ((short)_ax >= (short)memory16(_ds, 0x63))//jge short loc_18014
        goto loc_18014;
    _ax = memory16(_ds, 0x63);                  //mov ax, word_18703
    _push(_ax);                                 //push ax
    sub_18070();                                //call sub_18070
    memory16(_ds, 0xF56) = _pop();              //pop word ptr ds:0F56h
    goto loc_18025;                             //jmp short loc_18025
loc_18014:                                      //loc_18014:
    _ax = memory16(_ds, 0x67);                  //mov ax, word_18707
    if ((short)_ax >= (short)memory16(_ds, 0xF56))//jge short loc_18025
        goto loc_18025;
    _push(_ax);                                 //push ax
    sub_18070();                                //call sub_18070
    memory16(_ds, 0xF56) = _pop();              //pop word ptr ds:0F56h
loc_18025:                                      //loc_18025:
    _ch &= _ch;                                 //and ch, ch
    if (_ch != 0)                               //jnz short loc_1802C
        goto loc_1802C;
    sub_1805B();                                //call sub_1805B
loc_1802C:                                      //loc_1802C:
    goto loc_17F60;                             //jmp loc_17F60
}

void sub_1802F()
{
    _dl = _dl ^ _dl;                            //xor dl, dl
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    if ((short)_ax >= (short)memory16(_ds, 0x61))//jge short loc_1803B
        goto loc_1803B;
    _dl = 0x01;                                 //mov dl, 1
loc_1803B:                                      //loc_1803B:
    if ((short)_ax <= (short)memory16(_ds, 0x65))//jle short loc_18043
        goto loc_18043;
    _dl = 0x02;                                 //mov dl, 2
loc_18043:                                      //loc_18043:
    _ax = memory16(_ds, _bx + 2);               //mov ax, [bx+2]
    if ((short)_ax >= (short)memory16(_ds, 0x63))//jge short loc_1804F
        goto loc_1804F;
    _dl += 0x04;                                //add dl, 4
loc_1804F:                                      //loc_1804F:
    if ((short)_ax <= (short)memory16(_ds, 0x67))//jle short loc_18058
        goto loc_18058;
    _dl += 0x08;                                //add dl, 8
loc_18058:                                      //loc_18058:
    _al = _dl;                                  //mov al, dl
}

void sub_1805B()
{
    _ax = memory16(_ds, 0xF54);                 //mov ax, ds:0F54h
    _xchg(_ax, memory16(_ds, 0xF58));           //xchg ax, ds:0F58h
    memory16(_ds, 0xF54) = _ax;                 //mov ds:0F54h, ax
    _ax = memory16(_ds, 0xF56);                 //mov ax, ds:0F56h
    _xchg(_ax, memory16(_ds, 0xF5A));           //xchg ax, ds:0F5Ah
    memory16(_ds, 0xF56) = _ax;                 //mov ds:0F56h, ax
}

void sub_18070()
{
    _ax = _ax - memory16(_ds, 0xF56);           //sub ax, ds:0F56h
    _imul(memory16(_ds, 0xF50));                //imul word ptr ds:0F50h
    _idiv(memory16(_ds, 0xF52));                //idiv word ptr ds:0F52h
    memory16(_ds, 0xF54) += _ax;                //add ds:0F54h, ax
}

void sub_18081()
{
    _ax = _ax - memory16(_ds, 0xF54);           //sub ax, ds:0F54h
    _imul(memory16(_ds, 0xF52));                //imul word ptr ds:0F52h
    _idiv(memory16(_ds, 0xF50));                //idiv word ptr ds:0F50h
    memory16(_ds, 0xF56) += _ax;                //add ds:0F56h, ax
}

void sub_18092()
{
    sub_180DE();                                //call sub_180DE
    if (_flags.carry)                           //jb short loc_180AC
        goto loc_180AC;
    _xchg(_bx, _dx);                            //xchg bx, dx
    sub_180DE();                                //call sub_180DE
    if (_flags.carry)                           //jb short loc_180AC
        goto loc_180AC;
    _xchg(_ax, _cx);                            //xchg ax, cx
    sub_180DE();                                //call sub_180DE
    if (_flags.carry)                           //jb short loc_180AC
        goto loc_180AC;
    _xchg(_bx, _dx);                            //xchg bx, dx
    sub_180DE();                                //call sub_180DE
    _xchg(_ax, _cx);                            //xchg ax, cx
    if (!_flags.carry)                          //jnb short locret_180CF
        goto locret_180CF;
loc_180AC:                                      //loc_180AC:
    _di = memory16(_ds, 0x61);                  //mov di, word_18701
    _si = memory16(_ds, 0x65);                  //mov si, word_18705
    sub_180D0();                                //call sub_180D0
    _xchg(_ax, _cx);                            //xchg ax, cx
    sub_180D0();                                //call sub_180D0
    _xchg(_ax, _cx);                            //xchg ax, cx
    _di = memory16(_ds, 0x63);                  //mov di, word_18703
    _si = memory16(_ds, 0x67);                  //mov si, word_18707
    _xchg(_ax, _bx);                            //xchg ax, bx
    sub_180D0();                                //call sub_180D0
    _xchg(_ax, _bx);                            //xchg ax, bx
    _xchg(_ax, _dx);                            //xchg ax, dx
    sub_180D0();                                //call sub_180D0
    _xchg(_ax, _dx);                            //xchg ax, dx
    _flags.carry = true;                        //stc
locret_180CF:                                   //locret_180CF:
    return;
}

void sub_180D0()
{
    if ((short)_ax >= (short)_di)               //jge short loc_180D7
        goto loc_180D7;
    _ax = _di;                                  //mov ax, di
    return;                                     //retn
loc_180D7:                                      //loc_180D7:
    if (_ax <= _si)                             //jbe short locret_180DD
        goto locret_180DD;
    _ax = _si;                                  //mov ax, si
locret_180DD:                                   //locret_180DD:
    return;
}

void sub_180DE()
{
    if (_ax > memory16(_ds, 0x65))              //ja short loc_180F8
        goto loc_180F8;
    if (_bx > memory16(_ds, 0x67))              //ja short loc_180F8
        goto loc_180F8;
    if ((short)_ax < (short)memory16(_ds, 0x61))//jl short loc_180F8
        goto loc_180F8;
    if ((short)_bx < (short)memory16(_ds, 0x63))//jl short loc_180F8
        goto loc_180F8;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_180F8:                                      //loc_180F8:
    _flags.carry = false;                       //clc
}


// imports
void dword_186E9() { _ASSERT(0); }
void dword_18AB2() { _ASSERT(0); }
void loc_11A54() { _ASSERT(0); }
void loc_11A6A() { _ASSERT(0); }
void loc_11A80() { _ASSERT(0); }
void loc_11A96() { _ASSERT(0); }
void loc_11ABB() { _ASSERT(0); }
void loc_11AF6() { _ASSERT(0); }
void loc_11D4D() { _ASSERT(0); }
void loc_11D64() { _ASSERT(0); }
void loc_11D7B() { _ASSERT(0); }
void loc_11D92() { _ASSERT(0); }
void loc_11DCD() { _ASSERT(0); }
void loc_11E0A() { _ASSERT(0); }
void loc_12209() { _ASSERT(0); }
void loc_12213() { _ASSERT(0); }
void loc_12221() { _ASSERT(0); }
void loc_1223C() { _ASSERT(0); }
void loc_12247() { _ASSERT(0); }
void loc_12256() { _ASSERT(0); }
void loc_13D42() { _ASSERT(0); }
void loc_13D47() { _ASSERT(0); }
void loc_13D51() { _ASSERT(0); }
void loc_13D5D() { _ASSERT(0); }
void loc_13D66() { _ASSERT(0); }
void loc_13D70() { _ASSERT(0); }
void loc_14C60() { _ASSERT(0); }
void loc_14C6C() { _ASSERT(0); }
void loc_14C78() { _ASSERT(0); }
void loc_14C8A() { _ASSERT(0); }
void loc_14C94() { _ASSERT(0); }
void loc_14C9E() { _ASSERT(0); }
void loc_14CB6() { _ASSERT(0); }
void loc_14CDA() { _ASSERT(0); }
void loc_14CE3() { _ASSERT(0); }
void loc_14D19() { _ASSERT(0); }
void loc_14D22() { _ASSERT(0); }
void loc_14D2B() { _ASSERT(0); }
void loc_14D2F() { _ASSERT(0); }
void loc_14D33() { _ASSERT(0); }
void loc_14D50() { _ASSERT(0); }
void loc_14DA1() { _ASSERT(0); }
void loc_14DF3() { _ASSERT(0); }
void loc_14E13() { _ASSERT(0); }
void loc_14E54() { _ASSERT(0); }
void loc_14FA1() { _ASSERT(0); }
void loc_14FCD() { _ASSERT(0); }
void loc_1528E() { _ASSERT(0); }
void loc_15299() { _ASSERT(0); }
void loc_152A4() { _ASSERT(0); }
void loc_152AF() { _ASSERT(0); }
void loc_152B9() { _ASSERT(0); }
void loc_152CC() { _ASSERT(0); }
void loc_152D7() { _ASSERT(0); }
void loc_152E2() { _ASSERT(0); }
void loc_152ED() { _ASSERT(0); }
void loc_152F7() { _ASSERT(0); }
void loc_15301() { _ASSERT(0); }
void loc_1530B() { _ASSERT(0); }
void loc_15315() { _ASSERT(0); }
void loc_1531F() { _ASSERT(0); }
void loc_15331() { _ASSERT(0); }
void loc_1533B() { _ASSERT(0); }
void loc_156A4() { _ASSERT(0); }
void loc_156AE() { _ASSERT(0); }
void loc_156B8() { _ASSERT(0); }
void loc_156C2() { _ASSERT(0); }
void loc_156D4() { _ASSERT(0); }
void loc_156DE() { _ASSERT(0); }
void loc_15975() { _ASSERT(0); }
void loc_15989() { _ASSERT(0); }
void loc_159A3() { _ASSERT(0); }
void off_18A82() { _ASSERT(0); }
void off_18A84() { _ASSERT(0); }
void off_18A86() { _ASSERT(0); }
void off_18FF8() { _ASSERT(0); }
void off_18FFA() { _ASSERT(0); }
void off_18FFC() { _ASSERT(0); }

