// crt_all.cpp — modified CRT functions
void callByAddress(uint32_t addr);
void sub_100c05b0();
void sub_100c4a60();
void sub_100c8680();
void sub_100c8749();
void sub_100c8c18();
void sub_100c8f3d();
void sub_100c8fc4();
void sub_100c90d2();
void sub_100c9124();
void sub_100c91a2();
void sub_100c91bc();
void sub_100c924a();
void sub_100c9470();
void sub_100c97d5();
void sub_100c97f0();
void sub_100c9890();
void sub_100c9ce7();
void sub_100c9f1a();
void sub_100ca1a8();
void sub_100ca260();
void sub_100ca3c0();
void sub_100ca59c();
void sub_100ca5ff();
void sub_100ca62f();
void sub_100ca661();
void sub_100ca6c6();
void sub_100ca86a();
void sub_100ca881();
void sub_100caa85();
void sub_100caaf0();
void sub_100cad4a();
void sub_100cad80();
void sub_100caea1();
void sub_100caf1e();
void sub_100caf8c();
void sub_100cafdf();
void sub_100caffc();
void sub_100cb09d();
void sub_100cb145();
void sub_100cb27c();
void sub_100cb56d();
void sub_100cb654();
void sub_100cb826();
void sub_100cba74();
void sub_100cbe7e();
void sub_100cbec3();
void sub_100cbf0f();
void sub_100cbfaf();
void sub_100cc017();
void sub_100cc0cb();
void sub_100cc1e2();
void sub_100cc27b();
void sub_100cc3c4();
void sub_100cc453();
void sub_100cc52a();
void sub_100cd430();
void sub_100cd580();
void sub_100cd596();
void sub_100cd843();
void sub_100ce243();
void sub_100ce283();
void sub_100ce2b3();
void sub_100ce2dc();
void sub_100ce331();
void sub_100ce34e();
void sub_100ce372();
void sub_100ce523();
void sub_100ce539();
void sub_100ce5e8();
void sub_100ce9b0();
void sub_100ceb9a();
void sub_100cebdb();
void sub_100cec0d();
void sub_100cec49();
void sub_100cee5c();
void sub_100cf161();
void sub_100cfe3c();
void sub_100cff4d();
void sub_100cff64();
void sub_100d0027();
void sub_100d005a();
void sub_100d0b20();
void sub_100d0b65();
void sub_100d0d0c();
void sub_100d0f94();
void sub_100d0fa3();
void sub_100d0fcb();
void sub_100d103d();
void sub_100d1046();
void sub_100d1219();
void sub_100d1292();
void sub_100d13db();
void sub_100d1449();
void sub_100d1be7();
void sub_100d2e6c();
void sub_100d2ea9();
void sub_100d3c00();
void sub_100d3c67();
void sub_100d3e75();
void sub_100d4022();
void sub_100d5500();
void sub_100d56a8();
void sub_100d67af();
void sub_100d6a51();
void sub_100d6b2f();
void sub_100d6cc9();
void sub_100d6d84();
void sub_100d6ebb();
void sub_100d76e1();
void sub_100d76ff();
void sub_100d79f9();
void sub_100d7b8e();
void sub_100d7bd3();
void sub_100d7c61();
void sub_100d7cd5();
void sub_100d8064();
void sub_100d8487();
void sub_100d85e3();
void sub_100d8615();
void sub_100d86b1();
void sub_100da23e();
void sub_100da385();
void sub_100da580();
void sub_100da5c0();
void sub_100da610();
void sub_100da6cd();
void sub_100da6dc();
void sub_100dbe5d();
void sub_100dc046();
void sub_100dc08f();
void sub_100dc3cf();
void sub_100dc48f();
void sub_100dc4ef();
void sub_100dc887();
void sub_100dca8c();
void sub_100dcab9();
void sub_100dcb8d();
void sub_100dcfc7();
void sub_100dcfe1();
void sub_100dd034();
void sub_100dd837();
void sub_100dda82();
void sub_100ddc06();
void sub_100de97d();
void sub_100dea94();
void sub_100dfe00();
void sub_100dfe20();
void sub_100ca0cc();
void sub_100cba51();
void sub_100496af();
void sub_100d8582();
void sub_100d85b2();
void sub_100d85cc();
void sub_100d8599();
void sub_100da7f8();
void sub_100da83b();
void sub_100d3b31();
void sub_6ab00078();
// Auto-extracted sub_100c* and sub_100d* functions
// Total: 390 functions
// Forward declarations for CRT sub-dependencies (defined later in this file)
void sub_100c05b0() // 0000:100c05b0 +long
{
    esp -= 4;
    goto loc_100c05b0;
loc_1001f190: // 0000:1001f190
    ecx += 0x00000004;
    push32(ecx);
    indirectCall(cs, memoryAGet32(ds, 0x100e61dc), __LINE__, 0); // 0000:1001f194
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4; return; // undo synthetic only (stdcall already cleaned the push)
    // gap 5 bytes // gap 5 bytes
loc_1001f1a0: // 0000:1001f1a0
    ecx += 0x00000004;
    push32(ecx);
    indirectCall(cs, memoryAGet32(ds, 0x100e61d8), __LINE__, 0); // 0000:1001f1a4
    // SEH fixed (was stack_unbalanced, 0/-4) // SEH fixed (was stack_unbalanced, 0/-4)
    esp += 4; return;
    // gap 660485 bytes // gap 660485 bytes
loc_100c05b0: // 0000:100c05b0
    ecx = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, ecx + 0x50);
    if (!eax)
        goto loc_100c05c1;
    memoryASet32(ds, esp + 0x4, ecx);
    switch (eax)
    {
        case 0x1001f190: goto loc_1001f190;
        case 0x1001f1a0: goto loc_1001f1a0;
        case 0x00000000: break; // null vtable — no-op
        default: break; // any other vtable — CriticalSection is no-op in single-threaded emulator
        //default_disabled:
            stop("ind 0000:100c05bf");
    }
loc_100c05c1: // 0000:100c05c1
    push32(0x103ede88);
    push32(ecx);
    sub_100c3f10();
    esp += 0x00000008;
    esp += 4;
}
void sub_100c4a60() // 0000:100c4a60 +long
{
    esp -= 4;
    goto loc_100c4a60;
loc_1001f190: // 0000:1001f190
    ecx += 0x00000004;
    push32(ecx);
    indirectCall(cs, memoryAGet32(ds, 0x100e61dc), __LINE__, 0); // 0000:1001f194
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4; return; // undo synthetic only (stdcall already cleaned the push)
    // gap 5 bytes // gap 5 bytes
loc_1001f1a0: // 0000:1001f1a0
    ecx += 0x00000004;
    push32(ecx);
    indirectCall(cs, memoryAGet32(ds, 0x100e61d8), __LINE__, 0); // 0000:1001f1a4
    // SEH fixed (was stack_unbalanced, 0/-4) // SEH fixed (was stack_unbalanced, 0/-4)
    esp += 4; return;
    // gap 678069 bytes // gap 678069 bytes
loc_100c4a60: // 0000:100c4a60
    ecx = memoryAGet32(ds, esp + 0x4);
    if (!ecx)
        goto loc_100c4a8b;
    edx = memoryAGet32(ds, esp + 0x8);
    if (!edx)
        goto loc_100c4a8b;
    eax = memoryAGet32(ds, ecx + 0x24c);
    if (!eax)
        goto loc_100c4a84;
    memoryASet32(ds, esp + 0x8, edx);
    memoryASet32(ds, esp + 0x4, ecx);
    switch (eax)
    {
        case 0x1001f190: goto loc_1001f190;
        case 0x1001f1a0: goto loc_1001f1a0;
        case 0x00000000: break; // null vtable — no-op
        default: break; // any other vtable — CriticalSection is no-op in single-threaded emulator
        //default_disabled:
            stop("ind 0000:100c4a82");
    }
loc_100c4a84: // 0000:100c4a84
    push32(edx);
    sub_100c91bc();
    ecx = pop32();
loc_100c4a8b: // 0000:100c4a8b
    esp += 4; return;
}
void sub_100c8680() // 0000:100c8680 +long — memset via memoryASet (no native bypass)
{ esp -= 4; uint32_t d = memoryAGet32(ss,esp+4); uint32_t v = memoryAGet32(ss,esp+8)&0xFF; uint32_t sz = memoryAGet32(ss,esp+12);
  if(sz>0&&sz<0x1000000) for(uint32_t i=0;i<sz;i++) memoryASet(ds,d+i,v);
  eax=d; esp += 4; }
void sub_100c8749() // 0000:100c8749 +long
{ esp -= 4; uint32_t sz = memoryAGet32(ss, esp+4);
  if(!sz) sz=1;
  eax = allocate(sz); esp += 4; } // malloc stub
void sub_100c8c18() // 0000:100c8c18 +long — free(ptr) (bump allocator, intentional no-op)
{ esp -= 4; esp += 4; }
void sub_100c8f3d() // 0000:100c8f3d +long +stackDrop4
{ esp -= 4; esp += 8; } // stub +stackDrop4 (no-op)
void sub_100c8fc4() // 0000:100c8fc4 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    edx = memoryAGet32(ss, ebp + 0xc);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    push32(edi);
loc_100c8fd1: // 0000:100c8fd1
    eax = memoryAGet(ds, esi);
    ecx = eax - 65;
    esi++;
    if (ecx > 0x00000019)
        goto loc_100c8fe0;
    eax += 0x00000020;
loc_100c8fe0: // 0000:100c8fe0
    ecx = memoryAGet(ds, edx);
    edi = ecx - 65;
    edx++;
    if (edi > 0x00000019)
        goto loc_100c8fef;
    ecx += 0x00000020;
loc_100c8fef: // 0000:100c8fef
    if (!eax)
        goto loc_100c8ff7;
    if (eax == ecx)
        goto loc_100c8fd1;
loc_100c8ff7: // 0000:100c8ff7
    edi = pop32();
    eax -= ecx;
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100c90d2() // 0000:100c90d2 +long
{
    esp -= 4;
    goto loc_100c90d2;
loc_100c8fc4: // 0000:100c8fc4
    edi = edi;
    push32(ebp);
    ebp = esp;
    edx = memoryAGet32(ss, ebp + 0xc);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    push32(edi);
loc_100c8fd1: // 0000:100c8fd1
    eax = memoryAGet(ds, esi);
    ecx = eax - 65;
    esi++;
    if (ecx > 0x00000019)
        goto loc_100c8fe0;
    eax += 0x00000020;
loc_100c8fe0: // 0000:100c8fe0
    ecx = memoryAGet(ds, edx);
    edi = ecx - 65;
    edx++;
    if (edi > 0x00000019)
        goto loc_100c8fef;
    ecx += 0x00000020;
loc_100c8fef: // 0000:100c8fef
    if (!eax)
        goto loc_100c8ff7;
    if (eax == ecx)
        goto loc_100c8fd1;
loc_100c8ff7: // 0000:100c8ff7
    edi = pop32();
    eax -= ecx;
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4; return;
    // gap 213 bytes // gap 213 bytes
loc_100c90d2: // 0000:100c90d2
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = 0;
    if (memoryAGet32(ds, 0x10582164) != esi)
        goto loc_100c9112;
    if (memoryAGet32(ss, ebp + 0x8) != esi)
        goto loc_100c9106;
loc_100c90e7: // 0000:100c90e7
    sub_100cbff1();
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    memoryASet32(ds, eax, 0x00000016);
    sub_100cb27c();
    esp += 0x00000014;
    eax = 0x7fffffff;
    goto loc_100c9121;
loc_100c9106: // 0000:100c9106
    if (memoryAGet32(ss, ebp + 0xc) == esi)
        goto loc_100c90e7;
    esi = pop32();
    esp = ebp; ebp = pop32();
    goto loc_100c8fc4;
loc_100c9112: // 0000:100c9112
    push32(esi);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c8ffd();
    esp += 0x0000000c;
loc_100c9121: // 0000:100c9121
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100c9124() // 0000:100c9124 +long — __vsprintf_l(buf, fmt, locale, va_list)
{
    esp -= 4;
    uint32_t buf = memoryAGet32(ss, esp + 4);
    uint32_t fmt = memoryAGet32(ss, esp + 8);
    // skip locale at esp+12
    uint32_t vaList = memoryAGet32(ss, esp + 16);
    int outPos = 0, argOfs = 0;
    for (int i = 0; i < 256; i++) {
        uint8_t c = memoryAGet(ds, fmt + i);
        if (!c) break;
        if (c == '%' && i + 1 < 256) {
            uint8_t spec = memoryAGet(ds, fmt + i + 1);
            i++;
            // Skip flags/width/precision
            while (spec == '-' || spec == '+' || spec == ' ' || spec == '#' || spec == '0') { i++; spec = memoryAGet(ds, fmt + i); }
            while (spec >= '0' && spec <= '9') { i++; spec = memoryAGet(ds, fmt + i); }
            if (spec == '.') { i++; spec = memoryAGet(ds, fmt + i); while (spec >= '0' && spec <= '9') { i++; spec = memoryAGet(ds, fmt + i); } }
            if (spec == 'l' || spec == 'h') { i++; spec = memoryAGet(ds, fmt + i); }
            uint32_t val = memoryAGet32(ds, vaList + argOfs);
            argOfs += 4;
            if (spec == 's') {
                for (int j = 0; j < 260 && memoryAGet(ds, val + j); j++)
                    memoryASet(ds, buf + outPos++, memoryAGet(ds, val + j));
            } else if (spec == 'd' || spec == 'i') {
                char tmp[16]; snprintf(tmp, sizeof(tmp), "%d", (int32_t)val);
                for (int j = 0; tmp[j]; j++) memoryASet(ds, buf + outPos++, tmp[j]);
            } else if (spec == 'c') {
                memoryASet(ds, buf + outPos++, val & 0xff);
            } else if (spec == 'x' || spec == 'X') {
                char tmp[16]; snprintf(tmp, sizeof(tmp), spec == 'x' ? "%x" : "%X", val);
                for (int j = 0; tmp[j]; j++) memoryASet(ds, buf + outPos++, tmp[j]);
            } else if (spec == 'u') {
                char tmp[16]; snprintf(tmp, sizeof(tmp), "%u", val);
                for (int j = 0; tmp[j]; j++) memoryASet(ds, buf + outPos++, tmp[j]);
            } else if (spec == '%') {
                memoryASet(ds, buf + outPos++, '%');
            } else {
                memoryASet(ds, buf + outPos++, '%');
                memoryASet(ds, buf + outPos++, spec);
            }
        } else {
            memoryASet(ds, buf + outPos++, c);
        }
    }
    memoryASet(ds, buf + outPos, 0);
    eax = outPos;
    esp += 4;
}
void sub_100c91a2() // 0000:100c91a2 +long — _vsprintf(buf, fmt, va_list) cdecl
{
    esp -= 4;
    uint32_t buf = memoryAGet32(ss, esp + 4);
    uint32_t fmt = memoryAGet32(ss, esp + 8);
    uint32_t vaList = memoryAGet32(ss, esp + 12);
    // Simple vsprintf: copy fmt, replacing %s/%d with args from va_list
    int outPos = 0, argOfs = 0;
    for (int i = 0; i < 256; i++) {
        uint8_t c = memoryAGet(ds, fmt + i);
        if (!c) break;
        if (c == '%' && i + 1 < 256) {
            uint8_t spec = memoryAGet(ds, fmt + i + 1);
            i++;
            uint32_t val = memoryAGet32(ds, vaList + argOfs);
            argOfs += 4;
            if (spec == 's') {
                for (int j = 0; j < 260 && memoryAGet(ds, val + j); j++)
                    memoryASet(ds, buf + outPos++, memoryAGet(ds, val + j));
            } else if (spec == 'd' || spec == 'i') {
                char tmp[16]; snprintf(tmp, sizeof(tmp), "%d", (int32_t)val);
                for (int j = 0; tmp[j]; j++) memoryASet(ds, buf + outPos++, tmp[j]);
            } else if (spec == 'c') {
                memoryASet(ds, buf + outPos++, val & 0xff);
            } else if (spec == 'x' || spec == 'X') {
                char tmp[16]; snprintf(tmp, sizeof(tmp), spec == 'x' ? "%x" : "%X", val);
                for (int j = 0; tmp[j]; j++) memoryASet(ds, buf + outPos++, tmp[j]);
            } else if (spec == 'u') {
                char tmp[16]; snprintf(tmp, sizeof(tmp), "%u", val);
                for (int j = 0; tmp[j]; j++) memoryASet(ds, buf + outPos++, tmp[j]);
            } else if (spec == '%') {
                memoryASet(ds, buf + outPos++, '%');
            } else {
                memoryASet(ds, buf + outPos++, c);
                memoryASet(ds, buf + outPos++, spec);
            }
        } else {
            memoryASet(ds, buf + outPos++, c);
        }
    }
    memoryASet(ds, buf + outPos, 0);
/*
    { char _fmt[64]={0}, _res[64]={0};
      for(int i=0;i<63;i++){_fmt[i]=memoryAGet(ds,fmt+i);if(!_fmt[i])break;}
      for(int i=0;i<63;i++){_res[i]=memoryAGet(ds,buf+i);if(!_res[i])break;}
      printf("vsprintf: fmt='%s' -> '%s'\n", _fmt, _res);
    }
*/
    eax = outPos;
    esp += 4; // cdecl: no stackDrop
}
void sub_100c91bc() // 0000:100c91bc +long — free() (bump allocator, intentional no-op)
{
    esp -= 4;
    // free() is intentionally no-op: bump allocator never frees
    esp += 4;
}
void sub_100c924a() // 0000:100c924a +long
{ esp -= 4; uint32_t p = memoryAGet32(ss,esp+4); uint32_t sz = memoryAGet32(ss,esp+8); if(!sz) sz=1; uint32_t np = allocate(sz);
  if(p>=0x10001000&&sz<0x1000000) for(uint32_t i=0;i<sz;i++) memoryASet(ds,np+i,memoryAGet(ds,p+i));
  eax=np; esp += 4; } // realloc stub
void sub_100c9470() // 0000:100c9470 +long
{ esp -= 4; eax = 0; esp += 4; } //  stub
void sub_100c97d5() // 0000:100c97d5 +long
{
    esp -= 4;
    edi = edi;
    push32(esi);
    push32(0x00000001);
    push32(0x1057dc70);
    esi = ecx;
    sub_100cafdf();
    memoryASet32(ds, esi, 0x103cf748);
    eax = esi;
    esi = pop32();
    esp += 4;
}
void sub_100c97f0() // 0000:100c97f0 +long
{ esp -= 4; uint32_t sz = memoryAGet32(ss, esp+4); if(!sz) sz=1; eax = allocate(sz); esp += 4; }
void sub_100c9890() // 0000:100c9890 +long
{
    esp -= 4;
    uint32_t dst = memoryAGet32(ss, esp+4);
    uint32_t src = memoryAGet32(ss, esp+8);
    uint32_t sz = memoryAGet32(ss, esp+12);
    // memcpy via memoryASet/memoryAGet (no native bypass)
    if (sz > 0 && sz < 0x1000000)
        for (uint32_t i = 0; i < sz; i++) memoryASet(ds, dst+i, memoryAGet(ds, src+i));
    else
        printf("Warning: memcpy size %d\n", sz);
    eax = dst;
    esp += 4;
}
void sub_100c9ce7() // 0000:100c9ce7 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = 0;
    if (memoryAGet32(ds, 0x10582164) != esi)
        goto loc_100c9d30;
    if (memoryAGet32(ss, ebp + 0x8) != esi)
        goto loc_100c9d1b;
loc_100c9cfc: // 0000:100c9cfc
    sub_100cbff1();
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    memoryASet32(ds, eax, 0x00000016);
    sub_100cb27c();
    esp += 0x00000014;
    eax = 0x7fffffff;
    goto loc_100c9d42;
loc_100c9d1b: // 0000:100c9d1b
    if (memoryAGet32(ss, ebp + 0xc) == esi)
        goto loc_100c9cfc;
    if (memoryAGet32(ss, ebp + 0x10) > 0x7fffffff)
        goto loc_100c9cfc;
    esi = pop32();
    esp = ebp; ebp = pop32();
    goto loc_100d2cb0;
loc_100c9d30: // 0000:100c9d30
    push32(esi);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c9bf5();
    esp += 0x00000010;
loc_100c9d42: // 0000:100c9d42
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4; return;
    // gap 36715 bytes // gap 36715 bytes
loc_100d2cb0: // 0000:100d2cb0
    push32(ebp);
    ebp = esp;
    push32(edi);
    push32(esi);
    push32(ebx);
    ecx = memoryAGet32(ss, ebp + 0x10);
    if (!ecx)
        goto loc_100d2d0a;
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ss, ebp + 0xc);
    bh = 0x41;
    bl = 0x5a;
    dh = 0x20;
    ecx = ecx;
loc_100d2ccc: // 0000:100d2ccc
    ah = memoryAGet(ds, esi);
    al = memoryAGet(ds, edi);
    if (!ah)
        goto loc_100d2cfb;
    if (!al)
        goto loc_100d2cfb;
    esi++;
    edi++;
    if (ah < bh)
        goto loc_100d2ce8;
    if (ah > bl)
        goto loc_100d2ce8;
    ah += dh;
loc_100d2ce8: // 0000:100d2ce8
    if (al < bh)
        goto loc_100d2cf2;
    if (al > bl)
        goto loc_100d2cf2;
    al += dh;
loc_100d2cf2: // 0000:100d2cf2
    flags.carry = ah < al;
    if (ah != al)
        goto loc_100d2d01;
    ecx--;
    if (ecx)
        goto loc_100d2ccc;
loc_100d2cfb: // 0000:100d2cfb
    ecx = 0;
    flags.carry = ah < al;
    if (ah == al)
        goto loc_100d2d0a;
loc_100d2d01: // 0000:100d2d01
    ecx = 0xffffffff;
    if (flags.carry)
        goto loc_100d2d0a;
    ecx = -ecx;
loc_100d2d0a: // 0000:100d2d0a
    eax = ecx;
    ebx = pop32();
    esi = pop32();
    edi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_100c9f1a() // 0000:100c9f1a +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    if (memoryAGet32(ds, 0x10582164))
        goto loc_100c9f3a;
    eax = memoryAGet32(ss, ebp + 0x8);
    ecx = memoryAGet32(ds, 0x1057e9b8);
    eax = memoryAGet16(ds, ecx + eax * 2);
    eax &= 0x00000004;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100c9f3a: // 0000:100c9f3a
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c9ec9();
    ecx = pop32();
    ecx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
// Forward declarations for sub_10055bd0
void sub_100ca1a8() // 0000:100ca1a8 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    if (memoryAGet32(ds, 0x10582164))
        goto loc_100ca1ca;
    eax = memoryAGet32(ss, ebp + 0x8);
    ecx = memoryAGet32(ds, 0x1057e9b8);
    eax = memoryAGet16(ds, ecx + eax * 2);
    eax &= 0x00000157;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100ca1ca: // 0000:100ca1ca
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100ca152();
    ecx = pop32();
    ecx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100ca260() // 0000:100ca260 +long
{ esp -= eax; } // __alloca_probe: just sub esp, eax
void sub_100ca3c0() // 0000:100ca3c0 +long — _ftol2_sse: convert ST(0) to int32 in eax
{ esp -= 4; eax = (int32_t)st(0); fppop(); esp += 4; }
void sub_100ca59c() // 0000:100ca59c +long +stackDrop16
{ esp -= 4; eax = 0; esp += 20; } // stub +stackDrop16
void sub_100ca5ff() // 0000:100ca5ff +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, memoryAGet32(ds, 0x100e60f0), __LINE__, 0); // 0000:100ca607
    if (eax)
        goto loc_100ca619;
    indirectCall(cs, memoryAGet32(ds, 0x100e60e4), __LINE__, 0); // 0000:100ca611
    goto loc_100ca61b;
loc_100ca619: // 0000:100ca619
    eax = 0;
loc_100ca61b: // 0000:100ca61b
    if (!eax)
        goto loc_100ca62b;
    push32(eax);
    sub_100cc017();
    ecx = pop32();
    eax |= 0xffffffff;
    esp = ebp; ebp = pop32();
    esp += 4; return; // reverted: "SEH fix" +8 was WRONG (+4 leak)
loc_100ca62b: // 0000:100ca62b
    eax = 0;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100ca62f() // 0000:100ca62f +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, memoryAGet32(ds, 0x100e60f4), __LINE__, 0); // 0000:100ca639
    if (eax)
        goto loc_100ca64b;
    indirectCall(cs, memoryAGet32(ds, 0x100e60e4), __LINE__, 0); // 0000:100ca643
    goto loc_100ca64d;
loc_100ca64b: // 0000:100ca64b
    eax = 0;
loc_100ca64d: // 0000:100ca64d
    if (!eax)
        goto loc_100ca65d;
    push32(eax);
    sub_100cc017();
    ecx = pop32();
    eax |= 0xffffffff;
    esp = ebp; ebp = pop32();
    esp += 4; return; // reverted: "SEH fix" +12 was WRONG (+8 leak)
loc_100ca65d: // 0000:100ca65d
    eax = 0;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100ca661() // 0000:100ca661 +long +stackDrop20 — NATIVE: _eh_vec_ctor_vb
{
    // Args: [esp+4]=array, [esp+8]=elemSize, [esp+12]=count, [esp+16]=ctor, [esp+20]=dtor
    esp -= 4;
    uint32_t arr   = memoryAGet32(ss, esp + 4);
    uint32_t esz   = memoryAGet32(ss, esp + 8);
    uint32_t cnt   = memoryAGet32(ss, esp + 12);
    uint32_t ctor  = memoryAGet32(ss, esp + 16);
    uint32_t dtor  = memoryAGet32(ss, esp + 20);
    if (cnt > 10000) cnt = 0; // safety
    // Save callee-save registers — element constructors modify them
    volatile uint32_t save_ebx=ebx, save_esi=esi, save_edi=edi, save_ebp=ebp, save_esp=esp;
    for (uint32_t i = 0; i < cnt; i++) {
        esp = save_esp; // reset before each ctor (ctors have ESP drift)
        ecx = arr + i * esz;
        switch (ctor) {
            case 0x10031b90: sub_10031b90(); break;
            case 0x10031d70: sub_10031d70(); break;
            case 0x10009670: sub_10009670(); break;
            case 0x100608b0: sub_100608b0(); break;
            case 0x10061b60: sub_10061b60(); break;
            case 0x1000bf80: sub_1000bf80(); break;
            case 0x10065d80: sub_10065d80(); break;
            case 0x1004e4e0: sub_1004e4e0(); break;
case 0x100076c0: sub_100076c0(); break;
case 0x100574c0: sub_100574c0(); break;
case 0x10062750: sub_10062750(); break;
case 0x10065780: sub_10065780(); break;
case 0x10068560: sub_10068560(); break;
case 0x10058670: sub_10058670(); break;
case 0x10064fd0: sub_10064fd0(); break;
            default:
              fprintf(stderr, "------sub_100ca661- case 0x%x: sub_%x(); break;\n", ctor, ctor); 
fflush(stderr);
assert(0);
        }
    }
    ebx=save_ebx; esi=save_esi; edi=save_edi; ebp=save_ebp; esp=save_esp;
    esp += 24;
}
void sub_100ca6c6() // 0000:100ca6c6 +long — sprintf(dst, fmt, ...)
{
    esp -= 4;
    uint32_t dst = memoryAGet32(ss, esp + 4);
    uint32_t fmt_ptr = memoryAGet32(ss, esp + 8);
    // Read format string
    char fmt[256] = {0};
    for (int i = 0; i < 255; i++) { fmt[i] = memoryAGet(ds, fmt_ptr + i); if (!fmt[i]) break; }
    // Parse format string to determine arg types, then read varargs
    uint32_t raw[8];
    for (int i = 0; i < 8; i++) raw[i] = memoryAGet32(ss, esp + 12 + i * 4);
    // Scan format string for % specifiers, resolve %s args to strings
    char s[8][260]; // string buffers for %s args
    int argIdx = 0;
    for (const char* p = fmt; *p && argIdx < 8; p++) {
        if (*p != '%') continue;
        p++;
        if (*p == '%') continue; // %%
        // Skip flags, width, precision
        while (*p == '-' || *p == '+' || *p == ' ' || *p == '#' || *p == '0') p++;
        while (*p >= '0' && *p <= '9') p++;
        if (*p == '.') { p++; while (*p >= '0' && *p <= '9') p++; }
        // Length modifiers
        if (*p == 'l' || *p == 'h') p++;
        if (*p == 'l' || *p == 'h') p++;
        // Now *p is the conversion specifier
        if (*p == 's') {
            // String arg — read from emulated memory
            s[argIdx][0] = 0;
            if (raw[argIdx] >= 0x10000000u && raw[argIdx] < 0x50000000u) {
                for (int j = 0; j < 259; j++) { s[argIdx][j] = memoryAGet(ds, raw[argIdx] + j); if (!s[argIdx][j]) break; }
                s[argIdx][259] = 0;
            }
        }
        // For all other specifiers (d, i, u, x, X, o, c, p, f, e, g), raw value is used directly
        argIdx++;
        if (!*p) break;
    }
    // Build result — for %s, substitute string buffers; for others, pass raw values
    // Use a manual approach: rebuild format with resolved strings
    char result[1024];
    // Determine which args are strings
    bool isStr[8] = {false};
    argIdx = 0;
    for (const char* p = fmt; *p && argIdx < 8; p++) {
        if (*p != '%') continue;
        p++;
        if (*p == '%') continue;
        while (*p == '-' || *p == '+' || *p == ' ' || *p == '#' || *p == '0') p++;
        while (*p >= '0' && *p <= '9') p++;
        if (*p == '.') { p++; while (*p >= '0' && *p <= '9') p++; }
        if (*p == 'l' || *p == 'h') p++;
        if (*p == 'l' || *p == 'h') p++;
        if (*p == 's') isStr[argIdx] = true;
        argIdx++;
        if (!*p) break;
    }
    // Build with correct types
    // Since we can't dynamically dispatch printf types cleanly, use snprintf with
    // string pointers for %s and uint32_t cast for everything else
    // Simple approach: up to 4 args, cast as needed
    void* resolved[8];
    for (int i = 0; i < 8; i++) {
        if (isStr[i]) resolved[i] = (void*)s[i];
        else resolved[i] = (void*)(uintptr_t)raw[i];
    }
    snprintf(result, sizeof(result), fmt,
             resolved[0], resolved[1], resolved[2], resolved[3],
             resolved[4], resolved[5], resolved[6], resolved[7]);
    for (int i = 0; result[i] && i < 1023; i++) memoryASet(ds, dst + i, result[i]);
    memoryASet(ds, dst + strlen(result), 0);
    eax = dst;
    esp += 4;
}
void sub_100ca86a() // 0000:100ca86a +long
{ esp -= 4; eax=0; esp += 4; } // atexit stub
void sub_100ca881() // 0000:100ca881 +long — strtok: copies chars from src up to delimiter into dest
{
    esp -= 4;
    uint32_t dest = memoryAGet32(ss, esp + 4);
    uint32_t delim_ptr = memoryAGet32(ss, esp + 8);
    char delim = memoryAGet(ds, delim_ptr);
/*
    { static int _sc=0; if(++_sc<=10) {
        char _buf[64]={0}; for(int _i=0;_i<63;_i++){_buf[_i]=memoryAGet(ds,dest+_i);if(!_buf[_i])break;}
        fprintf(stderr, "strtok #%d: dest=0x%08x '%s' delim='%c'(0x%02x)\n", _sc, dest, _buf, delim?delim:'?', (uint8_t)delim);
    }}
*/
    // The source string is at edi (set by caller before push/call)
    // Copy from the local buffer at [esp+44 before pushes] = caller's stack buffer
    // Actually the source was copied to [esp+2c] area by the copy loop before the call
    // But the function itself: strtok(dest, delim) splits the PREVIOUSLY set string
    // For this specific case: the source string is in the dest buffer area (was copied there before)
    // Just find delimiter in the string at dest and truncate
    uint32_t i = 0;
    while (true) {
        uint8_t c = memoryAGet(ds, dest + i);
        if (c == 0 || c == (uint8_t)delim) {
            memoryASet(ds, dest + i, 0);
            break;
        }
        i++;
        if (i > 256) break;
    }
    eax = dest;
    esp += 4;
}
void sub_100caa85() // 0000:100caa85 +long
{
    esp -= 4;
    push32(memoryAGet32(ds, 0x10582674));
    sub_100d1046();
    ecx = pop32();
    if (!eax)
        goto loc_100caa97;
    indirectCall(cs, eax, __LINE__, 0); // 0000:100caa95
loc_100caa97: // 0000:100caa97
    push32(0x00000019);
    sub_100d0db0();
    push32(0x00000001);
    push32(0x00000000);
    sub_100cc1e2();
    esp += 0x0000000c;
    goto loc_100cc0cb;
    // gap 5660 bytes // gap 5660 bytes
loc_100cc0cb: // 0000:100cc0cb
    edi = edi;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000328;
    eax = memoryAGet32(ds, 0x1057deec);
    eax ^= ebp;
    memoryASet32(ss, ebp - 4, eax);
    push32(esi);
    if (!(memoryAGet(ds, 0x1057dec0) & 0x01))
        goto loc_100cc0f2;
    push32(0x0000000a);
    sub_100d0db0();
    ecx = pop32();
loc_100cc0f2: // 0000:100cc0f2
    sub_100d7736();
    if (!eax)
        goto loc_100cc103;
    push32(0x00000016);
    sub_100d7743();
    ecx = pop32();
loc_100cc103: // 0000:100cc103
    if (!(memoryAGet(ds, 0x1057dec0) & 0x02))
        goto loc_100cc1da;
    memoryASet32(ss, ebp - 544, eax);
    memoryASet32(ss, ebp - 548, ecx);
    memoryASet32(ss, ebp - 552, edx);
    memoryASet32(ss, ebp - 556, ebx);
    memoryASet32(ss, ebp - 560, esi);
    memoryASet32(ss, ebp - 564, edi);
    memoryASet16(ss, ebp - 520, ss);
    memoryASet16(ss, ebp - 532, cs);
    memoryASet16(ss, ebp - 568, ds);
    memoryASet16(ss, ebp - 572, es);
    memoryASet16(ss, ebp - 576, fs);
    memoryASet16(ss, ebp - 580, gs);
    push32(flagAsReg32());
    memoryASet32(ss, ebp - 528, pop32());
    esi = memoryAGet32(ss, ebp + 0x4);
    eax = ebp + 4;
    memoryASet32(ss, ebp - 524, eax);
    memoryASet32(ss, ebp - 720, 0x00010001);
    memoryASet32(ss, ebp - 536, esi);
    eax = memoryAGet32(ds, eax - 4);
    push32(0x00000050);
    memoryASet32(ss, ebp - 540, eax);
    eax = ebp - 808;
    push32(0x00000000);
    push32(eax);
    sub_100c8680();
    eax = ebp - 808;
    esp += 0x0000000c;
    memoryASet32(ss, ebp - 728, eax);
    eax = ebp - 720;
    push32(0x00000000);
    memoryASet32(ss, ebp - 808, 0x40000015);
    memoryASet32(ss, ebp - 796, esi);
    memoryASet32(ss, ebp - 724, eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e61e4), __LINE__, 0); // 0000:100cc1c7
    eax = ebp - 728;
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e6104), __LINE__, 0); // 0000:100cc1d4
loc_100cc1da: // 0000:100cc1da
    push32(0x00000003);
    sub_100ce539();
    stop("breakpoint");
    edi = edi;
    push32(ebp);
    ebp = esp;
    ecx = memoryAGet32(ss, ebp + 0xc);
    eax = memoryAGet32(ds, 0x1057dec0);
    edx = memoryAGet32(ss, ebp + 0x8);
    edx &= memoryAGet32(ss, ebp + 0xc);
    ecx = ~ecx;
    ecx &= eax;
    ecx |= edx;
    memoryASet32(ds, 0x1057dec0, ecx);
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-820) // SEH removed (was stack_unbalanced, 0/-820)
    esp += 4;
}
void sub_100caaf0() // 0000:100caaf0 +long +returnZero
{ esp -= 4; double ex=fpuinsns::st(0),ba=fpuinsns::st(1); double r=pow(ba,ex); if(!isfinite(r))r=0; fpuinsns::setst(1,r); fpuinsns::fppop(); esp += 4; } // pow stub
void sub_100cad4a() // 0000:100cad4a +long — __CIfmod: fmod(ST(0), ST(1))
{ esp -= 4; double x=st(0), y=st(1); double r=fmod(x,y); if(!isfinite(r)) r=0; setst(1,r); fppop(); esp += 4; }
void sub_100cad80() // 0000:100cad80 +long — fmod wrapper (cdecl, double args on stack)
{ esp -= 4;
  uint64_t xr = memoryAGet64(ds, esp+4), yr = memoryAGet64(ds, esp+12);
  double x, y; memcpy(&x, &xr, 8); memcpy(&y, &yr, 8);
  fppush(fmod(x,y));
  esp += 4; }
void sub_100caea1() // 0000:100caea1 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x14);
    push32(edi);
    edi = 0;
    if (esi != edi)
        goto loc_100caeb5;
loc_100caeb1: // 0000:100caeb1
    eax = 0;
    goto loc_100caf1a;
loc_100caeb5: // 0000:100caeb5
    if (memoryAGet32(ss, ebp + 0x8) != edi)
        goto loc_100caed5;
loc_100caeba: // 0000:100caeba
    sub_100cbff1();
    push32(0x00000016);
    esi = pop32();
    memoryASet32(ds, eax, esi);
loc_100caec4: // 0000:100caec4
    push32(edi);
    push32(edi);
    push32(edi);
    push32(edi);
    push32(edi);
    sub_100cb27c();
    esp += 0x00000014;
    eax = esi;
    goto loc_100caf1a;
loc_100caed5: // 0000:100caed5
    if (memoryAGet32(ss, ebp + 0x10) == edi)
        goto loc_100caef0;
    if (memoryAGet32(ss, ebp + 0xc) < esi)
        goto loc_100caef0;
    push32(esi);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c9890();
    esp += 0x0000000c;
    goto loc_100caeb1;
loc_100caef0: // 0000:100caef0
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(edi);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c8680();
    esp += 0x0000000c;
    if (memoryAGet32(ss, ebp + 0x10) == edi)
        goto loc_100caeba;
    if (memoryAGet32(ss, ebp + 0xc) >= esi)
        goto loc_100caf17;
    sub_100cbff1();
    push32(0x00000022);
    ecx = pop32();
    memoryASet32(ds, eax, ecx);
    esi = ecx;
    goto loc_100caec4;
loc_100caf17: // 0000:100caf17
    push32(0x00000016);
    eax = pop32();
loc_100caf1a: // 0000:100caf1a
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100caf1e() // 0000:100caf1e +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(esi);
    push32(edi);
    edi = 0;
    if (eax == edi)
        goto loc_100caf75;
    if (memoryAGet32(ss, ebp + 0x8) != edi)
        goto loc_100caf4e;
loc_100caf33: // 0000:100caf33
    sub_100cbff1();
    push32(0x00000016);
    esi = pop32();
    memoryASet32(ds, eax, esi);
loc_100caf3d: // 0000:100caf3d
    push32(edi);
    push32(edi);
    push32(edi);
    push32(edi);
    push32(edi);
    sub_100cb27c();
    esp += 0x00000014;
    eax = esi;
    goto loc_100caf77;
loc_100caf4e: // 0000:100caf4e
    if (memoryAGet32(ss, ebp + 0x10) == edi)
        goto loc_100caf33;
    if (memoryAGet32(ss, ebp + 0xc) >= eax)
        goto loc_100caf66;
    sub_100cbff1();
    push32(0x00000022);
    ecx = pop32();
    memoryASet32(ds, eax, ecx);
    esi = ecx;
    goto loc_100caf3d;
loc_100caf66: // 0000:100caf66
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c9470();
    esp += 0x0000000c;
loc_100caf75: // 0000:100caf75
    eax = 0;
loc_100caf77: // 0000:100caf77
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100caf8c() // 0000:100caf8c +long +stackDrop4
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    ebx = memoryAGet32(ss, ebp + 0x8);
    push32(esi);
    push32(edi);
    edi = ecx;
    memoryASet32(ds, edi, 0x103ef674);
    eax = memoryAGet32(ds, ebx);
    if (!eax)
        goto loc_100cafcb;
    push32(eax);
    sub_100cc040();
    esi = eax;
    esi++;
    push32(esi);
    sub_100c8749();
    ecx = pop32();
    ecx = pop32();
    memoryASet32(ds, edi + 0x4, eax);
    if (!eax)
        goto loc_100cafcf;
    push32(memoryAGet32(ds, ebx));
    push32(esi);
    push32(eax);
    sub_100d5500();
    esp += 0x0000000c;
    goto loc_100cafcf;
loc_100cafcb: // 0000:100cafcb
    memoryASet32(ds, edi + 0x4, memoryAGet32(ds, edi + 0x4) & 0x00000000);
loc_100cafcf: // 0000:100cafcf
    memoryASet32(ds, edi + 0x8, 0x00000001);
    eax = edi;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 8;
}
void sub_100cafdf() // 0000:100cafdf +long +stackDrop8
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = ecx;
    ecx = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, eax, 0x103ef674);
    ecx = memoryAGet32(ds, ecx);
    memoryASet32(ds, eax + 0x8, memoryAGet32(ds, eax + 0x8) & 0x00000000);
    memoryASet32(ds, eax + 0x4, ecx);
    esp = ebp; ebp = pop32();
    esp += 12;
}
void sub_100caffc() // 0000:100caffc +long +stackDrop4
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    ebx = memoryAGet32(ss, ebp + 0x8);
    push32(esi);
    esi = ecx;
    memoryASet32(ds, esi, 0x103ef674);
    eax = memoryAGet32(ds, ebx + 0x8);
    memoryASet32(ds, esi + 0x8, eax);
    flags.zero = eax == 0;
    eax = memoryAGet32(ds, ebx + 0x4);
    push32(edi);
    if (flags.zero)
        goto loc_100cb04d;
    if (!eax)
        goto loc_100cb047;
    push32(eax);
    sub_100cc040();
    edi = eax;
    edi++;
    push32(edi);
    sub_100c8749();
    ecx = pop32();
    ecx = pop32();
    memoryASet32(ds, esi + 0x4, eax);
    if (!eax)
        goto loc_100cb050;
    push32(memoryAGet32(ds, ebx + 0x4));
    push32(edi);
    push32(eax);
    sub_100d5500();
    esp += 0x0000000c;
    goto loc_100cb050;
loc_100cb047: // 0000:100cb047
    memoryASet32(ds, esi + 0x4, memoryAGet32(ds, esi + 0x4) & 0x00000000);
    goto loc_100cb050;
loc_100cb04d: // 0000:100cb04d
    memoryASet32(ds, esi + 0x4, eax);
loc_100cb050: // 0000:100cb050
    edi = pop32();
    eax = esi;
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 8;
}
void sub_100cb09d() // 0000:100cb09d +long — operator delete (calls free, intentional no-op)
{ esp -= 4; esp += 4; }
void sub_100cb145() // 0000:100cb145 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, 0x10582140, eax);
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cb27c() // 0000:100cb27c +long — CRT invalid parameter handler
{
    static int _crtCnt = 0;
    if (++_crtCnt <= 5) printf("CRT invalid parameter (continuing, #%d)\n", _crtCnt);
    // On Windows this doesn't abort — just returns. Our stricmp gets NULL args from
    // content entries with empty name strings. Let it continue.
loc_1001f190: // 0000:1001f190
    ecx += 0x00000004;
    push32(ecx);
    indirectCall(cs, memoryAGet32(ds, 0x100e61dc), __LINE__, 0); // 0000:1001f194
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4; return; // undo synthetic only (stdcall already cleaned the push)
    // gap 5 bytes // gap 5 bytes
loc_1001f1a0: // 0000:1001f1a0
    ecx += 0x00000004;
    push32(ecx);
    indirectCall(cs, memoryAGet32(ds, 0x100e61d8), __LINE__, 0); // 0000:1001f1a4
    // SEH fixed (was stack_unbalanced, 0/-4) // SEH fixed (was stack_unbalanced, 0/-4)
    esp += 4; return;
    // gap 704425 bytes // gap 704425 bytes
loc_100cb154: // 0000:100cb154
    edi = edi;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000328;
    eax = memoryAGet32(ds, 0x1057deec);
    eax ^= ebp;
    memoryASet32(ss, ebp - 4, eax);
    memoryASet32(ss, ebp - 808, memoryAGet32(ss, ebp - 808) & 0x00000000);
    push32(ebx);
    push32(0x0000004c);
    eax = ebp - 804;
    push32(0x00000000);
    push32(eax);
    sub_100c8680();
    eax = ebp - 808;
    memoryASet32(ss, ebp - 728, eax);
    eax = ebp - 720;
    esp += 0x0000000c;
    memoryASet32(ss, ebp - 724, eax);
    memoryASet32(ss, ebp - 544, eax);
    memoryASet32(ss, ebp - 548, ecx);
    memoryASet32(ss, ebp - 552, edx);
    memoryASet32(ss, ebp - 556, ebx);
    memoryASet32(ss, ebp - 560, esi);
    memoryASet32(ss, ebp - 564, edi);
    memoryASet16(ss, ebp - 520, ss);
    memoryASet16(ss, ebp - 532, cs);
    memoryASet16(ss, ebp - 568, ds);
    memoryASet16(ss, ebp - 572, es);
    memoryASet16(ss, ebp - 576, fs);
    memoryASet16(ss, ebp - 580, gs);
    push32(flagAsReg32());
    memoryASet32(ss, ebp - 528, pop32());
    eax = memoryAGet32(ss, ebp + 0x4);
    ecx = ebp + 4;
    memoryASet32(ss, ebp - 720, 0x00010001);
    memoryASet32(ss, ebp - 536, eax);
    memoryASet32(ss, ebp - 524, ecx);
    ecx = memoryAGet32(ds, ecx - 4);
    memoryASet32(ss, ebp - 540, ecx);
    memoryASet32(ss, ebp - 808, 0xc0000417);
    memoryASet32(ss, ebp - 804, 0x00000001);
    memoryASet32(ss, ebp - 796, eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e610c), __LINE__, 0); // 0000:100cb230
    push32(0x00000000);
    ebx = eax;
    indirectCall(cs, memoryAGet32(ds, 0x100e61e4), __LINE__, 0); // 0000:100cb23a
    eax = ebp - 728;
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e6104), __LINE__, 0); // 0000:100cb247
    if (eax)
        goto loc_100cb25d;
    if (ebx)
        goto loc_100cb25d;
    push32(0x00000002);
    sub_100d5668();
    ecx = pop32();
loc_100cb25d: // 0000:100cb25d
    push32(0xc0000417);
    indirectCall(cs, memoryAGet32(ds, 0x100e6100), __LINE__, 0); // 0000:100cb262
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e60fc), __LINE__, 0); // 0000:100cb269
    ecx = memoryAGet32(ss, ebp - 4);
    ecx ^= ebp;
    ebx = pop32();
    sub_100cc203();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-828) // SEH removed (was stack_unbalanced, 0/-828)
    esp += 4; return;
loc_100cb27c: // 0000:100cb27c
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(memoryAGet32(ds, 0x10582140));
    sub_100d1046();
    ecx = pop32();
    if (!eax)
        goto loc_100cb294;
    esp = ebp; ebp = pop32();
    switch (eax)
    {
        case 0x1001f190: goto loc_1001f190;
        case 0x1001f1a0: goto loc_1001f1a0;
        case 0x00000000: break; // null vtable — no-op
        default: break; // any other vtable — CriticalSection is no-op in single-threaded emulator
        //default_disabled:
            stop("ind 0000:100cb292");
    }
loc_100cb294: // 0000:100cb294
    push32(0x00000002);
    sub_100d5668();
    ecx = pop32();
    ebp = pop32();
    goto loc_100cb154;
}
void sub_100cb56d() // 0000:100cb56d +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    if (memoryAGet32(ds, 0x10582164))
        goto loc_100cb58b;
    eax = memoryAGet32(ss, ebp + 0x8);
    ecx = eax - 97;
    if (ecx > 0x00000019)
        goto loc_100cb597;
    eax += 0xffffffe0;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100cb58b: // 0000:100cb58b
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100cb457();
    ecx = pop32();
    ecx = pop32();
loc_100cb597: // 0000:100cb597
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cb654() // 0000:100cb654 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    eax = ebp + 16;
    push32(eax);
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(0x100d57f2);
    sub_100cb5ea();
    esp += 0x00000010;
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cb826() // 0000:100cb826 +long +stackDrop12
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0xc);
    push32(esi);
    push32(edi);
    if (eax != 0x00000001)
        goto loc_100cb8b1;
    push32(eax);
    sub_100d0d0c();
    ecx = pop32();
    if (eax)
        goto loc_100cb847;
loc_100cb840: // 0000:100cb840
    eax = 0;
    goto loc_100cb955;
loc_100cb847: // 0000:100cb847
    sub_100d1449();
    if (eax)
        goto loc_100cb857;
loc_100cb850: // 0000:100cb850
    sub_100d0d3c();
    goto loc_100cb840;
loc_100cb857: // 0000:100cb857
    sub_100d6ebb();
    indirectCall(cs, memoryAGet32(ds, 0x100e6120), __LINE__, 0); // 0000:100cb85c
    memoryASet32(ds, 0x10583d58, eax);
    sub_100d6d84();
    memoryASet32(ds, 0x1058214c, eax);
    sub_100d67af();
    if ((int32_t)eax >= 0)
        goto loc_100cb881;
loc_100cb87a: // 0000:100cb87a
    sub_100d10f5();
    goto loc_100cb850;
loc_100cb881: // 0000:100cb881
    sub_100d6cc9();
    if ((int32_t)eax < 0)
        goto loc_100cb8aa;
    sub_100d6a51();
    if ((int32_t)eax < 0)
        goto loc_100cb8aa;
    push32(0x00000000);
    sub_100ce372();
    ecx = pop32();
    if (eax)
        goto loc_100cb8aa;
    memoryASet32(ds, 0x10582148, memoryAGet32(ds, 0x10582148) + 1);
    goto loc_100cb952;
loc_100cb8aa: // 0000:100cb8aa
    sub_100d6a03();
    goto loc_100cb87a;
loc_100cb8b1: // 0000:100cb8b1
    edi = 0;
    if (eax != edi)
        goto loc_100cb8e8;
    if ((int32_t)memoryAGet32(ds, 0x10582148) <= (int32_t)edi)
        goto loc_100cb840;
    memoryASet32(ds, 0x10582148, memoryAGet32(ds, 0x10582148) - 1);
    if (memoryAGet32(ds, 0x10582194) != edi)
        goto loc_100cb8d2;
    sub_100ce54f();
loc_100cb8d2: // 0000:100cb8d2
    if (memoryAGet32(ss, ebp + 0x10) != edi)
        goto loc_100cb952;
    sub_100d6a03();
    sub_100d10f5();
    sub_100d0d3c();
    goto loc_100cb952;
loc_100cb8e8: // 0000:100cb8e8
    if (eax != 0x00000002)
        goto loc_100cb946;
    sub_100d10c1();
    push32(0x00000214);
    push32(0x00000001);
    sub_100cbec3();
    esi = eax;
    ecx = pop32();
    ecx = pop32();
    if (esi == edi)
        goto loc_100cb840;
    push32(esi);
    push32(memoryAGet32(ds, 0x1057e3b8));
    push32(memoryAGet32(ds, 0x10582624));
    sub_100d1046();
    ecx = pop32();
    indirectCall(cs, eax, __LINE__, 0); // 0000:100cb91d
    if (!eax)
        goto loc_100cb93a;
    push32(edi);
    push32(esi);
    sub_100d1132();
    ecx = pop32();
    ecx = pop32();
    indirectCall(cs, memoryAGet32(ds, 0x100e60c4), __LINE__, 0); // 0000:100cb92c
    memoryASet32(ds, esi + 0x4, memoryAGet32(ds, esi + 0x4) | 0xffffffff);
    memoryASet32(ds, esi, eax);
    goto loc_100cb952;
loc_100cb93a: // 0000:100cb93a
    push32(esi);
    sub_100c91bc();
    ecx = pop32();
    goto loc_100cb840;
loc_100cb946: // 0000:100cb946
    if (eax != 0x00000003)
        goto loc_100cb952;
    push32(edi);
    sub_100d13db();
    ecx = pop32();
loc_100cb952: // 0000:100cb952
    eax = 0;
    eax++;
loc_100cb955: // 0000:100cb955
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 16;
}
void sub_100cba74() // 0000:100cba74 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    if (!eax)
        goto loc_100cba92;
    eax -= 0x00000008;
    if (memoryAGet32(ds, eax) != 0x0000dddd)
        goto loc_100cba92;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100cba92: // 0000:100cba92
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cbe7e() // 0000:100cbe7e +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    push32(edi);
    esi = 0;
loc_100cbe87: // 0000:100cbe87
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c8749();
    edi = eax;
    ecx = pop32();
    if (edi)
        goto loc_100cbebd;
    if (memoryAGet32(ds, 0x10582160) <= eax)
        goto loc_100cbebd;
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, 0x100e6058), __LINE__, 0); // 0000:100cbe9f
    eax = esi + 1000;
    if (eax <= memoryAGet32(ds, 0x10582160))
        goto loc_100cbeb6;
    eax |= 0xffffffff;
loc_100cbeb6: // 0000:100cbeb6
    esi = eax;
    if (eax != 0xffffffff)
        goto loc_100cbe87;
loc_100cbebd: // 0000:100cbebd
    eax = edi;
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cbec3() // 0000:100cbec3 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    push32(edi);
    esi = 0;
loc_100cbecc: // 0000:100cbecc
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100d7548();
    edi = eax;
    esp += 0x0000000c;
    if (edi)
        goto loc_100cbf09;
    if (memoryAGet32(ds, 0x10582160) <= eax)
        goto loc_100cbf09;
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, 0x100e6058), __LINE__, 0); // 0000:100cbeeb
    eax = esi + 1000;
    if (eax <= memoryAGet32(ds, 0x10582160))
        goto loc_100cbf02;
    eax |= 0xffffffff;
loc_100cbf02: // 0000:100cbf02
    esi = eax;
    if (eax != 0xffffffff)
        goto loc_100cbecc;
loc_100cbf09: // 0000:100cbf09
    eax = edi;
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cbf0f() // 0000:100cbf0f +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    push32(edi);
    esi = 0;
loc_100cbf18: // 0000:100cbf18
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100c924a();
    edi = eax;
    ecx = pop32();
    ecx = pop32();
    if (edi)
        goto loc_100cbf57;
    if (memoryAGet32(ss, ebp + 0xc) == eax)
        goto loc_100cbf57;
    if (memoryAGet32(ds, 0x10582160) <= eax)
        goto loc_100cbf57;
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, 0x100e6058), __LINE__, 0); // 0000:100cbf39
    eax = esi + 1000;
    if (eax <= memoryAGet32(ds, 0x10582160))
        goto loc_100cbf50;
    eax |= 0xffffffff;
loc_100cbf50: // 0000:100cbf50
    esi = eax;
    if (eax != 0xffffffff)
        goto loc_100cbf18;
loc_100cbf57: // 0000:100cbf57
    eax = edi;
    edi = pop32();
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cbfaf() // 0000:100cbfaf +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    ecx = 0;
loc_100cbfb9: // 0000:100cbfb9
    if (eax == memoryAGet32(ds, ecx * 8 + 0x1057dd48))
        goto loc_100cbfd5;
    ecx++;
    if (ecx < 0x0000002d)
        goto loc_100cbfb9;
    ecx = eax - 19;
    if (ecx > 0x00000011)
        goto loc_100cbfde;
    push32(0x0000000d);
    eax = pop32();
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100cbfd5: // 0000:100cbfd5
    eax = memoryAGet32(ds, ecx * 8 + 0x1057dd4c);
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100cbfde: // 0000:100cbfde
    eax += 0xffffff44;
    push32(0x0000000e);
    ecx = pop32();
    flags.carry = ecx < eax;
    eax = -flags.carry;
    eax &= ecx;
    eax += 0x00000008;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cc017() // 0000:100cc017 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    sub_100cc004();
    ecx = memoryAGet32(ss, ebp + 0x8);
    push32(ecx);
    memoryASet32(ds, eax, ecx);
    sub_100cbfaf();
    ecx = pop32();
    esi = eax;
    sub_100cbff1();
    memoryASet32(ds, eax, esi);
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cc0cb() // 0000:100cc0cb +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000328;
    eax = memoryAGet32(ds, 0x1057deec);
    eax ^= ebp;
    memoryASet32(ss, ebp - 4, eax);
    push32(esi);
    if (!(memoryAGet(ds, 0x1057dec0) & 0x01))
        goto loc_100cc0f2;
    push32(0x0000000a);
    sub_100d0db0();
    ecx = pop32();
loc_100cc0f2: // 0000:100cc0f2
    sub_100d7736();
    if (!eax)
        goto loc_100cc103;
    push32(0x00000016);
    sub_100d7743();
    ecx = pop32();
loc_100cc103: // 0000:100cc103
    if (!(memoryAGet(ds, 0x1057dec0) & 0x02))
        goto loc_100cc1da;
    memoryASet32(ss, ebp - 544, eax);
    memoryASet32(ss, ebp - 548, ecx);
    memoryASet32(ss, ebp - 552, edx);
    memoryASet32(ss, ebp - 556, ebx);
    memoryASet32(ss, ebp - 560, esi);
    memoryASet32(ss, ebp - 564, edi);
    memoryASet16(ss, ebp - 520, ss);
    memoryASet16(ss, ebp - 532, cs);
    memoryASet16(ss, ebp - 568, ds);
    memoryASet16(ss, ebp - 572, es);
    memoryASet16(ss, ebp - 576, fs);
    memoryASet16(ss, ebp - 580, gs);
    push32(flagAsReg32());
    memoryASet32(ss, ebp - 528, pop32());
    esi = memoryAGet32(ss, ebp + 0x4);
    eax = ebp + 4;
    memoryASet32(ss, ebp - 524, eax);
    memoryASet32(ss, ebp - 720, 0x00010001);
    memoryASet32(ss, ebp - 536, esi);
    eax = memoryAGet32(ds, eax - 4);
    push32(0x00000050);
    memoryASet32(ss, ebp - 540, eax);
    eax = ebp - 808;
    push32(0x00000000);
    push32(eax);
    sub_100c8680();
    eax = ebp - 808;
    esp += 0x0000000c;
    memoryASet32(ss, ebp - 728, eax);
    eax = ebp - 720;
    push32(0x00000000);
    memoryASet32(ss, ebp - 808, 0x40000015);
    memoryASet32(ss, ebp - 796, esi);
    memoryASet32(ss, ebp - 724, eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e61e4), __LINE__, 0); // 0000:100cc1c7
    eax = ebp - 728;
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e6104), __LINE__, 0); // 0000:100cc1d4
loc_100cc1da: // 0000:100cc1da
    push32(0x00000003);
    sub_100ce539();
    stop("breakpoint");
    edi = edi;
    push32(ebp);
    ebp = esp;
    ecx = memoryAGet32(ss, ebp + 0xc);
    eax = memoryAGet32(ds, 0x1057dec0);
    edx = memoryAGet32(ss, ebp + 0x8);
    edx &= memoryAGet32(ss, ebp + 0xc);
    ecx = ~ecx;
    ecx &= eax;
    ecx |= edx;
    memoryASet32(ds, 0x1057dec0, ecx);
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-820) // SEH removed (was stack_unbalanced, 0/-820)
    esp += 4;
}
void sub_100cc1e2() // 0000:100cc1e2 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    ecx = memoryAGet32(ss, ebp + 0xc);
    eax = memoryAGet32(ds, 0x1057dec0);
    edx = memoryAGet32(ss, ebp + 0x8);
    edx &= memoryAGet32(ss, ebp + 0xc);
    ecx = ~ecx;
    ecx &= eax;
    ecx |= edx;
    memoryASet32(ds, 0x1057dec0, ecx);
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cc27b() // 0000:100cc27b +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, esi + 0xbc);
    ebx = 0;
    push32(edi);
    if (eax == ebx)
        goto loc_100cc301;
    if (eax == 0x1057dd04)
        goto loc_100cc301;
    eax = memoryAGet32(ds, esi + 0xb0);
    if (eax == ebx)
        goto loc_100cc301;
    if (memoryAGet32(ds, eax) != ebx)
        goto loc_100cc301;
    eax = memoryAGet32(ds, esi + 0xb8);
    if (eax == ebx)
        goto loc_100cc2c8;
    if (memoryAGet32(ds, eax) != ebx)
        goto loc_100cc2c8;
    push32(eax);
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0xbc));
    sub_100d7bd3();
    ecx = pop32();
    ecx = pop32();
loc_100cc2c8: // 0000:100cc2c8
    eax = memoryAGet32(ds, esi + 0xb4);
    if (eax == ebx)
        goto loc_100cc2e9;
    if (memoryAGet32(ds, eax) != ebx)
        goto loc_100cc2e9;
    push32(eax);
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0xbc));
    sub_100d7b8e();
    ecx = pop32();
    ecx = pop32();
loc_100cc2e9: // 0000:100cc2e9
    push32(memoryAGet32(ds, esi + 0xb0));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0xbc));
    sub_100c91bc();
    ecx = pop32();
    ecx = pop32();
loc_100cc301: // 0000:100cc301
    eax = memoryAGet32(ds, esi + 0xc0);
    if (eax == ebx)
        goto loc_100cc34f;
    if (memoryAGet32(ds, eax) != ebx)
        goto loc_100cc34f;
    eax = memoryAGet32(ds, esi + 0xc4);
    eax -= 0x000000fe;
    push32(eax);
    sub_100c91bc();
    eax = memoryAGet32(ds, esi + 0xcc);
    edi = 0x00000080;
    eax -= edi;
    push32(eax);
    sub_100c91bc();
    eax = memoryAGet32(ds, esi + 0xd0);
    eax -= edi;
    push32(eax);
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0xc0));
    sub_100c91bc();
    esp += 0x00000010;
loc_100cc34f: // 0000:100cc34f
    edi = esi + 212;
    eax = memoryAGet32(ds, edi);
    if (eax == 0x1057ec30)
        goto loc_100cc375;
    if (memoryAGet32(ds, eax + 0xb4) != ebx)
        goto loc_100cc375;
    push32(eax);
    sub_100d79f9();
    push32(memoryAGet32(ds, edi));
    sub_100c91bc();
    ecx = pop32();
    ecx = pop32();
loc_100cc375: // 0000:100cc375
    edi = esi + 80;
    memoryASet32(ss, ebp + 0x8, 0x00000006);
loc_100cc37f: // 0000:100cc37f
    if (memoryAGet32(ds, edi - 8) == 0x1057e8e8)
        goto loc_100cc399;
    eax = memoryAGet32(ds, edi);
    if (eax == ebx)
        goto loc_100cc399;
    if (memoryAGet32(ds, eax) != ebx)
        goto loc_100cc399;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100cc399: // 0000:100cc399
    if (memoryAGet32(ds, edi - 4) == ebx)
        goto loc_100cc3b0;
    eax = memoryAGet32(ds, edi + 0x4);
    if (eax == ebx)
        goto loc_100cc3b0;
    if (memoryAGet32(ds, eax) != ebx)
        goto loc_100cc3b0;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100cc3b0: // 0000:100cc3b0
    edi += 0x00000010;
    memoryASet32(ss, ebp + 0x8, memoryAGet32(ss, ebp + 0x8) - 1);
    if (memoryAGet32(ss, ebp + 0x8))
        goto loc_100cc37f;
    push32(esi);
    sub_100c91bc();
    ecx = pop32();
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cc3c4() // 0000:100cc3c4 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    esi = memoryAGet32(ds, 0x100e6108);
    push32(edi);
    edi = memoryAGet32(ss, ebp + 0x8);
    push32(edi);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc3d6
    eax = memoryAGet32(ds, edi + 0xb0);
    if (!eax)
        goto loc_100cc3e5;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc3e3
loc_100cc3e5: // 0000:100cc3e5
    eax = memoryAGet32(ds, edi + 0xb8);
    if (!eax)
        goto loc_100cc3f2;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc3f0
loc_100cc3f2: // 0000:100cc3f2
    eax = memoryAGet32(ds, edi + 0xb4);
    if (!eax)
        goto loc_100cc3ff;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc3fd
loc_100cc3ff: // 0000:100cc3ff
    eax = memoryAGet32(ds, edi + 0xc0);
    if (!eax)
        goto loc_100cc40c;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc40a
loc_100cc40c: // 0000:100cc40c
    ebx = edi + 80;
    memoryASet32(ss, ebp + 0x8, 0x00000006);
loc_100cc416: // 0000:100cc416
    if (memoryAGet32(ds, ebx - 8) == 0x1057e8e8)
        goto loc_100cc428;
    eax = memoryAGet32(ds, ebx);
    if (!eax)
        goto loc_100cc428;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc426
loc_100cc428: // 0000:100cc428
    if (!memoryAGet32(ds, ebx - 4))
        goto loc_100cc438;
    eax = memoryAGet32(ds, ebx + 0x4);
    if (!eax)
        goto loc_100cc438;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc436
loc_100cc438: // 0000:100cc438
    ebx += 0x00000010;
    memoryASet32(ss, ebp + 0x8, memoryAGet32(ss, ebp + 0x8) - 1);
    if (memoryAGet32(ss, ebp + 0x8))
        goto loc_100cc416;
    eax = memoryAGet32(ds, edi + 0xd4);
    eax += 0x000000b4;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc44c
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-8) // SEH removed (was stack_unbalanced, 0/-8)
    esp += 4;
}
void sub_100cc453() // 0000:100cc453 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(edi);
    edi = memoryAGet32(ss, ebp + 0x8);
    if (!edi)
        goto loc_100cc4e7;
    push32(ebx);
    push32(esi);
    esi = memoryAGet32(ds, 0x100e6068);
    push32(edi);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc46d
    eax = memoryAGet32(ds, edi + 0xb0);
    if (!eax)
        goto loc_100cc47c;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc47a
loc_100cc47c: // 0000:100cc47c
    eax = memoryAGet32(ds, edi + 0xb8);
    if (!eax)
        goto loc_100cc489;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc487
loc_100cc489: // 0000:100cc489
    eax = memoryAGet32(ds, edi + 0xb4);
    if (!eax)
        goto loc_100cc496;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc494
loc_100cc496: // 0000:100cc496
    eax = memoryAGet32(ds, edi + 0xc0);
    if (!eax)
        goto loc_100cc4a3;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc4a1
loc_100cc4a3: // 0000:100cc4a3
    ebx = edi + 80;
    memoryASet32(ss, ebp + 0x8, 0x00000006);
loc_100cc4ad: // 0000:100cc4ad
    if (memoryAGet32(ds, ebx - 8) == 0x1057e8e8)
        goto loc_100cc4bf;
    eax = memoryAGet32(ds, ebx);
    if (!eax)
        goto loc_100cc4bf;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc4bd
loc_100cc4bf: // 0000:100cc4bf
    if (!memoryAGet32(ds, ebx - 4))
        goto loc_100cc4cf;
    eax = memoryAGet32(ds, ebx + 0x4);
    if (!eax)
        goto loc_100cc4cf;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc4cd
loc_100cc4cf: // 0000:100cc4cf
    ebx += 0x00000010;
    memoryASet32(ss, ebp + 0x8, memoryAGet32(ss, ebp + 0x8) - 1);
    if (memoryAGet32(ss, ebp + 0x8))
        goto loc_100cc4ad;
    eax = memoryAGet32(ds, edi + 0xd4);
    eax += 0x000000b4;
    push32(eax);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100cc4e3
    esi = pop32();
    ebx = pop32();
loc_100cc4e7: // 0000:100cc4e7
    eax = edi;
    edi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cc52a() // 0000:100cc52a +long
{ esp -= 4; eax = 0; esp += 4; } // _updatetlocinfoEx stub
void sub_100cd430() // 0000:100cd430 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    if (memoryAGet32(ds, 0x10582164))
        goto loc_100cd44e;
    eax = memoryAGet32(ss, ebp + 0x8);
    ecx = eax - 65;
    if (ecx > 0x00000019)
        goto loc_100cd45a;
    eax += 0x00000020;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100cd44e: // 0000:100cd44e
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100cd31b();
    ecx = pop32();
    ecx = pop32();
loc_100cd45a: // 0000:100cd45a
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cd580() // 0000:100cd580 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x0000000a);
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100d8064();
    esp += 0x0000000c;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cd596() // 0000:100cd596 +long
{
    esp -= 4;
    goto loc_100cd596;
loc_100cd580: // 0000:100cd580
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x0000000a);
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100d8064();
    esp += 0x0000000c;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100cd596: // 0000:100cd596
    edi = edi;
    push32(ebp);
    ebp = esp;
    esp = ebp; ebp = pop32();
    goto loc_100cd580;
}
void sub_100cd843() // 0000:100cd843 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100cd798();
    ecx = pop32();
    ecx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100ce243() // 0000:100ce243 +long
{ esp -= 4; uint32_t c = memoryAGet32(ss,esp+4); uint32_t sz = memoryAGet32(ss,esp+8); uint32_t t=c*sz;
  if(t>0x1000000) printf("  CALLOC BAD: c=0x%08x sz=0x%08x t=0x%08x esp=0x%08x\n", c, sz, t, esp);
  if(!t)t=1; eax=allocate(t); esp += 4; } // calloc stub
void sub_100ce283() // 0000:100ce283 +long
{ esp -= 4; eax = 0; esp += 4; } // CRT stub
void sub_100ce2b3() // 0000:100ce2b3 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    sub_100d0f5b();
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100d0db0();
    push32(memoryAGet32(ds, 0x1057df00));
    sub_100d1046();
    push32(0x000000ff);
    indirectCall(cs, eax, __LINE__, 0); // 0000:100ce2d5
    esp += 0x0000000c;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100ce2dc() // 0000:100ce2dc +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x103eff7c);
    indirectCall(cs, memoryAGet32(ds, 0x100e6130), __LINE__, 0); // 0000:100ce2e6
    if (!eax)
        goto loc_100ce305;
    push32(0x103eff6c);
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e61d4), __LINE__, 0); // 0000:100ce2f6
    if (!eax)
        goto loc_100ce305;
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, eax, __LINE__, 0); // 0000:100ce303
loc_100ce305: // 0000:100ce305
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_100ce331() // 0000:100ce331 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = eax;
    goto loc_100ce346;
loc_100ce33b: // 0000:100ce33b
    eax = memoryAGet32(ds, esi);
    if (!eax)
        goto loc_100ce343;
    indirectCall(cs, eax, __LINE__, 0); // 0000:100ce341
loc_100ce343: // 0000:100ce343
    esi += 0x00000004;
loc_100ce346: // 0000:100ce346
    if (esi < memoryAGet32(ss, ebp + 0x8))
        goto loc_100ce33b;
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100ce34e() // 0000:100ce34e +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    eax = 0;
    goto loc_100ce36a;
loc_100ce35b: // 0000:100ce35b
    if (eax)
        goto loc_100ce36f;
    ecx = memoryAGet32(ds, esi);
    if (!ecx)
        goto loc_100ce367;
    indirectCall(cs, ecx, __LINE__, 0); // 0000:100ce365
loc_100ce367: // 0000:100ce367
    esi += 0x00000004;
loc_100ce36a: // 0000:100ce36a
    if (esi < memoryAGet32(ss, ebp + 0xc))
        goto loc_100ce35b;
loc_100ce36f: // 0000:100ce36f
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100ce372() // 0000:100ce372 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    if (!memoryAGet32(ds, 0x103ef60c))
        goto loc_100ce399;
    push32(0x103ef60c);
    sub_100da610();
    ecx = pop32();
    if (!eax)
        goto loc_100ce399;
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, memoryAGet32(ds, 0x103ef60c), __LINE__, 0); // 0000:100ce392
    ecx = pop32();
loc_100ce399: // 0000:100ce399
    sub_100cfc53();
    push32(0x100e6438);
    push32(0x100e641c);
    sub_100ce34e();
    ecx = pop32();
    ecx = pop32();
    if (eax)
        goto loc_100ce3f5;
    push32(0x100d6ee1);
    sub_100ca86a();
    eax = 0x100e62e8;
    memoryASet32(ds, esp, 0x100e6418);
    sub_100ce331();
    ecx = pop32();
    if (!memoryAGet32(ds, 0x10583d54))
        goto loc_100ce3f3;
    push32(0x10583d54);
    sub_100da610();
    ecx = pop32();
    if (!eax)
        goto loc_100ce3f3;
    push32(0x00000000);
    push32(0x00000002);
    push32(0x00000000);
    indirectCall(cs, memoryAGet32(ds, 0x10583d54), __LINE__, 0); // 0000:100ce3ed
loc_100ce3f3: // 0000:100ce3f3
    eax = 0;
loc_100ce3f5: // 0000:100ce3f5
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100ce523() // 0000:100ce523 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x00000000);
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100ce3f7();
    esp += 0x0000000c;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100ce539() // 0000:100ce539 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x00000000);
    push32(0x00000001);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100ce3f7();
    esp += 0x0000000c;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100ce5e8() // 0000:100ce5e8 +long — __CIsinh: sinh(ST(0))
{
    esp -= 4;
    setst(0, sinh(st(0)));
    esp += 4;
}
void sub_100ce9b0() // 0000:100ce9b0 +long
{
    esp -= 4;
    if (cl >= 0x40)
        goto loc_100ce9cb;
    if (cl >= 0x20)
        goto loc_100ce9c0;
    { uint64_t v = ((uint64_t)edx << 32) | eax; eax = (uint32_t)(v >> (cl & 31)); }
    edx = sar32(edx, cl);
    esp += 4; return;
loc_100ce9c0: // 0000:100ce9c0
    eax = edx;
    edx = sar32(edx, 0x1f);
    cl &= 0x1f;
    eax = sar32(eax, cl);
    esp += 4; return;
loc_100ce9cb: // 0000:100ce9cb
    edx = sar32(edx, 0x1f);
    eax = edx;
    esp += 4;
}
void sub_100ceb9a() // 0000:100ceb9a +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    eax = 0x1057df30;
    if (esi < eax)
        goto loc_100cebce;
    if (esi > 0x1057e190)
        goto loc_100cebce;
    ecx = esi;
    ecx -= eax;
    ecx = sar32(ecx, 0x05);
    ecx += 0x00000010;
    push32(ecx);
    sub_100d0027();
    memoryASet32(ds, esi + 0xc, memoryAGet32(ds, esi + 0xc) | 0x00008000);
    ecx = pop32();
    goto loc_100cebd8;
loc_100cebce: // 0000:100cebce
    esi += 0x00000020;
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, 0x100e61dc), __LINE__, 0); // 0000:100cebd2
loc_100cebd8: // 0000:100cebd8
    esi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_100cebdb() { printf("FATAL: unimplemented CRT function sub_100cebdb called\n"); abort(); }
void sub_100cec0d() // 0000:100cec0d +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    ecx = 0x1057df30;
    if (eax < ecx)
        goto loc_100cec3d;
    if (eax > 0x1057e190)
        goto loc_100cec3d;
    memoryASet32(ds, eax + 0xc, memoryAGet32(ds, eax + 0xc) & 0xffff7fff);
    eax -= ecx;
    eax = sar32(eax, 0x05);
    eax += 0x00000010;
    push32(eax);
    sub_100cff4d();
    ecx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4; return; // reverted: ebp-reset exit needs only +4
loc_100cec3d: // 0000:100cec3d
    eax += 0x00000020;
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e61d8), __LINE__, 0); // 0000:100cec41
    esp = ebp; ebp = pop32();
    // SEH fixed (was stack_unbalanced, 0/-4) // SEH fixed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_100cec49() { printf("FATAL: unimplemented CRT function sub_100cec49 called\n"); abort(); }
void sub_100cee5c() // 0000:100cee5c +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet32(ds, esi + 0xc);
    ecx = eax;
    cl &= 0x03;
    ebx = 0;
    if (cl != 0x02)
        goto loc_100ceeb5;
    if (!(eax & 0x00000108))
        goto loc_100ceeb5;
    eax = memoryAGet32(ds, esi + 0x8);
    push32(edi);
    edi = memoryAGet32(ds, esi);
    edi -= eax;
    if ((int32_t)edi <= 0)
        goto loc_100ceeb4;
    push32(edi);
    push32(eax);
    push32(esi);
    sub_100d85e3();
    ecx = pop32();
    push32(eax);
    sub_100db656();
    esp += 0x0000000c;
    if (eax != edi)
        goto loc_100ceead;
    eax = memoryAGet32(ds, esi + 0xc);
    if ((int8_t)al >= 0)
        goto loc_100ceeb4;
    eax &= 0xfffffffd;
    memoryASet32(ds, esi + 0xc, eax);
    goto loc_100ceeb4;
loc_100ceead: // 0000:100ceead
    memoryASet32(ds, esi + 0xc, memoryAGet32(ds, esi + 0xc) | 0x00000020);
    ebx |= 0xffffffff;
loc_100ceeb4: // 0000:100ceeb4
    edi = pop32();
loc_100ceeb5: // 0000:100ceeb5
    eax = memoryAGet32(ds, esi + 0x8);
    memoryASet32(ds, esi + 0x4, memoryAGet32(ds, esi + 0x4) & 0x00000000);
    memoryASet32(ds, esi, eax);
    esi = pop32();
    eax = ebx;
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cf161() // 0000:100cf161 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100cf042();
    esp += 0x0000000c;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cfe3c() // 0000:100cfe3c +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000018;
    eax = 0;
    push32(ebx);
    memoryASet32(ss, ebp - 4, eax);
    memoryASet32(ss, ebp - 12, eax);
    memoryASet32(ss, ebp - 8, eax);
    push32(ebx);
    push32(flagAsReg32());
    eax = pop32();
    ecx = eax;
    eax ^= 0x00200000;
    push32(eax);
    flagsFromReg32(pop32());
    push32(flagAsReg32());
    edx = pop32();
    edx -= ecx;
    if (!edx)
        goto loc_100cfe81;
    push32(ecx);
    flagsFromReg32(pop32());
    eax = 0;
    eax = 0; ebx = 0; ecx = 0; edx = 0; // cpuid stub
    memoryASet32(ss, ebp - 12, eax);
    memoryASet32(ss, ebp - 24, ebx);
    memoryASet32(ss, ebp - 20, edx);
    memoryASet32(ss, ebp - 16, ecx);
    eax = 0x00000001;
    eax = 0; ebx = 0; ecx = 0; edx = 0; // cpuid stub
    memoryASet32(ss, ebp - 4, edx);
    memoryASet32(ss, ebp - 8, eax);
loc_100cfe81: // 0000:100cfe81
    ebx = pop32();
    if (!(memoryAGet32(ss, ebp - 4) & 0x04000000))
        goto loc_100cfe99;
    sub_100cfdec();
    if (!eax)
        goto loc_100cfe99;
    eax = 0;
    eax++;
    goto loc_100cfe9b;
loc_100cfe99: // 0000:100cfe99
    eax = 0;
loc_100cfe9b: // 0000:100cfe9b
    ebx = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-28) // SEH removed (was stack_unbalanced, 0/-28)
    esp += 4;
}
void sub_100cff4d() // 0000:100cff4d +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    push32(memoryAGet32(ds, eax * 8 + 0x1057e1d8));
    indirectCall(cs, memoryAGet32(ds, 0x100e61d8), __LINE__, 0); // 0000:100cff5c
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_100cff64() // 0000:100cff64 +long
{ esp -= 4; eax = 0; esp += 4; } // _unlock stub stub // _unlock stub (no-op)
void sub_100d0027() // 0000:100d0027 +long
{ esp -= 4; eax = 0; esp += 4; } // _lock stub stub // _lock stub (no-op)
void sub_100d005a() // 0000:100d005a +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    ecx = memoryAGet32(ds, 0x10582d10);
    eax = memoryAGet32(ds, 0x10582d14);
    ecx = (int32_t)ecx * (int32_t)0x00000014;
    ecx += eax;
    goto loc_100d0082;
loc_100d0071: // 0000:100d0071
    edx = memoryAGet32(ss, ebp + 0x8);
    edx -= memoryAGet32(ds, eax + 0xc);
    if (edx < 0x00100000)
        goto loc_100d0088;
    eax += 0x00000014;
loc_100d0082: // 0000:100d0082
    if (eax < ecx)
        goto loc_100d0071;
    eax = 0;
loc_100d0088: // 0000:100d0088
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d0b20() // 0000:100d0b20 +long — __SEH_prolog4 (no exceptions in this port)
{
    // Stack at entry: [esp]=synthetic, [esp+4]=handler, [esp+8]=localSize, [esp+12]=caller_synthetic
    esp -= 4; // synthetic
    uint32_t _handler = memoryAGet32(ss, esp + 4);
    uint32_t _localSize = memoryAGet32(ss, esp + 8);
    // DON'T consume args — they stay on stack as part of the frame (matches real x86)
    // Set up ebp frame: push ebp on top of the synthetic slot
    push32(ebp);
    ebp = esp;
    // Now: [ebp+0]=saved_ebp, [ebp+4]=prolog_synthetic, [ebp+8]=handler, [ebp+12]=localSize
    push32(0xFFFFFFFF);  // [ebp-4] SEH state
    push32(_handler);    // [ebp-8] SEH handler
    push32(0);           // [ebp-12] fs:[0] chain
    esp -= _localSize;   // locals
    push32(ebx);
    push32(esi);
    push32(edi);
    memoryASet32(ss, ebp - 4, 0x12345678); // security cookie
}
void sub_100d0b65() // 0000:100d0b65 +long — __SEH_epilog4
{
    // Restore saved registers and frame pointer.
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;        // restore to saved_ebp location
    ebp = pop32();    // restore ebp; esp now at prolog's synthetic slot
    // Skip: prolog_synthetic(4) + handler(4) + localSize(4)
    // The caller's own `esp += 4` then completes the return.
    esp += 12;
}
void sub_100d0d0c() // 0000:100d0d0c +long
{ esp -= 4; eax = 1; esp += 4; } // __heap_init stub
void sub_100d0f94() // 0000:100d0f94 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, 0x10582614, eax);
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d0fa3() // 0000:100d0fa3 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(memoryAGet32(ds, 0x10582614));
    sub_100d1046();
    ecx = pop32();
    if (!eax)
        goto loc_100d0fc7;
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, eax, __LINE__, 0); // 0000:100d0fbb
    ecx = pop32();
    if (!eax)
        goto loc_100d0fc7;
    eax = 0;
    eax++;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100d0fc7: // 0000:100d0fc7
    eax = 0;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d0fcb() // 0000:100d0fcb +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    push32(memoryAGet32(ds, 0x1057e3bc));
    esi = memoryAGet32(ds, 0x100e6150);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100d0fdd
    if (!eax)
        goto loc_100d1004;
    eax = memoryAGet32(ds, 0x1057e3b8);
    if (eax == 0xffffffff)
        goto loc_100d1004;
    push32(eax);
    push32(memoryAGet32(ds, 0x1057e3bc));
    indirectCall(cs, esi, __LINE__, 0); // 0000:100d0ff4
    indirectCall(cs, eax, __LINE__, 0); // 0000:100d0ff6
    if (!eax)
        goto loc_100d1004;
    eax = memoryAGet32(ds, eax + 0x1f8);
    goto loc_100d102b;
loc_100d1004: // 0000:100d1004
    esi = 0x103f05fc;
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, 0x100e6130), __LINE__, 0); // 0000:100d100a
    if (eax)
        goto loc_100d101f;
    push32(esi);
    sub_100ce283();
    ecx = pop32();
    if (!eax)
        goto loc_100d1037;
loc_100d101f: // 0000:100d101f
    push32(0x103f05ec);
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e61d4), __LINE__, 0); // 0000:100d1025
loc_100d102b: // 0000:100d102b
    if (!eax)
        goto loc_100d1037;
    push32(memoryAGet32(ss, ebp + 0x8));
    indirectCall(cs, eax, __LINE__, 0); // 0000:100d1032
    memoryASet32(ss, ebp + 0x8, eax);
loc_100d1037: // 0000:100d1037
    eax = memoryAGet32(ss, ebp + 0x8);
    esi = pop32();
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-8) // SEH removed (was stack_unbalanced, 0/-8)
    esp += 4;
}
void sub_100d103d() // 0000:100d103d +long
{ esp -= 4; eax = memoryAGet32(ss, esp+4); esp += 4; } // _decode_pointer: identity
void sub_100d1046() // 0000:100d1046 +long
{ esp -= 4; eax = memoryAGet32(ss, esp+4); esp += 4; } // _encode_pointer: identity
void sub_100d1219() // 0000:100d1219 +long — __getptd_noexit (thread-local storage)
{
    static uint32_t getptdptr = 0;
    // used by rand, eax+0x14 = rand seed
    if (getptdptr == 0)
        getptdptr = allocate(32);
    eax = getptdptr;
//
//
//    esp -= 4;
//    static bool _warned = false;
//    if (!_warned) { _warned = true; printf("WARNING: __getptd_noexit stub called (returns 0)\n"); }
//    eax = 0;
//    esp += 4;
}
void sub_100d1292() // 0000:100d1292 +long
{
    esp -= 4;
    sub_100d1219(); // __getptd_noexit
    esp += 4;
}
void sub_100d13db() // 0000:100d13db +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    if (memoryAGet32(ds, 0x1057e3b8) == 0xffffffff)
        goto loc_100d1434;
    if (memoryAGet32(ss, ebp + 0x8))
        goto loc_100d1416;
    push32(esi);
    push32(memoryAGet32(ds, 0x1057e3bc));
    esi = memoryAGet32(ds, 0x100e6150);
    indirectCall(cs, esi, __LINE__, 0); // 0000:100d13fc
    if (!eax)
        goto loc_100d1415;
    push32(memoryAGet32(ds, 0x1057e3b8));
    push32(memoryAGet32(ds, 0x1057e3bc));
    indirectCall(cs, esi, __LINE__, 0); // 0000:100d140e
    indirectCall(cs, eax, __LINE__, 0); // 0000:100d1410
    memoryASet32(ss, ebp + 0x8, eax);
loc_100d1415: // 0000:100d1415
    esi = pop32();
loc_100d1416: // 0000:100d1416
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x1057e3b8));
    push32(memoryAGet32(ds, 0x10582624));
    sub_100d1046();
    ecx = pop32();
    indirectCall(cs, eax, __LINE__, 0); // 0000:100d142a
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100d12ac();
loc_100d1434: // 0000:100d1434
    eax = memoryAGet32(ds, 0x1057e3bc);
    if (eax == 0xffffffff)
        goto loc_100d1447;
    push32(0x00000000);
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e6158), __LINE__, 0); // 0000:100d1441
loc_100d1447: // 0000:100d1447
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d1449() // 0000:100d1449 +long
{ esp -= 4; eax = 1; esp += 4; } // __mtinit stub
void sub_100d1be7() // 0000:100d1be7 +long
{ esp -= 4; eax = 0; esp += 4; } // __setmbcp stub
void sub_100d2e6c() // 0000:100d2e6c +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, 0x10582674, eax);
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d2ea9() // 0000:100d2ea9 +long — __libm_sse2_pow_precise
{ esp -= 4; setst(1, pow(st(1), st(0))); fppop(); esp += 4; }
void sub_100d3c00() // 0000:100d3c00 +long
{ esp -= 4; if(fpuinsns::fppos>0) fpuinsns::fppop(); eax=0; esp += 4; } // float classifier stub
void sub_100d3c67() // 0000:100d3c67 +long
{
    esp -= 4;
    if (memoryAGet(ds, edx + 0xe) != 0x05)
        goto loc_100d3c7e;
    bx = memoryAGet16(ss, ebp - 164);
    bh |= 0x02;
    bh &= 0xfe;
    bl = 0x3f;
    goto loc_100d3c82;
loc_100d3c7e: // 0000:100d3c7e
    bx = 0x133f;
loc_100d3c82: // 0000:100d3c82
    memoryASet16(ss, ebp - 162, bx);
    fldcw(memoryAGet16(ss, ebp - 162));
    ebx = 0x1057ea5c;
    fxam(); // fxam fixed
    memoryASet32(ss, ebp - 148, edx);
    memoryASet16(ss, ebp - 160, fnstsw());
    memoryASet(ss, ebp - 144, 0x00);
    fxchst2(0, 1);
    cl = memoryAGet(ss, ebp - 159);
    fxam(); // fxam fixed
    memoryASet16(ss, ebp - 160, fnstsw());
    fxchst2(0, 1);
    ch = memoryAGet(ss, ebp - 159);
    ch <<= 1;
    ch = sar8(ch, 0x01);
    ch = rol8(ch, 0x01);
    al = ch;
    al &= 0x0f;
    al = memoryAGet(ds, bx + al);
    ah = al;
    cl <<= 1;
    cl = sar8(cl, 0x01);
    cl = rol8(cl, 0x01);
    al = cl;
    al &= 0x0f;
    al = memoryAGet(ds, bx + al);
    ah <<= 1;
    ah <<= 1;
    al |= ah;
    eax = (int8_t)al;
    ecx &= 0x00000404;
    ebx = edx;
    ebx += eax;
    ebx += 0x00000010;
    indirectJump(cs, memoryAGet32(ds, ebx), 0x0000, 0x100d3cf1); return; // 0000:100d3cf1
}
void sub_100d3e75() // 0000:100d3e75 +long +returnZero
{
    esp -= 4;
    eax = memoryAGet32(ds, edx + 0x4);
    eax &= 0x7ff00000;
    if (eax == 0x7ff00000)
        goto loc_100d3e87;
    fld64(memoryAGet64(ds, edx));
    flags.zero = eax == 0x7ff00000;
    esp += 4; return;
loc_100d3e87: // 0000:100d3e87
    eax = memoryAGet32(ds, edx + 0x4);
    esp -= 0x0000000a;
    eax |= 0x7fff0000;
    memoryASet32(ds, esp + 0x6, eax);
    eax = memoryAGet32(ds, edx + 0x4);
    ecx = memoryAGet32(ds, edx);
    eax = (eax << 11) | (ecx >> 21); // shld fixed
    ecx <<= 11;
    memoryASet32(ds, esp + 0x4, eax);
    memoryASet32(ds, esp, ecx);
    fld80(memoryAGet80(ds, esp));
    esp += 0x0000000a;
    flags.zero = !(eax & 0x00000000);
    eax = memoryAGet32(ds, edx + 0x4);
    esp += 4;
}
void sub_100d4022() // 0000:100d4022 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    fldz();
    push32(esi);
    fcom64(memoryAGet64(ss, ebp + 0x8));
    edx = 0;
    esi = 0;
    ax = fnstsw();
    fld64(memoryAGet64(ss, ebp + 0x8));
    if (ah & 0x41)
        goto loc_100d403d;
    fchs();
loc_100d403d: // 0000:100d403d
    eax = 0x7ff00000;
    ecx = 0xfff00000;
    if (memoryAGet32(ss, ebp + 0x14) != eax)
        goto loc_100d4089;
    if (memoryAGet32(ss, ebp + 0x10) != edx)
        goto loc_100d40d0;
    fld1();
    fcomst(1);
    ax = fnstsw();
    if (!(parityOdd(ah, 0x05)))
        goto loc_100d406d;
    fstpst(2);
    fstpst(1);
loc_100d4060: // 0000:100d4060
    fstpst(0);
    fld64(memoryAGet64(ds, 0x1057eef0));
    goto loc_100d414e;
loc_100d406d: // 0000:100d406d
    fcomst(1);
    ax = fnstsw();
    fstpst(1);
    flags.zero = !(ah & 0x41);
    eax = memoryAGet32(ss, ebp + 0x18);
    if (!flags.zero)
        goto loc_100d4082;
    fstpst(0);
    goto loc_100d4151;
loc_100d4082: // 0000:100d4082
    fstpst(1);
    goto loc_100d4151;
loc_100d4089: // 0000:100d4089
    if (memoryAGet32(ss, ebp + 0x14) != ecx)
        goto loc_100d40d0;
    if (memoryAGet32(ss, ebp + 0x10) != edx)
        goto loc_100d40d0;
    fld1();
    fcomst(1);
    ax = fnstsw();
    if (!(parityOdd(ah, 0x05)))
        goto loc_100d40a7;
    fstpst(0);
    fstpst(0);
    goto loc_100d414e;
loc_100d40a7: // 0000:100d40a7
    fstpst(2);
    fcompp();
    ax = fnstsw();
    flags.parity = !(parityOdd(ah, 0x05));
    eax = memoryAGet32(ss, ebp + 0x18);
    if (flags.parity)
        goto loc_100d40c0;
    fld64(memoryAGet64(ds, 0x1057eef0));
    goto loc_100d4151;
loc_100d40c0: // 0000:100d40c0
    fld64(memoryAGet64(ds, 0x1057eef8));
    esi = 0;
    memoryASet64(ds, eax, fstp64());
    esi++;
    goto loc_100d415d;
loc_100d40d0: // 0000:100d40d0
    fstpst(0);
    if (memoryAGet32(ss, ebp + 0xc) != eax)
        goto loc_100d40fd;
    if (memoryAGet32(ss, ebp + 0x8) != edx)
        goto loc_100d415b;
    fcom64(memoryAGet64(ss, ebp + 0x10));
    ax = fnstsw();
    if (parityOdd(ah, 0x05))
        goto loc_100d4060;
    fcom64(memoryAGet64(ss, ebp + 0x10));
    ax = fnstsw();
    flags.zero = !(ah & 0x41);
    eax = memoryAGet32(ss, ebp + 0x18);
    if (flags.zero)
        goto loc_100d4151;
    fstpst(0);
    fld1();
    goto loc_100d4151;
loc_100d40fd: // 0000:100d40fd
    fstpst(0);
    if (memoryAGet32(ss, ebp + 0xc) != ecx)
        goto loc_100d415d;
    if (memoryAGet32(ss, ebp + 0x8) != edx)
        goto loc_100d415d;
    fld64(memoryAGet64(ss, ebp + 0x10));
    push32(ecx);
    push32(ecx);
    memoryASet64(ds, esp, fstp64());
    sub_100d3fbc();
    fldz();
    ecx = pop32();
    fcom64(memoryAGet64(ss, ebp + 0x10));
    ecx = pop32();
    ecx = eax;
    ax = fnstsw();
    if (!(parityOdd(ah, 0x05)))
        goto loc_100d4137;
    fstpst(0);
    fld64(memoryAGet64(ds, 0x1057eef0));
    if (ecx != 0x00000001)
        goto loc_100d414e;
    fchs();
    goto loc_100d414e;
loc_100d4137: // 0000:100d4137
    fcom64(memoryAGet64(ss, ebp + 0x10));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_100d4155;
    if (ecx != 0x00000001)
        goto loc_100d414e;
    fstpst(0);
    fld64(memoryAGet64(ds, 0x1057ef10));
loc_100d414e: // 0000:100d414e
    eax = memoryAGet32(ss, ebp + 0x18);
loc_100d4151: // 0000:100d4151
    memoryASet64(ds, eax, fstp64());
    goto loc_100d415d;
loc_100d4155: // 0000:100d4155
    fstpst(0);
    fld1();
    goto loc_100d414e;
loc_100d415b: // 0000:100d415b
    fstpst(0);
loc_100d415d: // 0000:100d415d
    eax = esi;
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d5500() // 0000:100d5500 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    ecx = memoryAGet32(ss, ebp + 0x8);
    push32(ebx);
    ebx = 0;
    push32(esi);
    push32(edi);
    if (ecx == ebx)
        goto loc_100d5518;
    edi = memoryAGet32(ss, ebp + 0xc);
    if (edi > ebx)
        goto loc_100d5533;
loc_100d5518: // 0000:100d5518
    sub_100cbff1();
    push32(0x00000016);
    esi = pop32();
    memoryASet32(ds, eax, esi);
loc_100d5522: // 0000:100d5522
    push32(ebx);
    push32(ebx);
    push32(ebx);
    push32(ebx);
    push32(ebx);
    sub_100cb27c();
    esp += 0x00000014;
    eax = esi;
    goto loc_100d5563;
loc_100d5533: // 0000:100d5533
    esi = memoryAGet32(ss, ebp + 0x10);
    if (esi != ebx)
        goto loc_100d553e;
    memoryASet(ds, ecx, bl);
    goto loc_100d5518;
loc_100d553e: // 0000:100d553e
    edx = ecx;
loc_100d5540: // 0000:100d5540
    al = memoryAGet(ds, esi);
    memoryASet(ds, edx, al);
    edx++;
    esi++;
    if (al == bl)
        goto loc_100d554d;
    edi--;
    if (edi)
        goto loc_100d5540;
loc_100d554d: // 0000:100d554d
    if (edi != ebx)
        goto loc_100d5561;
    memoryASet(ds, ecx, bl);
    sub_100cbff1();
    push32(0x00000022);
    ecx = pop32();
    memoryASet32(ds, eax, ecx);
    esi = ecx;
    goto loc_100d5522;
loc_100d5561: // 0000:100d5561
    eax = 0;
loc_100d5563: // 0000:100d5563
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d56a8() // 0000:100d56a8 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100d5670();
    ecx = pop32();
    ecx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d67af() // 0000:100d67af +long
{ esp -= 4; eax = 0; esp += 4; } // __ioinit stub
void sub_100d6a51() // 0000:100d6a51 +long
{ esp -= 4; eax = 0; esp += 4; } // __setenvp stub
void sub_100d6b2f() // 0000:100d6b2f +long
{ esp -= 4; eax = 0; esp += 4; } // _parse_cmdline stub
void sub_100d6cc9() // 0000:100d6cc9 +long
{ esp -= 4; eax = 0; esp += 4; } // __setargv stub
void sub_100d6d84() // 0000:100d6d84 +long
{ esp -= 4; eax = 0; esp += 4; } // __crtGetEnvironmentStringsA stub
void sub_100d6ebb() // 0000:100d6ebb +long — __RTC_Initialize (genuinely empty on Windows too)
{ esp -= 4; esp += 4; }
void sub_100d76e1() // 0000:100d76e1 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, 0x10582798, eax);
    memoryASet32(ds, 0x1058279c, eax);
    memoryASet32(ds, 0x105827a0, eax);
    memoryASet32(ds, 0x105827a4, eax);
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d76ff() // 0000:100d76ff +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    ecx = memoryAGet32(ds, 0x1057ec2c);
    push32(esi);
loc_100d770e: // 0000:100d770e
    if (memoryAGet32(ds, eax + 0x4) == edx)
        goto loc_100d7722;
    esi = ecx;
    esi = (int32_t)esi * (int32_t)0x0000000c;
    esi += memoryAGet32(ss, ebp + 0x8);
    eax += 0x0000000c;
    if (eax < esi)
        goto loc_100d770e;
loc_100d7722: // 0000:100d7722
    ecx = (int32_t)ecx * (int32_t)0x0000000c;
    ecx += memoryAGet32(ss, ebp + 0x8);
    esi = pop32();
    if (eax >= ecx)
        goto loc_100d7732;
    if (memoryAGet32(ds, eax + 0x4) == edx)
        goto loc_100d7734;
loc_100d7732: // 0000:100d7732
    eax = 0;
loc_100d7734: // 0000:100d7734
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d79f9() // 0000:100d79f9 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    if (!esi)
        goto loc_100d7b8b;
    push32(memoryAGet32(ds, esi + 0x4));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x8));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0xc));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x10));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x14));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x18));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x20));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x24));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x28));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x2c));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x30));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x34));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x1c));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x38));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x3c));
    sub_100c91bc();
    esp += 0x00000040;
    push32(memoryAGet32(ds, esi + 0x40));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x44));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x48));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x4c));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x50));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x54));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x58));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x5c));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x60));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x64));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x68));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x6c));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x70));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x74));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x78));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x7c));
    sub_100c91bc();
    esp += 0x00000040;
    push32(memoryAGet32(ds, esi + 0x80));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x84));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x88));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x8c));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x90));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x94));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x98));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0x9c));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0xa0));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0xa4));
    sub_100c91bc();
    push32(memoryAGet32(ds, esi + 0xa8));
    sub_100c91bc();
    esp += 0x0000002c;
loc_100d7b8b: // 0000:100d7b8b
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d7b8e() // 0000:100d7b8e +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    if (!esi)
        goto loc_100d7bd0;
    eax = memoryAGet32(ds, esi);
    if (eax == memoryAGet32(ds, 0x1057dd04))
        goto loc_100d7bac;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100d7bac: // 0000:100d7bac
    eax = memoryAGet32(ds, esi + 0x4);
    if (eax == memoryAGet32(ds, 0x1057dd08))
        goto loc_100d7bbe;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100d7bbe: // 0000:100d7bbe
    esi = memoryAGet32(ds, esi + 0x8);
    if (esi == memoryAGet32(ds, 0x1057dd0c))
        goto loc_100d7bd0;
    push32(esi);
    sub_100c91bc();
    ecx = pop32();
loc_100d7bd0: // 0000:100d7bd0
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d7bd3() // 0000:100d7bd3 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    if (!esi)
        goto loc_100d7c5e;
    eax = memoryAGet32(ds, esi + 0xc);
    if (eax == memoryAGet32(ds, 0x1057dd10))
        goto loc_100d7bf2;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100d7bf2: // 0000:100d7bf2
    eax = memoryAGet32(ds, esi + 0x10);
    if (eax == memoryAGet32(ds, 0x1057dd14))
        goto loc_100d7c04;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100d7c04: // 0000:100d7c04
    eax = memoryAGet32(ds, esi + 0x14);
    if (eax == memoryAGet32(ds, 0x1057dd18))
        goto loc_100d7c16;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100d7c16: // 0000:100d7c16
    eax = memoryAGet32(ds, esi + 0x18);
    if (eax == memoryAGet32(ds, 0x1057dd1c))
        goto loc_100d7c28;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100d7c28: // 0000:100d7c28
    eax = memoryAGet32(ds, esi + 0x1c);
    if (eax == memoryAGet32(ds, 0x1057dd20))
        goto loc_100d7c3a;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100d7c3a: // 0000:100d7c3a
    eax = memoryAGet32(ds, esi + 0x20);
    if (eax == memoryAGet32(ds, 0x1057dd24))
        goto loc_100d7c4c;
    push32(eax);
    sub_100c91bc();
    ecx = pop32();
loc_100d7c4c: // 0000:100d7c4c
    esi = memoryAGet32(ds, esi + 0x24);
    if (esi == memoryAGet32(ds, 0x1057dd28))
        goto loc_100d7c5e;
    push32(esi);
    sub_100c91bc();
    ecx = pop32();
loc_100d7c5e: // 0000:100d7c5e
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d7c61() // 0000:100d7c61 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    push32(ebx);
    ebx = 0;
    push32(esi);
    push32(edi);
    if (eax == ebx)
        goto loc_100d7c79;
    edi = memoryAGet32(ss, ebp + 0xc);
    if (edi > ebx)
        goto loc_100d7c94;
loc_100d7c79: // 0000:100d7c79
    sub_100cbff1();
    push32(0x00000016);
    esi = pop32();
    memoryASet32(ds, eax, esi);
loc_100d7c83: // 0000:100d7c83
    push32(ebx);
    push32(ebx);
    push32(ebx);
    push32(ebx);
    push32(ebx);
    sub_100cb27c();
    esp += 0x00000014;
    eax = esi;
    goto loc_100d7cd0;
loc_100d7c94: // 0000:100d7c94
    esi = memoryAGet32(ss, ebp + 0x10);
    if (esi != ebx)
        goto loc_100d7c9f;
loc_100d7c9b: // 0000:100d7c9b
    memoryASet(ds, eax, bl);
    goto loc_100d7c79;
loc_100d7c9f: // 0000:100d7c9f
    edx = eax;
loc_100d7ca1: // 0000:100d7ca1
    if (memoryAGet(ds, edx) == bl)
        goto loc_100d7ca9;
    edx++;
    edi--;
    if (edi)
        goto loc_100d7ca1;
loc_100d7ca9: // 0000:100d7ca9
    if (edi == ebx)
        goto loc_100d7c9b;
loc_100d7cad: // 0000:100d7cad
    cl = memoryAGet(ds, esi);
    memoryASet(ds, edx, cl);
    edx++;
    esi++;
    if (cl == bl)
        goto loc_100d7cba;
    edi--;
    if (edi)
        goto loc_100d7cad;
loc_100d7cba: // 0000:100d7cba
    if (edi != ebx)
        goto loc_100d7cce;
    memoryASet(ds, eax, bl);
    sub_100cbff1();
    push32(0x00000022);
    ecx = pop32();
    memoryASet32(ds, eax, ecx);
    esi = ecx;
    goto loc_100d7c83;
loc_100d7cce: // 0000:100d7cce
    eax = 0;
loc_100d7cd0: // 0000:100d7cd0
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d7cd5() // 0000:100d7cd5 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    ebx = 0;
    push32(edi);
    if (memoryAGet32(ss, ebp + 0x14) != ebx)
        goto loc_100d7cf7;
    if (esi != ebx)
        goto loc_100d7cfb;
    if (memoryAGet32(ss, ebp + 0xc) != ebx)
        goto loc_100d7d02;
loc_100d7cf0: // 0000:100d7cf0
    eax = 0;
loc_100d7cf2: // 0000:100d7cf2
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100d7cf7: // 0000:100d7cf7
    if (esi == ebx)
        goto loc_100d7d02;
loc_100d7cfb: // 0000:100d7cfb
    edi = memoryAGet32(ss, ebp + 0xc);
    if (edi > ebx)
        goto loc_100d7d1d;
loc_100d7d02: // 0000:100d7d02
    sub_100cbff1();
    push32(0x00000016);
    esi = pop32();
    memoryASet32(ds, eax, esi);
loc_100d7d0c: // 0000:100d7d0c
    push32(ebx);
    push32(ebx);
    push32(ebx);
    push32(ebx);
    push32(ebx);
    sub_100cb27c();
    esp += 0x00000014;
    eax = esi;
    goto loc_100d7cf2;
loc_100d7d1d: // 0000:100d7d1d
    if (memoryAGet32(ss, ebp + 0x14) != ebx)
        goto loc_100d7d26;
    memoryASet(ds, esi, bl);
    goto loc_100d7cf0;
loc_100d7d26: // 0000:100d7d26
    edx = memoryAGet32(ss, ebp + 0x10);
    if (edx != ebx)
        goto loc_100d7d31;
    memoryASet(ds, esi, bl);
    goto loc_100d7d02;
loc_100d7d31: // 0000:100d7d31
    eax = esi;
    if (memoryAGet32(ss, ebp + 0x14) != 0xffffffff)
        goto loc_100d7d48;
loc_100d7d39: // 0000:100d7d39
    cl = memoryAGet(ds, edx);
    memoryASet(ds, eax, cl);
    eax++;
    edx++;
    if (cl == bl)
        goto loc_100d7d61;
    edi--;
    if (edi)
        goto loc_100d7d39;
    goto loc_100d7d61;
loc_100d7d48: // 0000:100d7d48
    cl = memoryAGet(ds, edx);
    memoryASet(ds, eax, cl);
    eax++;
    edx++;
    if (cl == bl)
        goto loc_100d7d5a;
    edi--;
    if (!edi)
        goto loc_100d7d5a;
    memoryASet32(ss, ebp + 0x14, memoryAGet32(ss, ebp + 0x14) - 1);
    if (memoryAGet32(ss, ebp + 0x14))
        goto loc_100d7d48;
loc_100d7d5a: // 0000:100d7d5a
    if (memoryAGet32(ss, ebp + 0x14) != ebx)
        goto loc_100d7d61;
    memoryASet(ds, eax, bl);
loc_100d7d61: // 0000:100d7d61
    if (edi != ebx)
        goto loc_100d7cf0;
    if (memoryAGet32(ss, ebp + 0x14) != 0xffffffff)
        goto loc_100d7d7a;
    eax = memoryAGet32(ss, ebp + 0xc);
    push32(0x00000050);
    memoryASet(ds, esi + eax - 1, bl);
    eax = pop32();
    goto loc_100d7cf2;
loc_100d7d7a: // 0000:100d7d7a
    memoryASet(ds, esi, bl);
    sub_100cbff1();
    push32(0x00000022);
    ecx = pop32();
    memoryASet32(ds, eax, ecx);
    esi = ecx;
    goto loc_100d7d0c;
}
void sub_100d8064() // 0000:100d8064 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = 0;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    if (memoryAGet32(ds, 0x10582164) != eax)
        goto loc_100d8084;
    push32(0x1057e9d0);
    goto loc_100d8085;
loc_100d8084: // 0000:100d8084
    push32(eax);
loc_100d8085: // 0000:100d8085
    sub_100d7e35();
    esp += 0x00000014;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d8487() { printf("FATAL: unimplemented CRT function sub_100d8487 called\n"); abort(); }
void sub_100d85e3() // 0000:100d85e3 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    push32(esi);
    esi = 0;
    if (eax != esi)
        goto loc_100d860f;
    sub_100cbff1();
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    memoryASet32(ds, eax, 0x00000016);
    sub_100cb27c();
    esp += 0x00000014;
    eax |= 0xffffffff;
    goto loc_100d8612;
loc_100d860f: // 0000:100d860f
    eax = memoryAGet32(ds, eax + 0x10);
loc_100d8612: // 0000:100d8612
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d8615() // 0000:100d8615 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0x8);
    push32(esi);
    sub_100d85e3();
    push32(eax);
    sub_100dc08f();
    ecx = pop32();
    ecx = pop32();
    if (!eax)
        goto loc_100d86ac;
    sub_100ceac3();
    eax += 0x00000020;
    if (esi != eax)
        goto loc_100d8640;
    eax = 0;
    goto loc_100d864f;
loc_100d8640: // 0000:100d8640
    sub_100ceac3();
    eax += 0x00000040;
    if (esi != eax)
        goto loc_100d86ac;
    eax = 0;
    eax++;
loc_100d864f: // 0000:100d864f
    memoryASet32(ds, 0x105821a0, memoryAGet32(ds, 0x105821a0) + 1);
    if (memoryAGet32(ds, esi + 0xc) & 0x0000010c)
        goto loc_100d86ac;
    push32(ebx);
    push32(edi);
    edi = (eax * 4) + 274213588;
    ebx = 0x00001000;
    if (memoryAGet32(ds, edi))
        goto loc_100d8691;
    push32(ebx);
    sub_100cbe7e();
    ecx = pop32();
    memoryASet32(ds, edi, eax);
    if (eax)
        goto loc_100d8691;
    eax = esi + 20;
    push32(0x00000002);
    memoryASet32(ds, esi + 0x8, eax);
    memoryASet32(ds, esi, eax);
    eax = pop32();
    memoryASet32(ds, esi + 0x18, eax);
    memoryASet32(ds, esi + 0x4, eax);
    goto loc_100d869e;
loc_100d8691: // 0000:100d8691
    edi = memoryAGet32(ds, edi);
    memoryASet32(ds, esi + 0x8, edi);
    memoryASet32(ds, esi, edi);
    memoryASet32(ds, esi + 0x18, ebx);
    memoryASet32(ds, esi + 0x4, ebx);
loc_100d869e: // 0000:100d869e
    memoryASet32(ds, esi + 0xc, memoryAGet32(ds, esi + 0xc) | 0x00001102);
    eax = 0;
    edi = pop32();
    eax++;
    ebx = pop32();
    goto loc_100d86ae;
loc_100d86ac: // 0000:100d86ac
    eax = 0;
loc_100d86ae: // 0000:100d86ae
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100d86b1() // 0000:100d86b1 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    if (!memoryAGet32(ss, ebp + 0x8))
        goto loc_100d86e3;
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0xc);
    if (!(memoryAGet32(ds, esi + 0xc) & 0x00001000))
        goto loc_100d86e2;
    push32(esi);
    sub_100cee5c();
    memoryASet32(ds, esi + 0xc, memoryAGet32(ds, esi + 0xc) & 0xffffeeff);
    memoryASet32(ds, esi + 0x18, memoryAGet32(ds, esi + 0x18) & 0x00000000);
    memoryASet32(ds, esi, memoryAGet32(ds, esi) & 0x00000000);
    memoryASet32(ds, esi + 0x8, memoryAGet32(ds, esi + 0x8) & 0x00000000);
    ecx = pop32();
loc_100d86e2: // 0000:100d86e2
    esi = pop32();
loc_100d86e3: // 0000:100d86e3
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100da23e() { printf("FATAL: unimplemented CRT function sub_100da23e called\n"); abort(); }
void sub_100da385() { printf("FATAL: unimplemented CRT function sub_100da385 called\n"); abort(); }
void sub_100da580() // 0000:100da580 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    ecx = memoryAGet32(ss, ebp + 0x8);
    eax = 0x00005a4d;
    if (memoryAGet16(ds, ecx) == ax)
        goto loc_100da596;
loc_100da592: // 0000:100da592
    eax = 0;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100da596: // 0000:100da596
    eax = memoryAGet32(ds, ecx + 0x3c);
    eax += ecx;
    if (memoryAGet32(ds, eax) != 0x00004550)
        goto loc_100da592;
    edx = 0;
    ecx = 0x0000010b;
    dl = memoryAGet16(ds, eax + 0x18) == cx;
    eax = edx;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100da5c0() // 0000:100da5c0 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    ecx = memoryAGet32(ds, eax + 0x3c);
    ecx += eax;
    eax = memoryAGet16(ds, ecx + 0x14);
    push32(ebx);
    push32(esi);
    esi = memoryAGet16(ds, ecx + 0x6);
    edx = 0;
    push32(edi);
    eax = (eax + ecx) + 24;
    if (esi <= 0)
        goto loc_100da5fd;
    edi = memoryAGet32(ss, ebp + 0xc);
loc_100da5e5: // 0000:100da5e5
    ecx = memoryAGet32(ds, eax + 0xc);
    if (edi < ecx)
        goto loc_100da5f5;
    ebx = memoryAGet32(ds, eax + 0x8);
    ebx += ecx;
    if (edi < ebx)
        goto loc_100da5ff;
loc_100da5f5: // 0000:100da5f5
    edx++;
    eax += 0x00000028;
    if (edx < esi)
        goto loc_100da5e5;
loc_100da5fd: // 0000:100da5fd
    eax = 0;
loc_100da5ff: // 0000:100da5ff
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100da610() // 0000:100da610 +long
{ esp -= 4; eax = 1; esp += 4; } // __IsNonwritableInCurrentImage stub
void sub_100da6cd() // 0000:100da6cd +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, 0x10582adc, eax);
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100da6dc() // 0000:100da6dc +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, 0x10582ae0, eax);
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dbe5d() // 0000:100dbe5d +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    ecx = memoryAGet32(ss, ebp + 0x8);
    push32(esi);
    esi = 0;
    if ((int32_t)ecx < (int32_t)esi)
        goto loc_100dbe8a;
    if ((int32_t)ecx <= (int32_t)0x00000002)
        goto loc_100dbe7d;
    if (ecx != 0x00000003)
        goto loc_100dbe8a;
    eax = memoryAGet32(ds, 0x10582154);
    goto loc_100dbea5;
loc_100dbe7d: // 0000:100dbe7d
    eax = memoryAGet32(ds, 0x10582154);
    memoryASet32(ds, 0x10582154, ecx);
    goto loc_100dbea5;
loc_100dbe8a: // 0000:100dbe8a
    sub_100cbff1();
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    memoryASet32(ds, eax, 0x00000016);
    sub_100cb27c();
    esp += 0x00000014;
    eax |= 0xffffffff;
loc_100dbea5: // 0000:100dbea5
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dc046() // 0000:100dc046 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    memoryASet32(ds, 0x105821a0, memoryAGet32(ds, 0x105821a0) + 1);
    push32(0x00001000);
    sub_100cbe7e();
    ecx = pop32();
    ecx = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, ecx + 0x8, eax);
    if (!eax)
        goto loc_100dc073;
    memoryASet32(ds, ecx + 0xc, memoryAGet32(ds, ecx + 0xc) | 0x00000008);
    memoryASet32(ds, ecx + 0x18, 0x00001000);
    goto loc_100dc084;
loc_100dc073: // 0000:100dc073
    memoryASet32(ds, ecx + 0xc, memoryAGet32(ds, ecx + 0xc) | 0x00000004);
    eax = ecx + 20;
    memoryASet32(ds, ecx + 0x8, eax);
    memoryASet32(ds, ecx + 0x18, 0x00000002);
loc_100dc084: // 0000:100dc084
    eax = memoryAGet32(ds, ecx + 0x8);
    memoryASet32(ds, ecx + 0x4, memoryAGet32(ds, ecx + 0x4) & 0x00000000);
    memoryASet32(ds, ecx, eax);
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dc08f() // 0000:100dc08f +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    if (eax != 0xfffffffe)
        goto loc_100dc0ab;
    sub_100cbff1();
    memoryASet32(ds, eax, 0x00000009);
    eax = 0;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dc0ab: // 0000:100dc0ab
    push32(esi);
    esi = 0;
    if ((int32_t)eax < (int32_t)esi)
        goto loc_100dc0ba;
    if (eax < memoryAGet32(ds, 0x10582bf8))
        goto loc_100dc0d6;
loc_100dc0ba: // 0000:100dc0ba
    sub_100cbff1();
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    memoryASet32(ds, eax, 0x00000009);
    sub_100cb27c();
    esp += 0x00000014;
    eax = 0;
    goto loc_100dc0f0;
loc_100dc0d6: // 0000:100dc0d6
    ecx = eax;
    eax &= 0x0000001f;
    ecx = sar32(ecx, 0x05);
    ecx = memoryAGet32(ds, ecx * 4 + 0x10582c00);
    eax <<= 6;
    eax = (int8_t)memoryAGet(ds, ecx + eax + 0x4);
    eax &= 0x00000040;
loc_100dc0f0: // 0000:100dc0f0
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dc3cf() // 0000:100dc3cf +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0xe);
    ecx = 0x00007ff0;
    edx = eax;
    edx &= ecx;
    if (dx != cx)
        goto loc_100dc412;
    fld64(memoryAGet64(ss, ebp + 0x8));
    push32(ecx);
    push32(ecx);
    memoryASet64(ds, esp, fstp64());
    sub_100dc48f();
    eax--;
    ecx = pop32();
    ecx = pop32();
    if (!eax)
        goto loc_100dc40b;
    eax--;
    if (!eax)
        goto loc_100dc406;
    eax--;
    if (!eax)
        goto loc_100dc402;
    eax = 0;
    eax++;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dc402: // 0000:100dc402
    push32(0x00000002);
    goto loc_100dc408;
loc_100dc406: // 0000:100dc406
    push32(0x00000004);
loc_100dc408: // 0000:100dc408
    eax = pop32();
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dc40b: // 0000:100dc40b
    eax = 0x00000200;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dc412: // 0000:100dc412
    eax &= 0x00008000;
    ecx = eax;
    if (dx)
        goto loc_100dc439;
    if (memoryAGet32(ss, ebp + 0xc) & 0x000fffff)
        goto loc_100dc42d;
    if (!memoryAGet32(ss, ebp + 0x8))
        goto loc_100dc439;
loc_100dc42d: // 0000:100dc42d
    flags.carry = eax != 0;
    eax = -eax;
    eax = -flags.carry;
    eax &= 0xffffff90;
    eax -= 0xffffff80;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dc439: // 0000:100dc439
    fldz();
    fcomp64(memoryAGet64(ss, ebp + 0x8));
    ax = fnstsw();
    flags.parity = !(parityOdd(ah, 0x44));
    eax = ecx;
    if (flags.parity)
        goto loc_100dc453;
    flags.carry = eax != 0;
    eax = -eax;
    eax = -flags.carry;
    eax &= 0xffffffe0;
    eax += 0x00000040;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dc453: // 0000:100dc453
    flags.carry = eax != 0;
    eax = -eax;
    eax = -flags.carry;
    eax &= 0xffffff08;
    eax += 0x00000100;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dc48f() // 0000:100dc48f +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    edx = 0;
    if (memoryAGet32(ss, ebp + 0xc) != 0x7ff00000)
        goto loc_100dc4a9;
    if (memoryAGet32(ss, ebp + 0x8) != edx)
        goto loc_100dc4bc;
    eax = 0;
    eax++;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dc4a9: // 0000:100dc4a9
    if (memoryAGet32(ss, ebp + 0xc) != 0xfff00000)
        goto loc_100dc4bc;
    if (memoryAGet32(ss, ebp + 0x8) != edx)
        goto loc_100dc4bc;
    push32(0x00000002);
loc_100dc4b9: // 0000:100dc4b9
    eax = pop32();
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dc4bc: // 0000:100dc4bc
    ecx = memoryAGet32(ss, ebp + 0xe);
    eax = 0x00007ff8;
    ecx &= eax;
    if (cx != ax)
        goto loc_100dc4cf;
    push32(0x00000003);
    goto loc_100dc4b9;
loc_100dc4cf: // 0000:100dc4cf
    eax = 0x00007ff0;
    if (cx != ax)
        goto loc_100dc4eb;
    if (memoryAGet32(ss, ebp + 0xc) & 0x0007ffff)
        goto loc_100dc4e7;
    if (memoryAGet32(ss, ebp + 0x8) == edx)
        goto loc_100dc4eb;
loc_100dc4e7: // 0000:100dc4e7
    push32(0x00000004);
    goto loc_100dc4b9;
loc_100dc4eb: // 0000:100dc4eb
    eax = 0;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dc4ef() // 0000:100dc4ef +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    fldz();
    fcom64(memoryAGet64(ss, ebp + 0x8));
    ax = fnstsw();
    if (!(parityOdd(ah, 0x44)))
        goto loc_100dc507;
    edx = 0;
    goto loc_100dc5a1;
loc_100dc507: // 0000:100dc507
    edx = memoryAGet32(ss, ebp + 0xe);
    ecx = 0;
    if (edx & 0x00007ff0)
        goto loc_100dc57f;
    if (memoryAGet32(ss, ebp + 0xc) & 0x000fffff)
        goto loc_100dc522;
    if (memoryAGet32(ss, ebp + 0x8) == ecx)
        goto loc_100dc57f;
loc_100dc522: // 0000:100dc522
    fcomp64(memoryAGet64(ss, ebp + 0x8));
    edx = 0xfffffc03;
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_100dc536;
    eax = 0;
    eax++;
    goto loc_100dc54e;
loc_100dc536: // 0000:100dc536
    eax = 0;
    goto loc_100dc54e;
loc_100dc53a: // 0000:100dc53a
    memoryASet32(ss, ebp + 0xc, memoryAGet32(ss, ebp + 0xc) << 1);
    if (!(memoryAGet32(ss, ebp + 0x8) & 0x80000000))
        goto loc_100dc54a;
    memoryASet32(ss, ebp + 0xc, memoryAGet32(ss, ebp + 0xc) | 0x00000001);
loc_100dc54a: // 0000:100dc54a
    memoryASet32(ss, ebp + 0x8, memoryAGet32(ss, ebp + 0x8) << 1);
    edx--;
loc_100dc54e: // 0000:100dc54e
    if (!(memoryAGet(ss, ebp + 0xe) & 0x10))
        goto loc_100dc53a;
    push32(esi);
    esi = 0x0000ffef;
    memoryASet16(ss, ebp + 0xe, memoryAGet16(ss, ebp + 0xe) & si);
    esi = pop32();
    if (eax == ecx)
        goto loc_100dc56c;
    eax = 0x00008000;
    memoryASet16(ss, ebp + 0xe, memoryAGet16(ss, ebp + 0xe) | ax);
loc_100dc56c: // 0000:100dc56c
    fld64(memoryAGet64(ss, ebp + 0x8));
    push32(ecx);
    push32(ecx);
    push32(ecx);
    memoryASet64(ds, esp, fstp64());
    sub_100dc463();
    esp += 0x0000000c;
    goto loc_100dc5a1;
loc_100dc57f: // 0000:100dc57f
    push32(ecx);
    fstpst(0);
    fld64(memoryAGet64(ss, ebp + 0x8));
    push32(ecx);
    push32(ecx);
    memoryASet64(ds, esp, fstp64());
    sub_100dc463();
    edx >>= 4;
    edx &= 0x000007ff;
    esp += 0x0000000c;
    edx -= 0x000003fe;
loc_100dc5a1: // 0000:100dc5a1
    eax = memoryAGet32(ss, ebp + 0x10);
    memoryASet32(ds, eax, edx);
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dc887() // 0000:100dc887 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x1c));
    push32(memoryAGet32(ss, ebp + 0x18));
    push32(memoryAGet32(ss, ebp + 0x14));
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100dc5ab();
    esp += 0x0000001c;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dca8c() // 0000:100dca8c +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    if (memoryAGet32(ss, ebp + 0x8) == 0x00000001)
        goto loc_100dcaac;
    if ((int32_t)memoryAGet32(ss, ebp + 0x8) <= (int32_t)0x00000001)
        goto loc_100dcab7;
    if ((int32_t)memoryAGet32(ss, ebp + 0x8) > (int32_t)0x00000003)
        goto loc_100dcab7;
    sub_100cbff1();
    memoryASet32(ds, eax, 0x00000022);
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dcaac: // 0000:100dcaac
    sub_100cbff1();
    memoryASet32(ds, eax, 0x00000021);
loc_100dcab7: // 0000:100dcab7
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dcab9() // 0000:100dcab9 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    al = memoryAGet(ss, ebp + 0x8);
    if (!(al & 0x20))
        goto loc_100dcac9;
    push32(0x00000005);
    goto loc_100dcae0;
loc_100dcac9: // 0000:100dcac9
    if (!(al & 0x08))
        goto loc_100dcad2;
    eax = 0;
    eax++;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dcad2: // 0000:100dcad2
    if (!(al & 0x04))
        goto loc_100dcada;
    push32(0x00000002);
    goto loc_100dcae0;
loc_100dcada: // 0000:100dcada
    if (!(al & 0x01))
        goto loc_100dcae3;
    push32(0x00000003);
loc_100dcae0: // 0000:100dcae0
    eax = pop32();
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dcae3: // 0000:100dcae3
    eax = al;
    eax &= 0x00000002;
    eax += eax;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dcb8d() // 0000:100dcb8d +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    if (memoryAGet32(ds, 0x1057ef18))
        goto loc_100dcbc3;
    push32(memoryAGet32(ss, ebp + 0x14));
    fld64(memoryAGet64(ss, ebp + 0xc));
    esp -= 0x00000018;
    memoryASet64(ds, esp + 0x10, fstp64());
    fldz();
    memoryASet64(ds, esp + 0x8, fstp64());
    fld64(memoryAGet64(ss, ebp + 0xc));
    memoryASet64(ds, esp, fstp64());
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(0x00000001);
    sub_100dcaed();
    esp += 0x00000024;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100dcbc3: // 0000:100dcbc3
    sub_100cbff1();
    push32(0x0000ffff);
    push32(memoryAGet32(ss, ebp + 0x14));
    memoryASet32(ds, eax, 0x00000021);
    sub_100dcccc();
    fld64(memoryAGet64(ss, ebp + 0xc));
    ecx = pop32();
    ecx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dcfc7() // 0000:100dcfc7 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100dceb0();
    esp += 0x00000010;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dcfe1() // 0000:100dcfe1 +long
{ esp -= 4; eax = 0; esp += 4; } // __ismbblead stub
void sub_100dd034() // 0000:100dd034 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    push32(0x00000004);
    push32(0x00000000);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(0x00000000);
    sub_100dcfe1();
    esp += 0x00000010;
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dd837() { printf("FATAL: unimplemented CRT function sub_100dd837 called\n"); abort(); }
void sub_100dda82() { printf("FATAL: unimplemented CRT function sub_100dda82 called\n"); abort(); }
void sub_100ddc06() { printf("FATAL: unimplemented CRT function sub_100ddc06 called\n"); abort(); }
void sub_100de97d() // 0000:100de97d +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    if (eax != 0xfffffffe)
        goto loc_100de9a2;
    sub_100cc004();
    memoryASet32(ds, eax, memoryAGet32(ds, eax) & 0x00000000);
    sub_100cbff1();
    memoryASet32(ds, eax, 0x00000009);
    eax |= 0xffffffff;
    esp = ebp; ebp = pop32();
    esp += 4; return;
loc_100de9a2: // 0000:100de9a2
    push32(esi);
    esi = 0;
    if ((int32_t)eax < (int32_t)esi)
        goto loc_100de9cb;
    if (eax >= memoryAGet32(ds, 0x10582bf8))
        goto loc_100de9cb;
    ecx = eax;
    eax &= 0x0000001f;
    ecx = sar32(ecx, 0x05);
    ecx = memoryAGet32(ds, ecx * 4 + 0x10582c00);
    eax <<= 6;
    eax += ecx;
    if (memoryAGet(ds, eax + 0x4) & 0x01)
        goto loc_100de9ef;
loc_100de9cb: // 0000:100de9cb
    sub_100cc004();
    memoryASet32(ds, eax, esi);
    sub_100cbff1();
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    memoryASet32(ds, eax, 0x00000009);
    sub_100cb27c();
    esp += 0x00000014;
    eax |= 0xffffffff;
    goto loc_100de9f1;
loc_100de9ef: // 0000:100de9ef
    eax = memoryAGet32(ds, eax);
loc_100de9f1: // 0000:100de9f1
    esi = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100dea94() // 0000:100dea94 +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    ecx = eax;
    eax &= 0x0000001f;
    ecx = sar32(ecx, 0x05);
    ecx = memoryAGet32(ds, ecx * 4 + 0x10582c00);
    eax <<= 6;
    eax = (ecx + eax) + 12;
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x100e61d8), __LINE__, 0); // 0000:100deab3
    esp = ebp; ebp = pop32();
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4;
}
void sub_100dfe00() // 0000:100dfe00 +long — [ecx+8] -= 1 (reference count decrement)
{
    esp -= 4;
    memoryASet32(ds, ecx + 8, memoryAGet32(ds, ecx + 8) - 1);
    esp += 4;
}
void sub_100dfe20() // 0000:100dfe20 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ecx);
    eax = 0;
    push32(ebx);
    push32(esi);
    esi = ecx;
    memoryASet32(ds, esi, eax);
    memoryASet32(ds, esi + 0x4, eax);
    memoryASet32(ds, esi + 0x8, eax);
    memoryASet32(ds, esi + 0xc, eax);
    memoryASet32(ds, esi + 0x10, eax);
    memoryASet32(ds, esi + 0x14, eax);
    memoryASet32(ds, esi + 0x18, eax);
    memoryASet32(ds, esi + 0x1c, eax);
    memoryASet32(ds, esi + 0x20, eax);
    memoryASet32(ss, ebp - 4, eax);
    eax = 0;
    eax = 0; ebx = 0; ecx = 0; edx = 0; // cpuid stub
    if (eax < 0x00000001)
        goto loc_100dfe5a;
    eax = 0x00000001;
    eax = 0; ebx = 0; ecx = 0; edx = 0; // cpuid stub
    memoryASet32(ss, ebp - 4, edx);
loc_100dfe5a: // 0000:100dfe5a
    eax = memoryAGet32(ss, ebp - 4);
    eax >>= 25;
    al &= 0x01;
    memoryASet(ds, esi + 0x24, al);
    eax = esi;
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    esp += 4;
}
// Restored functions (removed by duplicate-removal script but needed)
void sub_100ca0cc() // 0000:100ca0cc +long
{
    esp -= 4;
    edi = edi;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000010;
    push32(memoryAGet32(ss, ebp + 0xc));
    ecx = ebp - 16;
    sub_100c8f3d();
    eax = memoryAGet32(ss, ebp - 16);
    if ((int32_t)memoryAGet32(ds, eax + 0xac) <= (int32_t)0x00000001)
        goto loc_100ca101;
    eax = ebp - 16;
    push32(eax);
    push32(0x00000107);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_100d2d11();
    esp += 0x0000000c;
    goto loc_100ca113;
loc_100ca101:
    eax = memoryAGet32(ds, eax + 0xc8);
    ecx = memoryAGet32(ss, ebp + 0x8);
    eax = memoryAGet16(ds, eax + ecx * 2);
    eax &= 0x00000107;
loc_100ca113:
    if (!memoryAGet(ss, ebp - 4))
        goto loc_100ca120;
    ecx = memoryAGet32(ss, ebp - 8);
    memoryASet32(ds, ecx + 0x70, memoryAGet32(ds, ecx + 0x70) & 0xfffffffd);
loc_100ca120:
    esp = ebp; ebp = pop32();
    esp += 4;
}
void sub_100cba51() // 0000:100cba51 +stackDrop12 +entry
{
    edi = edi;
    push32(ebp);
    ebp = esp;
    if (memoryAGet32(ss, ebp + 0xc) != 0x00000001)
        goto loc_100cba61;
    sub_100d7088();
loc_100cba61:
    push32(memoryAGet32(ss, ebp + 0x8));
    ecx = memoryAGet32(ss, ebp + 0x10);
    edx = memoryAGet32(ss, ebp + 0xc);
    sub_100cb95b();
    ecx = pop32();
    esp = ebp; ebp = pop32();
    esp += 12;
}
void sub_100496af() // 0000:100496af +long — thunk: push ebp; mov ebp,esp; pop ebp; jmp operator_new
{
    esp -= 4; // synthetic for this function's CALL
    uint32_t sz = memoryAGet32(ss, esp + 4);
    if(!sz) sz=1;
    eax = allocate(sz);
    esp += 4; // synthetic return
}
// Stubs for CRT functions pulled in by procList additions
void sub_100d8582() { fprintf(stderr, "STUB: sub_100d8582\n"); assert(0); }
void sub_100d85b2() { fprintf(stderr, "STUB: sub_100d85b2\n"); assert(0); }
void sub_100d85cc() { fprintf(stderr, "STUB: sub_100d85cc\n"); assert(0); }
void sub_100d8599() { fprintf(stderr, "STUB: sub_100d8599\n"); assert(0); }
void sub_100da7f8() { fprintf(stderr, "STUB: sub_100da7f8\n"); assert(0); }
void sub_100da83b() { fprintf(stderr, "STUB: sub_100da83b\n"); assert(0); }
void sub_100d3b31() { fprintf(stderr, "STUB: sub_100d3b31\n"); assert(0); }
void _initterm()
{
        printf("  PRE-initterm: [0x103fb04c]=0x%08x\n", memoryAGet32(0, 0x103fb04c));
    // _initterm table: 0x100e62ec - 0x100e6418 (75 function pointers)
    //for (uint32_t slot = 0x100e62ec; slot < 0x100e6418; slot += 4) {
    //  printf("case 0x%x: sub_%x();\n", memoryAGet32(0, slot), memoryAGet32(0, slot));
    sub_100e4f06();
    sub_100e4f28();
    sub_100e4f3e();
    sub_100e45f0();
    sub_100e4610();
    sub_100e4630();
    sub_100e4650();
    sub_100e4670();
    sub_100e4690();
    sub_100e46b0();
    sub_100e46d0();
    sub_100e46f0();
    sub_100e4710();
    sub_100e4730();
    sub_100e4750();
    sub_100e4770();
    sub_100e4790();
    sub_100e47b0();
    sub_100e47d0();
    sub_100e47f0();
    sub_100e4810();
    sub_100e4830();
    sub_100e4850();
    sub_100e4870();
    sub_100e4890();
    sub_100e48b0();
    sub_100e48e0();
    sub_100e4900();
    sub_100e4920();
    sub_100e4940();
    sub_100e4960();
    sub_100e4980();
    sub_100e49a0();
    sub_100e49c0();
    sub_100e49e0();
    sub_100e4a00();
    sub_100e4a20();
    sub_100e4a40();
    sub_100e4a60();
    sub_100e4a80();
    sub_100e4ab0();
    sub_100e4ae0();
    sub_100e4b10();
    sub_100e4b40();
    sub_100e4b70();
    sub_100e4b90();
    sub_100e4bb0();
    sub_100e4bd0();
    sub_100e4bf0();
    sub_100e4c10();
    sub_100e4c30();
    sub_100e4c60();
    sub_100e4c90();
    sub_100e4cb0();
    sub_100e4cf0();
    sub_100e4d00();
    sub_100e4d20();
    sub_100e4d60();
    sub_100e4d70();
    sub_100e4d90();
    sub_100e4db0();
    sub_100e4dd0();
    sub_100e4df0();
    sub_100e4e10();
    sub_100e4e30();
    sub_100e4e50();
    sub_100e4e70();
    sub_100e4e90();
    sub_100e4eb0();
    sub_100e4ef0();
    sub_100e4f1c();
    sub_100e4f50();
    sub_100e4f70();
    sub_100e4fe0();
    sub_100e5000();
        printf("  POST-initterm: [0x103fb04c]=0x%08x\n", memoryAGet32(0, 0x103fb04c));
}
void sub_6ab00078()
{
    eax = kernel32::GetTickCount();
}
