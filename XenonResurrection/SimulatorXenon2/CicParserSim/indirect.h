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

void loc_135CE();
void sub_16F7F();
void loc_16F00();
void sub_16FE0();
void loc_1705B();
void sub_11E61();
void sub_107C0();
void sub_128DF();
void sub_16F00();
void sub_13B76();
void sub_16AAD();
void sub_13BDF();

void sub_16EEF() {
    _bx <<= 1;
    switch (_bx)
    {
        case 0: loc_135CE(); return;
        case 2: sub_16F7F(); return;
        case 4: sub_16F00(); return;
        case 6: sub_16FE0(); return;
        case 8: loc_1705B(); return;
    }
}
void sub_170F1();
void sub_141E2();
void sub_1480B();
void sub_108B9();
void sub_107A0();
void sub_10F2B();
void sub_137CA();
void sub_128DF();
void sub_12AB2();
void sub_13AA7();
void sub_12A6E();
void sub_16D22();
void sub_13A39();
void sub_1308C();
void sub_139EE();
void sub_1091F();
void sub_10897();
void sub_137DF();
void sub_13998();
void sub_1655B();
void loc_1308C();
void sub_141FB();
void sub_11F4D();
void sub_13835();
void sub_13B7F() {_ASSERT(0);}
void sub_16A0A();
void sub_125A8();
void sub_16AAD();
void sub_16696();
void sub_169D0() {}

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
        case 0x37df: // fire
            sub_137DF(); break;
        case 0x72c4: sub_172C4(); break;
        case 0x758f: sub_1758F(); break;
        case 0x655b: sub_1655B(); break;
        case 0x0853: sub_10853(); break;
        case 0x0761: sub_10761(); break;
        case 0x7520: sub_17520(); break;
        case 0x70f1: sub_170F1(); break;
        case 0x6EEF: sub_16EEF(); break;
        case 0x41E2: sub_141E2(); break;
        case 0x480b: sub_1480B(); break;
        case 0x714A: sub_1714A(); break;
        case 0x08B9: sub_108B9(); break;
        case 0x0f2b: sub_10F2B(); break;
        case 0x37ca: sub_137CA(); break;
//        case 0x3e1a: /*sub_13E1A();*/ _ASSERT(0); break;
//        case 0x078B: sub_1078B(); break;
        case 0x1e61: sub_11E61(); break;
        case 0x28df: sub_128DF(); break;
        case 0x2ab2: sub_12AB2(); break;
        case 0x3aa7: sub_13AA7(); break;
        case 0x2a6e: sub_12A6E(); break;
        case 0x6d22: sub_16D22(); break;
        case 0x3a39: sub_13A39(); break;
        case 0x308C: loc_1308C(); break;
        case 0x39ee:
            sub_139EE(); break; // draw fire
        case 0x091f: sub_1091F(); break; // draw fire
        case 0x0897: sub_10897(); break;
        case 0x3998: sub_13998(); break;
        case 0x41fb: sub_141FB(); break;
        case 0x1f4d: sub_11F4D(); break;
        case 0x3835: sub_13835(); break;
        case 0x3B76: sub_13B76(); break;
        //case 0x3b7f: sub_13B7F(); break;
        case 0x6a0a: sub_16A0A(); break;
        case 0x25a8: sub_125A8(); break;
        case 0x6aad: sub_16AAD(); break;
        case 0x3bdf: sub_13BDF(); break;
        case 0x6696: sub_16696(); break;
        case 0x69D0: sub_169D0(); break;
            
        default:
//            _ASSERT(0);
            std::cout << "Not implemented " << std::hex << (int)ptr << "\n";
    }
    //_ASSERT(0);
}



