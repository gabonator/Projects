function sub_100012c0() // 0000:100012c0 +long +stackDrop4
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, r32[esp] + 0x4));
    memoryASet32(ds, r32[ecx] + 0x50, fstp32());
    r32[esp] += 8;
}
function sub_10001990() // 0000:10001990 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    memoryASet32(ds, r32[esi] + 0xb4, r32[eax]);
    if (!(r8[al] & 0x8a))
        { pc = 0x10001a82; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x110);
    indirectCall(cs, r32[eax]);
    if (!memoryAGet32(ds, r32[esi] + 0xc8))
        { pc = 0x10001a5b; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x18c);
    push32(r32[ebx]);
    push32(r32[edi]);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x164);
    push32(0x00000000);
    push32(0xffffffff);
    push32(0x1003e858);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x164);
    push32(0x00000000);
    push32(0xffffffff);
    push32(0x1003e868);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x164);
    push32(0x00000000);
    push32(0xffffffff);
    push32(0x1003e878);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x164);
    push32(0x00000000);
    push32(0xffffffff);
    push32(0x1003e888);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x170);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xc8);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0xb0);
    r32[edi] = r32[eax] + 68;
    r32[ebx] = 0x00000063;
  case 0x10001a40: // 0000:10001a40
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x164);
    push32(0x00000000);
    push32(0xffffffff);
    push32(r32[edi]);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[edi] += 0x00000060;
    r32[ebx]--;
    if (r32[ebx])
        { pc = 0x10001a40; break; }
    r32[edi] = pop32();
    r32[ebx] = pop32();
  case 0x10001a5b: // 0000:10001a5b
    if (!memoryAGet32(ds, r32[esi] + 0xb0))
        { pc = 0x10001a6d; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x28);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
  case 0x10001a6d: // 0000:10001a6d
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xa4);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[eax] = 0x00000003;
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x10001a82: // 0000:10001a82
    r32[eax] = 0x00000002;
    r32[esi] = pop32();
    r32[esp] += 12;
    return;
  }
}
function sub_100043b0() // 0000:100043b0 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] -= 0x00000024;
    { pc = 0x100104d0; break; }
    // gap 49432 bytes // gap 49432 bytes
  case 0x100104d0: // 0000:100104d0
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    memoryASet32(ds, r32[esi] + 0x24, 0x1003edbc);
    memoryASet32(ds, r32[esi], 0x1003fe58);
    memoryASet32(ds, r32[esi] + 0xc, 0x1003fe90);
    eax = ole32__OleUninitialize();
    memoryASet32(ds, r32[esi] + 0xc, 0x1003fe40);
    memoryASet32(ds, r32[esi], 0x1003fe10);
    if (!(memoryAGet(ds, r32[esp] + 0x8) & 0x01))
        { pc = 0x1001050a; break; }
    push32(r32[esi]);
    sub_1001f9a6();
    r32[esp] += 0x00000004;
  case 0x1001050a: // 0000:1001050a
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 8;
    return;
  }
}
function sub_10010510() // 0000:10010510 +long +stackDrop4
{
    r32[esp] -= 4;
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(r32[edi]);
    r32[edi] = r32[ecx];
    r32[eax] = memoryAGet32(ds, r32[edi] - 32);
    r32[ebx] = memoryAGet32(ds, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xdc);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x10c);
    push32(r32[ecx]);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[edi] - 32);
    r32[edx] = memoryAGet32(ds, r32[ebx] + 0x30);
    push32(r32[eax]);
    indirectCall(cs, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x20);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[edx]);
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 8;
}
function sub_10017470() // 0000:10017470 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[esi] = r32[ecx];
    if (memoryAGet(ds, r32[edi]) & 0x02)
        { pc = 0x10017487; break; }
    r32[edi] = pop32();
    r32[eax] = 0x00000002;
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x10017487: // 0000:10017487
    r32[eax] = memoryAGet32(ds, r32[esi]);
    fld32(memoryAGet32(ds, r32[esi] + 0x54));
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x110);
    memoryASet32(ds, r32[esi] + 0x84, fstp32());
    indirectCall(cs, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x38);
    push32(r32[edi]);
    push32(r32[ecx]);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[edx]);
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 12;
    return;
  }
}
function sub_100174b0() // 0000:100174b0 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    fldz();
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    fcomp32(memoryAGet32(ds, r32[esi] + 0x54));
    r16[ax] = fnstsw();
    if (!flags.parity)
        { pc = 0x100174ce; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x44);
    if (!r32[ecx])
        { pc = 0x100174ce; break; }
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    push32(r32[esi]);
    indirectCall(cs, r32[edx]);
  case 0x100174ce: // 0000:100174ce
    fldz();
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x44);
    memoryASet32(ds, r32[esi] + 0x54, fstp32());
    if (!r32[ecx])
        { pc = 0x100174e2; break; }
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    push32(r32[esi]);
    indirectCall(cs, r32[edx]);
  case 0x100174e2: // 0000:100174e2
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[edx]);
    if (!r8[al])
        { pc = 0x100174f8; break; }
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x28);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[edx]);
  case 0x100174f8: // 0000:100174f8
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x114);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[edx]);
    r32[eax] = 0x00000001;
    r32[esi] = pop32();
    r32[esp] += 12;
    return;
  }
}
function sub_10017510() // 0000:10017510 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    if (!(memoryAGet(ds, r32[eax]) & 0x02))
        { pc = 0x1001757d; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    if (r32s[eax] < signed32(memoryAGet32(ds, r32[esi] + 0x8)))
        { pc = 0x1001755e; break; }
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x4);
    if (r32s[ecx] < signed32(memoryAGet32(ds, r32[esi] + 0xc)))
        { pc = 0x1001755e; break; }
    if (r32s[eax] > signed32(memoryAGet32(ds, r32[esi] + 0x10)))
        { pc = 0x1001755e; break; }
    if (r32s[ecx] > signed32(memoryAGet32(ds, r32[esi] + 0x14)))
        { pc = 0x1001755e; break; }
    fldz();
    memoryASet32(ds, r32[esp] + 0xc, 0x00000001);
    fcomp32(memoryAGet32(ds, r32[esi] + 0x84));
    r16[ax] = fnstsw();
    if (!flags.parity)
        { pc = 0x10017558; break; }
    memoryASet32(ds, r32[esp] + 0xc, 0x00000000);
  case 0x10017558: // 0000:10017558
    fild32(memoryAGet32(ds, r32[esp] + 0xc));
    { pc = 0x10017564; break; }
  case 0x1001755e: // 0000:1001755e
    fld32(memoryAGet32(ds, r32[esi] + 0x84));
  case 0x10017564: // 0000:10017564
    r32[edx] = memoryAGet32(ds, r32[esi]);
    memoryASet32(ds, r32[esi] + 0x54, fstp32());
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
    if (!r8[al])
        { pc = 0x1001757d; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x28);
    r32[ecx] = r32[esi];
    indirectCall(cs, r32[eax]);
  case 0x1001757d: // 0000:1001757d
    r32[eax] = 0x00000001;
    r32[esi] = pop32();
    r32[esp] += 12;
    return;
  }
}
function sub_10019d20() // 0000:10019d20 +long +stackDrop16
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    if (!memoryAGet(ds, r32[ecx] + 0x34))
        { pc = 0x10019d8f; break; }
    if (!memoryAGet(ds, r32[ecx] + 0x35))
        { pc = 0x10019d8f; break; }
    if (!memoryAGet32(ds, r32[ecx] + 0x2c))
        { pc = 0x10019d5f; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[esp] -= 0x00000010;
    r32[eax] = r32[esp];
    memoryASet32(ds, r32[eax], r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    memoryASet32(ds, r32[eax] + 0x8, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[eax] + 0xc, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x2c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x24);
    indirectCall(cs, r32[edx]);
    r32[esp] += 20; return;
  case 0x10019d5f: // 0000:10019d5f
    if (!memoryAGet32(ds, r32[ecx] + 0x28))
        { pc = 0x10019d8f; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[esp] -= 0x00000010;
    r32[eax] = r32[esp];
    memoryASet32(ds, r32[eax], r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    memoryASet32(ds, r32[eax] + 0x8, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[eax] + 0xc, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x28);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x24);
    indirectCall(cs, r32[edx]);
  case 0x10019d8f: // 0000:10019d8f
    r32[esp] += 20; return;
    return;
  }
}
function sub_1001f9a6() // 0000:1001f9a6 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[edi] = r32[edi];
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[ebp] = pop32();
    { pc = 0x1001fef1; break; }
    // gap 1344 bytes // gap 1344 bytes
  case 0x1001fef1: // 0000:1001fef1
    push32(0x0000000c);
    push32(0x10049268);
    sub_10026fd0();
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x8);
    if (!r32[esi])
        { pc = 0x1001ff79; break; }
    if (memoryAGet32(ds, 0x10050624) != 0x00000003)
        { pc = 0x1001ff50; break; }
    push32(0x00000004);
    sub_10027444();
    r32[ecx] = pop32();
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) & 0x00000000);
    push32(r32[esi]);
    sub_10027477();
    r32[ecx] = pop32();
    memoryASet32(ss, r32[ebp] - 28, r32[eax]);
    if (!r32[eax])
        { pc = 0x1001ff30; break; }
    push32(r32[esi]);
    push32(r32[eax]);
    sub_100274a7();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
  case 0x1001ff30: // 0000:1001ff30
    memoryASet32(ss, r32[ebp] - 4, 0xfffffffe);
    sub_1001ff47();
    if (memoryAGet32(ss, r32[ebp] - 28))
        { pc = 0x1001ff79; break; }
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    { pc = 0x1001ff51; break; }
    // gap 9 bytes // gap 9 bytes
  case 0x1001ff50: // 0000:1001ff50
    push32(r32[esi]);
  case 0x1001ff51: // 0000:1001ff51
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x1004fdd4));
    eax = kernel32__HeapFree(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPVOID>(2)); esp += 12;
    if (r32[eax])
        { pc = 0x1001ff79; break; }
    sub_10024c26();
    r32[esi] = r32[eax];
    eax = kernel32__GetLastError();
    push32(r32[eax]);
    sub_10024be4();
    memoryASet32(ds, r32[esi], r32[eax]);
    r32[ecx] = pop32();
  case 0x1001ff79: // 0000:1001ff79
    sub_10027015();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function sub_10026fd0() // 0000:10026fd0 +long
{
    r32[esp] -= 4;
    push32(0x10027030);
    push32(memoryAGet32(fs, 0x0));
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    memoryASet32(ds, r32[esp] + 0x10, r32[ebp]);
    r32[ebp] = r32[esp] + 16;
    r32[esp] -= r32[eax];
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) ^ r32[eax]);
    r32[eax] ^= r32[ebp];
    push32(r32[eax]);
    memoryASet32(ss, r32[ebp] - 24, r32[esp]);
    push32(memoryAGet32(ss, r32[ebp] - 8));
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    memoryASet32(ss, r32[ebp] - 4, 0xfffffffe);
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
    r32[eax] = r32[ebp] - 16;
    memoryASet32(fs, 0x0, r32[eax]);
    stop("stack_unbalanced");
    r32[esp] += 4;
}
function sub_10027444() // 0000:10027444 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[edi] = r32[edi];
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    push32(r32[esi]);
    r32[esi] = (r32[eax] * 8) + 268752648;
    if (memoryAGet32(ds, r32[esi]))
        { pc = 0x1002746c; break; }
    push32(r32[eax]);
    sub_10027381();
    r32[ecx] = pop32();
    if (r32[eax])
        { pc = 0x1002746c; break; }
    push32(0x00000011);
    sub_1002a3b5();
    r32[ecx] = pop32();
  case 0x1002746c: // 0000:1002746c
    push32(memoryAGet32(ds, r32[esi]));
    eax = kernel32__EnterCriticalSection();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function sub_10027477() // 0000:10027477 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[edi] = r32[edi];
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[ecx] = memoryAGet32(ds, 0x1005060c);
    r32[eax] = memoryAGet32(ds, 0x10050610);
    r32[ecx] = r32s[ecx] * signed32(0x00000014);
    r32[ecx] += r32[eax];
    { pc = 0x1002749f; break; }
  case 0x1002748e: // 0000:1002748e
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[edx] -= memoryAGet32(ds, r32[eax] + 0xc);
    if (r32[edx] < 0x00100000)
        { pc = 0x100274a5; break; }
    r32[eax] += 0x00000014;
  case 0x1002749f: // 0000:1002749f
    if (r32[eax] < r32[ecx])
        { pc = 0x1002748e; break; }
    r32[eax] = 0;
  case 0x100274a5: // 0000:100274a5
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function sub_100274a7() // 0000:100274a7 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[edi] = r32[edi];
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x00000010;
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x10);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0xc);
    push32(r32[edi]);
    r32[edi] = r32[esi];
    r32[edi] -= memoryAGet32(ds, r32[ecx] + 0xc);
    r32[esi] += 0xfffffffc;
    r32[edi] >>>= 15;
    r32[ecx] = r32[edi];
    r32[ecx] = r32s[ecx] * signed32(0x00000204);
    r32[ecx] = (r32[ecx] + r32[eax]) + 324;
    memoryASet32(ss, r32[ebp] - 16, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi]);
    r32[ecx]--;
    memoryASet32(ss, r32[ebp] - 4, r32[ecx]);
    if (r8[cl] & 0x01)
        { pc = 0x100277b9; break; }
    push32(r32[ebx]);
    r32[ebx] = r32[ecx] + r32[esi];
    r32[edx] = memoryAGet32(ds, r32[ebx]);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esi] - 4);
    memoryASet32(ss, r32[ebp] - 8, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    memoryASet32(ss, r32[ebp] + 0xc, r32[ebx]);
    if (r8[dl] & 0x01)
        { pc = 0x10027574; break; }
    r32[edx] = sar32(r32[edx], 0x04);
    r32[edx]--;
    if (r32[edx] <= 0x0000003f)
        { pc = 0x1002750c; break; }
    push32(0x0000003f);
    r32[edx] = pop32();
  case 0x1002750c: // 0000:1002750c
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x4);
    if (r32[ecx] != memoryAGet32(ds, r32[ebx] + 0x8))
        { pc = 0x10027556; break; }
    r32[ebx] = 0x80000000;
    if (r32[edx] >= 0x00000020)
        { pc = 0x10027537; break; }
    r32[ecx] = r32[edx];
    r32[ebx] >>>= r8[cl];
    r32[ecx] = (r32[edx] + r32[eax]) + 4;
    r32[ebx] = ~r32[ebx];
    memoryASet32(ds, r32[eax] + r32[edi] * 4 + 0x44, memoryAGet32(ds, r32[eax] + r32[edi] * 4 + 0x44) & r32[ebx]);
    memoryASet(ds, r32[ecx], memoryAGet(ds, r32[ecx]) - 1);
    if (memoryAGet(ds, r32[ecx]))
        { pc = 0x10027553; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) & r32[ebx]);
    { pc = 0x10027553; break; }
  case 0x10027537: // 0000:10027537
    r32[ecx] = r32[edx] - 32;
    r32[ebx] >>>= r8[cl];
    r32[ecx] = (r32[edx] + r32[eax]) + 4;
    r32[ebx] = ~r32[ebx];
    memoryASet32(ds, r32[eax] + r32[edi] * 4 + 0xc4, memoryAGet32(ds, r32[eax] + r32[edi] * 4 + 0xc4) & r32[ebx]);
    memoryASet(ds, r32[ecx], memoryAGet(ds, r32[ecx]) - 1);
    if (memoryAGet(ds, r32[ecx]))
        { pc = 0x10027553; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx] + 0x4, memoryAGet32(ds, r32[ecx] + 0x4) & r32[ebx]);
  case 0x10027553: // 0000:10027553
    r32[ebx] = memoryAGet32(ss, r32[ebp] + 0xc);
  case 0x10027556: // 0000:10027556
    r32[edx] = memoryAGet32(ds, r32[ebx] + 0x8);
    r32[ebx] = memoryAGet32(ds, r32[ebx] + 0x4);
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[ecx] += memoryAGet32(ss, r32[ebp] - 12);
    memoryASet32(ds, r32[edx] + 0x4, r32[ebx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[ebx] = memoryAGet32(ds, r32[edx] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0x8);
    memoryASet32(ds, r32[ebx] + 0x8, r32[edx]);
    memoryASet32(ss, r32[ebp] - 4, r32[ecx]);
  case 0x10027574: // 0000:10027574
    r32[edx] = r32[ecx];
    r32[edx] = sar32(r32[edx], 0x04);
    r32[edx]--;
    if (r32[edx] <= 0x0000003f)
        { pc = 0x10027582; break; }
    push32(0x0000003f);
    r32[edx] = pop32();
  case 0x10027582: // 0000:10027582
    r32[ebx] = memoryAGet32(ss, r32[ebp] - 8);
    r32[ebx] &= 0x00000001;
    memoryASet32(ss, r32[ebp] - 12, r32[ebx]);
    if (r32[ebx])
        { pc = 0x10027620; break; }
    r32[esi] -= memoryAGet32(ss, r32[ebp] - 8);
    r32[ebx] = memoryAGet32(ss, r32[ebp] - 8);
    r32[ebx] = sar32(r32[ebx], 0x04);
    push32(0x0000003f);
    memoryASet32(ss, r32[ebp] + 0xc, r32[esi]);
    r32[ebx]--;
    r32[esi] = pop32();
    if (r32[ebx] <= r32[esi])
        { pc = 0x100275a7; break; }
    r32[ebx] = r32[esi];
  case 0x100275a7: // 0000:100275a7
    r32[ecx] += memoryAGet32(ss, r32[ebp] - 8);
    r32[edx] = r32[ecx];
    r32[edx] = sar32(r32[edx], 0x04);
    r32[edx]--;
    memoryASet32(ss, r32[ebp] - 4, r32[ecx]);
    if (r32[edx] <= r32[esi])
        { pc = 0x100275b9; break; }
    r32[edx] = r32[esi];
  case 0x100275b9: // 0000:100275b9
    if (r32[ebx] == r32[edx])
        { pc = 0x1002761b; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x4);
    if (r32[esi] != memoryAGet32(ds, r32[ecx] + 0x8))
        { pc = 0x10027603; break; }
    r32[esi] = 0x80000000;
    if (r32[ebx] >= 0x00000020)
        { pc = 0x100275e9; break; }
    r32[ecx] = r32[ebx];
    r32[esi] >>>= r8[cl];
    r32[esi] = ~r32[esi];
    memoryASet32(ds, r32[eax] + r32[edi] * 4 + 0x44, memoryAGet32(ds, r32[eax] + r32[edi] * 4 + 0x44) & r32[esi]);
    memoryASet(ds, r32[ebx] + r32[eax] + 0x4, memoryAGet(ds, r32[ebx] + r32[eax] + 0x4) - 1);
    if (memoryAGet(ds, r32[ebx] + r32[eax] + 0x4))
        { pc = 0x10027603; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) & r32[esi]);
    { pc = 0x10027603; break; }
  case 0x100275e9: // 0000:100275e9
    r32[ecx] = r32[ebx] - 32;
    r32[esi] >>>= r8[cl];
    r32[esi] = ~r32[esi];
    memoryASet32(ds, r32[eax] + r32[edi] * 4 + 0xc4, memoryAGet32(ds, r32[eax] + r32[edi] * 4 + 0xc4) & r32[esi]);
    memoryASet(ds, r32[ebx] + r32[eax] + 0x4, memoryAGet(ds, r32[ebx] + r32[eax] + 0x4) - 1);
    if (memoryAGet(ds, r32[ebx] + r32[eax] + 0x4))
        { pc = 0x10027603; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx] + 0x4, memoryAGet32(ds, r32[ecx] + 0x4) & r32[esi]);
  case 0x10027603: // 0000:10027603
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x8);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x4);
    memoryASet32(ds, r32[esi] + 0x4, r32[ecx]);
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    memoryASet32(ds, r32[esi] + 0x8, r32[ecx]);
  case 0x1002761b: // 0000:1002761b
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0xc);
    { pc = 0x10027623; break; }
  case 0x10027620: // 0000:10027620
    r32[ebx] = memoryAGet32(ss, r32[ebp] + 0x8);
  case 0x10027623: // 0000:10027623
    if (memoryAGet32(ss, r32[ebp] - 12))
        { pc = 0x10027631; break; }
    if (r32[ebx] == r32[edx])
        { pc = 0x100276b1; break; }
  case 0x10027631: // 0000:10027631
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 16);
    r32[ecx] = r32[ecx] + (r32[edx] * 8);
    r32[ebx] = memoryAGet32(ds, r32[ecx] + 0x4);
    memoryASet32(ds, r32[esi] + 0x8, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x4, r32[ebx]);
    memoryASet32(ds, r32[ecx] + 0x4, r32[esi]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet32(ds, r32[ecx] + 0x8, r32[esi]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    if (r32[ecx] != memoryAGet32(ds, r32[esi] + 0x8))
        { pc = 0x100276b1; break; }
    r8[cl] = memoryAGet(ds, r32[edx] + r32[eax] + 0x4);
    memoryASet(ss, r32[ebp] + 0xf, r8[cl]);
    r8[cl]++;
    memoryASet(ds, r32[edx] + r32[eax] + 0x4, r8[cl]);
    if (r32[edx] >= 0x00000020)
        { pc = 0x10027688; break; }
    if (memoryAGet(ss, r32[ebp] + 0xf))
        { pc = 0x10027677; break; }
    r32[ecx] = r32[edx];
    r32[ebx] = 0x80000000;
    r32[ebx] >>>= r8[cl];
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) | r32[ebx]);
  case 0x10027677: // 0000:10027677
    r32[ebx] = 0x80000000;
    r32[ecx] = r32[edx];
    r32[ebx] >>>= r8[cl];
    r32[eax] = (r32[eax] + (r32[edi] * 4)) + 68;
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) | r32[ebx]);
    { pc = 0x100276b1; break; }
  case 0x10027688: // 0000:10027688
    if (memoryAGet(ss, r32[ebp] + 0xf))
        { pc = 0x1002769e; break; }
    r32[ecx] = r32[edx] - 32;
    r32[ebx] = 0x80000000;
    r32[ebx] >>>= r8[cl];
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx] + 0x4, memoryAGet32(ds, r32[ecx] + 0x4) | r32[ebx]);
  case 0x1002769e: // 0000:1002769e
    r32[ecx] = r32[edx] - 32;
    r32[edx] = 0x80000000;
    r32[edx] >>>= r8[cl];
    r32[eax] = (r32[eax] + (r32[edi] * 4)) + 196;
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) | r32[edx]);
  case 0x100276b1: // 0000:100276b1
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    memoryASet32(ds, r32[esi], r32[eax]);
    memoryASet32(ds, r32[eax] + r32[esi] - 4, r32[eax]);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 16);
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) - 1);
    if (memoryAGet32(ds, r32[eax]))
        { pc = 0x100277b8; break; }
    r32[eax] = memoryAGet32(ds, 0x1004ff28);
    if (!r32[eax])
        { pc = 0x100277aa; break; }
    r32[ecx] = memoryAGet32(ds, 0x10050620);
    r32[esi] = memoryAGet32(ds, 0x1003c0fc);
    push32(0x00004000);
    r32[ecx] <<= 15;
    r32[ecx] += memoryAGet32(ds, r32[eax] + 0xc);
    r32[ebx] = 0x00008000;
    push32(r32[ebx]);
    push32(r32[ecx]);
    indirectCall(cs, r32[esi]);
    r32[ecx] = memoryAGet32(ds, 0x10050620);
    r32[eax] = memoryAGet32(ds, 0x1004ff28);
    r32[edx] = 0x80000000;
    r32[edx] >>>= r8[cl];
    memoryASet32(ds, r32[eax] + 0x8, memoryAGet32(ds, r32[eax] + 0x8) | r32[edx]);
    r32[eax] = memoryAGet32(ds, 0x1004ff28);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x10);
    r32[ecx] = memoryAGet32(ds, 0x10050620);
    memoryASet32(ds, r32[eax] + r32[ecx] * 4 + 0xc4, memoryAGet32(ds, r32[eax] + r32[ecx] * 4 + 0xc4) & 0x00000000);
    r32[eax] = memoryAGet32(ds, 0x1004ff28);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x10);
    memoryASet(ds, r32[eax] + 0x43, memoryAGet(ds, r32[eax] + 0x43) - 1);
    r32[eax] = memoryAGet32(ds, 0x1004ff28);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x10);
    if (memoryAGet(ds, r32[ecx] + 0x43))
        { pc = 0x1002773f; break; }
    memoryASet32(ds, r32[eax] + 0x4, memoryAGet32(ds, r32[eax] + 0x4) & 0xfffffffe);
    r32[eax] = memoryAGet32(ds, 0x1004ff28);
  case 0x1002773f: // 0000:1002773f
    if (memoryAGet32(ds, r32[eax] + 0x8) != 0xffffffff)
        { pc = 0x100277aa; break; }
    push32(r32[ebx]);
    push32(0x00000000);
    push32(memoryAGet32(ds, r32[eax] + 0xc));
    indirectCall(cs, r32[esi]);
    r32[eax] = memoryAGet32(ds, 0x1004ff28);
    push32(memoryAGet32(ds, r32[eax] + 0x10));
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x1004fdd4));
    eax = kernel32__HeapFree(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPVOID>(2)); esp += 12;
    r32[ecx] = memoryAGet32(ds, 0x1005060c);
    r32[eax] = memoryAGet32(ds, 0x1004ff28);
    r32[ecx] = r32s[ecx] * signed32(0x00000014);
    r32[edx] = memoryAGet32(ds, 0x10050610);
    r32[ecx] -= r32[eax];
    r32[ecx] = (r32[ecx] + r32[edx]) + -20;
    push32(r32[ecx]);
    r32[ecx] = r32[eax] + 20;
    push32(r32[ecx]);
    push32(r32[eax]);
    sub_100267e0();
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[esp] += 0x0000000c;
    memoryASet32(ds, 0x1005060c, memoryAGet32(ds, 0x1005060c) - 1);
    if (r32[eax] <= memoryAGet32(ds, 0x1004ff28))
        { pc = 0x100277a0; break; }
    memoryASet32(ss, r32[ebp] + 0x8, memoryAGet32(ss, r32[ebp] + 0x8) - 0x00000014);
  case 0x100277a0: // 0000:100277a0
    r32[eax] = memoryAGet32(ds, 0x10050610);
    memoryASet32(ds, 0x10050618, r32[eax]);
  case 0x100277aa: // 0000:100277aa
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, 0x1004ff28, r32[eax]);
    memoryASet32(ds, 0x10050620, r32[edi]);
  case 0x100277b8: // 0000:100277b8
    r32[ebx] = pop32();
  case 0x100277b9: // 0000:100277b9
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
