// TODO: first two trees not animating
// TODO: cannot buy anything in shop
// TODO: should blink white when hit
// TODO: two trees in front of first boss

void sub_1F2BA();
void sub_14311();
void sub_14759();
void sub_1480B(int pc);
void sub_14759();
void sub_172C4();
void sub_1758F();
void sub_1655B();
void sub_1714A();
void sub_10853();
void sub_10761() { /* ret */ }
void sub_17520();
void sub_170F1();
void sub_1705B();

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
        case 8: sub_1705B(); return;
    }
}
void sub_170F1();
void sub_141E2();
void sub_1480B(int pc);
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
void sub_16A0A();
void sub_125A8();
void sub_16AAD();
void sub_16696();
void sub_169D0();
void sub_166A6();
void sub_16AC7();
void sub_16BCA();
void sub_12AD0();
void sub_16E2C();
void sub_171DD();
void sub_12A48();
void sub_1714D();
void sub_169C8();
void sub_13246();
void sub_13A99();
void sub_17569();
void sub_1F732();
void sub_18CA7();
void sub_17F32();
void sub_18CA7();
void sub_17F79();
void sub_18E01();

void sub_189AE();
void sub_188A9();
void sub_18C3E();
void sub_17DDE();
void sub_19F02();
void sub_19F4E() { std::cout << "-------uninmplemented\n"; }

void _indirectCall(WORD seg, int ptr)
{
    _ASSERT(ptr >= 0 && ptr <= 0xffff);
    // ma byt 4311 ale je 9f02
//    if (ptr!=0x0853 && ptr != 0x7520)
//        std::cout << "indirect " << (int)ptr << "\n";
    
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
        case 0x655b: sub_1655B(); break; // enter shop
        case 0x0853: sub_10853(); break;
        case 0x0761: sub_10761(); break;
        case 0x7520: sub_17520(); break;
        case 0x70f1: sub_170F1(); break;
        case 0x6EEF: sub_16EEF(); break;
        case 0x41E2: sub_141E2(); break;
           case 0x480b: sub_1480B(0); break;
              case 0x714A: sub_1714A(); break;
        case 0x08B9: /*sub_108B9();*/ break; // strom?
        case 0x0f2b: sub_10F2B(); break;
        case 0x37ca: sub_137CA(); break; // swingtail
        case 0x1e61: sub_11E61(); break; // hit2
        case 0x28df: sub_128DF(); break; // hit3
        case 0x2ab2: sub_12AB2(); break; // speed powerup
        case 0x3aa7: sub_13AA7(); break; // hit1
        case 0x2a6e: sub_12A6E(); break; // power powerup
        case 0x6d22: sub_16D22(); break; // tree - animation
        case 0x3a39: sub_13A39(); break; // swingtail hit
        case 0x308C: loc_1308C(); break; // rearshot powerup
        case 0x39ee: sub_139EE(); break; // draw fire
        case 0x091f: sub_1091F(); break; // draw fire
        case 0x0897: sub_10897(); break;

        case 0x3998: sub_13998(); break; // explosion anim
        case 0x41fb: sub_141FB(); break; // explosion cleanup
        case 0x1f4d: sub_11F4D(); break; // tree bulet move
        case 0x3835: sub_13835(); break;
            
        case 0x3B76: sub_13B76(); break;// tree hit 
        case 0x6a0a: sub_16A0A(); break;//
        case 0x25a8: sub_125A8(); break;//
        case 0x6aad: sub_16AAD(); break;
        case 0x3bdf: sub_13BDF(); break;
        case 0x6696: sub_16696(); break; // worm hit
        case 0x69D0: sub_169D0(); break; // worm segment fly
        case 0x66a6: sub_166A6(); break;
        case 0x6ac7: sub_16AC7(); break;
        case 0x6bca: sub_16BCA(); break;
        case 0x2ad0: sub_12AD0(); break;
        //case 0x5e2c: break;
        case 0x6e2c: sub_16E2C(); break;
        case 0x71dd: sub_171DD(); break;
        case 0x2a48: sub_12A48(); break;
        case 0x714d: sub_1714D(); break;
        case 0x69C8: sub_169C8(); break;
        case 0x3246: sub_13246(); break; // powerup - cannon
        case 0x3a99: sub_13A99(); break;
        case 0x7569: sub_17569(); break;
        //case 0xf732: sub_1F732(); break;
        case 0x8ca7: sub_18CA7(); break; // zero!
        case 0x7f32: sub_17F32(); break;
        case 0x7f79: sub_17F79(); break;
        case 0x8e01: sub_18E01(); break;

        case 0x89AE: sub_189AE(); break;
        case 0x88A9: sub_188A9(); break;
        case 0x8C3E: sub_18C3E(); break;
        case 0x7DDE: sub_17DDE(); break;
        case 0x6284: break; // retn
        case 0x9f02: sub_19F02(); break;
            
        case 0x9f9A:
        case 0x9fe6:
        case 0x9f4E: sub_19F4E(); break;
          
        case 0x4f96: //sub_14F96(); break;
        default:
//            _ASSERT(0);
            std::cout << "Not implemented " << std::hex << (int)ptr << "\n";
            assert(0);
    }

}



