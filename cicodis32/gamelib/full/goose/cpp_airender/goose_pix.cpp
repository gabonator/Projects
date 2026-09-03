#include "goose.h"
#include <string.h>

#define SCREEN_W        320
#define SCREEN_H        200
#define SCREEN_PITCH    SCREEN_W

uint8_t display_buffer[SCREEN_W * SCREEN_H];
uint8_t offscreen_buffer[1024*256];

uint16_t get_tunnel_plane_mask();
uint16_t get_tunnel_bg_color();
void sync(uint8_t* buf);

static void blit_sprite_clipped(bool to_screen, uint16_t height, uint16_t width,
                         uint16_t scroll_y, uint16_t screen_x,
                         uint8_t *sprite_data, uint16_t sprite_ofs)
{
    uint16_t src = sprite_ofs;
    int row_width;

    if (to_screen) {
        int16_t rel_y = (int16_t)((scroll_y - scroll_pos) & 0x03ff);
        if (rel_y & 0x0200)
            rel_y |= (int16_t)0xfc00;

        scroll_y = (uint16_t)rel_y;

        if (rel_y < 0) {
            height += (uint16_t)rel_y;
            if ((int16_t)height <= 0)
                return;
            src += (uint16_t)(-rel_y) * 0x00a0;
            scroll_y = 0;
        } else {
            int16_t overflow = rel_y + (int16_t)height - 0x00a0;
            if (overflow >= 0) {
                height -= (uint16_t)overflow;
                if ((int16_t)height <= 0)
                    return;
            }
        }

        screen_x += 0x20;
        scroll_y += 8;

        if ((int16_t)screen_x < 0x20)
            screen_x = 0x20;
        else if ((int16_t)(screen_x + width) > 0x120)
            screen_x = 0x120 - width;

        row_width = SCREEN_W;
    } else {
        row_width = 256;
    }

    for (uint16_t y = 0; y < height; y++) {
        uint8_t *row;
        if (to_screen)
            row = display_buffer + (scroll_y + y) * SCREEN_PITCH;
        else
            row = offscreen_buffer + ((scroll_y + y) & 0x3ff) * 256;

        int x = screen_x;

        for (uint16_t col = 0; col < width; col += 2) {
            uint8_t sprite_byte = sprite_data[src + col / 2];
            uint8_t hi = sprite_byte >> 4;
            uint8_t lo = sprite_byte & 0x0f;

            if (hi != blit_transp_color && (unsigned)x < (unsigned)row_width)
                row[x] = hi;

            if (col + 1 < width && lo != blit_transp_color && (unsigned)(x + 1) < (unsigned)row_width)
                row[x + 1] = lo;

            x += 2;
        }

        src += 0x00a0;
    }
}

void draw_hud_bar_pixel(uint16_t row_offset, uint16_t pixel_x)
{
    int base_y = row_offset / 0x28;
    int base_x = (row_offset % 0x28) * 8 + pixel_x;

    if ((unsigned)base_x >= SCREEN_W)
        return;

    for (int i = 0; i < 7; i++) {
        int y = base_y + i;
        if ((unsigned)y >= SCREEN_H)
            continue;

        int ofs = y * SCREEN_PITCH + base_x;
        if (display_buffer[ofs])
            display_buffer[ofs] ^= 7;
    }
}

void blit_sprite_masked(uint8_t *sprite_data,
                        uint16_t row_count,
                        uint16_t width,
                        uint16_t video_dest,
                        uint16_t sprite_source)
{
    int base_y = video_dest / 0x28;
    int base_x = (video_dest % 0x28) * 8;
    uint16_t src = sprite_source;

    for (uint16_t row = 0; row < row_count; row++) {
        int x = base_x;
        int y = base_y + row;

        if ((unsigned)y >= SCREEN_H) {
            src += 0x00a0;
            continue;
        }

        for (uint16_t col = 0; col < width; col += 2) {
            uint8_t byte = sprite_data[src + col / 2];
            uint8_t hi = byte >> 4;
            uint8_t lo = byte & 0x0f;

            if (hi != 0x02 && (unsigned)x < SCREEN_W)
                display_buffer[y * SCREEN_PITCH + x] = hi;

            if (col + 1 < width && lo != 0x02 && (unsigned)(x + 1) < SCREEN_W)
                display_buffer[y * SCREEN_PITCH + x + 1] = lo;

            x += 2;
        }

        src += 0x00a0;
    }
}

void fill_rect_ega(uint16_t color, uint16_t height, uint16_t width, uint16_t base_addr)
{
    int y = base_addr / 0x28;
    int x = (base_addr % 0x28) * 8;
    uint16_t pixel_width = width * 8;
    color &= 0x0f;

    for (uint16_t row = 0; row < height; row++) {
        if ((unsigned)(y + row) >= SCREEN_H)
            continue;

        for (uint16_t col = 0; col < pixel_width; col++) {
            if ((unsigned)(x + col) < SCREEN_W)
                display_buffer[(y + row) * SCREEN_PITCH + x + col] = color;
        }
    }
}

void render_tunnel_buffer()
{
    uint8_t plane_mask = (~get_tunnel_plane_mask()) & 0x0f;
    uint8_t bg_color = get_tunnel_bg_color() & plane_mask;
    uint8_t wire_color = ~plane_mask & 0x0f;
    uint16_t src = 0x0340;

    for (int y = 0; y < 160; y++) {
        uint8_t *row = display_buffer + (8 + y) * SCREEN_PITCH + 32;

        for (int x = 0; x < 256; x++) {
            uint8_t value = tunnel_buf[src + x / 8];
            row[x] = (value & (0x80 >> (x & 7))) ? (bg_color | wire_color) : bg_color;
        }

        src += 0x20;
    }
}

void render_map_buffer()
{
    uint32_t src_ofs = scroll_pos * 256;

    for (int y = 0; y < 0xa0; y++) {
        memcpy(display_buffer + (8 + y) * SCREEN_PITCH + 32,
               offscreen_buffer + src_ofs, 256);
        src_ofs = (src_ofs + 256) % sizeof(offscreen_buffer);
    }
}

void init_ega_double_buffer()
{
    memset(display_buffer, 0, SCREEN_W * SCREEN_H);
    sync(display_buffer);
}

void page_flip_and_vsync()
{
    sync(display_buffer);
}

void clear_video_buffer(uint8_t color)
{
    memset(display_buffer, color, SCREEN_W * SCREEN_H);
}

void wait_vsync()
{
    sync(display_buffer);
}

void blit_fullscreen_bitmap(uint8_t *src_data)
{
    const uint8_t *p0 = src_data;
    const uint8_t *p1 = p0 + 0x1f40;
    const uint8_t *p2 = p1 + 0x1f40;
    const uint8_t *p3 = p2 + 0x1f40;
    uint8_t *row = display_buffer;

    for (int y = 0; y < SCREEN_H; y++) {
        for (int xb = 0; xb < 40; xb++) {
            uint8_t b0 = *p0++;
            uint8_t b1 = *p1++;
            uint8_t b2 = *p2++;
            uint8_t b3 = *p3++;
            for (int mask = 0x80; mask > 0; mask >>= 1) {
                *row++ = ((b0 & mask) ? 8 : 0)
                       | ((b1 & mask) ? 4 : 0)
                       | ((b2 & mask) ? 2 : 0)
                       | ((b3 & mask) ? 1 : 0);
            }
        }
    }
}

void draw_hud_border_frame()
{
    for (int x = 32; x < 288; x++)
        display_buffer[7 * SCREEN_PITCH + x] = 15;

    for (int x = 32; x < 288; x++)
        display_buffer[168 * SCREEN_PITCH + x] = 15;

    for (int y = 7; y < 169; y++)
        display_buffer[y * SCREEN_PITCH + 31] = 15;

    for (int y = 7; y < 169; y++)
        display_buffer[y * SCREEN_PITCH + 288] = 15;
}

void clear_offscreen_buffer()
{
    memset(offscreen_buffer, 0, sizeof(offscreen_buffer));
}

static void render_entity(Entity& e, bool to_screen)
{
    uint16_t screen_x = e.x - (int16_t)(int8_t)e.drawOfsY;
    uint8_t ht_sum = e.heightOfs + e.drawOfsX;
    uint16_t scroll_y = e.y - (int16_t)(int8_t)ht_sum;

    blit_transp_color = e.colorMask;
    blit_sprite_clipped(to_screen, e.spriteH, e.spriteW, scroll_y, screen_x,
                        res_data[e.spriteSheet >> 1], e.spriteData);
}

void render_all_sprites()
{
    for (uint16_t z = 7; z != 0; --z)
        for (int i = 0; i < ENTITY_SLOTS; i++)
            if (entities[i].flags & 1 && z == entities[i].zLayer)
                render_entity(entities[i], true);
}

void render_entity_to_offscreen(Entity& tmpl)
{
    render_entity(tmpl, false);
}

void init_intro_sprites()
{
    blit_fullscreen_bitmap(res_data[RES_INTRO]);
    sync(display_buffer);
}

void render_intro_background()
{
    blit_fullscreen_bitmap(res_data[RES_INTRO]);
}
