static inline void sub_100685e0_inlined(uint32_t s, float value, uint8_t flag)
{
    const int count = (int32_t)memoryAGet32(ds, s + 0x2c);

    memoryFSet32(ds, s + 0x14, value);

    if ((float)count > value)
        memoryFSet32(ds, s + 0x14, floorf(value));

    if (flag || memoryAGet(ds, s + 0x30))
        memoryFSet32(ds, s + 0x18, floorf(memoryFGet32(ds, s + 0x14)));

    memoryASet(ds, s + 0x30, 0x01);
}

double subopt2_10062e20()
{
    StackGuard _sg(8, __FUNCTION__);

    const uint32_t s = memoryAGet32(ds, esp + 0x08);
    const float in = memoryFGet32(ds, esp + 0x04);

    const float v38 = memoryFGet32(ds, s + 0x38);

    if (memoryFGet32(ds, 0x100e6750) > v38)
    {
        esp += 8;
        return in;
    }

    float x34 = memoryFGet32(ds, s + 0x34);

    float curve;
    const float c6490 = memoryFGet32(ds, 0x100e6490);
    const float c74d4 = memoryFGet32(ds, 0x100e74d4);
    const float c7448 = memoryFGet32(ds, 0x100e7448);

    if (c6490 > x34)
    {
        curve = c7448 + x34 * (c7448 - x34 * c74d4);
    }
    else
    {
        const float d = x34 - c6490;
        curve = c7448 + d * (c7448 - d * c74d4);
    }

    x34 += curve / memoryFGet32(ds, ecx + 0x70);

    const int ix34 = (int)floorf(x34);
    x34 -= (float)ix34;
    memoryFSet32(ds, s + 0x34, x34);

    const int count = (int32_t)memoryAGet32(ds, s + 0x2c);

    const float callArg =
        (float)count * v38 * memoryFGet32(ds, 0x103cf534) * curve +
        (float)count * memoryFGet32(ds, 0x103d33f8);

    sub_100685e0_inlined(s, callArg, 0);
    ecx = s;

    float x18 = memoryFGet32(ds, s + 0x18);
    x18 += (memoryFGet32(ds, s + 0x14) - x18) * memoryFGet32(ds, s + 0x20);
    memoryFSet32(ds, s + 0x18, x18);

    const int i18 = (int)floorf(x18);
    const float frac = x18 - (float)i18;
    const float invFrac = 1.0f - frac;

    uint32_t writePtr = memoryAGet32(ds, s + 0x00);
    const uint32_t basePtr = memoryAGet32(ds, s + 0x04);
    const uint32_t endPtr = memoryAGet32(ds, s + 0x08);
    const uint32_t ringBytes = (uint32_t)count * 4u;

    uint32_t p0 = writePtr - (uint32_t)i18 * 4u;
    uint32_t p1 = p0 - 4u;

    if (p1 < basePtr)
        p1 += ringBytes;

    if (p0 < basePtr)
        p0 += ringBytes;

    const float a = memoryFGet32(ds, p1);
    const float b = memoryFGet32(ds, p0);
    const float interp = a + (b - a) * invFrac;

    float x10 = memoryFGet32(ds, s + 0x10);
    x10 += (interp - x10) * memoryFGet32(ds, s + 0x28);
    memoryFSet32(ds, s + 0x10, x10);

    float x0c = memoryFGet32(ds, s + 0x0c);
    x0c += (x10 - x0c) * memoryFGet32(ds, s + 0x24);
    memoryFSet32(ds, s + 0x0c, x0c);

    const float remainingFpuValue = x10 - x0c;

    const float out =
        in +
        memoryFGet32(ds, 0x103d33f0) +
        x0c +
        remainingFpuValue * memoryFGet32(ds, s + 0x1c);

    memoryFSet32(ds, writePtr, out);

    writePtr += 4;
    if (writePtr >= endPtr)
        writePtr -= ringBytes;

    memoryASet32(ds, s + 0x00, writePtr);

    esp += 8;
    return remainingFpuValue;
}

void sub_10062e20()
{
    fppush(subopt2_10062e20());
}