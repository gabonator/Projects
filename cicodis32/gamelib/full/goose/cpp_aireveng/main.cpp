#include <vector>
#include <assert.h>
#include "sdl.h"
#include "ega.h"
#include "goose.h"

CSdl sdl;

class CEgaInstance : public CEga
{
public:
    virtual void sync() override
    {
        for (int y=0; y<200; y++)
          for (int x=0; x<320; x++)
            sdl.SetPixel(x, y, GetPixel(x, y));
        sdl.Loop();
    }
} ega;
CVideoAdapter* video = &ega;


uint8_t game_mode = 0;
uint8_t prev_game_mode = 0;
uint8_t exit_flag = 0;
uint8_t intro_running = 0;
uint8_t level_index = 0;
uint8_t level_sub = 0;
uint8_t restart_flag = 0;
uint16_t anim_speed = 0;
uint8_t audio_flag = 0;
uint8_t anim_counter = 0;
uint8_t process_flag = 0;
uint8_t hud_frame_ctr = 0;
uint8_t invuln_timer = 0;
uint8_t missile_n_state = 0;
uint8_t missile_m_state = 0;
uint8_t effect_flag_1 = 0;
uint8_t fire_trigger = 0;
uint8_t terrain_collide = 0;
uint8_t sound_ctrl = 0;
uint8_t sound_state = 0;
uint8_t sound_flag_1 = 0;
uint8_t sound_flag_2 = 0;
uint8_t sound_flag_3 = 0;
uint8_t music_playing = 0;
uint8_t tunnel_entered = 0;
uint16_t tunnel_section = 0;
uint8_t tunnel_flag = 0;
uint8_t tunnel_color = 0;
uint16_t map_section_idx = 0;
uint16_t input_state = 0;
uint16_t scroll_pos = 0;
uint16_t scroll_speed = 0;
uint16_t player_velocity = 0;
uint16_t display_page = 0;
uint16_t draw_page = 0;
uint16_t tunnel_distance = 0;
uint16_t tunnel_frame = 0;
uint16_t lives_count = 0;
uint16_t ammo_count = 0;
uint16_t score_delta = 0;
uint16_t fuel_level = 0;
uint16_t fuel_delta = 0;
uint16_t ammo_delta = 0;
uint16_t shield_active = 0;
uint16_t shield_delta = 0;
uint16_t render_to_screen = 0;
uint16_t sprite_target = 0;
uint16_t blit_row_stride = 0;
uint8_t  blit_transp_color = 0;
uint8_t  blit_transp_byte = 0;
const uint8_t* intro_text_ptr = nullptr;
uint16_t intro_frame_ctr = 0;
uint8_t keyboard_buf[128] = {};
uint16_t key_bindings[KEY_COUNT] = {};
uint16_t old_irq9_ofs = 0;
uint16_t old_irq9_seg = 0;
uint16_t old_timer_ofs = 0;
uint16_t old_timer_seg = 0;
uint16_t file_handle = 0;
uint16_t file_segment = 0;
uint16_t spawn_flags[64] = {};
uint16_t spawn_state[192] = {};
uint8_t score_table[42] = {};
uint8_t text_buffer[84] = {};
uint8_t hiscore_data[7] = {};
uint8_t sort_buffer[7] = {};
uint8_t* res_data[RES_COUNT] = {};
uint8_t* tunnel_buf = nullptr;
Entity* entities = nullptr;

// Remaining state variables
uint8_t respawn_flag = 0;
uint8_t mouse_present = 0;
uint8_t terrain_height = 0;
uint8_t leading_zero = 0;
uint8_t spawn_counter = 0;
uint8_t tunnel_spawner = 0;
uint8_t tunnel_sec_chg = 0;
uint8_t tunnel_walls = 0;
uint8_t tunnel_phase = 0;
uint8_t config_exists = 0;
uint8_t timer_tick = 0;
uint8_t terrain_value = 0;
uint8_t score_entries = 0;
uint8_t text_entry_idx = 0;
uint16_t last_key_pos = 0;
uint16_t terrain_y_base = 0;
uint8_t* terrain_tile_ptr = nullptr;
uint8_t map_tiles[768] = {};
uint16_t hud_sprite_pos = 0;
uint16_t saved_player_x = 0;
uint16_t saved_scroll = 0;
uint16_t map_spawn_ctr = 0;
uint16_t terrain_search = 0;
uint16_t tunnel_vel = 0;
uint16_t tunnel_horiz_in = 0;
uint16_t tunnel_vert_in = 0;
uint16_t tunnel_wave_pos = 0;
uint16_t tunnel_map_phase = 0;
uint16_t ammo_bar = 0;
uint16_t text_input_buf = 0;
uint16_t text_input_pos = 0;
// Sound state
uint8_t snd_note_duration = 0;
uint8_t snd_vibrato_type = 0;
uint8_t snd_vibrato_phase = 0;
uint8_t snd_tick_divider = 0;
uint8_t snd_duration = 5;       // EXE initial: 0x05
uint8_t snd_envelope = 0;
uint16_t snd_frequency = 0;
uint16_t snd_freq_slide = 0;
uint16_t snd_computed_freq = 0;
uint16_t snd_vibrato_idx = 0;
uint16_t snd_music_pos = 0;
const uint8_t* snd_music_table = nullptr;
SfxChannel sfx_channels[15] = {
    {0x00, 0x03, 0x36b0, 0xfe0c}, {0x00, 0x18, 0x36b0, 0xfe0c}, {0x00, 0x04, 0x1388, 0x03e8},
    {0x00, 0x04, 0x1770, 0x03e8}, {0x00, 0x06, 0x0320, 0x0190}, {0x02, 0x0c, 0x0fa0, 0xff38},
    {0x03, 0x0c, 0x0bb8, 0xff38}, {0x00, 0x02, 0x1f40, 0x0000}, {0x00, 0x03, 0x0258, 0x012c},
    {0x01, 0x10, 0x1964, 0x0000}, {0x02, 0x0a, 0x07d0, 0x0000}, {0x00, 0x32, 0x01f4, 0x012c},
    {0x03, 0x0a, 0x0fa0, 0xfed4}, {0x03, 0x0a, 0x03e8, 0x012c}, {0x00, 0x05, 0x07d0, 0x0000},
};
uint16_t snd_note_freq = 2000;  // EXE initial: 0x07D0
// Player position trail
uint16_t trail_x[4] = {};
uint16_t trail_y[4] = {};
uint8_t trail_dir[4] = {};
uint8_t trail_ht[4] = {};
uint8_t angle_trail[3] = {};
// Score (6-digit BCD)
uint8_t score_digits[6] = {};
// Power-up collected flags
uint8_t powerup_flags[6] = {};
// Entity templates
Entity tmpl_terrain = {};
Entity tmpl_bullet = {};
Entity tmpl_explode = {};
Entity tmpl_weapon = {};
Entity tmpl_spawn = {};
Entity tmpl_missile = {};
Entity tmpl_fire_spread = {};
Entity tmpl_secondary = {};
Entity tmpl_tunnel_spawn = {};
Entity tmpl_tunnel_entity = {};
Entity tmpl_tunnel_player = {};
Entity tmpl_tunnel_missile = {};
Entity tmpl_player = {};
Entity tmpl_respawn = {};
Entity tmpl_map_missile = {};
Entity spawn_templates[21] = {};
Entity tmpl_explosion_effect = {};
Entity tmpl_small_effect = {};
Entity visual_templates[21] = {};
Entity tmpl_intro_char = {};

void init_templates() {
    entity_from_raw(tmpl_terrain, tmpl_terrain_raw);
    entity_from_raw(tmpl_bullet, tmpl_bullet_raw);
    entity_from_raw(tmpl_explode, tmpl_explode_raw);
    entity_from_raw(tmpl_weapon, tmpl_weapon_raw);
    entity_from_raw(tmpl_spawn, tmpl_spawn_raw);
    entity_from_raw(tmpl_missile, tmpl_missile_raw);
    entity_from_raw(tmpl_fire_spread, tmpl_fire_spread_raw);
    entity_from_raw(tmpl_secondary, tmpl_secondary_raw);
    entity_from_raw(tmpl_tunnel_spawn, tmpl_tunnel_spawn_raw);
    entity_from_raw(tmpl_tunnel_entity, tmpl_tunnel_entity_raw);
    entity_from_raw(tmpl_tunnel_player, tmpl_tunnel_player_raw);
    entity_from_raw(tmpl_tunnel_missile, tmpl_tunnel_missile_raw);
    entity_from_raw(tmpl_player, tmpl_player_raw);
    entity_from_raw(tmpl_respawn, tmpl_respawn_raw);
    entity_from_raw(tmpl_map_missile, tmpl_map_missile_raw);
    for (int i = 0; i < 21; i++)
        entity_from_raw(spawn_templates[i], spawn_tmpl_raw[i]);
    entity_from_raw(tmpl_explosion_effect, tmpl_explosion_effect_raw);
    entity_from_raw(tmpl_small_effect, tmpl_small_effect_raw);
    for (int i = 0; i < 21; i++)
        entity_from_raw(visual_templates[i], visual_tmpl_raw[i]);
    entity_from_raw(tmpl_intro_char, tmpl_intro_char_raw);
}

void interrupt(int)
{
}

std::vector<uint8_t> getFileContents(const std::string& fullPath)
{
    // Simple fopen - files should be in the app's root directory
    FILE* file = fopen((std::string("dos/")+fullPath).c_str(), "rb");
    if (!file) {
        return {};
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    if (fileSize <= 0) {
        fclose(file);
        return {};
    }
    
    // Read the file contents
    std::vector<uint8_t> data(fileSize);
    size_t bytesRead = fread(data.data(), 1, fileSize, file);
    fclose(file);
    
    if (bytesRead != (size_t)fileSize) {
        return {};
    }
    
    return data;
}


Entity entity_storage[ENTITY_SLOTS + 1]; // standalone entity array

void init_entity_array() {
//    dseg = memory ? &memory[(ds - loadAddress) * 16] : nullptr;
    entities = entity_storage;
    memset(entity_storage, 0, sizeof(entity_storage));
    entities[ENTITY_SLOTS].flags = 0x80; // end-of-list sentinel
}

void init_resource_ptrs(uint16_t segs[RES_COUNT], uint16_t tunnel_seg) {
    (void)segs; (void)tunnel_seg; // segment values no longer used
    for (int i = 0; i < RES_COUNT; i++) {
        if (!res_data[i])
            res_data[i] = new uint8_t[0x8000](); // 32KB per resource
    }
    if (!tunnel_buf)
        tunnel_buf = new uint8_t[0x8000](); // 32KB tunnel buffer
}

void load(const char* path_, const char* file, int size)
{
}

void init();
void start();

void out8(int port, int data)
{
    if (port == 0x388 || port == 0x389) //audio
        return;

    if (port > 0x300)
        video->PortWrite8(port, data);
}
int in8(int port)
{
    if (port == 0x201 || port == 0x61)
        return 0;
    if (port == 0x388) //audio
        return 0x60;
    if (port == 0x40)
    {
        static int counter = 0;
        return (counter++ & 2) ? 0xff:0x00;
    }

    return video->PortRead8(port);
}
void out16(int port, int data)
{
    video->PortWrite16(port, data);
}

uint8_t vr8(uint16_t seg, uint16_t ofs) { return video->Read(seg * 16 + ofs); }
void vw8(uint16_t seg, uint16_t ofs, uint8_t val) { video->Write(seg * 16 + ofs, val); }
uint16_t vr16(uint16_t seg, uint16_t ofs) { return video->Read(seg*16+ofs) | (video->Read(seg*16+ofs+1) << 8); }
void vw16(uint16_t seg, uint16_t ofs, uint16_t val) { video->Write(seg*16+ofs, val & 0xff); video->Write(seg*16+ofs+1, val >> 8); }

int main(int argc, char* argv[])
{
    sdl.Init();
    start();
    sdl.Deinit();
    return 0;
}

void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
    if (1)
    {
        #define MAPKEY( c, v ) if (k==c) keyboard_buf[v] = p
        MAPKEY( SDL_SCANCODE_LEFT, 75 );
        MAPKEY( SDL_SCANCODE_RIGHT, 77 );
        MAPKEY( SDL_SCANCODE_DOWN, 80 );
        MAPKEY( SDL_SCANCODE_UP, 72 );
        MAPKEY( SDL_SCANCODE_SPACE, 57 );
        MAPKEY( SDL_SCANCODE_N, 49 );
        MAPKEY( SDL_SCANCODE_M, 50 );
        MAPKEY( SDL_SCANCODE_Q, 16 );
        MAPKEY( SDL_SCANCODE_Y, 21 );

        MAPKEY( SDL_SCANCODE_Z, 0x3b );
        #undef MAPKEY
    }
    //lastKey
}
