BYTE MemAuto::Get8(WORD seg, WORD ofs)
{
    if (seg >= 0xa000)
        return MemVideo::Get8(seg, ofs);
    else
        return MemData::Get8(seg, ofs);
}

void MemAuto::Set8(WORD seg, WORD ofs, BYTE data)
{
    if (seg >= 0xa000)
        return MemVideo::Set8(seg, ofs, data);
    else
        return MemData::Set8(seg, ofs, data);
}

BYTE MemData::Get8(WORD seg, WORD ofs)
{
    _ASSERT(seg < 0xa000);
    return memory(seg, ofs);
}
void MemData::Set8(WORD seg, WORD ofs, BYTE data)
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
    assert(segment >= 0x1000 && segment < 0xa000);
    int ofs = segment*16 + offset;
    assert(ofs >= 0 && ofs < sizeof(data));
    return *(WORD*)(data + ofs);
}

BYTE& memory(WORD segment, WORD offset)
{
    assert(segment >= 0x1000 && segment < 0xa000);
    int ofs = segment*16 + offset;
    assert(ofs >= 0 && ofs < sizeof(data));
    return *(data + ofs);
}
