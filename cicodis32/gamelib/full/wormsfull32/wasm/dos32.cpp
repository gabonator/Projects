#include <stdio.h>
#include <assert.h>
#include <string.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/fiber.h>
#endif

extern "C" {
  int sprintf ( char * str, const char * format, ... );
  void apiPrint(char* msg);
  int apiOpen(char* name);
  int apiRead(char* name, int readofs, int readlen, int targetofs);
};

bool stop(const char* msg = nullptr, const char* info = nullptr);

extern int mouseX;
extern int mouseY;
extern int mouseB;
extern int allocatorBase;
extern uint32_t eax, ebx, ecx, edx, esi, edi, ebp, esp;
extern uint16_t ds, cs, es, ss;

#define al *reinterpret_cast<uint8_t*>(&eax)
#define ah *(reinterpret_cast<uint8_t*>(&eax) + 1)
#define bl *reinterpret_cast<uint8_t*>(&ebx)
#define bh *(reinterpret_cast<uint8_t*>(&ebx) + 1)
#define cl *reinterpret_cast<uint8_t*>(&ecx)
#define ch *(reinterpret_cast<uint8_t*>(&ecx) + 1)
#define dl *reinterpret_cast<uint8_t*>(&edx)
#define dh *(reinterpret_cast<uint8_t*>(&edx) + 1)
#define ax *reinterpret_cast<uint16_t*>(&eax)
#define bx *reinterpret_cast<uint16_t*>(&ebx)
#define cx *reinterpret_cast<uint16_t*>(&ecx)
#define dx *reinterpret_cast<uint16_t*>(&edx)
#define di *reinterpret_cast<uint16_t*>(&edi)
#define si *reinterpret_cast<uint16_t*>(&esi)

struct flags_t {
  bool carry, zero, sign, interrupts, direction;
};

extern flags_t flags;

/*
uint8_t memoryAGet(int s, int o);
uint16_t memoryAGet16(int s, int o);
uint32_t memoryAGet32(int s, int o);
uint64_t memoryAGet64(int s, int o);
*/
#define memoryASet(s, o, v) *((uint8_t*)(o)) = v
#define memoryASet16(s, o, v) *((uint16_t*)(o)) = v
#define memoryASet32(s, o, v) *((uint32_t*)(o)) = v
#define memoryASet64(s, o, v) *((uint64_t*)(o)) = v
#define memoryAGet(s, o) *((uint8_t*)(o))
#define memoryAGet16(s, o) *((uint16_t*)(o))
#define memoryAGet32(s, o) *((uint32_t*)(o))


void out16(int, int);
void out8(int, int);

void out16(int p, int v) {
    
    printf("Write16 port %x %x\n", p, v);
    assert(0);
}

int in8(int port) {
    if (port == 0x3da)
    {
        static uint8_t retrace = 0;
        retrace++;
        return (retrace & 1) ? 9 : 0;
    }
    if (port == 0x22e) // rd avail
        return 0x80;
    if (port == 0x22c) // wr avail
        return 0x80;
    if (port == 0x22a)
    {
        return 0xaa;
    }
    if (port == 0x21)
        return 0;
//    if (port == 0x22e || port == 0x24e || port == 0x26e || port == 0x28e || port == 0x28c)
//        return 0x0;
//    if (port == 0x22a || port == 0x24a || port == 0x26a || port == 0x28a)
//        return 0x0;

    if (port == 0x3cf || port == 0x3c5 || port == 0x3d5)
        return 0;
//    if (port == 0x22c)
//        return 0x0;
    stop(); return 0;
}
int in16(int port) {
    assert(0);
    return 0;
}

void interruptFileHandler()
{
    static char currentFile[128];
    static int currentOfs{0};
    static int currentSize{0};

    switch (ah)
    {
    case 0x3d:
    {
        char filename[128];
        int j = 0;
        for (int i=0; i<30; i++)
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
        apiPrint(filename);
        strcpy(currentFile, filename);
        apiOpen(currentFile);
        emscripten_sleep(0);
        currentOfs = 0;
        currentSize = apiRead(currentFile, 0, 0, 0);
        flags.carry = currentSize == -1;
        ax = 5;
        return;
    }
           
    case 0x3f:
    {
        int readBytes = apiRead(currentFile, currentOfs, ecx, edx);
        currentOfs += readBytes;
        eax = readBytes;
        flags.carry = 0;
        return;
    }
    case 0x42:
    {
      switch (al)
      {
        case 0x00:
          currentOfs = cx*0x10000 + dx;
          flags.carry = 0;
          return;
        case 0x01:
          currentOfs += cx*0x10000 + dx;
          ax = currentOfs & 0xffff;
          dx = currentOfs >> 16;
          flags.carry = 0;
          return;
        case 0x02:
          currentOfs = currentSize;
          ax = currentOfs & 0xffff;
          dx = currentOfs >> 16;
          flags.carry = 0;
          return;
      }
    }
    case 0x3e:
      return;
    }

    char info[128];
    sprintf(info, "unhandled int fs: %x", ax);
    apiPrint(info);
    assert(0);

#if 0
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
            //const char* root = "/Users/gabrielvalky/Documents/git/ext/dosbox-0.74-3/src/_dos/mm/";
            const char* root = "/Users/gabrielvalky/Documents/git/ext/dosbox-0.74-3/src/_dos/w2/";
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
            printf("Read 0x%x bytes to %x:%x\n", c, ds, edx);
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
#endif
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
                stop();
                //printf("%02x %c ", dl, dl);
                return;
            case 0x2a:
            {
                cx = 2025;
                dh = 9;
                dl = 1;
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
                static int base = 0x09a7;
                static int counter = 0x1c0;
                ax = base;
                dx = counter++;
                printf("Alloc low 0x%x par to %x:0000 desc %x\n", bx, base, si);

                base += bx;
                flags.carry = false;

                return;
            }
            case 0x0300:
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
                break;

            case 0x0301:
                assert(0);
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

