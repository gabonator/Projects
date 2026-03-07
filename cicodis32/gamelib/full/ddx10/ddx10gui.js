function sub_10001b10() // 0000:10001b10 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
/*
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] &= 0xfffffff8;
    push32(0xffffffff);
    push32(0x1003aeb1);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    r32[esp] -= 0x00000068;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 120;
//    memoryASet32(fs, 0x0, r32[eax]);
*/


    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] &= 0xfffffff8;
    r32[esp] -= 0x00000068;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);


    r32[esi] = r32[ecx];
    memoryASet32(ds, r32[esp] + 0x20, r32[esi]);
    push32(0x00000030);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[edi] = 0;
    memoryASet32(ds, r32[esp] + 0x80, r32[edi]);
    if (r32[eax] == r32[edi])
        { pc = 0x10001b7e; break; }
    r32[ecx] = r32[esp] + 64;
    push32(r32[ecx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, 0x00000001);
    memoryASet32(ds, r32[esp] + 0x4c, 0x1003ed34);
    sub_1001d620();
    memoryASet32(ds, r32[esp] + 0x2c, r32[eax]);
    { pc = 0x10001b82; break; }
  case 0x10001b7e: // 0000:10001b7e
    memoryASet32(ds, r32[esp] + 0x2c, r32[edi]);
  case 0x10001b82: // 0000:10001b82
    r32[ebx] |= 0xffffffff;
    push32(0x00000030);
    memoryASet32(ds, r32[esp] + 0x84, r32[ebx]);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[ecx] = 0x00000001;
    memoryASet32(ds, r32[esp] + 0x80, r32[ecx]);
    if (r32[eax] == r32[edi])
        { pc = 0x10001bc7; break; }
    r32[edx] = r32[esp] + 64;
    push32(r32[edx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x4c, 0x1003ed40);
    sub_1001d620();
    memoryASet32(ds, r32[esp] + 0x30, r32[eax]);
    { pc = 0x10001bcb; break; }
  case 0x10001bc7: // 0000:10001bc7
    memoryASet32(ds, r32[esp] + 0x30, r32[edi]);
  case 0x10001bcb: // 0000:10001bcb
    push32(0x00000030);
    memoryASet32(ds, r32[esp] + 0x84, r32[ebx]);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000002);
    if (r32[eax] == r32[edi])
        { pc = 0x10001c10; break; }
    r32[ecx] = r32[esp] + 64;
    push32(r32[ecx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, 0x00000001);
    memoryASet32(ds, r32[esp] + 0x4c, 0x1003ed50);
    sub_1001d620();
    memoryASet32(ds, r32[esp] + 0x1c, r32[eax]);
    { pc = 0x10001c14; break; }
  case 0x10001c10: // 0000:10001c10
    memoryASet32(ds, r32[esp] + 0x1c, r32[edi]);
  case 0x10001c14: // 0000:10001c14
    push32(0x00000030);
    memoryASet32(ds, r32[esp] + 0x84, r32[ebx]);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000003);
    if (r32[eax] == r32[edi])
        { pc = 0x10001c59; break; }
    r32[edx] = r32[esp] + 64;
    push32(r32[edx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, 0x00000001);
    memoryASet32(ds, r32[esp] + 0x4c, 0x1003ed58);
    sub_1001d620();
    memoryASet32(ds, r32[esp] + 0x34, r32[eax]);
    { pc = 0x10001c5d; break; }
  case 0x10001c59: // 0000:10001c59
    memoryASet32(ds, r32[esp] + 0x34, r32[edi]);
  case 0x10001c5d: // 0000:10001c5d
    push32(0x00000030);
    memoryASet32(ds, r32[esp] + 0x84, r32[ebx]);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000004);
    if (r32[eax] == r32[edi])
        { pc = 0x10001ca2; break; }
    r32[ecx] = r32[esp] + 64;
    push32(r32[ecx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, 0x00000001);
    memoryASet32(ds, r32[esp] + 0x4c, 0x1003ed60);
    sub_1001d620();
    memoryASet32(ds, r32[esp] + 0x38, r32[eax]);
    { pc = 0x10001ca6; break; }
  case 0x10001ca2: // 0000:10001ca2
    memoryASet32(ds, r32[esp] + 0x38, r32[edi]);
  case 0x10001ca6: // 0000:10001ca6
    push32(0x00000030);
    memoryASet32(ds, r32[esp] + 0x84, r32[ebx]);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000005);
    if (r32[eax] == r32[edi])
        { pc = 0x10001ceb; break; }
    r32[edx] = r32[esp] + 64;
    push32(r32[edx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, 0x00000001);
    memoryASet32(ds, r32[esp] + 0x4c, 0x1003ed68);
    sub_1001d620();
    memoryASet32(ds, r32[esp] + 0x3c, r32[eax]);
    { pc = 0x10001cef; break; }
  case 0x10001ceb: // 0000:10001ceb
    memoryASet32(ds, r32[esp] + 0x3c, r32[edi]);
  case 0x10001cef: // 0000:10001cef
    push32(0x00000030);
    memoryASet32(ds, r32[esp] + 0x84, r32[ebx]);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000006);
    if (r32[eax] == r32[edi])
        { pc = 0x10001d34; break; }
    r32[ecx] = r32[esp] + 64;
    push32(r32[ecx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, 0x00000001);
    memoryASet32(ds, r32[esp] + 0x4c, 0x1003ed78);
    sub_1001d620();
    memoryASet32(ds, r32[esp] + 0x40, r32[eax]);
    { pc = 0x10001d38; break; }
  case 0x10001d34: // 0000:10001d34
    memoryASet32(ds, r32[esp] + 0x40, r32[edi]);
  case 0x10001d38: // 0000:10001d38
    push32(0x00000030);
    memoryASet32(ds, r32[esp] + 0x84, r32[ebx]);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000007);
    if (r32[eax] == r32[edi])
        { pc = 0x10001d7d; break; }
    r32[edx] = r32[esp] + 36;
    push32(r32[edx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x2c, 0x00000001);
    memoryASet32(ds, r32[esp] + 0x30, 0x1003ed84);
    sub_1001d620();
    memoryASet32(ds, r32[esp] + 0x14, r32[eax]);
    { pc = 0x10001d81; break; }
  case 0x10001d7d: // 0000:10001d7d
    memoryASet32(ds, r32[esp] + 0x14, r32[edi]);
  case 0x10001d81: // 0000:10001d81
    push32(0x00000030);
    memoryASet32(ds, r32[esp] + 0x84, r32[ebx]);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000008);
    if (r32[eax] == r32[edi])
        { pc = 0x10001dc6; break; }
    r32[ecx] = r32[esp] + 36;
    push32(r32[ecx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x2c, 0x00000001);
    memoryASet32(ds, r32[esp] + 0x30, 0x1003ed94);
    sub_1001d620();
    memoryASet32(ds, r32[esp] + 0x18, r32[eax]);
    { pc = 0x10001dca; break; }
  case 0x10001dc6: // 0000:10001dc6
    memoryASet32(ds, r32[esp] + 0x18, r32[edi]);
  case 0x10001dca: // 0000:10001dca
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x2c);
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x10);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x14);
    memoryASet16(ds, r32[esi] + 0x1a, r16[ax]);
    r32[eax] = r16s[ax]; //cwde();
    r32[edx] = 0;
    memoryASet16(ds, r32[esi] + 0x16, r16[dx]);
    memoryASet16(ds, r32[esi] + 0x14, r16[dx]);
    memoryASet32(ds, r32[esp] + 0x54, r32[edx]);
    memoryASet32(ds, r32[esp] + 0x58, r32[edx]);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[edx] &= 0x00000007;
    r32[eax] += r32[edx];
    r32[eax] = sar32(r32[eax], 0x03);
    r32[eax] = r16s[ax]; //cwde();
    r32[eax] += r32[eax];
    r32[edi] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[eax] += r32[eax];
    r32[eax] += r32[eax];
    memoryASet32(ds, r32[esp] + 0x5c, r32[eax]);
    r32[eax] = r16s[cx];
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[edx] &= 0x00000007;
    memoryASet16(ds, r32[esi] + 0x18, r16[cx]);
    r32[eax] += r32[edx];
    r32[eax] = sar32(r32[eax], 0x03);
    r32[ecx] = r16s[ax];
    r32[ecx] += r32[ecx];
    r32[ecx] += r32[ecx];
    r32[ecx] += r32[ecx];
    push32(0x000000a0);
    memoryASet32(ds, r32[esi] + 0x8, r32[edi]);
    memoryASet32(ds, r32[esp] + 0x64, r32[ecx]);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000009);
    if (!r32[eax])
        { pc = 0x10001e5f; break; }
    r32[ecx] = r32[esi] + 12;
    push32(r32[ecx]);
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 92;
    sub_1001a0b0();
    r32[edi] = r32[eax];
    memoryASet32(ds, r32[esp] + 0x24, r32[edi]);
    { pc = 0x10001e6b; break; }
  case 0x10001e5f: // 0000:10001e5f
    memoryASet32(ds, r32[esp] + 0x24, 0x00000000);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x24);
  case 0x10001e6b: // 0000:10001e6b
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x2c);
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xb0);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    //console.log("Skip window show?")
    r32[eax] = 0x00000028;
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x6c, 0x00000010);
    memoryASet32(ds, r32[esp] + 0x74, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x68, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x70, 0x00000080);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000000a);
    if (!r32[eax])
        { pc = 0x10001ee9; break; }
    r32[edx] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[edx]);
    memoryASet32(ds, r32[esp] + 0x50, r32[edx]);
    r32[edx] = r32[esp] + 76;
    push32(r32[edx]);
    r32[edx] = r32[esp] + 88;
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x38);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    push32(r32[ecx]);
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 120;
    sub_100177e0(); // splashscreen?
    { pc = 0x10001eeb; break; }
  case 0x10001ee9: // 0000:10001ee9
    r32[eax] = 0;
  case 0x10001eeb: // 0000:10001eeb
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x28, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xdc);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[eax]); // window proc
    push32(0x000000e8);
    memoryASet32(ds, r32[esp] + 0x5c, 0x00000050);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000090);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000040);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000080);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000000b);
    if (!r32[eax])
        { pc = 0x10001f7e; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[esi] += 0x00000024;
    push32(r32[ecx]);
    r32[eax] = 0;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x50);
    r32[ebx] = r32[esp] + 84;
    r32[ecx] = r32[esp] + 92;
    memoryASet32(ds, r32[esp] + 0x54, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x58, r32[eax]);
    sub_100166c0();
    r32[eax] = r32[esi];
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[eax], 0x1003f864);
    memoryASet32(ds, r32[eax] + 0xd0, 0x1003f9dc);
    { pc = 0x10001f80; break; }
  case 0x10001f7e: // 0000:10001f7e
    r32[eax] = 0;
  case 0x10001f80: // 0000:10001f80
    r32[ebx] |= 0xffffffff;
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x2c, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = r32[eax];
    memoryASet32(ds, r32[esp], fstp32());
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xf8);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x2c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[ecx]);            ///// gaboA problem
    memoryASet32(ds, r32[esp] + 0x48, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000000);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x2c);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x2c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x168);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x2c);
    r32[eax] = memoryAGet32(ds, r32[edi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xdc);
    push32(r32[ecx]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000009c);
    memoryASet32(ds, r32[esp] + 0x64, 0x000000b4);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000040);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000080);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000000c);
    if (!r32[eax])
        { pc = 0x1000203a; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x1000203c; break; }
  case 0x1000203a: // 0000:1000203a
    r32[eax] = 0;
  case 0x1000203c: // 0000:1000203c
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x30, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000000);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x30);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x30);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004350);
    indirectCall(cs, r32[edx]);
    push32(0x000000e8);
    memoryASet32(ds, r32[esp] + 0x5c, 0x00000050);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000090);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000088);
    memoryASet32(ds, r32[esp] + 0x60, 0x000000c8);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000000d);
    if (!r32[eax])
        { pc = 0x10002102; break; }
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[eax]);
    r32[esi] += 0x00000024;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x50);
    r32[ebx] = r32[esp] + 84;
    r32[eax] = 0x00000001;
    r32[ecx] = r32[esp] + 92;
    sub_100166c0();
    r32[eax] = r32[esi];
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[eax], 0x1003f864);
    memoryASet32(ds, r32[eax] + 0xd0, 0x1003f9dc);
    r32[ebx] |= 0xffffffff;
    { pc = 0x10002104; break; }
  case 0x10002102: // 0000:10002102
    r32[eax] = 0;
  case 0x10002104: // 0000:10002104
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x34, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = r32[eax];
    memoryASet32(ds, r32[esp], fstp32());
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xf8);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x34);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x48, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000001);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x34);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x34);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x168);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x34);
    r32[eax] = memoryAGet32(ds, r32[edi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xdc);
    push32(r32[ecx]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000009c);
    memoryASet32(ds, r32[esp] + 0x64, 0x000000b4);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000088);
    memoryASet32(ds, r32[esp] + 0x60, 0x000000c8);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000000e);
    if (!r32[eax])
        { pc = 0x100021bb; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x100021bd; break; }
  case 0x100021bb: // 0000:100021bb
    r32[eax] = 0;
  case 0x100021bd: // 0000:100021bd
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x38, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000001);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x38);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x38);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000e8);
    memoryASet32(ds, r32[esp] + 0x5c, 0x00000050);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000090);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000248);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000288);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000000f);
    if (!r32[eax])
        { pc = 0x10002283; break; }
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[eax]);
    r32[esi] += 0x00000024;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x50);
    r32[ebx] = r32[esp] + 84;
    r32[eax] = 0x0000000e;
    r32[ecx] = r32[esp] + 92;
    sub_100166c0();
    r32[eax] = r32[esi];
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[eax], 0x1003f864);
    memoryASet32(ds, r32[eax] + 0xd0, 0x1003f9dc);
    r32[ebx] |= 0xffffffff;
    { pc = 0x10002285; break; }
  case 0x10002283: // 0000:10002283
    r32[eax] = 0;
  case 0x10002285: // 0000:10002285
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esi] + 0x3c, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = r32[eax];
    memoryASet32(ds, r32[esp], fstp32());
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xf8);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x3c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x48, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x0000000e);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x3c);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x3c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x168);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x3c);
    r32[eax] = memoryAGet32(ds, r32[edi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xdc);
    push32(r32[ecx]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000009c);
    memoryASet32(ds, r32[esp] + 0x64, 0x000000b4);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000248);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000288);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000010);
    if (!r32[eax])
        { pc = 0x10002340; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x10002342; break; }
  case 0x10002340: // 0000:10002340
    r32[eax] = 0;
  case 0x10002342: // 0000:10002342
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x40, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x0000000e);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x40);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x40);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x100042b0);
    indirectCall(cs, r32[edx]);
    push32(0x000000e8);
    memoryASet32(ds, r32[esp] + 0x5c, 0x00000050);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000090);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000290);
    memoryASet32(ds, r32[esp] + 0x60, 0x000002d0);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000011);
    if (!r32[eax])
        { pc = 0x10002408; break; }
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[eax]);
    r32[esi] += 0x00000024;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x50);
    r32[ebx] = r32[esp] + 84;
    r32[eax] = 0x0000000f;
    r32[ecx] = r32[esp] + 92;
    sub_100166c0();
    r32[eax] = r32[esi];
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[eax], 0x1003f864);
    memoryASet32(ds, r32[eax] + 0xd0, 0x1003f9dc);
    r32[ebx] |= 0xffffffff;
    { pc = 0x1000240a; break; }
  case 0x10002408: // 0000:10002408
    r32[eax] = 0;
  case 0x1000240a: // 0000:1000240a
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esi] + 0x44, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = r32[eax];
    memoryASet32(ds, r32[esp], fstp32());
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xf8);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x44);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x48, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x0000000f);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x44);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x44);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x168);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x44);
    r32[eax] = memoryAGet32(ds, r32[edi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xdc);
    push32(r32[ecx]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000009c);
    memoryASet32(ds, r32[esp] + 0x64, 0x000000b4);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000290);
    memoryASet32(ds, r32[esp] + 0x60, 0x000002d0);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000012);
    if (!r32[eax])
        { pc = 0x100024c5; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x100024c7; break; }
  case 0x100024c5: // 0000:100024c5
    r32[eax] = 0;
  case 0x100024c7: // 0000:100024c7
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x0000000f);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x48);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004300);
    indirectCall(cs, r32[edx]);
    push32(0x000000e8);
    memoryASet32(ds, r32[esp] + 0x5c, 0x00000050);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000090);
    memoryASet32(ds, r32[esp] + 0x58, 0x000002d8);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000318);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000013);
    if (!r32[eax])
        { pc = 0x1000258d; break; }
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[eax]);
    r32[esi] += 0x00000024;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x50);
    r32[ebx] = r32[esp] + 84;
    r32[eax] = 0x00000010;
    r32[ecx] = r32[esp] + 92;
    sub_100166c0();
    r32[eax] = r32[esi];
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[eax], 0x1003f864);
    memoryASet32(ds, r32[eax] + 0xd0, 0x1003f9dc);
    r32[ebx] |= 0xffffffff;
    { pc = 0x1000258f; break; }
  case 0x1000258d: // 0000:1000258d
    r32[eax] = 0;
  case 0x1000258f: // 0000:1000258f
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fld1();
    memoryASet32(ds, r32[esi] + 0x50, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = r32[eax];
    memoryASet32(ds, r32[esp], fstp32());
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xf8);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x50);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x48, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000010);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x50);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x50);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x168);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x50);
    r32[eax] = memoryAGet32(ds, r32[edi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xdc);
    push32(r32[ecx]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000009c);
    memoryASet32(ds, r32[esp] + 0x64, 0x000000b4);
    memoryASet32(ds, r32[esp] + 0x58, 0x000002d8);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000318);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000014);
    if (!r32[eax])
        { pc = 0x10002646; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x10002648; break; }
  case 0x10002646: // 0000:10002646
    r32[eax] = 0;
  case 0x10002648: // 0000:10002648
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x4c, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000010);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4c);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000040);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000070);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000015);
    if (!r32[eax])
        { pc = 0x1000270c; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x00000002);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x1000270e; break; }
  case 0x1000270c: // 0000:1000270c
    r32[ecx] = 0;
  case 0x1000270e: // 0000:1000270e
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x54, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x54);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x00000002);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x54);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x54);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x54);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000038);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000078);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000016);
    if (!r32[eax])
        { pc = 0x100027c3; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x100027c5; break; }
  case 0x100027c3: // 0000:100027c3
    r32[eax] = 0;
  case 0x100027c5: // 0000:100027c5
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x58, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000002);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x58);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x58);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004240);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000078);
    memoryASet32(ds, r32[esp] + 0x60, 0x000000a8);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000017);
    if (!r32[eax])
        { pc = 0x10002889; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x00000003);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x1000288b; break; }
  case 0x10002889: // 0000:10002889
    r32[ecx] = 0;
  case 0x1000288b: // 0000:1000288b
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x5c, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x5c);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x00000003);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x5c);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x5c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x5c);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000070);
    memoryASet32(ds, r32[esp] + 0x60, 0x000000b0);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000018);
    if (!r32[eax])
        { pc = 0x10002940; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x10002942; break; }
  case 0x10002940: // 0000:10002940
    r32[eax] = 0;
  case 0x10002942: // 0000:10002942
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x60, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000003);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x60);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x60);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004280);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x000000c0);
    memoryASet32(ds, r32[esp] + 0x60, 0x000000f0);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000019);
    if (!r32[eax])
        { pc = 0x10002a06; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x00000004);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x10002a08; break; }
  case 0x10002a06: // 0000:10002a06
    r32[ecx] = 0;
  case 0x10002a08: // 0000:10002a08
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x64, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x00000004);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x000000b8);
    memoryASet32(ds, r32[esp] + 0x60, 0x000000f8);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000001a);
    if (!r32[eax])
        { pc = 0x10002abd; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x10002abf; break; }
  case 0x10002abd: // 0000:10002abd
    r32[eax] = 0;
  case 0x10002abf: // 0000:10002abf
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x68, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000004);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x68);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x68);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x000000f8);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000128);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000001b);
    if (!r32[eax])
        { pc = 0x10002b83; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x00000005);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x10002b85; break; }
  case 0x10002b83: // 0000:10002b83
    r32[ecx] = 0;
  case 0x10002b85: // 0000:10002b85
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x6c, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6c);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x00000005);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6c);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6c);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x000000f0);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000130);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000001c);
    if (!r32[eax])
        { pc = 0x10002c3a; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x10002c3c; break; }
  case 0x10002c3a: // 0000:10002c3a
    r32[eax] = 0;
  case 0x10002c3c: // 0000:10002c3c
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x70, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000005);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x70);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x70);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000130);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000160);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000001d);
    if (!r32[eax])
        { pc = 0x10002d00; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x00000006);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x10002d02; break; }
  case 0x10002d00: // 0000:10002d00
    r32[ecx] = 0;
  case 0x10002d02: // 0000:10002d02
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esi] + 0x74, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x74);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x00000006);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x74);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x74);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x74);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000128);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000168);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000001e);
    if (!r32[eax])
        { pc = 0x10002dbb; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x10002dbd; break; }
  case 0x10002dbb: // 0000:10002dbb
    r32[eax] = 0;
  case 0x10002dbd: // 0000:10002dbd
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x78, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000006);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x78);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x78);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000168);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000198);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000001f);
    if (!r32[eax])
        { pc = 0x10002e81; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x00000007);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x10002e83; break; }
  case 0x10002e81: // 0000:10002e81
    r32[ecx] = 0;
  case 0x10002e83: // 0000:10002e83
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x7c, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x7c);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x00000007);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x7c);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x7c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x7c);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000160);
    memoryASet32(ds, r32[esp] + 0x60, 0x000001a0);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000020);
    if (!r32[eax])
        { pc = 0x10002f38; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x10002f3a; break; }
  case 0x10002f38: // 0000:10002f38
    r32[eax] = 0;
  case 0x10002f3a: // 0000:10002f3a
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x80, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000007);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x80);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x80);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x000001b0);
    memoryASet32(ds, r32[esp] + 0x60, 0x000001e0);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000021);
    if (!r32[eax])
        { pc = 0x10003007; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x00000008);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x10003009; break; }
  case 0x10003007: // 0000:10003007
    r32[ecx] = 0;
  case 0x10003009: // 0000:10003009
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x84, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x84);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x00000008);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x84);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x84);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x84);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x000001a8);
    memoryASet32(ds, r32[esp] + 0x60, 0x000001e8);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000022);
    if (!r32[eax])
        { pc = 0x100030cd; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x100030cf; break; }
  case 0x100030cd: // 0000:100030cd
    r32[eax] = 0;
  case 0x100030cf: // 0000:100030cf
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x88, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000008);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x88);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x88);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x000001e8);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000218);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000023);
    if (!r32[eax])
        { pc = 0x1000319c; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x00000009);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x1000319e; break; }
  case 0x1000319c: // 0000:1000319c
    r32[ecx] = 0;
  case 0x1000319e: // 0000:1000319e
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x8c, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x8c);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x00000009);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x8c);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x8c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x8c);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x000001e0);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000220);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000024);
    if (!r32[eax])
        { pc = 0x10003262; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x10003264; break; }
  case 0x10003262: // 0000:10003262
    r32[eax] = 0;
  case 0x10003264: // 0000:10003264
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x90, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x00000009);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x90);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x90);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000220);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000250);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000025);
    if (!r32[eax])
        { pc = 0x10003331; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x0000000a);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x10003333; break; }
  case 0x10003331: // 0000:10003331
    r32[ecx] = 0;
  case 0x10003333: // 0000:10003333
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x94, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x94);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x0000000a);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x94);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x94);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x94);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000218);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000258);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000026);
    if (!r32[eax])
        { pc = 0x100033f7; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x100033f9; break; }
  case 0x100033f7: // 0000:100033f7
    r32[eax] = 0;
  case 0x100033f9: // 0000:100033f9
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0x98, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x0000000a);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x98);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x98);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000278);
    memoryASet32(ds, r32[esp] + 0x60, 0x000002a8);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000027);
    if (!r32[eax])
        { pc = 0x100034c6; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x0000000b);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x100034c8; break; }
  case 0x100034c6: // 0000:100034c6
    r32[ecx] = 0;
  case 0x100034c8: // 0000:100034c8
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x9c, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x9c);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x0000000b);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x9c);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x9c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x9c);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000270);
    memoryASet32(ds, r32[esp] + 0x60, 0x000002b0);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000028);
    if (!r32[eax])
        { pc = 0x1000358c; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x1000358e; break; }
  case 0x1000358c: // 0000:1000358c
    r32[eax] = 0;
  case 0x1000358e: // 0000:1000358e
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0xa0, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x0000000b);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xa0);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xa0);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x000002b0);
    memoryASet32(ds, r32[esp] + 0x60, 0x000002e0);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000029);
    if (!r32[eax])
        { pc = 0x1000365b; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x0000000c);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x1000365d; break; }
  case 0x1000365b: // 0000:1000365b
    r32[ecx] = 0;
  case 0x1000365d: // 0000:1000365d
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fld1();
    memoryASet32(ds, r32[esi] + 0xa4, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xa4);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x0000000c);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xa4);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xa4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xa4);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x000002a8);
    memoryASet32(ds, r32[esp] + 0x60, 0x000002e8);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000002a);
    if (!r32[eax])
        { pc = 0x10003721; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x10003723; break; }
  case 0x10003721: // 0000:10003721
    r32[eax] = 0;
  case 0x10003723: // 0000:10003723
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0xa8, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x0000000c);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xa8);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xa8);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000c0);
    memoryASet32(ds, r32[esp] + 0x5c, 0x000000c8);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000148);
    memoryASet32(ds, r32[esp] + 0x58, 0x000002e8);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000318);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000002b);
    if (!r32[eax])
        { pc = 0x100037f0; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x4c, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x50, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(0x00000138);
    push32(0x000000c8);
    push32(0x0000000d);
    r32[eax] = r32[esp] + 104;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi] + 36;
    r32[edx] = r32[esp] + 104;
    sub_10016950();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    memoryASet32(ds, r32[ecx], 0x1003f9f4);
    { pc = 0x100037f2; break; }
  case 0x100037f0: // 0000:100037f0
    r32[ecx] = 0;
  case 0x100037f2: // 0000:100037f2
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0xac, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xf8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xac);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x48, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x2c);
    push32(0x0000000d);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xac);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    fld32(memoryAGet32(ds, 0x10041880));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xac);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x158);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xac);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x000000a4);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000015c);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000174);
    memoryASet32(ds, r32[esp] + 0x58, 0x000002e0);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000320);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000002c);
    if (!r32[eax])
        { pc = 0x100038b6; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10010380();
    { pc = 0x100038b8; break; }
  case 0x100038b6: // 0000:100038b6
    r32[eax] = 0;
  case 0x100038b8: // 0000:100038b8
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[esi] + 0xb0, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] += 0x000000d8;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2c);
    push32(0x0000000d);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xb0);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xb0);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x10004380);
    indirectCall(cs, r32[edx]);
    push32(0x000000a8);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000005a);
    memoryASet32(ds, r32[esp] + 0x64, 0x0000006a);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000128);
    memoryASet32(ds, r32[esp] + 0x60, 0x0000013a);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000002d);
    if (!r32[eax])
        { pc = 0x1000394f; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10001730();
    { pc = 0x10003951; break; }
  case 0x1000394f: // 0000:1000394f
    r32[eax] = 0;
  case 0x10003951: // 0000:10003951
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0xb4, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xdc);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[eax]);
    push32(0x000001bc);
    memoryASet32(ds, r32[esp] + 0x5c, 0x0000005a);
    memoryASet32(ds, r32[esp] + 0x64, 0x0000006a);
    memoryASet32(ds, r32[esp] + 0x58, 0x0000013c);
    memoryASet32(ds, r32[esp] + 0x60, 0x000001e8);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000002e);
    if (!r32[eax])
        { pc = 0x100039bb; break; }
    r32[ecx] = r32[esi] + 36;
    push32(r32[ecx]);
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 92;
    sub_10001810();
    { pc = 0x100039bd; break; }
  case 0x100039bb: // 0000:100039bb
    r32[eax] = 0;
  case 0x100039bd: // 0000:100039bd
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0xb8, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xdc);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    push32(0x000000cc);
    memoryASet32(ds, r32[esp] + 0x24, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x5c, 0x00000070);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000080);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000129);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000139);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x0000002f);
    if (!r32[eax])
        { pc = 0x10003a51; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x40);
    r32[eax] = r32[esi] + 36;
    push32(r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x44);
    r32[ecx] = r32[esp] + 92;
    sub_100152b0();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[ecx], 0x1003eb8c);
    memoryASet32(ds, r32[ecx] + 0xc8, r32[eax]);
    r32[ebx] |= 0xffffffff;
    { pc = 0x10003a53; break; }
  case 0x10003a51: // 0000:10003a51
    r32[ecx] = 0;
  case 0x10003a53: // 0000:10003a53
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0xbc, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x19c);
    push32(0x0000001a);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xbc);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xdc);
    push32(r32[eax]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x00000088);
    memoryASet32(ds, r32[esp] + 0x5c, 0x00000070);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000080);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000140);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000150);
    sub_1001fa1d();
    r32[ebx] = r32[eax];
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[ebx]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000030);
    if (!r32[ebx])
        { pc = 0x10003b01; break; }
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x38);
    push32(0x00000068);
    r32[eax] = r32[esi] + 36;
    push32(r32[eax]);
    push32(r32[ebx]);
    r32[ecx] = r32[esp] + 96;
    sub_10012850();
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x24);
    memoryASet32(ds, r32[ebx] + 0x74, 0x1004006c);
    r32[eax] = 0;
    memoryASet32(ds, r32[ebx], 0x10040b2c);
    memoryASet32(ds, r32[ebx] + 0x74, 0x10040c60);
    memoryASet32(ds, r32[ebx] + 0x7c, r32[eax]);
    memoryASet32(ds, r32[ebx] + 0x80, r32[eax]);
    memoryASet32(ds, r32[ebx] + 0x78, 0x00000010);
    { pc = 0x10003b03; break; }
  case 0x10003b01: // 0000:10003b01
    r32[ebx] = 0;
  case 0x10003b03: // 0000:10003b03
    memoryASet32(ds, r32[esp] + 0x80, 0xffffffff);
    memoryASet32(ds, r32[esi] + 0xc0, r32[ebx]);
    r32[eax] = memoryAGet32(ds, r32[edi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xdc);
    push32(r32[ebx]);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[edx]);
    push32(0x00000088);
    memoryASet32(ds, r32[esp] + 0x5c, 0x00000070);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000080);
    memoryASet32(ds, r32[esp] + 0x58, 0x00000150);
    memoryASet32(ds, r32[esp] + 0x60, 0x00000160);
    sub_1001fa1d();
    r32[ebx] = r32[eax];
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[ebx]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000031);
    if (!r32[ebx])
        { pc = 0x10003ba5; break; }
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x34);
    push32(0x00000067);
    r32[eax] = r32[esi] + 36;
    push32(r32[eax]);
    push32(r32[ebx]);
    r32[ecx] = r32[esp] + 96;
    sub_10012850();
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x24);
    memoryASet32(ds, r32[ebx] + 0x74, 0x1004006c);
    r32[eax] = 0;
    memoryASet32(ds, r32[ebx] + 0x7c, r32[eax]);
    memoryASet32(ds, r32[ebx] + 0x80, r32[eax]);
    memoryASet32(ds, r32[ebx], 0x10040b2c);
    memoryASet32(ds, r32[ebx] + 0x74, 0x10040c60);
    memoryASet32(ds, r32[ebx] + 0x78, 0x00000010);
    r32[eax] = r32[ebx];
    { pc = 0x10003ba7; break; }
  case 0x10003ba5: // 0000:10003ba5
    r32[eax] = 0;
  case 0x10003ba7: // 0000:10003ba7
    r32[ebx] |= 0xffffffff;
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0xc4, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xdc);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[eax]);
    push32(0x000000a8);
    memoryASet32(ds, r32[esp] + 0x5c, 0x00000070);
    memoryASet32(ds, r32[esp] + 0x64, 0x00000080);
    memoryASet32(ds, r32[esp] + 0x58, 0x000001a8);
    memoryASet32(ds, r32[esp] + 0x60, 0x000001e8);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x48, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x80, 0x00000032);
    if (!r32[eax])
        { pc = 0x10003c10; break; }
    push32(r32[eax]);
    r32[ecx] = r32[esp] + 88;
    sub_10001730();
    { pc = 0x10003c12; break; }
  case 0x10003c10: // 0000:10003c10
    r32[eax] = 0;
  case 0x10003c12: // 0000:10003c12
    memoryASet32(ds, r32[esp] + 0x80, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0xc8, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xdc);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x2c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x30);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x34);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x38);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x3c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x40);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x10, r32[edi]);
    r8[al] = 0x01;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x78);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp];
    r32[ebp] = pop32();
    r32[esp] += 8;
    return;
  }
}


function sub_1001d620() // 0000:1001d620 +long +stackDrop8
{
const qv = memoryAGet32(0, r32[esp])
const qw = memoryAGet32(0, r32[esp]+4)
const qs = r32[esp];
/*
    const prev = [r32[esp], r32[eax], r32[ebx], r32[esi], r32[edi]];
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x10039ee8); // TODO: GABO override stack, security cookie
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 16;
//    memoryASet32(fs, 0x0, r32[eax]);
*/

// simplified prologue
    r32[esp] -= 4;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[esp] -= 0x10;


const qt = r32[esp];
console.log("SH:", qs-qt);

    r32[eax] = memoryAGet32(ds, r32[esp] + 0x24);
  if (r32[eax] != qw) throw "badX"
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x20);
  if (r32[esi] != qv) throw "badY"

    r32[ecx] = 0x00000001;
    memoryASet32(ds, r32[esi] + 0x4, r32[ecx]);  // 10087c88 <- 1  gaboA, set 1
    r32[ebx] = 0;
    memoryASet32(ds, r32[esp] + 0x18, r32[ebx]);
    memoryASet32(ds, r32[esi], 0x1004118c);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x8, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x4);
    memoryASet32(ds, r32[esi] + 0xc, r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x1004e708);
    r32[edi] = r32[esi] + 8;
    memoryASet32(ds, r32[esi] + 0x10, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x14, r32[ebx]);
    memoryASet(ds, r32[esi] + 0x1c, r8[cl]);
    memoryASet(ds, r32[esi] + 0x18, r8[al]);
    r32[eax] >>>= 8;
    memoryASet(ds, r32[esi] + 0x19, r8[al]);
    r16[ax] = memoryAGet16(ds, 0x1004e70a);
    memoryASet(ds, r32[esi] + 0x1a, r8[al]);
    memoryASet(ds, r32[esi] + 0x1b, r8[ah]);
const check = [r32[esi], r32[esp]]
    sub_1001eab0();
if (check[0] != r32[esi] || check[1] != r32[esp])
  throw "bad A"
    push32(r32[edi]);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x28, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x2c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x24, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x20, r32[ebx]);
    sub_1001d8e0();
    r32[eax] = r32[esi];
/*
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();

    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x0000000c;
    stop("stack_below, 8/4");
    r32[esp] += 12;



if (r32[ebx] != prev[2] || r32[esi] != prev[3] || r32[edi] != prev[4]) throw "bad stack";
r32[esp] -= 8; 
//pop32(); pop32();
if (r32[esp] != prev[0]) throw "bad stack"
r32[esp] += 8;
*/

// simplified epilogue
    r32[esp] += 0x10;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 12;

}

function sub_1001d8e0() // 0000:1001d8e0 +long +stackDrop4
{
    r32[esp] -= 4;
    r32[esp] -= 0x00000010;
    push32(r32[ebx]);
    push32(r32[ebp]);
    r32[ebp] = r32[ecx];
    r32[eax] = memoryAGet32(ss, r32[ebp]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    push32(r32[esi]);
    push32(r32[edi]);

    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[eax] = r32[ebx];
    sub_1001d370();

    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000010;
    r32[esp] += 8; 
  return;

  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x00000010;
    push32(r32[ebx]);
    push32(r32[ebp]);
    r32[ebp] = r32[ecx];
    r32[eax] = memoryAGet32(ss, r32[ebp]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    push32(r32[esi]);
    push32(r32[edi]);
    //indirectCall(cs, r32[edx]); // delete object, gabo check
    push32(0x00000014);
    sub_1001fa1d(); // malloc
    r32[esi] = 0;
    r32[esp] += 0x00000004;
    if (r32[eax] == r32[esi])
        { pc = 0x1001d91b; break; }
    memoryASet32(ds, r32[eax], 0x10041414);
    memoryASet32(ds, r32[eax] + 0x4, r32[esi]);
    memoryASet32(ds, r32[eax] + 0x8, r32[esi]);
    memoryASet32(ds, r32[eax] + 0xc, r32[esi]);
    memoryASet32(ds, r32[eax] + 0x10, 0x00000001);
    r32[edi] = r32[eax];
    { pc = 0x1001d91d; break; }
  case 0x1001d91b: // 0000:1001d91b
    r32[edi] = 0;
  case 0x1001d91d: // 0000:1001d91d
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[eax] = r32[ebx];
    sub_1001d370();
    if (!r8[al])
        { pc = 0x1001d965; break; }
    push32(0x00000010);
    sub_10035374();
    r32[esi] = r32[eax];
    if (!r32[esi])
        { pc = 0x1001d95e; break; }
    r32[eax] = r32[esp] + 36;
    push32(r32[eax]);
    push32(r32[edi]);
    memoryASet32(ds, r32[esi], 0x100411c4);
    memoryASet32(ds, r32[esp] + 0x2c, 0x00000000);
    sub_10035302();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x24); // gaboA
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x4, r32[ecx]);
    { pc = 0x1001d960; break; }
  case 0x1001d95e: // 0000:1001d95e
    r32[esi] = 0;
  case 0x1001d960: // 0000:1001d960
    memoryASet32(ss, r32[ebp] + 0x28, r32[esi]);
    r32[esi] = 0;
  case 0x1001d965: // 0000:1001d965
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x8);
    push32(r32[edi]);
    indirectCall(cs, r32[eax]);  // delete object, gabo check stack
    if (memoryAGet32(ss, r32[ebp] + 0x28) != r32[esi])
        { pc = 0x1001d992; break; }
    if (memoryAGet32(ds, r32[ebx]) != r32[esi])
        { pc = 0x1001d97c; break; }
    r32[eax] = memoryAGet16(ds, r32[ebx] + 0x4);
    { pc = 0x1001d97f; break; }
  case 0x1001d97c: // 0000:1001d97c
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x4);
  case 0x1001d97f: // 0000:1001d97f
    r32[ecx] = memoryAGet32(ds, 0x10050208);
    push32(r32[eax]);
    push32(r32[ecx]);
    sub_100185c0();
    r32[esp] += 0x00000008;
    memoryASet32(ss, r32[ebp] + 0x28, r32[eax]);
  case 0x1001d992: // 0000:1001d992
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x28);
    r32[ebx] = 0;
    if (r32[esi] == r32[ebx])
        { pc = 0x1001db52; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = r32[esp] + 36;
    push32(r32[edx]);
    push32(r32[eax]);
    sub_10035326();
    if (r32[eax] == r32[ebx])
        { pc = 0x1001d9b4; break; }
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
  case 0x1001d9b4: // 0000:1001d9b4
    if (memoryAGet32(ds, r32[esp] + 0x24) == 0x000e200b)
        { pc = 0x1001dafc; break; }
    push32(0x00000010);
    sub_10035374();
    r32[edi] = r32[eax];
    if (r32[edi] == r32[ebx])
        { pc = 0x1001d9fc; break; }
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x28);
    sub_100184b0();
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x28);
    memoryASet32(ds, r32[esp] + 0x24, r32[eax]);
    sub_10018480();
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x28);
    r32[ecx] = 0x000e200b;
    r32[edx] = r32[eax];
    r32[esi] = r32[edi];
    sub_10018550();
    memoryASet32(ds, r32[esp] + 0x24, r32[eax]);
    { pc = 0x1001da00; break; }
  case 0x1001d9fc: // 0000:1001d9fc
    memoryASet32(ds, r32[esp] + 0x24, r32[ebx]);
  case 0x1001da00: // 0000:1001da00
    push32(0x00000008);
    sub_10035374();
    r32[esi] = r32[eax];
    if (r32[esi] == r32[ebx])
        { pc = 0x1001da18; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x24);
    sub_10018100();
    r32[ebx] = r32[eax];
  case 0x1001da18: // 0000:1001da18
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x28);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[ecx] = r32[esp] + 16;
    push32(r32[ecx]);
    r32[edi] = 0;
    push32(r32[edx]);
    memoryASet32(ds, r32[esp] + 0x18, r32[edi]);
    sub_1003530e();
    if (r32[eax] == r32[edi])
        { pc = 0x1001da36; break; }
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
  case 0x1001da36: // 0000:1001da36
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x28);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[ecx] = r32[esp] + 24;
    push32(r32[ecx]);
    push32(r32[edx]);
    memoryASet32(ds, r32[esp] + 0x24, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x20, r32[edi]);
    sub_100353e6();
    if (r32[eax] == r32[edi])
        { pc = 0x1001da5a; break; }
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
  case 0x1001da5a: // 0000:1001da5a
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x28);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[eax] = r32[esp] + 16;
    push32(r32[eax]);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x18, r32[edi]);
    sub_1003530e();
    if (r32[eax] == r32[edi])
        { pc = 0x1001da76; break; }
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
  case 0x1001da76: // 0000:1001da76
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x28);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = r32[esp] + 20;
    push32(r32[edx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x1c, 0x00000000);
    sub_100353e6();
    if (!r32[eax])
        { pc = 0x1001da9a; break; }
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
  case 0x1001da9a: // 0000:1001da9a
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x28);
    if (!r32[eax])
        { pc = 0x1001daa6; break; }
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x4);
    { pc = 0x1001daa8; break; }
  case 0x1001daa6: // 0000:1001daa6
    r32[eax] = 0;
  case 0x1001daa8: // 0000:1001daa8
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000002);
    push32(r32[edi]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x30);
    push32(0x00000000);
    push32(0x00000000);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[ebx]);
    push32(r32[ecx]);
    push32(0x00000000);
    push32(0x00000000);
    push32(r32[eax]);
    push32(r32[edx]);
    sub_10035314();
    if (!r32[eax])
        { pc = 0x1001dad8; break; }
    memoryASet32(ds, r32[ebx] + 0x4, r32[eax]);
  case 0x1001dad8: // 0000:1001dad8
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    push32(r32[eax]);
    sub_1003533e();
    push32(r32[ebx]);
    sub_100352f0();
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x28);
    if (!r32[ecx])
        { pc = 0x1001daf5; break; }
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    push32(0x00000001);
    indirectCall(cs, r32[eax]);
  case 0x1001daf5: // 0000:1001daf5
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x24);
    memoryASet32(ss, r32[ebp] + 0x28, r32[ecx]);
  case 0x1001dafc: // 0000:1001dafc
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x28);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = r32[esp] + 36;
    push32(r32[edx]);
    r32[edi] = 0;
    push32(r32[eax]);
    r8[bl] = 0x01;
    memoryASet32(ds, r32[esp] + 0x2c, r32[edi]);
    sub_100353e6();
    if (r32[eax] == r32[edi])
        { pc = 0x1001db1c; break; }
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
  case 0x1001db1c: // 0000:1001db1c
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x28);
    r32[edx] = r32[esp] + 36;
    memoryASet32(ss, r32[ebp] + 0x10, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x4);
    push32(r32[edx]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x2c, r32[edi]);
    sub_1003530e();
    if (r32[eax] == r32[edi])
        { pc = 0x1001db3f; break; }
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
  case 0x1001db3f: // 0000:1001db3f
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x24);
    memoryASet32(ss, r32[ebp] + 0x14, r32[ecx]);
    r8[al] = r8[bl];
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000010;
    stop("stack_unbalanced");
    r32[esp] += 8; return;
  case 0x1001db52: // 0000:1001db52
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r8[al] = 0;
    r32[ebx] = pop32();
    r32[esp] += 0x00000010;
    r32[esp] += 8;
    return;
  }
}


function sub_10001240() // 0000:10001240 +long +stackDrop4
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, r32[esp] + 0x4));
    memoryASet32(ds, r32[ecx] + 0x54, fstp32());
    r32[esp] += 8;
}

function sub_10001250() // 0000:10001250 +long
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, r32[ecx] + 0x54));
    r32[esp] += 4;
}

function sub_10001260() // 0000:10001260 +long +stackDrop4
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, r32[esp] + 0x4));
    memoryASet32(ds, r32[ecx] + 0x58, fstp32());
    r32[esp] += 8;
}

function sub_10001270() // 0000:10001270 +long
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, r32[ecx] + 0x58));
    r32[esp] += 4;
}

function sub_10001280() // 0000:10001280 +long +stackDrop4
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, r32[esp] + 0x4));
    memoryASet32(ds, r32[ecx] + 0x5c, fstp32());
    r32[esp] += 8;
}

function sub_10001290() // 0000:10001290 +long
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, r32[ecx] + 0x5c));
    r32[esp] += 4;
}

function sub_1000ff90() // 0000:1000ff90 +long +stackDrop4
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, r32[esp] + 0x4));
    memoryASet32(ds, r32[ecx] + 0xa4, fstp32());
    r32[esp] += 8;
}

function sub_10010380() // 0000:10010380 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1003a098);
    //r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    r32[esp] -= 0x0000000c;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 28;
    //memoryASet32(fs, 0x0, r32[eax]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x2c);
    push32(0x00000001);
    push32(r32[esi]);
    r32[edi] = 0;
    sub_10013900();
    r32[ebx] = 0;
    memoryASet32(ds, r32[esp] + 0x24, r32[ebx]);
    r8[al] = 0xff;
    r8[cl] = 0x40;
    memoryASet(ds, r32[esp] + 0x14, r8[cl]);
    memoryASet(ds, r32[esp] + 0x15, r8[cl]);
    memoryASet(ds, r32[esp] + 0x16, r8[cl]);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi], 0x1003fb5c);
    memoryASet(ds, r32[esp] + 0x14, r8[bl]);
    memoryASet(ds, r32[esp] + 0x15, r8[bl]);
    memoryASet(ds, r32[esp] + 0x16, r8[bl]);
    memoryASet(ds, r32[esp] + 0x17, r8[al]);
    memoryASet(ds, r32[esp] + 0x1b, r8[al]);
    memoryASet(ds, r32[esp] + 0x1c, r8[al]);
    memoryASet(ds, r32[esp] + 0x1d, r8[al]);
    memoryASet(ds, r32[esp] + 0x1e, r8[al]);
    memoryASet(ds, r32[esp] + 0x1f, r8[al]);
    indirectCall(cs, memoryAGet32(ds, 0x1003fb7c));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x8c);
    if (r32[ecx] == r32[ebx])
        { pc = 0x1001040f; break; }
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    indirectCall(cs, r32[edx]);
  case 0x1001040f: // 0000:1001040f
    r32[ecx] = 0x1004e690;
    memoryASet32(ds, r32[esi] + 0x8c, r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x1004e690);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x8);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[eax]);
    r32[ecx] = r32[esi];
    sub_100142c0();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
    push32(r32[ecx]);
    r32[ecx] = r32[esi];
    sub_10014250();
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[edx]);
    r32[ecx] = r32[esi];
    sub_100141e0();
    r32[eax] = r32[esi];
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x1c);
    //memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000018;
    stop("stack_unbalanced");
    r32[esp] += 8;
    return;
  }
}

function sub_10013900() // 0000:10013900 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x10039fa8);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[esi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 16;
//    memoryASet32(fs, 0x0, r32[eax]);
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[ebx] = 0;
    push32(r32[ebx]);
    push32(r32[ebx]);
    push32(r32[esi]);
    sub_10012850();
    memoryASet32(ds, r32[esp] + 0x18, r32[ebx]);
    r32[eax] = 0x00000001;
    memoryASet32(ds, r32[esi], 0x10040084);
    memoryASet32(ds, r32[esi] + 0x74, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x78, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x7c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x84, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x88, r32[ebp]);
    memoryASet(ds, r32[esi] + 0xa0, r8[al]);
    memoryASet(ds, r32[esi] + 0xa1, r8[al]);
    memoryASet32(ds, r32[esi] + 0x6c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x70, r32[ebx]);
    r32[ecx] = 0x1004e690;
    memoryASet32(ds, r32[esi] + 0x8c, r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x1004e690);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x8);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet(ds, 0x1004e710);
    memoryASet(ds, r32[esi] + 0x90, r8[al]);
    r32[ecx] = memoryAGet(ds, 0x1004e711);
    memoryASet(ds, r32[esi] + 0x91, r8[cl]);
    r32[edx] = memoryAGet(ds, 0x1004e712);
    memoryASet(ds, r32[esi] + 0x92, r8[dl]);
    r32[eax] = memoryAGet(ds, 0x1004e713);
    memoryASet(ds, r32[esi] + 0x93, r8[al]);
    r32[ecx] = memoryAGet(ds, 0x1004e70c);
    memoryASet(ds, r32[esi] + 0x94, r8[cl]);
    r32[edx] = memoryAGet(ds, 0x1004e70d);
    memoryASet(ds, r32[esi] + 0x95, r8[dl]);
    r32[eax] = memoryAGet(ds, 0x1004e70e);
    memoryASet(ds, r32[esi] + 0x96, r8[al]);
    r32[ecx] = memoryAGet(ds, 0x1004e70f);
    memoryASet(ds, r32[esi] + 0x97, r8[cl]);
    r32[edx] = memoryAGet(ds, 0x1004e70c);
    memoryASet(ds, r32[esi] + 0x98, r8[dl]);
    r32[eax] = memoryAGet(ds, 0x1004e70d);
    memoryASet(ds, r32[esi] + 0x99, r8[al]);
    r32[ecx] = memoryAGet(ds, 0x1004e70e);
    memoryASet(ds, r32[esi] + 0x9a, r8[cl]);
    r32[edx] = memoryAGet(ds, 0x1004e70f);
    memoryASet(ds, r32[esi] + 0x9b, r8[dl]);
    r32[eax] = memoryAGet(ds, 0x1004e718);
    memoryASet(ds, r32[esi] + 0x9c, r8[al]);
    r32[ecx] = memoryAGet(ds, 0x1004e719);
    memoryASet(ds, r32[esi] + 0x9d, r8[cl]);
    r32[edx] = memoryAGet(ds, 0x1004e71a);
    memoryASet(ds, r32[esi] + 0x9e, r8[dl]);
    r32[eax] = memoryAGet(ds, 0x1004e71b);
    memoryASet(ds, r32[esi] + 0x9f, r8[al]);
    memoryASet32(ds, r32[esi] + 0x80, r32[ebx]);
    r32[eax] = r32[esi];
    if (!(r32[ebp] & 0x00001000))
        { pc = 0x10013a69; break; }
    fld32(memoryAGet32(ds, r32[esi] + 0x54));
    memoryASet(ds, r32[esi] + 0x30, r8[bl]);
    memoryASet32(ds, r32[esi] + 0x4c, fstp32());
  case 0x10013a69: // 0000:10013a69
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x0000000c;
    stop("stack_unbalanced");
    r32[esp] += 12;
    return;
  }
}

function sub_10012850() // 0000:10012850 +long +stackDrop12
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1003a228);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 12;
//    memoryASet32(fs, 0x0, r32[eax]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = r32[esi];
    sub_10019a40();
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[ebx] = 0;
    memoryASet32(ds, r32[esp] + 0x14, r32[ebx]);
    fld1();
    memoryASet32(ds, r32[esi] + 0x4c, fst32());
    memoryASet32(ds, r32[esi], 0x1003ff24);
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esi] + 0x44, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x50, fstp32());
    memoryASet32(ds, r32[esi] + 0x48, r32[ecx]);
    fldz();
    memoryASet32(ds, r32[esi] + 0x64, 0xffffffff);
    memoryASet32(ds, r32[esi] + 0x54, fst32());
    memoryASet32(ds, r32[esi] + 0x58, fstp32());
    memoryASet32(ds, r32[esi] + 0x5c, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esi] + 0x60, fstp32());
    memoryASet32(ds, r32[esi] + 0x6c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x70, r32[ebx]);
    r32[eax] = user32__GetDoubleClickTime(); // TODO CICO!!
    memoryASet32(ds, r32[esi] + 0x68, r32[eax]);
    if (r32s[eax] >= signed32(0x000000fa))
        { pc = 0x100128dd; break; }
    memoryASet32(ds, r32[esi] + 0x68, 0x000000fa);
  case 0x100128dd: // 0000:100128dd
    memoryASet(ds, r32[esi] + 0x32, r8[bl]);
    memoryASet(ds, r32[esi] + 0x31, 0x01);
    memoryASet32(ds, r32[esi] + 0x6c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x70, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x3c);
    if (r32[ecx] == r32[ebx])
        { pc = 0x100128f8; break; }
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
  case 0x100128f8: // 0000:100128f8
    memoryASet32(ds, r32[esi] + 0x3c, r32[edi]);
    if (r32[edi] == r32[ebx])
        { pc = 0x10012908; break; }
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x8);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[eax]);
  case 0x10012908: // 0000:10012908
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x20);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[eax] = r32[esi];
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x0000000c;
    stop("stack_below, 12/8");
    r32[esp] += 16;
    return;
  }
}

function sub_10019a40() // 0000:10019a40 +long
{
    r32[esp] -= 4;
    memoryASet32(ds, r32[eax], 0x100411fc);
    push32(r32[esi]);
    r32[edx] = 0x00000001;
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esi] = memoryAGet32(ds, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x8, r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x4);
    memoryASet32(ds, r32[eax] + 0xc, r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x8);
    memoryASet32(ds, r32[eax] + 0x10, r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0xc);
    memoryASet32(ds, r32[eax] + 0x14, r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x18, r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x4);
    memoryASet32(ds, r32[eax] + 0x1c, r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x8);
    memoryASet32(ds, r32[eax] + 0x20, r32[esi]);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0xc);
    memoryASet32(ds, r32[eax] + 0x24, r32[ecx]);
    r32[ecx] = 0;
    memoryASet32(ds, r32[eax] + 0x28, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x2c, r32[ecx]);
    memoryASet(ds, r32[eax] + 0x30, r8[cl]);
    memoryASet(ds, r32[eax] + 0x31, r8[dl]);
    memoryASet(ds, r32[eax] + 0x32, r8[cl]);
    memoryASet(ds, r32[eax] + 0x33, r8[cl]);
    memoryASet(ds, r32[eax] + 0x34, r8[cl]);
    memoryASet(ds, r32[eax] + 0x35, r8[dl]);
    memoryASet32(ds, r32[eax] + 0x38, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x3c, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x40, r32[ecx]);
    r32[esi] = pop32();
    r32[esp] += 4;
}

function sub_10012a00() // 0000:10012a00 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r8[al] = memoryAGet(ds, r32[esp] + 0x4);
    memoryASet(ds, r32[ecx] + 0x30, r8[al]);
    if (!r8[al])
        { pc = 0x10012a25; break; }
    fld32(memoryAGet32(ds, 0x100414d8));
    fcom32(memoryAGet32(ds, r32[ecx] + 0x54));
    r16[ax] = fnstsw();
    if (flags.parity)
        { pc = 0x10012a28; break; }
    fstpst(0);
    fldz();
    memoryASet32(ds, r32[ecx] + 0x4c, fstp32());
    r32[esp] += 8; return;
  case 0x10012a25: // 0000:10012a25
    fld32(memoryAGet32(ds, r32[ecx] + 0x54));
  case 0x10012a28: // 0000:10012a28
    memoryASet32(ds, r32[ecx] + 0x4c, fstp32());
    r32[esp] += 8;
    return;
  }
}

function sub_10001000() // 0000:10001000 +long
{
    r32[esp] -= 4;
    memoryASet32(ds, r32[ecx] + 0x4, memoryAGet32(ds, r32[ecx] + 0x4) + 1);
    r32[esp] += 4;
 console.log("begin text?")
}

function sub_10019820() // 0000:10019820 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    memoryASet32(ds, r32[ecx] + 0x4, memoryAGet32(ds, r32[ecx] + 0x4) + 0xffffffff);
    if (memoryAGet32(ds, r32[ecx] + 0x4))
        { pc = 0x1001982e; break; }
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(0x00000001);
    indirectCall(cs, r32[edx]);
  case 0x1001982e: // 0000:1001982e
    r32[esp] += 4; return;
    return;
  }
}

function sub_100142c0() // 0000:100142c0 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    if (memoryAGet(ds, r32[esi] + 0x98) != r8[al])
        { pc = 0x100142f6; break; }
    r32[ecx] = r32[eax];
    r32[ecx] >>>= 8;
    if (memoryAGet(ds, r32[esi] + 0x99) != r8[cl])
        { pc = 0x100142f6; break; }
    r32[edx] = r32[eax];
    r32[edx] >>>= 16;
    if (memoryAGet(ds, r32[esi] + 0x9a) != r8[dl])
        { pc = 0x100142f6; break; }
    r32[ecx] = r32[eax];
    r32[ecx] >>>= 24;
    if (memoryAGet(ds, r32[esi] + 0x9b) == r8[cl])
        { pc = 0x10014305; break; }
  case 0x100142f6: // 0000:100142f6
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x20);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
  case 0x10014305: // 0000:10014305
    r8[cl] = memoryAGet(ds, r32[esp] + 0xa);
    r8[dl] = memoryAGet(ds, r32[esp] + 0xb);
    memoryASet(ds, r32[esi] + 0x98, r8[al]);
    memoryASet(ds, r32[esi] + 0x99, r8[ah]);
    memoryASet(ds, r32[esi] + 0x9a, r8[cl]);
    memoryASet(ds, r32[esi] + 0x9b, r8[dl]);
    r32[esi] = pop32();
    r32[esp] += 8;
    return;
  }
}

function sub_10014250() // 0000:10014250 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    if (memoryAGet(ds, r32[esi] + 0x94) != r8[al])
        { pc = 0x10014286; break; }
    r32[ecx] = r32[eax];
    r32[ecx] >>>= 8;
    if (memoryAGet(ds, r32[esi] + 0x95) != r8[cl])
        { pc = 0x10014286; break; }
    r32[edx] = r32[eax];
    r32[edx] >>>= 16;
    if (memoryAGet(ds, r32[esi] + 0x96) != r8[dl])
        { pc = 0x10014286; break; }
    r32[ecx] = r32[eax];
    r32[ecx] >>>= 24;
    if (memoryAGet(ds, r32[esi] + 0x97) == r8[cl])
        { pc = 0x10014295; break; }
  case 0x10014286: // 0000:10014286
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x20);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
  case 0x10014295: // 0000:10014295
    r8[cl] = memoryAGet(ds, r32[esp] + 0xa);
    r8[dl] = memoryAGet(ds, r32[esp] + 0xb);
    memoryASet(ds, r32[esi] + 0x94, r8[al]);
    memoryASet(ds, r32[esi] + 0x95, r8[ah]);
    memoryASet(ds, r32[esi] + 0x96, r8[cl]);
    memoryASet(ds, r32[esi] + 0x97, r8[dl]);
    r32[esi] = pop32();
    r32[esp] += 8;
    return;
  }
}

function sub_100141e0() // 0000:100141e0 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    if (memoryAGet(ds, r32[esi] + 0x90) != r8[al])
        { pc = 0x10014216; break; }
    r32[ecx] = r32[eax];
    r32[ecx] >>>= 8;
    if (memoryAGet(ds, r32[esi] + 0x91) != r8[cl])
        { pc = 0x10014216; break; }
    r32[edx] = r32[eax];
    r32[edx] >>>= 16;
    if (memoryAGet(ds, r32[esi] + 0x92) != r8[dl])
        { pc = 0x10014216; break; }
    r32[ecx] = r32[eax];
    r32[ecx] >>>= 24;
    if (memoryAGet(ds, r32[esi] + 0x93) == r8[cl])
        { pc = 0x10014225; break; }
  case 0x10014216: // 0000:10014216
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x20);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
  case 0x10014225: // 0000:10014225
    r8[cl] = memoryAGet(ds, r32[esp] + 0xa);
    r8[dl] = memoryAGet(ds, r32[esp] + 0xb);
    memoryASet(ds, r32[esi] + 0x90, r8[al]);
    memoryASet(ds, r32[esi] + 0x91, r8[ah]);
    memoryASet(ds, r32[esi] + 0x92, r8[cl]);
    memoryASet(ds, r32[esi] + 0x93, r8[dl]);
    r32[esi] = pop32();
    r32[esp] += 8;
    return;
  }
}

function sub_100143d0() // 0000:100143d0 +long +stackDrop4
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(ds, r32[ecx] + 0x74, r32[eax]);
    r32[esp] += 8;
}


function sub_10016950() // 0000:10016950 +long +stackDrop28
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x10039fd8);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    r32[esp] -= 0x00000010;
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 36;
//    memoryASet32(fs, 0x0, r32[eax]);
    r32[ebx] = r32[edx];
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x48);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x34);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x3c);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x4c);
    push32(r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x40);
    push32(r32[esi]);
    sub_10012850();
    r32[edi] = 0;
    memoryASet32(ds, r32[esp] + 0x2c, r32[edi]);
    memoryASet32(ds, r32[esi], 0x100409c4);
    r32[edx] = memoryAGet32(ds, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x74, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x4);
    memoryASet32(ds, r32[esi] + 0x78, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x7c, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x80, r32[edi]);
    r32[ebx] = 0x00000001;
    memoryASet32(ds, r32[esi] + 0x84, r32[ebp]);
    memoryASet32(ds, r32[esi] + 0x88, 0x00000042);
    memoryASet(ds, r32[esi] + 0xb1, r8[bl]);
    memoryASet(ds, r32[esi] + 0xb0, r8[bl]);
    if (r32[ebp] == r32[edi])
        { pc = 0x100169fe; break; }
    r32[edx] = memoryAGet32(ss, r32[ebp]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x8);
    r32[ecx] = r32[ebp];
    indirectCall(cs, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x84);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x10);
    memoryASet32(ds, r32[esi] + 0x8c, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x14);
    memoryASet32(ds, r32[esi] + 0x90, r32[edx]);
    { pc = 0x10016a0a; break; }
  case 0x100169fe: // 0000:100169fe
    memoryASet32(ds, r32[esi] + 0x8c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x90, r32[ebx]);
  case 0x10016a0a: // 0000:10016a0a
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x10);
    r32[eax] -= memoryAGet32(ds, r32[esi] + 0x8);
    memoryASet32(ds, r32[esp] + 0x18, r32[edi]);
    memoryASet32(ds, r32[esi] + 0xa4, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x14);
    r32[ecx] -= memoryAGet32(ds, r32[esi] + 0xc);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x44);
    memoryASet32(ds, r32[esi] + 0xa8, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x40);
    r32[eax] -= r32[ecx];
    r32[edx] = r32[ecx];
    r32[edx] -= memoryAGet32(ds, r32[esi] + 0xc);
    memoryASet32(ds, r32[esi] + 0x94, r32[eax]);
    r32[eax] = r32[esp] + 24;
    push32(r32[eax]);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0xa0, r32[edx]);
    memoryASet32(ds, r32[esp] + 0x20, r32[edi]);
    sub_10016d00();
    fld32(memoryAGet32(ds, 0x10041654));
    memoryASet32(ds, r32[esi] + 0xac, fstp32());
    memoryASet(ds, r32[esi] + 0x33, r8[bl]);
    r32[eax] = r32[esi];
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x24);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x0000001c;
    stop("stack_below, 28/24");
    r32[esp] += 32;
    return;
  }
}

function sub_10016d00() // 0000:10016d00 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, r32[ecx] + 0x7c, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x4);
    memoryASet32(ds, r32[ecx] + 0x80, r32[eax]);
    if (!(memoryAGet(ds, r32[ecx] + 0x88) & 0x01))
        { pc = 0x10016d43; break; }
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0xa0);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x7c);
    r32[eax] += r32[edx];
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x94);
    r32[edx] += memoryAGet32(ds, r32[ecx] + 0x8c);
    memoryASet32(ds, r32[ecx] + 0x98, r32[eax]);
    r32[edx] += r32[eax];
    memoryASet32(ds, r32[ecx] + 0x9c, r32[edx]);
    r32[esp] += 8; return;
  case 0x10016d43: // 0000:10016d43
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x80);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0xa0);
    r32[eax] += r32[edx];
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x94);
    r32[edx] += memoryAGet32(ds, r32[ecx] + 0x90);
    memoryASet32(ds, r32[ecx] + 0x98, r32[eax]);
    r32[edx] += r32[eax];
    memoryASet32(ds, r32[ecx] + 0x9c, r32[edx]);
    r32[esp] += 8;
    return;
  }
}

function sub_10010170() // 0000:10010170 +long +stackDrop4
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, r32[esp] + 0x4));
    memoryASet32(ds, r32[ecx] + 0xac, fstp32());
    r32[esp] += 8;
}

function sub_10001730() // 0000:10001730 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1003a858);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    r32[esp] -= 0x00000008;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 24;
//    memoryASet32(fs, 0x0, r32[eax]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x28);
    push32(r32[esi]);
    sub_10014410();
    r32[ebx] = 0;
    memoryASet32(ds, r32[esp] + 0x20, r32[ebx]);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi], 0x1003e89c);
    memoryASet(ds, r32[esp] + 0x18, r8[bl]);
    memoryASet(ds, r32[esp] + 0x19, r8[bl]);
    memoryASet(ds, r32[esp] + 0x1a, r8[bl]);
    memoryASet(ds, r32[esp] + 0x1b, r8[bl]);
    memoryASet(ds, r32[esp] + 0x14, 0x50);
    memoryASet(ds, r32[esp] + 0x15, 0xcd);
    memoryASet(ds, r32[esp] + 0x16, 0xbd);
    memoryASet(ds, r32[esp] + 0x17, 0xff);
    indirectCall(cs, memoryAGet32(ds, 0x1003e8bc));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x8c);
    if (r32[ecx] == r32[ebx])
        { pc = 0x100017ab; break; }
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    indirectCall(cs, r32[edx]);
  case 0x100017ab: // 0000:100017ab
    r32[ecx] = 0x1004e690;
    memoryASet32(ds, r32[esi] + 0x8c, r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x1004e690);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x8);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[eax]);
    r32[ecx] = r32[esi];
    sub_100141e0();
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x14);
    push32(r32[edi]);
    r32[ecx] = r32[esi];
    sub_10014250();
    push32(r32[edi]);
    r32[ecx] = r32[esi];
    sub_100142c0();
    if (memoryAGet32(ds, r32[esi] + 0x84) == r32[ebx])
        { pc = 0x100017f3; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x20);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
  case 0x100017f3: // 0000:100017f3
    r32[eax] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x84, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000014;
    stop("stack_unbalanced");
    r32[esp] += 8;
    return;
  }
}

function sub_10014410() // 0000:10014410 +long +stackDrop4
{
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1003a3e8);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 12;
//    memoryASet32(fs, 0x0, r32[eax]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(0x00000000);
    push32(r32[esi]);
    r32[edi] = 0;
    sub_10013900();
    memoryASet32(ds, r32[esp] + 0x14, r32[edi]);
    push32(r32[edi]);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi], 0x100401ec);
    memoryASet32(ds, r32[esi] + 0xa4, r32[edi]);
    sub_10014560();
    r32[eax] = r32[esi];
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 0x0000000c;
    r32[esp] += 8;
}

function sub_10014560() // 0000:10014560 +long +stackDrop4
{
  var pc = 0;
  var temp_cf;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[ebx] = r32[ecx];
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[ebx] + 0xa4);
    if (r32[edi])
        { pc = 0x1001457f; break; }
    if (!r32[esi])
        { pc = 0x10014605; break; }
    if (!r32[edi])
        { pc = 0x100145bd; break; }
  case 0x1001457f: // 0000:1001457f
    if (!r32[esi])
        { pc = 0x100145b0; break; }
    r32[ecx] = r32[esi];
    r32[eax] = r32[edi];
  case 0x10014587: // 0000:10014587
    r8[dl] = memoryAGet(ds, r32[eax]);
    flags.carry = r8[dl] < memoryAGet(ds, r32[ecx]);
    if (r8[dl] != memoryAGet(ds, r32[ecx]))
        { pc = 0x100145a7; break; }
    if (!r8[dl])
        { pc = 0x100145a3; break; }
    r8[dl] = memoryAGet(ds, r32[eax] + 0x1);
    flags.carry = r8[dl] < memoryAGet(ds, r32[ecx] + 0x1);
    if (r8[dl] != memoryAGet(ds, r32[ecx] + 0x1))
        { pc = 0x100145a7; break; }
    r32[eax] += 0x00000002;
    r32[ecx] += 0x00000002;
    if (r8[dl])
        { pc = 0x10014587; break; }
  case 0x100145a3: // 0000:100145a3
    r32[eax] = 0;
    { pc = 0x100145ac; break; }
  case 0x100145a7: // 0000:100145a7
    temp_cf = flags.carry;
    temp_cf = r32[eax] < r32[eax] + flags.carry;
    r32[eax] = -flags.carry;
    flags.carry = temp_cf;
    r32[eax] -= (0xffffffff + flags.carry);
  case 0x100145ac: // 0000:100145ac
    if (!r32[eax])
        { pc = 0x10014605; break; }
  case 0x100145b0: // 0000:100145b0
    if (!r32[edi])
        { pc = 0x100145bd; break; }
    push32(r32[edi]);
    sub_1001fef1();
    r32[esp] += 0x00000004;
  case 0x100145bd: // 0000:100145bd
    memoryASet32(ds, r32[ebx] + 0xa4, 0x00000000);
    if (!r32[esi])
        { pc = 0x100145fa; break; }
    r32[eax] = r32[esi];
    r32[edx] = r32[eax] + 1;
  case 0x100145d0: // 0000:100145d0
    r8[cl] = memoryAGet(ds, r32[eax]);
    r32[eax]++;
    if (r8[cl])
        { pc = 0x100145d0; break; }
    r32[eax] -= r32[edx];
    r32[eax]++;
    push32(r32[eax]);
    sub_10021194();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[ebx] + 0xa4, r32[eax]);
    r32[ecx] = r32[esi];
    r32[edx] = r32[eax];
    r32[ecx] = r32[ecx];
  case 0x100145f0: // 0000:100145f0
    r8[al] = memoryAGet(ds, r32[ecx]);
    memoryASet(ds, r32[edx], r8[al]);
    r32[ecx]++;
    r32[edx]++;
    if (r8[al])
        { pc = 0x100145f0; break; }
  case 0x100145fa: // 0000:100145fa
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x20);
    push32(0x00000001);
    r32[ecx] = r32[ebx];
    indirectCall(cs, r32[edx]);
  case 0x10014605: // 0000:10014605
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 8;
    return;
  }
}

function sub_10001810() // 0000:10001810 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1003a828);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    push32(r32[ecx]);
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 20;
//    memoryASet32(fs, 0x0, r32[eax]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[ebx] = 0;
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[edi] = 0;
    sub_10013900();
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x28);
    memoryASet32(ds, r32[esi] + 0xa4, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0xa8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0xb0, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x1b4, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x1b8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x44, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x48, 0x00000066);
    memoryASet(ds, r32[esi] + 0xb4, r8[bl]);
    memoryASet(ds, r32[esi] + 0x33, 0x01);
    memoryASet32(ds, r32[esp] + 0x1c, r32[ebx]);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi], 0x1003ea0c);
    memoryASet(ds, r32[esp] + 0x14, r8[bl]);
    memoryASet(ds, r32[esp] + 0x15, r8[bl]);
    memoryASet(ds, r32[esp] + 0x16, r8[bl]);
    memoryASet(ds, r32[esp] + 0x17, r8[bl]);
    memoryASet(ds, r32[esp] + 0x2c, 0x50);
    memoryASet(ds, r32[esp] + 0x2d, 0xcd);
    memoryASet(ds, r32[esp] + 0x2e, 0xbd);
    memoryASet(ds, r32[esp] + 0x2f, 0xff);
    indirectCall(cs, memoryAGet32(ds, 0x1003ea2c));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x8c);
    if (r32[ecx] == r32[ebx])
        { pc = 0x100018c2; break; }
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    indirectCall(cs, r32[eax]);
  case 0x100018c2: // 0000:100018c2
    r32[ecx] = 0x1004e690;
    memoryASet32(ds, r32[esi] + 0x8c, r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x1004e690);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x8);
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x28);
    push32(r32[ecx]);
    r32[ecx] = r32[esi];
    sub_100141e0();
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[edi]);
    r32[ecx] = r32[esi];
    sub_10014250();
    push32(r32[edi]);
    r32[ecx] = r32[esi];
    sub_100142c0();
    if (memoryAGet32(ds, r32[esi] + 0x84) == r32[ebx])
        { pc = 0x1000190b; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x20);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
  case 0x1000190b: // 0000:1000190b
    r32[eax] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x84, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000010;
    stop("stack_below, 8/4");
    r32[esp] += 12;
    return;
  }
}

function sub_100152b0() // 0000:100152b0 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1003a393);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    push32(r32[ebp]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 16;
//    memoryASet32(fs, 0x0, r32[eax]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[ebp] = 0;
    push32(r32[ebp]);
    push32(r32[esi]);
    r32[edi] = r32[edx];
    sub_10013900();
    memoryASet32(ds, r32[esp] + 0x18, r32[ebp]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[eax] |= 0xffffffff;
    memoryASet32(ds, r32[esi], 0x100404dc);
    memoryASet32(ds, r32[esi] + 0xb0, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0xb8, r32[eax]);
    memoryASet32(ds, r32[esi] + 0xc0, r32[ebp]);
    memoryASet32(ds, r32[esi] + 0x44, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x48, 0x00000069);
    memoryASet32(ds, r32[esi] + 0xac, r32[eax]);
    memoryASet32(ds, r32[esi] + 0xb4, 0x00000008);
    memoryASet32(ds, r32[esi] + 0xa4, r32[ebp]);
    memoryASet32(ds, r32[esi] + 0xbc, r32[eax]);
    memoryASet32(ds, r32[esi] + 0xc4, r32[ebp]);
    if (r32[ebx] == r32[ebp])
        { pc = 0x1001533e; break; }
    r32[edx] = memoryAGet32(ds, r32[ebx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x8);
    r32[ecx] = r32[ebx];
    indirectCall(cs, r32[eax]);
  case 0x1001533e: // 0000:1001533e
    push32(0x0000001c);
    sub_1001fa1d();
    r32[edi] = r32[eax];
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x24, r32[edi]);
    memoryASet(ds, r32[esp] + 0x18, 0x01);
    if (r32[edi] == r32[ebp])
        { pc = 0x10015365; break; }
    push32(r32[edi]);
    sub_10017c70();
    memoryASet32(ds, r32[esi] + 0xa8, r32[edi]);
    { pc = 0x1001536b; break; }
  case 0x10015365: // 0000:10015365
    memoryASet32(ds, r32[esi] + 0xa8, r32[ebp]);
  case 0x1001536b: // 0000:1001536b
    r32[eax] = r32[esi];
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[esp] += 0x0000000c;
    r32[esp] += 12;
    return;
  }
}

function sub_10017c70() // 0000:10017c70 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x10039f48);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    push32(r32[esi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 8;
//    memoryASet32(fs, 0x0, r32[eax]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(0x00000004);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x10017ca7; break; }
    memoryASet32(ds, r32[eax], r32[esi]);
    { pc = 0x10017ca9; break; }
  case 0x10017ca7: // 0000:10017ca7
    r32[eax] = 0;
  case 0x10017ca9: // 0000:10017ca9
    memoryASet32(ds, r32[esi], r32[eax]);
    memoryASet32(ds, r32[esp] + 0x10, 0x00000000);
    sub_10017e40();
    memoryASet32(ds, r32[esi] + 0x14, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x18, 0x00000000);
    r32[eax] = r32[esi];
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[esi] = pop32();
    r32[esp] += 0x0000000c;
    r32[esp] += 8;
    return;
  }
}

function sub_10017e40() // 0000:10017e40 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0x0000000c);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x10017e50; break; }
    memoryASet32(ds, r32[eax], r32[eax]);
  case 0x10017e50: // 0000:10017e50
    r32[ecx] = r32[eax] + 4;
    if (!r32[ecx])
        { pc = 0x10017e59; break; }
    memoryASet32(ds, r32[ecx], r32[eax]);
  case 0x10017e59: // 0000:10017e59
    r32[esp] += 4; return;
    return;
  }
}

function sub_10001620() // 0000:10001620 +long +stackDrop4
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(ds, r32[ecx] + 0xb8, r32[eax]);
    r32[esp] += 8;
}

function sub_1001d6c0() // 0000:1001d6c0 +long +stackDrop4
{
  console.log("destructor image ", r32[ecx].toString(16))
    r32[esp] += 4;
return;
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    sub_1001d7c0();
    if (!(memoryAGet(ds, r32[esp] + 0x8) & 0x01))
        { pc = 0x1001d6d8; break; }
    push32(r32[esi]);
    sub_1001f9a6();
    r32[esp] += 0x00000004;
  case 0x1001d6d8: // 0000:1001d6d8
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 8;
    return;
  }
}

function sub_1001d7c0() // 0000:1001d7c0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x10039c88);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    push32(r32[ecx]);
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 20;
//    memoryASet32(fs, 0x0, r32[eax]);
    r32[esi] = r32[ecx];
    memoryASet32(ds, r32[esp] + 0x10, r32[esi]);
    memoryASet32(ds, r32[esi], 0x1004118c);
    r32[ebx] = 0;
    memoryASet32(ds, r32[esp] + 0x1c, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x28);
    if (r32[ecx] == r32[ebx])
        { pc = 0x1001d805; break; }
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(0x00000001);
    indirectCall(cs, r32[edx]);
  case 0x1001d805: // 0000:1001d805
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x20);
    r32[edi] = memoryAGet32(ds, 0x1003c01c);
    memoryASet32(ds, r32[esi] + 0x28, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x2c, r32[ebx]);
    if (r32[eax] == r32[ebx])
        { pc = 0x1001d81b; break; }
    push32(r32[eax]);
    indirectCall(cs, r32[edi]);
  case 0x1001d81b: // 0000:1001d81b
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x24);
    if (r32[eax] == r32[ebx])
        { pc = 0x1001d825; break; }
    push32(r32[eax]);
    indirectCall(cs, r32[edi]);
  case 0x1001d825: // 0000:1001d825
    r32[ecx] = memoryAGet32(ds, 0x100505bc);
    memoryASet(ds, r32[esi] + 0x1c, r8[bl]);
    memoryASet32(ds, r32[esi] + 0x20, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x24, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x10, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x14, r32[ebx]);
    if (r32[ecx] == r32[ebx])
        { pc = 0x1001d86c; break; }
 console.log("Crash, reading ecx=", r32[ecx].toString(16));
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[ecx] + 0x4);
    indirectCall(cs, r32[edx]);
    memoryASet32(ds, r32[esi], 0x10040058);
    if (r32[edi] != 0x00000001)
        { pc = 0x1001d872; break; }
    memoryASet32(ds, 0x100505bc, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000010;
    r32[esp] += 4; return;
  case 0x1001d86c: // 0000:1001d86c
    memoryASet32(ds, r32[esi], 0x10040058);
  case 0x1001d872: // 0000:1001d872
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000010;
    r32[esp] += 4;
    return;
  }
}
