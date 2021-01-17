// ------------- indirect

// import
void sub_17BCB();
void sub_17B9A();
void sub_17ACE();
void sub_17A8C();
void sub_16B7E();
void sub_17A71();
void sub_17B10();
void sub_17AAD();
void sub_17B7E();
void sub_17B62();
void sub_17B2A();
void sub_17AEF();
void sub_16216();
void sub_16F16();
void sub_16A2A();
void sub_16A07();
void sub_1622F();

// export
void sub_17B46();
void sub_17A68();
void sub_17B14();

void _indirectCall(WORD seg, WORD ptr)
{
    switch(ptr) // sub_ 13EC0 + ptr
    {
        case 0x3c86: sub_17B46(); break;
        case 0x3ba7: break;
        case 0x3ba8: sub_17A68(); break;
        case 0x3c54: sub_17B14(); break;
        case 0x3c0e: sub_17ACE(); break;
        case 0x3bcc: sub_17A8C(); break;
        //case 0x2cbe: sub_16B7E(); break;
        case 0x3bb1: sub_17A71(); break;
        case 0x3c50: sub_17B10(); break;
        case 0x3bed: sub_17AAD(); break;
        case 0x3c6a: sub_17B2A(); break;
        case 0x3c2f: sub_17AEF(); break;
        case 0x3cbe: sub_17B7E(); break;
        case 0x3ca2: sub_17B62(); break;
            
        case 0x2356: sub_16216(); break;
        case 0x2b6a: sub_16A2A(); break; // ???
        case 0x2b47: sub_16A07(); break; // ??? // 236f, 1622f
        case 0x236f: sub_1622F(); break;
        default:
            break;
    }
}


void sub_16A2A()
{
    _cl = memory(_ds, 0x1E4);
    memory(_ds, 0x18E) = _cl; // new direction
    memory(_ds, 0x18D) = _cl; // new direction
    _bp = memory16(_ds, 0x1da);
    memory16(_ds, 0x194) = _bp;
    _bp = memory16(_ds, 0x1d6);
    memory16(_ds, 0x190) = _bp;
    _al = memory(_ds, 0x1e7);
    memory(_ds, 0x1e6) = _al;

    /*
     mov    cl, ds:1E4h
     mov    ds:18Eh, cl
     mov    ds:18Dh, cl
     mov    bp, ds:1DAh
     mov    ds:194h, bp
     
     mov    bp, ds:1D6h
     mov    ds:190h, bp
     
     mov    al, ds:1E7h
     mov    ds:1E6h, al

     */
}

void sub_16A07()
{
    _cl = memory(_ds, 0x1E5);
    memory(_ds, 0x18E) = _cl;
    memory(_ds, 0x18D) = _cl;
    _bp = memory16(_ds, 0x1dc);
    memory16(_ds, 0x194) = _bp;
    _bp = memory16(_ds, 0x1d8);
    memory16(_ds, 0x190) = _bp;
    _al = memory(_ds, 0x1e8);
    memory(_ds, 0x1e6) = _al;

    // todo
    /*
     sub_16A07    proc near
             mov    cl, ds:1E5h
             mov    ds:18Eh, cl
             mov    ds:18Dh, cl
             mov    bp, ds:1DCh
             mov    ds:194h, bp
             mov    bp, ds:1D8h
             mov    ds:190h, bp
             mov    al, ds:1E8h
             mov    ds:1E6h, al
             retn

     */
}
