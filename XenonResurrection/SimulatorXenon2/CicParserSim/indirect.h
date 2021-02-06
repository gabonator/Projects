void sub_1F2BA();
void sub_14311();
void sub_14759();
void sub_1480B();
void sub_14759();
void sub_172C4();
void sub_1758F();
void sub_1655B();
void sub_1714A();
void sub_10853();
void sub_10761() { /* ret */ }
void sub_17520();
void sub_170F1();
void sub_16EEF() {};
void sub_170F1();
void sub_141E2();
void sub_1480B();
void sub_108B9();
void sub_10F2B() {}
void sub_137CA();

void _indirectCall(WORD seg, WORD ptr)
{
    if (seg==_seg000 && ptr==0x002a) //0x000c)
    {
        sub_1F2BA();
        return;
    }
    switch (ptr)
    {
        case 0x4311: sub_14311(); break;
        case 0x4759: sub_14759(); break;
        //case 0x480B: sub_1480B(); break;
        case 0x37df: sub_14759(); break;
        case 0x72c4: sub_172C4(); break;
        case 0x758f: sub_1758F(); break;
        case 0x655b: /*sub_1655B();*/ break;
            /*
        case 0x9F02: sub_19F02(); break;
        case 0x9F4E: sub_19F4E(); break;
        case 0x9F9A: sub_19F9A(); break;
        case 0x9FE6: sub_19FE6(); break;
        case 0xA032: sub_1A032(); break;
        case 0xA07E: sub_1A07E(); break;
        case 0xA162: sub_1A162(); break;
        case 0xA116: sub_1A116(); break;
*/
        case 0x0853: sub_10853(); break;
        case 0x0761: sub_10761(); break;
        case 0x7520: sub_17520(); break;
            break;
        case 0x70f1: sub_170F1(); break;
        case 0x6EEF: sub_16EEF(); break;

        case 0x41E2: sub_141E2(); break;
        case 0x480b: sub_1480B(); break;

            //zero
        case 0x714A: sub_1714A(); break;
        case 0x08B9: sub_108B9(); break;
        case 0x0f2b: sub_10F2B(); break;
        case 0x37ca: sub_137CA(); break;
            break;
            
        default:
//            _ASSERT(0);
            std::cout << "Not implemented " << std::hex << (int)ptr << "\n";
    }
    //_ASSERT(0);
}

