#include "goose.h"

void wait_vsync();
void clear_video_buffer(uint8_t color);
uint16_t get_tunnel_plane_mask();
uint16_t get_tunnel_bg_color();
void render_single_entity_from(Entity& e);

void blit_sprite_clipped(uint16_t height, uint16_t width, uint16_t scroll_y, uint16_t screen_x, uint8_t* sprite_data, uint16_t sprite_ofs) // 1000:0c24 blit_sprite_clipped: EGA bit-plane sprite blitter with clipping
{
    uint16_t src = sprite_ofs;
    if (render_to_screen) {
        // --- Vertical clipping (map scroll space) ---
        int16_t rel_y = (int16_t)((scroll_y - scroll_pos) & 0x03ff);
        if (rel_y & 0x0200) rel_y |= (int16_t)0xfc00; // sign extend from 10-bit
        scroll_y = (uint16_t)rel_y;
        if (rel_y < 0) {
            height = height + (uint16_t)rel_y; // height -= abs(y)
            if ((int16_t)height <= 0)
                return;
            uint16_t skip = (uint16_t)(-rel_y);
            src += skip * 0x00a0; // skip clipped rows (row stride = 160)
            scroll_y = 0;
        } else {
            int16_t overflow = rel_y + (int16_t)height - 0x00a0;
            if (overflow >= 0) {
                height = height - (uint16_t)overflow;
                if ((int16_t)height <= 0)
                    return;
            }
        }
        // --- Horizontal position adjustment ---
        screen_x += 0x0020;
        scroll_y += 0x0008;
        if ((int16_t)screen_x < 0x0020) {
            screen_x = 0x0020;
        } else if ((int16_t)(screen_x + width) > 0x0120) {
            screen_x = 0x0120 - width;
        }
    }

    // --- EGA blitting setup ---
    uint16_t port = 0x03ce;
    out16(port, 0x0a05); // GC reg 5 = 0x0A: write mode 2, read mode 1
    out16(port, 0x0007); // GC reg 7 = 0x00: color don't care = all planes
    uint16_t row_stride = blit_row_stride;
    uint16_t y8 = scroll_y << 3;
    uint16_t dst = (row_stride == 0x0028) ? y8 : 0x0000;
    dst += (scroll_y << 5); // dst = Y * row_stride
    dst += (screen_x >> 3); // dst += X / 8
    uint8_t bit_pos = screen_x & 0x07;
    uint8_t bit_mask = 0x80 >> bit_pos;
    uint16_t dst_seg = sprite_target;
    uint16_t half_width = width >> 1; // 2 pixels per byte

    // --- Main blit loop: row by row ---
    for (uint16_t rows = height; rows != 0; --rows) {
        uint16_t saved_dst = dst, saved_src = src;
        uint8_t cur_mask = bit_mask;
        uint16_t cols = half_width;
        while (cols) {
            uint8_t transp_byte = blit_transp_byte;
            uint8_t sprite_byte = sprite_data[src];
            src++;
            if (transp_byte == sprite_byte) {
                // Both pixels transparent: advance bit mask
                cur_mask >>= 1;
                if (!cur_mask) {
                    cur_mask = 0x40;
                    dst++;
                    if (--cols) continue;
                    break;
                }
                cur_mask >>= 1;
                if (!cur_mask) {
                    cur_mask = 0x80;
                    dst++;
                }
                --cols;
                continue;
            }
            // --- Draw non-transparent pixel pair ---
            uint8_t hi_pixel = sprite_byte >> 4;
            uint8_t lo_pixel = sprite_byte & 0x0f;
            if (hi_pixel != blit_transp_color) {
                out16(port, ((uint16_t)cur_mask << 8) | 0x08);
                vw8(dst_seg, dst, vr8(dst_seg, dst) & hi_pixel);
            }
            cur_mask >>= 1;
            if (!cur_mask) {
                cur_mask = 0x80;
                dst++;
            }
            if (lo_pixel != blit_transp_color) {
                out16(port, ((uint16_t)cur_mask << 8) | 0x08);
                vw8(dst_seg, dst, vr8(dst_seg, dst) & lo_pixel);
            }
            cur_mask >>= 1;
            if (!cur_mask) {
                cur_mask = 0x80;
                dst++;
            }
            --cols;
        }
        // --- End of row ---
        src = saved_src + 0x00a0;
        dst = (saved_dst + row_stride) & 0x7fff;
    }

    // --- Restore EGA state ---
    out16(port, 0xff08);
    out16(port, 0x0005);
    out16(port, 0x0f07);
}

void draw_hud_bar_pixel(uint16_t row_offset, uint16_t pixel_x) // 1000:25e3 — draw_hud_bar_pixel
{
    uint16_t port = 0x03ce;
    uint16_t byte_ofs = (pixel_x >> 3) + row_offset;
    uint8_t bit_mask = 0x80 >> (pixel_x & 7);

    out16(port, 0x0805);   // write mode 2
    out16(port, (bit_mask << 8) | 0x08); // set bit mask
    out16(port, 0x1803);   // XOR data rotate
    out16(port, 0x0f01);   // enable set/reset all planes
    out16(port, 0x0700);   // set/reset = color 7

    uint16_t ofs = byte_ofs;
    for (int i = 0; i < 7; i++) {
        uint8_t latched = vr8(0xa000, ofs);
        if (!(bit_mask & latched)) {
            vw8(0xa000, ofs, bit_mask);
            vw8(0xa000, ofs + 8192, bit_mask);
        }
        ofs += 0x0028;
    }

    out16(port, 0x0005);
    out16(port, 0xff08);
    out16(port, 0x0003);
    out16(port, 0x0001);
    out16(port, 0x0000);
}
void blit_sprite_masked(uint8_t* sprite_data, uint16_t row_count, uint16_t width, uint16_t video_dest, uint16_t sprite_source) // 1000:2cea blit_sprite_masked
{
    uint16_t port = 0x03ce;
    out16(port, 0x0a05);
    out16(port, 0x0007);
    uint16_t half_width = width >> 1;
    uint16_t dst = video_dest;
    uint16_t src = sprite_source;
    uint8_t cur_mask = 0x80;
    for (uint16_t row = row_count; row; row--) {
        uint16_t saved_dst = dst;
        uint16_t saved_src = src;
        uint8_t saved_mask = cur_mask;
        uint8_t prev = 0x22;
        uint16_t col = half_width;
        while (col) {
            uint8_t byte = sprite_data[src];
            src++;
            if (prev == byte) {
                // Transparent pixel pair — skip 2 pixel positions
                cur_mask >>= 1;
                if (!cur_mask) { cur_mask = 0x40; dst++; if (!--col) break; }
                cur_mask >>= 1;
                if (!cur_mask) { cur_mask = 0x80; dst++; }
                if (!--col) break;
            } else {
                // Non-transparent: draw high nibble pixel
                uint8_t hi_pixel = byte >> 4;
                if (hi_pixel != 0x02) {
                    out16(port, (cur_mask << 8) | 0x08);
                    vw8(0xa000, dst, vr8(0xa000, dst) & hi_pixel);
                    vw8(0xa000, dst + 8192, vr8(0xa000, dst + 8192) & hi_pixel);
                }
                cur_mask >>= 1;
                if (!cur_mask) { cur_mask = 0x80; dst++; }
                // Draw low nibble pixel
                uint8_t lo_pixel = byte & 0x0f;
                if (lo_pixel != 0x02) {
                    out16(port, (cur_mask << 8) | 0x08);
                    vw8(0xa000, dst, vr8(0xa000, dst) & lo_pixel);
                    vw8(0xa000, dst + 8192, vr8(0xa000, dst + 8192) & lo_pixel);
                }
                cur_mask >>= 1;
                if (!cur_mask) { cur_mask = 0x80; dst++; }
                if (!--col) break;
                prev = 0x22;
            }
        }
        src = saved_src + 0x00a0;
        dst = (saved_dst + 0x0028) & 0x7fff;
        cur_mask = saved_mask;
    }
    out16(port, 0xff08);
    out16(port, 0x0005);
    out16(port, 0x0f07);
}
void fill_rect_ega(uint16_t color, uint16_t height, uint16_t width, uint16_t base_addr) // 1000:2d9a fill_rect_ega
{
    uint16_t port = 0x03ce;
    out16(port, (color << 8) | 0x00); // set/reset = color
    out16(port, 0x0f01);              // enable set/reset all planes
    uint16_t row = base_addr;
    for (uint16_t r = height; r; r--) {
        for (uint16_t c = 0; c < width; c++)
            vw8(0xa000, row + c, 0);
        for (uint16_t c = 0; c < width; c++)
            vw8(0xa000, row + 0x2000 + c, 0);
        row += 0x0028;
    }
    out16(port, 0x0000);
    out16(port, 0x0001);
}
void render_tunnel_buffer() // 1000:31a4 — render_tunnel_buffer: copies tunnel wireframe buffer to display page
{
    uint16_t dst_seg = display_page;
    uint16_t port = 0x03ce;
    uint16_t plane_mask = (~get_tunnel_plane_mask()) & 0x000f;
    out16(port, (plane_mask << 8) | 0x01); // enable set/reset for tunnel color planes
    uint16_t bg_color = get_tunnel_bg_color();
    out16(port, (bg_color << 8) | 0x00); // set background color
    uint16_t dst = 0x0144;
    uint16_t src = 0x0340;
    for (int row = 0; row < 0x00a0; row++) {
        for (int col = 0; col < 0x0020; col++)
            vw8(dst_seg, dst + col, tunnel_buf[src + col]);
        dst += 0x0028; // dest stride 40
        src += 0x0020; // source stride 32
    }
    out16(port, 0x0000); // clear set/reset
    out16(port, 0x0001); // disable set/reset
}
void copy_video_page(uint16_t dest_seg, uint16_t source_seg) // 1000:3291 — copy_video_page: copies game area from one video page to another
{
    uint16_t port = 0x03ce;
    out16(port, 0x0105); // write mode 1 (latched copy)
    uint16_t dst = 0x0144;
    uint16_t src = 0x0144;
    for (int row = 0; row < 0x00a0; row++) {
        for (int col = 0; col < 0x0020; col++)
            vw8(dest_seg, dst + col, vr8(source_seg, src + col));
        dst += 0x0028; // stride 40
        src += 0x0028;
    }
    out16(port, 0x0005); // write mode 0
}
void render_map_buffer() // 1000:32fe — render_map_buffer: copies offscreen map at A800 to display page
{
    uint16_t port = 0x03ce;
    out16(port, 0x0105); // write mode 1 (latched copy)
    uint16_t dst_seg = display_page;
    uint16_t src_ofs = scroll_pos << 5; // SCROLL_POS * 32
    uint16_t dst = 0x0144;
    for (int row = 0; row < 0x00a0; row++) {
        for (int col = 0; col < 0x0020; col++)
            vw8(dst_seg, dst + col, vr8(0xa800, src_ofs + col));
        src_ofs = (src_ofs + 0x0020) & 0x7fff; // wrap 32KB buffer
        dst += 0x0028; // stride 40
    }
    out16(port, 0x0005); // write mode 0
}
void init_ega_double_buffer() // 1000:333c — init_ega_double_buffer: sets EGA mode 0x0D, initializes two video pages
{
    //ax = 0x000d;
    //interrupt(0x10); // INT 10h AH=00: set EGA mode 0x0D (320x200, 16 colors)
    draw_page = 0xa000; // page 0 = A000
    display_page = 0xa200; // page 1 = A200
    clear_video_buffer(0x00); // clear page 1 with color 0
    // Swap pages so page 0 is now display page
    uint16_t tmp = display_page;
    display_page = draw_page;
    draw_page = tmp;
    wait_vsync();
    // Set CRT start address to show draw page (page 1 at A200)
    uint16_t addr = draw_page << 4; // segment * 16 = byte address
    //flags.interrupts = 0;
    out16(0x03d4, ((addr >> 8) << 8) | 0x0c); // CRT reg 0x0C = start address high byte
    out16(0x03d4, ((addr & 0xff) << 8) | 0x0d); // CRT reg 0x0D = start address low byte
    //flags.interrupts = 1;
    wait_vsync();
}
void page_flip_and_vsync() // 1000:3383 — page_flip_and_vsync: swaps display/draw pages, updates CRT start address
{
    // Swap display and draw page segments
    uint16_t tmp = display_page;
    display_page = draw_page;
    draw_page = tmp;
    // Set CRT start address to newly visible (old draw) page
    uint16_t addr = draw_page << 4; // segment * 16
    //flags.interrupts = 0;
    out16(0x03d4, ((addr >> 8) << 8) | 0x0c); // CRT reg 0x0C = start address high byte
    //flags.interrupts = 1;
    // Wait for current retrace to end, then wait for next retrace
    while (in8(0x03da) & 0x08); // wait for retrace to end
    wait_vsync(); // wait_vsync: wait for retrace to start
}
void clear_video_buffer(uint8_t color) // 1000:33b3 — clear_video_buffer: fills display page with given color
{
    uint16_t port = 0x03ce;
    out16(port, (color << 8) | 0x00); // GC reg 0 = fill color
    out16(port, 0x0f01);           // enable set/reset all planes
    for (uint16_t i = 0; i < 0x0fa0; i++)
        vw16(display_page, i * 2, 0);
    out16(port, 0x0000);
    out16(port, 0x0001);
}
void wait_vsync() // 1000:33d7 — wait_vsync: waits for vertical retrace start, then end
{
    while (!(in8(0x03da) & 0x08)); // wait for retrace to begin
    while (in8(0x03da) & 0x08);    // wait for retrace to end
}
void blit_fullscreen_bitmap(uint8_t* src_data, uint16_t src_ofs) // 1000:33e5 — blit_fullscreen_bitmap: copies a packed bitmap to display page using EGA write mode 2
{
    uint16_t dst_seg = display_page;
    uint16_t src = src_ofs;
    uint16_t gc_port = 0x03ce;
    uint16_t seq_port = 0x03c4;
    out16(gc_port, 0x0805); // write mode 2, read mode 1
    out16(gc_port, 0x0007); // color don't care = 0
    for (uint8_t plane_mask = 0x08; plane_mask; plane_mask >>= 1) {
        out16(seq_port, (plane_mask << 8) | 0x02); // select EGA plane
        uint16_t s = src;
        for (uint16_t i = 0; i < 0x1f40; i++) {
            vw8(dst_seg, i, vr8(dst_seg, i) & src_data[s]);
            s++;
        }
        src = s; // advance source past this plane
    }
    out16(seq_port, 0x0f02); // enable all planes
    out16(gc_port, 0x0005);  // write mode 0
    out16(gc_port, 0x0f07);  // color don't care all
}
void draw_hud_border_frame() // 1000:3439 — draw_hud_border_frame: draws the white border around the game area
{
    uint16_t page = display_page;
    // Top border line: row 7, 32 bytes wide
    for (uint16_t i = 0; i < 0x0010; i++)
        vw16(page, 0x011c + i * 2, 0xffff);
    // Bottom border line: row 167, 32 bytes wide
    for (uint16_t i = 0; i < 0x0010; i++)
        vw16(page, 0x1a44 + i * 2, 0xffff);
    // Left border: vertical line at pixel 32, 162 rows
    for (uint16_t i = 0; i < 0x00a2; i++)
        vw8(page, 0x011b + i * 0x0028, 0x01);
    // Right border: vertical line at pixel 288, 162 rows
    for (uint16_t i = 0; i < 0x00a2; i++)
        vw8(page, 0x013c + i * 0x0028, 0x80);
}
void clear_offscreen_buffer()
{
    out16(0x03ce, 0x0000); // GC: set/reset = 0
    out16(0x03ce, 0x0f01); // GC: enable set/reset = all planes
    for (uint16_t ofs = 0; ofs < 0x8000; ofs += 2)
        vw16(0xa800, ofs, 0x0f01);
}


// -----------

void render_all_sprites() // 1000:0b8e — render_all_sprites: iterates entities by z-order (1-7), renders visible ones
{
    sprite_target = display_page;
    blit_row_stride = 0x0028; // row stride = 40 bytes
    render_to_screen = 0x0001;
    for (uint16_t z = 7; z != 0; --z) {
        for (int i = 0; i < ENTITY_SLOTS; i++) {
            Entity& e = entities[i];
            if (!(e.flags & 0x01)) continue;
            if ((uint8_t)z != e.zLayer) continue;
            render_single_entity_from(ent(entity_offset(i)));
        }
    }
}
void render_entity_to_offscreen(Entity& tmpl) // 1000:0bc5 — renders Entity to offscreen map buffer at A800
{
    sprite_target = 0xa800;
    blit_row_stride = 0x0020;
    render_to_screen = 0x0000;
    render_single_entity_from(tmpl);
}
void render_single_entity_from(Entity& e)
{
    // Calculate screen X: entity.x - entity.drawOfsY (signed)
    uint16_t _screen_x = e.x - (int16_t)(int8_t)e.drawOfsY;

    // Calculate screen Y: entity.y - (entity.heightOfs + entity.drawOfsX)
    uint8_t ht_sum = e.heightOfs + e.drawOfsX;
    uint16_t _scroll_y = e.y - (int16_t)(int8_t)ht_sum;

    uint16_t _width = e.spriteW;
    uint16_t _height = e.spriteH;

    // Look up sprite sheet data from resource pointer table
    uint8_t* sprite_ptr = res_data[e.spriteSheet >> 1];

    // Set up EGA transparent color mask
    uint8_t cm = e.colorMask;
    blit_transp_color = cm;
    blit_transp_byte = cm | (cm << 4);

    uint16_t sprite_ofs = e.spriteData;
    blit_sprite_clipped(_height, _width, _scroll_y, _screen_x, sprite_ptr, sprite_ofs);
}

void init_intro_sprites() // 1000:3472 — init_intro_sprites: draws INTRO.X bitmap to both pages, copies to backup at A400
{
    blit_fullscreen_bitmap(res_data[RES_INTRO], 0);
    page_flip_and_vsync();
    blit_fullscreen_bitmap(res_data[RES_INTRO], 0);
    copy_video_page(0xa400, display_page);
}
void render_intro_background() // 1000:3498 — render_intro_background: copies backup intro image (A400) to display page
{
    copy_video_page(display_page, 0xa400); // copy_video_page(dest=display, source=A400)
}
