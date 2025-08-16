#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <vector>

class Test
{
    uint8_t al;
    uint16_t ds = 0, ax;
    uint32_t eax, ebx, ecx, edx, esi, edi, ebp, esp = 0x200;
    uint8_t memory[1024];
    int palIndex{0};
    uint8_t palette[3*256];
    uint8_t screen[320*200];
    std::vector<double> fpu;
    bool fpuc0, fpuc2, fpuc3;
    struct {
        bool carry;
    } flags;
    void out(int port, int val)
    {
        //printf("out(0x%03x, 0x%02x)\n", port, val);
        if (port == 0x3c9)
            palette[palIndex++] = val;
    }
    void memoryASet64(int seg, int ofs, uint64_t v)
    {
        assert(ofs > 0 && ofs+8 < sizeof(memory));
        *((uint64_t*)&memory[ofs]) = v;
    }
    void memoryASet32(int seg, int ofs, uint32_t v)
    {
        assert(ofs > 0 && ofs+4 < sizeof(memory));
        *((uint32_t*)&memory[ofs]) = v;
    }
    void memoryASet16(int seg, int ofs, uint16_t v)
    {
        assert(ofs > 0 && ofs+2 < sizeof(memory));
        *((uint16_t*)&memory[ofs]) = v;
    }
    void memoryASet(int seg, int ofs, uint8_t v)
    {
        if (ofs >= 0xa0000)
        {
            ofs -= 0xa0000;
            assert(ofs < sizeof(screen));
            screen[ofs] = v;
            return;
        }
        assert(ofs > 0 && ofs < sizeof(memory));
        memory[ofs] = v;
    }
    uint8_t memoryAGet(int seg, int ofs)
    {
        assert(ofs > 0 && ofs < sizeof(memory));
        return memory[ofs];
    }
    uint32_t memoryAGet32(int seg, int ofs)
    {
        assert(ofs > 0 && ofs+4 < sizeof(memory));
        return *((uint32_t*)&memory[ofs]);
    }
    uint64_t memoryAGet64(int seg, int ofs)
    {
        switch (ofs)
        {
            case 0x17c004: return 0x3f916872b020c49c; // 0.017
            case 0x17c00c: return 0x403f000000000000; // 31
            case 0x17c014: return 0x4040000000000000; // 32
            case 0x17c01c: return 0x4008000000000000; // 3
            case 0x17c024: return 0x4014000000000000; // 5
            case 0x17c02c: return 0x4069000000000000; // 200
            case 0x17c034: return 0x4074000000000000; // 320
            case 0x17c03c: return 0x4000000000000000; // 2
            case 0x17c044: return 0x4010000000000000; // 4
            case 0x17c04c: return 0x3f70000000000000; // 0.00390625
            case 0x17c054: return 0x406fe00000000000; // 255
        }
        assert(ofs > 0 && ofs+8 < sizeof(memory));
        return *((uint64_t*)&memory[ofs]);
    }
    void push32(uint32_t v)
    {
        assert(esp > 10);
        esp -= 4;
        memoryASet32(0, esp, v);
    }
    uint32_t pop32()
    {
        uint32_t aux = memoryAGet32(0, esp);
        esp += 4;
        return aux;
    }
private:
    void fild32(uint32_t v)
    {
        assert(fpu.size() < 8);
        fpu.insert(fpu.begin(), v);
    }
    void fmul64(uint64_t v)
    {
        double m;
        memcpy(&m, &v, sizeof(m));
        fpu[0] *= m;
    }
    void fld1()
    {
        fpu.insert(fpu.begin(), 1.0);
    }
    void fcos()
    {
        fpu[0] = cos(fpu[0]);
    }
    void fld64(uint64_t v)
    {
        double f;
        memcpy(&f, &v, sizeof(f));
        assert(fpu.size() < 8);
        fpu.insert(fpu.begin(), f);
    }
    void fsubr64(uint64_t v)
    {
        double m;
        memcpy(&m, &v, sizeof(m));
        fpu[0] = m - fpu[0];
    }
    uint64_t fstp64()
    {
        uint64_t v;
        memcpy(&v, &fpu[0], sizeof(uint64_t));
        fpu.erase(fpu.begin());
        return v;
    }
    uint64_t fistp64()
    {
        int aux = (int)fpu[0];
        fpu.erase(fpu.begin());
        return aux;
    }
    uint32_t fistp32()
    {
        int aux = (int)fpu[0];
        fpu.erase(fpu.begin());
        return aux;
    }
    uint64_t st(int n)
    {
        assert(n < fpu.size());
        uint64_t v;
        memcpy(&v, &fpu[n], sizeof(uint64_t));
        return v;
    }
    void fmul80(uint64_t v)
    {
        fmul64(v);
    }
    void fdiv80(uint64_t v)
    {
        fdiv64(v);
    }
    void fsubp80()
    {
        assert(fpu.size() >= 2);
        fpu[1] -= fpu[0]; // gabo!
        fpu.erase(fpu.begin());
    }
    void fadd80(uint64_t v)
    {
        fadd64(v);
    }
    void faddp80(uint64_t v)
    {
        faddp64(v);
    }
    void fdiv64(uint64_t v)
    {
        double m;
        memcpy(&m, &v, sizeof(m));
        fpu[0] /= m;
    }
    void fadd64(uint64_t v)
    {
        double m;
        memcpy(&m, &v, sizeof(m));
        fpu[0] += m;
    }
    void faddp64(uint64_t v)
    {
        double m;
        memcpy(&m, &v, sizeof(m));
        fpu[0] += m;
        fpu.erase(fpu.begin());
    }
    void fcomp64(uint64_t v)
    {
        double m;
        memcpy(&m, &v, sizeof(m));
        fpuc3 = fpuc2 = fpuc0 = 0;
        if (fpu[0] > m)
        {
        } else if (fpu[0] < m)
        {
            fpuc0 = 1;
        } else if (fpu[0] == m)
        {
            fpuc3 = 0;
        }
        fpu.erase(fpu.begin());
    }
    uint16_t fnstsw()
    {
        return (fpuc0 + fpuc2 * 4 + fpuc3*8) << 8;
    }
    void frndtint()
    {
        fpu[0] = (int)fpu[0];
    }
    void sahf()
    {
        flags.carry = ax & 0x100;
    }
    bool stop(const char* msg)
    {
      printf("Failure: %s\n", msg);
      return false;
    }
public:
    Test()
    {
        memset(screen, 0, sizeof(screen));
        sub_15e010();
        printf("P3\n320 200\n64\n");
        for (int y=0; y<200; y++)
            for (int x=0; x<320; x++)
                printf("%d %d %d\n", palette[screen[y*320+x]*3], palette[screen[y*320+x]*3+1], palette[screen[y*320+x]*3+2]);
    }
    void sub_15e27b()
    {
    }
    void sub_15e2b0()
    {
    }
    void sub_15e2d0()
    {
        out(eax, edx & 0xff);
    }
    void sub_15e2dc()
    {
        fcos();
    }
    void sub_15e358()
    {
//      push32(0x00000c3f);
//      memoryASet16(ds, esp + 2, fnstcw());
//      fldcw(memoryAGet16(ds, esp));
      frndtint();
//      fldcw(memoryAGet16(ds, esp + 2));
//      esp = esp + 4;
//      return;
    }
    void sub_15e370()
    {
    }

    void sub_15e010()
    {
        push32(0x0000009c);
        sub_15e27b();
        push32(ebx);
        push32(ecx);
        push32(edx);
        push32(esi);
        push32(edi);
        push32(ebp);
        esp -= 0x00000080;
        eax = 0;
        memoryASet32(ds, esp + 108, eax);
        memoryASet32(ds, esp + 112, 0xbff80000);
        memoryASet32(ds, esp + 116, eax);
        memoryASet32(ds, esp + 120, 0xbff00000);
        memoryASet32(ds, esp + 52, eax);
        edi = 0x40000000;
        memoryASet32(ds, esp + 56, edi);
        memoryASet32(ds, esp + 76, eax);
        memoryASet32(ds, esp + 80, edi);
        ebp = 0x000a0000;
        memoryASet16(ds, esp, 0x0013);
        ebx = esp;
        edx = esp;
        eax = 0x00000010;
        sub_15e2b0();
        eax = 0;
        ecx = 0;
    loc_15e072:
        edx = ecx;
        eax = 0x000003c8;
        sub_15e2d0();
        //stop("propagate sign flag");
        memoryASet32(ds, esp + 124, ecx);
        fild32(memoryAGet32(ds, esp + 124));
        fmul64(memoryAGet64(ds, 0x17c004));
        memoryASet64(ds, esp + 36, fstp64());
        fld1();
        fmul64(memoryAGet64(ds, esp + 36));
        sub_15e2dc();
        fmul64(memoryAGet64(ds, 0x17c00c));
        fsubr64(memoryAGet64(ds, 0x17c014));
        sub_15e358();
        memoryASet64(ds, esp + 84, fistp64());
        edx = memoryAGet32(ds, esp + 84);
        eax = 0x000003c9;
        sub_15e2d0();
        fld64(memoryAGet64(ds, esp + 36));
        fmul64(memoryAGet64(ds, 0x17c01c));
        sub_15e2dc();
        fmul64(memoryAGet64(ds, 0x17c00c));
        fsubr64(memoryAGet64(ds, 0x17c014));
        sub_15e358();
        memoryASet64(ds, esp + 84, fistp64());
        edx = memoryAGet32(ds, esp + 84);
        eax = 0x000003c9;
        sub_15e2d0();
        fld64(memoryAGet64(ds, esp + 36));
        fmul64(memoryAGet64(ds, 0x17c024));
        sub_15e2dc();
        fmul64(memoryAGet64(ds, 0x17c00c));
        fsubr64(memoryAGet64(ds, 0x17c014));
        sub_15e358();
        memoryASet64(ds, esp + 84, fistp64());
        edx = memoryAGet32(ds, esp + 84);
        eax = 0x000003c9;
        sub_15e2d0();
        ecx++;
        if ((int32_t)ecx < (int32_t)0x00000100)
            goto loc_15e072;
        ebx = 0;
        goto loc_15e140;
    loc_15e133:
        ebx++;
        if ((int32_t)ebx >= (int32_t)0x000000c8)
            goto loc_15e241;
    loc_15e140:
        memoryASet32(ds, esp + 124, ebx);
        fild32(memoryAGet32(ds, esp + 124));
        fmul64(memoryAGet64(ds, esp + 76));
        fdiv64(memoryAGet64(ds, 0x17c02c));
        fadd64(memoryAGet64(ds, esp + 116));
        memoryASet64(ds, esp + 68, fstp64());
        ecx = 0;
        goto loc_15e210;
    loc_15e161:
        edx++;
        if (edx > 0x00000100)
            goto loc_15e1cf;
    loc_15e16a:
        fld64(memoryAGet64(ds, esp + 92));
        fmul80(st(0));
        fld64(memoryAGet64(ds, esp + 100));
        fmul80(st(0));
        fsubp80();
        fadd64(memoryAGet64(ds, esp + 44));
        memoryASet64(ds, esp + 28, fstp64());
        fld64(memoryAGet64(ds, esp + 92));
        fmul64(memoryAGet64(ds, 0x17c03c));
        fmul64(memoryAGet64(ds, esp + 100));
        fadd64(memoryAGet64(ds, esp + 68));
        memoryASet64(ds, esp + 60, fstp64());
        eax = memoryAGet32(ds, esp + 28);
        memoryASet32(ds, esp + 92, eax);
        eax = memoryAGet32(ds, esp + 32);
        memoryASet32(ds, esp + 96, eax);
        eax = memoryAGet32(ds, esp + 60);
        memoryASet32(ds, esp + 100, eax);
        eax = memoryAGet32(ds, esp + 64);
        memoryASet32(ds, esp + 104, eax);
        fld64(memoryAGet64(ds, esp + 28));
        fmul80(st(0));
        fld64(memoryAGet64(ds, esp + 60));
        fmul80(st(0));
        faddp80(st(1));
        fcomp64(memoryAGet64(ds, 0x17c044));
        ax = fnstsw();
        sahf();
        if (flags.carry)
            goto loc_15e161;
    loc_15e1cf:
        if (edx >= 0x00000100)
            goto loc_15e203;
        memoryASet32(ds, esp + 124, edx);
        fild32(memoryAGet32(ds, esp + 124));
        fmul64(memoryAGet64(ds, 0x17c04c));
        fmul64(memoryAGet64(ds, 0x17c054));
        sub_15e358();
        memoryASet32(ds, esp + 124, fistp32());
        al = memoryAGet(ds, esp + 124);
        edx = ebx * 0x00000140;
        edx += ebp;
        memoryASet(ds, ecx + edx, al);
    loc_15e203:
        ecx++;
        if ((int32_t)ecx >= (int32_t)0x00000140)
            goto loc_15e133;
    loc_15e210:
        memoryASet32(ds, esp + 124, ecx);
        fild32(memoryAGet32(ds, esp + 124));
        fmul64(memoryAGet64(ds, esp + 52));
        fdiv64(memoryAGet64(ds, 0x17c034));
        fadd64(memoryAGet64(ds, esp + 108));
        memoryASet64(ds, esp + 44, fstp64());
        edx = 0;
        memoryASet32(ds, esp + 92, edx);
        memoryASet32(ds, esp + 96, edx);
        memoryASet32(ds, esp + 100, edx);
        memoryASet32(ds, esp + 104, edx);
        goto loc_15e16a;
    loc_15e241:
        sub_15e370();
        memoryASet16(ds, esp, 0x0003);
        ebx = esp;
        edx = esp;
        eax = 0x00000010;
        sub_15e2b0();
        eax = 0x00000001;
        esp += 0x00000080;
        ebp = pop32();
        edi = pop32();
        esi = pop32();
        edx = pop32();
        ecx = pop32();
        ebx = pop32();
    //    stop("stack_unbalanced");
    }
    
};


int main()
{
  Test t;
  return 0;
}