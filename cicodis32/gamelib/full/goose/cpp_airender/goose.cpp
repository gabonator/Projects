#include "goose.h"

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
Entity entities[ENTITY_SLOTS + 1]; // standalone entity array

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
Entity tmpl_terrain          = {.flags=0x01, .zLayer=0x07, .spriteW=0x18};
Entity tmpl_bullet           = {.flags=0x03, .zLayer=0x05, .dirFlag=0x01, .colorMask=0x02, .type=0x16};
Entity tmpl_explode          = {.flags=0x03, .zLayer=0x05, .x=0x0080, .y=0x0050, .spriteW=0x20, .spriteH=0x1d, .drawOfsY=0x10, .drawOfsX=0x0e, .spriteSheet=0x0002, .spriteData=0x4bc8, .colorMask=0x02, .type=0x10};
Entity tmpl_weapon           = {.flags=0x03, .zLayer=0x05, .x=0x0080, .y=0x0050, .spriteW=0x14, .spriteH=0x0f, .drawOfsY=0x0a, .drawOfsX=0x07, .spriteData=0x445e, .colorMask=0x02, .type=0x17};
Entity tmpl_spawn            = {.flags=0x43, .zLayer=0x03, .x=0x0080, .y=0x0060, .spriteW=0x04, .spriteH=0x04, .drawOfsY=0x01, .drawOfsX=0x02, .spriteData=0x7442, .colorMask=0x02, .type=0x13};
Entity tmpl_missile          = {.flags=0x03, .zLayer=0x03, .x=0x0080, .y=0x0060, .spriteW=0x04, .spriteH=0x04, .drawOfsY=0x01, .drawOfsX=0x02, .spriteData=0x7446, .colorMask=0x02, .type=0x14};
Entity tmpl_fire_spread      = {.flags=0x03, .zLayer=0x03, .x=0x0080, .y=0x0060, .spriteW=0x10, .spriteH=0x0c, .drawOfsY=0x08, .drawOfsX=0x06, .spriteData=0x3794, .colorMask=0x0d, .type=0x1d};
Entity tmpl_secondary        = {.flags=0x03, .zLayer=0x02, .x=0x0080, .y=0x0060, .spriteW=0x08, .spriteH=0x07, .drawOfsY=0x03, .drawOfsX=0x03, .spriteData=0x78aa, .colorMask=0x02, .type=0x1e};
Entity tmpl_tunnel_spawn     = {.flags=0x03, .zLayer=0x07, .x=0x0080, .y=0x006a, .spriteW=0x04, .spriteH=0x02, .drawOfsX=0x01, .spriteSheet=0x0008, .spriteData=0x7bee, .colorMask=0x02, .type=0x0e};
Entity tmpl_tunnel_entity    = {.flags=0x03, .zLayer=0x06, .x=0x0080, .y=0x006a, .spriteW=0x04, .spriteH=0x02, .drawOfsX=0x01, .spriteSheet=0x0008, .spriteData=0x20a8, .colorMask=0x02, .type=0x0f};
Entity tmpl_tunnel_player    = {.flags=0x03, .zLayer=0x02, .x=0x0080, .y=0x009a, .spriteW=0x40, .spriteH=0x27, .drawOfsY=0x20, .drawOfsX=0x13, .spriteSheet=0x0006, .colorMask=0x02, .type=0x0c};
Entity tmpl_tunnel_missile   = {.flags=0x03, .zLayer=0x02, .x=0x0080, .y=0x009a, .spriteW=0x18, .spriteH=0x13, .drawOfsY=0x0b, .drawOfsX=0x0a, .spriteSheet=0x0002, .spriteData=0x5238, .colorMask=0x02, .type=0x22};
Entity tmpl_player           = {.flags=0x03, .zLayer=0x04, .x=0x0080, .spriteData=0x1e10, .colorMask=0x02, .type=0x01};
Entity tmpl_respawn          = {.flags=0x03, .zLayer=0x01, .x=0x0080, .y=0x0050, .spriteW=0x40, .spriteH=0x2a, .drawOfsY=0x20, .drawOfsX=0x15, .spriteData=0x632e, .colorMask=0x02, .type=0x1b};
Entity tmpl_map_missile      = {.flags=0x43, .zLayer=0x02, .colorMask=0x02, .type=0x18, .hitPoints=0x05};
//                              flg  dir  zL  hOfs dFlg x       y       sW   sH   dOY  dOX  sSht    sData   cM   type param    hP   aF
Entity spawn_templates[21] = {
    {0x0b,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x1c,0x18,0x0f,0x12, 0x0000,0x0030, 0x02,0x02, {0x0000},0x28,0x00},
    {0x0b,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x14,0x19,0x0a,0x0b, 0x0000,0x4d10, 0x02,0x03, {0x0000},0x28,0x00},
    {0x1b,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x10,0x13,0x13,0x0d, 0x0000,0x5b7a, 0x02,0x04, {0x0000},0x28,0x00},
    {0x0b,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x1c,0x1e,0x10,0x0f, 0x0000,0x0064, 0x02,0x05, {0x0000},0x3c,0x00},
    {0x0b,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x18,0x15,0x0d,0x13, 0x0000,0x0080, 0x02,0x06, {0x0000},0x46,0x00},
    {0x0b,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x20,0x1b,0x10,0x0c, 0x0000,0x1b54, 0x02,0x07, {0x0000},0x64,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x2c,0x17,0x0a,0x13, 0x0002,0x6540, 0x02,0x08, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x2c,0x06,0x08,0xfd, 0x0004,0x46a0, 0x02,0x09, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x20,0x1e,0x04,0x08, 0x0004,0x2348, 0x02,0x0a, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x20,0x1e,0x04,0x08, 0x0004,0x2348, 0x02,0x0b, {0x0000},0x00,0x00},
    {0x03,0x00,0x01,0x00,0x00, 0x0000,0x0000, 0x2c,0x09,0x0a,0x0c, 0x0002,0x5fa0, 0x02,0x0d, {0x0000},0x00,0x00},
    {0x03,0x00,0x06,0x00,0x00, 0x0000,0x0000, 0x20,0x19,0x0f,0x0d, 0x0000,0x2502, 0x02,0x1a, {0x0000},0x32,0x00},
    {0x03,0x01,0x06,0x00,0x00, 0x0000,0x0000, 0x20,0x19,0x10,0x0f, 0x0002,0x4286, 0x0d,0x1a, {0x0000},0x28,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x20,0x18,0x04,0xfd, 0x0002,0x6e32, 0x02,0x1c, {0x0000},0x00,0x00},
    {0x03,0x02,0x06,0x00,0x00, 0x0000,0x0000, 0x1c,0x19,0x0f,0x0f, 0x0004,0x2068, 0x02,0x1a, {0x0000},0x3c,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x10,0x0c,0x07,0xfe, 0x0000,0x43ae, 0x02,0x20, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x10,0x0c,0x07,0xfe, 0x0000,0x43ae, 0x02,0x20, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x10,0x0c,0x07,0xfe, 0x0000,0x43ae, 0x02,0x20, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x10,0x0c,0x07,0xfe, 0x0000,0x43ae, 0x02,0x20, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x10,0x0c,0x07,0xfe, 0x0000,0x43ae, 0x02,0x20, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x10,0x0c,0x07,0xfe, 0x0000,0x43ae, 0x02,0x20, {0x0000},0x00,0x00},
};
Entity tmpl_explosion_effect = {.flags=0x03, .zLayer=0x03, .x=0x0080, .y=0x0060, .spriteW=0x08, .spriteH=0x05, .drawOfsY=0x02, .drawOfsX=0x02, .spriteData=0x3b06, .colorMask=0x02, .type=0x15};
Entity tmpl_small_effect     = {.flags=0x03, .zLayer=0x02, .x=0x0080, .y=0x0050, .spriteW=0x10, .spriteH=0x0f, .drawOfsY=0x08, .drawOfsX=0x07, .spriteData=0x005c, .colorMask=0x02, .type=0x1f};
//                              flg  dir  zL  hOfs dFlg x       y       sW   sH   dOY  dOX  sSht    sData   cM   type param    hP   aF
Entity visual_templates[21] = {
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x14,0x0b,0x0a,0xfe, 0x0000,0x0f3a, 0x02,0x12, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x14,0x0b,0x0a,0xfe, 0x0000,0x0f3a, 0x02,0x12, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x14,0x0b,0x0a,0xfe, 0x0000,0x0f3a, 0x02,0x12, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x08,0x05,0x04,0xfc, 0x0000,0x6890, 0x02,0x12, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x08,0x05,0x10,0x04, 0x0000,0x6890, 0x02,0x12, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x18,0x0d,0x0a,0x00, 0x0000,0x5b9e, 0x02,0x12, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x18,0x0d,0x0b,0x01, 0x0000,0x7222, 0x02,0x12, {0x0000},0x00,0x00},
    {0x03,0x00,0x07,0x00,0x00, 0x0000,0x0000, 0x18,0x0d,0x0a,0x00, 0x0000,0x5b9e, 0x02,0x12, {0x0000},0x00,0x00},
    {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {},
};
Entity tmpl_intro_char       = {.flags=0x03, .zLayer=0x04, .x=0x0080, .y=0x00c8, .spriteW=0x20, .spriteH=0x1e, .spriteSheet=0x0002, .spriteData=0x4bb8, .colorMask=0x02, .type=0x21};

void game_entry();

void start() // reads: none writes: none
{
    game_entry();
}

void game_entry();
void intro_and_init_level();
void gameplay_loop();
void set_restart_flag();
void intro_credits_animation();
void display_single_char(uint8_t char_code);
void wait_for_scroll();
void read_input();
void configure_keys_interactive();
void init_default_keys();
void restore_keyboard_irq();
void keyboard_isr();
uint16_t wait_for_key();
void wait_all_keys_released();
uint16_t scan_keyboard_input();
void init_mouse();
void init_timer_irq();
void restore_timer_irq();
void install_critical_error_handler();
void load_all_resources();
void load_resource_file(int res_index, const char* filename);
void load_map_data();
void build_terrain_map();
TerrainInfo get_terrain_at_position(uint16_t entity_y, uint16_t entity_x);
void load_map_section(uint16_t section_index);
void spawn_entities_from_map(Entity& e);
void init_terrain_height_table();
void spawn_entity_from_data(uint16_t entity_ptr, uint16_t spawn_type, uint16_t entity_data);
uint16_t process_entity_spawn(uint16_t entity_data, uint16_t spawn_type);
void copy_entity_template(uint16_t esi);
TerrainCollisionResult check_terrain_collision();
CollisionResult check_entity_collision(uint16_t index, uint16_t position);
uint16_t add_entity_to_list(const Entity& tmpl);
void clear_entity_list();
void render_all_sprites();
void render_entity_to_offscreen(Entity& tmpl);
void blit_sprite_clipped(uint16_t height, uint16_t width, uint16_t scroll_y, uint16_t screen_x, uint8_t* sprite_data, uint16_t sprite_ofs);
void init_level_state();
void init_rendering_context();
void advance_level();
void handle_death();
void init_entity_spawn_state();
void spawn_player_entity();
void init_tunnel_mode();
void init_bullet_tracking();
void update_all_entities();
void cull_behind(uint16_t esi);
void cull_offscreen(uint16_t esi);
void falling_projectile(uint16_t esi);
void player_update(uint16_t esi);
void death_decelerate(uint16_t esi);
void animated_passive_timed(uint16_t esi);
void terrain_obstacle(uint16_t esi);
void missile_state_check(uint16_t esi);
void moving_enemy_lifetime(uint16_t esi);
void directional_projectile(uint16_t esi);
void hazard_shield_damage(uint16_t esi);
void ground_enemy_shooting(uint16_t esi);
void countdown_self_destruct(uint16_t esi);
void enemy_missile_anim(uint16_t esi);
void explosion_5frame(uint16_t esi);
void explosion_6frame(uint16_t esi);
void brief_effect(uint16_t esi);
void anim_loop_4frame(uint16_t esi);
void anim_loop_6frame(uint16_t esi);
void vertical_tracker(uint16_t esi);
void vertical_tracker_spawner(uint16_t esi);
void bouncing_projectile(uint16_t esi);
void enemy_anim_fire(uint16_t esi);
void homing_enemy(uint16_t esi);
void enter_tunnel_mode();
void tunnel_entry_trigger(uint16_t esi);
void tunnel_camera_control(uint16_t esi);
void homing_approach(uint16_t esi);
void diamond_collectible(uint16_t esi);
void powerup_collectible(uint16_t esi);
void slow_scroll_entity(uint16_t esi);
void update_player_animation();
void handle_vertical_scroll();
void advance_map_position();
uint16_t entity_movement_helper(uint16_t entity_data, uint16_t spawn_type);
void deactivate_entity(uint16_t esi);
void entity_terrain_response(TerrainCollisionResult tcr);
void entity_setup_sprite();
void setup_missile_entity(uint16_t esi);
void setup_missile_entity(Entity& e);
void player_fire_weapon();
void enemy_spawn_bullet(uint16_t esi);
void spawn_bullet_entity(uint16_t esi, uint16_t x_offset, uint16_t y_offset, uint8_t height_offset);
void update_bullet_positions(uint16_t esi);
void fire_spread_bullets(uint16_t esi);
void spawn_secondary_entity(uint16_t esi);
void spawn_explosion_at_entity(uint16_t esi);
void mark_entity_destroyed(uint16_t esi);
void spawn_death_explosion(uint16_t esi);
void apply_entity_template(const Entity& src, uint16_t esi);
void spawn_hit_effect(uint16_t esi);
void remove_entity(uint16_t esi);
void load_sprite_data(const SpriteTable& spr, uint16_t entity_ptr);
void load_sprite_data(const SpriteTable& spr, Entity& e);
uint16_t track_player_vertically(uint16_t esi);
void init_game_parameters();
void reset_hud_values();
void update_hud_bars();
void init_hud_display();
void draw_lives_display();
void draw_hud_label();
void draw_score_digits();
void draw_fuel_label();
void draw_ammo_label();
void draw_shield_label();
void increment_score_display();
void draw_diamond_counter();
void draw_diamond_icon();
void draw_diamond_icon_2();
void draw_diamond_icon_3();
void draw_diamond_icon_4();
void draw_diamond_icon_5();
void decrement_score_display();
void init_fuel_bar();
void decrease_fuel_bar();
void set_fuel_bar();
void increase_fuel_bar();
void init_ammo_bar();
void decrease_ammo_bar();
void set_ammo_bar();
void increase_ammo_bar();
void init_shield_bar();
void decrease_shield_bar();
void set_shield_bar();
void increase_shield_bar();
void draw_hud_bar_pixel(uint16_t row_offset, uint16_t pixel_x);
void update_score_bcd();
void increment_score();
void update_diamond_counter();
void check_all_diamonds();
void add_bcd_score(uint16_t ones, uint16_t tens, uint16_t hundreds, uint16_t thousands);
void update_weapon_effects();
void init_font_and_hud();
void load_intro_text_restart();
void draw_text_block();
uint16_t draw_text_line(uint16_t entry_a_idx, uint16_t entry_b_idx);
void load_intro_text_first();
void store_intro_text_data(uint16_t hud_pos, uint16_t hiscore_idx);
void decode_sprite_char(uint16_t hud_pos, uint16_t hiscore_idx);
void draw_sprite_row(uint16_t text_ofs);
void load_hiscore_file();
void blit_char_sprite(uint16_t col_offset, uint16_t sprite_offset);
void toggle_intro_display();
void clear_intro_area();
void draw_hiscore_table();
void activate_powerup(uint8_t powerup_id);
void start_key_config_screen();
void save_key_config();
void show_key_prompt(uint8_t bar_index);
void draw_single_hud_bar(uint8_t bar_index);
void blit_sprite_masked(uint8_t* sprite_data, uint16_t row_count, uint16_t width, uint16_t video_dest, uint16_t sprite_source);
void fill_rect_ega(uint16_t color, uint16_t height, uint16_t width, uint16_t base_addr);
void init_tunnel_entity_data();
void clear_tunnel_entities();
void tunnel_player_handler(uint16_t esi);
void tunnel_missile_entity(uint16_t esi);
void tunnel_enemy_positioned(uint16_t esi);
void tunnel_exit_trigger(uint16_t esi);
void tunnel_update_position(uint16_t esi);
int16_t tunnel_check_collision(uint8_t angle);
void tunnel_frame_update();
void tunnel_position_entity(uint8_t dist_idx, uint16_t esi);
// tunnel_set_y_top/x_right/y_bottom/x_left inlined into tunnel_position_entity
void render_tunnel_buffer();
uint16_t get_tunnel_plane_mask();
uint16_t get_tunnel_bg_color();
void render_map_buffer();
void init_ega_double_buffer();
void page_flip_and_vsync();
void clear_video_buffer(uint8_t color);
void wait_vsync();
void blit_fullscreen_bitmap(uint8_t* src_data);
void clear_and_init_buffers();
void draw_hud_border_frame();
void init_intro_sprites();
void render_intro_background();
void draw_tunnel_wireframe();
void draw_tunnel_octant_lines(uint16_t param_a, uint16_t param_b);
void draw_line_bresenham(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
// compute_pixel_position inlined into draw_line_bresenham
void init_sound_state();
void play_sound_effect(uint8_t sound_id);
void update_sound_channel(uint8_t chan_id);
void shutdown_sound();
void init_sound_system();
void timer_isr();
void sound_tick();
void music_sequencer_tick();
void play_music_note(uint8_t note);
void clear_offscreen_buffer();

void game_entry() // 1000:0010 +entry — game_entry: allocates memory, loads resources, runs game loop
{
    init_entity_array();
    // Allocate standalone resource buffers
    init_resource_ptrs(nullptr, 0);

    printf("Star Goose (C) 1988 Logotron Ltd ...Loading... ");
    load_all_resources();
    init_ega_double_buffer();
    init_font_and_hud();
    install_critical_error_handler();
    init_default_keys();
    init_mouse();
    init_timer_irq();
    init_sound_state();
    level_index = 0x00;

    // --- Main game loop (infinite) ---
    while (true) {
        intro_and_init_level();
        gameplay_loop();
        set_restart_flag();
    }
}
void intro_and_init_level() // 1000:00a9 — intro_and_init_level: shows intro credits, initializes level
{
    intro_credits_animation(); // intro_credits_animation
    exit_flag = 0x00;
    audio_flag = 0x01;
    anim_speed = 0x10; // base animation speed
    game_mode = 0x00; // start in map mode
    level_sub = 0x00;
    init_rendering_context(); // init_rendering_context
    clear_and_init_buffers(); // clear_both_pages
    init_game_parameters(); // init_game_parameters
}
void gameplay_loop() // 1000:00cf — gameplay_loop: main frame loop (input → update → render → flip)
{
    while (!exit_flag) {
        read_input();
        update_all_entities();
        if (game_mode) {
            // Tunnel mode rendering
            draw_tunnel_wireframe();
            render_tunnel_buffer();
        } else {
            // Map mode rendering
            render_map_buffer();
        }
        render_all_sprites();
        update_hud_bars();
        page_flip_and_vsync();
    }
}
void set_restart_flag() // 1000:00fd — set_restart_flag: marks that game has been played once (affects intro)
{
    restart_flag = 0x01;
}
void intro_credits_animation() // 1000:0103 — intro_credits_animation: displays scrolling intro/credits text
{
    if (restart_flag) {
        intro_text_ptr = intro_text_restart;
        load_intro_text_restart();
    } else {
        intro_text_ptr = intro_text_first;
        load_intro_text_first();
    }
    init_sound_system();
    init_intro_sprites();
    intro_running = 0x01;
    intro_frame_ctr = 0;
    init_level_state();

    while (true) {
        read_input();
        update_all_entities();
        render_intro_background();
        render_all_sprites();
        page_flip_and_vsync();
        if (input_state & INPUT_FIRE)
            break;
        intro_frame_ctr++;
        uint16_t frame = intro_frame_ctr;
        if (frame & 0x0007)
            continue;
        uint8_t ch = intro_text_ptr[frame >> 3];
        if (ch == 0x00)
            continue;
        if (ch == 0xff)
            break;
        if (ch == 0xfe) {
            if (config_exists)
                toggle_intro_display();
            else
                wait_for_scroll();
        } else if (ch & 0x80) {
            display_single_char(ch & 0x3f);
            display_single_char((ch & 0x3f) + 1);
        } else {
            display_single_char(ch);
        }
    }
    intro_running = 0x00;
}
void display_single_char(uint8_t char_code) // 1000:019d — display_single_char: adds a character entity for intro text display
{
    Entity ch = tmpl_intro_char;
    ch.dirFlag = char_code; // set character code as direction flag
    load_sprite_data(spr_0120, ch); // load_sprite_data (loads glyph sprite for this char)
    add_entity_to_list(ch);
}
void wait_for_scroll() // 1000:01ad — wait_for_scroll: busy-waits, polling input, until fire pressed or timeout
{
    for (int i = 8000; i > 0; i--) {
        read_input();
        if (input_state & INPUT_FIRE)
            return;
    }
}
void quit_game() // 1000:0096 — quit_game: restore interrupts, set text mode, exit
{
    shutdown_sound();
    restore_timer_irq();
    restore_keyboard_irq();
    exit(1);
}
void read_input() // 1000:01c0 — read_input: scans keyboard buffer, builds INPUT_STATE bitfield, handles mouse
{
    // F3 = pause: wait for F4 to resume
    if (keyboard_buf[0x3d]) {
        while (!keyboard_buf[0x3e]) {}
    }
    // F1 = redefine keys
    if (keyboard_buf[0x3b])
        configure_keys_interactive();

    // Build direction input state
    if (keyboard_buf[key_bindings[KEY_LEFT]])
        input_state = INPUT_LEFT;
    else if (keyboard_buf[key_bindings[KEY_RIGHT]])
        input_state = INPUT_RIGHT;
    else
        input_state = 0x0000;

    if (keyboard_buf[key_bindings[KEY_UP]])
        input_state |= INPUT_UP;
    else if (keyboard_buf[key_bindings[KEY_DOWN]])
        input_state |= INPUT_DOWN;

    if (keyboard_buf[key_bindings[KEY_FIRE]])
        input_state |= INPUT_FIRE;
    if (keyboard_buf[key_bindings[KEY_MISSILE_N]])
        input_state |= INPUT_MISSILE_N;
    if (keyboard_buf[key_bindings[KEY_MISSILE_M]])
        input_state |= INPUT_MISSILE_M;

    // Q key = quit (confirm with Y/N)
    if (keyboard_buf[key_bindings[KEY_QUIT]]) {
        save_key_config(); // display_quit_prompt
        while (!keyboard_buf[0x15] && !keyboard_buf[0x31]) {} // wait for Y or N
        if (keyboard_buf[0x15])
            quit_game();
        wait_all_keys_released();
    }

    // P key (offset 0x3c) = toggle sound
    if (keyboard_buf[0x3c]) {
        if (sound_state == 0x00) {
            play_sound_effect(0x0e);
            sound_state = 0x01;
            sound_ctrl = 0x00;
        } else if (sound_state == 0x02) {
            sound_state = 0x03;
            sound_ctrl = 0x01;
            play_sound_effect(0x0d);
        }
    } else {
        if (sound_state == 0x01)
            sound_state = 0x02;
        else if (sound_state == 0x03)
            sound_state = 0x00;
    }

}
void configure_keys_interactive() // 1000:033b — lets user reassign all 8 keys, rejecting duplicates
{
    // Helper: check if scancode matches any of the already-assigned keys
    uint16_t assigned[8];
    int count = 0;
    auto is_duplicate = [&](uint16_t scan) {
        for (int i = 0; i < count; i++)
            if (scan == assigned[i]) return true;
        return false;
    };
    // Order: fire, left, right, up, down, missile_n, missile_m, quit
    constexpr KeyIndex keys[] = {KEY_FIRE, KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, KEY_MISSILE_N, KEY_MISSILE_M, KEY_QUIT};
    constexpr int prompts[] = {0x04, 0x00, 0x01, 0x02, 0x03, 0x06, 0x07, 0x05};

    start_key_config_screen();
    for (int i = 0; i < 8; i++) {
        show_key_prompt(prompts[i]);
        uint16_t scan;
        do {
            scan = wait_for_key();
        } while (is_duplicate(scan));
        key_bindings[keys[i]] = scan;
        assigned[count++] = scan;
    }
    wait_all_keys_released();
}
void init_default_keys() // 1000:0442 — init_default_keys: sets default key bindings and installs keyboard IRQ
{
    last_key_pos = 0x0000; // clear key config flag
    key_bindings[KEY_LEFT]      = 0x004b; // left arrow
    key_bindings[KEY_RIGHT]     = 0x004d; // right arrow
    key_bindings[KEY_UP]        = 0x0048; // up arrow
    key_bindings[KEY_DOWN]      = 0x0050; // down arrow
    key_bindings[KEY_FIRE]      = 0x0039; // space bar
    key_bindings[KEY_MISSILE_N] = 0x0031; // N key
    key_bindings[KEY_MISSILE_M] = 0x0032; // M key
    key_bindings[KEY_QUIT]      = 0x0010; // Q key
    memset(keyboard_buf, 0, sizeof(keyboard_buf));
}
void restore_keyboard_irq() // 1000:04a5 — no-op in emulator
{
}
void keyboard_isr() // 1000:04b7 — INT 9 keyboard ISR: reads scan code from port 0x60, updates keyboard_buf
{
    uint8_t scancode = in8(0x60);
    // Acknowledge keyboard controller (toggle bit 7 of port 0x61)
    uint8_t port61 = in8(0x61);
    out8(0x61, port61 | 0x80);
    out8(0x61, port61);
    // Update keyboard buffer
    if (scancode & 0x80)
        keyboard_buf[scancode & 0x7f] = 0x00; // key released
    else
        keyboard_buf[scancode] = 0x01;         // key pressed
    out8(0x20, 0x20); // send EOI to PIC
}
uint16_t wait_for_key() // 1000:04f3 — wait_for_key: scans keyboard buffer, returns scan code of first non-special key
{
    while (true) {
        for (int scan = 0; scan < 0x80; scan++) {
            if (!keyboard_buf[scan])
                continue;
            // Skip special keys: F1-F4, LShift, RShift
            if (scan == 0x3b || scan == 0x3c || scan == 0x3d || scan == 0x3e ||
                scan == 0x2a || scan == 0x36)
                continue;
            return scan;
        }
    }
}
void wait_all_keys_released() // 1000:0529 — wait_all_keys_released: waits until no keys are held down
{
    bool any_held;
    do {
        any_held = false;
        for (int i = 0; i < 0x80; i++) {
            if (keyboard_buf[i])
                any_held = true;
        }
    } while (any_held);
}
uint16_t scan_keyboard_input() // 1000:0541 — scans keyboard buffer for newly pressed key, returns action
{
    uint16_t last_scan = last_key_pos; // last scancode position (as buffer offset)
    for (int attempt = 0x4e20; attempt > 0; attempt--) {
        bool found_any = false;
        for (int i = 0; i < 128; i++) {
            if (!keyboard_buf[i])
                continue;
            found_any = true;
            uint16_t pos = KEYBOARD_BUF + i + 1; // matches original si after lodsb
            if (pos == last_scan)
                continue; // skip if same as last reported key
            // New key found — record position and look up action
            last_key_pos = pos;
            uint8_t action = key_action_map[i]; // key-to-action mapping table at ds:0x005A
            if (!action)
                break; // unmapped key, try again
            if ((int8_t)action < 0)
                action = 0x00; // clamp negative values
            return action;
        }
        if (!found_any) {
            last_key_pos = 0x0000;
        }
    }
    return 0;
}
void init_mouse() // no mouse in emulator
{
    mouse_present = 0;
}
void init_timer_irq() // no-op in emulator (PIT reprogramming not needed)
{
}
void restore_timer_irq() // no-op in emulator
{
}
void install_critical_error_handler() // no-op in emulator
{
}
void load_all_resources() // 1000:0600 — load_all_resources: loads 6 .X sprite sheet files
{
    load_resource_file(RES_BIRD1, "BIRD1.X");
    load_resource_file(RES_BIRD2, "BIRD2.X");
    load_resource_file(RES_BLOX, "BLOX.X");
    load_resource_file(RES_NEWBIRD, "NEWBIRD.X");
    load_resource_file(RES_PODZ1, "PODZ1.X");
    load_resource_file(RES_INTRO, "INTRO.X");
}
void load_map_data() // 1000:069a — load_map_data: decodes map section for current level into entity spawn table and terrain tiles
{
    int table_idx = level_index * 3 + level_sub;

    // --- Part 1: Decode entity spawn flags ---
    // Clear spawn flags table (64 words)
    memset(spawn_flags, 0, sizeof(spawn_flags));

    // Read spawn data: triplets (entity_type, bitmask_index, section) until 0xFF terminator
    const uint8_t* src = map_spawn_tbl[table_idx];
    while (true) {
        uint8_t entity_type = *src++;
        if (entity_type == 0xff)
            break;
        uint8_t type_bits = entity_type << 2;   // entity type shifted into high byte position
        uint8_t bitmask_idx = *src++;       // index into bitmask LUT
        uint16_t spawn_bits = (type_bits << 8) | bitmask_lut[bitmask_idx];
        int section = 0x3f - *src++; // section index (reversed)
        spawn_flags[section] |= spawn_bits;
    }

    // --- Part 2: RLE-decode terrain tile data (768 bytes) ---
    const uint8_t* tsrc = terrain_data_tbl[table_idx];
    int out = 0;
    int8_t repeat = 0;
    uint8_t tile = 0;
    for (int remaining = 0x0300; remaining > 0; remaining--) {
        repeat--;
        if (repeat < 0) {
            uint8_t raw = *tsrc++;
            tile = raw & 0x3f;
            repeat = (raw >> 6); // 0=no repeat, 1-3=repeat count
            if (repeat == 0)
                repeat = 0; // new byte each time
        }
        map_tiles[out] = tile;
        out++;
    }
    // --- Part 3: Clear offscreen terrain buffer (EGA page at A800:0000) ---
    clear_offscreen_buffer();

    // --- Part 4: Render terrain columns into offscreen buffer ---
    terrain_tile_ptr = map_tiles; // tile read pointer
    terrain_y_base = 0x03f0;    // Y base position
    for (int col = 0x0040; col > 0; col--) {
        terrain_height = 0x00; // terrain height accumulator
        // Top row (8px tall)
        build_terrain_map();
        tmpl_terrain.x = 0x0000;
        tmpl_terrain.spriteW = 0x08;
        tmpl_terrain.spriteData += 0x0008;
        render_entity_to_offscreen(tmpl_terrain);
        // Middle 10 rows (24px each)
        tmpl_terrain.x = 0x0008;
        tmpl_terrain.spriteW = 0x18;
        for (int row = 0x000a; row > 0; row--) {
            build_terrain_map();
            render_entity_to_offscreen(tmpl_terrain);
            tmpl_terrain.x += 0x0018;
        }
        // Bottom row (8px tall)
        tmpl_terrain.spriteW = 0x08;
        build_terrain_map();
        render_entity_to_offscreen(tmpl_terrain);
        terrain_y_base -= 0x0010;
    }
}
void build_terrain_map() // 1000:07af — reads next tile, sets up rendering parameters for terrain block
{
    tmpl_terrain.heightOfs = terrain_height; // copy height accumulator to render param
    uint8_t tile = *terrain_tile_ptr++;

    tmpl_terrain.spriteH = tile_color[tile];
    terrain_height += tile_height[tile]; // accumulate height
    int8_t y_offset = (int8_t)tile_yofs[tile];
    tmpl_terrain.y = (int16_t)y_offset + terrain_y_base; // Y position
    tmpl_terrain.spriteSheet = (tile < 0x26) ? 0x0004 : 0x0002; // sprite sheet selector
    tmpl_terrain.spriteData = tile_sprite_data[tile];
}
TerrainInfo get_terrain_at_position(uint16_t entity_y, uint16_t entity_x) // 1000:07fd get_terrain_at_position
{
    // Convert pixel coordinates to tile coordinates
    uint16_t adjusted_x = entity_x + 0x0010;
    uint16_t tile_col = adjusted_x / 0x18;         // x tile index (24px wide tiles)
    uint16_t sub_tile_x = (adjusted_x % 0x18) / 3; // x sub-tile (3px granularity)
    uint16_t tile_row = 0x3f - ((entity_y & 0x03ff) >> 4); // y tile row (inverted, 16px tall)
    uint16_t sub_tile_y = (entity_y & 0x000f) >> 1;        // y sub-tile (2px granularity)

    // Look up tile at (tile_row, tile_col) in map_tiles[row*12 + col]
    uint16_t row_offset = tile_row * 4;
    uint16_t map_offset = row_offset + row_offset * 2; // row*12
    uint8_t tile = map_tiles[map_offset + tile_col];

    // Look up collision shape from tile shape table
    uint8_t collision = tile_shape_ptr[tile][sub_tile_y * 8 + sub_tile_x];

    // Extract height from collision data (5-bit signed, sign-extended)
    int8_t height = collision & 0x1f;
    if (height & 0x10)
        height |= 0xe0; // sign-extend from 5 bits

    // Accumulate heights across tiles in this row up to tile_col
    for (uint16_t i = 0; i < tile_col; i++) {
        uint8_t t = map_tiles[map_offset + i];
        height += tile_height[t];
    }

    // Determine terrain type based on collision flag
    TerrainInfo result;
    result.height = (uint8_t)(int8_t)height;
    result.type = (collision & 0x80)
        ? tile_terrain_hazard[tile]
        : tile_terrain_normal[tile];
    result.section = 0x3f - tile_row;
    return result;
}
void load_map_section(uint16_t section_index) // 1000:08ba load_map_section
{
    uint16_t flags_val = spawn_flags[section_index];
    if (!flags_val)
        return;

    uint8_t entity_type = (flags_val >> 8) >> 2; // high byte >> 2
    Entity ent = spawn_templates[entity_type];

    // Special handling for entity types 0x0F-0x14 (diamond pickups)
    if (entity_type >= 0x0f && entity_type <= 0x14) {
        uint8_t diamond_idx = entity_type - 0x0f;
        ent.direction = diamond_idx;
        if (powerup_flags[diamond_idx]) // already collected?
            return;
        ent.spriteData = diamond_sprite[diamond_idx]; // diamond sprite data
    }

    ent.param1 = 0x0a; // spawn counter
    ent.param2 = (uint8_t)section_index;

    // Process 10 spawn bits (one per entity slot)
    for (int bit = 0; bit < 10; bit++) {
        if (flags_val & 1) {
            spawn_entities_from_map(ent);
            uint16_t spawn_result = process_entity_spawn(section_index, (uint16_t)ent.param1);
            if (spawn_result) {
                add_entity_to_list(ent);
            } else {
                uint16_t spawned = add_entity_to_list(ent);
                if (spawned)
                    copy_entity_template(spawned);
            }
        }
        flags_val >>= 1;
        ent.param1--;
    }
}
void spawn_entities_from_map(Entity& e) // overload: computes entity position from map section and tile data
{
    uint8_t slot = e.param1;   // spawn slot index (counts down from 10)
    uint8_t section = e.param2; // map section

    // Calculate tile row offset: (0x3f - section) * 12
    uint16_t row_start = (0x3f - section) * 4;
    uint16_t tile_ofs = row_start + row_start * 2; // row * 12

    // Accumulate terrain heights across tiles up to slot position
    uint8_t height = 0;
    for (uint8_t i = 0; i < slot; i++) {
        uint8_t tile = map_tiles[tile_ofs + i];
        height += tile_height[tile];
    }

    e.heightOfs = height;                            // entity height offset
    e.y = (uint16_t)section << 4;                    // entity Y position (section * 16)
    uint16_t x_pos = (uint16_t)slot * 2;
    x_pos = (x_pos + x_pos * 2) * 4 - 4;           // slot * 24 - 4
    e.x = x_pos;                                     // entity X position
}
void init_terrain_height_table() // 1000:09a4 — fills spawn state table (192 words) with 0xFFFF (all slots available)
{
    for (int i = 0; i < 192; i++)
        spawn_state[i] = 0xffff;
}
void spawn_entity_from_data(uint16_t entity_ptr, uint16_t spawn_type, uint16_t entity_data) // 1000:09b5
{
    copy_entity_template(entity_ptr);
    uint16_t mask = spawn_bitmask[spawn_type];
    spawn_state[entity_data + level_sub * 64] &= mask;
}
uint16_t process_entity_spawn(uint16_t entity_data, uint16_t spawn_type) // 1000:09e9
{
    uint16_t mask = ~spawn_bitmask[spawn_type];
    return spawn_state[entity_data + level_sub * 64] & mask;
}
void copy_entity_template(uint16_t esi) // 1000:0a1b — copy_entity_template: copies visual/sprite fields from entity type template to entity at esi
{
    Entity& e = ent(esi);
    const Entity& src = visual_templates[e.type];
    e.flags      = src.flags;
    e.spriteW    = src.spriteW;
    e.spriteH    = src.spriteH;
    e.drawOfsY   = src.drawOfsY;
    e.drawOfsX   = src.drawOfsX;
    e.spriteData = src.spriteData;
    e.type       = src.type;
}
TerrainCollisionResult check_terrain_collision() // 1000:0a51
{
    uint16_t anim = (uint16_t)player().param2;
    uint16_t mask = spawn_state[anim + level_sub * 64] & spawn_flags[anim];
    if (mask) {
        uint16_t type_idx = (uint8_t)((mask >> 8) >> 2);
        uint8_t terrain_val = entity_type_table[type_idx];
        if (terrain_val) {
            terrain_value = terrain_val;
            terrain_search = 0x000a;
            uint16_t half_width = entity_half_width[type_idx];
            uint16_t center_x = entity_center_x[type_idx];
            uint16_t count = 0x000a;
            for (; count != 0; --count) {
                bool bit = mask & 1;
                mask >>= 1;
                if (bit) {
                    uint16_t saved_cx = center_x;
                    uint16_t left = center_x - half_width;
                    if (!((int16_t)left > (int16_t)player().x)) {
                        uint16_t right = center_x + half_width;
                        if (!((int16_t)right < (int16_t)player().x)) {
                            return {(uint16_t)terrain_val, terrain_search};
                        }
                    }
                    center_x = saved_cx;
                }
                center_x -= 0x0018;
                terrain_search--;
            }
        }
    }
    return {0, 0};
}
CollisionResult check_entity_collision(uint16_t index, uint16_t position) // 1000:0ad5 — check_entity_collision
{
    uint16_t collision_mask = spawn_state[index + level_sub * 64] & spawn_flags[index];
    if (collision_mask) {
        uint16_t type_idx = (uint8_t)((collision_mask >> 8) >> 2); // entity type from high byte
        uint8_t check_type = entity_type_table[type_idx];
        if (check_type) {
            terrain_search = 0x000a;
            uint16_t type_idx2 = type_idx << 1;
            uint16_t half_width = entity_half_width[type_idx] - 0x000e;
            uint16_t scan_pos = entity_center_x[type_idx];
            for (uint16_t count = 0x000a; count != 0; --count) {
                bool has_entity = collision_mask & 1;
                collision_mask >>= 1;
                if (has_entity) {
                    if (!((int16_t)(scan_pos - half_width) > (int16_t)position) &&
                        !((int16_t)(scan_pos + half_width) < (int16_t)position)) {
                        return { 0x0001, terrain_search };
                    }
                }
                scan_pos -= 0x0018;
                terrain_search--;
            }
        }
    }
    return { 0x0000, 0 };
}
uint16_t add_entity_to_list(const Entity& tmpl) // 1000:0b58 — copies Entity struct into first empty slot
{
    for (int i = 0; i < ENTITY_SLOTS; i++) {
        if (entities[i].flags & 0x01) continue;
        entities[i] = tmpl;
        return entity_offset(i);
    }
    return 0x0000;
}
void clear_entity_list() // 1000:0b7c — clear_entity_list: marks all entity slots as empty (flags=0)
{
    for (int i = 0; i < ENTITY_SLOTS; i++)
        entities[i].flags = 0x00;
}
void init_level_state() // 1000:0d98 — init_level_state: sets initial scroll pos and clears entity list
{
    scroll_pos = 0x001a; // starting scroll offset
    process_flag = 0x00;
    clear_entity_list(); // clear_entity_list
}
void init_rendering_context() // 1000:0da7 — init_rendering_context: builds terrain map, loads map data, resets missiles
{
    init_terrain_height_table(); // build_terrain_buffer (renders terrain into offscreen A800 buffer)
    load_map_data(); // load_map_data
    respawn_flag = 0x00; // clear fire state
    missile_n_state = 0x00; // reset missile N
    missile_m_state = 0x00; // reset missile M
    init_entity_spawn_state(); // init_entity_spawn_state
}
void advance_level() // 1000:0dc0 — init_after_tunnel_special: advances level, adjusts animation speed
{
    // Increment audio flag (tracks progress/difficulty)
    audio_flag++;
    uint8_t af = audio_flag;
    // Set animation speed based on progress: faster as you advance
    if (af >= 0x06)
        anim_speed = 0x0030;
    else if (af >= 0x03)
        anim_speed = 0x0020;
    else
        anim_speed = 0x0010;
    // Advance to next level
    level_index = level_index + 1;
    if (level_index > 0x07) // max 7 levels
        level_index = 0x01; // wrap to level 1
    init_terrain_height_table(); // build_terrain_buffer
    load_map_data(); // load_map_data
    respawn_flag = 0x00; // clear fire state
    init_entity_spawn_state(); // init_entity_spawn_state
    draw_hiscore_table(); // init_diamond_display
}
void handle_death() // 1000:0e07 — reinitialize_after_death: decrements lives, resets or game over
{
    if (!lives_count) {
        exit_flag = 0x01; // no lives left = game over
        return;
    }
    draw_ammo_label(); // remove_life_icon (decrement and redraw lives display)
    if (level_sub) {
        level_sub = 0x00; // reset to beginning of level section
        load_map_data(); // load_map_data
    }
    reset_hud_values(); // init_all_hud_bars (reset bars to full)
    respawn_flag = 0x01; // mark as respawn
    missile_n_state = 0x00;
    missile_m_state = 0x00;
    init_entity_spawn_state(); // init_entity_spawn_state
}
void init_entity_spawn_state() // 1000:0e3d — init_entity_spawn_state: sets starting scroll, speed, player pos, clears flags
{
    scroll_pos = level_scroll[level_index] & 0x03ff;
    scroll_speed = anim_speed;
    saved_player_x = 0x0080; // player starting X = 128 (center)
    tunnel_entered = 0x00;
    tunnel_section = 0x0000;
    map_spawn_ctr = 0x0000; // clear map section counter
    process_flag = 0x00;
    invuln_timer = 0x00;
    effect_flag_1 = 0x00;
    terrain_collide = 0x00;
    spawn_player_entity(); // spawn_player_entity
}
void spawn_player_entity() // 1000:0e84 — spawn_player_entity: creates player entity at starting position
{
    if (tunnel_entered) {
        tunnel_entered = 0x00;
        load_map_data(); // load_map_data (reload after tunnel)
    }
    player_velocity = 0x0000;
    clear_entity_list();
    add_entity_to_list(tmpl_player); // player entity template data
    player().x = saved_player_x;
    update_player_animation();
    uint16_t section = ((scroll_pos >> 4) - 0x0003) & 0x003f;
    map_section_idx = section;
    for (uint16_t i = 0x000f; i != 0; --i) {
        load_map_section(section);
        section = (section + 1) & 0x003f;
    }
    if (terrain_collide) {
        player().dirFlag = 0x0a;
        load_sprite_data(spr_0d49, ENTITY_BASE);
        player().type = 0x23;
        return;
    }
    if (respawn_flag) {
        respawn_flag = 0x00;
        Entity respawn = tmpl_respawn;
        respawn.y = player().y;
        respawn.heightOfs = player().heightOfs;
        add_entity_to_list(respawn);
    }
    init_bullet_tracking();
    if (missile_n_state) {
        missile_n_state = 0x01;
        Entity missile = tmpl_map_missile;
        missile.flags &= 0xdf;
        setup_missile_entity(missile);
        add_entity_to_list(missile);
    }
    if (missile_m_state) {
        missile_m_state = 0x01;
        Entity missile = tmpl_map_missile;
        missile.flags |= 0x20;
        setup_missile_entity(missile);
        add_entity_to_list(missile);
    }
}
void init_tunnel_mode() // 1000:0f3c — init_tunnel_mode: sets up tunnel state, spawns tunnel player entity
{
    tunnel_flag = 0x00; // clear tunnel rendering flag
    init_tunnel_entity_data(); // init_tunnel_3d_data
    scroll_pos = 0x001a; // reset scroll
    tunnel_distance = 0x0000;
    tunnel_vel = 0x0000; // tunnel position counter
    tunnel_spawner = 0x00; // tunnel speed
    tunnel_walls = 0x03; // tunnel wall count
    clear_entity_list(); // clear_entity_list
    add_entity_to_list(tmpl_tunnel_player); // tunnel player entity template
    clear_tunnel_entities(); // spawn_tunnel_walls
    // If missile N was active, bring it into tunnel
    if (missile_n_state) {
        missile_n_state = 0x01;
        Entity missile = tmpl_tunnel_missile;
        missile.flags &= 0xdf; // clear direction bit (left missile)
        uint16_t spawned = add_entity_to_list(missile);
        if (spawned)
            tunnel_missile_entity(spawned); // position missile in tunnel
    }
    // If missile M was active, bring it into tunnel
    if (missile_m_state) {
        missile_m_state = 0x01;
        Entity missile = tmpl_tunnel_missile;
        missile.flags |= 0x20; // set direction bit (right missile)
        uint16_t spawned = add_entity_to_list(missile);
        if (spawned)
            tunnel_missile_entity(spawned);
    }
}
void init_bullet_tracking() // 1000:0f9d — init_bullet_tracking: copies player position to 4 bullet tracking slots
{
    uint16_t px = player().x;
    trail_x[0] = trail_x[1] = trail_x[2] = trail_x[3] = px;
    uint16_t py = player().y;
    trail_y[0] = trail_y[1] = trail_y[2] = trail_y[3] = py;
    uint8_t pd = player().dirFlag;
    trail_dir[0] = trail_dir[1] = trail_dir[2] = trail_dir[3] = pd;
    uint8_t ph = player().heightOfs;
    trail_ht[0] = trail_ht[1] = trail_ht[2] = trail_ht[3] = ph;
}
void update_all_entities() // 1000:0fda — update_all_entities: main entity processing loop
{
    while (true) {
        prev_game_mode = game_mode;
        uint16_t cur = ENTITY_BASE;

        while (true) {
            if (process_flag) {
                handle_death();
                if (exit_flag)
                    return;
                break;
            }
            if (game_mode != prev_game_mode) {
                if (game_mode == 0x01) {
                    play_sound_effect(0x0b);
                    init_tunnel_mode();
                } else {
                    play_sound_effect(0x0b);
                    if (tunnel_color == 0xf0) {
                        advance_level();
                    } else {
                        uint8_t angle = player().animFrame & 0x7f;
                        if (angle > 0x28 && angle < 0x58)
                            terrain_collide = 0x01;
                        spawn_player_entity();
                    }
                }
                break;
            }
            uint8_t eflags = ent(cur).flags;
            if (eflags & 0x80)
                return; // end marker
            if (eflags & 0x02) {
                uint8_t etype = ent(cur).type;
                if (etype) {
                    uint16_t type_idx = (uint16_t)(etype - 1) << 1;
                    switch (type_idx)
                    {
                        case 0: player_update(cur); break;
                        case 2: anim_loop_4frame(cur); break;
                        case 4: anim_loop_6frame(cur); break;
                        case 6: cull_offscreen(cur); break;
                        case 8: vertical_tracker(cur); break;
                        case 10: vertical_tracker_spawner(cur); break;
                        case 12: enemy_anim_fire(cur); break;
                        case 14: diamond_collectible(cur); break;
                        case 16: cull_offscreen(cur); break;
                        case 18: tunnel_entry_trigger(cur); break;
                        case 20: tunnel_camera_control(cur); break;
                        case 22: tunnel_player_handler(cur); break;
                        case 24: cull_offscreen(cur); break;
                        case 26: tunnel_enemy_positioned(cur); break;
                        case 28: tunnel_exit_trigger(cur); break;
                        case 30: explosion_5frame(cur); break;
                        case 32: animated_passive_timed(cur); break;
                        case 34: cull_offscreen(cur); break;
                        case 36: terrain_obstacle(cur); break;
                        case 38: ground_enemy_shooting(cur); break;
                        case 40: enemy_missile_anim(cur); break;
                        case 42: countdown_self_destruct(cur); break;
                        case 44: brief_effect(cur); break;
                        case 46: missile_state_check(cur); break;
                        case 48: moving_enemy_lifetime(cur); break;
                        case 50: hazard_shield_damage(cur); break;
                        case 52: falling_projectile(cur); break;
                        case 54: homing_enemy(cur); break;
                        case 56: directional_projectile(cur); break;
                        case 58: bouncing_projectile(cur); break;
                        case 60: explosion_6frame(cur); break;
                        case 62: powerup_collectible(cur); break;
                        case 64: slow_scroll_entity(cur); break;
                        case 66: tunnel_missile_entity(cur); break;
                        case 68: death_decelerate(cur); break;
                        default:
                            exit(1);
                    }
                }
            }
            cur += ENTITY_SIZE;
        }
    }
}
void cull_behind(uint16_t esi) // 1000:10a0 — cull_behind: deactivate entity if scrolled off top of screen
{
    Entity& e = ent(esi);
    int8_t sprite_offset = (int8_t)(uint8_t)(e.spriteH - e.heightOfs - e.drawOfsX);
    uint16_t entity_bottom = ((int16_t)sprite_offset + e.y) & 0x03ff;
    uint16_t scroll = scroll_pos;
    if (entity_bottom < scroll)
        entity_bottom += 0x0400;
    if ((entity_bottom - scroll) > 0x0200)
        e.flags = 0x00; // deactivate: scrolled off top
}
void cull_offscreen(uint16_t esi) // 1000:10c6 — cull_offscreen: deactivate entity if scrolled off bottom of screen
{
    Entity& e = ent(esi);
    int8_t top_offset = (int8_t)(uint8_t)(e.heightOfs + e.drawOfsX);
    uint16_t entity_top = ((int16_t)(-top_offset) + e.y) & 0x03ff;
    uint16_t visible_bottom = (scroll_pos + 0x00a0) & 0x03ff;
    if (entity_top < visible_bottom)
        entity_top += 0x0400;
    if ((entity_top - visible_bottom) < 0x0200)
        e.flags = 0x00; // deactivate: scrolled off bottom
}
void falling_projectile(uint16_t esi) // 1000:10f3 — falling_projectile (type 27): moves upward with accelerating speed
{
    Entity& e = ent(esi);
    e.animFrame++;
    uint8_t speed = e.animFrame;
    if (speed > 0x08)
        speed = 0x08; // cap speed at 8
    e.y -= speed; // move up by speed
    cull_behind(esi);
}
void player_update(uint16_t /*esi*/) // 1000:1108 — player_update (entity type 1)
{
    handle_vertical_scroll();
    advance_map_position();

    uint8_t input = (uint8_t)input_state;
    int16_t vel = (int16_t)player_velocity;

    // --- Horizontal velocity update ---
    if (input & INPUT_LEFT) {
        vel--;
        if (vel >= 0 && vel > 0x0004)
            vel = 0x0004;
        if (vel < (int16_t)0xffe8)
            vel = (int16_t)0xffe8;
    } else if (input & INPUT_RIGHT) {
        vel++;
        if (vel < 0 && vel < (int16_t)0xfffc)
            vel = (int16_t)0xfffc;
        if (vel > 0x0018)
            vel = 0x0018;
    } else {
        if (vel > 0) vel--;
        else if (vel < 0) vel++;
    }

    // --- Apply velocity to X position ---
    player_velocity = (uint16_t)vel;
    int16_t delta = (int16_t)(vel + 3) >> 1;
    delta = (int16_t)delta >> 1; // delta = (velocity+3) / 4
    int16_t new_x = delta + (int16_t)player().x;

    if (new_x < 0x0014) {
        new_x = 0x0014;
        player_velocity = 0x0000;
    }
    if (new_x > 0x00ec) {
        new_x = 0x00ec;
        player_velocity = 0x0000;
    }
    player().x = (uint16_t)new_x;

    // Update player animation if dirFlag is set
    if (player().dirFlag)
        update_player_animation();

    // --- Terrain collision check ---
    entity_setup_sprite();
    TerrainCollisionResult tcr = check_terrain_collision();
    if (tcr.damage) {
        entity_terrain_response(tcr);
    } else {
        // Try one frame ahead for predictive collision
        player().param2++;
        player().param2 &= 0x3f;
        tcr = check_terrain_collision();
        if (tcr.damage)
            entity_terrain_response(tcr);
        player().param2--;
        player().param2 &= 0x3f;
    }

    // --- Shield check ---
    if ((int16_t)shield_active <= 0) {
        deactivate_entity(ENTITY_BASE);
        return;
    }

    // --- Invulnerability check ---
    if (!player().dirFlag) {
        invuln_timer++;
        if (invuln_timer >= 0x04)
            deactivate_entity(ENTITY_BASE);
        return;
    }

    // --- Fire main weapon (space bar) ---
    if ((int16_t)ammo_bar > 0 && (input & INPUT_FIRE))
        player_fire_weapon();

    // --- Missile N (key N = bit 0x40) ---
    uint8_t ms_n = missile_n_state;
    if (input & INPUT_MISSILE_N) {
        if (!ms_n) {
            if ((int16_t)ammo_count > 0) {
                missile_n_state = 0x01;
                Entity missile = tmpl_map_missile;
                missile.flags &= 0xdf;
                setup_missile_entity(missile);
                add_entity_to_list(missile);
                score_delta = score_delta - 1;
                play_sound_effect(0x01);
            }
        } else if (ms_n == 0x02) {
            missile_n_state = 0x03;
            play_sound_effect(0x02);
        }
    } else {
        if (ms_n == 0x01) missile_n_state = 0x02;
        else if (ms_n == 0x03) missile_n_state = 0x00;
    }

    // --- Missile M (key M = bit 0x20) ---
    uint8_t ms_m = missile_m_state;
    if (input & INPUT_MISSILE_M) {
        if (!ms_m) {
            if ((int16_t)ammo_count > 0) {
                missile_m_state = 0x01;
                Entity missile = tmpl_map_missile;
                missile.flags |= 0x20;
                setup_missile_entity(missile);
                add_entity_to_list(missile);
                score_delta = score_delta - 1;
                play_sound_effect(0x01);
            }
        } else if (ms_m == 0x02) {
            missile_m_state = 0x03;
            play_sound_effect(0x02);
        }
    } else {
        if (ms_m == 0x01) missile_m_state = 0x02;
        else if (ms_m == 0x03) missile_m_state = 0x00;
    }
}
void death_decelerate(uint16_t /*esi*/) // 1000:12a7 — death_decelerate (type 35): player death animation with scroll deceleration
{
    int16_t speed = (int16_t)scroll_speed - 3;
    if (speed >= 0)
        scroll_speed = (uint16_t)speed;
    else
        deactivate_entity(ENTITY_BASE);
    advance_map_position();
    update_player_animation();
    player().dirFlag = 0x0a; // explosion sprite
    load_sprite_data(spr_0d49, ENTITY_BASE);
}
void animated_passive_timed(uint16_t /*esi*/) // 1000:12cb — animated_passive_timed (type 17): passive entity with countdown
{
    int16_t speed = (int16_t)scroll_speed - 1;
    if (speed >= 0)
        scroll_speed = (uint16_t)speed;
    advance_map_position();
    update_player_animation();
    anim_counter++;
    if (anim_counter >= 0x28) // waited 40 frames
        process_flag = 0x01; // signal restart
}
void terrain_obstacle(uint16_t esi) // 1000:12eb — terrain_obstacle (type 19): ground-based obstacle that blocks player
{
    cull_behind(esi);
    if (!ent(esi).flags)
        return;
    ent(esi).y -= 0x0010;
    ent(esi).y &= 0x03ff;
    uint8_t dir = ent(esi).dirFlag;
    if (dir == 0x01) {
        if ((char)ent(esi).heightOfs > (char)0x9c)
            ent(esi).heightOfs -= 0x08;
    } else if (dir == 0x02) {
        if ((char)ent(esi).heightOfs < (char)0x64)
            ent(esi).heightOfs += 0x08;
    }
    TerrainInfo terrain = get_terrain_at_position(ent(esi).y, ent(esi).x);
    if ((int8_t)terrain.height >= (int8_t)ent(esi).heightOfs) {
        mark_entity_destroyed(esi);
        return;
    }
    ent(esi).param2 = (uint8_t)terrain.section;
    CollisionResult coll = check_entity_collision(terrain.section, ent(esi).x);
    if (!coll.hit)
        return;
    uint16_t found = entity_movement_helper((uint16_t)ent(esi).param2, coll.search_idx);
    if (!(ent(found).flags & 0x80)) {
        uint8_t height_diff = ent(found).heightOfs - ent(esi).heightOfs;
        if ((int8_t)height_diff < 0)
            height_diff = -height_diff;
        if (height_diff < 0x10) {
            ent(found).hitPoints = ent(found).hitPoints - 1;
            if ((char)ent(found).hitPoints >= 0)
                increment_score();
            else {
                spawn_hit_effect(found);
                play_sound_effect(0x06);
            }
            spawn_explosion_at_entity(esi);
            return;
        }
    }
}
void missile_state_check(uint16_t esi) // 1000:1384 — missile_state_check (type 24): player missile tracking armed state
{
    if (player().type == 0x11) // player is dead
        ent(esi).flags = 0x00; // deactivate missile
    setup_missile_entity(esi);
    uint8_t state = (ent(esi).flags & 0x20) ? missile_m_state : missile_n_state;
    if (state == 0x03) // armed
        ent(esi).type = 0x19; // change to type 25 (detonate)
}
void moving_enemy_lifetime(uint16_t esi) // 1000:13a8 — moving_enemy_lifetime (type 25): enemy that moves, checks terrain, has hitpoints
{
    cull_behind(esi);
    if (!ent(esi).flags)
        return;
    ent(esi).y -= 0x0006;
    ent(esi).y &= 0x03ff;
    {
    TerrainInfo terrain = get_terrain_at_position(ent(esi).y, ent(esi).x);
    ent(esi).heightOfs = terrain.height + 0x04;
    ent(esi).param2 = (uint8_t)terrain.section;
    ent(esi).dirFlag = terrain.type;
    }
    load_sprite_data(spr_0dda, esi);
    if (!ent(esi).dirFlag) {
        ent(esi).y += 0x0004;
        ent(esi).y &= 0x03ff;
        ent(esi).hitPoints = ent(esi).hitPoints - 1;
        if ((char)ent(esi).hitPoints < 0) {
            remove_entity(esi);
            ent(esi).flags = 0x00;
            return;
        }
    }
    CollisionResult coll = check_entity_collision((uint16_t)ent(esi).param2, ent(esi).x);
    if (coll.hit) {
        uint16_t found = entity_movement_helper((uint16_t)ent(esi).param2, coll.search_idx);
        if (!(ent(found).flags & 0x80)) {
            spawn_hit_effect(found);
            play_sound_effect(0x06);
            ent(esi).flags = 0x00;
        }
    }
}
void directional_projectile(uint16_t esi) // 1000:1429 — directional_projectile (type 29): fast projectile moving in 5 directions
{
    cull_offscreen(esi);
    if (!ent(esi).flags)
        return;
    uint8_t dir = ent(esi).direction;
    if (dir == 0x02)
        ent(esi).y += 0x0005;
    else if (dir == 0x00)
        ent(esi).x -= 0x0005;
    else if (dir == 0x01) {
        ent(esi).x -= 0x0003;
        ent(esi).y += 0x0002;
    } else if (dir == 0x03) {
        ent(esi).x += 0x0003;
        ent(esi).y += 0x0002;
    } else
        ent(esi).x += 0x0005;
    ent(esi).y &= 0x03ff;
    int16_t ex = (int16_t)ent(esi).x;
    if (ex < 0x000c || ex > 0x00f4) {
        ent(esi).flags = 0x00;
        return;
    }
    TerrainInfo terrain = get_terrain_at_position(ent(esi).y, ent(esi).x);
    ent(esi).heightOfs = terrain.height + 0x08;
    ent(esi).param2 = (uint8_t)terrain.section;
    ent(esi).dirFlag = terrain.type;
    load_sprite_data(*fire_sprite[dir], esi);
    if (player().type == 0x11)
        return;
    uint16_t dx_abs = ent(esi).x - player().x;
    if ((int16_t)dx_abs < 0) dx_abs = -dx_abs;
    if (dx_abs < 0x0010) {
        uint16_t dy_abs = ent(esi).y - player().y - 0x0008;
        if ((int16_t)dy_abs < 0) dy_abs = -dy_abs;
        if (dy_abs < 0x0010) {
            play_sound_effect(0x05);
            shield_delta = shield_delta - 0x0064;
            tmpl_explode.zLayer = 0x01;
            remove_entity(esi);
            tmpl_explode.zLayer = 0x05;
            ent(esi).flags = 0x00;
        }
    }
}
void hazard_shield_damage(uint16_t esi) // 1000:14f0 — hazard_shield_damage (type 26): stationary hazard that damages player shield
{
    ent(esi).y += 0x0001;
    TerrainInfo terrain = get_terrain_at_position(ent(esi).y, ent(esi).x);
    ent(esi).heightOfs = terrain.height;
    ent(esi).param2 = (uint8_t)terrain.section;
    ent(esi).dirFlag = terrain.type;
    load_sprite_data(*sprite_table_4065[ent(esi).direction], esi);
    if (player().type != 0x11) {
        uint16_t dx_abs = ent(esi).x - player().x;
        if ((int16_t)dx_abs < 0) dx_abs = -dx_abs;
        if (dx_abs < 0x001a) {
            uint16_t dy_abs = ent(esi).y - player().y;
            if ((int16_t)dy_abs < 0) dy_abs = -dy_abs;
            if (dy_abs < 0x0012) {
                shield_delta = shield_delta - 0x000c;
                ent(esi).hitPoints = 0xff;
            }
        }
    }
    // Iterate entity list checking for collisions
    uint16_t scan_di = 0x1ba1;
    while (true) {
        if ((int8_t)ent(esi).hitPoints < 0x00) {
            play_sound_effect(0x07);
            remove_entity(esi);
            ent(esi).flags = 0x00;
            update_diamond_counter();
            return;
        }
        Entity& scan = ent(scan_di);
        if (scan.flags & 0x80)
            break; // end marker
        if (scan.flags & 0x40) {
            uint16_t saved_di = scan_di;
            // Check X distance
            uint16_t check_dx = scan.x - ent(esi).x;
            if ((int16_t)check_dx < 0) check_dx = -check_dx;
            if (check_dx < 0x0014) {
                // Check Y distance
                uint16_t check_dy = scan.y - ent(esi).y;
                if ((int16_t)check_dy < 0) check_dy = -check_dy;
                if (check_dy < 0x0010) {
                    if (scan.type == 0x19) {
                        // Missile hit
                        ent(esi).hitPoints = 0xff;
                        scan.flags = 0x00;
                    } else {
                        // Check height distance
                        uint8_t ht_diff = scan.heightOfs - ent(esi).heightOfs;
                        if ((int8_t)ht_diff < 0) ht_diff = -ht_diff;
                        if (ht_diff < 0x10) {
                            ent(esi).hitPoints = ent(esi).hitPoints - 1;
                            mark_entity_destroyed(scan_di);
                            play_sound_effect(0x03);
                            increment_score();
                        }
                    }
                }
            }
            scan_di = saved_di;
        }
        scan_di += 0x0017;
    }
    // Player proximity check for bullet firing
    if (player().type != 0x11 && player().y > ent(esi).y) {
        uint16_t px_dist = player().x - ent(esi).x;
        if ((int16_t)px_dist < 0) px_dist = -px_dist;
        if (px_dist < 0x0020) {
            ent(esi).animFrame = ent(esi).animFrame - 1;
            if ((char)ent(esi).animFrame >= 0)
                fire_trigger = 0x00;
            else {
                ent(esi).animFrame = 0x07;
                fire_trigger = 0x01;
            }
            enemy_spawn_bullet(esi);
        }
    }
    cull_offscreen(esi);
}
void ground_enemy_shooting(uint16_t esi) // 1000:15fc — ground_enemy_shooting (type 20): fast directional enemy bullet
{
    cull_offscreen(esi);
    if (!ent(esi).flags)
        return;
    uint8_t dir = ent(esi).direction;
    if (dir == 0x02)
        ent(esi).y += 0x0008;
    else if (dir == 0x00)
        ent(esi).x -= 0x0008;
    else if (dir == 0x01) {
        ent(esi).x -= 0x0006;
        ent(esi).y += 0x0004;
    } else if (dir == 0x03) {
        ent(esi).x += 0x0006;
        ent(esi).y += 0x0004;
    } else
        ent(esi).x += 0x0008;
    ent(esi).y &= 0x03ff;
    int16_t ex = (int16_t)ent(esi).x;
    if (ex < 0x0004 || ex > 0x00fc) {
        ent(esi).flags = 0x00;
        return;
    }
    uint8_t dfl = ent(esi).dirFlag;
    if (dfl == 0x01) {
        if ((char)ent(esi).heightOfs < (char)0x64)
            ent(esi).heightOfs += 0x04;
    } else if (dfl == 0x02) {
        if ((char)ent(esi).heightOfs > (char)0x9c)
            ent(esi).heightOfs -= 0x04;
    }
    {
    TerrainInfo terrain = get_terrain_at_position(ent(esi).y, ent(esi).x);
    if ((int8_t)terrain.height >= (int8_t)ent(esi).heightOfs) {
        mark_entity_destroyed(esi);
        return;
    }
    }
    if (player().type == 0x11)
        return;
    uint16_t dx = ent(esi).x - player().x;
    if ((int16_t)dx < 0) dx = -dx;
    if (dx < 0x000c) {
        uint16_t dy = ent(esi).y - player().y;
        if ((int16_t)dy < 0) dy = -dy;
        if (dy < 0x0008) {
            uint8_t ht_diff = ent(esi).heightOfs - player().heightOfs;
            if ((int8_t)ht_diff < 0) ht_diff = -ht_diff;
            if (ht_diff < 0x10) {
                shield_delta -= 0x0001;
                mark_entity_destroyed(esi);
                play_sound_effect(0x04);
            }
        }
    }
}
void countdown_self_destruct(uint16_t esi) // 1000:16d6 — countdown_self_destruct (type 22): entity disappears after countdown
{
    ent(esi).dirFlag = ent(esi).dirFlag - 1; // dirFlag countdown
    if ((char)ent(esi).dirFlag < 0)
        ent(esi).flags = 0x00; // deactivate when countdown reaches 0
}
void enemy_missile_anim(uint16_t esi) // 1000:16df — enemy_missile_anim (type 21): 4-frame animated missile
{
    uint8_t frame = ent(esi).dirFlag;
    ent(esi).dirFlag = frame + 1;
    if (frame >= 0x04) {
        ent(esi).flags = 0x00; // deactivate after 4 frames
        return;
    }
    ent(esi).spriteData = sprite_frame_data[frame]; // sprite data lookup table
    cull_offscreen(esi);
}
void explosion_5frame(uint16_t esi) // 1000:16fe — explosion_5frame (type 16): 5-frame explosion animation
{
    ent(esi).animFrame++;
    uint8_t frame = (ent(esi).animFrame >> 2) & 0x07;
    if (frame >= 0x05) {
        ent(esi).flags = 0x00; // deactivate after animation
        return;
    }
    ent(esi).dirFlag = frame;
    load_sprite_data(spr_12b5, esi);
    cull_offscreen(esi);
}
void explosion_6frame(uint16_t esi) // 1000:171f — explosion_6frame (type 31): 6-frame explosion animation
{
    ent(esi).animFrame++;
    uint8_t frame = (ent(esi).animFrame >> 2) & 0x07;
    if (frame >= 0x06) {
        ent(esi).flags = 0x00;
        return;
    }
    ent(esi).dirFlag = frame;
    load_sprite_data(spr_12f5, esi);
    cull_offscreen(esi);
}
void brief_effect(uint16_t esi) // 1000:1740 — brief_effect (type 23): 4-frame brief visual effect, clears effect flags
{
    ent(esi).animFrame++;
    uint8_t frame = ent(esi).animFrame & 0x07;
    if (frame >= 0x04) {
        // Animation done: clear the effect flag based on direction bit
        if (ent(esi).flags & 0x20)
            effect_flag_1 &= 0x7f;
        else
            effect_flag_1 &= 0xfe;
        ent(esi).flags = 0x00; // deactivate
        return;
    }
    ent(esi).dirFlag = frame;
    load_sprite_data(spr_133d, esi);
}
void anim_loop_4frame(uint16_t esi) // 1000:176c — anim_loop_4frame (type 2): 4-frame looping animation
{
    ent(esi).animFrame++;
    ent(esi).dirFlag = (ent(esi).animFrame >> 1) & 0x03;
    load_sprite_data(spr_0e2b, esi);
    cull_offscreen(esi);
}
void anim_loop_6frame(uint16_t esi) // 1000:1783 — anim_loop_6frame (type 3): 6-frame looping animation with frame remap
{
    ent(esi).animFrame++;
    uint8_t frame = (ent(esi).animFrame >> 1) & 0x07;
    if (frame >= 0x06) {
        frame = 0x00;
        ent(esi).animFrame = 0x00; // reset animation counter
    }
    ent(esi).dirFlag = frame_remap_3660[(uint16_t)frame]; // frame remap table
    load_sprite_data(spr_0e52, esi);
    cull_offscreen(esi);
}
void vertical_tracker(uint16_t esi) // 1000:17ac — vertical_tracker (type 5): tracks player vertically, fires periodically
{
    if (track_player_vertically(esi)) { // nonzero = entity in range
        ent(esi).animFrame--;
        if ((int8_t)ent(esi).animFrame < 0) {
            ent(esi).animFrame = 0x08; // reset cooldown to 8
            fire_trigger = 0x01;
        } else {
            fire_trigger = 0x00;
        }
        update_bullet_positions(esi);
    }
    load_sprite_data(spr_0e73, esi);
    cull_offscreen(esi);
}
void vertical_tracker_spawner(uint16_t esi) // 1000:17d6 — vertical_tracker_spawner (type 6): tracks player, spawns entities
{
    if (track_player_vertically(esi)) {
        ent(esi).animFrame = ent(esi).animFrame - 1; // spawn cooldown--
        if ((char)ent(esi).animFrame < 0) {
            ent(esi).animFrame = 0x12; // reset cooldown to 18
            spawn_secondary_entity(esi); // spawn_entity
        }
    }
    load_sprite_data(spr_0e9c, esi);
    cull_offscreen(esi);
}
void bouncing_projectile(uint16_t esi) // 1000:17f4 — bouncing_projectile (type 30): projectile with height wobble
{
    cull_offscreen(esi);
    if (!ent(esi).flags)
        return;
    uint8_t dir = ent(esi).direction;
    if (dir == 0x02) {
        ent(esi).y += 0x0003;
    } else if (dir == 0x00) {
        ent(esi).x -= 0x0004;
    } else if (dir == 0x01) {
        ent(esi).x -= 0x0004;
        ent(esi).y += 0x0003;
    } else if (dir == 0x03) {
        ent(esi).x += 0x0004;
        ent(esi).y += 0x0003;
    } else {
        ent(esi).x += 0x0004;
    }
    ent(esi).y &= 0x03ff;
    int16_t ex = (int16_t)ent(esi).x;
    if (ex < 0x0008 || ex > 0x00f8) {
        ent(esi).flags = 0x00;
        return;
    }
    ent(esi).animFrame = ent(esi).animFrame + 1;
    uint8_t frame = ent(esi).animFrame;
    if (frame >= 0x10) {
        spawn_death_explosion(esi);
        return;
    }
    ent(esi).heightOfs += homing_height[(uint16_t)frame];
    if (player().type == 0x11)
        return;
    uint16_t dx_abs = ent(esi).x - player().x;
    if ((int16_t)dx_abs < 0) dx_abs = -dx_abs;
    if (dx_abs < 0x000e) {
        uint16_t dy_abs = ent(esi).y - player().y;
        if ((int16_t)dy_abs < 0) dy_abs = -dy_abs;
        if (dy_abs < 0x000a) {
            uint8_t ht_diff = ent(esi).heightOfs - player().heightOfs;
            if ((int8_t)ht_diff < 0) ht_diff = -ht_diff;
            if (ht_diff < 0x10) {
                shield_delta = shield_delta - 0x000a;
                play_sound_effect(0x05);
            }
        }
    }
}
void enemy_anim_fire(uint16_t esi) // 1000:18a9 — enemy_anim_fire (type 7): animated enemy that fires at player
{
    if (track_player_vertically(esi)) {
        ent(esi).animFrame = ent(esi).animFrame - 1; // fire cooldown--
        if ((char)ent(esi).animFrame < 0) {
            ent(esi).animFrame = 0x28; // reset cooldown to 40 frames
            fire_spread_bullets(esi); // fire_projectile_at_player
        }
    }
    load_sprite_data(spr_0ec5, esi);
    cull_offscreen(esi);
}
void homing_enemy(uint16_t esi) // 1000:18c7 — homing_enemy (type 28): pursues player, only active when all 6 diamonds collected
{
    uint8_t all_flags = powerup_flags[0];
    all_flags &= powerup_flags[1];
    all_flags &= powerup_flags[2];
    all_flags &= powerup_flags[3];
    all_flags &= powerup_flags[4];
    all_flags &= powerup_flags[5];
    if (!all_flags) {
        cull_offscreen(esi);
        return;
    }
    uint16_t dx_val = player().x - ent(esi).x - 0x000c;
    if ((int16_t)dx_val < 0) dx_val = -dx_val;
    uint16_t dy_val = player().y - 0x0008 - ent(esi).y;
    if ((int16_t)dy_val < 0) dy_val = -dy_val;
    uint8_t speed = ent(esi).dirFlag >> 1;
    uint16_t dist = dx_val + dy_val;
    if (dist <= 0x0040) {
        if (speed != 0x08)
            ent(esi).dirFlag = ent(esi).dirFlag + 1;
    } else {
        if (speed)
            ent(esi).dirFlag = ent(esi).dirFlag - 1;
    }
    ent(esi).spriteData = homing_sprite[speed];
    if (speed >= 0x02) {
        dx_val = player().x - ent(esi).x - 0x000c;
        if ((int16_t)dx_val < 0) {
            dx_val = -dx_val;
            if (dx_val <= 0x0018)
                player().x++;
        } else {
            if (dx_val && dx_val <= 0x0018)
                player().x--;
        }
        if (speed == 0x08 && dy_val <= 0x0008 && dx_val <= 0x0008 && player().type != 0x11)
            enter_tunnel_mode();
    }
    cull_offscreen(esi);
}
void enter_tunnel_mode() // 1000:196f — enter_tunnel_mode: activates tunnel when homing enemy catches player
{
    if (!player().dirFlag) {
        tunnel_color = 0xf0;
        game_mode = 0x01;
    } else {
        player().dirFlag = 0x00;
        load_sprite_data(spr_0d49, ENTITY_BASE);
    }
}
void tunnel_entry_trigger(uint16_t esi) // 1000:1993 — tunnel_entry_trigger (type 10): looks up tunnel entry parameters
{
    homing_approach(esi);
    if (game_mode == 0x01) {
        // tunnel data index = level*3 + levelSub
        uint8_t idx = level_index * 3 + level_sub;
        uint16_t entry = anim_entry_a[idx];
        saved_scroll = entry & 0x03ff;
        tunnel_color = (entry >> 8) & 0xc0;
    }
}
void tunnel_camera_control(uint16_t esi) // 1000:19c2 — tunnel_camera_control (type 11): handles tunnel exit, advances level sub-index
{
    homing_approach(esi);
    if (game_mode == 0x01) {
        // tunnel data index = level*3 + levelSub
        uint8_t idx = level_index * 3 + level_sub;
        uint16_t entry = anim_entry_b[idx];
        saved_scroll = entry & 0x03ff;
        tunnel_color = (entry >> 8) & 0xc0;
        tunnel_entered = 0x01;
        // Advance level sub-index (wraps 0->1->2->0)
        level_sub = (level_sub + 1 > 0x02) ? 0x00 : level_sub + 1;
    }
}
void homing_approach(uint16_t esi) // 1000:1a04 — homing_approach: entity homes toward player, triggers tunnel mode when close
{
    uint16_t dx_val = player().x - ent(esi).x - 0x000c;
    if ((int16_t)dx_val < 0) dx_val = -dx_val;
    uint16_t dy_val = player().y - ent(esi).y;
    if ((int16_t)dy_val < 0) dy_val = -dy_val;
    uint8_t speed = ent(esi).dirFlag >> 1;
    uint16_t dist = dx_val + dy_val;
    if (dist <= 0x0040) {
        if (speed != 0x06)
            ent(esi).dirFlag = ent(esi).dirFlag + 1;
    } else {
        if (speed)
            ent(esi).dirFlag = ent(esi).dirFlag - 1;
    }
    if (speed == 0x06) {
        ent(esi).zLayer = 0x00;
    } else {
        ent(esi).zLayer = 0x07;
        ent(esi).spriteData = sprite_speed_data[speed];
    }
    if (speed >= 0x01) {
        dx_val = player().x - ent(esi).x - 0x000c;
        if ((int16_t)dx_val < 0) {
            dx_val = -dx_val;
            if (dx_val <= 0x0018)
                player().x++;
        } else {
            if (dx_val && dx_val <= 0x0018)
                player().x--;
        }
        if (dy_val <= 0x0008 && dx_val <= 0x0008 && player().type != 0x11) {
            saved_player_x = player().x;
            game_mode = 0x01;
        }
    }
    cull_offscreen(esi);
}
void diamond_collectible(uint16_t esi) // 1000:1a9e — diamond_collectible (type 8): diamond pickup, steers player toward it
{
    cull_offscreen(esi);
    if (!ent(esi).flags)
        return;
    int16_t dy = (int16_t)(player().y - ent(esi).y);
    if (dy < 0) {
        if (dy < (int16_t)0xfff0)
            ent(esi).zLayer = 0x01;
        return;
    }
    if (dy > 0x0020)
        return;
    int16_t dx_signed = (int16_t)(player().x - ent(esi).x - 0x000c);
    uint16_t dx = (dx_signed < 0) ? (uint16_t)(-dx_signed) : (uint16_t)dx_signed;
    if (dx_signed < 0) {
        if (dx < 0x0018)
            player().x++;
    } else {
        if (dx && dx < 0x0018)
            player().x--;
    }
    if ((uint16_t)dy > 0x0008)
        return;
    if (dx <= 0x0002)
        score_delta++;
    else if (dx < 0x0024) {
        shield_active = 0x0000;
        play_sound_effect(0x06);
    }
}
void powerup_collectible(uint16_t esi) // 1000:1b09 — powerup_collectible (type 32): fuel/ammo/shield power-up pickup
{
    cull_offscreen(esi);
    if (!ent(esi).flags)
        return;
    if (player().type == 0x11) // player must be alive
        return;
    uint16_t dx = ent(esi).x - player().x;
    if ((int16_t)dx < 0) dx = -dx;
    if (dx < 0x0012) {
        uint16_t dy = ent(esi).y - player().y;
        if ((int16_t)dy < 0) dy = -dy;
        if (dy < 0x0010) {
            ent(esi).flags = 0x00;
            activate_powerup(ent(esi).direction);
            play_sound_effect(0x0a);
        }
    }
}
void slow_scroll_entity(uint16_t esi) // 1000:1b4a — slow_scroll_entity (type 33): entity that scrolls upward slowly
{
    ent(esi).y -= 0x0002; // move up by 2
    ent(esi).y &= 0x03ff; // wrap in map space
    cull_behind(esi); // cull_behind
}
void update_player_animation() // 1000:1b57 — update_player_animation: recalculates player terrain height and sprite
{
    uint16_t player_y = (scroll_pos + 0x0070) & 0x03ff;
    player().y = player_y;
    TerrainInfo terrain = get_terrain_at_position(player_y, player().x);
    player().heightOfs = terrain.height;
    player().param2 = (uint8_t)terrain.section;
    player().dirFlag = terrain.type;
    load_sprite_data(spr_0d49, ENTITY_BASE);
}
void handle_vertical_scroll() // 1000:1b80 — handle_vertical_scroll: adjusts scroll speed based on fuel and input
{
    int16_t speed = (int16_t)scroll_speed;
    uint8_t input = ((int16_t)fuel_level > 0) ? (uint8_t)input_state : (uint8_t)0x08;
    if (input & 0x04) { // up pressed: accelerate
        speed++;
        if (speed > 0x0040)
            speed = 0x0040;
    } else if (input & 0x08) { // down pressed: decelerate
        speed -= 2;
        if (speed < (int16_t)anim_speed)
            speed = (int16_t)anim_speed;
    }
    scroll_speed = (uint16_t)speed;
}
void advance_map_position() // 1000:1bb9 — advance_map_position: moves scroll position based on speed, loads new map sections
{
    uint16_t scroll_delta = (scroll_speed + 0x000f) >> 3; // (speed + 15) / 8
    uint16_t section_advance = scroll_delta - 1 + tunnel_section;
    if (section_advance > 0x008b) {
        section_advance = 0x0000; // reset section counter
        fuel_delta = 0xffff; // deplete fuel at map end
    }
    tunnel_section = section_advance;
    uint16_t half_delta = scroll_delta >> 1;
    scroll_pos = (scroll_pos - half_delta) & 0x03ff; // scroll upward
    // Check if we've scrolled to a new map section boundary
    uint16_t section = ((scroll_pos >> 4) - 0x0003) & 0x003f;
    if (section != map_section_idx) {
        map_section_idx = section;
        load_map_section(section);
    }
}
uint16_t entity_movement_helper(uint16_t entity_data, uint16_t spawn_type) // 1000:1c0a — find_entity_by_type
{
    uint16_t search_si = 0x1b8a;
    while (true) {
        uint8_t flags = ent(search_si).flags;
        if (flags & 0x80)
            return search_si;
        if ((flags & 0x08) && (uint8_t)entity_data == ent(search_si).param2 && (uint8_t)spawn_type == ent(search_si).param1)
            return search_si;
        search_si += 0x0017;
    }
}
void deactivate_entity(uint16_t /*esi*/) // 1000:1c33 — deactivate_entity: changes player to death state (type 17)
{
    if (player().type == 0x11) // already in death state?
        return;
    play_sound_effect(0x0c); // play_sound: death
    remove_entity(ENTITY_BASE); // spawn_explosion_at_entity
    player().type = 0x11; // set type to 17 (animated_passive_timed)
    player().zLayer = 0x00; // remove from rendering
    anim_counter = 0x00; // reset animation counter
}
void entity_terrain_response(TerrainCollisionResult tcr) // 1000:1c56 — entity_terrain_response: handle terrain collision (damage shield, spawn effect)
{
    shield_delta = -tcr.damage;
    play_sound_effect(0x06);
    uint16_t found = entity_movement_helper((uint16_t)player().param2, tcr.search_idx);
    if (!(ent(found).flags & 0x80))
        spawn_hit_effect(found);
}
void entity_setup_sprite() // 1000:1c78 — shift_bullet_tracking: shifts player position history for delayed bullet aiming
{
    // Shift X positions: [3]=[2], [2]=[1], [1]=[0], [0]=current player X
    trail_x[3] = trail_x[2];
    trail_x[2] = trail_x[1];
    trail_x[1] = trail_x[0];
    trail_x[0] = player().x;
    // Shift Y positions
    trail_y[3] = trail_y[2];
    trail_y[2] = trail_y[1];
    trail_y[1] = trail_y[0];
    trail_y[0] = player().y;
    // Shift direction flags
    trail_dir[3] = trail_dir[2];
    trail_dir[2] = trail_dir[1];
    trail_dir[1] = trail_dir[0];
    trail_dir[0] = player().dirFlag;
    // Shift height offsets
    trail_ht[3] = trail_ht[2];
    trail_ht[2] = trail_ht[1];
    trail_ht[1] = trail_ht[0];
    trail_ht[0] = player().heightOfs;
}
void setup_missile_entity(uint16_t esi) // 1000:1cd9 — setup_missile_entity: positions missile at delayed player position (4 frames ago)
{
    Entity& e = ent(esi);
    e.x = trail_x[3];
    e.y = (trail_y[3] + 0x0006) & 0x03ff;
    uint8_t tdir = trail_dir[3];
    e.dirFlag = tdir; // offset +4: direction flag selects sprite frame
    uint8_t dir_ofs = dir_ofs_3513[(uint16_t)tdir];
    e.heightOfs = trail_ht[3] + 0x06;
    if (e.flags & 0x20) {
        e.x += 0x0008;
        e.heightOfs -= dir_ofs;
    } else {
        e.x -= 0x0008;
        e.heightOfs += dir_ofs;
    }
    load_sprite_data(spr_0dda, esi);
}
void setup_missile_entity(Entity& e) // overload: positions missile Entity at delayed player position
{
    e.x = trail_x[3];
    e.y = (trail_y[3] + 0x0006) & 0x03ff;
    uint8_t tdir = trail_dir[3];
    e.dirFlag = tdir; // offset +4: direction flag selects sprite frame
    uint8_t dir_ofs = dir_ofs_3513[(uint16_t)tdir];
    e.heightOfs = trail_ht[3] + 0x06;
    if (e.flags & 0x20) {
        e.x += 0x0008;
        e.heightOfs -= dir_ofs;
    } else {
        e.x -= 0x0008;
        e.heightOfs += dir_ofs;
    }
    load_sprite_data(spr_0dda, e);
}
void player_fire_weapon() // 1000:1d1e — player_fire_weapon: spawns left and right bullet entities from player position
{
    // Left bullet
    tmpl_spawn.flags &= 0xdf;
    uint16_t pdir = (uint16_t)player().dirFlag;
    tmpl_spawn.dirFlag = dir_mapping_5021[pdir];
    int8_t x_ofs_l = (int8_t)player_xofs_l[pdir];
    tmpl_spawn.x = (uint16_t)((int16_t)x_ofs_l + player().x);
    tmpl_spawn.y = (player().y - 0x0004) & 0x03ff;
    tmpl_spawn.heightOfs = player().heightOfs + player_ht_l[pdir];
    uint16_t dir4 = (uint16_t)tmpl_spawn.dirFlag;
    tmpl_spawn.spriteH = dir_anim_5031[dir4];
    tmpl_spawn.spriteData = dir_sprite_5034[dir4];
    add_entity_to_list(tmpl_spawn);
    // Left bullet trail
    tmpl_bullet.x = tmpl_spawn.x;
    tmpl_bullet.y = tmpl_spawn.y;
    tmpl_bullet.heightOfs = tmpl_spawn.heightOfs;
    spawn_counter++;
    uint16_t ctr_idx = spawn_counter & 0x0f;
    tmpl_bullet.dirFlag = dir_table_4071[ctr_idx];
    load_sprite_data(spr_100e, tmpl_bullet);
    add_entity_to_list(tmpl_bullet);
    // Right bullet
    tmpl_spawn.flags |= 0x20;
    pdir = (uint16_t)player().dirFlag;
    int8_t x_ofs_r = (int8_t)player_xofs_r[pdir];
    tmpl_spawn.x = (uint16_t)((int16_t)x_ofs_r + player().x);
    tmpl_spawn.heightOfs = player().heightOfs + player_ht_r[pdir];
    add_entity_to_list(tmpl_spawn);
    // Right bullet trail
    tmpl_bullet.x = tmpl_spawn.x;
    tmpl_bullet.y = tmpl_spawn.y;
    tmpl_bullet.heightOfs = tmpl_spawn.heightOfs;
    add_entity_to_list(tmpl_bullet);
    uint16_t ammo_count = map_spawn_ctr + pdir;
    if (ammo_count > 0x0010) {
        ammo_count = 0x0000;
        ammo_delta = 0xffff;
    }
    map_spawn_ctr = ammo_count;
}
void enemy_spawn_bullet(uint16_t esi) // 1000:1def — enemy_spawn_bullet: spawns enemy bullet aimed toward player
{
    Entity& e = ent(esi);
    spawn_counter++;
    uint16_t ctr_idx = spawn_counter & 0x0f;
    tmpl_bullet.dirFlag = dir_table_4071[ctr_idx];
    uint8_t dir = e.direction;
    uint16_t df = (uint16_t)e.dirFlag;
    if (!dir) {
        spawn_bullet_entity(esi, 0xfffd, 0x0008, bullet_height_tbl[0][df]);
        df = (uint16_t)ent(esi).dirFlag;
        spawn_bullet_entity(esi, 0x0003, 0x0008, bullet_height_tbl[1][df]);
    } else if (dir == 0x01) {
        spawn_bullet_entity(esi, 0x0000, 0x0008, bullet_height_tbl[2][df]);
    } else {
        spawn_bullet_entity(esi, 0xfff9, 0x0008, bullet_height_tbl[3][df]);
        df = (uint16_t)ent(esi).dirFlag;
        spawn_bullet_entity(esi, 0x0000, 0x000b, bullet_height_tbl[4][df]);
        df = (uint16_t)ent(esi).dirFlag;
        spawn_bullet_entity(esi, 0x0007, 0x0008, bullet_height_tbl[5][df]);
    }
}
void spawn_bullet_entity(uint16_t esi, uint16_t x_offset, uint16_t y_offset, uint8_t height_offset) // 1000:1e7d — spawn_bullet_entity
{
    Entity& e = ent(esi);
    tmpl_bullet.x = x_offset + e.x;
    tmpl_bullet.y = (y_offset + e.y) & 0x03ff;
    tmpl_bullet.heightOfs = height_offset + e.heightOfs;
    load_sprite_data(spr_1039, tmpl_bullet);
    uint16_t spawned = add_entity_to_list(tmpl_bullet);
    if (spawned && esi > spawned)
        countdown_self_destruct(spawned);
    if (!fire_trigger)
        return;
    uint16_t df = (uint16_t)ent(esi).dirFlag;
    tmpl_missile.dirFlag = dir_mapping_5021[df];
    tmpl_missile.x = tmpl_bullet.x;
    tmpl_missile.y = tmpl_bullet.y;
    tmpl_missile.heightOfs = tmpl_bullet.heightOfs;
    tmpl_missile.direction = 0x02;
    uint16_t dir4 = (uint16_t)tmpl_missile.dirFlag;
    tmpl_missile.spriteH = dir_anim_5031[dir4];
    tmpl_missile.spriteW = 0x04;
    tmpl_missile.spriteData = dir_sprite_5063[dir4];
    spawned = add_entity_to_list(tmpl_missile);
    if (spawned && esi > spawned)
        ground_enemy_shooting(spawned);
}
void update_bullet_positions(uint16_t esi) // 1000:1f0b
{
    spawn_counter++;
    uint16_t ctr_idx = spawn_counter & 0x0f;
    tmpl_bullet.dirFlag = dir_table_4071[ctr_idx];
    uint16_t df = (uint16_t)ent(esi).dirFlag;
    int8_t x_ofs = (int8_t)bullet_xofs[df];
    int8_t y_ofs = (int8_t)bullet_yofs[df];
    tmpl_bullet.x = (uint16_t)((int16_t)x_ofs + ent(esi).x);
    tmpl_bullet.y = (uint16_t)((int16_t)y_ofs + ent(esi).y) & 0x03ff;
    tmpl_bullet.heightOfs = ent(esi).heightOfs + 0x04;
    load_sprite_data(*sprite_table_4143[df], tmpl_bullet);
    uint16_t spawned = add_entity_to_list(tmpl_bullet);
    if (spawned && esi > spawned)
        countdown_self_destruct(spawned);
    if (!fire_trigger)
        return;
    df = (uint16_t)ent(esi).dirFlag;
    tmpl_missile.direction = (uint8_t)df;
    tmpl_missile.x = tmpl_bullet.x;
    tmpl_missile.y = tmpl_bullet.y;
    tmpl_missile.heightOfs = tmpl_bullet.heightOfs;
    tmpl_missile.spriteW = bullet_speed[df];
    tmpl_missile.spriteH = bullet_anim[df];
    tmpl_missile.dirFlag = 0x00;
    tmpl_missile.spriteData = bullet_sprite[df];
    spawned = add_entity_to_list(tmpl_missile);
    if (spawned && esi > spawned)
        ground_enemy_shooting(spawned);
}
void fire_spread_bullets(uint16_t esi) // 1000:1fba
{
    Entity& e = ent(esi);
    Entity bullet = tmpl_fire_spread;
    uint16_t df = (uint16_t)e.dirFlag;
    bullet.direction = (uint8_t)df;
    bullet.x = (uint16_t)((int16_t)(int8_t)fire_xofs[df] + e.x);
    bullet.y = (uint16_t)((int16_t)(int8_t)fire_yofs[df] + e.y) & 0x03ff;
    bullet.heightOfs = e.heightOfs + 0x08;
    load_sprite_data(*fire_sprite[df], bullet);
    uint16_t spawned = add_entity_to_list(bullet);
    if (spawned && esi > spawned)
        directional_projectile(spawned);
}
void spawn_secondary_entity(uint16_t esi) // 1000:2005 — spawn_secondary_entity: creates a secondary entity (enemy ship part) offset from parent
{
    Entity& e = ent(esi);
    Entity sec = tmpl_secondary;
    uint16_t df = (uint16_t)e.dirFlag;
    sec.direction = (uint8_t)df;
    sec.x = (uint16_t)((int16_t)(int8_t)spawn_xofs[df] + e.x);
    sec.y = (uint16_t)((int16_t)(int8_t)spawn_yofs[df] + e.y) & 0x03ff;
    sec.heightOfs = e.heightOfs + 0x08;
    uint16_t spawned = add_entity_to_list(sec);
    if (spawned && esi > spawned)
        bouncing_projectile(spawned);
}
void spawn_explosion_at_entity(uint16_t esi) // 1000:2047
{
    Entity& e = ent(esi);
    uint8_t ef = effect_flag_1;
    if (e.flags & 0x20) {
        if (ef & 0x80)
            e.flags = 0x00;
        else {
            effect_flag_1 = ef | 0x80;
            tmpl_weapon.flags |= 0x20; // set direction bit
            apply_entity_template(tmpl_weapon, esi);
            play_sound_effect(0x03);
        }
    } else {
        if (ef & 0x01)
            e.flags = 0x00;
        else {
            effect_flag_1 = ef | 0x01;
            tmpl_weapon.flags &= 0xdf; // clear direction bit
            apply_entity_template(tmpl_weapon, esi);
            play_sound_effect(0x03);
        }
    }
}
void mark_entity_destroyed(uint16_t esi) // 1000:2092 — mark_entity_destroyed: replaces entity with explosion (template at 0x1427)
{
    apply_entity_template(tmpl_explosion_effect, esi); // apply explosion effect
}
void spawn_death_explosion(uint16_t esi) // 1000:2099 — mark_entity_small_effect: replaces entity with small effect (template at 0x12DE)
{
    apply_entity_template(tmpl_small_effect, esi); // apply small effect
}
void apply_entity_template(const Entity& src, uint16_t esi) // 1000:20a0 — apply_entity_template: copies visual/type fields from template onto entity at esi
{
    Entity& e = ent(esi);
    e.flags      = src.flags;
    e.zLayer     = src.zLayer;
    e.animFrame  = src.animFrame;
    e.dirFlag    = src.dirFlag;
    e.spriteW    = src.spriteW;
    e.spriteH    = src.spriteH;
    e.drawOfsY   = src.drawOfsY;
    e.drawOfsX   = src.drawOfsX;
    e.spriteData = src.spriteData;
    e.type       = src.type;
}
void spawn_hit_effect(uint16_t esi) // 1000:20db
{
    update_diamond_counter();
    remove_entity(esi);
    spawn_entity_from_data(esi, (uint16_t)ent(esi).param1, (uint16_t)ent(esi).param2);
}
void remove_entity(uint16_t esi) // 1000:20f0 — remove_entity: spawns an explosion effect at entity's position, then entity will be overwritten
{
    Entity& e = ent(esi);
    // Copy entity position to explosion template
    tmpl_explode.x = e.x;
    tmpl_explode.y = e.y;
    tmpl_explode.heightOfs = e.heightOfs;
    if (e.flags & 0x10) { // large entity: offset explosion position
        tmpl_explode.x -= 0x000c;
        tmpl_explode.y = (tmpl_explode.y - 0x0008) & 0x03ff;
    }
    add_entity_to_list(tmpl_explode);
}
void load_sprite_data(const SpriteTable& spr, uint16_t entity_ptr) // 1000:2121 — load_sprite_data: loads sprite dimensions and data pointers from sprite table
{
    Entity& e = ent(entity_ptr);
    load_sprite_data(spr, e);
}
void load_sprite_data(const SpriteTable& spr, Entity& e) // overload: loads sprite data into Entity struct
{
    uint16_t frame = e.dirFlag;
    e.spriteW    = spr.spriteW[frame];
    e.spriteH    = spr.spriteH[frame];
    e.drawOfsY   = spr.drawOfsY[frame];
    e.drawOfsX   = spr.drawOfsX[frame];
    e.spriteSheet = spr.spriteSheet[frame];
    e.spriteData  = spr.spriteData[frame];
}
uint16_t track_player_vertically(uint16_t esi) // 1000:215b
{
    Entity& e = ent(esi);
    int16_t dy = (int16_t)(player().y - e.y);
    if (dy > (int16_t)0x008c) {
        e.dirFlag = 0x02;
        return 0;
    }
    if (dy < (int16_t)0xfff0) {
        uint8_t dir = e.dirFlag;
        if (e.flags & 0x20) {
            dir++;
            if ((int8_t)dir > 0x04) {
                e.flags &= 0xdf;
                dir = 0x04;
            }
        } else {
            dir--;
            if ((int8_t)dir < 0x00) {
                e.flags |= 0x20;
                dir = 0x00;
            }
        }
        e.dirFlag = dir;
        return 0;
    }
    int16_t dx_val = (int16_t)(player().x - e.x);
    if (dx_val < 0) {
        if (dx_val > (int16_t)0xffe0)
            e.dirFlag = 0x02;
        else if (dy > 0x0020)
            e.dirFlag = 0x01;
        else
            e.dirFlag = 0x00;
    } else {
        if (dx_val < 0x0020)
            e.dirFlag = 0x02;
        else if (dy > 0x0020)
            e.dirFlag = 0x03;
        else
            e.dirFlag = 0x04;
    }
    return 1;
}
void init_game_parameters() // 1000:21dc — init_game_parameters: sets up HUD panel, bars, and initial game values
{
    // Push initial HUD panel parameters (x, y, width, height, color)
    blit_sprite_masked(res_data[RES_BIRD2], 0x0007, 0x0038, 0x1e11, 0x403c); // draw_hud_panel
    reset_hud_values(); // init_all_hud_bars
    update_score_bcd(); // init_score_display
    draw_hiscore_table(); // init_diamond_display
    init_hud_display(); // init_lives_display
}
void reset_hud_values() // 1000:2200 — init_all_hud_bars: draws all four status bars (fuel, ammo, shield, score)
{
    init_fuel_bar(); // init_fuel_bar
    init_ammo_bar(); // init_ammo_bar
    init_shield_bar(); // init_shield_bar
    draw_shield_label(); // init_score_bar
}
void update_hud_bars() // 1000:220d — update_hud_bars: updates fuel/ammo/shield/score bars each frame
{
    // Increment HUD frame counter, update score display every 4th frame
    hud_frame_ctr = hud_frame_ctr + 1;
    if (!(hud_frame_ctr & 0x03)) {
        add_bcd_score(audio_flag, 0x0000, 0x0000, 0x0000);
        update_weapon_effects();
    }
    // Update fuel bar
    int16_t fd = (int16_t)fuel_delta;
    if (fd) {
        if (fd < 0)
            decrease_fuel_bar();
        else
            for (uint16_t i = (uint16_t)fd; i != 0; --i) increase_fuel_bar();
        fuel_delta = 0x0000;
    }
    // Update ammo bar
    int16_t ad = (int16_t)ammo_delta;
    if (ad) {
        if (ad < 0)
            decrease_ammo_bar();
        else
            for (uint16_t i = (uint16_t)ad; i != 0; --i) increase_ammo_bar();
        ammo_delta = 0x0000;
    }
    // Update shield bar
    int16_t sd = (int16_t)shield_delta;
    if (sd) {
        if (sd < 0)
            for (uint16_t i = (uint16_t)(-sd); i != 0; --i) decrease_shield_bar();
        else
            for (uint16_t i = (uint16_t)sd; i != 0; --i) increase_shield_bar();
        shield_delta = 0x0000;
    }
    // Update score bar
    int16_t scd = (int16_t)score_delta;
    if (scd) {
        if (scd < 0)
            for (uint16_t i = (uint16_t)(-scd); i != 0; --i) decrement_score_display();
        else
            for (uint16_t i = (uint16_t)scd; i != 0; --i) increment_score_display();
        score_delta = 0x0000;
    }
}
void init_hud_display() // 1000:22b1 — init_lives_display: sets lives to 3 and draws all 3 life icons
{
    lives_count = 0x0003;
    draw_hud_label(); // draw_life_icon_1
    draw_score_digits(); // draw_life_icon_2
    draw_fuel_label(); // draw_life_icon_3
}
void draw_lives_display() // 1000:22c1
{
    lives_count++;
    uint16_t lc = lives_count;
    if (lc > 0x0003) {
        lives_count = 0x0003;
        return;
    }
    if (lc == 0x0001)
        blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1b90, 0x43e6);
    else if (lc == 0x0002)
        blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1b93, 0x43e6);
    else if (lc == 0x0003)
        blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1b96, 0x43e6);
}
void draw_hud_label() // 1000:22e1
{
    blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1b90, 0x43e6);
}
void draw_score_digits() // 1000:22f9
{
    blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1b93, 0x43e6);
}
void draw_fuel_label() // 1000:2311
{
    blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1b96, 0x43e6);
}
void draw_ammo_label() // 1000:2329
{
    lives_count--;
    uint16_t lc = lives_count;
    if (lc == 0x0000)
        fill_rect_ega(0x0000, 0x000f, 0x0002, 0x1b90);
    else if (lc == 0x0001)
        fill_rect_ega(0x0000, 0x000f, 0x0002, 0x1b93);
    else if (lc == 0x0002)
        fill_rect_ega(0x0000, 0x000f, 0x0002, 0x1b96);
}
void draw_shield_label() // 1000:237c
{
    ammo_count = 0x0006;
    score_delta = 0x0000;
    draw_diamond_counter();
    draw_diamond_icon();
    draw_diamond_icon_2();
    draw_diamond_icon_3();
    draw_diamond_icon_4();
    draw_diamond_icon_5();
}
void increment_score_display() // 1000:239b
{
    ammo_count++;
    uint16_t ac = ammo_count;
    if (ac > 0x0006) {
        ammo_count = 0x0006;
        return;
    }
    play_sound_effect(0x08);
    uint16_t addr_table[] = {0x1b99, 0x1b9b, 0x1b9d, 0x1b9f, 0x1ba1, 0x1ba3};
    if (ac >= 0x0001 && ac <= 0x0006)
        blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, addr_table[ac - 1], 0x43ee);
}
void draw_diamond_counter() // 1000:23d4
{
    blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1b99, 0x43ee);
}
void draw_diamond_icon() // 1000:23ec
{
    blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1b9b, 0x43ee);
}
void draw_diamond_icon_2() // 1000:2404
{
    blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1b9d, 0x43ee);
}
void draw_diamond_icon_3() // 1000:241c
{
    blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1b9f, 0x43ee);
}
void draw_diamond_icon_4() // 1000:2434
{
    blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1ba1, 0x43ee);
}
void draw_diamond_icon_5() // 1000:244c
{
    blit_sprite_masked(res_data[RES_BIRD2], 0x000f, 0x0010, 0x1ba3, 0x43ee);
}
void decrement_score_display() // 1000:2464
{
    uint16_t old_count = ammo_count;
    ammo_count--;
    if ((int16_t)ammo_count < 0) {
        ammo_count = 0;
        return;
    }
    uint16_t addr_table[] = {0x1b99, 0x1b9b, 0x1b9d, 0x1b9f, 0x1ba1, 0x1ba3};
    if (old_count >= 1 && old_count <= 6) {
        fill_rect_ega(0x0000, 0x000f, 0x0002, addr_table[old_count - 1]);
    }
}
void init_fuel_bar() // 1000:250b
{
    fuel_level = 0x002c;
    fuel_delta = 0x0000;
    blit_sprite_masked(res_data[RES_BIRD2], 0x0007, 0x002c, 0x1b88, 0x48f6);
}
void decrease_fuel_bar() // 1000:252f
{
    int16_t level = fuel_level - 1;
    if (level < 0)
        return;
    fuel_level = level;
    draw_hud_bar_pixel(0x1b88, level);
}
void set_fuel_bar() // 1000:2536
{
    // only called from increase_fuel_bar — inlined there
}
void increase_fuel_bar() // 1000:2542
{
    uint16_t level = fuel_level;
    if (level >= 0x002c)
        return;
    draw_hud_bar_pixel(0x1b88, level);
    fuel_level = level + 1;
}
void init_ammo_bar() // 1000:2553
{
    ammo_bar = 0x0030;
    ammo_delta = 0x0000;
    blit_sprite_masked(res_data[RES_BIRD2], 0x0007, 0x0030, 0x1cc8, 0x2ce6);
}
void decrease_ammo_bar() // 1000:2577
{
    int16_t level = ammo_bar - 1;
    if (level < 0)
        return;
    ammo_bar = level;
    draw_hud_bar_pixel(0x1cc8, level);
}
void set_ammo_bar() // 1000:257e
{
    // only called from increase_ammo_bar — inlined there
}
void increase_ammo_bar() // 1000:258a
{
    uint16_t level = ammo_bar;
    if (level >= 0x0030)
        return;
    draw_hud_bar_pixel(0x1cc8, level);
    ammo_bar = level + 1;
}
void init_shield_bar() // 1000:259b
{
    shield_active = 0x0038;
    shield_delta = 0x0000;
    blit_sprite_masked(res_data[RES_BIRD2], 0x0007, 0x0038, 0x1e08, 0x4496);
}
void decrease_shield_bar() // 1000:25bf
{
    int16_t level = shield_active - 1;
    if (level < 0)
        return;
    shield_active = level;
    draw_hud_bar_pixel(0x1e08, level);
}
void set_shield_bar() // 1000:25c6
{
    // only called from increase_shield_bar — inlined there
}
void increase_shield_bar() // 1000:25d2
{
    uint16_t level = shield_active;
    if (level >= 0x0038)
        return;
    draw_hud_bar_pixel(0x1e08, level);
    shield_active = level + 1;
}
void update_score_bcd() // 1000:264a
{
    score_digits[0] = score_digits[1] = score_digits[2] = 0;
    score_digits[3] = score_digits[4] = score_digits[5] = 0;
    update_weapon_effects();
}
void increment_score() // 1000:2662
{
    add_bcd_score(0x0000, 0x0001, 0x0000, 0x0000);
}
void update_diamond_counter() // 1000:2676
{
    add_bcd_score(0x0000, 0x0005, 0x0001, 0x0000);
}
void check_all_diamonds() // 1000:268a
{
    add_bcd_score(0x0000, 0x0000, 0x0005, 0x0002);
}
void add_bcd_score(uint16_t ones, uint16_t tens, uint16_t hundreds, uint16_t thousands) // 1000:269e add_bcd_score
{
    // BCD addition with carry chain
    uint8_t d5 = score_digits[5] + ones;
    if (d5 > 0x09) { d5 -= 0x0a; score_digits[4]++; }
    score_digits[5] = d5;

    uint8_t d4 = score_digits[4] + tens;
    if (d4 > 0x09) { d4 -= 0x0a; score_digits[3]++; }
    score_digits[4] = d4;

    uint8_t d3 = score_digits[3] + hundreds;
    if (d3 > 0x09) { d3 -= 0x0a; score_digits[2]++; }
    score_digits[3] = d3;

    uint8_t d2 = score_digits[2] + thousands;
    if (d2 > 0x09) { d2 -= 0x0a; score_digits[1]++; }
    score_digits[2] = d2;

    uint8_t d1 = score_digits[1];
    if (d1 > 0x09) {
        d1 -= 0x0a;
        score_digits[0]++;
        draw_lives_display();
    }
    score_digits[1] = d1;

    uint8_t d0 = score_digits[0];
    if (d0 > 0x09) d0 -= 0x0a;
    score_digits[0] = d0;
}
void update_weapon_effects() // 1000:2714
{
    leading_zero = 0x01;
    uint16_t pos_dx = 0x0000;
    for (uint16_t i = 0; i < 6; i++) {
        uint8_t digit = score_digits[i];
        if (digit)
            leading_zero = 0x00;
        if (!leading_zero) {
            blit_sprite_masked(res_data[RES_BIRD2], 0x0009, 0x0010, score_pos[pos_dx >> 1], score_digit_sprite[digit]);
            pos_dx += 0x0002;
        }
    }
}
void load_hiscore_file() // load hiscore data directly from file
{
/*
    FILE* f = fopen("dos/hiscores", "rb");
    if (!f) return;
    uint8_t buf[140];
    if (fread(buf, 1, 140, f) == 140) {
        memcpy(text_buffer, buf, 84);
        memcpy(score_table, buf + 84, 42);
        memcpy(sort_buffer, buf + 126, 7);
        memcpy(hiscore_data, buf + 133, 7);
    }
    fclose(f);
*/
}
void init_font_and_hud() // 1000:2762
{
    // Clear score entries 1-6 (36 bytes)
    memset(score_table + 6, 0, 36);
    // Fill text buffer with '.' (0x2e)
    memset(text_buffer, 0x2e, 84);
    text_buffer[0] = 0x5f;
    // Initialize hiscore entries 0-6
    for (uint16_t i = 0; i < 7; i++)
        hiscore_data[i] = (uint8_t)i;
    load_hiscore_file();
}
void load_intro_text_restart() // 1000:279f
{
    draw_text_block();
    uint8_t entries = score_entries;
    if (!entries) {
        config_exists = 0x00;
        return;
    }
    config_exists = 0x01;
    uint16_t score_ofs = (uint16_t)entries * 6;
    for (int i = 0; i < 6; i++)
        score_table[score_ofs + i] = score_digits[i];
    uint16_t text_dest = (uint16_t)entries * 12;
    text_input_buf = text_dest;
    for (int i = 0; i < 12; i++)
        text_buffer[text_dest + i] = text_buffer[i];
    uint16_t scan = 0;
    while (hiscore_data[scan])
        scan++;
    hiscore_data[scan] = entries;
    score_entries = 0x00;
    text_entry_idx = (uint8_t)scan;
    load_intro_text_first();
}
void draw_text_block() // 1000:2809
{
    for (int i = 0; i < 6; i++)
        sort_buffer[i] = hiscore_data[i];
    sort_buffer[6] = score_entries;
    uint16_t dst = 0;
    for (int j = 0; j < 7; j++) {
        uint16_t best = 0;
        while (sort_buffer[best] == 0xff)
            best++;
        if (best != 6) {
            uint16_t cand = best;
            do {
                cand++;
                if (sort_buffer[cand] != 0xff) {
                    if (draw_text_line(best, cand))
                        best = cand;
                }
            } while (cand != 6);
        }
        uint8_t val = sort_buffer[best];
        sort_buffer[best] = 0xff;
        hiscore_data[dst] = val;
        dst++;
    }
}
uint16_t draw_text_line(uint16_t entry_a_idx, uint16_t entry_b_idx) // 1000:2872
{
    uint8_t idx_a = sort_buffer[entry_a_idx];
    uint8_t idx_b = sort_buffer[entry_b_idx];
    uint16_t score_a = (uint16_t)idx_a * 6;
    uint16_t score_b = (uint16_t)idx_b * 6;
    for (int i = 0; i < 6; i++) {
        uint8_t d = score_table[score_b + i];
        uint8_t s = score_table[score_a + i];
        if (d > s) return 1;
        if (d < s) return 0;
    }
    return 0;
}
void load_intro_text_first() // 1000:28da
{
    for (int i = 0; i < 6; i++) {
        uint16_t name_pos = hud_text_tbl[i * 4 + 1];
        decode_sprite_char(name_pos, i);
        uint16_t score_pos = hud_text_tbl[i * 4 + 3];
        store_intro_text_data(score_pos, i);
    }
}
void store_intro_text_data(uint16_t hud_pos, uint16_t hiscore_idx) // 1000:2907
{
    hud_sprite_pos = hud_pos;
    uint8_t entry_index = hiscore_data[hiscore_idx];
    uint16_t score_src = (uint16_t)entry_index * 6;
    leading_zero = 0x01;
    uint16_t col = 0;
    for (int i = 0; i < 6; i++) {
        uint8_t digit = score_table[score_src + i];
        if (digit)
            leading_zero = 0x00;
        uint16_t sprite_ofs;
        if (leading_zero)
            sprite_ofs = 0x6f6c;
        else
            sprite_ofs = font_digit_sprite[digit];
        blit_char_sprite(col, sprite_ofs);
        col += 6;
    }
}
void decode_sprite_char(uint16_t hud_pos, uint16_t hiscore_idx) // 1000:2959
{
    hud_sprite_pos = hud_pos;
    uint8_t entry_index = hiscore_data[hiscore_idx];
    uint16_t text_src = (uint16_t)entry_index * 12;
    uint16_t col = 0;
    for (int i = 0; i < 12; i++) {
        uint8_t ch = text_buffer[text_src + i];
        uint16_t sprite_ofs;
        if (ch == 0x20) sprite_ofs = 0x6546;
        else if (ch == 0x2e) sprite_ofs = 0x6f6c;
        else if (ch == 0x5f) sprite_ofs = 0x764c;
        else sprite_ofs = (uint16_t)(ch - 0x41) * 6;
        blit_char_sprite(col, sprite_ofs);
        col += 6;
    }
}
void draw_sprite_row(uint16_t text_ofs) // 1000:296f
{
    uint16_t col = 0;
    for (int i = 0; i < 12; i++) {
        uint8_t ch = text_buffer[text_ofs + i];
        uint16_t sprite_ofs;
        if (ch == 0x20) sprite_ofs = 0x6546;
        else if (ch == 0x2e) sprite_ofs = 0x6f6c;
        else if (ch == 0x5f) sprite_ofs = 0x764c;
        else sprite_ofs = (uint16_t)(ch - 0x41) * 6;
        blit_char_sprite(col, sprite_ofs);
        col += 6;
    }
}
void blit_char_sprite(uint16_t col_offset, uint16_t sprite_offset) // 1000:29ae — blit_char_sprite
{
    uint8_t *dp = res_data[RES_PODZ1];
    uint8_t *sp = res_data[RES_BIRD2];
    uint16_t dst = hud_sprite_pos + col_offset;
    uint16_t src = sprite_offset;
    for (int i = 0; i < 0x000b; i++) {
        *(uint16_t*)&dp[dst] = *(uint16_t*)&sp[src]; dst += 2; src += 2;
        *(uint16_t*)&dp[dst] = *(uint16_t*)&sp[src]; dst += 2; src += 2;
        *(uint16_t*)&dp[dst] = *(uint16_t*)&sp[src]; dst += 2; src += 2;
        dst += 0x009a;
        src += 0x009a;
    }
}
void toggle_intro_display() // 1000:29db
{
    text_input_pos = 0;
    while (true) {
        if (text_input_pos >= 0x000c)
            break;
        uint8_t key = scan_keyboard_input();
        if (!key)
            break;
        uint16_t buf_base = text_input_buf;
        if (key == 0x08) {
            // Backspace
            text_buffer[buf_base + text_input_pos] = 0x2e;
            text_input_pos--;
            if ((int16_t)text_input_pos < 0)
                text_input_pos = 0;
        } else {
            // Regular character
            text_buffer[buf_base + text_input_pos] = key;
            text_input_pos++;
        }
        uint16_t pos = text_input_pos;
        if (pos < 0x000c)
            text_buffer[text_input_buf + pos] = 0x5f;
        clear_intro_area();
        render_intro_background();
        render_all_sprites();
        page_flip_and_vsync();
    }
    uint16_t pos = text_input_pos;
    if (pos < 0x000c) {
        uint16_t addr = text_input_buf + pos;
        if (text_buffer[addr] == 0x5f) {
            text_buffer[addr] = 0x2e;
            clear_intro_area();
        }
    }
    // hiscore save (no-op in emulation — file creation not implemented)
    config_exists = 0x00;
}
void clear_intro_area() // 1000:2a64
{
    uint16_t idx = (uint16_t)text_entry_idx << 3;
    hud_sprite_pos = hud_text_tbl[idx >> 1];
    draw_sprite_row(text_input_buf);
}
void draw_hiscore_table() // 1000:2a7f
{
    powerup_flags[0] = 0x00;
    powerup_flags[1] = 0x00;
    powerup_flags[2] = 0x00;
    powerup_flags[3] = 0x00;
    powerup_flags[4] = 0x00;
    powerup_flags[5] = 0x00;
    blit_sprite_masked(res_data[RES_BLOX], 0x0008, 0x0010, 0x1b82, 0x1178);
    blit_sprite_masked(res_data[RES_BLOX], 0x0008, 0x0010, 0x1cc2, 0x1678);
    blit_sprite_masked(res_data[RES_BLOX], 0x0008, 0x0010, 0x1e02, 0x1b78);
    blit_sprite_masked(res_data[RES_BLOX], 0x0008, 0x0010, 0x1b85, 0x2078);
    blit_sprite_masked(res_data[RES_BLOX], 0x0008, 0x0010, 0x1cc5, 0x2578);
    blit_sprite_masked(res_data[RES_BLOX], 0x0008, 0x0010, 0x1e05, 0x2a78);
}
void activate_powerup(uint8_t powerup_id) // 1000:2b28
{
    add_bcd_score(0x0000, 0x0005, 0x0001, 0x0000);
    uint16_t sprite_addrs[] = {0x1b82, 0x1cc2, 0x1e02, 0x1b85, 0x1cc5, 0x1e05};
    if (powerup_id <= 0x05) {
        powerup_flags[powerup_id] = 0x01;
        blit_sprite_masked(res_data[RES_BLOX], 0x0008, 0x0010, sprite_addrs[powerup_id], 0x2f78);
    }
}
void start_key_config_screen() // 1000:2c07
{
    fill_rect_ega(0x0005, 0x0030, 0x0013, 0x0a0b);
    fill_rect_ega(0x0002, 0x0028, 0x0011, 0x0aac);
    blit_sprite_masked(res_data[RES_BLOX], 0x000f, 0x0078, 0x0b4d, 0x5a5c);
}
void save_key_config() // 1000:2c45
{
    fill_rect_ega(0x0005, 0x0028, 0x0010, 0x0aac);
    fill_rect_ega(0x0002, 0x0020, 0x000e, 0x0b4d);
    blit_sprite_masked(res_data[RES_BIRD2], 0x000c, 0x0028, 0x0c8f, 0x7592);
    blit_sprite_masked(res_data[RES_BLOX], 0x000d, 0x0020, 0x0ce4, 0x1ab8);
}
void show_key_prompt(uint8_t bar_index) // 1000:2c9a — draw_hud_bar
{
    fill_rect_ega(0x0002, 0x000f, 0x0011, 0x0dcc);
    if (bar_index == 0x06)
        draw_single_hud_bar(0x00);
    else if (bar_index == 0x07)
        draw_single_hud_bar(0x01);
    blit_sprite_masked(res_data[hud_table_idx[bar_index] >> 1], hud_rows[bar_index], hud_width[bar_index], hud_vid_dest[bar_index], hud_sprite_src[bar_index]);
}
void draw_single_hud_bar(uint8_t bar_index) // 1000:2cc7 — draw_single_hud_bar
{
    blit_sprite_masked(res_data[hud_table_idx[bar_index] >> 1], hud_rows[bar_index], hud_width[bar_index], hud_vid_dest[bar_index], hud_sprite_src[bar_index]);
}
void init_tunnel_entity_data() // 1000:2ddc
{
    tunnel_map_phase = tunnel_phase & 0x03;
    tunnel_phase++;
    tunnel_sec_chg = 0xff;
}
void clear_tunnel_entities() // 1000:2df6
{
    angle_trail[0] = 0;
    angle_trail[1] = 0;
    angle_trail[2] = 0;
}
void tunnel_player_handler(uint16_t esi) // 1000:2e02 — tunnel_player_handler (type 12): controls player inside tunnel
{
    handle_vertical_scroll();
    tunnel_frame_update();
    // Horizontal input
    int16_t horiz = (int16_t)(scroll_speed >> 3);
    uint16_t inp = input_state;
    if (inp & 0x01) horiz = -horiz - 3;
    else if (inp & 0x02) horiz += 3;
    else horiz = 0;
    tunnel_horiz_in = (uint16_t)horiz;
    // Vertical input from angle
    uint8_t tun_angle = ent(esi).animFrame & 0x7f;
    int16_t vert;
    if (tun_angle > 0x3f)
        vert = -tunnel_check_collision((uint8_t)(0x7f - tun_angle));
    else
        vert = tunnel_check_collision(tun_angle);
    tunnel_vert_in = (uint16_t)vert;
    // Velocity update with damping
    int16_t vel = (int16_t)(tunnel_vel + tunnel_horiz_in + tunnel_vert_in);
    if (vel) { vel += (vel < 0) ? 1 : -1; if (vel) vel += (vel < 0) ? 1 : -1; }
    if (vel > 0x40) vel = 0x40;
    else if (vel < -0x40) vel = -0x40;
    tunnel_vel = (uint16_t)vel;
    ent(esi).animFrame += (uint8_t)(int8_t)(vel >> 2);
    // Position from angle lookup
    uint16_t angle_idx = ent(esi).animFrame & 0x7f;
    int16_t sin_val = (int16_t)(int8_t)tunnel_sin[angle_idx];
    ent(esi).x = (uint16_t)(sin_val * 2 + 0x0080);
    int16_t cos_val = (int16_t)(int8_t)tunnel_cos[angle_idx];
    uint16_t y_raw = (uint16_t)(cos_val * 2 + 0x0080);
    if (y_raw) y_raw = (y_raw * 10 + 5) / 12;
    ent(esi).y = y_raw;
    ent(esi).dirFlag = tunnel_dir_6005[angle_idx];
    load_sprite_data(spr_1594, esi);
    // Angle trail
    angle_trail[2] = angle_trail[1];
    angle_trail[1] = angle_trail[0];
    angle_trail[0] = player().animFrame;
    // Missile N state machine
    uint8_t ms_n = missile_n_state;
    if (inp & 0x40) {
        if (ms_n == 0x02) { missile_n_state = 0x03; play_sound_effect(0x02); tunnel_flag = 0x02; }
    } else {
        if (ms_n == 0x01) missile_n_state = 0x02;
        else if (ms_n == 0x03) missile_n_state = 0x00;
    }
    // Missile M state machine
    uint8_t ms_m = missile_m_state;
    if (inp & 0x20) {
        if (ms_m == 0x02) { missile_m_state = 0x03; play_sound_effect(0x02); tunnel_flag = 0x02; }
    } else {
        if (ms_m == 0x01) missile_m_state = 0x02;
        else if (ms_m == 0x03) missile_m_state = 0x00;
    }
}
void tunnel_missile_entity(uint16_t esi) // 1000:2f50 — tunnel_entity (type 34): missile entity inside tunnel
{
    uint8_t eflags = ent(esi).flags;
    uint8_t ms_state;
    int8_t angle_ofs;
    if (eflags & 0x20) {
        ms_state = missile_m_state;
        angle_ofs = 0x08;
    } else {
        ms_state = missile_n_state;
        angle_ofs = (int8_t)0xf8; // -8
    }
    if (ms_state == 0x03 || !ms_state) {
        ent(esi).flags = 0x00;
        uint16_t scan = 0x1ba1;
        while (true) {
            uint8_t f = ent(scan).flags;
            if (f & 0x80) return;
            if ((f & 0x01) && ent(scan).type == 0x0f) {
                tunnel_update_position(scan);
            }
            scan += 0x0017;
        }
        return;
    }
    uint16_t angle_idx = ((uint8_t)(angle_ofs + angle_trail[2])) & 0x7f;
    int16_t sin_val = (int16_t)(int8_t)tunnel_sin[angle_idx];
    ent(esi).x = (uint16_t)(sin_val + (sin_val >> 1) + 0x0080);
    int16_t cos_val = (int16_t)(int8_t)tunnel_cos[angle_idx];
    uint16_t y_raw = (uint16_t)(cos_val + (cos_val >> 1) + 0x0080);
    if (y_raw) y_raw = (y_raw * 10 + 5) / 12;
    ent(esi).y = y_raw;
    uint16_t p_angle = player().animFrame & 0x7f;
    ent(esi).dirFlag = tunnel_dirflag_6290[p_angle];
    load_sprite_data(spr_1811, esi);
}
void tunnel_enemy_positioned(uint16_t esi) // 1000:2fe8 — tunnel_enemy_positioned (type 14): enemy at fixed position in tunnel
{
    uint16_t wave_idx = (tunnel_wave_pos >> 3) & 0x001f;
    tunnel_walls = tunnel_walls_6666[wave_idx];
    ent(esi).dirFlag = tunnel_dirflag_6634[wave_idx];
    load_sprite_data(spr_1929, esi);
}
void tunnel_exit_trigger(uint16_t esi) // 1000:300a — tunnel_exit_trigger (type 15): detects when player exits tunnel
{
    uint16_t dist = (tunnel_distance - ent(esi).param) >> 3;
    if (dist > 0x002d) {
        ent(esi).flags = 0x00;
        return;
    }
    tunnel_position_entity((uint8_t)dist, esi);
    uint16_t half_dist = dist >> 1;
    ent(esi).dirFlag = (uint8_t)half_dist;
    ent(esi).zLayer = tunnel_zlayer[half_dist];
    load_sprite_data(spr_1ac9, esi);
    if (ent(esi).zLayer != 0x02)
        return;
    uint8_t pdir = player().dirFlag;
    if (tunnel_dir_6133[(uint16_t)pdir] != ent(esi).direction)
        return;
    play_sound_effect(0x09);
    tunnel_update_position(esi);
}
void tunnel_update_position(uint16_t esi) // 1000:3059
{
    ent(esi).flags = 0x00;
    uint8_t tc = tunnel_color;
    if (tc == 0x40) {
        ammo_delta += 0x0006;
    } else if (tc == 0x80) {
        fuel_delta += 0x0004;
    } else if (tc == 0xc0) {
        shield_delta += 0x0008;
    } else {
        check_all_diamonds();
    }
}
int16_t tunnel_check_collision(uint8_t angle) // 1000:3084
{
    int8_t val = (int8_t)(angle - 0x05);
    if (val < 0)
        return 0;
    uint8_t clamped = (uint8_t)val;
    if (clamped > 0x38) clamped = 0x38;
    return -(int16_t)(clamped >> 1) - 3;
}
void tunnel_frame_update() // 1000:309d
{
    uint16_t step = ((scroll_speed + 7) >> 3) + 2;
    tunnel_distance += step;
    uint16_t section = tunnel_section + step;
    if (section > 0x02e8) {
        section = 0;
        fuel_delta = 0xffff;
    }
    tunnel_section = section;
    int16_t remain = (int16_t)(tunnel_distance - 0x0380);
    if (remain >= 0) {
        game_mode = 0x00;
        scroll_pos = saved_scroll;
    } else {
        uint16_t dist_to_end = (uint16_t)(-remain);
        if (dist_to_end < 0x0100) {
            tunnel_wave_pos = dist_to_end;
            if (!tunnel_spawner) {
                add_entity_to_list(tmpl_tunnel_spawn);
                tunnel_spawner = 0x01;
            }
        } else {
            uint8_t sec_idx = (uint8_t)(tunnel_distance >> 6);
            if (sec_idx != tunnel_sec_chg) {
                tunnel_sec_chg = sec_idx;
                uint8_t map_val = tunnel_map_data[tunnel_map_phase][sec_idx];
                if (map_val) {
                    Entity ent = tmpl_tunnel_entity;
                    ent.direction = map_val;
                    ent.param = tunnel_distance;
                    add_entity_to_list(ent);
                }
            }
        }
    }
}
void tunnel_position_entity(uint8_t dist_idx, uint16_t esi) // 1000:3130
{
    uint16_t radius = tunnel_radius[(uint16_t)dist_idx];
    uint8_t dir = ent(esi).direction;
    if (dir == 0x01 || dir == 0x02 || dir == 0x08)
        ent(esi).y = (uint16_t)(-radius + 0x006a);
    if (dir == 0x02 || dir == 0x03 || dir == 0x04)
        ent(esi).x = radius + 0x0080;
    if (dir == 0x04 || dir == 0x05 || dir == 0x06)
        ent(esi).y = radius + 0x006a;
    if (dir == 0x06 || dir == 0x07 || dir == 0x08)
        ent(esi).x = (uint16_t)(-radius + 0x0080);
}
uint16_t get_tunnel_plane_mask() // 1000:31e7 — get_tunnel_plane_mask: returns EGA plane mask based on TUNNEL_COLOR
{
    uint8_t tc = tunnel_color;
    if (tc == 0x40) return 0x0002;      // green plane
    else if (tc == 0x80) return 0x0004; // red plane
    else if (tc == 0xc0) return 0x0001; // blue plane
    else return 0x0003;                  // cyan (blue + green)
}
uint16_t get_tunnel_bg_color() // 1000:3209 — get_tunnel_bg_color: returns background color, cycles TUNNEL_FLAG
{
    uint8_t tf = tunnel_flag;
    if (!tf) {
        return 0x0000; // black background
    } else if (tf == 0x01) {
        tunnel_flag = 0x00; // toggle back
        return 0x0007; // light gray
    } else {
        tunnel_flag = 0x01; // toggle to gray
        return 0x000f; // white
    }
}
void clear_and_init_buffers() // 1000:3423 — clear_and_init_buffers: clears both pages and draws HUD border frame
{
    clear_video_buffer(0x00);
    draw_hud_border_frame();
    page_flip_and_vsync();
    clear_video_buffer(0x00);
    draw_hud_border_frame();
}
void draw_tunnel_wireframe() // 1000:34a8 — draw_tunnel_wireframe: clears tunnel buffer, draws border and perspective walls
{
    // Clear tunnel buffer (8192 bytes = 4096 words)
    for (uint16_t i = 0; i < 0x1000; i++)
        *(uint16_t*)&tunnel_buf[i * 2] = 0;
    // Draw outer border rectangle using Bresenham lines
    draw_line_bresenham(0x0000, 0x00B0, 0x00FF, 0x004F); // left edge
    draw_line_bresenham(0x00FF, 0x00B0, 0x0000, 0x004F); // right edge
    draw_line_bresenham(0x00B0, 0x00FF, 0x004F, 0x0000); // top edge
    draw_line_bresenham(0x004F, 0x00FF, 0x00B0, 0x0000); // bottom edge
    uint16_t tf = tunnel_distance & 0x003f;
    tunnel_frame = tf;
    draw_tunnel_octant_lines((uint16_t)tunnel_octant[tf], tf + 0x40);
    if (tf > 0x000c)
        return;
    draw_line_bresenham(0x7F - tunnel_inner_x[tf], 0xFF, 0, (uint16_t)tunnel_inner_y[tf] + 0x80);
    draw_line_bresenham(0x7F - tunnel_inner_x[tf], 0, 0, 0x7F - tunnel_inner_y[tf]);
    draw_line_bresenham((uint16_t)tunnel_inner_x[tf] + 0x80, 0xFF, 0xFF, (uint16_t)tunnel_inner_y[tf] + 0x80);
    draw_line_bresenham((uint16_t)tunnel_inner_x[tf] + 0x80, 0, 0xFF, 0x7F - tunnel_inner_y[tf]);
}
void draw_tunnel_octant_lines(uint16_t param_a, uint16_t param_b) // 1000:35bc — draw_tunnel_octant_lines
{
    while (true) {
        draw_line_bresenham(0x7F - param_b, 0x80 + param_a, 0x7F - param_b, 0x7F - param_a);
        draw_line_bresenham(0x7F - param_a, 0x80 + param_b, 0x7F - param_b, 0x80 + param_a);
        draw_line_bresenham(0x80 + param_a, 0x80 + param_b, 0x7F - param_a, 0x80 + param_b);
        draw_line_bresenham(0x80 + param_a, 0x80 + param_b, 0x80 + param_b, 0x80 + param_a);
        draw_line_bresenham(0x80 + param_b, 0x80 + param_a, 0x80 + param_b, 0x7F - param_a);
        draw_line_bresenham(0x80 + param_b, 0x7F - param_a, 0x80 + param_a, 0x7F - param_b);
        draw_line_bresenham(0x80 + param_a, 0x7F - param_b, 0x7F - param_a, 0x7F - param_b);
        draw_line_bresenham(0x7F - param_b, 0x7F - param_a, 0x7F - param_a, 0x7F - param_b);
        uint16_t half_b = param_b >> 1;
        if ((uint8_t)half_b <= tunnel_walls)
            return;
        param_b = half_b;
        param_a = param_a >> 1;
    }
}
void draw_line_bresenham(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) // 1000:36d4 draw_line_bresenham
{
    // Scale x coordinates from pixel to 5/12 ratio
    if (x2) x2 = (x2 * 10 + 5) / 12;
    if (x1) x1 = (x1 * 10 + 5) / 12;
    // Ensure y1 >= y2 (swap endpoints if needed)
    if (y1 < y2) {
        uint16_t t = y1; y1 = y2; y2 = t;
        t = x1; x1 = x2; x2 = t;
    }
    uint16_t ldx = y1 - y2;
    int16_t dx_signed = (int16_t)(x1 - x2);
    uint16_t dy_abs = (dx_signed < 0) ? -dx_signed : dx_signed;
    uint16_t row_step = (dx_signed < 0) ? 0xffe0 : 0x0020;

    // Inline compute_pixel_position: compute initial byte offset and bit mask
    uint16_t ofs = (x2 << 5) + (y2 >> 3);
    uint8_t mask = 0x80 >> (y2 & 7);
    tunnel_buf[ofs] |= mask;

    if (!ldx) {
        // Horizontal line only
        for (uint16_t i = dy_abs; i; i--) {
            ofs += row_step;
            tunnel_buf[ofs] |= mask;
        }
    } else if (!dy_abs) {
        // Vertical line only
        for (uint16_t i = ldx; i; i--) {
            mask >>= 1;
            if (!mask) { mask = 0x80; ofs++; }
            tunnel_buf[ofs] |= mask;
        }
    } else if (dy_abs < ldx) {
        // Mostly horizontal
        uint16_t accum = ldx >> 1;
        for (uint16_t i = ldx; i; i--) {
            mask >>= 1;
            if (!mask) { mask = 0x80; ofs++; }
            accum += dy_abs;
            if (accum > ldx) { accum -= ldx; ofs += row_step; }
            tunnel_buf[ofs] |= mask;
        }
    } else {
        // Mostly vertical
        uint16_t accum = dy_abs >> 1;
        for (uint16_t i = dy_abs; i; i--) {
            ofs += row_step;
            accum += ldx;
            if (accum > dy_abs) {
                accum -= dy_abs;
                mask >>= 1;
                if (!mask) { mask = 0x80; ofs++; }
            }
            tunnel_buf[ofs] |= mask;
        }
    }
}
// compute_pixel_position inlined into draw_line_bresenham
void init_sound_state() // 1000:382a
{
    sound_flag_1 = 0;
    sound_flag_2 = 0;
    sound_flag_3 = 0;
    sound_ctrl = 0x01;
    sound_state = 0x00;
}
void play_sound_effect(uint8_t sound_id) // 1000:3840 — play_sound
{
    if (music_playing) return;
    if (!sound_ctrl) return;
    if (!sound_flag_1) {
        sound_flag_1 = sound_id;
        update_sound_channel(sound_id);
    } else if (!sound_flag_2) {
        sound_flag_2 = sound_id;
    } else {
        if (sound_id > sound_flag_3)
            sound_flag_3 = sound_id;
    }
}
void update_sound_channel(uint8_t chan_id) // 1000:3914
{
    uint16_t idx = (chan_id - 1);
    SfxChannel& ch = sfx_channels[idx];
    snd_note_duration = ch.note_duration;
    if (idx == SND_CHAN_A_IDX) {
        uint16_t freq = ((uint16_t)ammo_count << 8);
        freq <<= 1;
        freq <<= 1;
        freq = -freq;
        freq += 0x1f40;
        ch.frequency = freq;
    } else if (idx == SND_CHAN_B_IDX) {
        uint16_t angle = player().animFrame & 0x7f;
        if (angle > 0x3f) angle -= 0x40;
        else { angle = -angle; angle += 0x3f; }
        angle <<= 1;
        angle <<= 1;
        angle += 0x0190;
        ch.frequency = angle;
    }
    uint16_t freq = ch.frequency;
    snd_frequency = freq;
    snd_freq_slide = ch.freq_slide;
    uint8_t vib_type = ch.vibrato_type;
    snd_vibrato_type = vib_type;
    if ((int8_t)vib_type > 0) {
        snd_vibrato_idx = vib_type - 1;
        snd_vibrato_phase = 0x00;
    }
    out8(0x43, 0xb6);
    out8(0x42, freq & 0xff);
    out8(0x42, freq >> 8);
    uint8_t port_val = in8(0x61);
    port_val |= 0x03;
    out8(0x61, port_val);
}
void shutdown_sound() // 1000:39a3
{
    sound_flag_1 = 0;
    sound_flag_2 = 0;
    sound_flag_3 = 0;
    snd_note_duration = 0;
    uint8_t port_val = in8(0x61);
    port_val &= 0xfc;
    out8(0x61, port_val);
}
void init_sound_system() // 1000:39b8
{
    snd_tick_divider = 0x00;
    snd_music_pos = 0x0000;
    music_playing = 0x01;
    snd_music_table = config_exists ? music_notes_1 : music_notes_2;
}
void timer_isr() // 1000:05ce — INT 1Ch timer ISR: increments tick counter, calls sound_tick
{
    timer_tick++;
    sound_tick();
}
void sound_tick() // 1000:387d — called from timer ISR: advances sound effects and music sequencer
{
    // Music sequencer update
    if (music_playing) {
        if (!sound_ctrl) {
            snd_music_pos = 0x0000;
            music_playing = 0x00;
        } else {
            music_sequencer_tick();
        }
    }
    // Sound effect update
    if (!sound_flag_1)
        return;
    snd_note_duration--;
    if (snd_note_duration) {
        // Note still playing — apply frequency slide
        uint16_t freq = snd_frequency;
        freq += snd_freq_slide;
        snd_frequency = freq;
        // Apply vibrato envelope
        uint8_t vib = snd_vibrato_type;
        if (vib) {
            uint16_t phase = snd_vibrato_phase;
            snd_vibrato_phase++;
            phase &= 0x0f;
            snd_computed_freq = vibrato_data[snd_vibrato_idx][phase];
        } else {
            snd_computed_freq = 0x0000;
        }
        snd_computed_freq += freq;
        uint16_t out_freq = snd_computed_freq;
        out8(0x42, out_freq & 0xff);
        out8(0x42, out_freq >> 8);
        return;
    }
    // Current note finished — check for queued sounds
    if (!sound_ctrl) {
        shutdown_sound();
        return;
    }
    uint8_t next = sound_flag_2;
    if (!next) {
        shutdown_sound();
        return;
    }
    sound_flag_1 = next;
    sound_flag_2 = sound_flag_3;
    sound_flag_3 = 0x00;
    update_sound_channel(next);
}
void music_sequencer_tick() // 1000:39db — advances intro music by one step every 8 timer ticks
{
    snd_tick_divider--;
    if ((char)snd_tick_divider >= 0)
        return;
    snd_tick_divider = 0x07; // reset tick divider (every 8 ticks)
    snd_duration = 0x0e; // set sound duration
    snd_envelope = 0x04; // set sound envelope type
    uint16_t pos = snd_music_pos; // music position index
    uint8_t note = snd_music_table[pos];  // fetch next note byte
    if (note == 0xff) { // end of music
        music_playing = 0x00;
        return;
    }
    if (note) {
        if (note == 0xfe) { // rest/silence
            note = 0x00;
        } else {
            note += 0x0c; // transpose up one octave
        }
    } else {
        // Note value 0: play ambient sound based on position
        if (!sound_flag_1) {
            snd_envelope = 0x00;
            snd_duration = 0x06;
            note = ambient_note_table[pos & 0x1f]; // lookup ambient note table
            note -= 0x0c;
        } else {
            note = 0x00;
        }
    }
    play_music_note(note);
    snd_music_pos++;
}
void play_music_note(uint8_t note) // 1000:3a3b — plays a music note: note = note index (1-based)
{
    note--;
    if ((int8_t)note < 0)
        return;
    uint16_t freq = note_freq_tbl[note];
    snd_note_freq = freq;
    sound_flag_1 = 0x0f;
    update_sound_channel(0x0f);
}
