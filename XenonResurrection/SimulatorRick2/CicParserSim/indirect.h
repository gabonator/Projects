// ------------- indirect
/*
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
*/

void sub_10533();
void sub_10594();
void sub_105A1();
void sub_105CC();
void sub_10702();
void sub_107F1();
void sub_10836();
void sub_109D3();
void sub_109EE();
void sub_10A67();
void sub_1091B();
void sub_10D03();
void sub_10DF8();
void sub_10D3D();
void sub_11162();
void sub_112D6();
void sub_107AC();
void sub_108DD();
void sub_111F1();
void sub_10BC4();
void sub_10C2E();
void sub_10EE8();
void sub_109A5();
void sub_10986();
void sub_10EA6();
void sub_10524();
void sub_1087B();
void sub_109C4();
void sub_1A168();
void sub_1A1BC();
void sub_10E23();
void sub_10E40();
void sub_1A121();
void sub_1A155();
void sub_1A137();
void sub_1A1BC();
//void sub_1A23E();
//void sub_1635E();
void sub_1A2F6();
void sub_1A1E4();

void sub_10EC0();
void sub_10E7F();
void sub_12950();
void sub_1A1E6();
void sub_1A23E();
void sub_11376();
void sub_1A13F();

void _indirectCall(WORD seg, WORD ptr)
{
    for (int i=0; i<0x4C; i+=2)
        if (memory16(_seg001, i) == ptr)
        {
            ptr = i;
            break;
        }
    //_ASSERT(ptr < 100);
    
    switch(ptr) // sub_ 13EC0 + ptr
    {
        case 0x0000: sub_10524(); break;
        case 0x0002: sub_10533(); break;
        case 0x0004: sub_10594(); break;
        case 0x0006: sub_105A1(); break;
        case 0x0008: sub_105CC(); break;
        case 0x000A: sub_10702(); break;
        case 0x000C: sub_107F1(); break;
        case 0x000E: sub_10836(); break;
        case 0x0010: sub_1087B(); break; // 47b
        case 0x0018: sub_109C4(); break;
        case 0x001A: sub_109D3(); break;
        case 0x001C: sub_109EE(); break;
        case 0x001E: sub_10A67(); break;
        case 0x0024: sub_1091B(); break;
        case 0x0026: sub_10D03(); break;
        case 0x0028: sub_10DF8(); break;
        case 0x002A: sub_10D3D(); break;
        case 0x002C: sub_10E23(); break;
        case 0x002E: sub_10E40(); break;
        case 0x0038: break;
        case 0x003A: break;
        case 0x003C: break;
        case 0x003E: sub_11162(); break;
        case 0x0042: sub_112D6(); break;
        case 0x0044: sub_11376(); break;
        case 0x0046: sub_107AC(); break;
        case 0x0048: break;
        case 0x0012: sub_108DD(); break;
        case 0x0040: sub_111F1(); break;
        case 0x0020: sub_10BC4(); break;
        case 0x0022: sub_10C2E(); break;
        case 0x004A: sub_10EE8(); break;
        case 0x0016: sub_109A5(); break;
        case 0x0014: sub_10986(); break;
        case 0x0030: sub_10EA6(); break;
        case 0x0032: sub_10EC0(); break;
        case 0x0034: sub_10E7F(); break;
//        case 0x004E: /*??*/ break;

        case 0x9d68: sub_1A168(); break;
        case 0x9d21: sub_1A121(); break;
        case 0x9d55: sub_1A155(); break;
        case 0x9d37: sub_1A137(); break;
        case 0x9dbc: sub_1A1BC(); break;
        case 0x9de4: sub_1A1E4(); break;
        case 0x9ef6: sub_1A2F6(); break;
        case 0x9e3e: sub_1A23E(); break;
//        case 0x5f5e: /*sub_1635E();*/ break;
//        case 0x2550: /*sub_12950();*/ break;
        case 0x9DE6: sub_1A1E6(); break;
        case 0x9D3F: sub_1A13F(); break;

            
        default:
            std::cout << "Skip indirect " << std::hex << ptr << " addr = " << (ptr + 0x10400) << "\n";
            break;
            _ASSERT(0);
    }
}

