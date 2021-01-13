// ------------- indirect

// import
void sub_17BCB();
void sub_17B9A();

// export
void sub_17B46();
void sub_17A68();
void sub_17B14();
void sub_17ACE();

void _indirectCall(WORD ptr)
{
    switch(ptr)
    {
        case 0x3c86: sub_17B46(); break;
        case 0x3ba7: break;
        case 0x3ba8: sub_17A68(); break;
        case 0x3c54: sub_17B14(); break;
        case 0x3c0e: sub_17ACE(); break;
        case 0x3bcc:
        case 0x2cbe:
        case 0x3bb1:
        case 0x3c50:
        case 0x3bed:
        case 0x3c6a:
        case 0x3c2f:
        case 0x3cbe:
        case 0x3ca2:
            break;
        default:
            std::cout << "Skip indirect " << std::hex << _di << "\n";
            break;
            _ASSERT(0);
    }
}

void sub_17B46()
{
    _ax += 0x0003;                              //add ax, 3
    sub_17BCB();                                //call sub_17BCB
    _ax -= 0x0006;                              //sub ax, 6
    sub_17BCB();                                //call sub_17BCB
    _ax += 0x0003;                              //add ax, 3
    _bx += 0x0003;                              //add bx, 3
    sub_17BCB();                                //call sub_17BCB
    _bx -= 0x0006;                              //sub bx, 6
    sub_17BCB();                                //call sub_17BCB
}

void sub_17A68()
{
    memory(_ds, 0x4C7) = 0;                     //mov byte ptr ds:4C7h, 0
    sub_17B9A();                                //call sub_17B9A
}

void sub_17B14()
{
    _ax -= 1;                                   //dec ax
    sub_17BCB();                                //call sub_17BCB
    _ax += 0x0002;                              //add ax, 2
    sub_17BCB();                                //call sub_17BCB
    _ax -= 1;                                   //dec ax
    _bx -= 1;                                   //dec bx
    sub_17BCB();                                //call sub_17BCB
    _bx += 0x0002;                              //add bx, 2
    sub_17BCB();                                //call sub_17BCB
}

void sub_17ACE()
{
    memory(_ds, 0x4C7) = 6;                     //mov byte ptr ds:4C7h, 6
    _ax += 0x0004;                              //add ax, 4
    sub_17B9A();                                //call sub_17B9A
    _ax -= 0x0008;                              //sub ax, 8
    sub_17B9A();                                //call sub_17B9A
    _ax += 0x0004;                              //add ax, 4
    _bx += 0x0004;                              //add bx, 4
    sub_17B9A();                                //call sub_17B9A
    _bx -= 0x0008;                              //sub bx, 8
    sub_17B9A();                                //call sub_17B9A
}


// -------------/indirect
