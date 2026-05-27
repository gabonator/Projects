
void sub_1001000();
void sub_100101d();
void sub_100112d();
void sub_1001157();
void sub_1001181();
void sub_1001200();
void sub_10012f5();
void sub_1001316();
void sub_100131c();
void sub_1001322();
void sub_1001323();
void sub_10013d0();
void sub_1001443();
void sub_1001449();
void sub_100144f();
void sub_1001450();
void sub_1001507();
void sub_1001525();
void sub_1001531();
void sub_1001582();
void sub_10015a2();
void sub_10015b7();
void sub_10015de();
void sub_10015ed();
void sub_10015fc();
void sub_10018bb();
void sub_10018d0();
void sub_10018e5();
void sub_10018fa();
void sub_1001900();
void sub_1001990();
void sub_1002d50();
void sub_1002f74();
void sub_1003022();
void sub_1003803();
void sub_10039bb();
void sub_100430e();
void sub_1004337();
void sub_1004379();
void sub_10043a2();
void sub_10043e4();
void sub_100440d();
void sub_100444f();
void sub_1004478();
void sub_10044ba();
void sub_1004560();
void sub_10045d0();
void sub_1004600();
void sub_1004640();
void sub_1004670();
void sub_10046b0();
void sub_1005a60();
void sub_1005ad0();
void sub_1005dc6();
void sub_1005e70();
void sub_1005ea6();
void sub_1006054();
void sub_100605a();
void sub_1006060();
void sub_1006066();
void sub_100606c();
void sub_1006072();

void synsoemuIndirectCall(int s, int o, int orgs, int orgo)
{
            // SYNSOEMU runtime dispatch (vtable calls, not resolvable by cicodis)
            switch (o) {
                case 0x1001000: sub_1001000(); break;
                case 0x100101d: sub_100101d(); break;
                case 0x100112d: sub_100112d(); break;
                case 0x1001157: sub_1001157(); break;
                case 0x1001181: sub_1001181(); break;
                case 0x1001200: sub_1001200(); break;
                case 0x10012f5: sub_10012f5(); break;
                case 0x1001316: sub_1001316(); break;
                case 0x100131c: sub_100131c(); break;
                case 0x1001322: sub_1001322(); break;
                case 0x1001323: sub_1001323(); break;
                case 0x10013d0: sub_10013d0(); break;
                case 0x1001443: sub_1001443(); break;
                case 0x1001449: sub_1001449(); break;
                case 0x100144f: sub_100144f(); break;
                case 0x1001450: sub_1001450(); break;
                case 0x1001507: sub_1001507(); break;
                case 0x1001525: sub_1001525(); break;
                case 0x1001531: sub_1001531(); break;
                case 0x1001582: sub_1001582(); break;
                case 0x10015a2: sub_10015a2(); break;
                case 0x10015b7: sub_10015b7(); break;
                case 0x10015de: sub_10015de(); break;
                case 0x10015ed: sub_10015ed(); break;
                case 0x10015fc: sub_10015fc(); break;
                case 0x10018bb: sub_10018bb(); break;
                case 0x10018d0: sub_10018d0(); break;
                case 0x10018e5: sub_10018e5(); break;
                case 0x10018fa: sub_10018fa(); break;
                case 0x1001900: sub_1001900(); break;
                case 0x1001990: sub_1001990(); break;
                case 0x1002d50: sub_1002d50(); break;
                case 0x1002f74: sub_1002f74(); break;
                case 0x1003022: sub_1003022(); break;
                case 0x1003803: sub_1003803(); break;
                case 0x10039bb: sub_10039bb(); break;
                case 0x100430e: sub_100430e(); break;
                case 0x1004337: sub_1004337(); break;
                case 0x1004379: sub_1004379(); break;
                case 0x10043a2: sub_10043a2(); break;
                case 0x10043e4: sub_10043e4(); break;
                case 0x100440d: sub_100440d(); break;
                case 0x100444f: sub_100444f(); break;
                case 0x1004478: sub_1004478(); break;
                case 0x10044ba: sub_10044ba(); break;
                case 0x1004560: sub_1004560(); break;
                case 0x10045d0: sub_10045d0(); break;
                case 0x1004600: sub_1004600(); break;
                case 0x1004640: sub_1004640(); break;
                case 0x1004670: sub_1004670(); break;
                case 0x10046b0: sub_10046b0(); break;
                case 0x1005a60: sub_1005a60(); break;
                case 0x1005ad0: sub_1005ad0(); break;
                case 0x1005dc6: sub_1005dc6(); break;
                case 0x1005e70: sub_1005e70(); break;
                case 0x1005ea6: sub_1005ea6(); break;
                case 0x1006054: sub_1006054(); break;
                case 0x100605a: sub_100605a(); break;
                case 0x1006060: sub_1006060(); break;
                case 0x1006066: sub_1006066(); break;
                case 0x100606c: sub_100606c(); break;
                case 0x1006072: sub_1006072(); break;
                case 0x77779001: sub_1001531(); break; // posAPI
                case 0x77779003: sub_1001582(); break; // posAPI
                case 0x77779004: sub_10015fc(); break; // posAPI
                case 0x77779006: sub_10015a2(); break; // posAPI
                case 0x77779009: sub_10015b7(); break; // posAPI
                case 0x77779010: sub_10018bb(); break; // posAPI
                case 0x77779011: sub_10018e5(); break; // posAPI
                case 0x77779012: sub_10018d0(); break; // posAPI
                case 0x77779002: eax = 0; break; // posAPI no-op
                case 0x77779005: eax = 0; break; // posAPI no-op
                case 0x77779007: eax = 0; break; // posAPI no-op
                case 0x77779008: eax = 0; break; // posAPI no-op
                case 0x7777900a: eax = 0; break; // posAPI no-op
                case 0x7777900b: eax = 0; break; // posAPI no-op
                case 0x7777900c: eax = 0; break; // posAPI no-op
                case 0x7777900d: eax = 0; break; // posAPI no-op
                case 0x7777900e: eax = 0; break; // posAPI no-op
                case 0x7777900f: eax = 0; break; // posAPI no-op
                case 0x00004000: sub_4000(); break; // TODO CICO!
                default: 
                  printf("{\"id\": \"jumpTable\", \"addr\": \"0:%x\", \"calls32\": [\"0:%x\"]}\n", orgo, o);
                  fprintf(stderr, "missing indirect %x:%x from %x:%x\n", s, o, orgs, orgo); fflush(stderr);
                  assert(0);
            }
}

void sub_1001000() // 0000:1001000 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(esi);
    push32(edi);
    eax = 0;
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0xc);
    ecx = 0x00000004;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsd<DS_ESI, ES_EDI>();
    al = !flags.zero;
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 8/4) // SEH removed (was stack_below, 8/4)
    esp += 12;
}
void sub_100101d() // 0000:100101d +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(esi);
    push32(edi);
    eax = 0;
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0xc);
    ecx = memoryAGet32(ss, ebp + 0x10);
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    al = !flags.zero;
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 16;
}
void sub_100112d() // 0000:100112d +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0xc);
    ebx = memoryAGet32(ss, ebp + 0x10);
    ecx = 0;
loc_100113e: // 0000:100113e
    eax = memoryAGet32(ds, esi + ecx * 4);
    edx = memoryAGet32(ds, ebx + ecx * 4);
    eax = (int32_t)eax * (int32_t)edx;
    memoryASet32(ds, edi + ecx * 4, eax);
    ecx++;
    if (ecx != 0x00000004)
        goto loc_100113e;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 16;
}
void sub_1001157() // 0000:1001157 +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0xc);
    ebx = memoryAGet32(ss, ebp + 0x10);
    ecx = 0;
loc_1001168: // 0000:1001168
    eax = memoryAGet32(ds, esi + ecx * 4);
    edx = memoryAGet32(ds, ebx + ecx * 4);
    eax = (int32_t)eax * (int32_t)edx;
    memoryASet32(ds, edi + ecx * 4, eax);
    ecx++;
    if (ecx != 0x00000004)
        goto loc_1001168;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 16;
}
void sub_1001181() // 0000:1001181 +long +stackDrop16
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    push32(esi);
    ecx = 0;
    memoryASet32(ss, ebp - 4, ecx);
    esi = memoryAGet32(ss, ebp + 0x14);
loc_1001190: // 0000:1001190
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp + 0xc);
    edx = memoryAGet16(ds, edx + ecx * 2);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx >>= 14;
    edx &= 0x000003f0;
    eax |= edx;
    edx = memoryAGet32(ds, esi + eax * 4);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 12;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x1000);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x1100);
    eax = memoryAGet32(ss, ebp - 4);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x1200);
    eax = edx;
    edx &= 0x00ffffff;
    memoryASet32(ss, ebp - 4, edx);
    eax >>= 24;
    edx = memoryAGet32(ss, ebp + 0x10);
    memoryASet(ds, ecx + edx, al);
    ecx++;
    if (ecx != 0x00000028)
        goto loc_1001190;
    esi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 16/8) // SEH removed (was stack_below, 16/8)
    esp += 20;
}
void sub_1001200() // 0000:1001200 +long +stackDrop20
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffff8;
    push32(ebx);
    push32(esi);
    ebx = 0;
    ecx = 0;
    memoryASet32(ss, ebp - 4, ecx);
    memoryASet32(ss, ebp - 8, ecx);
    esi = memoryAGet32(ss, ebp + 0x18);
loc_1001215: // 0000:1001215
    eax = memoryAGet32(ss, ebp + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp + 0x10);
    edx = memoryAGet(ds, ecx + edx);
    edx &= 0x00000003;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x8);
    edx = memoryAGet(ds, ecx + edx);
    edx &= 0x00000003;
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, esi + eax * 4);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x8000);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x8400);
    eax = memoryAGet32(ss, ebp - 4);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x8600);
    memoryASet32(ss, ebp - 4, edx);
    eax = edx;
    eax >>= 21;
    eax &= 0x00000700;
    edx = memoryAGet32(ss, ebp - 8);
    edx &= 0x00003800;
    eax |= edx;
    eax >>= 3;
    edx = memoryAGet32(ss, ebp + 0x14);
    edx = memoryAGet16(ds, edx + ecx * 2);
    eax |= edx;
    edx = memoryAGet32(ds, esi + eax * 4 + 0x8a00);
    eax = memoryAGet32(ss, ebp - 8);
    eax >>= 4;
    eax &= 0x0000000f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0xaa00);
    eax = memoryAGet32(ss, ebp - 8);
    eax >>= 8;
    eax &= 0x00000007;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0xaa40);
    eax = memoryAGet32(ss, ebp - 8);
    eax &= 0x0000000f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0xaa60);
    memoryASet32(ss, ebp - 8, edx);
    if (ecx < 0x00000008)
        goto loc_10012e3;
    edx >>= 14;
    edx &= 0x00000001;
    ebx |= edx;
    ebx = ror32(ebx, 0x00000001);
loc_10012e3: // 0000:10012e3
    ecx++;
    if (ecx != 0x00000028)
        goto loc_1001215;
    eax = ebx;
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 20/8) // SEH removed (was stack_below, 20/8)
    esp += 24;
}
void sub_10012f5() // 0000:10012f5 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    edx = memoryAGet32(ss, ebp + 0xc);
    eax = edx + 44;
    push32(eax);
    eax = edx + 556;
    push32(eax);
    eax = edx + 4;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1001323();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 8/4) // SEH removed (was stack_below, 8/4)
    esp += 12;
}
void sub_1001316() // 0000:1001316 +long
{
    esp -= 4;
    eax = 0x01007114;
    esp += 4;
}
void sub_100131c() // 0000:100131c +long
{
    esp -= 4;
    eax = 0x01007124;
    esp += 4;
}
void sub_1001322() // 0000:1001322 +long
{
    esp -= 4;
    esp += 4;
}
void sub_1001323() // 0000:1001323 +long +stackDrop16
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffff4;
    push32(ebx);
    push32(esi);
    ecx = 0;
    memoryASet32(ss, ebp - 4, ecx);
    ebx = 0;
    esi = memoryAGet32(ss, ebp + 0x10);
loc_1001335: // 0000:1001335
    edx = memoryAGet32(ss, ebp + 0x8);
    edx = memoryAGet16(ds, edx + ecx * 2);
    memoryASet32(ss, ebp - 8, edx);
    edx <<= 3;
    eax = memoryAGet32(ss, ebp + 0xc);
    eax = memoryAGet(ds, ecx + eax);
    memoryASet32(ss, ebp - 12, eax);
    eax <<= 1;
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx &= 0x07fc0000;
    edx >>= 13;
    eax |= edx;
    edx = memoryAGet32(ds, esi + eax * 4);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 12;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x10000);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x10100);
    eax = memoryAGet32(ss, ebp - 4);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x10200);
    edx &= 0x07ffffff;
    etx = memoryAGet32(ss, ebp - 4); memoryASet32(ss, ebp - 4, edx); edx = etx;
    if (ecx < 0x00000008)
        goto loc_10013be;
    edx >>= 18;
    eax = memoryAGet32(ss, ebp + 0x14);
    eax = memoryAGet(ds, edx + eax);
    indirectCall(cs, memoryAGet32(ds, eax * 4 + 0x1007134), 0x0000, 0x010013a6); // 0000:10013a6
    edx = memoryAGet32(ss, ebp - 8);
    eax = eax + (edx * 4);
    edx = memoryAGet32(ss, ebp - 12);
    eax = memoryAGet(ds, edx + eax);
    ebx |= eax;
    ebx = ror32(ebx, 0x00000001);
loc_10013be: // 0000:10013be
    ecx++;
    if (ecx != 0x00000028)
        goto loc_1001335;
    eax = ebx;
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 20;
}
void sub_10013d0() // 0000:10013d0 +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = memoryAGet32(ss, ebp + 0x10);
    edi = 0;
    memoryASet32(ss, ebp - 4, 0x00000000);
loc_10013e5: // 0000:10013e5
    edx = ebx + 66860;
    esi = memoryAGet32(ss, ebp + 0xc);
    ecx = 0;
loc_10013f0: // 0000:10013f0
    eax = memoryAGet16(ds, edx + ecx * 2);
    memoryASet16(ds, esi + ecx * 2, ax);
    ecx++;
    if (ecx != 0x00000008)
        goto loc_10013f0;
    push32(memoryAGet32(ss, ebp - 4));
    eax = ebx + 66876;
    push32(eax);
    eax = ebx + 66940;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1001450();
    eax = ebx;
    push32(memoryAGet32(ss, ebp + 0xc));
    indirectCall(cs, memoryAGet32(ds, eax), 0x0000, 0x0100141f); // 0000:100141f
    if (eax == memoryAGet32(ss, ebp + 0x8))
        goto loc_100143c;
    ecx = (int32_t)edi * (int32_t)0x00000008;
    eax >>= cl;
    if (memoryAGet(ss, edi + ebp + 0x8) != al)
        goto loc_1001435;
    edi++;
    goto loc_100143a;
loc_1001435: // 0000:1001435
    memoryASet(ss, edi + ebp - 4, memoryAGet(ss, edi + ebp - 4) + 1);
loc_100143a: // 0000:100143a
    goto loc_10013e5;
loc_100143c: // 0000:100143c
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 16;
}
void sub_1001443() // 0000:1001443 +long
{
    esp -= 4;
    eax = 0x01007140;
    esp += 4;
}
void sub_1001449() // 0000:1001449 +long
{
    esp -= 4;
    eax = 0x01007144;
    esp += 4;
}
void sub_100144f() // 0000:100144f +long
{
    esp -= 4;
    esp += 4;
}
void sub_1001450() // 0000:1001450 +long +stackDrop20
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    push32(ebx);
    push32(esi);
    push32(edi);
    ecx = 0;
    memoryASet32(ss, ebp - 4, ecx);
    ebx = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0x18);
    esi = memoryAGet32(ss, ebp + 0x10);
loc_1001467: // 0000:1001467
    if (ecx < 0x00000008)
        goto loc_100149c;
    edx = memoryAGet32(ss, ebp - 4);
    edx >>= 12;
    eax = memoryAGet32(ss, ebp + 0x14);
    eax = memoryAGet(ds, edx + eax);
    indirectCall(cs, memoryAGet32(ds, eax * 4 + 0x1007148), 0x0000, 0x01001479); // 0000:1001479
    edx = ebx;
    edx &= 0x00000001;
    eax = eax + (edx * 2);
    edx = edi;
    edx &= 0x00000001;
    eax = memoryAGet(ds, edx + eax);
    edx = memoryAGet32(ss, ebp + 0xc);
    memoryASet16(ds, edx + ecx * 2, ax);
    ebx = ror32(ebx, 0x00000001);
    edi = ror32(edi, 0x00000001);
loc_100149c: // 0000:100149c
    eax = memoryAGet32(ss, ebp + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp - 4);
    edx &= 0x0003f000;
    edx >>= 10;
    eax |= edx;
    edx = memoryAGet32(ds, esi + eax * 4);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 8;
    eax &= 0x0000000f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x400);
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 4;
    eax &= 0x0000000f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x440);
    eax = memoryAGet32(ss, ebp - 4);
    eax &= 0x0000000f;
    edx ^= memoryAGet32(ds, esi + eax * 4 + 0x480);
    eax = edx;
    edx &= 0x0003ffff;
    memoryASet32(ss, ebp - 4, edx);
    eax >>= 18;
    edx = memoryAGet32(ss, ebp + 0xc);
    memoryASet16(ds, edx + ecx * 2, ax);
    ecx++;
    if (ecx != 0x00000028)
        goto loc_1001467;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 20/12) // SEH removed (was stack_below, 20/12)
    esp += 24;
}
void sub_1001507() // 0000:1001507 +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_10012f5();
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(eax);
    sub_10013d0();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 16;
}
void sub_1001525() // 0000:1001525 +stackDrop12 +entry
{
    push32(ebp);
    ebp = esp;
    eax = 0x00000001;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 12;
}
void sub_1001531() // 0000:1001531 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    eax = memoryAGet32(ss, ebp + 0x1c);
    memoryASet32(ds, eax, 0xffffffff);
    if (!memoryAGet32(ss, ebp + 0xc))
        goto loc_100157b;
    ebx = 0x01007020;
loc_100154b: // 0000:100154b
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0xc));
    sub_1001000();
    if (eax)
        goto loc_1001573;
    push32(0x0000001c);
    push32(0x00000040);
    sub_1006054();
    edi = eax;
    eax = memoryAGet32(ss, ebp + 0x1c);
    printf("  posRegister: MATCH! alloc=0x%08x storing at outPtr=0x%08x, copying from ebx=0x%08x\n", edi, eax, ebx);
    // Save entire ordinal table + handle area (0x105814bc..0x1058150c = 20 DWORDs)
    uint32_t _sv[21]; for(int _i=0;_i<21;_i++) _sv[_i]=memoryAGet32(ds,0x005814bc+_i*4);
    memoryASet32(ds, eax, edi);
    esi = ebx;
    ecx = 0x00000018;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    { uint32_t h = memoryAGet32(ds, 0x005814bc);
      printf("  POST-COPY: handle=0x%08x [+0x14]=0x%08x edi=0x%08x\n", h, memoryAGet32(ds, h+0x14), edi); }
    // Restore ordinal table (skip first entry which is the handle ptr itself)
    for(int _i=2;_i<21;_i++) memoryASet32(ds,0x005814bc+_i*4,_sv[_i]);
    // Keep the handle ptr and first copy byte at 0x105814bc..0x105814c3
    { uint32_t h=memoryAGet32(ds,0x005814bc);
      printf("  posRegister: handle=0x%08x [+0x10]=0x%08x [+0x14]=0x%08x\n",
          h, memoryAGet32(ds,h+0x10), memoryAGet32(ds,h+0x14)); }
    goto loc_100157b;
loc_1001573: // 0000:1001573
    ebx = ebx + 24;
    if (memoryAGet32(ds, ebx))
        goto loc_100154b;
loc_100157b: // 0000:100157b
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_1001582() // 0000:1001582 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    ebx = memoryAGet32(ss, ebp + 0x8);
    if (ebx == 0xffffffff)
        goto loc_100159d;
    eax = memoryAGet32(ds, ebx + 0x10);
    if (!eax)
        goto loc_100159d;
    push32(memoryAGet32(ss, ebp + 0x10));
    indirectCall(cs, eax, 0x0000, 0x01001598); // 0000:1001598
    memoryASet32(ds, ebx + 0x18, eax);
loc_100159d: // 0000:100159d
    eax = 0;
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_10015a2() // 0000:10015a2 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    if (eax == 0xffffffff)
        goto loc_10015b3;
    push32(eax);
    sub_100605a();
loc_10015b3: // 0000:10015b3
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_10015b7() // 0000:10015b7 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(0x00000150);
    push32(0x00000040);
    sub_1006054();
    edx = memoryAGet32(ss, ebp + 0x18);
    memoryASet32(ds, edx, 0x00000150);
    edx = memoryAGet32(ss, ebp + 0x14);
    memoryASet32(ds, edx, eax);
    memoryASet32(ds, eax, 0x00000001);
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-12) // SEH removed (was stack_unbalanced, 0/-12)
    esp += 4;
}
void sub_10015de() // 0000:10015de +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100605a();
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-8) // SEH removed (was stack_unbalanced, 0/-8)
    esp += 4;
}
void sub_10015ed() // 0000:10015ed +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100605a();
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-8) // SEH removed (was stack_unbalanced, 0/-8)
    esp += 4;
}
void sub_10015fc() // 0000:10015fc +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = memoryAGet32(ss, ebp + 0x8);
    push32(0x01007154);
    push32(memoryAGet32(ss, ebp + 0x10));
    sub_1001000();
    if (eax)
        goto loc_1001782;
    push32(0x0000001c);
    push32(0x00000040);
    sub_1006054();
    edi = eax;
    eax = memoryAGet32(ss, ebp + 0x1c);
    memoryASet32(ds, eax, edi);
    eax = memoryAGet32(ss, ebp + 0x20);
    memoryASet32(ds, eax, 0x0000001c);
    esi = 0x0100719c;
    ecx = 0x0000001c;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    push32(0x01007038);
    push32(ebx);
    sub_1001000();
    if (!eax)
        goto loc_10018b4;
    push32(0x01007050);
    push32(ebx);
    sub_1001000();
    if (!eax)
        goto loc_10018b4;
    push32(0x01007020);
    push32(ebx);
    sub_1001000();
    if (!eax)
        goto loc_10018b4;
    push32(0x01007068);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_100169e;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(0x011079b8);
    push32(memoryAGet32(ds, eax + 0x4));
    push32(memoryAGet32(ds, eax));
    sub_1001507();
    goto loc_10018b4;
loc_100169e: // 0000:100169e
    push32(0x01007080);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_10016c4;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(0x010b1eb8);
    push32(memoryAGet32(ds, eax + 0x4));
    push32(memoryAGet32(ds, eax));
    sub_1001507();
    goto loc_10018b4;
loc_10016c4: // 0000:10016c4
    push32(0x010070b0);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_10016ea;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(0x010ce7b8);
    push32(memoryAGet32(ds, eax + 0x4));
    push32(memoryAGet32(ds, eax));
    sub_1001507();
    goto loc_10018b4;
loc_10016ea: // 0000:10016ea
    push32(0x010070c8);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_1001726;
    if (memoryAGet32(ds, ebx + 0x18) != 0x00000262)
        goto loc_1001715;
    eax = memoryAGet32(ss, ebp + 0xa8);
    edx = memoryAGet32(ss, ebp + 0xac);
    memoryASet32(ss, ebp + 0x8c, memoryAGet32(ss, ebp + 0x8c) + 0x00000011);
loc_1001715: // 0000:1001715
    push32(0x01134d00);
    push32(edx);
    push32(eax);
    sub_1001507();
    goto loc_10018b4;
loc_1001726: // 0000:1001726
    push32(0x010070e0);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_100174c;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(0x011242b8);
    push32(memoryAGet32(ds, eax + 0x4));
    push32(memoryAGet32(ds, eax));
    sub_1001507();
    goto loc_10018b4;
loc_100174c: // 0000:100174c
    push32(0x010070f8);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_1001772;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(0x010eb0b8);
    push32(memoryAGet32(ds, eax + 0x4));
    push32(memoryAGet32(ds, eax));
    sub_1001507();
    goto loc_10018b4;
loc_1001772: // 0000:1001772
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000001);
    push32(0xdead0001);
    sub_1006060();
loc_1001782: // 0000:1001782
    push32(0x01007178);
    push32(memoryAGet32(ss, ebp + 0x10));
    sub_1001000();
    if (eax)
        goto loc_10018a4;
    push32(0x010070e0);
    push32(ebx);
    sub_1001000();
    if (!eax)
        goto loc_10018b4;
    push32(0x01007068);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_10017d6;
    push32(0x00000003);
    eax = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet32(ds, ebx + 0x18) != 0x000001ae)
        goto loc_10017cd;
    eax = eax + 3754892;
loc_10017cd: // 0000:10017cd
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x14), 0x0000, 0x010017ce); // 0000:10017ce
    goto loc_10018b4;
loc_10017d6: // 0000:10017d6
    push32(0x01007080);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_1001824;
    push32(0x00000003);
    eax = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet32(ds, ebx + 0x18) != 0x000001f4)
        goto loc_10017fb;
    eax = eax + 3315348;
    goto loc_100181b;
loc_10017fb: // 0000:10017fb
    if (memoryAGet32(ds, ebx + 0x18) != 0x000001f5)
        goto loc_100180c;
    eax = eax + 3320236;
    goto loc_100181b;
loc_100180c: // 0000:100180c
    if (memoryAGet32(ds, ebx + 0x18) != 0x000001fe)
        goto loc_100181b;
    eax = eax + 3333812;
loc_100181b: // 0000:100181b
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x14), 0x0000, 0x0100181c); // 0000:100181c
    goto loc_10018b4;
loc_1001824: // 0000:1001824
    push32(0x01007098);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_1001852;
    push32(0x00000003);
    eax = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet32(ds, ebx + 0x18) != 0x0000006e)
        goto loc_1001846;
    eax = eax + 746332;
    goto loc_100184c;
loc_1001846: // 0000:1001846
    eax = eax + 746332;
loc_100184c: // 0000:100184c
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x14), __LINE__, 0); // 0000:100184d
    goto loc_10018b4;
loc_1001852: // 0000:1001852
    push32(0x010070b0);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_100187b;
    push32(0x00000003);
    eax = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet32(ds, ebx + 0x18) != 0x0000015e)
        goto loc_1001875;
    eax = eax + 928228;
loc_1001875: // 0000:1001875
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x14), 0x0000, 0x01001876); // 0000:1001876
    goto loc_10018b4;
loc_100187b: // 0000:100187b
    push32(0x010070f8);
    push32(ebx);
    sub_1001000();
    if (eax)
        goto loc_10018a4;
    push32(0x00000003);
    eax = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet32(ds, ebx + 0x18) != 0x000000dc)
        goto loc_100189e;
    eax = eax + 201308;
loc_100189e: // 0000:100189e
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x14), 0x0000, 0x0100189f); // 0000:100189f
    goto loc_10018b4;
loc_10018a4: // 0000:10018a4
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000001);
    push32(0xdead0002);
    sub_1006060();
loc_10018b4: // 0000:10018b4
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_10018bb() // 0000:10018bb +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, eax + 0x4);
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, memoryAGet32(ds, eax + 0x14), 0x0000, 0x010018c9); // 0000:10018c9
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-12) // SEH removed (was stack_unbalanced, 0/-12)
    esp += 4;
}
void sub_10018d0() // 0000:10018d0 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, eax + 0x4);
    push32(0x00000002);
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, memoryAGet32(ds, eax + 0x14), __LINE__, 0); // 0000:110018de
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-12) // SEH removed (was stack_unbalanced, 0/-12)
    esp += 4;
}
void sub_10018e5() // 0000:10018e5 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, eax + 0x4);
    push32(0x00000001);
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, memoryAGet32(ds, eax + 0x14), 0x0000, 0x010018f3); // 0000:10018f3
    eax = 0;
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-12) // SEH removed (was stack_unbalanced, 0/-12)
    esp += 4;
}
void sub_10018fa() // 0000:10018fa +long
{
    esp -= 4;
    eax = 0;
    esp += 4;
}
void sub_1001900() // 0000:1001900 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x01616380)
        goto loc_1001929;
    eax = 0x000001f4;
    goto loc_1001947;
loc_1001929: // 0000:1001929
    if (eax != 0x0161d890)
        goto loc_1001937;
    eax = 0x000001f5;
    goto loc_1001947;
loc_1001937: // 0000:1001937
    if (eax != 0x0162e530)
        goto loc_1001945;
    eax = 0x000001fe;
    goto loc_1001947;
loc_1001945: // 0000:1001945
    eax = 0;
loc_1001947: // 0000:1001947
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_1001990() // 0000:1001990 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffdc;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1006066();
    memoryASet32(ss, ebp - 32, 0x00000000);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_10019b1: // 0000:10019b1
    push32(edi);
    esi = 0x01007378;
    ecx = 0x00000028;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (!flags.zero)
        goto loc_10019c4;
    memoryASet32(ss, ebp - 32, memoryAGet32(ss, ebp - 32) + 1);
loc_10019c4: // 0000:10019c4
    if (memoryAGet32(ss, ebp - 32) == 0x00000002)
        goto loc_10019cd;
    edi++;
    goto loc_10019b1;
loc_10019cd: // 0000:10019cd
    memoryASet32(ds, 0x1145744, edi);
    goto loc_10019f9;
    // gap 36 bytes // gap 36 bytes
loc_10019f9: // 0000:10019f9
    edi = memoryAGet32(ds, ebx + 0x4);
loc_10019fc: // 0000:10019fc
    push32(edi);
    esi = 0x010073a0;
    ecx = 0x00000020;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (flags.zero)
        goto loc_1001a0f;
    edi++;
    goto loc_10019fc;
loc_1001a0f: // 0000:1001a0f
    memoryASet32(ds, 0x1145748, edi);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_1001a18: // 0000:1001a18
    esi = memoryAGet32(ds, 0x1145748);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_1001a2a;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_1001a2d;
loc_1001a2a: // 0000:1001a2a
    edi++;
    goto loc_1001a18;
loc_1001a2d: // 0000:1001a2d
    push32(edi);
loc_1001a2e: // 0000:1001a2e
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_1001a3a;
    goto loc_1001a2e;
loc_1001a3a: // 0000:1001a3a
    ebx = 0x00000024;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x010019d5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_1001a56: // 0000:1001a56
    esi = memoryAGet32(ds, 0x1145748);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_1001a68;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_1001a6b;
loc_1001a68: // 0000:1001a68
    edi++;
    goto loc_1001a56;
loc_1001a6b: // 0000:1001a6b
    push32(edi);
loc_1001a6c: // 0000:1001a6c
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_1001a78;
    goto loc_1001a6c;
loc_1001a78: // 0000:1001a78
    ebx = 0x00000024;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x010019d5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_1001a94: // 0000:1001a94
    esi = memoryAGet32(ds, 0x1145748);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_1001aa6;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_1001aa9;
loc_1001aa6: // 0000:1001aa6
    edi++;
    goto loc_1001a94;
loc_1001aa9: // 0000:1001aa9
    push32(edi);
loc_1001aaa: // 0000:1001aaa
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_1001ab6;
    goto loc_1001aaa;
loc_1001ab6: // 0000:1001ab6
    ebx = 0x00000024;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x010019d5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_1001ad2: // 0000:1001ad2
    esi = memoryAGet32(ds, 0x1145748);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_1001ae4;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_1001ae7;
loc_1001ae4: // 0000:1001ae4
    edi++;
    goto loc_1001ad2;
loc_1001ae7: // 0000:1001ae7
    push32(edi);
loc_1001ae8: // 0000:1001ae8
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_1001af4;
    goto loc_1001ae8;
loc_1001af4: // 0000:1001af4
    ebx = 0x00000024;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x010019d5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_1001b10: // 0000:1001b10
    esi = memoryAGet32(ds, 0x1145748);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_1001b22;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_1001b25;
loc_1001b22: // 0000:1001b22
    edi++;
    goto loc_1001b10;
loc_1001b25: // 0000:1001b25
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_1001b31;
    goto loc_1001b25;
loc_1001b31: // 0000:1001b31
    ebx = 0x00000024;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x010019d5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-128) // SEH removed (was stack_unbalanced, 4/-128)
    esp += 8;
}
void sub_1002d50() // 0000:1002d50 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe0;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1006066();
    edi = memoryAGet32(ds, ebx + 0x4);
loc_1002d6a: // 0000:1002d6a
    push32(edi);
    esi = 0x0102cf48;
    ecx = 0x00000028;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (flags.zero)
        goto loc_1002d7d;
    edi++;
    goto loc_1002d6a;
loc_1002d7d: // 0000:1002d7d
    memoryASet32(ds, 0x1146c94, edi);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_1002d86: // 0000:1002d86
    push32(edi);
    esi = 0x0102cf70;
    ecx = 0x00000020;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (flags.zero)
        goto loc_1002d99;
    edi++;
    goto loc_1002d86;
loc_1002d99: // 0000:1002d99
    memoryASet32(ds, 0x1146c98, edi);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_1002da2: // 0000:1002da2
    esi = memoryAGet32(ds, 0x1146c98);
    if (memoryAGet32(ds, edi) == esi)
        goto loc_1002daf;
    edi++;
    goto loc_1002da2;
loc_1002daf: // 0000:1002daf
    edi--;
    if (memoryAGet16(ds, edi - 2) == 0xcccc)
        goto loc_1002dba;
    goto loc_1002daf;
loc_1002dba: // 0000:1002dba
    goto loc_1002dd6;
    // gap 26 bytes // gap 26 bytes
loc_1002dd6: // 0000:1002dd6
    ebx = 0x0000001a;
    eax = ebp - 32;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x01002dbc;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-60) // SEH removed (was stack_unbalanced, 4/-60)
    esp += 8;
}
void sub_1002f74() // 0000:1002f74 +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(edi);
    edi = memoryAGet32(ss, ebp + 0x8);
    eax = 0xffffffff;
    ecx = 0x00000028;
    for (; ecx != 0; --ecx) stosb<ES_EDI>(al);
    ebx = 0;
    ecx = 0;
loc_1002f8c: // 0000:1002f8c
    push32(ebx);
    eax = memoryAGet(ds, ecx + 0x103dc10);
    edx = memoryAGet32(ss, ebp + 0xc);
    edx = memoryAGet16(ds, edx + ecx * 2);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x8);
    memoryASet(ds, ecx + edx, memoryAGet(ds, ecx + edx) + 1);
    edx = memoryAGet(ds, ecx + edx);
    edx &= 0x00000003;
    edx <<= 4;
    eax |= edx;
    edx = ebx;
    edx >>= 18;
    edx &= 0x000003c0;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x103dc38);
    eax = ebx;
    eax >>= 16;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103ec38);
    eax = ebx;
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103f038);
    eax = ebx;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103f438);
    eax = edx;
    eax >>= 28;
    ebx = memoryAGet32(ss, ebp + 0x10);
    if (memoryAGet16(ds, ebx + ecx * 2) == ax)
        goto loc_1003007;
    ebx = pop32();
    goto loc_1003013;
loc_1003007: // 0000:1003007
    esp += 0x00000008; // SEH fixed: was +4, deficit 4
    ebx = edx;
    ebx &= 0x0fffffff;
    ecx++;
loc_1003013: // 0000:1003013
    if (ecx != 0x00000028)
        goto loc_1002f8c;
    edi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH fixed (was stack_below, 12/8) // SEH fixed (was stack_below, 12/8)
    esp += 16;
}
void sub_1003022() // 0000:1003022 +long
{
    esp -= 4;
    esp -= 0x0000006c;
    eax = memoryAGet32(ds, esp + 0x20);
    ecx = memoryAGet32(ds, esp + 0x2c);
    push32(ebx);
    push32(ebp);
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x28);
    push32(edi);
    edi = esp - 42;
    memoryASet32(ds, esp - 52, eax);
    eax = memoryAGet32(ds, esp + 0x34);
    ebx = edi;
    ebx -= eax;
    memoryASet32(ds, esp - 48, ebx);
    ebp = esp - 44;
    memoryASet32(ds, esp - 64, ecx);
    ebx = esp - 40;
    ecx = 0;
    esi++;
    ebp -= eax;
    ebx -= eax;
    edx = eax + 4;
    memoryASet32(ds, esp - 60, ebx);
    memoryASet32(ds, esp - 68, 0x00000008);
    esp = esp;
loc_1003070: // 0000:1003070
    eax = (int16_t)memoryAGet16(ds, edx - 4);
    ebx = ecx;
    ebx >>= 14;
    ebx &= 0x00000070;
    eax |= ebx;
    ebx = memoryAGet(ds, esi - 1);
    ebx &= 0x00000003;
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x103f838);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x103fa38);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x103fb38);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x103fc38);
    ecx = eax;
    eax &= 0x001fffff;
    ecx >>= 21;
    ebx = eax;
    ebx >>= 14;
    ebx &= 0x00000070;
    memoryASet16(ds, edi - 2, cx);
    ecx = (int16_t)memoryAGet16(ds, edx - 2);
    ecx |= ebx;
    ebx = memoryAGet(ds, esi);
    ebx &= 0x00000003;
    ebx += ebx;
    ebx += ebx;
    ecx |= ebx;
    ecx = memoryAGet32(ds, ecx * 4 + 0x103f838);
    ebx = eax;
    ebx >>= 12;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x103fa38);
    ebx = eax;
    ebx >>= 6;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x103fb38);
    ebx = (int16_t)memoryAGet16(ds, edx);
    eax &= 0x0000003f;
    ecx ^= memoryAGet32(ds, eax * 4 + 0x103fc38);
    eax = ecx;
    eax >>= 21;
    memoryASet16(ds, edi, ax);
    ecx &= 0x001fffff;
    eax = ecx;
    eax >>= 14;
    eax &= 0x00000070;
    eax |= ebx;
    ebx = memoryAGet(ds, esi + 0x1);
    ebx &= 0x00000003;
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x103f838);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x103fa38);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x103fb38);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x103fc38);
    ecx = eax;
    ecx >>= 21;
    eax &= 0x001fffff;
    memoryASet16(ss, ebp + edx, cx);
    ecx = (int16_t)memoryAGet16(ds, edx + 0x2);
    ebx = eax;
    ebx >>= 14;
    ebx &= 0x00000070;
    ecx |= ebx;
    ebx = memoryAGet(ds, esi + 0x2);
    ebx &= 0x00000003;
    ebx += ebx;
    ebx += ebx;
    ecx |= ebx;
    ecx = memoryAGet32(ds, ecx * 4 + 0x103f838);
    ebx = eax;
    ebx >>= 12;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x103fa38);
    ebx = eax;
    ebx >>= 6;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x103fb38);
    ebx = memoryAGet32(ds, esp - 48);
    eax &= 0x0000003f;
    ecx ^= memoryAGet32(ds, eax * 4 + 0x103fc38);
    esi += 0x00000005;
    eax = ecx;
    eax >>= 21;
    memoryASet16(ds, edx + ebx, ax);
    eax = (int16_t)memoryAGet16(ds, edx + 0x4);
    ecx &= 0x001fffff;
    ebx = ecx;
    ebx >>= 14;
    ebx &= 0x00000070;
    eax |= ebx;
    ebx = memoryAGet(ds, esi - 2);
    ebx &= 0x00000003;
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x103f838);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x103fa38);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x103fb38);
    ebx = memoryAGet32(ds, esp - 60);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x103fc38);
    edi += 0x0000000a;
    ecx = eax;
    ecx >>= 21;
    memoryASet16(ds, edx + ebx, cx);
    eax &= 0x001fffff;
    edx += 0x0000000a;
    memoryASet32(ds, esp - 68, memoryAGet32(ds, esp - 68) - 0x00000001);
    ecx = eax;
    if (memoryAGet32(ds, esp - 68))
        goto loc_1003070;
    eax = memoryAGet32(ds, esp - 64);
    ecx = 0x00000002;
    ecx -= 0x0102cf49;
    memoryASet32(ds, esp - 60, ecx);
    ecx = 0x00000003;
    ecx -= 0x0102cf49;
    ebx = 0;
    memoryASet32(ds, esp - 48, ecx);
    memoryASet32(ds, eax, ebx);
    ecx = 0x00000004;
    edx = 0;
    eax = 0;
    ecx -= 0x0102cf49;
    memoryASet32(ds, esp - 68, ebx);
    memoryASet32(ds, esp - 56, ecx);
loc_1003283: // 0000:1003283
    ecx = (int16_t)memoryAGet16(ds, esp + eax * 2 - 44);
    edx <<= 10;
    edx |= ecx;
    edx += edx;
    edx += edx;
    ecx = ebx;
    ecx = sar32(ecx, 0x14);
    ecx &= 0x00000ff0;
    edx |= ecx;
    ecx = memoryAGet(ds, eax + 0x102cf48);
    edx |= ecx;
    ecx = memoryAGet(ds, esp - 66);
    edi = bh;
    ebx &= 0x000000ff;
    ecx += ecx;
    edx += edx;
    ecx += ecx;
    edi += edi;
    ebx += ebx;
    esi = memoryAGet32(ds, ebx + ebx + 0x103fd38);
    esi ^= memoryAGet32(ds, edi + edi + 0x1040138);
    edi += edi;
    esi ^= memoryAGet32(ds, ecx + 0x1040538);
    ebx += ebx;
    edx += edx;
    ebp = edx;
    esi ^= memoryAGet32(ss, ebp + 0x1040938);
    edx = memoryAGet32(ds, ebx + 0x1048938);
    edx ^= memoryAGet32(ds, edi + 0x1048d38);
    edi = esi;
    edx ^= memoryAGet32(ds, ecx + 0x1049138);
    ecx = esi;
    edx ^= memoryAGet32(ss, ebp + 0x1049538);
    ebp = memoryAGet32(ds, esp - 64);
    ecx = sar32(ecx, 0x04);
    ecx &= 0x00000003;
    memoryASet16(ds, esp + eax * 2 - 44, cx);
    ecx = esi;
    ecx = sar32(ecx, 0x02);
    cl &= 0x03;
    edi &= 0x00000001;
    memoryASet32(ds, esp - 68, edx);
    if ((int32_t)eax < (int32_t)0x00000008)
        goto loc_100332d;
    esi = sar32(esi, 0x00000001);
    esi &= 0x00000001;
    ecx = eax - 8;
    esi <<= cl;
    memoryASet32(ss, ebp, memoryAGet32(ss, ebp) | esi);
loc_100332d: // 0000:100332d
    ecx = (int16_t)memoryAGet16(ds, esp + eax * 2 - 42);
    edi <<= 10;
    edi |= ecx;
    edi += edi;
    ecx = edx;
    ecx = sar32(ecx, 0x14);
    ecx &= 0x00000ff0;
    edi += edi;
    edi |= ecx;
    ecx = memoryAGet(ds, eax + 0x102cf49);
    edi |= ecx;
    ecx = memoryAGet(ds, esp - 66);
    esi = dh;
    edx &= 0x000000ff;
    edi += edi;
    edx += edx;
    edi += edi;
    edx += edx;
    ecx += ecx;
    ebx = edi;
    edi = memoryAGet32(ds, edx + 0x103fd38);
    edx = memoryAGet32(ds, edx + 0x1048938);
    ecx += ecx;
    esi += esi;
    edi ^= memoryAGet32(ds, esi + esi + 0x1040138);
    edx ^= memoryAGet32(ds, esi + esi + 0x1048d38);
    edi ^= memoryAGet32(ds, ecx + 0x1040538);
    edx ^= memoryAGet32(ds, ecx + 0x1049138);
    edi ^= memoryAGet32(ds, ebx + 0x1040938);
    edx ^= memoryAGet32(ds, ebx + 0x1049538);
    esi += esi;
    ecx = edi;
    ecx = sar32(ecx, 0x04);
    ecx &= 0x00000003;
    memoryASet16(ds, esp + eax * 2 - 42, cx);
    ecx = edi;
    ecx = sar32(ecx, 0x02);
    esi = edi;
    cl &= 0x03;
    esi &= 0x00000001;
    memoryASet32(ds, esp - 68, edx);
    if ((int32_t)eax < (int32_t)0x00000007)
        goto loc_10033d3;
    edi = sar32(edi, 0x00000001);
    edi &= 0x00000001;
    ecx = eax - 7;
    edi <<= cl;
    memoryASet32(ss, ebp, memoryAGet32(ss, ebp) | edi);
loc_10033d3: // 0000:10033d3
    ecx = (int16_t)memoryAGet16(ds, esp + eax * 2 - 40);
    esi <<= 10;
    esi |= ecx;
    esi += esi;
    ecx = edx;
    ecx = sar32(ecx, 0x14);
    ecx &= 0x00000ff0;
    esi += esi;
    esi |= ecx;
    ecx = memoryAGet(ds, eax + 0x102cf4a);
    esi |= ecx;
    ecx = memoryAGet(ds, esp - 66);
    edi = dh;
    edx &= 0x000000ff;
    esi += esi;
    esi += esi;
    edx += edx;
    edx += edx;
    ebx = esi;
    esi = memoryAGet32(ds, ebx + 0x1040938);
    ecx += ecx;
    ecx += ecx;
    ebp = edx;
    esi ^= memoryAGet32(ss, ebp + 0x103fd38);
    edx = memoryAGet32(ds, ebx + 0x1049538);
    edx ^= memoryAGet32(ss, ebp + 0x1048938);
    edi += edi;
    esi ^= memoryAGet32(ds, edi + edi + 0x1040138);
    edx ^= memoryAGet32(ds, edi + edi + 0x1048d38);
    esi ^= memoryAGet32(ds, ecx + 0x1040538);
    edx ^= memoryAGet32(ds, ecx + 0x1049138);
    edi += edi;
    ecx = esi;
    ecx = sar32(ecx, 0x04);
    ecx &= 0x00000003;
    memoryASet16(ds, esp + eax * 2 - 40, cx);
    ecx = esi;
    ecx = sar32(ecx, 0x02);
    cl &= 0x03;
    ecx = memoryAGet32(ds, esp - 60);
    edi = esi;
    ecx = (ecx + eax) + 16961353;
    edi &= 0x00000001;
    memoryASet32(ds, esp - 68, edx);
    if ((int32_t)ecx < (int32_t)0x00000008)
        goto loc_1003489;
    esi = sar32(esi, 0x00000001);
    esi &= 0x00000001;
    ecx = eax - 6;
    esi <<= cl;
    ecx = memoryAGet32(ds, esp - 64);
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) | esi);
loc_1003489: // 0000:1003489
    ecx = (int16_t)memoryAGet16(ds, esp + eax * 2 - 38);
    edi <<= 10;
    edi |= ecx;
    edi += edi;
    ecx = edx;
    ecx = sar32(ecx, 0x14);
    ecx &= 0x00000ff0;
    edi += edi;
    edi |= ecx;
    ecx = memoryAGet(ds, eax + 0x102cf4b);
    edi |= ecx;
    ecx = memoryAGet(ds, esp - 66);
    esi = dh;
    edx &= 0x000000ff;
    edi += edi;
    edi += edi;
    edx += edx;
    edx += edx;
    ebx = edi;
    edi = memoryAGet32(ds, ebx + 0x1040938);
    ecx += ecx;
    ebp = edx;
    edi ^= memoryAGet32(ss, ebp + 0x103fd38);
    edx = memoryAGet32(ds, ebx + 0x1049538);
    edx ^= memoryAGet32(ss, ebp + 0x1048938);
    ecx += ecx;
    esi += esi;
    edi ^= memoryAGet32(ds, esi + esi + 0x1040138);
    edx ^= memoryAGet32(ds, esi + esi + 0x1048d38);
    edi ^= memoryAGet32(ds, ecx + 0x1040538);
    edx ^= memoryAGet32(ds, ecx + 0x1049138);
    ebp = memoryAGet32(ds, esp - 64);
    esi += esi;
    ecx = edi;
    ecx = sar32(ecx, 0x04);
    ecx &= 0x00000003;
    memoryASet16(ds, esp + eax * 2 - 38, cx);
    ecx = edi;
    ecx = sar32(ecx, 0x02);
    cl &= 0x03;
    ecx = memoryAGet32(ds, esp - 48);
    esi = edi;
    ecx = (ecx + eax) + 16961353;
    esi &= 0x00000001;
    memoryASet32(ds, esp - 68, edx);
    if ((int32_t)ecx < (int32_t)0x00000008)
        goto loc_1003540;
    edi = sar32(edi, 0x00000001);
    edi &= 0x00000001;
    ecx = eax - 5;
    edi <<= cl;
    memoryASet32(ss, ebp, memoryAGet32(ss, ebp) | edi);
loc_1003540: // 0000:1003540
    ecx = (int16_t)memoryAGet16(ds, esp + eax * 2 - 36);
    esi <<= 10;
    esi |= ecx;
    esi += esi;
    ecx = edx;
    ecx = sar32(ecx, 0x14);
    ecx &= 0x00000ff0;
    esi += esi;
    esi |= ecx;
    ecx = memoryAGet(ds, eax + 0x102cf4c);
    esi |= ecx;
    ecx = memoryAGet(ds, esp - 66);
    esi += esi;
    ebx = dh;
    esi += esi;
    edx &= 0x000000ff;
    edi = esi;
    esi = memoryAGet32(ds, edi + 0x1040938);
    edi = memoryAGet32(ds, edi + 0x1049538);
    ecx += ecx;
    edx += edx;
    esi ^= memoryAGet32(ds, edx + edx + 0x103fd38);
    edi ^= memoryAGet32(ds, edx + edx + 0x1048938);
    ecx += ecx;
    edx += edx;
    ebx += ebx;
    esi ^= memoryAGet32(ds, ebx + ebx + 0x1040138);
    edi ^= memoryAGet32(ds, ebx + ebx + 0x1048d38);
    esi ^= memoryAGet32(ds, ecx + 0x1040538);
    edi ^= memoryAGet32(ds, ecx + 0x1049138);
    ebx += ebx;
    ecx = esi;
    ecx = sar32(ecx, 0x04);
    ecx &= 0x00000003;
    memoryASet16(ds, esp + eax * 2 - 36, cx);
    ecx = esi;
    ecx = sar32(ecx, 0x02);
    cl &= 0x03;
    ecx = memoryAGet32(ds, esp - 56);
    edx = esi;
    ecx = (ecx + eax) + 16961353;
    edx &= 0x00000001;
    ebx = edi;
    memoryASet32(ds, esp - 68, ebx);
    if ((int32_t)ecx < (int32_t)0x00000008)
        goto loc_10035f5;
    esi = sar32(esi, 0x00000001);
    esi &= 0x00000001;
    ecx = eax - 4;
    esi <<= cl;
    memoryASet32(ss, ebp, memoryAGet32(ss, ebp) | esi);
loc_10035f5: // 0000:10035f5
    eax += 0x00000005;
    if ((int32_t)eax < (int32_t)0x00000028)
        goto loc_1003283;
    eax = memoryAGet32(ds, esp + 0x38);
    esi = memoryAGet32(ds, esp - 52);
    edi = esp - 42;
    ebx = edi;
    ebx -= eax;
    memoryASet32(ds, esp - 52, ebx);
    ebp = esp - 44;
    ebx = esp - 40;
    ecx = 0;
    esi++;
    ebp -= eax;
    ebx -= eax;
    edx = eax + 4;
    memoryASet32(ds, esp - 56, ebx);
    memoryASet32(ds, esp - 64, 0x00000008);
loc_1003635: // 0000:1003635
    eax = (int16_t)memoryAGet16(ds, edx - 4);
    ebx = ecx;
    ebx >>= 14;
    ebx &= 0x00000070;
    eax |= ebx;
    ebx = (int16_t)memoryAGet16(ds, edi - 2);
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x1051538);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1051738);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1051838);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x1051938);
    ecx = eax;
    eax &= 0x001fffff;
    ecx >>= 21;
    memoryASet(ds, esi - 1, cl);
    ecx = (int16_t)memoryAGet16(ds, edx - 2);
    ebx = eax;
    ebx >>= 14;
    ebx &= 0x00000070;
    ecx |= ebx;
    ebx = (int16_t)memoryAGet16(ds, edi);
    ebx += ebx;
    ebx += ebx;
    ecx |= ebx;
    ecx = memoryAGet32(ds, ecx * 4 + 0x1051538);
    ebx = eax;
    ebx >>= 12;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x1051738);
    ebx = eax;
    ebx >>= 6;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x1051838);
    eax &= 0x0000003f;
    ecx ^= memoryAGet32(ds, eax * 4 + 0x1051938);
    eax = ecx;
    eax >>= 21;
    memoryASet(ds, esi, al);
    ebx = (int16_t)memoryAGet16(ds, edx);
    ecx &= 0x001fffff;
    eax = ecx;
    eax >>= 14;
    eax &= 0x00000070;
    eax |= ebx;
    ebx = (int16_t)memoryAGet16(ss, ebp + edx);
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x1051538);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1051738);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1051838);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x1051938);
    ecx = eax;
    ecx >>= 21;
    eax &= 0x001fffff;
    memoryASet(ds, esi + 0x1, cl);
    ecx = (int16_t)memoryAGet16(ds, edx + 0x2);
    ebx = eax;
    ebx >>= 14;
    ebx &= 0x00000070;
    ecx |= ebx;
    ebx = memoryAGet32(ds, esp - 52);
    ebx = (int16_t)memoryAGet16(ds, edx + ebx);
    ebx += ebx;
    ebx += ebx;
    ecx |= ebx;
    ecx = memoryAGet32(ds, ecx * 4 + 0x1051538);
    ebx = eax;
    ebx >>= 12;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x1051738);
    ebx = eax;
    ebx >>= 6;
    ebx &= 0x0000003f;
    ecx ^= memoryAGet32(ds, ebx * 4 + 0x1051838);
    eax &= 0x0000003f;
    ecx ^= memoryAGet32(ds, eax * 4 + 0x1051938);
    esi += 0x00000005;
    eax = ecx;
    eax >>= 21;
    ecx &= 0x001fffff;
    memoryASet(ds, esi - 3, al);
    eax = (int16_t)memoryAGet16(ds, edx + 0x4);
    ebx = ecx;
    ebx >>= 14;
    ebx &= 0x00000070;
    eax |= ebx;
    ebx = memoryAGet32(ds, esp - 56);
    ebx = (int16_t)memoryAGet16(ds, edx + ebx);
    ebx += ebx;
    ebx += ebx;
    eax |= ebx;
    eax = memoryAGet32(ds, eax * 4 + 0x1051538);
    ebx = ecx;
    ebx >>= 12;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1051738);
    ebx = ecx;
    ebx >>= 6;
    ebx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ebx * 4 + 0x1051838);
    ecx &= 0x0000003f;
    eax ^= memoryAGet32(ds, ecx * 4 + 0x1051938);
    edi += 0x0000000a;
    ecx = eax;
    ecx >>= 21;
    memoryASet(ds, esi - 2, cl);
    eax &= 0x001fffff;
    edx += 0x0000000a;
    memoryASet32(ds, esp - 64, memoryAGet32(ds, esp - 64) - 0x00000001);
    ecx = eax;
    if (memoryAGet32(ds, esp - 64))
        goto loc_1003635;
    ecx = memoryAGet32(ds, esp + 0x24);
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x0000006c;
    // SEH removed (was stack_unbalanced, 0/-333) // SEH removed (was stack_unbalanced, 0/-333)
    esp += 4;
}
void sub_1003803() // 0000:1003803 +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd4;
    push32(ebx);
    push32(esi);
    push32(edi);
    edx = memoryAGet32(ds, 0x1146c90);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(memoryAGet32(ds, edx + 0x1c));
    eax = ebp - 44;
    push32(eax);
    sub_1002f74();
    memoryASet32(ss, ebp - 4, 0x00000028);
    if (memoryAGet32(ss, ebp + 0x10) == 0x00000001)
        goto loc_1003912;
    memoryASet32(ss, ebp - 4, 0x00000000);
loc_1003839: // 0000:1003839
    if (memoryAGet32(ss, ebp - 4))
        goto loc_1003854;
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    sub_10039bb();
    goto loc_100389d;
loc_1003854: // 0000:1003854
    if (memoryAGet32(ss, ebp - 4) == 0x00000028)
        goto loc_1003990;
    if (!memoryAGet32(ss, ebp - 4))
        goto loc_1003990;
    ecx = memoryAGet32(ss, ebp - 4);
    ecx--;
    ecx = (int32_t)ecx * (int32_t)0x00000088;
    ebx = ecx + 18115740;
    ecx = memoryAGet32(ds, ebx + 0x80);
    ecx = (int32_t)ecx * (int32_t)0x00000020;
    ebx = ecx + ebx;
    push32(memoryAGet32(ds, ebx + 0x14));
    push32(memoryAGet32(ds, ebx + 0x10));
    push32(memoryAGet32(ds, ebx + 0xc));
    push32(memoryAGet32(ds, ebx + 0x8));
    push32(memoryAGet32(ds, ebx + 0x4));
    push32(memoryAGet32(ds, ebx));
    push32(memoryAGet32(ss, ebp - 4));
    sub_10039bb();
loc_100389d: // 0000:100389d
    ecx = memoryAGet32(ss, ebp - 4);
    ecx = (int32_t)ecx * (int32_t)0x00000088;
    ebx = ecx + 18115740;
    memoryASet32(ds, ebx + 0x80, 0xffffffff);
    memoryASet32(ds, ebx + 0x84, 0x00000000);
    ecx = memoryAGet32(ss, ebp - 4);
    edx = ebp - 44;
    edx = memoryAGet(ds, ecx + edx);
    ecx = 0;
    edi = 0;
loc_10038ce: // 0000:10038ce
    memoryASet32(ds, ecx + ebx + 0x1c, 0x00000000);
    eax = memoryAGet32(ds, ecx + ebx + 0x18);
    if (eax != edx)
        goto loc_10038fb;
    memoryASet32(ds, ecx + ebx + 0x1c, 0x00000001);
    memoryASet32(ds, ebx + 0x84, memoryAGet32(ds, ebx + 0x84) + 1);
    if (memoryAGet32(ds, ebx + 0x80) != 0xffffffff)
        goto loc_10038fb;
    memoryASet32(ds, ebx + 0x80, edi);
loc_10038fb: // 0000:10038fb
    ecx = ecx + 32;
    edi++;
    if (edi != 0x00000004)
        goto loc_10038ce;
    if (memoryAGet32(ds, ebx + 0x80) == 0xffffffff)
        goto loc_1003912;
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) + 1);
    goto loc_1003986;
loc_1003912: // 0000:1003912
    ecx = memoryAGet32(ss, ebp - 4);
    if (!memoryAGet32(ss, ebp - 4))
        goto loc_1003986;
    ecx--;
    ecx = (int32_t)ecx * (int32_t)0x00000088;
    ebx = ecx + 18115740;
    if (!memoryAGet32(ds, ebx + 0x84))
        goto loc_1003966;
    memoryASet32(ds, ebx + 0x80, memoryAGet32(ds, ebx + 0x80) + 1);
    edi = memoryAGet32(ds, ebx + 0x80);
    memoryASet32(ds, ebx + 0x80, 0xffffffff);
    goto loc_100395f;
loc_1003949: // 0000:1003949
    ecx = 0;
    ecx = (int32_t)edi * (int32_t)0x00000020;
    eax = memoryAGet32(ds, ecx + ebx + 0x1c);
    if (!eax)
        goto loc_100395e;
    memoryASet32(ds, ebx + 0x80, edi);
    goto loc_1003970;
loc_100395e: // 0000:100395e
    edi++;
loc_100395f: // 0000:100395f
    if (edi != 0x00000004)
        goto loc_1003949;
    goto loc_1003970;
loc_1003966: // 0000:1003966
    memoryASet32(ds, ebx + 0x80, 0xffffffff);
loc_1003970: // 0000:1003970
    if (memoryAGet32(ds, ebx + 0x80) == 0xffffffff)
        goto loc_100397b;
    goto loc_1003986;
loc_100397b: // 0000:100397b
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) - 1);
    if (!memoryAGet32(ss, ebp - 4))
        goto loc_1003986;
    goto loc_1003912;
loc_1003986: // 0000:1003986
    if (memoryAGet32(ss, ebp - 4))
        goto loc_1003839;
loc_1003990: // 0000:1003990
    if (memoryAGet32(ss, ebp - 4) != 0x00000028)
        goto loc_10039b4;
    ebx = 0x01146c9c;
    edi = memoryAGet32(ss, ebp + 0xc);
    ecx = 0;
loc_10039a0: // 0000:10039a0
    eax = (int32_t)ecx * (int32_t)0x00000088;
    eax = memoryAGet32(ds, eax + ebx + 0x80);
    stosb<ES_EDI>(al);
    ecx++;
    if (ecx != 0x00000028)
        goto loc_10039a0;
loc_10039b4: // 0000:10039b4
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 12/-36) // SEH removed (was stack_unbalanced, 12/-36)
    esp += 16;
}
void sub_10039bb() // 0000:10039bb +long +stackDrop28
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffff8;
    push32(ebx);
    push32(esi);
    ecx = memoryAGet32(ss, ebp + 0x8);
    ecx = (int32_t)ecx * (int32_t)0x00000088;
    ebx = ecx + 18115740;
    esi = memoryAGet32(ds, 0x1146c90);
    ecx = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, esi + 0x4);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = 0x00000000;
    eax |= edx;
    edx = memoryAGet(ds, ecx + 0x102cf20);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0xc);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx, edx);
    eax = memoryAGet32(ds, esi);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x10);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0x4, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 4, edx);
    eax = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, esi + 0x10);
    edx = memoryAGet(ds, ecx + edx);
    eax |= edx;
    edx = 0x00000000;
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x14);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx + 0x8, edx);
    eax = memoryAGet32(ds, esi + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x8);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x18);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0xc, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 8, edx);
    eax = memoryAGet32(ds, esi + 0x18);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp - 8);
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x1c);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx + 0x10, edx);
    eax = memoryAGet32(ds, esi + 0x14);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x10);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x20);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0x14, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ds, ebx + 0x18, edx);
    ebx += 0x00000020;
    eax = memoryAGet32(ds, esi + 0x4);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = 0x00000001;
    eax |= edx;
    edx = memoryAGet(ds, ecx + 0x102cf20);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0xc);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx, edx);
    eax = memoryAGet32(ds, esi);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x10);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0x4, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 4, edx);
    eax = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, esi + 0x10);
    edx = memoryAGet(ds, ecx + edx);
    eax |= edx;
    edx = 0x00000001;
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x14);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx + 0x8, edx);
    eax = memoryAGet32(ds, esi + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x8);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x18);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0xc, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 8, edx);
    eax = memoryAGet32(ds, esi + 0x18);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp - 8);
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x1c);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx + 0x10, edx);
    eax = memoryAGet32(ds, esi + 0x14);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x10);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x20);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0x14, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ds, ebx + 0x18, edx);
    ebx += 0x00000020;
    eax = memoryAGet32(ds, esi + 0x4);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = 0x00000002;
    eax |= edx;
    edx = memoryAGet(ds, ecx + 0x102cf20);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0xc);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx, edx);
    eax = memoryAGet32(ds, esi);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x10);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0x4, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 4, edx);
    eax = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, esi + 0x10);
    edx = memoryAGet(ds, ecx + edx);
    eax |= edx;
    edx = 0x00000002;
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x14);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx + 0x8, edx);
    eax = memoryAGet32(ds, esi + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x8);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x18);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0xc, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 8, edx);
    eax = memoryAGet32(ds, esi + 0x18);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp - 8);
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x1c);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx + 0x10, edx);
    eax = memoryAGet32(ds, esi + 0x14);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x10);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x20);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0x14, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ds, ebx + 0x18, edx);
    ebx += 0x00000020;
    eax = memoryAGet32(ds, esi + 0x4);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = 0x00000003;
    eax |= edx;
    edx = memoryAGet(ds, ecx + 0x102cf20);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0xc);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0xc);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx, edx);
    eax = memoryAGet32(ds, esi);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x10);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x10);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0x4, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 4, edx);
    eax = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, esi + 0x10);
    edx = memoryAGet(ds, ecx + edx);
    eax |= edx;
    edx = 0x00000003;
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x14);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0x14);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx + 0x8, edx);
    eax = memoryAGet32(ds, esi + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x8);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x18);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x18);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0xc, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ss, ebp - 8, edx);
    eax = memoryAGet32(ds, esi + 0x18);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ss, ebp - 8);
    eax |= edx;
    edx = memoryAGet32(ss, ebp - 4);
    edx <<= 2;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x1c);
    edx >>= 16;
    edx &= 0x00001f80;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x102cf90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 8;
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1034f90);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax >>= 16;
    eax &= 0x0000007f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035390);
    eax = memoryAGet32(ss, ebp + 0x1c);
    eax &= 0x000000ff;
    edx ^= memoryAGet32(ds, eax * 4 + 0x1035590);
    memoryASet32(ds, ebx + 0x10, edx);
    eax = memoryAGet32(ds, esi + 0x14);
    eax = memoryAGet16(ds, eax + ecx * 2);
    edx = memoryAGet32(ds, ebx + 0x10);
    edx >>= 23;
    edx &= 0x000001c0;
    eax |= edx;
    edx = memoryAGet32(ss, ebp + 0x20);
    edx >>= 8;
    edx &= 0x00001e00;
    eax |= edx;
    edx = memoryAGet32(ds, eax * 4 + 0x1035990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 6;
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103d990);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax >>= 12;
    eax &= 0x0000001f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103da90);
    eax = memoryAGet32(ss, ebp + 0x20);
    eax &= 0x0000003f;
    edx ^= memoryAGet32(ds, eax * 4 + 0x103db10);
    memoryASet32(ds, ebx + 0x14, edx);
    edx >>= 21;
    edx &= 0x00000003;
    memoryASet32(ds, ebx + 0x18, edx);
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 28/16) // SEH removed (was stack_below, 28/16)
    esp += 32;
}
void sub_100430e() // 0000:100430e +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    eax = ebp - 4;
    push32(eax);
    push32(0x01051cb0);
    push32(0x01051d00);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003022();
    esp += 0x00000014;
    eax = memoryAGet32(ss, ebp - 4);
    esp = ebp; ebp = pop32();
    esp += 12;
}
void sub_1004337() // 0000:1004337 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    memoryASet32(ds, 0x1146c90, 0x01051c90);
    push32(0x00000000);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003803();
loc_1004355: // 0000:1004355
    push32(memoryAGet32(ss, ebp + 0xc));
    eax = ebp - 40;
    push32(eax);
    sub_100430e();
    if (!eax)
        goto loc_1004375;
    push32(0x00000001);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003803();
    goto loc_1004355;
loc_1004375: // 0000:1004375
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 8/-36) // SEH removed (was stack_unbalanced, 8/-36)
    esp += 12;
}
void sub_1004379() // 0000:1004379 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    eax = ebp - 4;
    push32(eax);
    push32(0x01051fc8);
    push32(0x01052018);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003022();
    esp += 0x00000014;
    eax = memoryAGet32(ss, ebp - 4);
    esp = ebp; ebp = pop32();
    esp += 12;
}
void sub_10043a2() // 0000:10043a2 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    memoryASet32(ds, 0x1146c90, 0x01051fa8);
    push32(0x00000000);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003803();
loc_10043c0: // 0000:10043c0
    push32(memoryAGet32(ss, ebp + 0xc));
    eax = ebp - 40;
    push32(eax);
    sub_1004379();
    if (!eax)
        goto loc_10043e0;
    push32(0x00000001);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003803();
    goto loc_10043c0;
loc_10043e0: // 0000:10043e0
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 8/-36) // SEH removed (was stack_unbalanced, 8/-36)
    esp += 12;
}
void sub_10043e4() // 0000:10043e4 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    eax = ebp - 4;
    push32(eax);
    push32(0x010522e0);
    push32(0x01052330);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003022();
    esp += 0x00000014;
    eax = memoryAGet32(ss, ebp - 4);
    esp = ebp; ebp = pop32();
    esp += 12;
}
void sub_100440d() // 0000:100440d +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    memoryASet32(ds, 0x1146c90, 0x010522c0);
    push32(0x00000000);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003803();
loc_100442b: // 0000:100442b
    push32(memoryAGet32(ss, ebp + 0xc));
    eax = ebp - 40;
    push32(eax);
    sub_10043e4();
    if (!eax)
        goto loc_100444b;
    push32(0x00000001);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003803();
    goto loc_100442b;
loc_100444b: // 0000:100444b
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 8/-36) // SEH removed (was stack_unbalanced, 8/-36)
    esp += 12;
}
void sub_100444f() // 0000:100444f +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffffc;
    eax = ebp - 4;
    push32(eax);
    push32(0x010525f8);
    push32(0x01052648);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003022();
    esp += 0x00000014;
    eax = memoryAGet32(ss, ebp - 4);
    esp = ebp; ebp = pop32();
    esp += 12;
}
void sub_1004478() // 0000:1004478 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    memoryASet32(ds, 0x1146c90, 0x010525d8);
    push32(0x00000000);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003803();
loc_1004496: // 0000:1004496
    push32(memoryAGet32(ss, ebp + 0xc));
    eax = ebp - 40;
    push32(eax);
    sub_100444f();
    if (!eax)
        goto loc_10044b6;
    push32(0x00000001);
    eax = ebp - 40;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1003803();
    goto loc_1004496;
loc_10044b6: // 0000:10044b6
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 8/-36) // SEH removed (was stack_unbalanced, 8/-36)
    esp += 12;
}
void sub_10044ba() // 0000:10044ba +long +stackDrop12
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(esi);
    push32(edi);
    edi = memoryAGet32(ds, 0x1146c94);
    esi = 0x0102cf48;
    ecx = 0x00000028;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    push32(0x00000050);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(0x0102cde0);
    sub_100101d();
    if (eax)
        goto loc_10044f1;
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1004337();
    goto loc_1004558;
loc_10044f1: // 0000:10044f1
    push32(0x00000050);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(0x0102ce30);
    sub_100101d();
    if (eax)
        goto loc_1004511;
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_10043a2();
    goto loc_1004558;
loc_1004511: // 0000:1004511
    push32(0x00000050);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(0x0102ce80);
    sub_100101d();
    if (eax)
        goto loc_1004531;
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100440d();
    goto loc_1004558;
loc_1004531: // 0000:1004531
    push32(0x00000050);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(0x0102ced0);
    sub_100101d();
    if (eax)
        goto loc_1004551;
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1004478();
    goto loc_1004558;
loc_1004551: // 0000:1004551
    push32(0x00000000);
    sub_100606c();
loc_1004558: // 0000:1004558
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 12/8) // SEH removed (was stack_below, 12/8)
    esp += 16;
}
void sub_1004560() // 0000:1004560 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x00a1cb58)
        goto loc_1004589;
    eax = 0x0000015e;
    goto loc_100458b;
loc_1004589: // 0000:1004589
    eax = 0;
loc_100458b: // 0000:100458b
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_10045d0() // 0000:10045d0 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x00581450)
        goto loc_10045f9;
    eax = 0x000000dc;
    goto loc_10045fb;
loc_10045f9: // 0000:10045f9
    eax = 0;
loc_10045fb: // 0000:10045fb
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_1004600() // 0000:1004600 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    push32(ebx);
    ebx = ebp - 40;
    push32(0x010df318);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(0x010df200);
    sub_1001181();
    push32(0x010e0618);
    push32(0x010df2c8);
    push32(0x010df2a0);
    push32(0x010df250);
    push32(ebx);
    sub_1001200();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_1004640() // 0000:1004640 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x0155daa0)
        goto loc_1004669;
    eax = 0x000001ae;
    goto loc_100466b;
loc_1004669: // 0000:1004669
    eax = 0;
loc_100466b: // 0000:100466b
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_1004670() // 0000:1004670 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffd8;
    push32(ebx);
    ebx = ebp - 40;
    push32(0x010fbc18);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(0x010fbb00);
    sub_1001181();
    push32(0x010fcf18);
    push32(0x010fbbc8);
    push32(0x010fbba0);
    push32(0x010fbb50);
    push32(ebx);
    sub_1001200();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_10046b0() // 0000:10046b0 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffdc;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1006066();
    memoryASet32(ss, ebp - 32, 0x00000000);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_10046d1: // 0000:10046d1
    push32(edi);
    esi = 0x01052858;
    ecx = 0x00000028;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (!flags.zero)
        goto loc_10046e4;
    memoryASet32(ss, ebp - 32, memoryAGet32(ss, ebp - 32) + 1);
loc_10046e4: // 0000:10046e4
    if (memoryAGet32(ss, ebp - 32) == 0x00000002)
        goto loc_10046ed;
    edi++;
    goto loc_10046d1;
loc_10046ed: // 0000:10046ed
    memoryASet32(ds, 0x11481e4, edi);
    goto loc_1004718;
    // gap 35 bytes // gap 35 bytes
loc_1004718: // 0000:1004718
    edi = memoryAGet32(ds, ebx + 0x4);
loc_100471b: // 0000:100471b
    push32(edi);
    esi = 0x01052880;
    ecx = 0x00000020;
    for (flags.zero = 1; ecx != 0 && flags.zero; --ecx) cmpsb<DS_ESI, ES_EDI>();
    edi = pop32();
    if (flags.zero)
        goto loc_100472e;
    edi++;
    goto loc_100471b;
loc_100472e: // 0000:100472e
    memoryASet32(ds, 0x11481e8, edi);
    edi = memoryAGet32(ds, ebx + 0x4);
loc_1004737: // 0000:1004737
    esi = memoryAGet32(ds, 0x11481e8);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_1004749;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_100474c;
loc_1004749: // 0000:1004749
    edi++;
    goto loc_1004737;
loc_100474c: // 0000:100474c
    push32(edi);
loc_100474d: // 0000:100474d
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_1004759;
    goto loc_100474d;
loc_1004759: // 0000:1004759
    ebx = 0x00000023;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x010046f5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_1004775: // 0000:1004775
    esi = memoryAGet32(ds, 0x11481e8);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_1004787;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_100478a;
loc_1004787: // 0000:1004787
    edi++;
    goto loc_1004775;
loc_100478a: // 0000:100478a
    push32(edi);
loc_100478b: // 0000:100478b
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_1004797;
    goto loc_100478b;
loc_1004797: // 0000:1004797
    ebx = 0x00000023;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x010046f5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_10047b3: // 0000:10047b3
    esi = memoryAGet32(ds, 0x11481e8);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_10047c5;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_10047c8;
loc_10047c5: // 0000:10047c5
    edi++;
    goto loc_10047b3;
loc_10047c8: // 0000:10047c8
    push32(edi);
loc_10047c9: // 0000:10047c9
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_10047d5;
    goto loc_10047c9;
loc_10047d5: // 0000:10047d5
    ebx = 0x00000023;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x010046f5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_10047f1: // 0000:10047f1
    esi = memoryAGet32(ds, 0x11481e8);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_1004803;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_1004806;
loc_1004803: // 0000:1004803
    edi++;
    goto loc_10047f1;
loc_1004806: // 0000:1004806
    push32(edi);
loc_1004807: // 0000:1004807
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_1004813;
    goto loc_1004807;
loc_1004813: // 0000:1004813
    ebx = 0x00000023;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x010046f5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    edi = pop32();
loc_100482f: // 0000:100482f
    esi = memoryAGet32(ds, 0x11481e8);
    if (memoryAGet32(ds, edi) != esi)
        goto loc_1004841;
    if (memoryAGet16(ds, edi - 2) == 0xbd3c)
        goto loc_1004844;
loc_1004841: // 0000:1004841
    edi++;
    goto loc_100482f;
loc_1004844: // 0000:1004844
    edi--;
    if (memoryAGet32(ds, edi - 4) == 0x00fc0000)
        goto loc_1004850;
    goto loc_1004844;
loc_1004850: // 0000:1004850
    ebx = 0x00000023;
    eax = ebp - 36;
    push32(eax);
    push32(0x00000040);
    push32(ebx);
    push32(edi);
    sub_1006072();
    esi = 0x010046f5;
    ecx = ebx;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-128) // SEH removed (was stack_unbalanced, 4/-128)
    esp += 8;
}
void sub_1005a60() // 0000:1005a60 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x00580408)
        goto loc_1005a89;
    eax = 0x00000079;
    goto loc_1005a8b;
loc_1005a89: // 0000:1005a89
    eax = 0;
loc_1005a8b: // 0000:1005a8b
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_1005ad0() // 0000:1005ad0 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x0067d268)
        goto loc_1005af9;
    eax = 0x00000262;
    goto loc_1005afb;
loc_1005af9: // 0000:1005af9
    eax = 0;
loc_1005afb: // 0000:1005afb
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_1005dc6() // 0000:1005dc6 +long +stackDrop4
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xffffffe4;
    push32(ebx);
    ebx = ebp - 28;
    push32(0x0000001c);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1006066();
    eax = memoryAGet32(ss, ebp + 0x8);
    eax -= memoryAGet32(ds, ebx + 0x4);
    if (eax != 0x00ea9550)
        goto loc_1005def;
    eax = 0x0000006e;
    goto loc_1005df1;
loc_1005def: // 0000:1005def
    eax = 0;
loc_1005df1: // 0000:1005df1
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 4/-40) // SEH removed (was stack_unbalanced, 4/-40)
    esp += 8;
}
void sub_1005e70() // 0000:1005e70 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    ebx = 0x0109c770;
loc_1005e7b: // 0000:1005e7b
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_1001000();
    if (eax)
        goto loc_1005e97;
    esi = ebx + 16;
    edi = memoryAGet32(ss, ebp + 0xc);
    ecx = 0x00000004;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    goto loc_1005e9f;
loc_1005e97: // 0000:1005e97
    ebx = ebx + 32;
    if (memoryAGet32(ds, ebx))
        goto loc_1005e7b;
loc_1005e9f: // 0000:1005e9f
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 8/4) // SEH removed (was stack_below, 8/4)
    esp += 12;
}
void sub_1005ea6() // 0000:1005ea6 +long +stackDrop8
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    push32(edi);
    if (memoryAGet32(ss, ebp + 0xc))
        goto loc_1005ede;
    ebx = memoryAGet32(ss, ebp + 0x8);
    push32(0x0000008b);
    push32(0x00000040);
    sub_1006054();
    memoryASet32(ds, ebx + 0x28, eax);
    memoryASet32(ds, ebx + 0x2c, 0x0000008b);
    edi = eax;
    esi = 0x010a5834;
    ecx = 0x0000008b;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    goto loc_1005f79;
loc_1005ede: // 0000:1005ede
    if (memoryAGet32(ss, ebp + 0xc) != 0x00000001)
        goto loc_1005f12;
    ebx = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, ebx + 0x14);
    memoryASet32(ds, ebx + 0x1c, eax);
    esi = memoryAGet32(ds, ebx + 0x10);
    edi = memoryAGet32(ds, ebx + 0x18);
    ebx = memoryAGet32(ds, ebx + 0x1c);
loc_1005ef6: // 0000:1005ef6
    push32(0x010a58df);
    push32(edi);
    push32(esi);
    sub_1001157();
    esi = esi + 16;
    edi = edi + 16;
    ebx = ebx - 16;
    if (ebx > 0x00000000)
        goto loc_1005ef6;
    goto loc_1005f79;
loc_1005f12: // 0000:1005f12
    if (memoryAGet32(ss, ebp + 0xc) != 0x00000002)
        goto loc_1005f64;
    ebx = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, ebx + 0x8);
    eax = eax + 91;
    push32(0x01149770);
    push32(eax);
    sub_1005e70();
    if (eax)
        goto loc_1005f5b;
    eax = memoryAGet32(ds, ebx + 0x1c);
    memoryASet32(ds, ebx + 0x24, eax);
    esi = memoryAGet32(ds, ebx + 0x18);
    edi = memoryAGet32(ds, ebx + 0x20);
    ebx = memoryAGet32(ds, ebx + 0x24);
loc_1005f3f: // 0000:1005f3f
    push32(0x01149770);
    push32(edi);
    push32(esi);
    sub_100112d();
    esi = esi + 16;
    edi = edi + 16;
    ebx = ebx - 16;
    if (ebx > 0x00000000)
        goto loc_1005f3f;
    goto loc_1005f79;
loc_1005f5b: // 0000:1005f5b
    memoryASet32(ds, ebx + 0x24, 0x00000000);
    goto loc_1005f79;
loc_1005f64: // 0000:1005f64
    if (memoryAGet32(ss, ebp + 0xc) != 0x00000003)
        goto loc_1005f79;
    esi = 0x010a58bf;
    edi = memoryAGet32(ss, ebp + 0x8);
    ecx = 0x00000004;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
loc_1005f79: // 0000:1005f79
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_below, 8/4) // SEH removed (was stack_below, 8/4)
    esp += 12;
}
void sub_1006054() // GlobalAlloc (stdcall, 2 args: flags, size)
{ uint32_t flags=memoryAGet32(ss,esp); uint32_t size=memoryAGet32(ss,esp+4);
  if(!size) size=32; // minimum alloc
  eax=allocate(size); printf("  SYNSO GlobalAlloc(flags=0x%x,sz=%d)=0x%08x\n",flags,size,eax); esp+=8; }
void sub_100605a() // GlobalFree thunk
{ esp+=4; eax=0; }
void sub_1006060() // RaiseException thunk
{ printf("  SYNSO RaiseException!\n"); esp+=16; }
void sub_1006066() // VirtualQuery (stdcall, 3 args: addr, buf, len)
{ esp -= 4; // synthetic
  uint32_t addr=memoryAGet32(ss,esp+4); uint32_t buf=memoryAGet32(ss,esp+8);
  printf("  VirtualQuery(addr=0x%08x, buf=0x%08x)\n", addr, buf);
  if(buf){
    // Determine allocation base from address
    uint32_t allocBase = 0x00000000; // reloc build: main DLL base is 0x0 (MEM_BASE=0)
    if (addr >= 0x01000000 && addr < 0x01200000) allocBase = 0x01000000; // SYNSOEMU
    memoryASet32(ds,buf+0x00,addr);       // BaseAddress
    memoryASet32(ds,buf+0x04,allocBase);  // AllocationBase
    memoryASet32(ds,buf+0x08,0x40);       // AllocationProtect (PAGE_EXECUTE_READWRITE)
    memoryASet32(ds,buf+0x0C,0x1000);     // RegionSize
    memoryASet32(ds,buf+0x10,0x1000);     // State (MEM_COMMIT)
    memoryASet32(ds,buf+0x14,0x40);       // Protect
    memoryASet32(ds,buf+0x18,0x1000000);  // Type (MEM_IMAGE)
  } eax=28; esp+=16; } // +4 synthetic +12 stdcall
void sub_100606c() // ExitProcess thunk
{ printf("  SYNSO ExitProcess!\n"); esp+=4; }
void sub_1006072() // VirtualProtect thunk
{ uint32_t oldProt=memoryAGet32(ss,esp+16); if(oldProt) memoryASet32(ds,oldProt,0x40); eax=1; esp+=16; }

