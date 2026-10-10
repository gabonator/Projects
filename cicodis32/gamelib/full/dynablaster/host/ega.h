uint8_t memoryAGet(int s, int o);
void sync();

class CVideoAdapter
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) = 0;
    virtual void sync() = 0;
    virtual bool PortWrite16(int port, int data) = 0;
    virtual bool PortWrite8(int port, int data) = 0;
    virtual uint8_t PortRead8(int port) { return 0; }
    virtual bool Interrupt() = 0;
    virtual void Write(uint32_t dwAddr, uint8_t bWrite) = 0;
    virtual uint8_t Read(uint32_t dwAddr) = 0;
    virtual uint32_t GetPixel(int x, int y) = 0;
};

class CVga : public CVideoAdapter
{
public:
    uint8_t buffer[320*240*6];
    uint8_t palette[0x300];
    int readcolorindex{0};
    int wrmask {0};
    int rdmask {0};
    int startAdr {0};
    int rowOffset {0};

    CVga() {}

    virtual uint8_t ReadMemory(int seg, int ofs) override { return memoryAGet(seg, ofs); }
    virtual void sync() override {}

    virtual bool PortWrite16(int port, int data) override { return false; }

    virtual uint8_t PortRead8(int port) override
    {
        if (port == 0x3c9)
        {
            return palette[readcolorindex++];
        }
        return 0;
    }

    virtual bool PortWrite8(int port, int data) override
    {
        static int colorindex = 0;
        static int seq = 0;
        static int reg3d4 = 0;

        if (port == 0x3c7)
        {
            readcolorindex = data*3;
            return true;
        }
        if (port == 0x3c8)
        {
            colorindex = data*3;
            return true;
        }
        if (port == 0x3c9)
        {
            palette[colorindex++] = data;
            return true;
        }
        if (port == 0x3c4)
        {
            seq = data;
            return true;
        }
        if (port == 0x3c5)
        {
            switch (seq)
            {
                case 2:
                    switch (data & 0x0f)
                    {
                        case 15: wrmask = -1; break;
                        case 1: wrmask = 0; break;
                        case 2: wrmask = 1; break;
                        case 4: wrmask = 2; break;
                        case 8: wrmask = 3; break;
                        default: break;
                    }
                    return true;
                default: return true;
            }
        }
        if (port == 0x3ce)
        {
            seq = data;
            return true;
        }
        if (port == 0x3cf)
        {
            switch (seq)
            {
                case 4:
                    switch (data & 0x0f)
                    {
                        case 0: rdmask = 0; break;
                        case 1: rdmask = 1; break;
                        case 2: rdmask = 2; break;
                        case 3: rdmask = 3; break;
                        default: break;
                    }
                    return true;
                default: return true;
            }
        }
        if (port == 0x3d4)
        {
            reg3d4 = data;
            return true;
        }
        if (port == 0x3d5)
        {
            switch (reg3d4)
            {
                case 0x0c:
                    startAdr = (startAdr & 0x00ff) | (data << 8);
                    return true;
                case 0x0d:
                    startAdr = (startAdr & 0xff00) | data;
                    sync();
                    return true;
                case 0x13:
                    rowOffset = data;
                    return true;
                default:
                    return true;
            }
        }
        return false;
    }

    virtual bool Interrupt() override { return false; }

    virtual void Write(uint32_t dwAddr, uint8_t bWrite) override
    {
        int addr = dwAddr - 0xa000*16;
        if (wrmask == -1)
        {
            addr = addr * 4;
            if (addr < 0 || addr+3 >= (int)sizeof(buffer)) return;
            buffer[addr++] = bWrite;
            buffer[addr++] = bWrite;
            buffer[addr++] = bWrite;
            buffer[addr++] = bWrite;
            return;
        }
        addr = addr * 4 + wrmask;
        if (addr < 0 || addr >= (int)sizeof(buffer)) return;
        buffer[addr] = bWrite;
    }

    virtual uint8_t Read(uint32_t dwAddr) override
    {
        int addr = dwAddr - 0xa000*16;
        addr = addr * 4 + rdmask;
        if (addr < 0 || addr >= (int)sizeof(buffer)) return 0;
        return buffer[addr];
    }

    virtual uint32_t GetPixel(int x, int y) override
    {
        int ofs = startAdr*4;
        int addr = ofs + (y/5)*40*rowOffset + x + (y%5)*rowOffset*8;
        if (addr < 0 || addr >= (int)sizeof(buffer)) return 0;
        uint8_t c = buffer[addr];
        return (palette[3*c]*4) | ((palette[3*c+1]*4)<<8) | ((palette[3*c+2]*4)<<16);
    }
};
