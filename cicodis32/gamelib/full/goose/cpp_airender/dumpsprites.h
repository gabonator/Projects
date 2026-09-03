#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "goose.h"

static const uint32_t ega_palette[16] = {
    0x000000, 0x0000b0, 0x00b000, 0x00b0b0, 0xb00000, 0xb000b0, 0xb0b000, 0xb0b0b0,
    0x808080, 0x0000ff, 0x00ff00, 0x00ffff, 0xff0000, 0xff00ff, 0xffff00, 0xffffff
};

inline void write_rgba(FILE* f, uint8_t idx, int transp_color)
{
    uint32_t c = ega_palette[idx & 0x0f];
    uint8_t rgba[4] = {(uint8_t)(c >> 16), (uint8_t)(c >> 8), (uint8_t)c,
                       (idx == transp_color) ? (uint8_t)0 : (uint8_t)255};
    fwrite(rgba, 1, 4, f);
}

inline void write_pam_header(FILE* f, int w, int h)
{
    fprintf(f, "P7\nWIDTH %d\nHEIGHT %d\nDEPTH 4\nMAXVAL 255\nTUPLTYPE RGB_ALPHA\nENDHDR\n", w, h);
}

inline void dump_pam(const char* filename, const uint8_t* data, int w, int h, int stride, int transp = -1)
{
    FILE* f = fopen(filename, "wb");
    write_pam_header(f, w, h);
    for (int y = 0; y < h; y++) {
        const uint8_t* row = data + y * stride;
        for (int x = 0; x < w; x++)
            write_rgba(f, row[x], transp);
    }
    fclose(f);
}

inline void dump_sprite(const char* filename, const uint8_t* sheet,
                         uint16_t offset, int w, int h, int transp)
{
    FILE* f = fopen(filename, "wb");
    write_pam_header(f, w, h);
    for (int y = 0; y < h; y++) {
        const uint8_t* row = sheet + offset + y * 0xa0;
        for (int x = 0; x < w; x += 2) {
            uint8_t byte = row[x / 2];
            write_rgba(f, byte >> 4, transp);
            if (x + 1 < w)
                write_rgba(f, byte & 0x0f, transp);
        }
    }
    fclose(f);
}

inline int dump_entity_sprite_table(const char* name, Entity& e, const SpriteTable& spr)
{
    int count = 0;
    uint8_t saved_dirFlag = e.dirFlag;
    for (int fr = 0; fr < spr.num_frames; fr++) {
        int sheet_idx = spr.spriteSheet[fr] >> 1;
        if (sheet_idx >= RES_COUNT || !res_data[sheet_idx])
            continue;
        if (spr.spriteW[fr] == 0 || spr.spriteH[fr] == 0)
            continue;
        char path[256];
        snprintf(path, sizeof(path), "sprites/%s_f%02d.pam", name, fr);
        dump_sprite(path, res_data[sheet_idx], spr.spriteData[fr],
                    spr.spriteW[fr], spr.spriteH[fr], e.colorMask);
        count++;
    }
    e.dirFlag = saved_dirFlag;
    return count;
}

inline void dump_frame(uint8_t* buf)
{
    mkdir("sprites", 0755);
    int total = 0;

    dump_pam("sprites/screen.pam", buf, 320, 200, 320);

    extern uint8_t offscreen_buffer[];
    dump_pam("sprites/offscreen.pam", offscreen_buffer, 256, 1024, 256);

    // Entity → SpriteTable mapping (from load_sprite_data calls in goose.cpp)
    // colorMask is always read from the entity struct
    #define DUMP(name, entity, spr) total += dump_entity_sprite_table(name, entity, spr)
    DUMP("player",           tmpl_player,          spr_0d49);
    DUMP("player_bullet",    tmpl_bullet,          spr_0dda);
    DUMP("intro_char",       tmpl_intro_char,      spr_0120);
    DUMP("explosion",        tmpl_explode,         spr_12b5);
    DUMP("small_effect",     tmpl_small_effect,    spr_12f5);
    DUMP("weapon",           tmpl_weapon,          spr_133d);
    DUMP("enemy_t02",        spawn_templates[0],   spr_0e2b);   // type 0x02
    DUMP("enemy_t03",        spawn_templates[1],   spr_0e52);   // type 0x03
    DUMP("enemy_t04",        spawn_templates[2],   spr_0e73);   // type 0x04
    DUMP("enemy_t05",        spawn_templates[3],   spr_0e9c);   // type 0x05
    DUMP("enemy_t06",        spawn_templates[4],   spr_0e9c);   // type 0x06
    DUMP("enemy_t07",        spawn_templates[5],   spr_0ec5);   // type 0x07
    // type 0x1a hazard — direction selects sprite table & colorMask
    DUMP("hazard_dir0",      spawn_templates[11],  spr_0eee);   // dir=0, colorMask=0x02
    DUMP("hazard_dir1",      spawn_templates[12],  spr_0f3f);   // dir=1, colorMask=0x0d
    DUMP("hazard_dir2",      spawn_templates[14],  spr_0f90);   // dir=2, colorMask=0x02
    // fire projectiles — tmpl_fire_spread (colorMask=0x0d)
    for (int i = 0; i < 5; i++) {
        char n[64];
        snprintf(n, sizeof(n), "fire_projectile_dir%d", i);
        DUMP(n, tmpl_fire_spread, *fire_sprite[i]);
    }
    // bullet types
    DUMP("bullet_100e",      tmpl_bullet,          spr_100e);
    DUMP("bullet_1039",      tmpl_bullet,          spr_1039);
    for (int i = 0; i < 5; i++) {
        char n[64];
        snprintf(n, sizeof(n), "bullet_dir%d", i);
        DUMP(n, tmpl_bullet, *sprite_table_4143[i]);
    }
    DUMP("tunnel_player",    tmpl_tunnel_player,   spr_1594);
    DUMP("tunnel_missile",   tmpl_tunnel_missile,  spr_1811);
    DUMP("tunnel_spawn",     tmpl_tunnel_spawn,    spr_1929);
    DUMP("tunnel_entity",    tmpl_tunnel_entity,   spr_1ac9);
    #undef DUMP

    // Diamonds — 6 variants on sheet 0, spawn_templates[15] dimensions (16x12)
    // NOTE: in-game, copy_entity_template reads visual_templates[0x20] which is
    // out of bounds — in the original DOS binary this read adjacent data segment
    // memory. The diamond sprites at these offsets are the correct pre-spawn data.
    char path[256];
    Entity& diamond_tmpl = spawn_templates[15];
    for (int i = 0; i < 6; i++) {
        snprintf(path, sizeof(path), "sprites/diamond_f%02d.pam", i);
        int si = diamond_tmpl.spriteSheet >> 1;
        dump_sprite(path, res_data[si], diamond_sprite[i],
                    diamond_tmpl.spriteW, diamond_tmpl.spriteH, diamond_tmpl.colorMask);
        total++;
    }
    // Homing missiles — speed 0..8, sprite[9] is unused garbage
    Entity& homing_tmpl = spawn_templates[13];
    for (int i = 0; i < 9; i++) {
        snprintf(path, sizeof(path), "sprites/homing_f%02d.pam", i);
        int si = homing_tmpl.spriteSheet >> 1;
        dump_sprite(path, res_data[si], homing_sprite[i],
                    homing_tmpl.spriteW, homing_tmpl.spriteH, homing_tmpl.colorMask);
        total++;
    }

    // Terrain tiles — 42 tiles, width=24, height from tile_color[], sheet from tile index
    for (int t = 0; t < 42; t++) {
        int si = (t < 0x26) ? 2 : 1;  // spriteSheet: <38 → PODZ1(2), >=38 → BLOX(1)
        if (!res_data[si])
            continue;
        snprintf(path, sizeof(path), "sprites/tile_%02d.pam", t);
        dump_sprite(path, res_data[si], tile_sprite_data[t],
                    24, tile_color[t], tmpl_terrain.colorMask);
        total++;
    }

    // Full resource sheets (no transparency)
    for (int r = 0; r < RES_COUNT; r++) {
        if (!res_data[r])
            continue;
        snprintf(path, sizeof(path), "sprites/sheet_res%d.pam", r);
        FILE* f = fopen(path, "wb");
        int rows = 0x8000 / 0xa0;
        write_pam_header(f, 320, rows);
        for (int y = 0; y < rows; y++) {
            const uint8_t* row = res_data[r] + y * 0xa0;
            for (int x = 0; x < 160; x++) {
                write_rgba(f, row[x] >> 4, -1);
                write_rgba(f, row[x] & 0x0f, -1);
            }
        }
        fclose(f);
    }

    printf("Dumped %d sprite frames to sprites/\n", total);
    exit(0);
}
