BYTE MemAuto::Get8(WORD seg, WORD ofs)
{
    _ASSERT(seg < 0xa000);
    return memory(seg, ofs);
}
void MemAuto::Set8(WORD seg, WORD ofs, BYTE data)
{
    _ASSERT(seg < 0xa000);
    memory(seg, ofs) = data;
}

BYTE MemVideo::Get8(WORD seg, WORD ofs)
{
    _ASSERT(seg >= 0xa000);
    return mVideo.Read(seg*16+ofs);
}
void MemVideo::Set8(WORD seg, WORD ofs, BYTE data)
{
    _ASSERT(seg >= 0xa000);
    mVideo.Write(seg*16+ofs, data);
}

BYTE memoryVideoGet(WORD seg, WORD ofs)
{
    MemVideo memoryVideo;
    return memoryVideo.Get8(seg, ofs);
}

WORD memoryVideoGet16(WORD seg, WORD ofs)
{
    MemVideo memoryVideo;
    return memoryVideo.Get8(seg, ofs) | (memoryVideo.Get8(seg, ofs+1)<<8);
}

void memoryVideoSet(WORD seg, WORD ofs, BYTE data)
{
    MemVideo memoryVideo;
    memoryVideo.Set8(seg, ofs, data);
}

void memoryVideoOr(WORD seg, WORD ofs, BYTE data)
{
    memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) | data);
}

void memoryVideoSet16(WORD seg, WORD ofs, WORD w)
{
    memoryVideoSet(seg, ofs+1, w>>8);
    memoryVideoSet(seg, ofs, w & 255);
}

void memoryVideoOr16(WORD seg, WORD ofs, WORD x)
{
    memoryVideoOr(seg, ofs, x&0xff);
    memoryVideoOr(seg, ofs+1, x>>8);
}

WORD& memory16(WORD segment, WORD offset)
{
    segment += appBase;
    _ASSERT(segment == 0x1020 || segment == 0x2499);
    
    _ASSERT(segment >= 0x1000);
    _ASSERT(segment >= 0x1000 && segment < 0xa000);
    int ofs = (segment-0x1000)*16 + offset;
    _ASSERT(ofs >= 0 && ofs < sizeof(datasegment));
    return *(WORD*)(datasegment + ofs);
}

BYTE& memory(WORD segment, WORD offset)
{
    if (segment == 0 && offset >= 0x2be &&offset <= 0x2be + 13)
    {
        int f = 9;
    }
    segment += appBase;
    _ASSERT(segment == 0x1020 || segment == 0x23ec || segment == 0x2499 || segment == 0x2411);

    _ASSERT(segment >= 0x1000 && segment < 0xa000);
    int ofs = (segment-0x1000)*16 + offset;
    _ASSERT(ofs >= 0 && ofs < sizeof(datasegment));
    return *(datasegment + ofs);
}
