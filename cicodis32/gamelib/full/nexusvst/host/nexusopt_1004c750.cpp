#include <stdint.h>

const uint8_t g_decode_table[] = {
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0x02, 0x05, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfc, 0x06, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0x02, 0x05, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfb, 0x07, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0x02, 0x05, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfc, 0x06, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0x02, 0x05, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0x03, 0x08, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0x02, 0x05, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfc, 0x06, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0x02, 0x05, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfb, 0x07, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0x02, 0x05, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfc, 0x06, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0x02, 0x05, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfd, 0x04, 
0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0xfe, 0x03, 0x00, 0x02, 0x01, 0x02, 0xff, 0x02, 0x00, 0x08
};

#ifdef RASPIsloooow

#include <stdint.h>

typedef struct {
    const uint8_t *src;
    uint32_t bitbuf;
    int32_t bits;
} BitReader;

static inline uint8_t br_read8(BitReader *br)
{
    return *br->src++;
}

static inline void br_fill_to(BitReader *br, int32_t need)
{
    while (br->bits < need) {
        br->bitbuf |= (uint32_t)br_read8(br) << br->bits;
        br->bits += 8;
    }
}

static inline uint32_t br_get(BitReader *br, int32_t n)
{
    br_fill_to(br, n);

    uint32_t v = br->bitbuf & ((1u << n) - 1u);

    br->bitbuf >>= n;
    br->bits -= n;

    return v;
}

static inline int32_t read_signed_literal(BitReader *br, int32_t bits)
{
    if (bits == 0)
        return 0;

    uint32_t raw = br_get(br, bits);
    uint32_t sign = 1u << (bits - 1);

    if (raw & sign)
        return -(int32_t)(raw & ((1u << bits) - 1u));

    return (int32_t)((raw & (sign - 1u)) | sign);
}

static inline int32_t decode_prefix_literal(BitReader *br)
{
    br_fill_to(br, 8);

    uint32_t c = br->bitbuf & 0xffu;

    if (c != 0xffu) {
        int32_t value = (int8_t)g_decode_table[c * 2 + 0];
        int32_t used  = (int8_t)g_decode_table[c * 2 + 1];

        br->bitbuf >>= used;
        br->bits -= used;

        return value;
    }

    uint32_t consumed = 0;

    do {
        br->bitbuf >>= 8;
        br->bits -= 8;
        br_fill_to(br, 8);
        consumed += 8;
    } while ((br->bitbuf & 0xffu) == 0xffu);

    uint32_t n = consumed;

    for (;;) {
        n++;
        if (br_get(br, 1) == 0)
            break;
    }

    int32_t x = (int32_t)n;
    int32_t a = x + 1;

    if ((a % 3) == 0)
        return a / 3;

    return (x / 3) - x;
}

static void sub_1004c750_fast(uint32_t dst, uint32_t src, int32_t count)
{
    if (count == 0)
        return;

    BitReader br;
    br.src = (const uint8_t *)src;
    br.bitbuf = 0;
    br.bits = 0;

    uint8_t first = *br.src++;
    int wide = first & 1;

    uint8_t *outp = (uint8_t *)dst;

    int32_t delta = 0;
    int32_t value = 0;
    int32_t state = 0;

    while (count-- > 0) {
        int32_t prefix = decode_prefix_literal(&br);

        int32_t bits = (state >> 8) + prefix + 1;
        int32_t correction = (state + 16) >> 5;

        state += bits * 8 - correction;

        int32_t d2 = read_signed_literal(&br, bits);

        delta += d2;
        value += delta;

        if (wide) {
            uint32_t extra = br_get(&br, 4);
            uint32_t out = ((uint32_t)value << 4) | extra;

            outp[0] = (uint8_t)out;
            outp[1] = (uint8_t)(out >> 8);
            outp[2] = (uint8_t)(out >> 16);

            outp += 3;
        } else {
            *(uint16_t *)outp = (uint16_t)value;
            outp += 2;
        }
    }
}

void sub_1004c750(void)
{
    uint32_t dst   = *(uint32_t *)(esp + 0);
    int32_t count  = (int32_t)*(uint32_t *)(esp + 4);
    uint32_t src   = *(uint32_t *)(esp + 8);

    sub_1004c750_fast(dst, src, count);
}

#else

static inline int32_t _sar32(int32_t v, int n)
{
    return v >> n;
}

static inline void write16_emu(uint32_t p, int32_t v)
{
    memoryASet(ds, p + 0, (uint8_t)(v));
    memoryASet(ds, p + 1, (uint8_t)(v >> 8));
}

static inline void write24_emu(uint32_t p, int32_t v)
{
    memoryASet(ds, p + 0, (uint8_t)(v));
    memoryASet(ds, p + 1, (uint8_t)(v >> 8));
    memoryASet(ds, p + 2, (uint8_t)(v >> 16));
}

static int32_t decode_prefix_literal(uint32_t src,
                                     uint32_t *edi,
                                     uint32_t *ebx,
                                     int32_t *esi)
{
    uint32_t eax, ecx, edx;

    if (*esi < 8) {
        eax = memoryAGet(ds, src + *edi);
        ecx = (uint32_t)*esi;
        eax <<= ecx;
        (*edi)++;
        *ebx |= eax;
        *esi += 8;
    }

    ecx = (uint8_t)(*ebx);

    if (ecx != 0xff) {
        eax = (int8_t)g_decode_table[ecx * 2 + 0];
        ecx = (int8_t)g_decode_table[ecx * 2 + 1];

        *ebx >>= ecx;
        *esi -= (int32_t)ecx;

        return (int32_t)eax;
    }

    uint32_t consumed = 0;
    ecx = (uint32_t)(*esi - 8);

    do {
        edx = memoryAGet(ds, src + *edi);
        consumed += 8;
        edx <<= ecx;
        *ebx >>= 8;
        (*edi)++;
        *ebx |= edx;
    } while (((uint8_t)*ebx) == 0xff);

    ecx = consumed;

    for (;;) {
        ecx++;

        if (*esi == 0) {
            *ebx = memoryAGet(ds, src + *edi);
            (*edi)++;
            *esi = 7;
        } else {
            (*esi)--;
        }

        eax = *ebx & 1;
        *ebx >>= 1;

        if (!eax)
            break;
    }

    /*
        This matches:

            eax = ecx + 1;
            edx = sign(eax);
            idiv 3;
            if remainder == 0:
                return quotient;

            eax = magic_div3(ecx) - ecx;
    */

    int32_t n = (int32_t)ecx;
    int32_t a = n + 1;

    if ((a % 3) == 0)
        return a / 3;

    return (n / 3) - n;
}

static int32_t read_signed_literal(uint32_t src,
                                   uint32_t *edi,
                                   uint32_t *ebx,
                                   int32_t *esi,
                                   int32_t bits)
{
    uint32_t eax, ecx, edx;

    if (bits == 0)
        return 0;

    while (bits > *esi) {
        edx = memoryAGet(ds, src + *edi);
        ecx = (uint32_t)*esi;
        edx <<= ecx;
        *esi += 8;
        (*edi)++;
        *ebx |= edx;
    }

    ecx = (uint32_t)bits;
    uint32_t raw = *ebx;

    *ebx >>= ecx;

    ecx = (uint32_t)(bits - 1);
    edx = 1u << ecx;

    *esi -= bits;

    if (raw & edx) {
        edx = 1u << bits;
        edx--;
        edx &= raw;
        return -(int32_t)edx;
    } else {
        edx--;
        edx &= raw;
        edx |= 1u << (bits - 1);
        return (int32_t)edx;
    }
}

static void sub_1004c750_dropin_emulated(uint32_t dst,
                                         uint32_t src,
                                         int32_t count)
{
    uint32_t edi = 0;
    uint32_t ebx = 0;
    int32_t esi = 0;

    int32_t delta = 0;
    int32_t value = 0;
    int32_t state = 0;

    uint8_t first = memoryAGet(ds, src + edi);
    edi++;

    if (count == 0)
        return;

    int wide = first & 1;

    while (count--) {
        int32_t prefix = decode_prefix_literal(src, &edi, &ebx, &esi);

        int32_t bits = _sar32(state, 8) + prefix + 1;

        int32_t correction = _sar32(state + 16, 5);
        state += bits * 8 - correction;

        int32_t d2 = read_signed_literal(src, &edi, &ebx, &esi, bits);

        delta += d2;
        value += delta;

        if (wide) {
            while (esi < 4) {
                uint32_t eax = memoryAGet(ds, src + edi);
                uint32_t ecx = (uint32_t)esi;
                eax <<= ecx;
                esi += 8;
                edi++;
                ebx |= eax;
            }

            uint32_t extra = ebx & 0x0f;
            int32_t out = (value << 4) | extra;

            write24_emu(dst, out);
            dst += 3;

            ebx >>= 4;
            esi -= 4;
        } else {
            write16_emu(dst, value);
            dst += 2;
        }
    }
}

void sub_1004c750()
{
    /*
        Generated calling convention:

            [esp + 0] = dst
            [esp + 4] = count
            [esp + 8] = src
    */

    uint32_t dst = memoryAGet32(ds, esp + 0);
    int32_t count = (int32_t)memoryAGet32(ds, esp + 4);
    uint32_t src = memoryAGet32(ds, esp + 8);

    sub_1004c750_dropin_emulated(dst, src, count);
}
#endif