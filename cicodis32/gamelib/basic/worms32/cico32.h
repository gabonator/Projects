#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <vector>

uint32_t eax;
uint16_t& ax = *reinterpret_cast<uint16_t*>(&eax);
uint8_t& al = *reinterpret_cast<uint8_t*>(&ax);
uint8_t& ah = *(reinterpret_cast<uint8_t*>(&ax) + 1);
uint32_t ebx;
uint16_t& bx = *reinterpret_cast<uint16_t*>(&ebx);
uint8_t& bl = *reinterpret_cast<uint8_t*>(&bx);
uint8_t& bh = *(reinterpret_cast<uint8_t*>(&bx) + 1);
uint32_t ecx;
uint16_t& cx = *reinterpret_cast<uint16_t*>(&ecx);
uint8_t& cl = *reinterpret_cast<uint8_t*>(&cx);
uint8_t& ch = *(reinterpret_cast<uint8_t*>(&cx) + 1);
uint32_t edx;
uint16_t& dx = *reinterpret_cast<uint16_t*>(&edx);
uint8_t& dl = *reinterpret_cast<uint8_t*>(&dx);
uint8_t& dh = *(reinterpret_cast<uint8_t*>(&dx) + 1);
uint16_t tx;
uint8_t& tl = *reinterpret_cast<uint8_t*>(&tx);
uint8_t& th = *(reinterpret_cast<uint8_t*>(&tx) + 1);
//uint16_t cs, ds, es, ss, sp, si, di, bp;
uint32_t esi, edi, esp, ebp;
uint16_t& bp = *reinterpret_cast<uint16_t*>(&ebp);

uint16_t ds, ss, es, gs, cs, fs;
uint16_t& di = *reinterpret_cast<uint16_t*>(&edi);
uint16_t& si = *reinterpret_cast<uint16_t*>(&esi);
uint32_t etx;
uint32_t cr0;

struct flags_t {
  bool carry, zero, sign, interrupts, direction;
};

flags_t flags;


std::vector<uint8_t> GetFileContents(std::string fullPath);

void memoryASet(int s, int o, int v);
void memoryASet16(int s, int o, int v);
void memoryASet32(int s, int o, uint32_t v);
uint8_t memoryAGet(int s, int o);
uint16_t memoryAGet16(int s, int o);
uint32_t memoryAGet32(int s, int o);

uint32_t pop32()
{
  uint32_t aux = memoryAGet32(ss, esp);
  esp += 4;
  return aux;
}

void push32(uint32_t w)
{
  esp -= 4;
  memoryASet32(ss, esp, w);
  assert(esp > 0);
}

uint16_t pop()
{
  uint16_t aux = memoryAGet16(ss, esp);
  esp += 4;
  return aux;
}

void push(uint16_t w)
{
  esp -= 4;
  memoryASet32(ss, esp, w);
  assert(esp > 0);
}

struct DS_ESI {
  static uint8_t Get8() { return memoryAGet(ds, esi); }
  static uint16_t Get16() { return memoryAGet16(ds, esi); }
  static uint32_t Get32() { return memoryAGet32(ds, esi); }
  static void Advance(int n) { esi += flags.direction ? -n : n; }
};
struct ES_EDI {
  static uint8_t Get8() { return memoryAGet(es, edi); }
  static uint16_t Get16() { return memoryAGet16(es, edi); }
  static void Set8(uint8_t v) { return memoryASet(es, edi, v); }
  static void Set16(uint16_t v) { return memoryASet16(es, edi, v); }
  static void Set32(uint32_t v) { return memoryASet32(es, edi, v); }
  static void Advance(int n) { edi += flags.direction ? -n : n; }
};


template <typename dst, typename src> void movsw()
{
  dst::Set16(src::Get16());
  dst::Advance(2);
  src::Advance(2);
}

template <typename dst, typename src> void movsd()
{
  dst::Set32(src::Get32());
  dst::Advance(4);
  src::Advance(4);
}

template <typename dst, typename src> void movsb()
{
  dst::Set8(src::Get8());
  dst::Advance(1);
  src::Advance(1);
}

template <typename dst> void stosb(int v)
{
  dst::Set8(v);
  dst::Advance(1);
}

template <typename dst> void stosd(uint32_t v)
{
  dst::Set32(v);
  dst::Advance(4);
}
template <typename src> int lodsb()
{
  int temp = src::Get8();
  src::Advance(1);
  return temp;
}


uint32_t sar32(uint32_t a, uint32_t b)
{
    int32_t sa = (int32_t)a;
    sa >>= b;
    return sa;
}

bool stop(const char* msg = nullptr, const char* info = nullptr)
{
    assert(0);
    return false;
}

void indirectCall(int s, int o)
{
    stop();
}
void indirectJump(int s, int o)
{
    stop();
}

void idiv32(int32_t r)
{
    // edx:eax / r
    int64_t num = ((uint64_t)edx<<32) | eax;
    eax = num / r;
    edx = num % r;
    
//    int32_t n = (dx << 16) | ax;
//    ax = n / (int16_t)r;
//    dx = n % (int16_t)r;
}

void div32(uint32_t r)
{
    uint64_t num = ((uint64_t)edx<<32) | eax;
    eax = num / r;
    edx = num % r;
//    int32_t n = (dx << 16) | ax;
//    ax = n / (int16_t)r;
//    dx = n % (int16_t)r;
}

void sync();
//{
//    stop();
//}

uint32_t flagAsReg32()
{
    return 0;
//    return stop();
}

void flagsFromReg32(uint32_t)
{
//    stop();
}

template <typename src> void scasb_inv(uint8_t b)
{
    flags.zero = src::Get8() == b;
    src::Advance(1);
}

void out16(int, int) { stop(); }
void out8(int, int);
int in8(int port) {
    if (port == 0x3da)
    {
        static uint8_t retrace = 0;
        retrace++;
        return (retrace & 1) ? 9 : 0;
    }
    
    stop(); return 0;
}
void interruptFileHandler()
{
    struct fileslot_t {
        bool opened{false};
        int handle{-1};
        int offset{0};
        char name[1024] = {0};
        std::vector<uint8_t> data;
    };
    static fileslot_t slots[32];
    static int slotCounter = 0;
    switch (ah)
    {
        case 0x3d:
        {
            char filename[32];
            int j = 0;
            for (int i=0; i<31; i++)
            {
                char c = memoryAGet(ds, edx+i);
                if (!c)
                    break;
                if (c >= 'a' && c <= 'z')
                    c -= 'a' - 'A';
                if (c != ' ')
                {
                    filename[j++] = c;
                    filename[j] = 0;
                }
            }
            
            const char* root = "/Users/gabrielvalky/Documents/git/ext/dosbox-0.74-3/src/_dos/w/";
            char fullname[1024];
            strcpy(fullname, root);
            strcat(fullname, "/");
            strcat(fullname, filename);
            for (int i=0; i<1024 && fullname[i]; i++)
                if (fullname[i] == '\\')
                    fullname[i] = '/';
            
            assert(slotCounter < sizeof(slots)/sizeof(slots[0]));
            
            std::vector<uint8_t> data = GetFileContents(fullname);

            if (data.empty())
            {
                printf("Not found: %s\n", fullname);
                flags.carry = 1;
                ax = 0;
            } else {

                slots[slotCounter].opened = true;
                slots[slotCounter].handle = 0xb0+slotCounter;
                slots[slotCounter].offset = 0;
                strncpy(slots[slotCounter].name, fullname, sizeof(slots[slotCounter].name));
                slots[slotCounter].data = std::move(data);

                ax = slots[slotCounter].handle;
                flags.carry = 0;
                printf("Opening %s as %x\n", fullname, ax);
                slotCounter++;
            }
            return;

//            char filename[32];
//            int k=0;
//            for (int j=0; j<31; j++)
//            {
//                char c = memoryAGet(ds, edx+j);
//                if (!c)
//                    break;
//                if (c >= 'a' && c <= 'z')
//                    c -= 'a' - 'A';
//                if (c != ' ')
//                {
//                    filename[k++] = c;
//                    filename[k] = 0;
//                }
//            }
//            flags.carry = 0;
//            eax = 0xa0;
//            printf("open file: %s as %x\n", filename, eax);

            break;
        }
        case 0x40:
        {
            //write file
            printf("Write file: '");
            for (int i=0; i<cx; i++)
                printf("%c", memoryAGet(ds, edx+i));
            printf("'\n");
            ax = cx;
            flags.carry = false;
            return;
        }
        case 0x42:
        {
            if (al == 0x00)
            {
                fileslot_t& slot = slots[bx-0xb0];
                assert(slot.handle == bx);
                assert(slot.opened);

                if (slot.data.empty())
                {
                    flags.carry = 1;
                    return;
                }
                assert(!slot.data.empty());
                slot.offset = cx*0x10000 + dx;
                assert(slot.offset <= slot.data.size());
                flags.carry = 0;
                return;
            }
            if (al == 0x01)
            {
                fileslot_t& slot = slots[bx-0xb0];
                assert(slot.handle == bx);
                assert(slot.opened);
                assert(!slot.data.empty());

                slot.offset += cx*0x10000 + dx;
                assert(slot.offset <= slot.data.size());
                ax = slot.offset & 0xffff;
                dx = slot.offset >> 16;
                flags.carry = 0;
                return;
            }
            if (al == 0x02)
            {
                fileslot_t& slot = slots[bx-0xb0];
                assert(slot.handle == bx);
                assert(slot.opened);
                assert(!slot.data.empty());

                assert(cx == 0 && dx == 0);
                slot.offset = slot.data.size();
                ax = slot.offset & 0xffff;
                dx = slot.offset >> 16;
                flags.carry = 0;
                return;
            }
            assert(0);
            return;
        }
        case 0x3e:
        {
            fileslot_t& slot = slots[bx-0xb0];
            assert(slot.handle == bx);
            assert(slot.opened);

            printf("Closing %s as %x\n", slot.name, slot.handle);
            slot.data.clear();
            slot.opened = false;
            return;
        }
        case 0x3f:
        {
            fileslot_t& slot = slots[bx-0xb0];
            assert(slot.handle == bx);
            assert(slot.opened);
            
            int c = ecx;
            if (c > slot.data.size() - slot.offset)
                c = slot.data.size() - slot.offset;
            if (c <= 0)
            {
                eax = 0;
                assert(c==0);
                flags.carry = 0;
                return;
            }
            for (int i=0; i<c; i++)
                memoryASet(ds, edx+i, slot.data[slot.offset+i]);
            slot.offset += c;
            eax = c;
            flags.carry = 0;
            return;
        }

        default:
            assert(0);
    }
            
    return;

}
void interrupt(int i) {
    if (i == 0x21)
    {
        switch (ah)
        {
            case 0x3d:
            case 0x3e:
            case 0x3f:
            case 0x42:
            case 0x43:
            case 0x40:
                interruptFileHandler();
                return;

            case 0x30:
                al = 5;
                ah = 0;
                return;
            case 0xff:
                eax = 0x4734ffff;
                return;
            case 0x00:
                printf("Terminated\n");
                exit(1);
                //printf("%02x %c ", dl, dl);
                return;
            case 0x2a:
            {
                cx = 2025;
                dh = 9;
                dl = 24;
                // get date
                return;
            }
            case 0x2c:
            {
                static int hundredths = 0;
                dh = hundredths++;
                
                
                // get time
                return;
            }
            case 0x44:
            {
                assert(al == 0);
                ax = 2;
                dx = 2;
                return;
            }
                /*
                 if (i == 0x21 && ah == 0x3d)
                 {
                     char filename[32];
                     int j = 0;
                     for (int i=0; i<16; i++)
                     {
                         char c = memoryAGet(ds, dx+i);
                         if (!c)
                             break;
                         if (c >= 'a' && c <= 'z')
                             c -= 'a' - 'A';
                         if (c != ' ')
                         {
                             filename[j++] = c;
                             filename[j] = 0;
                         }
                     }
                     
                     char fullname[1024];
                     strcpy(fullname, root);
                     strcat(fullname, "/");
                     strcat(fullname, filename);
                     for (int i=0; i<1024 && fullname[i]; i++)
                         if (fullname[i] == '\\')
                             fullname[i] = '/';
                     
             //        if (!currentFile.empty())
             //        {
             //            printf("Warning single file not closed!\n");
             //            currentFile.clear();
             //        }
             //        assert(currentFile.empty());
                     assert(slotCounter < sizeof(slots)/sizeof(slots[0]));
                     
                     std::vector<uint8_t> data = getFileContents(fullname);

                     if (data.empty())
                     {
                         printf("Not found: %s\n", fullname);
                         flags.carry = 1;
                         ax = 0;
                     } else {

                         slots[slotCounter].opened = true;
                         slots[slotCounter].handle = 0xb0+slotCounter;
                         slots[slotCounter].offset = 0;
                         strncpy(slots[slotCounter].name, fullname, sizeof(slots[slotCounter].name));
                         slots[slotCounter].data = std::move(data);

                         ax = slots[slotCounter].handle;
                         flags.carry = 0;
                         printf("Opening %s as %x\n", fullname, ax);
                         slotCounter++;
                     }
                     return;
                 }

                 */
            case 0x35:
            {
                // get vect
                return;
            }
            case 0x25:
            {
                // set vect
                return;
            }
        }
    }
    if (i == 0x33)
    {
        switch (ax)
        {
            case 0:
                ax = -1;
                bx = 3;
                return;
            case 0x07:
            case 0x08:
            case 0x1c:
            case 4:
                return;
            case 3:
                cx = 100;
                dx = 100;
                bx = 0;
                return;
        }
    }
    if (i == 0x31)
    {
        switch (ax)
        {
            case 0x0006:
                //https://www.delorie.com/djgpp/doc/dpmi/api/310006.html
                cx = 0;
                dx = 0;
                break;
            case 0x0501:
            {
                //allocate memory block
                // bx:cx = block size
                // bx:cx = lin address of block
                // carry = zero
                //https://www.delorie.com/djgpp/doc/dpmi/api/310501.html
                // alloc 0x1000, bx:cx = 0015:d000, si:di=0001:5894
                // alloc 0x00101000, bx:cx = 003f:5000 si:di=0001:5895
                // alloc 0x8000, bx:cx = 0015:e000, si:di=0001:5896
                static int counter = 0;
                uint32_t sz = cx + bx*0x10000;
                switch (counter++)
                {
                    case 0:
                        assert(sz == 0x1000);
                        bx = 0x0015; cx = 0xd000;
                        si = 0x0001; di = 0x5894;
                        break;
//                    case 1:
//                        assert(sz == 0x101000);
//                        bx = 0x003f; cx = 0x5000;
//                        si = 0x0001; di = 0x5895;
//                        break;
                    case 1:
                        assert(sz == 0x8000);
                        bx = 0x0015; cx = 0xe000;
                        si = 0x0001; di = 0x5896;
                        break;
                }
                flags.carry = false;
                return;
            }
            default:
                assert(0);
        }
        return;
    }
    if (i == 0x10)
    {
        printf("Set VGA ax=%x\n", ax);
        return;
    }
    stop();
}
void sahf() { stop(); }

uint32_t ror32(uint32_t r, int l)
{
    return (r>>l) | (r<<(32-l));
}
uint32_t rol32(uint32_t r, int l)
{
    return (r<<l) | (r>>(32-l));
}

uint32_t rcr32(uint32_t r, int l) { stop(); return 0;}
uint32_t rcl32(uint32_t r, int l) {
    while (l > 0)
    {
        int newCarry = !!(r & 0x80000000);
        r <<= 1;
        r |= flags.carry ? 0x00000001 : 0x00000000;
        flags.carry = newCarry;
        l--;
    }
    return r;
}

uint16_t rcr16(uint16_t r, int l) { stop(); return 0;}
uint16_t rcl16(uint16_t r, int l) { stop(); return 0;}
uint16_t ror16(uint16_t r, int l) { stop(); return 0;}
uint16_t rol16(uint16_t r, int l) { stop(); return 0;}


namespace fpuinsns {
void fild32(uint32_t v) {stop();}
void fadd32(uint32_t v) {stop();}
void fdiv32(uint32_t v) {stop();}
void fmul64(uint64_t v) {stop();}
void fld1() {stop();}
void fcos() {stop();}
void fld64(uint64_t v) {stop();}
void fsubr64(uint64_t v) {stop();}
uint64_t fstp64() {stop(); return 0;}
uint64_t fistp64() {stop(); return 0;}
uint32_t fistp32() {stop(); return 0;}
uint64_t st(int n) {stop(); return 0;}
void fmul80(uint64_t v) {stop();}
void fdiv64(uint64_t v) {stop();}
void fdiv80(uint64_t v) {stop();}
void fsubp80() {stop();}
void fadd64(uint64_t v) {stop();}
void fadd80(uint64_t v) {stop();}
void faddp64(uint64_t v) {stop();}
void faddp80(uint64_t v) {stop();}
//void fdiv64(uint64_t v) {stop();}
//void fadd64(uint64_t v) {stop();}
//void faddp64(uint64_t v) {stop();}
void fcomp64(uint64_t v) {stop();}
void fcomp32(uint32_t v) {stop();}
void fmul32(uint32_t v) {stop();}
uint32_t fstp32() {stop(); return 0;}
void fld32(uint32_t v) {stop();}
uint16_t fnstsw() {stop(); return 0;}
void fldcw(uint16_t) {stop();}
void frndtint() {stop();}
uint16_t fnstcw() {stop(); return 0;}
}
using namespace fpuinsns;
