// alleg40.h
// Allegro 4.0 Library Function Declarations
// Contains only functions imported by the application

#ifndef ALLEG40_H
#define ALLEG40_H

#ifdef __cplusplus
extern "C" {
#endif

// Allegro uses __cdecl calling convention
#ifndef ALLEGRO_CC
#define ALLEGRO_CC __cdecl
#endif

// Forward declarations for Allegro types
struct BITMAP;
struct PALETTE;
struct RGB;
struct SAMPLE;
struct DATAFILE;
struct FONT;
struct PACKFILE;
struct COLOR_MAP;
struct RGB_MAP;
struct JOYSTICK_INFO;

typedef struct BITMAP BITMAP;
typedef struct PALETTE PALETTE;
typedef struct RGB RGB;
typedef struct SAMPLE SAMPLE;
typedef struct DATAFILE DATAFILE;
typedef struct FONT FONT;
typedef struct PACKFILE PACKFILE;
typedef struct COLOR_MAP COLOR_MAP;
typedef struct RGB_MAP RGB_MAP;
typedef struct JOYSTICK_INFO JOYSTICK_INFO;

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
void ALLEGRO_CC adjust_sample(SAMPLE *spl, int vol, int pan, int freq, int loop);
void ALLEGRO_CC alert(const char *s1, const char *s2, const char *s3, const char *b1, const char *b2, int c1, int c2);
void ALLEGRO_CC allegro_exit(void);
void ALLEGRO_CC allegro_message(const char *msg, ...);
void ALLEGRO_CC blit(BITMAP *source, BITMAP *dest, int source_x, int source_y, int dest_x, int dest_y, int width, int height);
void ALLEGRO_CC clear_bitmap(BITMAP *bitmap);
void ALLEGRO_CC clear_keybuf(void);
BITMAP * ALLEGRO_CC create_bitmap(int width, int height);
void ALLEGRO_CC destroy_bitmap(BITMAP *bitmap);
void ALLEGRO_CC destroy_sample(SAMPLE *spl);
void ALLEGRO_CC drawing_mode(int mode, BITMAP *pattern, int x_anchor, int y_anchor);
int ALLEGRO_CC exists(const char *filename);
void ALLEGRO_CC fade_in(const PALETTE p, int speed);
void ALLEGRO_CC fade_out(int speed);
int ALLEGRO_CC install_allegro(int system_id, int *errno_ptr, int (*atexit_ptr)(void (*func)(void)));
void ALLEGRO_CC install_int(void (*proc)(void), long speed);
void ALLEGRO_CC install_joystick(int type);
void ALLEGRO_CC install_keyboard(void);
int ALLEGRO_CC install_sound(int digi, int midi, const char *cfg_path);
void ALLEGRO_CC install_timer(void);
int ALLEGRO_CC keypressed(void);
DATAFILE * ALLEGRO_CC load_datafile(const char *filename);
SAMPLE * ALLEGRO_CC load_wav(const char *filename);
void ALLEGRO_CC masked_blit(BITMAP *source, BITMAP *dest, int source_x, int source_y, int dest_x, int dest_y, int width, int height);
PACKFILE * ALLEGRO_CC pack_fclose(PACKFILE *f);
PACKFILE * ALLEGRO_CC pack_fopen(const char *filename, const char *mode);
int ALLEGRO_CC pack_fread(void *p, long n, PACKFILE *f);
int ALLEGRO_CC pack_fwrite(const void *p, long n, PACKFILE *f);
void ALLEGRO_CC get_palette(PALETTE p);
void ALLEGRO_CC get_palette_range(PALETTE p, int from, int to, PALETTE p2);
int ALLEGRO_CC play_sample(const SAMPLE *spl, int vol, int pan, int freq, int loop);
int ALLEGRO_CC poll_joystick(void);
int ALLEGRO_CC readkey(void);
void ALLEGRO_CC save_pcx(const char *filename, BITMAP *bmp, const PALETTE pal);
void ALLEGRO_CC set_clip(BITMAP *bitmap, int x1, int y1, int x2, int y2);
void ALLEGRO_CC set_color_depth(int depth);
int ALLEGRO_CC set_gfx_mode(int card, int w, int h, int v_w, int v_h);
int ALLEGRO_CC set_display_switch_mode(int mode);
void ALLEGRO_CC set_palette(const PALETTE p);
void ALLEGRO_CC set_palette_range(const PALETTE p, int from, int to, int vsync);
void ALLEGRO_CC solid_mode(void);
void ALLEGRO_CC stop_sample(const SAMPLE *spl);
void ALLEGRO_CC stretch_blit(BITMAP *s, BITMAP *d, int s_x, int s_y, int s_w, int s_h, int d_x, int d_y, int d_w, int d_h);
int ALLEGRO_CC text_height(const FONT *f);
int ALLEGRO_CC text_length(const FONT *f, const char *str);
void ALLEGRO_CC text_mode(int mode);
void ALLEGRO_CC textout(BITMAP *bmp, const FONT *f, const char *s, int x, int y, int color);
void ALLEGRO_CC textout_centre(BITMAP *bmp, const FONT *f, const char *s, int x, int y, int color);
void ALLEGRO_CC textprintf(BITMAP *bmp, const FONT *f, int x, int y, int color, const char *fmt, ...);
void ALLEGRO_CC textprintf_centre(BITMAP *bmp, const FONT *f, int x, int y, int color, const char *fmt, ...);
void ALLEGRO_CC textprintf_right(BITMAP *bmp, const FONT *f, int x, int y, int color, const char *fmt, ...);
void ALLEGRO_CC unload_datafile(DATAFILE *dat);
void ALLEGRO_CC create_rgb_table(RGB_MAP *table, const PALETTE pal, void (*callback)(int pos));
void ALLEGRO_CC create_light_table(COLOR_MAP *table, const PALETTE pal, int r, int g, int b, void (*callback)(int pos));
int ALLEGRO_CC _WinMain(void *hInst, void *hPrev, char *Cmd, int nShow);

// missing
void ALLEGRO_CC stretch_sprite(BITMAP *bmp, BITMAP *sprite, int x, int y, int w, int h);
extern int allegro_errno;

#ifdef __cplusplus
}
#endif

#endif // ALLEG40_H
