// Sectio7ns of icytower.exe:
//  - .text: 401000 .. 40d000
//  - .rdata: 40d000 .. 40e000
//  - .data: 40e000 .. 42d194
//  - .rsrc: 42e000 .. 4333b6

//#include "alleg40.h"
//#include "kernel32.h"

//void sub_406e7d();

function init()
{
    loadOverlay("icytower_text.bin", 0x401000);
    loadOverlay("icytower_rdata.bin", 0x40d000);
    loadOverlay("icytower_data.bin", 0x40e000);
    loadOverlay("icytower_rsrc.bin", 0x42e000);
    r32[esp] = 0x434000;
    r32[ebp] = 0x434000;
    fs = 9999;
    ss = ds = cs = es = 0;
    alleg40.init();
}

function* start()
{
    yield* sub_406e7d();
}

const ptr_imports = [
    "begin",
    "kernel32_CloseHandle",
    "kernel32_FlushFileBuffers",
    "kernel32_SetStdHandle",
    "kernel32_LCMapStringW",
    "kernel32_LCMapStringA",
    "kernel32_GetStringTypeW",
    "kernel32_GetStringTypeA",
    "kernel32_MultiByteToWideChar",
    "kernel32_LoadLibraryA",
    "kernel32_GetOEMCP",
    "kernel32_GetACP",
    "kernel32_GetCPInfo",
    "kernel32_SetFilePointer",
    "kernel32_GetLastError",
    "kernel32_WriteFile",
    "kernel32_RtlUnwind",
    "kernel32_GetFileType",
    "kernel32_GetStdHandle",
    "kernel32_SetHandleCount",
    "kernel32_GetEnvironmentStringsW",
    "kernel32_GetEnvironmentStrings",
    "kernel32_WideCharToMultiByte",
    "kernel32_FreeEnvironmentStringsW",
    "kernel32_FreeEnvironmentStringsA",
    "kernel32_GetModuleFileNameA",
    "kernel32_UnhandledExceptionFilter",
    "kernel32_GetProcAddress",
    "kernel32_HeapSize",
    "kernel32_HeapReAlloc",
    "kernel32_VirtualAlloc",
    "kernel32_VirtualFree",
    "kernel32_HeapCreate",
    "kernel32_HeapDestroy",
    "kernel32_GetVersion",
    "kernel32_GetCommandLineA",
    "kernel32_GetStartupInfoA",
    "kernel32_GetModuleHandleA",
    "kernel32_GetCurrentProcess",
    "kernel32_TerminateProcess",
    "kernel32_ExitProcess",
    "kernel32_HeapFree",
    "kernel32_HeapAlloc",
    "alleg40_textprintf_centre",
    "alleg40_fade_out",
    "alleg40_readkey",
    "alleg40_save_pcx",
    "alleg40_keypressed",
    "alleg40_clear_keybuf",
    "alleg40_textout_centre",
    "alleg40_stop_sample",
    "alleg40_adjust_sample",
    "alleg40_fade_in",
    "alleg40_font",
    "alleg40_clear_bitmap",
    "alleg40_color_map",
    "alleg40_drawing_mode",
    "alleg40_textout",
    "alleg40_black_palette",
    "alleg40__WinMain",
    "alleg40_text_length",
    "alleg40_set_clip",
    "alleg40_install_int",
    "alleg40_install_timer",
    "alleg40_get_palette_range",
    "alleg40_set_palette_range",
    "alleg40_screen",
    "alleg40_stretch_sprite",
    "alleg40_allegro_errno",
    "alleg40__cos_tbl",
    "alleg40_blit",
    "alleg40_destroy_sample",
    "alleg40_unload_datafile",
    "alleg40_destroy_bitmap",
    "alleg40_allegro_exit",
    "alleg40_install_allegro",
    "alleg40_install_keyboard",
    "alleg40_install_sound",
    "alleg40_install_joystick",
    "alleg40_create_bitmap",
    "alleg40_allegro_message",
    "alleg40_load_datafile",
    "alleg40_pack_fopen",
    "alleg40_pack_fclose",
    "alleg40_create_rgb_table",
    "alleg40_rgb_map",
    "alleg40_create_light_table",
    "alleg40_set_color_depth",
    "alleg40_set_gfx_mode",
    "alleg40_exists",
    "alleg40_set_display_switch_mode",
    "alleg40_text_mode",
    "alleg40_load_wav",
    "alleg40_play_sample",
    "alleg40_get_palette",
    "alleg40_desktop_palette",
    "alleg40_set_palette",
    "alleg40_alert",
    "alleg40_text_height",
    "alleg40_textprintf",
    "alleg40_textprintf_right",
    "alleg40_pack_fread",
    "alleg40_pack_fwrite",
    "alleg40_poll_joystick",
    "alleg40_joy",
    "alleg40_key",
    "alleg40_masked_blit",
    "alleg40_solid_mode"
];

const ptr = Object.freeze(
  Object.fromEntries(ptr_imports.map((n, i) => [n, 0x6ab00000 + i]))
);

function* indirectCall(s, o) {
    switch (o)
    {
        case 0x6ab10003:
            alleg40.vtable_draw_256_sprite(stack32(0), stack32(1), stack32(2), stack32(3));
            return;
        case 0x6ab10004:
            alleg40.pivot_scaled_sprite_flip(stack32(0), stack32(1), stack32(2), stack32(3),
                stack32(4), stack32(5), stack32(6), stack32(7), stack32(8));
            return;
        case 0x6ab10005:
            alleg40.vtable_line(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
            return;
        case 0x6ab10006:
            alleg40.vtable_rectfill(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
            return;
        case 0x6ab10007:
            alleg40.vtable_acquire(stack32(0));
            return;
        case 0x6ab10008:
            alleg40.vtable_release(stack32(0));
            yield* sync();
            return;
        case 0x6ab1000c:
            alleg40.vtable_draw_256_sprite_hflip(stack32(0), stack32(1), stack32(2), stack32(3));
            return;
    }

    switch (o) {
        case ptr.kernel32_CloseHandle:
            r32[eax] = kernel32.CloseHandle(stack32(0)); r32[esp] += 4;
            break; // 6ab00001
        case ptr.kernel32_FlushFileBuffers:
            r32[eax] = kernel32.FlushFileBuffers(stack32(0)); r32[esp] += 4;
            break; // 6ab00002
        case ptr.kernel32_SetStdHandle:
            r32[eax] = kernel32.SetStdHandle(stack32(0), stack32(1)); r32[esp] += 8;
            break; // 6ab00003
        case ptr.kernel32_LCMapStringW:
            r32[eax] = kernel32.LCMapStringW(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
            break; // 6ab00004
        case ptr.kernel32_LCMapStringA:
            r32[eax] = kernel32.LCMapStringA(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
            break; // 6ab00005
        case ptr.kernel32_GetStringTypeW:
            r32[eax] = kernel32.GetStringTypeW(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
            break; // 6ab00006
        case ptr.kernel32_GetStringTypeA:
            r32[eax] = kernel32.GetStringTypeA(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4)); r32[esp] += 20;
            break; // 6ab00007
        case ptr.kernel32_MultiByteToWideChar:
            r32[eax] = kernel32.MultiByteToWideChar(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
            break; // 6ab00008
        case ptr.kernel32_LoadLibraryA:
            r32[eax] = kernel32.LoadLibraryA(stack32(0)); r32[esp] += 4;
            break; // 6ab00009
        case ptr.kernel32_GetOEMCP:
            r32[eax] = kernel32.GetOEMCP();
            break; // 6ab0000a
        case ptr.kernel32_GetACP:
            r32[eax] = kernel32.GetACP();
            break; // 6ab0000b
        case ptr.kernel32_GetCPInfo:
            r32[eax] = kernel32.GetCPInfo(stack32(0), stack32(1)); r32[esp] += 8;
            break; // 6ab0000c
        case ptr.kernel32_SetFilePointer:
            r32[eax] = kernel32.SetFilePointer(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
            break; // 6ab0000d
        case ptr.kernel32_GetLastError:
            r32[eax] = kernel32.GetLastError();
            break; // 6ab0000e
        case ptr.kernel32_WriteFile:
            r32[eax] = kernel32.WriteFile(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4)); r32[esp] += 20;
            break; // 6ab0000f
        case ptr.kernel32_RtlUnwind:
            kernel32.RtlUnwind(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
            break; // 6ab00010
        case ptr.kernel32_GetFileType:
            r32[eax] = kernel32.GetFileType(stack32(0)); r32[esp] += 4;
            break; // 6ab00011
        case ptr.kernel32_GetStdHandle:
            r32[eax] = kernel32.GetStdHandle(stack32(0)); r32[esp] += 4;
            break; // 6ab00012
        case ptr.kernel32_SetHandleCount:
            r32[eax] = kernel32.SetHandleCount(stack32(0)); r32[esp] += 4;
            break; // 6ab00013
        case ptr.kernel32_GetEnvironmentStringsW:
            r32[eax] = kernel32.GetEnvironmentStringsW();
            break; // 6ab00014
        case ptr.kernel32_GetEnvironmentStrings:
            r32[eax] = kernel32.GetEnvironmentStrings();
            break; // 6ab00015
        case ptr.kernel32_WideCharToMultiByte:
            r32[eax] = kernel32.WideCharToMultiByte(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7)); r32[esp] += 32;
            break; // 6ab00016
        case ptr.kernel32_FreeEnvironmentStringsW:
            r32[eax] = kernel32.FreeEnvironmentStringsW(stack32(0)); r32[esp] += 4;
            break; // 6ab00017
        case ptr.kernel32_FreeEnvironmentStringsA:
            r32[eax] = kernel32.FreeEnvironmentStringsA(stack32(0)); r32[esp] += 4;
            break; // 6ab00018
        case ptr.kernel32_GetModuleFileNameA:
            r32[eax] = kernel32.GetModuleFileNameA(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
            break; // 6ab00019
        case ptr.kernel32_UnhandledExceptionFilter:
            r32[eax] = kernel32.UnhandledExceptionFilter(stack32(0)); r32[esp] += 4;
            break; // 6ab0001a
        case ptr.kernel32_GetProcAddress:
            r32[eax] = kernel32.GetProcAddress(stack32(0), stack32(1)); r32[esp] += 8;
            break; // 6ab0001b
        case ptr.kernel32_HeapSize:
            r32[eax] = kernel32.HeapSize(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
            break; // 6ab0001c
        case ptr.kernel32_HeapReAlloc:
            r32[eax] = kernel32.HeapReAlloc(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
            break; // 6ab0001d
        case ptr.kernel32_VirtualAlloc:
            r32[eax] = kernel32.VirtualAlloc(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
            break; // 6ab0001e
        case ptr.kernel32_VirtualFree:
            r32[eax] = kernel32.VirtualFree(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
            break; // 6ab0001f
        case ptr.kernel32_HeapCreate:
            r32[eax] = kernel32.HeapCreate(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
            break; // 6ab00020
        case ptr.kernel32_HeapDestroy:
            r32[eax] = kernel32.HeapDestroy(stack32(0)); r32[esp] += 4;
            break; // 6ab00021
        case ptr.kernel32_GetVersion:
            r32[eax] = kernel32.GetVersion();
            break; // 6ab00022
        case ptr.kernel32_GetCommandLineA:
            r32[eax] = kernel32.GetCommandLineA();
            break; // 6ab00023
        case ptr.kernel32_GetStartupInfoA:
            kernel32.GetStartupInfoA(stack32(0)); r32[esp] += 4;
            break; // 6ab00024
        case ptr.kernel32_GetModuleHandleA:
            r32[eax] = kernel32.GetModuleHandleA(stack32(0)); r32[esp] += 4;
            break; // 6ab00025
        case ptr.kernel32_GetCurrentProcess:
            r32[eax] = kernel32.GetCurrentProcess();
            break; // 6ab00026
        case ptr.kernel32_TerminateProcess:
            r32[eax] = kernel32.TerminateProcess(stack32(0), stack32(1)); r32[esp] += 8;
            break; // 6ab00027
        case ptr.kernel32_ExitProcess:
            kernel32.ExitProcess(stack32(0)); r32[esp] += 4;
            break; // 6ab00028
        case ptr.kernel32_HeapFree:
            r32[eax] = kernel32.HeapFree(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
            break; // 6ab00029
        case ptr.kernel32_HeapAlloc:
            r32[eax] = kernel32.HeapAlloc(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
            break; // 6ab0002a
        case ptr.alleg40_textprintf_centre:
            alleg40.textprintf_centre(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
            break; // 6ab0002b
        case ptr.alleg40_fade_out:
            alleg40.fade_out(stack32(0));
            break; // 6ab0002c
        case ptr.alleg40_readkey:
            r32[eax] = alleg40.readkey();
            break; // 6ab0002d
        case ptr.alleg40_save_pcx:
            alleg40.save_pcx(stack32(0), stack32(1), stack32(2));
            break; // 6ab0002e
        case ptr.alleg40_keypressed:
            r32[eax] = alleg40.keypressed();
            break; // 6ab0002f
        case ptr.alleg40_clear_keybuf:
            alleg40.clear_keybuf();
            break; // 6ab00030
        case ptr.alleg40_textout_centre:
            alleg40.textout_centre(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
            break; // 6ab00031
        case ptr.alleg40_stop_sample:
            alleg40.stop_sample(stack32(0));
            break; // 6ab00032
        case ptr.alleg40_adjust_sample:
            alleg40.adjust_sample(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
            break; // 6ab00033
        case ptr.alleg40_fade_in:
            alleg40.fade_in(stack32(0), stack32(1));
            break; // 6ab00034
        case ptr.alleg40_font:
            stop("invalid decl");
            break; // 6ab00035
        case ptr.alleg40_clear_bitmap:
            alleg40.clear_bitmap(stack32(0));
            break; // 6ab00036
        case ptr.alleg40_color_map:
            stop("invalid decl");
            break; // 6ab00037
        case ptr.alleg40_drawing_mode:
            alleg40.drawing_mode(stack32(0), stack32(1), stack32(2), stack32(3));
            break; // 6ab00038
        case ptr.alleg40_textout:
            alleg40.textout(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
            break; // 6ab00039
        case ptr.alleg40_black_palette:
            stop("invalid decl");
            break; // 6ab0003a
        case ptr.alleg40__WinMain:
            r32[eax] = alleg40._WinMain(stack32(0), stack32(1), stack32(2), stack32(3));
            break; // 6ab0003b
        case ptr.alleg40_text_length:
            r32[eax] = alleg40.text_length(stack32(0), stack32(1));
            break; // 6ab0003c
        case ptr.alleg40_set_clip:
            alleg40.set_clip(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
            break; // 6ab0003d
        case ptr.alleg40_install_int:
            alleg40.install_int(stack32(0), stack32(1));
            break; // 6ab0003e
        case ptr.alleg40_install_timer:
            alleg40.install_timer();
            break; // 6ab0003f
        case ptr.alleg40_get_palette_range:
            alleg40.get_palette_range(stack32(0), stack32(1), stack32(2), stack32(3));
            break; // 6ab00040
        case ptr.alleg40_set_palette_range:
            alleg40.set_palette_range(stack32(0), stack32(1), stack32(2), stack32(3));
            break; // 6ab00041
        case ptr.alleg40_screen:
            stop("invalid decl");
            break; // 6ab00042
        case ptr.alleg40_stretch_sprite:
            alleg40.stretch_sprite(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
            break; // 6ab00043
        case ptr.alleg40_allegro_errno:
            stop("invalid decl");
            break; // 6ab00044
        case ptr.alleg40__cos_tbl:
            stop("invalid decl");
            break; // 6ab00045
        case ptr.alleg40_blit:
            alleg40.blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
            break; // 6ab00046
        case ptr.alleg40_destroy_sample:
            alleg40.destroy_sample(stack32(0));
            break; // 6ab00047
        case ptr.alleg40_unload_datafile:
            alleg40.unload_datafile(stack32(0));
            break; // 6ab00048
        case ptr.alleg40_destroy_bitmap:
            alleg40.destroy_bitmap(stack32(0));
            break; // 6ab00049
        case ptr.alleg40_allegro_exit:
            alleg40.allegro_exit();
            break; // 6ab0004a
        case ptr.alleg40_install_allegro:
            r32[eax] = alleg40.install_allegro(stack32(0), stack32(1), stack32(2));
            break; // 6ab0004b
        case ptr.alleg40_install_keyboard:
            alleg40.install_keyboard();
            break; // 6ab0004c
        case ptr.alleg40_install_sound:
            r32[eax] = alleg40.install_sound(stack32(0), stack32(1), stack32(2));
            break; // 6ab0004d
        case ptr.alleg40_install_joystick:
            alleg40.install_joystick(stack32(0));
            break; // 6ab0004e
        case ptr.alleg40_create_bitmap:
            r32[eax] = alleg40.create_bitmap(stack32(0), stack32(1));
            break; // 6ab0004f
        case ptr.alleg40_allegro_message:
            alleg40.allegro_message(stack32(0));
            break; // 6ab00050
        case ptr.alleg40_load_datafile:
            r32[eax] = alleg40.load_datafile(stack32(0));
            break; // 6ab00051
        case ptr.alleg40_pack_fopen:
            r32[eax] = alleg40.pack_fopen(stack32(0), stack32(1));
            break; // 6ab00052
        case ptr.alleg40_pack_fclose:
            r32[eax] = alleg40.pack_fclose(stack32(0));
            break; // 6ab00053
        case ptr.alleg40_create_rgb_table:
            alleg40.create_rgb_table(stack32(0), stack32(1), stack32(2));
            break; // 6ab00054
        case ptr.alleg40_rgb_map:
            stop("invalid decl");
            break; // 6ab00055
        case ptr.alleg40_create_light_table:
            alleg40.create_light_table(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
            break; // 6ab00056
        case ptr.alleg40_set_color_depth:
            alleg40.set_color_depth(stack32(0));
            break; // 6ab00057
        case ptr.alleg40_set_gfx_mode:
            r32[eax] = alleg40.set_gfx_mode(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
            break; // 6ab00058
        case ptr.alleg40_exists:
            r32[eax] = alleg40.exists(stack32(0));
            break; // 6ab00059
        case ptr.alleg40_set_display_switch_mode:
            r32[eax] = alleg40.set_display_switch_mode(stack32(0));
            break; // 6ab0005a
        case ptr.alleg40_text_mode:
            alleg40.text_mode(stack32(0));
            break; // 6ab0005b
        case ptr.alleg40_load_wav:
            r32[eax] = alleg40.load_wav(stack32(0));
            break; // 6ab0005c
        case ptr.alleg40_play_sample:
            r32[eax] = alleg40.play_sample(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
            break; // 6ab0005d
        case ptr.alleg40_get_palette:
            alleg40.get_palette(stack32(0));
            break; // 6ab0005e
        case ptr.alleg40_desktop_palette:
            stop("invalid decl");
            break; // 6ab0005f
        case ptr.alleg40_set_palette:
            alleg40.set_palette(stack32(0));
            break; // 6ab00060
        case ptr.alleg40_alert:
            alleg40.alert(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6));
            break; // 6ab00061
        case ptr.alleg40_text_height:
            r32[eax] = alleg40.text_height(stack32(0));
            break; // 6ab00062
        case ptr.alleg40_textprintf:
            alleg40.textprintf(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
            break; // 6ab00063
        case ptr.alleg40_textprintf_right:
            alleg40.textprintf_right(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
            break; // 6ab00064
        case ptr.alleg40_pack_fread:
            r32[eax] = alleg40.pack_fread(stack32(0), stack32(1), stack32(2));
            break; // 6ab00065
        case ptr.alleg40_pack_fwrite:
            r32[eax] = alleg40.pack_fwrite(stack32(0), stack32(1), stack32(2));
            break; // 6ab00066
        case ptr.alleg40_poll_joystick:
            r32[eax] = alleg40.poll_joystick();
            break; // 6ab00067
        case ptr.alleg40_joy:
            stop("invalid decl");
            break; // 6ab00068
        case ptr.alleg40_key:
            stop("invalid decl");
            break; // 6ab00069
        case ptr.alleg40_masked_blit:
            alleg40.masked_blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
            break; // 6ab0006a
        case ptr.alleg40_solid_mode:
            alleg40.solid_mode();
            break; // 6ab0006b
        default:
            console.log("indirect", o.toString(16))
            stop();
    }
}

function* sub_401000() // 0000:401000 +long
{
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(0x0000004b);
    push32(0x00000053);
    push32(0x00000052);
    push32(0x00000055);
    push32(0x00000054);
    push32(r32[esi]);
    yield* sub_401030();
    r32[esp] += 0x00000018;
    memoryASet32(ds, r32[esi] + 0x18, 0x00000043);
    memoryASet32(ds, r32[esi] + 0x1c, 0x00000000);
    memoryASet32(ds, r32[esi], 0x00000000);
    r32[esi] = pop32();
    r32[esp] += 4;
}
function* sub_401030() // 0000:401030 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet32(ds, r32[eax] + 0xc, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
    memoryASet32(ds, r32[eax] + 0x10, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    memoryASet32(ds, r32[eax] + 0x4, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    memoryASet32(ds, r32[eax] + 0x8, r32[edx]);
    memoryASet32(ds, r32[eax] + 0x14, r32[ecx]);
    r32[esp] += 4;
}
function* sub_401060() // 0000:401060 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, r32[esi]);
    memoryASet32(ds, r32[esi] + 0x1c, 0x00000000);
    if (!r32[eax])
        { pc = 0x4010e2; break; }
    r32[eax] = alleg40.poll_joystick();
    r32[eax] = memoryAGet32(ds, 0x40d1a0);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x28);
    if (!r32[ecx])
        { pc = 0x40108c; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x04;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x40108c: // 0000:40108c
    r32[ecx] = memoryAGet32(ds, 0x40d1a0);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x2c);
    if (!r32[eax])
        { pc = 0x4010a1; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x08;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x4010a1: // 0000:4010a1
    r32[edx] = memoryAGet32(ds, 0x40d1a0);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x18);
    if (!r32[eax])
        { pc = 0x4010b6; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x01;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x4010b6: // 0000:4010b6
    r32[eax] = memoryAGet32(ds, 0x40d1a0);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x1c);
    if (!r32[ecx])
        { pc = 0x4010ca; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x02;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x4010ca: // 0000:4010ca
    r32[ecx] = memoryAGet32(ds, 0x40d1a0);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x138);
    if (!r32[eax])
        { pc = 0x4010e2; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x10;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x4010e2: // 0000:4010e2
    r32[edx] = memoryAGet32(ds, r32[esi] + 0xc);
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, r32[edx] + r32[eax]))
        { pc = 0x4010f8; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x04;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x4010f8: // 0000:4010f8
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x10);
    r32[edx] = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, r32[ecx] + r32[edx]))
        { pc = 0x40110f; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x08;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x40110f: // 0000:40110f
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[ecx] = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, r32[eax] + r32[ecx]))
        { pc = 0x401126; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x01;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x401126: // 0000:401126
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, r32[edx] + r32[eax]))
        { pc = 0x40113c; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x02;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x40113c: // 0000:40113c
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x14);
    r32[edx] = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, r32[ecx] + r32[edx]))
        { pc = 0x401153; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x10;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x401153: // 0000:401153
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x18);
    r32[ecx] = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, r32[eax] + r32[ecx]))
        { pc = 0x40116a; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r8[al] |= 0x20;
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
  case 0x40116a: // 0000:40116a
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_401170() // 0000:401170 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    if (r32[eax] != memoryAGet32(ds, r32[ecx] + 0x4))
        { pc = 0x401181; break; }
    r32[eax] |= 0xffffffff;
    r32[esp] += 4; return;
  case 0x401181: // 0000:401181
    if (r32[eax] != memoryAGet32(ds, r32[ecx] + 0x8))
        { pc = 0x40118a; break; }
    r32[eax] |= 0xffffffff;
    r32[esp] += 4; return;
  case 0x40118a: // 0000:40118a
    if (r32[eax] != memoryAGet32(ds, r32[ecx] + 0xc))
        { pc = 0x401193; break; }
    r32[eax] |= 0xffffffff;
    r32[esp] += 4; return;
  case 0x401193: // 0000:401193
    if (r32[eax] != memoryAGet32(ds, r32[ecx] + 0x10))
        { pc = 0x40119c; break; }
    r32[eax] |= 0xffffffff;
    r32[esp] += 4; return;
  case 0x40119c: // 0000:40119c
    if (r32[eax] != memoryAGet32(ds, r32[ecx] + 0x14))
        { pc = 0x4011a5; break; }
    r32[eax] |= 0xffffffff;
    r32[esp] += 4; return;
  case 0x4011a5: // 0000:4011a5
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x18);
    r32[edx] = 0;
    r8[dl] = r32[eax] != r32[esi];
    r32[edx]--;
    r32[esi] = pop32();
    r32[eax] = r32[edx];
    r32[esp] += 4;
    return;
  }
}
function* sub_4011c0() // 0000:4011c0 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x1c);
    r8[al] &= 0x04;
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esp] += 4;
}
function* sub_4011d0() // 0000:4011d0 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x1c);
    r8[al] &= 0x08;
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esp] += 4;
}
function* sub_4011e0() // 0000:4011e0 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x1c);
    r8[al] &= 0x01;
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esp] += 4;
}
function* sub_4011f0() // 0000:4011f0 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x1c);
    r8[al] &= 0x02;
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esp] += 4;
}
function* sub_401200() // 0000:401200 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x1c);
    r8[al] &= 0x10;
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esp] += 4;
}
function* sub_401210() // 0000:401210 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x1c);
    r8[al] &= 0x20;
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esp] += 4;
}
function* sub_401220() // 0000:401220 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x1c);
    flags.carry = r32[eax] != 0;
    r32[eax] = -r32[eax];
    r32[eax] = -flags.carry;
    r32[esp] += 4;
}
function* sub_401230() // 0000:401230 +long
{
    r32[esp] -= 4;
    push32(0x00000050);
    yield* sub_406b40();
    r32[esp] += 0x00000004;
    r32[esp] += 4;
}
function* sub_401240() // 0000:401240 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[eax]);
    yield* sub_406bb4();
    r32[ecx] = pop32();
    r32[esp] += 4;
}
function* sub_401250() // 0000:401250 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x10);
    if (!r32[edx])
        { pc = 0x40126e; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = 0;
    r32[ecx] += 0x00000008;
  case 0x401261: // 0000:401261
    if (r32[edx] >= memoryAGet32(ds, r32[ecx]))
        { pc = 0x401271; break; }
    r32[eax]++;
    r32[ecx] += 0x00000010;
    if (r32s[eax] < signed32(0x00000005))
        { pc = 0x401261; break; }
  case 0x40126e: // 0000:40126e
    r32[eax] = 0;
    r32[esp] += 4; return;
  case 0x401271: // 0000:401271
    r32[eax] = 0x00000001;
    r32[esp] += 4;
    return;
  }
}
function* sub_401280() // 0000:401280 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x00000014;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[esi]);
    r32[ecx] = r32[eax] + 16;
    push32(r32[edi]);
    r32[edx] = 0x00000001;
    memoryASet32(ds, r32[esp] + 0x10, r32[ecx]);
  case 0x401297: // 0000:401297
    r32[edi] = r32[ecx];
    r32[eax] = r32[edx];
    r32[esi] = memoryAGet32(ds, r32[edi]);
    memoryASet32(ds, r32[esp] + 0x14, r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[edi] + 0x4);
    memoryASet32(ds, r32[esp] + 0x18, r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[edi] + 0x8);
    r32[edi] = memoryAGet32(ds, r32[edi] + 0xc);
    memoryASet32(ds, r32[esp] + 0x20, r32[edi]);
    if (!r32[edx])
        { pc = 0x4012e1; break; }
    r32[ecx] += 0xfffffff0;
  case 0x4012b9: // 0000:4012b9
    if (r32[esi] <= memoryAGet32(ds, r32[ecx] + 0x8))
        { pc = 0x4012e1; break; }
    r32[ebx] = r32[ecx];
    r32[edi] = r32[ecx] + 16;
    r32[eax]--;
    r32[ecx] -= 0x00000010;
    r32[ebp] = memoryAGet32(ds, r32[ebx]);
    memoryASet32(ds, r32[edi], r32[ebp]);
    r32[ebp] = memoryAGet32(ds, r32[ebx] + 0x4);
    memoryASet32(ds, r32[edi] + 0x4, r32[ebp]);
    r32[ebp] = memoryAGet32(ds, r32[ebx] + 0x8);
    memoryASet32(ds, r32[edi] + 0x8, r32[ebp]);
    r32[ebx] = memoryAGet32(ds, r32[ebx] + 0xc);
    memoryASet32(ds, r32[edi] + 0xc, r32[ebx]);
    if (r32[eax])
        { pc = 0x4012b9; break; }
  case 0x4012e1: // 0000:4012e1
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x28);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] <<= 4;
    r32[eax] += r32[ebx];
    r32[edx]++;
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    memoryASet32(ds, r32[eax] + 0x4, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[eax] + 0x8, r32[esi]);
    memoryASet32(ds, r32[eax] + 0xc, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[ecx] += 0x00000010;
    memoryASet32(ds, r32[esp] + 0x10, r32[ecx]);
    if (r32s[edx] < signed32(0x00000005))
        { pc = 0x401297; break; }
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000014;
    r32[esp] += 4;
    return;
  }
}
function* sub_401320() // 0000:401320 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edx] |= 0xffffffff;
    r32[edi] = 0x00989680;
    r32[eax] = 0;
    r32[esi] = r32[ebx] + 8;
  case 0x401334: // 0000:401334
    r32[ecx] = memoryAGet32(ds, r32[esi]);
    if (r32[ecx] >= r32[edi])
        { pc = 0x40133e; break; }
    r32[edx] = r32[eax];
    r32[edi] = r32[ecx];
  case 0x40133e: // 0000:40133e
    r32[eax]++;
    r32[esi] += 0x00000010;
    if (r32s[eax] < signed32(0x00000005))
        { pc = 0x401334; break; }
    if (r32s[edx] < 0)
        { pc = 0x40136b; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[edx] <<= 4;
    r32[edx] += r32[ebx];
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[edx] + 0x8, r32[eax]);
    memoryASet32(ds, r32[edx] + 0xc, r32[ecx]);
  case 0x40136b: // 0000:40136b
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_401370() // 0000:401370 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x14);
    push32(r32[ebp]);
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[ecx] = r32[ebp];
    r32[eax] = 0x66666667;
    r32[ecx] -= r32[ebx];
    push32(r32[esi]);
    imul32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[edi]);
    r32[edx] = sar32(r32[edx], 0x00000001);
    r32[eax] = r32[edx];
    r32[ebx] = r32[ecx] + 12;
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    memoryASet32(ds, r32[esp] + 0x1c, 0x00000005);
    memoryASet32(ds, r32[esp] + 0x20, r32[edx]);
  case 0x4013a3: // 0000:4013a3
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[ecx] |= 0xffffffff;
    r32[eax] = 0;
    r32[edx] = r32[ebx] - 12;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = ~r32[ecx];
    r32[edi] -= r32[ecx];
    r32[eax] = r32[ecx];
    r32[esi] = r32[edi];
    r32[edi] = r32[edx];
    r32[ecx] >>= 2;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    r32[ecx] = r32[eax];
    r32[ecx] &= 0x00000003;
    for (; r32[ecx] != 0; --r32[ecx]) movsb_ESEDI_DSESI();
    memoryASet32(ds, r32[ebx] - 4, r32[ebp]);
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000007;
    r32[ebx] += 0x00000010;
    idiv32(r32[ecx]);
    r32[eax] = 0x66666667;
    r32[ecx] = r32[edx];
    imul32(r32[ebp]);
    r32[edx] = sar32(r32[edx], 0x03);
    r32[eax] = r32[edx];
    r32[edx] += r32[ecx];
    r32[eax] >>= 31;
    r32[eax] += r32[edx];
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x20);
    memoryASet32(ds, r32[ebx] - 16, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[ebp] -= r32[edx];
    r32[eax]--;
    memoryASet32(ds, r32[esp] + 0x1c, r32[eax]);
    if (r32[eax])
        { pc = 0x4013a3; break; }
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_401410() // 0000:401410 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[eax]);
    push32(0x00000050);
    push32(r32[ecx]);
    r32[eax] = alleg40.pack_fread(stack32(0), stack32(1), stack32(2));
    r32[esp] += 0x0000000c;
    r32[eax] = 0x00000001;
    r32[esp] += 4;
}
function* sub_401430() // 0000:401430 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[eax]);
    push32(0x00000050);
    push32(r32[ecx]);
    r32[eax] = alleg40.pack_fwrite(stack32(0), stack32(1), stack32(2));
    r32[esp] += 0x0000000c;
    r32[esp] += 4;
}
function* sub_401450() // 0000:401450 +long
{
    r32[esp] -= 4;
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x14);
    push32(r32[ebp]);
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x24);
    push32(r32[esi]);
    push32(0x0040e034);
    push32(0xffffffff);
    push32(r32[edi]);
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[eax]);
    alleg40.textprintf(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xc);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x34);
    push32(r32[ecx]);
    push32(0x0040e030);
    push32(0xffffffff);
    r32[edx] = r32[ebx] + 100;
    push32(r32[edi]);
    push32(r32[edx]);
    push32(r32[ebp]);
    push32(r32[eax]);
    alleg40.textprintf_right(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x8);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    push32(r32[ecx]);
    push32(0x0040e030);
    push32(0xffffffff);
    r32[ebx] += 0x000000c8;
    push32(r32[edi]);
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[edx]);
    alleg40.textprintf_right(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[esp] += 0x00000054;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4;
}
function* sub_4014c0() // 0000:4014c0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[ebp]);
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[esi] = 0;
  case 0x4014d2: // 0000:4014d2
    push32(r32[edi]);
    r32[esi]++;
    r32[eax] = alleg40.text_height(stack32(0));
    r32[eax] -= 0x00000005;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = r32s[eax] * r32s[esi];
    r32[eax] += r32[ebp];
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x28);
    push32(r32[eax]);
    push32(r32[edi]);
    push32(r32[ecx]);
    push32(r32[ebx]);
    yield* sub_401450();
    r32[esp] += 0x00000018;
    r32[ebx] += 0x00000010;
    if (r32s[esi] < signed32(0x00000005))
        { pc = 0x4014d2; break; }
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_401510() // 0000:401510 +long
{
    r32[esp] -= 4;
    r32[esp] -= 0x00000400;
    r32[eax] = r32[esp];
    push32(r32[esi]);
    push32(r32[eax]);
    alleg40.get_palette(stack32(0));
    r32[ecx] = memoryAGet32(ds, 0x40d17c);
    r32[esi] = memoryAGet32(ds, 0x40d180);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x414);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x410);
    push32(0x0000001b);
    push32(0x0000000d);
    push32(0x0040e74c);
    push32(0x0040e740);
    push32(r32[edx]);
    push32(r32[eax]);
    push32(0x0040e738);
    alleg40.alert(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6));
    r32[ecx] = r32[esp] + 40;
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000028;
    r32[esi] = pop32();
    r32[esp] += 0x00000400;
    r32[esp] += 4;
}
function* sub_401570() // 0000:401570 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x8);
    if (!r32[esi])
        { pc = 0x4015cd; break; }
    r32[eax] = memoryAGet32(ds, 0x40e040);
    if (!r32[eax])
        { pc = 0x4015cd; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    push32(0x00000000);
    if (!r32[ecx])
        { pc = 0x4015b8; break; }
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000190;
    idiv32(r32[ecx]);
    r32[edx] += 0x00000384;
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, 0x40e040);
    push32(0x00000080);
    push32(r32[edx]);
    push32(r32[esi]);
    r32[eax] = alleg40.play_sample(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
    r32[esp] += 0x00000014;
    r32[esi] = pop32();
    r32[esp] += 4; return;
  case 0x4015b8: // 0000:4015b8
    push32(0x000003e8);
    push32(0x00000080);
    push32(r32[eax]);
    push32(r32[esi]);
    r32[eax] = alleg40.play_sample(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
    r32[esp] += 0x00000014;
  case 0x4015cd: // 0000:4015cd
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_4015d0() // 0000:4015d0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0xc);
    push32(r32[esi]);
    r32[eax] = alleg40.load_wav(stack32(0));
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[ecx], r32[eax]);
    if (r32[eax])
        { pc = 0x4015f7; break; }
    push32(r32[esi]);
    push32(0x0040e754);
    yield* sub_401510();
    r32[esp] += 0x00000008;
  case 0x4015f7: // 0000:4015f7
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_401600() // 0000:401600 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    push32(r32[edi]);
    push32(0x00406d70);
    push32(0x0040fab8);
    push32(0x00000000);
    r32[eax] = alleg40.install_allegro(stack32(0), stack32(1), stack32(2));
    alleg40.install_keyboard();
    //yield* sub_406b00();
    push32(0x00000000);
    push32(0xffffffff);
    push32(0x44584120);
    r32[eax] = alleg40.install_sound(stack32(0), stack32(1), stack32(2));
    push32(0xffffffff);
    alleg40.install_joystick(stack32(0));
    r32[esi] = memoryAGet32(ds, 0x40d13c);
    push32(0x000001e0);
    flags.carry = r32[eax] != 0;
    r32[eax] = -r32[eax];
    r32[eax] = -flags.carry;
    push32(0x00000280);
    r32[eax]++;
    memoryASet32(ds, 0x42bbc4, r32[eax]);
    yield* indirectCall(cs, r32[esi]);
    push32(0x00000040);
    push32(0x00000280);
    memoryASet32(ds, 0x40fa34, r32[eax]);
    yield* indirectCall(cs, r32[esi]);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    r32[esp] += 0x0000002c;
    memoryASet32(ds, 0x40fa38, r32[eax]);
    if (!r32[ecx])
        { pc = 0x401c4b; break; }
    if (!r32[eax])
        { pc = 0x401c4b; break; }
    push32(0x000001e0);
    push32(0x00000280);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000008;
    memoryASet32(ds, 0x40fa34, r32[eax]);
    if (r32[eax])
        { pc = 0x4016a9; break; }
    push32(0x0040ea30);
    alleg40.allegro_message(stack32(0));
    r32[esp] += 0x00000004;
    r32[eax] = 0;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 4; return;
  case 0x4016a9: // 0000:4016a9
    yield* sub_401230();
    memoryASet32(ds, 0x40fa3c, r32[eax]);
    if (r32[eax])
        { pc = 0x4016ca; break; }
    push32(0x0040ea04);
    alleg40.allegro_message(stack32(0));
    r32[esp] += 0x00000004;
    r32[eax] = 0;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 4; return;
  case 0x4016ca: // 0000:4016ca
    push32(0x00000000);
    push32(0x000003e8);
    push32(0x0040ea00);
    push32(r32[eax]);
    yield* sub_401370();
    r32[esi] = memoryAGet32(ds, 0x40d144);
    push32(0x0040e9f0);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000014;
    memoryASet32(ds, 0x40fa40, r32[eax]);
    if (r32[eax])
        { pc = 0x401708; break; }
    push32(0x0040e9d4);
    alleg40.allegro_message(stack32(0));
    r32[esp] += 0x00000004;
    r32[eax] = 0;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 4; return;
  case 0x401708: // 0000:401708
    push32(0x0040e9c4);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000004;
    memoryASet32(ds, 0x40fa44, r32[eax]);
    if (r32[eax])
        { pc = 0x4017ce; break; }
    push32(0x0040e9b4);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000004;
    memoryASet32(ds, 0x40fa44, r32[eax]);
    if (r32[eax])
        { pc = 0x40179c; break; }
    push32(0x0040e9a4);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000004;
    memoryASet32(ds, 0x40fa44, r32[eax]);
    if (r32[eax])
        { pc = 0x40176c; break; }
    r32[eax] = memoryAGet32(ds, 0x40e998);
    r32[ecx] = memoryAGet32(ds, 0x40e99c);
    r8[dl] = memoryAGet(ds, 0x40e9a0);
    memoryASet32(ds, 0x42bbe0, r32[eax]);
    memoryASet32(ds, 0x42bbe4, r32[ecx]);
    memoryASet(ds, 0x42bbe8, r8[dl]);
    { pc = 0x4017fe; break; }
  case 0x40176c: // 0000:40176c
    r32[eax] = memoryAGet32(ds, 0x40e98c);
    r32[ecx] = memoryAGet32(ds, 0x40e990);
    r16[dx] = memoryAGet16(ds, 0x40e994);
    memoryASet32(ds, 0x42bbe0, r32[eax]);
    r8[al] = memoryAGet(ds, 0x40e996);
    memoryASet32(ds, 0x42bbe4, r32[ecx]);
    memoryASet16(ds, 0x42bbe8, r16[dx]);
    memoryASet(ds, 0x42bbea, r8[al]);
    { pc = 0x4017fe; break; }
  case 0x40179c: // 0000:40179c
    r32[ecx] = memoryAGet32(ds, 0x40e980);
    r32[edx] = memoryAGet32(ds, 0x40e984);
    r16[ax] = memoryAGet16(ds, 0x40e988);
    memoryASet32(ds, 0x42bbe0, r32[ecx]);
    r8[cl] = memoryAGet(ds, 0x40e98a);
    memoryASet32(ds, 0x42bbe4, r32[edx]);
    memoryASet16(ds, 0x42bbe8, r16[ax]);
    memoryASet(ds, 0x42bbea, r8[cl]);
    { pc = 0x4017fe; break; }
  case 0x4017ce: // 0000:4017ce
    r32[edx] = memoryAGet32(ds, 0x40e974);
    r32[eax] = memoryAGet32(ds, 0x40e978);
    r16[cx] = memoryAGet16(ds, 0x40e97c);
    memoryASet32(ds, 0x42bbe0, r32[edx]);
    r8[dl] = memoryAGet(ds, 0x40e97e);
    memoryASet32(ds, 0x42bbe4, r32[eax]);
    memoryASet16(ds, 0x42bbe8, r16[cx]);
    memoryASet(ds, 0x42bbea, r8[dl]);
  case 0x4017fe: // 0000:4017fe
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    push32(0x0040e970);
    push32(0x0040e964);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    memoryASet(ds, r32[ecx] + 0x2, 0x00);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    memoryASet(ds, r32[eax] + 0x1, 0x00);
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    memoryASet(ds, r32[edx], 0x00);
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x160);
    memoryASet32(ds, 0x413320, r32[ecx]);
    r32[eax] = alleg40.pack_fopen(stack32(0), stack32(1));
    r32[esi] = r32[eax];
    r32[esp] += 0x00000008;
    if (!r32[esi])
        { pc = 0x40186c; break; }
    push32(r32[esi]);
    push32(0x0040e040);
    yield* sub_4064e0();
    r32[edx] = memoryAGet32(ds, 0x40fa3c);
    push32(r32[esi]);
    push32(r32[edx]);
    yield* sub_401410();
    push32(r32[esi]);
    r32[eax] = alleg40.pack_fclose(stack32(0));
    r32[esp] += 0x00000014;
  case 0x40186c: // 0000:40186c
    r32[eax] = memoryAGet32(ds, 0x40e040);
    r32[ecx] = memoryAGet32(ds, 0x40e044);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ds, 0x40e058, r32[eax]);
    memoryASet32(ds, 0x40e068, r32[ecx]);
    push32(0x00000000);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    push32(r32[eax]);
    push32(0x00423bc0);
    alleg40.create_rgb_table(stack32(0), stack32(1), stack32(2));
    r32[ecx] = memoryAGet32(ds, 0x40d154);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    //memoryASet32(ds, r32[ecx], 0x00423bc0);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    push32(0x00000000);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    push32(r32[eax]);
    push32(0x00413340);
    alleg40.create_light_table(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    push32(0x00000008);
    alleg40.set_color_depth(stack32(0));
    r32[eax] = memoryAGet32(ds, 0x40e050);
    r32[esi] = memoryAGet32(ds, 0x40d160);
    r32[edi] = memoryAGet32(ds, 0x40d180);
    r32[esp] += 0x00000028;
    if (r32[eax])
        { pc = 0x40191d; break; }
    push32(0x00000000);
    push32(0x00000000);
    push32(0x000001e0);
    push32(0x00000280);
    push32(0x4458574e);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000014;
    if (r32s[eax] < 0)
        { pc = 0x40194f; break; }
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ds, 0x40e038, 0x00000001);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    yield* indirectCall(cs, r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x40e050);
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x40196e; break; }
  case 0x40191d: // 0000:40191d
    push32(0x00000000);
    push32(0x00000000);
    push32(0x000001e0);
    push32(0x00000280);
    push32(0x00000000);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000014;
    if (r32s[eax] < 0)
        { pc = 0x40195b; break; }
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ds, 0x40e038, 0x00000000);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000004;
    { pc = 0x40196e; break; }
  case 0x40194f: // 0000:40194f
    memoryASet32(ds, 0x40e050, 0xffffffff);
    { pc = 0x40191d; break; }
  case 0x40195b: // 0000:40195b
    push32(0x0040e944);
    alleg40.allegro_message(stack32(0));
    r32[esp] += 0x00000004;
    r32[eax] = 0;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 4; return;
  case 0x40196e: // 0000:40196e
    r32[eax] = memoryAGet32(ds, 0x40fa44);
    if (!r32[eax])
        { pc = 0x401a93; break; }
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x90);
    memoryASet32(ds, 0x40fa48, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x140);
    memoryASet32(ds, 0x40fa4c, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xa0);
    memoryASet32(ds, 0x40fa50, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x170);
    memoryASet32(ds, 0x40fa54, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x10);
    memoryASet32(ds, 0x40fa58, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x60);
    memoryASet32(ds, 0x40fa5c, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x20);
    memoryASet32(ds, 0x40fa60, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x30);
    memoryASet32(ds, 0x40fa64, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xd0);
    memoryASet32(ds, 0x40fa68, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0xe0);
    memoryASet32(ds, 0x40fa6c, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xc0);
    memoryASet32(ds, 0x40fa70, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0xb0);
    memoryASet32(ds, 0x40fa74, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x80);
    memoryASet32(ds, 0x40fa78, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x150);
    memoryASet32(ds, 0x40fa7c, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x180);
    memoryASet32(ds, 0x40fa88, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x160);
    memoryASet32(ds, 0x40fa8c, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ds, 0x40fa90, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x50);
    memoryASet32(ds, 0x40fa94, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x110);
    memoryASet32(ds, 0x40fa98, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x70);
    memoryASet32(ds, 0x40fa9c, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x120);
    memoryASet32(ds, 0x40faa0, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x40);
    memoryASet32(ds, 0x40faa4, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x130);
    memoryASet32(ds, 0x40faa8, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0xf0);
    memoryASet32(ds, 0x40fa80, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x100);
    memoryASet32(ds, 0x40fa84, r32[edx]);
    { pc = 0x401c16; break; }
  case 0x401a93: // 0000:401a93
    push32(0x0040e934);
    push32(0x0040fa48);
    yield* sub_4015d0();
    push32(0x0040e924);
    push32(0x0040fa4c);
    yield* sub_4015d0();
    push32(0x0040e914);
    push32(0x0040fa50);
    yield* sub_4015d0();
    push32(0x0040e908);
    push32(0x0040fa54);
    yield* sub_4015d0();
    push32(0x0040e8f8);
    push32(0x0040fa58);
    yield* sub_4015d0();
    push32(0x0040e8e8);
    push32(0x0040fa5c);
    yield* sub_4015d0();
    push32(0x0040e8d8);
    push32(0x0040fa60);
    yield* sub_4015d0();
    push32(0x0040e8c8);
    push32(0x0040fa64);
    yield* sub_4015d0();
    r32[esp] += 0x00000040;
    push32(0x0040e8b8);
    push32(0x0040fa68);
    yield* sub_4015d0();
    push32(0x0040e8a4);
    push32(0x0040fa6c);
    yield* sub_4015d0();
    push32(0x0040e894);
    push32(0x0040fa70);
    yield* sub_4015d0();
    push32(0x0040e884);
    push32(0x0040fa74);
    yield* sub_4015d0();
    push32(0x0040e870);
    push32(0x0040fa78);
    yield* sub_4015d0();
    push32(0x0040e85c);
    push32(0x0040fa7c);
    yield* sub_4015d0();
    push32(0x0040e850);
    push32(0x0040fa88);
    yield* sub_4015d0();
    push32(0x0040e840);
    push32(0x0040fa8c);
    yield* sub_4015d0();
    r32[esp] += 0x00000040;
    push32(0x0040e830);
    push32(0x0040fa90);
    yield* sub_4015d0();
    push32(0x0040e820);
    push32(0x0040fa94);
    yield* sub_4015d0();
    push32(0x0040e810);
    push32(0x0040fa98);
    yield* sub_4015d0();
    push32(0x0040e800);
    push32(0x0040fa9c);
    yield* sub_4015d0();
    push32(0x0040e7f0);
    push32(0x0040faa0);
    yield* sub_4015d0();
    push32(0x0040e7dc);
    push32(0x0040fa80);
    yield* sub_4015d0();
    push32(0x0040e7c8);
    push32(0x0040fa84);
    yield* sub_4015d0();
    push32(0x0040e7b8);
    push32(0x0040faa4);
    yield* sub_4015d0();
    r32[esp] += 0x00000040;
    push32(0x0040e7a8);
    push32(0x0040faa8);
    yield* sub_4015d0();
    r32[esp] += 0x00000008;
  case 0x401c16: // 0000:401c16
    push32(0x0040e79c);
    r32[eax] = alleg40.exists(stack32(0));
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x401c32; break; }
    memoryASet32(ds, 0x40fa30, 0xffffffff);
  case 0x401c32: // 0000:401c32
    push32(0x00000001);
    r32[eax] = alleg40.set_display_switch_mode(stack32(0));
    push32(0xffffffff);
    alleg40.text_mode(stack32(0));
    r32[esp] += 0x00000008;
    r32[eax] |= 0xffffffff;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 4; return;
  case 0x401c4b: // 0000:401c4b
    push32(0x0040e774);
    alleg40.allegro_message(stack32(0));
    r32[esp] += 0x00000004;
    r32[eax] = 0;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_401c60() // 0000:401c60 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    push32(0x0040ea58);
    push32(0x0040e964);
    r32[eax] = alleg40.pack_fopen(stack32(0), stack32(1));
    r32[esi] = r32[eax];
    r32[esp] += 0x00000008;
    if (!r32[esi])
        { pc = 0x401c9b; break; }
    push32(r32[esi]);
    push32(0x0040e040);
    yield* sub_4064c0();
    r32[eax] = memoryAGet32(ds, 0x40fa3c);
    push32(r32[esi]);
    push32(r32[eax]);
    yield* sub_401430();
    push32(r32[esi]);
    r32[eax] = alleg40.pack_fclose(stack32(0));
    r32[esp] += 0x00000014;
  case 0x401c9b: // 0000:401c9b
    r32[eax] = memoryAGet32(ds, 0x40fa44);
    push32(r32[edi]);
    if (r32[eax])
        { pc = 0x401d59; break; }
    r32[edi] = memoryAGet32(ds, 0x40d11c);
    r32[esi] = 0x0040fa48;
  case 0x401cb4: // 0000:401cb4
    r32[eax] = memoryAGet32(ds, r32[esi]);
    if (!r32[eax])
        { pc = 0x401cc0; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000004;
  case 0x401cc0: // 0000:401cc0
    r32[esi] += 0x00000004;
    if (r32s[esi] < signed32(0x0040fa60))
        { pc = 0x401cb4; break; }
    r32[esi] = 0x0040fa68;
  case 0x401cd0: // 0000:401cd0
    r32[eax] = memoryAGet32(ds, r32[esi]);
    if (!r32[eax])
        { pc = 0x401cdc; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000004;
  case 0x401cdc: // 0000:401cdc
    r32[esi] += 0x00000004;
    if (r32s[esi] < signed32(0x0040fa74))
        { pc = 0x401cd0; break; }
    r32[esi] = 0x0040fa74;
  case 0x401cec: // 0000:401cec
    r32[eax] = memoryAGet32(ds, r32[esi]);
    if (!r32[eax])
        { pc = 0x401cf8; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000004;
  case 0x401cf8: // 0000:401cf8
    r32[esi] += 0x00000004;
    if (r32s[esi] < signed32(0x0040fa80))
        { pc = 0x401cec; break; }
    r32[esi] = 0x0040fa80;
  case 0x401d08: // 0000:401d08
    r32[eax] = memoryAGet32(ds, r32[esi]);
    if (!r32[eax])
        { pc = 0x401d14; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000004;
  case 0x401d14: // 0000:401d14
    r32[esi] += 0x00000004;
    if (r32s[esi] < signed32(0x0040fa88))
        { pc = 0x401d08; break; }
    r32[esi] = 0x0040fa88;
  case 0x401d24: // 0000:401d24
    r32[eax] = memoryAGet32(ds, r32[esi]);
    if (!r32[eax])
        { pc = 0x401d30; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000004;
  case 0x401d30: // 0000:401d30
    r32[esi] += 0x00000004;
    if (r32s[esi] < signed32(0x0040faac))
        { pc = 0x401d24; break; }
    r32[eax] = memoryAGet32(ds, 0x40fa60);
    if (!r32[eax])
        { pc = 0x401d4a; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000004;
  case 0x401d4a: // 0000:401d4a
    r32[eax] = memoryAGet32(ds, 0x40fa64);
    if (!r32[eax])
        { pc = 0x401d59; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000004;
  case 0x401d59: // 0000:401d59
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[esi] = memoryAGet32(ds, 0x40d120);
    r32[edi] = pop32();
    if (!r32[eax])
        { pc = 0x401d6f; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000004;
  case 0x401d6f: // 0000:401d6f
    r32[eax] = memoryAGet32(ds, 0x40fa44);
    if (!r32[eax])
        { pc = 0x401d7e; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000004;
  case 0x401d7e: // 0000:401d7e
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    r32[esi] = pop32();
    if (!r32[eax])
        { pc = 0x401d92; break; }
    push32(r32[eax]);
    alleg40.destroy_bitmap(stack32(0));
    r32[esp] += 0x00000004;
  case 0x401d92: // 0000:401d92
    r32[eax] = memoryAGet32(ds, 0x40fa3c);
    if (!r32[eax])
        { pc = 0x401da4; break; }
    push32(r32[eax]);
    yield* sub_401240();
    r32[esp] += 0x00000004;
  case 0x401da4: // 0000:401da4
    indirectJump(cs, memoryAGet32(ds, 0x40d128)); return; // 0000:401da4
    return;
  }
}
function* sub_401db0() // 0000:401db0 +long draw bricks, blur
{
  var pc = 0;
  alleg40.vtable_rectfill(memoryAGet32(ds, 0x40fa34), 0, 0, 640, 480, 0x18);

  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x00000038;
    push32(r32[ebx]);
    r32[eax] = 0;
    push32(r32[esi]);
    push32(r32[edi]);
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
    { pc = 0x401dc3; break; }
  case 0x401dc0: // 0000:401dc0
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
  case 0x401dc3: // 0000:401dc3
    r32[edi] = r32[eax];
    memoryASet32(ss, r32[ebp] - 12, 0x0000000f);
    r32[edi] = ~r32[edi];
    r32[edi] &= 0x00000001;
    r32[edi] <<= 5;
    r32[eax] <<= 5;
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
    { pc = 0x401ddf; break; }
  case 0x401ddc: // 0000:401ddc
    r32[eax] = memoryAGet32(ss, r32[ebp] - 8);
  case 0x401ddf: // 0000:401ddf
    r32[ecx] = r32[edi];
    r32[esi] = 0x00000040;
    r32[ecx] = sar32(r32[ecx], 0x02);
    r32[esi] -= r32[ecx];
    push32(0x00000020);
    r32[ebx] = r32[esi];
    r32[edx] = r32[edi];
    r32[ebx] = sar32(r32[ebx], 0x00000001);
    push32(r32[esi]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[edx] -= r32[ebx];
    r32[edx] += 0x00000140;
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x10);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[ecx]);
    push32(r32[edx]);
    alleg40.stretch_sprite(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[eax] = memoryAGet32(ss, r32[ebp] - 8);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = 0x00000140;
    push32(0x00000020);
    r32[ecx] -= r32[ebx];
    push32(r32[esi]);
    r32[ecx] -= r32[edi];
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x10);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    push32(r32[ecx]);
    alleg40.stretch_sprite(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[eax] = memoryAGet32(ss, r32[ebp] - 12);
    r32[esp] += 0x00000030;
    r32[edi] += r32[esi];
    r32[eax]--;
    memoryASet32(ss, r32[ebp] - 12, r32[eax]);
    if (r32[eax])
        { pc = 0x401ddc; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax]++;
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
    if (r32s[eax] < signed32(0x00000004))
        { pc = 0x401dc0; break; }
    memoryASet32(ss, r32[ebp] - 4, 0x00000000);
/*
  case 0x401e61: // 0000:401e61
    r32[edi] = 0;
    memoryASet32(ss, r32[ebp] - 8, 0x00000140);
  case 0x401e6a: // 0000:401e6a
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = 0;
    r8[cl] = memoryAGet(ds, r32[eax] + r32[edi]);
    r32[esi] = r32[ecx];
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    memoryASet32(ss, r32[ebp] - 12, r32[esi]);
    if (r32s[esi] < signed32(0x00000010))
        { pc = 0x401e9d; break; }
    if (r32s[esi] <= signed32(0x0000001f))
        { pc = 0x401ea4; break; }
  case 0x401e9d: // 0000:401e9d
    memoryASet32(ss, r32[ebp] - 12, 0x00000014);
  case 0x401ea4: // 0000:401ea4
    r32[eax] = r32[edi] - 320;
    r32[ecx] = r32[eax];
    if (r32s[eax] >= 0)
        { pc = 0x401eb3; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
  case 0x401eb3: // 0000:401eb3
    r32[eax] = 0x2aaaaaab;
    imul32(r32[ecx]);
    r32[eax] = r32[edx];
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    memoryASet32(ss, r32[ebp] - 16, r32[edx]);
    fild32(memoryAGet32(ss, r32[ebp] - 16));
    fcom64(memoryAGet64(ds, 0x40d1f0));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x401eeb; break; }
    r32[ecx] = memoryAGet32(ds, 0x40d110);
    r32[eax] = 0x7fffffff;
    fstp80();
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    memoryASet32(ds, r32[edx], 0x00000022);
    { pc = 0x401f3a; break; }
  case 0x401eeb: // 0000:401eeb
    fcom64(memoryAGet64(ds, 0x40d1e8));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x401f0e; break; }
    r32[eax] = memoryAGet32(ds, 0x40d110);
    fstp80();
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    r32[eax] = 0x80000001;
    memoryASet32(ds, r32[ecx], 0x00000022);
    { pc = 0x401f3a; break; }
  case 0x401f0e: // 0000:401f0e
    fcom64(memoryAGet64(ds, 0x40d1e0));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x401f23; break; }
    fld64(memoryAGet64(ds, 0x40d1d8));
    { pc = 0x401f29; break; }
  case 0x401f23: // 0000:401f23
    fld64(memoryAGet64(ds, 0x40d1d0));
  case 0x401f29: // 0000:401f29
    fxch80(st(0));
    fmul64(memoryAGet64(ds, 0x40d1c8));
    fadd80(st(1));
    yield* sub_406e04();
    fstp80();
  case 0x401f3a: // 0000:401f3a
    r32[edx] = memoryAGet32(ds, 0x40d114);
    r32[eax] += 0x00004000;
    r32[eax] = sar32(r32[eax], 0x0f);
    r32[eax] &= 0x000001ff;
    r32[eax] = memoryAGet32(ds, r32[edx] + r32[eax] * 4);
    memoryASet32(ss, r32[ebp] - 20, r32[eax]);
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000003;
    idiv32(r32[ecx]);
    memoryASet32(ss, r32[ebp] - 16, r32[edx]);
    fild32(memoryAGet32(ss, r32[ebp] - 16));
    fild32(memoryAGet32(ss, r32[ebp] - 12));
    fild32(memoryAGet32(ss, r32[ebp] - 20));
    fmul64(memoryAGet64(ds, 0x40d1c0));
    fsubp80(st(1));
    faddp80(st(1));
    fsub64(memoryAGet64(ds, 0x40d1b8));
    yield* sub_406e04();
    r32[ebx] = r32[eax];
    if (r32s[ebx] >= signed32(0x00000010))
        { pc = 0x401f8f; break; }
    r32[ebx] = 0x00000010;
    { pc = 0x401f99; break; }
  case 0x401f8f: // 0000:401f8f
    if (r32s[ebx] <= signed32(0x0000001f))
        { pc = 0x401f99; break; }
    r32[ebx] = 0x0000001f;
  case 0x401f99: // 0000:401f99
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x20);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    yield* indirectCall(cs, r32[ecx]);
    memoryASet(ds, r32[eax] + r32[edi], r8[bl]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 8);
    r32[edi]++;
    r32[eax]--;
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
    if (r32s[eax] > signed32(0xfffffec0))
        { pc = 0x401e6a; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax]++;
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
    if (r32s[eax] < signed32(0x00000080))
        { pc = 0x401e61; break; }
    r32[edi] = 0x00000020;
    memoryASet32(ss, r32[ebp] - 4, r32[edi]);
  case 0x401fe8: // 0000:401fe8
    r32[ebx] = r32[edi] - 1;
    r32[edi]++;
    r32[esi] = 0x00000001;
    memoryASet32(ss, r32[ebp] - 20, r32[ebx]);
    memoryASet32(ss, r32[ebp] - 8, r32[ebx]);
    memoryASet32(ss, r32[ebp] - 24, r32[edi]);
    { pc = 0x401fff; break; }
  case 0x401ffc: // 0000:401ffc
    r32[ebx] = memoryAGet32(ss, r32[ebp] - 20);
  case 0x401fff: // 0000:401fff
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 12, r32[eax]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = 0;
    r8[cl] = memoryAGet(ds, r32[eax] + r32[esi]);
    memoryASet32(ss, r32[ebp] - 56, r32[ecx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 16, r32[ebx]);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 16);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = 0;
    r8[cl] = memoryAGet(ds, r32[eax] + r32[esi] + 0x1);
    memoryASet32(ss, r32[ebp] - 52, r32[ecx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = 0;
    r8[cl] = memoryAGet(ds, r32[eax] + r32[esi] + 0x1);
    memoryASet32(ss, r32[ebp] - 48, r32[ecx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 16, r32[edi]);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 16);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = 0;
    r8[cl] = memoryAGet(ds, r32[eax] + r32[esi] + 0x1);
    memoryASet32(ss, r32[ebp] - 44, r32[ecx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 16, r32[ebx]);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 16);
    yield* indirectCall(cs, r32[ecx]);
    r32[ebx] = 0;
    r8[bl] = memoryAGet(ds, r32[eax] + r32[esi]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 12, r32[eax]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = 0;
    r8[cl] = memoryAGet(ds, r32[eax] + r32[esi]);
    memoryASet32(ss, r32[ebp] - 40, r32[ecx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 16, r32[edi]);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 16);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = 0;
    r8[cl] = memoryAGet(ds, r32[eax] + r32[esi]);
    memoryASet32(ss, r32[ebp] - 36, r32[ecx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 8);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = 0;
    r8[cl] = memoryAGet(ds, r32[eax] + r32[esi] - 1);
    memoryASet32(ss, r32[ebp] - 32, r32[ecx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = 0;
    r8[cl] = memoryAGet(ds, r32[eax] + r32[esi] - 1);
    memoryASet32(ss, r32[ebp] - 28, r32[ecx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x24);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 24);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = 0;
    r8[cl] = memoryAGet(ds, r32[eax] + r32[esi] - 1);
    memoryASet32(ss, r32[ebp] - 16, r32[ecx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 16);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 28);
    r32[ecx] = r32[edx] + r32[eax];
    r32[edx] = memoryAGet32(ss, r32[ebp] - 32);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 36);
    r32[ecx] += r32[edx];
    r32[edx] = memoryAGet32(ss, r32[ebp] - 40);
    r32[ecx] += r32[eax];
    r32[eax] = memoryAGet32(ss, r32[ebp] - 48);
    r32[ecx] += r32[edx];
    r32[edx] = memoryAGet32(ss, r32[ebp] - 44);
    r32[ecx] += r32[ebx];
    r32[ebx] = memoryAGet32(ss, r32[ebp] - 52);
    r32[ecx] += r32[edx];
    r32[edx] = memoryAGet32(ss, r32[ebp] - 56);
    r32[ecx] += r32[eax];
    r32[ecx] += r32[ebx];
    r32[eax] = 0x66666667;
    r32[ecx] += r32[edx];
    imul32(r32[ecx]);
    r32[edx] = sar32(r32[edx], 0x02);
    r32[ecx] = r32[edx];
    r32[ecx] >>= 31;
    r32[edx] += r32[ecx];
    r32[ebx] = r32[edx];
    if (r32s[ebx] >= signed32(0x00000010))
        { pc = 0x4021df; break; }
    r32[ebx] = 0x00000010;
    { pc = 0x4021e9; break; }
  case 0x4021df: // 0000:4021df
    if (r32s[ebx] <= signed32(0x0000001f))
        { pc = 0x4021e9; break; }
    r32[ebx] = 0x0000001f;
  case 0x4021e9: // 0000:4021e9
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x20);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    yield* indirectCall(cs, r32[ecx]);
    memoryASet(ds, r32[eax] + r32[esi], r8[bl]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    yield* indirectCall(cs, r32[ecx]);
    r32[esi]++;
    if (r32s[esi] < signed32(0x0000027f))
        { pc = 0x401ffc; break; }
    memoryASet32(ss, r32[ebp] - 4, r32[edi]);
    if (r32s[edi] < signed32(0x00000060))
        { pc = 0x401fe8; break; }
*/
    r32[eax] = memoryAGet32(ds, 0x40fa38);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    push32(0x00000040);
    push32(0x00000280);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000020);
    push32(0x00000000);
    push32(r32[eax]);
    push32(r32[ecx]);
    alleg40.vtable_rectfill(memoryAGet32(ds, 0x40fa34), 0, 0, 640, 480, "#00000080");
    alleg40.blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
    r32[esp] += 0x00000020;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp];
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_402250() // 0000:402250 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x40d108);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x10);
    if (!r32[ecx])
        { pc = 0x402267; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ecx]);
    r32[esp] += 0x00000004;
  case 0x402267: // 0000:402267
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, 0x40d108);
    push32(r32[ecx]);
    push32(0x00000000);
    r32[ecx] = memoryAGet32(ds, r32[edx]);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(r32[ecx]);
    push32(r32[eax]);
    alleg40.blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
    r32[edx] = memoryAGet32(ds, 0x40d108);
    r32[esp] += 0x00000020;
    r32[eax] = memoryAGet32(ds, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x14);
    if (!r32[ecx])
        { pc = 0x4022a3; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ecx]);
    r32[ecx] = pop32();
  case 0x4022a3: // 0000:4022a3
    r32[esp] += 4; return;
    return;
  }
}
function* sub_4022b0() // 0000:4022b0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x40e054);
    r32[esp] -= 0x00000400;
    if (!r32[eax])
        { pc = 0x402314; break; }
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x40c);
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x40c);
    push32(r32[esi]);
    r32[eax] = r32[esp] + 12;
    push32(r32[edi]);
    push32(r32[eax]);
    alleg40.get_palette_range(stack32(0), stack32(1), stack32(2), stack32(3));
    r32[edx] = memoryAGet32(ds, r32[esp] + r32[esi] * 4 + 0x14);
    r32[eax] = (r32[esp] + (r32[esi] * 4)) + 20;
    r32[esp] += 0x0000000c;
    if (r32s[esi] <= r32s[edi])
        { pc = 0x4022fc; break; }
    r32[ecx] = r32[esi];
    push32(r32[ebx]);
    r32[ecx] -= r32[edi];
  case 0x4022f0: // 0000:4022f0
    r32[ebx] = memoryAGet32(ds, r32[eax] - 4);
    memoryASet32(ds, r32[eax], r32[ebx]);
    r32[eax] += 0xfffffffc;
    r32[ecx]--;
    if (r32[ecx])
        { pc = 0x4022f0; break; }
    r32[ebx] = pop32();
  case 0x4022fc: // 0000:4022fc
    push32(0x00000000);
    push32(r32[esi]);
    r32[ecx] = r32[esp] + 16;
    push32(r32[edi]);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp] + r32[edi] * 4 + 0x18, r32[edx]);
    alleg40.set_palette_range(stack32(0), stack32(1), stack32(2), stack32(3));
    r32[esp] += 0x00000010;
    r32[edi] = pop32();
    r32[esi] = pop32();
  case 0x402314: // 0000:402314
    r32[esp] += 0x00000400;
    r32[esp] += 4;
    return;
  }
}
function* sub_402320() // 0000:402320 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x0000000c;
    r32[eax] = memoryAGet32(ds, 0x40e054);
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    if (!r32[eax])
        { pc = 0x4023e2; break; }
    r32[esi] = memoryAGet32(ds, 0x42be00);
    r32[edi] = memoryAGet32(ds, 0x42bbc8);
    r32[eax] = r32[esi];
    push32(0x00000000);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[ecx] = memoryAGet32(ds, r32[edi] + 0x4);
    r32[eax] = sar32(r32[eax], 0x00000001);
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    fild32(memoryAGet32(ss, r32[ebp] - 4));
    fild32(memoryAGet32(ds, r32[edi] + 0x4));
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ebx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = r32[esi];
    push32(r32[esi]);
    fmul80(st(1));
    r32[eax] <<= 8;
    r32[ecx] <<= 15;
    fmul64(memoryAGet64(ds, 0x40d208));
    fild32(memoryAGet32(ds, 0x42be00));
    push32(r32[eax]);
    push32(r32[ecx]);
    r32[ebx] <<= 15;
    fmul64(memoryAGet64(ds, 0x40d200));
    push32(r32[ebx]);
    memoryASet32(ss, r32[ebp] - 4, r32[edx]);
    faddp80(st(1));
    yield* sub_406e04();
    r32[ecx] = 0x00000168;
    r32[ecx] -= r32[eax];
    r32[eax] = memoryAGet32(ds, r32[edi] + 0x4);
    r32[eax] = r32s[eax] * r32s[esi];
    fild32(memoryAGet32(ds, r32[edi]));
    fmul80(st(1));
    fmul64(memoryAGet64(ds, 0x40d1f8));
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[ecx] <<= 16;
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[ecx] += r32[eax];
    push32(r32[ecx]);
    yield* sub_406e04();
    r32[ecx] = 0x00000140;
    r32[ecx] -= r32[eax];
    r32[eax] = memoryAGet32(ds, r32[edi]);
    r32[eax] = r32s[eax] * r32s[esi];
    fstp80();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[ecx] <<= 16;
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[ecx] += r32[eax];
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    push32(r32[ecx]);
    push32(r32[edi]);
    push32(r32[edx]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[eax] + 0xa0));
    r32[esp] += 0x00000024;
    { pc = 0x4024b1; break; }
  case 0x4023e2: // 0000:4023e2
    r32[ecx] = memoryAGet32(ds, 0x42bbc8);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x4);
    r32[ecx] = r32s[ecx] * (signed32(memoryAGet32(ds, 0x42be00)));
    memoryASet32(ss, r32[ebp] - 4, r32[ecx]);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax] = sar32(r32[eax], 0x10);
    r32[edx] = memoryAGet32(ds, 0x42bbc8);
    r32[ebx] = r32[eax];
    r32[esi] = memoryAGet32(ds, r32[edx]);
    r32[esi] = r32s[esi] * (signed32(memoryAGet32(ds, 0x42be00)));
    memoryASet32(ss, r32[ebp] - 4, r32[esi]);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax] = sar32(r32[eax], 0x10);
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x42bbc8);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x4);
    r32[eax] = r32s[eax] * (signed32(memoryAGet32(ds, 0x42be00)));
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[edi] = r32[eax];
    r32[edi] = sar32(r32[edi], 0x00000001);
    memoryASet32(ss, r32[ebp] - 4, r32[edi]);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax] = sar32(r32[eax], 0x10);
    r32[ecx] = sar32(r32[ecx], 0x0f);
    memoryASet32(ss, r32[ebp] - 12, r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x42be00);
    r32[ecx] &= 0x00000001;
    r32[ecx] += r32[ebx];
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[esi] = sar32(r32[esi], 0x0f);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
    r32[esi] &= 0x00000001;
    r32[eax] -= r32[edx];
    r32[esi] += r32[ecx];
    r32[eax] = sar32(r32[eax], 0x00000001);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, 0x42bbc8);
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
    fild32(memoryAGet32(ss, r32[ebp] - 4));
    fild32(memoryAGet32(ds, r32[esi] + 0x4));
    fmul80(st(1));
    fmul64(memoryAGet64(ds, 0x40d1f8));
    yield* sub_406e04();
    fild32(memoryAGet32(ds, r32[esi]));
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = 0x00000168;
    r32[edi] = sar32(r32[edi], 0x0f);
    fmul80(st(1));
    r32[ecx] -= r32[eax];
    r32[edi] &= 0x00000001;
    r32[ecx] -= r32[edi];
    fmul64(memoryAGet64(ds, 0x40d1f8));
    r32[ecx] -= r32[edx];
    push32(r32[ecx]);
    yield* sub_406e04();
    r32[edx] = 0x00000140;
    r32[edx] -= r32[eax];
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    push32(r32[edx]);
    push32(r32[esi]);
    push32(r32[eax]);
    fstp80();
    alleg40.stretch_sprite(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[esp] += 0x00000018;
  case 0x4024b1: // 0000:4024b1
    r32[eax] = memoryAGet32(ds, 0x40fcac);
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    if (r32s[eax] <= signed32(0x0000003c))
        { pc = 0x4024c8; break; }
    memoryASet32(ds, 0x42be00, memoryAGet32(ds, 0x42be00) + 0x00000ccd);
  case 0x4024c8: // 0000:4024c8
    if (r32s[eax] >= signed32(0x0000000a))
        { pc = 0x4024d7; break; }
    memoryASet32(ds, 0x42be00, memoryAGet32(ds, 0x42be00) - 0x0000199a);
  case 0x4024d7: // 0000:4024d7
    r32[eax]--;
    memoryASet32(ds, 0x40fcac, r32[eax]);
    r32[esp] = r32[ebp];
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_4024f0() // 0000:4024f0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[edi]);
    r32[ebp] = 0x00000005;
    memoryASet32(ds, 0x40fcac, 0x00000050);
    memoryASet32(ds, 0x42be00, 0x00000000);
    if (r32s[eax] >= signed32(0x00000007))
        { pc = 0x402519; break; }
    r32[ebp] = 0;
    { pc = 0x402547; break; }
  case 0x402519: // 0000:402519
    if (r32s[eax] >= signed32(0x0000000f))
        { pc = 0x402525; break; }
    r32[ebp] = 0x00000001;
    { pc = 0x402547; break; }
  case 0x402525: // 0000:402525
    if (r32s[eax] >= signed32(0x00000019))
        { pc = 0x402531; break; }
    r32[ebp] = 0x00000002;
    { pc = 0x402547; break; }
  case 0x402531: // 0000:402531
    if (r32s[eax] >= signed32(0x00000023))
        { pc = 0x40253d; break; }
    r32[ebp] = 0x00000003;
    { pc = 0x402547; break; }
  case 0x40253d: // 0000:40253d
    if (r32s[eax] >= signed32(0x0000002d))
        { pc = 0x402547; break; }
    r32[ebp] = 0x00000004;
  case 0x402547: // 0000:402547
    r32[eax] = memoryAGet32(ds, 0x40e054);
    if (!r32[eax])
        { pc = 0x4025e4; break; }
    if (r32s[ebp] <= signed32(0x00000002))
        { pc = 0x4025e4; break; }
    r32[edi] = r32[ebp] - 2;
    r32[ebx] = r32[edi];
    r32[ebx] <<= 4;
    if (r32s[ebx] <= 0)
        { pc = 0x4025e4; break; }
    push32(r32[esi]);
  case 0x40256a: // 0000:40256a
    push32(0x00000168);
    push32(0x00000140);
    push32(0x0040ffe0);
    yield* sub_406500();
    r32[esi] = r32[eax] + (r32[eax] * 2);
    r32[esp] += 0x0000000c;
    r32[esi] <<= 3;
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x000001f4;
    idiv32(r32[ecx]);
    r32[eax] = 0xae147ae1;
    r32[edx] += r32[ecx];
    r32[edx] <<= 16;
    imul32(r32[edx]);
    r32[edx] = sar32(r32[edx], 0x05);
    r32[eax] = r32[edx];
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    memoryASet32(ds, r32[esi] + 0x40fff0, r32[edx]);
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x000003e8;
    idiv32(r32[ecx]);
    r32[eax] = 0x51eb851f;
    r32[edx] -= 0x000001f4;
    r32[edx] = r32s[edx] * r32s[edi];
    r32[edx] <<= 16;
    imul32(r32[edx]);
    r32[edx] = sar32(r32[edx], 0x05);
    r32[eax] = r32[edx];
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    r32[ebx]--;
    memoryASet32(ds, r32[esi] + 0x40ffec, r32[edx]);
    if (r32[ebx])
        { pc = 0x40256a; break; }
    r32[esi] = pop32();
  case 0x4025e4: // 0000:4025e4
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = r32[ebp] + 46;
    r32[ecx] <<= 4;
    push32(0x00000000);
    r32[eax] = memoryAGet32(ds, r32[ecx] + r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[ebp] * 4 + 0x40fa48);
    push32(r32[ecx]);
    memoryASet32(ds, 0x42bbc8, r32[eax]);
    yield* sub_401570();
    r32[esp] += 0x00000008;
    r32[edi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_402610() // 0000:402610 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    fld64(memoryAGet64(ds, r32[ecx] + 0x18));
    fcomp64(memoryAGet64(ds, 0x40d218));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x402635; break; }
    r32[eax] = memoryAGet32(ds, 0x40fa70);
    push32(0x00000001);
    push32(r32[eax]);
    yield* sub_401570();
    r32[esp] += 0x00000008;
    r32[esp] += 4; return;
  case 0x402635: // 0000:402635
    fld64(memoryAGet64(ds, r32[ecx] + 0x18));
    fcomp64(memoryAGet64(ds, 0x40d210));
    push32(0x00000001);
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x402657; break; }
    r32[ecx] = memoryAGet32(ds, 0x40fa6c);
    push32(r32[ecx]);
    yield* sub_401570();
    r32[esp] += 0x00000008;
    r32[esp] += 4; return;
  case 0x402657: // 0000:402657
    r32[edx] = memoryAGet32(ds, 0x40fa68);
    push32(r32[edx]);
    yield* sub_401570();
    r32[esp] += 0x00000008;
    r32[esp] += 4;
    return;
  }
}
function* sub_402670() // 0000:402670 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x8);
    if (!r32[esi])
        { pc = 0x40277d; break; }
    push32(r32[esi]);
    yield* sub_401060();
    push32(r32[esi]);
    yield* sub_4011e0();
    r32[esp] += 0x00000008;
    if (!r32[eax])
        { pc = 0x4026b1; break; }
    fld64(memoryAGet64(ds, 0x412ff0));
    fcom64(memoryAGet64(ds, 0x40d1e0));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x4026a9; break; }
    fmul64(memoryAGet64(ds, 0x40d230));
  case 0x4026a9: // 0000:4026a9
    fsub64(memoryAGet64(ds, 0x40d228));
    { pc = 0x4026f2; break; }
  case 0x4026b1: // 0000:4026b1
    push32(r32[esi]);
    yield* sub_4011f0();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x4026df; break; }
    fld64(memoryAGet64(ds, 0x412ff0));
    fcom64(memoryAGet64(ds, 0x40d1e0));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4026d7; break; }
    fmul64(memoryAGet64(ds, 0x40d230));
  case 0x4026d7: // 0000:4026d7
    fadd64(memoryAGet64(ds, 0x40d228));
    { pc = 0x4026f2; break; }
  case 0x4026df: // 0000:4026df
    r32[eax] = memoryAGet32(ds, 0x413010);
    fld64(memoryAGet64(ds, 0x412ff0));
    fmul64(memoryAGet64(ds, 0x40d220));
  case 0x4026f2: // 0000:4026f2
    r32[eax] = memoryAGet32(ds, 0x40e048);
    push32(r32[esi]);
    memoryASet64(ds, 0x412ff0, fstp64());
    if (r32[eax])
        { pc = 0x402753; break; }
    yield* sub_401200();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x40273f; break; }
    r32[eax] = memoryAGet32(ds, 0x413014);
    if (r32[eax])
        { pc = 0x40273f; break; }
    push32(0x00412fe0);
    yield* sub_406800();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x40273f; break; }
    push32(0x00412fe0);
    memoryASet32(ds, 0x413014, 0xffffffff);
    yield* sub_402610();
    r32[esp] += 0x00000004;
  case 0x40273f: // 0000:40273f
    push32(r32[esi]);
    yield* sub_401200();
    r32[esp] += 0x00000004;
    if (r32[eax])
        { pc = 0x40277d; break; }
    memoryASet32(ds, 0x413014, r32[eax]);
    r32[esi] = pop32();
    r32[esp] += 4; return;
  case 0x402753: // 0000:402753
    yield* sub_401200();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x40277d; break; }
    push32(0x00412fe0);
    yield* sub_406800();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x40277d; break; }
    push32(0x00412fe0);
    yield* sub_402610();
    r32[esp] += 0x00000004;
  case 0x40277d: // 0000:40277d
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_402780() // 0000:402780 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x0000001c;
    push32(r32[ebx]);
    r32[eax] = 0;
    push32(r32[esi]);
    push32(r32[edi]);
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
    memoryASet32(ss, r32[ebp] - 20, r32[eax]);
    memoryASet32(ss, r32[ebp] - 16, r32[eax]);
    memoryASet32(ss, r32[ebp] - 12, r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x40ffc4);
    r32[eax]++;
    memoryASet32(ds, 0x40ffc4, r32[eax]);
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[edi] = memoryAGet32(ds, 0x40d118);
    r32[ebx] = 0xffffffc0;
  case 0x4027b0: // 0000:4027b0
    r32[eax] = memoryAGet32(ds, 0x40ffc0);
    push32(0x00000040);
    r32[eax] &= 0x8000007f;
    push32(0x00000208);
    if (r32s[eax] >= 0)
        { pc = 0x4027c8; break; }
    r32[eax]--;
    r32[eax] |= 0xffffff80;
    r32[eax]++;
  case 0x4027c8: // 0000:4027c8
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[ecx] = memoryAGet32(ds, 0x40fa38);
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[eax] += r32[ebx];
    push32(r32[eax]);
    push32(0x0000003c);
    push32(0x00000000);
    push32(0x0000003c);
    push32(r32[esi]);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[edi]);
    r32[ebx] += 0x00000040;
    r32[esp] += 0x00000020;
    if (r32s[ebx] < signed32(0x00000200))
        { pc = 0x4027b0; break; }
    r32[edi] = memoryAGet32(ds, 0x413324);
    if (r32s[edi] >= signed32(0x000001e0))
        { pc = 0x402852; break; }
    if (r32s[edi] <= signed32(0xffffff9c))
        { pc = 0x402852; break; }
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    push32(r32[edi]);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x2b0);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[edx] = r32[eax];
    r32[eax] = 0x00000140;
    r32[edx] = sar32(r32[edx], 0x00000001);
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    push32(r32[eax]);
    push32(r32[ecx]);
    r32[ebx] = memoryAGet32(ds, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    push32(r32[esi]);
    if (r32[ebx] != 0x00000008)
        { pc = 0x402833; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x402836; break; }
  case 0x402833: // 0000:402833
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x402836: // 0000:402836
    r32[esp] += 0x00000010;
    push32(0x000000ef);
    push32(0x000000e0);
    yield* sub_4022b0();
    r32[esp] += 0x00000008;
    memoryASet32(ss, r32[ebp] - 20, 0x00000001);
  case 0x402852: // 0000:402852
    memoryASet32(ss, r32[ebp] + 0x8, 0x000001f0);
    r32[ebx] = 0x0040ffb0;
    memoryASet32(ss, r32[ebp] - 24, 0xffffffe0);
  case 0x402865: // 0000:402865
    r32[eax] = memoryAGet32(ds, r32[ebx] - 8);
    if (r32[eax])
        { pc = 0x4029cd; break; }
    r32[eax] = memoryAGet32(ds, 0x40ffc0);
    r32[edi] = memoryAGet32(ds, r32[ebx] - 4);
    r32[eax] &= 0x8000000f;
    if (r32s[eax] >= 0)
        { pc = 0x402884; break; }
    r32[eax]--;
    r32[eax] |= 0xfffffff0;
    r32[eax]++;
  case 0x402884: // 0000:402884
    r32[ecx] = r32[edi];
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[ecx] <<= 4;
    r32[ecx] -= 0x00000005;
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ss, r32[ebp] - 8, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0xc);
    r32[eax] += 0x000001ca;
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 8);
    r32[ecx] = r32[ecx] + (r32[ecx] * 2);
    push32(r32[eax]);
    r32[ecx] <<= 4;
    r32[ecx] = memoryAGet32(ds, r32[ecx] + r32[edx] + 0x70);
    push32(r32[ecx]);
    push32(r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    flags.zero = memoryAGet32(ds, r32[edx]) == 0x00000008;
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    if (!flags.zero)
        { pc = 0x4028c3; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x4028c6; break; }
  case 0x4028c3: // 0000:4028c3
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x4028c6: // 0000:4028c6
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    r32[esp] += 0x00000010;
    r32[edi]++;
    if (r32s[edi] >= r32s[eax])
        { pc = 0x402936; break; }
    r32[eax] = r32[edi];
    r32[eax] <<= 4;
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
  case 0x4028d8: // 0000:4028d8
    r32[eax] = memoryAGet32(ds, 0x40ffc0);
    r32[eax] &= 0x8000000f;
    if (r32s[eax] >= 0)
        { pc = 0x4028e9; break; }
    r32[eax]--;
    r32[eax] |= 0xfffffff0;
    r32[eax]++;
  case 0x4028e9: // 0000:4028e9
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0xc);
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = r32[ecx] + (r32[ecx] * 2);
    r32[eax] += 0x000001ca;
    r32[ecx] <<= 4;
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 8);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + r32[edx] + 0x80);
    push32(r32[eax]);
    push32(r32[ecx]);
    push32(r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    flags.zero = memoryAGet32(ds, r32[edx]) == 0x00000008;
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    if (!flags.zero)
        { pc = 0x402920; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x402923; break; }
  case 0x402920: // 0000:402920
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x402923: // 0000:402923
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    r32[esp] += 0x00000010;
    r32[edi]++;
    r32[ecx] += 0x00000010;
    memoryASet32(ss, r32[ebp] - 8, r32[ecx]);
    if (r32s[edi] < r32s[eax])
        { pc = 0x4028d8; break; }
  case 0x402936: // 0000:402936
    r32[eax] = memoryAGet32(ds, 0x40ffc0);
    r32[eax] &= 0x8000000f;
    if (r32s[eax] >= 0)
        { pc = 0x402947; break; }
    r32[eax]--;
    r32[eax] |= 0xfffffff0;
    r32[eax]++;
  case 0x402947: // 0000:402947
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[eax] -= r32[ecx];
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0xc);
    r32[ecx] += 0x00000003;
    r32[eax] += 0x000001ca;
    r32[edi] <<= 4;
    r32[ecx] = r32[ecx] + (r32[ecx] * 2);
    push32(r32[eax]);
    r32[ecx] <<= 4;
    push32(r32[edi]);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + r32[edx]);
    push32(r32[ecx]);
    push32(r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    flags.zero = memoryAGet32(ds, r32[edx]) == 0x00000008;
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    if (!flags.zero)
        { pc = 0x40297d; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x402980; break; }
  case 0x40297d: // 0000:40297d
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x402980: // 0000:402980
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x4);
    r32[esp] += 0x00000010;
    r32[ecx]--;
    r32[eax] = 0x66666667;
    imul32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, 0x40ffc0);
    r32[edx] = sar32(r32[edx], 0x00000001);
    r32[eax] = r32[edx];
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    r32[ecx] &= 0x8000000f;
    push32(r32[edx]);
    push32(0x0040e030);
    push32(0x0000000f);
    if (r32s[ecx] >= 0)
        { pc = 0x4029b2; break; }
    r32[ecx]--;
    r32[ecx] |= 0xfffffff0;
    r32[ecx]++;
  case 0x4029b2: // 0000:4029b2
    r32[edx] = memoryAGet32(ss, r32[ebp] - 24);
    r32[ecx] += r32[edx];
    r32[edx] = memoryAGet32(ds, 0x40d0d4);
    push32(r32[ecx]);
    push32(0x00000000);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    push32(r32[eax]);
    push32(r32[esi]);
    alleg40.textprintf(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[esp] += 0x0000001c;
  case 0x4029cd: // 0000:4029cd
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x8);
    if (!r32[eax])
        { pc = 0x402aa4; break; }
    r32[edi] = memoryAGet32(ds, 0x40ffc0);
    r32[edi] &= 0x8000000f;
    if (r32s[edi] >= 0)
        { pc = 0x4029eb; break; }
    r32[edi]--;
    r32[edi] |= 0xfffffff0;
    r32[edi]++;
  case 0x4029eb: // 0000:4029eb
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[edi] -= r32[ecx];
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0xc);
    r32[ecx] += 0x00000035;
    r32[edi] += 0x000001da;
    r32[ecx] <<= 4;
    push32(r32[edi]);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[ebx] - 4);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    memoryASet32(ss, r32[ebp] - 28, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    r32[eax] -= r32[edx];
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ds, r32[ebx] - 4);
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[eax] += r32[edx];
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    r32[eax] <<= 4;
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 8);
    flags.zero = r32[eax] == 0x00000008;
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    push32(r32[edx]);
    push32(r32[ecx]);
    push32(r32[esi]);
    if (!flags.zero)
        { pc = 0x402a3d; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x44));
    { pc = 0x402a40; break; }
  case 0x402a3d: // 0000:402a3d
    yield* indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x40));
  case 0x402a40: // 0000:402a40
    r32[eax] = memoryAGet32(ss, r32[ebp] - 28);
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ds, r32[ebx] + 0x8);
    r32[esp] += 0x00000010;
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[eax] += r32[ecx];
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ss, r32[ebp] - 28, r32[eax]);
    push32(0x0040e030);
    r32[ecx] = r32[edi] + 7;
    push32(0x00000001);
    r32[eax] += 0x00000002;
    push32(r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x150);
    push32(r32[eax]);
    push32(r32[esi]);
    alleg40.textprintf_centre(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x8);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 28);
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    push32(r32[ecx]);
    push32(0x0040e030);
    r32[edi] += 0x00000006;
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x150);
    push32(0x0000000f);
    r32[edx]++;
    push32(r32[edi]);
    push32(r32[edx]);
    push32(r32[ecx]);
    push32(r32[esi]);
    alleg40.textprintf_centre(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[esp] += 0x00000038;
  case 0x402aa4: // 0000:402aa4
    r32[eax] = memoryAGet32(ss, r32[ebp] - 24);
    r32[edi] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[eax] += 0x00000010;
    r32[edi] -= 0x00000010;
    r32[ebx] -= 0x00000018;
    memoryASet32(ss, r32[ebp] - 24, r32[eax]);
    memoryASet32(ss, r32[ebp] + 0x8, r32[edi]);
    if (r32s[eax] <= signed32(0x000001d0))
        { pc = 0x402865; break; }
    r32[ebx] = 0x0040ffe8;
  case 0x402ac9: // 0000:402ac9
    r32[eax] = memoryAGet32(ds, r32[ebx] - 8);
    if (!r32[eax])
        { pc = 0x402b30; break; }
    r32[ecx] = memoryAGet32(ds, r32[ebx]);
    memoryASet32(ss, r32[ebp] + 0x8, r32[ecx]);
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[eax] = sar32(r32[eax], 0x10);
    r32[edx] = memoryAGet32(ds, r32[ebx] - 4);
    r32[ecx] = sar32(r32[ecx], 0x0f);
    r32[ecx] &= 0x00000001;
    memoryASet32(ss, r32[ebp] + 0x8, r32[edx]);
    r32[ecx] += r32[eax];
    r32[edi] = r32[ecx];
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[eax] = sar32(r32[eax], 0x10);
    r32[edx] = sar32(r32[edx], 0x0f);
    r32[edx] &= 0x00000001;
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    r32[edx] += r32[eax];
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ss, r32[ebp] + 0x8, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[ebx] + 0xc);
    r32[edx] += 0x00000039;
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[edx] <<= 4;
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + r32[eax]);
    push32(r32[eax]);
    push32(r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    flags.zero = memoryAGet32(ds, r32[edx]) == 0x00000008;
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    if (!flags.zero)
        { pc = 0x402b2a; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x402b2d; break; }
  case 0x402b2a: // 0000:402b2a
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x402b2d: // 0000:402b2d
    r32[esp] += 0x00000010;
  case 0x402b30: // 0000:402b30
    r32[ebx] += 0x00000018;
    if (r32s[ebx] < signed32(0x00412fe8))
        { pc = 0x402ac9; break; }
    r32[eax] = memoryAGet32(ds, 0x413010);
    if (!r32[eax])
        { pc = 0x402b4e; break; }
    r32[ecx] = 0x00000006;
    memoryASet32(ss, r32[ebp] - 4, r32[ecx]);
    { pc = 0x402b51; break; }
  case 0x402b4e: // 0000:402b4e
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
  case 0x402b51: // 0000:402b51
    if (r32[eax] == 0x00000003)
        { pc = 0x402b5b; break; }
    if (r32[eax] != 0x00000002)
        { pc = 0x402b7f; break; }
  case 0x402b5b: // 0000:402b5b
    fld64(memoryAGet64(ds, 0x412ff8));
    fcomp64(memoryAGet64(ds, 0x40d270));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x402c6e; break; }
    r32[ecx] = 0x00000007;
    memoryASet32(ss, r32[ebp] - 4, r32[ecx]);
    { pc = 0x402c78; break; }
  case 0x402b7f: // 0000:402b7f
    if (r32[eax] != 0x00000001)
        { pc = 0x402ba8; break; }
    fld64(memoryAGet64(ds, 0x412ff8));
    fcomp64(memoryAGet64(ds, 0x40d268));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x402c6e; break; }
    r32[ecx] = 0x00000005;
    memoryASet32(ss, r32[ebp] - 4, r32[ecx]);
    { pc = 0x402c78; break; }
  case 0x402ba8: // 0000:402ba8
    if (r32[eax])
        { pc = 0x402c6e; break; }
    fld64(memoryAGet64(ds, 0x412ff0));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    fld64(memoryAGet64(ds, 0x412ff0));
    memoryASet32(ss, r32[ebp] - 4, 0x00000001);
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x402bd2; break; }
    fchs();
  case 0x402bd2: // 0000:402bd2
    fcomp64(memoryAGet64(ds, 0x40d260));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x402cb5; break; }
    memoryASet32(ss, r32[ebp] - 4, 0x00000000);
  case 0x402bea: // 0000:402bea
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[edi] = 0;
    memoryASet32(ds, 0x413018, r32[edi]);
    if (r32[eax])
        { pc = 0x402d0c; break; }
    r32[eax] = memoryAGet32(ds, 0x413034);
    if (!r32[eax])
        { pc = 0x402e08; break; }
    r32[edx] = memoryAGet32(ds, 0x40ffc4);
    r8[dl] = ~r8[dl];
    r32[edi] = r8s[dl];
    r32[edi] &= 0x00000008;
    r32[edi] |= 0x00000120;
    r32[edi] >>= 3;
    if (r32[eax] != 0x00000002)
        { pc = 0x402d93; break; }
    fld64(memoryAGet64(ds, 0x412fe8));
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x1c);
    yield* sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    r32[eax] -= 0x00000032;
    push32(r32[eax]);
    yield* sub_406e04();
    r32[eax] -= 0x0000001a;
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[edi] <<= 4;
    r32[ecx] = memoryAGet32(ds, r32[edi] + r32[eax]);
    push32(r32[ecx]);
    push32(r32[esi]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[ebx] + 0x4c));
    r32[eax] = memoryAGet32(ds, 0x413038);
    r32[esp] += 0x00000010;
    r32[eax]++;
    memoryASet32(ds, 0x413038, r32[eax]);
    { pc = 0x402f5b; break; }
  case 0x402c6e: // 0000:402c6e
    if (r32s[ecx] < signed32(0x00000005))
        { pc = 0x402cac; break; }
    if (r32s[ecx] > signed32(0x00000007))
        { pc = 0x402cac; break; }
  case 0x402c78: // 0000:402c78
    fld64(memoryAGet64(ds, 0x412ff0));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    fld64(memoryAGet64(ds, 0x412ff0));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x402c93; break; }
    fchs();
  case 0x402c93: // 0000:402c93
    fcomp64(memoryAGet64(ds, 0x40d258));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x402cac; break; }
    memoryASet32(ss, r32[ebp] - 4, 0x00000008);
    { pc = 0x402bea; break; }
  case 0x402cac: // 0000:402cac
    if (r32[ecx] != 0x00000001)
        { pc = 0x402bea; break; }
  case 0x402cb5: // 0000:402cb5
    fld64(memoryAGet64(ds, 0x412ff0));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    fld64(memoryAGet64(ds, 0x412ff0));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x402cd0; break; }
    fchs();
  case 0x402cd0: // 0000:402cd0
    fcomp64(memoryAGet64(ds, 0x40d250));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x01)
        { pc = 0x402bea; break; }
    r32[eax] = memoryAGet32(ds, 0x40ffc4);
    r32[ecx] = 0x0000000a;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[ecx]);
    r32[edi] = memoryAGet32(ds, 0x413018);
    if (r32[edx])
        { pc = 0x402cff; break; }
    r32[edi]++;
    memoryASet32(ds, 0x413018, r32[edi]);
  case 0x402cff: // 0000:402cff
    if (r32[edi] != 0x00000004)
        { pc = 0x402d0c; break; }
    r32[edi] = 0;
    memoryASet32(ds, 0x413018, r32[edi]);
  case 0x402d0c: // 0000:402d0c
    r32[eax] = memoryAGet32(ds, 0x41302c);
    if (!r32[eax])
        { pc = 0x402ec0; break; }
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[edx] = memoryAGet32(ds, 0x413030);
    fld64(memoryAGet64(ds, 0x412fe8));
    r32[edi] = memoryAGet32(ds, r32[eax] + 0x230);
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x1c);
    push32(0x00000000);
    push32(0x00010000);
    r32[eax] = memoryAGet32(ds, r32[edi] + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[edi]);
    r32[eax] <<= 15;
    push32(r32[edx]);
    push32(r32[eax]);
    r32[ecx] <<= 15;
    push32(r32[ecx]);
    yield* sub_406e04();
    r32[ecx] = r32[eax];
    r32[eax] = memoryAGet32(ds, r32[edi] + 0x4);
    r32[eax] <<= 16;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    fld64(memoryAGet64(ds, 0x412fe0));
    r32[ecx] -= 0x00000033;
    r32[eax] -= r32[edx];
    r32[ecx] <<= 16;
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[ecx] += r32[eax];
    push32(r32[ecx]);
    yield* sub_406e04();
    r32[ecx] = r32[eax];
    r32[eax] = memoryAGet32(ds, r32[edi]);
    r32[eax] <<= 16;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] -= 0x0000000e;
    r32[eax] -= r32[edx];
    r32[ecx] <<= 16;
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[ecx] += r32[eax];
    push32(r32[ecx]);
    push32(r32[edi]);
    push32(r32[esi]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[ebx] + 0xa0));
    r32[esp] += 0x00000024;
    { pc = 0x402f5b; break; }
  case 0x402d93: // 0000:402d93
    fld64(memoryAGet64(ds, 0x412fe8));
    yield* sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    r32[eax] -= 0x00000032;
    r32[ebx] = 0;
    memoryASet32(ss, r32[ebp] + 0x8, r32[eax]);
    r8[bl] = r32[edi] != 0x00000020;
    r32[ebx]--;
    yield* sub_406e04();
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[eax] = (r32[ebx] + r32[eax]) + -11;
    r32[edi] <<= 4;
    r32[edi] = memoryAGet32(ds, r32[edi] + r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[edi] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    push32(r32[ecx]);
    push32(r32[eax]);
    flags.zero = r32[edx] == 0x00000008;
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    push32(r32[edi]);
    push32(r32[esi]);
    if (!flags.zero)
        { pc = 0x402df2; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    r32[eax] = memoryAGet32(ds, 0x413038);
    r32[esp] += 0x00000010;
    r32[eax]++;
    memoryASet32(ds, 0x413038, r32[eax]);
    { pc = 0x402f5b; break; }
  case 0x402df2: // 0000:402df2
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
    r32[eax] = memoryAGet32(ds, 0x413038);
    r32[esp] += 0x00000010;
    r32[eax]++;
    memoryASet32(ds, 0x413038, r32[eax]);
    { pc = 0x402f5b; break; }
  case 0x402e08: // 0000:402e08
    if (signed32(memoryAGet32(ds, 0x40ffc0)) <= signed32(0x000000c8))
        { pc = 0x402e2e; break; }
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d248));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x402e2e; break; }
    r32[edi] = 0x00000022;
    { pc = 0x402e67; break; }
  case 0x402e2e: // 0000:402e2e
    r32[eax] = memoryAGet32(ds, 0x40ffc4);
    if (r32s[eax] >= signed32(0x0000000c))
        { pc = 0x402e3f; break; }
    r32[edi] = 0x00000020;
    { pc = 0x402e67; break; }
  case 0x402e3f: // 0000:402e3f
    r32[eax] = memoryAGet32(ds, 0x40ffc4);
    if (r32s[eax] >= signed32(0x00000019))
        { pc = 0x402e50; break; }
    r32[edi] = 0x00000017;
    { pc = 0x402e67; break; }
  case 0x402e50: // 0000:402e50
    r32[edx] = 0;
    r32[ebx] = memoryAGet32(ds, 0x40ffc4);
    r8[dl] = r32s[ebx] >= signed32(0x00000025);
    r32[edx]--;
    r32[edx] &= 0x0000000a;
    r32[edx] += 0x00000017;
    r32[edi] = r32[edx];
  case 0x402e67: // 0000:402e67
    fld64(memoryAGet64(ds, 0x412fe8));
    yield* sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    r32[eax] -= 0x00000033;
    r32[ebx] = 0;
    memoryASet32(ss, r32[ebp] + 0x8, r32[eax]);
    r8[bl] = r32[edi] != 0x00000020;
    r32[ebx]--;
    yield* sub_406e04();
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    r32[eax] = (r32[ebx] + r32[eax]) + -14;
    r32[edi] <<= 4;
    r32[edi] = memoryAGet32(ds, r32[edi] + r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[edi] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0x8);
    push32(r32[edx]);
    push32(r32[eax]);
    flags.zero = r32[ecx] == 0x00000008;
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x1c);
    push32(r32[edi]);
    push32(r32[esi]);
    if (!flags.zero)
        { pc = 0x402eb8; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[ecx] + 0x44));
    { pc = 0x402f58; break; }
  case 0x402eb8: // 0000:402eb8
    yield* indirectCall(cs, memoryAGet32(ds, r32[ecx] + 0x40));
    { pc = 0x402f58; break; }
  case 0x402ec0: // 0000:402ec0
    fld64(memoryAGet64(ds, 0x412ff0));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x402f1f; break; }
    fld64(memoryAGet64(ds, 0x412fe8));
    yield* sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    r32[ebx] = r32[eax];
    r32[ebx] -= 0x00000033;
    yield* sub_406e04();
    r32[edx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax] -= 0x0000000e;
    push32(r32[ebx]);
    push32(r32[eax]);
    r32[ecx] = (r32[edi] + r32[edx]) + 23;
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] <<= 4;
    r32[ecx] = memoryAGet32(ds, r32[ecx] + r32[edx]);
    push32(r32[ecx]);
    push32(r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    r32[edi] = memoryAGet32(ds, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    if (r32[edi] != 0x00000008)
        { pc = 0x402f1a; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x402f58; break; }
  case 0x402f1a: // 0000:402f1a
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
    { pc = 0x402f58; break; }
  case 0x402f1f: // 0000:402f1f
    fld64(memoryAGet64(ds, 0x412fe8));
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x1c);
    yield* sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    r32[eax] -= 0x00000033;
    push32(r32[eax]);
    yield* sub_406e04();
    r32[eax] -= 0x0000000e;
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[ecx] = (r32[edi] + r32[eax]) + 23;
    r32[ecx] <<= 4;
    r32[eax] = memoryAGet32(ds, r32[ecx] + r32[edx]);
    push32(r32[eax]);
    push32(r32[esi]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[ebx] + 0x4c));
  case 0x402f58: // 0000:402f58
    r32[esp] += 0x00000010;
  case 0x402f5b: // 0000:402f5b
    r32[edi] = 0xffffff84;
  case 0x402f60: // 0000:402f60
    r32[eax] = memoryAGet32(ds, 0x40ffc0);
    r32[ecx] = 0x00000054;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[ecx]);
    memoryASet32(ss, r32[ebp] + 0x8, r32[edx]);
    fild32(memoryAGet32(ss, r32[ebp] + 0x8));
    fmul64(memoryAGet64(ds, 0x40d240));
    yield* sub_406e04();
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = r32[edi];
    r32[ecx] -= r32[eax];
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x340);
    push32(r32[ecx]);
    push32(0x00000235);
    push32(r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    push32(r32[esi]);
    r32[ebx] = memoryAGet32(ds, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    if (r32[ebx] != 0x00000008)
        { pc = 0x402fa8; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x402fab; break; }
  case 0x402fa8: // 0000:402fa8
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x402fab: // 0000:402fab
    r32[eax] = memoryAGet32(ds, 0x40ffc0);
    r32[ecx] = 0x00000054;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[ecx]);
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x1c);
    r32[esp] += 0x00000010;
    memoryASet32(ss, r32[ebp] + 0x8, r32[edx]);
    fild32(memoryAGet32(ss, r32[ebp] + 0x8));
    fmul64(memoryAGet64(ds, 0x40d240));
    yield* sub_406e04();
    r32[edx] = r32[edi];
    r32[edx] -= r32[eax];
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    push32(r32[edx]);
    push32(0xffffffc7);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x340);
    push32(r32[ecx]);
    push32(r32[esi]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[ebx] + 0x4c));
    r32[edi] += 0x0000007c;
    r32[esp] += 0x00000010;
    if (r32s[edi] < signed32(0x000001f0))
        { pc = 0x402f60; break; }
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x60);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x1c);
    if (memoryAGet32(ds, r32[ecx]) != 0x00000008)
        { pc = 0x403017; break; }
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    push32(0x00000064);
    push32(0x00000014);
    push32(r32[eax]);
    push32(r32[esi]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x403023; break; }
  case 0x403017: // 0000:403017
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x1c);
    push32(0x00000064);
    push32(0x00000014);
    push32(r32[eax]);
    push32(r32[esi]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[ecx] + 0x40));
  case 0x403023: // 0000:403023
    r32[eax] = memoryAGet32(ds, 0x41301c);
    r32[esp] += 0x00000010;
    if (!r32[eax])
        { pc = 0x4030d3; break; }
    r32[edx] = 0x000000db;
    push32(r32[eax]);
    r32[edx] -= r32[eax];
    push32(0x00000010);
    r32[ecx] = 0x00000064;
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] -= r32[eax];
    push32(0x0000001f);
    push32(r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x50);
    push32(0x00000000);
    push32(r32[esi]);
    push32(r32[eax]);
    alleg40.blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    r32[esp] += 0x00000020;
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x40);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    if (memoryAGet32(ds, r32[edx]) != 0x00000008)
        { pc = 0x403080; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x1c);
    push32(0x000000d2);
    push32(0xfffffff6);
    push32(r32[eax]);
    push32(r32[esi]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[ecx] + 0x44));
    { pc = 0x40308f; break; }
  case 0x403080: // 0000:403080
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    push32(0x000000d2);
    push32(0xfffffff6);
    push32(r32[eax]);
    push32(r32[esi]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x40308f: // 0000:40308f
    r32[eax] = memoryAGet32(ds, 0x413020);
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    r32[esp] += 0x00000010;
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x130);
    push32(r32[eax]);
    push32(0x0040e030);
    push32(0xffffffff);
    push32(0x000000d6);
    push32(0x00000028);
    push32(r32[edx]);
    push32(r32[esi]);
    alleg40.textprintf_centre(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    push32(0x000000ef);
    push32(0x000000e0);
    yield* sub_4022b0();
    r32[esp] += 0x00000024;
    memoryASet32(ss, r32[ebp] - 20, 0x00000001);
  case 0x4030d3: // 0000:4030d3
    r32[eax] = memoryAGet32(ds, 0x413324);
    if (r32s[eax] >= signed32(0x000001e0))
        { pc = 0x40310c; break; }
    if (r32s[eax] <= signed32(0x000000fa))
        { pc = 0x40310c; break; }
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000003;
    idiv32(r32[ecx]);
    r32[edi] = r32[edx];
    r32[edi]--;
    memoryASet32(ss, r32[ebp] - 16, r32[edi]);
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000003;
    idiv32(r32[ecx]);
    r32[edx]--;
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
    { pc = 0x403112; break; }
  case 0x40310c: // 0000:40310c
    r32[edi] = memoryAGet32(ss, r32[ebp] - 16);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
  case 0x403112: // 0000:403112
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = r32[edx] + 10;
    r32[edx] = r32[edi] + 4;
    push32(r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x20);
    push32(r32[edx]);
    push32(r32[eax]);
    push32(r32[esi]);
    r32[edi] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ebx] = memoryAGet32(ds, r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x1c);
    if (r32[ebx] != 0x00000008)
        { pc = 0x403136; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edi] + 0x44));
    { pc = 0x403139; break; }
  case 0x403136: // 0000:403136
    yield* indirectCall(cs, memoryAGet32(ds, r32[edi] + 0x40));
  case 0x403139: // 0000:403139
    r32[eax] = memoryAGet32(ds, 0x413324);
    r32[esp] += 0x00000010;
    if (r32s[eax] >= signed32(0x000001e0))
        { pc = 0x403171; break; }
    if (r32s[eax] <= signed32(0x000000c8))
        { pc = 0x403171; break; }
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000003;
    idiv32(r32[ecx]);
    r32[edx]--;
    memoryASet32(ss, r32[ebp] - 16, r32[edx]);
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000003;
    idiv32(r32[ecx]);
    r32[edx]--;
    memoryASet32(ss, r32[ebp] - 12, r32[edx]);
  case 0x403171: // 0000:403171
    r32[eax] = memoryAGet32(ds, 0x413328);
    if (!r32[eax])
        { pc = 0x40320d; break; }
    r32[eax] = memoryAGet32(ds, 0x413328);
    r32[ecx] = 0x000005dc;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[ecx]);
    memoryASet32(ss, r32[ebp] + 0x8, r32[edx]);
    fild32(memoryAGet32(ss, r32[ebp] + 0x8));
    fmul64(memoryAGet64(ds, 0x40d238));
    fcom64(memoryAGet64(ds, 0x40d1f0));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x4031bb; break; }
    r32[edx] = memoryAGet32(ds, 0x40d110);
    fstp80();
    r32[eax] = memoryAGet32(ds, r32[edx]);
    memoryASet32(ds, r32[eax], 0x00000022);
    r32[eax] = 0x7fffffff;
    { pc = 0x40320f; break; }
  case 0x4031bb: // 0000:4031bb
    fcom64(memoryAGet64(ds, 0x40d1e8));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4031df; break; }
    r32[ecx] = memoryAGet32(ds, 0x40d110);
    r32[eax] = 0x80000001;
    fstp80();
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    memoryASet32(ds, r32[edx], 0x00000022);
    { pc = 0x40320f; break; }
  case 0x4031df: // 0000:4031df
    fcom64(memoryAGet64(ds, 0x40d1e0));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4031f4; break; }
    fld64(memoryAGet64(ds, 0x40d1d8));
    { pc = 0x4031fa; break; }
  case 0x4031f4: // 0000:4031f4
    fld64(memoryAGet64(ds, 0x40d1d0));
  case 0x4031fa: // 0000:4031fa
    fxch80(st(0));
    fmul64(memoryAGet64(ds, 0x40d1c8));
    fadd80(st(1));
    yield* sub_406e04();
    fstp80();
    { pc = 0x40320f; break; }
  case 0x40320d: // 0000:40320d
    r32[eax] = 0;
  case 0x40320f: // 0000:40320f
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    push32(0x00000000);
    push32(0x00010000);
    push32(r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x30);
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[ecx]);
    r32[eax] = r32[edx];
    r32[eax] <<= 15;
    push32(r32[eax]);
    r32[eax] = r32[edi];
    r32[eax] <<= 15;
    push32(r32[eax]);
    r32[eax] = r32[edx];
    r32[eax] <<= 16;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[edx] += 0x0000001c;
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[edx] <<= 16;
    r32[eax] += r32[edx];
    push32(r32[eax]);
    r32[eax] = r32[edi];
    r32[eax] <<= 16;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ss, r32[ebp] - 16);
    r32[edx] += 0x00000020;
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[edx] <<= 16;
    r32[eax] += r32[edx];
    push32(r32[eax]);
    push32(r32[ecx]);
    push32(r32[esi]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[ebx] + 0xa0));
    r32[eax] = memoryAGet32(ds, 0x40fcac);
    r32[esp] += 0x00000024;
    if (!r32[eax])
        { pc = 0x4032a2; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] - 20);
    if (r32[eax])
        { pc = 0x40328d; break; }
    push32(0x000000ef);
    push32(0x000000e0);
    yield* sub_4022b0();
    r32[esp] += 0x00000008;
  case 0x40328d: // 0000:40328d
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    yield* sub_402320();
    r32[esp] += 0x00000004;
    r32[ebx] = 0x00000001;
    { pc = 0x4032a5; break; }
  case 0x4032a2: // 0000:4032a2
    r32[ebx] = memoryAGet32(ss, r32[ebp] - 20);
  case 0x4032a5: // 0000:4032a5
    r32[eax] = memoryAGet32(ds, 0x413028);
    if (!r32[eax])
        { pc = 0x40334a; break; }
    r32[edi] = memoryAGet32(ds, 0x413320);
    r32[ecx] = 0x000001e0;
    r32[ecx] -= r32[eax];
    r32[eax] = memoryAGet32(ds, r32[edi]);
    push32(r32[ecx]);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[edx] = r32[eax];
    r32[eax] = 0x00000140;
    r32[edx] = sar32(r32[edx], 0x00000001);
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ds, r32[edi] + 0x1c);
    push32(r32[eax]);
    push32(r32[edi]);
    flags.zero = memoryAGet32(ds, r32[edx]) == 0x00000008;
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    push32(r32[esi]);
    if (!flags.zero)
        { pc = 0x4032e3; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x4032e6; break; }
  case 0x4032e3: // 0000:4032e3
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x4032e6: // 0000:4032e6
    r32[eax] = memoryAGet32(ds, 0x413008);
    r32[edi] = memoryAGet32(ds, 0x413028);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[esp] += 0x00000010;
    r32[ecx] = 0x00000244;
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x130);
    push32(0x0040ea74);
    r32[ecx] -= r32[edi];
    push32(0xffffffff);
    push32(r32[ecx]);
    push32(0x00000140);
    push32(r32[eax]);
    push32(r32[esi]);
    alleg40.textprintf_centre(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[eax] = memoryAGet32(ds, 0x413028);
    r32[esp] += 0x0000001c;
    if (r32s[eax] >= signed32(0x0000012c))
        { pc = 0x403334; break; }
    r32[eax] += 0x00000008;
    memoryASet32(ds, 0x413028, r32[eax]);
  case 0x403334: // 0000:403334
    if (r32[ebx])
        { pc = 0x40334a; break; }
    push32(0x000000ef);
    push32(0x000000e0);
    yield* sub_4022b0();
    r32[esp] += 0x00000008;
  case 0x40334a: // 0000:40334a
    r32[eax] = memoryAGet32(ds, 0x413008);
    r32[edx] = memoryAGet32(ds, 0x41300c);
    r32[edi] = memoryAGet32(ds, 0x40d18c);
    r32[ecx] = r32[eax] + (r32[eax] * 4);
    r32[eax] = r32[edx] + (r32[ecx] * 2);
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    push32(r32[eax]);
    push32(0x0040ea68);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x130);
    push32(0xffffffff);
    push32(0x000001b8);
    push32(0x00000008);
    push32(r32[edx]);
    push32(r32[esi]);
    yield* indirectCall(cs, r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x40fa30);
    r32[esp] += 0x0000001c;
    if (!r32[eax])
        { pc = 0x403419; break; }
    fld64(memoryAGet64(ds, 0x412fe8));
    yield* sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    push32(r32[eax]);
    yield* sub_406e04();
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x40d0d4);
    push32(0x0040ea60);
    push32(0x0000000f);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    push32(0x00000000);
    push32(0x000000c8);
    push32(r32[ecx]);
    push32(r32[esi]);
    yield* indirectCall(cs, r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x40fa30);
    r32[esp] += 0x00000020;
    if (!r32[eax])
        { pc = 0x403419; break; }
    r32[edx] = memoryAGet32(ds, 0x413038);
    r32[eax] = memoryAGet32(ds, 0x40d0d4);
    push32(r32[edx]);
    push32(0x0040e030);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    push32(0x0000000f);
    push32(0x0000000a);
    push32(0x000000c8);
    push32(r32[ecx]);
    push32(r32[esi]);
    yield* indirectCall(cs, r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x40fa30);
    r32[esp] += 0x0000001c;
    if (!r32[eax])
        { pc = 0x403419; break; }
    r32[edx] = memoryAGet32(ds, 0x40fcb0);
    r32[eax] = memoryAGet32(ds, 0x40d0d4);
    push32(r32[edx]);
    push32(0x0040ea5c);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    push32(0x0000000f);
    push32(0x00000000);
    push32(0x00000000);
    push32(r32[ecx]);
    push32(r32[esi]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x0000001c;
  case 0x403419: // 0000:403419
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp];
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_403420() // 0000:403420 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    push32(0x0040fcc0);
    yield* sub_404fc0();
    r32[esp] += 0x00000004;
    r32[esi] = 0x0000001e;
  case 0x403433: // 0000:403433
    push32(0x0040fcc0);
    yield* sub_404ff0();
    r32[esp] += 0x00000004;
    r32[esi]--;
    if (r32[esi])
        { pc = 0x403433; break; }
    push32(0x00412fe0);
    yield* sub_406620();
    r32[eax] = 0;
    push32(0x0040ffe0);
    memoryASet32(ds, 0x412fe0, 0x00000000);
    memoryASet32(ds, 0x412fe4, 0x40690000);
    memoryASet32(ds, 0x412fe8, 0x00000000);
    memoryASet32(ds, 0x412fec, 0x407af000);
    memoryASet32(ds, 0x413010, r32[eax]);
    memoryASet32(ds, 0x40fcac, r32[eax]);
    memoryASet32(ds, 0x413324, 0x000001e0);
    yield* sub_406600();
    r32[esp] += 0x00000008;
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_4034a0() // 0000:4034a0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] &= 0xfffffff8;
    r32[esp] -= 0x00000070;
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[esi]);
    r32[eax] |= 0xffffffff;
    r32[esi] = 0;
    r32[ebx] = 0;
    push32(r32[edi]);
    memoryASet32(ds, r32[esp] + 0x28, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x38, r32[esi]);
    memoryASet32(ds, r32[esp] + 0x18, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x3c, 0x000005dc);
    memoryASet32(ds, r32[esp] + 0x40, 0x00000bb8);
    memoryASet32(ds, r32[esp] + 0x44, 0x00001194);
    memoryASet32(ds, r32[esp] + 0x48, 0x00001770);
    memoryASet32(ds, r32[esp] + 0x4c, 0x00001d4c);
    memoryASet32(ds, r32[esp] + 0x50, 0x00002328);
    memoryASet32(ds, r32[esp] + 0x54, 0x001b7740);
    memoryASet32(ds, r32[esp] + 0x58, 0x00895440);
    memoryASet32(ds, r32[esp] + 0x2c, r32[esi]);
    memoryASet32(ds, r32[esp] + 0x24, 0x00000032);
    memoryASet32(ds, r32[esp] + 0x20, 0x00000001);
    memoryASet32(ds, r32[esp] + 0x30, r32[esi]);
    memoryASet32(ds, r32[esp] + 0x1c, r32[ebx]);
    yield* sub_401db0();
    memoryASet32(ds, 0x413328, r32[esi]);
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    memoryASet32(ds, 0x40ffc0, r32[esi]);
    yield* sub_402780();
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[ecx]);
    yield* sub_402250();
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    push32(0x00000008);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    push32(r32[eax]);
    alleg40.fade_in(stack32(0), stack32(1));
    r32[ecx] = memoryAGet32(ds, 0x40fa88);
    push32(r32[esi]);
    push32(r32[ecx]);
    yield* sub_401570();
    r32[ecx] = memoryAGet32(ds, 0x40fa60);
    r32[esp] += 0x00000018;
    if (r32[ecx] == r32[esi])
        { pc = 0x403592; break; }
    r32[edx] = memoryAGet32(ds, 0x40e044);
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    push32(r32[edx]);
    push32(r32[ecx]);
    r32[eax] = alleg40.play_sample(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
    r32[ecx] = memoryAGet32(ds, 0x40fa60);
    r32[esp] += 0x00000014;
  case 0x403592: // 0000:403592
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r32[ebp] = 0;
    { pc = 0x4035a1; break; }
  case 0x40359b: // 0000:40359b
    r32[ecx] = memoryAGet32(ds, 0x40fa60);
  case 0x4035a1: // 0000:4035a1
    memoryASet32(ds, 0x42bbc0, r32[ebp]);
    if (r32[ecx] == r32[ebp])
        { pc = 0x4035cc; break; }
    r32[eax] = memoryAGet32(ds, 0x40e044);
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    push32(r32[eax]);
    push32(r32[ecx]);
    alleg40.adjust_sample(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r32[esp] += 0x00000014;
  case 0x4035cc: // 0000:4035cc
    if (memoryAGet32(ds, 0x40fa30) == r32[ebp])
        { pc = 0x4036c9; break; }
    r8[cl] = memoryAGet(ds, r32[eax] + 0x54);
    if (!r8[cl])
        { pc = 0x4035f3; break; }
    memoryASet32(ds, 0x412ff8, 0x00000000);
    memoryASet32(ds, 0x412ffc, 0xc0300000);
  case 0x4035f3: // 0000:4035f3
    r8[cl] = memoryAGet(ds, r32[eax] + 0x1c);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x20);
    if (!r8[cl])
        { pc = 0x403611; break; }
    if (r32[esi] == r32[ebp])
        { pc = 0x403611; break; }
    push32(0x00000005);
    yield* sub_4024f0();
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r32[esp] += 0x00000004;
  case 0x403611: // 0000:403611
    r8[cl] = memoryAGet(ds, r32[eax] + 0x1d);
    if (!r8[cl])
        { pc = 0x40362b; break; }
    if (r32[esi] == r32[ebp])
        { pc = 0x40362b; break; }
    push32(0x0000000a);
    yield* sub_4024f0();
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r32[esp] += 0x00000004;
  case 0x40362b: // 0000:40362b
    r8[cl] = memoryAGet(ds, r32[eax] + 0x1e);
    if (!r8[cl])
        { pc = 0x403645; break; }
    if (r32[esi] == r32[ebp])
        { pc = 0x403645; break; }
    push32(0x00000014);
    yield* sub_4024f0();
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r32[esp] += 0x00000004;
  case 0x403645: // 0000:403645
    r8[cl] = memoryAGet(ds, r32[eax] + 0x1f);
    if (!r8[cl])
        { pc = 0x40365f; break; }
    if (r32[esi] == r32[ebp])
        { pc = 0x40365f; break; }
    push32(0x0000001e);
    yield* sub_4024f0();
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r32[esp] += 0x00000004;
  case 0x40365f: // 0000:40365f
    r8[cl] = memoryAGet(ds, r32[eax] + 0x20);
    if (!r8[cl])
        { pc = 0x403679; break; }
    if (r32[esi] == r32[ebp])
        { pc = 0x403679; break; }
    push32(0x00000028);
    yield* sub_4024f0();
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r32[esp] += 0x00000004;
  case 0x403679: // 0000:403679
    r8[cl] = memoryAGet(ds, r32[eax] + 0x21);
    if (!r8[cl])
        { pc = 0x403693; break; }
    if (r32[esi] == r32[ebp])
        { pc = 0x403693; break; }
    push32(0x00000032);
    yield* sub_4024f0();
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r32[esp] += 0x00000004;
  case 0x403693: // 0000:403693
    r8[cl] = memoryAGet(ds, r32[eax] + 0x1c);
    if (r8[cl])
        { pc = 0x4036c5; break; }
    r8[cl] = memoryAGet(ds, r32[eax] + 0x1d);
    if (r8[cl])
        { pc = 0x4036c5; break; }
    r8[cl] = memoryAGet(ds, r32[eax] + 0x1e);
    if (r8[cl])
        { pc = 0x4036c5; break; }
    r8[cl] = memoryAGet(ds, r32[eax] + 0x1f);
    if (r8[cl])
        { pc = 0x4036c5; break; }
    r8[cl] = memoryAGet(ds, r32[eax] + 0x20);
    if (r8[cl])
        { pc = 0x4036c5; break; }
    r8[cl] = memoryAGet(ds, r32[eax] + 0x21);
    memoryASet32(ds, r32[esp] + 0x20, 0x00000001);
    if (!r8[cl])
        { pc = 0x4036c9; break; }
  case 0x4036c5: // 0000:4036c5
    memoryASet32(ds, r32[esp] + 0x20, r32[ebp]);
  case 0x4036c9: // 0000:4036c9
    push32(0x0042bde0);
    yield* sub_402670();
    push32(0x00412fe0);
    yield* sub_406670();
    r32[eax] = memoryAGet32(ds, 0x41302c);
    r32[esp] += 0x00000008;
    if (r32[eax] == r32[ebp])
        { pc = 0x403721; break; }
    if (memoryAGet32(ds, 0x41301c) == r32[ebp])
        { pc = 0x403721; break; }
    if (memoryAGet32(ds, 0x40e054) == r32[ebp])
        { pc = 0x403721; break; }
    fld64(memoryAGet64(ds, 0x412fe8));
    yield* sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    r32[eax] -= 0x00000010;
    push32(r32[eax]);
    yield* sub_406e04();
    push32(r32[eax]);
    push32(0x0040ffe0);
    yield* sub_406500();
    r32[esp] += 0x0000000c;
  case 0x403721: // 0000:403721
    r32[esi] = 0x0040ffe0;
  case 0x403726: // 0000:403726
    if (memoryAGet32(ds, r32[esi]) == r32[ebp])
        { pc = 0x403733; break; }
    push32(r32[esi]);
    yield* sub_4065b0();
    r32[esp] += 0x00000004;
  case 0x403733: // 0000:403733
    r32[esi] += 0x00000018;
    if (r32s[esi] < signed32(0x00412fe0))
        { pc = 0x403726; break; }
    r32[edx] = memoryAGet32(ds, 0x40ffc0);
    r32[esi] = r32[edx];
    r32[esi] &= 0x8000000f;
    if (r32s[esi] >= 0)
        { pc = 0x403753; break; }
    r32[esi]--;
    r32[esi] |= 0xfffffff0;
    r32[esi]++;
  case 0x403753: // 0000:403753
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d2c0));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x40384e; break; }
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d2b8));
    r32[ecx] = 0x00000001;
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
    r16[ax] = fnstsw();
    if (!(r8[cl] & r8[ah]))
        { pc = 0x40378e; break; }
    r32[ecx] = 0x00000002;
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
  case 0x40378e: // 0000:40378e
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d2b0));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4037a6; break; }
    r32[ecx]++;
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
  case 0x4037a6: // 0000:4037a6
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d2a8));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4037be; break; }
    r32[ecx]++;
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
  case 0x4037be: // 0000:4037be
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d2a0));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4037d6; break; }
    r32[ecx]++;
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
  case 0x4037d6: // 0000:4037d6
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d298));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4037ee; break; }
    r32[ecx]++;
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
  case 0x4037ee: // 0000:4037ee
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d290));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x403806; break; }
    r32[ecx]++;
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
  case 0x403806: // 0000:403806
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d288));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x40381e; break; }
    r32[ecx]++;
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
  case 0x40381e: // 0000:40381e
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x403836; break; }
    r32[ecx]++;
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
  case 0x403836: // 0000:403836
    fild32(memoryAGet32(ds, r32[esp] + 0x14));
    r32[edx] += r32[ecx];
    memoryASet32(ds, 0x40ffc0, r32[edx]);
    fadd64(memoryAGet64(ds, 0x412fe8));
    memoryASet64(ds, 0x412fe8, fstp64());
  case 0x40384e: // 0000:40384e
    r32[eax] = memoryAGet32(ds, 0x413028);
    if (r32s[edx] <= signed32(0x00000064))
        { pc = 0x4038af; break; }
    if (r32[eax] != r32[ebp])
        { pc = 0x4038b9; break; }
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x18);
    if (r32[edi] != 0xffffffff)
        { pc = 0x40386d; break; }
    r32[edi] = 0;
    memoryASet32(ds, r32[esp] + 0x18, r32[edi]);
    { pc = 0x403871; break; }
  case 0x40386d: // 0000:40386d
    if (r32[edi] != r32[ebp])
        { pc = 0x403895; break; }
  case 0x403871: // 0000:403871
    if (!(memoryAGet(ds, 0x40ffc4) & 0x01))
        { pc = 0x4038bd; break; }
    fld64(memoryAGet64(ds, 0x412fe8));
    fadd64(memoryAGet64(ds, 0x40d1b8));
    r32[edx]++;
    memoryASet32(ds, 0x40ffc0, r32[edx]);
    memoryASet64(ds, 0x412fe8, fstp64());
    { pc = 0x4038bd; break; }
  case 0x403895: // 0000:403895
    fild32(memoryAGet32(ds, r32[esp] + 0x18));
    r32[edx] += r32[edi];
    memoryASet32(ds, 0x40ffc0, r32[edx]);
    fadd64(memoryAGet64(ds, 0x412fe8));
    memoryASet64(ds, 0x412fe8, fstp64());
    { pc = 0x4038bd; break; }
  case 0x4038af: // 0000:4038af
    if (r32[eax] != r32[ebp])
        { pc = 0x4038b9; break; }
    memoryASet32(ds, 0x413328, r32[ebp]);
  case 0x4038b9: // 0000:4038b9
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x18);
  case 0x4038bd: // 0000:4038bd
    r32[eax] = memoryAGet32(ds, 0x413324);
    if (r32s[eax] >= signed32(0x000001e0))
        { pc = 0x4038d6; break; }
    if (r32s[eax] <= signed32(0xffffff9c))
        { pc = 0x4038d6; break; }
    r32[eax] -= 0x00000002;
    memoryASet32(ds, 0x413324, r32[eax]);
  case 0x4038d6: // 0000:4038d6
    r32[ecx] = memoryAGet32(ds, 0x413328);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x2c);
    if (r32s[ecx] <= signed32(memoryAGet32(ds, r32[esp] + r32[eax] * 4 + 0x3c)))
        { pc = 0x403924; break; }
    flags.zero = r32[edi] == 0x00000005;
    if (r32s[edi] >= signed32(0x00000005))
        { pc = 0x403927; break; }
    r32[ecx] = memoryAGet32(ds, 0x40fa74);
    r32[edx] = r32[eax];
    r32[edx]++;
    r32[edi]++;
    push32(r32[ebp]);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x34, r32[edx]);
    memoryASet32(ds, r32[esp] + 0x20, r32[edi]);
    memoryASet32(ds, 0x413324, 0x000001df);
    yield* sub_401570();
    r32[edx] = memoryAGet32(ds, 0x40fa98);
    push32(r32[ebp]);
    push32(r32[edx]);
    yield* sub_401570();
    r32[edx] = memoryAGet32(ds, 0x40ffc0);
    r32[esp] += 0x00000010;
  case 0x403924: // 0000:403924
    flags.zero = r32[edi] == 0x00000005;
  case 0x403927: // 0000:403927
    if (!flags.zero)
        { pc = 0x403936; break; }
    r32[eax] = memoryAGet32(ds, 0x413328);
    r32[eax] -= 0x0000002d;
    memoryASet32(ds, 0x413328, r32[eax]);
  case 0x403936: // 0000:403936
    r32[edx] &= 0x8000000f;
    if (r32s[edx] >= 0)
        { pc = 0x403943; break; }
    r32[edx]--;
    r32[edx] |= 0xfffffff0;
    r32[edx]++;
  case 0x403943: // 0000:403943
    if (r32s[esi] <= r32s[edx])
        { pc = 0x403954; break; }
    push32(0x0040fcc0);
    yield* sub_404ff0();
    r32[esp] += 0x00000004;
  case 0x403954: // 0000:403954
    fld64(memoryAGet64(ds, 0x412fe8));
    yield* sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    push32(r32[eax]);
    yield* sub_406e04();
    r32[eax] -= 0x0000000b;
    push32(r32[eax]);
    push32(0x0040fcc0);
    yield* sub_405170();
    fld64(memoryAGet64(ds, 0x412fe8));
    r32[esi] = r32[eax];
    yield* sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    push32(r32[eax]);
    yield* sub_406e04();
    r32[eax] += 0x0000000b;
    push32(r32[eax]);
    push32(0x0040fcc0);
    yield* sub_405170();
    r32[ecx] = memoryAGet32(ds, 0x413010);
    r32[edi] = r32[eax];
    r32[esp] += 0x00000018;
    r32[eax] = r32[edi] + r32[esi];
    if (r32[eax] != r32[ebp])
        { pc = 0x4039c2; break; }
    if (r32[ecx] != 0x00000002)
        { pc = 0x4039c2; break; }
    r32[ecx] = 0x00000003;
    memoryASet32(ds, 0x413010, r32[ecx]);
  case 0x4039c2: // 0000:4039c2
    if (r32[eax] != r32[ebp])
        { pc = 0x4039dd; break; }
    if (r32[ecx] != r32[ebp])
        { pc = 0x4039d5; break; }
    r32[ecx] = 0x00000003;
    memoryASet32(ds, 0x413010, r32[ecx]);
  case 0x4039d5: // 0000:4039d5
    if (r32[eax] == r32[ebp])
        { pc = 0x403a67; break; }
  case 0x4039dd: // 0000:4039dd
    if (r32[ecx] == 0x00000001)
        { pc = 0x403a67; break; }
    if (r32[ecx] == 0x00000002)
        { pc = 0x403a67; break; }
    if (r32[ecx] == r32[ebp])
        { pc = 0x403a00; break; }
    r32[ecx] = memoryAGet32(ds, 0x40faa8);
    push32(0x00000001);
    push32(r32[ecx]);
    yield* sub_401570();
    r32[esp] += 0x00000008;
  case 0x403a00: // 0000:403a00
    r32[ecx] = 0;
    memoryASet32(ds, 0x413010, r32[ecx]);
    memoryASet32(ds, 0x412ff8, r32[ecx]);
    memoryASet32(ds, 0x412ffc, r32[ecx]);
    if (r32[esi] == r32[ebp])
        { pc = 0x403a28; break; }
    r32[edx] = r32[esi] - 9999;
    memoryASet32(ds, r32[esp] + 0x1c, r32[edx]);
    fild32(memoryAGet32(ds, r32[esp] + 0x1c));
    { pc = 0x403a3a; break; }
  case 0x403a28: // 0000:403a28
    if (r32[edi] == r32[ebp])
        { pc = 0x403a46; break; }
    r32[eax] = r32[edi] - 9999;
    memoryASet32(ds, r32[esp] + 0x1c, r32[eax]);
    fild32(memoryAGet32(ds, r32[esp] + 0x1c));
  case 0x403a3a: // 0000:403a3a
    fsubr64(memoryAGet64(ds, 0x412fe8)); // dc 2d e8 2f 41 00 : fsubr qword ptr [0x412fe8]
    memoryASet64(ds, 0x412fe8, fstp64());
  case 0x403a46: // 0000:403a46
    memoryASet32(ds, 0x41302c, r32[ebp]);
    if (r32[esi] == r32[edi])
        { pc = 0x403a5f; break; }
    flags.carry = r32[esi] != 0;
    r32[esi] = -r32[esi];
    r32[esi] = -flags.carry;
    r32[esi] += 0x00000002;
    memoryASet32(ds, 0x413034, r32[esi]);
    { pc = 0x403a79; break; }
  case 0x403a5f: // 0000:403a5f
    memoryASet32(ds, 0x413034, r32[ebp]);
    { pc = 0x403a79; break; }
  case 0x403a67: // 0000:403a67
    if (memoryAGet32(ds, 0x41302c) == r32[ebp])
        { pc = 0x403a79; break; }
    memoryASet32(ds, 0x413030, memoryAGet32(ds, 0x413030) + 0x00080000);
  case 0x403a79: // 0000:403a79
    r32[eax] = memoryAGet32(ds, 0x41301c);
    if (r32[eax] == r32[ebp])
        { pc = 0x403aba; break; }
    r32[eax]--;
    memoryASet32(ds, 0x41301c, r32[eax]);
    if (r32[eax])
        { pc = 0x403aba; break; }
    if (signed32(memoryAGet32(ds, 0x413024)) <= signed32(0x00000001))
        { pc = 0x403aba; break; }
    r32[eax] = memoryAGet32(ds, 0x413020);
    r32[edx] = memoryAGet32(ds, 0x41300c);
    r32[ecx] = r32[eax];
    push32(r32[eax]);
    r32[ecx] = r32s[ecx] * r32s[eax];
    r32[edx] += r32[ecx];
    memoryASet32(ds, 0x41300c, r32[edx]);
    yield* sub_4024f0();
    r32[ecx] = memoryAGet32(ds, 0x413010);
    r32[esp] += 0x00000004;
  case 0x403aba: // 0000:403aba
    if (r32[ecx] != r32[ebp])
        { pc = 0x403b6b; break; }
    fld64(memoryAGet64(ds, 0x412fe8));
    yield* sub_406e04();
    push32(r32[eax]);
    push32(0x0040fcc0);
    yield* sub_4051e0();
    r32[ecx] = r32[eax];
    r32[esp] += 0x00000008;
    r32[ecx]--;
    r32[eax] = 0x66666667;
    imul32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, 0x413008);
    r32[edx] = sar32(r32[edx], 0x00000001);
    r32[eax] = r32[edx];
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    if (r32s[edx] < r32s[ecx])
        { pc = 0x403b53; break; }
    r32[eax] = r32[edx];
    r32[eax] -= r32[ecx];
    r32[ecx] = 0x00000001;
    flags.zero = r32[eax] == r32[ecx];
    if (r32s[eax] <= r32s[ecx])
        { pc = 0x403b41; break; }
    if (memoryAGet32(ds, 0x41301c) == r32[ebp])
        { pc = 0x403b2a; break; }
    r32[edi] = memoryAGet32(ds, 0x413020);
    r32[esi] = memoryAGet32(ds, 0x413024);
    r32[edi] += r32[eax];
    r32[esi]++;
    memoryASet32(ds, 0x413020, r32[edi]);
    memoryASet32(ds, 0x413024, r32[esi]);
    { pc = 0x403b35; break; }
  case 0x403b2a: // 0000:403b2a
    memoryASet32(ds, 0x413020, r32[eax]);
    memoryASet32(ds, 0x413024, r32[ecx]);
  case 0x403b35: // 0000:403b35
    memoryASet32(ds, 0x41301c, 0x00000064);
    flags.zero = r32[eax] == r32[ecx];
  case 0x403b41: // 0000:403b41
    if (!flags.zero)
        { pc = 0x403b65; break; }
    if (memoryAGet32(ds, 0x41301c) == r32[ebp])
        { pc = 0x403b65; break; }
    memoryASet32(ds, 0x41301c, r32[ecx]);
    { pc = 0x403b65; break; }
  case 0x403b53: // 0000:403b53
    if (memoryAGet32(ds, 0x41301c) == r32[ebp])
        { pc = 0x403b65; break; }
    memoryASet32(ds, 0x41301c, 0x00000001);
  case 0x403b65: // 0000:403b65
    memoryASet32(ds, 0x413008, r32[edx]);
  case 0x403b6b: // 0000:403b6b
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d280));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x403ba7; break; }
    if (memoryAGet32(ds, 0x413028) != r32[ebp])
        { pc = 0x403ba7; break; }
    r32[ecx] = memoryAGet32(ds, 0x40fa9c);
    r32[ebx] = 0x00000001;
    push32(r32[ebp]);
    push32(r32[ecx]);
    memoryASet32(ds, 0x41301c, r32[ebp]);
    memoryASet32(ds, 0x413028, r32[ebx]);
    yield* sub_401570();
    r32[esp] += 0x00000008;
  case 0x403ba7: // 0000:403ba7
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d278));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x403bd8; break; }
    if (memoryAGet32(ds, r32[esp] + 0x30) != r32[ebp])
        { pc = 0x403bd8; break; }
    r32[edx] = memoryAGet32(ds, 0x40fa78);
    push32(r32[ebp]);
    push32(r32[edx]);
    memoryASet32(ds, r32[esp] + 0x38, 0x00000002);
    yield* sub_401570();
    r32[esp] += 0x00000008;
  case 0x403bd8: // 0000:403bd8
    if (r32[ebx] == r32[ebp])
        { pc = 0x403bdd; break; }
    r32[ebx]++;
  case 0x403bdd: // 0000:403bdd
    r32[eax] = memoryAGet32(ds, 0x413008);
    r32[eax] = r32[eax] + (r32[eax] * 4);
    if (r32s[ebx] > r32s[eax])
        { pc = 0x403bf1; break; }
    if (r32s[ebx] <= signed32(0x000000fa))
        { pc = 0x403c1a; break; }
  case 0x403bf1: // 0000:403bf1
    r32[ecx] = memoryAGet32(ds, 0x40faa0);
    push32(r32[ebp]);
    push32(r32[ecx]);
    yield* sub_401570();
    r32[edx] = memoryAGet32(ds, 0x40fa9c);
    push32(r32[edx]);
    alleg40.stop_sample(stack32(0));
    r32[esp] += 0x0000000c;
    r32[ebx] = 0;
    memoryASet32(ds, 0x413040, 0x00000018);
  case 0x403c1a: // 0000:403c1a
    r32[eax] = memoryAGet32(ds, 0x413008);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x24);
    if (r32s[eax] < r32s[ecx])
        { pc = 0x403cab; break; }
    r32[ecx] = memoryAGet32(ds, 0x40fa90);
    push32(r32[ebp]);
    push32(r32[ecx]);
    yield* sub_401570();
    r32[eax] = memoryAGet32(ds, 0x40e054);
    r32[esp] += 0x00000008;
    if (r32[eax] == r32[ebp])
        { pc = 0x403ca6; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[eax] = sar32(r32[eax], 0x00000001);
    if (r32s[eax] <= r32s[ebp])
        { pc = 0x403ca6; break; }
    r32[edi] = r32[eax];
  case 0x403c53: // 0000:403c53
    push32(0x000001e0);
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000258;
    idiv32(r32[ecx]);
    r32[edx] += 0x00000014;
    push32(r32[edx]);
    push32(0x0040ffe0);
    yield* sub_406500();
    r32[esp] += 0x0000000c;
    r32[esi] = r32[eax];
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x000000c8;
    idiv32(r32[ecx]);
    r32[eax] = 0x99999999;
    r32[ecx] = r32[esi] + (r32[esi] * 2);
    r32[edx] <<= 16;
    imul32(r32[edx]);
    r32[edx] = sar32(r32[edx], 0x02);
    r32[eax] = r32[edx];
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    r32[edi]--;
    memoryASet32(ds, r32[ecx] * 8 + 0x40fff0, r32[edx]);
    if (r32[edi])
        { pc = 0x403c53; break; }
  case 0x403ca6: // 0000:403ca6
    memoryASet32(ds, r32[esp] + 0x24, memoryAGet32(ds, r32[esp] + 0x24) + 0x00000032);
  case 0x403cab: // 0000:403cab
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[edx]);
    yield* sub_402780();
    r32[eax] = memoryAGet32(ds, 0x413040);
    r32[esp] += 0x00000004;
    if (r32[eax] == r32[ebp])
        { pc = 0x403d33; break; }
    r32[eax] = memoryAGet32(ds, 0x40d108);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x10);
    if (r32[ecx] == r32[ebp])
        { pc = 0x403cda; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ecx]);
    r32[esp] += 0x00000004;
  case 0x403cda: // 0000:403cda
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    push32(r32[edx]);
    push32(r32[eax]);
    push32(r32[ebp]);
    push32(r32[ebp]);
    yield* sub_406be3();
    r32[eax] &= 0x80000007;
    if (r32s[eax] >= 0)
        { pc = 0x403cf9; break; }
    r32[eax]--;
    r32[eax] |= 0xfffffff8;
    r32[eax]++;
  case 0x403cf9: // 0000:403cf9
    r32[ecx] = memoryAGet32(ds, 0x40d108);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[ebp]);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    push32(r32[eax]);
    alleg40.blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
    r32[ecx] = memoryAGet32(ds, 0x40d108);
    r32[esp] += 0x00000020;
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x14);
    if (r32[ecx] == r32[ebp])
        { pc = 0x403d2b; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ecx]);
    r32[esp] += 0x00000004;
  case 0x403d2b: // 0000:403d2b
    memoryASet32(ds, 0x413040, memoryAGet32(ds, 0x413040) - 1);
    { pc = 0x403d41; break; }
  case 0x403d33: // 0000:403d33
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    yield* sub_402250();
    r32[esp] += 0x00000004;
  case 0x403d41: // 0000:403d41
    if (memoryAGet32(ds, 0x413034) == r32[ebp])
        { pc = 0x403d7a; break; }
    r32[eax] = memoryAGet32(ds, 0x413038);
    if (r32[eax] == r32[ebp])
        { pc = 0x403d80; break; }
    if (r32[eax] != 0x0000000b)
        { pc = 0x403d75; break; }
    if (memoryAGet32(ds, 0x413010) != r32[ebp])
        { pc = 0x403d80; break; }
    r32[ecx] = memoryAGet32(ds, 0x40fa94);
    push32(0x00000001);
    push32(r32[ecx]);
    yield* sub_401570();
    r32[eax] = memoryAGet32(ds, 0x413038);
    r32[esp] += 0x00000008;
  case 0x403d75: // 0000:403d75
    if (r32[eax] != 0x00000032)
        { pc = 0x403d80; break; }
  case 0x403d7a: // 0000:403d7a
    memoryASet32(ds, 0x413038, r32[ebp]);
  case 0x403d80: // 0000:403d80
    push32(0x0042bde0);
    yield* sub_401200();
    r32[ecx] = memoryAGet32(ds, 0x413028);
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x403da3; break; }
    if (r32s[ecx] <= signed32(0x000000fa))
        { pc = 0x403da3; break; }
    memoryASet32(ds, r32[esp] + 0x28, r32[ebp]);
  case 0x403da3: // 0000:403da3
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r8[dl] = memoryAGet(ds, r32[eax] + 0x3b);
    if (!r8[dl])
        { pc = 0x403ee0; break; }
    if (r32[ecx] == r32[ebp])
        { pc = 0x403dc0; break; }
    memoryASet32(ds, r32[esp] + 0x28, r32[ebp]);
    { pc = 0x403ee0; break; }
  case 0x403dc0: // 0000:403dc0
    r32[edi] = memoryAGet32(ds, 0x413328);
    r32[esi] = 0;
  case 0x403dc8: // 0000:403dc8
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[ebp]);
    push32(0x000001e0);
    push32(r32[ebp]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    push32(r32[esi]);
    push32(r32[eax]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x28));
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[ebp]);
    push32(0x00000280);
    push32(r32[esi]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x1c);
    push32(r32[ebp]);
    push32(r32[eax]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[ecx] + 0x2c));
    r32[esi] += 0x00000002;
    r32[esp] += 0x00000028;
    if (r32s[esi] < signed32(0x00000280))
        { pc = 0x403dc8; break; }
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    r32[esi] = memoryAGet32(ds, 0x40d0c4);
    push32(0xffffffff);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x130);
    push32(0x000000a0);
    push32(0x00000140);
    push32(0x0040eb04);
    push32(r32[eax]);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[esi]);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    push32(0xffffffff);
    push32(0x000000d2);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x140);
    push32(0x00000140);
    push32(0x0040eaec);
    push32(r32[eax]);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[esi]);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    push32(0xffffffff);
    push32(0x000000f0);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x140);
    push32(0x00000140);
    push32(0x0040ead8);
    push32(r32[eax]);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[esi]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    r32[esp] += 0x00000048;
    push32(r32[edx]);
    yield* sub_402250();
    r32[eax] = memoryAGet32(ds, 0x40fa8c);
    push32(r32[ebp]);
    push32(r32[eax]);
    yield* sub_401570();
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r32[esp] += 0x0000000c;
    r8[cl] = memoryAGet(ds, r32[eax] + 0x3b);
    if (!r8[cl])
        { pc = 0x403eaa; break; }
  case 0x403ea3: // 0000:403ea3
    r8[cl] = memoryAGet(ds, r32[eax] + 0x3b);
    if (r8[cl])
        { pc = 0x403ea3; break; }
  case 0x403eaa: // 0000:403eaa
    alleg40.clear_keybuf();
    r32[esi] = memoryAGet32(ds, 0x40d0bc);
    yield* indirectCall(cs, r32[esi]);
    if (r32[eax])
        { pc = 0x403ec2; break; }
  case 0x403ebc: // 0000:403ebc
    yield* indirectCall(cs, r32[esi]);
    if (!r32[eax])
        { pc = 0x403ebc; break; }
  case 0x403ec2: // 0000:403ec2
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r8[cl] = memoryAGet(ds, r32[eax] + 0x3b);
    if (!r8[cl])
        { pc = 0x403eda; break; }
    memoryASet32(ds, r32[esp] + 0x28, r32[ebp]);
    memoryASet32(ds, r32[esp] + 0x38, 0x00000001);
  case 0x403eda: // 0000:403eda
    memoryASet32(ds, 0x413328, r32[edi]);
  case 0x403ee0: // 0000:403ee0
    r8[cl] = memoryAGet(ds, r32[eax] + 0x2f);
    if (!r8[cl])
        { pc = 0x403f09; break; }
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    push32(r32[eax]);
    push32(0x0040eacc);
    alleg40.save_pcx(stack32(0), stack32(1), stack32(2));
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r32[esp] += 0x0000000c;
  case 0x403f09: // 0000:403f09
    r8[cl] = memoryAGet(ds, r32[eax] + 0x40);
    if (r8[cl])
        { pc = 0x403f24; break; }
    r32[ecx] = memoryAGet32(ds, 0x42bbc0);
    if (r32[ecx] != r32[ebp])
        { pc = 0x403f24; break; }
  case 0x403f1a: // 0000:403f1a
    r32[ecx] = memoryAGet32(ds, 0x42bbc0);
//    if (r32[ecx] == r32[ebp])
//        { pc = 0x403f1a; break; }
  case 0x403f24: // 0000:403f24
    if (memoryAGet32(ds, r32[esp] + 0x28) != r32[ebp])
        { pc = 0x40359b; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x38);
    memoryASet32(ds, r32[esp] + 0x1c, r32[ebx]);
    if (r32[eax] != r32[ebp])
        { pc = 0x40460e; break; }
    r32[eax] = memoryAGet32(ds, 0x413008);
    r32[esi] = memoryAGet32(ds, 0x41300c);
    r32[ecx] = memoryAGet32(ds, 0x40eac8);
    r32[esp] -= 0x00000010;
    r32[edx] = r32[eax] + (r32[eax] * 4);
    memoryASet32(ds, r32[esp] + 0x4c, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x28, 0x000001e0);
    memoryASet32(ds, r32[esp] + 0x58, r32[eax]);
    r32[edx] = r32[esi] + (r32[edx] * 2);
    r32[esi] = r32[esp];
    memoryASet32(ds, r32[esp] + 0x54, r32[edx]);
    memoryASet32(ds, r32[esi], r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x50);
    memoryASet32(ds, r32[esi] + 0x4, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x8, r32[edx]);
    r32[edx] = memoryAGet32(ds, 0x40fa3c);
    push32(r32[edx]);
    memoryASet32(ds, r32[esi] + 0xc, r32[eax]);
    yield* sub_401250();
    r32[esp] += 0x00000014;
    if (!r32[eax])
        { pc = 0x40460e; break; }
    r32[ecx] = 0x00000008;
    r32[esi] = 0x0040eaa4;
    r32[edi] = r32[esp] + 92;
    r32[eax] = 0;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    movsb_ESEDI_DSESI();
    r32[edi] = r32[esp] + 92;
    r32[ecx] |= 0xffffffff;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r8[al] = memoryAGet(ds, r32[esp] + 0x3c);
    r8[dl] = memoryAGet(ds, r32[esp] + 0x3e);
    r32[ecx] = ~r32[ecx];
    r32[ecx] += 0xfffffffe;
    memoryASet(ds, r32[esp] + 0x30, r8[al]);
    r32[eax] = memoryAGet32(ds, 0x40faa4);
    memoryASet32(ds, r32[esp] + 0x28, r32[ecx]);
    r8[cl] = memoryAGet(ds, r32[esp] + 0x3d);
    push32(r32[ebp]);
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x28, 0x00000014);
    memoryASet32(ds, r32[esp] + 0x1c, r32[ebp]);
    memoryASet(ds, r32[esp] + 0x39, 0x00);
    memoryASet(ds, r32[esp] + 0x3a, r8[cl]);
    memoryASet(ds, r32[esp] + 0x3b, 0x00);
    memoryASet(ds, r32[esp] + 0x3c, r8[dl]);
    memoryASet(ds, r32[esp] + 0x3d, 0x00);
    memoryASet(ds, r32[esp] + 0x3e, 0x00);
    memoryASet(ds, r32[esp] + 0x3f, 0x00);
    memoryASet32(ds, r32[esp] + 0x40, r32[ebp]);
    yield* sub_401570();
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[esp] += 0x00000008;
    r32[esi] = 0x0000035c;
    r32[ebx] = 0;
  case 0x404014: // 0000:404014
    memoryASet32(ds, 0x42bbc0, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, 0x413028);
    r32[ecx] -= 0x00000010;
    r32[edi] -= 0x00000004;
    memoryASet32(ds, 0x413028, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[ecx]);
    r32[esi] -= 0x00000008;
    yield* sub_402780();
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[esp] += 0x00000004;
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x290);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[ebx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[edx] = r32[eax];
    r32[eax] = 0x00000140;
    r32[edx] = sar32(r32[edx], 0x00000001);
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    flags.zero = memoryAGet32(ds, r32[ebx]) == 0x00000008;
    push32(r32[eax]);
    r32[ebx] = memoryAGet32(ds, r32[edx] + 0x1c);
    push32(r32[ecx]);
    push32(r32[edx]);
    if (!flags.zero)
        { pc = 0x404074; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[ebx] + 0x44));
    { pc = 0x404077; break; }
  case 0x404074: // 0000:404074
    yield* indirectCall(cs, memoryAGet32(ds, r32[ebx] + 0x40));
  case 0x404077: // 0000:404077
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    r32[esp] += 0x00000010;
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x130);
    push32(0xffffffff);
    push32(r32[esi]);
    push32(0x00000140);
    push32(0x0040ea90);
    push32(r32[ecx]);
    push32(r32[edx]);
    alleg40.textout_centre(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x34);
    r32[ebx] = 0;
    r32[esp] += 0x00000018;
    if (r32[ecx] == r32[ebx])
        { pc = 0x4040b2; break; }
    r32[ecx]++;
    memoryASet32(ds, r32[esp] + 0x1c, r32[ecx]);
  case 0x4040b2: // 0000:4040b2
    r32[eax] = memoryAGet32(ds, 0x413008);
    r32[eax] = r32[eax] + (r32[eax] * 4);
    if (r32s[ecx] > r32s[eax])
        { pc = 0x4040c6; break; }
    if (r32s[ecx] <= signed32(0x000000fa))
        { pc = 0x4040f3; break; }
  case 0x4040c6: // 0000:4040c6
    r32[ecx] = memoryAGet32(ds, 0x40faa0);
    push32(r32[ebx]);
    push32(r32[ecx]);
    yield* sub_401570();
    r32[edx] = memoryAGet32(ds, 0x40fa9c);
    push32(r32[edx]);
    alleg40.stop_sample(stack32(0));
    r32[esp] += 0x0000000c;
    memoryASet32(ds, r32[esp] + 0x1c, r32[ebx]);
    memoryASet32(ds, 0x413040, 0x00000018);
    { pc = 0x4040fb; break; }
  case 0x4040f3: // 0000:4040f3
    if (memoryAGet32(ds, 0x413040) == r32[ebx])
        { pc = 0x40416b; break; }
  case 0x4040fb: // 0000:4040fb
    r32[eax] = memoryAGet32(ds, 0x40d108);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x10);
    if (r32[ecx] == r32[ebx])
        { pc = 0x404112; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ecx]);
    r32[esp] += 0x00000004;
  case 0x404112: // 0000:404112
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    push32(r32[edx]);
    push32(r32[eax]);
    push32(r32[ebx]);
    push32(r32[ebx]);
    yield* sub_406be3();
    r32[eax] &= 0x80000007;
    if (r32s[eax] >= 0)
        { pc = 0x404131; break; }
    r32[eax]--;
    r32[eax] |= 0xfffffff8;
    r32[eax]++;
  case 0x404131: // 0000:404131
    r32[ecx] = memoryAGet32(ds, 0x40d108);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[ebx]);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    push32(r32[eax]);
    alleg40.blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
    r32[ecx] = memoryAGet32(ds, 0x40d108);
    r32[esp] += 0x00000020;
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x14);
    if (r32[ecx] == r32[ebx])
        { pc = 0x404163; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ecx]);
    r32[esp] += 0x00000004;
  case 0x404163: // 0000:404163
    memoryASet32(ds, 0x413040, memoryAGet32(ds, 0x413040) - 1);
    { pc = 0x404179; break; }
  case 0x40416b: // 0000:40416b
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    yield* sub_402250();
    r32[esp] += 0x00000004;
  case 0x404179: // 0000:404179
    r32[ecx] = memoryAGet32(ds, 0x40d1a4);
    r8[al] = memoryAGet(ds, r32[ecx] + 0x40);
    if (r8[al])
        { pc = 0x404198; break; }
    r32[eax] = memoryAGet32(ds, 0x42bbc0);
    if (r32[eax] != r32[ebx])
        { pc = 0x404198; break; }
  case 0x40418f: // 0000:40418f
    r32[eax] = memoryAGet32(ds, 0x42bbc0);
    if (r32[eax] == r32[ebx])
        { pc = 0x40418f; break; }
  case 0x404198: // 0000:404198
    if (r32s[esi] > signed32(0x00000104))
        { pc = 0x404014; break; }
    memoryASet32(ds, r32[esp] + 0x18, r32[edi]);
    memoryASet32(ds, 0x413028, r32[ebx]);
    alleg40.clear_keybuf();
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x38);
  case 0x4041b8: // 0000:4041b8
    memoryASet32(ds, 0x42bbc0, 0x00000000);
    r32[edx] = memoryAGet32(ds, 0x40ffc4);
    r32[edx]++;
    memoryASet32(ds, 0x40ffc4, r32[edx]);
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    yield* sub_402780();
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    r32[esp] += 0x00000004;
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x290);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x1c);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ebx] = memoryAGet32(ds, r32[esi]);
    r32[eax] -= r32[edx];
    r32[edx] = r32[eax];
    r32[eax] = 0x00000140;
    r32[edx] = sar32(r32[edx], 0x00000001);
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    flags.zero = r32[ebx] == 0x00000008;
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[esi] = memoryAGet32(ds, r32[edx] + 0x1c);
    push32(r32[ebx]);
    push32(r32[eax]);
    push32(r32[ecx]);
    push32(r32[edx]);
    if (!flags.zero)
        { pc = 0x404219; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[esi] + 0x44));
    { pc = 0x40421c; break; }
  case 0x404219: // 0000:404219
    yield* indirectCall(cs, memoryAGet32(ds, r32[esi] + 0x40));
  case 0x40421c: // 0000:40421c
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x28);
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    r32[esp] += 0x00000010;
    r32[ebx] = memoryAGet32(ds, 0x40d0c4);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x130);
    r32[eax] = (r32[eax] + r32[eax]) + -100;
    push32(0xffffffff);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(0x00000140);
    push32(0x0040ea90);
    push32(r32[edx]);
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ebx]);
    r32[esp] += 0x00000018;
    if (r32[ebp])
        { pc = 0x40425f; break; }
    if (!(memoryAGet(ds, 0x40ffc4) & 0x04))
        { pc = 0x40429c; break; }
  case 0x40425f: // 0000:40425f
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    push32(0xffffffff);
    r32[edx] = r32[esp] + 52;
    r32[esi] = r32[ecx] + 150;
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x140);
    push32(r32[esi]);
    push32(0x0000012c);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[ecx]);
    push32(r32[edx]);
    yield* indirectCall(cs, r32[ebx]);
    r32[esp] += 0x00000018;
    if (r32[ebp] != 0x00000001)
        { pc = 0x40429c; break; }
    if (!(memoryAGet(ds, 0x40ffc4) & 0x04))
        { pc = 0x4042da; break; }
  case 0x40429c: // 0000:40429c
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    push32(0xffffffff);
    r32[ecx] = r32[esp] + 54;
    r32[esi] = r32[eax] + 150;
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x140);
    push32(r32[esi]);
    push32(0x00000140);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[ebx]);
    r32[esp] += 0x00000018;
    if (r32[ebp] != 0x00000002)
        { pc = 0x4042da; break; }
    if (!(memoryAGet(ds, 0x40ffc4) & 0x04))
        { pc = 0x404332; break; }
  case 0x4042da: // 0000:4042da
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    push32(0xffffffff);
    push32(r32[esi]);
    r32[edx] = r32[esp] + 60;
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x140);
    push32(0x00000154);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[ecx]);
    push32(r32[edx]);
    yield* indirectCall(cs, r32[ebx]);
    r32[esp] += 0x00000018;
    if (r32[ebp] != 0x00000003)
        { pc = 0x404332; break; }
    if (!(memoryAGet(ds, 0x40ffc4) & 0x04))
        { pc = 0x404332; break; }
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    push32(0xffffffff);
    push32(r32[esi]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x140);
    push32(0x00000168);
    push32(0x0040ea8c);
    push32(r32[ecx]);
    push32(r32[edx]);
    yield* indirectCall(cs, r32[ebx]);
    r32[esp] += 0x00000018;
  case 0x404332: // 0000:404332
    push32(0x000000ef);
    push32(0x000000e0);
    yield* sub_4022b0();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[esp] += 0x00000008;
    if (!r32[ecx])
        { pc = 0x404351; break; }
    r32[ecx]++;
    memoryASet32(ds, r32[esp] + 0x1c, r32[ecx]);
  case 0x404351: // 0000:404351
    r32[eax] = memoryAGet32(ds, 0x413008);
    r32[eax] = r32[eax] + (r32[eax] * 4);
    if (r32s[ecx] > r32s[eax])
        { pc = 0x404365; break; }
    if (r32s[ecx] <= signed32(0x000000fa))
        { pc = 0x404397; break; }
  case 0x404365: // 0000:404365
    r32[ecx] = memoryAGet32(ds, 0x40faa0);
    push32(0x00000000);
    push32(r32[ecx]);
    yield* sub_401570();
    r32[edx] = memoryAGet32(ds, 0x40fa9c);
    push32(r32[edx]);
    alleg40.stop_sample(stack32(0));
    r32[esp] += 0x0000000c;
    memoryASet32(ds, r32[esp] + 0x1c, 0x00000000);
    memoryASet32(ds, 0x413040, 0x00000018);
    { pc = 0x4043a0; break; }
  case 0x404397: // 0000:404397
    r32[eax] = memoryAGet32(ds, 0x413040);
    if (!r32[eax])
        { pc = 0x404413; break; }
  case 0x4043a0: // 0000:4043a0
    r32[eax] = memoryAGet32(ds, 0x40d108);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x10);
    if (!r32[ecx])
        { pc = 0x4043b7; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ecx]);
    r32[esp] += 0x00000004;
  case 0x4043b7: // 0000:4043b7
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    push32(r32[edx]);
    push32(r32[eax]);
    push32(0x00000000);
    push32(0x00000000);
    yield* sub_406be3();
    r32[eax] &= 0x80000007;
    if (r32s[eax] >= 0)
        { pc = 0x4043d8; break; }
    r32[eax]--;
    r32[eax] |= 0xfffffff8;
    r32[eax]++;
  case 0x4043d8: // 0000:4043d8
    r32[ecx] = memoryAGet32(ds, 0x40d108);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(0x00000000);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    push32(r32[eax]);
    alleg40.blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
    r32[ecx] = memoryAGet32(ds, 0x40d108);
    r32[esp] += 0x00000020;
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x14);
    if (!r32[ecx])
        { pc = 0x40440b; break; }
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ecx]);
    r32[esp] += 0x00000004;
  case 0x40440b: // 0000:40440b
    memoryASet32(ds, 0x413040, memoryAGet32(ds, 0x413040) - 1);
    { pc = 0x404421; break; }
  case 0x404413: // 0000:404413
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    yield* sub_402250();
    r32[esp] += 0x00000004;
  case 0x404421: // 0000:404421
    push32(0x0042bde0);
    yield* sub_401060();
    r32[esp] += 0x00000004;
    r32[eax] = alleg40.keypressed();
    if (!r32[eax])
        { pc = 0x404529; break; }
    if (memoryAGet32(ds, r32[esp] + 0x20) != 0x00000014)
        { pc = 0x404529; break; }
    r32[eax] = alleg40.readkey();
    r32[eax] &= 0x000000ff;
    r32[eax] -= 0x00000020;
    if (r32[eax] != 0xffffffe8)
        { pc = 0x404461; break; }
    r32[eax] = 0xffffffa4;
    { pc = 0x40446a; break; }
  case 0x404461: // 0000:404461
    if (r32[eax] == 0x00000020)
        { pc = 0x404529; break; }
  case 0x40446a: // 0000:40446a
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x28);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[ecx] = 0;
    if (r32s[edx] <= 0)
        { pc = 0x4044a9; break; }
  case 0x404478: // 0000:404478
    r8[dl] = memoryAGet(ds, r32[esp] + r32[ecx] + 0x5c);
    r32[ebx] = r8s[dl];
    if (r32[eax] != r32[ebx])
        { pc = 0x40449c; break; }
    memoryASet(ds, r32[esp] + r32[ebp] * 2 + 0x30, r8[dl]);
    r32[ebp]++;
    r32[edi] = 0x00000064;
    r32[esi] = r32[ecx];
    if (r32[ebp] != 0x00000003)
        { pc = 0x40449c; break; }
    memoryASet32(ds, r32[esp] + 0x20, 0x00000013);
  case 0x40449c: // 0000:40449c
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x28);
    r32[ecx]++;
    if (r32s[ecx] < r32s[edx])
        { pc = 0x404478; break; }
    memoryASet32(ds, r32[esp] + 0x14, r32[esi]);
  case 0x4044a9: // 0000:4044a9
    if (r32[edi])
        { pc = 0x404562; break; }
    push32(0x0042bde0);
    yield* sub_4011f0();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x4044da; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x28);
    r32[esi]++;
    memoryASet32(ds, r32[esp] + 0x14, r32[esi]);
    if (r32s[esi] <= r32s[eax])
        { pc = 0x4044d5; break; }
    r32[esi] = 0;
    memoryASet32(ds, r32[esp] + 0x14, r32[esi]);
  case 0x4044d5: // 0000:4044d5
    r32[edi] = 0x00000008;
  case 0x4044da: // 0000:4044da
    push32(0x0042bde0);
    yield* sub_4011e0();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x4044ff; break; }
    r32[esi]--;
    memoryASet32(ds, r32[esp] + 0x14, r32[esi]);
    if (r32s[esi] >= 0)
        { pc = 0x4044fa; break; }
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x28);
    memoryASet32(ds, r32[esp] + 0x14, r32[esi]);
  case 0x4044fa: // 0000:4044fa
    r32[edi] = 0x00000008;
  case 0x4044ff: // 0000:4044ff
    push32(0x0042bde0);
    yield* sub_401200();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x40455e; break; }
    r8[al] = memoryAGet(ds, r32[esp] + r32[esi] + 0x5c);
    if (r8[al] != 0xa4)
        { pc = 0x404532; break; }
    if (!r32[ebp])
        { pc = 0x404532; break; }
    memoryASet(ds, r32[esp] + r32[ebp] * 2 + 0x30, 0x2e);
    r32[ebp]--;
    r32[edi] = 0x00000064;
    { pc = 0x404562; break; }
  case 0x404529: // 0000:404529
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x14);
    { pc = 0x4044a9; break; }
  case 0x404532: // 0000:404532
    if (r32s[ebp] >= signed32(0x00000002))
        { pc = 0x404543; break; }
    if (r8[al] == 0xa4)
        { pc = 0x404557; break; }
    r32[ebp]++;
    r32[edi] = 0x00000064;
    { pc = 0x404562; break; }
  case 0x404543: // 0000:404543
    if (r8[al] == 0xa4)
        { pc = 0x404557; break; }
    if (memoryAGet32(ds, r32[esp] + 0x20) != 0x00000014)
        { pc = 0x404557; break; }
    memoryASet32(ds, r32[esp] + 0x20, 0x00000013);
    r32[ebp]++;
  case 0x404557: // 0000:404557
    r32[edi] = 0x00000064;
    { pc = 0x404562; break; }
  case 0x40455e: // 0000:40455e
    if (!r32[edi])
        { pc = 0x404563; break; }
  case 0x404562: // 0000:404562
    r32[edi]--;
  case 0x404563: // 0000:404563
    push32(0x0042bde0);
    yield* sub_401220();
    r32[esp] += 0x00000004;
    if (r32[eax])
        { pc = 0x404576; break; }
    r32[edi] = 0;
  case 0x404576: // 0000:404576
    if (r32s[ebp] >= signed32(0x00000003))
        { pc = 0x404583; break; }
    r8[cl] = memoryAGet(ds, r32[esp] + r32[esi] + 0x5c);
    memoryASet(ds, r32[esp] + r32[ebp] * 2 + 0x30, r8[cl]);
  case 0x404583: // 0000:404583
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    if (r32s[eax] >= signed32(0x00000014))
        { pc = 0x404591; break; }
    r32[eax]--;
    memoryASet32(ds, r32[esp] + 0x20, r32[eax]);
  case 0x404591: // 0000:404591
    r32[edx] = memoryAGet32(ds, 0x40d1a4);
    r8[cl] = memoryAGet(ds, r32[edx] + 0x40);
    if (r8[cl])
        { pc = 0x4045b2; break; }
    r32[ecx] = memoryAGet32(ds, 0x42bbc0);
    if (r32[ecx])
        { pc = 0x4045b2; break; }
  case 0x4045a8: // 0000:4045a8
    r32[ecx] = memoryAGet32(ds, 0x42bbc0);
    if (!r32[ecx])
        { pc = 0x4045a8; break; }
  case 0x4045b2: // 0000:4045b2
    if (r32[eax])
        { pc = 0x4041b8; break; }
    r8[al] = memoryAGet(ds, r32[esp] + 0x30);
    r8[cl] = memoryAGet(ds, r32[esp] + 0x32);
    r8[dl] = memoryAGet(ds, r32[esp] + 0x34);
    r32[esp] -= 0x00000010;
    memoryASet(ds, r32[esp] + 0x4c, r8[al]);
    memoryASet(ds, r32[esp] + 0x4d, r8[cl]);
    memoryASet(ds, r32[esp] + 0x4e, r8[dl]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4c);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x50);
    r32[eax] = r32[esp];
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x54);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x58);
    memoryASet32(ds, r32[eax] + 0x8, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0xc, r32[edx]);
    r32[eax] = memoryAGet32(ds, 0x40fa3c);
    push32(r32[eax]);
    yield* sub_401320();
    r32[ecx] = memoryAGet32(ds, 0x40fa3c);
    push32(r32[ecx]);
    yield* sub_401280();
    r32[esp] += 0x00000018;
    r32[ebp] = 0;
  case 0x40460e: // 0000:40460e
    r32[edx] = memoryAGet32(ds, 0x40fa7c);
    push32(r32[ebp]);
    push32(r32[edx]);
    yield* sub_401570();
    push32(0x00000008);
    alleg40.fade_out(stack32(0));
    r32[eax] = memoryAGet32(ds, 0x40fa60);
    push32(r32[eax]);
    alleg40.stop_sample(stack32(0));
    r32[ecx] = memoryAGet32(ds, 0x40d108);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    alleg40.clear_bitmap(stack32(0));
    r32[esp] += 0x00000014;
    r32[eax] = 0;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp];
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_404650() // 0000:404650 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] &= 0xfffffff8;
    r32[esp] -= 0x00000014;
    fild32(memoryAGet32(ds, 0x40e044));
    r32[eax] = memoryAGet32(ds, 0x40d108);
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    memoryASet64(ds, r32[esp] + 0x10, fst64());
    fmul64(memoryAGet64(ds, 0x40d2c8));
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    push32(r32[ecx]);
    memoryASet64(ds, r32[esp] + 0x1c, fstp64());
    alleg40.clear_bitmap(stack32(0));
    r32[edx] = memoryAGet32(ds, 0x40d108);
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    push32(0x000001e0);
    push32(0x00000280);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x420);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(r32[eax]);
    push32(r32[edx]);
    alleg40.blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[edx] = memoryAGet32(ds, 0x40d108);
    r32[esp] += 0x00000024;
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x410);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    push32(0x00000014);
    push32(0x000000fa);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    push32(r32[ecx]);
    push32(r32[eax]);
    r32[esi] = memoryAGet32(ds, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    if (r32[esi] != 0x00000008)
        { pc = 0x4046dd; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x4046e0; break; }
  case 0x4046dd: // 0000:4046dd
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x4046e0: // 0000:4046e0
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[edx] = memoryAGet32(ds, 0x40d108);
    r32[esp] += 0x00000010;
    r32[esi] = memoryAGet32(ds, 0x40d0c4);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x130);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    push32(0xffffffff);
    push32(0x0000012c);
    push32(0x00000140);
    push32(0x0040eb4c);
    push32(r32[ecx]);
    push32(r32[eax]);
    yield* indirectCall(cs, r32[esi]);
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    r32[eax] = memoryAGet32(ds, 0x40d108);
    push32(0xffffffff);
    push32(0x0000017c);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x140);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    push32(0x00000140);
    push32(0x0040eb30);
    push32(r32[edx]);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[esi]);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = memoryAGet32(ds, 0x40d108);
    push32(0xffffffff);
    push32(0x0000019a);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x140);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(0x00000140);
    push32(0x0040eb10);
    push32(r32[eax]);
    push32(r32[edx]);
    yield* indirectCall(cs, r32[esi]);
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[esp] += 0x00000048;
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    push32(0x00000010);
    push32(r32[ecx]);
    alleg40.fade_in(stack32(0), stack32(1));
    r32[esp] += 0x00000008;
    memoryASet32(ds, 0x42bbc0, 0x00000000);
    r32[edx] = memoryAGet32(ds, 0x40d1a4);
    r8[al] = memoryAGet(ds, r32[edx] + 0x3b);
    if (r8[al])
        { pc = 0x4047fd; break; }
    r32[ebx] = memoryAGet32(ds, 0x40d0cc);
    r32[esi] = memoryAGet32(ds, 0x40fa64);
  case 0x40479b: // 0000:40479b
    r32[eax] = memoryAGet32(ds, 0x42bbc0);
    if (r32s[eax] >= signed32(0x00000096))
        { pc = 0x4047fd; break; }
    r32[edi] = memoryAGet32(ds, 0x42bbc0);
    if (!r32[esi])
        { pc = 0x4047d3; break; }
    fld64(memoryAGet64(ds, r32[esp] + 0x10));
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    yield* sub_406e04();
    push32(r32[eax]);
    push32(r32[esi]);
    yield* indirectCall(cs, r32[ebx]);
    r32[esi] = memoryAGet32(ds, 0x40fa64);
    r32[esp] += 0x00000014;
  case 0x4047d3: // 0000:4047d3
    fld64(memoryAGet64(ds, r32[esp] + 0x10));
    fsub64(memoryAGet64(ds, r32[esp] + 0x18));
    memoryASet64(ds, r32[esp] + 0x10, fstp64());
    r32[eax] = memoryAGet32(ds, 0x42bbc0);
    if (r32[edi] != r32[eax])
        { pc = 0x4047f1; break; }
  case 0x4047e8: // 0000:4047e8
    r32[eax] = memoryAGet32(ds, 0x42bbc0);
    if (r32[edi] == r32[eax])
        { pc = 0x4047e8; break; }
  case 0x4047f1: // 0000:4047f1
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r8[cl] = memoryAGet(ds, r32[eax] + 0x3b);
    if (!r8[cl])
        { pc = 0x40479b; break; }
  case 0x4047fd: // 0000:4047fd
    push32(0x00000010);
    alleg40.fade_out(stack32(0));
    r32[esp] += 0x00000004;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp];
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_404810() // 0000:404810 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x40d108);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x420);
    r32[esi] = 0;
    push32(0x000001e0);
    push32(0x00000280);
    push32(r32[esi]);
    push32(r32[esi]);
    push32(r32[esi]);
    push32(r32[esi]);
    push32(r32[ecx]);
    push32(r32[eax]);
    alleg40.blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
    r32[ecx] = memoryAGet32(ds, 0x40d108);
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    push32(0x000001e0);
    push32(0x00000280);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x2c0);
    push32(r32[esi]);
    push32(r32[esi]);
    push32(r32[esi]);
    push32(r32[esi]);
    push32(r32[edx]);
    push32(r32[ecx]);
    alleg40.masked_blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
    r32[esp] += 0x00000040;
    push32(0x0042bde0);
    yield* sub_401220();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x404895; break; }
  case 0x40487a: // 0000:40487a
    push32(0x0042bde0);
    yield* sub_401060();
    push32(0x0042bde0);
    yield* sub_401220();
    r32[esp] += 0x00000008;
    if (r32[eax])
        { pc = 0x40487a; break; }
  case 0x404895: // 0000:404895
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    push32(0x00000008);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    push32(r32[eax]);
    alleg40.fade_in(stack32(0), stack32(1));
    r32[edi] = memoryAGet32(ds, 0x40d0b8);
    r32[esp] += 0x00000008;
  case 0x4048af: // 0000:4048af
    memoryASet32(ds, 0x42bbc0, 0x00000000);
    push32(0x000000ef);
    push32(0x000000e0);
    yield* sub_4022b0();
    push32(0x0042bde0);
    yield* sub_401060();
    push32(0x0042bde0);
    yield* sub_401200();
    r32[esp] += 0x00000010;
    if (!r32[eax])
        { pc = 0x4048e8; break; }
    r32[esi] = 0x00000001;
  case 0x4048e8: // 0000:4048e8
    r32[eax] = memoryAGet32(ds, 0x40d1a4);
    r8[cl] = memoryAGet(ds, r32[eax] + 0x3b);
    if (r8[cl])
        { pc = 0x4048fb; break; }
    r8[cl] = memoryAGet(ds, r32[eax] + 0x43);
    if (!r8[cl])
        { pc = 0x404900; break; }
  case 0x4048fb: // 0000:4048fb
    r32[esi] = 0x00000001;
  case 0x404900: // 0000:404900
    r8[cl] = memoryAGet(ds, r32[eax] + 0x2f);
    if (!r8[cl])
        { pc = 0x404922; break; }
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    r32[eax] = memoryAGet32(ds, 0x40d108);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    push32(r32[edx]);
    push32(r32[ecx]);
    push32(0x0040eb60);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x0000000c;
  case 0x404922: // 0000:404922
    r32[eax] = memoryAGet32(ds, 0x42bbc0);
    if (r32[eax])
        { pc = 0x404934; break; }
//  case 0x40492b: // 0000:40492b
//    r32[eax] = memoryAGet32(ds, 0x42bbc0);
//    if (!r32[eax])
//        { pc = 0x40492b; break; }
  case 0x404934: // 0000:404934
    if (!r32[esi])
        { pc = 0x4048af; break; }
    push32(0x00000008);
    alleg40.fade_out(stack32(0));
    r32[esp] += 0x00000004;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_404950() // 0000:404950 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x40fa84);
    push32(0x00000000);
    push32(r32[eax]);
    yield* sub_401570();
    r32[esp] += 0x00000008;
    r32[esp] += 4;
}
function* sub_404970() // 0000:404970 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x40fa80);
    push32(0x00000000);
    push32(r32[eax]);
    yield* sub_401570();
    r32[esp] += 0x00000008;
    r32[esp] += 4;
}
function* sub_404990() // 0000:404990 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(r32[ecx]);
    memoryASet32(ds, 0x40fab0, memoryAGet32(ds, 0x40fab0) + 1);
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x000000c8;
    idiv32(r32[ecx]);
    if (r32[edx] != 0x00000001)
        { pc = 0x4049b2; break; }
    memoryASet32(ds, 0x40faac, memoryAGet32(ds, 0x40faac) + 1);
  case 0x4049b2: // 0000:4049b2
    if (memoryAGet32(ds, 0x40faac) != 0x00000003)
        { pc = 0x4049c5; break; }
    memoryASet32(ds, 0x40faac, 0x00000000);
  case 0x4049c5: // 0000:4049c5
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x420);
    push32(0x000001e0);
    push32(0x00000280);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(r32[edx]);
    push32(r32[ecx]);
    alleg40.blit(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7));
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    r32[esp] += 0x00000020;
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x410);
    push32(0x00000014);
    push32(0x000000fa);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    push32(r32[eax]);
    push32(r32[ecx]);
    r32[esi] = memoryAGet32(ds, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    if (r32[esi] != 0x00000008)
        { pc = 0x404a22; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x404a25; break; }
  case 0x404a22: // 0000:404a22
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x404a25: // 0000:404a25
    r32[eax] = memoryAGet32(ds, 0x40fab0);
    r32[ecx] = memoryAGet32(ds, 0x40d114);
    r32[esp] += 0x00000010;
    r32[edx] = r32[eax] + (r32[eax] * 2);
    r32[eax] = r32[eax] + (r32[eax] * 4);
    r32[eax] <<= 16;
    r32[edx] <<= 16;
    r32[eax] -= 0x003fc000;
    r32[edx] -= 0x003fbff6;
    r32[eax] = sar32(r32[eax], 0x0f);
    r32[edx] = sar32(r32[edx], 0x0f);
    r32[eax] &= 0x000001ff;
    r32[edx] &= 0x000001ff;
    push32(r32[ebx]);
    r32[eax] = memoryAGet32(ds, r32[ecx] + r32[eax] * 4);
    r32[edx] = memoryAGet32(ds, r32[ecx] + r32[edx] * 4);
    r32[ecx] = r32[eax] + (r32[eax] * 4);
    r32[ecx] <<= 1;
    memoryASet32(ss, r32[ebp] - 4, r32[ecx]);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax] = sar32(r32[eax], 0x10);
    r32[esi] = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x40faac);
    push32(0x00000000);
    r32[eax] += 0x00000026;
    r32[edx] = r32[edx] + (r32[edx] * 4);
    r32[eax] <<= 4;
    r32[edi] = memoryAGet32(ds, 0x40fa34);
    push32(0x00010000);
    r32[esi] = memoryAGet32(ds, r32[eax] + r32[esi]);
    push32(r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[edi] + 0x1c);
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = r32[ebx];
    r32[edx] <<= 15;
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[edx] <<= 15;
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[ecx] = sar32(r32[ecx], 0x0f);
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
    r32[ecx] &= 0x00000001;
    r32[eax] = r32[ebx];
    r32[eax] <<= 16;
    r32[ecx] = (r32[ecx] + r32[edx]) + 10;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[ecx] <<= 16;
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[ecx] += r32[eax];
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[eax] <<= 16;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax] = sar32(r32[eax], 0x00000001);
    r32[eax] += 0x00280000;
    push32(r32[ecx]);
    push32(r32[eax]);
    push32(r32[esi]);
    push32(r32[edi]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0xa0));
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    push32(0xffffffff);
    push32(0x000000f0);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x140);
    push32(0x000001a4);
    push32(0x0040eb88);
    push32(r32[ecx]);
    push32(r32[edx]);
    alleg40.textout(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    r32[esp] += 0x0000003c;
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x2a0);
    r32[ebx] = pop32();
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    flags.zero = memoryAGet32(ds, r32[edx]) == 0x00000008;
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x1c);
    push32(0x0000010c);
    push32(0x000001a7);
    push32(r32[eax]);
    push32(r32[ecx]);
    if (!flags.zero)
        { pc = 0x404b40; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x404b43; break; }
  case 0x404b40: // 0000:404b40
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x404b43: // 0000:404b43
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    r32[esp] += 0x00000010;
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x140);
    r32[eax] = memoryAGet32(ds, 0x40fa3c);
    push32(0x00000104);
    push32(0x000001a4);
    push32(r32[ecx]);
    push32(r32[edx]);
    push32(r32[eax]);
    yield* sub_4014c0();
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000005);
    alleg40.drawing_mode(stack32(0), stack32(1), stack32(2), stack32(3));
    r32[ecx] = memoryAGet32(ds, 0x40d0dc);
    push32(0x000000c8);
    push32(0x000001c0);
    push32(0x0000027f);
    memoryASet32(ds, r32[ecx], 0x00413340);
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(0x000001c0);
    push32(0x00000000);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    push32(r32[eax]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x34));
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(0x00000096);
    push32(0x000001c1);
    push32(0x0000027f);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x1c);
    push32(0x000001c1);
    push32(0x00000000);
    push32(r32[eax]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[ecx] + 0x34));
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    r32[esp] += 0x00000054;
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    push32(0x00000064);
    push32(0x000001df);
    push32(0x0000027f);
    push32(0x000001c2);
    push32(0x00000000);
    push32(r32[eax]);
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x38));
    r32[eax] = memoryAGet32(ds, 0x40e714);
    push32(r32[eax]);
    push32(0x00423380);
    yield* sub_406a90();
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    push32(0x000001c2);
    push32(0x00000000);
    push32(r32[ecx]);
    push32(0x00423380);
    yield* sub_406930();
    r32[esp] += 0x00000030;
    if (r32[eax])
        { pc = 0x404c2a; break; }
    push32(0x00423380);
    yield* sub_406aa0();
    r32[esp] += 0x00000004;
  case 0x404c2a: // 0000:404c2a
    alleg40.solid_mode();
    r32[eax] = memoryAGet32(ds, 0x40fa30);
    flags.zero = r32[eax] == 0;
    r32[eax] = 0x0040eb7c;
    if (!flags.zero)
        { pc = 0x404c43; break; }
    r32[eax] = 0x0040fab4;
  case 0x404c43: // 0000:404c43
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    r32[esi] = memoryAGet32(ds, 0x40d190);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x150);
    push32(0x0042bbe0);
    push32(0x0040eb78);
    push32(0x0040eb6c);
    push32(0x00000000);
    push32(0x00000003);
    push32(0x0000027e);
    push32(r32[eax]);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[esi]);
    r32[eax] = memoryAGet32(ds, 0x40fa30);
    r32[esp] += 0x00000024;
    flags.zero = r32[eax] == 0;
    r32[eax] = 0x0040eb7c;
    if (!flags.zero)
        { pc = 0x404c8e; break; }
    r32[eax] = 0x0040fab4;
  case 0x404c8e: // 0000:404c8e
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    r32[ecx] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    push32(0x0042bbe0);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x150);
    push32(0x0040eb78);
    push32(0x0040eb6c);
    push32(0x00000069);
    push32(0x00000002);
    push32(0x0000027d);
    push32(r32[eax]);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[esi]);
    r32[eax] = memoryAGet32(ds, 0x40e038);
    r32[esi] = memoryAGet32(ds, 0x40d160);
    r32[edi] = memoryAGet32(ds, 0x40d180);
    r32[esp] += 0x00000024;
    if (!r32[eax])
        { pc = 0x404d11; break; }
    r32[eax] = memoryAGet32(ds, 0x40e050);
    if (!r32[eax])
        { pc = 0x404d08; break; }
    push32(0x00000000);
    push32(0x00000000);
    push32(0x000001e0);
    push32(0x00000280);
    push32(0x00000000);
    yield* indirectCall(cs, r32[esi]);
    r32[edx] = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ds, 0x40e038, 0x00000000);
    r32[eax] = memoryAGet32(ds, r32[edx]);
    push32(r32[eax]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000018;
  case 0x404d08: // 0000:404d08
    r32[eax] = memoryAGet32(ds, 0x40e038);
    if (r32[eax])
        { pc = 0x404d47; break; }
  case 0x404d11: // 0000:404d11
    r32[eax] = memoryAGet32(ds, 0x40e050);
    if (r32[eax])
        { pc = 0x404d47; break; }
    push32(0x00000000);
    push32(0x00000000);
    push32(0x000001e0);
    push32(0x00000280);
    push32(0x4458574e);
    yield* indirectCall(cs, r32[esi]);
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ds, 0x40e038, 0x00000001);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000018;
  case 0x404d47: // 0000:404d47
    push32(0x0040e058);
    yield* sub_4064b0();
    push32(0x0040e068);
    memoryASet32(ds, 0x40e040, r32[eax]);
    yield* sub_4064b0();
    r32[ecx] = memoryAGet32(ds, 0x40fa64);
    r32[esp] += 0x00000008;
    r32[edi] = pop32();
    memoryASet32(ds, 0x40e044, r32[eax]);
    r32[esi] = pop32();
    if (!r32[ecx])
        { pc = 0x404d8b; break; }
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    push32(r32[eax]);
    push32(r32[ecx]);
    alleg40.adjust_sample(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
    r32[esp] += 0x00000014;
  case 0x404d8b: // 0000:404d8b
    r32[esp] = r32[ebp];
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_404d90() // 0000:404d90 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    yield* sub_401600();
    if (r32[eax])
        { pc = 0x404db3; break; }
    push32(0x0040eb94);
    alleg40.allegro_message(stack32(0));
    r32[esp] += 0x00000004;
    alleg40.allegro_exit();
    r32[eax] = 0x00000001;
    r32[esp] += 4; return;
  case 0x404db3: // 0000:404db3
    r32[eax] = memoryAGet32(ds, 0x40d0e8);
    push32(r32[eax]);
    alleg40.set_palette(stack32(0));
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    push32(0xffffffff);
    push32(0x0000001e);
    push32(0x00000280);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x140);
    push32(0x0040e658);
    push32(r32[edx]);
    push32(0x00423380);
    yield* sub_406880();
    r32[eax] = memoryAGet32(ds, 0x40fa40);
    push32(0x00423348);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x130);
    memoryASet32(ds, 0x423340, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x2d0);
    memoryASet32(ds, 0x423368, r32[edx]);
    memoryASet32(ds, 0x42336c, 0x00000000);
    yield* sub_401000();
    push32(0x0042bde0);
    yield* sub_401000();
    r32[eax] = memoryAGet32(ds, 0x42bbc4);
    r32[esp] += 0x00000024;
    if (!r32[eax])
        { pc = 0x404e35; break; }
    memoryASet32(ds, 0x42bde0, 0xffffffff);
  case 0x404e35: // 0000:404e35
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[esi]);
    push32(r32[edi]);
    push32(0x00000000);
    push32(0x00423340);
    push32(0x0040e408);
    yield* sub_405480();
    r32[eax] = memoryAGet32(ds, 0x40fa64);
    r32[ebp] = memoryAGet32(ds, 0x40d174);
    r32[esp] += 0x0000000c;
    if (!r32[eax])
        { pc = 0x404e75; break; }
    r32[ecx] = memoryAGet32(ds, 0x40e044);
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    push32(r32[ecx]);
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ebp]);
    r32[esp] += 0x00000014;
  case 0x404e75: // 0000:404e75
    r32[esi] = memoryAGet32(ds, 0x40d0d0);
    r32[edi] = memoryAGet32(ds, 0x40d0b0);
    r32[ebx] = memoryAGet32(ds, 0x40d0c8);
  case 0x404e87: // 0000:404e87
    yield* sub_404990();
    r32[edx] = memoryAGet32(ds, 0x40fa34);
    push32(0x0000010e);
    push32(0x00000032);
    push32(0x00423340);
    push32(0x0040e408);
    push32(r32[edx]);
    yield* sub_4053a0();
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(r32[eax]);
    yield* sub_402250();
    r32[ecx] = memoryAGet32(ds, 0x40fa40);
    push32(0x00000008);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    yield* indirectCall(cs, r32[esi]);
    r32[eax] = memoryAGet32(ds, 0x40fa34);
    push32(0x0000010e);
    push32(0x00000032);
    push32(0x00404990);
    push32(r32[eax]);
    push32(0x0042bde0);
    push32(0x00423340);
    push32(0x0040e408);
    yield* sub_405680();
    r32[esp] += 0x0000003c;
    if (r32[eax] != 0x00000065)
        { pc = 0x404f3a; break; }
    push32(0x00000008);
    yield* indirectCall(cs, r32[edi]);
    r32[ecx] = memoryAGet32(ds, 0x40fa64);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[ebx]);
    r32[esp] += 0x00000008;
    yield* sub_403420();
    yield* sub_4034a0();
    r32[eax] = memoryAGet32(ds, 0x40fa64);
    if (!r32[eax])
        { pc = 0x404f2b; break; }
    r32[edx] = memoryAGet32(ds, 0x40e044);
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    push32(r32[edx]);
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ebp]);
    r32[esp] += 0x00000014;
  case 0x404f2b: // 0000:404f2b
    memoryASet32(ds, 0x42336c, 0x00000000);
    { pc = 0x404e87; break; }
  case 0x404f3a: // 0000:404f3a
    if (r32[eax] != 0x00000068)
        { pc = 0x404f5a; break; }
    push32(0x00000008);
    yield* indirectCall(cs, r32[edi]);
    r32[esp] += 0x00000004;
    yield* sub_404810();
    memoryASet32(ds, 0x42336c, 0x00000001);
    { pc = 0x404e87; break; }
  case 0x404f5a: // 0000:404f5a
    if (r32[eax] != 0x0000006b)
        { pc = 0x404e87; break; }
    push32(0x00000010);
    yield* indirectCall(cs, r32[edi]);
    yield* sub_404650();
    r32[eax] = memoryAGet32(ds, 0x40fa64);
    push32(r32[eax]);
    yield* indirectCall(cs, r32[ebx]);
    r32[esp] += 0x00000008;
    yield* sub_401c60();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = 0;
    r32[ebx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_404f90() // 0000:404f90 +long +stackDrop16
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[ecx]);
    push32(r32[edx]);
    push32(r32[eax]);
    push32(0x00404d90);
    r32[eax] = yield* alleg40._WinMain(stack32(0), stack32(1), stack32(2), stack32(3));
    r32[esp] += 0x00000014;
    r32[esp] += 20;
}
function* sub_404fc0() // 0000:404fc0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = 0x00000020;
    r32[edx] = 0;
    r32[eax] = r32[edi] + 16;
  case 0x404fcf: // 0000:404fcf
    memoryASet32(ds, r32[eax] - 16, 0xffffffff);
    memoryASet32(ds, r32[eax] - 4, r32[edx]);
    memoryASet32(ds, r32[eax], r32[edx]);
    r32[eax] += 0x00000018;
    r32[ecx]--;
    if (r32[ecx])
        { pc = 0x404fcf; break; }
    memoryASet32(ds, r32[edi] + 0x300, r32[edx]);
    r32[edi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_404ff0() // 0000:404ff0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x00000008;
    r32[edx] = 0x0000001f;
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edi] = r32[ebx];
  case 0x405001: // 0000:405001
    r32[eax] = r32[edi] + 24;
    r32[ecx] = 0x00000006;
    r32[esi] = r32[eax];
    r32[edx]--;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    r32[edi] = r32[eax];
    if (r32[edx])
        { pc = 0x405001; break; }
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x2f4);
    r32[eax] = 0x10624dd3;
    imul32(r32[ecx]);
    r32[edx] = sar32(r32[edx], 0x05);
    r32[eax] = r32[edx];
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    r32[edx] &= 0x80000003;
    if (r32s[edx] >= 0)
        { pc = 0x405036; break; }
    r32[edx]--;
    r32[edx] |= 0xfffffffc;
    r32[edx]++;
  case 0x405036: // 0000:405036
    r32[eax] = r32[ecx];
    memoryASet32(ds, r32[ebx] + 0x2fc, r32[edx]);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[esi] = 0x000000fa;
    r32[edi] = 0;
    idiv32(r32[esi]);
    if (r32[edx])
        { pc = 0x40506e; break; }
    r32[ecx]++;
    memoryASet32(ds, r32[ebx] + 0x2e8, r32[edi]);
    memoryASet32(ds, r32[ebx] + 0x2f4, r32[ecx]);
    memoryASet32(ds, r32[ebx] + 0x2ec, r32[edi]);
    memoryASet32(ds, r32[ebx] + 0x2f0, 0x00000028);
    { pc = 0x40512e; break; }
  case 0x40506e: // 0000:40506e
    r32[eax] = r32[ecx];
    r32[esi] = 0x00000005;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[esi]);
    if (r32[edx])
        { pc = 0x40511d; break; }
    r32[ecx]++;
    r32[eax] = 0x66666667;
    imul32(r32[ecx]);
    r32[edx] = sar32(r32[edx], 0x00000001);
    memoryASet32(ds, r32[ebx] + 0x2f4, r32[ecx]);
    r32[ecx] = r32[edx];
    r32[ecx] >>= 31;
    r32[edx] += r32[ecx];
    r32[eax] = 0x0000012c;
    r32[eax] -= r32[edx];
    memoryASet32(ds, r32[ebx] + 0x2e8, r32[edi]);
    memoryASet32(ds, r32[esp] + 0x18, r32[eax]);
    fild32(memoryAGet32(ds, r32[esp] + 0x18));
    fmul64(memoryAGet64(ds, 0x40d2d8));
    fmul64(memoryAGet64(ds, 0x40d2d0));
    fld64(memoryAGet64(ds, 0x40d1b8));
    fcomp80(st(1));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x4050db; break; }
    fstp80();
    memoryASet32(ds, r32[esp] + 0xc, 0x00000000);
    memoryASet32(ds, r32[esp] + 0x10, 0x3ff00000);
    { pc = 0x4050df; break; }
  case 0x4050db: // 0000:4050db
    memoryASet64(ds, r32[esp] + 0xc, fstp64());
  case 0x4050df: // 0000:4050df
    yield* sub_406be3();
    fld64(memoryAGet64(ds, r32[esp] + 0xc));
    r32[esi] = r32[eax];
    yield* sub_406e04();
    r32[ecx] = r32[eax];
    r32[eax] = r32[esi];
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[ecx]);
    r32[esi] = r32[edx];
    r32[esi] += 0x00000006;
    yield* sub_406be3();
    r32[ecx] = 0x0000001e;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] -= r32[esi];
    idiv32(r32[ecx]);
    r32[eax] = r32[edx] + 5;
    memoryASet32(ds, r32[ebx] + 0x2ec, r32[eax]);
    r32[eax] += r32[esi];
    memoryASet32(ds, r32[ebx] + 0x2f0, r32[eax]);
    { pc = 0x40512e; break; }
  case 0x40511d: // 0000:40511d
    r32[ecx]++;
    memoryASet32(ds, r32[ebx] + 0x2e8, 0xffffffff);
    memoryASet32(ds, r32[ebx] + 0x2f4, r32[ecx]);
  case 0x40512e: // 0000:40512e
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x2f4);
    r32[esi] = 0x00000032;
    r32[eax] = r32[ecx] - 1;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[esi]);
    if (r32[edx])
        { pc = 0x405160; break; }
    r32[eax] = 0x66666667;
    r32[edi] = pop32();
    imul32(r32[ecx]);
    r32[edx] = sar32(r32[edx], 0x00000001);
    r32[eax] = r32[edx];
    r32[esi] = pop32();
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    memoryASet32(ds, r32[ebx] + 0x2f8, r32[edx]);
    r32[ebx] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 4; return;
  case 0x405160: // 0000:405160
    memoryASet32(ds, r32[ebx] + 0x2f8, r32[edi]);
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 4;
    return;
  }
}
function* sub_405170() // 0000:405170 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[eax] = 0x0000001d;
    r32[ecx] = r32[edi] + 1;
    r32[ecx] = sar32(r32[ecx], 0x04);
    r32[eax] -= r32[ecx];
    if (r32s[eax] < 0)
        { pc = 0x4051d2; break; }
    if (r32s[eax] > signed32(0x0000001f))
        { pc = 0x4051d2; break; }
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = r32[eax] + (r32[eax] * 2);
    r32[ecx] = memoryAGet32(ds, r32[esi] + r32[edx] * 8);
    r32[edx] = r32[esi] + (r32[edx] * 8);
    if (r32[ecx])
        { pc = 0x4051d2; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[ebx] = memoryAGet32(ds, r32[edx] + 0x4);
    r32[ecx] = sar32(r32[ecx], 0x04);
    if (r32s[ecx] < r32s[ebx])
        { pc = 0x4051d2; break; }
    if (r32s[ecx] > signed32(memoryAGet32(ds, r32[edx] + 0x8)))
        { pc = 0x4051d2; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x300);
    r32[ecx] &= 0x8000000f;
    if (r32s[ecx] >= 0)
        { pc = 0x4051c2; break; }
    r32[ecx]--;
    r32[ecx] |= 0xfffffff0;
    r32[ecx]++;
  case 0x4051c2: // 0000:4051c2
    r32[eax] += 0x00000254;
    r32[eax] <<= 4;
    r32[eax] -= r32[ecx];
    r32[eax] += r32[edi];
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4; return;
  case 0x4051d2: // 0000:4051d2
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[eax] = 0;
    r32[ebx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_4051e0() // 0000:4051e0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = r32[eax] + 1;
    r32[eax] = 0x0000001d;
    r32[ecx] = sar32(r32[ecx], 0x04);
    r32[eax] -= r32[ecx];
    if (r32s[eax] < 0)
        { pc = 0x405204; break; }
    if (r32s[eax] > signed32(0x0000001f))
        { pc = 0x405204; break; }
    r32[edx] = r32[eax] + (r32[eax] * 2);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax] + r32[edx] * 8 + 0xc);
    r32[esp] += 4; return;
  case 0x405204: // 0000:405204
    r32[eax] = 0;
    r32[esp] += 4;
    return;
  }
}
function* sub_405210() // 0000:405210 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x00000020;
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x28);
    push32(r32[ebp]);
    push32(r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x8c);
    push32(r32[edi]);
    if (!(r8[al] & 0x02))
        { pc = 0x4052e5; break; }
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x90);
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x3c);
    push32(0x0040ebd8);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edi] = memoryAGet32(ds, r32[ecx] + 0xc);
    r32[eax] -= r32[esi];
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[edi]);
    push32(r32[ebx]);
    r32[ebp] = r32[eax];
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x8);
    r32[eax] -= r32[esi];
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[edi]);
    r32[esi] = r32[eax];
    memoryASet32(ds, r32[esp] + 0x40, r32[esi]);
    yield* sub_406e2b();
    r32[esp] += 0x0000000c;
    r32[edx] = 0;
    if (r32s[ebp] <= 0)
        { pc = 0x4052a4; break; }
    memoryASet32(ds, r32[esp] + 0x38, r32[ebp]);
    r32[edx] = r32[ebp];
  case 0x40526b: // 0000:40526b
    r32[edi] = 0x0040ebd4;
    r32[ecx] |= 0xffffffff;
    r32[eax] = 0;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = ~r32[ecx];
    r32[edi] -= r32[ecx];
    r32[esi] = r32[edi];
    r32[ebp] = r32[ecx];
    r32[edi] = r32[ebx];
    r32[ecx] |= 0xffffffff;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = r32[ebp];
    r32[edi]--;
    r32[ecx] >>= 2;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x38);
    r32[ecx] = r32[ebp];
    r32[ecx] &= 0x00000003;
    r32[eax]--;
    for (; r32[ecx] != 0; --r32[ecx]) movsb_ESEDI_DSESI();
    memoryASet32(ds, r32[esp] + 0x38, r32[eax]);
    if (r32[eax])
        { pc = 0x40526b; break; }
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x34);
  case 0x4052a4: // 0000:4052a4
    if (r32s[edx] >= r32s[esi])
        { pc = 0x405390; break; }
    r32[esi] -= r32[edx];
    r32[edx] = r32[esi];
  case 0x4052b0: // 0000:4052b0
    r32[edi] = 0x0040ebd0;
    r32[ecx] |= 0xffffffff;
    r32[eax] = 0;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = ~r32[ecx];
    r32[edi] -= r32[ecx];
    r32[esi] = r32[edi];
    r32[ebp] = r32[ecx];
    r32[edi] = r32[ebx];
    r32[ecx] |= 0xffffffff;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = r32[ebp];
    r32[edi]--;
    r32[ecx] >>= 2;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    r32[ecx] = r32[ebp];
    r32[ecx] &= 0x00000003;
    r32[edx]--;
    for (; r32[ecx] != 0; --r32[ecx]) movsb_ESEDI_DSESI();
    if (r32[edx])
        { pc = 0x4052b0; break; }
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000020;
    r32[esp] += 4; return;
  case 0x4052e5: // 0000:4052e5
    if (!(r8[al] & 0x08))
        { pc = 0x405311; break; }
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x90);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[eax] + r32[ecx] * 4 + 0x8);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x38);
    push32(r32[edx]);
    push32(r32[ebx]);
    push32(0x0040ebc8);
    push32(r32[eax]);
    yield* sub_406e2b();
    r32[esp] += 0x00000010;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000020;
    r32[esp] += 4; return;
  case 0x405311: // 0000:405311
    if (!(r8[al] & 0x04))
        { pc = 0x405346; break; }
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x90);
    r32[eax] = 0x0040ebc4;
    if (memoryAGet32(ds, r32[ecx]))
        { pc = 0x40532a; break; }
    r32[eax] = 0x0040ebc0;
  case 0x40532a: // 0000:40532a
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x38);
    push32(r32[eax]);
    push32(r32[ebx]);
    push32(0x0040ebc8);
    push32(r32[edx]);
    yield* sub_406e2b();
    r32[esp] += 0x00000010;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000020;
    r32[esp] += 4; return;
  case 0x405346: // 0000:405346
    if (!(r8[al] & 0x10))
        { pc = 0x40537d; break; }
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x90);
    r32[eax] = r32[esp] + 16;
    push32(r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    yield* sub_4059e0();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x40);
    r32[eax] = r32[esp] + 24;
    push32(r32[eax]);
    push32(r32[ebx]);
    push32(0x0040ebb4);
    push32(r32[ecx]);
    yield* sub_406e2b();
    r32[esp] += 0x00000018;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000020;
    r32[esp] += 4; return;
  case 0x40537d: // 0000:40537d
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x38);
    push32(r32[ebx]);
    push32(0x0040e034);
    push32(r32[edx]);
    yield* sub_406e2b();
    r32[esp] += 0x0000000c;
  case 0x405390: // 0000:405390
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000020;
    r32[esp] += 4;
    return;
  }
}
function* sub_4053a0() // 0000:4053a0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x00000108;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x110);
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x118);
    push32(r32[ebp]);
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x120);
    push32(r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x4);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x128);
    r32[eax] -= 0x0000000d;
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x11c);
    r32[esi] -= r32[eax];
    memoryASet32(ds, r32[esp] + 0x14, r32[eax]);
    r32[ecx] += 0xfffffff8;
    { pc = 0x4053e6; break; }
  case 0x4053de: // 0000:4053de
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
  case 0x4053e6: // 0000:4053e6
    r32[ecx] += 0x00000094;
    r32[edx] = r32[esp] + 24;
    memoryASet32(ds, r32[esp] + 0x10, r32[ecx]);
    r32[ecx] += 0xffffff74;
    push32(r32[edx]);
    push32(r32[ecx]);
    r32[esi] += r32[eax];
    yield* sub_405210();
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[esp] += 0x00000008;
    if (!(memoryAGet(ds, r32[eax]) & 0x01))
        { pc = 0x40544c; break; }
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x28);
    r32[ecx] = r32[ebp];
    r32[edx] = memoryAGet32(ds, r32[eax]);
    r32[ecx] -= r32[edx];
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x1c);
    r32[ebp] = memoryAGet32(ds, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[edi] + 0x1c);
    flags.zero = r32[ebp] == 0x00000008;
    r32[ebp] = r32[esi] - 8;
    push32(r32[ebp]);
    push32(r32[ecx]);
    push32(r32[eax]);
    push32(r32[edi]);
    if (!flags.zero)
        { pc = 0x405431; break; }
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x44));
    { pc = 0x405434; break; }
  case 0x405431: // 0000:405431
    yield* indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
  case 0x405434: // 0000:405434
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x138);
    r32[ecx] = memoryAGet32(ds, r32[ebx]);
    r32[esp] += 0x00000010;
    r32[eax] = r32[esp] + 24;
    push32(0xffffffff);
    push32(r32[esi]);
    push32(r32[ebp]);
    push32(r32[eax]);
    push32(r32[ecx]);
    { pc = 0x405458; break; }
  case 0x40544c: // 0000:40544c
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    push32(0xffffffff);
    push32(r32[esi]);
    r32[edx] = r32[esp] + 32;
    push32(r32[ebp]);
    push32(r32[edx]);
    push32(r32[eax]);
  case 0x405458: // 0000:405458
    push32(r32[edi]);
    alleg40.textout(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x28);
    r32[esp] += 0x00000018;
    if (!(memoryAGet(ds, r32[ecx]) & 0x20))
        { pc = 0x4053de; break; }
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000108;
    r32[esp] += 4;
    return;
  }
}
function* sub_405480() // 0000:405480 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[esi]);
    r32[eax] = r32[ecx] - 8;
  case 0x405488: // 0000:405488
    r32[esi] = memoryAGet32(ds, r32[eax] + 0x94);
    r32[eax] += 0x00000094;
    r32[esi] &= 0xfffffffe;
    memoryASet32(ds, r32[eax], r32[esi]);
    r8[dl] = memoryAGet(ds, r32[eax]);
    if (!(r8[dl] & 0x20))
        { pc = 0x405488; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = r32[eax] + (r32[eax] * 8);
    r32[eax] = r32[eax] + (r32[edx] * 4);
    r32[esi] = memoryAGet32(ds, r32[ecx] + r32[eax] * 4 + 0x8c);
    r32[eax] = (r32[ecx] + (r32[eax] * 4)) + 140;
    r32[esi] |= 0x00000001;
    memoryASet32(ds, r32[eax], r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[ecx] = memoryAGet32(ds, r32[esi]);
    push32(r32[ecx]);
    r32[eax] = alleg40.text_height(stack32(0));
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x4, r32[eax]);
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_4054e0() // 0000:4054e0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ecx]);
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[ebp]);
    push32(r32[esi]);
    r32[esi] = 0;
    push32(r32[edi]);
    memoryASet32(ds, r32[esp] + 0x10, r32[esi]);
    r32[ebp] |= 0xffffffff;
    r32[ecx] = r32[ebx] - 8;
  case 0x4054f5: // 0000:4054f5
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x94);
    r32[ecx] += 0x00000094;
    r32[ebp]++;
    if (!(r8[al] & 0x01))
        { pc = 0x405508; break; }
    r32[esi] = r32[ebp];
  case 0x405508: // 0000:405508
    if (!(r8[al] & 0x20))
        { pc = 0x4054f5; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x2c);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x28);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x20);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[ecx]);
    push32(r32[edx]);
    push32(r32[ebx]);
    push32(r32[eax]);
    yield* sub_4053a0();
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x38);
    r32[esp] += 0x00000014;
    if (!r32[eax])
        { pc = 0x405654; break; }
    push32(r32[eax]);
    r32[edi] = r32[esi];
    yield* sub_4011c0();
    r32[esp] += 0x00000004;
    if (r32[eax])
        { pc = 0x405558; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[ecx] += 0x00000008;
    push32(r32[ecx]);
    yield* sub_4011c0();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x40555d; break; }
  case 0x405558: // 0000:405558
    if (!r32[esi])
        { pc = 0x40555d; break; }
    r32[esi]--;
  case 0x40555d: // 0000:40555d
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x24);
    push32(r32[edx]);
    yield* sub_4011d0();
    r32[esp] += 0x00000004;
    if (r32[eax])
        { pc = 0x405582; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[eax] += 0x00000008;
    push32(r32[eax]);
    yield* sub_4011d0();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x405587; break; }
  case 0x405582: // 0000:405582
    if (r32s[esi] >= r32s[ebp])
        { pc = 0x405587; break; }
    r32[esi]++;
  case 0x405587: // 0000:405587
    if (r32[esi] == r32[edi])
        { pc = 0x4055c2; break; }
    r32[ecx] = r32[edi] + (r32[edi] * 8);
    r32[edx] = r32[edi] + (r32[ecx] * 4);
    r32[eax] = (r32[ebx] + (r32[edx] * 4)) + 140;
    r32[edx] = memoryAGet32(ds, r32[ebx] + r32[edx] * 4 + 0x8c);
    r32[edx] &= 0xfffffffe;
    memoryASet32(ds, r32[eax], r32[edx]);
    r32[eax] = r32[esi] + (r32[esi] * 8);
    r32[ecx] = r32[esi] + (r32[eax] * 4);
    r32[eax] = (r32[ebx] + (r32[ecx] * 4)) + 140;
    r32[ecx] = memoryAGet32(ds, r32[ebx] + r32[ecx] * 4 + 0x8c);
    r32[ecx] |= 0x00000001;
    memoryASet32(ds, r32[eax], r32[ecx]);
    yield* sub_404950();
  case 0x4055c2: // 0000:4055c2
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x24);
    push32(r32[ebp]);
    yield* sub_401200();
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[esp] += 0x00000004;
    if (r32[eax])
        { pc = 0x4055e7; break; }
    r32[edx] = r32[edi] + 8;
    push32(r32[edx]);
    yield* sub_401210();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x4055f8; break; }
  case 0x4055e7: // 0000:4055e7
    r32[eax] = r32[esi] + (r32[esi] * 8);
    r32[ecx] = r32[esi] + (r32[eax] * 4);
    r32[edx] = memoryAGet32(ds, r32[ebx] + r32[ecx] * 4 + 0x80);
    memoryASet32(ds, r32[esp] + 0x10, r32[edx]);
  case 0x4055f8: // 0000:4055f8
    push32(r32[ebp]);
    yield* sub_4011e0();
    r32[esp] += 0x00000004;
    if (r32[eax])
        { pc = 0x405615; break; }
    r32[eax] = r32[edi] + 8;
    push32(r32[eax]);
    yield* sub_4011e0();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x405626; break; }
  case 0x405615: // 0000:405615
    r32[ecx] = r32[esi] + (r32[esi] * 8);
    r32[edx] = r32[esi] + (r32[ecx] * 4);
    r32[eax] = memoryAGet32(ds, r32[ebx] + r32[edx] * 4 + 0x84);
    memoryASet32(ds, r32[esp] + 0x10, r32[eax]);
  case 0x405626: // 0000:405626
    push32(r32[ebp]);
    yield* sub_4011f0();
    r32[esp] += 0x00000004;
    if (r32[eax])
        { pc = 0x405643; break; }
    r32[edi] += 0x00000008;
    push32(r32[edi]);
    yield* sub_4011f0();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x405654; break; }
  case 0x405643: // 0000:405643
    r32[ecx] = r32[esi] + (r32[esi] * 8);
    r32[edx] = r32[esi] + (r32[ecx] * 4);
    r32[eax] = memoryAGet32(ds, r32[ebx] + r32[edx] * 4 + 0x88);
    memoryASet32(ds, r32[esp] + 0x10, r32[eax]);
  case 0x405654: // 0000:405654
    r32[ecx] = r32[esi] + (r32[esi] * 8);
    r32[edi] = pop32();
    r32[edx] = r32[esi] + (r32[ecx] * 4);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x2c);
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = memoryAGet32(ds, r32[ebx] + r32[edx] * 4 + 0x90);
    r32[ebx] = pop32();
    memoryASet32(ds, r32[ecx], r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp]);
    r32[ecx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_405680() // 0000:405680 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x00000084;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x88);
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x90);
    push32(r32[ebp]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x2c);
    r32[edi] = 0;
    push32(r32[eax]);
    push32(r32[ebx]);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x1c, r32[edi]);
    yield* sub_405480();
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0xac);
    r32[esp] += 0x0000000c;
  case 0x4056b3: // 0000:4056b3
    //memoryASet32(ds, 0x42bbc0, 0x00000000);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xa8);
    if (!r32[eax])
        { pc = 0x4056cc; break; }
    //yield* indirectCall(cs, r32[eax]);
    assert(r32[eax] == 0x404990); yield* sub_404990();
    { pc = 0x4056dd; break; }
  case 0x4056cc: // 0000:4056cc
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xa4);
    push32(r32[edx]);
    alleg40.clear_bitmap(stack32(0));
    r32[esp] += 0x00000004;
  case 0x4056dd: // 0000:4056dd
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xb0);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xac);
    flags.carry = r32[edi] != 0;
    r32[edi] = -r32[edi];
    r32[eax] = r32[esp] + 16;
    r32[edi] = -flags.carry;
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x9c);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xac);
    r32[edi] &= r32[ebp];
    push32(r32[edx]);
    push32(r32[edi]);
    push32(r32[ebx]);
    push32(r32[eax]);
    push32(r32[ecx]);
    yield* sub_4054e0();
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xc0);
    r32[esi] = r32[eax];
    push32(r32[edx]);
    yield* sub_402250();
    push32(r32[ebp]);
    yield* sub_401220();
    r32[esp] += 0x00000024;
    if (r32[eax])
        { pc = 0x405740; break; }
    r32[eax] = r32[ebx] + 8;
    push32(r32[eax]);
    yield* sub_401220();
    r32[esp] += 0x00000004;
    if (r32[eax])
        { pc = 0x405740; break; }
    r32[edi] |= 0xffffffff;
    { pc = 0x405742; break; }
  case 0x405740: // 0000:405740
    r32[edi] = 0;
  case 0x405742: // 0000:405742
    push32(r32[ebp]);
    yield* sub_401060();
    r32[ecx] = r32[ebx] + 8;
    push32(r32[ecx]);
    yield* sub_401060();
    r32[esp] += 0x00000008;
    if (!r32[esi])
        { pc = 0x40575d; break; }
    yield* sub_404970();
  case 0x40575d: // 0000:40575d
    if (r32[esi] > 0x00000072)
        { pc = 0x40588a; break; }
    r32[edx] = 0;
    r8[dl] = memoryAGet(ds, r32[esi] + 0x405960);
    switch (r32[edx])
    {
        case 0: { pc = 0x4058ac; break; }
        case 1: { pc = 0x4058d8; break; }
        case 2: { pc = 0x405775; break; }
        case 3: { pc = 0x4058e8; break; }
        case 4: { pc = 0x4058f8; break; }
        case 5: { pc = 0x405908; break; }
        case 6: { pc = 0x405918; break; }
        case 7: { pc = 0x4057b0; break; }
        case 8: { pc = 0x4057cb; break; }
        case 9: { pc = 0x4057fe; break; }
        case 10: { pc = 0x4057e6; break; }
        case 11: { pc = 0x405816; break; }
        case 12: { pc = 0x40582a; break; }
        case 13: { pc = 0x40588a; break; }
        default:
            stop("ind 0000:40576e");
    }
    break;
  case 0x405775: // 0000:405775
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xb0);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xac);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xa8);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xa8);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[edx]);
    push32(r32[eax]);
    push32(r32[ebp]);
    push32(r32[ebx]);
    push32(r32[ecx]);
    memoryASet32(ds, r32[ebx] + 0x2c, 0x00000000);
    yield* sub_405680();
    r32[esp] += 0x0000001c;
    { pc = 0x4058ac; break; }
  case 0x4057b0: // 0000:4057b0
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xc);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    r32[ecx] += r32[edx];
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x8);
    if (r32s[ecx] < r32s[edx])
        { pc = 0x4057c4; break; }
    r32[ecx] = r32[edx];
  case 0x4057c4: // 0000:4057c4
    memoryASet32(ds, r32[eax], r32[ecx]);
    { pc = 0x4058ac; break; }
  case 0x4057cb: // 0000:4057cb
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0xc);
    r32[eax] -= r32[edx];
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x4);
    if (r32s[eax] > r32s[edx])
        { pc = 0x4057df; break; }
    r32[eax] = r32[edx];
  case 0x4057df: // 0000:4057df
    memoryASet32(ds, r32[ecx], r32[eax]);
    { pc = 0x4058ac; break; }
  case 0x4057e6: // 0000:4057e6
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[edx]);
    r32[eax]--;
    r32[ecx]++;
    if (r32s[ecx] >= r32s[eax])
        { pc = 0x4057f7; break; }
    r32[eax] = r32[ecx];
  case 0x4057f7: // 0000:4057f7
    memoryASet32(ds, r32[edx], r32[eax]);
    { pc = 0x4058ac; break; }
  case 0x4057fe: // 0000:4057fe
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = 0;
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[eax]--;
    r8[dl] = r32s[eax] <= 0;
    r32[edx]--;
    r32[eax] &= r32[edx];
    memoryASet32(ds, r32[ecx], r32[eax]);
    { pc = 0x4058ac; break; }
  case 0x405816: // 0000:405816
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    flags.carry = r32[ecx] != 0;
    r32[ecx] = -r32[ecx];
    r32[ecx] = -flags.carry;
    r32[ecx] = -r32[ecx];
    r32[ecx]--;
    memoryASet32(ds, r32[eax], r32[ecx]);
    { pc = 0x4058ac; break; }
  case 0x40582a: // 0000:40582a
    r32[esi] = 0;
    r32[eax] = 0;
  case 0x40582e: // 0000:40582e
    r32[edx] = memoryAGet32(ds, 0x40d1a4);
    memoryASet(ds, r32[edx] + r32[eax], 0x00);
    r32[eax]++;
    if (r32s[eax] < signed32(0x00000080))
        { pc = 0x40582e; break; }
  case 0x405840: // 0000:405840
    r32[ecx] = memoryAGet32(ds, 0x40d1a4);
    r32[eax] = 0;
  case 0x405848: // 0000:405848
    if (!memoryAGet(ds, r32[ecx] + r32[eax]))
        { pc = 0x405850; break; }
    r32[esi] = r32[eax];
  case 0x405850: // 0000:405850
    r32[eax]++;
    if (r32s[eax] < signed32(0x00000080))
        { pc = 0x405848; break; }
    push32(r32[esi]);
    push32(r32[ebp]);
    yield* sub_401170();
    r32[esp] += 0x00000008;
    if (!r32[eax])
        { pc = 0x40586a; break; }
    r32[esi] = 0;
    { pc = 0x405840; break; }
  case 0x40586a: // 0000:40586a
    if (!r32[esi])
        { pc = 0x405840; break; }
    r32[eax] = 0;
  case 0x405870: // 0000:405870
    r32[ecx] = memoryAGet32(ds, 0x40d1a4);
    memoryASet(ds, r32[ecx] + r32[eax], 0x00);
    r32[eax]++;
    if (r32s[eax] < signed32(0x00000080))
        { pc = 0x405870; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x10);
    memoryASet32(ds, r32[edx], r32[esi]);
    { pc = 0x4058ac; break; }
  case 0x40588a: // 0000:40588a
    push32(r32[esi]);
    r32[eax] = r32[esp] + 24;
    push32(0x0040ebec);
    push32(r32[eax]);
    yield* sub_406e2b();
    r32[ecx] = r32[esp] + 32;
    push32(r32[ecx]);
    push32(0x0040ebe0);
    yield* sub_401510();
    r32[esp] += 0x00000014;
  case 0x4058ac: // 0000:4058ac
    r32[edx] = memoryAGet32(ds, 0x40d1a4);
    r8[al] = memoryAGet(ds, r32[edx] + 0x40);
    if (r8[al])
        { pc = 0x4056b3; break; }
    r32[eax] = memoryAGet32(ds, 0x42bbc0);
    if (r32[eax])
        { pc = 0x4056b3; break; }
  case 0x4058ca: // 0000:4058ca
    r32[eax] = memoryAGet32(ds, 0x42bbc0);
    if (!r32[eax])
        { pc = 0x4058ca; break; }
    { pc = 0x4056b3; break; }
  case 0x4058d8: // 0000:4058d8
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = 0x00000065;
    r32[ebx] = pop32();
    r32[esp] += 0x00000084;
    r32[esp] += 4; return;
  case 0x4058e8: // 0000:4058e8
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = 0x00000068;
    r32[ebx] = pop32();
    r32[esp] += 0x00000084;
    r32[esp] += 4; return;
  case 0x4058f8: // 0000:4058f8
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = 0x00000069;
    r32[ebx] = pop32();
    r32[esp] += 0x00000084;
    r32[esp] += 4; return;
  case 0x405908: // 0000:405908
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = 0x0000006b;
    r32[ebx] = pop32();
    r32[esp] += 0x00000084;
    r32[esp] += 4; return;
  case 0x405918: // 0000:405918
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = 0x0000006c;
    r32[ebx] = pop32();
    r32[esp] += 0x00000084;
    r32[esp] += 4;
    return;
  }
}
function* sub_4059e0() // 0000:4059e0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    if (r32[eax] != 0x00000001)
        { pc = 0x4059f8; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40eeac);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x4059f8: // 0000:4059f8
    if (r32[eax] != 0x00000002)
        { pc = 0x405a0b; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40eea8);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405a0b: // 0000:405a0b
    if (r32[eax] != 0x00000003)
        { pc = 0x405a1f; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40eea4);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405a1f: // 0000:405a1f
    if (r32[eax] != 0x00000004)
        { pc = 0x405a33; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40eea0);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405a33: // 0000:405a33
    if (r32[eax] != 0x00000005)
        { pc = 0x405a46; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee9c);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405a46: // 0000:405a46
    if (r32[eax] != 0x00000006)
        { pc = 0x405a5a; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee98);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405a5a: // 0000:405a5a
    if (r32[eax] != 0x00000007)
        { pc = 0x405a6e; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ee94);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405a6e: // 0000:405a6e
    if (r32[eax] != 0x00000008)
        { pc = 0x405a81; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee90);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405a81: // 0000:405a81
    if (r32[eax] != 0x00000009)
        { pc = 0x405a95; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee8c);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405a95: // 0000:405a95
    if (r32[eax] != 0x0000000a)
        { pc = 0x405aa9; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ee88);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405aa9: // 0000:405aa9
    if (r32[eax] != 0x0000000b)
        { pc = 0x405abc; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee84);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405abc: // 0000:405abc
    if (r32[eax] != 0x0000000c)
        { pc = 0x405ad0; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee80);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405ad0: // 0000:405ad0
    if (r32[eax] != 0x0000000d)
        { pc = 0x405ae4; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ee7c);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405ae4: // 0000:405ae4
    if (r32[eax] != 0x0000000e)
        { pc = 0x405af7; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee78);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405af7: // 0000:405af7
    if (r32[eax] != 0x0000000f)
        { pc = 0x405b0b; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee74);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405b0b: // 0000:405b0b
    if (r32[eax] != 0x00000010)
        { pc = 0x405b1f; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ee70);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405b1f: // 0000:405b1f
    if (r32[eax] != 0x00000011)
        { pc = 0x405b32; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee6c);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405b32: // 0000:405b32
    if (r32[eax] != 0x00000012)
        { pc = 0x405b46; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee68);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405b46: // 0000:405b46
    if (r32[eax] != 0x00000013)
        { pc = 0x405b5a; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ee64);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405b5a: // 0000:405b5a
    if (r32[eax] != 0x00000014)
        { pc = 0x405b6d; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee60);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405b6d: // 0000:405b6d
    if (r32[eax] != 0x00000015)
        { pc = 0x405b81; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee5c);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405b81: // 0000:405b81
    if (r32[eax] != 0x00000016)
        { pc = 0x405b95; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ee58);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405b95: // 0000:405b95
    if (r32[eax] != 0x00000017)
        { pc = 0x405ba8; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee54);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405ba8: // 0000:405ba8
    if (r32[eax] != 0x00000018)
        { pc = 0x405bbc; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee50);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405bbc: // 0000:405bbc
    if (r32[eax] != 0x00000019)
        { pc = 0x405bd0; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ee4c);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405bd0: // 0000:405bd0
    if (r32[eax] != 0x0000001a)
        { pc = 0x405be3; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee48);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405be3: // 0000:405be3
    if (r32[eax] != 0x0000001b)
        { pc = 0x405bf7; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee44);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405bf7: // 0000:405bf7
    if (r32[eax] != 0x0000001c)
        { pc = 0x405c0b; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ee40);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405c0b: // 0000:405c0b
    if (r32[eax] != 0x0000001d)
        { pc = 0x405c1e; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee3c);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405c1e: // 0000:405c1e
    if (r32[eax] != 0x0000001e)
        { pc = 0x405c32; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee38);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405c32: // 0000:405c32
    if (r32[eax] != 0x0000001f)
        { pc = 0x405c46; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ee34);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405c46: // 0000:405c46
    if (r32[eax] != 0x00000020)
        { pc = 0x405c59; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee30);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405c59: // 0000:405c59
    if (r32[eax] != 0x00000021)
        { pc = 0x405c6d; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee2c);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405c6d: // 0000:405c6d
    if (r32[eax] != 0x00000022)
        { pc = 0x405c81; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ee28);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405c81: // 0000:405c81
    if (r32[eax] != 0x00000023)
        { pc = 0x405c94; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ee24);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405c94: // 0000:405c94
    if (r32[eax] != 0x00000024)
        { pc = 0x405ca8; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ee20);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405ca8: // 0000:405ca8
    if (r32[eax] != 0x00000025)
        { pc = 0x405cc3; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ee18);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ee1c);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x405cc3: // 0000:405cc3
    if (r32[eax] != 0x00000026)
        { pc = 0x405cde; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ee10);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ee14);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x405cde: // 0000:405cde
    if (r32[eax] != 0x00000027)
        { pc = 0x405cf9; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ee08);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ee0c);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x405cf9: // 0000:405cf9
    if (r32[eax] != 0x00000028)
        { pc = 0x405d14; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ee00);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ee04);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x405d14: // 0000:405d14
    if (r32[eax] != 0x00000029)
        { pc = 0x405d2f; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40edf8);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40edfc);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x405d2f: // 0000:405d2f
    if (r32[eax] != 0x0000002a)
        { pc = 0x405d4a; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40edf0);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40edf4);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x405d4a: // 0000:405d4a
    if (r32[eax] != 0x0000002b)
        { pc = 0x405d65; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ede8);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40edec);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x405d65: // 0000:405d65
    if (r32[eax] != 0x0000002c)
        { pc = 0x405d80; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ede0);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ede4);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x405d80: // 0000:405d80
    if (r32[eax] != 0x0000002d)
        { pc = 0x405d9b; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40edd8);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40eddc);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x405d9b: // 0000:405d9b
    if (r32[eax] != 0x0000002e)
        { pc = 0x405db6; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40edd0);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40edd4);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x405db6: // 0000:405db6
    if (r32[eax] != 0x0000002f)
        { pc = 0x405dd3; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40edcc);
    memoryASet16(ds, r32[eax], r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40edce);
    memoryASet(ds, r32[eax] + 0x2, r8[dl]);
    r32[esp] += 4; return;
  case 0x405dd3: // 0000:405dd3
    if (r32[eax] != 0x00000030)
        { pc = 0x405df0; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40edc8);
    memoryASet16(ds, r32[eax], r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40edca);
    memoryASet(ds, r32[eax] + 0x2, r8[dl]);
    r32[esp] += 4; return;
  case 0x405df0: // 0000:405df0
    if (r32[eax] != 0x00000031)
        { pc = 0x405e0d; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40edc4);
    memoryASet16(ds, r32[eax], r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40edc6);
    memoryASet(ds, r32[eax] + 0x2, r8[dl]);
    r32[esp] += 4; return;
  case 0x405e0d: // 0000:405e0d
    if (r32[eax] != 0x00000032)
        { pc = 0x405e2a; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40edc0);
    memoryASet16(ds, r32[eax], r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40edc2);
    memoryASet(ds, r32[eax] + 0x2, r8[dl]);
    r32[esp] += 4; return;
  case 0x405e2a: // 0000:405e2a
    if (r32[eax] != 0x00000033)
        { pc = 0x405e47; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40edbc);
    memoryASet16(ds, r32[eax], r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40edbe);
    memoryASet(ds, r32[eax] + 0x2, r8[dl]);
    r32[esp] += 4; return;
  case 0x405e47: // 0000:405e47
    if (r32[eax] != 0x00000034)
        { pc = 0x405e64; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40edb8);
    memoryASet16(ds, r32[eax], r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40edba);
    memoryASet(ds, r32[eax] + 0x2, r8[dl]);
    r32[esp] += 4; return;
  case 0x405e64: // 0000:405e64
    if (r32[eax] != 0x00000035)
        { pc = 0x405e81; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40edb4);
    memoryASet16(ds, r32[eax], r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40edb6);
    memoryASet(ds, r32[eax] + 0x2, r8[dl]);
    r32[esp] += 4; return;
  case 0x405e81: // 0000:405e81
    if (r32[eax] != 0x00000036)
        { pc = 0x405e9e; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40edb0);
    memoryASet16(ds, r32[eax], r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40edb2);
    memoryASet(ds, r32[eax] + 0x2, r8[dl]);
    r32[esp] += 4; return;
  case 0x405e9e: // 0000:405e9e
    if (r32[eax] != 0x00000037)
        { pc = 0x405ebb; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40edac);
    memoryASet16(ds, r32[eax], r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40edae);
    memoryASet(ds, r32[eax] + 0x2, r8[dl]);
    r32[esp] += 4; return;
  case 0x405ebb: // 0000:405ebb
    if (r32[eax] != 0x00000038)
        { pc = 0x405ecd; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40eda8);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[esp] += 4; return;
  case 0x405ecd: // 0000:405ecd
    if (r32[eax] != 0x00000039)
        { pc = 0x405ede; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40eda4);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[esp] += 4; return;
  case 0x405ede: // 0000:405ede
    if (r32[eax] != 0x0000003a)
        { pc = 0x405ef0; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40eda0);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r32[esp] += 4; return;
  case 0x405ef0: // 0000:405ef0
    if (r32[eax] != 0x0000003b)
        { pc = 0x405f02; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ed9c);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[esp] += 4; return;
  case 0x405f02: // 0000:405f02
    if (r32[eax] != 0x0000003c)
        { pc = 0x405f15; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ed98);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405f15: // 0000:405f15
    if (r32[eax] != 0x0000003d)
        { pc = 0x405f29; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ed94);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405f29: // 0000:405f29
    if (r32[eax] != 0x0000003e)
        { pc = 0x405f3d; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ed90);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405f3d: // 0000:405f3d
    if (r32[eax] != 0x0000003f)
        { pc = 0x405f61; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40ed84);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[ecx] = memoryAGet32(ds, 0x40ed88);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r16[ax] = memoryAGet16(ds, 0x40ed8c);
    memoryASet16(ds, r32[edx] + 0x8, r16[ax]);
    r32[esp] += 4; return;
  case 0x405f61: // 0000:405f61
    if (r32[eax] != 0x00000040)
        { pc = 0x405f73; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ed80);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r32[esp] += 4; return;
  case 0x405f73: // 0000:405f73
    if (r32[eax] != 0x00000041)
        { pc = 0x405f87; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ebd0);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405f87: // 0000:405f87
    if (r32[eax] != 0x00000042)
        { pc = 0x405f9a; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ebd4);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405f9a: // 0000:405f9a
    if (r32[eax] != 0x00000043)
        { pc = 0x405fb6; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ed78);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r16[ax] = memoryAGet16(ds, 0x40ed7c);
    memoryASet16(ds, r32[ecx] + 0x4, r16[ax]);
    r32[esp] += 4; return;
  case 0x405fb6: // 0000:405fb6
    if (r32[eax] != 0x00000044)
        { pc = 0x405fca; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ed74);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x405fca: // 0000:405fca
    if (r32[eax] != 0x00000045)
        { pc = 0x405fde; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ed70);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x405fde: // 0000:405fde
    if (r32[eax] != 0x00000046)
        { pc = 0x405ff1; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ed6c);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x405ff1: // 0000:405ff1
    if (r32[eax] != 0x00000047)
        { pc = 0x406005; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ed6c);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x406005: // 0000:406005
    if (r32[eax] != 0x00000048)
        { pc = 0x406019; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ed68);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x406019: // 0000:406019
    if (r32[eax] != 0x00000049)
        { pc = 0x40602c; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[ax] = memoryAGet16(ds, 0x40ed64);
    memoryASet16(ds, r32[edx], r16[ax]);
    r32[esp] += 4; return;
  case 0x40602c: // 0000:40602c
    if (r32[eax] != 0x0000004a)
        { pc = 0x406040; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[dx] = memoryAGet16(ds, 0x40ed60);
    memoryASet16(ds, r32[ecx], r16[dx]);
    r32[esp] += 4; return;
  case 0x406040: // 0000:406040
    if (r32[eax] != 0x0000004b)
        { pc = 0x40605d; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ed58);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r16[dx] = memoryAGet16(ds, 0x40ed5c);
    memoryASet16(ds, r32[eax] + 0x4, r16[dx]);
    r32[esp] += 4; return;
  case 0x40605d: // 0000:40605d
    if (r32[eax] != 0x0000004c)
        { pc = 0x406083; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ed50);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r16[dx] = memoryAGet16(ds, 0x40ed54);
    memoryASet16(ds, r32[eax] + 0x4, r16[dx]);
    r8[cl] = memoryAGet(ds, 0x40ed56);
    memoryASet(ds, r32[eax] + 0x6, r8[cl]);
    r32[esp] += 4; return;
  case 0x406083: // 0000:406083
    if (r32[eax] != 0x0000004d)
        { pc = 0x4060a7; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40ed48);
    memoryASet32(ds, r32[edx], r32[eax]);
    r16[cx] = memoryAGet16(ds, 0x40ed4c);
    memoryASet16(ds, r32[edx] + 0x4, r16[cx]);
    r8[al] = memoryAGet(ds, 0x40ed4e);
    memoryASet(ds, r32[edx] + 0x6, r8[al]);
    r32[esp] += 4; return;
  case 0x4060a7: // 0000:4060a7
    if (r32[eax] != 0x0000004e)
        { pc = 0x4060c1; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ed40);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r8[al] = memoryAGet(ds, 0x40ed44);
    memoryASet(ds, r32[ecx] + 0x4, r8[al]);
    r32[esp] += 4; return;
  case 0x4060c1: // 0000:4060c1
    if (r32[eax] != 0x0000004f)
        { pc = 0x4060d3; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ed3c);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r32[esp] += 4; return;
  case 0x4060d3: // 0000:4060d3
    if (r32[eax] != 0x00000050)
        { pc = 0x4060ee; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ed34);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ed38);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x4060ee: // 0000:4060ee
    if (r32[eax] != 0x00000051)
        { pc = 0x406114; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ed28);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ed2c);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r16[cx] = memoryAGet16(ds, 0x40ed30);
    memoryASet16(ds, r32[eax] + 0x8, r16[cx]);
    r32[esp] += 4; return;
  case 0x406114: // 0000:406114
    if (r32[eax] != 0x00000052)
        { pc = 0x406141; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40ed1c);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[ecx] = memoryAGet32(ds, 0x40ed20);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r16[ax] = memoryAGet16(ds, 0x40ed24);
    memoryASet16(ds, r32[edx] + 0x8, r16[ax]);
    r8[cl] = memoryAGet(ds, 0x40ed26);
    memoryASet(ds, r32[edx] + 0xa, r8[cl]);
    r32[esp] += 4; return;
  case 0x406141: // 0000:406141
    if (r32[eax] != 0x00000053)
        { pc = 0x406163; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40ed10);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[ecx] = memoryAGet32(ds, 0x40ed14);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x40ed18);
    memoryASet32(ds, r32[edx] + 0x8, r32[eax]);
    r32[esp] += 4; return;
  case 0x406163: // 0000:406163
    if (r32[eax] != 0x00000054)
        { pc = 0x406186; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ed04);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r32[eax] = memoryAGet32(ds, 0x40ed08);
    memoryASet32(ds, r32[ecx] + 0x4, r32[eax]);
    r8[dl] = memoryAGet(ds, 0x40ed0c);
    memoryASet(ds, r32[ecx] + 0x8, r8[dl]);
    r32[esp] += 4; return;
  case 0x406186: // 0000:406186
    if (r32[eax] != 0x00000055)
        { pc = 0x4061b5; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ecf8);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ecfc);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r16[cx] = memoryAGet16(ds, 0x40ed00);
    memoryASet16(ds, r32[eax] + 0x8, r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40ed02);
    memoryASet(ds, r32[eax] + 0xa, r8[dl]);
    r32[esp] += 4; return;
  case 0x4061b5: // 0000:4061b5
    if (r32[eax] != 0x00000056)
        { pc = 0x4061d0; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ecf0);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ecf4);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[esp] += 4; return;
  case 0x4061d0: // 0000:4061d0
    if (r32[eax] != 0x00000057)
        { pc = 0x4061e4; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r16[cx] = memoryAGet16(ds, 0x40ecec);
    memoryASet16(ds, r32[eax], r16[cx]);
    r32[esp] += 4; return;
  case 0x4061e4: // 0000:4061e4
    if (r32[eax] != 0x00000058)
        { pc = 0x4061ff; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ece4);
    memoryASet32(ds, r32[eax], r32[edx]);
    r32[ecx] = memoryAGet32(ds, 0x40ece8);
    memoryASet32(ds, r32[eax] + 0x4, r32[ecx]);
    r32[esp] += 4; return;
  case 0x4061ff: // 0000:4061ff
    if (r32[eax] != 0x00000059)
        { pc = 0x40621a; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ecdc);
    memoryASet32(ds, r32[eax], r32[edx]);
    r32[ecx] = memoryAGet32(ds, 0x40ece0);
    memoryASet32(ds, r32[eax] + 0x4, r32[ecx]);
    r32[esp] += 4; return;
  case 0x40621a: // 0000:40621a
    if (r32[eax] != 0x0000005a)
        { pc = 0x406245; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40eccc);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[ecx] = memoryAGet32(ds, 0x40ecd0);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x40ecd4);
    memoryASet32(ds, r32[edx] + 0x8, r32[eax]);
    r8[cl] = memoryAGet(ds, 0x40ecd8);
    memoryASet(ds, r32[edx] + 0xc, r8[cl]);
    r32[esp] += 4; return;
  case 0x406245: // 0000:406245
    if (r32[eax] != 0x0000005b)
        { pc = 0x406267; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40ecc0);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[ecx] = memoryAGet32(ds, 0x40ecc4);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x40ecc8);
    memoryASet32(ds, r32[edx] + 0x8, r32[eax]);
    r32[esp] += 4; return;
  case 0x406267: // 0000:406267
    if (r32[eax] != 0x0000005c)
        { pc = 0x406292; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ecb0);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r32[eax] = memoryAGet32(ds, 0x40ecb4);
    memoryASet32(ds, r32[ecx] + 0x4, r32[eax]);
    r32[edx] = memoryAGet32(ds, 0x40ecb8);
    memoryASet32(ds, r32[ecx] + 0x8, r32[edx]);
    r8[al] = memoryAGet(ds, 0x40ecbc);
    memoryASet(ds, r32[ecx] + 0xc, r8[al]);
    r32[esp] += 4; return;
  case 0x406292: // 0000:406292
    if (r32[eax] != 0x0000005d)
        { pc = 0x4062ae; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40eca8);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r16[ax] = memoryAGet16(ds, 0x40ecac);
    memoryASet16(ds, r32[ecx] + 0x4, r16[ax]);
    r32[esp] += 4; return;
  case 0x4062ae: // 0000:4062ae
    if (r32[eax] != 0x0000005f)
        { pc = 0x4062c0; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40eca4);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r32[esp] += 4; return;
  case 0x4062c0: // 0000:4062c0
    if (r32[eax] != 0x00000060)
        { pc = 0x4062db; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ec9c);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r8[dl] = memoryAGet(ds, 0x40eca0);
    memoryASet(ds, r32[eax] + 0x4, r8[dl]);
    r32[esp] += 4; return;
  case 0x4062db: // 0000:4062db
    if (r32[eax] != 0x00000067)
        { pc = 0x40630a; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ec90);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ec94);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r16[cx] = memoryAGet16(ds, 0x40ec98);
    memoryASet16(ds, r32[eax] + 0x8, r16[cx]);
    r8[dl] = memoryAGet(ds, 0x40ec9a);
    memoryASet(ds, r32[eax] + 0xa, r8[dl]);
    r32[esp] += 4; return;
  case 0x40630a: // 0000:40630a
    if (r32[eax] != 0x00000068)
        { pc = 0x40632e; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ec84);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ec88);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r32[ecx] = memoryAGet32(ds, 0x40ec8c);
    memoryASet32(ds, r32[eax] + 0x8, r32[ecx]);
    r32[esp] += 4; return;
  case 0x40632e: // 0000:40632e
    if (r32[eax] != 0x00000069)
        { pc = 0x406359; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40ec74);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[ecx] = memoryAGet32(ds, 0x40ec78);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x40ec7c);
    memoryASet32(ds, r32[edx] + 0x8, r32[eax]);
    r8[cl] = memoryAGet(ds, 0x40ec80);
    memoryASet(ds, r32[edx] + 0xc, r8[cl]);
    r32[esp] += 4; return;
  case 0x406359: // 0000:406359
    if (r32[eax] != 0x0000006a)
        { pc = 0x406386; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40ec64);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[ecx] = memoryAGet32(ds, 0x40ec68);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x40ec6c);
    memoryASet32(ds, r32[edx] + 0x8, r32[eax]);
    r16[cx] = memoryAGet16(ds, 0x40ec70);
    memoryASet16(ds, r32[edx] + 0xc, r16[cx]);
    r32[esp] += 4; return;
  case 0x406386: // 0000:406386
    if (r32[eax] != 0x0000006b)
        { pc = 0x406397; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40ec60);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[esp] += 4; return;
  case 0x406397: // 0000:406397
    if (r32[eax] != 0x0000006c)
        { pc = 0x4063bc; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ec58);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r16[ax] = memoryAGet16(ds, 0x40ec5c);
    memoryASet16(ds, r32[ecx] + 0x4, r16[ax]);
    r8[dl] = memoryAGet(ds, 0x40ec5e);
    memoryASet(ds, r32[ecx] + 0x6, r8[dl]);
    r32[esp] += 4; return;
  case 0x4063bc: // 0000:4063bc
    if (r32[eax] != 0x0000006d)
        { pc = 0x4063e0; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ec4c);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ec50);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r8[cl] = memoryAGet(ds, 0x40ec54);
    memoryASet(ds, r32[eax] + 0x8, r8[cl]);
    r32[esp] += 4; return;
  case 0x4063e0: // 0000:4063e0
    if (r32[eax] != 0x0000006e)
        { pc = 0x406404; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40ec40);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[ecx] = memoryAGet32(ds, 0x40ec44);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r16[ax] = memoryAGet16(ds, 0x40ec48);
    memoryASet16(ds, r32[edx] + 0x8, r16[ax]);
    r32[esp] += 4; return;
  case 0x406404: // 0000:406404
    if (r32[eax] != 0x0000006f)
        { pc = 0x40641e; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ec38);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r8[al] = memoryAGet(ds, 0x40ec3c);
    memoryASet(ds, r32[ecx] + 0x4, r8[al]);
    r32[esp] += 4; return;
  case 0x40641e: // 0000:40641e
    if (r32[eax] != 0x00000070)
        { pc = 0x406441; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ec2c);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r32[eax] = memoryAGet32(ds, 0x40ec30);
    memoryASet32(ds, r32[ecx] + 0x4, r32[eax]);
    r32[edx] = memoryAGet32(ds, 0x40ec34);
    memoryASet32(ds, r32[ecx] + 0x8, r32[edx]);
    r32[esp] += 4; return;
  case 0x406441: // 0000:406441
    if (r32[eax] != 0x00000071)
        { pc = 0x406465; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, 0x40ec20);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[edx] = memoryAGet32(ds, 0x40ec24);
    memoryASet32(ds, r32[eax] + 0x4, r32[edx]);
    r8[cl] = memoryAGet(ds, 0x40ec28);
    memoryASet(ds, r32[eax] + 0x8, r8[cl]);
    r32[esp] += 4; return;
  case 0x406465: // 0000:406465
    if (r32[eax] != 0x00000072)
        { pc = 0x406489; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, 0x40ec14);
    memoryASet32(ds, r32[edx], r32[eax]);
    r32[ecx] = memoryAGet32(ds, 0x40ec18);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r16[ax] = memoryAGet16(ds, 0x40ec1c);
    memoryASet16(ds, r32[edx] + 0x8, r16[ax]);
    r32[esp] += 4; return;
  case 0x406489: // 0000:406489
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, 0x40ec08);
    memoryASet32(ds, r32[ecx], r32[edx]);
    r32[eax] = memoryAGet32(ds, 0x40ec0c);
    memoryASet32(ds, r32[ecx] + 0x4, r32[eax]);
    r16[dx] = memoryAGet16(ds, 0x40ec10);
    memoryASet16(ds, r32[ecx] + 0x8, r16[dx]);
    r32[esp] += 4;
    return;
  }
}
function* sub_4064b0() // 0000:4064b0 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[esp] += 4;
}
function* sub_4064c0() // 0000:4064c0 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[eax]);
    push32(0x00000018);
    push32(r32[ecx]);
    r32[eax] = alleg40.pack_fwrite(stack32(0), stack32(1), stack32(2));
    r32[esp] += 0x0000000c;
    r32[esp] += 4;
}
function* sub_4064e0() // 0000:4064e0 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[eax]);
    push32(0x00000018);
    push32(r32[ecx]);
    r32[eax] = alleg40.pack_fread(stack32(0), stack32(1), stack32(2));
    r32[esp] += 0x0000000c;
    r32[esp] += 4;
}
function* sub_406500() // 0000:406500 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[edi]);
    r32[edi] = 0;
    r32[eax] = r32[ecx];
  case 0x406509: // 0000:406509
    if (!memoryAGet32(ds, r32[eax]))
        { pc = 0x40651a; break; }
    r32[edi]++;
    r32[eax] += 0x00000018;
    if (r32s[edi] < signed32(0x00000200))
        { pc = 0x406509; break; }
  case 0x40651a: // 0000:40651a
    if (r32[edi] != 0x00000200)
        { pc = 0x406526; break; }
    r32[eax] = 0;
    r32[edi] = pop32();
    r32[esp] += 4; return;
  case 0x406526: // 0000:406526
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[eax] = r32[edi] + (r32[edi] * 2);
    push32(r32[esi]);
    r32[esi] = r32[ecx] + (r32[eax] * 8);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[ecx] <<= 16;
    r32[edx] <<= 16;
    memoryASet32(ds, r32[esi] + 0x4, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x8, r32[edx]);
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000032;
    idiv32(r32[ecx]);
    r32[eax] = 0x66666667;
    r32[edx] -= 0x00000019;
    r32[edx] <<= 16;
    imul32(r32[edx]);
    r32[edx] = sar32(r32[edx], 0x02);
    r32[eax] = r32[edx];
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    memoryASet32(ds, r32[esi] + 0xc, r32[edx]);
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000032;
    idiv32(r32[ecx]);
    r32[eax] = 0x51eb851f;
    r32[edx] -= 0x00000019;
    r32[edx] <<= 16;
    imul32(r32[edx]);
    r32[edx] = sar32(r32[edx], 0x04);
    r32[eax] = r32[edx];
    r32[eax] >>= 31;
    r32[edx] += r32[eax];
    memoryASet32(ds, r32[esi] + 0x10, r32[edx]);
    memoryASet32(ds, r32[esi], 0x000000ff);
    yield* sub_406be3();
    r32[eax] &= 0x80000007;
    if (r32s[eax] >= 0)
        { pc = 0x4065a6; break; }
    r32[eax]--;
    r32[eax] |= 0xfffffff8;
    r32[eax]++;
  case 0x4065a6: // 0000:4065a6
    memoryASet32(ds, r32[esi] + 0x14, r32[eax]);
    r32[eax] = r32[edi];
    r32[esi] = pop32();
    r32[edi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_4065b0() // 0000:4065b0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xc);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x8);
    r32[ecx] += r32[eax];
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x10);
    memoryASet32(ds, r32[esi] + 0x4, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi]);
    r32[edx] += r32[eax];
    r32[eax] += 0x00004ccd;
    r32[ecx]--;
    memoryASet32(ds, r32[esi] + 0x8, r32[edx]);
    memoryASet32(ds, r32[esi] + 0x10, r32[eax]);
    memoryASet32(ds, r32[esi], r32[ecx]);
    yield* sub_406be3();
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    r32[ecx] = 0x00000005;
    idiv32(r32[ecx]);
    if (r32[edx] != 0x00000001)
        { pc = 0x4065fe; break; }
    yield* sub_406be3();
    r32[eax] &= 0x80000007;
    if (r32s[eax] >= 0)
        { pc = 0x4065fb; break; }
    r32[eax]--;
    r32[eax] |= 0xfffffff8;
    r32[eax]++;
  case 0x4065fb: // 0000:4065fb
    memoryASet32(ds, r32[esi] + 0x14, r32[eax]);
  case 0x4065fe: // 0000:4065fe
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_406600() // 0000:406600 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[ecx] = 0x00000200;
  case 0x406609: // 0000:406609
    memoryASet32(ds, r32[eax], 0x00000000);
    r32[eax] += 0x00000018;
    r32[ecx]--;
    if (r32[ecx])
        { pc = 0x406609; break; }
    r32[esp] += 4;
    return;
  }
}
function* sub_406620() // 0000:406620 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[ecx] = 0;
    memoryASet32(ds, r32[eax] + 0x10, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x18, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x20, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x14, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x1c, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x30, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x34, 0x00000001);
    memoryASet32(ds, r32[eax] + 0x38, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x28, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x3c, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x40, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x44, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x2c, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x48, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x24, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x4c, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x54, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x58, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x5c, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0x60, r32[ecx]);
    r32[esp] += 4;
}
function* sub_406670() // 0000:406670 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    fld64(memoryAGet64(ds, r32[ecx] + 0x18));
    fcomp64(memoryAGet64(ds, 0x40d320));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4066a0; break; }
    fld64(memoryAGet64(ds, r32[ecx] + 0x18));
    fld64(memoryAGet64(ds, 0x40d318));
    fcomp80(st(1));
    r16[ax] = fnstsw();
    fstp80();
    if (r8[ah] & 0x41)
        { pc = 0x4066a0; break; }
    fld64(memoryAGet64(ds, 0x40d318));
    { pc = 0x4066bb; break; }
  case 0x4066a0: // 0000:4066a0
    fld64(memoryAGet64(ds, r32[ecx] + 0x18));
    fcomp64(memoryAGet64(ds, 0x40d320));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4066b5; break; }
    fld64(memoryAGet64(ds, r32[ecx] + 0x18));
    { pc = 0x4066bb; break; }
  case 0x4066b5: // 0000:4066b5
    fld64(memoryAGet64(ds, 0x40d320));
  case 0x4066bb: // 0000:4066bb
    memoryASet64(ds, r32[ecx] + 0x18, fst64());
    fld64(memoryAGet64(ds, r32[ecx] + 0x10));
    fcomp64(memoryAGet64(ds, 0x40d320));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4066ea; break; }
    fld64(memoryAGet64(ds, r32[ecx] + 0x10));
    fld64(memoryAGet64(ds, 0x40d310));
    fcomp80(st(1));
    r16[ax] = fnstsw();
    fstp80();
    if (r8[ah] & 0x41)
        { pc = 0x4066ea; break; }
    fld64(memoryAGet64(ds, 0x40d310));
    { pc = 0x406705; break; }
  case 0x4066ea: // 0000:4066ea
    fld64(memoryAGet64(ds, r32[ecx] + 0x10));
    fcomp64(memoryAGet64(ds, 0x40d320));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4066ff; break; }
    fld64(memoryAGet64(ds, r32[ecx] + 0x10));
    { pc = 0x406705; break; }
  case 0x4066ff: // 0000:4066ff
    fld64(memoryAGet64(ds, 0x40d320));
  case 0x406705: // 0000:406705
    memoryASet64(ds, r32[ecx] + 0x10, fst64());
    fld80(st(0));
    fadd64(memoryAGet64(ds, r32[ecx]));
    memoryASet64(ds, r32[ecx], fst64());
    fld80(st(2));
    fadd64(memoryAGet64(ds, r32[ecx] + 0x8));
    memoryASet64(ds, r32[ecx] + 0x8, fst64());
    fcomp64(memoryAGet64(ds, 0x40d308));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x406731; break; }
    memoryASet32(ds, r32[ecx] + 0x8, 0x00000000);
    memoryASet32(ds, r32[ecx] + 0xc, 0x408f4000);
  case 0x406731: // 0000:406731
    fcomp64(memoryAGet64(ds, 0x40d300));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x406779; break; }
    fmul64(memoryAGet64(ds, 0x40d2f8));
    memoryASet32(ds, r32[ecx], 0x00000000);
    memoryASet32(ds, r32[ecx] + 0x4, 0x40815800);
    fcom64(memoryAGet64(ds, 0x40d1e0));
    memoryASet64(ds, r32[ecx] + 0x10, fst64());
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x406763; break; }
    fchs();
  case 0x406763: // 0000:406763
    fcomp64(memoryAGet64(ds, 0x40d2f0));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x40677b; break; }
    memoryASet32(ds, r32[ecx] + 0x5c, 0xffffffec);
    { pc = 0x40677b; break; }
  case 0x406779: // 0000:406779
    fstp80();
  case 0x40677b: // 0000:40677b
    fld64(memoryAGet64(ds, r32[ecx]));
    fcomp64(memoryAGet64(ds, 0x40d2e8));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4067c6; break; }
    fld64(memoryAGet64(ds, r32[ecx] + 0x10));
    fmul64(memoryAGet64(ds, 0x40d2f8));
    memoryASet32(ds, r32[ecx], 0x00000000);
    memoryASet32(ds, r32[ecx] + 0x4, 0x40554000);
    fcom64(memoryAGet64(ds, 0x40d1e0));
    memoryASet64(ds, r32[ecx] + 0x10, fst64());
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x4067b2; break; }
    fchs();
  case 0x4067b2: // 0000:4067b2
    fcomp64(memoryAGet64(ds, 0x40d2f0));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x4067c6; break; }
    memoryASet32(ds, r32[ecx] + 0x5c, 0x00000014);
  case 0x4067c6: // 0000:4067c6
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x30);
    if (!r32[eax])
        { pc = 0x4067d8; break; }
    fadd64(memoryAGet64(ds, 0x40d2e0));
    memoryASet64(ds, r32[ecx] + 0x18, fstp64());
    { pc = 0x4067da; break; }
  case 0x4067d8: // 0000:4067d8
    fstp80();
  case 0x4067da: // 0000:4067da
    if (r32[eax] != 0x00000001)
        { pc = 0x4067f6; break; }
    fld64(memoryAGet64(ds, r32[ecx] + 0x18));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x4067f6; break; }
    memoryASet32(ds, r32[ecx] + 0x30, 0x00000002);
  case 0x4067f6: // 0000:4067f6
    r32[esp] += 4; return;
    return;
  }
}
function* sub_406800() // 0000:406800 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x30);
    if (!r32[eax])
        { pc = 0x40680e; break; }
    r32[eax] = 0;
    r32[esp] += 4; return;
  case 0x40680e: // 0000:40680e
    fld64(memoryAGet64(ds, r32[ecx] + 0x10));
    fadd80(st(0));
    r32[edx] = 0x00000001;
    memoryASet32(ds, r32[ecx] + 0x30, r32[edx]);
    fcom64(memoryAGet64(ds, 0x40d1e0));
    fld80(st(0));
    r16[ax] = fnstsw();
    if (!(r8[dl] & r8[ah]))
        { pc = 0x40682b; break; }
    fchs();
  case 0x40682b: // 0000:40682b
    fchs();
    fcomp64(memoryAGet64(ds, 0x40d310));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x40684d; break; }
    fcom64(memoryAGet64(ds, 0x40d1e0));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x406849; break; }
    fchs();
  case 0x406849: // 0000:406849
    fchs();
    { pc = 0x406855; break; }
  case 0x40684d: // 0000:40684d
    fstp80();
    fld64(memoryAGet64(ds, 0x40d310));
  case 0x406855: // 0000:406855
    memoryASet64(ds, r32[ecx] + 0x18, fst64());
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x10);
    fcomp64(memoryAGet64(ds, 0x40d218));
    memoryASet32(ds, r32[ecx] + 0x20, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x14);
    memoryASet32(ds, r32[ecx] + 0x24, r32[eax]);
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x406874; break; }
    memoryASet32(ds, r32[ecx] + 0x4c, r32[edx]);
  case 0x406874: // 0000:406874
    memoryASet32(ds, r32[ecx] + 0x50, 0x00000000);
    r32[eax] |= 0xffffffff;
    r32[esp] += 4;
    return;
  }
}
function* sub_406880() // 0000:406880 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[eax]);
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
    r32[eax] = alleg40.text_height(stack32(0));
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    memoryASet32(ds, r32[esi] + 0xc, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    memoryASet32(ds, r32[esi] + 0x14, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi], r32[eax]);
    memoryASet32(ds, r32[esi] + 0x4, r32[edx]);
    memoryASet32(ds, r32[esi] + 0x10, r32[ecx]);
    if (!r32[eax])
        { pc = 0x4068d1; break; }
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x8);
    push32(r32[edx]);
    r32[eax] = alleg40.text_length(stack32(0), stack32(1));
    memoryASet32(ds, r32[esi] + 0x20, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x10);
    r32[esp] += 0x00000008;
    memoryASet32(ds, r32[esi] + 0x18, r32[eax]);
    r32[esi] = pop32();
    r32[esp] += 4; return;
  case 0x4068d1: // 0000:4068d1
    push32(r32[edi]);
    r32[edi] = r32[edx];
    r32[ecx] |= 0xffffffff;
    r32[eax] = 0;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = ~r32[ecx];
    r32[ecx]--;
    memoryASet32(ds, r32[esi] + 0x24, r32[edx]);
    memoryASet32(ds, r32[esi] + 0x1c, 0x00000001);
    if (r32s[ecx] <= 0)
        { pc = 0x406919; break; }
  case 0x4068ec: // 0000:4068ec
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edx] += r32[eax];
    if (memoryAGet(ds, r32[edx]) != 0x0a)
        { pc = 0x406914; break; }
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x1c);
    if (r32s[edi] >= signed32(0x00000200))
        { pc = 0x406914; break; }
    r32[edx]++;
    memoryASet32(ds, r32[esi] + r32[edi] * 4 + 0x24, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x1c);
    r32[edx]++;
    memoryASet32(ds, r32[esi] + 0x1c, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x4);
    memoryASet(ds, r32[eax] + r32[edx], 0x00);
  case 0x406914: // 0000:406914
    r32[eax]++;
    if (r32s[eax] < r32s[ecx])
        { pc = 0x4068ec; break; }
  case 0x406919: // 0000:406919
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x14);
    r32[edi] = pop32();
    memoryASet32(ds, r32[esi] + 0x18, r32[eax]);
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_406930() // 0000:406930 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[edi]);
    if (!memoryAGet32(ds, r32[esi]))
        { pc = 0x4069b3; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x20);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x18);
    r32[eax] = -r32[eax];
    if (r32s[ecx] >= r32s[eax])
        { pc = 0x406950; break; }
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = 0;
    r32[ebx] = pop32();
    r32[esp] += 4; return;
  case 0x406950: // 0000:406950
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x10);
    if (r32s[ecx] <= r32s[eax])
        { pc = 0x40695e; break; }
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = 0;
    r32[ebx] = pop32();
    r32[esp] += 4; return;
  case 0x40695e: // 0000:40695e
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x14);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[ecx] += r32[ebx];
    r32[eax] += r32[ebp];
    push32(r32[ecx]);
    push32(r32[eax]);
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[edi]);
    alleg40.set_clip(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x18);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x8);
    push32(0xffffffff);
    r32[edx] += r32[ebp];
    push32(r32[ebx]);
    push32(r32[edx]);
    push32(r32[eax]);
    push32(r32[ecx]);
    push32(r32[edi]);
    alleg40.textout(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[edx] = memoryAGet32(ds, r32[edi] + 0x4);
    r32[eax] = memoryAGet32(ds, r32[edi]);
    r32[edx]--;
    r32[eax]--;
    push32(r32[edx]);
    push32(r32[eax]);
    push32(0x00000000);
    push32(0x00000000);
    push32(r32[edi]);
    alleg40.set_clip(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
    r32[esp] += 0x00000040;
    r32[eax] |= 0xffffffff;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4; return;
  case 0x4069b3: // 0000:4069b3
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xc);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x18);
    r32[ecx] = r32s[ecx] * (signed32(memoryAGet32(ds, r32[esi] + 0x1c)));
    r32[ecx] = -r32[ecx];
    if (r32s[eax] >= r32s[ecx])
        { pc = 0x4069ca; break; }
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = 0;
    r32[ebx] = pop32();
    r32[esp] += 4; return;
  case 0x4069ca: // 0000:4069ca
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x14);
    if (r32s[eax] <= r32s[ecx])
        { pc = 0x4069d8; break; }
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[eax] = 0;
    r32[ebx] = pop32();
    r32[esp] += 4; return;
  case 0x4069d8: // 0000:4069d8
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x10);
    r32[ecx] += r32[eax];
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[edx] += r32[ecx];
    push32(r32[edx]);
    push32(r32[eax]);
    push32(r32[ecx]);
    push32(r32[ebx]);
    alleg40.set_clip(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r32[esp] += 0x00000014;
    r32[edi] = 0;
    if (r32s[eax] <= 0)
        { pc = 0x406a64; break; }
    r32[eax] = r32[esi] + 36;
    memoryASet32(ds, r32[esp] + 0x18, r32[eax]);
  case 0x406a09: // 0000:406a09
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xc);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x18);
    r32[eax] = r32[ecx];
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x14);
    r32[eax] = r32s[eax] * r32s[edi];
    r32[eax] += r32[edx];
    if (r32s[eax] > r32s[ebp])
        { pc = 0x406a51; break; }
    r32[ebp] = r32[edi] + 1;
    r32[ebp] = r32s[ebp] * r32s[ecx];
    r32[ebp] += r32[edx];
    if (r32s[ebp] < 0)
        { pc = 0x406a51; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x10);
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] += r32[ecx];
    push32(0xffffffff);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[edx] = sar32(r32[edx], 0x00000001);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    r32[edx] += r32[ebp];
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x8);
    push32(r32[ecx]);
    push32(r32[edx]);
    push32(r32[ebx]);
    alleg40.textout_centre(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5));
    r32[esp] += 0x00000018;
  case 0x406a51: // 0000:406a51
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x1c);
    r32[edi]++;
    r32[ecx] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x18, r32[ecx]);
    if (r32s[edi] < r32s[eax])
        { pc = 0x406a09; break; }
  case 0x406a64: // 0000:406a64
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[ebx]);
    r32[eax]--;
    r32[ecx]--;
    push32(r32[eax]);
    push32(r32[ecx]);
    push32(0x00000000);
    push32(0x00000000);
    push32(r32[ebx]);
    alleg40.set_clip(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4));
    r32[esp] += 0x00000014;
    r32[eax] |= 0xffffffff;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_406a90() // 0000:406a90 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    memoryASet32(ds, r32[eax] + 0x18, memoryAGet32(ds, r32[eax] + 0x18) + r32[ecx]);
    r32[esp] += 4;
}
function* sub_406aa0() // 0000:406aa0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    if (!memoryAGet32(ds, r32[eax]))
        { pc = 0x406ab0; break; }
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x10);
    memoryASet32(ds, r32[eax] + 0x18, r32[ecx]);
    r32[esp] += 4; return;
  case 0x406ab0: // 0000:406ab0
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x14);
    memoryASet32(ds, r32[eax] + 0x18, r32[edx]);
    r32[esp] += 4;
    return;
  }
}
function* sub_406b00() // 0000:406b00 +long
{
    r32[esp] -= 4;
    push32(r32[esi]);
    alleg40.install_timer();
    r32[esi] = memoryAGet32(ds, 0x40d0f8);
    push32(0x000003e8);
    push32(0x00406ac0);
    yield* indirectCall(cs, r32[esi]);
    r32[eax] = 0;
    memoryASet32(ds, 0x40fcb0, r32[eax]);
    memoryASet32(ds, 0x40ffc4, r32[eax]);
    push32(0x00000014);
    push32(0x00406ae0);
    yield* indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000010;
    r32[eax] |= 0xffffffff;
    r32[esi] = pop32();
    r32[esp] += 4;
}
function* sub_406b40() // 0000:406b40 +long
{
    r32[esp] -= 4;
    push32(memoryAGet32(ds, 0x40fb18));
    push32(memoryAGet32(ds, r32[esp] + 0x8));
    yield* sub_406b52();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
    r32[esp] += 4;
}
function* sub_406b52() // 0000:406b52 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    if (memoryAGet32(ds, r32[esp] + 0x4) > 0xffffffe0)
        { pc = 0x406b7b; break; }
  case 0x406b59: // 0000:406b59
    push32(memoryAGet32(ds, r32[esp] + 0x4));
    yield* sub_406b7e();
    r32[ecx] = pop32();
    if (r32[eax])
        { pc = 0x406b7d; break; }
    if (memoryAGet32(ds, r32[esp] + 0x8) == r32[eax])
        { pc = 0x406b7d; break; }
    push32(memoryAGet32(ds, r32[esp] + 0x4));
    yield* sub_406fbc();
    r32[ecx] = pop32();
    if (r32[eax])
        { pc = 0x406b59; break; }
  case 0x406b7b: // 0000:406b7b
    r32[eax] = 0;
  case 0x406b7d: // 0000:406b7d
    r32[esp] += 4; return;
    return;
  }
}
function* sub_406b7e() // 0000:406b7e +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x8);
    if (r32[esi] > memoryAGet32(ds, 0x40eed4))
        { pc = 0x406b96; break; }
    push32(r32[esi]);
    yield* sub_4073a7();
    r32[ecx] = pop32();
    if (r32[eax])
        { pc = 0x406bb2; break; }
  case 0x406b96: // 0000:406b96
    if (r32[esi])
        { pc = 0x406b9d; break; }
    push32(0x00000001);
    r32[esi] = pop32();
  case 0x406b9d: // 0000:406b9d
    r32[esi] += 0x0000000f;
    r32[esi] &= 0xfffffff0;
    push32(r32[esi]);
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x42d17c));
    r32[eax] = kernel32.HeapAlloc(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
  case 0x406bb2: // 0000:406bb2
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_406bb4() // 0000:406bb4 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x8);
    if (!r32[esi])
        { pc = 0x406be1; break; }
    push32(r32[esi]);
    yield* sub_407051();
    r32[ecx] = pop32();
    push32(r32[esi]);
    if (!r32[eax])
        { pc = 0x406bd3; break; }
    push32(r32[eax]);
    yield* sub_40707c();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
    r32[esi] = pop32();
    r32[esp] += 4; return;
  case 0x406bd3: // 0000:406bd3
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x42d17c));
    r32[eax] = kernel32.HeapFree(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
  case 0x406be1: // 0000:406be1
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_406be3() // 0000:406be3 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x40eeb0);
    r32[eax] = r32s[eax] * signed32(0x000343fd);
    r32[eax] += 0x00269ec3;
    memoryASet32(ds, 0x40eeb0, r32[eax]);
    r32[eax] = sar32(r32[eax], 0x10);
    r32[eax] &= 0x00007fff;
    r32[esp] += 4;
}
function* sub_406c01() // 0000:406c01 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x40eebc);
    if (!r32[eax])
        { pc = 0x406c0c; break; }
    yield* indirectCall(cs, r32[eax]);
  case 0x406c0c: // 0000:406c0c
    push32(0x0040e018);
    push32(0x0040e008);
    yield* sub_406ce9();
    push32(0x0040e004);
    push32(0x0040e000);
    yield* sub_406ce9();
    r32[esp] += 0x00000010;
    r32[esp] += 4;
    return;
  }
}
function* sub_406c2e() // 0000:406c2e +long
{
    r32[esp] -= 4;
    push32(0x00000000);
    push32(0x00000000);
    push32(memoryAGet32(ds, r32[esp] + 0xc));
    yield* sub_406c50();
    r32[esp] += 0x0000000c;
    r32[esp] += 4;
}
function* sub_406c50() // 0000:406c50 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[edi]);
    push32(0x00000001);
    r32[edi] = pop32();
    if (memoryAGet32(ds, 0x40fb00) != r32[edi])
        { pc = 0x406c6d; break; }
    push32(memoryAGet32(ds, r32[esp] + 0x8));
    r32[eax] = kernel32.GetCurrentProcess();
    push32(r32[eax]);
    r32[eax] = kernel32.TerminateProcess(stack32(0), stack32(1)); r32[esp] += 8;
  case 0x406c6d: // 0000:406c6d
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x14);
    memoryASet32(ds, 0x40fafc, r32[edi]);
    memoryASet(ds, 0x40faf8, r8[bl]);
    if (memoryAGet32(ds, r32[esp] + 0xc))
        { pc = 0x406cc1; break; }
    r32[eax] = memoryAGet32(ds, 0x42d190);
    if (!r32[eax])
        { pc = 0x406cb0; break; }
    r32[ecx] = memoryAGet32(ds, 0x42d18c);
    push32(r32[esi]);
    r32[esi] = r32[ecx] - 4;
    if (r32[esi] < r32[eax])
        { pc = 0x406caf; break; }
  case 0x406c9c: // 0000:406c9c
    r32[eax] = memoryAGet32(ds, r32[esi]);
    if (!r32[eax])
        { pc = 0x406ca4; break; }
    yield* indirectCall(cs, r32[eax]);
  case 0x406ca4: // 0000:406ca4
    r32[esi] -= 0x00000004;
    if (r32[esi] >= memoryAGet32(ds, 0x42d190))
        { pc = 0x406c9c; break; }
  case 0x406caf: // 0000:406caf
    r32[esi] = pop32();
  case 0x406cb0: // 0000:406cb0
    push32(0x0040e024);
    push32(0x0040e01c);
    yield* sub_406ce9();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
  case 0x406cc1: // 0000:406cc1
    push32(0x0040e02c);
    push32(0x0040e028);
    yield* sub_406ce9();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
    flags.zero = r32[ebx] == 0;
    r32[ebx] = pop32();
    if (!flags.zero)
        { pc = 0x406ce7; break; }
    push32(memoryAGet32(ds, r32[esp] + 0x8));
    memoryASet32(ds, 0x40fb00, r32[edi]);
    kernel32.ExitProcess(stack32(0)); r32[esp] += 4;
  case 0x406ce7: // 0000:406ce7
    r32[edi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_406ce9() // 0000:406ce9 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x8);
  case 0x406cee: // 0000:406cee
    if (r32[esi] >= memoryAGet32(ds, r32[esp] + 0xc))
        { pc = 0x406d01; break; }
    r32[eax] = memoryAGet32(ds, r32[esi]);
    if (!r32[eax])
        { pc = 0x406cfc; break; }
    yield* indirectCall(cs, r32[eax]);
  case 0x406cfc: // 0000:406cfc
    r32[esi] += 0x00000004;
    { pc = 0x406cee; break; }
  case 0x406d01: // 0000:406d01
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_406d82() // 0000:406d82 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0x00000080);
    yield* sub_406b40();
    r32[ecx] = pop32();
    memoryASet32(ds, 0x42d190, r32[eax]);
    if (r32[eax])
        { pc = 0x406da3; break; }
    push32(0x00000018);
    yield* sub_406f73();
    r32[eax] = memoryAGet32(ds, 0x42d190);
    r32[ecx] = pop32();
  case 0x406da3: // 0000:406da3
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) & 0x00000000);
    r32[eax] = memoryAGet32(ds, 0x42d190);
    memoryASet32(ds, 0x42d18c, r32[eax]);
    r32[esp] += 4;
    return;
  }
}
function* sub_406db1() // 0000:406db1 +long
{
    r32[esp] -= 4;
    yield* sub_406dc9();
    yield* sub_407ceb();
    memoryASet32(ds, 0x40fb08, r32[eax]);
    yield* sub_407c9b();
    stop("disassembly failed at 0000:406dc5 (fnclex )");
    r32[esp] += 4;
}
function* sub_406dc9() // 0000:406dc9 +long
{
    r32[esp] -= 4;
    r32[eax] = 0x004080d9;
    memoryASet32(ds, 0x40eedc, 0x00407d6e);
    memoryASet32(ds, 0x40eed8, r32[eax]);
    memoryASet32(ds, 0x40eee0, 0x00407dd4);
    memoryASet32(ds, 0x40eee4, 0x00407d14);
    memoryASet32(ds, 0x40eee8, 0x00407dbc);
    memoryASet32(ds, 0x40eeec, r32[eax]);
    r32[esp] += 4;
}
function* sub_406e04() // 0000:406e04 +long
{
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] += 0xfffffff4;
    memoryASet16(ss, r32[ebp] - 2, fnstcw());
    r16[ax] = memoryAGet16(ss, r32[ebp] - 2);
    r8[ah] |= 0x0c;
    memoryASet16(ss, r32[ebp] - 4, r16[ax]);
    fldcw(memoryAGet16(ss, r32[ebp] - 4));
    memoryASet64(ss, r32[ebp] - 12, fistp64());
    fldcw(memoryAGet16(ss, r32[ebp] - 2));
    r32[eax] = memoryAGet32(ss, r32[ebp] - 12);
    r32[edx] = memoryAGet32(ss, r32[ebp] - 8);
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
}
function* sub_406e2b() // 0000:406e2b +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x00000020;
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    push32(r32[esi]);
    memoryASet32(ss, r32[ebp] - 24, r32[eax]);
    memoryASet32(ss, r32[ebp] - 32, r32[eax]);
    r32[eax] = r32[ebp] + 16;
    memoryASet32(ss, r32[ebp] - 20, 0x00000042);
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 32;
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    memoryASet32(ss, r32[ebp] - 28, 0x7fffffff);
    push32(r32[eax]);
    yield* sub_408264();
    r32[esp] += 0x0000000c;
    memoryASet32(ss, r32[ebp] - 28, memoryAGet32(ss, r32[ebp] - 28) - 1);
    r32[esi] = r32[eax];
    if (signed32(memoryAGet32(ss, r32[ebp] - 28)) < 0)
        { pc = 0x406e6b; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] - 32);
    memoryASet(ds, r32[eax], memoryAGet(ds, r32[eax]) & 0x00);
    { pc = 0x406e78; break; }
  case 0x406e6b: // 0000:406e6b
    r32[eax] = r32[ebp] - 32;
    push32(r32[eax]);
    push32(0x00000000);
    yield* sub_40814f();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
  case 0x406e78: // 0000:406e78
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_406e7d() // 0000:406e7d +entry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(0xffffffff);
    push32(0x0040d328);
    push32(0x00409328);
    //r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    //memoryASet32(fs, 0x0, r32[esp]);
    r32[esp] -= 0x00000058;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    memoryASet32(ss, r32[ebp] - 24, r32[esp]);
    r32[eax] = kernel32.GetVersion();
    r32[edx] = 0;
    r8[dl] = r8[ah];
    memoryASet32(ds, 0x40fad0, r32[edx]);
    r32[ecx] = r32[eax];
    r32[ecx] &= 0x000000ff;
    memoryASet32(ds, 0x40facc, r32[ecx]);
    r32[ecx] <<= 8;
    r32[ecx] += r32[edx];
    memoryASet32(ds, 0x40fac8, r32[ecx]);
    r32[eax] >>= 16;
    memoryASet32(ds, 0x40fac4, r32[eax]);
    r32[esi] = 0;
    push32(r32[esi]);
    yield* sub_406fd7();
    r32[ecx] = pop32();
    if (r32[eax])
        { pc = 0x406ee9; break; }
    push32(0x0000001c);
    yield* sub_406f98();
    r32[ecx] = pop32();
  case 0x406ee9: // 0000:406ee9
    memoryASet32(ss, r32[ebp] - 4, r32[esi]);
    yield* sub_409082();
    r32[eax] = kernel32.GetCommandLineA();
    memoryASet32(ds, 0x42d180, r32[eax]);
    //yield* sub_408f50();
    memoryASet32(ds, 0x40fb0c, r32[eax]);
    //yield* sub_408d03();
    //yield* sub_408c4a();
    //yield* sub_406c01();
    memoryASet32(ss, r32[ebp] - 48, r32[esi]);
    r32[eax] = r32[ebp] - 92;
    push32(r32[eax]);
    kernel32.GetStartupInfoA(stack32(0)); r32[esp] += 4;
    //yield* sub_408bf2();
    memoryASet32(ss, r32[ebp] - 100, r32[eax]);
    if (!(memoryAGet(ss, r32[ebp] - 48) & 0x01))
        { pc = 0x406f36; break; }
    r32[eax] = memoryAGet16(ss, r32[ebp] - 44);
    { pc = 0x406f39; break; }
  case 0x406f36: // 0000:406f36
    push32(0x0000000a);
    r32[eax] = pop32();
  case 0x406f39: // 0000:406f39
    push32(r32[eax]);
    push32(memoryAGet32(ss, r32[ebp] - 100));
    push32(r32[esi]);
    push32(r32[esi]);
    r32[eax] = kernel32.GetModuleHandleA(stack32(0)); r32[esp] += 4;
    push32(r32[eax]);
    yield* sub_404f90();
    memoryASet32(ss, r32[ebp] - 96, r32[eax]);
    push32(r32[eax]);
    yield* sub_406c2e();
    r32[eax] = memoryAGet32(ss, r32[ebp] - 20);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[ecx]);
    memoryASet32(ss, r32[ebp] - 104, r32[ecx]);
    push32(r32[eax]);
    push32(r32[ecx]);
    yield* sub_408a6e();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
    stop("stack_unbalanced");
    return;
  }
}
function* sub_406f73() // 0000:406f73 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    if (memoryAGet32(ds, 0x40fb14) != 0x00000001)
        { pc = 0x406f81; break; }
    yield* sub_409400();
  case 0x406f81: // 0000:406f81
    push32(memoryAGet32(ds, r32[esp] + 0x4));
    yield* sub_409439();
    push32(0x000000ff);
    yield* indirectCall(cs, memoryAGet32(ds, 0x40eec8));
    r32[ecx] = pop32();
    r32[ecx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_406f98() // 0000:406f98 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    if (memoryAGet32(ds, 0x40fb14) != 0x00000001)
        { pc = 0x406fa6; break; }
    yield* sub_409400();
  case 0x406fa6: // 0000:406fa6
    push32(memoryAGet32(ds, r32[esp] + 0x4));
    yield* sub_409439();
    r32[ecx] = pop32();
    push32(0x000000ff);
    kernel32.ExitProcess(stack32(0)); r32[esp] += 4;
    r32[esp] += 4;
    return;
  }
}
function* sub_406fbc() // 0000:406fbc +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x40fb1c);
    if (!r32[eax])
        { pc = 0x406fd4; break; }
    push32(memoryAGet32(ds, r32[esp] + 0x4));
    yield* indirectCall(cs, r32[eax]);
    r32[ecx] = pop32();
    if (!r32[eax])
        { pc = 0x406fd4; break; }
    push32(0x00000001);
    r32[eax] = pop32();
    r32[esp] += 4; return;
  case 0x406fd4: // 0000:406fd4
    r32[eax] = 0;
    r32[esp] += 4;
    return;
  }
}
function* sub_406fd7() // 0000:406fd7 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = 0;
    push32(0x00000000);
    push32(0x00001000);
    r8[al] = memoryAGet32(ds, r32[esp] + 0x8) == r32[eax];
    push32(r32[eax]);
    r32[eax] = kernel32.HeapCreate(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
    memoryASet32(ds, 0x42d17c, r32[eax]);
    if (!r32[eax])
        { pc = 0x40700c; break; }
    yield* sub_407013();
    if (r32[eax])
        { pc = 0x40700f; break; }
    push32(memoryAGet32(ds, 0x42d17c));
    r32[eax] = kernel32.HeapDestroy(stack32(0)); r32[esp] += 4;
  case 0x40700c: // 0000:40700c
    r32[eax] = 0;
    r32[esp] += 4; return;
  case 0x40700f: // 0000:40700f
    push32(0x00000001);
    r32[eax] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_407013() // 0000:407013 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0x00000140);
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x42d17c));
    r32[eax] = kernel32.HeapAlloc(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
    memoryASet32(ds, 0x42d178, r32[eax]);
    if (r32[eax])
        { pc = 0x407030; break; }
    r32[esp] += 4; return;
  case 0x407030: // 0000:407030
    memoryASet32(ds, 0x42d170, memoryAGet32(ds, 0x42d170) & 0x00000000);
    memoryASet32(ds, 0x42d174, memoryAGet32(ds, 0x42d174) & 0x00000000);
    push32(0x00000001);
    memoryASet32(ds, 0x42d16c, r32[eax]);
    memoryASet32(ds, 0x42d164, 0x00000010);
    r32[eax] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_407051() // 0000:407051 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x42d174);
    r32[ecx] = r32[eax] + (r32[eax] * 4);
    r32[eax] = memoryAGet32(ds, 0x42d178);
    r32[ecx] = r32[eax] + (r32[ecx] * 4);
  case 0x407061: // 0000:407061
    if (r32[eax] >= r32[ecx])
        { pc = 0x407079; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[edx] -= memoryAGet32(ds, r32[eax] + 0xc);
    if (r32[edx] < 0x00100000)
        { pc = 0x40707b; break; }
    r32[eax] += 0x00000014;
    { pc = 0x407061; break; }
  case 0x407079: // 0000:407079
    r32[eax] = 0;
  case 0x40707b: // 0000:40707b
    r32[esp] += 4; return;
    return;
  }
}
function* sub_40707c() // 0000:40707c +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x00000014;
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x10);
    r32[esi] = r32[edx];
    r32[esi] -= memoryAGet32(ds, r32[ecx] + 0xc);
    r32[ebx] = memoryAGet32(ds, r32[edx] - 4);
    r32[edx] += 0xfffffffc;
    push32(r32[edi]);
    r32[esi] >>= 15;
    r32[ecx] = r32[esi];
    r32[edi] = memoryAGet32(ds, r32[edx] - 4);
    r32[ecx] = r32s[ecx] * signed32(0x00000204);
    r32[ebx]--;
    memoryASet32(ss, r32[ebp] - 4, r32[edi]);
    r32[ecx] = (r32[ecx] + r32[eax]) + 324;
    memoryASet32(ss, r32[ebp] - 12, r32[ebx]);
    memoryASet32(ss, r32[ebp] - 16, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[ebx] + r32[edx]);
    memoryASet32(ss, r32[ebp] - 8, r32[ecx]);
    if (r8[cl] & 0x01)
        { pc = 0x407142; break; }
    r32[ecx] = sar32(r32[ecx], 0x04);
    push32(0x0000003f);
    r32[ecx]--;
    r32[edi] = pop32();
    memoryASet32(ss, r32[ebp] + 0xc, r32[ecx]);
    if (r32[ecx] <= r32[edi])
        { pc = 0x4070d4; break; }
    memoryASet32(ss, r32[ebp] + 0xc, r32[edi]);
  case 0x4070d4: // 0000:4070d4
    r32[ecx] = memoryAGet32(ds, r32[ebx] + r32[edx] + 0x4);
    if (r32[ecx] != memoryAGet32(ds, r32[ebx] + r32[edx] + 0x8))
        { pc = 0x407126; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0xc);
    if (r32[ecx] >= 0x00000020)
        { pc = 0x407102; break; }
    r32[edi] = 0x80000000;
    r32[edi] >>= r8[cl];
    r32[ecx] = (r32[ecx] + r32[eax]) + 4;
    r32[edi] = ~r32[edi];
    memoryASet32(ds, r32[eax] + r32[esi] * 4 + 0x44, memoryAGet32(ds, r32[eax] + r32[esi] * 4 + 0x44) & r32[edi]);
    memoryASet(ds, r32[ecx], memoryAGet(ds, r32[ecx]) - 1);
    if (memoryAGet(ds, r32[ecx]))
        { pc = 0x407126; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) & r32[edi]);
    { pc = 0x407126; break; }
  case 0x407102: // 0000:407102
    r32[ecx] += 0xffffffe0;
    r32[edi] = 0x80000000;
    r32[edi] >>= r8[cl];
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[ecx] = (r32[ecx] + r32[eax]) + 4;
    r32[edi] = ~r32[edi];
    memoryASet32(ds, r32[eax] + r32[esi] * 4 + 0xc4, memoryAGet32(ds, r32[eax] + r32[esi] * 4 + 0xc4) & r32[edi]);
    memoryASet(ds, r32[ecx], memoryAGet(ds, r32[ecx]) - 1);
    if (memoryAGet(ds, r32[ecx]))
        { pc = 0x407126; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx] + 0x4, memoryAGet32(ds, r32[ecx] + 0x4) & r32[edi]);
  case 0x407126: // 0000:407126
    r32[ecx] = memoryAGet32(ds, r32[ebx] + r32[edx] + 0x8);
    r32[edi] = memoryAGet32(ds, r32[ebx] + r32[edx] + 0x4);
    memoryASet32(ds, r32[ecx] + 0x4, r32[edi]);
    r32[ecx] = memoryAGet32(ds, r32[ebx] + r32[edx] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[ebx] + r32[edx] + 0x8);
    r32[ebx] += memoryAGet32(ss, r32[ebp] - 8);
    memoryASet32(ds, r32[ecx] + 0x8, r32[edi]);
    memoryASet32(ss, r32[ebp] - 12, r32[ebx]);
  case 0x407142: // 0000:407142
    r32[edi] = r32[ebx];
    r32[edi] = sar32(r32[edi], 0x04);
    r32[edi]--;
    if (r32[edi] <= 0x0000003f)
        { pc = 0x407150; break; }
    push32(0x0000003f);
    r32[edi] = pop32();
  case 0x407150: // 0000:407150
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[ecx] &= 0x00000001;
    memoryASet32(ss, r32[ebp] - 20, r32[ecx]);
    if (r32[ecx])
        { pc = 0x4071ff; break; }
    r32[edx] -= memoryAGet32(ss, r32[ebp] - 4);
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[ecx] = sar32(r32[ecx], 0x04);
    push32(0x0000003f);
    memoryASet32(ss, r32[ebp] - 8, r32[edx]);
    r32[ecx]--;
    r32[edx] = pop32();
    memoryASet32(ss, r32[ebp] + 0xc, r32[ecx]);
    if (r32[ecx] <= r32[edx])
        { pc = 0x40717b; break; }
    memoryASet32(ss, r32[ebp] + 0xc, r32[edx]);
    r32[ecx] = r32[edx];
  case 0x40717b: // 0000:40717b
    r32[ebx] += memoryAGet32(ss, r32[ebp] - 4);
    r32[edi] = r32[ebx];
    memoryASet32(ss, r32[ebp] - 12, r32[ebx]);
    r32[edi] = sar32(r32[edi], 0x04);
    r32[edi]--;
    if (r32[edi] <= r32[edx])
        { pc = 0x40718d; break; }
    r32[edi] = r32[edx];
  case 0x40718d: // 0000:40718d
    if (r32[ecx] == r32[edi])
        { pc = 0x4071fc; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x4);
    if (r32[edx] != memoryAGet32(ds, r32[ecx] + 0x8))
        { pc = 0x4071e4; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0xc);
    if (r32[ecx] >= 0x00000020)
        { pc = 0x4071c0; break; }
    r32[edx] = 0x80000000;
    r32[edx] >>= r8[cl];
    r32[ecx] = (r32[ecx] + r32[eax]) + 4;
    r32[edx] = ~r32[edx];
    memoryASet32(ds, r32[eax] + r32[esi] * 4 + 0x44, memoryAGet32(ds, r32[eax] + r32[esi] * 4 + 0x44) & r32[edx]);
    memoryASet(ds, r32[ecx], memoryAGet(ds, r32[ecx]) - 1);
    if (memoryAGet(ds, r32[ecx]))
        { pc = 0x4071e4; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) & r32[edx]);
    { pc = 0x4071e4; break; }
  case 0x4071c0: // 0000:4071c0
    r32[ecx] += 0xffffffe0;
    r32[edx] = 0x80000000;
    r32[edx] >>= r8[cl];
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[ecx] = (r32[ecx] + r32[eax]) + 4;
    r32[edx] = ~r32[edx];
    memoryASet32(ds, r32[eax] + r32[esi] * 4 + 0xc4, memoryAGet32(ds, r32[eax] + r32[esi] * 4 + 0xc4) & r32[edx]);
    memoryASet(ds, r32[ecx], memoryAGet(ds, r32[ecx]) - 1);
    if (memoryAGet(ds, r32[ecx]))
        { pc = 0x4071e4; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx] + 0x4, memoryAGet32(ds, r32[ecx] + 0x4) & r32[edx]);
  case 0x4071e4: // 0000:4071e4
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x8);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x4);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    memoryASet32(ds, r32[edx] + 0x8, r32[ecx]);
  case 0x4071fc: // 0000:4071fc
    r32[edx] = memoryAGet32(ss, r32[ebp] - 8);
  case 0x4071ff: // 0000:4071ff
    if (memoryAGet32(ss, r32[ebp] - 20))
        { pc = 0x40720e; break; }
    if (memoryAGet32(ss, r32[ebp] + 0xc) == r32[edi])
        { pc = 0x407297; break; }
  case 0x40720e: // 0000:40720e
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 16);
    r32[ecx] = r32[ecx] + (r32[edi] * 8);
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x4);
    memoryASet32(ds, r32[edx] + 0x4, r32[ecx]);
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 16);
    r32[ecx] = r32[ecx] + (r32[edi] * 8);
    memoryASet32(ds, r32[edx] + 0x8, r32[ecx]);
    memoryASet32(ds, r32[ecx] + 0x4, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x4);
    memoryASet32(ds, r32[ecx] + 0x8, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x4);
    if (r32[ecx] != memoryAGet32(ds, r32[edx] + 0x8))
        { pc = 0x407297; break; }
    r8[cl] = memoryAGet(ds, r32[edi] + r32[eax] + 0x4);
    memoryASet(ss, r32[ebp] + 0xf, r8[cl]);
    r8[cl]++;
    memoryASet(ds, r32[edi] + r32[eax] + 0x4, r8[cl]);
    if (r32[edi] >= 0x00000020)
        { pc = 0x40726b; break; }
    if (memoryAGet(ss, r32[ebp] + 0xf))
        { pc = 0x40725a; break; }
    r32[ebx] = 0x80000000;
    r32[ecx] = r32[edi];
    r32[ebx] >>= r8[cl];
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) | r32[ebx]);
  case 0x40725a: // 0000:40725a
    r32[ebx] = 0x80000000;
    r32[ecx] = r32[edi];
    r32[ebx] >>= r8[cl];
    r32[eax] = (r32[eax] + (r32[esi] * 4)) + 68;
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) | r32[ebx]);
    { pc = 0x407294; break; }
  case 0x40726b: // 0000:40726b
    if (memoryAGet(ss, r32[ebp] + 0xf))
        { pc = 0x407281; break; }
    r32[ecx] = r32[edi] - 32;
    r32[ebx] = 0x80000000;
    r32[ebx] >>= r8[cl];
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, r32[ecx] + 0x4, memoryAGet32(ds, r32[ecx] + 0x4) | r32[ebx]);
  case 0x407281: // 0000:407281
    r32[ecx] = r32[edi] - 32;
    r32[edi] = 0x80000000;
    r32[edi] >>= r8[cl];
    r32[eax] = (r32[eax] + (r32[esi] * 4)) + 196;
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) | r32[edi]);
  case 0x407294: // 0000:407294
    r32[ebx] = memoryAGet32(ss, r32[ebp] - 12);
  case 0x407297: // 0000:407297
    r32[eax] = memoryAGet32(ss, r32[ebp] - 16);
    memoryASet32(ds, r32[edx], r32[ebx]);
    memoryASet32(ds, r32[ebx] + r32[edx] - 4, r32[ebx]);
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) - 1);
    if (memoryAGet32(ds, r32[eax]))
        { pc = 0x4073a2; break; }
    r32[eax] = memoryAGet32(ds, 0x42d170);
    if (!r32[eax])
        { pc = 0x407394; break; }
    r32[ecx] = memoryAGet32(ds, 0x42d168);
    r32[edi] = memoryAGet32(ds, 0x40d078);
    r32[ecx] <<= 15;
    r32[ecx] += memoryAGet32(ds, r32[eax] + 0xc);
    r32[ebx] = 0x00008000;
    push32(0x00004000);
    push32(r32[ebx]);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[edi]);
    r32[ecx] = memoryAGet32(ds, 0x42d168);
    r32[eax] = memoryAGet32(ds, 0x42d170);
    r32[edx] = 0x80000000;
    r32[edx] >>= r8[cl];
    memoryASet32(ds, r32[eax] + 0x8, memoryAGet32(ds, r32[eax] + 0x8) | r32[edx]);
    r32[eax] = memoryAGet32(ds, 0x42d170);
    r32[ecx] = memoryAGet32(ds, 0x42d168);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x10);
    memoryASet32(ds, r32[eax] + r32[ecx] * 4 + 0xc4, memoryAGet32(ds, r32[eax] + r32[ecx] * 4 + 0xc4) & 0x00000000);
    r32[eax] = memoryAGet32(ds, 0x42d170);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x10);
    memoryASet(ds, r32[eax] + 0x43, memoryAGet(ds, r32[eax] + 0x43) - 1);
    r32[eax] = memoryAGet32(ds, 0x42d170);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x10);
    if (memoryAGet(ds, r32[ecx] + 0x43))
        { pc = 0x407322; break; }
    memoryASet32(ds, r32[eax] + 0x4, memoryAGet32(ds, r32[eax] + 0x4) & 0xfffffffe);
    r32[eax] = memoryAGet32(ds, 0x42d170);
  case 0x407322: // 0000:407322
    if (memoryAGet32(ds, r32[eax] + 0x8) != 0xffffffff)
        { pc = 0x407394; break; }
    push32(r32[ebx]);
    push32(0x00000000);
    push32(memoryAGet32(ds, r32[eax] + 0xc));
    yield* indirectCall(cs, r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x42d170);
    push32(memoryAGet32(ds, r32[eax] + 0x10));
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x42d17c));
    r32[eax] = kernel32.HeapFree(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
    r32[eax] = memoryAGet32(ds, 0x42d174);
    r32[edx] = memoryAGet32(ds, 0x42d178);
    r32[eax] = r32[eax] + (r32[eax] * 4);
    r32[eax] <<= 2;
    r32[ecx] = r32[eax];
    r32[eax] = memoryAGet32(ds, 0x42d170);
    r32[ecx] -= r32[eax];
    r32[ecx] = (r32[ecx] + r32[edx]) + -20;
    push32(r32[ecx]);
    r32[ecx] = r32[eax] + 20;
    push32(r32[ecx]);
    push32(r32[eax]);
    yield* sub_409590();
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[esp] += 0x0000000c;
    memoryASet32(ds, 0x42d174, memoryAGet32(ds, 0x42d174) - 1);
    if (r32[eax] <= memoryAGet32(ds, 0x42d170))
        { pc = 0x407386; break; }
    r32[eax] -= 0x00000014;
  case 0x407386: // 0000:407386
    r32[ecx] = memoryAGet32(ds, 0x42d178);
    memoryASet32(ds, 0x42d16c, r32[ecx]);
    { pc = 0x407397; break; }
  case 0x407394: // 0000:407394
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
  case 0x407397: // 0000:407397
    memoryASet32(ds, 0x42d170, r32[eax]);
    memoryASet32(ds, 0x42d168, r32[esi]);
  case 0x4073a2: // 0000:4073a2
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_4073a7() // 0000:4073a7 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x00000014;
    r32[eax] = memoryAGet32(ds, 0x42d174);
    r32[edx] = memoryAGet32(ds, 0x42d178);
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[eax] = r32[eax] + (r32[eax] * 4);
    push32(r32[edi]);
    r32[edi] = r32[edx] + (r32[eax] * 4);
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ss, r32[ebp] - 4, r32[edi]);
    r32[ecx] = r32[eax] + 23;
    r32[ecx] &= 0xfffffff0;
    memoryASet32(ss, r32[ebp] - 16, r32[ecx]);
    r32[ecx] = sar32(r32[ecx], 0x04);
    r32[ecx]--;
    if (r32s[ecx] >= signed32(0x00000020))
        { pc = 0x4073e7; break; }
    r32[esi] |= 0xffffffff;
    r32[esi] >>= r8[cl];
    memoryASet32(ss, r32[ebp] - 8, memoryAGet32(ss, r32[ebp] - 8) | 0xffffffff);
    memoryASet32(ss, r32[ebp] - 12, r32[esi]);
    { pc = 0x4073f7; break; }
  case 0x4073e7: // 0000:4073e7
    r32[ecx] += 0xffffffe0;
    r32[eax] |= 0xffffffff;
    r32[esi] = 0;
    r32[eax] >>= r8[cl];
    memoryASet32(ss, r32[ebp] - 12, r32[esi]);
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
  case 0x4073f7: // 0000:4073f7
    r32[eax] = memoryAGet32(ds, 0x42d16c);
    r32[ebx] = r32[eax];
    memoryASet32(ss, r32[ebp] + 0x8, r32[ebx]);
    if (r32[ebx] >= r32[edi])
        { pc = 0x40741e; break; }
  case 0x407405: // 0000:407405
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[ebx]);
    r32[ecx] &= memoryAGet32(ss, r32[ebp] - 8);
    r32[edi] &= r32[esi];
    r32[ecx] |= r32[edi];
    if (r32[ecx])
        { pc = 0x40741e; break; }
    r32[ebx] += 0x00000014;
    memoryASet32(ss, r32[ebp] + 0x8, r32[ebx]);
    if (r32[ebx] < memoryAGet32(ss, r32[ebp] - 4))
        { pc = 0x407405; break; }
  case 0x40741e: // 0000:40741e
    if (r32[ebx] != memoryAGet32(ss, r32[ebp] - 4))
        { pc = 0x40749c; break; }
    r32[ebx] = r32[edx];
  case 0x407425: // 0000:407425
    flags.zero = r32[ebx] == r32[eax];
    memoryASet32(ss, r32[ebp] + 0x8, r32[ebx]);
    if (r32[ebx] >= r32[eax])
        { pc = 0x407441; break; }
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[ebx]);
    r32[ecx] &= memoryAGet32(ss, r32[ebp] - 8);
    r32[edi] &= r32[esi];
    r32[ecx] |= r32[edi];
    if (r32[ecx])
        { pc = 0x40743f; break; }
    r32[ebx] += 0x00000014;
    { pc = 0x407425; break; }
  case 0x40743f: // 0000:40743f
    flags.zero = r32[ebx] == r32[eax];
  case 0x407441: // 0000:407441
    if (!flags.zero)
        { pc = 0x40749c; break; }
  case 0x407443: // 0000:407443
    flags.zero = r32[ebx] == memoryAGet32(ss, r32[ebp] - 4);
    if (r32[ebx] >= memoryAGet32(ss, r32[ebp] - 4))
        { pc = 0x407459; break; }
    if (memoryAGet32(ds, r32[ebx] + 0x8))
        { pc = 0x407456; break; }
    r32[ebx] += 0x00000014;
    memoryASet32(ss, r32[ebp] + 0x8, r32[ebx]);
    { pc = 0x407443; break; }
  case 0x407456: // 0000:407456
    flags.zero = r32[ebx] == memoryAGet32(ss, r32[ebp] - 4);
  case 0x407459: // 0000:407459
    if (!flags.zero)
        { pc = 0x407481; break; }
    r32[ebx] = r32[edx];
  case 0x40745d: // 0000:40745d
    flags.zero = r32[ebx] == r32[eax];
    memoryASet32(ss, r32[ebp] + 0x8, r32[ebx]);
    if (r32[ebx] >= r32[eax])
        { pc = 0x407471; break; }
    if (memoryAGet32(ds, r32[ebx] + 0x8))
        { pc = 0x40746f; break; }
    r32[ebx] += 0x00000014;
    { pc = 0x40745d; break; }
  case 0x40746f: // 0000:40746f
    flags.zero = r32[ebx] == r32[eax];
  case 0x407471: // 0000:407471
    if (!flags.zero)
        { pc = 0x407481; break; }
    yield* sub_4076b0();
    r32[ebx] = r32[eax];
    memoryASet32(ss, r32[ebp] + 0x8, r32[ebx]);
    if (!r32[ebx])
        { pc = 0x407495; break; }
  case 0x407481: // 0000:407481
    push32(r32[ebx]);
    yield* sub_407761();
    r32[ecx] = pop32();
    r32[ecx] = memoryAGet32(ds, r32[ebx] + 0x10);
    memoryASet32(ds, r32[ecx], r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x10);
    if (memoryAGet32(ds, r32[eax]) != 0xffffffff)
        { pc = 0x40749c; break; }
  case 0x407495: // 0000:407495
    r32[eax] = 0;
    { pc = 0x4076ab; break; }
  case 0x40749c: // 0000:40749c
    memoryASet32(ds, 0x42d16c, r32[ebx]);
    r32[eax] = memoryAGet32(ds, r32[ebx] + 0x10);
    r32[edx] = memoryAGet32(ds, r32[eax]);
    memoryASet32(ss, r32[ebp] - 4, r32[edx]);
    if (r32[edx] == 0xffffffff)
        { pc = 0x4074c3; break; }
    r32[ecx] = memoryAGet32(ds, r32[eax] + r32[edx] * 4 + 0xc4);
    r32[edi] = memoryAGet32(ds, r32[eax] + r32[edx] * 4 + 0x44);
    r32[ecx] &= memoryAGet32(ss, r32[ebp] - 8);
    r32[edi] &= r32[esi];
    r32[ecx] |= r32[edi];
    if (r32[ecx])
        { pc = 0x4074fa; break; }
  case 0x4074c3: // 0000:4074c3
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xc4);
    r32[esi] = memoryAGet32(ds, r32[eax] + 0x44);
    r32[edx] &= memoryAGet32(ss, r32[ebp] - 8);
    r32[esi] &= memoryAGet32(ss, r32[ebp] - 12);
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) & 0x00000000);
    r32[ecx] = r32[eax] + 68;
    flags.zero = !(r32[edx] | r32[esi]);
    r32[edx] |= r32[esi];
    r32[esi] = memoryAGet32(ss, r32[ebp] - 12);
    if (!flags.zero)
        { pc = 0x4074f7; break; }
  case 0x4074e0: // 0000:4074e0
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x84);
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) + 1);
    r32[edx] &= memoryAGet32(ss, r32[ebp] - 8);
    r32[ecx] += 0x00000004;
    r32[edi] = r32[esi];
    r32[edi] &= memoryAGet32(ds, r32[ecx]);
    r32[edx] |= r32[edi];
    if (!r32[edx])
        { pc = 0x4074e0; break; }
  case 0x4074f7: // 0000:4074f7
    r32[edx] = memoryAGet32(ss, r32[ebp] - 4);
  case 0x4074fa: // 0000:4074fa
    r32[ecx] = r32[edx];
    r32[edi] = 0;
    r32[ecx] = r32s[ecx] * signed32(0x00000204);
    r32[ecx] = (r32[ecx] + r32[eax]) + 324;
    memoryASet32(ss, r32[ebp] - 12, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + r32[edx] * 4 + 0x44);
    r32[ecx] &= r32[esi];
    if (r32[ecx])
        { pc = 0x407523; break; }
    r32[ecx] = memoryAGet32(ds, r32[eax] + r32[edx] * 4 + 0xc4);
    push32(0x00000020);
    r32[ecx] &= memoryAGet32(ss, r32[ebp] - 8);
    r32[edi] = pop32();
  case 0x407523: // 0000:407523
    if (r32s[ecx] < 0)
        { pc = 0x40752c; break; }
    r32[ecx] <<= 1;
    r32[edi]++;
    { pc = 0x407523; break; }
  case 0x40752c: // 0000:40752c
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[edx] = memoryAGet32(ds, r32[ecx] + r32[edi] * 8 + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[edx]);
    r32[ecx] -= memoryAGet32(ss, r32[ebp] - 16);
    r32[esi] = r32[ecx];
    memoryASet32(ss, r32[ebp] - 8, r32[ecx]);
    r32[esi] = sar32(r32[esi], 0x04);
    r32[esi]--;
    if (r32s[esi] <= signed32(0x0000003f))
        { pc = 0x407549; break; }
    push32(0x0000003f);
    r32[esi] = pop32();
  case 0x407549: // 0000:407549
    if (r32[esi] == r32[edi])
        { pc = 0x40765e; break; }
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x4);
    if (r32[ecx] != memoryAGet32(ds, r32[edx] + 0x8))
        { pc = 0x4075ba; break; }
    if (r32s[edi] >= signed32(0x00000020))
        { pc = 0x407589; break; }
    r32[ebx] = 0x80000000;
    r32[ecx] = r32[edi];
    r32[ebx] >>= r8[cl];
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[edi] = (r32[eax] + r32[edi]) + 4;
    r32[ebx] = ~r32[ebx];
    memoryASet32(ss, r32[ebp] - 20, r32[ebx]);
    r32[ebx] &= memoryAGet32(ds, r32[eax] + r32[ecx] * 4 + 0x44);
    memoryASet32(ds, r32[eax] + r32[ecx] * 4 + 0x44, r32[ebx]);
    memoryASet(ds, r32[edi], memoryAGet(ds, r32[edi]) - 1);
    if (memoryAGet(ds, r32[edi]))
        { pc = 0x4075b7; break; }
    r32[ebx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 20);
    memoryASet32(ds, r32[ebx], memoryAGet32(ds, r32[ebx]) & r32[ecx]);
    { pc = 0x4075ba; break; }
  case 0x407589: // 0000:407589
    r32[ecx] = r32[edi] - 32;
    r32[ebx] = 0x80000000;
    r32[ebx] >>= r8[cl];
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[edi] = (r32[eax] + r32[edi]) + 4;
    r32[ecx] = (r32[eax] + (r32[ecx] * 4)) + 196;
    r32[ebx] = ~r32[ebx];
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) & r32[ebx]);
    memoryASet(ds, r32[edi], memoryAGet(ds, r32[edi]) - 1);
    memoryASet32(ss, r32[ebp] - 20, r32[ebx]);
    if (memoryAGet(ds, r32[edi]))
        { pc = 0x4075b7; break; }
    r32[ebx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 20);
    memoryASet32(ds, r32[ebx] + 0x4, memoryAGet32(ds, r32[ebx] + 0x4) & r32[ecx]);
    { pc = 0x4075ba; break; }
  case 0x4075b7: // 0000:4075b7
    r32[ebx] = memoryAGet32(ss, r32[ebp] + 0x8);
  case 0x4075ba: // 0000:4075ba
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x8);
    r32[edi] = memoryAGet32(ds, r32[edx] + 0x4);
    memoryASet32(ds, r32[ecx] + 0x4, r32[edi]);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[edx] + 0x8);
    memoryASet32(ds, r32[ecx] + 0x8, r32[edi]);
    if (!memoryAGet32(ss, r32[ebp] - 8))
        { pc = 0x40766a; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 12);
    r32[edi] = memoryAGet32(ds, r32[ecx] + r32[esi] * 8 + 0x4);
    r32[ecx] = r32[ecx] + (r32[esi] * 8);
    memoryASet32(ds, r32[edx] + 0x4, r32[edi]);
    memoryASet32(ds, r32[edx] + 0x8, r32[ecx]);
    memoryASet32(ds, r32[ecx] + 0x4, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x4);
    memoryASet32(ds, r32[ecx] + 0x8, r32[edx]);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0x4);
    if (r32[ecx] != memoryAGet32(ds, r32[edx] + 0x8))
        { pc = 0x40765b; break; }
    r8[cl] = memoryAGet(ds, r32[esi] + r32[eax] + 0x4);
    memoryASet(ss, r32[ebp] + 0xb, r8[cl]);
    if (r32s[esi] >= signed32(0x00000020))
        { pc = 0x40762c; break; }
    r8[cl]++;
    memoryASet(ds, r32[esi] + r32[eax] + 0x4, r8[cl]);
    if (memoryAGet(ss, r32[ebp] + 0xb))
        { pc = 0x40761a; break; }
    r32[edi] = 0x80000000;
    r32[ecx] = r32[esi];
    r32[edi] >>= r8[cl];
    memoryASet32(ds, r32[ebx], memoryAGet32(ds, r32[ebx]) | r32[edi]);
  case 0x40761a: // 0000:40761a
    r32[edi] = 0x80000000;
    r32[ecx] = r32[esi];
    r32[edi] >>= r8[cl];
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    memoryASet32(ds, r32[eax] + r32[ecx] * 4 + 0x44, memoryAGet32(ds, r32[eax] + r32[ecx] * 4 + 0x44) | r32[edi]);
    { pc = 0x40765b; break; }
  case 0x40762c: // 0000:40762c
    r8[cl]++;
    memoryASet(ds, r32[esi] + r32[eax] + 0x4, r8[cl]);
    if (memoryAGet(ss, r32[ebp] + 0xb))
        { pc = 0x407645; break; }
    r32[ecx] = r32[esi] - 32;
    r32[edi] = 0x80000000;
    r32[edi] >>= r8[cl];
    memoryASet32(ds, r32[ebx] + 0x4, memoryAGet32(ds, r32[ebx] + 0x4) | r32[edi]);
  case 0x407645: // 0000:407645
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[edi] = (r32[eax] + (r32[ecx] * 4)) + 196;
    r32[ecx] = r32[esi] - 32;
    r32[esi] = 0x80000000;
    r32[esi] >>= r8[cl];
    memoryASet32(ds, r32[edi], memoryAGet32(ds, r32[edi]) | r32[esi]);
  case 0x40765b: // 0000:40765b
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
  case 0x40765e: // 0000:40765e
    if (!r32[ecx])
        { pc = 0x40766d; break; }
    memoryASet32(ds, r32[edx], r32[ecx]);
    memoryASet32(ds, r32[ecx] + r32[edx] - 4, r32[ecx]);
    { pc = 0x40766d; break; }
  case 0x40766a: // 0000:40766a
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
  case 0x40766d: // 0000:40766d
    r32[esi] = memoryAGet32(ss, r32[ebp] - 16);
    r32[edx] += r32[ecx];
    r32[ecx] = r32[esi] + 1;
    memoryASet32(ds, r32[edx], r32[ecx]);
    memoryASet32(ds, r32[edx] + r32[esi] - 4, r32[ecx]);
    r32[esi] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ecx] = memoryAGet32(ds, r32[esi]);
    r32[edi] = r32[ecx] + 1;
    memoryASet32(ds, r32[esi], r32[edi]);
    if (r32[ecx])
        { pc = 0x4076a3; break; }
    if (r32[ebx] != memoryAGet32(ds, 0x42d170))
        { pc = 0x4076a3; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    if (r32[ecx] != memoryAGet32(ds, 0x42d168))
        { pc = 0x4076a3; break; }
    memoryASet32(ds, 0x42d170, memoryAGet32(ds, 0x42d170) & 0x00000000);
  case 0x4076a3: // 0000:4076a3
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[eax] = r32[edx] + 4;
  case 0x4076ab: // 0000:4076ab
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_4076b0() // 0000:4076b0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x42d174);
    r32[ecx] = memoryAGet32(ds, 0x42d164);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edi] = 0;
    if (r32[eax] != r32[ecx])
        { pc = 0x4076f3; break; }
    r32[eax] = (r32[ecx] + (r32[ecx] * 4)) + 80;
    r32[eax] <<= 2;
    push32(r32[eax]);
    push32(memoryAGet32(ds, 0x42d178));
    push32(r32[edi]);
    push32(memoryAGet32(ds, 0x42d17c));
    r32[eax] = kernel32.HeapReAlloc(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
    if (r32[eax] == r32[edi])
        { pc = 0x407743; break; }
    memoryASet32(ds, 0x42d164, memoryAGet32(ds, 0x42d164) + 0x00000010);
    memoryASet32(ds, 0x42d178, r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x42d174);
  case 0x4076f3: // 0000:4076f3
    r32[ecx] = memoryAGet32(ds, 0x42d178);
    push32(0x000041c4);
    push32(0x00000008);
    r32[eax] = r32[eax] + (r32[eax] * 4);
    push32(memoryAGet32(ds, 0x42d17c));
    r32[esi] = r32[ecx] + (r32[eax] * 4);
    r32[eax] = kernel32.HeapAlloc(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
    memoryASet32(ds, r32[esi] + 0x10, r32[eax]);
    if (r32[eax] == r32[edi])
        { pc = 0x407743; break; }
    push32(0x00000004);
    push32(0x00002000);
    push32(0x00100000);
    push32(r32[edi]);
    r32[eax] = kernel32.VirtualAlloc(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
    memoryASet32(ds, r32[esi] + 0xc, r32[eax]);
    if (r32[eax] != r32[edi])
        { pc = 0x407747; break; }
    push32(memoryAGet32(ds, r32[esi] + 0x10));
    push32(r32[edi]);
    push32(memoryAGet32(ds, 0x42d17c));
    r32[eax] = kernel32.HeapFree(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
  case 0x407743: // 0000:407743
    r32[eax] = 0;
    { pc = 0x40775e; break; }
  case 0x407747: // 0000:407747
    memoryASet32(ds, r32[esi] + 0x8, memoryAGet32(ds, r32[esi] + 0x8) | 0xffffffff);
    memoryASet32(ds, r32[esi], r32[edi]);
    memoryASet32(ds, r32[esi] + 0x4, r32[edi]);
    memoryASet32(ds, 0x42d174, memoryAGet32(ds, 0x42d174) + 1);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x10);
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) | 0xffffffff);
    r32[eax] = r32[esi];
  case 0x40775e: // 0000:40775e
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_407761() // 0000:407761 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x10);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x8);
    r32[ebx] = 0;
  case 0x407773: // 0000:407773
    if (r32s[eax] < 0)
        { pc = 0x40777c; break; }
    r32[eax] <<= 1;
    r32[ebx]++;
    { pc = 0x407773; break; }
  case 0x40777c: // 0000:40777c
    r32[eax] = r32[ebx];
    push32(0x0000003f);
    r32[eax] = r32s[eax] * signed32(0x00000204);
    r32[edx] = pop32();
    r32[eax] = (r32[eax] + r32[esi]) + 324;
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
  case 0x407791: // 0000:407791
    memoryASet32(ds, r32[eax] + 0x8, r32[eax]);
    memoryASet32(ds, r32[eax] + 0x4, r32[eax]);
    r32[eax] += 0x00000008;
    r32[edx]--;
    if (r32[edx])
        { pc = 0x407791; break; }
    r32[edi] = r32[ebx];
    push32(0x00000004);
    r32[edi] <<= 15;
    r32[edi] += memoryAGet32(ds, r32[ecx] + 0xc);
    push32(0x00001000);
    push32(0x00008000);
    push32(r32[edi]);
    r32[eax] = kernel32.VirtualAlloc(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
    if (r32[eax])
        { pc = 0x4077c4; break; }
    r32[eax] |= 0xffffffff;
    { pc = 0x407857; break; }
  case 0x4077c4: // 0000:4077c4
    r32[edx] = r32[edi] + 28672;
    if (r32[edi] > r32[edx])
        { pc = 0x40780a; break; }
    r32[eax] = r32[edi] + 16;
  case 0x4077d1: // 0000:4077d1
    memoryASet32(ds, r32[eax] - 8, memoryAGet32(ds, r32[eax] - 8) | 0xffffffff);
    memoryASet32(ds, r32[eax] + 0xfec, memoryAGet32(ds, r32[eax] + 0xfec) | 0xffffffff);
    r32[ecx] = r32[eax] + 4092;
    memoryASet32(ds, r32[eax] - 4, 0x00000ff0);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r32[ecx] = r32[eax] - 4100;
    memoryASet32(ds, r32[eax] + 0x4, r32[ecx]);
    memoryASet32(ds, r32[eax] + 0xfe8, 0x00000ff0);
    r32[eax] += 0x00001000;
    r32[ecx] = r32[eax] - 16;
    if (r32[ecx] <= r32[edx])
        { pc = 0x4077d1; break; }
  case 0x40780a: // 0000:40780a
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[ecx] = r32[edi] + 12;
    r32[eax] += 0x000001f8;
    push32(0x00000001);
    r32[edi] = pop32();
    memoryASet32(ds, r32[eax] + 0x4, r32[ecx]);
    memoryASet32(ds, r32[ecx] + 0x8, r32[eax]);
    r32[ecx] = r32[edx] + 12;
    memoryASet32(ds, r32[eax] + 0x8, r32[ecx]);
    memoryASet32(ds, r32[ecx] + 0x4, r32[eax]);
    memoryASet32(ds, r32[esi] + r32[ebx] * 4 + 0x44, memoryAGet32(ds, r32[esi] + r32[ebx] * 4 + 0x44) & 0x00000000);
    memoryASet32(ds, r32[esi] + r32[ebx] * 4 + 0xc4, r32[edi]);
    r8[al] = memoryAGet(ds, r32[esi] + 0x43);
    r8[cl] = r8[al];
    r8[cl]++;
    flags.zero = r8[al] == 0;
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet(ds, r32[esi] + 0x43, r8[cl]);
    if (!flags.zero)
        { pc = 0x407847; break; }
    memoryASet32(ds, r32[eax] + 0x4, memoryAGet32(ds, r32[eax] + 0x4) | r32[edi]);
  case 0x407847: // 0000:407847
    r32[edx] = 0x80000000;
    r32[ecx] = r32[ebx];
    r32[edx] >>= r8[cl];
    r32[edx] = ~r32[edx];
    memoryASet32(ds, r32[eax] + 0x8, memoryAGet32(ds, r32[eax] + 0x8) & r32[edx]);
    r32[eax] = r32[ebx];
  case 0x407857: // 0000:407857
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_407c9b() // 0000:407c9b +long
{
    r32[esp] -= 4;
    push32(0x00030000);
    push32(0x00010000);
    yield* sub_409c3a();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
    r32[esp] += 4;
}
function* sub_407ceb() // 0000:407ceb +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    { pc = 0x407ceb; break; }
  case 0x407cad: // 0000:407cad
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x00000018;
    fld64(memoryAGet64(ds, 0x40d340));
    memoryASet64(ss, r32[ebp] - 8, fstp64());
    fld64(memoryAGet64(ds, 0x40d338));
    memoryASet64(ss, r32[ebp] - 16, fstp64());
    fld64(memoryAGet64(ss, r32[ebp] - 16));
    fdiv64(memoryAGet64(ss, r32[ebp] - 8));
    fmul64(memoryAGet64(ss, r32[ebp] - 8));
    fsubr64(memoryAGet64(ss, r32[ebp] - 16)); // dc 6d f0 : fsubr qword ptr [ebp - 0x10]
    memoryASet64(ss, r32[ebp] - 24, fstp64());
    fld64(memoryAGet64(ss, r32[ebp] - 24));
    fcomp64(memoryAGet64(ds, 0x40d1b8));
    r16[ax] = fnstsw();
    sahf();
    if (stop("TODO: reads sahf"))
        { pc = 0x407ce7; break; }
    push32(0x00000001);
    r32[eax] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4; return;
  case 0x407ce7: // 0000:407ce7
    r32[eax] = 0;
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4; return;
  case 0x407ceb: // 0000:407ceb
    push32(0x0040d364);
    r32[eax] = kernel32.GetModuleHandleA(stack32(0)); r32[esp] += 4;
    if (!r32[eax])
        { pc = 0x407d0f; break; }
    push32(0x0040d348);
    push32(r32[eax]);
    r32[eax] = kernel32.GetProcAddress(stack32(0), stack32(1)); r32[esp] += 8;
    if (!r32[eax])
        { pc = 0x407d0f; break; }
    push32(0x00000000);
    yield* indirectCall(cs, r32[eax]);
    stop("stack_unbalanced");
    r32[esp] += 4; return;
  case 0x407d0f: // 0000:407d0f
    { pc = 0x407cad; break; }
    return;
  }
}
function* sub_40814f() // 0000:40814f +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xc);
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x10);
    if (!(r8[al] & 0x82))
        { pc = 0x408258; break; }
    if (r8[al] & 0x40)
        { pc = 0x408258; break; }
    if (!(r8[al] & 0x01))
        { pc = 0x408187; break; }
    memoryASet32(ds, r32[esi] + 0x4, memoryAGet32(ds, r32[esi] + 0x4) & 0x00000000);
    if (!(r8[al] & 0x10))
        { pc = 0x408258; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x8);
    r8[al] &= 0xfe;
    memoryASet32(ds, r32[esi], r32[ecx]);
    memoryASet32(ds, r32[esi] + 0xc, r32[eax]);
  case 0x408187: // 0000:408187
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xc);
    memoryASet32(ds, r32[esi] + 0x4, memoryAGet32(ds, r32[esi] + 0x4) & 0x00000000);
    memoryASet32(ss, r32[ebp] + 0xc, memoryAGet32(ss, r32[ebp] + 0xc) & 0x00000000);
    r8[al] &= 0xef;
    r8[al] |= 0x02;
    memoryASet32(ds, r32[esi] + 0xc, r32[eax]);
    if (r16[ax] & 0x010c)
        { pc = 0x4081c1; break; }
    if (r32[esi] == 0x0040f2a0)
        { pc = 0x4081af; break; }
    if (r32[esi] != 0x0040f2c0)
        { pc = 0x4081ba; break; }
  case 0x4081af: // 0000:4081af
    push32(r32[ebx]);
    yield* sub_40a89f();
    r32[ecx] = pop32();
    if (r32[eax])
        { pc = 0x4081c1; break; }
  case 0x4081ba: // 0000:4081ba
    push32(r32[esi]);
    yield* sub_40a85b();
    r32[ecx] = pop32();
  case 0x4081c1: // 0000:4081c1
    push32(r32[edi]);
    if (!(memoryAGet16(ds, r32[esi] + 0xc) & 0x0108))
        { pc = 0x40822e; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x8);
    r32[edi] = memoryAGet32(ds, r32[esi]);
    r32[edi] -= r32[eax];
    r32[ecx] = r32[eax] + 1;
    memoryASet32(ds, r32[esi], r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x18);
    r32[ecx]--;
    memoryASet32(ds, r32[esi] + 0x4, r32[ecx]);
    if (r32s[edi] <= 0)
        { pc = 0x4081f1; break; }
    push32(r32[edi]);
    push32(r32[eax]);
    push32(r32[ebx]);
    yield* sub_40a6ae();
    r32[esp] += 0x0000000c;
    memoryASet32(ss, r32[ebp] + 0xc, r32[eax]);
    { pc = 0x408224; break; }
  case 0x4081f1: // 0000:4081f1
    if (r32[ebx] == 0xffffffff)
        { pc = 0x40820c; break; }
    r32[eax] = r32[ebx];
    r32[ecx] = r32[ebx];
    r32[eax] = sar32(r32[eax], 0x05);
    r32[ecx] &= 0x0000001f;
    r32[eax] = memoryAGet32(ds, r32[eax] * 4 + 0x42d060);
    r32[eax] = r32[eax] + (r32[ecx] * 8);
    { pc = 0x408211; break; }
  case 0x40820c: // 0000:40820c
    r32[eax] = 0x0040ef80;
  case 0x408211: // 0000:408211
    if (!(memoryAGet(ds, r32[eax] + 0x4) & 0x20))
        { pc = 0x408224; break; }
    push32(0x00000002);
    push32(0x00000000);
    push32(r32[ebx]);
    yield* sub_40a614();
    r32[esp] += 0x0000000c;
  case 0x408224: // 0000:408224
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x8);
    r8[cl] = memoryAGet(ss, r32[ebp] + 0x8);
    memoryASet(ds, r32[eax], r8[cl]);
    { pc = 0x408242; break; }
  case 0x40822e: // 0000:40822e
    push32(0x00000001);
    r32[eax] = r32[ebp] + 8;
    r32[edi] = pop32();
    push32(r32[edi]);
    push32(r32[eax]);
    push32(r32[ebx]);
    yield* sub_40a6ae();
    r32[esp] += 0x0000000c;
    memoryASet32(ss, r32[ebp] + 0xc, r32[eax]);
  case 0x408242: // 0000:408242
    flags.zero = memoryAGet32(ss, r32[ebp] + 0xc) == r32[edi];
    r32[edi] = pop32();
    if (flags.zero)
        { pc = 0x40824e; break; }
    memoryASet32(ds, r32[esi] + 0xc, memoryAGet32(ds, r32[esi] + 0xc) | 0x00000020);
    { pc = 0x40825d; break; }
  case 0x40824e: // 0000:40824e
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[eax] &= 0x000000ff;
    { pc = 0x408260; break; }
  case 0x408258: // 0000:408258
    r8[al] |= 0x20;
    memoryASet32(ds, r32[esi] + 0xc, r32[eax]);
  case 0x40825d: // 0000:40825d
    r32[eax] |= 0xffffffff;
  case 0x408260: // 0000:408260
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_408264() // 0000:408264 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x00000248;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[esi] = 0;
    r8[bl] = memoryAGet(ds, r32[edi]);
    r32[edi]++;
    memoryASet32(ss, r32[ebp] - 12, r32[esi]);
    memoryASet32(ss, r32[ebp] - 20, r32[esi]);
    memoryASet32(ss, r32[ebp] + 0xc, r32[edi]);
    if (!r8[bl])
        { pc = 0x40897d; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 16);
    r32[edx] = 0;
    { pc = 0x408298; break; }
  case 0x408290: // 0000:408290
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 16);
    r32[esi] = memoryAGet32(ss, r32[ebp] - 48);
    r32[edx] = 0;
  case 0x408298: // 0000:408298
    if (signed32(memoryAGet32(ss, r32[ebp] - 20)) < r32s[edx])
        { pc = 0x40897d; break; }
    if (r8s[bl] < signed8(0x20))
        { pc = 0x4082b9; break; }
    if (r8s[bl] > signed8(0x78))
        { pc = 0x4082b9; break; }
    r32[eax] = r8s[bl];
    r8[al] = memoryAGet(ds, r32[eax] + 0x40d358);
    r32[eax] &= 0x0000000f;
    { pc = 0x4082bb; break; }
  case 0x4082b9: // 0000:4082b9
    r32[eax] = 0;
  case 0x4082bb: // 0000:4082bb
    r32[eax] = signed8(memoryAGet(ds, r32[esi] + r32[eax] * 8 + 0x40d378));
    r32[eax] = sar32(r32[eax], 0x04);
    memoryASet32(ss, r32[ebp] - 48, r32[eax]);
    if (r32[eax] > 0x00000007)
        { pc = 0x40896c; break; }
    switch (r32[eax])
    {
        case 0: { pc = 0x408403; break; }
        case 1: { pc = 0x4082d9; break; }
        case 2: { pc = 0x4082f4; break; }
        case 3: { pc = 0x408340; break; }
        case 4: { pc = 0x408377; break; }
        case 5: { pc = 0x40837f; break; }
        case 6: { pc = 0x4083b4; break; }
        case 7: { pc = 0x408447; break; }
        default:
            stop("ind 0000:4082d2");
    }
    break;
  case 0x4082d9: // 0000:4082d9
    memoryASet32(ss, r32[ebp] - 16, memoryAGet32(ss, r32[ebp] - 16) | 0xffffffff);
    memoryASet32(ss, r32[ebp] - 52, r32[edx]);
    memoryASet32(ss, r32[ebp] - 40, r32[edx]);
    memoryASet32(ss, r32[ebp] - 32, r32[edx]);
    memoryASet32(ss, r32[ebp] - 28, r32[edx]);
    memoryASet32(ss, r32[ebp] - 4, r32[edx]);
    memoryASet32(ss, r32[ebp] - 36, r32[edx]);
    { pc = 0x40896c; break; }
  case 0x4082f4: // 0000:4082f4
    r32[eax] = r8s[bl];
    r32[eax] -= 0x00000020;
    if (!r32[eax])
        { pc = 0x408337; break; }
    r32[eax] -= 0x00000003;
    if (!r32[eax])
        { pc = 0x40832e; break; }
    r32[eax] -= 0x00000008;
    if (!r32[eax])
        { pc = 0x408325; break; }
    r32[eax]--;
    r32[eax]--;
    if (!r32[eax])
        { pc = 0x40831c; break; }
    r32[eax] -= 0x00000003;
    if (r32[eax])
        { pc = 0x40896c; break; }
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0x00000008);
    { pc = 0x40896c; break; }
  case 0x40831c: // 0000:40831c
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0x00000004);
    { pc = 0x40896c; break; }
  case 0x408325: // 0000:408325
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0x00000001);
    { pc = 0x40896c; break; }
  case 0x40832e: // 0000:40832e
    memoryASet(ss, r32[ebp] - 4, memoryAGet(ss, r32[ebp] - 4) | 0x80);
    { pc = 0x40896c; break; }
  case 0x408337: // 0000:408337
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0x00000002);
    { pc = 0x40896c; break; }
  case 0x408340: // 0000:408340
    if (r8[bl] != 0x2a)
        { pc = 0x408368; break; }
    r32[eax] = r32[ebp] + 16;
    push32(r32[eax]);
    yield* sub_408a43();
    r32[ecx] = pop32();
    memoryASet32(ss, r32[ebp] - 32, r32[eax]);
    if (r32s[eax] >= 0)
        { pc = 0x40896c; break; }
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0x00000004);
    r32[eax] = -r32[eax];
  case 0x408360: // 0000:408360
    memoryASet32(ss, r32[ebp] - 32, r32[eax]);
    { pc = 0x40896c; break; }
  case 0x408368: // 0000:408368
    r32[eax] = memoryAGet32(ss, r32[ebp] - 32);
    r32[ecx] = r8s[bl];
    r32[eax] = r32[eax] + (r32[eax] * 4);
    r32[eax] = (r32[ecx] + (r32[eax] * 2)) + -48;
    { pc = 0x408360; break; }
  case 0x408377: // 0000:408377
    memoryASet32(ss, r32[ebp] - 16, r32[edx]);
    { pc = 0x40896c; break; }
  case 0x40837f: // 0000:40837f
    if (r8[bl] != 0x2a)
        { pc = 0x4083a2; break; }
    r32[eax] = r32[ebp] + 16;
    push32(r32[eax]);
    yield* sub_408a43();
    r32[ecx] = pop32();
    memoryASet32(ss, r32[ebp] - 16, r32[eax]);
    if (r32s[eax] >= 0)
        { pc = 0x40896c; break; }
    memoryASet32(ss, r32[ebp] - 16, memoryAGet32(ss, r32[ebp] - 16) | 0xffffffff);
    { pc = 0x40896c; break; }
  case 0x4083a2: // 0000:4083a2
    r32[eax] = r32[ecx] + (r32[ecx] * 4);
    r32[ecx] = r8s[bl];
    r32[eax] = (r32[ecx] + (r32[eax] * 2)) + -48;
    memoryASet32(ss, r32[ebp] - 16, r32[eax]);
    { pc = 0x40896c; break; }
  case 0x4083b4: // 0000:4083b4
    if (r8[bl] == 0x49)
        { pc = 0x4083e7; break; }
    if (r8[bl] == 0x68)
        { pc = 0x4083de; break; }
    if (r8[bl] == 0x6c)
        { pc = 0x4083d5; break; }
    if (r8[bl] != 0x77)
        { pc = 0x40896c; break; }
    memoryASet(ss, r32[ebp] - 3, memoryAGet(ss, r32[ebp] - 3) | 0x08);
    { pc = 0x40896c; break; }
  case 0x4083d5: // 0000:4083d5
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0x00000010);
    { pc = 0x40896c; break; }
  case 0x4083de: // 0000:4083de
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0x00000020);
    { pc = 0x40896c; break; }
  case 0x4083e7: // 0000:4083e7
    if (memoryAGet(ds, r32[edi]) != 0x36)
        { pc = 0x408400; break; }
    if (memoryAGet(ds, r32[edi] + 0x1) != 0x34)
        { pc = 0x408400; break; }
    r32[edi]++;
    r32[edi]++;
    memoryASet(ss, r32[ebp] - 3, memoryAGet(ss, r32[ebp] - 3) | 0x80);
    memoryASet32(ss, r32[ebp] + 0xc, r32[edi]);
    { pc = 0x40896c; break; }
  case 0x408400: // 0000:408400
    memoryASet32(ss, r32[ebp] - 48, r32[edx]);
  case 0x408403: // 0000:408403
    r32[ecx] = memoryAGet32(ds, 0x40f03c);
    memoryASet32(ss, r32[ebp] - 36, r32[edx]);
    r32[eax] = r8[bl];
    if (!(memoryAGet(ds, r32[ecx] + r32[eax] * 2 + 0x1) & 0x80))
        { pc = 0x40842f; break; }
    r32[eax] = r32[ebp] - 20;
    push32(r32[eax]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    r32[eax] = r8s[bl];
    push32(r32[eax]);
    yield* sub_4089a5();
    r8[bl] = memoryAGet(ds, r32[edi]);
    r32[esp] += 0x0000000c;
    r32[edi]++;
    memoryASet32(ss, r32[ebp] + 0xc, r32[edi]);
  case 0x40842f: // 0000:40842f
    r32[eax] = r32[ebp] - 20;
    push32(r32[eax]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    r32[eax] = r8s[bl];
    push32(r32[eax]);
    yield* sub_4089a5();
    r32[esp] += 0x0000000c;
    { pc = 0x40896c; break; }
  case 0x408447: // 0000:408447
    r32[eax] = r8s[bl];
    if (r32s[eax] > signed32(0x00000067))
        { pc = 0x40866f; break; }
    if (r32s[eax] >= signed32(0x00000065))
        { pc = 0x4084f2; break; }
    if (r32s[eax] > signed32(0x00000058))
        { pc = 0x408550; break; }
    if (r32[eax] == 0x00000058)
        { pc = 0x4086e3; break; }
    r32[eax] -= 0x00000043;
    if (!r32[eax])
        { pc = 0x408513; break; }
    r32[eax]--;
    r32[eax]--;
    if (!r32[eax])
        { pc = 0x4084e8; break; }
    r32[eax]--;
    r32[eax]--;
    if (!r32[eax])
        { pc = 0x4084e8; break; }
    r32[eax] -= 0x0000000c;
    if (r32[eax])
        { pc = 0x40886e; break; }
    if (memoryAGet16(ss, r32[ebp] - 4) & 0x0830)
        { pc = 0x408491; break; }
    memoryASet(ss, r32[ebp] - 3, memoryAGet(ss, r32[ebp] - 3) | 0x08);
  case 0x408491: // 0000:408491
    r32[esi] = memoryAGet32(ss, r32[ebp] - 16);
    if (r32[esi] != 0xffffffff)
        { pc = 0x40849e; break; }
    r32[esi] = 0x7fffffff;
  case 0x40849e: // 0000:40849e
    r32[eax] = r32[ebp] + 16;
    push32(r32[eax]);
    yield* sub_408a43();
    r32[ecx] = pop32();
    r32[ecx] = r32[eax];
    memoryASet32(ss, r32[ebp] - 8, r32[ecx]);
    if (!(memoryAGet16(ss, r32[ebp] - 4) & 0x0810))
        { pc = 0x4086b7; break; }
    if (r32[ecx])
        { pc = 0x4084c6; break; }
    r32[ecx] = memoryAGet32(ds, 0x40eef4);
    memoryASet32(ss, r32[ebp] - 8, r32[ecx]);
  case 0x4084c6: // 0000:4084c6
    memoryASet32(ss, r32[ebp] - 36, 0x00000001);
    r32[eax] = r32[ecx];
  case 0x4084cf: // 0000:4084cf
    r32[edx] = r32[esi];
    r32[esi]--;
    if (!r32[edx])
        { pc = 0x4086ae; break; }
    if (!memoryAGet16(ds, r32[eax]))
        { pc = 0x4086ae; break; }
    r32[eax]++;
    r32[eax]++;
    { pc = 0x4084cf; break; }
  case 0x4084e8: // 0000:4084e8
    memoryASet32(ss, r32[ebp] - 52, 0x00000001);
    r8[bl] += 0x20;
  case 0x4084f2: // 0000:4084f2
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0x00000040);
    r32[edi] = r32[ebp] - 584;
    memoryASet32(ss, r32[ebp] - 8, r32[edi]);
    if (r32s[ecx] >= r32s[edx])
        { pc = 0x4085d6; break; }
    memoryASet32(ss, r32[ebp] - 16, 0x00000006);
    { pc = 0x4085e4; break; }
  case 0x408513: // 0000:408513
    if (memoryAGet16(ss, r32[ebp] - 4) & 0x0830)
        { pc = 0x40851f; break; }
    memoryASet(ss, r32[ebp] - 3, memoryAGet(ss, r32[ebp] - 3) | 0x08);
  case 0x40851f: // 0000:40851f
    r32[eax] = r32[ebp] + 16;
    push32(r32[eax]);
    if (!(memoryAGet16(ss, r32[ebp] - 4) & 0x0810))
        { pc = 0x408566; break; }
    yield* sub_408a60();
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 584;
    push32(r32[eax]);
    yield* sub_40a97e();
    r32[esp] += 0x0000000c;
    memoryASet32(ss, r32[ebp] - 12, r32[eax]);
    if (r32s[eax] >= 0)
        { pc = 0x408579; break; }
    memoryASet32(ss, r32[ebp] - 40, 0x00000001);
    { pc = 0x408579; break; }
  case 0x408550: // 0000:408550
    r32[eax] -= 0x0000005a;
    if (!r32[eax])
        { pc = 0x408587; break; }
    r32[eax] -= 0x00000009;
    if (!r32[eax])
        { pc = 0x40851f; break; }
    r32[eax]--;
    if (!r32[eax])
        { pc = 0x408749; break; }
    { pc = 0x40886e; break; }
  case 0x408566: // 0000:408566
    yield* sub_408a43();
    r32[ecx] = pop32();
    memoryASet(ss, r32[ebp] - 584, r8[al]);
    memoryASet32(ss, r32[ebp] - 12, 0x00000001);
  case 0x408579: // 0000:408579
    r32[eax] = r32[ebp] - 584;
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
    { pc = 0x40886e; break; }
  case 0x408587: // 0000:408587
    r32[eax] = r32[ebp] + 16;
    push32(r32[eax]);
    yield* sub_408a43();
    r32[ecx] = pop32();
    if (!r32[eax])
        { pc = 0x4085c8; break; }
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x4);
    if (!r32[ecx])
        { pc = 0x4085c8; break; }
    if (!(memoryAGet(ss, r32[ebp] - 3) & 0x08))
        { pc = 0x4085b9; break; }
    r32[eax] = signed16(memoryAGet16(ds, r32[eax]));
    r32[eax] >>= 1;
    memoryASet32(ss, r32[ebp] - 8, r32[ecx]);
    memoryASet32(ss, r32[ebp] - 12, r32[eax]);
    memoryASet32(ss, r32[ebp] - 36, 0x00000001);
    { pc = 0x40886e; break; }
  case 0x4085b9: // 0000:4085b9
    memoryASet32(ss, r32[ebp] - 36, memoryAGet32(ss, r32[ebp] - 36) & 0x00000000);
    memoryASet32(ss, r32[ebp] - 8, r32[ecx]);
    r32[eax] = signed16(memoryAGet16(ds, r32[eax]));
    { pc = 0x40886b; break; }
  case 0x4085c8: // 0000:4085c8
    r32[eax] = memoryAGet32(ds, 0x40eef0);
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
    push32(r32[eax]);
    { pc = 0x408664; break; }
  case 0x4085d6: // 0000:4085d6
    if (r32[ecx] != r32[edx])
        { pc = 0x4085e4; break; }
    if (r8[bl] != 0x67)
        { pc = 0x4085e4; break; }
    memoryASet32(ss, r32[ebp] - 16, 0x00000001);
  case 0x4085e4: // 0000:4085e4
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x10);
    push32(memoryAGet32(ss, r32[ebp] - 52));
    r32[eax] += 0x00000008;
    memoryASet32(ss, r32[ebp] + 0x10, r32[eax]);
    push32(memoryAGet32(ss, r32[ebp] - 16));
    r32[ecx] = memoryAGet32(ds, r32[eax] - 8);
    memoryASet32(ss, r32[ebp] - 72, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[eax] - 4);
    memoryASet32(ss, r32[ebp] - 68, r32[eax]);
    r32[eax] = r8s[bl];
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 584;
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 72;
    push32(r32[eax]);
    yield* indirectCall(cs, memoryAGet32(ds, 0x40eed8));
    r32[esi] = memoryAGet32(ss, r32[ebp] - 4);
    r32[esp] += 0x00000014;
    r32[esi] &= 0x00000080;
    if (!r32[esi])
        { pc = 0x408636; break; }
    if (memoryAGet32(ss, r32[ebp] - 16))
        { pc = 0x408636; break; }
    r32[eax] = r32[ebp] - 584;
    push32(r32[eax]);
    yield* indirectCall(cs, memoryAGet32(ds, 0x40eee4));
    r32[ecx] = pop32();
  case 0x408636: // 0000:408636
    if (r8[bl] != 0x67)
        { pc = 0x40864d; break; }
    if (r32[esi])
        { pc = 0x40864d; break; }
    r32[eax] = r32[ebp] - 584;
    push32(r32[eax]);
    yield* indirectCall(cs, memoryAGet32(ds, 0x40eedc));
    r32[ecx] = pop32();
  case 0x40864d: // 0000:40864d
    if (memoryAGet(ss, r32[ebp] - 584) != 0x2d)
        { pc = 0x408663; break; }
    memoryASet(ss, r32[ebp] - 3, memoryAGet(ss, r32[ebp] - 3) | 0x01);
    r32[edi] = r32[ebp] - 583;
    memoryASet32(ss, r32[ebp] - 8, r32[edi]);
  case 0x408663: // 0000:408663
    push32(r32[edi]);
  case 0x408664: // 0000:408664
    yield* sub_40a590();
    r32[ecx] = pop32();
    { pc = 0x40886b; break; }
  case 0x40866f: // 0000:40866f
    r32[eax] -= 0x00000069;
    if (!r32[eax])
        { pc = 0x408749; break; }
    r32[eax] -= 0x00000005;
    if (!r32[eax])
        { pc = 0x40871f; break; }
    r32[eax]--;
    if (!r32[eax])
        { pc = 0x40870c; break; }
    r32[eax]--;
    if (!r32[eax])
        { pc = 0x4086dc; break; }
    r32[eax] -= 0x00000003;
    if (!r32[eax])
        { pc = 0x408491; break; }
    r32[eax]--;
    r32[eax]--;
    if (!r32[eax])
        { pc = 0x40874d; break; }
    r32[eax] -= 0x00000003;
    if (r32[eax])
        { pc = 0x40886e; break; }
    memoryASet32(ss, r32[ebp] - 44, 0x00000027);
    { pc = 0x4086ea; break; }
  case 0x4086ae: // 0000:4086ae
    r32[eax] -= r32[ecx];
    r32[eax] = sar32(r32[eax], 0x00000001);
    { pc = 0x40886b; break; }
  case 0x4086b7: // 0000:4086b7
    if (r32[ecx])
        { pc = 0x4086c4; break; }
    r32[ecx] = memoryAGet32(ds, 0x40eef0);
    memoryASet32(ss, r32[ebp] - 8, r32[ecx]);
  case 0x4086c4: // 0000:4086c4
    r32[eax] = r32[ecx];
  case 0x4086c6: // 0000:4086c6
    r32[edx] = r32[esi];
    r32[esi]--;
    if (!r32[edx])
        { pc = 0x4086d5; break; }
    if (!memoryAGet(ds, r32[eax]))
        { pc = 0x4086d5; break; }
    r32[eax]++;
    { pc = 0x4086c6; break; }
  case 0x4086d5: // 0000:4086d5
    r32[eax] -= r32[ecx];
    { pc = 0x40886b; break; }
  case 0x4086dc: // 0000:4086dc
    memoryASet32(ss, r32[ebp] - 16, 0x00000008);
  case 0x4086e3: // 0000:4086e3
    memoryASet32(ss, r32[ebp] - 44, 0x00000007);
  case 0x4086ea: // 0000:4086ea
    memoryASet32(ss, r32[ebp] - 12, 0x00000010);
    if (!(memoryAGet(ss, r32[ebp] - 4) & 0x80))
        { pc = 0x408754; break; }
    r8[al] = memoryAGet(ss, r32[ebp] - 44);
    memoryASet(ss, r32[ebp] - 22, 0x30);
    r8[al] += 0x51;
    memoryASet32(ss, r32[ebp] - 28, 0x00000002);
    memoryASet(ss, r32[ebp] - 21, r8[al]);
    { pc = 0x408754; break; }
  case 0x40870c: // 0000:40870c
    memoryASet32(ss, r32[ebp] - 12, 0x00000008);
    if (!(memoryAGet(ss, r32[ebp] - 4) & 0x80))
        { pc = 0x408754; break; }
    memoryASet(ss, r32[ebp] - 3, memoryAGet(ss, r32[ebp] - 3) | 0x02);
    { pc = 0x408754; break; }
  case 0x40871f: // 0000:40871f
    r32[eax] = r32[ebp] + 16;
    push32(r32[eax]);
    yield* sub_408a43();
    r32[ecx] = pop32();
    if (!(memoryAGet(ss, r32[ebp] - 4) & 0x20))
        { pc = 0x408738; break; }
    r16[cx] = memoryAGet16(ss, r32[ebp] - 20);
    memoryASet16(ds, r32[eax], r16[cx]);
    { pc = 0x40873d; break; }
  case 0x408738: // 0000:408738
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 20);
    memoryASet32(ds, r32[eax], r32[ecx]);
  case 0x40873d: // 0000:40873d
    memoryASet32(ss, r32[ebp] - 40, 0x00000001);
    { pc = 0x40896c; break; }
  case 0x408749: // 0000:408749
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0x00000040);
  case 0x40874d: // 0000:40874d
    memoryASet32(ss, r32[ebp] - 12, 0x0000000a);
  case 0x408754: // 0000:408754
    if (!(memoryAGet(ss, r32[ebp] - 3) & 0x80))
        { pc = 0x408766; break; }
    r32[eax] = r32[ebp] + 16;
    push32(r32[eax]);
    yield* sub_408a50();
    r32[ecx] = pop32();
    { pc = 0x4087a7; break; }
  case 0x408766: // 0000:408766
    if (!(memoryAGet(ss, r32[ebp] - 4) & 0x20))
        { pc = 0x40878d; break; }
    r32[eax] = r32[ebp] + 16;
    push32(r32[eax]);
    if (!(memoryAGet(ss, r32[ebp] - 4) & 0x40))
        { pc = 0x408782; break; }
    yield* sub_408a43();
    r32[ecx] = pop32();
    r32[eax] = r16s[ax];
  case 0x40877f: // 0000:40877f
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    { pc = 0x4087a7; break; }
  case 0x408782: // 0000:408782
    yield* sub_408a43();
    r32[ecx] = pop32();
    r32[eax] = r16[ax];
    { pc = 0x40877f; break; }
  case 0x40878d: // 0000:40878d
    r32[eax] = r32[ebp] + 16;
    push32(r32[eax]);
    if (!(memoryAGet(ss, r32[ebp] - 4) & 0x40))
        { pc = 0x40879f; break; }
    yield* sub_408a43();
    r32[ecx] = pop32();
    { pc = 0x40877f; break; }
  case 0x40879f: // 0000:40879f
    yield* sub_408a43();
    r32[ecx] = pop32();
    r32[edx] = 0;
  case 0x4087a7: // 0000:4087a7
    if (!(memoryAGet(ss, r32[ebp] - 4) & 0x40))
        { pc = 0x4087c8; break; }
    if (r32s[edx] > 0)
        { pc = 0x4087c8; break; }
    if (r32s[edx] < 0)
        { pc = 0x4087b7; break; }
    if (true)
        { pc = 0x4087c8; break; }
  case 0x4087b7: // 0000:4087b7
    flags.carry = r32[eax] != 0;
    r32[eax] = -r32[eax];
    r32[edx] += (0x00000000 + flags.carry);
    r32[esi] = r32[eax];
    r32[edx] = -r32[edx];
    memoryASet(ss, r32[ebp] - 3, memoryAGet(ss, r32[ebp] - 3) | 0x01);
    r32[edi] = r32[edx];
    { pc = 0x4087cc; break; }
  case 0x4087c8: // 0000:4087c8
    r32[esi] = r32[eax];
    r32[edi] = r32[edx];
  case 0x4087cc: // 0000:4087cc
    if (memoryAGet(ss, r32[ebp] - 3) & 0x80)
        { pc = 0x4087d5; break; }
    r32[edi] &= 0x00000000;
  case 0x4087d5: // 0000:4087d5
    if (signed32(memoryAGet32(ss, r32[ebp] - 16)) >= signed32(0x00000000))
        { pc = 0x4087e4; break; }
    memoryASet32(ss, r32[ebp] - 16, 0x00000001);
    { pc = 0x4087e8; break; }
  case 0x4087e4: // 0000:4087e4
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) & 0xfffffff7);
  case 0x4087e8: // 0000:4087e8
    r32[eax] = r32[esi];
    r32[eax] |= r32[edi];
    if (r32[eax])
        { pc = 0x4087f2; break; }
    memoryASet32(ss, r32[ebp] - 28, memoryAGet32(ss, r32[ebp] - 28) & 0x00000000);
  case 0x4087f2: // 0000:4087f2
    r32[eax] = r32[ebp] - 73;
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
  case 0x4087f8: // 0000:4087f8
    r32[eax] = memoryAGet32(ss, r32[ebp] - 16);
    memoryASet32(ss, r32[ebp] - 16, memoryAGet32(ss, r32[ebp] - 16) - 1);
    if (r32s[eax] > 0)
        { pc = 0x408808; break; }
    r32[eax] = r32[esi];
    r32[eax] |= r32[edi];
    if (!r32[eax])
        { pc = 0x408843; break; }
  case 0x408808: // 0000:408808
    r32[eax] = memoryAGet32(ss, r32[ebp] - 12);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    push32(r32[edx]);
    push32(r32[eax]);
    push32(r32[edi]);
    push32(r32[esi]);
    memoryASet32(ss, r32[ebp] - 64, r32[eax]);
    memoryASet32(ss, r32[ebp] - 60, r32[edx]);
    yield* sub_40aa60();
    push32(memoryAGet32(ss, r32[ebp] - 60));
    r32[ebx] = r32[eax];
    r32[ebx] += 0x00000030;
    push32(memoryAGet32(ss, r32[ebp] - 64));
    push32(r32[edi]);
    push32(r32[esi]);
    yield* sub_40a9f0();
    r32[esi] = r32[eax];
    r32[edi] = r32[edx];
    if (r32s[ebx] <= signed32(0x00000039))
        { pc = 0x408839; break; }
    r32[ebx] += memoryAGet32(ss, r32[ebp] - 44);
  case 0x408839: // 0000:408839
    r32[eax] = memoryAGet32(ss, r32[ebp] - 8);
    memoryASet32(ss, r32[ebp] - 8, memoryAGet32(ss, r32[ebp] - 8) - 1);
    memoryASet(ds, r32[eax], r8[bl]);
    { pc = 0x4087f8; break; }
  case 0x408843: // 0000:408843
    r32[eax] = r32[ebp] - 73;
    r32[eax] -= memoryAGet32(ss, r32[ebp] - 8);
    memoryASet32(ss, r32[ebp] - 8, memoryAGet32(ss, r32[ebp] - 8) + 1);
    memoryASet32(ss, r32[ebp] - 12, r32[eax]);
    if (!(memoryAGet(ss, r32[ebp] - 3) & 0x02))
        { pc = 0x40886e; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
    if (memoryAGet(ds, r32[ecx]) != 0x30)
        { pc = 0x408861; break; }
    if (r32[eax])
        { pc = 0x40886e; break; }
  case 0x408861: // 0000:408861
    memoryASet32(ss, r32[ebp] - 8, memoryAGet32(ss, r32[ebp] - 8) - 1);
    r32[eax]++;
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 8);
    memoryASet(ds, r32[ecx], 0x30);
  case 0x40886b: // 0000:40886b
    memoryASet32(ss, r32[ebp] - 12, r32[eax]);
  case 0x40886e: // 0000:40886e
    if (memoryAGet32(ss, r32[ebp] - 40))
        { pc = 0x40896c; break; }
    r32[ebx] = memoryAGet32(ss, r32[ebp] - 4);
    if (!(r8[bl] & 0x40))
        { pc = 0x4088a6; break; }
    if (!(r8[bh] & 0x01))
        { pc = 0x40888b; break; }
    memoryASet(ss, r32[ebp] - 22, 0x2d);
    { pc = 0x40889f; break; }
  case 0x40888b: // 0000:40888b
    if (!(r8[bl] & 0x01))
        { pc = 0x408896; break; }
    memoryASet(ss, r32[ebp] - 22, 0x2b);
    { pc = 0x40889f; break; }
  case 0x408896: // 0000:408896
    if (!(r8[bl] & 0x02))
        { pc = 0x4088a6; break; }
    memoryASet(ss, r32[ebp] - 22, 0x20);
  case 0x40889f: // 0000:40889f
    memoryASet32(ss, r32[ebp] - 28, 0x00000001);
  case 0x4088a6: // 0000:4088a6
    r32[esi] = memoryAGet32(ss, r32[ebp] - 32);
    r32[esi] -= memoryAGet32(ss, r32[ebp] - 28);
    r32[esi] -= memoryAGet32(ss, r32[ebp] - 12);
    if (r8[bl] & 0x0c)
        { pc = 0x4088c6; break; }
    r32[eax] = r32[ebp] - 20;
    push32(r32[eax]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    push32(r32[esi]);
    push32(0x00000020);
    yield* sub_4089da();
    r32[esp] += 0x00000010;
  case 0x4088c6: // 0000:4088c6
    r32[eax] = r32[ebp] - 20;
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 22;
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    push32(memoryAGet32(ss, r32[ebp] - 28));
    push32(r32[eax]);
    yield* sub_408a0b();
    r32[esp] += 0x00000010;
    if (!(r8[bl] & 0x08))
        { pc = 0x4088f8; break; }
    if (r8[bl] & 0x04)
        { pc = 0x4088f8; break; }
    r32[eax] = r32[ebp] - 20;
    push32(r32[eax]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    push32(r32[esi]);
    push32(0x00000030);
    yield* sub_4089da();
    r32[esp] += 0x00000010;
  case 0x4088f8: // 0000:4088f8
    if (!memoryAGet32(ss, r32[ebp] - 36))
        { pc = 0x40893f; break; }
    if (signed32(memoryAGet32(ss, r32[ebp] - 12)) <= signed32(0x00000000))
        { pc = 0x40893f; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] - 12);
    r32[ebx] = memoryAGet32(ss, r32[ebp] - 8);
    r32[edi] = r32[eax] - 1;
  case 0x40890d: // 0000:40890d
    r16[ax] = memoryAGet16(ds, r32[ebx]);
    r32[ebx]++;
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 56;
    push32(r32[eax]);
    r32[ebx]++;
    yield* sub_40a97e();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
    if (r32s[eax] <= 0)
        { pc = 0x408954; break; }
    r32[ecx] = r32[ebp] - 20;
    push32(r32[ecx]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 56;
    push32(r32[eax]);
    yield* sub_408a0b();
    r32[esp] += 0x00000010;
    r32[eax] = r32[edi];
    r32[edi]--;
    if (r32[eax])
        { pc = 0x40890d; break; }
    { pc = 0x408954; break; }
  case 0x40893f: // 0000:40893f
    r32[eax] = r32[ebp] - 20;
    push32(r32[eax]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    push32(memoryAGet32(ss, r32[ebp] - 12));
    push32(memoryAGet32(ss, r32[ebp] - 8));
    yield* sub_408a0b();
    r32[esp] += 0x00000010;
  case 0x408954: // 0000:408954
    if (!(memoryAGet(ss, r32[ebp] - 4) & 0x04))
        { pc = 0x40896c; break; }
    r32[eax] = r32[ebp] - 20;
    push32(r32[eax]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    push32(r32[esi]);
    push32(0x00000020);
    yield* sub_4089da();
    r32[esp] += 0x00000010;
  case 0x40896c: // 0000:40896c
    r32[edi] = memoryAGet32(ss, r32[ebp] + 0xc);
    r8[bl] = memoryAGet(ds, r32[edi]);
    r32[edi]++;
    memoryASet32(ss, r32[ebp] + 0xc, r32[edi]);
    if (r8[bl])
        { pc = 0x408290; break; }
  case 0x40897d: // 0000:40897d
    r32[eax] = memoryAGet32(ss, r32[ebp] - 20);
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_4089a5() // 0000:4089a5 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0xc);
    memoryASet32(ds, r32[ecx] + 0x4, memoryAGet32(ds, r32[ecx] + 0x4) - 1);
    if (signed32(memoryAGet32(ds, r32[ecx] + 0x4)) < 0)
        { pc = 0x4089be; break; }
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r8[al] = memoryAGet(ss, r32[ebp] + 0x8);
    memoryASet(ds, r32[edx], r8[al]);
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
    r32[eax] = r8[al];
    { pc = 0x4089c9; break; }
  case 0x4089be: // 0000:4089be
    push32(r32[ecx]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    yield* sub_40814f();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
  case 0x4089c9: // 0000:4089c9
    flags.zero = r32[eax] == 0xffffffff;
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x10);
    if (!flags.zero)
        { pc = 0x4089d6; break; }
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) | 0xffffffff);
    r32[ebp] = pop32();
    r32[esp] += 4; return;
  case 0x4089d6: // 0000:4089d6
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) + 1);
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_4089da() // 0000:4089da +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[eax] = r32[edi];
    r32[edi]--;
    if (r32s[eax] <= 0)
        { pc = 0x408a08; break; }
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x18);
  case 0x4089eb: // 0000:4089eb
    push32(r32[esi]);
    push32(memoryAGet32(ds, r32[esp] + 0x18));
    push32(memoryAGet32(ds, r32[esp] + 0x14));
    yield* sub_4089a5();
    r32[esp] += 0x0000000c;
    if (memoryAGet32(ds, r32[esi]) == 0xffffffff)
        { pc = 0x408a08; break; }
    r32[eax] = r32[edi];
    r32[edi]--;
    if (r32s[eax] > 0)
        { pc = 0x4089eb; break; }
  case 0x408a08: // 0000:408a08
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_408a0b() // 0000:408a0b +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[eax] = r32[ebx];
    r32[ebx]--;
    push32(r32[esi]);
    push32(r32[edi]);
    if (r32s[eax] <= 0)
        { pc = 0x408a3f; break; }
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x10);
  case 0x408a21: // 0000:408a21
    r32[eax] = signed8(memoryAGet(ds, r32[esi]));
    push32(r32[edi]);
    r32[esi]++;
    push32(memoryAGet32(ds, r32[esp] + 0x1c));
    push32(r32[eax]);
    yield* sub_4089a5();
    r32[esp] += 0x0000000c;
    if (memoryAGet32(ds, r32[edi]) == 0xffffffff)
        { pc = 0x408a3f; break; }
    r32[eax] = r32[ebx];
    r32[ebx]--;
    if (r32s[eax] > 0)
        { pc = 0x408a21; break; }
  case 0x408a3f: // 0000:408a3f
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_408a43() // 0000:408a43 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) + 0x00000004);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax] - 4);
    r32[esp] += 4;
}
function* sub_408a50() // 0000:408a50 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) + 0x00000008);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ecx] - 8);
    r32[edx] = memoryAGet32(ds, r32[ecx] - 4);
    r32[esp] += 4;
}
function* sub_408a60() // 0000:408a60 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) + 0x00000004);
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r16[ax] = memoryAGet16(ds, r32[eax] - 4);
    r32[esp] += 4;
}
function* sub_408a6e() // 0000:408a6e +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(r32[ebx]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    yield* sub_408baf();
    r32[ecx] = pop32();
    if (!r32[eax])
        { pc = 0x408ba3; break; }
    r32[ebx] = memoryAGet32(ds, r32[eax] + 0x8);
    if (!r32[ebx])
        { pc = 0x408ba3; break; }
    if (r32[ebx] != 0x00000005)
        { pc = 0x408a9f; break; }
    memoryASet32(ds, r32[eax] + 0x8, memoryAGet32(ds, r32[eax] + 0x8) & 0x00000000);
    push32(0x00000001);
    r32[eax] = pop32();
    { pc = 0x408bac; break; }
  case 0x408a9f: // 0000:408a9f
    if (r32[ebx] == 0x00000001)
        { pc = 0x408b9e; break; }
    r32[ecx] = memoryAGet32(ds, 0x40fb30);
    memoryASet32(ss, r32[ebp] + 0x8, r32[ecx]);
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0xc);
    memoryASet32(ds, 0x40fb30, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x4);
    if (r32[ecx] != 0x00000008)
        { pc = 0x408b8e; break; }
    r32[ecx] = memoryAGet32(ds, 0x40ef70);
    r32[edx] = memoryAGet32(ds, 0x40ef74);
    r32[edx] += r32[ecx];
    push32(r32[esi]);
    if (r32s[ecx] >= r32s[edx])
        { pc = 0x408aee; break; }
    r32[esi] = r32[ecx] + (r32[ecx] * 2);
    r32[edx] -= r32[ecx];
    r32[esi] = (r32[esi] * 4) + 4255488;
  case 0x408ae5: // 0000:408ae5
    memoryASet32(ds, r32[esi], memoryAGet32(ds, r32[esi]) & 0x00000000);
    r32[esi] += 0x0000000c;
    r32[edx]--;
    if (r32[edx])
        { pc = 0x408ae5; break; }
  case 0x408aee: // 0000:408aee
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[esi] = memoryAGet32(ds, 0x40ef7c);
    if (r32[eax] != 0xc000008e)
        { pc = 0x408b09; break; }
    memoryASet32(ds, 0x40ef7c, 0x00000083);
    { pc = 0x408b79; break; }
  case 0x408b09: // 0000:408b09
    if (r32[eax] != 0xc0000090)
        { pc = 0x408b1c; break; }
    memoryASet32(ds, 0x40ef7c, 0x00000081);
    { pc = 0x408b79; break; }
  case 0x408b1c: // 0000:408b1c
    if (r32[eax] != 0xc0000091)
        { pc = 0x408b2f; break; }
    memoryASet32(ds, 0x40ef7c, 0x00000084);
    { pc = 0x408b79; break; }
  case 0x408b2f: // 0000:408b2f
    if (r32[eax] != 0xc0000093)
        { pc = 0x408b42; break; }
    memoryASet32(ds, 0x40ef7c, 0x00000085);
    { pc = 0x408b79; break; }
  case 0x408b42: // 0000:408b42
    if (r32[eax] != 0xc000008d)
        { pc = 0x408b55; break; }
    memoryASet32(ds, 0x40ef7c, 0x00000082);
    { pc = 0x408b79; break; }
  case 0x408b55: // 0000:408b55
    if (r32[eax] != 0xc000008f)
        { pc = 0x408b68; break; }
    memoryASet32(ds, 0x40ef7c, 0x00000086);
    { pc = 0x408b79; break; }
  case 0x408b68: // 0000:408b68
    if (r32[eax] != 0xc0000092)
        { pc = 0x408b79; break; }
    memoryASet32(ds, 0x40ef7c, 0x0000008a);
  case 0x408b79: // 0000:408b79
    push32(memoryAGet32(ds, 0x40ef7c));
    push32(0x00000008);
    yield* indirectCall(cs, r32[ebx]);
    r32[ecx] = pop32();
    memoryASet32(ds, 0x40ef7c, r32[esi]);
    r32[ecx] = pop32();
    r32[esi] = pop32();
    { pc = 0x408b96; break; }
  case 0x408b8e: // 0000:408b8e
    memoryASet32(ds, r32[eax] + 0x8, memoryAGet32(ds, r32[eax] + 0x8) & 0x00000000);
    push32(r32[ecx]);
    yield* indirectCall(cs, r32[ebx]);
    r32[ecx] = pop32();
  case 0x408b96: // 0000:408b96
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, 0x40fb30, r32[eax]);
  case 0x408b9e: // 0000:408b9e
    r32[eax] |= 0xffffffff;
    { pc = 0x408bac; break; }
  case 0x408ba3: // 0000:408ba3
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    r32[eax] = kernel32.UnhandledExceptionFilter(stack32(0)); r32[esp] += 4;
  case 0x408bac: // 0000:408bac
    r32[ebx] = pop32();
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_408baf() // 0000:408baf +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[ecx] = memoryAGet32(ds, 0x40ef78);
    push32(r32[esi]);
    r32[eax] = 0x0040eef8;
    if (memoryAGet32(ds, 0x40eef8) == r32[edx])
        { pc = 0x408bdc; break; }
    r32[esi] = r32[ecx] + (r32[ecx] * 2);
    r32[esi] = (r32[esi] * 4) + 4255480;
  case 0x408bd1: // 0000:408bd1
    r32[eax] += 0x0000000c;
    if (r32[eax] >= r32[esi])
        { pc = 0x408bdc; break; }
    if (memoryAGet32(ds, r32[eax]) != r32[edx])
        { pc = 0x408bd1; break; }
  case 0x408bdc: // 0000:408bdc
    r32[ecx] = r32[ecx] + (r32[ecx] * 2);
    r32[esi] = pop32();
    r32[ecx] = (r32[ecx] * 4) + 4255480;
    if (r32[eax] >= r32[ecx])
        { pc = 0x408bef; break; }
    if (memoryAGet32(ds, r32[eax]) == r32[edx])
        { pc = 0x408bf1; break; }
  case 0x408bef: // 0000:408bef
    r32[eax] = 0;
  case 0x408bf1: // 0000:408bf1
    r32[esp] += 4; return;
    return;
  }
}
function* sub_408bf2() // 0000:408bf2 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    if (memoryAGet32(ds, 0x42d188))
        { pc = 0x408c00; break; }
    yield* sub_40aedb();
  case 0x408c00: // 0000:408c00
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, 0x42d180);
    r8[al] = memoryAGet(ds, r32[esi]);
    if (r8[al] != 0x22)
        { pc = 0x408c32; break; }
  case 0x408c0d: // 0000:408c0d
    r8[al] = memoryAGet(ds, r32[esi] + 0x1);
    r32[esi]++;
    if (r8[al] == 0x22)
        { pc = 0x408c2a; break; }
    if (!r8[al])
        { pc = 0x408c2a; break; }
    r32[eax] = r8[al];
    push32(r32[eax]);
    yield* sub_40aad5();
    r32[ecx] = pop32();
    if (!r32[eax])
        { pc = 0x408c0d; break; }
    r32[esi]++;
    { pc = 0x408c0d; break; }
  case 0x408c2a: // 0000:408c2a
    if (memoryAGet(ds, r32[esi]) != 0x22)
        { pc = 0x408c3c; break; }
  case 0x408c2f: // 0000:408c2f
    r32[esi]++;
    { pc = 0x408c3c; break; }
  case 0x408c32: // 0000:408c32
    if (r8[al] <= 0x20)
        { pc = 0x408c3c; break; }
  case 0x408c36: // 0000:408c36
    r32[esi]++;
    if (memoryAGet(ds, r32[esi]) > 0x20)
        { pc = 0x408c36; break; }
  case 0x408c3c: // 0000:408c3c
    r8[al] = memoryAGet(ds, r32[esi]);
    if (!r8[al])
        { pc = 0x408c46; break; }
    if (r8[al] <= 0x20)
        { pc = 0x408c2f; break; }
  case 0x408c46: // 0000:408c46
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_408c4a() // 0000:408c4a +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    r32[ebx] = 0;
    push32(r32[esi]);
    push32(r32[edi]);
    if (memoryAGet32(ds, 0x42d188) != r32[ebx])
        { pc = 0x408c5c; break; }
    yield* sub_40aedb();
  case 0x408c5c: // 0000:408c5c
    r32[esi] = memoryAGet32(ds, 0x40fb0c);
    r32[edi] = 0;
  case 0x408c64: // 0000:408c64
    r8[al] = memoryAGet(ds, r32[esi]);
    if (r8[al] == r8[bl])
        { pc = 0x408c7c; break; }
    if (r8[al] == 0x3d)
        { pc = 0x408c6f; break; }
    r32[edi]++;
  case 0x408c6f: // 0000:408c6f
    push32(r32[esi]);
    yield* sub_40a590();
    r32[ecx] = pop32();
    r32[esi] = (r32[esi] + r32[eax]) + 1;
    { pc = 0x408c64; break; }
  case 0x408c7c: // 0000:408c7c
    r32[eax] = (r32[edi] * 4) + 4;
    push32(r32[eax]);
    yield* sub_406b40();
    r32[esi] = r32[eax];
    r32[ecx] = pop32();
    memoryASet32(ds, 0x40fae0, r32[esi]);
    if (r32[esi] != r32[ebx])
        { pc = 0x408c9e; break; }
    push32(0x00000009);
    yield* sub_406f73();
    r32[ecx] = pop32();
  case 0x408c9e: // 0000:408c9e
    r32[edi] = memoryAGet32(ds, 0x40fb0c);
    if (memoryAGet(ds, r32[edi]) == r8[bl])
        { pc = 0x408ce1; break; }
    push32(r32[ebp]);
  case 0x408ca9: // 0000:408ca9
    push32(r32[edi]);
    yield* sub_40a590();
    r32[ebp] = r32[eax];
    r32[ecx] = pop32();
    r32[ebp]++;
    if (memoryAGet(ds, r32[edi]) == 0x3d)
        { pc = 0x408cda; break; }
    push32(r32[ebp]);
    yield* sub_406b40();
    r32[ecx] = pop32();
    memoryASet32(ds, r32[esi], r32[eax]);
    if (r32[eax] != r32[ebx])
        { pc = 0x408ccd; break; }
    push32(0x00000009);
    yield* sub_406f73();
    r32[ecx] = pop32();
  case 0x408ccd: // 0000:408ccd
    push32(r32[edi]);
    push32(memoryAGet32(ds, r32[esi]));
    yield* sub_40a2a0();
    r32[ecx] = pop32();
    r32[esi] += 0x00000004;
    r32[ecx] = pop32();
  case 0x408cda: // 0000:408cda
    r32[edi] += r32[ebp];
    if (memoryAGet(ds, r32[edi]) != r8[bl])
        { pc = 0x408ca9; break; }
    r32[ebp] = pop32();
  case 0x408ce1: // 0000:408ce1
    push32(memoryAGet32(ds, 0x40fb0c));
    yield* sub_406bb4();
    r32[ecx] = pop32();
    memoryASet32(ds, 0x40fb0c, r32[ebx]);
    memoryASet32(ds, r32[esi], r32[ebx]);
    r32[edi] = pop32();
    r32[esi] = pop32();
    memoryASet32(ds, 0x42d184, 0x00000001);
    r32[ebx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_408d03() // 0000:408d03 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(r32[ecx]);
    push32(r32[ecx]);
    push32(r32[ebx]);
    r32[ebx] = 0;
    push32(r32[esi]);
    push32(r32[edi]);
    if (memoryAGet32(ds, 0x42d188) != r32[ebx])
        { pc = 0x408d1a; break; }
    yield* sub_40aedb();
  case 0x408d1a: // 0000:408d1a
    r32[esi] = 0x0040fb34;
    push32(0x00000104);
    push32(r32[esi]);
    push32(r32[ebx]);
    r32[eax] = kernel32.GetModuleFileNameA(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
    r32[eax] = memoryAGet32(ds, 0x42d180);
    memoryASet32(ds, 0x40faf0, r32[esi]);
    r32[edi] = r32[esi];
    if (memoryAGet(ds, r32[eax]) == r8[bl])
        { pc = 0x408d3f; break; }
    r32[edi] = r32[eax];
  case 0x408d3f: // 0000:408d3f
    r32[eax] = r32[ebp] - 8;
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 4;
    push32(r32[eax]);
    push32(r32[ebx]);
    push32(r32[ebx]);
    push32(r32[edi]);
    yield* sub_408d9c();
    r32[eax] = memoryAGet32(ss, r32[ebp] - 8);
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax] = r32[eax] + (r32[ecx] * 4);
    push32(r32[eax]);
    yield* sub_406b40();
    r32[esi] = r32[eax];
    r32[esp] += 0x00000018;
    if (r32[esi] != r32[ebx])
        { pc = 0x408d6f; break; }
    push32(0x00000008);
    yield* sub_406f73();
    r32[ecx] = pop32();
  case 0x408d6f: // 0000:408d6f
    r32[eax] = r32[ebp] - 8;
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 4;
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax] = r32[esi] + (r32[eax] * 4);
    push32(r32[eax]);
    push32(r32[esi]);
    push32(r32[edi]);
    yield* sub_408d9c();
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[esp] += 0x00000014;
    r32[eax]--;
    memoryASet32(ds, 0x40fad8, r32[esi]);
    r32[edi] = pop32();
    r32[esi] = pop32();
    memoryASet32(ds, 0x40fad4, r32[eax]);
    r32[ebx] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_408d9c() // 0000:408d9c +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x18);
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x14);
    push32(r32[ebx]);
    push32(r32[esi]);
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) & 0x00000000);
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x10);
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ss, r32[ebp] + 0xc);
    memoryASet32(ds, r32[eax], 0x00000001);
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    if (!r32[edi])
        { pc = 0x408dc6; break; }
    memoryASet32(ds, r32[edi], r32[esi]);
    r32[edi] += 0x00000004;
    memoryASet32(ss, r32[ebp] + 0xc, r32[edi]);
  case 0x408dc6: // 0000:408dc6
    if (memoryAGet(ds, r32[eax]) != 0x22)
        { pc = 0x408e0f; break; }
  case 0x408dcb: // 0000:408dcb
    r8[dl] = memoryAGet(ds, r32[eax] + 0x1);
    r32[eax]++;
    if (r8[dl] == 0x22)
        { pc = 0x408dfd; break; }
    if (!r8[dl])
        { pc = 0x408dfd; break; }
    r32[edx] = r8[dl];
    if (!(memoryAGet(ds, r32[edx] + 0x42bf21) & 0x04))
        { pc = 0x408df0; break; }
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
    if (!r32[esi])
        { pc = 0x408df0; break; }
    r8[dl] = memoryAGet(ds, r32[eax]);
    memoryASet(ds, r32[esi], r8[dl]);
    r32[esi]++;
    r32[eax]++;
  case 0x408df0: // 0000:408df0
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
    if (!r32[esi])
        { pc = 0x408dcb; break; }
    r8[dl] = memoryAGet(ds, r32[eax]);
    memoryASet(ds, r32[esi], r8[dl]);
    r32[esi]++;
    { pc = 0x408dcb; break; }
  case 0x408dfd: // 0000:408dfd
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
    if (!r32[esi])
        { pc = 0x408e07; break; }
    memoryASet(ds, r32[esi], memoryAGet(ds, r32[esi]) & 0x00);
    r32[esi]++;
  case 0x408e07: // 0000:408e07
    if (memoryAGet(ds, r32[eax]) != 0x22)
        { pc = 0x408e52; break; }
    r32[eax]++;
    { pc = 0x408e52; break; }
  case 0x408e0f: // 0000:408e0f
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
    if (!r32[esi])
        { pc = 0x408e1a; break; }
    r8[dl] = memoryAGet(ds, r32[eax]);
    memoryASet(ds, r32[esi], r8[dl]);
    r32[esi]++;
  case 0x408e1a: // 0000:408e1a
    r8[dl] = memoryAGet(ds, r32[eax]);
    r32[eax]++;
    r32[ebx] = r8[dl];
    if (!(memoryAGet(ds, r32[ebx] + 0x42bf21) & 0x04))
        { pc = 0x408e35; break; }
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
    if (!r32[esi])
        { pc = 0x408e34; break; }
    r8[bl] = memoryAGet(ds, r32[eax]);
    memoryASet(ds, r32[esi], r8[bl]);
    r32[esi]++;
  case 0x408e34: // 0000:408e34
    r32[eax]++;
  case 0x408e35: // 0000:408e35
    if (r8[dl] == 0x20)
        { pc = 0x408e43; break; }
    if (!r8[dl])
        { pc = 0x408e47; break; }
    if (r8[dl] != 0x09)
        { pc = 0x408e0f; break; }
  case 0x408e43: // 0000:408e43
    if (r8[dl])
        { pc = 0x408e4a; break; }
  case 0x408e47: // 0000:408e47
    r32[eax]--;
    { pc = 0x408e52; break; }
  case 0x408e4a: // 0000:408e4a
    if (!r32[esi])
        { pc = 0x408e52; break; }
    memoryASet(ds, r32[esi] - 1, memoryAGet(ds, r32[esi] - 1) & 0x00);
  case 0x408e52: // 0000:408e52
    memoryASet32(ss, r32[ebp] + 0x18, memoryAGet32(ss, r32[ebp] + 0x18) & 0x00000000);
  case 0x408e56: // 0000:408e56
    if (!memoryAGet(ds, r32[eax]))
        { pc = 0x408f3f; break; }
  case 0x408e5f: // 0000:408e5f
    r8[dl] = memoryAGet(ds, r32[eax]);
    if (r8[dl] == 0x20)
        { pc = 0x408e6b; break; }
    if (r8[dl] != 0x09)
        { pc = 0x408e6e; break; }
  case 0x408e6b: // 0000:408e6b
    r32[eax]++;
    { pc = 0x408e5f; break; }
  case 0x408e6e: // 0000:408e6e
    if (!memoryAGet(ds, r32[eax]))
        { pc = 0x408f3f; break; }
    if (!r32[edi])
        { pc = 0x408e83; break; }
    memoryASet32(ds, r32[edi], r32[esi]);
    r32[edi] += 0x00000004;
    memoryASet32(ss, r32[ebp] + 0xc, r32[edi]);
  case 0x408e83: // 0000:408e83
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0x14);
    memoryASet32(ds, r32[edx], memoryAGet32(ds, r32[edx]) + 1);
  case 0x408e88: // 0000:408e88
    memoryASet32(ss, r32[ebp] + 0x8, 0x00000001);
    r32[ebx] = 0;
  case 0x408e91: // 0000:408e91
    if (memoryAGet(ds, r32[eax]) != 0x5c)
        { pc = 0x408e9a; break; }
    r32[eax]++;
    r32[ebx]++;
    { pc = 0x408e91; break; }
  case 0x408e9a: // 0000:408e9a
    if (memoryAGet(ds, r32[eax]) != 0x22)
        { pc = 0x408ecb; break; }
    if (r8[bl] & 0x01)
        { pc = 0x408ec9; break; }
    r32[edi] = 0;
    if (memoryAGet32(ss, r32[ebp] + 0x18) == r32[edi])
        { pc = 0x408eb8; break; }
    r32[edx] = r32[eax] + 1;
    if (memoryAGet(ds, r32[eax] + 0x1) != 0x22)
        { pc = 0x408eb8; break; }
    r32[eax] = r32[edx];
    { pc = 0x408ebb; break; }
  case 0x408eb8: // 0000:408eb8
    memoryASet32(ss, r32[ebp] + 0x8, r32[edi]);
  case 0x408ebb: // 0000:408ebb
    r32[edi] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[edx] = 0;
    r8[dl] = memoryAGet32(ss, r32[ebp] + 0x18) == r32[edx];
    memoryASet32(ss, r32[ebp] + 0x18, r32[edx]);
  case 0x408ec9: // 0000:408ec9
    r32[ebx] >>= 1;
  case 0x408ecb: // 0000:408ecb
    r32[edx] = r32[ebx];
    r32[ebx]--;
    if (!r32[edx])
        { pc = 0x408ee0; break; }
    r32[ebx]++;
  case 0x408ed3: // 0000:408ed3
    if (!r32[esi])
        { pc = 0x408edb; break; }
    memoryASet(ds, r32[esi], 0x5c);
    r32[esi]++;
  case 0x408edb: // 0000:408edb
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
    r32[ebx]--;
    if (r32[ebx])
        { pc = 0x408ed3; break; }
  case 0x408ee0: // 0000:408ee0
    r8[dl] = memoryAGet(ds, r32[eax]);
    if (!r8[dl])
        { pc = 0x408f30; break; }
    if (memoryAGet32(ss, r32[ebp] + 0x18))
        { pc = 0x408ef6; break; }
    if (r8[dl] == 0x20)
        { pc = 0x408f30; break; }
    if (r8[dl] == 0x09)
        { pc = 0x408f30; break; }
  case 0x408ef6: // 0000:408ef6
    if (!memoryAGet32(ss, r32[ebp] + 0x8))
        { pc = 0x408f2a; break; }
    if (!r32[esi])
        { pc = 0x408f19; break; }
    r32[ebx] = r8[dl];
    if (!(memoryAGet(ds, r32[ebx] + 0x42bf21) & 0x04))
        { pc = 0x408f12; break; }
    memoryASet(ds, r32[esi], r8[dl]);
    r32[esi]++;
    r32[eax]++;
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
  case 0x408f12: // 0000:408f12
    r8[dl] = memoryAGet(ds, r32[eax]);
    memoryASet(ds, r32[esi], r8[dl]);
    r32[esi]++;
    { pc = 0x408f28; break; }
  case 0x408f19: // 0000:408f19
    r32[edx] = r8[dl];
    if (!(memoryAGet(ds, r32[edx] + 0x42bf21) & 0x04))
        { pc = 0x408f28; break; }
    r32[eax]++;
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
  case 0x408f28: // 0000:408f28
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
  case 0x408f2a: // 0000:408f2a
    r32[eax]++;
    { pc = 0x408e88; break; }
  case 0x408f30: // 0000:408f30
    if (!r32[esi])
        { pc = 0x408f38; break; }
    memoryASet(ds, r32[esi], memoryAGet(ds, r32[esi]) & 0x00);
    r32[esi]++;
  case 0x408f38: // 0000:408f38
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) + 1);
    { pc = 0x408e56; break; }
  case 0x408f3f: // 0000:408f3f
    if (!r32[edi])
        { pc = 0x408f46; break; }
    memoryASet32(ds, r32[edi], memoryAGet32(ds, r32[edi]) & 0x00000000);
  case 0x408f46: // 0000:408f46
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x14);
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) + 1);
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_408f50() // 0000:408f50 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ecx]);
    push32(r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x40fc38);
    push32(r32[ebx]);
    push32(r32[ebp]);
    r32[ebp] = memoryAGet32(ds, 0x40d04c);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[ebx] = 0;
    r32[esi] = 0;
    r32[edi] = 0;
    if (r32[eax] != r32[ebx])
        { pc = 0x408f9e; break; }
    yield* indirectCall(cs, r32[ebp]);
    r32[esi] = r32[eax];
    if (r32[esi] == r32[ebx])
        { pc = 0x408f7f; break; }
    memoryASet32(ds, 0x40fc38, 0x00000001);
    { pc = 0x408fa7; break; }
  case 0x408f7f: // 0000:408f7f
    r32[eax] = kernel32.GetEnvironmentStrings();
    r32[edi] = r32[eax];
    if (r32[edi] == r32[ebx])
        { pc = 0x409079; break; }
    memoryASet32(ds, 0x40fc38, 0x00000002);
    { pc = 0x40902d; break; }
  case 0x408f9e: // 0000:408f9e
    if (r32[eax] != 0x00000001)
        { pc = 0x409028; break; }
  case 0x408fa7: // 0000:408fa7
    if (r32[esi] != r32[ebx])
        { pc = 0x408fb7; break; }
    yield* indirectCall(cs, r32[ebp]);
    r32[esi] = r32[eax];
    if (r32[esi] == r32[ebx])
        { pc = 0x409079; break; }
  case 0x408fb7: // 0000:408fb7
    r32[eax] = r32[esi];
    if (memoryAGet16(ds, r32[esi]) == r16[bx])
        { pc = 0x408fcc; break; }
  case 0x408fbe: // 0000:408fbe
    r32[eax]++;
    r32[eax]++;
    if (memoryAGet16(ds, r32[eax]) != r16[bx])
        { pc = 0x408fbe; break; }
    r32[eax]++;
    r32[eax]++;
    if (memoryAGet16(ds, r32[eax]) != r16[bx])
        { pc = 0x408fbe; break; }
  case 0x408fcc: // 0000:408fcc
    r32[eax] -= r32[esi];
    r32[edi] = memoryAGet32(ds, 0x40d054);
    r32[eax] = sar32(r32[eax], 0x00000001);
    push32(r32[ebx]);
    push32(r32[ebx]);
    r32[eax]++;
    push32(r32[ebx]);
    push32(r32[ebx]);
    push32(r32[eax]);
    push32(r32[esi]);
    push32(r32[ebx]);
    push32(r32[ebx]);
    memoryASet32(ds, r32[esp] + 0x34, r32[eax]);
    yield* indirectCall(cs, r32[edi]);
    r32[ebp] = r32[eax];
    if (r32[ebp] == r32[ebx])
        { pc = 0x40901d; break; }
    push32(r32[ebp]);
    yield* sub_406b40();
    r32[ecx] = pop32();
    memoryASet32(ds, r32[esp] + 0x10, r32[eax]);
    if (r32[eax] == r32[ebx])
        { pc = 0x40901d; break; }
    push32(r32[ebx]);
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[eax]);
    push32(memoryAGet32(ds, r32[esp] + 0x24));
    push32(r32[esi]);
    push32(r32[ebx]);
    push32(r32[ebx]);
    yield* indirectCall(cs, r32[edi]);
    if (r32[eax])
        { pc = 0x409019; break; }
    push32(memoryAGet32(ds, r32[esp] + 0x10));
    yield* sub_406bb4();
    r32[ecx] = pop32();
    memoryASet32(ds, r32[esp] + 0x10, r32[ebx]);
  case 0x409019: // 0000:409019
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x10);
  case 0x40901d: // 0000:40901d
    push32(r32[esi]);
    r32[eax] = kernel32.FreeEnvironmentStringsW(stack32(0)); r32[esp] += 4;
    r32[eax] = r32[ebx];
    { pc = 0x40907b; break; }
  case 0x409028: // 0000:409028
    if (r32[eax] != 0x00000002)
        { pc = 0x409079; break; }
  case 0x40902d: // 0000:40902d
    if (r32[edi] != r32[ebx])
        { pc = 0x40903d; break; }
    r32[eax] = kernel32.GetEnvironmentStrings();
    r32[edi] = r32[eax];
    if (r32[edi] == r32[ebx])
        { pc = 0x409079; break; }
  case 0x40903d: // 0000:40903d
    r32[eax] = r32[edi];
    if (memoryAGet(ds, r32[edi]) == r8[bl])
        { pc = 0x40904d; break; }
  case 0x409043: // 0000:409043
    r32[eax]++;
    if (memoryAGet(ds, r32[eax]) != r8[bl])
        { pc = 0x409043; break; }
    r32[eax]++;
    if (memoryAGet(ds, r32[eax]) != r8[bl])
        { pc = 0x409043; break; }
  case 0x40904d: // 0000:40904d
    r32[eax] -= r32[edi];
    r32[eax]++;
    r32[ebp] = r32[eax];
    push32(r32[ebp]);
    yield* sub_406b40();
    r32[esi] = r32[eax];
    r32[ecx] = pop32();
    if (r32[esi] != r32[ebx])
        { pc = 0x409063; break; }
    r32[esi] = 0;
    { pc = 0x40906e; break; }
  case 0x409063: // 0000:409063
    push32(r32[ebp]);
    push32(r32[edi]);
    push32(r32[esi]);
    yield* sub_4098d0();
    r32[esp] += 0x0000000c;
  case 0x40906e: // 0000:40906e
    push32(r32[edi]);
    r32[eax] = kernel32.FreeEnvironmentStringsA(stack32(0)); r32[esp] += 4;
    r32[eax] = r32[esi];
    { pc = 0x40907b; break; }
  case 0x409079: // 0000:409079
    r32[eax] = 0;
  case 0x40907b: // 0000:40907b
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_409082() // 0000:409082 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x00000044;
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[esi]);
    push32(r32[edi]);
    push32(0x00000100);
    yield* sub_406b40();
    r32[esi] = r32[eax];
    r32[ecx] = pop32();
    if (r32[esi])
        { pc = 0x4090a2; break; }
    push32(0x0000001b);
    yield* sub_406f73();
    r32[ecx] = pop32();
  case 0x4090a2: // 0000:4090a2
    memoryASet32(ds, 0x42d060, r32[esi]);
    memoryASet32(ds, 0x42d160, 0x00000020);
    r32[eax] = r32[esi] + 256;
  case 0x4090b8: // 0000:4090b8
    if (r32[esi] >= r32[eax])
        { pc = 0x4090d6; break; }
    memoryASet(ds, r32[esi] + 0x4, memoryAGet(ds, r32[esi] + 0x4) & 0x00);
    memoryASet32(ds, r32[esi], memoryAGet32(ds, r32[esi]) | 0xffffffff);
    memoryASet(ds, r32[esi] + 0x5, 0x0a);
    r32[eax] = memoryAGet32(ds, 0x42d060);
    r32[esi] += 0x00000008;
    r32[eax] += 0x00000100;
    { pc = 0x4090b8; break; }
  case 0x4090d6: // 0000:4090d6
    r32[eax] = r32[esp] + 16;
    push32(r32[eax]);
    kernel32.GetStartupInfoA(stack32(0)); r32[esp] += 4;
    if (!memoryAGet16(ds, r32[esp] + 0x42))
        { pc = 0x4091b2; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x44);
    if (!r32[eax])
        { pc = 0x4091b2; break; }
    r32[esi] = memoryAGet32(ds, r32[eax]);
    r32[ebp] = r32[eax] + 4;
    r32[eax] = 0x00000800;
    r32[ebx] = r32[esi] + r32[ebp];
    if (r32s[esi] < r32s[eax])
        { pc = 0x40910c; break; }
    r32[esi] = r32[eax];
  case 0x40910c: // 0000:40910c
    if (signed32(memoryAGet32(ds, 0x42d160)) >= r32s[esi])
        { pc = 0x409166; break; }
    r32[edi] = 0x0042d064;
  case 0x409119: // 0000:409119
    push32(0x00000100);
    yield* sub_406b40();
    r32[ecx] = pop32();
    if (!r32[eax])
        { pc = 0x409160; break; }
    memoryASet32(ds, 0x42d160, memoryAGet32(ds, 0x42d160) + 0x00000020);
    memoryASet32(ds, r32[edi], r32[eax]);
    r32[ecx] = r32[eax] + 256;
  case 0x409137: // 0000:409137
    if (r32[eax] >= r32[ecx])
        { pc = 0x409153; break; }
    memoryASet(ds, r32[eax] + 0x4, memoryAGet(ds, r32[eax] + 0x4) & 0x00);
    memoryASet32(ds, r32[eax], memoryAGet32(ds, r32[eax]) | 0xffffffff);
    memoryASet(ds, r32[eax] + 0x5, 0x0a);
    r32[ecx] = memoryAGet32(ds, r32[edi]);
    r32[eax] += 0x00000008;
    r32[ecx] += 0x00000100;
    { pc = 0x409137; break; }
  case 0x409153: // 0000:409153
    r32[edi] += 0x00000004;
    if (signed32(memoryAGet32(ds, 0x42d160)) < r32s[esi])
        { pc = 0x409119; break; }
    { pc = 0x409166; break; }
  case 0x409160: // 0000:409160
    r32[esi] = memoryAGet32(ds, 0x42d160);
  case 0x409166: // 0000:409166
    r32[edi] = 0;
    if (r32s[esi] <= 0)
        { pc = 0x4091b2; break; }
  case 0x40916c: // 0000:40916c
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    if (r32[eax] == 0xffffffff)
        { pc = 0x4091a9; break; }
    r8[cl] = memoryAGet(ss, r32[ebp]);
    if (!(r8[cl] & 0x01))
        { pc = 0x4091a9; break; }
    if (r8[cl] & 0x08)
        { pc = 0x40918b; break; }
    push32(r32[eax]);
    r32[eax] = kernel32.GetFileType(stack32(0)); r32[esp] += 4;
    if (!r32[eax])
        { pc = 0x4091a9; break; }
  case 0x40918b: // 0000:40918b
    r32[eax] = r32[edi];
    r32[ecx] = r32[edi];
    r32[eax] = sar32(r32[eax], 0x05);
    r32[ecx] &= 0x0000001f;
    r32[eax] = memoryAGet32(ds, r32[eax] * 4 + 0x42d060);
    r32[eax] = r32[eax] + (r32[ecx] * 8);
    r32[ecx] = memoryAGet32(ds, r32[ebx]);
    memoryASet32(ds, r32[eax], r32[ecx]);
    r8[cl] = memoryAGet(ss, r32[ebp]);
    memoryASet(ds, r32[eax] + 0x4, r8[cl]);
  case 0x4091a9: // 0000:4091a9
    r32[edi]++;
    r32[ebp]++;
    r32[ebx] += 0x00000004;
    if (r32s[edi] < r32s[esi])
        { pc = 0x40916c; break; }
  case 0x4091b2: // 0000:4091b2
    r32[ebx] = 0;
  case 0x4091b4: // 0000:4091b4
    r32[eax] = memoryAGet32(ds, 0x42d060);
    r32[esi] = r32[eax] + (r32[ebx] * 8);
    if (memoryAGet32(ds, r32[eax] + r32[ebx] * 8) != 0xffffffff)
        { pc = 0x40920f; break; }
    memoryASet(ds, r32[esi] + 0x4, 0x81);
    if (r32[ebx])
        { pc = 0x4091cf; break; }
    push32(0xfffffff6);
    r32[eax] = pop32();
    { pc = 0x4091d9; break; }
  case 0x4091cf: // 0000:4091cf
    r32[eax] = r32[ebx];
    r32[eax]--;
    flags.carry = r32[eax] != 0;
    r32[eax] = -r32[eax];
    r32[eax] = -flags.carry;
    r32[eax] += 0xfffffff5;
  case 0x4091d9: // 0000:4091d9
    push32(r32[eax]);
    r32[eax] = kernel32.GetStdHandle(stack32(0)); r32[esp] += 4;
    r32[edi] = r32[eax];
    if (r32[edi] == 0xffffffff)
        { pc = 0x4091fe; break; }
    push32(r32[edi]);
    r32[eax] = kernel32.GetFileType(stack32(0)); r32[esp] += 4;
    if (!r32[eax])
        { pc = 0x4091fe; break; }
    r32[eax] &= 0x000000ff;
    memoryASet32(ds, r32[esi], r32[edi]);
    if (r32[eax] != 0x00000002)
        { pc = 0x409204; break; }
  case 0x4091fe: // 0000:4091fe
    memoryASet(ds, r32[esi] + 0x4, memoryAGet(ds, r32[esi] + 0x4) | 0x40);
    { pc = 0x409213; break; }
  case 0x409204: // 0000:409204
    if (r32[eax] != 0x00000003)
        { pc = 0x409213; break; }
    memoryASet(ds, r32[esi] + 0x4, memoryAGet(ds, r32[esi] + 0x4) | 0x08);
    { pc = 0x409213; break; }
  case 0x40920f: // 0000:40920f
    memoryASet(ds, r32[esi] + 0x4, memoryAGet(ds, r32[esi] + 0x4) | 0x80);
  case 0x409213: // 0000:409213
    r32[ebx]++;
    if (r32s[ebx] < signed32(0x00000003))
        { pc = 0x4091b4; break; }
    push32(memoryAGet32(ds, 0x42d160));
    r32[eax] = kernel32.SetHandleCount(stack32(0)); r32[esp] += 4;
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000044;
    r32[esp] += 4;
    return;
  }
}
function* sub_409400() // 0000:409400 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x40fb14);
    if (r32[eax] == 0x00000001)
        { pc = 0x409417; break; }
    if (r32[eax])
        { pc = 0x409438; break; }
    if (memoryAGet32(ds, 0x40eecc) != 0x00000001)
        { pc = 0x409438; break; }
  case 0x409417: // 0000:409417
    push32(0x000000fc);
    yield* sub_409439();
    r32[eax] = memoryAGet32(ds, 0x40fc3c);
    r32[ecx] = pop32();
    if (!r32[eax])
        { pc = 0x40942d; break; }
    yield* indirectCall(cs, r32[eax]);
  case 0x40942d: // 0000:40942d
    push32(0x000000ff);
    yield* sub_409439();
    r32[ecx] = pop32();
  case 0x409438: // 0000:409438
    r32[esp] += 4; return;
    return;
  }
}
function* sub_409439() // 0000:409439 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x000001a4;
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[ecx] = 0;
    r32[eax] = 0x0040ef98;
  case 0x40944c: // 0000:40944c
    if (r32[edx] == memoryAGet32(ds, r32[eax]))
        { pc = 0x40945b; break; }
    r32[eax] += 0x00000008;
    r32[ecx]++;
    if (r32s[eax] < signed32(0x0040f028))
        { pc = 0x40944c; break; }
  case 0x40945b: // 0000:40945b
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    r32[esi] <<= 3;
    if (r32[edx] != memoryAGet32(ds, r32[esi] + 0x40ef98))
        { pc = 0x409589; break; }
    r32[eax] = memoryAGet32(ds, 0x40fb14);
    if (r32[eax] == 0x00000001)
        { pc = 0x409563; break; }
    if (r32[eax])
        { pc = 0x40948c; break; }
    if (memoryAGet32(ds, 0x40eecc) == 0x00000001)
        { pc = 0x409563; break; }
  case 0x40948c: // 0000:40948c
    if (r32[edx] == 0x000000fc)
        { pc = 0x409589; break; }
    r32[eax] = r32[ebp] - 420;
    push32(0x00000104);
    push32(r32[eax]);
    push32(0x00000000);
    r32[eax] = kernel32.GetModuleFileNameA(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
    if (r32[eax])
        { pc = 0x4094c3; break; }
    r32[eax] = r32[ebp] - 420;
    push32(0x0040d6c0);
    push32(r32[eax]);
    yield* sub_40a2a0();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
  case 0x4094c3: // 0000:4094c3
    r32[eax] = r32[ebp] - 420;
    push32(r32[edi]);
    push32(r32[eax]);
    r32[edi] = r32[ebp] - 420;
    yield* sub_40a590();
    r32[eax]++;
    r32[ecx] = pop32();
    if (r32[eax] <= 0x0000003c)
        { pc = 0x409506; break; }
    r32[eax] = r32[ebp] - 420;
    push32(r32[eax]);
    yield* sub_40a590();
    r32[edi] = r32[eax];
    r32[eax] = r32[ebp] - 420;
    r32[eax] -= 0x0000003b;
    push32(0x00000003);
    r32[edi] += r32[eax];
    push32(0x0040eac8);
    push32(r32[edi]);
    yield* sub_40af80();
    r32[esp] += 0x00000010;
  case 0x409506: // 0000:409506
    r32[eax] = r32[ebp] - 160;
    push32(0x0040d6a4);
    push32(r32[eax]);
    yield* sub_40a2a0();
    r32[eax] = r32[ebp] - 160;
    push32(r32[edi]);
    push32(r32[eax]);
    yield* sub_40a2b0();
    r32[eax] = r32[ebp] - 160;
    push32(0x0040d6a0);
    push32(r32[eax]);
    yield* sub_40a2b0();
    push32(memoryAGet32(ds, r32[esi] + 0x40ef9c));
    r32[eax] = r32[ebp] - 160;
    push32(r32[eax]);
    yield* sub_40a2b0();
    push32(0x00012010);
    r32[eax] = r32[ebp] - 160;
    push32(0x0040d678);
    push32(r32[eax]);
    yield* sub_40aef7();
    r32[esp] += 0x0000002c;
    r32[edi] = pop32();
    { pc = 0x409589; break; }
  case 0x409563: // 0000:409563
    r32[eax] = r32[ebp] + 8;
    r32[esi] = r32[esi] + 4255644;
    push32(0x00000000);
    push32(r32[eax]);
    push32(memoryAGet32(ds, r32[esi]));
    yield* sub_40a590();
    r32[ecx] = pop32();
    push32(r32[eax]);
    push32(memoryAGet32(ds, r32[esi]));
    push32(0xfffffff4);
    r32[eax] = kernel32.GetStdHandle(stack32(0)); r32[esp] += 4;
    push32(r32[eax]);
    r32[eax] = kernel32.WriteFile(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4)); r32[esp] += 20;
  case 0x409589: // 0000:409589
    r32[esi] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_409590() // 0000:409590 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(r32[edi]);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x10);
    r32[edi] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[eax] = r32[ecx];
    r32[edx] = r32[ecx];
    r32[eax] += r32[esi];
    if (r32[edi] <= r32[esi])
        { pc = 0x4095b0; break; }
    if (r32[edi] < r32[eax])
        { pc = 0x409728; break; }
  case 0x4095b0: // 0000:4095b0
    if (r32[edi] & 0x00000003)
        { pc = 0x4095cc; break; }
    r32[ecx] >>= 2;
    r32[edx] &= 0x00000003;
    if (r32[ecx] < 0x00000008)
        { pc = 0x4095ec; break; }
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    indirectJump(cs, memoryAGet32(ds, r32[edx] * 4 + 0x4096d8)); return; // 0000:4095c5
  case 0x4095cc: // 0000:4095cc
    r32[eax] = r32[edi];
    r32[edx] = 0x00000003;
    flags.carry = r32[ecx] < 0x00000004;
    r32[ecx] -= 0x00000004;
    if (flags.carry)
        { pc = 0x4095e4; break; }
    r32[eax] &= 0x00000003;
    r32[ecx] += r32[eax];
    indirectJump(cs, memoryAGet32(ds, r32[eax] * 4 + 0x4095f0)); return; // 0000:4095dd
  case 0x4095e4: // 0000:4095e4
    indirectJump(cs, memoryAGet32(ds, r32[ecx] * 4 + 0x4096e8)); return; // 0000:4095e4
    // gap 1 bytes // gap 1 bytes
  case 0x4095ec: // 0000:4095ec
    indirectJump(cs, memoryAGet32(ds, r32[ecx] * 4 + 0x40966c)); return; // 0000:4095ec
    // gap 309 bytes // gap 309 bytes
  case 0x409728: // 0000:409728
    r32[esi] = (r32[ecx] + r32[esi]) + -4;
    r32[edi] = (r32[ecx] + r32[edi]) + -4;
    if (r32[edi] & 0x00000003)
        { pc = 0x40975c; break; }
    r32[ecx] >>= 2;
    r32[edx] &= 0x00000003;
    if (r32[ecx] < 0x00000008)
        { pc = 0x409750; break; }
    flags.direction = 1;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    flags.direction = 0;
    indirectJump(cs, memoryAGet32(ds, r32[edx] * 4 + 0x409870)); return; // 0000:409747
    // gap 2 bytes // gap 2 bytes
  case 0x409750: // 0000:409750
    r32[ecx] = -r32[ecx];
    indirectJump(cs, memoryAGet32(ds, r32[ecx] * 4 + 0x409820)); return; // 0000:409752
    // gap 3 bytes // gap 3 bytes
  case 0x40975c: // 0000:40975c
    r32[eax] = r32[edi];
    r32[edx] = 0x00000003;
    if (r32[ecx] < 0x00000004)
        { pc = 0x409774; break; }
    r32[eax] &= 0x00000003;
    r32[ecx] -= r32[eax];
    indirectJump(cs, memoryAGet32(ds, r32[eax] * 4 + 0x409778)); return; // 0000:40976d
  case 0x409774: // 0000:409774
    indirectJump(cs, memoryAGet32(ds, r32[ecx] * 4 + 0x409870)); return; // 0000:409774
    return;
  }
}
function* sub_4098d0() // 0000:4098d0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(r32[edi]);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x10);
    r32[edi] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[eax] = r32[ecx];
    r32[edx] = r32[ecx];
    r32[eax] += r32[esi];
    if (r32[edi] <= r32[esi])
        { pc = 0x4098f0; break; }
    if (r32[edi] < r32[eax])
        { pc = 0x409a68; break; }
  case 0x4098f0: // 0000:4098f0
    if (r32[edi] & 0x00000003)
        { pc = 0x40990c; break; }
    r32[ecx] >>= 2;
    r32[edx] &= 0x00000003;
    if (r32[ecx] < 0x00000008)
        { pc = 0x40992c; break; }
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    indirectJump(cs, memoryAGet32(ds, r32[edx] * 4 + 0x409a18)); return; // 0000:409905
  case 0x40990c: // 0000:40990c
    r32[eax] = r32[edi];
    r32[edx] = 0x00000003;
    flags.carry = r32[ecx] < 0x00000004;
    r32[ecx] -= 0x00000004;
    if (flags.carry)
        { pc = 0x409924; break; }
    r32[eax] &= 0x00000003;
    r32[ecx] += r32[eax];
    indirectJump(cs, memoryAGet32(ds, r32[eax] * 4 + 0x409930)); return; // 0000:40991d
  case 0x409924: // 0000:409924
    indirectJump(cs, memoryAGet32(ds, r32[ecx] * 4 + 0x409a28)); return; // 0000:409924
    // gap 1 bytes // gap 1 bytes
  case 0x40992c: // 0000:40992c
    indirectJump(cs, memoryAGet32(ds, r32[ecx] * 4 + 0x4099ac)); return; // 0000:40992c
    // gap 309 bytes // gap 309 bytes
  case 0x409a68: // 0000:409a68
    r32[esi] = (r32[ecx] + r32[esi]) + -4;
    r32[edi] = (r32[ecx] + r32[edi]) + -4;
    if (r32[edi] & 0x00000003)
        { pc = 0x409a9c; break; }
    r32[ecx] >>= 2;
    r32[edx] &= 0x00000003;
    if (r32[ecx] < 0x00000008)
        { pc = 0x409a90; break; }
    flags.direction = 1;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    flags.direction = 0;
    indirectJump(cs, memoryAGet32(ds, r32[edx] * 4 + 0x409bb0)); return; // 0000:409a87
    // gap 2 bytes // gap 2 bytes
  case 0x409a90: // 0000:409a90
    r32[ecx] = -r32[ecx];
    indirectJump(cs, memoryAGet32(ds, r32[ecx] * 4 + 0x409b60)); return; // 0000:409a92
    // gap 3 bytes // gap 3 bytes
  case 0x409a9c: // 0000:409a9c
    r32[eax] = r32[edi];
    r32[edx] = 0x00000003;
    if (r32[ecx] < 0x00000004)
        { pc = 0x409ab4; break; }
    r32[eax] &= 0x00000003;
    r32[ecx] -= r32[eax];
    indirectJump(cs, memoryAGet32(ds, r32[eax] * 4 + 0x409ab8)); return; // 0000:409aad
  case 0x409ab4: // 0000:409ab4
    indirectJump(cs, memoryAGet32(ds, r32[ecx] * 4 + 0x409bb0)); return; // 0000:409ab4
    return;
  }
}
function* sub_409c05() // 0000:409c05 +long
{
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(r32[ecx]);
    push32(r32[esi]);
    memoryASet16(ss, r32[ebp] - 4, fnstcw());
    push32(memoryAGet32(ss, r32[ebp] - 4));
    yield* sub_409c50();
    r32[esi] = r32[eax];
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[eax] = ~r32[eax];
    r32[esi] &= r32[eax];
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[eax] &= memoryAGet32(ss, r32[ebp] + 0xc);
    r32[esi] |= r32[eax];
    push32(r32[esi]);
    yield* sub_409ce2();
    r32[ecx] = pop32();
    memoryASet32(ss, r32[ebp] + 0xc, r32[eax]);
    r32[ecx] = pop32();
    fldcw(memoryAGet16(ss, r32[ebp] + 0xc));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
}
function* sub_409c3a() // 0000:409c3a +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] &= 0xfff7ffff;
    push32(r32[eax]);
    push32(memoryAGet32(ds, r32[esp] + 0x8));
    yield* sub_409c05();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
    r32[esp] += 4;
}
function* sub_409c50() // 0000:409c50 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = 0;
    push32(r32[ebp]);
    push32(r32[edi]);
    if (!(r8[bl] & 0x01))
        { pc = 0x409c61; break; }
    push32(0x00000010);
    r32[eax] = pop32();
  case 0x409c61: // 0000:409c61
    if (!(r8[bl] & 0x04))
        { pc = 0x409c68; break; }
    r8[al] |= 0x08;
  case 0x409c68: // 0000:409c68
    if (!(r8[bl] & 0x08))
        { pc = 0x409c6f; break; }
    r8[al] |= 0x04;
  case 0x409c6f: // 0000:409c6f
    if (!(r8[bl] & 0x10))
        { pc = 0x409c76; break; }
    r8[al] |= 0x02;
  case 0x409c76: // 0000:409c76
    if (!(r8[bl] & 0x20))
        { pc = 0x409c7d; break; }
    r8[al] |= 0x01;
  case 0x409c7d: // 0000:409c7d
    if (!(r8[bl] & 0x02))
        { pc = 0x409c87; break; }
    r32[eax] |= 0x00080000;
  case 0x409c87: // 0000:409c87
    r32[ecx] = r16[bx];
    push32(r32[esi]);
    r32[edx] = r32[ecx];
    r32[esi] = 0x00000c00;
    r32[edi] = 0x00000300;
    r32[edx] &= r32[esi];
    r32[ebp] = 0x00000200;
    if (!r32[edx])
        { pc = 0x409cbf; break; }
    if (r32[edx] == 0x00000400)
        { pc = 0x409cbc; break; }
    if (r32[edx] == 0x00000800)
        { pc = 0x409cb8; break; }
    if (r32[edx] != r32[esi])
        { pc = 0x409cbf; break; }
    r32[eax] |= r32[edi];
    { pc = 0x409cbf; break; }
  case 0x409cb8: // 0000:409cb8
    r32[eax] |= r32[ebp];
    { pc = 0x409cbf; break; }
  case 0x409cbc: // 0000:409cbc
    r8[ah] |= 0x01;
  case 0x409cbf: // 0000:409cbf
    r32[ecx] &= r32[edi];
    r32[esi] = pop32();
    if (!r32[ecx])
        { pc = 0x409ccf; break; }
    if (r32[ecx] != r32[ebp])
        { pc = 0x409cd4; break; }
    r32[eax] |= 0x00010000;
    { pc = 0x409cd4; break; }
  case 0x409ccf: // 0000:409ccf
    r32[eax] |= 0x00020000;
  case 0x409cd4: // 0000:409cd4
    r32[edi] = pop32();
    r32[ebp] = pop32();
    flags.zero = !(r8[bh] & 0x10);
    r32[ebx] = pop32();
    if (flags.zero)
        { pc = 0x409ce1; break; }
    r32[eax] |= 0x00040000;
  case 0x409ce1: // 0000:409ce1
    r32[esp] += 4; return;
    return;
  }
}
function* sub_409ce2() // 0000:409ce2 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = 0;
    push32(r32[esi]);
    if (!(r8[bl] & 0x10))
        { pc = 0x409cf2; break; }
    push32(0x00000001);
    r32[eax] = pop32();
  case 0x409cf2: // 0000:409cf2
    if (!(r8[bl] & 0x08))
        { pc = 0x409cf9; break; }
    r8[al] |= 0x04;
  case 0x409cf9: // 0000:409cf9
    if (!(r8[bl] & 0x04))
        { pc = 0x409d00; break; }
    r8[al] |= 0x08;
  case 0x409d00: // 0000:409d00
    if (!(r8[bl] & 0x02))
        { pc = 0x409d07; break; }
    r8[al] |= 0x10;
  case 0x409d07: // 0000:409d07
    if (!(r8[bl] & 0x01))
        { pc = 0x409d0e; break; }
    r8[al] |= 0x20;
  case 0x409d0e: // 0000:409d0e
    if (!(r32[ebx] & 0x00080000))
        { pc = 0x409d18; break; }
    r8[al] |= 0x02;
  case 0x409d18: // 0000:409d18
    r32[ecx] = r32[ebx];
    r32[edx] = 0x00000300;
    r32[ecx] &= r32[edx];
    r32[esi] = 0x00000200;
    if (!r32[ecx])
        { pc = 0x409d45; break; }
    if (r32[ecx] == 0x00000100)
        { pc = 0x409d42; break; }
    if (r32[ecx] == r32[esi])
        { pc = 0x409d3d; break; }
    if (r32[ecx] != r32[edx])
        { pc = 0x409d45; break; }
    r8[ah] |= 0x0c;
    { pc = 0x409d45; break; }
  case 0x409d3d: // 0000:409d3d
    r8[ah] |= 0x08;
    { pc = 0x409d45; break; }
  case 0x409d42: // 0000:409d42
    r8[ah] |= 0x04;
  case 0x409d45: // 0000:409d45
    r32[ecx] = r32[ebx];
    r32[ecx] &= 0x00030000;
    if (!r32[ecx])
        { pc = 0x409d5b; break; }
    if (r32[ecx] != 0x00010000)
        { pc = 0x409d5d; break; }
    r32[eax] |= r32[esi];
    { pc = 0x409d5d; break; }
  case 0x409d5b: // 0000:409d5b
    r32[eax] |= r32[edx];
  case 0x409d5d: // 0000:409d5d
    r32[esi] = pop32();
    flags.zero = !(r32[ebx] & 0x00040000);
    r32[ebx] = pop32();
    if (flags.zero)
        { pc = 0x409d6a; break; }
    r8[ah] |= 0x10;
  case 0x409d6a: // 0000:409d6a
    r32[esp] += 4; return;
    return;
  }
}
function* sub_40a2a0() // 0000:40a2a0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x8);
    { pc = 0x40a311; break; }
    // gap 106 bytes // gap 106 bytes
  case 0x40a311: // 0000:40a311
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    if (!(r32[ecx] & 0x00000003))
        { pc = 0x40a336; break; }
  case 0x40a31d: // 0000:40a31d
    r8[dl] = memoryAGet(ds, r32[ecx]);
    r32[ecx]++;
    if (!r8[dl])
        { pc = 0x40a388; break; }
    memoryASet(ds, r32[edi], r8[dl]);
    r32[edi]++;
    if (r32[ecx] & 0x00000003)
        { pc = 0x40a31d; break; }
    { pc = 0x40a336; break; }
  case 0x40a331: // 0000:40a331
    memoryASet32(ds, r32[edi], r32[edx]);
    r32[edi] += 0x00000004;
  case 0x40a336: // 0000:40a336
    r32[edx] = 0x7efefeff;
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] += r32[eax];
    r32[eax] ^= 0xffffffff;
    r32[eax] ^= r32[edx];
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[ecx] += 0x00000004;
    if (!(r32[eax] & 0x81010100))
        { pc = 0x40a331; break; }
    if (!r8[dl])
        { pc = 0x40a388; break; }
    if (!r8[dh])
        { pc = 0x40a37f; break; }
    if (!(r32[edx] & 0x00ff0000))
        { pc = 0x40a372; break; }
    if (!(r32[edx] & 0xff000000))
        { pc = 0x40a36a; break; }
    { pc = 0x40a331; break; }
  case 0x40a36a: // 0000:40a36a
    memoryASet32(ds, r32[edi], r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edi] = pop32();
    r32[esp] += 4; return;
  case 0x40a372: // 0000:40a372
    memoryASet16(ds, r32[edi], r16[dx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    memoryASet(ds, r32[edi] + 0x2, 0x00);
    r32[edi] = pop32();
    r32[esp] += 4; return;
  case 0x40a37f: // 0000:40a37f
    memoryASet16(ds, r32[edi], r16[dx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edi] = pop32();
    r32[esp] += 4; return;
  case 0x40a388: // 0000:40a388
    memoryASet(ds, r32[edi], r8[dl]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_40a2b0() // 0000:40a2b0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[edi]);
    if (!(r32[ecx] & 0x00000003))
        { pc = 0x40a2cc; break; }
  case 0x40a2bd: // 0000:40a2bd
    r8[al] = memoryAGet(ds, r32[ecx]);
    r32[ecx]++;
    if (!r8[al])
        { pc = 0x40a2ff; break; }
    if (r32[ecx] & 0x00000003)
        { pc = 0x40a2bd; break; }
  case 0x40a2cc: // 0000:40a2cc
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = 0x7efefeff;
    r32[edx] += r32[eax];
    r32[eax] ^= 0xffffffff;
    r32[eax] ^= r32[edx];
    r32[ecx] += 0x00000004;
    if (!(r32[eax] & 0x81010100))
        { pc = 0x40a2cc; break; }
    r32[eax] = memoryAGet32(ds, r32[ecx] - 4);
    if (!r8[al])
        { pc = 0x40a30e; break; }
    if (!r8[ah])
        { pc = 0x40a309; break; }
    if (!(r32[eax] & 0x00ff0000))
        { pc = 0x40a304; break; }
    if (!(r32[eax] & 0xff000000))
        { pc = 0x40a2ff; break; }
    { pc = 0x40a2cc; break; }
  case 0x40a2ff: // 0000:40a2ff
    r32[edi] = r32[ecx] - 1;
    { pc = 0x40a311; break; }
  case 0x40a304: // 0000:40a304
    r32[edi] = r32[ecx] - 2;
    { pc = 0x40a311; break; }
  case 0x40a309: // 0000:40a309
    r32[edi] = r32[ecx] - 3;
    { pc = 0x40a311; break; }
  case 0x40a30e: // 0000:40a30e
    r32[edi] = r32[ecx] - 4;
  case 0x40a311: // 0000:40a311
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    if (!(r32[ecx] & 0x00000003))
        { pc = 0x40a336; break; }
  case 0x40a31d: // 0000:40a31d
    r8[dl] = memoryAGet(ds, r32[ecx]);
    r32[ecx]++;
    if (!r8[dl])
        { pc = 0x40a388; break; }
    memoryASet(ds, r32[edi], r8[dl]);
    r32[edi]++;
    if (r32[ecx] & 0x00000003)
        { pc = 0x40a31d; break; }
    { pc = 0x40a336; break; }
  case 0x40a331: // 0000:40a331
    memoryASet32(ds, r32[edi], r32[edx]);
    r32[edi] += 0x00000004;
  case 0x40a336: // 0000:40a336
    r32[edx] = 0x7efefeff;
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] += r32[eax];
    r32[eax] ^= 0xffffffff;
    r32[eax] ^= r32[edx];
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r32[ecx] += 0x00000004;
    if (!(r32[eax] & 0x81010100))
        { pc = 0x40a331; break; }
    if (!r8[dl])
        { pc = 0x40a388; break; }
    if (!r8[dh])
        { pc = 0x40a37f; break; }
    if (!(r32[edx] & 0x00ff0000))
        { pc = 0x40a372; break; }
    if (!(r32[edx] & 0xff000000))
        { pc = 0x40a36a; break; }
    { pc = 0x40a331; break; }
  case 0x40a36a: // 0000:40a36a
    memoryASet32(ds, r32[edi], r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edi] = pop32();
    r32[esp] += 4; return;
  case 0x40a372: // 0000:40a372
    memoryASet16(ds, r32[edi], r16[dx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    memoryASet(ds, r32[edi] + 0x2, 0x00);
    r32[edi] = pop32();
    r32[esp] += 4; return;
  case 0x40a37f: // 0000:40a37f
    memoryASet16(ds, r32[edi], r16[dx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edi] = pop32();
    r32[esp] += 4; return;
  case 0x40a388: // 0000:40a388
    memoryASet(ds, r32[edi], r8[dl]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_40a530() // 0000:40a530 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    if (!r32[edx])
        { pc = 0x40a583; break; }
    r32[eax] = 0;
    r8[al] = memoryAGet(ds, r32[esp] + 0x8);
    push32(r32[edi]);
    r32[edi] = r32[ecx];
    if (r32[edx] < 0x00000004)
        { pc = 0x40a577; break; }
    r32[ecx] = -r32[ecx];
    r32[ecx] &= 0x00000003;
    if (!r32[ecx])
        { pc = 0x40a559; break; }
    r32[edx] -= r32[ecx];
  case 0x40a553: // 0000:40a553
    memoryASet(ds, r32[edi], r8[al]);
    r32[edi]++;
    r32[ecx]--;
    if (r32[ecx])
        { pc = 0x40a553; break; }
  case 0x40a559: // 0000:40a559
    r32[ecx] = r32[eax];
    r32[eax] <<= 8;
    r32[eax] += r32[ecx];
    r32[ecx] = r32[eax];
    r32[eax] <<= 16;
    r32[eax] += r32[ecx];
    r32[ecx] = r32[edx];
    r32[edx] &= 0x00000003;
    r32[ecx] >>= 2;
    if (!r32[ecx])
        { pc = 0x40a577; break; }
    for (; r32[ecx] != 0; --r32[ecx]) stosd_ESEDI(r32[eax]);
    if (!r32[edx])
        { pc = 0x40a57d; break; }
  case 0x40a577: // 0000:40a577
    memoryASet(ds, r32[edi], r8[al]);
    r32[edi]++;
    r32[edx]--;
    if (r32[edx])
        { pc = 0x40a577; break; }
  case 0x40a57d: // 0000:40a57d
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edi] = pop32();
    r32[esp] += 4; return;
  case 0x40a583: // 0000:40a583
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[esp] += 4;
    return;
  }
}
function* sub_40a590() // 0000:40a590 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    if (!(r32[ecx] & 0x00000003))
        { pc = 0x40a5b0; break; }
  case 0x40a59c: // 0000:40a59c
    r8[al] = memoryAGet(ds, r32[ecx]);
    r32[ecx]++;
    if (!r8[al])
        { pc = 0x40a5e3; break; }
    if (r32[ecx] & 0x00000003)
        { pc = 0x40a59c; break; }
    r32[eax] += 0x00000000;
  case 0x40a5b0: // 0000:40a5b0
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r32[edx] = 0x7efefeff;
    r32[edx] += r32[eax];
    r32[eax] ^= 0xffffffff;
    r32[eax] ^= r32[edx];
    r32[ecx] += 0x00000004;
    if (!(r32[eax] & 0x81010100))
        { pc = 0x40a5b0; break; }
    r32[eax] = memoryAGet32(ds, r32[ecx] - 4);
    if (!r8[al])
        { pc = 0x40a601; break; }
    if (!r8[ah])
        { pc = 0x40a5f7; break; }
    if (!(r32[eax] & 0x00ff0000))
        { pc = 0x40a5ed; break; }
    if (!(r32[eax] & 0xff000000))
        { pc = 0x40a5e3; break; }
    { pc = 0x40a5b0; break; }
  case 0x40a5e3: // 0000:40a5e3
    r32[eax] = r32[ecx] - 1;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] -= r32[ecx];
    r32[esp] += 4; return;
  case 0x40a5ed: // 0000:40a5ed
    r32[eax] = r32[ecx] - 2;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] -= r32[ecx];
    r32[esp] += 4; return;
  case 0x40a5f7: // 0000:40a5f7
    r32[eax] = r32[ecx] - 3;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] -= r32[ecx];
    r32[esp] += 4; return;
  case 0x40a601: // 0000:40a601
    r32[eax] = r32[ecx] - 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] -= r32[ecx];
    r32[esp] += 4;
    return;
  }
}
function* sub_40a614() // 0000:40a614 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    if (r32[eax] >= memoryAGet32(ds, 0x42d160))
        { pc = 0x40a696; break; }
    r32[ecx] = r32[eax];
    r32[esi] = r32[eax];
    r32[ecx] = sar32(r32[ecx], 0x05);
    r32[esi] &= 0x0000001f;
    r32[edi] = (r32[ecx] * 4) + 4378720;
    r32[esi] <<= 3;
    r32[ecx] = memoryAGet32(ds, r32[edi]);
    if (!(memoryAGet(ds, r32[ecx] + r32[esi] + 0x4) & 0x01))
        { pc = 0x40a696; break; }
    push32(r32[eax]);
    yield* sub_40bdfc();
    r32[ecx] = pop32();
    if (r32[eax] != 0xffffffff)
        { pc = 0x40a658; break; }
    memoryASet32(ds, 0x40fab8, 0x00000009);
    { pc = 0x40a6a7; break; }
  case 0x40a658: // 0000:40a658
    push32(memoryAGet32(ds, r32[esp] + 0x18));
    push32(0x00000000);
    push32(memoryAGet32(ds, r32[esp] + 0x1c));
    push32(r32[eax]);
    r32[eax] = kernel32.SetFilePointer(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
    r32[ebx] = r32[eax];
    if (r32[ebx] != 0xffffffff)
        { pc = 0x40a678; break; }
    r32[eax] = kernel32.GetLastError();
    { pc = 0x40a67a; break; }
  case 0x40a678: // 0000:40a678
    r32[eax] = 0;
  case 0x40a67a: // 0000:40a67a
    if (!r32[eax])
        { pc = 0x40a687; break; }
    push32(r32[eax]);
    yield* sub_40bd1b();
    r32[ecx] = pop32();
    { pc = 0x40a6a7; break; }
  case 0x40a687: // 0000:40a687
    r32[eax] = memoryAGet32(ds, r32[edi]);
    memoryASet(ds, r32[eax] + r32[esi] + 0x4, memoryAGet(ds, r32[eax] + r32[esi] + 0x4) & 0xfd);
    r32[eax] = (r32[eax] + r32[esi]) + 4;
    r32[eax] = r32[ebx];
    { pc = 0x40a6aa; break; }
  case 0x40a696: // 0000:40a696
    memoryASet32(ds, 0x40fabc, memoryAGet32(ds, 0x40fabc) & 0x00000000);
    memoryASet32(ds, 0x40fab8, 0x00000009);
  case 0x40a6a7: // 0000:40a6a7
    r32[eax] |= 0xffffffff;
  case 0x40a6aa: // 0000:40a6aa
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_40a6ae() // 0000:40a6ae +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x00000414;
    r32[ecx] = memoryAGet32(ss, r32[ebp] + 0x8);
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    if (r32[ecx] >= memoryAGet32(ds, 0x42d160))
        { pc = 0x40a842; break; }
    r32[eax] = r32[ecx];
    r32[esi] = r32[ecx];
    r32[eax] = sar32(r32[eax], 0x05);
    r32[esi] &= 0x0000001f;
    r32[ebx] = (r32[eax] * 4) + 4378720;
    r32[esi] <<= 3;
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    r8[al] = memoryAGet(ds, r32[eax] + r32[esi] + 0x4);
    if (!(r8[al] & 0x01))
        { pc = 0x40a842; break; }
    r32[edi] = 0;
    memoryASet32(ss, r32[ebp] - 8, r32[edi]);
    memoryASet32(ss, r32[ebp] - 16, r32[edi]);
    if (memoryAGet32(ss, r32[ebp] + 0x10) != r32[edi])
        { pc = 0x40a6ff; break; }
  case 0x40a6f8: // 0000:40a6f8
    r32[eax] = 0;
    { pc = 0x40a856; break; }
  case 0x40a6ff: // 0000:40a6ff
    if (!(r8[al] & 0x20))
        { pc = 0x40a70f; break; }
    push32(0x00000002);
    push32(r32[edi]);
    push32(r32[ecx]);
    yield* sub_40a614();
    r32[esp] += 0x0000000c;
  case 0x40a70f: // 0000:40a70f
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    r32[eax] += r32[esi];
    if (!(memoryAGet(ds, r32[eax] + 0x4) & 0x80))
        { pc = 0x40a7de; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0xc);
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
    memoryASet32(ss, r32[ebp] + 0x8, r32[edi]);
    if (memoryAGet32(ss, r32[ebp] + 0x10) <= r32[edi])
        { pc = 0x40a816; break; }
  case 0x40a72f: // 0000:40a72f
    r32[eax] = r32[ebp] - 1044;
  case 0x40a735: // 0000:40a735
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    r32[ecx] -= memoryAGet32(ss, r32[ebp] + 0xc);
    if (r32[ecx] >= memoryAGet32(ss, r32[ebp] + 0x10))
        { pc = 0x40a769; break; }
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 4);
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) + 1);
    r8[cl] = memoryAGet(ds, r32[ecx]);
    if (r8[cl] != 0x0a)
        { pc = 0x40a754; break; }
    memoryASet32(ss, r32[ebp] - 16, memoryAGet32(ss, r32[ebp] - 16) + 1);
    memoryASet(ds, r32[eax], 0x0d);
    r32[eax]++;
  case 0x40a754: // 0000:40a754
    memoryASet(ds, r32[eax], r8[cl]);
    r32[eax]++;
    r32[ecx] = r32[eax];
    r32[edx] = r32[ebp] - 1044;
    r32[ecx] -= r32[edx];
    if (r32s[ecx] < signed32(0x00000400))
        { pc = 0x40a735; break; }
  case 0x40a769: // 0000:40a769
    r32[edi] = r32[eax];
    r32[eax] = r32[ebp] - 1044;
    r32[edi] -= r32[eax];
    r32[eax] = r32[ebp] - 12;
    push32(0x00000000);
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 1044;
    push32(r32[edi]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    push32(memoryAGet32(ds, r32[eax] + r32[esi]));
    r32[eax] = kernel32.WriteFile(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4)); r32[esp] += 20;
    if (!r32[eax])
        { pc = 0x40a7d3; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] - 12);
    memoryASet32(ss, r32[ebp] - 8, memoryAGet32(ss, r32[ebp] - 8) + r32[eax]);
    if (r32s[eax] < r32s[edi])
        { pc = 0x40a7a5; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] - 4);
    r32[eax] -= memoryAGet32(ss, r32[ebp] + 0xc);
    if (r32[eax] < memoryAGet32(ss, r32[ebp] + 0x10))
        { pc = 0x40a72f; break; }
  case 0x40a7a5: // 0000:40a7a5
    r32[edi] = 0;
  case 0x40a7a7: // 0000:40a7a7
    r32[eax] = memoryAGet32(ss, r32[ebp] - 8);
    if (r32[eax] != r32[edi])
        { pc = 0x40a83d; break; }
    if (memoryAGet32(ss, r32[ebp] + 0x8) == r32[edi])
        { pc = 0x40a816; break; }
    push32(0x00000005);
    r32[eax] = pop32();
    if (memoryAGet32(ss, r32[ebp] + 0x8) != r32[eax])
        { pc = 0x40a80b; break; }
    memoryASet32(ds, 0x40fab8, 0x00000009);
    memoryASet32(ds, 0x40fabc, r32[eax]);
    { pc = 0x40a853; break; }
  case 0x40a7d3: // 0000:40a7d3
    r32[eax] = kernel32.GetLastError();
    memoryASet32(ss, r32[ebp] + 0x8, r32[eax]);
    { pc = 0x40a7a5; break; }
  case 0x40a7de: // 0000:40a7de
    r32[ecx] = r32[ebp] - 12;
    push32(r32[edi]);
    push32(r32[ecx]);
    push32(memoryAGet32(ss, r32[ebp] + 0x10));
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    push32(memoryAGet32(ds, r32[eax]));
    r32[eax] = kernel32.WriteFile(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4)); r32[esp] += 20;
    if (!r32[eax])
        { pc = 0x40a800; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] - 12);
    memoryASet32(ss, r32[ebp] + 0x8, r32[edi]);
    memoryASet32(ss, r32[ebp] - 8, r32[eax]);
    { pc = 0x40a7a7; break; }
  case 0x40a800: // 0000:40a800
    r32[eax] = kernel32.GetLastError();
    memoryASet32(ss, r32[ebp] + 0x8, r32[eax]);
    { pc = 0x40a7a7; break; }
  case 0x40a80b: // 0000:40a80b
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    yield* sub_40bd1b();
    r32[ecx] = pop32();
    { pc = 0x40a853; break; }
  case 0x40a816: // 0000:40a816
    r32[eax] = memoryAGet32(ds, r32[ebx]);
    if (!(memoryAGet(ds, r32[eax] + r32[esi] + 0x4) & 0x40))
        { pc = 0x40a82b; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0xc);
    if (memoryAGet(ds, r32[eax]) == 0x1a)
        { pc = 0x40a6f8; break; }
  case 0x40a82b: // 0000:40a82b
    memoryASet32(ds, 0x40fab8, 0x0000001c);
    memoryASet32(ds, 0x40fabc, r32[edi]);
    { pc = 0x40a853; break; }
  case 0x40a83d: // 0000:40a83d
    r32[eax] -= memoryAGet32(ss, r32[ebp] - 16);
    { pc = 0x40a856; break; }
  case 0x40a842: // 0000:40a842
    memoryASet32(ds, 0x40fabc, memoryAGet32(ds, 0x40fabc) & 0x00000000);
    memoryASet32(ds, 0x40fab8, 0x00000009);
  case 0x40a853: // 0000:40a853
    r32[eax] |= 0xffffffff;
  case 0x40a856: // 0000:40a856
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_40a85b() // 0000:40a85b +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    memoryASet32(ds, 0x40fc70, memoryAGet32(ds, 0x40fc70) + 1);
    push32(0x00001000);
    yield* sub_406b40();
    r32[ecx] = pop32();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(ds, r32[ecx] + 0x8, r32[eax]);
    if (!r32[eax])
        { pc = 0x40a884; break; }
    memoryASet32(ds, r32[ecx] + 0xc, memoryAGet32(ds, r32[ecx] + 0xc) | 0x00000008);
    memoryASet32(ds, r32[ecx] + 0x18, 0x00001000);
    { pc = 0x40a895; break; }
  case 0x40a884: // 0000:40a884
    memoryASet32(ds, r32[ecx] + 0xc, memoryAGet32(ds, r32[ecx] + 0xc) | 0x00000004);
    r32[eax] = r32[ecx] + 20;
    memoryASet32(ds, r32[ecx] + 0x8, r32[eax]);
    memoryASet32(ds, r32[ecx] + 0x18, 0x00000002);
  case 0x40a895: // 0000:40a895
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x8);
    memoryASet32(ds, r32[ecx] + 0x4, memoryAGet32(ds, r32[ecx] + 0x4) & 0x00000000);
    memoryASet32(ds, r32[ecx], r32[eax]);
    r32[esp] += 4;
    return;
  }
}
function* sub_40a89f() // 0000:40a89f +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    if (r32[eax] < memoryAGet32(ds, 0x42d160))
        { pc = 0x40a8ae; break; }
    r32[eax] = 0;
    r32[esp] += 4; return;
  case 0x40a8ae: // 0000:40a8ae
    r32[ecx] = r32[eax];
    r32[eax] &= 0x0000001f;
    r32[ecx] = sar32(r32[ecx], 0x05);
    r32[ecx] = memoryAGet32(ds, r32[ecx] * 4 + 0x42d060);
    r8[al] = memoryAGet(ds, r32[ecx] + r32[eax] * 8 + 0x4);
    r32[eax] &= 0x00000040;
    r32[esp] += 4;
    return;
  }
}
function* sub_40a8c5() // 0000:40a8c5 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, 0x42d040);
    push32(r32[esi]);
    push32(0x00000014);
    r32[esi] = pop32();
    if (r32[eax])
        { pc = 0x40a8d9; break; }
    r32[eax] = 0x00000200;
    { pc = 0x40a8df; break; }
  case 0x40a8d9: // 0000:40a8d9
    if (r32s[eax] >= r32s[esi])
        { pc = 0x40a8e4; break; }
    r32[eax] = r32[esi];
  case 0x40a8df: // 0000:40a8df
    memoryASet32(ds, 0x42d040, r32[eax]);
  case 0x40a8e4: // 0000:40a8e4
    push32(0x00000004);
    push32(r32[eax]);
    yield* sub_40be39();
    r32[ecx] = pop32();
    memoryASet32(ds, 0x42c028, r32[eax]);
    r32[ecx] = pop32();
    if (r32[eax])
        { pc = 0x40a918; break; }
    push32(0x00000004);
    push32(r32[esi]);
    memoryASet32(ds, 0x42d040, r32[esi]);
    yield* sub_40be39();
    r32[ecx] = pop32();
    memoryASet32(ds, 0x42c028, r32[eax]);
    r32[ecx] = pop32();
    if (r32[eax])
        { pc = 0x40a918; break; }
    push32(0x0000001a);
    yield* sub_406f73();
    r32[ecx] = pop32();
  case 0x40a918: // 0000:40a918
    r32[ecx] = 0;
    r32[eax] = 0x0040f280;
  case 0x40a91f: // 0000:40a91f
    r32[edx] = memoryAGet32(ds, 0x42c028);
    memoryASet32(ds, r32[ecx] + r32[edx], r32[eax]);
    r32[eax] += 0x00000020;
    r32[ecx] += 0x00000004;
    if (r32s[eax] < signed32(0x0040f500))
        { pc = 0x40a91f; break; }
    r32[edx] = 0;
    r32[ecx] = 0x0040f290;
  case 0x40a93c: // 0000:40a93c
    r32[eax] = r32[edx];
    r32[esi] = r32[edx];
    r32[eax] = sar32(r32[eax], 0x05);
    r32[esi] &= 0x0000001f;
    r32[eax] = memoryAGet32(ds, r32[eax] * 4 + 0x42d060);
    r32[eax] = memoryAGet32(ds, r32[eax] + r32[esi] * 8);
    if (r32[eax] == 0xffffffff)
        { pc = 0x40a959; break; }
    if (r32[eax])
        { pc = 0x40a95c; break; }
  case 0x40a959: // 0000:40a959
    memoryASet32(ds, r32[ecx], memoryAGet32(ds, r32[ecx]) | 0xffffffff);
  case 0x40a95c: // 0000:40a95c
    r32[ecx] += 0x00000020;
    r32[edx]++;
    if (r32s[ecx] < signed32(0x0040f2f0))
        { pc = 0x40a93c; break; }
    r32[esi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_40a97e() // 0000:40a97e +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    if (r32[eax])
        { pc = 0x40a98a; break; }
    r32[ebp] = pop32();
    r32[esp] += 4; return;
  case 0x40a98a: // 0000:40a98a
    if (memoryAGet32(ds, 0x40fc94))
        { pc = 0x40a9a5; break; }
    r16[cx] = memoryAGet16(ss, r32[ebp] + 0xc);
    if (r16[cx] > 0x00ff)
        { pc = 0x40a9d7; break; }
    push32(0x00000001);
    memoryASet(ds, r32[eax], r8[cl]);
    r32[eax] = pop32();
    r32[ebp] = pop32();
    r32[esp] += 4; return;
  case 0x40a9a5: // 0000:40a9a5
    r32[ecx] = r32[ebp] + 8;
    memoryASet32(ss, r32[ebp] + 0x8, memoryAGet32(ss, r32[ebp] + 0x8) & 0x00000000);
    push32(r32[ecx]);
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x40f030));
    push32(r32[eax]);
    r32[eax] = r32[ebp] + 12;
    push32(0x00000001);
    push32(r32[eax]);
    push32(0x00000220);
    push32(memoryAGet32(ds, 0x40fca4));
    r32[eax] = kernel32.WideCharToMultiByte(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7)); r32[esp] += 32;
    if (!r32[eax])
        { pc = 0x40a9d7; break; }
    if (!memoryAGet32(ss, r32[ebp] + 0x8))
        { pc = 0x40a9e4; break; }
  case 0x40a9d7: // 0000:40a9d7
    memoryASet32(ds, 0x40fab8, 0x0000002a);
    r32[eax] |= 0xffffffff;
  case 0x40a9e4: // 0000:40a9e4
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_40a9f0() // 0000:40a9f0 +long +stackDrop16
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    if (r32[eax])
        { pc = 0x40aa12; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = 0;
    div32(r32[ecx]);
    r32[ebx] = r32[eax];
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);
    div32(r32[ecx]);
    r32[edx] = r32[ebx];
    { pc = 0x40aa53; break; }
  case 0x40aa12: // 0000:40aa12
    r32[ecx] = r32[eax];
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);
  case 0x40aa20: // 0000:40aa20
    flags.carry = r32[ecx] & 1;
    r32[ecx] >>= 1;
    r32[ebx] = rcr32(r32[ebx], 0x00000001);
    flags.carry = r32[edx] & 1;
    r32[edx] >>= 1;
    r32[eax] = rcr32(r32[eax], 0x00000001);
    if (r32[ecx])
        { pc = 0x40aa20; break; }
    div32(r32[ebx]);
    r32[esi] = r32[eax];
    mul32(memoryAGet32(ds, r32[esp] + 0x18));
    r32[ecx] = r32[eax];
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    mul32(r32[esi]);
    flags.carry = overflow32(r32[edx] + r32[ecx]);
    r32[edx] += r32[ecx];
    if (flags.carry)
        { pc = 0x40aa4e; break; }
    if (r32[edx] > memoryAGet32(ds, r32[esp] + 0x10))
        { pc = 0x40aa4e; break; }
    if (r32[edx] < memoryAGet32(ds, r32[esp] + 0x10))
        { pc = 0x40aa4f; break; }
    if (r32[eax] <= memoryAGet32(ds, r32[esp] + 0xc))
        { pc = 0x40aa4f; break; }
  case 0x40aa4e: // 0000:40aa4e
    r32[esi]--;
  case 0x40aa4f: // 0000:40aa4f
    r32[edx] = 0;
    r32[eax] = r32[esi];
  case 0x40aa53: // 0000:40aa53
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 20;
    return;
  }
}
function* sub_40aa60() // 0000:40aa60 +long +stackDrop16
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    if (r32[eax])
        { pc = 0x40aa81; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[edx] = 0;
    div32(r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    div32(r32[ecx]);
    r32[eax] = r32[edx];
    r32[edx] = 0;
    { pc = 0x40aad1; break; }
  case 0x40aa81: // 0000:40aa81
    r32[ecx] = r32[eax];
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
  case 0x40aa8f: // 0000:40aa8f
    flags.carry = r32[ecx] & 1;
    r32[ecx] >>= 1;
    r32[ebx] = rcr32(r32[ebx], 0x00000001);
    flags.carry = r32[edx] & 1;
    r32[edx] >>= 1;
    r32[eax] = rcr32(r32[eax], 0x00000001);
    if (r32[ecx])
        { pc = 0x40aa8f; break; }
    div32(r32[ebx]);
    r32[ecx] = r32[eax];
    mul32(memoryAGet32(ds, r32[esp] + 0x14));
    r32[etx] = r32[ecx]; r32[ecx] = r32[eax]; r32[eax] = r32[etx];
    mul32(memoryAGet32(ds, r32[esp] + 0x10));
    flags.carry = overflow32(r32[edx], r32[ecx]);
    r32[edx] += r32[ecx];
    if (flags.carry)
        { pc = 0x40aaba; break; }
    if (r32[edx] > memoryAGet32(ds, r32[esp] + 0xc))
        { pc = 0x40aaba; break; }
    if (r32[edx] < memoryAGet32(ds, r32[esp] + 0xc))
        { pc = 0x40aac2; break; }
    if (r32[eax] <= memoryAGet32(ds, r32[esp] + 0x8))
        { pc = 0x40aac2; break; }
  case 0x40aaba: // 0000:40aaba
    flags.carry = r32[eax] < memoryAGet32(ds, r32[esp] + 0x10);
    r32[eax] -= memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] -= memoryAGet32(ds, r32[esp] + 0x14) + flags.carry;
  case 0x40aac2: // 0000:40aac2
    flags.carry = r32[eax] < memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] -= memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] -= memoryAGet32(ds, r32[esp] + 0xc) + flags.carry;
    r32[edx] = -r32[edx];
    flags.carry = r32[eax] != 0;
    r32[eax] = -r32[eax];
    r32[edx] -= (0x00000000 + flags.carry);
  case 0x40aad1: // 0000:40aad1
    r32[ebx] = pop32();
    r32[esp] += 20;
    return;
  }
}
function* sub_40aad5() // 0000:40aad5 +long
{
    r32[esp] -= 4;
    push32(0x00000004);
    push32(0x00000000);
    push32(memoryAGet32(ds, r32[esp] + 0xc));
    yield* sub_40aae6();
    r32[esp] += 0x0000000c;
    r32[esp] += 4;
}
function* sub_40aae6() // 0000:40aae6 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet(ds, r32[esp] + 0x4);
    r8[cl] = memoryAGet(ds, r32[esp] + 0xc);
    if (memoryAGet(ds, r32[eax] + 0x42bf21) & r8[cl])
        { pc = 0x40ab13; break; }
    if (!memoryAGet32(ds, r32[esp] + 0x8))
        { pc = 0x40ab0c; break; }
    r32[eax] = memoryAGet16(ds, r32[eax] * 2 + 0x40f046);
    r32[eax] &= memoryAGet32(ds, r32[esp] + 0x8);
    { pc = 0x40ab0e; break; }
  case 0x40ab0c: // 0000:40ab0c
    r32[eax] = 0;
  case 0x40ab0e: // 0000:40ab0e
    if (r32[eax])
        { pc = 0x40ab13; break; }
    r32[esp] += 4; return;
  case 0x40ab13: // 0000:40ab13
    push32(0x00000001);
    r32[eax] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_40ab17() // 0000:40ab17 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x00000018;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    yield* sub_40acb0();
    r32[esi] = r32[eax];
    r32[ecx] = pop32();
    memoryASet32(ss, r32[ebp] + 0x8, r32[esi]);
    if (r32[esi] == memoryAGet32(ds, 0x42be04))
        { pc = 0x40aca4; break; }
    r32[ebx] = 0;
    if (r32[esi] == r32[ebx])
        { pc = 0x40ac9a; break; }
    r32[edx] = 0;
    r32[eax] = 0x0040f508;
  case 0x40ab4b: // 0000:40ab4b
    if (memoryAGet32(ds, r32[eax]) == r32[esi])
        { pc = 0x40abc1; break; }
    r32[eax] += 0x00000030;
    r32[edx]++;
    if (r32s[eax] < signed32(0x0040f5f8))
        { pc = 0x40ab4b; break; }
    r32[eax] = r32[ebp] - 24;
    push32(r32[eax]);
    push32(r32[esi]);
    r32[eax] = kernel32.GetCPInfo(stack32(0), stack32(1)); r32[esp] += 8;
    if (r32[eax] != 0x00000001)
        { pc = 0x40ac92; break; }
    push32(0x00000040);
    r32[eax] = 0;
    r32[ecx] = pop32();
    r32[edi] = 0x0042bf20;
    memoryASet32(ds, 0x42be04, r32[esi]);
    for (; r32[ecx] != 0; --r32[ecx]) stosd_ESEDI(r32[eax]);
    stosb_ESEDI(r8[al]);
    memoryASet32(ds, 0x42c024, r32[ebx]);
    if (memoryAGet32(ss, r32[ebp] - 24) <= 0x00000001)
        { pc = 0x40ac80; break; }
    if (!memoryAGet(ss, r32[ebp] - 18))
        { pc = 0x40ac56; break; }
    r32[ecx] = r32[ebp] - 17;
  case 0x40ab9e: // 0000:40ab9e
    r8[dl] = memoryAGet(ds, r32[ecx]);
    if (!r8[dl])
        { pc = 0x40ac56; break; }
    r32[eax] = memoryAGet(ds, r32[ecx] - 1);
    r32[edx] = r8[dl];
  case 0x40abaf: // 0000:40abaf
    if (r32[eax] > r32[edx])
        { pc = 0x40ac4a; break; }
    memoryASet(ds, r32[eax] + 0x42bf21, memoryAGet(ds, r32[eax] + 0x42bf21) | 0x04);
    r32[eax]++;
    { pc = 0x40abaf; break; }
  case 0x40abc1: // 0000:40abc1
    push32(0x00000040);
    r32[eax] = 0;
    r32[ecx] = pop32();
    r32[edi] = 0x0042bf20;
    for (; r32[ecx] != 0; --r32[ecx]) stosd_ESEDI(r32[eax]);
    r32[esi] = r32[edx] + (r32[edx] * 2);
    memoryASet32(ss, r32[ebp] - 4, r32[ebx]);
    r32[esi] <<= 4;
    stosb_ESEDI(r8[al]);
    r32[ebx] = r32[esi] + 4257048;
  case 0x40abdd: // 0000:40abdd
    r32[ecx] = r32[ebx];
    if (!memoryAGet(ds, r32[ebx]))
        { pc = 0x40ac10; break; }
  case 0x40abe4: // 0000:40abe4
    r8[dl] = memoryAGet(ds, r32[ecx] + 0x1);
    if (!r8[dl])
        { pc = 0x40ac10; break; }
    r32[eax] = memoryAGet(ds, r32[ecx]);
    r32[edi] = r8[dl];
    if (r32[eax] > r32[edi])
        { pc = 0x40ac09; break; }
    r32[edx] = memoryAGet32(ss, r32[ebp] - 4);
    r8[dl] = memoryAGet(ds, r32[edx] + 0x40f500);
  case 0x40abfe: // 0000:40abfe
    memoryASet(ds, r32[eax] + 0x42bf21, memoryAGet(ds, r32[eax] + 0x42bf21) | r8[dl]);
    r32[eax]++;
    if (r32[eax] <= r32[edi])
        { pc = 0x40abfe; break; }
  case 0x40ac09: // 0000:40ac09
    r32[ecx]++;
    r32[ecx]++;
    if (memoryAGet(ds, r32[ecx]))
        { pc = 0x40abe4; break; }
  case 0x40ac10: // 0000:40ac10
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) + 1);
    r32[ebx] += 0x00000008;
    if (memoryAGet32(ss, r32[ebp] - 4) < 0x00000004)
        { pc = 0x40abdd; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x8);
    memoryASet32(ds, 0x42be1c, 0x00000001);
    push32(r32[eax]);
    memoryASet32(ds, 0x42be04, r32[eax]);
    yield* sub_40acfa();
    r32[esi] = r32[esi] + 4257036;
    r32[edi] = 0x0042be10;
    movsd_ESEDI_DSESI();
    movsd_ESEDI_DSESI();
    r32[ecx] = pop32();
    memoryASet32(ds, 0x42c024, r32[eax]);
    movsd_ESEDI_DSESI();
    { pc = 0x40ac9f; break; }
  case 0x40ac4a: // 0000:40ac4a
    r32[ecx]++;
    r32[ecx]++;
    if (memoryAGet(ds, r32[ecx] - 1))
        { pc = 0x40ab9e; break; }
  case 0x40ac56: // 0000:40ac56
    push32(0x00000001);
    r32[eax] = pop32();
  case 0x40ac59: // 0000:40ac59
    memoryASet(ds, r32[eax] + 0x42bf21, memoryAGet(ds, r32[eax] + 0x42bf21) | 0x08);
    r32[eax]++;
    if (r32[eax] < 0x000000ff)
        { pc = 0x40ac59; break; }
    push32(r32[esi]);
    yield* sub_40acfa();
    r32[ecx] = pop32();
    memoryASet32(ds, 0x42c024, r32[eax]);
    memoryASet32(ds, 0x42be1c, 0x00000001);
    { pc = 0x40ac86; break; }
  case 0x40ac80: // 0000:40ac80
    memoryASet32(ds, 0x42be1c, r32[ebx]);
  case 0x40ac86: // 0000:40ac86
    r32[eax] = 0;
    r32[edi] = 0x0042be10;
    stosd_ESEDI(r32[eax]);
    stosd_ESEDI(r32[eax]);
    stosd_ESEDI(r32[eax]);
    { pc = 0x40ac9f; break; }
  case 0x40ac92: // 0000:40ac92
    if (memoryAGet32(ds, 0x40fc74) == r32[ebx])
        { pc = 0x40aca8; break; }
  case 0x40ac9a: // 0000:40ac9a
    yield* sub_40ad2d();
  case 0x40ac9f: // 0000:40ac9f
    yield* sub_40ad56();
  case 0x40aca4: // 0000:40aca4
    r32[eax] = 0;
    { pc = 0x40acab; break; }
  case 0x40aca8: // 0000:40aca8
    r32[eax] |= 0xffffffff;
  case 0x40acab: // 0000:40acab
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_40acb0() // 0000:40acb0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(ds, 0x40fc74, memoryAGet32(ds, 0x40fc74) & 0x00000000);
    if (r32[eax] != 0xfffffffe)
        { pc = 0x40acd0; break; }
    memoryASet32(ds, 0x40fc74, 0x00000001);
    indirectJump(cs, memoryAGet32(ds, 0x40d024)); return; // 0000:40acca
  case 0x40acd0: // 0000:40acd0
    if (r32[eax] != 0xfffffffd)
        { pc = 0x40ace5; break; }
    memoryASet32(ds, 0x40fc74, 0x00000001);
    indirectJump(cs, memoryAGet32(ds, 0x40d028)); return; // 0000:40acdf
  case 0x40ace5: // 0000:40ace5
    if (r32[eax] != 0xfffffffc)
        { pc = 0x40acf9; break; }
    r32[eax] = memoryAGet32(ds, 0x40fca4);
    memoryASet32(ds, 0x40fc74, 0x00000001);
  case 0x40acf9: // 0000:40acf9
    r32[esp] += 4; return;
    return;
  }
}
function* sub_40acfa() // 0000:40acfa +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] -= 0x000003a4;
    if (!r32[eax])
        { pc = 0x40ad27; break; }
    r32[eax] -= 0x00000004;
    if (!r32[eax])
        { pc = 0x40ad21; break; }
    r32[eax] -= 0x0000000d;
    if (!r32[eax])
        { pc = 0x40ad1b; break; }
    r32[eax]--;
    if (!r32[eax])
        { pc = 0x40ad15; break; }
    r32[eax] = 0;
    r32[esp] += 4; return;
  case 0x40ad15: // 0000:40ad15
    r32[eax] = 0x00000404;
    r32[esp] += 4; return;
  case 0x40ad1b: // 0000:40ad1b
    r32[eax] = 0x00000412;
    r32[esp] += 4; return;
  case 0x40ad21: // 0000:40ad21
    r32[eax] = 0x00000804;
    r32[esp] += 4; return;
  case 0x40ad27: // 0000:40ad27
    r32[eax] = 0x00000411;
    r32[esp] += 4;
    return;
  }
}
function* sub_40ad2d() // 0000:40ad2d +long
{
    r32[esp] -= 4;
    push32(r32[edi]);
    push32(0x00000040);
    r32[ecx] = pop32();
    r32[eax] = 0;
    r32[edi] = 0x0042bf20;
    for (; r32[ecx] != 0; --r32[ecx]) stosd_ESEDI(r32[eax]);
    stosb_ESEDI(r8[al]);
    r32[eax] = 0;
    r32[edi] = 0x0042be10;
    memoryASet32(ds, 0x42be04, r32[eax]);
    memoryASet32(ds, 0x42be1c, r32[eax]);
    memoryASet32(ds, 0x42c024, r32[eax]);
    stosd_ESEDI(r32[eax]);
    stosd_ESEDI(r32[eax]);
    stosd_ESEDI(r32[eax]);
    r32[edi] = pop32();
    r32[esp] += 4;
}
function* sub_40ad56() // 0000:40ad56 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] -= 0x00000514;
    r32[eax] = r32[ebp] - 20;
    push32(r32[esi]);
    push32(r32[eax]);
    push32(memoryAGet32(ds, 0x42be04));
    r32[eax] = kernel32.GetCPInfo(stack32(0), stack32(1)); r32[esp] += 8;
    if (r32[eax] != 0x00000001)
        { pc = 0x40ae8f; break; }
    r32[eax] = 0;
    r32[esi] = 0x00000100;
  case 0x40ad80: // 0000:40ad80
    memoryASet(ss, r32[ebp] + r32[eax] - 276, r8[al]);
    r32[eax]++;
    if (r32[eax] < r32[esi])
        { pc = 0x40ad80; break; }
    r8[al] = memoryAGet(ss, r32[ebp] - 14);
    memoryASet(ss, r32[ebp] - 276, 0x20);
    if (!r8[al])
        { pc = 0x40add1; break; }
    push32(r32[ebx]);
    push32(r32[edi]);
    r32[edx] = r32[ebp] - 13;
  case 0x40ad9f: // 0000:40ad9f
    r32[ecx] = memoryAGet(ds, r32[edx]);
    r32[eax] = r8[al];
    if (r32[eax] > r32[ecx])
        { pc = 0x40adc6; break; }
    r32[ecx] -= r32[eax];
    r32[edi] = (r32[ebp] + r32[eax]) + -276;
    r32[ecx]++;
    r32[eax] = 0x20202020;
    r32[ebx] = r32[ecx];
    r32[ecx] >>= 2;
    for (; r32[ecx] != 0; --r32[ecx]) stosd_ESEDI(r32[eax]);
    r32[ecx] = r32[ebx];
    r32[ecx] &= 0x00000003;
    for (; r32[ecx] != 0; --r32[ecx]) stosb_ESEDI(r8[al]);
  case 0x40adc6: // 0000:40adc6
    r32[edx]++;
    r32[edx]++;
    r8[al] = memoryAGet(ds, r32[edx] - 1);
    if (r8[al])
        { pc = 0x40ad9f; break; }
    r32[edi] = pop32();
    r32[ebx] = pop32();
  case 0x40add1: // 0000:40add1
    push32(0x00000000);
    r32[eax] = r32[ebp] - 1300;
    push32(memoryAGet32(ds, 0x42c024));
    push32(memoryAGet32(ds, 0x42be04));
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 276;
    push32(r32[esi]);
    push32(r32[eax]);
    push32(0x00000001);
    yield* sub_40b07e();
    push32(0x00000000);
    r32[eax] = r32[ebp] - 532;
    push32(memoryAGet32(ds, 0x42be04));
    push32(r32[esi]);
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 276;
    push32(r32[esi]);
    push32(r32[eax]);
    push32(r32[esi]);
    push32(memoryAGet32(ds, 0x42c024));
    yield* sub_40b1c7();
    push32(0x00000000);
    r32[eax] = r32[ebp] - 788;
    push32(memoryAGet32(ds, 0x42be04));
    push32(r32[esi]);
    push32(r32[eax]);
    r32[eax] = r32[ebp] - 276;
    push32(r32[esi]);
    push32(r32[eax]);
    push32(0x00000200);
    push32(memoryAGet32(ds, 0x42c024));
    yield* sub_40b1c7();
    r32[esp] += 0x0000005c;
    r32[eax] = 0;
    r32[ecx] = r32[ebp] - 1300;
  case 0x40ae4c: // 0000:40ae4c
    r16[dx] = memoryAGet16(ds, r32[ecx]);
    if (!(r8[dl] & 0x01))
        { pc = 0x40ae6a; break; }
    memoryASet(ds, r32[eax] + 0x42bf21, memoryAGet(ds, r32[eax] + 0x42bf21) | 0x10);
    r8[dl] = memoryAGet(ss, r32[ebp] + r32[eax] - 532);
  case 0x40ae62: // 0000:40ae62
    memoryASet(ds, r32[eax] + 0x42be20, r8[dl]);
    { pc = 0x40ae86; break; }
  case 0x40ae6a: // 0000:40ae6a
    if (!(r8[dl] & 0x02))
        { pc = 0x40ae7f; break; }
    memoryASet(ds, r32[eax] + 0x42bf21, memoryAGet(ds, r32[eax] + 0x42bf21) | 0x20);
    r8[dl] = memoryAGet(ss, r32[ebp] + r32[eax] - 788);
    { pc = 0x40ae62; break; }
  case 0x40ae7f: // 0000:40ae7f
    memoryASet(ds, r32[eax] + 0x42be20, memoryAGet(ds, r32[eax] + 0x42be20) & 0x00);
  case 0x40ae86: // 0000:40ae86
    r32[eax]++;
    r32[ecx]++;
    r32[ecx]++;
    if (r32[eax] < r32[esi])
        { pc = 0x40ae4c; break; }
    { pc = 0x40aed8; break; }
  case 0x40ae8f: // 0000:40ae8f
    r32[eax] = 0;
    r32[esi] = 0x00000100;
  case 0x40ae96: // 0000:40ae96
    if (r32[eax] < 0x00000041)
        { pc = 0x40aeb4; break; }
    if (r32[eax] > 0x0000005a)
        { pc = 0x40aeb4; break; }
    memoryASet(ds, r32[eax] + 0x42bf21, memoryAGet(ds, r32[eax] + 0x42bf21) | 0x10);
    r8[cl] = r8[al];
    r8[cl] += 0x20;
  case 0x40aeac: // 0000:40aeac
    memoryASet(ds, r32[eax] + 0x42be20, r8[cl]);
    { pc = 0x40aed3; break; }
  case 0x40aeb4: // 0000:40aeb4
    if (r32[eax] < 0x00000061)
        { pc = 0x40aecc; break; }
    if (r32[eax] > 0x0000007a)
        { pc = 0x40aecc; break; }
    memoryASet(ds, r32[eax] + 0x42bf21, memoryAGet(ds, r32[eax] + 0x42bf21) | 0x20);
    r8[cl] = r8[al];
    r8[cl] -= 0x20;
    { pc = 0x40aeac; break; }
  case 0x40aecc: // 0000:40aecc
    memoryASet(ds, r32[eax] + 0x42be20, memoryAGet(ds, r32[eax] + 0x42be20) & 0x00);
  case 0x40aed3: // 0000:40aed3
    r32[eax]++;
    if (r32[eax] < r32[esi])
        { pc = 0x40ae96; break; }
  case 0x40aed8: // 0000:40aed8
    r32[esi] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_40aedb() // 0000:40aedb +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    if (memoryAGet32(ds, 0x42d188))
        { pc = 0x40aef6; break; }
    push32(0xfffffffd);
    yield* sub_40ab17();
    r32[ecx] = pop32();
    memoryASet32(ds, 0x42d188, 0x00000001);
  case 0x40aef6: // 0000:40aef6
    r32[esp] += 4; return;
    return;
  }
}
function* sub_40aef7() // 0000:40aef7 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    r32[ebx] = 0;
    push32(r32[esi]);
    push32(r32[edi]);
    if (memoryAGet32(ds, 0x40fc78) != r32[ebx])
        { pc = 0x40af46; break; }
    push32(0x0040d708);
    r32[eax] = kernel32.LoadLibraryA(stack32(0)); r32[esp] += 4;
    r32[edi] = r32[eax];
    if (r32[edi] == r32[ebx])
        { pc = 0x40af7c; break; }
    r32[esi] = memoryAGet32(ds, 0x40d068);
    push32(0x0040d6fc);
    push32(r32[edi]);
    yield* indirectCall(cs, r32[esi]);
    memoryASet32(ds, 0x40fc78, r32[eax]);
    if (!r32[eax])
        { pc = 0x40af7c; break; }
    push32(0x0040d6ec);
    push32(r32[edi]);
    yield* indirectCall(cs, r32[esi]);
    push32(0x0040d6d8);
    push32(r32[edi]);
    memoryASet32(ds, 0x40fc7c, r32[eax]);
    yield* indirectCall(cs, r32[esi]);
    memoryASet32(ds, 0x40fc80, r32[eax]);
  case 0x40af46: // 0000:40af46
    r32[eax] = memoryAGet32(ds, 0x40fc7c);
    if (!r32[eax])
        { pc = 0x40af65; break; }
    yield* indirectCall(cs, r32[eax]);
    r32[ebx] = r32[eax];
    if (!r32[ebx])
        { pc = 0x40af65; break; }
    r32[eax] = memoryAGet32(ds, 0x40fc80);
    if (!r32[eax])
        { pc = 0x40af65; break; }
    push32(r32[ebx]);
    yield* indirectCall(cs, r32[eax]);
    r32[ebx] = r32[eax];
  case 0x40af65: // 0000:40af65
    push32(memoryAGet32(ds, r32[esp] + 0x18));
    push32(memoryAGet32(ds, r32[esp] + 0x18));
    push32(memoryAGet32(ds, r32[esp] + 0x18));
    push32(r32[ebx]);
    yield* indirectCall(cs, memoryAGet32(ds, 0x40fc78));
  case 0x40af78: // 0000:40af78
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4; return;
  case 0x40af7c: // 0000:40af7c
    r32[eax] = 0;
    { pc = 0x40af78; break; }
    return;
  }
}
function* sub_40af80() // 0000:40af80 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    push32(r32[edi]);
    if (!r32[ecx])
        { pc = 0x40b003; break; }
    push32(r32[esi]);
    push32(r32[ebx]);
    r32[ebx] = r32[ecx];
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x10);
    if (r32[esi] & 0x00000003)
        { pc = 0x40afa4; break; }
    r32[ecx] >>= 2;
    if (r32[ecx])
        { pc = 0x40b011; break; }
    { pc = 0x40afc5; break; }
  case 0x40afa4: // 0000:40afa4
    r8[al] = memoryAGet(ds, r32[esi]);
    r32[esi]++;
    memoryASet(ds, r32[edi], r8[al]);
    r32[edi]++;
    r32[ecx]--;
    if (!r32[ecx])
        { pc = 0x40afd2; break; }
    if (!r8[al])
        { pc = 0x40afda; break; }
    if (r32[esi] & 0x00000003)
        { pc = 0x40afa4; break; }
    r32[ebx] = r32[ecx];
    r32[ecx] >>= 2;
    if (r32[ecx])
        { pc = 0x40b011; break; }
  case 0x40afc0: // 0000:40afc0
    r32[ebx] &= 0x00000003;
    if (!r32[ebx])
        { pc = 0x40afd2; break; }
  case 0x40afc5: // 0000:40afc5
    r8[al] = memoryAGet(ds, r32[esi]);
    r32[esi]++;
    memoryASet(ds, r32[edi], r8[al]);
    r32[edi]++;
    if (!r8[al])
        { pc = 0x40affe; break; }
    r32[ebx]--;
    if (r32[ebx])
        { pc = 0x40afc5; break; }
  case 0x40afd2: // 0000:40afd2
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[ebx] = pop32();
    r32[esi] = pop32();
    r32[edi] = pop32();
    r32[esp] += 4; return;
  case 0x40afda: // 0000:40afda
    if (!(r32[edi] & 0x00000003))
        { pc = 0x40aff4; break; }
  case 0x40afe2: // 0000:40afe2
    memoryASet(ds, r32[edi], r8[al]);
    r32[edi]++;
    r32[ecx]--;
    if (!r32[ecx])
        { pc = 0x40b076; break; }
    if (r32[edi] & 0x00000003)
        { pc = 0x40afe2; break; }
  case 0x40aff4: // 0000:40aff4
    r32[ebx] = r32[ecx];
    r32[ecx] >>= 2;
    if (r32[ecx])
        { pc = 0x40b067; break; }
  case 0x40affb: // 0000:40affb
    memoryASet(ds, r32[edi], r8[al]);
    r32[edi]++;
  case 0x40affe: // 0000:40affe
    r32[ebx]--;
    if (r32[ebx])
        { pc = 0x40affb; break; }
    r32[ebx] = pop32();
    r32[esi] = pop32();
  case 0x40b003: // 0000:40b003
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edi] = pop32();
    r32[esp] += 4; return;
  case 0x40b009: // 0000:40b009
    memoryASet32(ds, r32[edi], r32[edx]);
    r32[edi] += 0x00000004;
    r32[ecx]--;
    if (!r32[ecx])
        { pc = 0x40afc0; break; }
  case 0x40b011: // 0000:40b011
    r32[edx] = 0x7efefeff;
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[edx] += r32[eax];
    r32[eax] ^= 0xffffffff;
    r32[eax] ^= r32[edx];
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[esi] += 0x00000004;
    if (!(r32[eax] & 0x81010100))
        { pc = 0x40b009; break; }
    if (!r8[dl])
        { pc = 0x40b05b; break; }
    if (!r8[dh])
        { pc = 0x40b051; break; }
    if (!(r32[edx] & 0x00ff0000))
        { pc = 0x40b047; break; }
    if (r32[edx] & 0xff000000)
        { pc = 0x40b009; break; }
    memoryASet32(ds, r32[edi], r32[edx]);
    { pc = 0x40b05f; break; }
  case 0x40b047: // 0000:40b047
    r32[edx] &= 0x0000ffff;
    memoryASet32(ds, r32[edi], r32[edx]);
    { pc = 0x40b05f; break; }
  case 0x40b051: // 0000:40b051
    r32[edx] &= 0x000000ff;
    memoryASet32(ds, r32[edi], r32[edx]);
    { pc = 0x40b05f; break; }
  case 0x40b05b: // 0000:40b05b
    r32[edx] = 0;
    memoryASet32(ds, r32[edi], r32[edx]);
  case 0x40b05f: // 0000:40b05f
    r32[edi] += 0x00000004;
    r32[eax] = 0;
    r32[ecx]--;
    if (!r32[ecx])
        { pc = 0x40b071; break; }
  case 0x40b067: // 0000:40b067
    r32[eax] = 0;
  case 0x40b069: // 0000:40b069
    memoryASet32(ds, r32[edi], r32[eax]);
    r32[edi] += 0x00000004;
    r32[ecx]--;
    if (r32[ecx])
        { pc = 0x40b069; break; }
  case 0x40b071: // 0000:40b071
    r32[ebx] &= 0x00000003;
    if (r32[ebx])
        { pc = 0x40affb; break; }
  case 0x40b076: // 0000:40b076
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[ebx] = pop32();
    r32[esi] = pop32();
    r32[edi] = pop32();
    r32[esp] += 4;
    return;
  }
}
function* sub_40b07e() // 0000:40b07e +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(0xffffffff);
    push32(0x0040d720);
    push32(0x00409328);
    //r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    //memoryASet32(fs, 0x0, r32[esp]);
    r32[esp] -= 0x00000018;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    memoryASet32(ss, r32[ebp] - 24, r32[esp]);
    r32[eax] = memoryAGet32(ds, 0x40fc84);
    r32[ebx] = 0;
    if (r32[eax] != r32[ebx])
        { pc = 0x40b0ed; break; }
    r32[eax] = r32[ebp] - 28;
    push32(r32[eax]);
    push32(0x00000001);
    r32[esi] = pop32();
    push32(r32[esi]);
    push32(0x0040d718);
    push32(r32[esi]);
    r32[eax] = kernel32.GetStringTypeW(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
    if (!r32[eax])
        { pc = 0x40b0cb; break; }
    r32[eax] = r32[esi];
    { pc = 0x40b0e8; break; }
  case 0x40b0cb: // 0000:40b0cb
    r32[eax] = r32[ebp] - 28;
    push32(r32[eax]);
    push32(r32[esi]);
    push32(0x0040d714);
    push32(r32[esi]);
    push32(r32[ebx]);
    r32[eax] = kernel32.GetStringTypeA(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4)); r32[esp] += 20;
    if (!r32[eax])
        { pc = 0x40b1b3; break; }
    push32(0x00000002);
    r32[eax] = pop32();
  case 0x40b0e8: // 0000:40b0e8
    memoryASet32(ds, 0x40fc84, r32[eax]);
  case 0x40b0ed: // 0000:40b0ed
    if (r32[eax] != 0x00000002)
        { pc = 0x40b116; break; }
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x1c);
    if (r32[eax] != r32[ebx])
        { pc = 0x40b0fe; break; }
    r32[eax] = memoryAGet32(ds, 0x40fc94);
  case 0x40b0fe: // 0000:40b0fe
    push32(memoryAGet32(ss, r32[ebp] + 0x14));
    push32(memoryAGet32(ss, r32[ebp] + 0x10));
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    push32(r32[eax]);
    r32[eax] = kernel32.GetStringTypeA(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4)); r32[esp] += 20;
    { pc = 0x40b1b5; break; }
  case 0x40b116: // 0000:40b116
    if (r32[eax] != 0x00000001)
        { pc = 0x40b1b3; break; }
    if (memoryAGet32(ss, r32[ebp] + 0x18) != r32[ebx])
        { pc = 0x40b12c; break; }
    r32[eax] = memoryAGet32(ds, 0x40fca4);
    memoryASet32(ss, r32[ebp] + 0x18, r32[eax]);
  case 0x40b12c: // 0000:40b12c
    push32(r32[ebx]);
    push32(r32[ebx]);
    push32(memoryAGet32(ss, r32[ebp] + 0x10));
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x20);
    flags.carry = r32[eax] != 0;
    r32[eax] = -r32[eax];
    r32[eax] = -flags.carry;
    r32[eax] &= 0x00000008;
    r32[eax]++;
    push32(r32[eax]);
    push32(memoryAGet32(ss, r32[ebp] + 0x18));
    r32[eax] = kernel32.MultiByteToWideChar(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
    memoryASet32(ss, r32[ebp] - 32, r32[eax]);
    if (r32[eax] == r32[ebx])
        { pc = 0x40b1b3; break; }
    memoryASet32(ss, r32[ebp] - 4, r32[ebx]);
    r32[edi] = r32[eax] + r32[eax];
    r32[eax] = r32[edi];
    r32[eax] += 0x00000003;
    r8[al] &= 0xfc;
    yield* sub_40c020();
    memoryASet32(ss, r32[ebp] - 24, r32[esp]);
    r32[esi] = r32[esp];
    memoryASet32(ss, r32[ebp] - 36, r32[esi]);
    push32(r32[edi]);
    push32(r32[ebx]);
    push32(r32[esi]);
    yield* sub_40a530();
    r32[esp] += 0x0000000c;
    { pc = 0x40b182; break; }
    // gap 11 bytes // gap 11 bytes
  case 0x40b182: // 0000:40b182
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0xffffffff);
    if (r32[esi] == r32[ebx])
        { pc = 0x40b1b3; break; }
    push32(memoryAGet32(ss, r32[ebp] - 32));
    push32(r32[esi]);
    push32(memoryAGet32(ss, r32[ebp] + 0x10));
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    push32(0x00000001);
    push32(memoryAGet32(ss, r32[ebp] + 0x18));
    r32[eax] = kernel32.MultiByteToWideChar(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
    if (r32[eax] == r32[ebx])
        { pc = 0x40b1b3; break; }
    push32(memoryAGet32(ss, r32[ebp] + 0x14));
    push32(r32[eax]);
    push32(r32[esi]);
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    r32[eax] = kernel32.GetStringTypeW(stack32(0), stack32(1), stack32(2), stack32(3)); r32[esp] += 16;
    { pc = 0x40b1b5; break; }
  case 0x40b1b3: // 0000:40b1b3
    r32[eax] = 0;
  case 0x40b1b5: // 0000:40b1b5
    r32[esp] = r32[ebp] - 52;
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 16);
    //memoryASet32(fs, 0x0, r32[ecx]);
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function* sub_40b1c7() // 0000:40b1c7 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(0xffffffff);
    push32(0x0040d730);
    push32(0x00409328);
    //r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    //memoryASet32(fs, 0x0, r32[esp]);
    r32[esp] -= 0x0000001c;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    memoryASet32(ss, r32[ebp] - 24, r32[esp]);
    r32[edi] = 0;
    if (memoryAGet32(ds, 0x40fc88) != r32[edi])
        { pc = 0x40b23d; break; }
    push32(r32[edi]);
    push32(r32[edi]);
    push32(0x00000001);
    r32[ebx] = pop32();
    push32(r32[ebx]);
    push32(0x0040d718);
    r32[esi] = 0x00000100;
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = kernel32.LCMapStringW(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
    if (!r32[eax])
        { pc = 0x40b21b; break; }
    memoryASet32(ds, 0x40fc88, r32[ebx]);
    { pc = 0x40b23d; break; }
  case 0x40b21b: // 0000:40b21b
    push32(r32[edi]);
    push32(r32[edi]);
    push32(r32[ebx]);
    push32(0x0040d714);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = kernel32.LCMapStringA(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
    if (!r32[eax])
        { pc = 0x40b355; break; }
    memoryASet32(ds, 0x40fc88, 0x00000002);
  case 0x40b23d: // 0000:40b23d
    if (signed32(memoryAGet32(ss, r32[ebp] + 0x14)) <= r32s[edi])
        { pc = 0x40b252; break; }
    push32(memoryAGet32(ss, r32[ebp] + 0x14));
    push32(memoryAGet32(ss, r32[ebp] + 0x10));
    yield* sub_40b3eb();
    r32[ecx] = pop32();
    r32[ecx] = pop32();
    memoryASet32(ss, r32[ebp] + 0x14, r32[eax]);
  case 0x40b252: // 0000:40b252
    r32[eax] = memoryAGet32(ds, 0x40fc88);
    if (r32[eax] != 0x00000002)
        { pc = 0x40b279; break; }
    push32(memoryAGet32(ss, r32[ebp] + 0x1c));
    push32(memoryAGet32(ss, r32[ebp] + 0x18));
    push32(memoryAGet32(ss, r32[ebp] + 0x14));
    push32(memoryAGet32(ss, r32[ebp] + 0x10));
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    r32[eax] = kernel32.LCMapStringA(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
    { pc = 0x40b357; break; }
  case 0x40b279: // 0000:40b279
    if (r32[eax] != 0x00000001)
        { pc = 0x40b355; break; }
    if (memoryAGet32(ss, r32[ebp] + 0x20) != r32[edi])
        { pc = 0x40b28f; break; }
    r32[eax] = memoryAGet32(ds, 0x40fca4);
    memoryASet32(ss, r32[ebp] + 0x20, r32[eax]);
  case 0x40b28f: // 0000:40b28f
    push32(r32[edi]);
    push32(r32[edi]);
    push32(memoryAGet32(ss, r32[ebp] + 0x14));
    push32(memoryAGet32(ss, r32[ebp] + 0x10));
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0x24);
    flags.carry = r32[eax] != 0;
    r32[eax] = -r32[eax];
    r32[eax] = -flags.carry;
    r32[eax] &= 0x00000008;
    r32[eax]++;
    push32(r32[eax]);
    push32(memoryAGet32(ss, r32[ebp] + 0x20));
    r32[eax] = kernel32.MultiByteToWideChar(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
    r32[ebx] = r32[eax];
    memoryASet32(ss, r32[ebp] - 28, r32[ebx]);
    if (r32[ebx] == r32[edi])
        { pc = 0x40b355; break; }
    memoryASet32(ss, r32[ebp] - 4, r32[edi]);
    r32[eax] = r32[ebx] + r32[ebx];
    r32[eax] += 0x00000003;
    r8[al] &= 0xfc;
    yield* sub_40c020();
    memoryASet32(ss, r32[ebp] - 24, r32[esp]);
    r32[eax] = r32[esp];
    memoryASet32(ss, r32[ebp] - 36, r32[eax]);
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0xffffffff);
    { pc = 0x40b2ea; break; }
    // gap 19 bytes // gap 19 bytes
  case 0x40b2ea: // 0000:40b2ea
    if (memoryAGet32(ss, r32[ebp] - 36) == r32[edi])
        { pc = 0x40b355; break; }
    push32(r32[ebx]);
    push32(memoryAGet32(ss, r32[ebp] - 36));
    push32(memoryAGet32(ss, r32[ebp] + 0x14));
    push32(memoryAGet32(ss, r32[ebp] + 0x10));
    push32(0x00000001);
    push32(memoryAGet32(ss, r32[ebp] + 0x20));
    r32[eax] = kernel32.MultiByteToWideChar(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
    if (!r32[eax])
        { pc = 0x40b355; break; }
    push32(r32[edi]);
    push32(r32[edi]);
    push32(r32[ebx]);
    push32(memoryAGet32(ss, r32[ebp] - 36));
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    r32[eax] = kernel32.LCMapStringW(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
    r32[esi] = r32[eax];
    memoryASet32(ss, r32[ebp] - 40, r32[esi]);
    if (r32[esi] == r32[edi])
        { pc = 0x40b355; break; }
    if (!(memoryAGet(ss, r32[ebp] + 0xd) & 0x04))
        { pc = 0x40b369; break; }
    if (memoryAGet32(ss, r32[ebp] + 0x1c) == r32[edi])
        { pc = 0x40b3e4; break; }
    if (r32s[esi] > signed32(memoryAGet32(ss, r32[ebp] + 0x1c)))
        { pc = 0x40b355; break; }
    push32(memoryAGet32(ss, r32[ebp] + 0x1c));
    push32(memoryAGet32(ss, r32[ebp] + 0x18));
    push32(r32[ebx]);
    push32(memoryAGet32(ss, r32[ebp] - 36));
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    r32[eax] = kernel32.LCMapStringW(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
    if (r32[eax])
        { pc = 0x40b3e4; break; }
  case 0x40b355: // 0000:40b355
    r32[eax] = 0;
  case 0x40b357: // 0000:40b357
    r32[esp] = r32[ebp] - 56;
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 16);
    //memoryASet32(fs, 0x0, r32[ecx]);
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4; return;
  case 0x40b369: // 0000:40b369
    memoryASet32(ss, r32[ebp] - 4, 0x00000001);
    r32[eax] = r32[esi] + r32[esi];
    r32[eax] += 0x00000003;
    r8[al] &= 0xfc;
    yield* sub_40c020();
    memoryASet32(ss, r32[ebp] - 24, r32[esp]);
    r32[ebx] = r32[esp];
    memoryASet32(ss, r32[ebp] - 32, r32[ebx]);
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0xffffffff);
    { pc = 0x40b39d; break; }
    // gap 18 bytes // gap 18 bytes
  case 0x40b39d: // 0000:40b39d
    if (r32[ebx] == r32[edi])
        { pc = 0x40b355; break; }
    push32(r32[esi]);
    push32(r32[ebx]);
    push32(memoryAGet32(ss, r32[ebp] - 28));
    push32(memoryAGet32(ss, r32[ebp] - 36));
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    r32[eax] = kernel32.LCMapStringW(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5)); r32[esp] += 24;
    if (!r32[eax])
        { pc = 0x40b355; break; }
    push32(r32[edi]);
    push32(r32[edi]);
    if (memoryAGet32(ss, r32[ebp] + 0x1c) != r32[edi])
        { pc = 0x40b3c4; break; }
    push32(r32[edi]);
    push32(r32[edi]);
    { pc = 0x40b3ca; break; }
  case 0x40b3c4: // 0000:40b3c4
    push32(memoryAGet32(ss, r32[ebp] + 0x1c));
    push32(memoryAGet32(ss, r32[ebp] + 0x18));
  case 0x40b3ca: // 0000:40b3ca
    push32(r32[esi]);
    push32(r32[ebx]);
    push32(0x00000220);
    push32(memoryAGet32(ss, r32[ebp] + 0x20));
    r32[eax] = kernel32.WideCharToMultiByte(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4), stack32(5), stack32(6), stack32(7)); r32[esp] += 32;
    r32[esi] = r32[eax];
    if (r32[esi] == r32[edi])
        { pc = 0x40b355; break; }
  case 0x40b3e4: // 0000:40b3e4
    r32[eax] = r32[esi];
    { pc = 0x40b357; break; }
    return;
  }
}
function* sub_40b3eb() // 0000:40b3eb +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[esi]);
    r32[ecx] = r32[edx] - 1;
    if (!r32[edx])
        { pc = 0x40b408; break; }
  case 0x40b3fb: // 0000:40b3fb
    if (!memoryAGet(ds, r32[eax]))
        { pc = 0x40b408; break; }
    r32[eax]++;
    r32[esi] = r32[ecx];
    r32[ecx]--;
    if (r32[esi])
        { pc = 0x40b3fb; break; }
  case 0x40b408: // 0000:40b408
    r32[esi] = pop32();
    if (memoryAGet(ds, r32[eax]))
        { pc = 0x40b413; break; }
    r32[eax] -= memoryAGet32(ds, r32[esp] + 0x4);
    r32[esp] += 4; return;
  case 0x40b413: // 0000:40b413
    r32[eax] = r32[edx];
    r32[esp] += 4;
    return;
  }
}
function* sub_40bd1b() // 0000:40bd1b +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[edx] = 0;
    memoryASet32(ds, 0x40fabc, r32[ecx]);
    r32[eax] = 0x0040f600;
  case 0x40bd2c: // 0000:40bd2c
    if (r32[ecx] == memoryAGet32(ds, r32[eax]))
        { pc = 0x40bd50; break; }
    r32[eax] += 0x00000008;
    r32[edx]++;
    if (r32s[eax] < signed32(0x0040f768))
        { pc = 0x40bd2c; break; }
    if (r32[ecx] < 0x00000013)
        { pc = 0x40bd5d; break; }
    if (r32[ecx] > 0x00000024)
        { pc = 0x40bd5d; break; }
    memoryASet32(ds, 0x40fab8, 0x0000000d);
    r32[esp] += 4; return;
  case 0x40bd50: // 0000:40bd50
    r32[eax] = memoryAGet32(ds, r32[edx] * 8 + 0x40f604);
    memoryASet32(ds, 0x40fab8, r32[eax]);
    r32[esp] += 4; return;
  case 0x40bd5d: // 0000:40bd5d
    if (r32[ecx] < 0x000000bc)
        { pc = 0x40bd77; break; }
    memoryASet32(ds, 0x40fab8, 0x00000008);
    if (r32[ecx] <= 0x000000ca)
        { pc = 0x40bd81; break; }
  case 0x40bd77: // 0000:40bd77
    memoryASet32(ds, 0x40fab8, 0x00000016);
  case 0x40bd81: // 0000:40bd81
    r32[esp] += 4; return;
    return;
  }
}
function* sub_40bdfc() // 0000:40bdfc +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    if (r32[eax] >= memoryAGet32(ds, 0x42d160))
        { pc = 0x40be24; break; }
    r32[ecx] = r32[eax];
    r32[eax] &= 0x0000001f;
    r32[ecx] = sar32(r32[ecx], 0x05);
    r32[ecx] = memoryAGet32(ds, r32[ecx] * 4 + 0x42d060);
    flags.zero = !(memoryAGet(ds, r32[ecx] + r32[eax] * 8 + 0x4) & 0x01);
    r32[eax] = r32[ecx] + (r32[eax] * 8);
    if (flags.zero)
        { pc = 0x40be24; break; }
    r32[eax] = memoryAGet32(ds, r32[eax]);
    r32[esp] += 4; return;
  case 0x40be24: // 0000:40be24
    memoryASet32(ds, 0x40fabc, memoryAGet32(ds, 0x40fabc) & 0x00000000);
    memoryASet32(ds, 0x40fab8, 0x00000009);
    r32[eax] |= 0xffffffff;
    r32[esp] += 4;
    return;
  }
}
function* sub_40be39() // 0000:40be39 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0xc);
    push32(r32[edi]);
    r32[esi] = r32s[esi] * (signed32(memoryAGet32(ds, r32[esp] + 0x14)));
    r32[ebx] = r32[esi];
    if (r32[esi] > 0xffffffe0)
        { pc = 0x40be59; break; }
    if (r32[esi])
        { pc = 0x40be53; break; }
    push32(0x00000001);
    r32[esi] = pop32();
  case 0x40be53: // 0000:40be53
    r32[esi] += 0x0000000f;
    r32[esi] &= 0xfffffff0;
  case 0x40be59: // 0000:40be59
    r32[edi] = 0;
    if (r32[esi] > 0xffffffe0)
        { pc = 0x40be8a; break; }
    if (r32[ebx] > memoryAGet32(ds, 0x40eed4))
        { pc = 0x40be75; break; }
    push32(r32[ebx]);
    yield* sub_4073a7();
    r32[edi] = r32[eax];
    r32[ecx] = pop32();
    if (r32[edi])
        { pc = 0x40bea0; break; }
  case 0x40be75: // 0000:40be75
    push32(r32[esi]);
    push32(0x00000008);
    push32(memoryAGet32(ds, 0x42d17c));
    r32[eax] = kernel32.HeapAlloc(stack32(0), stack32(1), stack32(2)); r32[esp] += 12;
    r32[edi] = r32[eax];
    if (r32[edi])
        { pc = 0x40beac; break; }
  case 0x40be8a: // 0000:40be8a
    if (!memoryAGet32(ds, 0x40fb18))
        { pc = 0x40beac; break; }
    push32(r32[esi]);
    yield* sub_406fbc();
    r32[ecx] = pop32();
    if (!r32[eax])
        { pc = 0x40beb2; break; }
    { pc = 0x40be59; break; }
  case 0x40bea0: // 0000:40bea0
    push32(r32[ebx]);
    push32(0x00000000);
    push32(r32[edi]);
    yield* sub_40a530();
    r32[esp] += 0x0000000c;
  case 0x40beac: // 0000:40beac
    r32[eax] = r32[edi];
  case 0x40beae: // 0000:40beae
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 4; return;
  case 0x40beb2: // 0000:40beb2
    r32[eax] = 0;
    { pc = 0x40beae; break; }
    return;
  }
}
function* sub_40c020() // 0000:40c020 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ecx]);
    r32[ecx] = r32[esp] + 8;
    if (r32[eax] < 0x00001000)
        { pc = 0x40c040; break; }
  case 0x40c02c: // 0000:40c02c
    r32[ecx] -= 0x00001000;
    r32[eax] -= 0x00001000;
    if (r32[eax] >= 0x00001000)
        { pc = 0x40c02c; break; }
  case 0x40c040: // 0000:40c040
    r32[ecx] -= r32[eax];
    r32[eax] = r32[esp];
    r32[esp] = r32[ecx];
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x4);
    push32(r32[eax]);
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function fixReloc(seg)
{
}


