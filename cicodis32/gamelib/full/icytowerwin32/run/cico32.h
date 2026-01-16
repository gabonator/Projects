#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <vector>

extern const char* appRootPath;
int mouseX = 100;
int mouseY = 100;
int mouseB = 0;
extern int allocatorBase;

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

void loadOverlay(const char*, int);
void memoryASet(int s, int o, int v);
void memoryASet16(int s, int o, int v);
void memoryASet32(int s, int o, uint32_t v);
void memoryASet64(int s, int o, uint64_t v);
uint8_t memoryAGet(int s, int o);
uint16_t memoryAGet16(int s, int o);
uint32_t memoryAGet32(int s, int o);
uint64_t memoryAGet64(int s, int o);


void memoryVideoSet(int s, int o, int v);
void memoryVideoSet32(int s, int o, uint32_t v);

uint8_t memoryPspGet(int s, int o);
uint16_t memoryPspGet16(int s, int o);
uint32_t memoryPspGet32(int s, int o);

uint8_t memorySkipGet(int s, int o) { return 0; }
uint16_t memorySkipGet16(int s, int o) { return 0; }
uint32_t memorySkipGet32(int s, int o) { return 0; }
void memorySkipSet(int s, int o, uint8_t v) {}
void memorySkipSet16(int s, int o, uint16_t v) {}
void memorySkipSet32(int s, int o, uint32_t v) {}

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

template <typename T> uint32_t stack32(int n)
{
    return memoryAGet32(ss, esp+n*4);
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

struct MemAuto {
    static uint8_t Get8(int s, int o) { return memoryAGet(s, o); }
    static uint16_t Get16(int s, int o) { return memoryAGet16(s, o); }
    static uint32_t Get32(int s, int o) { return memoryAGet32(s, o); }
    static void Set8(int s, int o, uint8_t v) { return memoryASet(s, o, v); }
    static void Set16(int s, int o, uint16_t v) { return memoryASet16(s, o, v); }
    static void Set32(int s, int o, uint32_t v) { return memoryASet32(s, o, v); }
};

struct MemPsp {
    static uint8_t Get8(int s, int o) { return memoryPspGet(s, o); }
    static uint16_t Get16(int s, int o) { return memoryPspGet16(s, o); }
    static uint16_t Get32(int s, int o) { assert(0); return 0; }
    static void Set8(int, int, uint8_t) { assert(0); }
    static void Set16(int, int, uint8_t) { assert(0); }
    static void Set32(int, int, uint8_t) { assert(0); }
};

template <typename Mem> struct Mem_DS_ESI {
  static uint8_t Get8() { return Mem::Get8(ds, esi); }
  static uint16_t Get16() { return Mem::Get16(ds, esi); }
  static uint32_t Get32() { return Mem::Get32(ds, esi); }
  static void Advance(int n) { esi += flags.direction ? -n : n; }
};

template <typename Mem> struct Mem_ES_EDI  {
  static uint8_t Get8() { return Mem::Get8(es, edi); }
  static uint16_t Get16() { return Mem::Get16(es, edi); }
  static uint16_t Get32() { return Mem::Get32(es, edi); }
  static void Set8(uint8_t v) { return Mem::Set8(es, edi, v); }
  static void Set16(uint16_t v) { return Mem::Set16(es, edi, v); }
  static void Set32(uint32_t v) { return Mem::Set32(es, edi, v); }
  static void Advance(int n) { edi += flags.direction ? -n : n; }
};

using ES_EDI = Mem_ES_EDI<MemAuto>;
using ES_EDI_PSP = Mem_ES_EDI<MemPsp>;
using DS_ESI = Mem_DS_ESI<MemAuto>;
using DS_ESI_PSP = Mem_DS_ESI<MemPsp>;

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
    if (msg && strstr(msg, "stack_unbalanced"))
        return false;
//    if (msg && strstr(msg, "stack_below"))
//        return false;
    assert(0);
    return false;
}

/*
void indirectCall(int s, int o)
{
    switch (o)
    {
            
    }
    printf("indirectCall %x:%x\n", s, o);
}
*/
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

void imul32(int32_t r)
{
    // edx:eax / r
    int64_t num = ((int64_t)eax)*r;
    eax = num;
    edx = num >> 32;
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

void mul16(uint16_t r)
{
    int v = r * ax;
    ax = v & 0xffff;
    dx = v >> 16;
}

void mul32(uint32_t r)
{
    uint64_t v = (uint64_t)ax * (uint64_t)r;
    eax = (uint32_t)v;
    edx = v >> 32;
}

void div16(uint16_t r)
{
    uint16_t result = ax / r;
    uint16_t remain = ax % r;
    ax = result;
    dx = remain;
}

void mul8(uint8_t r)
{
    int v = r * al;
    ax = v & 0xffff;
}
    
void div8(int r)
{
    uint16_t result = ax / r;
    uint16_t remain = ax % r;
    al = result;
    ah = remain;
}

uint8_t ror8(uint8_t r, int l)
{
    return (r>>l) | (r<<(8-l));
}

uint8_t rol8(uint8_t r, int l)
{
    return (r<<l) | (r>>(8-l));
}

uint8_t rcl8(uint8_t r, int i)
{
    assert(i == 1);
    int newCarry = !!(r & 0x80);
    r <<= 1;
    r |= flags.carry;
    flags.carry = newCarry;
    return r;
}


uint16_t sar16(uint16_t r, int n)
{
    int16_t sa = (int16_t)r;
    sa >>= n;
    return sa;
}


void playSound(int seg, uint32_t ofs, int len, int samplerate, const char* fmt, bool loop);

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

template <typename src> void scasw_inv(uint8_t w)
{
    flags.zero = src::Get16() == w;
    src::Advance(2);
}

template <typename dst> void stosw(int v)
{
  dst::Set16(v);
  dst::Advance(2);
}

template <typename src> int lodsw()
{
  int temp = src::Get16();
  src::Advance(2);
  return temp;
}

template <class dst, class src> void cmpsb()
{
    // TODO: should set carry?
    flags.zero = src::Get8() == dst::Get8();
    dst::Advance(1);
    src::Advance(1);
}

template <class dst, class src> void cmpsd()
{
    // TODO: should set carry?
    flags.zero = src::Get32() == dst::Get32();
    dst::Advance(4);
    src::Advance(4);
}

void out16(int, int);
void out8(int, int);
int in8(int port);
int in16(int port) {
    assert(0);
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
    
    static fileslot_t slots[10];
    //static int slotCounter = 0;
    int freeSlot = -1;
    for (int i=0; i<sizeof(slots)/sizeof(slots[0]); i++)
    {
        if (!slots[i].opened)
        {
            freeSlot = i;
            break;
        }
    }
    assert(freeSlot >= 0);
    int slotCounter = freeSlot;
    
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
            
            //const char* root = "/Users/gabrielvalky/Documents/git/ext/dosbox-0.74-3/src/_dos/w/";
//            const char* root = "/Users/gabrielvalky/Documents/git/ext/dosbox-0.74-3/src/_dos/mm/";
            const char* root = appRootPath; //"/Users/gabrielvalky/Documents/git/ext/dosbox-0.74-3/src/_dos/w2/";
            char fullname[1024];
            strcpy(fullname, root);
            strcat(fullname, "/");
            strcat(fullname, filename);
            for (int i=0; i<1024 && fullname[i]; i++)
                if (fullname[i] == '\\')
                    fullname[i] = '/';
            
            //assert(slotCounter < sizeof(slots)/sizeof(slots[0]));
            
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
            if (bx<0xb0)
            {
                flags.carry = 0;
                return;
            }
            assert(bx >= 0xb0);
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
            assert(bx >= 0xb0);
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
            assert(bx >= 0xb0);
            fileslot_t& slot = slots[bx-0xb0];
            assert(slot.handle == bx);
            assert(slot.opened);
            
            int c = ecx;
            //assert(c < slot.data.size() - slot.offset);
            if (c > slot.data.size() - slot.offset)
                c = slot.data.size() - slot.offset;
            if (c <= 0)
            {
                eax = 0;
                assert(c==0);
                flags.carry = 0;
                return;
            }
            printf("Read %s 0x%x (0x%x) bytes starting 0x%x to %x:%x\n", strrchr(slot.name, '/'), c, ecx, slot.offset, ds, edx);
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
                dl = random()%30+1;
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
            case 0x35:
            {
                // get vect
                return;
            }
            case 0x25:
            {
                // set vect
                printf("Set interrupt 0x%x vector %x:%x\n", al, ds, edx);
                return;
            }
            case 0x2f:
            {
                // get dta
                ebx = 0x77777;
                return;                
            }
            case 0x1a:
            {
                printf("Set Disk Transfer Address %04x:%04x\n", ds, edx);
                return;
            }
            case 0x4e:
            {
                // find first "construc\cours*."
                for (int i=0; i<30 && memoryAGet(ds, edx+i); i++)
                    printf("%c", memoryAGet(ds, edx+i));
                printf("\n");
                flags.carry = true;
                return;
            }

        }
    }
    if (i == 0x33)
    {
#ifdef MOUSE_ABSOLUTE
        static int prevX = -1;
        static int prevY = -1;
        if (prevX == -1)
        {
            prevX = mouseX;
            prevY = mouseY;
        }
        int deltaX = mouseX-prevX;
        int deltaY = mouseY-prevY;
        prevX = mouseX;
        prevY = mouseY;
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
                //mouseX = cx;
                //mouseY = dx;
                return;
            case 3:
                cx = 512 + deltaX; //1000; //random()%200; //mouseX;
                dx = 512 + deltaY; //1000; //mouseY;
                bx = mouseB;
                return;
        }
#else
        switch (ax)
        {
            case 0:
                ax = -1;
                bx = 3;
                return;
            case 4:
                mouseX = cx;
                mouseY = dx;
                return;
            case 0x07:
            case 0x08:
            case 0x1c:
                return;
            case 3:
                cx = mouseX; //1000; //random()%200; //mouseX;
                dx = mouseY; //1000; //mouseY;
                bx = mouseB;
                return;
        }

#endif
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
                /*
                 worms demo
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
                 */
                
                /* micromachines2
                switch (counter++)
                {
                    case 0:
                        assert(sz == 0x1000);
                        bx = 0x0015; cx = 0xd000;
                        si = 0x0001; di = 0x5894;
                        break;
                    case 1:
                        assert(sz == 0x61000);
                        bx = 0x0041; cx = 0xd000;
                        si = 0x0001; di = 0x5896;
                        break;
                        
                    case 2:
                        assert(sz == 0x11000);
                        bx = 0x0047; cx = 0xd000;
                        si = 0x0001; di = 0x5897;
                        break;
                    case 3:
                        assert(sz == 0x8000);
                        bx = 0x0015; cx = 0xe000;
                        si = 0x0001; di = 0x5897;
                        break;

                }
                 */
                static int top = 0;
                if (top == 0)
                    top = allocatorBase;

                bx = top >> 16; cx = top & 0xffff;
                si = 0x0001; di = 0x5893 + counter;
                printf("Alloc linear 0x%x bytes to %x desc %x:%x\n", sz, top, si, di);
                top += (sz + 0x1000 -1) & ~(0x1000-1);

                flags.carry = false;
                return;
            }
            case 0x0600:
            {
                //https://www.delorie.com/djgpp/doc/dpmi/api/310600.html
                flags.carry = false;
                return;
            }
            case 0x0100:
            {
                static int base = 0x0080; //0x0080; //0x012; //0x09a7;
                static int counter = 0x1c0;
                ax = base;
                dx = counter++;
                printf("Alloc low 0x%x par to %x:0000 desc %x\n", bx, base, dx);

                base += bx;
                flags.carry = false;

                return;
                /*
                // in: bx = num of 16byte paragraphs
                // out: cf=clear, ax=segment, dx=selector
                if (bx == 0x0400)
                {
                    ax = 0x09a7;
                    dx = 0x01c0;
                    flags.carry = false;
                    return;
                }
                assert(0);*/
            }
            case 0x0300:
                printf("Unimplemnted int 0x%x ax=0x%x, emu int 0x%x, stack size 0x%x words, org %x:%x\n", i, ax, bl, cx, esi, edi);
//                printf("  di/edi=%08x\n", memoryAGet32(esi, edi+0));
//                printf("  si/esi=%08x\n", memoryAGet32(esi, edi+4));
//                printf("  BP/ebp=%08x\n", memoryAGet32(esi, edi+8));
//                printf("  pad=%08x\n", memoryAGet32(esi, edi+12));
//                printf("  ebx=%08x\n", memoryAGet32(esi, edi+16));
//                printf("  edx=%08x\n", memoryAGet32(esi, edi+20));
//                printf("  ecx=%08x\n", memoryAGet32(esi, edi+24));
//                printf("  eax=%08x\n", memoryAGet32(esi, edi+28));
//                printf("  flags=%04x\n", memoryAGet16(esi, edi+32));
//                printf("  es=%04x\n", memoryAGet16(esi, edi+34));
//                printf("  ds=%04x\n", memoryAGet16(esi, edi+36));
//                printf("  fs=%04x\n", memoryAGet16(esi, edi+38));
//                printf("  gs=%04x\n", memoryAGet16(esi, edi+40));
                {
                    int _esi = 0x160; // TODO: bug
                    if (memoryAGet32(_esi, edi+28) == 0x1500)
                    {
                        al = 0xff;
                    } else
                        if (memoryAGet32(_esi, edi+28) == 0x1510)
                        {
                            al = 0x01;
                        } else
                            assert(0);
                }
//                for (int i=0; i<cx; i++)
//                    printf("  %04x\n", memoryAGet16(esi, edi+i*2));
                break;

            case 0x0301:
                printf("Unsupported: Call real mode proc %x:%x\n", memoryAGet16(esi, edi+0x2c), memoryAGet16(esi, edi+0x2a));
                assert(0);
                ah = 1;
                break;
            case 0x0101:
                printf("Free block %x\n", dx);
                flags.carry = false;
                break;
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
    if (i == 0x1a && ah == 0x02)
    {
        // rtc https://www.stanislavs.org/helppc/int_1a-2.html
        flags.carry = 0;
        ch = 1;
        cl = 1;
        dh = 1;
        dl = 1;
        return;
    }
    if (i == 0x33 && ah == 0x00)
    {
        ax = 0;
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

uint32_t rcr32(uint32_t r, int l) {
    while (l > 0)
    {
        int newCarry = !!(r & 1);
        r >>= 1;
        r |= flags.carry ? 0x80000000 : 0x00000000;
        flags.carry = newCarry;
        l--;
    }
    return r;
}

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

//uint16_t rcr16(uint16_t r, int l) { stop(); return 0;}
uint16_t rcl16(uint16_t r, int i) {
    assert(i == 1);
    int newCarry = !!(r & 0x8000);
    r <<= 1;
    r |= flags.carry ? 1 : 0;
    flags.carry = newCarry;
    return r;
}
uint16_t rol16(uint16_t r, int l)
{
    return (r<<l) | (r>>(16-l));
}

uint16_t ror16(uint16_t r, int l)
{
    return (r>>l) | (r<<(16-l));
}

uint16_t rcr16(uint8_t r, int i)
{
    assert(i == 1);
    int newCarry = !!(r & 0x1);
    r >>= 1;
    r |= flags.carry ? 0x8000 : 0;
    flags.carry = newCarry;
    return r;
}


namespace fpuinsns {
double fpstack[8];
int top{0};
int fppos{0};
/*
void fppush(double d)
{
    fpstack[5] = fpstack[4];
    fpstack[4] = fpstack[3];
    fpstack[3] = fpstack[2];
    fpstack[2] = fpstack[1];
    fpstack[1] = fpstack[0];
    fpstack[0] = d;
    fppos++;
    assert(fppos < 5);
}
double fppop()
{
    assert(fppos > 0);
    fppos--;
    double aux = fpstack[0];
    fpstack[0] = fpstack[1];
    fpstack[1] = fpstack[2];
    fpstack[2] = fpstack[3];
    fpstack[3] = fpstack[4];
    fpstack[4] = fpstack[5];
    return aux;
}
 double& st(int n) {
     return fpstack[n];
 }
 */

void fppush(double value)
{
    assert(fppos < 8);           // stack overflow check

    top = (top - 1) & 7;         // rotate TOP downward
    assert(top != 0);
    fpstack[top] = value;        // write new ST(0)

    fppos++;
}
double fppop()
{
    assert(fppos > 0);           // stack underflow check

    double value = fpstack[top]; // read ST(0)
    fpstack[top] = 0;
    top = (top + 1) & 7;         // rotate TOP upward
    fppos--;

    return value;
}
double& st(int i) {
    assert(((top+i)&7) != 0);
    return fpstack[(top+i)&7];
}

void fild32(uint32_t v) {
    fppush((int32_t)v);
}
double FromFp64(uint64_t v)
{
    double d;
    memcpy(&d, &v, sizeof d);
    return d;
}
uint64_t toFp64(double d)
{
    uint64_t v{0};
    memcpy(&v, &d, sizeof d);
    return v;
}

void fadd32(uint32_t v) {stop();}
void fdiv32(uint32_t v) {stop();}
void fmul64(uint64_t v) {
    double d = FromFp64(v);
    st(0) *= d;
}
void fld1() {stop();}
void fldz() {stop();}
void fldln2() {stop();}
void fldl2e() {stop();}
void fcos() {stop();}
void fabs() {stop();}
void fyl2x() {stop();}
void f2xm1() {stop();}
void fchs() {st(0) = -st(0);}
void fscale() {stop();}
void fninit() {stop();}
void fld64(uint64_t v) {
    fppush(FromFp64(v));
}

void fsubr64(uint64_t v) {
    st(0) = FromFp64(v) - st(0);
}
void fsub64(uint64_t v) {
    st(0) -= FromFp64(v);
}
uint64_t fstp64() {
    double d = fppop();
    return toFp64(d);
}
uint64_t fistp64() {
    double d = fppop();
    return (int64_t)d;
    
}
uint32_t fistp32() {stop(); return 0;}
double fstp80() {
    return fppop();
}
uint64_t fst64() { return toFp64(st(0));}
void fmul80(double d) {st(0) *= d;}
void fmulp80(uint64_t v) {stop();}
void fdiv64(uint64_t v) {stop();}
void fdiv80(uint64_t v) {stop();}
void fdivp80(uint64_t v) {stop();}
void fsubp80() {stop();}
void fsub80() {stop();}
void fsub80(uint64_t v) {stop();}
void fsub32(uint64_t v) {stop();}
void fadd64(uint64_t v) {
    double d = FromFp64(v);
    st(0) += d;
}
void fadd80(double d) {st(0) += d;}
void faddp64(uint64_t v) {stop();}
void faddp80(double& v) {
    v += st(0);
    fppop();
}
void fsubp80(double& v) {
    v -= st(0);
    fppop();
}
//void fdiv64(uint64_t v) {stop();}
//void fadd64(uint64_t v) {stop();}
//void faddp64(uint64_t v) {stop();}
void fdivrp80(uint64_t v) {stop();}
uint16_t compareResult = 0;

uint16_t emulate_fnstsw_compare(double a, double b)
{
    uint16_t ax = 0;

    int unordered = isnan(a) || isnan(b);

    if (unordered) {
        // C3 = 1, C2 = 1, C0 = 1
        ax |= (1 << 14); // C3
        ax |= (1 << 10); // C2
        ax |= (1 << 8);  // C0
    }
    else if (a > b) {
        // all zero
    }
    else if (a < b) {
        ax |= (1 << 8);  // C0
    }
    else { // a == b
        ax |= (1 << 14); // C3
    }

    return ax;
}
void fcom64(uint64_t v) {
    double d = FromFp64(v);
    compareResult = emulate_fnstsw_compare(st(0), d);
}
void fcomp64(uint64_t v) {
    double d = FromFp64(v);
    compareResult = emulate_fnstsw_compare(st(0), d);
    fppop();
}
void fcomp32(uint32_t v) {stop();}
void fcomp80(double v) {
    assert(fppos >= 2);
    compareResult = emulate_fnstsw_compare(st(0), v);
    fppop();
}
void fcompp() {stop();}
void fmul32(uint32_t v) {stop();}
uint32_t fst32() {stop(); return 0;}
uint32_t fstp32() {stop(); return 0;}
void fld32(uint32_t v) {stop();}
void fld16(uint16_t v) {stop();}
void fild16(uint16_t v) {stop();}
uint16_t fnstsw() {
    return compareResult;
}
void fldcw(uint16_t) {}
void frndtint() {stop();}
uint16_t fnstcw() {return 0;}
void fld80(double d) {
    fppush(d);
}
void fprem() {stop();}
void fxch80(double& d) {
    double temp = d;
    d=st(0);
    st(0)=temp;
}
void ftst() {stop();}
}
using namespace fpuinsns;

template <typename T> struct CicoPtr {
    uint32_t ptr;
    operator uint32_t()
    {
        return ptr;
    }
    CicoPtr(uint32_t ptr) : ptr(ptr) {}
};

