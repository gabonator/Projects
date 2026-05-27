// crt_all.cpp — modified CRT functions
void callByAddress(uint32_t addr);
void sub_c05b0();
void sub_c4a60();
void sub_c8680();
void sub_c8749();
void sub_c8c18();
void sub_c8f3d();
void sub_c9124();
void sub_c91a2();
void sub_c91bc();
void sub_c924a();
void sub_c9470();
void sub_c97d5();
void sub_c97f0();
void sub_c9890();
void sub_ca260();
void sub_ca3c0();
void sub_ca59c();
void sub_ca5ff();
void sub_ca62f();
void sub_ca661();
void sub_ca6c6();
void sub_ca86a();
void sub_ca881();
void sub_caaf0();
void sub_cad4a();
void sub_cad80();
void sub_cb09d();
void sub_cb27c();
void sub_cc52a();
void sub_ce243();
void sub_ce283();
void sub_ce5e8();
void sub_ce9b0();
void sub_cebdb();
void sub_cec49();
void sub_cfe3c();
void sub_cff64();
void sub_d0027();
void sub_d0b20();
void sub_d0b65();
void sub_d0d0c();
void sub_d103d();
void sub_d1046();
void sub_d1219();
void sub_d1292();
void sub_d1449();
void sub_d1be7();
void sub_d2ea9();
void sub_d3c00();
void sub_d3c67();
void sub_d3e75();
void sub_d67af();
void sub_d6a51();
void sub_d6b2f();
void sub_d6cc9();
void sub_d6d84();
void sub_d6ebb();
void sub_d8487();
void sub_da23e();
void sub_da385();
void sub_da610();
void sub_dcfe1();
void sub_dd837();
void sub_dda82();
void sub_ddc06();
void sub_dfe00();
void sub_dfe20();
void sub_ca0cc();
void sub_496af();
void sub_d8582();
void sub_d85b2();
void sub_d85cc();
void sub_d8599();
void sub_da7f8();
void sub_da83b();
void sub_d3b31();
void sub_6ab00078();
// Auto-extracted sub_c* and sub_d* functions
// Total: 390 functions
// --- Allocation tracking ---
#ifndef WASM
#include <unordered_map>
namespace alloc_track {
    static std::unordered_map<uint32_t,uint32_t> map; // ptr -> allocated size
    static uint64_t n_malloc=0, b_malloc=0;
    static uint64_t n_calloc=0, b_calloc=0;
    static uint64_t n_new=0,    b_new=0;
    static uint64_t n_realloc=0, b_realloc=0, b_wasted=0;
    static uint64_t n_free=0, n_delete=0;
    static const int NB=9;
    static uint64_t nb[NB]={}, bb[NB]={};
    static int bkt(uint32_t s){
        if(s<16)return 0; if(s<64)return 1; if(s<256)return 2; if(s<1024)return 3;
        if(s<4096)return 4; if(s<16384)return 5; if(s<65536)return 6; if(s<262144)return 7; return 8;
    }
    static void record(uint32_t ptr, uint32_t sz){
        map[ptr]=sz; int b=bkt(sz); nb[b]++; bb[b]+=sz;
    }
    static uint32_t lookup(uint32_t ptr){
        auto it=map.find(ptr); return it!=map.end()?it->second:0;
    }
}
void print_alloc_stats(){
    using namespace alloc_track;
    uint64_t total=b_malloc+b_calloc+b_new+b_realloc;
    fprintf(stderr,"\n=== ALLOC STATS ===\n");
    fprintf(stderr,"malloc:  %6llu calls  %10llu bytes\n",(unsigned long long)n_malloc,(unsigned long long)b_malloc);
    fprintf(stderr,"calloc:  %6llu calls  %10llu bytes\n",(unsigned long long)n_calloc,(unsigned long long)b_calloc);
    fprintf(stderr,"new:     %6llu calls  %10llu bytes\n",(unsigned long long)n_new,(unsigned long long)b_new);
    fprintf(stderr,"realloc: %6llu calls  %10llu bytes  wasted=%llu\n",(unsigned long long)n_realloc,(unsigned long long)b_realloc,(unsigned long long)b_wasted);
    fprintf(stderr,"free:    %6llu calls (no-op)\n",(unsigned long long)n_free);
    fprintf(stderr,"delete:  %6llu calls (no-op)\n",(unsigned long long)n_delete);
    fprintf(stderr,"Total:   %10llu bytes  bump-wasted: %llu (%.1f%%)\n",
        (unsigned long long)total,(unsigned long long)b_wasted,total?100.0*b_wasted/total:0.0);
    const char* names[]={"<16","16-63","64-255","256-1K","1K-4K","4K-16K","16K-64K","64K-256K",">=256K"};
    fprintf(stderr,"Size distribution:\n");
    for(int i=0;i<NB;i++)
        if(nb[i]) fprintf(stderr,"  %-10s %6llu calls  %10llu bytes\n",names[i],(unsigned long long)nb[i],(unsigned long long)bb[i]);
    fprintf(stderr,"===================\n");
}
#else
// WASM: no unordered_map — tracking stubs only (avoid heap conflicts with emulated memory)
namespace alloc_track {
    static uint64_t n_malloc=0,b_malloc=0,n_calloc=0,b_calloc=0;
    static uint64_t n_new=0,b_new=0,n_realloc=0,b_realloc=0,b_wasted=0;
    static uint64_t n_free=0,n_delete=0;
    static void record(uint32_t,uint32_t){}
    static uint32_t lookup(uint32_t){return 0;}
}
void print_alloc_stats(){}
#endif

// Forward declarations for CRT sub-dependencies (defined later in this file)
void sub_c05b0() // 0000:100c05b0 +long
{
    esp -= 4;
    goto loc_100c05b0;
loc_1001f190: // 0000:1001f190
    ecx += 0x00000004;
    push32(ecx);
    indirectCall(cs, 0x6ab00075u, __LINE__, 0); // 0000:1001f194
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4; return; // undo synthetic only (stdcall already cleaned the push)
    // gap 5 bytes // gap 5 bytes
loc_1001f1a0: // 0000:1001f1a0
    ecx += 0x00000004;
    push32(ecx);
    indirectCall(cs, 0x6ab00074u, __LINE__, 0); // 0000:1001f1a4
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
        default:// break; // any other vtable — CriticalSection is no-op in single-threaded emulator
        //default_disabled:
            stop("ind 0000:100c05bf");
    }
loc_100c05c1: // 0000:100c05c1
    push32(0x103ede88);
    push32(ecx);
    sub_c3f10();
    esp += 0x00000008;
    esp += 4;
}
void sub_c4a60() // 0000:100c4a60 +long
{
    esp -= 4;
    goto loc_100c4a60;
loc_1001f190: // 0000:1001f190
    ecx += 0x00000004;
    push32(ecx);
    indirectCall(cs, 0x6ab00075u, __LINE__, 0); // 0000:1001f194
    // SEH removed (was stack_unbalanced, 0/-4) // SEH removed (was stack_unbalanced, 0/-4)
    esp += 4; return; // undo synthetic only (stdcall already cleaned the push)
    // gap 5 bytes // gap 5 bytes
loc_1001f1a0: // 0000:1001f1a0
    ecx += 0x00000004;
    push32(ecx);
    indirectCall(cs, 0x6ab00074u, __LINE__, 0); // 0000:1001f1a4
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
        default: //break; // any other vtable — CriticalSection is no-op in single-threaded emulator
        //default_disabled:
            stop("ind 0000:100c4a82");
    }
loc_100c4a84: // 0000:100c4a84
    push32(edx);
    sub_c91bc();
    ecx = pop32();
loc_100c4a8b: // 0000:100c4a8b
    esp += 4; return;
}
void sub_c8680() // 0000:100c8680 +long — memset via memoryASet (no native bypass)
{ esp -= 4; uint32_t d = memoryAGet32(ss,esp+4); uint32_t v = memoryAGet32(ss,esp+8)&0xFF; uint32_t sz = memoryAGet32(ss,esp+12);
#ifdef RASPI
  memset((void*)d, v, sz);
#else
  if(sz>0&&sz<0x1000000) for(uint32_t i=0;i<sz;i++) memoryASet(ds,d+i,v);
#endif

  eax=d; esp += 4; }
void sub_c8749() // 0000:100c8749 +long
{ esp -= 4; uint32_t sz = memoryAGet32(ss, esp+4);
  if(!sz) sz=1;
  eax = allocate(sz);
  { using namespace alloc_track; n_malloc++; b_malloc+=sz; record(eax,sz); }
  esp += 4; } // malloc stub
void sub_c8c18() // 0000:100c8c18 +long — free(ptr) (bump allocator, intentional no-op)
{ esp -= 4; alloc_track::n_free++; esp += 4; }
void sub_c8f3d() // 0000:100c8f3d +long +stackDrop4
{ esp -= 4; esp += 8; } // stub +stackDrop4 (no-op)
void sub_c9124() // 0000:100c9124 +long — __vsprintf_l(buf, fmt, locale, va_list)
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
void sub_c91a2() // 0000:100c91a2 +long — _vsprintf(buf, fmt, va_list) cdecl
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
void sub_c91bc() // 0000:100c91bc +long — free() (bump allocator, intentional no-op)
{
    esp -= 4;
    alloc_track::n_free++;
    // free() is intentionally no-op: bump allocator never frees
    esp += 4;
}
void sub_c924a() // 0000:100c924a +long
{ esp -= 4; uint32_t p = memoryAGet32(ss,esp+4); uint32_t sz = memoryAGet32(ss,esp+8); if(!sz) sz=1; uint32_t np = allocate(sz);
  if(p!=0&&sz<0x1000000) for(uint32_t i=0;i<sz;i++) memoryASet(ds,np+i,memoryAGet(ds,p+i));
  { using namespace alloc_track; uint32_t old_sz=lookup(p); n_realloc++; b_realloc+=sz; b_wasted+=old_sz; record(np,sz); }
  eax=np; esp += 4; } // realloc stub
void sub_c9470() // 0000:100c9470 +long
{ esp -= 4; eax = 0; esp += 4; } //  stub


void sub_c97f0() // 0000:100c97f0 +long
{ esp -= 4; uint32_t sz = memoryAGet32(ss, esp+4); if(!sz) sz=1; eax = allocate(sz);
  { using namespace alloc_track; n_malloc++; b_malloc+=sz; record(eax,sz); }
  esp += 4; }
void sub_c9890() // 0000:100c9890 +long
{
    esp -= 4;
    uint32_t dst = memoryAGet32(ss, esp+4);
    uint32_t src = memoryAGet32(ss, esp+8);
    uint32_t sz = memoryAGet32(ss, esp+12);
    // memcpy via memoryASet/memoryAGet (no native bypass)
#ifdef RASPI
    memcpy((void*)dst, (void*)src, sz);
#else
    for (uint32_t i = 0; i < sz; i++) 
        memoryASet(ds, dst+i, memoryAGet(ds, src+i));
#endif
    eax = dst;
    esp += 4;
}
// Forward declarations for sub_55bd0
void sub_ca260() // 0000:100ca260 +long
{ esp -= eax; } // __alloca_probe: just sub esp, eax
void sub_ca3c0() // 0000:100ca3c0 +long — _ftol2_sse: convert ST(0) to int32 in eax
{ esp -= 4; eax = (int32_t)st(0); fppop(); esp += 4; }
void sub_ca3c0(double st0) // 0000:100ca3c0 +long — _ftol2_sse: convert ST(0) to int32 in eax
{ esp -= 4; eax = (int32_t)st0; fppop(); esp += 4; }

void sub_ca59c() // 0000:100ca59c +long +stackDrop16
{ esp -= 4; eax = 0; esp += 20; } // stub +stackDrop16

void sub_ca661() // 0000:100ca661 +long +stackDrop20 — NATIVE: _eh_vec_ctor_vb
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
    //volatile uint32_t save_ebx=ebx, save_esi=esi, save_edi=edi, save_ebp=ebp, save_esp=esp;
    for (uint32_t i = 0; i < cnt; i++) {
//        esp = save_esp; // reset before each ctor (ctors have ESP drift)
        ecx = arr + i * esz;
        switch (ctor) {
            case 0x0031b90: sub_31b90(); break;
            case 0x0031d70: sub_31d70(); break;
            case 0x0009670: sub_9670(); break;
            case 0x00608b0: sub_608b0(); break;
            case 0x0061b60: sub_61b60(); break;
            case 0x000bf80: sub_bf80(); break;
            case 0x0065d80: sub_65d80(); break;
            case 0x004e4e0: sub_4e4e0(); break;
case 0x00076c0: sub_76c0(); break;
case 0x00574c0: sub_574c0(); break;
case 0x0062750: sub_62750(); break;
case 0x0065780: sub_65780(); break;
case 0x0068560: sub_68560(); break;
case 0x0058670: sub_58670(); break;
case 0x0064fd0: sub_64fd0(); break;
            default:
              fprintf(stderr, "------sub_ca661- case 0x%x: sub_%x(); break;\n", ctor, ctor); 
fflush(stderr);
assert(0);
        }
    }
    //ebx=save_ebx; esi=save_esi; edi=save_edi; ebp=save_ebp; esp=save_esp;
    esp += 24;
}

void sub_ca6c6() // 0000:100ca6c6 +long — sprintf(dst, fmt, ...)
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
            //if (raw[argIdx] >= 0x10000000u && raw[argIdx] < 0x50000000u) {
                for (int j = 0; j < 259; j++) { s[argIdx][j] = memoryAGet(ds, raw[argIdx] + j); if (!s[argIdx][j]) break; }
                s[argIdx][259] = 0;
            //}
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
void sub_ca86a() // 0000:100ca86a +long
{ esp -= 4; eax=0; esp += 4; } // atexit stub
void sub_ca881() // 0000:100ca881 +long — strtok: copies chars from src up to delimiter into dest
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
void sub_caaf0() // 0000:100caaf0 +long +returnZero
{ esp -= 4; double ex=fpuinsns::st(0),ba=fpuinsns::st(1); double r=pow(ba,ex); if(!isfinite(r))r=0; fpuinsns::setst(1,r); fpuinsns::fppop(); esp += 4; } // pow stub

double sub_caaf0(double ex, double ba) // 0000:100caaf0 +long +returnZero
{ 
printf("check pow(%f, %f)\n", ba, ex);
return pow(ba, ex);
} // pow stub

void sub_cad4a() // 0000:100cad4a +long — __CIfmod: fmod(ST(0), ST(1))
{ esp -= 4; double x=st(0), y=st(1); double r=fmod(x,y); if(!isfinite(r)) r=0; setst(1,r); fppop(); esp += 4; }
void sub_cad80() // 0000:100cad80 +long — fmod wrapper (cdecl, double args on stack)
{ esp -= 4;
  uint64_t xr = memoryAGet64(ds, esp+4), yr = memoryAGet64(ds, esp+12);
  double x, y; memcpy(&x, &xr, 8); memcpy(&y, &yr, 8);
  fppush(fmod(x,y));
  esp += 4; }
void sub_cb09d() // 0000:100cb09d +long — operator delete (calls free, intentional no-op)
{ esp -= 4; alloc_track::n_delete++; esp += 4; }
void sub_cb27c() // 0000:100cb27c +long — CRT invalid parameter handler
{
    printf("FATAL: unimplemented CRT function sub_cb27c called\n"); abort();
}
void sub_cc52a() // 0000:100cc52a +long
{ esp -= 4; eax = 0; esp += 4; } // _updatetlocinfoEx stub
void sub_ce243() // 0000:100ce243 +long
{ esp -= 4; uint32_t c = memoryAGet32(ss,esp+4); uint32_t sz = memoryAGet32(ss,esp+8); uint32_t t=c*sz;
  if(t>0x1000000) printf("  CALLOC BAD: c=0x%08x sz=0x%08x t=0x%08x esp=0x%08x\n", c, sz, t, esp);
  if(!t)t=1; eax=allocate(t);
  { using namespace alloc_track; n_calloc++; b_calloc+=t; record(eax,t); }
  esp += 4; } // calloc stub
void sub_ce283() // 0000:100ce283 +long
{ esp -= 4; eax = 0; esp += 4; } // CRT stub
void sub_ce5e8() // 0000:100ce5e8 +long — __CIsinh: sinh(ST(0))
{
    esp -= 4;
    setst(0, sinh(st(0)));
    esp += 4;
}
void sub_cebdb() { printf("FATAL: unimplemented CRT function sub_cebdb called\n"); abort(); }
void sub_cec49() { printf("FATAL: unimplemented CRT function sub_cec49 called\n"); abort(); }
void sub_cff64() // 0000:100cff64 +long
{ esp -= 4; eax = 0; esp += 4; } // _unlock stub stub // _unlock stub (no-op)
void sub_d0027() // 0000:100d0027 +long
{ esp -= 4; eax = 0; esp += 4; } // _lock stub stub // _lock stub (no-op)
void sub_d0b20() // 0000:100d0b20 +long — __SEH_prolog4 (no exceptions in this port)
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
void sub_d0b65() // 0000:100d0b65 +long — __SEH_epilog4
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
void sub_d0d0c() // 0000:100d0d0c +long
{ esp -= 4; eax = 1; esp += 4; } // __heap_init stub
void sub_d103d() // 0000:100d103d +long
{ esp -= 4; eax = memoryAGet32(ss, esp+4); esp += 4; } // _decode_pointer: identity
void sub_d1046() // 0000:100d1046 +long
{ esp -= 4; eax = memoryAGet32(ss, esp+4); esp += 4; } // _encode_pointer: identity
void sub_d1219() // 0000:100d1219 +long — __getptd_noexit (thread-local storage)
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
void sub_d1292() // 0000:100d1292 +long
{
    esp -= 4;
    sub_d1219(); // __getptd_noexit
    esp += 4;
}
void sub_d1449() // 0000:100d1449 +long
{ esp -= 4; eax = 1; esp += 4; } // __mtinit stub
void sub_d1be7() // 0000:100d1be7 +long
{ esp -= 4; eax = 0; esp += 4; } // __setmbcp stub
void sub_d2ea9() // 0000:100d2ea9 +long — __libm_sse2_pow_precise
{ esp -= 4; setst(1, pow(st(1), st(0))); fppop(); esp += 4; }
void sub_d3c00() // 0000:100d3c00 +long
{ esp -= 4; if(fpuinsns::fppos>0) fpuinsns::fppop(); eax=0; esp += 4; } // float classifier stub
void sub_d67af() // 0000:100d67af +long
{ esp -= 4; eax = 0; esp += 4; } // __ioinit stub
void sub_d6a51() // 0000:100d6a51 +long
{ esp -= 4; eax = 0; esp += 4; } // __setenvp stub
void sub_d6b2f() // 0000:100d6b2f +long
{ esp -= 4; eax = 0; esp += 4; } // _parse_cmdline stub
void sub_d6cc9() // 0000:100d6cc9 +long
{ esp -= 4; eax = 0; esp += 4; } // __setargv stub
void sub_d6d84() // 0000:100d6d84 +long
{ esp -= 4; eax = 0; esp += 4; } // __crtGetEnvironmentStringsA stub
void sub_d6ebb() // 0000:100d6ebb +long — __RTC_Initialize (genuinely empty on Windows too)
{ esp -= 4; esp += 4; }
void sub_d8487() { printf("FATAL: unimplemented CRT function sub_d8487 called\n"); abort(); }
void sub_da23e() { printf("FATAL: unimplemented CRT function sub_da23e called\n"); abort(); }
void sub_da385() { printf("FATAL: unimplemented CRT function sub_da385 called\n"); abort(); }
void sub_da610() // 0000:100da610 +long
{ esp -= 4; eax = 1; esp += 4; } // __IsNonwritableInCurrentImage stub
void sub_dcfe1() // 0000:100dcfe1 +long
{ esp -= 4; eax = 0; esp += 4; } // __ismbblead stub
void sub_dd837() { printf("FATAL: unimplemented CRT function sub_dd837 called\n"); abort(); }
void sub_dda82() { printf("FATAL: unimplemented CRT function sub_dda82 called\n"); abort(); }
void sub_ddc06() { printf("FATAL: unimplemented CRT function sub_ddc06 called\n"); abort(); }
void sub_dfe00() // 0000:100dfe00 +long — [ecx+8] -= 1 (reference count decrement)
{
    esp -= 4;
    memoryASet32(ds, ecx + 8, memoryAGet32(ds, ecx + 8) - 1);
    esp += 4;
}
void sub_496af() // 0000:100496af +long — thunk: push ebp; mov ebp,esp; pop ebp; jmp operator_new
{
    esp -= 4; // synthetic for this function's CALL
    uint32_t sz = memoryAGet32(ss, esp + 4);
    if(!sz) sz=1;
    eax = allocate(sz);
    { using namespace alloc_track; n_new++; b_new+=sz; record(eax,sz); }
    esp += 4; // synthetic return
}
// Stubs for CRT functions pulled in by procList additions
void sub_d8582() { fprintf(stderr, "STUB: sub_d8582\n"); assert(0); }
void sub_d85b2() { fprintf(stderr, "STUB: sub_d85b2\n"); assert(0); }
void sub_d85cc() { fprintf(stderr, "STUB: sub_d85cc\n"); assert(0); }
void sub_d8599() { fprintf(stderr, "STUB: sub_d8599\n"); assert(0); }
void sub_da7f8() { fprintf(stderr, "STUB: sub_da7f8\n"); assert(0); }
void sub_da83b() { fprintf(stderr, "STUB: sub_da83b\n"); assert(0); }
void sub_d3b31() { fprintf(stderr, "STUB: sub_d3b31\n"); assert(0); }
void _initterm()
{
    // _initterm table: 0x100e62ec - 0x100e6418 (75 function pointers)
    //for (uint32_t slot = 0x100e62ec; slot < 0x100e6418; slot += 4) {
    //  printf("case 0x%x: sub_%x();\n", memoryAGet32(0, slot), memoryAGet32(0, slot));
    sub_e4f06();
    sub_e4f28();
    sub_e4f3e();
    sub_e45f0();
    sub_e4610();
    sub_e4630();
    sub_e4650();
    sub_e4670();
    sub_e4690();
    sub_e46b0();
    sub_e46d0();
    sub_e46f0();
    sub_e4710();
    sub_e4730();
    sub_e4750();
    sub_e4770();
    sub_e4790();
    sub_e47b0();
    sub_e47d0();
    sub_e47f0();
    sub_e4810();
    sub_e4830();
    sub_e4850();
    sub_e4870();
    sub_e4890();
    sub_e48b0();
    sub_e48e0();
    sub_e4900();
    sub_e4920();
    sub_e4940();
    sub_e4960();
    sub_e4980();
    sub_e49a0();
    sub_e49c0();
    sub_e49e0();
    sub_e4a00();
    sub_e4a20();
    sub_e4a40();
    sub_e4a60();
    sub_e4a80();
    sub_e4ab0();
    sub_e4ae0();
    sub_e4b10();
    sub_e4b40();
    sub_e4b70();
    sub_e4b90();
    sub_e4bb0();
    sub_e4bd0();
    sub_e4bf0();
    sub_e4c10();
    sub_e4c30();
    sub_e4c60();
    sub_e4c90();
    sub_e4cb0();
    sub_e4cf0();
    sub_e4d00();
    sub_e4d20();
    sub_e4d60();
    sub_e4d70();
    sub_e4d90();
    sub_e4db0();
    sub_e4dd0();
    sub_e4df0();
    sub_e4e10();
    sub_e4e30();
    sub_e4e50();
    sub_e4e70();
    sub_e4e90();
    sub_e4eb0();
    sub_e4ef0();
    sub_e4f1c();
    sub_e4f50();
    sub_e4f70();
    sub_e4fe0();
    sub_e5000();
}
void sub_6ab00078()
{
    eax = kernel32::GetTickCount();
}
