// alleg40.h
// Allegro 4.0 Library Function Declarations
// Contains only functions imported by the application

#ifndef ALLEG40_H
#define ALLEG40_H

#include "alleg40tools.h"
uint32_t ptrDefaultFont = 0;
uint32_t ptrAllegKeys = 0;
uint8_t* screenPixels = nullptr;
void renderPixels(uint8_t*, uint32_t*);
void renderScreen();
uint8_t* MemoryGetPtr(int s, int o);
extern int allocatorLast;
extern std::vector<uint8_t> allocator;
uint32_t ptrShared = 0;

template <typename T> T* _cicoptr(uint32_t ptr)
{
    uint32_t* token = (uint32_t*)&allocator[ptr-allocatorBase-4];
    assert(*token == 0x12345678);
    return (T*)&allocator[ptr-allocatorBase];
}

uint32_t _alloc(size_t size)
{
    uint32_t ptr = allocatorLast;
    allocatorLast += size+4;
    printf("Alloc %d @ 0x%x\n", size, ptr);
    uint32_t token = 0x12345678;
    uint8_t* real = &allocator[ptr-allocatorBase];

    memset(real, 0, size);
    memcpy(real, &token, 4);
    assert(allocatorLast < allocator.size());
    return ptr+4;
}
/*
template<typename T> struct CicoAlloc_t
{
    void* self;
    T* data;
    uint32_t cicoptr;
};

CicoAlloc_t _cicoalloc(int size)
{
    return CicoAlloc_t{.self = _alloc
    
}
*/

void playSound(uint8_t* ptr, int len, int samplerate, const char* fmt, bool loop);

void sub_404d90();
#ifdef __cplusplus
// RGB structure - represents a single palette entry
struct RGB {
    unsigned char r, g, b;
    unsigned char filler;
};

// PALETTE - array of 256 RGB entries
typedef struct RGB PALETTE[256];


typedef struct BITMAP            /* a bitmap structure */
{
   int32_t w, h;                     /* width and height in pixels */
    int32_t clip;                     /* flag if clipping is turned on */
    int32_t cl, cr, ct, cb;           /* clip left, right, top and bottom values */
    uint32_t ptr_vtable; //GFX_VTABLE ptr_vtable;           /* drawing functions */
    uint32_t ptr_write_bank; //void *write_bank;             /* C func on some machines, asm on i386 */
    uint32_t ptr_read_bank; //void *read_bank;              /* C func on some machines, asm on i386 */
    uint32_t ptr_dat; //void *dat;                    /* the memory we allocated for the bitmap */
   uint32_t id;             /* for identifying sub-bitmaps */
    uint32_t ptr_extra; //void *extra;                  /* points to a structure with more info */
    int32_t x_ofs;                    /* horizontal offset (for sub-bitmaps) */
    int32_t y_ofs;                    /* vertical offset (for sub-bitmaps) */
    int32_t seg;                      /* bitmap segment */
   uint32_t ptr_line[0]; // @ 17*4
} BITMAP;

// SAMPLE structure - digital sound sample
//struct SAMPLE {
//    int bits;                   // 8 or 16
//    int stereo;                 // sample type flag
//    int freq;                   // sample frequency
//    int priority;               // 0-255
//    unsigned long len;          // length (in samples)
//    unsigned long loop_start;   // loop start position
//    unsigned long loop_end;     // loop finish position
//    unsigned long param;        // for internal use by the driver
//    void *data;                 // sample data
//};
//
// DATAFILE structure - holds resources loaded from datafile
struct DATAFILE {
    uint32_t ptrdata;
    uint32_t type;
    uint32_t size;
    uint32_t ptrprop;
//
//    void *dat;                  // pointer to the data
//    int type;                   // object type ID
//    long size;                  // size of the object
//    void *prop;                 // properties
};

typedef struct SAMPLE                  /* a sample */
{
   int32_t bits;                           /* 8 or 16 */
    int32_t stereo;                         /* sample type flag */
   int32_t freq;                           /* sample frequency */
    int32_t priority;                       /* 0-255 */
   uint32_t len;                  /* length (in samples) */
    uint32_t loop_start;           /* loop start position */
    uint32_t loop_end;             /* loop finish position */
    uint32_t param;                /* for internal use by the driver */
   uint32_t ptrdata;                         /* sample data */
} SAMPLE;

// FONT structure
struct FONT {
    int32_t magic{0x6ab0f0f0};
    int32_t height;
    int32_t ptrBitmaps[0x80-0x20];
//    void *data;                 // font data
//    int height;                 // font height
//    void *vtable;               // font vtable for rendering
};

// PACKFILE structure - for file I/O
struct PACKFILE {
    int flags;                  // PACKFILE flags
    void *pack_data;            // compressor specific data
    int (*pack_getc)(void *);   // read a character
    int (*pack_putc)(int, void *); // write a character
    long (*pack_fread)(void *, long, void *); // read n bytes
    long (*pack_fwrite)(const void *, long, void *); // write n bytes
    int (*pack_fseek)(void *, int); // seek to position
    int (*pack_fclose)(void *); // close the file
    void *parent;               // parent PACKFILE
    void *pack_data2;           // more compressor specific data
    int todo;                   // bytes remaining to be read
    void *normal_data;          // normal file data
};

// COLOR_MAP structure - for lighting/transparency effects
struct COLOR_MAP {
    unsigned char data[256][256];
};

// RGB_MAP structure - for fast color conversions
struct RGB_MAP {
    unsigned char data[32][32][32];
};

// JOYSTICK_INFO structure
struct JOYSTICK_INFO {
    int flags;                  // status flags for this joystick
    int num_sticks;            // how many stick inputs?
    int num_buttons;           // how many buttons?
    struct {
        int flags;             // status flags for this stick
        int num_axis;         // how many axis inputs?
        struct {
            int pos;          // analog axis position
            int d1, d2;       // digital axis position
            const char *name; // axis name
        } axis[3];            // stick axis data
        const char *name;     // stick name
    } stick[5];               // stick data
    struct {
        int b;                // boolean on/off flag
        const char *name;     // button name
    } button[32];             // button data
};

//typedef struct BITMAP BITMAP;
typedef struct RGB RGB;
typedef struct SAMPLE SAMPLE;
typedef struct DATAFILE DATAFILE;
typedef struct FONT FONT;
typedef struct PACKFILE PACKFILE;
typedef struct COLOR_MAP COLOR_MAP;
typedef struct RGB_MAP RGB_MAP;
typedef struct JOYSTICK_INFO JOYSTICK_INFO;

PALETTE currentPalette;
namespace alleg40 {
#endif

// Allegro uses __cdecl calling convention
#ifndef ALLEGRO_CC
#define ALLEGRO_CC __cdecl
#endif

// Forward declarations for Allegro types


// Global variables (exported as data)
extern const int *_cos_tbl;
extern const char *allegro_error;
extern FONT *font;
extern COLOR_MAP *color_map;
extern BITMAP *screen;
extern RGB_MAP *rgb_map;
extern PALETTE black_palette;
extern PALETTE desktop_palette;
extern JOYSTICK_INFO *joy;
extern volatile char *key;



// Function declarations (ordinal_7) _cos_tbl
void ALLEGRO_CC adjust_sample(CicoPtr<SAMPLE*> spl, int vol, int pan, int freq, int loop) {
//    printf("SKIP ----- %s\n", __FUNCTION__);
}
void ALLEGRO_CC alert(CicoPtr<const char*> s1, CicoPtr<const char*> s2, CicoPtr<const char*> s3, CicoPtr<const char*> b1, CicoPtr<const char*> b2, int c1, int c2) {assert(0);}
void ALLEGRO_CC allegro_exit(void) { exit(1); }
void ALLEGRO_CC allegro_message(CicoPtr<const char*> msg, ...) {
    printf("allegro_message: %s\n", MemoryGetPtr(0, msg));
//    assert(0);
}
//void ALLEGRO_CC blit(CicoPtr<BITMAP*> source, CicoPtr<BITMAP*> dest, int source_x, int source_y, int dest_x, int dest_y, int width, int height) {
//    BITMAP* pDest = _cicoptr<BITMAP>(dest);
//    BITMAP* pSource = _cicoptr<BITMAP>(source);
//    
//    uint8_t* pPixelsDest = _cicoptr<uint8_t>(pDest->ptr_dat);
//    uint8_t* pPixelsSource = _cicoptr<uint8_t>(pSource->ptr_dat);
//
//    assert(source_x==0 && source_y==0 && dest_x == 0 && dest_y == 0 && width == 640 && height == 480);
//    assert(pSource->w == pDest->w && pSource->h == pDest->h);
//    
//    for (int ty=0; ty<pDest->h; ty++)
//        for (int tx=0; tx<pDest->w; tx++)
//            pPixelsDest[ty*pDest->w+tx] = pPixelsSource[ty*pSource->w+tx];
//}

void ALLEGRO_CC blit(CicoPtr<BITMAP*> source, CicoPtr<BITMAP*> dest,
                      int source_x, int source_y,
                      int dest_x, int dest_y,
                      int width, int height)
{
    
    BITMAP* pDest = _cicoptr<BITMAP>(dest);
    BITMAP* pSource = _cicoptr<BITMAP>(source);
    
    uint8_t* pPixelsDest = _cicoptr<uint8_t>(pDest->ptr_dat);
    uint8_t* pPixelsSource = _cicoptr<uint8_t>(pSource->ptr_dat);

    // Clip left/top if dest_x/dest_y is negative
    if (dest_x < 0) {
        source_x -= dest_x;      // skip pixels in source
        width += dest_x;         // reduce width
        dest_x = 0;
    }
    if (dest_y < 0) {
        source_y -= dest_y;
        height += dest_y;
        dest_y = 0;
    }

    // Clip right/bottom if out of bounds
    if (source_x + width > pSource->w)
        width = pSource->w - source_x;
    if (source_y + height > pSource->h)
        height = pSource->h - source_y;
    if (dest_x + width > pDest->w)
        width = pDest->w - dest_x;
    if (dest_y + height > pDest->h)
        height = pDest->h - dest_y;

    // Nothing to blit if width or height <= 0
    if (width <= 0 || height <= 0)
        return;

    // Copy each row
    for (int ty = 0; ty < height; ty++) {
        memcpy(
            pPixelsDest + (dest_y + ty) * pDest->w + dest_x,
            pPixelsSource + (source_y + ty) * pSource->w + source_x,
            width
        );
    }}
void vtable_rectfill(CicoPtr<BITMAP*> bmp, int x1, int y1, int x2, int y2, int c);

void ALLEGRO_CC clear_bitmap(CicoPtr<BITMAP*> bitmap) {
    BITMAP* bmp = _cicoptr<BITMAP>(bitmap);

    vtable_rectfill(bitmap, 0, 0, bmp->w, bmp->h, 0);
}
void ALLEGRO_CC clear_keybuf(void) {assert(0);}
CicoPtr<BITMAP*> ALLEGRO_CC create_bitmap(int width, int height) {
    uint32_t ptrBitmap = _alloc(sizeof(BITMAP) + height*4);
    uint32_t ptrBitmapData = _alloc(width*height);
    BITMAP* pBitmap = _cicoptr<BITMAP>(ptrBitmap); //(BITMAP*)&allocator[ptrBitmap-allocatorBase];
    pBitmap->ptr_dat = ptrBitmapData;
    pBitmap->w = width;
    pBitmap->h = height;
    pBitmap->ptr_read_bank = 0x6ab10009;
    pBitmap->ptr_write_bank = 0x6ab1000b;
    uint32_t ptrVtable = _alloc(50*4);
    pBitmap->ptr_vtable = ptrVtable;
    memoryASet32(0, ptrVtable, 8); // bit_depth
    memoryASet32(0, ptrVtable+0x44, 0x6ab10003); // draw_256_sprite
    memoryASet32(0, ptrVtable+0x4c, 0x6ab1000c); // draw_256_sprite _hflip!!!
    memoryASet32(0, ptrVtable+0xa0, 0x6ab10004); // pivot_scaled_sprite_flip
    memoryASet32(0, ptrVtable+0x34, 0x6ab10005); // line
    memoryASet32(0, ptrVtable+0x38, 0x6ab10006); // rectfill
    memoryASet32(0, ptrVtable+0x10, 0x6ab10007); // acquire
    memoryASet32(0, ptrVtable+0x14, 0x6ab10008); // release
    memoryASet32(0, ptrVtable+0x8, 0x6ab1000a); // unwrite bank

//    for (int i=0; i<height; i++)
//        pBitmap->ptr_line[i] = ptrBitmapData + i*width;
    printf("OK ----- %s(0x%x, vtable=%x) width=%d height=%d\n", __FUNCTION__, ptrBitmap, ptrVtable, width, height);
    return ptrBitmap;
    //assert(0);
}
void ALLEGRO_CC destroy_bitmap(CicoPtr<BITMAP*> bitmap) {}
void ALLEGRO_CC destroy_sample(CicoPtr<SAMPLE*> spl) {}
void ALLEGRO_CC drawing_mode(int mode, CicoPtr<BITMAP*> pattern, int x_anchor, int y_anchor) {
    printf("SKIP ----- %s\n", __FUNCTION__);
}
int ALLEGRO_CC exists(CicoPtr<const char*> filename) {
    char* str = (char*)MemoryGetPtr(0, filename);
    printf("SKIP ----- %s(%s)\n", __FUNCTION__, str);
    return 0;
}
void ALLEGRO_CC fade_in(CicoPtr<const PALETTE> pal, int speed) {
    RGB* p = _cicoptr<RGB>(pal);
    for (int i=0; i<256; i++)
    {
        currentPalette[i].r = p[i].r*4;
        currentPalette[i].g = p[i].g*4;
        currentPalette[i].b = p[i].b*4;
    }
}
void ALLEGRO_CC fade_out(int speed) {
    printf("SKIP ----- %s\n", __FUNCTION__);
}
int ALLEGRO_CC install_allegro(int system_id, CicoPtr<int*> errno_ptr, CicoPtr<int (*)(void (*func)(void))>) {
//    assert(0);
    return 1;
}
void ALLEGRO_CC install_int(void (*proc)(void), long speed) {assert(0);}
void ALLEGRO_CC install_joystick(int type) {}
void ALLEGRO_CC install_keyboard(void) { }
int ALLEGRO_CC install_sound(int digi, int midi, CicoPtr<const char*> cfg_path) { return 1; }
void ALLEGRO_CC install_timer(void) {}
int ALLEGRO_CC keypressed(void) {assert(0);}
CicoPtr<DATAFILE*> ALLEGRO_CC load_datafile(CicoPtr<const char*> filename) {
    char* str = (char*)MemoryGetPtr(0, filename);
    char* part = strstr(str, "/");
    assert(part);
    part++;
    
    std::vector<uint8_t> data = load_file(part);
    if (data.size() == 0)
    {
        printf("FAIL ----- LOAD DATAFILE: %s\n", MemoryGetPtr(0, filename));
        return 0;
    }
    printf("OK ----- LOAD DATAFILE: %s\n", MemoryGetPtr(0, filename));
    data = decompress_lzss(data);
    std::vector<dataresource_t> resources = load_allegro_datafile(data);

    uint32_t ptrResult = _alloc(4*4*resources.size());
    for (int i=0; i<resources.size(); i++)
    {
        dataresource_t& res = resources[i];
        uint32_t ptrPayload;
        switch (res.type)
        {
            case dataresource_t::type_e::PAL:
                assert(res.payload.size() == 1024);
                ptrPayload = _alloc(res.payload.size());
                memcpy(_cicoptr<void>(ptrPayload), &res.payload[0], res.payload.size());
                break;
            case dataresource_t::type_e::BMP:
            {
                int bits = res.payload[0]*256 + res.payload[1];
                int w = res.payload[2]*256 + res.payload[3];
                int h = res.payload[4]*256 + res.payload[5];
                assert(res.payload.size() == w*h+6);
                assert(bits == 8);
                ptrPayload = create_bitmap(w, h);
                BITMAP* bmp = _cicoptr<BITMAP>(ptrPayload);
                uint8_t* pixels = _cicoptr<uint8_t>(bmp->ptr_dat);
                memcpy(pixels, &res.payload[6], w*h);
                break;
            }
            case dataresource_t::type_e::FONT:
            {
                ptrPayload = _alloc(sizeof(FONT));
                FONT* font = _cicoptr<FONT>(ptrPayload);
                
                if (ptrDefaultFont == 0)
                    ptrDefaultFont = ptrPayload;

                font->height = 0;
                int type = res.payload[0]*256 + res.payload[1];
                int ranges = res.payload[2]*256 + res.payload[3];
                int mono = res.payload[4];
                assert(type == 0 && ranges == 1);
                if (mono)
                {
                    int begin = res.payload[5]*256*256*256 + res.payload[6]*256*256 + res.payload[7]*256 + res.payload[8];
                    int end = res.payload[9]*256*256*256 + res.payload[10]*256*256 + res.payload[11]*256 + res.payload[12];
                    assert(begin == 0x20 && end == 0x7f);
                    int pos = 13;
                    for (int c = begin; c < end; c++)
                    {
                        int w = res.payload[pos]*256 + res.payload[pos+1];
                        int h = res.payload[pos+2]*256 + res.payload[pos+3];
                        assert(w < 100 && h < 100 && w > 1 && h > 4);
                        if (h > font->height)
                            font->height = h;
                        pos += 4;
                        int pitch = (w + 7) / 8;
                        
                        // store c, w, h, data
                        uint32_t ptrBitmap = create_bitmap(w, h);
                        BITMAP* bmp = _cicoptr<BITMAP>(ptrBitmap);
                        uint8_t* pixels = _cicoptr<uint8_t>(bmp->ptr_dat);
                        for (int y=0; y<h; y++)
                            for (int x=0; x<h; x++)
                                pixels[y*w+x] = res.payload[pos+y*pitch+x/8] &(128>>(x&7)) ? 15 : 0; //es.payload[pos++];
                        pos += pitch*h;
                        font->ptrBitmaps[c-begin] = ptrBitmap;
                    }
                } else {
                    int begin = res.payload[5]*256*256*256 + res.payload[6]*256*256 + res.payload[7]*256 + res.payload[8];
                    int end = res.payload[9]*256*256*256 + res.payload[10]*256*256 + res.payload[11]*256 + res.payload[12];
                    int pos = 13;
                    for (int c = begin; c < end; c++)
                    {
                        int bits = 8;
                        int w = res.payload[pos+0]*256 + res.payload[pos+1];
                        int h = res.payload[pos+2]*256 + res.payload[pos+3];
                        assert(bits == 8);
                        assert(w < 100 && h < 100 && w > 4 && h > 4);
                        if (h > font->height)
                            font->height = h;
                        
                        pos += 4;
                        uint32_t ptrBitmap = create_bitmap(w, h);
                        BITMAP* bmp = _cicoptr<BITMAP>(ptrBitmap);
                        uint8_t* pixels = _cicoptr<uint8_t>(bmp->ptr_dat);
                        for (int y=0; y<h; y++)
                            for (int x=0; x<w; x++)
                                pixels[y*w+x] = res.payload[pos++];
                        font->ptrBitmaps[c-begin] = ptrBitmap;
                    }
                }
                
                break;
            }
            case dataresource_t::type_e::SAMP:
            {
                int bits = res.payload[0]*256 + res.payload[1];
                assert(bits == 16);
                int freq = res.payload[2]*256 + res.payload[3];
                assert(freq == 44100 || freq == 11025);
                int len = res.payload[4]*256*256*256 + res.payload[5]*256*256 + res.payload[6]*256 + res.payload[7];
                assert(len*2+8 == res.payload.size());
                
                ptrPayload = _alloc(sizeof(SAMPLE));
                uint32_t ptrSampleData = _alloc(len*2);
                
                SAMPLE* smp = _cicoptr<SAMPLE>(ptrPayload);
                smp->bits = 16;
                smp->freq = freq;
                smp->len = len;
                smp->ptrdata = ptrSampleData;
                
                uint8_t* smpdata = _cicoptr<uint8_t>(smp->ptrdata);
                memcpy(smpdata, &res.payload[8], len*2);
                break;
            }
        }
        *((uint32_t*)MemoryGetPtr(0, ptrResult+i*4*4)) = ptrPayload;
        *((uint32_t*)MemoryGetPtr(0, ptrResult+i*4*4+4)) = 0x6ab07777;
        *((uint32_t*)MemoryGetPtr(0, ptrResult+i*4*4+8)) = (uint32_t)resources[i].payload.size();
        *((uint32_t*)MemoryGetPtr(0, ptrResult+i*4*4+12)) = 0;
    }
    return ptrResult;

//    uint32_t ptrdata;
//    uint32_t type;
//    uint32_t size;
//    uint32_t ptrprop;

    if (strcmp(str, "data/data.dat") == 0 || strcmp(str, "data/sfx_11.dat") == 0)
    {
        uint32_t ptr1 = _alloc(1024*32);
        uint32_t ptr2 = _alloc(1024*4);
        *((uint32_t*)MemoryGetPtr(0, ptr1)) = ptr2;
        return ptr1;
    }
    else
        return 0;
}
CicoPtr<SAMPLE*> ALLEGRO_CC load_wav(CicoPtr<const char*> filename) {assert(0);}
void ALLEGRO_CC masked_blit(CicoPtr<BITMAP*> source, CicoPtr<BITMAP*> dest, int source_x, int source_y, int dest_x, int dest_y, int width, int height) {
    blit(source, dest, source_x, source_y, dest_x, dest_y, width, height);
    
}
CicoPtr<PACKFILE*> ALLEGRO_CC pack_fclose(CicoPtr<PACKFILE*> f) {assert(0);}
CicoPtr<PACKFILE*> ALLEGRO_CC pack_fopen(CicoPtr<const char*> filename, CicoPtr<const char*> mode) {
    char* str = (char*)MemoryGetPtr(0, filename);
    printf("SKIP ----- PACK_FOPEN: %s\n", MemoryGetPtr(0, filename));
    return 0;
}
int ALLEGRO_CC pack_fread(CicoPtr<void*> p, long n, CicoPtr<PACKFILE*> f) {assert(0);}
int ALLEGRO_CC pack_fwrite(CicoPtr<const void*> p, long n, CicoPtr<PACKFILE*> f) {assert(0);}
void ALLEGRO_CC get_palette(PALETTE p) {assert(0);}
void ALLEGRO_CC get_palette_range(CicoPtr<PALETTE> p, int from, int to) {
//    RGB* pal = _cicoptr<RGB>(p);
    
    for (int i=from; i<to; i++)
    {
        memoryASet(0, p.ptr+i*4, currentPalette[i].r/4);
        memoryASet(0, p.ptr+i*4+1, currentPalette[i].g/4);
        memoryASet(0, p.ptr+i*4+2, currentPalette[i].b/4);
    }
}

int ALLEGRO_CC play_sample(CicoPtr<const SAMPLE*> spl, int vol, int pan, int freq, int loop) {
    SAMPLE* smp = _cicoptr<SAMPLE>(spl);
    uint8_t* data = _cicoptr<uint8_t>(smp->ptrdata);
    assert(smp->bits == 16 && smp->freq == 11025);
    playSound(data, smp->len, smp->freq, "u16", loop);
    return 0;
    //printf("SKIP ----- play_sample: %x\n", spl.ptr);
    //return 1;
}
int ALLEGRO_CC poll_joystick(void) {assert(0);}
int ALLEGRO_CC readkey(void) {assert(0);}
void ALLEGRO_CC save_pcx(CicoPtr<const char*> filename, CicoPtr<BITMAP*> bmp, CicoPtr<const PALETTE> pal) {assert(0);}
void ALLEGRO_CC set_clip(CicoPtr<BITMAP*> bitmap, int x1, int y1, int x2, int y2) {
    printf("SKIP ----- %s(%d %d %d %d)\n", __FUNCTION__, x1, y1, x2, y2);
}
void ALLEGRO_CC set_color_depth(int depth) {
    printf("SKIP ----- %s\n", __FUNCTION__);
}
int ALLEGRO_CC set_gfx_mode(int card, int w, int h, int v_w, int v_h) {
    printf("SKIP ----- %s\n", __FUNCTION__);
    return 0;
}
int ALLEGRO_CC set_display_switch_mode(int mode) {
    printf("SKIP ----- %s(%d)\n", __FUNCTION__, mode);
    return 0;
}
void ALLEGRO_CC set_palette(CicoPtr<const PALETTE> pal) {
    RGB* p = _cicoptr<RGB>(pal);
    for (int i=0; i<256; i++)
    {
        currentPalette[i].r = p[i].r*4;
        currentPalette[i].g = p[i].g*4;
        currentPalette[i].b = p[i].b*4;
    }

//    printf("SKIP ----- %s(%d)\n", __FUNCTION__, p);
//    memcpy(currentPalette, _cicoptr<PALETTE>(p), sizeof(currentPalette));
}
void ALLEGRO_CC set_palette_range(CicoPtr<const PALETTE> pal, int from, int to, int vsync) {
//    RGB* p = _cicoptr<RGB>(pal);
    for (int i=from; i<to; i++)
    {
        currentPalette[i].r = memoryAGet(0, pal.ptr+i*4)*4;
        currentPalette[i].g = memoryAGet(0, pal.ptr+i*4+1)*4;
        currentPalette[i].b = memoryAGet(0, pal.ptr+i*4+2)*4;
    }
}
void ALLEGRO_CC solid_mode(void) {
    printf("SKIP ----- %s\n", __FUNCTION__);
}
void ALLEGRO_CC stop_sample(CicoPtr<const SAMPLE*> spl) {
    printf("SKIP ----- %s\n", __FUNCTION__);
}
void ALLEGRO_CC stretch_blit(CicoPtr<BITMAP*> s, CicoPtr<BITMAP*> d, int s_x, int s_y, int s_w, int s_h, int d_x, int d_y, int d_w, int d_h) {assert(0);}
int ALLEGRO_CC text_height(CicoPtr<const FONT*> f) {
    FONT* font = _cicoptr<FONT>(f);
    if (!font->ptrBitmaps[0])
        font = _cicoptr<FONT>(ptrDefaultFont);
    return font->height;
}
int  text_length(CicoPtr<const FONT*> f, const char* _str) {
    FONT* font = _cicoptr<FONT>(f);
    if (!font->ptrBitmaps[0])
        font = _cicoptr<FONT>(ptrDefaultFont);
    int w = 0;
    while (*_str)
    {
        char c = *_str++;
        assert(c >= 0x20 && c <= 0x7f);
        w += _cicoptr<BITMAP>(font->ptrBitmaps[c-0x20])->w;
    }
    return w;
}

int ALLEGRO_CC text_length(CicoPtr<const FONT*> f, CicoPtr<const char*> str) {
    char* _str = (char*)MemoryGetPtr(0, str);
    return text_length(f, _str);
}

void ALLEGRO_CC text_mode(int mode) {
    printf("SKIP ----- %s(%d)\n", __FUNCTION__, mode);
}
void vtable_draw_256_sprite(CicoPtr<BITMAP*> bmp, CicoPtr<BITMAP*> sprite, int x, int y);

void textout(CicoPtr<BITMAP*> bmp, CicoPtr<const FONT*> f, char* _str, int x, int y, int color, char align) {
    if (strstr(_str, "%"))
    {
        int f = 9;
    }
    if (align=='c')
        x -= text_length(f, _str)/2;
    else if (align=='r')
        x -= text_length(f, _str);
    
    FONT* font = _cicoptr<FONT>(f);
    if (!font->ptrBitmaps[0])
        font = _cicoptr<FONT>(ptrDefaultFont);
    while (*_str)
    {
        char c = *_str++;
        assert(c >= 0x20 && c <= 0x7f);
        if (!font->ptrBitmaps[c-0x20])
            continue;
        vtable_draw_256_sprite(bmp, font->ptrBitmaps[c-0x20], x, y);
        x += _cicoptr<BITMAP>(font->ptrBitmaps[c-0x20])->w;
    }
}

void ALLEGRO_CC textout(CicoPtr<BITMAP*> bmp, CicoPtr<const FONT*> f, CicoPtr<const char*> s, int x, int y, int color) {
    char* _str = (char*)MemoryGetPtr(0, s);
    textout(bmp, f, _str, x, y, color, 'l');
}
void ALLEGRO_CC textout_centre(CicoPtr<BITMAP*> bmp, CicoPtr<const FONT*> f, CicoPtr<const char*> s, int x, int y, int color)
{
    char* _str = (char*)MemoryGetPtr(0, s);
    textout(bmp, f, _str, x, y, color, 'c');
}
void ALLEGRO_CC textprintf(CicoPtr<BITMAP*> bmp, CicoPtr<const FONT*> f, int x, int y, int color, CicoPtr<const char*> fmt, ...) {
    char* strFmt = (char*)MemoryGetPtr(0, fmt);
    if (strcmp(strFmt, "%s") == 0)
    {
        textout(bmp, f, stack32<const char *>(6), x, y, color);
        return;
    }
    if (strcmp(strFmt, "%d") == 0)
    {
        char* temp = _cicoptr<char>(ptrShared);
//        char temp[1024];
        sprintf(temp, "%d", stack32<const char *>(6));
        textout(bmp, f, ptrShared, x, y, color);
        return;
    }
    if (strcmp(strFmt, "score: %d") == 0)
    {
        char* temp = _cicoptr<char>(ptrShared);
        sprintf(temp, "score: %d", stack32<const char *>(6));
        textout(bmp, f, ptrShared, x, y, color);
        return;
    }
    //
    char* _str = (char*)MemoryGetPtr(0, fmt);
    //char* arg0 = (char*)MemoryGetPtr(0, stack32<const char *>(6));
    printf("SKIP ----- %s('%s' x=%d y=%d c=0x%x)\n", __FUNCTION__, _str, x, y, color);
}
void ALLEGRO_CC textprintf_centre(CicoPtr<BITMAP*> bmp, CicoPtr<const FONT*> f, int x, int y, int color, CicoPtr<const char*> fmt, ...) {
    char* strFmt = (char*)MemoryGetPtr(0, fmt);
    if (strcmp(strFmt, "%d") == 0 || strcmp(strFmt, "You reached Level %d.") == 0)
    {
        char temp[128];
        sprintf(temp, strFmt, stack32<const char *>(6));
        textout(bmp, f, temp, x, y, color, 'c');
        return;
    }
    textout(bmp, f, strFmt, x, y, color, 'c');
    //printf("SKIP ----- %s('%s' x=%d y=%d c=0x%x)\n", __FUNCTION__, strFmt, x, y, color);
//    assert(0);
}
void ALLEGRO_CC textprintf_right(CicoPtr<BITMAP*> bmp, CicoPtr<const FONT*> f, int x, int y, int color, CicoPtr<const char*> fmt, ...) {
    char* strFmt = (char*)MemoryGetPtr(0, fmt);
    //char* arg0 = (char*)MemoryGetPtr(0, stack32<const char *>(6));
    if (strcmp(strFmt, "%d") == 0)
    {
        char temp[32];
        sprintf(temp, "%d", stack32<int>(6));
        textout(bmp, f, temp, x, y, color, 'r');
        return;
    }
    char* _str = (char*)MemoryGetPtr(0, fmt);
    printf("SKIP ----- %s('%s' x=%d y=%d c=0x%x)\n", __FUNCTION__, strFmt, x, y, color);
}
void ALLEGRO_CC unload_datafile(CicoPtr<DATAFILE*> dat) {}
void ALLEGRO_CC create_rgb_table(CicoPtr<RGB_MAP*> table, CicoPtr<const PALETTE> pal, CicoPtr<void (*)(int pos)> callback) {
    RGB* p = _cicoptr<RGB>(pal);
    for (int i=0; i<256; i++)
    {
        currentPalette[i].r = p[i].r*4;
        currentPalette[i].g = p[i].g*4;
        currentPalette[i].b = p[i].b*4;
    }
//    memcpy(currentPalette, _cicoptr<PALETTE>(pal), sizeof(currentPalette));
//    printf("SKIP ----- create_rgb_table\n");
}
void ALLEGRO_CC create_light_table(CicoPtr<COLOR_MAP*> table, CicoPtr<const PALETTE> pal, int r, int g, int b, CicoPtr<void (*)(int pos)> callback) {
    printf("SKIP ----- %s\n", __FUNCTION__);
}
int ALLEGRO_CC _WinMain(CicoPtr<void*> hInst, CicoPtr<void*> hPrev, CicoPtr<char*> Cmd, int nShow) {
    sub_404d90();
    return 0;
//    assert(0);
}
void vtable_draw_256_sprite(CicoPtr<BITMAP*> bmp, CicoPtr<BITMAP*> sprite, int x, int y);
void vtable_stretch_256_sprite_all(
    CicoPtr<BITMAP*> bmp,
    CicoPtr<BITMAP*> sprite,
    int x, int y,
    int stretch_w, int stretch_h,
                                   bool hflip, bool vflip);

void ALLEGRO_CC stretch_sprite(CicoPtr<BITMAP*> bmp, CicoPtr<BITMAP*> sprite, int x, int y, int w, int h) {
//    printf("DBG ----- %s(%x/%x x=%d y=%d w=%d h=%d)\n", __FUNCTION__, bmp.ptr, sprite.ptr, x, y, w, h);
    vtable_stretch_256_sprite_all(bmp, sprite, x, y, w, h, false, false);
//    vtable_draw_256_sprite(bmp, sprite, x, y);
}
extern int allegro_errno;

void vtable_draw_256_sprite_all(CicoPtr<BITMAP*> bmp, CicoPtr<BITMAP*> sprite, int x, int y, bool hflip, bool vflip)
{
    BITMAP* pBitmap = _cicoptr<BITMAP>(bmp);
    BITMAP* pSprite = _cicoptr<BITMAP>(sprite);
    
    uint8_t* pPixelsBitmap = _cicoptr<uint8_t>(pBitmap->ptr_dat);
    uint8_t* pPixelsSprite = _cicoptr<uint8_t>(pSprite->ptr_dat);

    for (int ty=0; ty<pSprite->h; ty++)
        for (int tx=0; tx<pSprite->w; tx++)
        {
            int nx = tx + x;
            int ny = ty + y;
            if (nx < 0 || nx >= pBitmap->w || ny < 0 || ny >= pBitmap->h)
                continue;
            assert(ty*pSprite->w+tx >= 0 && ty*pSprite->w+tx < pSprite->h*pSprite->w);
            assert(ny*pBitmap->w+nx >= 0 && ny*pBitmap->w+nx < pBitmap->h*pBitmap->w);
            int p;
            if (hflip)
                p = pPixelsSprite[ty*pSprite->w+pSprite->w-tx];
            else
                p = pPixelsSprite[ty*pSprite->w+tx];
            if (p)
                pPixelsBitmap[ny*pBitmap->w+nx] = p;
        }
}

void vtable_stretch_256_sprite_all(
    CicoPtr<BITMAP*> bmp,
    CicoPtr<BITMAP*> sprite,
    int x, int y,
    int stretch_w, int stretch_h,
    bool hflip, bool vflip)
{
    BITMAP* pBitmap = _cicoptr<BITMAP>(bmp);
    BITMAP* pSprite = _cicoptr<BITMAP>(sprite);

    uint8_t* pPixelsBitmap = _cicoptr<uint8_t>(pBitmap->ptr_dat);
    uint8_t* pPixelsSprite = _cicoptr<uint8_t>(pSprite->ptr_dat);

    if (stretch_w <= 0 || stretch_h <= 0)
        return;

    for (int dy = 0; dy < stretch_h; dy++)
    {
        // Map destination Y to source Y
        int sy = dy * pSprite->h / stretch_h;
        if (vflip)
            sy = pSprite->h - 1 - sy;

        for (int dx = 0; dx < stretch_w; dx++)
        {
            // Map destination X to source X
            int sx = dx * pSprite->w / stretch_w;
            if (hflip)
                sx = pSprite->w - 1 - sx;

            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= pBitmap->w || ny < 0 || ny >= pBitmap->h)
                continue;

            assert(sx >= 0 && sx < pSprite->w);
            assert(sy >= 0 && sy < pSprite->h);

            uint8_t p = pPixelsSprite[sy * pSprite->w + sx];
            if (p)
                pPixelsBitmap[ny * pBitmap->w + nx] = p;
        }
    }
}

void vtable_draw_256_sprite(CicoPtr<BITMAP*> bmp, CicoPtr<BITMAP*> sprite, int x, int y)
{
    vtable_draw_256_sprite_all(bmp, sprite, x, y, false, false);
}
void vtable_draw_256_sprite_hflip(CicoPtr<BITMAP*> bmp, CicoPtr<BITMAP*> sprite, int x, int y)
{
    vtable_draw_256_sprite_all(bmp, sprite, x, y, true, false);
}
void vtable_draw_256_sprite_vflip(CicoPtr<BITMAP*> bmp, CicoPtr<BITMAP*> sprite, int x, int y)
{
    vtable_draw_256_sprite_all(bmp, sprite, x, y, false, true);
}
/*
void pivot_scaled_sprite_flip(CicoPtr<BITMAP*> bmp, CicoPtr<BITMAP*> sprite, uint32_t fixedX, uint32_t fixedY,
                              uint32_t fixedCX, uint32_t fixedCY, uint32_t fixedAngle, uint32_t fixedScale, int v_flip)
{
    fixedX >>= 16;
    fixedY >>= 16;
    fixedCX >>= 16;
    fixedCY >>= 16;
    vtable_draw_256_sprite_all(bmp, sprite, fixedX - fixedCX, fixedY - fixedCY, 0, v_flip);
    
    BITMAP* pBitmap = _cicoptr<BITMAP>(bmp);
    uint8_t* pPixelsBitmap = _cicoptr<uint8_t>(pBitmap->ptr_dat);

//    renderPixels(pPixelsBitmap, (uint8_t*)currentPalette);
}
*/
void pivot_scaled_sprite_flip(CicoPtr<BITMAP*> bmp, CicoPtr<BITMAP*> sprite,
                              int32_t fixedX, int32_t fixedY,
                              int32_t fixedCX, int32_t fixedCY,
                              int32_t fixedAngle, int32_t fixedScale,
                              int v_flip)
{
    BITMAP* pBitmap = _cicoptr<BITMAP>(bmp);
    BITMAP* pSprite = _cicoptr<BITMAP>(sprite);

    uint8_t* dst = _cicoptr<uint8_t>(pBitmap->ptr_dat);
    uint8_t* src = _cicoptr<uint8_t>(pSprite->ptr_dat);

    // Convert from 16.16 fixed
    int dstX = fixedX >> 16;
    int dstY = fixedY >> 16;
    int cx   = fixedCX >> 16;
    int cy   = fixedCY >> 16;

    float scale = fixedScale / 65536.0f;
    float angle = (fixedAngle / 65536.0f) * (M_PI / 180.0f); //(fixedAngle / 65536.0f) * 2.0f * 3.14159265358979323846f;

    float cos_a = cosf(angle) * scale;
    float sin_a = sinf(angle) * scale;

    // Compute bounding box (conservative)
    int maxDim = int((pSprite->w + pSprite->h) * scale) + 2;

    for (int y = -maxDim; y <= maxDim; y++)
    {
        for (int x = -maxDim; x <= maxDim; x++)
        {
            int dx = dstX + x;
            int dy = dstY + y;

            if (dx < 0 || dx >= pBitmap->w || dy < 0 || dy >= pBitmap->h)
                continue;

            // Inverse transform (screen → sprite space)
            float sx =  ( x * cos_a + y * sin_a );
            float sy =  (-x * sin_a + y * cos_a );

            int srcX = int(sx + cx);
            int srcY = int(sy + cy);

            if (v_flip)
                srcY = pSprite->h - 1 - srcY;

            if (srcX < 0 || srcX >= pSprite->w ||
                srcY < 0 || srcY >= pSprite->h)
                continue;

            uint8_t p = src[srcY * pSprite->w + srcX];
            if (p)
                dst[dy * pBitmap->w + dx] = p;
        }
    }
}

void initTables()
{
    uint32_t ptrTable = _alloc(512*4);
    memoryASet32(ds, 0x40d114, ptrTable);
    enum {
 TABLE_SIZE = 512,
 FIXED_SHIFT = 16,
    };
        for (int i = 0; i < TABLE_SIZE; i++) {
            double angle = 2.0 * M_PI * i / TABLE_SIZE;  // full circle
            double c = cos(angle);
            int32_t _cos_tbl_i = (int32_t)(c * (1 << FIXED_SHIFT) + 0.5); // 16.16 fixed point
            memoryASet32(ds, ptrTable+i*4, _cos_tbl_i);
        }
    
    uint32_t ptrLightMap = _alloc(4);
    memoryASet32(ds, 0x40d0dc, ptrLightMap);
    
    CicoPtr<BITMAP*> ptrScreen = create_bitmap(640, 480);
    screenPixels = _cicoptr<uint8_t>(_cicoptr<BITMAP>(ptrScreen)->ptr_dat);
    uint32_t ptrptrScreen = _alloc(4);
    memoryASet32(ds, ptrptrScreen, ptrScreen.ptr);
    memoryASet32(ds, 0x40d108, ptrptrScreen);
    
    ptrAllegKeys = _alloc(256);
    int t = memoryAGet32(ds, 0x40d1a4);
    memoryASet32(ds, 0x40d1a4, ptrAllegKeys);
    
    
    uint32_t ptrptrErrno = _alloc(4);
    uint32_t ptrErrno = _alloc(4);
    memoryASet32(ds, 0x40d110, ptrptrErrno);
    memoryASet32(ds, ptrptrErrno, ptrErrno);
    
    uint32_t ptrptrFont = _alloc(4);
    uint32_t ptrFont = _alloc(sizeof(FONT));
    memoryASet32(ds, 0x40d0d4, ptrptrFont);
    memoryASet32(ds, ptrptrFont, ptrFont);
    
    ptrShared = _alloc(1024);
    
    // ptr_alleg40_black_palette
    uint32_t ptrBlackPalette = _alloc(1024);
    memoryASet32(ds, 0x40d0e8, ptrBlackPalette);
}

void vtable_line(CicoPtr<BITMAP*> bmp, int x1, int y1, int x2, int y2, int c)
{
    
    BITMAP* pBitmap = _cicoptr<BITMAP>(bmp);
    uint8_t* pPixelsBitmap = _cicoptr<uint8_t>(pBitmap->ptr_dat);

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        pPixelsBitmap[y1*pBitmap->w+x1] = c;
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}
void vtable_rectfill(CicoPtr<BITMAP*> bmp, int x1, int y1, int x2, int y2, int c)
{
    
    BITMAP* pBitmap = _cicoptr<BITMAP>(bmp);
    uint8_t* pPixelsBitmap = _cicoptr<uint8_t>(pBitmap->ptr_dat);
    for (int y=y1; y<y2; y++)
        for (int x=x1; x<x2; x++)
            pPixelsBitmap[y*pBitmap->w+x] = c;
        
}

void vtable_acquire(CicoPtr<BITMAP*> bmp)
{
}
void vtable_release(CicoPtr<BITMAP*> bmp)
{
    BITMAP* pBitmap = _cicoptr<BITMAP>(bmp);
    uint8_t* pPixels = _cicoptr<uint8_t>(pBitmap->ptr_dat);
    assert(pBitmap->w == 640 && pBitmap->h == 480);
    renderPixels(pPixels, (uint32_t*)currentPalette);
}

uint32_t vtable_read_bank(CicoPtr<BITMAP*> bmp, int row)
{
    BITMAP* bitmap = _cicoptr<BITMAP>(bmp);
    assert(row >= 0 && row < bitmap->h);
    return bitmap->ptr_dat + row * bitmap->w;
}


#ifdef __cplusplus
}
#endif

void renderScreen()
{
    renderPixels(screenPixels, (uint32_t*)currentPalette);
}

#endif // ALLEG40_H
