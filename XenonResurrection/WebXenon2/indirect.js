function* loc_1480E() { yield* sub_1480B(0x1480e); }
function* sub_10761() { /* ret */ }
function* nullsub_1() {}

function* sub_16EEF() {
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: yield* loc_135CE(); return;
        case 2: yield* sub_16F7F(); return;
        case 4: yield* sub_16F00(); return;
        case 6: yield* sub_16FE0(); return;
        case 8: yield* sub_1705B(); return;
    }
}

function* indirectCall(seg, ptr)
{
    switch(ptr)
    {
        case 0x002a: yield* sub_1F2BA(); break;
        case 0x4311: yield* sub_14311(); break;
        case 0x4759: yield* sub_14759(); break;
        case 0x37df: yield* sub_137DF(); break;
        case 0x72c4: yield* sub_172C4(); break;
        case 0x758f: yield* sub_1758F(); break;
        case 0x655b: yield* sub_1655B(); break; // enter shop
        case 0x0853: yield* sub_10853(); break;
        case 0x0761: yield* sub_10761(); break;
        case 0x7520: yield* sub_17520(); break;
        case 0x70f1: yield* sub_170F1(); break;
        case 0x6EEF: yield* sub_16EEF(); break;
        case 0x41E2: yield* sub_141E2(); break;
        case 0x480b: yield* sub_1480B(0); break;
        case 0x714A: yield* sub_1714A(); break;
        case 0x08B9: yield* sub_108B9(); break; // strom?
        case 0x0f2b: yield* sub_10F2B(); break;
        case 0x37ca: yield* sub_137CA(); break; // swingtail
        case 0x1e61: yield* sub_11E61(); break; // hit2
        case 0x28df: yield* sub_128DF(); break; // hit3
        case 0x2ab2: yield* sub_12AB2(); break; // speed powerup
        case 0x3aa7: yield* sub_13AA7(); break; // hit1
        case 0x2a6e: yield* sub_12A6E(); break; // power powerup
        case 0x6d22: yield* sub_16D22(); break; // tree - animation
        case 0x3a39: yield* sub_13A39(); break; // swingtail hit
        case 0x308C: yield* sub_13246(); // gabo cannon combo!
                     yield* loc_1308C(); break; // rearshot powerup
        case 0x39ee: yield* sub_139EE(); break; // draw fire
        case 0x091f: yield* sub_1091F(); break; // draw fire
        case 0x0897: yield* sub_10897(); break; // lv2 boss
        case 0x3998: yield* sub_13998(); break; // explosion anim
        case 0x41fb: yield* sub_141FB(); break; // explosion cleanup
        case 0x1f4d: yield* sub_11F4D(); break; // tree bulet move
        case 0x3835: yield* sub_13835(); break;            
        case 0x3B76: yield* sub_13B76(); break;// tree hit 
        case 0x6a0a: yield* sub_16A0A(); break;//
        case 0x25a8: yield* sub_125A8(); break;//
        case 0x6aad: yield* sub_16AAD(); break;
        case 0x3bdf: yield* sub_13BDF(); break;
        case 0x6696: yield* sub_16696(); break; // worm hit
        case 0x69D0: yield* sub_169D0(); break; // worm segment fly
        case 0x66a6: yield* sub_166A6(); break;
        case 0x6ac7: yield* sub_16AC7(); break;
        case 0x6bca: yield* sub_16BCA(); break;
        case 0x2ad0: yield* sub_12AD0(); break;
        case 0x6e2c: yield* sub_16E2C(); break;
        case 0x71dd: yield* sub_171DD(); break;
        case 0x2a48: yield* sub_12A48(); break;
        case 0x714d: yield* sub_1714D(); break;
        case 0x69C8: yield* sub_169C8(); break;
        case 0x3246: yield* sub_13246(); break; // powerup - cannon
        case 0x3a99: yield* sub_13A99(); break;
        case 0x7569: yield* sub_17569(); break;
        case 0x8ca7: yield* sub_18CA7(); break; // zero!
        case 0x7f32: yield* sub_17F32(); break;
        case 0x7f79: yield* sub_17F79(); break;
        case 0x8e01: yield* sub_18E01(); break;
        case 0x89AE: yield* sub_189AE(); break;
        case 0x88A9: yield* sub_188A9(); break;
        case 0x8C3E: yield* sub_18C3E(); break;
        case 0x7DDE: yield* sub_17DDE(); break;
        case 0x6284: break; // retn
        case 0x9f02: yield* sub_19F02(); break;
        case 0x9f4E: yield* sub_19F4E(); break;
        case 0x21e9: yield* sub_121E9(); break; // cannon
        case 0x246d: yield* sub_1246D(); break; // cannon
        case 0x28b8: yield* sub_128B8(); break; // cannon fire
        // level 2    
        case 0x4f96: yield* sub_14F96(); break; // horse
        case 0x2aa4: yield* sub_12AA4(); break; // autoshoot
        case 0x80ca: yield* sub_180CA(); break;
        case 0x866d: yield* sub_1866D(); break; // lv2 boss
        case 0x8114: yield* sub_18114(); break;
        case 0x8126: yield* sub_18126(); break;
        case 0x80f5: yield* sub_180F5(); break;
        case 0x87D5: yield* sub_187D5(); break;
        case 0x8783: yield* sub_18783(); break;
        
        default:
            throw "wrong indirect";
    }
}
