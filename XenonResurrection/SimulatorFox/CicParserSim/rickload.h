void sub_0100();
void sub_0134();
void sub_0267();
void sub_02ad();
void loc_01ba();
void loc_0191();
void loc_0132();                                       //

void sub_0100()
{
    _sp = 0x0662;                               //
    _ax = _ax ^ _ax;                            //
    _push(_ax);                                 //
    _lea(_ax, _ds, 0x02bb);                     //
    _push(_ax);                                 //
    _sp += 0x0002;                              //
    _ax |= _ax;                                 //
    sub_0134();                                 //
    _push(_ax);                                 //
    sub_02ad();                                 //
    _lea(_si, _ds, 0x0543);                     //
    sub_0267();                                 // Loading rick dangerous...
    _ax = _pop();                               //
    _ax -= 1;                                   //
    _ax <<= 1;                                  //
    _lea(_si, _ds, 0x02e1);                     //
    _si += _ax;                                 //
    _si = memory16(_ds, _si);                   //
    loc_0191();                    //
    return;
}

void loc_0132()                                       //
{
    _interrupt(32);                             //
    sub_0134();
}

void sub_0134()
{

    _ah = memory(_ds, 128);                     //
    _al = memory(_ds, 0x82);                    //
    if (_ah >= 0x02)                            //
        goto loc_015c;
    sub_02ad();                                 //
    _lea(_si, _ds, 0x02e7);                     //
    sub_0267();                                 //
    _lea(_si, _ds, 0x04fe);                     //
    sub_0267();                                 //
    _lea(_si, _ds, 0x051b);                     //
    sub_0267();                                 //
loc_0158:                                       //
    _ax = _ax ^ _ax;                            //
    _interrupt(22);                             //
    
    _al = 0x31; // gabo
    
loc_015c:                                       //
    if (_al == 0x31)                            //
        goto loc_018c;
    if (_al == 0x32)                            //
        goto loc_018c;
    if (_al == 0x33)                            //
        goto loc_018c;
    _al &= 0xdf;                                //
    if (_al != 0x45)                            //
        goto loc_0173;
    _al = 0x31;                                 //
    goto loc_018c;                              //
loc_0173:                                       //
    if (_al != 0x43)                            //
        goto loc_017c;
    _al = 0x32;                                 //
    goto loc_018c;                              //
loc_017c:                                       //
    if (_al != 0x54)                            //
        goto loc_0185;
    _al = 0x33;                                 //
    goto loc_018c;                              //
loc_0185:                                       //
    if (_ah != 0x01)                            //
        goto loc_0158;
    loc_0132();                    //
    return;
loc_018c:                                       //
    _al -= 0x30;                                //
    _ah = _ah ^ _ah;                            //
    return;                                     //
}
void loc_0191()                                       //
{
    _ax = _cs;                                  //
    _ds = _ax;                                  //
    _es = _ax;                                  //
    _ah = 0x4a;                                 //
    _bx = 0x0661;                               //
    _bx >>= 1;                                  //
    _bx >>= 1;                                  //
    _bx >>= 1;                                  //
    _bx >>= 1;                                  //
    _bx += 1;                                   //
     _interrupt(33);                             //
    _ah = 0x48;                                 //
    _bx = 0xffff;                               //
    _interrupt(33);                             //
    _ah = 0x48;                                 //
    _interrupt(33);                             //
    _bp = _ax;                                  //
    _ax = _ax ^ _ax;                            //
    _di = _di ^ _di;                            //
    _dx = _si;                                  //
    loc_01ba();
}

void loc_01ba()                                       //
{
loc_01ba:
    _lodsb<MemData, DirForward>();              //
    _al |= _al;                                 //
    if (_al == 0)                               //
        goto loc_01c3;
    _di += _ax;                                 //
    goto loc_01ba;                              //
loc_01c3:                                       //
    _ax = 0x3d00;                               //
    _interrupt(33);                             //
    if (_flags.carry)                           //
        goto loc_01f3;
    _bx = _ax;                                  //
    _ax = 0x3f00;                               //
    _cx = 0x0200;                               //
    _dx = _dx ^ _dx;                            //
    _ds = _bp;                                  //
    _interrupt(33);                             //
    if (_flags.carry)                           //
        goto loc_01f3;
    if (_ax != _cx)                             //
        goto loc_01f3;
    _cx = _ax;                                  //
    _si = _dx;                                  //
loc_01e2:                                       //
    _ax = _di;                                  //
    memory(_ds, _si) = memory(_ds, _si) ^ _ah;  //
    _si += 1;                                   //
    _ax <<= 1;                                  //
    _ax <<= 1;                                  //
    _di += _ax;                                 //
    _di += 1;                                   //
    if (--_cx)                                  //
        goto loc_01e2;
    goto loc_01f6;                              //
loc_01f3:                                       //
    loc_0132();                    //
    return;
loc_01f6:                                       //
    _ax = 0x3f00;                               //
    _cx = 0x8000;                               //
    _dx = 0x0100;                               //
    _interrupt(33);                             //
    if (_flags.carry)                           //
        goto loc_01f3;
    _ax |= _ax;                                 //
    if (_ax == 0)                               //
        goto loc_0223;
    _cx = _ax;                                  //
    _si = _dx;                                  //
loc_020b:                                       //
    _ax = _di;                                  //
    memory(_ds, _si) = memory(_ds, _si) ^ _ah;  //
    _si += 1;                                   //
    _ax <<= 1;                                  //
    _ax <<= 1;                                  //
    _di += _ax;                                 //
    _di += 1;                                   //
    if (--_cx)                                  //
        goto loc_020b;
    _si = _ds;                                  //
    _si += 0x0800;                              //
    _ds = _si;                                  //
    goto loc_01f6;                              //
loc_0223:                                       //
    _ax = 0x3e00;                               //
    _interrupt(33);                             //
    if (_flags.carry)                           //
        goto loc_01f3;
    _ax = _bp;                                  //
    _ax -= 1;                                   //
    _ds = _ax;                                  // ds=one paragraph before buffer
    _ax = memory16(_ds, 0x0003);                // ax=9dba
_ax = 0x4000; // gabo
    return;
    _ds = _bp;                                  // ds245
    if (_ax < memory16(_ds, 10))                // ds:000a = 0907
        goto loc_01f3;
    _ax = memory16(_ds, 0x000e);                // 26f7 (initial stack offset)
    _ax += _bp;                                 // begin of new exe
    _ax += 0x0010;                              //
    _ss = _ax;                                  // 294c
    _sp = memory16(_ds, 16);                    // initial SP
    _ax = memory16(_ds, 0x0016);                // initial CS
    _ax += _bp;                                 //
    _ax += 0x0010;                              //
    _push(_ax);                                 // new CS
    _push(memory16(_ds, 20));                   // IP
    _si = _si ^ _si;                            //
    _di = _di ^ _di;                            //
    _es = _bp;                                  //
    _ax = _cs;                                  //
    _ds = _ax;                                  //
    _cx = 0x0080;                               //
    _rep_movsw<MemData, MemData, DirForward>(); // overwrite exe header
    _ds = _bp;                                  //
}

void sub_0267()
{
    _lodsw<MemData, DirForward>();              //
    _xchg(_al, _ah);                            //
    _dx = _ax;                                  //
    memory(_ds, 0x2c5) = _al;                   //
    _lodsw<MemData, DirForward>();              //
    _ax &= 0x0f0f;                              //
    _ah <<= 1;                                  //
    _ah <<= 1;                                  //
    _ah <<= 1;                                  //
    _ah <<= 1;                                  //
    _al |= _ah;                                 //
    memory(_ds, 0x2c4) = _al;                   //
loc_0280:                                       //
    _lodsb<MemData, DirForward>();              //
    _al |= _al;                                 //
    if (_al == 0)                               //
        goto loc_02ac;
    if (_al != 0x0d)                            //
        goto loc_0291;
    _dh += 1;                                   //
    _dl = memory(_ds, 709);                     //
    goto loc_0280;                              //
loc_0291:                                       //
    _push(_dx);                                 //
    _push(_ax);                                 //
    _ah = 0x02;                                 //
    _bh = 0;                                    //
    _interrupt(16);                             //
    _ax = _pop();                               //
    _ah = 0x09;                                 //
    _bl = memory(_ds, 708);                     //
    _bh = 0;                                    //
    _cx = 0x0001;                               //
    _interrupt(16);                             //
    _dx = _pop();                               //
    _dl += 1;                                   //
    goto loc_0280;                              //
loc_02ac:                                       //
    return;
}

void sub_02ad()
{
    _ah = 0x06;                                 //
    _al = 0;                                    //
    _bh = 0x07;                                 //
    _cx = 0;                                    //
    _dx = 0x1950;                               //
    _interrupt(16);                             //
}


