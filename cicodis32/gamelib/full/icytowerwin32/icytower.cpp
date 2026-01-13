// Sections of icytower.exe:
//  - .text: 401000 .. 40d000
//  - .rdata: 40d000 .. 40e000
//  - .data: 40e000 .. 42d194
//  - .rsrc: 42e000 .. 4333b6
#include "alleg40.h"
#include "kernel32.h"

void sub_406e7d();

void init()
{
    loadOverlay("icytower_text.bin", 0x401000);
    loadOverlay("icytower_rdata.bin", 0x40d000);
    loadOverlay("icytower_data.bin", 0x40e000);
    loadOverlay("icytower_rsrc.bin", 0x42e000);
    esp = 0x434000;
    ebp = 0x434000;
}

void start()
{
    sub_406e7d();
}
enum class ptrImportTable {
    ptr_begin = 0x6ab00000,
    ptr_kernel32_CloseHandle,
    ptr_kernel32_FlushFileBuffers,
    ptr_kernel32_SetStdHandle,
    ptr_kernel32_LCMapStringW,
    ptr_kernel32_LCMapStringA,
    ptr_kernel32_GetStringTypeW,
    ptr_kernel32_GetStringTypeA,
    ptr_kernel32_MultiByteToWideChar,
    ptr_kernel32_LoadLibraryA,
    ptr_kernel32_GetOEMCP,
    ptr_kernel32_GetACP,
    ptr_kernel32_GetCPInfo,
    ptr_kernel32_SetFilePointer,
    ptr_kernel32_GetLastError,
    ptr_kernel32_WriteFile,
    ptr_kernel32_RtlUnwind,
    ptr_kernel32_GetFileType,
    ptr_kernel32_GetStdHandle,
    ptr_kernel32_SetHandleCount,
    ptr_kernel32_GetEnvironmentStringsW,
    ptr_kernel32_GetEnvironmentStrings,
    ptr_kernel32_WideCharToMultiByte,
    ptr_kernel32_FreeEnvironmentStringsW,
    ptr_kernel32_FreeEnvironmentStringsA,
    ptr_kernel32_GetModuleFileNameA,
    ptr_kernel32_UnhandledExceptionFilter,
    ptr_kernel32_GetProcAddress,
    ptr_kernel32_HeapSize,
    ptr_kernel32_HeapReAlloc,
    ptr_kernel32_VirtualAlloc,
    ptr_kernel32_VirtualFree,
    ptr_kernel32_HeapCreate,
    ptr_kernel32_HeapDestroy,
    ptr_kernel32_GetVersion,
    ptr_kernel32_GetCommandLineA,
    ptr_kernel32_GetStartupInfoA,
    ptr_kernel32_GetModuleHandleA,
    ptr_kernel32_GetCurrentProcess,
    ptr_kernel32_TerminateProcess,
    ptr_kernel32_ExitProcess,
    ptr_kernel32_HeapFree,
    ptr_kernel32_HeapAlloc,
    ptr_alleg40_textprintf_centre,
    ptr_alleg40_fade_out,
    ptr_alleg40_readkey,
    ptr_alleg40_save_pcx,
    ptr_alleg40_keypressed,
    ptr_alleg40_clear_keybuf,
    ptr_alleg40_textout_centre,
    ptr_alleg40_stop_sample,
    ptr_alleg40_adjust_sample,
    ptr_alleg40_fade_in,
    ptr_alleg40_font,
    ptr_alleg40_clear_bitmap,
    ptr_alleg40_color_map,
    ptr_alleg40_drawing_mode,
    ptr_alleg40_textout,
    ptr_alleg40_black_palette,
    ptr_alleg40__WinMain,
    ptr_alleg40_text_length,
    ptr_alleg40_set_clip,
    ptr_alleg40_install_int,
    ptr_alleg40_install_timer,
    ptr_alleg40_get_palette_range,
    ptr_alleg40_set_palette_range,
    ptr_alleg40_screen,
    ptr_alleg40_stretch_sprite,
    ptr_alleg40_allegro_errno,
    ptr_alleg40__cos_tbl,
    ptr_alleg40_blit,
    ptr_alleg40_destroy_sample,
    ptr_alleg40_unload_datafile,
    ptr_alleg40_destroy_bitmap,
    ptr_alleg40_allegro_exit,
    ptr_alleg40_install_allegro,
    ptr_alleg40_install_keyboard,
    ptr_alleg40_install_sound,
    ptr_alleg40_install_joystick,
    ptr_alleg40_create_bitmap,
    ptr_alleg40_allegro_message,
    ptr_alleg40_load_datafile,
    ptr_alleg40_pack_fopen,
    ptr_alleg40_pack_fclose,
    ptr_alleg40_create_rgb_table,
    ptr_alleg40_rgb_map,
    ptr_alleg40_create_light_table,
    ptr_alleg40_set_color_depth,
    ptr_alleg40_set_gfx_mode,
    ptr_alleg40_exists,
    ptr_alleg40_set_display_switch_mode,
    ptr_alleg40_text_mode,
    ptr_alleg40_load_wav,
    ptr_alleg40_play_sample,
    ptr_alleg40_get_palette,
    ptr_alleg40_desktop_palette,
    ptr_alleg40_set_palette,
    ptr_alleg40_alert,
    ptr_alleg40_text_height,
    ptr_alleg40_textprintf,
    ptr_alleg40_textprintf_right,
    ptr_alleg40_pack_fread,
    ptr_alleg40_pack_fwrite,
    ptr_alleg40_poll_joystick,
    ptr_alleg40_joy,
    ptr_alleg40_key,
    ptr_alleg40_masked_blit,
    ptr_alleg40_solid_mode,
};
switch ((ptrImportTable)o) {
    case ptrImportTable::ptr_kernel32_CloseHandle:
        eax = kernel32::CloseHandle(stack32<HANDLE>(0)); esp += 4;
        break; // 6ab00001
    case ptrImportTable::ptr_kernel32_FlushFileBuffers:
        eax = kernel32::FlushFileBuffers(stack32<HANDLE>(0)); esp += 4;
        break; // 6ab00002
    case ptrImportTable::ptr_kernel32_SetStdHandle:
        eax = kernel32::SetStdHandle(stack32<DWORD>(0), stack32<HANDLE>(1)); esp += 8;
        break; // 6ab00003
    case ptrImportTable::ptr_kernel32_LCMapStringW:
        eax = kernel32::LCMapStringW(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCWSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;
        break; // 6ab00004
    case ptrImportTable::ptr_kernel32_LCMapStringA:
        eax = kernel32::LCMapStringA(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPSTR>(4), stack32<int>(5)); esp += 24;
        break; // 6ab00005
    case ptrImportTable::ptr_kernel32_GetStringTypeW:
        eax = kernel32::GetStringTypeW(stack32<DWORD>(0), stack32<LPCWSTR>(1), stack32<int>(2), stack32<LPWORD>(3)); esp += 16;
        break; // 6ab00006
    case ptrImportTable::ptr_kernel32_GetStringTypeA:
        eax = kernel32::GetStringTypeA(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPWORD>(4)); esp += 20;
        break; // 6ab00007
    case ptrImportTable::ptr_kernel32_MultiByteToWideChar:
        eax = kernel32::MultiByteToWideChar(stack32<UINT>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;
        break; // 6ab00008
    case ptrImportTable::ptr_kernel32_LoadLibraryA:
        eax = kernel32::LoadLibraryA(stack32<LPCSTR>(0)); esp += 4;
        break; // 6ab00009
    case ptrImportTable::ptr_kernel32_GetOEMCP:
        eax = kernel32::GetOEMCP();
        break; // 6ab0000a
    case ptrImportTable::ptr_kernel32_GetACP:
        eax = kernel32::GetACP();
        break; // 6ab0000b
    case ptrImportTable::ptr_kernel32_GetCPInfo:
        eax = kernel32::GetCPInfo(stack32<UINT>(0), stack32<LPCPINFO>(1)); esp += 8;
        break; // 6ab0000c
    case ptrImportTable::ptr_kernel32_SetFilePointer:
        eax = kernel32::SetFilePointer(stack32<HANDLE>(0), stack32<LONG>(1), stack32<PLONG>(2), stack32<DWORD>(3)); esp += 16;
        break; // 6ab0000d
    case ptrImportTable::ptr_kernel32_GetLastError:
        eax = kernel32::GetLastError();
        break; // 6ab0000e
    case ptrImportTable::ptr_kernel32_WriteFile:
        eax = kernel32::WriteFile(stack32<HANDLE>(0), stack32<LPCVOID>(1), stack32<DWORD>(2), stack32<LPDWORD>(3), stack32<LPOVERLAPPED>(4)); esp += 20;
        break; // 6ab0000f
    case ptrImportTable::ptr_kernel32_RtlUnwind:
        kernel32::RtlUnwind(stack32<PVOID>(0), stack32<PVOID>(1), stack32<PEXCEPTION_RECORD>(2), stack32<PVOID>(3)); esp += 16;
        break; // 6ab00010
    case ptrImportTable::ptr_kernel32_GetFileType:
        eax = kernel32::GetFileType(stack32<HANDLE>(0)); esp += 4;
        break; // 6ab00011
    case ptrImportTable::ptr_kernel32_GetStdHandle:
        eax = kernel32::GetStdHandle(stack32<DWORD>(0)); esp += 4;
        break; // 6ab00012
    case ptrImportTable::ptr_kernel32_SetHandleCount:
        eax = kernel32::SetHandleCount(stack32<UINT>(0)); esp += 4;
        break; // 6ab00013
    case ptrImportTable::ptr_kernel32_GetEnvironmentStringsW:
        eax = kernel32::GetEnvironmentStringsW();
        break; // 6ab00014
    case ptrImportTable::ptr_kernel32_GetEnvironmentStrings:
        eax = kernel32::GetEnvironmentStrings();
        break; // 6ab00015
    case ptrImportTable::ptr_kernel32_WideCharToMultiByte:
        eax = kernel32::WideCharToMultiByte(stack32<UINT>(0), stack32<DWORD>(1), stack32<LPCWSTR>(2), stack32<int>(3), stack32<LPSTR>(4), stack32<int>(5), stack32<LPCSTR>(6), stack32<LPBOOL>(7)); esp += 32;
        break; // 6ab00016
    case ptrImportTable::ptr_kernel32_FreeEnvironmentStringsW:
        eax = kernel32::FreeEnvironmentStringsW(stack32<LPWCH>(0)); esp += 4;
        break; // 6ab00017
    case ptrImportTable::ptr_kernel32_FreeEnvironmentStringsA:
        eax = kernel32::FreeEnvironmentStringsA(stack32<LPCH>(0)); esp += 4;
        break; // 6ab00018
    case ptrImportTable::ptr_kernel32_GetModuleFileNameA:
        eax = kernel32::GetModuleFileNameA(stack32<HMODULE>(0), stack32<LPSTR>(1), stack32<DWORD>(2)); esp += 12;
        break; // 6ab00019
    case ptrImportTable::ptr_kernel32_UnhandledExceptionFilter:
        eax = kernel32::UnhandledExceptionFilter(stack32<struct _EXCEPTION_POINTERS>(0)); esp += 4;
        break; // 6ab0001a
    case ptrImportTable::ptr_kernel32_GetProcAddress:
        eax = kernel32::GetProcAddress(stack32<HMODULE>(0), stack32<LPCSTR>(1)); esp += 8;
        break; // 6ab0001b
    case ptrImportTable::ptr_kernel32_HeapSize:
        eax = kernel32::HeapSize(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPCVOID>(2)); esp += 12;
        break; // 6ab0001c
    case ptrImportTable::ptr_kernel32_HeapReAlloc:
        eax = kernel32::HeapReAlloc(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPVOID>(2), stack32<SIZE_T>(3)); esp += 16;
        break; // 6ab0001d
    case ptrImportTable::ptr_kernel32_VirtualAlloc:
        eax = kernel32::VirtualAlloc(stack32<LPVOID>(0), stack32<SIZE_T>(1), stack32<DWORD>(2), stack32<DWORD>(3)); esp += 16;
        break; // 6ab0001e
    case ptrImportTable::ptr_kernel32_VirtualFree:
        eax = kernel32::VirtualFree(stack32<LPVOID>(0), stack32<SIZE_T>(1), stack32<DWORD>(2)); esp += 12;
        break; // 6ab0001f
    case ptrImportTable::ptr_kernel32_HeapCreate:
        eax = kernel32::HeapCreate(stack32<DWORD>(0), stack32<SIZE_T>(1), stack32<SIZE_T>(2)); esp += 12;
        break; // 6ab00020
    case ptrImportTable::ptr_kernel32_HeapDestroy:
        eax = kernel32::HeapDestroy(stack32<HANDLE>(0)); esp += 4;
        break; // 6ab00021
    case ptrImportTable::ptr_kernel32_GetVersion:
        eax = kernel32::GetVersion();
        break; // 6ab00022
    case ptrImportTable::ptr_kernel32_GetCommandLineA:
        eax = kernel32::GetCommandLineA();
        break; // 6ab00023
    case ptrImportTable::ptr_kernel32_GetStartupInfoA:
        kernel32::GetStartupInfoA(stack32<LPSTARTUPINFOA>(0)); esp += 4;
        break; // 6ab00024
    case ptrImportTable::ptr_kernel32_GetModuleHandleA:
        eax = kernel32::GetModuleHandleA(stack32<LPCSTR>(0)); esp += 4;
        break; // 6ab00025
    case ptrImportTable::ptr_kernel32_GetCurrentProcess:
        eax = kernel32::GetCurrentProcess();
        break; // 6ab00026
    case ptrImportTable::ptr_kernel32_TerminateProcess:
        eax = kernel32::TerminateProcess(stack32<HANDLE>(0), stack32<UINT>(1)); esp += 8;
        break; // 6ab00027
    case ptrImportTable::ptr_kernel32_ExitProcess:
        kernel32::ExitProcess(stack32<UINT>(0)); esp += 4;
        break; // 6ab00028
    case ptrImportTable::ptr_kernel32_HeapFree:
        eax = kernel32::HeapFree(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPVOID>(2)); esp += 12;
        break; // 6ab00029
    case ptrImportTable::ptr_kernel32_HeapAlloc:
        eax = kernel32::HeapAlloc(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<SIZE_T>(2)); esp += 12;
        break; // 6ab0002a
    case ptrImportTable::ptr_alleg40_textprintf_centre:
        alleg40::textprintf_centre(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));
        break; // 6ab0002b
    case ptrImportTable::ptr_alleg40_fade_out:
        alleg40::fade_out(stack32<int>(0));
        break; // 6ab0002c
    case ptrImportTable::ptr_alleg40_readkey:
        eax = alleg40::readkey();
        break; // 6ab0002d
    case ptrImportTable::ptr_alleg40_save_pcx:
        alleg40::save_pcx(stack32<const char>(0), stack32<BITMAP>(1), stack32<const PALETTE>(2));
        break; // 6ab0002e
    case ptrImportTable::ptr_alleg40_keypressed:
        eax = alleg40::keypressed();
        break; // 6ab0002f
    case ptrImportTable::ptr_alleg40_clear_keybuf:
        alleg40::clear_keybuf();
        break; // 6ab00030
    case ptrImportTable::ptr_alleg40_textout_centre:
        alleg40::textout_centre(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<const char>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));
        break; // 6ab00031
    case ptrImportTable::ptr_alleg40_stop_sample:
        alleg40::stop_sample(stack32<const SAMPLE>(0));
        break; // 6ab00032
    case ptrImportTable::ptr_alleg40_adjust_sample:
        alleg40::adjust_sample(stack32<SAMPLE>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));
        break; // 6ab00033
    case ptrImportTable::ptr_alleg40_fade_in:
        alleg40::fade_in(stack32<const PALETTE>(0), stack32<int>(1));
        break; // 6ab00034
    case ptrImportTable::ptr_alleg40_font:
        stop("invalid decl");
        break; // 6ab00035
    case ptrImportTable::ptr_alleg40_clear_bitmap:
        alleg40::clear_bitmap(stack32<BITMAP>(0));
        break; // 6ab00036
    case ptrImportTable::ptr_alleg40_color_map:
        stop("invalid decl");
        break; // 6ab00037
    case ptrImportTable::ptr_alleg40_drawing_mode:
        alleg40::drawing_mode(stack32<int>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3));
        break; // 6ab00038
    case ptrImportTable::ptr_alleg40_textout:
        alleg40::textout(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<const char>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));
        break; // 6ab00039
    case ptrImportTable::ptr_alleg40_black_palette:
        stop("invalid decl");
        break; // 6ab0003a
    case ptrImportTable::ptr_alleg40__WinMain:
        eax = alleg40::_WinMain(stack32<void>(0), stack32<void>(1), stack32<char>(2), stack32<int>(3));
        break; // 6ab0003b
    case ptrImportTable::ptr_alleg40_text_length:
        eax = alleg40::text_length(stack32<const FONT>(0), stack32<const char>(1));
        break; // 6ab0003c
    case ptrImportTable::ptr_alleg40_set_clip:
        alleg40::set_clip(stack32<BITMAP>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));
        break; // 6ab0003d
    case ptrImportTable::ptr_alleg40_install_int:
        alleg40::install_int(stack32<void (*)(void)>(0), stack32<long>(1));
        break; // 6ab0003e
    case ptrImportTable::ptr_alleg40_install_timer:
        alleg40::install_timer();
        break; // 6ab0003f
    case ptrImportTable::ptr_alleg40_get_palette_range:
        alleg40::get_palette_range(stack32<PALETTE>(0), stack32<int>(1), stack32<int>(2), stack32<PALETTE>(3));
        break; // 6ab00040
    case ptrImportTable::ptr_alleg40_set_palette_range:
        alleg40::set_palette_range(stack32<const PALETTE>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3));
        break; // 6ab00041
    case ptrImportTable::ptr_alleg40_screen:
        stop("invalid decl");
        break; // 6ab00042
    case ptrImportTable::ptr_alleg40_stretch_sprite:
        alleg40::stretch_sprite(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));
        break; // 6ab00043
    case ptrImportTable::ptr_alleg40_allegro_errno:
        stop("invalid decl");
        break; // 6ab00044
    case ptrImportTable::ptr_alleg40__cos_tbl:
        stop("invalid decl");
        break; // 6ab00045
    case ptrImportTable::ptr_alleg40_blit:
        alleg40::blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));
        break; // 6ab00046
    case ptrImportTable::ptr_alleg40_destroy_sample:
        alleg40::destroy_sample(stack32<SAMPLE>(0));
        break; // 6ab00047
    case ptrImportTable::ptr_alleg40_unload_datafile:
        alleg40::unload_datafile(stack32<DATAFILE>(0));
        break; // 6ab00048
    case ptrImportTable::ptr_alleg40_destroy_bitmap:
        alleg40::destroy_bitmap(stack32<BITMAP>(0));
        break; // 6ab00049
    case ptrImportTable::ptr_alleg40_allegro_exit:
        alleg40::allegro_exit();
        break; // 6ab0004a
    case ptrImportTable::ptr_alleg40_install_allegro:
        eax = alleg40::install_allegro(stack32<int>(0), stack32<int>(1), stack32<int (*)(void (*func)(void))>(2));
        break; // 6ab0004b
    case ptrImportTable::ptr_alleg40_install_keyboard:
        alleg40::install_keyboard();
        break; // 6ab0004c
    case ptrImportTable::ptr_alleg40_install_sound:
        eax = alleg40::install_sound(stack32<int>(0), stack32<int>(1), stack32<const char>(2));
        break; // 6ab0004d
    case ptrImportTable::ptr_alleg40_install_joystick:
        alleg40::install_joystick(stack32<int>(0));
        break; // 6ab0004e
    case ptrImportTable::ptr_alleg40_create_bitmap:
        eax = alleg40::create_bitmap(stack32<int>(0), stack32<int>(1));
        break; // 6ab0004f
    case ptrImportTable::ptr_alleg40_allegro_message:
        alleg40::allegro_message(stack32<const char>(0));
        break; // 6ab00050
    case ptrImportTable::ptr_alleg40_load_datafile:
        eax = alleg40::load_datafile(stack32<const char>(0));
        break; // 6ab00051
    case ptrImportTable::ptr_alleg40_pack_fopen:
        eax = alleg40::pack_fopen(stack32<const char>(0), stack32<const char>(1));
        break; // 6ab00052
    case ptrImportTable::ptr_alleg40_pack_fclose:
        eax = alleg40::pack_fclose(stack32<PACKFILE>(0));
        break; // 6ab00053
    case ptrImportTable::ptr_alleg40_create_rgb_table:
        alleg40::create_rgb_table(stack32<RGB_MAP>(0), stack32<const PALETTE>(1), stack32<void (*)(int pos)>(2));
        break; // 6ab00054
    case ptrImportTable::ptr_alleg40_rgb_map:
        stop("invalid decl");
        break; // 6ab00055
    case ptrImportTable::ptr_alleg40_create_light_table:
        alleg40::create_light_table(stack32<COLOR_MAP>(0), stack32<const PALETTE>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<void (*)(int pos)>(5));
        break; // 6ab00056
    case ptrImportTable::ptr_alleg40_set_color_depth:
        alleg40::set_color_depth(stack32<int>(0));
        break; // 6ab00057
    case ptrImportTable::ptr_alleg40_set_gfx_mode:
        eax = alleg40::set_gfx_mode(stack32<int>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));
        break; // 6ab00058
    case ptrImportTable::ptr_alleg40_exists:
        eax = alleg40::exists(stack32<const char>(0));
        break; // 6ab00059
    case ptrImportTable::ptr_alleg40_set_display_switch_mode:
        eax = alleg40::set_display_switch_mode(stack32<int>(0));
        break; // 6ab0005a
    case ptrImportTable::ptr_alleg40_text_mode:
        alleg40::text_mode(stack32<int>(0));
        break; // 6ab0005b
    case ptrImportTable::ptr_alleg40_load_wav:
        eax = alleg40::load_wav(stack32<const char>(0));
        break; // 6ab0005c
    case ptrImportTable::ptr_alleg40_play_sample:
        eax = alleg40::play_sample(stack32<const SAMPLE>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));
        break; // 6ab0005d
    case ptrImportTable::ptr_alleg40_get_palette:
        alleg40::get_palette(stack32<PALETTE>(0));
        break; // 6ab0005e
    case ptrImportTable::ptr_alleg40_desktop_palette:
        stop("invalid decl");
        break; // 6ab0005f
    case ptrImportTable::ptr_alleg40_set_palette:
        alleg40::set_palette(stack32<const PALETTE>(0));
        break; // 6ab00060
    case ptrImportTable::ptr_alleg40_alert:
        alleg40::alert(stack32<const char>(0), stack32<const char>(1), stack32<const char>(2), stack32<const char>(3), stack32<const char>(4), stack32<int>(5), stack32<int>(6));
        break; // 6ab00061
    case ptrImportTable::ptr_alleg40_text_height:
        eax = alleg40::text_height(stack32<const FONT>(0));
        break; // 6ab00062
    case ptrImportTable::ptr_alleg40_textprintf:
        alleg40::textprintf(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));
        break; // 6ab00063
    case ptrImportTable::ptr_alleg40_textprintf_right:
        alleg40::textprintf_right(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));
        break; // 6ab00064
    case ptrImportTable::ptr_alleg40_pack_fread:
        eax = alleg40::pack_fread(stack32<void>(0), stack32<long>(1), stack32<PACKFILE>(2));
        break; // 6ab00065
    case ptrImportTable::ptr_alleg40_pack_fwrite:
        eax = alleg40::pack_fwrite(stack32<const void>(0), stack32<long>(1), stack32<PACKFILE>(2));
        break; // 6ab00066
    case ptrImportTable::ptr_alleg40_poll_joystick:
        eax = alleg40::poll_joystick();
        break; // 6ab00067
    case ptrImportTable::ptr_alleg40_joy:
        stop("invalid decl");
        break; // 6ab00068
    case ptrImportTable::ptr_alleg40_key:
        stop("invalid decl");
        break; // 6ab00069
    case ptrImportTable::ptr_alleg40_masked_blit:
        alleg40::masked_blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));
        break; // 6ab0006a
    case ptrImportTable::ptr_alleg40_solid_mode:
        alleg40::solid_mode();
        break; // 6ab0006b
}
void sub_401000();
void sub_401030();
void sub_401060();
void sub_401170();
void sub_4011c0();
void sub_4011d0();
void sub_4011e0();
void sub_4011f0();
void sub_401200();
void sub_401210();
void sub_401220();
void sub_401230();
void sub_401240();
void sub_401250();
void sub_401280();
void sub_401320();
void sub_401370();
void sub_401410();
void sub_401430();
void sub_401450();
void sub_4014c0();
void sub_401510();
void sub_401570();
void sub_4015d0();
void sub_401600();
void sub_401c60();
void sub_401db0();
void sub_402250();
void sub_4022b0();
void sub_402320();
void sub_4024f0();
void sub_402610();
void sub_402670();
void sub_402780();
void sub_403420();
void sub_4034a0();
void sub_404650();
void sub_404810();
void sub_404950();
void sub_404970();
void sub_404990();
void sub_404d90();
void sub_404f90();
void sub_404fc0();
void sub_404ff0();
void sub_405170();
void sub_4051e0();
void sub_405210();
void sub_4053a0();
void sub_405480();
void sub_4054e0();
void sub_405680();
void sub_4059e0();
void sub_4064b0();
void sub_4064c0();
void sub_4064e0();
void sub_406500();
void sub_4065b0();
void sub_406600();
void sub_406620();
void sub_406670();
void sub_406800();
void sub_406880();
void sub_406930();
void sub_406a90();
void sub_406aa0();
void sub_406b00();
void sub_406b40();
void sub_406b52();
void sub_406b7e();
void sub_406bb4();
void sub_406be3();
void sub_406c01();
void sub_406c2e();
void sub_406c50();
void sub_406ce9();
void sub_406d82();
void sub_406db1();
void sub_406dc9();
void sub_406e04();
void sub_406e2b();
void sub_406e7d();
void sub_406f73();
void sub_406f98();
void sub_406fbc();
void sub_406fd7();
void sub_407013();
void sub_407051();
void sub_40707c();
void sub_4073a7();
void sub_4076b0();
void sub_407761();
void sub_407c9b();
void sub_407ceb();
void sub_40814f();
void sub_408264();
void sub_4089a5();
void sub_4089da();
void sub_408a0b();
void sub_408a43();
void sub_408a50();
void sub_408a60();
void sub_408a6e();
void sub_408baf();
void sub_408bf2();
void sub_408c4a();
void sub_408d03();
void sub_408d9c();
void sub_408f50();
void sub_409082();
void sub_409400();
void sub_409439();
void sub_409590();
void sub_4098d0();
void sub_409c05();
void sub_409c3a();
void sub_409c50();
void sub_409ce2();
void sub_40a2a0();
void sub_40a2b0();
void sub_40a530();
void sub_40a590();
void sub_40a614();
void sub_40a6ae();
void sub_40a85b();
void sub_40a89f();
void sub_40a8c5();
void sub_40a97e();
void sub_40a9f0();
void sub_40aa60();
void sub_40aad5();
void sub_40aae6();
void sub_40ab17();
void sub_40acb0();
void sub_40acfa();
void sub_40ad2d();
void sub_40ad56();
void sub_40aedb();
void sub_40aef7();
void sub_40af80();
void sub_40b07e();
void sub_40b1c7();
void sub_40b3eb();
void sub_40bd1b();
void sub_40bdfc();
void sub_40be39();
void sub_40c020();

void sub_401000() // 0000:401000 +long
{
    esp -= 4;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x8);
    push32(0x0000004b);
    push32(0x00000053);
    push32(0x00000052);
    push32(0x00000055);
    push32(0x00000054);
    push32(esi);
    sub_401030();
    esp += 0x00000018;
    memoryASet32(ds, esi + 0x18, 0x00000043);
    memoryASet32(ds, esi + 0x1c, 0x00000000);
    memoryASet32(ds, esi, 0x00000000);
    esi = pop32();
    esp += 4;
}
void sub_401030() // 0000:401030 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, esp + 0xc);
    memoryASet32(ds, eax + 0xc, ecx);
    ecx = memoryAGet32(ds, esp + 0x10);
    memoryASet32(ds, eax + 0x10, edx);
    edx = memoryAGet32(ds, esp + 0x14);
    memoryASet32(ds, eax + 0x4, ecx);
    ecx = memoryAGet32(ds, esp + 0x18);
    memoryASet32(ds, eax + 0x8, edx);
    memoryASet32(ds, eax + 0x14, ecx);
    esp += 4;
}
void sub_401060() // 0000:401060 +long
{
    esp -= 4;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, esi);
    memoryASet32(ds, esi + 0x1c, 0x00000000);
    if (!eax)
        goto loc_4010e2;
    eax = alleg40::poll_joystick();();
    eax = memoryAGet32(ds, 0x40d1a0);
    ecx = memoryAGet32(ds, eax + 0x28);
    if (!ecx)
        goto loc_40108c;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x04;
    memoryASet32(ds, esi + 0x1c, eax);
loc_40108c: // 0000:40108c
    ecx = memoryAGet32(ds, 0x40d1a0);
    eax = memoryAGet32(ds, ecx + 0x2c);
    if (!eax)
        goto loc_4010a1;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x08;
    memoryASet32(ds, esi + 0x1c, eax);
loc_4010a1: // 0000:4010a1
    edx = memoryAGet32(ds, 0x40d1a0);
    eax = memoryAGet32(ds, edx + 0x18);
    if (!eax)
        goto loc_4010b6;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x01;
    memoryASet32(ds, esi + 0x1c, eax);
loc_4010b6: // 0000:4010b6
    eax = memoryAGet32(ds, 0x40d1a0);
    ecx = memoryAGet32(ds, eax + 0x1c);
    if (!ecx)
        goto loc_4010ca;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x02;
    memoryASet32(ds, esi + 0x1c, eax);
loc_4010ca: // 0000:4010ca
    ecx = memoryAGet32(ds, 0x40d1a0);
    eax = memoryAGet32(ds, ecx + 0x138);
    if (!eax)
        goto loc_4010e2;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x10;
    memoryASet32(ds, esi + 0x1c, eax);
loc_4010e2: // 0000:4010e2
    edx = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, edx + eax))
        goto loc_4010f8;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x04;
    memoryASet32(ds, esi + 0x1c, eax);
loc_4010f8: // 0000:4010f8
    ecx = memoryAGet32(ds, esi + 0x10);
    edx = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, ecx + edx))
        goto loc_40110f;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x08;
    memoryASet32(ds, esi + 0x1c, eax);
loc_40110f: // 0000:40110f
    eax = memoryAGet32(ds, esi + 0x4);
    ecx = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, eax + ecx))
        goto loc_401126;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x01;
    memoryASet32(ds, esi + 0x1c, eax);
loc_401126: // 0000:401126
    edx = memoryAGet32(ds, esi + 0x8);
    eax = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, edx + eax))
        goto loc_40113c;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x02;
    memoryASet32(ds, esi + 0x1c, eax);
loc_40113c: // 0000:40113c
    ecx = memoryAGet32(ds, esi + 0x14);
    edx = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, ecx + edx))
        goto loc_401153;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x10;
    memoryASet32(ds, esi + 0x1c, eax);
loc_401153: // 0000:401153
    eax = memoryAGet32(ds, esi + 0x18);
    ecx = memoryAGet32(ds, 0x40d1a4);
    if (!memoryAGet(ds, eax + ecx))
        goto loc_40116a;
    eax = memoryAGet32(ds, esi + 0x1c);
    al |= 0x20;
    memoryASet32(ds, esi + 0x1c, eax);
loc_40116a: // 0000:40116a
    esi = pop32();
    esp += 4;
}
void sub_401170() // 0000:401170 +long
{
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, esp + 0x8);
    if (eax != memoryAGet32(ds, ecx + 0x4))
        goto loc_401181;
    eax |= 0xffffffff;
    esp += 4; return;
loc_401181: // 0000:401181
    if (eax != memoryAGet32(ds, ecx + 0x8))
        goto loc_40118a;
    eax |= 0xffffffff;
    esp += 4; return;
loc_40118a: // 0000:40118a
    if (eax != memoryAGet32(ds, ecx + 0xc))
        goto loc_401193;
    eax |= 0xffffffff;
    esp += 4; return;
loc_401193: // 0000:401193
    if (eax != memoryAGet32(ds, ecx + 0x10))
        goto loc_40119c;
    eax |= 0xffffffff;
    esp += 4; return;
loc_40119c: // 0000:40119c
    if (eax != memoryAGet32(ds, ecx + 0x14))
        goto loc_4011a5;
    eax |= 0xffffffff;
    esp += 4; return;
loc_4011a5: // 0000:4011a5
    push32(esi);
    esi = memoryAGet32(ds, ecx + 0x18);
    edx = 0;
    dl = eax != esi;
    edx--;
    esi = pop32();
    eax = edx;
    esp += 4;
}
void sub_4011c0() // 0000:4011c0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, eax + 0x1c);
    al &= 0x04;
    flags.carry = al != 0;
    al = -al;
    eax = -flags.carry;
    esp += 4;
}
void sub_4011d0() // 0000:4011d0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, eax + 0x1c);
    al &= 0x08;
    flags.carry = al != 0;
    al = -al;
    eax = -flags.carry;
    esp += 4;
}
void sub_4011e0() // 0000:4011e0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, eax + 0x1c);
    al &= 0x01;
    flags.carry = al != 0;
    al = -al;
    eax = -flags.carry;
    esp += 4;
}
void sub_4011f0() // 0000:4011f0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, eax + 0x1c);
    al &= 0x02;
    flags.carry = al != 0;
    al = -al;
    eax = -flags.carry;
    esp += 4;
}
void sub_401200() // 0000:401200 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, eax + 0x1c);
    al &= 0x10;
    flags.carry = al != 0;
    al = -al;
    eax = -flags.carry;
    esp += 4;
}
void sub_401210() // 0000:401210 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, eax + 0x1c);
    al &= 0x20;
    flags.carry = al != 0;
    al = -al;
    eax = -flags.carry;
    esp += 4;
}
void sub_401220() // 0000:401220 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, eax + 0x1c);
    flags.carry = eax != 0;
    eax = -eax;
    eax = -flags.carry;
    esp += 4;
}
void sub_401230() // 0000:401230 +long
{
    esp -= 4;
    push32(0x00000050);
    sub_406b40();
    esp += 0x00000004;
    esp += 4;
}
void sub_401240() // 0000:401240 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    push32(eax);
    sub_406bb4();
    ecx = pop32();
    esp += 4;
}
void sub_401250() // 0000:401250 +long
{
    esp -= 4;
    edx = memoryAGet32(ds, esp + 0x10);
    if (!edx)
        goto loc_40126e;
    ecx = memoryAGet32(ds, esp + 0x4);
    eax = 0;
    ecx += 0x00000008;
loc_401261: // 0000:401261
    if (edx >= memoryAGet32(ds, ecx))
        goto loc_401271;
    eax++;
    ecx += 0x00000010;
    if ((int32_t)eax < (int32_t)0x00000005)
        goto loc_401261;
loc_40126e: // 0000:40126e
    eax = 0;
    esp += 4; return;
loc_401271: // 0000:401271
    eax = 0x00000001;
    esp += 4;
}
void sub_401280() // 0000:401280 +long
{
    esp -= 4;
    esp -= 0x00000014;
    eax = memoryAGet32(ds, esp + 0x18);
    push32(ebx);
    push32(ebp);
    push32(esi);
    ecx = eax + 16;
    push32(edi);
    edx = 0x00000001;
    memoryASet32(ds, esp + 0x10, ecx);
loc_401297: // 0000:401297
    edi = ecx;
    eax = edx;
    esi = memoryAGet32(ds, edi);
    memoryASet32(ds, esp + 0x14, esi);
    esi = memoryAGet32(ds, edi + 0x4);
    memoryASet32(ds, esp + 0x18, esi);
    esi = memoryAGet32(ds, edi + 0x8);
    edi = memoryAGet32(ds, edi + 0xc);
    memoryASet32(ds, esp + 0x20, edi);
    if (!edx)
        goto loc_4012e1;
    ecx += 0xfffffff0;
loc_4012b9: // 0000:4012b9
    if (esi <= memoryAGet32(ds, ecx + 0x8))
        goto loc_4012e1;
    ebx = ecx;
    edi = ecx + 16;
    eax--;
    ecx -= 0x00000010;
    ebp = memoryAGet32(ds, ebx);
    memoryASet32(ds, edi, ebp);
    ebp = memoryAGet32(ds, ebx + 0x4);
    memoryASet32(ds, edi + 0x4, ebp);
    ebp = memoryAGet32(ds, ebx + 0x8);
    memoryASet32(ds, edi + 0x8, ebp);
    ebx = memoryAGet32(ds, ebx + 0xc);
    memoryASet32(ds, edi + 0xc, ebx);
    if (eax)
        goto loc_4012b9;
loc_4012e1: // 0000:4012e1
    ebx = memoryAGet32(ds, esp + 0x28);
    ecx = memoryAGet32(ds, esp + 0x14);
    eax <<= 4;
    eax += ebx;
    edx++;
    memoryASet32(ds, eax, ecx);
    ecx = memoryAGet32(ds, esp + 0x18);
    memoryASet32(ds, eax + 0x4, ecx);
    ecx = memoryAGet32(ds, esp + 0x20);
    memoryASet32(ds, eax + 0x8, esi);
    memoryASet32(ds, eax + 0xc, ecx);
    ecx = memoryAGet32(ds, esp + 0x10);
    ecx += 0x00000010;
    memoryASet32(ds, esp + 0x10, ecx);
    if ((int32_t)edx < (int32_t)0x00000005)
        goto loc_401297;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000014;
    esp += 4;
}
void sub_401320() // 0000:401320 +long
{
    esp -= 4;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x8);
    push32(esi);
    push32(edi);
    edx |= 0xffffffff;
    edi = 0x00989680;
    eax = 0;
    esi = ebx + 8;
loc_401334: // 0000:401334
    ecx = memoryAGet32(ds, esi);
    if (ecx >= edi)
        goto loc_40133e;
    edx = eax;
    edi = ecx;
loc_40133e: // 0000:40133e
    eax++;
    esi += 0x00000010;
    if ((int32_t)eax < (int32_t)0x00000005)
        goto loc_401334;
    if ((int32_t)edx < 0)
        goto loc_40136b;
    eax = memoryAGet32(ds, esp + 0x14);
    ecx = memoryAGet32(ds, esp + 0x18);
    edx <<= 4;
    edx += ebx;
    memoryASet32(ds, edx, eax);
    eax = memoryAGet32(ds, esp + 0x1c);
    memoryASet32(ds, edx + 0x4, ecx);
    ecx = memoryAGet32(ds, esp + 0x20);
    memoryASet32(ds, edx + 0x8, eax);
    memoryASet32(ds, edx + 0xc, ecx);
loc_40136b: // 0000:40136b
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp += 4;
}
void sub_401370() // 0000:401370 +long
{
    esp -= 4;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x14);
    push32(ebp);
    ebp = memoryAGet32(ds, esp + 0x14);
    ecx = ebp;
    eax = 0x66666667;
    ecx -= ebx;
    push32(esi);
    imul32(ecx);
    ecx = memoryAGet32(ds, esp + 0x10);
    push32(edi);
    edx = sar32(edx, 0x00000001);
    eax = edx;
    ebx = ecx + 12;
    eax >>= 31;
    edx += eax;
    memoryASet32(ds, esp + 0x1c, 0x00000005);
    memoryASet32(ds, esp + 0x20, edx);
loc_4013a3: // 0000:4013a3
    edi = memoryAGet32(ds, esp + 0x18);
    ecx |= 0xffffffff;
    eax = 0;
    edx = ebx - 12;
    for (flags.zero = 0; ecx != 0 && !flags.zero; --ecx) scasb_inv<ES_EDI>(al);
    ecx = ~ecx;
    edi -= ecx;
    eax = ecx;
    esi = edi;
    edi = edx;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    ecx = eax;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    memoryASet32(ds, ebx - 4, ebp);
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000007;
    ebx += 0x00000010;
    idiv32(ecx);
    eax = 0x66666667;
    ecx = edx;
    imul32(ebp);
    edx = sar32(edx, 0x03);
    eax = edx;
    edx += ecx;
    eax >>= 31;
    eax += edx;
    edx = memoryAGet32(ds, esp + 0x20);
    memoryASet32(ds, ebx - 16, eax);
    eax = memoryAGet32(ds, esp + 0x1c);
    ebp -= edx;
    eax--;
    memoryASet32(ds, esp + 0x1c, eax);
    if (eax)
        goto loc_4013a3;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 4;
}
void sub_401410() // 0000:401410 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, esp + 0x4);
    push32(eax);
    push32(0x00000050);
    push32(ecx);
    eax = alleg40::pack_fread(stack32<void>(0), stack32<long>(1), stack32<PACKFILE>(2));();
    esp += 0x0000000c;
    eax = 0x00000001;
    esp += 4;
}
void sub_401430() // 0000:401430 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, esp + 0x4);
    push32(eax);
    push32(0x00000050);
    push32(ecx);
    eax = alleg40::pack_fwrite(stack32<const void>(0), stack32<long>(1), stack32<PACKFILE>(2));();
    esp += 0x0000000c;
    esp += 4;
}
void sub_401450() // 0000:401450 +long
{
    esp -= 4;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x14);
    push32(ebp);
    ebp = memoryAGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, esp + 0x10);
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x10);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x24);
    push32(esi);
    push32(0x0040e034);
    push32(0xffffffff);
    push32(edi);
    push32(ebx);
    push32(ebp);
    push32(eax);
    alleg40::textprintf(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));();
    ecx = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet32(ds, esp + 0x34);
    push32(ecx);
    push32(0x0040e030);
    push32(0xffffffff);
    edx = ebx + 100;
    push32(edi);
    push32(edx);
    push32(ebp);
    push32(eax);
    alleg40::textprintf_right(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));();
    ecx = memoryAGet32(ds, esi + 0x8);
    edx = memoryAGet32(ds, esp + 0x50);
    push32(ecx);
    push32(0x0040e030);
    push32(0xffffffff);
    ebx += 0x000000c8;
    push32(edi);
    push32(ebx);
    push32(ebp);
    push32(edx);
    alleg40::textprintf_right(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));();
    esp += 0x00000054;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 4;
}
void sub_4014c0() // 0000:4014c0 +long
{
    esp -= 4;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x8);
    push32(ebp);
    ebp = memoryAGet32(ds, esp + 0x1c);
    push32(esi);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x1c);
    esi = 0;
loc_4014d2: // 0000:4014d2
    push32(edi);
    esi++;
    eax = alleg40::text_height(stack32<const FONT>(0));();
    eax -= 0x00000005;
    ecx = memoryAGet32(ds, esp + 0x1c);
    eax = (int32_t)eax * (int32_t)esi;
    eax += ebp;
    push32(eax);
    eax = memoryAGet32(ds, esp + 0x28);
    push32(eax);
    push32(edi);
    push32(ecx);
    push32(ebx);
    sub_401450();
    esp += 0x00000018;
    ebx += 0x00000010;
    if ((int32_t)esi < (int32_t)0x00000005)
        goto loc_4014d2;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 4;
}
void sub_401510() // 0000:401510 +long
{
    esp -= 4;
    esp -= 0x00000400;
    eax = esp;
    push32(esi);
    push32(eax);
    alleg40::get_palette(stack32<PALETTE>(0));();
    ecx = memoryAGet32(ds, 0x40d17c);
    esi = memoryAGet32(ds, 0x40d180);
    push32(ecx);
    indirectCall(cs, esi); // 0000:40152f
    edx = memoryAGet32(ds, esp + 0x414);
    eax = memoryAGet32(ds, esp + 0x410);
    push32(0x0000001b);
    push32(0x0000000d);
    push32(0x0040e74c);
    push32(0x0040e740);
    push32(edx);
    push32(eax);
    push32(0x0040e738);
    alleg40::alert(stack32<const char>(0), stack32<const char>(1), stack32<const char>(2), stack32<const char>(3), stack32<const char>(4), stack32<int>(5), stack32<int>(6));();
    ecx = esp + 40;
    push32(ecx);
    indirectCall(cs, esi); // 0000:40155f
    esp += 0x00000028;
    esi = pop32();
    esp += 0x00000400;
    esp += 4;
}
void sub_401570() // 0000:401570 +long
{
    esp -= 4;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x8);
    if (!esi)
        goto loc_4015cd;
    eax = memoryAGet32(ds, 0x40e040);
    if (!eax)
        goto loc_4015cd;
    ecx = memoryAGet32(ds, esp + 0xc);
    push32(0x00000000);
    if (!ecx)
        goto loc_4015b8;
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000190;
    idiv32(ecx);
    edx += 0x00000384;
    push32(edx);
    edx = memoryAGet32(ds, 0x40e040);
    push32(0x00000080);
    push32(edx);
    push32(esi);
    eax = alleg40::play_sample(stack32<const SAMPLE>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));();
    esp += 0x00000014;
    esi = pop32();
    esp += 4; return;
loc_4015b8: // 0000:4015b8
    push32(0x000003e8);
    push32(0x00000080);
    push32(eax);
    push32(esi);
    eax = alleg40::play_sample(stack32<const SAMPLE>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));();
    esp += 0x00000014;
loc_4015cd: // 0000:4015cd
    esi = pop32();
    esp += 4;
}
void sub_4015d0() // 0000:4015d0 +long
{
    esp -= 4;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0xc);
    push32(esi);
    eax = alleg40::load_wav(stack32<const char>(0));();
    ecx = memoryAGet32(ds, esp + 0xc);
    esp += 0x00000004;
    memoryASet32(ds, ecx, eax);
    if (eax)
        goto loc_4015f7;
    push32(esi);
    push32(0x0040e754);
    sub_401510();
    esp += 0x00000008;
loc_4015f7: // 0000:4015f7
    esi = pop32();
    esp += 4;
}
void sub_401600() // 0000:401600 +long
{
    esp -= 4;
    push32(esi);
    push32(edi);
    push32(0x00406d70);
    push32(0x0040fab8);
    push32(0x00000000);
    eax = alleg40::install_allegro(stack32<int>(0), stack32<int>(1), stack32<int (*)(void (*func)(void))>(2));();
    alleg40::install_keyboard();();
    sub_406b00();
    push32(0x00000000);
    push32(0xffffffff);
    push32(0x44584120);
    eax = alleg40::install_sound(stack32<int>(0), stack32<int>(1), stack32<const char>(2));();
    push32(0xffffffff);
    alleg40::install_joystick(stack32<int>(0));();
    esi = memoryAGet32(ds, 0x40d13c);
    push32(0x000001e0);
    flags.carry = eax != 0;
    eax = -eax;
    eax = -flags.carry;
    push32(0x00000280);
    eax++;
    memoryASet32(ds, 0x42bbc4, eax);
    indirectCall(cs, esi); // 0000:401650
    push32(0x00000040);
    push32(0x00000280);
    memoryASet32(ds, 0x40fa34, eax);
    indirectCall(cs, esi); // 0000:40165e
    ecx = memoryAGet32(ds, 0x40fa34);
    esp += 0x0000002c;
    memoryASet32(ds, 0x40fa38, eax);
    if (!ecx)
        goto loc_401c4b;
    if (!eax)
        goto loc_401c4b;
    push32(0x000001e0);
    push32(0x00000280);
    indirectCall(cs, esi); // 0000:401688
    esp += 0x00000008;
    memoryASet32(ds, 0x40fa34, eax);
    if (eax)
        goto loc_4016a9;
    push32(0x0040ea30);
    alleg40::allegro_message(stack32<const char>(0));();
    esp += 0x00000004;
    eax = 0;
    edi = pop32();
    esi = pop32();
    esp += 4; return;
loc_4016a9: // 0000:4016a9
    sub_401230();
    memoryASet32(ds, 0x40fa3c, eax);
    if (eax)
        goto loc_4016ca;
    push32(0x0040ea04);
    alleg40::allegro_message(stack32<const char>(0));();
    esp += 0x00000004;
    eax = 0;
    edi = pop32();
    esi = pop32();
    esp += 4; return;
loc_4016ca: // 0000:4016ca
    push32(0x00000000);
    push32(0x000003e8);
    push32(0x0040ea00);
    push32(eax);
    sub_401370();
    esi = memoryAGet32(ds, 0x40d144);
    push32(0x0040e9f0);
    indirectCall(cs, esi); // 0000:4016e7
    esp += 0x00000014;
    memoryASet32(ds, 0x40fa40, eax);
    if (eax)
        goto loc_401708;
    push32(0x0040e9d4);
    alleg40::allegro_message(stack32<const char>(0));();
    esp += 0x00000004;
    eax = 0;
    edi = pop32();
    esi = pop32();
    esp += 4; return;
loc_401708: // 0000:401708
    push32(0x0040e9c4);
    indirectCall(cs, esi); // 0000:40170d
    esp += 0x00000004;
    memoryASet32(ds, 0x40fa44, eax);
    if (eax)
        goto loc_4017ce;
    push32(0x0040e9b4);
    indirectCall(cs, esi); // 0000:401724
    esp += 0x00000004;
    memoryASet32(ds, 0x40fa44, eax);
    if (eax)
        goto loc_40179c;
    push32(0x0040e9a4);
    indirectCall(cs, esi); // 0000:401737
    esp += 0x00000004;
    memoryASet32(ds, 0x40fa44, eax);
    if (eax)
        goto loc_40176c;
    eax = memoryAGet32(ds, 0x40e998);
    ecx = memoryAGet32(ds, 0x40e99c);
    dl = memoryAGet(ds, 0x40e9a0);
    memoryASet32(ds, 0x42bbe0, eax);
    memoryASet32(ds, 0x42bbe4, ecx);
    memoryASet(ds, 0x42bbe8, dl);
    goto loc_4017fe;
loc_40176c: // 0000:40176c
    eax = memoryAGet32(ds, 0x40e98c);
    ecx = memoryAGet32(ds, 0x40e990);
    dx = memoryAGet16(ds, 0x40e994);
    memoryASet32(ds, 0x42bbe0, eax);
    al = memoryAGet(ds, 0x40e996);
    memoryASet32(ds, 0x42bbe4, ecx);
    memoryASet16(ds, 0x42bbe8, dx);
    memoryASet(ds, 0x42bbea, al);
    goto loc_4017fe;
loc_40179c: // 0000:40179c
    ecx = memoryAGet32(ds, 0x40e980);
    edx = memoryAGet32(ds, 0x40e984);
    ax = memoryAGet16(ds, 0x40e988);
    memoryASet32(ds, 0x42bbe0, ecx);
    cl = memoryAGet(ds, 0x40e98a);
    memoryASet32(ds, 0x42bbe4, edx);
    memoryASet16(ds, 0x42bbe8, ax);
    memoryASet(ds, 0x42bbea, cl);
    goto loc_4017fe;
loc_4017ce: // 0000:4017ce
    edx = memoryAGet32(ds, 0x40e974);
    eax = memoryAGet32(ds, 0x40e978);
    cx = memoryAGet16(ds, 0x40e97c);
    memoryASet32(ds, 0x42bbe0, edx);
    dl = memoryAGet(ds, 0x40e97e);
    memoryASet32(ds, 0x42bbe4, eax);
    memoryASet16(ds, 0x42bbe8, cx);
    memoryASet(ds, 0x42bbea, dl);
loc_4017fe: // 0000:4017fe
    eax = memoryAGet32(ds, 0x40fa40);
    push32(0x0040e970);
    push32(0x0040e964);
    ecx = memoryAGet32(ds, eax);
    memoryASet(ds, ecx + 0x2, 0x00);
    edx = memoryAGet32(ds, 0x40fa40);
    eax = memoryAGet32(ds, edx);
    memoryASet(ds, eax + 0x1, 0x00);
    ecx = memoryAGet32(ds, 0x40fa40);
    edx = memoryAGet32(ds, ecx);
    memoryASet(ds, edx, 0x00);
    eax = memoryAGet32(ds, 0x40fa40);
    ecx = memoryAGet32(ds, eax + 0x160);
    memoryASet32(ds, 0x413320, ecx);
    eax = alleg40::pack_fopen(stack32<const char>(0), stack32<const char>(1));();
    esi = eax;
    esp += 0x00000008;
    if (!esi)
        goto loc_40186c;
    push32(esi);
    push32(0x0040e040);
    sub_4064e0();
    edx = memoryAGet32(ds, 0x40fa3c);
    push32(esi);
    push32(edx);
    sub_401410();
    push32(esi);
    eax = alleg40::pack_fclose(stack32<PACKFILE>(0));();
    esp += 0x00000014;
loc_40186c: // 0000:40186c
    eax = memoryAGet32(ds, 0x40e040);
    ecx = memoryAGet32(ds, 0x40e044);
    edx = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ds, 0x40e058, eax);
    memoryASet32(ds, 0x40e068, ecx);
    push32(0x00000000);
    eax = memoryAGet32(ds, edx);
    push32(eax);
    push32(0x00423bc0);
    alleg40::create_rgb_table(stack32<RGB_MAP>(0), stack32<const PALETTE>(1), stack32<void (*)(int pos)>(2));();
    ecx = memoryAGet32(ds, 0x40d154);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    memoryASet32(ds, ecx, 0x00423bc0);
    edx = memoryAGet32(ds, 0x40fa40);
    push32(0x00000000);
    eax = memoryAGet32(ds, edx);
    push32(eax);
    push32(0x00413340);
    alleg40::create_light_table(stack32<COLOR_MAP>(0), stack32<const PALETTE>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<void (*)(int pos)>(5));();
    push32(0x00000008);
    alleg40::set_color_depth(stack32<int>(0));();
    eax = memoryAGet32(ds, 0x40e050);
    esi = memoryAGet32(ds, 0x40d160);
    edi = memoryAGet32(ds, 0x40d180);
    esp += 0x00000028;
    if (eax)
        goto loc_40191d;
    push32(0x00000000);
    push32(0x00000000);
    push32(0x000001e0);
    push32(0x00000280);
    push32(0x4458574e);
    indirectCall(cs, esi); // 0000:4018f3
    esp += 0x00000014;
    if ((int32_t)eax < 0)
        goto loc_40194f;
    ecx = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ds, 0x40e038, 0x00000001);
    edx = memoryAGet32(ds, ecx);
    push32(edx);
    indirectCall(cs, edi); // 0000:40190f
    eax = memoryAGet32(ds, 0x40e050);
    esp += 0x00000004;
    if (!eax)
        goto loc_40196e;
loc_40191d: // 0000:40191d
    push32(0x00000000);
    push32(0x00000000);
    push32(0x000001e0);
    push32(0x00000280);
    push32(0x00000000);
    indirectCall(cs, esi); // 0000:40192d
    esp += 0x00000014;
    if ((int32_t)eax < 0)
        goto loc_40195b;
    eax = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ds, 0x40e038, 0x00000000);
    ecx = memoryAGet32(ds, eax);
    push32(ecx);
    indirectCall(cs, edi); // 0000:401948
    esp += 0x00000004;
    goto loc_40196e;
loc_40194f: // 0000:40194f
    memoryASet32(ds, 0x40e050, 0xffffffff);
    goto loc_40191d;
loc_40195b: // 0000:40195b
    push32(0x0040e944);
    alleg40::allegro_message(stack32<const char>(0));();
    esp += 0x00000004;
    eax = 0;
    edi = pop32();
    esi = pop32();
    esp += 4; return;
loc_40196e: // 0000:40196e
    eax = memoryAGet32(ds, 0x40fa44);
    if (!eax)
        goto loc_401a93;
    edx = memoryAGet32(ds, eax + 0x90);
    memoryASet32(ds, 0x40fa48, edx);
    ecx = memoryAGet32(ds, eax + 0x140);
    memoryASet32(ds, 0x40fa4c, ecx);
    edx = memoryAGet32(ds, eax + 0xa0);
    memoryASet32(ds, 0x40fa50, edx);
    ecx = memoryAGet32(ds, eax + 0x170);
    memoryASet32(ds, 0x40fa54, ecx);
    edx = memoryAGet32(ds, eax + 0x10);
    memoryASet32(ds, 0x40fa58, edx);
    ecx = memoryAGet32(ds, eax + 0x60);
    memoryASet32(ds, 0x40fa5c, ecx);
    edx = memoryAGet32(ds, eax + 0x20);
    memoryASet32(ds, 0x40fa60, edx);
    ecx = memoryAGet32(ds, eax + 0x30);
    memoryASet32(ds, 0x40fa64, ecx);
    edx = memoryAGet32(ds, eax + 0xd0);
    memoryASet32(ds, 0x40fa68, edx);
    ecx = memoryAGet32(ds, eax + 0xe0);
    memoryASet32(ds, 0x40fa6c, ecx);
    edx = memoryAGet32(ds, eax + 0xc0);
    memoryASet32(ds, 0x40fa70, edx);
    ecx = memoryAGet32(ds, eax + 0xb0);
    memoryASet32(ds, 0x40fa74, ecx);
    edx = memoryAGet32(ds, eax + 0x80);
    memoryASet32(ds, 0x40fa78, edx);
    ecx = memoryAGet32(ds, eax + 0x150);
    memoryASet32(ds, 0x40fa7c, ecx);
    edx = memoryAGet32(ds, eax + 0x180);
    memoryASet32(ds, 0x40fa88, edx);
    ecx = memoryAGet32(ds, eax + 0x160);
    memoryASet32(ds, 0x40fa8c, ecx);
    edx = memoryAGet32(ds, eax);
    memoryASet32(ds, 0x40fa90, edx);
    ecx = memoryAGet32(ds, eax + 0x50);
    memoryASet32(ds, 0x40fa94, ecx);
    edx = memoryAGet32(ds, eax + 0x110);
    memoryASet32(ds, 0x40fa98, edx);
    ecx = memoryAGet32(ds, eax + 0x70);
    memoryASet32(ds, 0x40fa9c, ecx);
    edx = memoryAGet32(ds, eax + 0x120);
    memoryASet32(ds, 0x40faa0, edx);
    ecx = memoryAGet32(ds, eax + 0x40);
    memoryASet32(ds, 0x40faa4, ecx);
    edx = memoryAGet32(ds, eax + 0x130);
    memoryASet32(ds, 0x40faa8, edx);
    ecx = memoryAGet32(ds, eax + 0xf0);
    memoryASet32(ds, 0x40fa80, ecx);
    edx = memoryAGet32(ds, eax + 0x100);
    memoryASet32(ds, 0x40fa84, edx);
    goto loc_401c16;
loc_401a93: // 0000:401a93
    push32(0x0040e934);
    push32(0x0040fa48);
    sub_4015d0();
    push32(0x0040e924);
    push32(0x0040fa4c);
    sub_4015d0();
    push32(0x0040e914);
    push32(0x0040fa50);
    sub_4015d0();
    push32(0x0040e908);
    push32(0x0040fa54);
    sub_4015d0();
    push32(0x0040e8f8);
    push32(0x0040fa58);
    sub_4015d0();
    push32(0x0040e8e8);
    push32(0x0040fa5c);
    sub_4015d0();
    push32(0x0040e8d8);
    push32(0x0040fa60);
    sub_4015d0();
    push32(0x0040e8c8);
    push32(0x0040fa64);
    sub_4015d0();
    esp += 0x00000040;
    push32(0x0040e8b8);
    push32(0x0040fa68);
    sub_4015d0();
    push32(0x0040e8a4);
    push32(0x0040fa6c);
    sub_4015d0();
    push32(0x0040e894);
    push32(0x0040fa70);
    sub_4015d0();
    push32(0x0040e884);
    push32(0x0040fa74);
    sub_4015d0();
    push32(0x0040e870);
    push32(0x0040fa78);
    sub_4015d0();
    push32(0x0040e85c);
    push32(0x0040fa7c);
    sub_4015d0();
    push32(0x0040e850);
    push32(0x0040fa88);
    sub_4015d0();
    push32(0x0040e840);
    push32(0x0040fa8c);
    sub_4015d0();
    esp += 0x00000040;
    push32(0x0040e830);
    push32(0x0040fa90);
    sub_4015d0();
    push32(0x0040e820);
    push32(0x0040fa94);
    sub_4015d0();
    push32(0x0040e810);
    push32(0x0040fa98);
    sub_4015d0();
    push32(0x0040e800);
    push32(0x0040fa9c);
    sub_4015d0();
    push32(0x0040e7f0);
    push32(0x0040faa0);
    sub_4015d0();
    push32(0x0040e7dc);
    push32(0x0040fa80);
    sub_4015d0();
    push32(0x0040e7c8);
    push32(0x0040fa84);
    sub_4015d0();
    push32(0x0040e7b8);
    push32(0x0040faa4);
    sub_4015d0();
    esp += 0x00000040;
    push32(0x0040e7a8);
    push32(0x0040faa8);
    sub_4015d0();
    esp += 0x00000008;
loc_401c16: // 0000:401c16
    push32(0x0040e79c);
    eax = alleg40::exists(stack32<const char>(0));();
    esp += 0x00000004;
    if (!eax)
        goto loc_401c32;
    memoryASet32(ds, 0x40fa30, 0xffffffff);
loc_401c32: // 0000:401c32
    push32(0x00000001);
    eax = alleg40::set_display_switch_mode(stack32<int>(0));();
    push32(0xffffffff);
    alleg40::text_mode(stack32<int>(0));();
    esp += 0x00000008;
    eax |= 0xffffffff;
    edi = pop32();
    esi = pop32();
    esp += 4; return;
loc_401c4b: // 0000:401c4b
    push32(0x0040e774);
    alleg40::allegro_message(stack32<const char>(0));();
    esp += 0x00000004;
    eax = 0;
    edi = pop32();
    esi = pop32();
    esp += 4;
}
void sub_401c60() // 0000:401c60 +long
{
    esp -= 4;
    push32(esi);
    push32(0x0040ea58);
    push32(0x0040e964);
    eax = alleg40::pack_fopen(stack32<const char>(0), stack32<const char>(1));();
    esi = eax;
    esp += 0x00000008;
    if (!esi)
        goto loc_401c9b;
    push32(esi);
    push32(0x0040e040);
    sub_4064c0();
    eax = memoryAGet32(ds, 0x40fa3c);
    push32(esi);
    push32(eax);
    sub_401430();
    push32(esi);
    eax = alleg40::pack_fclose(stack32<PACKFILE>(0));();
    esp += 0x00000014;
loc_401c9b: // 0000:401c9b
    eax = memoryAGet32(ds, 0x40fa44);
    push32(edi);
    if (eax)
        goto loc_401d59;
    edi = memoryAGet32(ds, 0x40d11c);
    esi = 0x0040fa48;
loc_401cb4: // 0000:401cb4
    eax = memoryAGet32(ds, esi);
    if (!eax)
        goto loc_401cc0;
    push32(eax);
    indirectCall(cs, edi); // 0000:401cbb
    esp += 0x00000004;
loc_401cc0: // 0000:401cc0
    esi += 0x00000004;
    if ((int32_t)esi < (int32_t)0x0040fa60)
        goto loc_401cb4;
    esi = 0x0040fa68;
loc_401cd0: // 0000:401cd0
    eax = memoryAGet32(ds, esi);
    if (!eax)
        goto loc_401cdc;
    push32(eax);
    indirectCall(cs, edi); // 0000:401cd7
    esp += 0x00000004;
loc_401cdc: // 0000:401cdc
    esi += 0x00000004;
    if ((int32_t)esi < (int32_t)0x0040fa74)
        goto loc_401cd0;
    esi = 0x0040fa74;
loc_401cec: // 0000:401cec
    eax = memoryAGet32(ds, esi);
    if (!eax)
        goto loc_401cf8;
    push32(eax);
    indirectCall(cs, edi); // 0000:401cf3
    esp += 0x00000004;
loc_401cf8: // 0000:401cf8
    esi += 0x00000004;
    if ((int32_t)esi < (int32_t)0x0040fa80)
        goto loc_401cec;
    esi = 0x0040fa80;
loc_401d08: // 0000:401d08
    eax = memoryAGet32(ds, esi);
    if (!eax)
        goto loc_401d14;
    push32(eax);
    indirectCall(cs, edi); // 0000:401d0f
    esp += 0x00000004;
loc_401d14: // 0000:401d14
    esi += 0x00000004;
    if ((int32_t)esi < (int32_t)0x0040fa88)
        goto loc_401d08;
    esi = 0x0040fa88;
loc_401d24: // 0000:401d24
    eax = memoryAGet32(ds, esi);
    if (!eax)
        goto loc_401d30;
    push32(eax);
    indirectCall(cs, edi); // 0000:401d2b
    esp += 0x00000004;
loc_401d30: // 0000:401d30
    esi += 0x00000004;
    if ((int32_t)esi < (int32_t)0x0040faac)
        goto loc_401d24;
    eax = memoryAGet32(ds, 0x40fa60);
    if (!eax)
        goto loc_401d4a;
    push32(eax);
    indirectCall(cs, edi); // 0000:401d45
    esp += 0x00000004;
loc_401d4a: // 0000:401d4a
    eax = memoryAGet32(ds, 0x40fa64);
    if (!eax)
        goto loc_401d59;
    push32(eax);
    indirectCall(cs, edi); // 0000:401d54
    esp += 0x00000004;
loc_401d59: // 0000:401d59
    eax = memoryAGet32(ds, 0x40fa40);
    esi = memoryAGet32(ds, 0x40d120);
    edi = pop32();
    if (!eax)
        goto loc_401d6f;
    push32(eax);
    indirectCall(cs, esi); // 0000:401d6a
    esp += 0x00000004;
loc_401d6f: // 0000:401d6f
    eax = memoryAGet32(ds, 0x40fa44);
    if (!eax)
        goto loc_401d7e;
    push32(eax);
    indirectCall(cs, esi); // 0000:401d79
    esp += 0x00000004;
loc_401d7e: // 0000:401d7e
    eax = memoryAGet32(ds, 0x40fa34);
    esi = pop32();
    if (!eax)
        goto loc_401d92;
    push32(eax);
    alleg40::destroy_bitmap(stack32<BITMAP>(0));();
    esp += 0x00000004;
loc_401d92: // 0000:401d92
    eax = memoryAGet32(ds, 0x40fa3c);
    if (!eax)
        goto loc_401da4;
    push32(eax);
    sub_401240();
    esp += 0x00000004;
loc_401da4: // 0000:401da4
    indirectJump(cs, memoryAGet32(ds, 0x40d128)); return; // 0000:401da4
}
void sub_401db0() // 0000:401db0 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000038;
    push32(ebx);
    eax = 0;
    push32(esi);
    push32(edi);
    memoryASet32(ss, ebp - 4, eax);
    goto loc_401dc3;
loc_401dc0: // 0000:401dc0
    eax = memoryAGet32(ss, ebp - 4);
loc_401dc3: // 0000:401dc3
    edi = eax;
    memoryASet32(ss, ebp - 12, 0x0000000f);
    edi = ~edi;
    edi &= 0x00000001;
    edi <<= 5;
    eax <<= 5;
    memoryASet32(ss, ebp - 8, eax);
    goto loc_401ddf;
loc_401ddc: // 0000:401ddc
    eax = memoryAGet32(ss, ebp - 8);
loc_401ddf: // 0000:401ddf
    ecx = edi;
    esi = 0x00000040;
    ecx = sar32(ecx, 0x02);
    esi -= ecx;
    push32(0x00000020);
    ebx = esi;
    edx = edi;
    ebx = sar32(ebx, 0x00000001);
    push32(esi);
    push32(eax);
    eax = memoryAGet32(ds, 0x40fa40);
    edx -= ebx;
    edx += 0x00000140;
    ecx = memoryAGet32(ds, eax + 0x10);
    push32(edx);
    edx = memoryAGet32(ds, 0x40fa34);
    push32(ecx);
    push32(edx);
    alleg40::stretch_sprite(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));();
    eax = memoryAGet32(ss, ebp - 8);
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = 0x00000140;
    push32(0x00000020);
    ecx -= ebx;
    push32(esi);
    ecx -= edi;
    push32(eax);
    eax = memoryAGet32(ds, edx + 0x10);
    push32(ecx);
    ecx = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    push32(ecx);
    alleg40::stretch_sprite(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));();
    eax = memoryAGet32(ss, ebp - 12);
    esp += 0x00000030;
    edi += esi;
    eax--;
    memoryASet32(ss, ebp - 12, eax);
    if (eax)
        goto loc_401ddc;
    eax = memoryAGet32(ss, ebp - 4);
    eax++;
    memoryASet32(ss, ebp - 4, eax);
    if ((int32_t)eax < (int32_t)0x00000004)
        goto loc_401dc0;
    memoryASet32(ss, ebp - 4, 0x00000000);
loc_401e61: // 0000:401e61
    edi = 0;
    memoryASet32(ss, ebp - 8, 0x00000140);
loc_401e6a: // 0000:401e6a
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 4);
    indirectCall(cs, ecx); // 0000:401e7c
    ecx = 0;
    cl = memoryAGet(ds, eax + edi);
    esi = ecx;
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:401e8e
    memoryASet32(ss, ebp - 12, esi);
    if ((int32_t)esi < (int32_t)0x00000010)
        goto loc_401e9d;
    if ((int32_t)esi <= (int32_t)0x0000001f)
        goto loc_401ea4;
loc_401e9d: // 0000:401e9d
    memoryASet32(ss, ebp - 12, 0x00000014);
loc_401ea4: // 0000:401ea4
    eax = edi - 320;
    ecx = eax;
    if ((int32_t)eax >= 0)
        goto loc_401eb3;
    ecx = memoryAGet32(ss, ebp - 8);
loc_401eb3: // 0000:401eb3
    eax = 0x2aaaaaab;
    imul32(ecx);
    eax = edx;
    eax >>= 31;
    edx += eax;
    memoryASet32(ss, ebp - 16, edx);
    fild32(memoryAGet32(ss, ebp - 16));
    fcom64(memoryAGet64(ds, 0x40d1f0));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_401eeb;
    ecx = memoryAGet32(ds, 0x40d110);
    eax = 0x7fffffff;
    st(0) = fstp80();
    edx = memoryAGet32(ds, ecx);
    memoryASet32(ds, edx, 0x00000022);
    goto loc_401f3a;
loc_401eeb: // 0000:401eeb
    fcom64(memoryAGet64(ds, 0x40d1e8));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_401f0e;
    eax = memoryAGet32(ds, 0x40d110);
    st(0) = fstp80();
    ecx = memoryAGet32(ds, eax);
    eax = 0x80000001;
    memoryASet32(ds, ecx, 0x00000022);
    goto loc_401f3a;
loc_401f0e: // 0000:401f0e
    fcom64(memoryAGet64(ds, 0x40d1e0));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_401f23;
    fld64(memoryAGet64(ds, 0x40d1d8));
    goto loc_401f29;
loc_401f23: // 0000:401f23
    fld64(memoryAGet64(ds, 0x40d1d0));
loc_401f29: // 0000:401f29
    stop("disassembly failed at 0000:401f29 (fxch st(1))");
    fmul64(memoryAGet64(ds, 0x40d1c8));
    fadd80(st(1));
    sub_406e04();
    st(0) = fstp80();
loc_401f3a: // 0000:401f3a
    edx = memoryAGet32(ds, 0x40d114);
    eax += 0x00004000;
    eax = sar32(eax, 0x0f);
    eax &= 0x000001ff;
    eax = memoryAGet32(ds, edx + eax * 4);
    memoryASet32(ss, ebp - 20, eax);
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000003;
    idiv32(ecx);
    memoryASet32(ss, ebp - 16, edx);
    fild32(memoryAGet32(ss, ebp - 16));
    fild32(memoryAGet32(ss, ebp - 12));
    fild32(memoryAGet32(ss, ebp - 20));
    fmul64(memoryAGet64(ds, 0x40d1c0));
    fsubp80(st(1));
    faddp80(st(1));
    fsub64(memoryAGet64(ds, 0x40d1b8));
    sub_406e04();
    ebx = eax;
    if ((int32_t)ebx >= (int32_t)0x00000010)
        goto loc_401f8f;
    ebx = 0x00000010;
    goto loc_401f99;
loc_401f8f: // 0000:401f8f
    if ((int32_t)ebx <= (int32_t)0x0000001f)
        goto loc_401f99;
    ebx = 0x0000001f;
loc_401f99: // 0000:401f99
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x20);
    eax = memoryAGet32(ss, ebp - 4);
    indirectCall(cs, ecx); // 0000:401fab
    memoryASet(ds, eax + edi, bl);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:401fb9
    eax = memoryAGet32(ss, ebp - 8);
    edi++;
    eax--;
    memoryASet32(ss, ebp - 8, eax);
    if ((int32_t)eax > (int32_t)0xfffffec0)
        goto loc_401e6a;
    eax = memoryAGet32(ss, ebp - 4);
    eax++;
    memoryASet32(ss, ebp - 4, eax);
    if ((int32_t)eax < (int32_t)0x00000080)
        goto loc_401e61;
    edi = 0x00000020;
    memoryASet32(ss, ebp - 4, edi);
loc_401fe8: // 0000:401fe8
    ebx = edi - 1;
    edi++;
    esi = 0x00000001;
    memoryASet32(ss, ebp - 20, ebx);
    memoryASet32(ss, ebp - 8, ebx);
    memoryASet32(ss, ebp - 24, edi);
    goto loc_401fff;
loc_401ffc: // 0000:401ffc
    ebx = memoryAGet32(ss, ebp - 20);
loc_401fff: // 0000:401fff
    eax = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 12, eax);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 4);
    indirectCall(cs, ecx); // 0000:402010
    ecx = 0;
    cl = memoryAGet(ds, eax + esi);
    memoryASet32(ss, ebp - 56, ecx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:402023
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 16, ebx);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 16);
    indirectCall(cs, ecx); // 0000:40203a
    ecx = 0;
    cl = memoryAGet(ds, eax + esi + 0x1);
    memoryASet32(ss, ebp - 52, ecx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:40204e
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 4);
    indirectCall(cs, ecx); // 0000:402062
    ecx = 0;
    cl = memoryAGet(ds, eax + esi + 0x1);
    memoryASet32(ss, ebp - 48, ecx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:402076
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 16, edi);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 16);
    indirectCall(cs, ecx); // 0000:40208d
    ecx = 0;
    cl = memoryAGet(ds, eax + esi + 0x1);
    memoryASet32(ss, ebp - 44, ecx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:4020a1
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 16, ebx);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 16);
    indirectCall(cs, ecx); // 0000:4020b8
    ebx = 0;
    bl = memoryAGet(ds, eax + esi);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:4020c8
    eax = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 12, eax);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 4);
    indirectCall(cs, ecx); // 0000:4020db
    ecx = 0;
    cl = memoryAGet(ds, eax + esi);
    memoryASet32(ss, ebp - 40, ecx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:4020ee
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 16, edi);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 16);
    indirectCall(cs, ecx); // 0000:402105
    ecx = 0;
    cl = memoryAGet(ds, eax + esi);
    memoryASet32(ss, ebp - 36, ecx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:402118
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 8);
    indirectCall(cs, ecx); // 0000:40212c
    ecx = 0;
    cl = memoryAGet(ds, eax + esi - 1);
    memoryASet32(ss, ebp - 32, ecx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:402140
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 4);
    indirectCall(cs, ecx); // 0000:402154
    ecx = 0;
    cl = memoryAGet(ds, eax + esi - 1);
    memoryASet32(ss, ebp - 28, ecx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:402168
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x24);
    eax = memoryAGet32(ss, ebp - 24);
    indirectCall(cs, ecx); // 0000:40217c
    ecx = 0;
    cl = memoryAGet(ds, eax + esi - 1);
    memoryASet32(ss, ebp - 16, ecx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:402190
    edx = memoryAGet32(ss, ebp - 16);
    eax = memoryAGet32(ss, ebp - 28);
    ecx = edx + eax;
    edx = memoryAGet32(ss, ebp - 32);
    eax = memoryAGet32(ss, ebp - 36);
    ecx += edx;
    edx = memoryAGet32(ss, ebp - 40);
    ecx += eax;
    eax = memoryAGet32(ss, ebp - 48);
    ecx += edx;
    edx = memoryAGet32(ss, ebp - 44);
    ecx += ebx;
    ebx = memoryAGet32(ss, ebp - 52);
    ecx += edx;
    edx = memoryAGet32(ss, ebp - 56);
    ecx += eax;
    ecx += ebx;
    eax = 0x66666667;
    ecx += edx;
    imul32(ecx);
    edx = sar32(edx, 0x02);
    ecx = edx;
    ecx >>= 31;
    edx += ecx;
    ebx = edx;
    if ((int32_t)ebx >= (int32_t)0x00000010)
        goto loc_4021df;
    ebx = 0x00000010;
    goto loc_4021e9;
loc_4021df: // 0000:4021df
    if ((int32_t)ebx <= (int32_t)0x0000001f)
        goto loc_4021e9;
    ebx = 0x0000001f;
loc_4021e9: // 0000:4021e9
    edx = memoryAGet32(ds, 0x40fa34);
    memoryASet32(ss, ebp - 12, edx);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x20);
    eax = memoryAGet32(ss, ebp - 4);
    indirectCall(cs, ecx); // 0000:4021fb
    memoryASet(ds, eax + esi, bl);
    edx = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, edx + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x8);
    indirectCall(cs, ecx); // 0000:402209
    esi++;
    if ((int32_t)esi < (int32_t)0x0000027f)
        goto loc_401ffc;
    memoryASet32(ss, ebp - 4, edi);
    if ((int32_t)edi < (int32_t)0x00000060)
        goto loc_401fe8;
    eax = memoryAGet32(ds, 0x40fa38);
    ecx = memoryAGet32(ds, 0x40fa34);
    push32(0x00000040);
    push32(0x00000280);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000020);
    push32(0x00000000);
    push32(eax);
    push32(ecx);
    alleg40::blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));();
    esp += 0x00000020;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 4;
}
void sub_402250() // 0000:402250 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x40d108);
    eax = memoryAGet32(ds, eax);
    ecx = memoryAGet32(ds, eax + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x10);
    if (!ecx)
        goto loc_402267;
    push32(eax);
    indirectCall(cs, ecx); // 0000:402262
    esp += 0x00000004;
loc_402267: // 0000:402267
    eax = memoryAGet32(ds, esp + 0x4);
    edx = memoryAGet32(ds, eax + 0x4);
    ecx = memoryAGet32(ds, eax);
    push32(edx);
    edx = memoryAGet32(ds, 0x40d108);
    push32(ecx);
    push32(0x00000000);
    ecx = memoryAGet32(ds, edx);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(ecx);
    push32(eax);
    alleg40::blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));();
    edx = memoryAGet32(ds, 0x40d108);
    esp += 0x00000020;
    eax = memoryAGet32(ds, edx);
    ecx = memoryAGet32(ds, eax + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x14);
    if (!ecx)
        goto loc_4022a3;
    push32(eax);
    indirectCall(cs, ecx); // 0000:4022a0
    ecx = pop32();
loc_4022a3: // 0000:4022a3
    esp += 4; return;
}
void sub_4022b0() // 0000:4022b0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x40e054);
    esp -= 0x00000400;
    if (!eax)
        goto loc_402314;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x40c);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x40c);
    push32(esi);
    eax = esp + 12;
    push32(edi);
    push32(eax);
    alleg40::get_palette_range(stack32<PALETTE>(0), stack32<int>(1), stack32<int>(2), stack32<PALETTE>(3));();
    edx = memoryAGet32(ds, esp + esi * 4 + 0x14);
    eax = (esp + (esi * 4)) + 20;
    esp += 0x0000000c;
    if ((int32_t)esi <= (int32_t)edi)
        goto loc_4022fc;
    ecx = esi;
    push32(ebx);
    ecx -= edi;
loc_4022f0: // 0000:4022f0
    ebx = memoryAGet32(ds, eax - 4);
    memoryASet32(ds, eax, ebx);
    eax += 0xfffffffc;
    ecx--;
    if (ecx)
        goto loc_4022f0;
    ebx = pop32();
loc_4022fc: // 0000:4022fc
    push32(0x00000000);
    push32(esi);
    ecx = esp + 16;
    push32(edi);
    push32(ecx);
    memoryASet32(ds, esp + edi * 4 + 0x18, edx);
    alleg40::set_palette_range(stack32<const PALETTE>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3));();
    esp += 0x00000010;
    edi = pop32();
    esi = pop32();
loc_402314: // 0000:402314
    esp += 0x00000400;
    esp += 4;
}
void sub_402320() // 0000:402320 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x0000000c;
    eax = memoryAGet32(ds, 0x40e054);
    push32(ebx);
    push32(esi);
    push32(edi);
    if (!eax)
        goto loc_4023e2;
    esi = memoryAGet32(ds, 0x42be00);
    edi = memoryAGet32(ds, 0x42bbc8);
    eax = esi;
    push32(0x00000000);
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    ecx = memoryAGet32(ds, edi + 0x4);
    eax = sar32(eax, 0x00000001);
    memoryASet32(ss, ebp - 4, eax);
    eax = memoryAGet32(ss, ebp + 0x8);
    fild32(memoryAGet32(ss, ebp - 4));
    fild32(memoryAGet32(ds, edi + 0x4));
    edx = memoryAGet32(ds, eax + 0x1c);
    ebx = memoryAGet32(ds, edi);
    eax = esi;
    push32(esi);
    fmul80(st(1));
    eax <<= 8;
    ecx <<= 15;
    fmul64(memoryAGet64(ds, 0x40d208));
    fild32(memoryAGet32(ds, 0x42be00));
    push32(eax);
    push32(ecx);
    ebx <<= 15;
    fmul64(memoryAGet64(ds, 0x40d200));
    push32(ebx);
    memoryASet32(ss, ebp - 4, edx);
    faddp80(st(1));
    sub_406e04();
    ecx = 0x00000168;
    ecx -= eax;
    eax = memoryAGet32(ds, edi + 0x4);
    eax = (int32_t)eax * (int32_t)esi;
    fild32(memoryAGet32(ds, edi));
    fmul80(st(1));
    fmul64(memoryAGet64(ds, 0x40d1f8));
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    ecx <<= 16;
    eax = sar32(eax, 0x00000001);
    ecx += eax;
    push32(ecx);
    sub_406e04();
    ecx = 0x00000140;
    ecx -= eax;
    eax = memoryAGet32(ds, edi);
    eax = (int32_t)eax * (int32_t)esi;
    st(0) = fstp80();
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edx = memoryAGet32(ss, ebp + 0x8);
    ecx <<= 16;
    eax = sar32(eax, 0x00000001);
    ecx += eax;
    eax = memoryAGet32(ss, ebp - 4);
    push32(ecx);
    push32(edi);
    push32(edx);
    indirectCall(cs, memoryAGet32(ds, eax + 0xa0)); // 0000:4023d4
    esp += 0x00000024;
    goto loc_4024b1;
loc_4023e2: // 0000:4023e2
    ecx = memoryAGet32(ds, 0x42bbc8);
    ecx = memoryAGet32(ds, ecx + 0x4);
    ecx = (int32_t)ecx * ((int32_t)memoryAGet32(ds, 0x42be00));
    memoryASet32(ss, ebp - 4, ecx);
    eax = memoryAGet32(ss, ebp - 4);
    eax = sar32(eax, 0x10);
    edx = memoryAGet32(ds, 0x42bbc8);
    ebx = eax;
    esi = memoryAGet32(ds, edx);
    esi = (int32_t)esi * ((int32_t)memoryAGet32(ds, 0x42be00));
    memoryASet32(ss, ebp - 4, esi);
    eax = memoryAGet32(ss, ebp - 4);
    eax = sar32(eax, 0x10);
    memoryASet32(ss, ebp - 8, eax);
    eax = memoryAGet32(ds, 0x42bbc8);
    eax = memoryAGet32(ds, eax + 0x4);
    eax = (int32_t)eax * ((int32_t)memoryAGet32(ds, 0x42be00));
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edi = eax;
    edi = sar32(edi, 0x00000001);
    memoryASet32(ss, ebp - 4, edi);
    eax = memoryAGet32(ss, ebp - 4);
    eax = sar32(eax, 0x10);
    ecx = sar32(ecx, 0x0f);
    memoryASet32(ss, ebp - 12, eax);
    eax = memoryAGet32(ds, 0x42be00);
    ecx &= 0x00000001;
    ecx += ebx;
    edx = (int32_t)eax < 0 ? -1 : 0;
    esi = sar32(esi, 0x0f);
    push32(ecx);
    ecx = memoryAGet32(ss, ebp - 8);
    esi &= 0x00000001;
    eax -= edx;
    esi += ecx;
    eax = sar32(eax, 0x00000001);
    push32(esi);
    esi = memoryAGet32(ds, 0x42bbc8);
    memoryASet32(ss, ebp - 4, eax);
    fild32(memoryAGet32(ss, ebp - 4));
    fild32(memoryAGet32(ds, esi + 0x4));
    fmul80(st(1));
    fmul64(memoryAGet64(ds, 0x40d1f8));
    sub_406e04();
    fild32(memoryAGet32(ds, esi));
    edx = memoryAGet32(ss, ebp - 12);
    ecx = 0x00000168;
    edi = sar32(edi, 0x0f);
    fmul80(st(1));
    ecx -= eax;
    edi &= 0x00000001;
    ecx -= edi;
    fmul64(memoryAGet64(ds, 0x40d1f8));
    ecx -= edx;
    push32(ecx);
    sub_406e04();
    edx = 0x00000140;
    edx -= eax;
    eax = memoryAGet32(ss, ebp + 0x8);
    push32(edx);
    push32(esi);
    push32(eax);
    st(0) = fstp80();
    alleg40::stretch_sprite(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));();
    esp += 0x00000018;
loc_4024b1: // 0000:4024b1
    eax = memoryAGet32(ds, 0x40fcac);
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    if ((int32_t)eax <= (int32_t)0x0000003c)
        goto loc_4024c8;
    memoryASet32(ds, 0x42be00, memoryAGet32(ds, 0x42be00) + 0x00000ccd);
loc_4024c8: // 0000:4024c8
    if ((int32_t)eax >= (int32_t)0x0000000a)
        goto loc_4024d7;
    memoryASet32(ds, 0x42be00, memoryAGet32(ds, 0x42be00) - 0x0000199a);
loc_4024d7: // 0000:4024d7
    eax--;
    memoryASet32(ds, 0x40fcac, eax);
    esp = ebp;
    ebp = pop32();
    esp += 4;
}
void sub_4024f0() // 0000:4024f0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    push32(ebx);
    push32(ebp);
    push32(edi);
    ebp = 0x00000005;
    memoryASet32(ds, 0x40fcac, 0x00000050);
    memoryASet32(ds, 0x42be00, 0x00000000);
    if ((int32_t)eax >= (int32_t)0x00000007)
        goto loc_402519;
    ebp = 0;
    goto loc_402547;
loc_402519: // 0000:402519
    if ((int32_t)eax >= (int32_t)0x0000000f)
        goto loc_402525;
    ebp = 0x00000001;
    goto loc_402547;
loc_402525: // 0000:402525
    if ((int32_t)eax >= (int32_t)0x00000019)
        goto loc_402531;
    ebp = 0x00000002;
    goto loc_402547;
loc_402531: // 0000:402531
    if ((int32_t)eax >= (int32_t)0x00000023)
        goto loc_40253d;
    ebp = 0x00000003;
    goto loc_402547;
loc_40253d: // 0000:40253d
    if ((int32_t)eax >= (int32_t)0x0000002d)
        goto loc_402547;
    ebp = 0x00000004;
loc_402547: // 0000:402547
    eax = memoryAGet32(ds, 0x40e054);
    if (!eax)
        goto loc_4025e4;
    if ((int32_t)ebp <= (int32_t)0x00000002)
        goto loc_4025e4;
    edi = ebp - 2;
    ebx = edi;
    ebx <<= 4;
    if ((int32_t)ebx <= 0)
        goto loc_4025e4;
    push32(esi);
loc_40256a: // 0000:40256a
    push32(0x00000168);
    push32(0x00000140);
    push32(0x0040ffe0);
    sub_406500();
    esi = eax + (eax * 2);
    esp += 0x0000000c;
    esi <<= 3;
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x000001f4;
    idiv32(ecx);
    eax = 0xae147ae1;
    edx += ecx;
    edx <<= 16;
    imul32(edx);
    edx = sar32(edx, 0x05);
    eax = edx;
    eax >>= 31;
    edx += eax;
    memoryASet32(ds, esi + 0x40fff0, edx);
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x000003e8;
    idiv32(ecx);
    eax = 0x51eb851f;
    edx -= 0x000001f4;
    edx = (int32_t)edx * (int32_t)edi;
    edx <<= 16;
    imul32(edx);
    edx = sar32(edx, 0x05);
    eax = edx;
    eax >>= 31;
    edx += eax;
    ebx--;
    memoryASet32(ds, esi + 0x40ffec, edx);
    if (ebx)
        goto loc_40256a;
    esi = pop32();
loc_4025e4: // 0000:4025e4
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = ebp + 46;
    ecx <<= 4;
    push32(0x00000000);
    eax = memoryAGet32(ds, ecx + edx);
    ecx = memoryAGet32(ds, ebp * 4 + 0x40fa48);
    push32(ecx);
    memoryASet32(ds, 0x42bbc8, eax);
    sub_401570();
    esp += 0x00000008;
    edi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 4;
}
void sub_402610() // 0000:402610 +long
{
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0x4);
    fld64(memoryAGet64(ds, ecx + 0x18));
    fcomp64(memoryAGet64(ds, 0x40d218));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_402635;
    eax = memoryAGet32(ds, 0x40fa70);
    push32(0x00000001);
    push32(eax);
    sub_401570();
    esp += 0x00000008;
    esp += 4; return;
loc_402635: // 0000:402635
    fld64(memoryAGet64(ds, ecx + 0x18));
    fcomp64(memoryAGet64(ds, 0x40d210));
    push32(0x00000001);
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_402657;
    ecx = memoryAGet32(ds, 0x40fa6c);
    push32(ecx);
    sub_401570();
    esp += 0x00000008;
    esp += 4; return;
loc_402657: // 0000:402657
    edx = memoryAGet32(ds, 0x40fa68);
    push32(edx);
    sub_401570();
    esp += 0x00000008;
    esp += 4;
}
void sub_402670() // 0000:402670 +long
{
    esp -= 4;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x8);
    if (!esi)
        goto loc_40277d;
    push32(esi);
    sub_401060();
    push32(esi);
    sub_4011e0();
    esp += 0x00000008;
    if (!eax)
        goto loc_4026b1;
    fld64(memoryAGet64(ds, 0x412ff0));
    fcom64(memoryAGet64(ds, 0x40d1e0));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_4026a9;
    fmul64(memoryAGet64(ds, 0x40d230));
loc_4026a9: // 0000:4026a9
    fsub64(memoryAGet64(ds, 0x40d228));
    goto loc_4026f2;
loc_4026b1: // 0000:4026b1
    push32(esi);
    sub_4011f0();
    esp += 0x00000004;
    if (!eax)
        goto loc_4026df;
    fld64(memoryAGet64(ds, 0x412ff0));
    fcom64(memoryAGet64(ds, 0x40d1e0));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_4026d7;
    fmul64(memoryAGet64(ds, 0x40d230));
loc_4026d7: // 0000:4026d7
    fadd64(memoryAGet64(ds, 0x40d228));
    goto loc_4026f2;
loc_4026df: // 0000:4026df
    eax = memoryAGet32(ds, 0x413010);
    fld64(memoryAGet64(ds, 0x412ff0));
    fmul64(memoryAGet64(ds, 0x40d220));
loc_4026f2: // 0000:4026f2
    eax = memoryAGet32(ds, 0x40e048);
    push32(esi);
    memoryASet64(ds, 0x412ff0, fstp64());
    if (eax)
        goto loc_402753;
    sub_401200();
    esp += 0x00000004;
    if (!eax)
        goto loc_40273f;
    eax = memoryAGet32(ds, 0x413014);
    if (eax)
        goto loc_40273f;
    push32(0x00412fe0);
    sub_406800();
    esp += 0x00000004;
    if (!eax)
        goto loc_40273f;
    push32(0x00412fe0);
    memoryASet32(ds, 0x413014, 0xffffffff);
    sub_402610();
    esp += 0x00000004;
loc_40273f: // 0000:40273f
    push32(esi);
    sub_401200();
    esp += 0x00000004;
    if (eax)
        goto loc_40277d;
    memoryASet32(ds, 0x413014, eax);
    esi = pop32();
    esp += 4; return;
loc_402753: // 0000:402753
    sub_401200();
    esp += 0x00000004;
    if (!eax)
        goto loc_40277d;
    push32(0x00412fe0);
    sub_406800();
    esp += 0x00000004;
    if (!eax)
        goto loc_40277d;
    push32(0x00412fe0);
    sub_402610();
    esp += 0x00000004;
loc_40277d: // 0000:40277d
    esi = pop32();
    esp += 4;
}
void sub_402780() // 0000:402780 +long
{
    bool temp_cond0;
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x0000001c;
    push32(ebx);
    eax = 0;
    push32(esi);
    push32(edi);
    memoryASet32(ss, ebp - 4, eax);
    memoryASet32(ss, ebp - 20, eax);
    memoryASet32(ss, ebp - 16, eax);
    memoryASet32(ss, ebp - 12, eax);
    eax = memoryAGet32(ds, 0x40ffc4);
    eax++;
    memoryASet32(ds, 0x40ffc4, eax);
    esi = memoryAGet32(ss, ebp + 0x8);
    edi = memoryAGet32(ds, 0x40d118);
    ebx = 0xffffffc0;
loc_4027b0: // 0000:4027b0
    eax = memoryAGet32(ds, 0x40ffc0);
    push32(0x00000040);
    eax &= 0x8000007f;
    push32(0x00000208);
    if ((int32_t)eax >= 0)
        goto loc_4027c8;
    eax--;
    eax |= 0xffffff80;
    eax++;
loc_4027c8: // 0000:4027c8
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    ecx = memoryAGet32(ds, 0x40fa38);
    eax = sar32(eax, 0x00000001);
    eax += ebx;
    push32(eax);
    push32(0x0000003c);
    push32(0x00000000);
    push32(0x0000003c);
    push32(esi);
    push32(ecx);
    indirectCall(cs, edi); // 0000:4027de
    ebx += 0x00000040;
    esp += 0x00000020;
    if ((int32_t)ebx < (int32_t)0x00000200)
        goto loc_4027b0;
    edi = memoryAGet32(ds, 0x413324);
    if ((int32_t)edi >= (int32_t)0x000001e0)
        goto loc_402852;
    if ((int32_t)edi <= (int32_t)0xffffff9c)
        goto loc_402852;
    edx = memoryAGet32(ds, 0x40fa40);
    push32(edi);
    ecx = memoryAGet32(ds, edx + 0x2b0);
    eax = memoryAGet32(ds, ecx);
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edx = eax;
    eax = 0x00000140;
    edx = sar32(edx, 0x00000001);
    eax -= edx;
    edx = memoryAGet32(ds, ecx + 0x1c);
    push32(eax);
    push32(ecx);
    ebx = memoryAGet32(ds, edx);
    edx = memoryAGet32(ds, esi + 0x1c);
    push32(esi);
    if (ebx != 0x00000008)
        goto loc_402833;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:40282e
    goto loc_402836;
loc_402833: // 0000:402833
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:402833
loc_402836: // 0000:402836
    esp += 0x00000010;
    push32(0x000000ef);
    push32(0x000000e0);
    sub_4022b0();
    esp += 0x00000008;
    memoryASet32(ss, ebp - 20, 0x00000001);
loc_402852: // 0000:402852
    memoryASet32(ss, ebp + 0x8, 0x000001f0);
    ebx = 0x0040ffb0;
    memoryASet32(ss, ebp - 24, 0xffffffe0);
loc_402865: // 0000:402865
    eax = memoryAGet32(ds, ebx - 8);
    if (eax)
        goto loc_4029cd;
    eax = memoryAGet32(ds, 0x40ffc0);
    edi = memoryAGet32(ds, ebx - 4);
    eax &= 0x8000000f;
    if ((int32_t)eax >= 0)
        goto loc_402884;
    eax--;
    eax |= 0xfffffff0;
    eax++;
loc_402884: // 0000:402884
    ecx = edi;
    edx = memoryAGet32(ss, ebp + 0x8);
    ecx <<= 4;
    ecx -= 0x00000005;
    eax -= edx;
    edx = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ss, ebp - 8, ecx);
    ecx = memoryAGet32(ds, ebx + 0xc);
    eax += 0x000001ca;
    push32(eax);
    eax = memoryAGet32(ss, ebp - 8);
    ecx = ecx + (ecx * 2);
    push32(eax);
    ecx <<= 4;
    ecx = memoryAGet32(ds, ecx + edx + 0x70);
    push32(ecx);
    push32(esi);
    edx = memoryAGet32(ds, ecx + 0x1c);
    flags.zero = memoryAGet32(ds, edx) == 0x00000008;
    edx = memoryAGet32(ds, esi + 0x1c);
    if (!flags.zero)
        goto loc_4028c3;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:4028be
    goto loc_4028c6;
loc_4028c3: // 0000:4028c3
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:4028c3
loc_4028c6: // 0000:4028c6
    eax = memoryAGet32(ds, ebx);
    esp += 0x00000010;
    edi++;
    if ((int32_t)edi >= (int32_t)eax)
        goto loc_402936;
    eax = edi;
    eax <<= 4;
    memoryASet32(ss, ebp - 8, eax);
loc_4028d8: // 0000:4028d8
    eax = memoryAGet32(ds, 0x40ffc0);
    eax &= 0x8000000f;
    if ((int32_t)eax >= 0)
        goto loc_4028e9;
    eax--;
    eax |= 0xfffffff0;
    eax++;
loc_4028e9: // 0000:4028e9
    ecx = memoryAGet32(ds, ebx + 0xc);
    edx = memoryAGet32(ss, ebp + 0x8);
    eax -= edx;
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = ecx + (ecx * 2);
    eax += 0x000001ca;
    ecx <<= 4;
    push32(eax);
    eax = memoryAGet32(ss, ebp - 8);
    ecx = memoryAGet32(ds, ecx + edx + 0x80);
    push32(eax);
    push32(ecx);
    push32(esi);
    edx = memoryAGet32(ds, ecx + 0x1c);
    flags.zero = memoryAGet32(ds, edx) == 0x00000008;
    edx = memoryAGet32(ds, esi + 0x1c);
    if (!flags.zero)
        goto loc_402920;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:40291b
    goto loc_402923;
loc_402920: // 0000:402920
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:402920
loc_402923: // 0000:402923
    ecx = memoryAGet32(ss, ebp - 8);
    eax = memoryAGet32(ds, ebx);
    esp += 0x00000010;
    edi++;
    ecx += 0x00000010;
    memoryASet32(ss, ebp - 8, ecx);
    if ((int32_t)edi < (int32_t)eax)
        goto loc_4028d8;
loc_402936: // 0000:402936
    eax = memoryAGet32(ds, 0x40ffc0);
    eax &= 0x8000000f;
    if ((int32_t)eax >= 0)
        goto loc_402947;
    eax--;
    eax |= 0xfffffff0;
    eax++;
loc_402947: // 0000:402947
    ecx = memoryAGet32(ss, ebp + 0x8);
    edx = memoryAGet32(ds, 0x40fa40);
    eax -= ecx;
    ecx = memoryAGet32(ds, ebx + 0xc);
    ecx += 0x00000003;
    eax += 0x000001ca;
    edi <<= 4;
    ecx = ecx + (ecx * 2);
    push32(eax);
    ecx <<= 4;
    push32(edi);
    ecx = memoryAGet32(ds, ecx + edx);
    push32(ecx);
    push32(esi);
    edx = memoryAGet32(ds, ecx + 0x1c);
    flags.zero = memoryAGet32(ds, edx) == 0x00000008;
    edx = memoryAGet32(ds, esi + 0x1c);
    if (!flags.zero)
        goto loc_40297d;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:402978
    goto loc_402980;
loc_40297d: // 0000:40297d
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:40297d
loc_402980: // 0000:402980
    ecx = memoryAGet32(ds, ebx + 0x4);
    esp += 0x00000010;
    ecx--;
    eax = 0x66666667;
    imul32(ecx);
    ecx = memoryAGet32(ds, 0x40ffc0);
    edx = sar32(edx, 0x00000001);
    eax = edx;
    eax >>= 31;
    edx += eax;
    ecx &= 0x8000000f;
    push32(edx);
    push32(0x0040e030);
    push32(0x0000000f);
    if ((int32_t)ecx >= 0)
        goto loc_4029b2;
    ecx--;
    ecx |= 0xfffffff0;
    ecx++;
loc_4029b2: // 0000:4029b2
    edx = memoryAGet32(ss, ebp - 24);
    ecx += edx;
    edx = memoryAGet32(ds, 0x40d0d4);
    push32(ecx);
    push32(0x00000000);
    eax = memoryAGet32(ds, edx);
    push32(eax);
    push32(esi);
    alleg40::textprintf(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));();
    esp += 0x0000001c;
loc_4029cd: // 0000:4029cd
    eax = memoryAGet32(ds, ebx + 0x8);
    if (!eax)
        goto loc_402aa4;
    edi = memoryAGet32(ds, 0x40ffc0);
    edi &= 0x8000000f;
    if ((int32_t)edi >= 0)
        goto loc_4029eb;
    edi--;
    edi |= 0xfffffff0;
    edi++;
loc_4029eb: // 0000:4029eb
    ecx = memoryAGet32(ss, ebp + 0x8);
    edx = memoryAGet32(ds, 0x40fa40);
    edi -= ecx;
    ecx = memoryAGet32(ds, ebx + 0xc);
    ecx += 0x00000035;
    edi += 0x000001da;
    ecx <<= 4;
    push32(edi);
    ecx = memoryAGet32(ds, ecx + edx);
    edx = memoryAGet32(ds, ebx - 4);
    eax = memoryAGet32(ds, ecx);
    memoryASet32(ss, ebp - 28, eax);
    eax = memoryAGet32(ds, ebx);
    eax -= edx;
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edx = memoryAGet32(ds, ebx - 4);
    eax = sar32(eax, 0x00000001);
    eax += edx;
    edx = memoryAGet32(ds, ecx + 0x1c);
    eax <<= 4;
    memoryASet32(ss, ebp - 8, eax);
    eax = memoryAGet32(ds, edx);
    edx = memoryAGet32(ss, ebp - 8);
    flags.zero = eax == 0x00000008;
    eax = memoryAGet32(ds, esi + 0x1c);
    push32(edx);
    push32(ecx);
    push32(esi);
    if (!flags.zero)
        goto loc_402a3d;
    indirectCall(cs, memoryAGet32(ds, eax + 0x44)); // 0000:402a38
    goto loc_402a40;
loc_402a3d: // 0000:402a3d
    indirectCall(cs, memoryAGet32(ds, eax + 0x40)); // 0000:402a3d
loc_402a40: // 0000:402a40
    eax = memoryAGet32(ss, ebp - 28);
    ecx = memoryAGet32(ss, ebp - 8);
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edx = memoryAGet32(ds, ebx + 0x8);
    esp += 0x00000010;
    eax = sar32(eax, 0x00000001);
    eax += ecx;
    push32(edx);
    edx = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ss, ebp - 28, eax);
    push32(0x0040e030);
    ecx = edi + 7;
    push32(0x00000001);
    eax += 0x00000002;
    push32(ecx);
    push32(eax);
    eax = memoryAGet32(ds, edx + 0x150);
    push32(eax);
    push32(esi);
    alleg40::textprintf_centre(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));();
    ecx = memoryAGet32(ds, ebx + 0x8);
    edx = memoryAGet32(ss, ebp - 28);
    eax = memoryAGet32(ds, 0x40fa40);
    push32(ecx);
    push32(0x0040e030);
    edi += 0x00000006;
    ecx = memoryAGet32(ds, eax + 0x150);
    push32(0x0000000f);
    edx++;
    push32(edi);
    push32(edx);
    push32(ecx);
    push32(esi);
    alleg40::textprintf_centre(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));();
    esp += 0x00000038;
loc_402aa4: // 0000:402aa4
    eax = memoryAGet32(ss, ebp - 24);
    edi = memoryAGet32(ss, ebp + 0x8);
    eax += 0x00000010;
    edi -= 0x00000010;
    ebx -= 0x00000018;
    memoryASet32(ss, ebp - 24, eax);
    memoryASet32(ss, ebp + 0x8, edi);
    if ((int32_t)eax <= (int32_t)0x000001d0)
        goto loc_402865;
    ebx = 0x0040ffe8;
loc_402ac9: // 0000:402ac9
    eax = memoryAGet32(ds, ebx - 8);
    if (!eax)
        goto loc_402b30;
    ecx = memoryAGet32(ds, ebx);
    memoryASet32(ss, ebp + 0x8, ecx);
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = sar32(eax, 0x10);
    edx = memoryAGet32(ds, ebx - 4);
    ecx = sar32(ecx, 0x0f);
    ecx &= 0x00000001;
    memoryASet32(ss, ebp + 0x8, edx);
    ecx += eax;
    edi = ecx;
    eax = memoryAGet32(ss, ebp + 0x8);
    eax = sar32(eax, 0x10);
    edx = sar32(edx, 0x0f);
    edx &= 0x00000001;
    ecx = memoryAGet32(ds, 0x40fa34);
    edx += eax;
    eax = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ss, ebp + 0x8, edx);
    edx = memoryAGet32(ds, ebx + 0xc);
    edx += 0x00000039;
    push32(edi);
    edi = memoryAGet32(ss, ebp + 0x8);
    edx <<= 4;
    push32(edi);
    eax = memoryAGet32(ds, edx + eax);
    push32(eax);
    push32(ecx);
    edx = memoryAGet32(ds, eax + 0x1c);
    flags.zero = memoryAGet32(ds, edx) == 0x00000008;
    edx = memoryAGet32(ds, ecx + 0x1c);
    if (!flags.zero)
        goto loc_402b2a;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:402b25
    goto loc_402b2d;
loc_402b2a: // 0000:402b2a
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:402b2a
loc_402b2d: // 0000:402b2d
    esp += 0x00000010;
loc_402b30: // 0000:402b30
    ebx += 0x00000018;
    if ((int32_t)ebx < (int32_t)0x00412fe8)
        goto loc_402ac9;
    eax = memoryAGet32(ds, 0x413010);
    if (!eax)
        goto loc_402b4e;
    ecx = 0x00000006;
    memoryASet32(ss, ebp - 4, ecx);
    goto loc_402b51;
loc_402b4e: // 0000:402b4e
    ecx = memoryAGet32(ss, ebp - 4);
loc_402b51: // 0000:402b51
    flags.zero = eax == 0x00000003;
    flags.sign = (int32_t)eax < (int32_t)0x00000003;
    if (flags.zero)
        goto loc_402b5b;
    flags.zero = eax == 0x00000002;
    flags.sign = (int32_t)eax < (int32_t)0x00000002;
    if (!flags.zero)
        goto loc_402b7f;
loc_402b5b: // 0000:402b5b
    fld64(memoryAGet64(ds, 0x412ff8));
    fcomp64(memoryAGet64(ds, 0x40d270));
    ax = fnstsw();
    flags.zero = !(ah & 0x41);
    flags.sign = ah & 128;
    if (!flags.zero)
        goto loc_402c6e;
    ecx = 0x00000007;
    memoryASet32(ss, ebp - 4, ecx);
    goto loc_402c78;
loc_402b7f: // 0000:402b7f
    if (eax != 0x00000001)
        goto loc_402ba8;
    fld64(memoryAGet64(ds, 0x412ff8));
    fcomp64(memoryAGet64(ds, 0x40d268));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_402c6e;
    ecx = 0x00000005;
    memoryASet32(ss, ebp - 4, ecx);
    goto loc_402c78;
loc_402ba8: // 0000:402ba8
    if (eax)
        goto loc_402c6e;
    fld64(memoryAGet64(ds, 0x412ff0));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    fld64(memoryAGet64(ds, 0x412ff0));
    memoryASet32(ss, ebp - 4, 0x00000001);
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_402bd2;
    fchs();
loc_402bd2: // 0000:402bd2
    fcomp64(memoryAGet64(ds, 0x40d260));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_402cb5;
    memoryASet32(ss, ebp - 4, 0x00000000);
loc_402bea: // 0000:402bea
    eax = memoryAGet32(ss, ebp - 4);
    edi = 0;
    memoryASet32(ds, 0x413018, edi);
    if (eax)
        goto loc_402d0c;
    eax = memoryAGet32(ds, 0x413034);
    if (!eax)
        goto loc_402e08;
    edx = memoryAGet32(ds, 0x40ffc4);
    dl = ~dl;
    edi = (int8_t)dl;
    edi &= 0x00000008;
    edi |= 0x00000120;
    edi >>= 3;
    if (eax != 0x00000002)
        goto loc_402d93;
    fld64(memoryAGet64(ds, 0x412fe8));
    ebx = memoryAGet32(ds, esi + 0x1c);
    sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    eax -= 0x00000032;
    push32(eax);
    sub_406e04();
    eax -= 0x0000001a;
    push32(eax);
    eax = memoryAGet32(ds, 0x40fa40);
    edi <<= 4;
    ecx = memoryAGet32(ds, edi + eax);
    push32(ecx);
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x4c)); // 0000:402c58
    eax = memoryAGet32(ds, 0x413038);
    esp += 0x00000010;
    eax++;
    memoryASet32(ds, 0x413038, eax);
    goto loc_402f5b;
loc_402c6e: // 0000:402c6e
    if ((int32_t)ecx < (int32_t)0x00000005)
        goto loc_402cac;
    flags.zero = ecx == 0x00000007;
    flags.sign = (int32_t)ecx < (int32_t)0x00000007;
    if ((int32_t)ecx > (int32_t)0x00000007)
        goto loc_402cac;
loc_402c78: // 0000:402c78
    fld64(memoryAGet64(ds, 0x412ff0));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    fld64(memoryAGet64(ds, 0x412ff0));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_402c93;
    fchs();
loc_402c93: // 0000:402c93
    fcomp64(memoryAGet64(ds, 0x40d258));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_402cac;
    memoryASet32(ss, ebp - 4, 0x00000008);
    goto loc_402bea;
loc_402cac: // 0000:402cac
    flags.zero = ecx == 0x00000001;
    flags.sign = (int32_t)ecx < (int32_t)0x00000001;
    if (!flags.zero)
        goto loc_402bea;
loc_402cb5: // 0000:402cb5
    fld64(memoryAGet64(ds, 0x412ff0));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    fld64(memoryAGet64(ds, 0x412ff0));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_402cd0;
    fchs();
loc_402cd0: // 0000:402cd0
    fcomp64(memoryAGet64(ds, 0x40d250));
    ax = fnstsw();
    if (ah & 0x01)
        goto loc_402bea;
    eax = memoryAGet32(ds, 0x40ffc4);
    ecx = 0x0000000a;
    edx = (int32_t)eax < 0 ? -1 : 0;
    idiv32(ecx);
    edi = memoryAGet32(ds, 0x413018);
    if (edx)
        goto loc_402cff;
    edi++;
    memoryASet32(ds, 0x413018, edi);
loc_402cff: // 0000:402cff
    if (edi != 0x00000004)
        goto loc_402d0c;
    edi = 0;
    memoryASet32(ds, 0x413018, edi);
loc_402d0c: // 0000:402d0c
    eax = memoryAGet32(ds, 0x41302c);
    if (!eax)
        goto loc_402ec0;
    eax = memoryAGet32(ds, 0x40fa40);
    edx = memoryAGet32(ds, 0x413030);
    fld64(memoryAGet64(ds, 0x412fe8));
    edi = memoryAGet32(ds, eax + 0x230);
    ebx = memoryAGet32(ds, esi + 0x1c);
    push32(0x00000000);
    push32(0x00010000);
    eax = memoryAGet32(ds, edi + 0x4);
    ecx = memoryAGet32(ds, edi);
    eax <<= 15;
    push32(edx);
    push32(eax);
    ecx <<= 15;
    push32(ecx);
    sub_406e04();
    ecx = eax;
    eax = memoryAGet32(ds, edi + 0x4);
    eax <<= 16;
    edx = (int32_t)eax < 0 ? -1 : 0;
    fld64(memoryAGet64(ds, 0x412fe0));
    ecx -= 0x00000033;
    eax -= edx;
    ecx <<= 16;
    eax = sar32(eax, 0x00000001);
    ecx += eax;
    push32(ecx);
    sub_406e04();
    ecx = eax;
    eax = memoryAGet32(ds, edi);
    eax <<= 16;
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx -= 0x0000000e;
    eax -= edx;
    ecx <<= 16;
    eax = sar32(eax, 0x00000001);
    ecx += eax;
    push32(ecx);
    push32(edi);
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, ebx + 0xa0)); // 0000:402d85
    esp += 0x00000024;
    goto loc_402f5b;
loc_402d93: // 0000:402d93
    fld64(memoryAGet64(ds, 0x412fe8));
    sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    eax -= 0x00000032;
    ebx = 0;
    memoryASet32(ss, ebp + 0x8, eax);
    bl = edi != 0x00000020;
    ebx--;
    sub_406e04();
    edx = memoryAGet32(ds, 0x40fa40);
    eax = (ebx + eax) + -11;
    edi <<= 4;
    edi = memoryAGet32(ds, edi + edx);
    ecx = memoryAGet32(ds, edi + 0x1c);
    edx = memoryAGet32(ds, ecx);
    ecx = memoryAGet32(ss, ebp + 0x8);
    push32(ecx);
    push32(eax);
    flags.zero = edx == 0x00000008;
    edx = memoryAGet32(ds, esi + 0x1c);
    push32(edi);
    push32(esi);
    if (!flags.zero)
        goto loc_402df2;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:402ddc
    eax = memoryAGet32(ds, 0x413038);
    esp += 0x00000010;
    eax++;
    memoryASet32(ds, 0x413038, eax);
    goto loc_402f5b;
loc_402df2: // 0000:402df2
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:402df2
    eax = memoryAGet32(ds, 0x413038);
    esp += 0x00000010;
    eax++;
    memoryASet32(ds, 0x413038, eax);
    goto loc_402f5b;
loc_402e08: // 0000:402e08
    if ((int32_t)memoryAGet32(ds, 0x40ffc0) <= (int32_t)0x000000c8)
        goto loc_402e2e;
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d248));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_402e2e;
    edi = 0x00000022;
    goto loc_402e67;
loc_402e2e: // 0000:402e2e
    eax = memoryAGet32(ds, 0x40ffc4);
    if ((int32_t)eax >= (int32_t)0x0000000c)
        goto loc_402e3f;
    edi = 0x00000020;
    goto loc_402e67;
loc_402e3f: // 0000:402e3f
    eax = memoryAGet32(ds, 0x40ffc4);
    if ((int32_t)eax >= (int32_t)0x00000019)
        goto loc_402e50;
    edi = 0x00000017;
    goto loc_402e67;
loc_402e50: // 0000:402e50
    edx = 0;
    ebx = memoryAGet32(ds, 0x40ffc4);
    dl = (int32_t)ebx >= (int32_t)0x00000025;
    edx--;
    edx &= 0x0000000a;
    edx += 0x00000017;
    edi = edx;
loc_402e67: // 0000:402e67
    fld64(memoryAGet64(ds, 0x412fe8));
    sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    eax -= 0x00000033;
    ebx = 0;
    memoryASet32(ss, ebp + 0x8, eax);
    bl = edi != 0x00000020;
    ebx--;
    sub_406e04();
    ecx = memoryAGet32(ds, 0x40fa40);
    eax = (ebx + eax) + -14;
    edi <<= 4;
    edi = memoryAGet32(ds, edi + ecx);
    edx = memoryAGet32(ds, edi + 0x1c);
    ecx = memoryAGet32(ds, edx);
    edx = memoryAGet32(ss, ebp + 0x8);
    push32(edx);
    push32(eax);
    flags.zero = ecx == 0x00000008;
    ecx = memoryAGet32(ds, esi + 0x1c);
    push32(edi);
    push32(esi);
    if (!flags.zero)
        goto loc_402eb8;
    indirectCall(cs, memoryAGet32(ds, ecx + 0x44)); // 0000:402eb0
    goto loc_402f58;
loc_402eb8: // 0000:402eb8
    indirectCall(cs, memoryAGet32(ds, ecx + 0x40)); // 0000:402eb8
    goto loc_402f58;
loc_402ec0: // 0000:402ec0
    fld64(memoryAGet64(ds, 0x412ff0));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_402f1f;
    fld64(memoryAGet64(ds, 0x412fe8));
    sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    ebx = eax;
    ebx -= 0x00000033;
    sub_406e04();
    edx = memoryAGet32(ss, ebp - 4);
    eax -= 0x0000000e;
    push32(ebx);
    push32(eax);
    ecx = (edi + edx) + 23;
    edx = memoryAGet32(ds, 0x40fa40);
    ecx <<= 4;
    ecx = memoryAGet32(ds, ecx + edx);
    push32(ecx);
    push32(esi);
    edx = memoryAGet32(ds, ecx + 0x1c);
    edi = memoryAGet32(ds, edx);
    edx = memoryAGet32(ds, esi + 0x1c);
    if (edi != 0x00000008)
        goto loc_402f1a;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:402f15
    goto loc_402f58;
loc_402f1a: // 0000:402f1a
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:402f1a
    goto loc_402f58;
loc_402f1f: // 0000:402f1f
    fld64(memoryAGet64(ds, 0x412fe8));
    ebx = memoryAGet32(ds, esi + 0x1c);
    sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    eax -= 0x00000033;
    push32(eax);
    sub_406e04();
    eax -= 0x0000000e;
    edx = memoryAGet32(ds, 0x40fa40);
    push32(eax);
    eax = memoryAGet32(ss, ebp - 4);
    ecx = (edi + eax) + 23;
    ecx <<= 4;
    eax = memoryAGet32(ds, ecx + edx);
    push32(eax);
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x4c)); // 0000:402f55
loc_402f58: // 0000:402f58
    esp += 0x00000010;
loc_402f5b: // 0000:402f5b
    edi = 0xffffff84;
loc_402f60: // 0000:402f60
    eax = memoryAGet32(ds, 0x40ffc0);
    ecx = 0x00000054;
    edx = (int32_t)eax < 0 ? -1 : 0;
    idiv32(ecx);
    memoryASet32(ss, ebp + 0x8, edx);
    fild32(memoryAGet32(ss, ebp + 0x8));
    fmul64(memoryAGet64(ds, 0x40d240));
    sub_406e04();
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = edi;
    ecx -= eax;
    eax = memoryAGet32(ds, edx + 0x340);
    push32(ecx);
    push32(0x00000235);
    push32(eax);
    edx = memoryAGet32(ds, eax + 0x1c);
    push32(esi);
    ebx = memoryAGet32(ds, edx);
    edx = memoryAGet32(ds, esi + 0x1c);
    if (ebx != 0x00000008)
        goto loc_402fa8;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:402fa3
    goto loc_402fab;
loc_402fa8: // 0000:402fa8
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:402fa8
loc_402fab: // 0000:402fab
    eax = memoryAGet32(ds, 0x40ffc0);
    ecx = 0x00000054;
    edx = (int32_t)eax < 0 ? -1 : 0;
    idiv32(ecx);
    ebx = memoryAGet32(ds, esi + 0x1c);
    esp += 0x00000010;
    memoryASet32(ss, ebp + 0x8, edx);
    fild32(memoryAGet32(ss, ebp + 0x8));
    fmul64(memoryAGet64(ds, 0x40d240));
    sub_406e04();
    edx = edi;
    edx -= eax;
    eax = memoryAGet32(ds, 0x40fa40);
    push32(edx);
    push32(0xffffffc7);
    ecx = memoryAGet32(ds, eax + 0x340);
    push32(ecx);
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, ebx + 0x4c)); // 0000:402fe3
    edi += 0x0000007c;
    esp += 0x00000010;
    if ((int32_t)edi < (int32_t)0x000001f0)
        goto loc_402f60;
    edx = memoryAGet32(ds, 0x40fa40);
    eax = memoryAGet32(ds, edx + 0x60);
    ecx = memoryAGet32(ds, eax + 0x1c);
    if (memoryAGet32(ds, ecx) != 0x00000008)
        goto loc_403017;
    edx = memoryAGet32(ds, esi + 0x1c);
    push32(0x00000064);
    push32(0x00000014);
    push32(eax);
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:403012
    goto loc_403023;
loc_403017: // 0000:403017
    ecx = memoryAGet32(ds, esi + 0x1c);
    push32(0x00000064);
    push32(0x00000014);
    push32(eax);
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, ecx + 0x40)); // 0000:403020
loc_403023: // 0000:403023
    eax = memoryAGet32(ds, 0x41301c);
    esp += 0x00000010;
    if (!eax)
        goto loc_4030d3;
    edx = 0x000000db;
    push32(eax);
    edx -= eax;
    push32(0x00000010);
    ecx = 0x00000064;
    push32(edx);
    edx = memoryAGet32(ds, 0x40fa40);
    ecx -= eax;
    push32(0x0000001f);
    push32(ecx);
    eax = memoryAGet32(ds, edx + 0x50);
    push32(0x00000000);
    push32(esi);
    push32(eax);
    alleg40::blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));();
    ecx = memoryAGet32(ds, 0x40fa40);
    esp += 0x00000020;
    eax = memoryAGet32(ds, ecx + 0x40);
    edx = memoryAGet32(ds, eax + 0x1c);
    if (memoryAGet32(ds, edx) != 0x00000008)
        goto loc_403080;
    ecx = memoryAGet32(ds, esi + 0x1c);
    push32(0x000000d2);
    push32(0xfffffff6);
    push32(eax);
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, ecx + 0x44)); // 0000:40307b
    goto loc_40308f;
loc_403080: // 0000:403080
    edx = memoryAGet32(ds, esi + 0x1c);
    push32(0x000000d2);
    push32(0xfffffff6);
    push32(eax);
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:40308c
loc_40308f: // 0000:40308f
    eax = memoryAGet32(ds, 0x413020);
    ecx = memoryAGet32(ds, 0x40fa40);
    esp += 0x00000010;
    edx = memoryAGet32(ds, ecx + 0x130);
    push32(eax);
    push32(0x0040e030);
    push32(0xffffffff);
    push32(0x000000d6);
    push32(0x00000028);
    push32(edx);
    push32(esi);
    alleg40::textprintf_centre(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));();
    push32(0x000000ef);
    push32(0x000000e0);
    sub_4022b0();
    esp += 0x00000024;
    memoryASet32(ss, ebp - 20, 0x00000001);
loc_4030d3: // 0000:4030d3
    eax = memoryAGet32(ds, 0x413324);
    if ((int32_t)eax >= (int32_t)0x000001e0)
        goto loc_40310c;
    if ((int32_t)eax <= (int32_t)0x000000fa)
        goto loc_40310c;
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000003;
    idiv32(ecx);
    edi = edx;
    edi--;
    memoryASet32(ss, ebp - 16, edi);
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000003;
    idiv32(ecx);
    edx--;
    memoryASet32(ss, ebp - 12, edx);
    goto loc_403112;
loc_40310c: // 0000:40310c
    edi = memoryAGet32(ss, ebp - 16);
    edx = memoryAGet32(ss, ebp - 12);
loc_403112: // 0000:403112
    eax = memoryAGet32(ds, 0x40fa40);
    ecx = edx + 10;
    edx = edi + 4;
    push32(ecx);
    eax = memoryAGet32(ds, eax + 0x20);
    push32(edx);
    push32(eax);
    push32(esi);
    edi = memoryAGet32(ds, eax + 0x1c);
    ebx = memoryAGet32(ds, edi);
    edi = memoryAGet32(ds, esi + 0x1c);
    if (ebx != 0x00000008)
        goto loc_403136;
    indirectCall(cs, memoryAGet32(ds, edi + 0x44)); // 0000:403131
    goto loc_403139;
loc_403136: // 0000:403136
    indirectCall(cs, memoryAGet32(ds, edi + 0x40)); // 0000:403136
loc_403139: // 0000:403139
    eax = memoryAGet32(ds, 0x413324);
    esp += 0x00000010;
    if ((int32_t)eax >= (int32_t)0x000001e0)
        goto loc_403171;
    if ((int32_t)eax <= (int32_t)0x000000c8)
        goto loc_403171;
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000003;
    idiv32(ecx);
    edx--;
    memoryASet32(ss, ebp - 16, edx);
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000003;
    idiv32(ecx);
    edx--;
    memoryASet32(ss, ebp - 12, edx);
loc_403171: // 0000:403171
    eax = memoryAGet32(ds, 0x413328);
    temp_cond0 =     stop("FNSTSW reads flags");;
    if (!eax)
        goto loc_40320d;
    eax = memoryAGet32(ds, 0x413328);
    ecx = 0x000005dc;
    edx = (int32_t)eax < 0 ? -1 : 0;
    idiv32(ecx);
    memoryASet32(ss, ebp + 0x8, edx);
    fild32(memoryAGet32(ss, ebp + 0x8));
    fmul64(memoryAGet64(ds, 0x40d238));
    fcom64(memoryAGet64(ds, 0x40d1f0));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_4031bb;
    edx = memoryAGet32(ds, 0x40d110);
    st(0) = fstp80();
    eax = memoryAGet32(ds, edx);
    memoryASet32(ds, eax, 0x00000022);
    eax = 0x7fffffff;
    goto loc_40320f;
loc_4031bb: // 0000:4031bb
    fcom64(memoryAGet64(ds, 0x40d1e8));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_4031df;
    ecx = memoryAGet32(ds, 0x40d110);
    eax = 0x80000001;
    st(0) = fstp80();
    edx = memoryAGet32(ds, ecx);
    memoryASet32(ds, edx, 0x00000022);
    goto loc_40320f;
loc_4031df: // 0000:4031df
    fcom64(memoryAGet64(ds, 0x40d1e0));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_4031f4;
    fld64(memoryAGet64(ds, 0x40d1d8));
    goto loc_4031fa;
loc_4031f4: // 0000:4031f4
    fld64(memoryAGet64(ds, 0x40d1d0));
loc_4031fa: // 0000:4031fa
    stop("disassembly failed at 0000:4031fa (fxch st(1))");
    fmul64(memoryAGet64(ds, 0x40d1c8));
    fadd80(st(1));
    sub_406e04();
    st(0) = fstp80();
    goto loc_40320f;
loc_40320d: // 0000:40320d
    eax = 0;
loc_40320f: // 0000:40320f
    ecx = memoryAGet32(ds, 0x40fa40);
    push32(0x00000000);
    push32(0x00010000);
    push32(eax);
    ecx = memoryAGet32(ds, ecx + 0x30);
    ebx = memoryAGet32(ds, esi + 0x1c);
    edx = memoryAGet32(ds, ecx + 0x4);
    edi = memoryAGet32(ds, ecx);
    eax = edx;
    eax <<= 15;
    push32(eax);
    eax = edi;
    eax <<= 15;
    push32(eax);
    eax = edx;
    eax <<= 16;
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edx = memoryAGet32(ss, ebp - 12);
    edx += 0x0000001c;
    eax = sar32(eax, 0x00000001);
    edx <<= 16;
    eax += edx;
    push32(eax);
    eax = edi;
    eax <<= 16;
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edx = memoryAGet32(ss, ebp - 16);
    edx += 0x00000020;
    eax = sar32(eax, 0x00000001);
    edx <<= 16;
    eax += edx;
    push32(eax);
    push32(ecx);
    push32(esi);
    indirectCall(cs, memoryAGet32(ds, ebx + 0xa0)); // 0000:403262
    eax = memoryAGet32(ds, 0x40fcac);
    esp += 0x00000024;
    if (!eax)
        goto loc_4032a2;
    eax = memoryAGet32(ss, ebp - 20);
    if (eax)
        goto loc_40328d;
    push32(0x000000ef);
    push32(0x000000e0);
    sub_4022b0();
    esp += 0x00000008;
loc_40328d: // 0000:40328d
    eax = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    sub_402320();
    esp += 0x00000004;
    ebx = 0x00000001;
    goto loc_4032a5;
loc_4032a2: // 0000:4032a2
    ebx = memoryAGet32(ss, ebp - 20);
loc_4032a5: // 0000:4032a5
    eax = memoryAGet32(ds, 0x413028);
    if (!eax)
        goto loc_40334a;
    edi = memoryAGet32(ds, 0x413320);
    ecx = 0x000001e0;
    ecx -= eax;
    eax = memoryAGet32(ds, edi);
    push32(ecx);
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edx = eax;
    eax = 0x00000140;
    edx = sar32(edx, 0x00000001);
    eax -= edx;
    edx = memoryAGet32(ds, edi + 0x1c);
    push32(eax);
    push32(edi);
    flags.zero = memoryAGet32(ds, edx) == 0x00000008;
    edx = memoryAGet32(ds, esi + 0x1c);
    push32(esi);
    if (!flags.zero)
        goto loc_4032e3;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:4032de
    goto loc_4032e6;
loc_4032e3: // 0000:4032e3
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:4032e3
loc_4032e6: // 0000:4032e6
    eax = memoryAGet32(ds, 0x413008);
    edi = memoryAGet32(ds, 0x413028);
    edx = memoryAGet32(ds, 0x40fa40);
    esp += 0x00000010;
    ecx = 0x00000244;
    push32(eax);
    eax = memoryAGet32(ds, edx + 0x130);
    push32(0x0040ea74);
    ecx -= edi;
    push32(0xffffffff);
    push32(ecx);
    push32(0x00000140);
    push32(eax);
    push32(esi);
    alleg40::textprintf_centre(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<const char>(5));();
    eax = memoryAGet32(ds, 0x413028);
    esp += 0x0000001c;
    if ((int32_t)eax >= (int32_t)0x0000012c)
        goto loc_403334;
    eax += 0x00000008;
    memoryASet32(ds, 0x413028, eax);
loc_403334: // 0000:403334
    if (ebx)
        goto loc_40334a;
    push32(0x000000ef);
    push32(0x000000e0);
    sub_4022b0();
    esp += 0x00000008;
loc_40334a: // 0000:40334a
    eax = memoryAGet32(ds, 0x413008);
    edx = memoryAGet32(ds, 0x41300c);
    edi = memoryAGet32(ds, 0x40d18c);
    ecx = eax + (eax * 4);
    eax = edx + (ecx * 2);
    ecx = memoryAGet32(ds, 0x40fa40);
    push32(eax);
    push32(0x0040ea68);
    edx = memoryAGet32(ds, ecx + 0x130);
    push32(0xffffffff);
    push32(0x000001b8);
    push32(0x00000008);
    push32(edx);
    push32(esi);
    indirectCall(cs, edi); // 0000:40337e
    eax = memoryAGet32(ds, 0x40fa30);
    esp += 0x0000001c;
    if (!eax)
        goto loc_403419;
    fld64(memoryAGet64(ds, 0x412fe8));
    sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    push32(eax);
    sub_406e04();
    push32(eax);
    eax = memoryAGet32(ds, 0x40d0d4);
    push32(0x0040ea60);
    push32(0x0000000f);
    ecx = memoryAGet32(ds, eax);
    push32(0x00000000);
    push32(0x000000c8);
    push32(ecx);
    push32(esi);
    indirectCall(cs, edi); // 0000:4033bf
    eax = memoryAGet32(ds, 0x40fa30);
    esp += 0x00000020;
    if (!eax)
        goto loc_403419;
    edx = memoryAGet32(ds, 0x413038);
    eax = memoryAGet32(ds, 0x40d0d4);
    push32(edx);
    push32(0x0040e030);
    ecx = memoryAGet32(ds, eax);
    push32(0x0000000f);
    push32(0x0000000a);
    push32(0x000000c8);
    push32(ecx);
    push32(esi);
    indirectCall(cs, edi); // 0000:4033eb
    eax = memoryAGet32(ds, 0x40fa30);
    esp += 0x0000001c;
    if (!eax)
        goto loc_403419;
    edx = memoryAGet32(ds, 0x40fcb0);
    eax = memoryAGet32(ds, 0x40d0d4);
    push32(edx);
    push32(0x0040ea5c);
    ecx = memoryAGet32(ds, eax);
    push32(0x0000000f);
    push32(0x00000000);
    push32(0x00000000);
    push32(ecx);
    push32(esi);
    indirectCall(cs, edi); // 0000:403414
    esp += 0x0000001c;
loc_403419: // 0000:403419
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 4;
}
void sub_403420() // 0000:403420 +long
{
    esp -= 4;
    push32(esi);
    push32(0x0040fcc0);
    sub_404fc0();
    esp += 0x00000004;
    esi = 0x0000001e;
loc_403433: // 0000:403433
    push32(0x0040fcc0);
    sub_404ff0();
    esp += 0x00000004;
    esi--;
    if (esi)
        goto loc_403433;
    push32(0x00412fe0);
    sub_406620();
    eax = 0;
    push32(0x0040ffe0);
    memoryASet32(ds, 0x412fe0, 0x00000000);
    memoryASet32(ds, 0x412fe4, 0x40690000);
    memoryASet32(ds, 0x412fe8, 0x00000000);
    memoryASet32(ds, 0x412fec, 0x407af000);
    memoryASet32(ds, 0x413010, eax);
    memoryASet32(ds, 0x40fcac, eax);
    memoryASet32(ds, 0x413324, 0x000001e0);
    sub_406600();
    esp += 0x00000008;
    esi = pop32();
    esp += 4;
}
void sub_4034a0() // 0000:4034a0 +long
{
    bool temp_cond0;
    bool temp_cond1;
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp &= 0xfffffff8;
    esp -= 0x00000070;
    push32(ebx);
    push32(ebp);
    push32(esi);
    eax |= 0xffffffff;
    esi = 0;
    ebx = 0;
    push32(edi);
    memoryASet32(ds, esp + 0x28, eax);
    memoryASet32(ds, esp + 0x38, esi);
    memoryASet32(ds, esp + 0x18, eax);
    memoryASet32(ds, esp + 0x3c, 0x000005dc);
    memoryASet32(ds, esp + 0x40, 0x00000bb8);
    memoryASet32(ds, esp + 0x44, 0x00001194);
    memoryASet32(ds, esp + 0x48, 0x00001770);
    memoryASet32(ds, esp + 0x4c, 0x00001d4c);
    memoryASet32(ds, esp + 0x50, 0x00002328);
    memoryASet32(ds, esp + 0x54, 0x001b7740);
    memoryASet32(ds, esp + 0x58, 0x00895440);
    memoryASet32(ds, esp + 0x2c, esi);
    memoryASet32(ds, esp + 0x24, 0x00000032);
    memoryASet32(ds, esp + 0x20, 0x00000001);
    memoryASet32(ds, esp + 0x30, esi);
    memoryASet32(ds, esp + 0x1c, ebx);
    sub_401db0();
    memoryASet32(ds, 0x413328, esi);
    eax = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    memoryASet32(ds, 0x40ffc0, esi);
    sub_402780();
    ecx = memoryAGet32(ds, 0x40fa34);
    push32(ecx);
    sub_402250();
    edx = memoryAGet32(ds, 0x40fa40);
    push32(0x00000008);
    eax = memoryAGet32(ds, edx);
    push32(eax);
    alleg40::fade_in(stack32<const PALETTE>(0), stack32<int>(1));();
    ecx = memoryAGet32(ds, 0x40fa88);
    push32(esi);
    push32(ecx);
    sub_401570();
    ecx = memoryAGet32(ds, 0x40fa60);
    esp += 0x00000018;
    if (ecx == esi)
        goto loc_403592;
    edx = memoryAGet32(ds, 0x40e044);
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    push32(edx);
    push32(ecx);
    eax = alleg40::play_sample(stack32<const SAMPLE>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));();
    ecx = memoryAGet32(ds, 0x40fa60);
    esp += 0x00000014;
loc_403592: // 0000:403592
    eax = memoryAGet32(ds, 0x40d1a4);
    ebp = 0;
    goto loc_4035a1;
loc_40359b: // 0000:40359b
    ecx = memoryAGet32(ds, 0x40fa60);
loc_4035a1: // 0000:4035a1
    memoryASet32(ds, 0x42bbc0, ebp);
    if (ecx == ebp)
        goto loc_4035cc;
    eax = memoryAGet32(ds, 0x40e044);
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    push32(eax);
    push32(ecx);
    alleg40::adjust_sample(stack32<SAMPLE>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));();
    eax = memoryAGet32(ds, 0x40d1a4);
    esp += 0x00000014;
loc_4035cc: // 0000:4035cc
    if (memoryAGet32(ds, 0x40fa30) == ebp)
        goto loc_4036c9;
    cl = memoryAGet(ds, eax + 0x54);
    if (!cl)
        goto loc_4035f3;
    memoryASet32(ds, 0x412ff8, 0x00000000);
    memoryASet32(ds, 0x412ffc, 0xc0300000);
loc_4035f3: // 0000:4035f3
    cl = memoryAGet(ds, eax + 0x1c);
    esi = memoryAGet32(ds, esp + 0x20);
    if (!cl)
        goto loc_403611;
    if (esi == ebp)
        goto loc_403611;
    push32(0x00000005);
    sub_4024f0();
    eax = memoryAGet32(ds, 0x40d1a4);
    esp += 0x00000004;
loc_403611: // 0000:403611
    cl = memoryAGet(ds, eax + 0x1d);
    if (!cl)
        goto loc_40362b;
    if (esi == ebp)
        goto loc_40362b;
    push32(0x0000000a);
    sub_4024f0();
    eax = memoryAGet32(ds, 0x40d1a4);
    esp += 0x00000004;
loc_40362b: // 0000:40362b
    cl = memoryAGet(ds, eax + 0x1e);
    if (!cl)
        goto loc_403645;
    if (esi == ebp)
        goto loc_403645;
    push32(0x00000014);
    sub_4024f0();
    eax = memoryAGet32(ds, 0x40d1a4);
    esp += 0x00000004;
loc_403645: // 0000:403645
    cl = memoryAGet(ds, eax + 0x1f);
    if (!cl)
        goto loc_40365f;
    if (esi == ebp)
        goto loc_40365f;
    push32(0x0000001e);
    sub_4024f0();
    eax = memoryAGet32(ds, 0x40d1a4);
    esp += 0x00000004;
loc_40365f: // 0000:40365f
    cl = memoryAGet(ds, eax + 0x20);
    if (!cl)
        goto loc_403679;
    if (esi == ebp)
        goto loc_403679;
    push32(0x00000028);
    sub_4024f0();
    eax = memoryAGet32(ds, 0x40d1a4);
    esp += 0x00000004;
loc_403679: // 0000:403679
    cl = memoryAGet(ds, eax + 0x21);
    if (!cl)
        goto loc_403693;
    if (esi == ebp)
        goto loc_403693;
    push32(0x00000032);
    sub_4024f0();
    eax = memoryAGet32(ds, 0x40d1a4);
    esp += 0x00000004;
loc_403693: // 0000:403693
    cl = memoryAGet(ds, eax + 0x1c);
    if (cl)
        goto loc_4036c5;
    cl = memoryAGet(ds, eax + 0x1d);
    if (cl)
        goto loc_4036c5;
    cl = memoryAGet(ds, eax + 0x1e);
    if (cl)
        goto loc_4036c5;
    cl = memoryAGet(ds, eax + 0x1f);
    if (cl)
        goto loc_4036c5;
    cl = memoryAGet(ds, eax + 0x20);
    if (cl)
        goto loc_4036c5;
    cl = memoryAGet(ds, eax + 0x21);
    memoryASet32(ds, esp + 0x20, 0x00000001);
    if (!cl)
        goto loc_4036c9;
loc_4036c5: // 0000:4036c5
    memoryASet32(ds, esp + 0x20, ebp);
loc_4036c9: // 0000:4036c9
    push32(0x0042bde0);
    sub_402670();
    push32(0x00412fe0);
    sub_406670();
    eax = memoryAGet32(ds, 0x41302c);
    esp += 0x00000008;
    if (eax == ebp)
        goto loc_403721;
    if (memoryAGet32(ds, 0x41301c) == ebp)
        goto loc_403721;
    if (memoryAGet32(ds, 0x40e054) == ebp)
        goto loc_403721;
    fld64(memoryAGet64(ds, 0x412fe8));
    sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    eax -= 0x00000010;
    push32(eax);
    sub_406e04();
    push32(eax);
    push32(0x0040ffe0);
    sub_406500();
    esp += 0x0000000c;
loc_403721: // 0000:403721
    esi = 0x0040ffe0;
loc_403726: // 0000:403726
    if (memoryAGet32(ds, esi) == ebp)
        goto loc_403733;
    push32(esi);
    sub_4065b0();
    esp += 0x00000004;
loc_403733: // 0000:403733
    esi += 0x00000018;
    if ((int32_t)esi < (int32_t)0x00412fe0)
        goto loc_403726;
    edx = memoryAGet32(ds, 0x40ffc0);
    esi = edx;
    esi &= 0x8000000f;
    flags.zero = esi == 0; flags.sign = (int32_t)esi < 0;
    if (!flags.sign)
        goto loc_403753;
    esi--;
    esi |= 0xfffffff0;
    esi++;
    flags.zero = esi == 0; flags.sign = (int32_t)esi < 0;
loc_403753: // 0000:403753
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d2c0));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_40384e;
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d2b8));
    ecx = 0x00000001;
    memoryASet32(ds, esp + 0x14, ecx);
    ax = fnstsw();
    temp_cond0 =     stop("FNSTSW reads flags");;
    if (!(cl & ah))
        goto loc_40378e;
    ecx = 0x00000002;
    memoryASet32(ds, esp + 0x14, ecx);
loc_40378e: // 0000:40378e
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d2b0));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_4037a6;
    ecx++;
    flags.zero = ecx == 0; flags.sign = (int32_t)ecx < 0;
    memoryASet32(ds, esp + 0x14, ecx);
loc_4037a6: // 0000:4037a6
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d2a8));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_4037be;
    ecx++;
    flags.zero = ecx == 0; flags.sign = (int32_t)ecx < 0;
    memoryASet32(ds, esp + 0x14, ecx);
loc_4037be: // 0000:4037be
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d2a0));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_4037d6;
    ecx++;
    flags.zero = ecx == 0; flags.sign = (int32_t)ecx < 0;
    memoryASet32(ds, esp + 0x14, ecx);
loc_4037d6: // 0000:4037d6
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d298));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_4037ee;
    ecx++;
    flags.zero = ecx == 0; flags.sign = (int32_t)ecx < 0;
    memoryASet32(ds, esp + 0x14, ecx);
loc_4037ee: // 0000:4037ee
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d290));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_403806;
    ecx++;
    flags.zero = ecx == 0; flags.sign = (int32_t)ecx < 0;
    memoryASet32(ds, esp + 0x14, ecx);
loc_403806: // 0000:403806
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d288));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_40381e;
    ecx++;
    flags.zero = ecx == 0; flags.sign = (int32_t)ecx < 0;
    memoryASet32(ds, esp + 0x14, ecx);
loc_40381e: // 0000:40381e
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_403836;
    ecx++;
    memoryASet32(ds, esp + 0x14, ecx);
loc_403836: // 0000:403836
    fild32(memoryAGet32(ds, esp + 0x14));
    edx += ecx;
    memoryASet32(ds, 0x40ffc0, edx);
    fadd64(memoryAGet64(ds, 0x412fe8));
    memoryASet64(ds, 0x412fe8, fstp64());
loc_40384e: // 0000:40384e
    eax = memoryAGet32(ds, 0x413028);
    if ((int32_t)edx <= (int32_t)0x00000064)
        goto loc_4038af;
    if (eax != ebp)
        goto loc_4038b9;
    edi = memoryAGet32(ds, esp + 0x18);
    if (edi != 0xffffffff)
        goto loc_40386d;
    edi = 0;
    memoryASet32(ds, esp + 0x18, edi);
    goto loc_403871;
loc_40386d: // 0000:40386d
    if (edi != ebp)
        goto loc_403895;
loc_403871: // 0000:403871
    if (!(memoryAGet(ds, 0x40ffc4) & 0x01))
        goto loc_4038bd;
    fld64(memoryAGet64(ds, 0x412fe8));
    fadd64(memoryAGet64(ds, 0x40d1b8));
    edx++;
    memoryASet32(ds, 0x40ffc0, edx);
    memoryASet64(ds, 0x412fe8, fstp64());
    goto loc_4038bd;
loc_403895: // 0000:403895
    fild32(memoryAGet32(ds, esp + 0x18));
    edx += edi;
    memoryASet32(ds, 0x40ffc0, edx);
    fadd64(memoryAGet64(ds, 0x412fe8));
    memoryASet64(ds, 0x412fe8, fstp64());
    goto loc_4038bd;
loc_4038af: // 0000:4038af
    if (eax != ebp)
        goto loc_4038b9;
    memoryASet32(ds, 0x413328, ebp);
loc_4038b9: // 0000:4038b9
    edi = memoryAGet32(ds, esp + 0x18);
loc_4038bd: // 0000:4038bd
    eax = memoryAGet32(ds, 0x413324);
    if ((int32_t)eax >= (int32_t)0x000001e0)
        goto loc_4038d6;
    if ((int32_t)eax <= (int32_t)0xffffff9c)
        goto loc_4038d6;
    eax -= 0x00000002;
    memoryASet32(ds, 0x413324, eax);
loc_4038d6: // 0000:4038d6
    ecx = memoryAGet32(ds, 0x413328);
    eax = memoryAGet32(ds, esp + 0x2c);
    if ((int32_t)ecx <= (int32_t)memoryAGet32(ds, esp + eax * 4 + 0x3c))
        goto loc_403924;
    flags.zero = edi == 0x00000005;
    if ((int32_t)edi >= (int32_t)0x00000005)
        goto loc_403927;
    ecx = memoryAGet32(ds, 0x40fa74);
    edx = eax;
    edx++;
    edi++;
    push32(ebp);
    push32(ecx);
    memoryASet32(ds, esp + 0x34, edx);
    memoryASet32(ds, esp + 0x20, edi);
    memoryASet32(ds, 0x413324, 0x000001df);
    sub_401570();
    edx = memoryAGet32(ds, 0x40fa98);
    push32(ebp);
    push32(edx);
    sub_401570();
    edx = memoryAGet32(ds, 0x40ffc0);
    esp += 0x00000010;
loc_403924: // 0000:403924
    flags.zero = edi == 0x00000005;
loc_403927: // 0000:403927
    if (!flags.zero)
        goto loc_403936;
    eax = memoryAGet32(ds, 0x413328);
    eax -= 0x0000002d;
    memoryASet32(ds, 0x413328, eax);
loc_403936: // 0000:403936
    edx &= 0x8000000f;
    if ((int32_t)edx >= 0)
        goto loc_403943;
    edx--;
    edx |= 0xfffffff0;
    edx++;
loc_403943: // 0000:403943
    if ((int32_t)esi <= (int32_t)edx)
        goto loc_403954;
    push32(0x0040fcc0);
    sub_404ff0();
    esp += 0x00000004;
loc_403954: // 0000:403954
    fld64(memoryAGet64(ds, 0x412fe8));
    sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    push32(eax);
    sub_406e04();
    eax -= 0x0000000b;
    push32(eax);
    push32(0x0040fcc0);
    sub_405170();
    fld64(memoryAGet64(ds, 0x412fe8));
    esi = eax;
    sub_406e04();
    fld64(memoryAGet64(ds, 0x412fe0));
    push32(eax);
    sub_406e04();
    eax += 0x0000000b;
    push32(eax);
    push32(0x0040fcc0);
    sub_405170();
    ecx = memoryAGet32(ds, 0x413010);
    edi = eax;
    esp += 0x00000018;
    eax = edi + esi;
    if (eax != ebp)
        goto loc_4039c2;
    if (ecx != 0x00000002)
        goto loc_4039c2;
    ecx = 0x00000003;
    memoryASet32(ds, 0x413010, ecx);
loc_4039c2: // 0000:4039c2
    if (eax != ebp)
        goto loc_4039dd;
    if (ecx != ebp)
        goto loc_4039d5;
    ecx = 0x00000003;
    memoryASet32(ds, 0x413010, ecx);
loc_4039d5: // 0000:4039d5
    if (eax == ebp)
        goto loc_403a67;
loc_4039dd: // 0000:4039dd
    if (ecx == 0x00000001)
        goto loc_403a67;
    if (ecx == 0x00000002)
        goto loc_403a67;
    if (ecx == ebp)
        goto loc_403a00;
    ecx = memoryAGet32(ds, 0x40faa8);
    push32(0x00000001);
    push32(ecx);
    sub_401570();
    esp += 0x00000008;
loc_403a00: // 0000:403a00
    ecx = 0;
    memoryASet32(ds, 0x413010, ecx);
    memoryASet32(ds, 0x412ff8, ecx);
    memoryASet32(ds, 0x412ffc, ecx);
    if (esi == ebp)
        goto loc_403a28;
    edx = esi - 9999;
    memoryASet32(ds, esp + 0x1c, edx);
    fild32(memoryAGet32(ds, esp + 0x1c));
    goto loc_403a3a;
loc_403a28: // 0000:403a28
    if (edi == ebp)
        goto loc_403a46;
    eax = edi - 9999;
    memoryASet32(ds, esp + 0x1c, eax);
    fild32(memoryAGet32(ds, esp + 0x1c));
loc_403a3a: // 0000:403a3a
    fsubr64(memoryAGet64(ds, 0x412fe8));
    memoryASet64(ds, 0x412fe8, fstp64());
loc_403a46: // 0000:403a46
    memoryASet32(ds, 0x41302c, ebp);
    if (esi == edi)
        goto loc_403a5f;
    flags.carry = esi != 0;
    esi = -esi;
    esi = -flags.carry;
    esi += 0x00000002;
    memoryASet32(ds, 0x413034, esi);
    goto loc_403a79;
loc_403a5f: // 0000:403a5f
    memoryASet32(ds, 0x413034, ebp);
    goto loc_403a79;
loc_403a67: // 0000:403a67
    if (memoryAGet32(ds, 0x41302c) == ebp)
        goto loc_403a79;
    memoryASet32(ds, 0x413030, memoryAGet32(ds, 0x413030) + 0x00080000);
loc_403a79: // 0000:403a79
    eax = memoryAGet32(ds, 0x41301c);
    if (eax == ebp)
        goto loc_403aba;
    eax--;
    memoryASet32(ds, 0x41301c, eax);
    if (eax)
        goto loc_403aba;
    if ((int32_t)memoryAGet32(ds, 0x413024) <= (int32_t)0x00000001)
        goto loc_403aba;
    eax = memoryAGet32(ds, 0x413020);
    edx = memoryAGet32(ds, 0x41300c);
    ecx = eax;
    push32(eax);
    ecx = (int32_t)ecx * (int32_t)eax;
    edx += ecx;
    memoryASet32(ds, 0x41300c, edx);
    sub_4024f0();
    ecx = memoryAGet32(ds, 0x413010);
    esp += 0x00000004;
loc_403aba: // 0000:403aba
    temp_cond1 =     stop("FNSTSW reads flags");;
    if (ecx != ebp)
        goto loc_403b6b;
    fld64(memoryAGet64(ds, 0x412fe8));
    sub_406e04();
    push32(eax);
    push32(0x0040fcc0);
    sub_4051e0();
    ecx = eax;
    esp += 0x00000008;
    ecx--;
    eax = 0x66666667;
    imul32(ecx);
    ecx = memoryAGet32(ds, 0x413008);
    edx = sar32(edx, 0x00000001);
    eax = edx;
    eax >>= 31;
    edx += eax;
    if ((int32_t)edx < (int32_t)ecx)
        goto loc_403b53;
    eax = edx;
    eax -= ecx;
    ecx = 0x00000001;
    temp_cond1 =     stop("FNSTSW reads flags");;
    if ((int32_t)eax <= (int32_t)ecx)
        goto loc_403b41;
    if (memoryAGet32(ds, 0x41301c) == ebp)
        goto loc_403b2a;
    edi = memoryAGet32(ds, 0x413020);
    esi = memoryAGet32(ds, 0x413024);
    edi += eax;
    esi++;
    memoryASet32(ds, 0x413020, edi);
    memoryASet32(ds, 0x413024, esi);
    goto loc_403b35;
loc_403b2a: // 0000:403b2a
    memoryASet32(ds, 0x413020, eax);
    memoryASet32(ds, 0x413024, ecx);
loc_403b35: // 0000:403b35
    memoryASet32(ds, 0x41301c, 0x00000064);
    temp_cond1 =     stop("FNSTSW reads flags");;
loc_403b41: // 0000:403b41
    if (eax != ecx)
        goto loc_403b65;
    temp_cond1 =     stop("FNSTSW reads flags");;
    if (memoryAGet32(ds, 0x41301c) == ebp)
        goto loc_403b65;
    memoryASet32(ds, 0x41301c, ecx);
    goto loc_403b65;
loc_403b53: // 0000:403b53
    temp_cond1 =     stop("FNSTSW reads flags");;
    if (memoryAGet32(ds, 0x41301c) == ebp)
        goto loc_403b65;
    memoryASet32(ds, 0x41301c, 0x00000001);
loc_403b65: // 0000:403b65
    memoryASet32(ds, 0x413008, edx);
loc_403b6b: // 0000:403b6b
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d280));
    ax = fnstsw();
    flags.zero = !(ah & 0x41);
    flags.sign = ah & 128;
    if (!flags.zero)
        goto loc_403ba7;
    flags.zero = memoryAGet32(ds, 0x413028) == ebp;
    flags.sign = (int32_t)memoryAGet32(ds, 0x413028) < (int32_t)ebp;
    if (!flags.zero)
        goto loc_403ba7;
    ecx = memoryAGet32(ds, 0x40fa9c);
    ebx = 0x00000001;
    push32(ebp);
    push32(ecx);
    memoryASet32(ds, 0x41301c, ebp);
    memoryASet32(ds, 0x413028, ebx);
    sub_401570();
    esp += 0x00000008;
    flags.zero = esp == 0; flags.sign = (int32_t)esp < 0;
loc_403ba7: // 0000:403ba7
    fld64(memoryAGet64(ds, 0x412fe8));
    fcomp64(memoryAGet64(ds, 0x40d278));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_403bd8;
    if (memoryAGet32(ds, esp + 0x30) != ebp)
        goto loc_403bd8;
    edx = memoryAGet32(ds, 0x40fa78);
    push32(ebp);
    push32(edx);
    memoryASet32(ds, esp + 0x38, 0x00000002);
    sub_401570();
    esp += 0x00000008;
loc_403bd8: // 0000:403bd8
    if (ebx == ebp)
        goto loc_403bdd;
    ebx++;
loc_403bdd: // 0000:403bdd
    eax = memoryAGet32(ds, 0x413008);
    eax = eax + (eax * 4);
    if ((int32_t)ebx > (int32_t)eax)
        goto loc_403bf1;
    if ((int32_t)ebx <= (int32_t)0x000000fa)
        goto loc_403c1a;
loc_403bf1: // 0000:403bf1
    ecx = memoryAGet32(ds, 0x40faa0);
    push32(ebp);
    push32(ecx);
    sub_401570();
    edx = memoryAGet32(ds, 0x40fa9c);
    push32(edx);
    alleg40::stop_sample(stack32<const SAMPLE>(0));();
    esp += 0x0000000c;
    ebx = 0;
    memoryASet32(ds, 0x413040, 0x00000018);
loc_403c1a: // 0000:403c1a
    eax = memoryAGet32(ds, 0x413008);
    ecx = memoryAGet32(ds, esp + 0x24);
    if ((int32_t)eax < (int32_t)ecx)
        goto loc_403cab;
    ecx = memoryAGet32(ds, 0x40fa90);
    push32(ebp);
    push32(ecx);
    sub_401570();
    eax = memoryAGet32(ds, 0x40e054);
    esp += 0x00000008;
    if (eax == ebp)
        goto loc_403ca6;
    eax = memoryAGet32(ds, esp + 0x24);
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    eax = sar32(eax, 0x00000001);
    if ((int32_t)eax <= (int32_t)ebp)
        goto loc_403ca6;
    edi = eax;
loc_403c53: // 0000:403c53
    push32(0x000001e0);
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000258;
    idiv32(ecx);
    edx += 0x00000014;
    push32(edx);
    push32(0x0040ffe0);
    sub_406500();
    esp += 0x0000000c;
    esi = eax;
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x000000c8;
    idiv32(ecx);
    eax = 0x99999999;
    ecx = esi + (esi * 2);
    edx <<= 16;
    imul32(edx);
    edx = sar32(edx, 0x02);
    eax = edx;
    eax >>= 31;
    edx += eax;
    edi--;
    memoryASet32(ds, ecx * 8 + 0x40fff0, edx);
    if (edi)
        goto loc_403c53;
loc_403ca6: // 0000:403ca6
    memoryASet32(ds, esp + 0x24, memoryAGet32(ds, esp + 0x24) + 0x00000032);
loc_403cab: // 0000:403cab
    edx = memoryAGet32(ds, 0x40fa34);
    push32(edx);
    sub_402780();
    eax = memoryAGet32(ds, 0x413040);
    esp += 0x00000004;
    if (eax == ebp)
        goto loc_403d33;
    eax = memoryAGet32(ds, 0x40d108);
    eax = memoryAGet32(ds, eax);
    ecx = memoryAGet32(ds, eax + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x10);
    if (ecx == ebp)
        goto loc_403cda;
    push32(eax);
    indirectCall(cs, ecx); // 0000:403cd5
    esp += 0x00000004;
loc_403cda: // 0000:403cda
    eax = memoryAGet32(ds, 0x40fa34);
    edx = memoryAGet32(ds, eax + 0x4);
    eax = memoryAGet32(ds, eax);
    push32(edx);
    push32(eax);
    push32(ebp);
    push32(ebp);
    sub_406be3();
    eax &= 0x80000007;
    if ((int32_t)eax >= 0)
        goto loc_403cf9;
    eax--;
    eax |= 0xfffffff8;
    eax++;
loc_403cf9: // 0000:403cf9
    ecx = memoryAGet32(ds, 0x40d108);
    push32(eax);
    eax = memoryAGet32(ds, 0x40fa34);
    push32(ebp);
    edx = memoryAGet32(ds, ecx);
    push32(edx);
    push32(eax);
    alleg40::blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));();
    ecx = memoryAGet32(ds, 0x40d108);
    esp += 0x00000020;
    eax = memoryAGet32(ds, ecx);
    edx = memoryAGet32(ds, eax + 0x1c);
    ecx = memoryAGet32(ds, edx + 0x14);
    if (ecx == ebp)
        goto loc_403d2b;
    push32(eax);
    indirectCall(cs, ecx); // 0000:403d26
    esp += 0x00000004;
loc_403d2b: // 0000:403d2b
    memoryASet32(ds, 0x413040, memoryAGet32(ds, 0x413040) - 1);
    goto loc_403d41;
loc_403d33: // 0000:403d33
    eax = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    sub_402250();
    esp += 0x00000004;
loc_403d41: // 0000:403d41
    if (memoryAGet32(ds, 0x413034) == ebp)
        goto loc_403d7a;
    eax = memoryAGet32(ds, 0x413038);
    if (eax == ebp)
        goto loc_403d80;
    if (eax != 0x0000000b)
        goto loc_403d75;
    if (memoryAGet32(ds, 0x413010) != ebp)
        goto loc_403d80;
    ecx = memoryAGet32(ds, 0x40fa94);
    push32(0x00000001);
    push32(ecx);
    sub_401570();
    eax = memoryAGet32(ds, 0x413038);
    esp += 0x00000008;
loc_403d75: // 0000:403d75
    if (eax != 0x00000032)
        goto loc_403d80;
loc_403d7a: // 0000:403d7a
    memoryASet32(ds, 0x413038, ebp);
loc_403d80: // 0000:403d80
    push32(0x0042bde0);
    sub_401200();
    ecx = memoryAGet32(ds, 0x413028);
    esp += 0x00000004;
    if (!eax)
        goto loc_403da3;
    if ((int32_t)ecx <= (int32_t)0x000000fa)
        goto loc_403da3;
    memoryASet32(ds, esp + 0x28, ebp);
loc_403da3: // 0000:403da3
    eax = memoryAGet32(ds, 0x40d1a4);
    dl = memoryAGet(ds, eax + 0x3b);
    if (!dl)
        goto loc_403ee0;
    if (ecx == ebp)
        goto loc_403dc0;
    memoryASet32(ds, esp + 0x28, ebp);
    goto loc_403ee0;
loc_403dc0: // 0000:403dc0
    edi = memoryAGet32(ds, 0x413328);
    esi = 0;
loc_403dc8: // 0000:403dc8
    eax = memoryAGet32(ds, 0x40fa34);
    push32(ebp);
    push32(0x000001e0);
    push32(ebp);
    edx = memoryAGet32(ds, eax + 0x1c);
    push32(esi);
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, edx + 0x28)); // 0000:403dd9
    eax = memoryAGet32(ds, 0x40fa34);
    push32(ebp);
    push32(0x00000280);
    push32(esi);
    ecx = memoryAGet32(ds, eax + 0x1c);
    push32(ebp);
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ecx + 0x2c)); // 0000:403ded
    esi += 0x00000002;
    esp += 0x00000028;
    if ((int32_t)esi < (int32_t)0x00000280)
        goto loc_403dc8;
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = memoryAGet32(ds, 0x40fa34);
    esi = memoryAGet32(ds, 0x40d0c4);
    push32(0xffffffff);
    eax = memoryAGet32(ds, edx + 0x130);
    push32(0x000000a0);
    push32(0x00000140);
    push32(0x0040eb04);
    push32(eax);
    push32(ecx);
    indirectCall(cs, esi); // 0000:403e29
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = memoryAGet32(ds, 0x40fa34);
    push32(0xffffffff);
    push32(0x000000d2);
    eax = memoryAGet32(ds, edx + 0x140);
    push32(0x00000140);
    push32(0x0040eaec);
    push32(eax);
    push32(ecx);
    indirectCall(cs, esi); // 0000:403e50
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = memoryAGet32(ds, 0x40fa34);
    push32(0xffffffff);
    push32(0x000000f0);
    eax = memoryAGet32(ds, edx + 0x140);
    push32(0x00000140);
    push32(0x0040ead8);
    push32(eax);
    push32(ecx);
    indirectCall(cs, esi); // 0000:403e77
    edx = memoryAGet32(ds, 0x40fa34);
    esp += 0x00000048;
    push32(edx);
    sub_402250();
    eax = memoryAGet32(ds, 0x40fa8c);
    push32(ebp);
    push32(eax);
    sub_401570();
    eax = memoryAGet32(ds, 0x40d1a4);
    esp += 0x0000000c;
    cl = memoryAGet(ds, eax + 0x3b);
    if (!cl)
        goto loc_403eaa;
loc_403ea3: // 0000:403ea3
    cl = memoryAGet(ds, eax + 0x3b);
    if (cl)
        goto loc_403ea3;
loc_403eaa: // 0000:403eaa
    alleg40::clear_keybuf();();
    esi = memoryAGet32(ds, 0x40d0bc);
    indirectCall(cs, esi); // 0000:403eb6
    if (eax)
        goto loc_403ec2;
loc_403ebc: // 0000:403ebc
    indirectCall(cs, esi); // 0000:403ebc
    if (!eax)
        goto loc_403ebc;
loc_403ec2: // 0000:403ec2
    eax = memoryAGet32(ds, 0x40d1a4);
    cl = memoryAGet(ds, eax + 0x3b);
    if (!cl)
        goto loc_403eda;
    memoryASet32(ds, esp + 0x28, ebp);
    memoryASet32(ds, esp + 0x38, 0x00000001);
loc_403eda: // 0000:403eda
    memoryASet32(ds, 0x413328, edi);
loc_403ee0: // 0000:403ee0
    cl = memoryAGet(ds, eax + 0x2f);
    if (!cl)
        goto loc_403f09;
    ecx = memoryAGet32(ds, 0x40fa40);
    eax = memoryAGet32(ds, 0x40fa34);
    edx = memoryAGet32(ds, ecx);
    push32(edx);
    push32(eax);
    push32(0x0040eacc);
    alleg40::save_pcx(stack32<const char>(0), stack32<BITMAP>(1), stack32<const PALETTE>(2));();
    eax = memoryAGet32(ds, 0x40d1a4);
    esp += 0x0000000c;
loc_403f09: // 0000:403f09
    cl = memoryAGet(ds, eax + 0x40);
    if (cl)
        goto loc_403f24;
    ecx = memoryAGet32(ds, 0x42bbc0);
    if (ecx != ebp)
        goto loc_403f24;
loc_403f1a: // 0000:403f1a
    ecx = memoryAGet32(ds, 0x42bbc0);
    if (ecx == ebp)
        goto loc_403f1a;
loc_403f24: // 0000:403f24
    if (memoryAGet32(ds, esp + 0x28) != ebp)
        goto loc_40359b;
    eax = memoryAGet32(ds, esp + 0x38);
    memoryASet32(ds, esp + 0x1c, ebx);
    if (eax != ebp)
        goto loc_40460e;
    eax = memoryAGet32(ds, 0x413008);
    esi = memoryAGet32(ds, 0x41300c);
    ecx = memoryAGet32(ds, 0x40eac8);
    esp -= 0x00000010;
    edx = eax + (eax * 4);
    memoryASet32(ds, esp + 0x4c, ecx);
    memoryASet32(ds, esp + 0x28, 0x000001e0);
    memoryASet32(ds, esp + 0x58, eax);
    edx = esi + (edx * 2);
    esi = esp;
    memoryASet32(ds, esp + 0x54, edx);
    memoryASet32(ds, esi, ecx);
    ecx = memoryAGet32(ds, esp + 0x50);
    memoryASet32(ds, esi + 0x4, ecx);
    memoryASet32(ds, esi + 0x8, edx);
    edx = memoryAGet32(ds, 0x40fa3c);
    push32(edx);
    memoryASet32(ds, esi + 0xc, eax);
    sub_401250();
    esp += 0x00000014;
    if (!eax)
        goto loc_40460e;
    ecx = 0x00000008;
    esi = 0x0040eaa4;
    edi = esp + 92;
    eax = 0;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    movsb<ES_EDI, DS_ESI>();
    edi = esp + 92;
    ecx |= 0xffffffff;
    for (flags.zero = 0; ecx != 0 && !flags.zero; --ecx) scasb_inv<ES_EDI>(al);
    al = memoryAGet(ds, esp + 0x3c);
    dl = memoryAGet(ds, esp + 0x3e);
    ecx = ~ecx;
    ecx += 0xfffffffe;
    memoryASet(ds, esp + 0x30, al);
    eax = memoryAGet32(ds, 0x40faa4);
    memoryASet32(ds, esp + 0x28, ecx);
    cl = memoryAGet(ds, esp + 0x3d);
    push32(ebp);
    push32(eax);
    memoryASet32(ds, esp + 0x28, 0x00000014);
    memoryASet32(ds, esp + 0x1c, ebp);
    memoryASet(ds, esp + 0x39, 0x00);
    memoryASet(ds, esp + 0x3a, cl);
    memoryASet(ds, esp + 0x3b, 0x00);
    memoryASet(ds, esp + 0x3c, dl);
    memoryASet(ds, esp + 0x3d, 0x00);
    memoryASet(ds, esp + 0x3e, 0x00);
    memoryASet(ds, esp + 0x3f, 0x00);
    memoryASet32(ds, esp + 0x40, ebp);
    sub_401570();
    edi = memoryAGet32(ds, esp + 0x20);
    esp += 0x00000008;
    esi = 0x0000035c;
    ebx = 0;
loc_404014: // 0000:404014
    memoryASet32(ds, 0x42bbc0, ebx);
    ecx = memoryAGet32(ds, 0x413028);
    ecx -= 0x00000010;
    edi -= 0x00000004;
    memoryASet32(ds, 0x413028, ecx);
    ecx = memoryAGet32(ds, 0x40fa34);
    push32(ecx);
    esi -= 0x00000008;
    sub_402780();
    edx = memoryAGet32(ds, 0x40fa40);
    esp += 0x00000004;
    ecx = memoryAGet32(ds, edx + 0x290);
    push32(edi);
    eax = memoryAGet32(ds, ecx);
    ebx = memoryAGet32(ds, ecx + 0x1c);
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edx = eax;
    eax = 0x00000140;
    edx = sar32(edx, 0x00000001);
    eax -= edx;
    edx = memoryAGet32(ds, 0x40fa34);
    flags.zero = memoryAGet32(ds, ebx) == 0x00000008;
    push32(eax);
    ebx = memoryAGet32(ds, edx + 0x1c);
    push32(ecx);
    push32(edx);
    if (!flags.zero)
        goto loc_404074;
    indirectCall(cs, memoryAGet32(ds, ebx + 0x44)); // 0000:40406f
    goto loc_404077;
loc_404074: // 0000:404074
    indirectCall(cs, memoryAGet32(ds, ebx + 0x40)); // 0000:404074
loc_404077: // 0000:404077
    eax = memoryAGet32(ds, 0x40fa40);
    edx = memoryAGet32(ds, 0x40fa34);
    esp += 0x00000010;
    ecx = memoryAGet32(ds, eax + 0x130);
    push32(0xffffffff);
    push32(esi);
    push32(0x00000140);
    push32(0x0040ea90);
    push32(ecx);
    push32(edx);
    alleg40::textout_centre(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<const char>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));();
    ecx = memoryAGet32(ds, esp + 0x34);
    ebx = 0;
    esp += 0x00000018;
    if (ecx == ebx)
        goto loc_4040b2;
    ecx++;
    memoryASet32(ds, esp + 0x1c, ecx);
loc_4040b2: // 0000:4040b2
    eax = memoryAGet32(ds, 0x413008);
    eax = eax + (eax * 4);
    if ((int32_t)ecx > (int32_t)eax)
        goto loc_4040c6;
    if ((int32_t)ecx <= (int32_t)0x000000fa)
        goto loc_4040f3;
loc_4040c6: // 0000:4040c6
    ecx = memoryAGet32(ds, 0x40faa0);
    push32(ebx);
    push32(ecx);
    sub_401570();
    edx = memoryAGet32(ds, 0x40fa9c);
    push32(edx);
    alleg40::stop_sample(stack32<const SAMPLE>(0));();
    esp += 0x0000000c;
    memoryASet32(ds, esp + 0x1c, ebx);
    memoryASet32(ds, 0x413040, 0x00000018);
    goto loc_4040fb;
loc_4040f3: // 0000:4040f3
    if (memoryAGet32(ds, 0x413040) == ebx)
        goto loc_40416b;
loc_4040fb: // 0000:4040fb
    eax = memoryAGet32(ds, 0x40d108);
    eax = memoryAGet32(ds, eax);
    ecx = memoryAGet32(ds, eax + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x10);
    if (ecx == ebx)
        goto loc_404112;
    push32(eax);
    indirectCall(cs, ecx); // 0000:40410d
    esp += 0x00000004;
loc_404112: // 0000:404112
    eax = memoryAGet32(ds, 0x40fa34);
    edx = memoryAGet32(ds, eax + 0x4);
    eax = memoryAGet32(ds, eax);
    push32(edx);
    push32(eax);
    push32(ebx);
    push32(ebx);
    sub_406be3();
    eax &= 0x80000007;
    if ((int32_t)eax >= 0)
        goto loc_404131;
    eax--;
    eax |= 0xfffffff8;
    eax++;
loc_404131: // 0000:404131
    ecx = memoryAGet32(ds, 0x40d108);
    push32(eax);
    eax = memoryAGet32(ds, 0x40fa34);
    push32(ebx);
    edx = memoryAGet32(ds, ecx);
    push32(edx);
    push32(eax);
    alleg40::blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));();
    ecx = memoryAGet32(ds, 0x40d108);
    esp += 0x00000020;
    eax = memoryAGet32(ds, ecx);
    edx = memoryAGet32(ds, eax + 0x1c);
    ecx = memoryAGet32(ds, edx + 0x14);
    if (ecx == ebx)
        goto loc_404163;
    push32(eax);
    indirectCall(cs, ecx); // 0000:40415e
    esp += 0x00000004;
loc_404163: // 0000:404163
    memoryASet32(ds, 0x413040, memoryAGet32(ds, 0x413040) - 1);
    goto loc_404179;
loc_40416b: // 0000:40416b
    eax = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    sub_402250();
    esp += 0x00000004;
loc_404179: // 0000:404179
    ecx = memoryAGet32(ds, 0x40d1a4);
    al = memoryAGet(ds, ecx + 0x40);
    if (al)
        goto loc_404198;
    eax = memoryAGet32(ds, 0x42bbc0);
    if (eax != ebx)
        goto loc_404198;
loc_40418f: // 0000:40418f
    eax = memoryAGet32(ds, 0x42bbc0);
    if (eax == ebx)
        goto loc_40418f;
loc_404198: // 0000:404198
    if ((int32_t)esi > (int32_t)0x00000104)
        goto loc_404014;
    memoryASet32(ds, esp + 0x18, edi);
    memoryASet32(ds, 0x413028, ebx);
    alleg40::clear_keybuf();();
    edi = memoryAGet32(ds, esp + 0x38);
loc_4041b8: // 0000:4041b8
    memoryASet32(ds, 0x42bbc0, 0x00000000);
    edx = memoryAGet32(ds, 0x40ffc4);
    edx++;
    memoryASet32(ds, 0x40ffc4, edx);
    eax = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    sub_402780();
    ecx = memoryAGet32(ds, 0x40fa40);
    esp += 0x00000004;
    ecx = memoryAGet32(ds, ecx + 0x290);
    eax = memoryAGet32(ds, ecx);
    esi = memoryAGet32(ds, ecx + 0x1c);
    edx = (int32_t)eax < 0 ? -1 : 0;
    ebx = memoryAGet32(ds, esi);
    eax -= edx;
    edx = eax;
    eax = 0x00000140;
    edx = sar32(edx, 0x00000001);
    eax -= edx;
    edx = memoryAGet32(ds, 0x40fa34);
    flags.zero = ebx == 0x00000008;
    ebx = memoryAGet32(ds, esp + 0x18);
    esi = memoryAGet32(ds, edx + 0x1c);
    push32(ebx);
    push32(eax);
    push32(ecx);
    push32(edx);
    if (!flags.zero)
        goto loc_404219;
    indirectCall(cs, memoryAGet32(ds, esi + 0x44)); // 0000:404214
    goto loc_40421c;
loc_404219: // 0000:404219
    indirectCall(cs, memoryAGet32(ds, esi + 0x40)); // 0000:404219
loc_40421c: // 0000:40421c
    eax = memoryAGet32(ds, esp + 0x28);
    ecx = memoryAGet32(ds, 0x40fa40);
    esp += 0x00000010;
    ebx = memoryAGet32(ds, 0x40d0c4);
    edx = memoryAGet32(ds, ecx + 0x130);
    eax = (eax + eax) + -100;
    push32(0xffffffff);
    push32(eax);
    eax = memoryAGet32(ds, 0x40fa34);
    push32(0x00000140);
    push32(0x0040ea90);
    push32(edx);
    push32(eax);
    indirectCall(cs, ebx); // 0000:40424d
    esp += 0x00000018;
    if (ebp)
        goto loc_40425f;
    if (!(memoryAGet(ds, 0x40ffc4) & 0x04))
        goto loc_40429c;
loc_40425f: // 0000:40425f
    ecx = memoryAGet32(ds, esp + 0x18);
    eax = memoryAGet32(ds, 0x40fa40);
    push32(0xffffffff);
    edx = esp + 52;
    esi = ecx + 150;
    ecx = memoryAGet32(ds, eax + 0x140);
    push32(esi);
    push32(0x0000012c);
    push32(edx);
    edx = memoryAGet32(ds, 0x40fa34);
    push32(ecx);
    push32(edx);
    indirectCall(cs, ebx); // 0000:404289
    esp += 0x00000018;
    if (ebp != 0x00000001)
        goto loc_40429c;
    if (!(memoryAGet(ds, 0x40ffc4) & 0x04))
        goto loc_4042da;
loc_40429c: // 0000:40429c
    eax = memoryAGet32(ds, esp + 0x18);
    edx = memoryAGet32(ds, 0x40fa40);
    push32(0xffffffff);
    ecx = esp + 54;
    esi = eax + 150;
    eax = memoryAGet32(ds, edx + 0x140);
    push32(esi);
    push32(0x00000140);
    push32(ecx);
    ecx = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    push32(ecx);
    indirectCall(cs, ebx); // 0000:4042c7
    esp += 0x00000018;
    if (ebp != 0x00000002)
        goto loc_4042da;
    if (!(memoryAGet(ds, 0x40ffc4) & 0x04))
        goto loc_404332;
loc_4042da: // 0000:4042da
    eax = memoryAGet32(ds, 0x40fa40);
    push32(0xffffffff);
    push32(esi);
    edx = esp + 60;
    ecx = memoryAGet32(ds, eax + 0x140);
    push32(0x00000154);
    push32(edx);
    edx = memoryAGet32(ds, 0x40fa34);
    push32(ecx);
    push32(edx);
    indirectCall(cs, ebx); // 0000:4042fa
    esp += 0x00000018;
    if (ebp != 0x00000003)
        goto loc_404332;
    if (!(memoryAGet(ds, 0x40ffc4) & 0x04))
        goto loc_404332;
    eax = memoryAGet32(ds, 0x40fa40);
    edx = memoryAGet32(ds, 0x40fa34);
    push32(0xffffffff);
    push32(esi);
    ecx = memoryAGet32(ds, eax + 0x140);
    push32(0x00000168);
    push32(0x0040ea8c);
    push32(ecx);
    push32(edx);
    indirectCall(cs, ebx); // 0000:40432d
    esp += 0x00000018;
loc_404332: // 0000:404332
    push32(0x000000ef);
    push32(0x000000e0);
    sub_4022b0();
    ecx = memoryAGet32(ds, esp + 0x24);
    esp += 0x00000008;
    if (!ecx)
        goto loc_404351;
    ecx++;
    memoryASet32(ds, esp + 0x1c, ecx);
loc_404351: // 0000:404351
    eax = memoryAGet32(ds, 0x413008);
    eax = eax + (eax * 4);
    if ((int32_t)ecx > (int32_t)eax)
        goto loc_404365;
    if ((int32_t)ecx <= (int32_t)0x000000fa)
        goto loc_404397;
loc_404365: // 0000:404365
    ecx = memoryAGet32(ds, 0x40faa0);
    push32(0x00000000);
    push32(ecx);
    sub_401570();
    edx = memoryAGet32(ds, 0x40fa9c);
    push32(edx);
    alleg40::stop_sample(stack32<const SAMPLE>(0));();
    esp += 0x0000000c;
    memoryASet32(ds, esp + 0x1c, 0x00000000);
    memoryASet32(ds, 0x413040, 0x00000018);
    goto loc_4043a0;
loc_404397: // 0000:404397
    eax = memoryAGet32(ds, 0x413040);
    if (!eax)
        goto loc_404413;
loc_4043a0: // 0000:4043a0
    eax = memoryAGet32(ds, 0x40d108);
    eax = memoryAGet32(ds, eax);
    ecx = memoryAGet32(ds, eax + 0x1c);
    ecx = memoryAGet32(ds, ecx + 0x10);
    if (!ecx)
        goto loc_4043b7;
    push32(eax);
    indirectCall(cs, ecx); // 0000:4043b2
    esp += 0x00000004;
loc_4043b7: // 0000:4043b7
    eax = memoryAGet32(ds, 0x40fa34);
    edx = memoryAGet32(ds, eax + 0x4);
    eax = memoryAGet32(ds, eax);
    push32(edx);
    push32(eax);
    push32(0x00000000);
    push32(0x00000000);
    sub_406be3();
    eax &= 0x80000007;
    if ((int32_t)eax >= 0)
        goto loc_4043d8;
    eax--;
    eax |= 0xfffffff8;
    eax++;
loc_4043d8: // 0000:4043d8
    ecx = memoryAGet32(ds, 0x40d108);
    push32(eax);
    eax = memoryAGet32(ds, 0x40fa34);
    push32(0x00000000);
    edx = memoryAGet32(ds, ecx);
    push32(edx);
    push32(eax);
    alleg40::blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));();
    ecx = memoryAGet32(ds, 0x40d108);
    esp += 0x00000020;
    eax = memoryAGet32(ds, ecx);
    edx = memoryAGet32(ds, eax + 0x1c);
    ecx = memoryAGet32(ds, edx + 0x14);
    if (!ecx)
        goto loc_40440b;
    push32(eax);
    indirectCall(cs, ecx); // 0000:404406
    esp += 0x00000004;
loc_40440b: // 0000:40440b
    memoryASet32(ds, 0x413040, memoryAGet32(ds, 0x413040) - 1);
    goto loc_404421;
loc_404413: // 0000:404413
    eax = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    sub_402250();
    esp += 0x00000004;
loc_404421: // 0000:404421
    push32(0x0042bde0);
    sub_401060();
    esp += 0x00000004;
    eax = alleg40::keypressed();();
    if (!eax)
        goto loc_404529;
    if (memoryAGet32(ds, esp + 0x20) != 0x00000014)
        goto loc_404529;
    eax = alleg40::readkey();();
    eax &= 0x000000ff;
    eax -= 0x00000020;
    if (eax != 0xffffffe8)
        goto loc_404461;
    eax = 0xffffffa4;
    goto loc_40446a;
loc_404461: // 0000:404461
    if (eax == 0x00000020)
        goto loc_404529;
loc_40446a: // 0000:40446a
    edx = memoryAGet32(ds, esp + 0x28);
    esi = memoryAGet32(ds, esp + 0x14);
    ecx = 0;
    if ((int32_t)edx <= 0)
        goto loc_4044a9;
loc_404478: // 0000:404478
    dl = memoryAGet(ds, esp + ecx + 0x5c);
    ebx = (int8_t)dl;
    if (eax != ebx)
        goto loc_40449c;
    memoryASet(ds, esp + ebp * 2 + 0x30, dl);
    ebp++;
    edi = 0x00000064;
    esi = ecx;
    if (ebp != 0x00000003)
        goto loc_40449c;
    memoryASet32(ds, esp + 0x20, 0x00000013);
loc_40449c: // 0000:40449c
    edx = memoryAGet32(ds, esp + 0x28);
    ecx++;
    if ((int32_t)ecx < (int32_t)edx)
        goto loc_404478;
    memoryASet32(ds, esp + 0x14, esi);
loc_4044a9: // 0000:4044a9
    if (edi)
        goto loc_404562;
    push32(0x0042bde0);
    sub_4011f0();
    esp += 0x00000004;
    if (!eax)
        goto loc_4044da;
    eax = memoryAGet32(ds, esp + 0x28);
    esi++;
    memoryASet32(ds, esp + 0x14, esi);
    if ((int32_t)esi <= (int32_t)eax)
        goto loc_4044d5;
    esi = 0;
    memoryASet32(ds, esp + 0x14, esi);
loc_4044d5: // 0000:4044d5
    edi = 0x00000008;
loc_4044da: // 0000:4044da
    push32(0x0042bde0);
    sub_4011e0();
    esp += 0x00000004;
    if (!eax)
        goto loc_4044ff;
    esi--;
    memoryASet32(ds, esp + 0x14, esi);
    if ((int32_t)esi >= 0)
        goto loc_4044fa;
    esi = memoryAGet32(ds, esp + 0x28);
    memoryASet32(ds, esp + 0x14, esi);
loc_4044fa: // 0000:4044fa
    edi = 0x00000008;
loc_4044ff: // 0000:4044ff
    push32(0x0042bde0);
    sub_401200();
    esp += 0x00000004;
    if (!eax)
        goto loc_40455e;
    al = memoryAGet(ds, esp + esi + 0x5c);
    if (al != 0xa4)
        goto loc_404532;
    if (!ebp)
        goto loc_404532;
    memoryASet(ds, esp + ebp * 2 + 0x30, 0x2e);
    ebp--;
    edi = 0x00000064;
    goto loc_404562;
loc_404529: // 0000:404529
    esi = memoryAGet32(ds, esp + 0x14);
    goto loc_4044a9;
loc_404532: // 0000:404532
    if ((int32_t)ebp >= (int32_t)0x00000002)
        goto loc_404543;
    if (al == 0xa4)
        goto loc_404557;
    ebp++;
    edi = 0x00000064;
    goto loc_404562;
loc_404543: // 0000:404543
    if (al == 0xa4)
        goto loc_404557;
    if (memoryAGet32(ds, esp + 0x20) != 0x00000014)
        goto loc_404557;
    memoryASet32(ds, esp + 0x20, 0x00000013);
    ebp++;
loc_404557: // 0000:404557
    edi = 0x00000064;
    goto loc_404562;
loc_40455e: // 0000:40455e
    if (!edi)
        goto loc_404563;
loc_404562: // 0000:404562
    edi--;
loc_404563: // 0000:404563
    push32(0x0042bde0);
    sub_401220();
    esp += 0x00000004;
    if (eax)
        goto loc_404576;
    edi = 0;
loc_404576: // 0000:404576
    if ((int32_t)ebp >= (int32_t)0x00000003)
        goto loc_404583;
    cl = memoryAGet(ds, esp + esi + 0x5c);
    memoryASet(ds, esp + ebp * 2 + 0x30, cl);
loc_404583: // 0000:404583
    eax = memoryAGet32(ds, esp + 0x20);
    if ((int32_t)eax >= (int32_t)0x00000014)
        goto loc_404591;
    eax--;
    memoryASet32(ds, esp + 0x20, eax);
loc_404591: // 0000:404591
    edx = memoryAGet32(ds, 0x40d1a4);
    cl = memoryAGet(ds, edx + 0x40);
    if (cl)
        goto loc_4045b2;
    ecx = memoryAGet32(ds, 0x42bbc0);
    if (ecx)
        goto loc_4045b2;
loc_4045a8: // 0000:4045a8
    ecx = memoryAGet32(ds, 0x42bbc0);
    if (!ecx)
        goto loc_4045a8;
loc_4045b2: // 0000:4045b2
    if (eax)
        goto loc_4041b8;
    al = memoryAGet(ds, esp + 0x30);
    cl = memoryAGet(ds, esp + 0x32);
    dl = memoryAGet(ds, esp + 0x34);
    esp -= 0x00000010;
    memoryASet(ds, esp + 0x4c, al);
    memoryASet(ds, esp + 0x4d, cl);
    memoryASet(ds, esp + 0x4e, dl);
    ecx = memoryAGet32(ds, esp + 0x4c);
    edx = memoryAGet32(ds, esp + 0x50);
    eax = esp;
    memoryASet32(ds, eax, ecx);
    ecx = memoryAGet32(ds, esp + 0x54);
    memoryASet32(ds, eax + 0x4, edx);
    edx = memoryAGet32(ds, esp + 0x58);
    memoryASet32(ds, eax + 0x8, ecx);
    memoryASet32(ds, eax + 0xc, edx);
    eax = memoryAGet32(ds, 0x40fa3c);
    push32(eax);
    sub_401320();
    ecx = memoryAGet32(ds, 0x40fa3c);
    push32(ecx);
    sub_401280();
    esp += 0x00000018;
    ebp = 0;
loc_40460e: // 0000:40460e
    edx = memoryAGet32(ds, 0x40fa7c);
    push32(ebp);
    push32(edx);
    sub_401570();
    push32(0x00000008);
    alleg40::fade_out(stack32<int>(0));();
    eax = memoryAGet32(ds, 0x40fa60);
    push32(eax);
    alleg40::stop_sample(stack32<const SAMPLE>(0));();
    ecx = memoryAGet32(ds, 0x40d108);
    edx = memoryAGet32(ds, ecx);
    push32(edx);
    alleg40::clear_bitmap(stack32<BITMAP>(0));();
    esp += 0x00000014;
    eax = 0;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 4;
}
void sub_404650() // 0000:404650 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp &= 0xfffffff8;
    esp -= 0x00000014;
    fild32(memoryAGet32(ds, 0x40e044));
    eax = memoryAGet32(ds, 0x40d108);
    push32(ebx);
    push32(esi);
    push32(edi);
    memoryASet64(ds, esp + 0x10, fst64());
    fmul64(memoryAGet64(ds, 0x40d2c8));
    ecx = memoryAGet32(ds, eax);
    push32(ecx);
    memoryASet64(ds, esp + 0x1c, fstp64());
    alleg40::clear_bitmap(stack32<BITMAP>(0));();
    edx = memoryAGet32(ds, 0x40d108);
    ecx = memoryAGet32(ds, 0x40fa40);
    push32(0x000001e0);
    push32(0x00000280);
    eax = memoryAGet32(ds, edx);
    edx = memoryAGet32(ds, ecx + 0x420);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(eax);
    push32(edx);
    alleg40::blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));();
    eax = memoryAGet32(ds, 0x40fa40);
    edx = memoryAGet32(ds, 0x40d108);
    esp += 0x00000024;
    ecx = memoryAGet32(ds, eax + 0x410);
    eax = memoryAGet32(ds, edx);
    push32(0x00000014);
    push32(0x000000fa);
    edx = memoryAGet32(ds, ecx + 0x1c);
    push32(ecx);
    push32(eax);
    esi = memoryAGet32(ds, edx);
    edx = memoryAGet32(ds, eax + 0x1c);
    if (esi != 0x00000008)
        goto loc_4046dd;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:4046d8
    goto loc_4046e0;
loc_4046dd: // 0000:4046dd
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:4046dd
loc_4046e0: // 0000:4046e0
    eax = memoryAGet32(ds, 0x40fa40);
    edx = memoryAGet32(ds, 0x40d108);
    esp += 0x00000010;
    esi = memoryAGet32(ds, 0x40d0c4);
    ecx = memoryAGet32(ds, eax + 0x130);
    eax = memoryAGet32(ds, edx);
    push32(0xffffffff);
    push32(0x0000012c);
    push32(0x00000140);
    push32(0x0040eb4c);
    push32(ecx);
    push32(eax);
    indirectCall(cs, esi); // 0000:40470f
    ecx = memoryAGet32(ds, 0x40fa40);
    eax = memoryAGet32(ds, 0x40d108);
    push32(0xffffffff);
    push32(0x0000017c);
    edx = memoryAGet32(ds, ecx + 0x140);
    ecx = memoryAGet32(ds, eax);
    push32(0x00000140);
    push32(0x0040eb30);
    push32(edx);
    push32(ecx);
    indirectCall(cs, esi); // 0000:404737
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = memoryAGet32(ds, 0x40d108);
    push32(0xffffffff);
    push32(0x0000019a);
    eax = memoryAGet32(ds, edx + 0x140);
    edx = memoryAGet32(ds, ecx);
    push32(0x00000140);
    push32(0x0040eb10);
    push32(eax);
    push32(edx);
    indirectCall(cs, esi); // 0000:404760
    eax = memoryAGet32(ds, 0x40fa40);
    esp += 0x00000048;
    ecx = memoryAGet32(ds, eax);
    push32(0x00000010);
    push32(ecx);
    alleg40::fade_in(stack32<const PALETTE>(0), stack32<int>(1));();
    esp += 0x00000008;
    memoryASet32(ds, 0x42bbc0, 0x00000000);
    edx = memoryAGet32(ds, 0x40d1a4);
    al = memoryAGet(ds, edx + 0x3b);
    if (al)
        goto loc_4047fd;
    ebx = memoryAGet32(ds, 0x40d0cc);
    esi = memoryAGet32(ds, 0x40fa64);
loc_40479b: // 0000:40479b
    eax = memoryAGet32(ds, 0x42bbc0);
    if ((int32_t)eax >= (int32_t)0x00000096)
        goto loc_4047fd;
    edi = memoryAGet32(ds, 0x42bbc0);
    if (!esi)
        goto loc_4047d3;
    fld64(memoryAGet64(ds, esp + 0x10));
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    sub_406e04();
    push32(eax);
    push32(esi);
    indirectCall(cs, ebx); // 0000:4047c8
    esi = memoryAGet32(ds, 0x40fa64);
    esp += 0x00000014;
loc_4047d3: // 0000:4047d3
    fld64(memoryAGet64(ds, esp + 0x10));
    fsub64(memoryAGet64(ds, esp + 0x18));
    memoryASet64(ds, esp + 0x10, fstp64());
    eax = memoryAGet32(ds, 0x42bbc0);
    if (edi != eax)
        goto loc_4047f1;
loc_4047e8: // 0000:4047e8
    eax = memoryAGet32(ds, 0x42bbc0);
    if (edi == eax)
        goto loc_4047e8;
loc_4047f1: // 0000:4047f1
    eax = memoryAGet32(ds, 0x40d1a4);
    cl = memoryAGet(ds, eax + 0x3b);
    if (!cl)
        goto loc_40479b;
loc_4047fd: // 0000:4047fd
    push32(0x00000010);
    alleg40::fade_out(stack32<int>(0));();
    esp += 0x00000004;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp;
    ebp = pop32();
    esp += 4;
}
void sub_404810() // 0000:404810 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x40d108);
    edx = memoryAGet32(ds, 0x40fa40);
    push32(esi);
    push32(edi);
    ecx = memoryAGet32(ds, eax);
    eax = memoryAGet32(ds, edx + 0x420);
    esi = 0;
    push32(0x000001e0);
    push32(0x00000280);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(ecx);
    push32(eax);
    alleg40::blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));();
    ecx = memoryAGet32(ds, 0x40d108);
    eax = memoryAGet32(ds, 0x40fa40);
    push32(0x000001e0);
    push32(0x00000280);
    edx = memoryAGet32(ds, ecx);
    ecx = memoryAGet32(ds, eax + 0x2c0);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(esi);
    push32(edx);
    push32(ecx);
    alleg40::masked_blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));();
    esp += 0x00000040;
    push32(0x0042bde0);
    sub_401220();
    esp += 0x00000004;
    if (!eax)
        goto loc_404895;
loc_40487a: // 0000:40487a
    push32(0x0042bde0);
    sub_401060();
    push32(0x0042bde0);
    sub_401220();
    esp += 0x00000008;
    if (eax)
        goto loc_40487a;
loc_404895: // 0000:404895
    edx = memoryAGet32(ds, 0x40fa40);
    push32(0x00000008);
    eax = memoryAGet32(ds, edx);
    push32(eax);
    alleg40::fade_in(stack32<const PALETTE>(0), stack32<int>(1));();
    edi = memoryAGet32(ds, 0x40d0b8);
    esp += 0x00000008;
loc_4048af: // 0000:4048af
    memoryASet32(ds, 0x42bbc0, 0x00000000);
    push32(0x000000ef);
    push32(0x000000e0);
    sub_4022b0();
    push32(0x0042bde0);
    sub_401060();
    push32(0x0042bde0);
    sub_401200();
    esp += 0x00000010;
    if (!eax)
        goto loc_4048e8;
    esi = 0x00000001;
loc_4048e8: // 0000:4048e8
    eax = memoryAGet32(ds, 0x40d1a4);
    cl = memoryAGet(ds, eax + 0x3b);
    if (cl)
        goto loc_4048fb;
    cl = memoryAGet(ds, eax + 0x43);
    if (!cl)
        goto loc_404900;
loc_4048fb: // 0000:4048fb
    esi = 0x00000001;
loc_404900: // 0000:404900
    cl = memoryAGet(ds, eax + 0x2f);
    if (!cl)
        goto loc_404922;
    ecx = memoryAGet32(ds, 0x40fa40);
    eax = memoryAGet32(ds, 0x40d108);
    edx = memoryAGet32(ds, ecx);
    ecx = memoryAGet32(ds, eax);
    push32(edx);
    push32(ecx);
    push32(0x0040eb60);
    indirectCall(cs, edi); // 0000:40491d
    esp += 0x0000000c;
loc_404922: // 0000:404922
    eax = memoryAGet32(ds, 0x42bbc0);
    if (eax)
        goto loc_404934;
loc_40492b: // 0000:40492b
    eax = memoryAGet32(ds, 0x42bbc0);
    if (!eax)
        goto loc_40492b;
loc_404934: // 0000:404934
    if (!esi)
        goto loc_4048af;
    push32(0x00000008);
    alleg40::fade_out(stack32<int>(0));();
    esp += 0x00000004;
    edi = pop32();
    esi = pop32();
    esp += 4;
}
void sub_404950() // 0000:404950 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x40fa84);
    push32(0x00000000);
    push32(eax);
    sub_401570();
    esp += 0x00000008;
    esp += 4;
}
void sub_404970() // 0000:404970 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x40fa80);
    push32(0x00000000);
    push32(eax);
    sub_401570();
    esp += 0x00000008;
    esp += 4;
}
void sub_404990() // 0000:404990 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ecx);
    memoryASet32(ds, 0x40fab0, memoryAGet32(ds, 0x40fab0) + 1);
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x000000c8;
    idiv32(ecx);
    if (edx != 0x00000001)
        goto loc_4049b2;
    memoryASet32(ds, 0x40faac, memoryAGet32(ds, 0x40faac) + 1);
loc_4049b2: // 0000:4049b2
    if (memoryAGet32(ds, 0x40faac) != 0x00000003)
        goto loc_4049c5;
    memoryASet32(ds, 0x40faac, 0x00000000);
loc_4049c5: // 0000:4049c5
    eax = memoryAGet32(ds, 0x40fa40);
    edx = memoryAGet32(ds, 0x40fa34);
    push32(esi);
    push32(edi);
    ecx = memoryAGet32(ds, eax + 0x420);
    push32(0x000001e0);
    push32(0x00000280);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(edx);
    push32(ecx);
    alleg40::blit(stack32<BITMAP>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5), stack32<int>(6), stack32<int>(7));();
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = memoryAGet32(ds, 0x40fa34);
    esp += 0x00000020;
    eax = memoryAGet32(ds, edx + 0x410);
    push32(0x00000014);
    push32(0x000000fa);
    edx = memoryAGet32(ds, eax + 0x1c);
    push32(eax);
    push32(ecx);
    esi = memoryAGet32(ds, edx);
    edx = memoryAGet32(ds, ecx + 0x1c);
    if (esi != 0x00000008)
        goto loc_404a22;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:404a1d
    goto loc_404a25;
loc_404a22: // 0000:404a22
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:404a22
loc_404a25: // 0000:404a25
    eax = memoryAGet32(ds, 0x40fab0);
    ecx = memoryAGet32(ds, 0x40d114);
    esp += 0x00000010;
    edx = eax + (eax * 2);
    eax = eax + (eax * 4);
    eax <<= 16;
    edx <<= 16;
    eax -= 0x003fc000;
    edx -= 0x003fbff6;
    eax = sar32(eax, 0x0f);
    edx = sar32(edx, 0x0f);
    eax &= 0x000001ff;
    edx &= 0x000001ff;
    push32(ebx);
    eax = memoryAGet32(ds, ecx + eax * 4);
    edx = memoryAGet32(ds, ecx + edx * 4);
    ecx = eax + (eax * 4);
    ecx <<= 1;
    memoryASet32(ss, ebp - 4, ecx);
    eax = memoryAGet32(ss, ebp - 4);
    eax = sar32(eax, 0x10);
    esi = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ss, ebp - 4, eax);
    eax = memoryAGet32(ds, 0x40faac);
    push32(0x00000000);
    eax += 0x00000026;
    edx = edx + (edx * 4);
    eax <<= 4;
    edi = memoryAGet32(ds, 0x40fa34);
    push32(0x00010000);
    esi = memoryAGet32(ds, eax + esi);
    push32(edx);
    eax = memoryAGet32(ds, edi + 0x1c);
    ebx = memoryAGet32(ds, esi + 0x4);
    edx = ebx;
    edx <<= 15;
    push32(edx);
    edx = memoryAGet32(ds, esi);
    edx <<= 15;
    push32(edx);
    edx = memoryAGet32(ss, ebp - 4);
    ecx = sar32(ecx, 0x0f);
    memoryASet32(ss, ebp - 4, eax);
    ecx &= 0x00000001;
    eax = ebx;
    eax <<= 16;
    ecx = (ecx + edx) + 10;
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    ecx <<= 16;
    eax = sar32(eax, 0x00000001);
    ecx += eax;
    eax = memoryAGet32(ds, esi);
    eax <<= 16;
    edx = (int32_t)eax < 0 ? -1 : 0;
    eax -= edx;
    edx = memoryAGet32(ss, ebp - 4);
    eax = sar32(eax, 0x00000001);
    eax += 0x00280000;
    push32(ecx);
    push32(eax);
    push32(esi);
    push32(edi);
    indirectCall(cs, memoryAGet32(ds, edx + 0xa0)); // 0000:404adf
    eax = memoryAGet32(ds, 0x40fa40);
    edx = memoryAGet32(ds, 0x40fa34);
    push32(0xffffffff);
    push32(0x000000f0);
    ecx = memoryAGet32(ds, eax + 0x140);
    push32(0x000001a4);
    push32(0x0040eb88);
    push32(ecx);
    push32(edx);
    alleg40::textout(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<const char>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));();
    eax = memoryAGet32(ds, 0x40fa40);
    ecx = memoryAGet32(ds, 0x40fa34);
    esp += 0x0000003c;
    eax = memoryAGet32(ds, eax + 0x2a0);
    ebx = pop32();
    edx = memoryAGet32(ds, eax + 0x1c);
    flags.zero = memoryAGet32(ds, edx) == 0x00000008;
    edx = memoryAGet32(ds, ecx + 0x1c);
    push32(0x0000010c);
    push32(0x000001a7);
    push32(eax);
    push32(ecx);
    if (!flags.zero)
        goto loc_404b40;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:404b3b
    goto loc_404b43;
loc_404b40: // 0000:404b40
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:404b40
loc_404b43: // 0000:404b43
    eax = memoryAGet32(ds, 0x40fa40);
    edx = memoryAGet32(ds, 0x40fa34);
    esp += 0x00000010;
    ecx = memoryAGet32(ds, eax + 0x140);
    eax = memoryAGet32(ds, 0x40fa3c);
    push32(0x00000104);
    push32(0x000001a4);
    push32(ecx);
    push32(edx);
    push32(eax);
    sub_4014c0();
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000005);
    alleg40::drawing_mode(stack32<int>(0), stack32<BITMAP>(1), stack32<int>(2), stack32<int>(3));();
    ecx = memoryAGet32(ds, 0x40d0dc);
    push32(0x000000c8);
    push32(0x000001c0);
    push32(0x0000027f);
    memoryASet32(ds, ecx, 0x00413340);
    eax = memoryAGet32(ds, 0x40fa34);
    push32(0x000001c0);
    push32(0x00000000);
    edx = memoryAGet32(ds, eax + 0x1c);
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, edx + 0x34)); // 0000:404ba7
    eax = memoryAGet32(ds, 0x40fa34);
    push32(0x00000096);
    push32(0x000001c1);
    push32(0x0000027f);
    ecx = memoryAGet32(ds, eax + 0x1c);
    push32(0x000001c1);
    push32(0x00000000);
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, ecx + 0x34)); // 0000:404bc9
    eax = memoryAGet32(ds, 0x40fa34);
    esp += 0x00000054;
    edx = memoryAGet32(ds, eax + 0x1c);
    push32(0x00000064);
    push32(0x000001df);
    push32(0x0000027f);
    push32(0x000001c2);
    push32(0x00000000);
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, edx + 0x38)); // 0000:404beb
    eax = memoryAGet32(ds, 0x40e714);
    push32(eax);
    push32(0x00423380);
    sub_406a90();
    ecx = memoryAGet32(ds, 0x40fa34);
    push32(0x000001c2);
    push32(0x00000000);
    push32(ecx);
    push32(0x00423380);
    sub_406930();
    esp += 0x00000030;
    if (eax)
        goto loc_404c2a;
    push32(0x00423380);
    sub_406aa0();
    esp += 0x00000004;
loc_404c2a: // 0000:404c2a
    alleg40::solid_mode();();
    eax = memoryAGet32(ds, 0x40fa30);
    flags.zero = eax == 0;
    eax = 0x0040eb7c;
    if (!flags.zero)
        goto loc_404c43;
    eax = 0x0040fab4;
loc_404c43: // 0000:404c43
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    esi = memoryAGet32(ds, 0x40d190);
    eax = memoryAGet32(ds, edx + 0x150);
    push32(0x0042bbe0);
    push32(0x0040eb78);
    push32(0x0040eb6c);
    push32(0x00000000);
    push32(0x00000003);
    push32(0x0000027e);
    push32(eax);
    push32(ecx);
    indirectCall(cs, esi); // 0000:404c76
    eax = memoryAGet32(ds, 0x40fa30);
    esp += 0x00000024;
    flags.zero = eax == 0;
    eax = 0x0040eb7c;
    if (!flags.zero)
        goto loc_404c8e;
    eax = 0x0040fab4;
loc_404c8e: // 0000:404c8e
    edx = memoryAGet32(ds, 0x40fa40);
    ecx = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    push32(0x0042bbe0);
    eax = memoryAGet32(ds, edx + 0x150);
    push32(0x0040eb78);
    push32(0x0040eb6c);
    push32(0x00000069);
    push32(0x00000002);
    push32(0x0000027d);
    push32(eax);
    push32(ecx);
    indirectCall(cs, esi); // 0000:404cbb
    eax = memoryAGet32(ds, 0x40e038);
    esi = memoryAGet32(ds, 0x40d160);
    edi = memoryAGet32(ds, 0x40d180);
    esp += 0x00000024;
    if (!eax)
        goto loc_404d11;
    eax = memoryAGet32(ds, 0x40e050);
    if (!eax)
        goto loc_404d08;
    push32(0x00000000);
    push32(0x00000000);
    push32(0x000001e0);
    push32(0x00000280);
    push32(0x00000000);
    indirectCall(cs, esi); // 0000:404cee
    edx = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ds, 0x40e038, 0x00000000);
    eax = memoryAGet32(ds, edx);
    push32(eax);
    indirectCall(cs, edi); // 0000:404d03
    esp += 0x00000018;
loc_404d08: // 0000:404d08
    eax = memoryAGet32(ds, 0x40e038);
    if (eax)
        goto loc_404d47;
loc_404d11: // 0000:404d11
    eax = memoryAGet32(ds, 0x40e050);
    if (eax)
        goto loc_404d47;
    push32(0x00000000);
    push32(0x00000000);
    push32(0x000001e0);
    push32(0x00000280);
    push32(0x4458574e);
    indirectCall(cs, esi); // 0000:404d2d
    ecx = memoryAGet32(ds, 0x40fa40);
    memoryASet32(ds, 0x40e038, 0x00000001);
    edx = memoryAGet32(ds, ecx);
    push32(edx);
    indirectCall(cs, edi); // 0000:404d42
    esp += 0x00000018;
loc_404d47: // 0000:404d47
    push32(0x0040e058);
    sub_4064b0();
    push32(0x0040e068);
    memoryASet32(ds, 0x40e040, eax);
    sub_4064b0();
    ecx = memoryAGet32(ds, 0x40fa64);
    esp += 0x00000008;
    edi = pop32();
    memoryASet32(ds, 0x40e044, eax);
    esi = pop32();
    if (!ecx)
        goto loc_404d8b;
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    push32(eax);
    push32(ecx);
    alleg40::adjust_sample(stack32<SAMPLE>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));();
    esp += 0x00000014;
loc_404d8b: // 0000:404d8b
    esp = ebp;
    ebp = pop32();
    esp += 4;
}
void sub_404d90() // 0000:404d90 +long
{
    esp -= 4;
    sub_401600();
    if (eax)
        goto loc_404db3;
    push32(0x0040eb94);
    alleg40::allegro_message(stack32<const char>(0));();
    esp += 0x00000004;
    alleg40::allegro_exit();();
    eax = 0x00000001;
    esp += 4; return;
loc_404db3: // 0000:404db3
    eax = memoryAGet32(ds, 0x40d0e8);
    push32(eax);
    alleg40::set_palette(stack32<const PALETTE>(0));();
    ecx = memoryAGet32(ds, 0x40fa40);
    push32(0xffffffff);
    push32(0x0000001e);
    push32(0x00000280);
    edx = memoryAGet32(ds, ecx + 0x140);
    push32(0x0040e658);
    push32(edx);
    push32(0x00423380);
    sub_406880();
    eax = memoryAGet32(ds, 0x40fa40);
    push32(0x00423348);
    ecx = memoryAGet32(ds, eax + 0x130);
    memoryASet32(ds, 0x423340, ecx);
    edx = memoryAGet32(ds, eax + 0x2d0);
    memoryASet32(ds, 0x423368, edx);
    memoryASet32(ds, 0x42336c, 0x00000000);
    sub_401000();
    push32(0x0042bde0);
    sub_401000();
    eax = memoryAGet32(ds, 0x42bbc4);
    esp += 0x00000024;
    if (!eax)
        goto loc_404e35;
    memoryASet32(ds, 0x42bde0, 0xffffffff);
loc_404e35: // 0000:404e35
    push32(ebx);
    push32(ebp);
    push32(esi);
    push32(edi);
    push32(0x00000000);
    push32(0x00423340);
    push32(0x0040e408);
    sub_405480();
    eax = memoryAGet32(ds, 0x40fa64);
    ebp = memoryAGet32(ds, 0x40d174);
    esp += 0x0000000c;
    if (!eax)
        goto loc_404e75;
    ecx = memoryAGet32(ds, 0x40e044);
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    push32(ecx);
    push32(eax);
    indirectCall(cs, ebp); // 0000:404e70
    esp += 0x00000014;
loc_404e75: // 0000:404e75
    esi = memoryAGet32(ds, 0x40d0d0);
    edi = memoryAGet32(ds, 0x40d0b0);
    ebx = memoryAGet32(ds, 0x40d0c8);
loc_404e87: // 0000:404e87
    sub_404990();
    edx = memoryAGet32(ds, 0x40fa34);
    push32(0x0000010e);
    push32(0x00000032);
    push32(0x00423340);
    push32(0x0040e408);
    push32(edx);
    sub_4053a0();
    eax = memoryAGet32(ds, 0x40fa34);
    push32(eax);
    sub_402250();
    ecx = memoryAGet32(ds, 0x40fa40);
    push32(0x00000008);
    edx = memoryAGet32(ds, ecx);
    push32(edx);
    indirectCall(cs, esi); // 0000:404ebf
    eax = memoryAGet32(ds, 0x40fa34);
    push32(0x0000010e);
    push32(0x00000032);
    push32(0x00404990);
    push32(eax);
    push32(0x0042bde0);
    push32(0x00423340);
    push32(0x0040e408);
    sub_405680();
    esp += 0x0000003c;
    if (eax != 0x00000065)
        goto loc_404f3a;
    push32(0x00000008);
    indirectCall(cs, edi); // 0000:404ef1
    ecx = memoryAGet32(ds, 0x40fa64);
    push32(ecx);
    indirectCall(cs, ebx); // 0000:404efa
    esp += 0x00000008;
    sub_403420();
    sub_4034a0();
    eax = memoryAGet32(ds, 0x40fa64);
    if (!eax)
        goto loc_404f2b;
    edx = memoryAGet32(ds, 0x40e044);
    push32(0x00000001);
    push32(0x000003e8);
    push32(0x00000080);
    push32(edx);
    push32(eax);
    indirectCall(cs, ebp); // 0000:404f26
    esp += 0x00000014;
loc_404f2b: // 0000:404f2b
    memoryASet32(ds, 0x42336c, 0x00000000);
    goto loc_404e87;
loc_404f3a: // 0000:404f3a
    if (eax != 0x00000068)
        goto loc_404f5a;
    push32(0x00000008);
    indirectCall(cs, edi); // 0000:404f41
    esp += 0x00000004;
    sub_404810();
    memoryASet32(ds, 0x42336c, 0x00000001);
    goto loc_404e87;
loc_404f5a: // 0000:404f5a
    if (eax != 0x0000006b)
        goto loc_404e87;
    push32(0x00000010);
    indirectCall(cs, edi); // 0000:404f65
    sub_404650();
    eax = memoryAGet32(ds, 0x40fa64);
    push32(eax);
    indirectCall(cs, ebx); // 0000:404f72
    esp += 0x00000008;
    sub_401c60();
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    eax = 0;
    ebx = pop32();
    esp += 4;
}
void sub_404f90() // 0000:404f90 +long +stackDrop16
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x10);
    ecx = memoryAGet32(ds, esp + 0xc);
    edx = memoryAGet32(ds, esp + 0x8);
    push32(eax);
    eax = memoryAGet32(ds, esp + 0x8);
    push32(ecx);
    push32(edx);
    push32(eax);
    push32(0x00404d90);
    eax = alleg40::_WinMain(stack32<void>(0), stack32<void>(1), stack32<char>(2), stack32<int>(3));();
    esp += 0x00000014;
    esp += 20;
}
void sub_404fc0() // 0000:404fc0 +long
{
    esp -= 4;
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x8);
    ecx = 0x00000020;
    edx = 0;
    eax = edi + 16;
loc_404fcf: // 0000:404fcf
    memoryASet32(ds, eax - 16, 0xffffffff);
    memoryASet32(ds, eax - 4, edx);
    memoryASet32(ds, eax, edx);
    eax += 0x00000018;
    ecx--;
    if (ecx)
        goto loc_404fcf;
    memoryASet32(ds, edi + 0x300, edx);
    edi = pop32();
    esp += 4;
}
void sub_404ff0() // 0000:404ff0 +long
{
    esp -= 4;
    esp -= 0x00000008;
    edx = 0x0000001f;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x10);
    push32(esi);
    push32(edi);
    edi = ebx;
loc_405001: // 0000:405001
    eax = edi + 24;
    ecx = 0x00000006;
    esi = eax;
    edx--;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    edi = eax;
    if (edx)
        goto loc_405001;
    ecx = memoryAGet32(ds, ebx + 0x2f4);
    eax = 0x10624dd3;
    imul32(ecx);
    edx = sar32(edx, 0x05);
    eax = edx;
    eax >>= 31;
    edx += eax;
    edx &= 0x80000003;
    if ((int32_t)edx >= 0)
        goto loc_405036;
    edx--;
    edx |= 0xfffffffc;
    edx++;
loc_405036: // 0000:405036
    eax = ecx;
    memoryASet32(ds, ebx + 0x2fc, edx);
    edx = (int32_t)eax < 0 ? -1 : 0;
    esi = 0x000000fa;
    edi = 0;
    idiv32(esi);
    if (edx)
        goto loc_40506e;
    ecx++;
    memoryASet32(ds, ebx + 0x2e8, edi);
    memoryASet32(ds, ebx + 0x2f4, ecx);
    memoryASet32(ds, ebx + 0x2ec, edi);
    memoryASet32(ds, ebx + 0x2f0, 0x00000028);
    goto loc_40512e;
loc_40506e: // 0000:40506e
    eax = ecx;
    esi = 0x00000005;
    edx = (int32_t)eax < 0 ? -1 : 0;
    idiv32(esi);
    if (edx)
        goto loc_40511d;
    ecx++;
    eax = 0x66666667;
    imul32(ecx);
    edx = sar32(edx, 0x00000001);
    memoryASet32(ds, ebx + 0x2f4, ecx);
    ecx = edx;
    ecx >>= 31;
    edx += ecx;
    eax = 0x0000012c;
    eax -= edx;
    memoryASet32(ds, ebx + 0x2e8, edi);
    memoryASet32(ds, esp + 0x18, eax);
    fild32(memoryAGet32(ds, esp + 0x18));
    fmul64(memoryAGet64(ds, 0x40d2d8));
    fmul64(memoryAGet64(ds, 0x40d2d0));
    fld64(memoryAGet64(ds, 0x40d1b8));
    fcomp80(st(1));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_4050db;
    st(0) = fstp80();
    memoryASet32(ds, esp + 0xc, 0x00000000);
    memoryASet32(ds, esp + 0x10, 0x3ff00000);
    goto loc_4050df;
loc_4050db: // 0000:4050db
    memoryASet64(ds, esp + 0xc, fstp64());
loc_4050df: // 0000:4050df
    sub_406be3();
    fld64(memoryAGet64(ds, esp + 0xc));
    esi = eax;
    sub_406e04();
    ecx = eax;
    eax = esi;
    edx = (int32_t)eax < 0 ? -1 : 0;
    idiv32(ecx);
    esi = edx;
    esi += 0x00000006;
    sub_406be3();
    ecx = 0x0000001e;
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx -= esi;
    idiv32(ecx);
    eax = edx + 5;
    memoryASet32(ds, ebx + 0x2ec, eax);
    eax += esi;
    memoryASet32(ds, ebx + 0x2f0, eax);
    goto loc_40512e;
loc_40511d: // 0000:40511d
    ecx++;
    memoryASet32(ds, ebx + 0x2e8, 0xffffffff);
    memoryASet32(ds, ebx + 0x2f4, ecx);
loc_40512e: // 0000:40512e
    ecx = memoryAGet32(ds, ebx + 0x2f4);
    esi = 0x00000032;
    eax = ecx - 1;
    edx = (int32_t)eax < 0 ? -1 : 0;
    idiv32(esi);
    if (edx)
        goto loc_405160;
    eax = 0x66666667;
    edi = pop32();
    imul32(ecx);
    edx = sar32(edx, 0x00000001);
    eax = edx;
    esi = pop32();
    eax >>= 31;
    edx += eax;
    memoryASet32(ds, ebx + 0x2f8, edx);
    ebx = pop32();
    esp += 0x00000008;
    esp += 4; return;
loc_405160: // 0000:405160
    memoryASet32(ds, ebx + 0x2f8, edi);
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp += 0x00000008;
    esp += 4;
}
void sub_405170() // 0000:405170 +long
{
    esp -= 4;
    push32(ebx);
    push32(esi);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x18);
    eax = 0x0000001d;
    ecx = edi + 1;
    ecx = sar32(ecx, 0x04);
    eax -= ecx;
    if ((int32_t)eax < 0)
        goto loc_4051d2;
    if ((int32_t)eax > (int32_t)0x0000001f)
        goto loc_4051d2;
    esi = memoryAGet32(ds, esp + 0x10);
    edx = eax + (eax * 2);
    ecx = memoryAGet32(ds, esi + edx * 8);
    edx = esi + (edx * 8);
    if (ecx)
        goto loc_4051d2;
    ecx = memoryAGet32(ds, esp + 0x14);
    ebx = memoryAGet32(ds, edx + 0x4);
    ecx = sar32(ecx, 0x04);
    if ((int32_t)ecx < (int32_t)ebx)
        goto loc_4051d2;
    if ((int32_t)ecx > (int32_t)memoryAGet32(ds, edx + 0x8))
        goto loc_4051d2;
    ecx = memoryAGet32(ds, esi + 0x300);
    ecx &= 0x8000000f;
    if ((int32_t)ecx >= 0)
        goto loc_4051c2;
    ecx--;
    ecx |= 0xfffffff0;
    ecx++;
loc_4051c2: // 0000:4051c2
    eax += 0x00000254;
    eax <<= 4;
    eax -= ecx;
    eax += edi;
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp += 4; return;
loc_4051d2: // 0000:4051d2
    edi = pop32();
    esi = pop32();
    eax = 0;
    ebx = pop32();
    esp += 4;
}
void sub_4051e0() // 0000:4051e0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = eax + 1;
    eax = 0x0000001d;
    ecx = sar32(ecx, 0x04);
    eax -= ecx;
    if ((int32_t)eax < 0)
        goto loc_405204;
    if ((int32_t)eax > (int32_t)0x0000001f)
        goto loc_405204;
    edx = eax + (eax * 2);
    eax = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, eax + edx * 8 + 0xc);
    esp += 4; return;
loc_405204: // 0000:405204
    eax = 0;
    esp += 4;
}
void sub_405210() // 0000:405210 +long
{
    esp -= 4;
    esp -= 0x00000020;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x28);
    push32(ebp);
    push32(esi);
    eax = memoryAGet32(ds, ebx + 0x8c);
    push32(edi);
    if (!(al & 0x02))
        goto loc_4052e5;
    ecx = memoryAGet32(ds, ebx + 0x90);
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x3c);
    push32(0x0040ebd8);
    esi = memoryAGet32(ds, ecx + 0x4);
    eax = memoryAGet32(ds, ecx);
    edi = memoryAGet32(ds, ecx + 0xc);
    eax -= esi;
    edx = (int32_t)eax < 0 ? -1 : 0;
    idiv32(edi);
    push32(ebx);
    ebp = eax;
    eax = memoryAGet32(ds, ecx + 0x8);
    eax -= esi;
    edx = (int32_t)eax < 0 ? -1 : 0;
    idiv32(edi);
    esi = eax;
    memoryASet32(ds, esp + 0x40, esi);
    sub_406e2b();
    esp += 0x0000000c;
    edx = 0;
    if ((int32_t)ebp <= 0)
        goto loc_4052a4;
    memoryASet32(ds, esp + 0x38, ebp);
    edx = ebp;
loc_40526b: // 0000:40526b
    edi = 0x0040ebd4;
    ecx |= 0xffffffff;
    eax = 0;
    for (flags.zero = 0; ecx != 0 && !flags.zero; --ecx) scasb_inv<ES_EDI>(al);
    ecx = ~ecx;
    edi -= ecx;
    esi = edi;
    ebp = ecx;
    edi = ebx;
    ecx |= 0xffffffff;
    for (flags.zero = 0; ecx != 0 && !flags.zero; --ecx) scasb_inv<ES_EDI>(al);
    ecx = ebp;
    edi--;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    eax = memoryAGet32(ds, esp + 0x38);
    ecx = ebp;
    ecx &= 0x00000003;
    eax--;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    memoryASet32(ds, esp + 0x38, eax);
    if (eax)
        goto loc_40526b;
    esi = memoryAGet32(ds, esp + 0x34);
loc_4052a4: // 0000:4052a4
    if ((int32_t)edx >= (int32_t)esi)
        goto loc_405390;
    esi -= edx;
    edx = esi;
loc_4052b0: // 0000:4052b0
    edi = 0x0040ebd0;
    ecx |= 0xffffffff;
    eax = 0;
    for (flags.zero = 0; ecx != 0 && !flags.zero; --ecx) scasb_inv<ES_EDI>(al);
    ecx = ~ecx;
    edi -= ecx;
    esi = edi;
    ebp = ecx;
    edi = ebx;
    ecx |= 0xffffffff;
    for (flags.zero = 0; ecx != 0 && !flags.zero; --ecx) scasb_inv<ES_EDI>(al);
    ecx = ebp;
    edi--;
    ecx >>= 2;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    ecx = ebp;
    ecx &= 0x00000003;
    edx--;
    for (; ecx != 0; --ecx) movsb<ES_EDI, DS_ESI>();
    if (edx)
        goto loc_4052b0;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000020;
    esp += 4; return;
loc_4052e5: // 0000:4052e5
    if (!(al & 0x08))
        goto loc_405311;
    eax = memoryAGet32(ds, ebx + 0x90);
    ecx = memoryAGet32(ds, eax);
    edx = memoryAGet32(ds, eax + ecx * 4 + 0x8);
    eax = memoryAGet32(ds, esp + 0x38);
    push32(edx);
    push32(ebx);
    push32(0x0040ebc8);
    push32(eax);
    sub_406e2b();
    esp += 0x00000010;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000020;
    esp += 4; return;
loc_405311: // 0000:405311
    if (!(al & 0x04))
        goto loc_405346;
    ecx = memoryAGet32(ds, ebx + 0x90);
    eax = 0x0040ebc4;
    if (memoryAGet32(ds, ecx))
        goto loc_40532a;
    eax = 0x0040ebc0;
loc_40532a: // 0000:40532a
    edx = memoryAGet32(ds, esp + 0x38);
    push32(eax);
    push32(ebx);
    push32(0x0040ebc8);
    push32(edx);
    sub_406e2b();
    esp += 0x00000010;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000020;
    esp += 4; return;
loc_405346: // 0000:405346
    if (!(al & 0x10))
        goto loc_40537d;
    ecx = memoryAGet32(ds, ebx + 0x90);
    eax = esp + 16;
    push32(eax);
    edx = memoryAGet32(ds, ecx);
    push32(edx);
    sub_4059e0();
    ecx = memoryAGet32(ds, esp + 0x40);
    eax = esp + 24;
    push32(eax);
    push32(ebx);
    push32(0x0040ebb4);
    push32(ecx);
    sub_406e2b();
    esp += 0x00000018;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000020;
    esp += 4; return;
loc_40537d: // 0000:40537d
    edx = memoryAGet32(ds, esp + 0x38);
    push32(ebx);
    push32(0x0040e034);
    push32(edx);
    sub_406e2b();
    esp += 0x0000000c;
loc_405390: // 0000:405390
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000020;
    esp += 4;
}
void sub_4053a0() // 0000:4053a0 +long
{
    esp -= 4;
    esp -= 0x00000108;
    ecx = memoryAGet32(ds, esp + 0x110);
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x118);
    push32(ebp);
    ebp = memoryAGet32(ds, esp + 0x120);
    push32(esi);
    eax = memoryAGet32(ds, ebx + 0x4);
    esi = memoryAGet32(ds, esp + 0x128);
    eax -= 0x0000000d;
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x11c);
    esi -= eax;
    memoryASet32(ds, esp + 0x14, eax);
    ecx += 0xfffffff8;
    goto loc_4053e6;
loc_4053de: // 0000:4053de
    eax = memoryAGet32(ds, esp + 0x14);
    ecx = memoryAGet32(ds, esp + 0x10);
loc_4053e6: // 0000:4053e6
    ecx += 0x00000094;
    edx = esp + 24;
    memoryASet32(ds, esp + 0x10, ecx);
    ecx += 0xffffff74;
    push32(edx);
    push32(ecx);
    esi += eax;
    sub_405210();
    eax = memoryAGet32(ds, esp + 0x18);
    esp += 0x00000008;
    if (!(memoryAGet(ds, eax) & 0x01))
        goto loc_40544c;
    eax = memoryAGet32(ds, ebx + 0x28);
    ecx = ebp;
    edx = memoryAGet32(ds, eax);
    ecx -= edx;
    edx = memoryAGet32(ds, eax + 0x1c);
    ebp = memoryAGet32(ds, edx);
    edx = memoryAGet32(ds, edi + 0x1c);
    flags.zero = ebp == 0x00000008;
    ebp = esi - 8;
    push32(ebp);
    push32(ecx);
    push32(eax);
    push32(edi);
    if (!flags.zero)
        goto loc_405431;
    indirectCall(cs, memoryAGet32(ds, edx + 0x44)); // 0000:40542c
    goto loc_405434;
loc_405431: // 0000:405431
    indirectCall(cs, memoryAGet32(ds, edx + 0x40)); // 0000:405431
loc_405434: // 0000:405434
    ebp = memoryAGet32(ds, esp + 0x138);
    ecx = memoryAGet32(ds, ebx);
    esp += 0x00000010;
    eax = esp + 24;
    push32(0xffffffff);
    push32(esi);
    push32(ebp);
    push32(eax);
    push32(ecx);
    goto loc_405458;
loc_40544c: // 0000:40544c
    eax = memoryAGet32(ds, ebx);
    push32(0xffffffff);
    push32(esi);
    edx = esp + 32;
    push32(ebp);
    push32(edx);
    push32(eax);
loc_405458: // 0000:405458
    push32(edi);
    alleg40::textout(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<const char>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));();
    ecx = memoryAGet32(ds, esp + 0x28);
    esp += 0x00000018;
    if (!(memoryAGet(ds, ecx) & 0x20))
        goto loc_4053de;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000108;
    esp += 4;
}
void sub_405480() // 0000:405480 +long
{
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0x4);
    push32(esi);
    eax = ecx - 8;
loc_405488: // 0000:405488
    esi = memoryAGet32(ds, eax + 0x94);
    eax += 0x00000094;
    esi &= 0xfffffffe;
    memoryASet32(ds, eax, esi);
    dl = memoryAGet(ds, eax);
    if (!(dl & 0x20))
        goto loc_405488;
    eax = memoryAGet32(ds, esp + 0x10);
    edx = eax + (eax * 8);
    eax = eax + (edx * 4);
    esi = memoryAGet32(ds, ecx + eax * 4 + 0x8c);
    eax = (ecx + (eax * 4)) + 140;
    esi |= 0x00000001;
    memoryASet32(ds, eax, esi);
    esi = memoryAGet32(ds, esp + 0xc);
    ecx = memoryAGet32(ds, esi);
    push32(ecx);
    eax = alleg40::text_height(stack32<const FONT>(0));();
    esp += 0x00000004;
    memoryASet32(ds, esi + 0x4, eax);
    esi = pop32();
    esp += 4;
}
void sub_4054e0() // 0000:4054e0 +long
{
    esp -= 4;
    push32(ecx);
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x10);
    push32(ebp);
    push32(esi);
    esi = 0;
    push32(edi);
    memoryASet32(ds, esp + 0x10, esi);
    ebp |= 0xffffffff;
    ecx = ebx - 8;
loc_4054f5: // 0000:4054f5
    eax = memoryAGet32(ds, ecx + 0x94);
    ecx += 0x00000094;
    ebp++;
    if (!(al & 0x01))
        goto loc_405508;
    esi = ebp;
loc_405508: // 0000:405508
    if (!(al & 0x20))
        goto loc_4054f5;
    eax = memoryAGet32(ds, esp + 0x2c);
    ecx = memoryAGet32(ds, esp + 0x28);
    edx = memoryAGet32(ds, esp + 0x20);
    push32(eax);
    eax = memoryAGet32(ds, esp + 0x1c);
    push32(ecx);
    push32(edx);
    push32(ebx);
    push32(eax);
    sub_4053a0();
    eax = memoryAGet32(ds, esp + 0x38);
    esp += 0x00000014;
    if (!eax)
        goto loc_405654;
    push32(eax);
    edi = esi;
    sub_4011c0();
    esp += 0x00000004;
    if (eax)
        goto loc_405558;
    ecx = memoryAGet32(ds, esp + 0x20);
    ecx += 0x00000008;
    push32(ecx);
    sub_4011c0();
    esp += 0x00000004;
    if (!eax)
        goto loc_40555d;
loc_405558: // 0000:405558
    if (!esi)
        goto loc_40555d;
    esi--;
loc_40555d: // 0000:40555d
    edx = memoryAGet32(ds, esp + 0x24);
    push32(edx);
    sub_4011d0();
    esp += 0x00000004;
    if (eax)
        goto loc_405582;
    eax = memoryAGet32(ds, esp + 0x20);
    eax += 0x00000008;
    push32(eax);
    sub_4011d0();
    esp += 0x00000004;
    if (!eax)
        goto loc_405587;
loc_405582: // 0000:405582
    if ((int32_t)esi >= (int32_t)ebp)
        goto loc_405587;
    esi++;
loc_405587: // 0000:405587
    if (esi == edi)
        goto loc_4055c2;
    ecx = edi + (edi * 8);
    edx = edi + (ecx * 4);
    eax = (ebx + (edx * 4)) + 140;
    edx = memoryAGet32(ds, ebx + edx * 4 + 0x8c);
    edx &= 0xfffffffe;
    memoryASet32(ds, eax, edx);
    eax = esi + (esi * 8);
    ecx = esi + (eax * 4);
    eax = (ebx + (ecx * 4)) + 140;
    ecx = memoryAGet32(ds, ebx + ecx * 4 + 0x8c);
    ecx |= 0x00000001;
    memoryASet32(ds, eax, ecx);
    sub_404950();
loc_4055c2: // 0000:4055c2
    ebp = memoryAGet32(ds, esp + 0x24);
    push32(ebp);
    sub_401200();
    edi = memoryAGet32(ds, esp + 0x24);
    esp += 0x00000004;
    if (eax)
        goto loc_4055e7;
    edx = edi + 8;
    push32(edx);
    sub_401210();
    esp += 0x00000004;
    if (!eax)
        goto loc_4055f8;
loc_4055e7: // 0000:4055e7
    eax = esi + (esi * 8);
    ecx = esi + (eax * 4);
    edx = memoryAGet32(ds, ebx + ecx * 4 + 0x80);
    memoryASet32(ds, esp + 0x10, edx);
loc_4055f8: // 0000:4055f8
    push32(ebp);
    sub_4011e0();
    esp += 0x00000004;
    if (eax)
        goto loc_405615;
    eax = edi + 8;
    push32(eax);
    sub_4011e0();
    esp += 0x00000004;
    if (!eax)
        goto loc_405626;
loc_405615: // 0000:405615
    ecx = esi + (esi * 8);
    edx = esi + (ecx * 4);
    eax = memoryAGet32(ds, ebx + edx * 4 + 0x84);
    memoryASet32(ds, esp + 0x10, eax);
loc_405626: // 0000:405626
    push32(ebp);
    sub_4011f0();
    esp += 0x00000004;
    if (eax)
        goto loc_405643;
    edi += 0x00000008;
    push32(edi);
    sub_4011f0();
    esp += 0x00000004;
    if (!eax)
        goto loc_405654;
loc_405643: // 0000:405643
    ecx = esi + (esi * 8);
    edx = esi + (ecx * 4);
    eax = memoryAGet32(ds, ebx + edx * 4 + 0x88);
    memoryASet32(ds, esp + 0x10, eax);
loc_405654: // 0000:405654
    ecx = esi + (esi * 8);
    edi = pop32();
    edx = esi + (ecx * 4);
    ecx = memoryAGet32(ds, esp + 0x2c);
    esi = pop32();
    ebp = pop32();
    eax = memoryAGet32(ds, ebx + edx * 4 + 0x90);
    ebx = pop32();
    memoryASet32(ds, ecx, eax);
    eax = memoryAGet32(ds, esp);
    ecx = pop32();
    esp += 4;
}
void sub_405680() // 0000:405680 +long
{
    esp -= 4;
    esp -= 0x00000084;
    ecx = memoryAGet32(ds, esp + 0x88);
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x90);
    push32(ebp);
    push32(esi);
    push32(edi);
    eax = memoryAGet32(ds, ebx + 0x2c);
    edi = 0;
    push32(eax);
    push32(ebx);
    push32(ecx);
    memoryASet32(ds, esp + 0x1c, edi);
    sub_405480();
    ebp = memoryAGet32(ds, esp + 0xac);
    esp += 0x0000000c;
loc_4056b3: // 0000:4056b3
    memoryASet32(ds, 0x42bbc0, 0x00000000);
    eax = memoryAGet32(ds, esp + 0xa8);
    if (!eax)
        goto loc_4056cc;
    indirectCall(cs, eax); // 0000:4056c8
    goto loc_4056dd;
loc_4056cc: // 0000:4056cc
    edx = memoryAGet32(ds, esp + 0xa4);
    push32(edx);
    alleg40::clear_bitmap(stack32<BITMAP>(0));();
    esp += 0x00000004;
loc_4056dd: // 0000:4056dd
    ecx = memoryAGet32(ds, esp + 0xb0);
    edx = memoryAGet32(ds, esp + 0xac);
    flags.carry = edi != 0;
    edi = -edi;
    eax = esp + 16;
    edi = -flags.carry;
    push32(eax);
    eax = memoryAGet32(ds, esp + 0x9c);
    push32(ecx);
    ecx = memoryAGet32(ds, esp + 0xac);
    edi &= ebp;
    push32(edx);
    push32(edi);
    push32(ebx);
    push32(eax);
    push32(ecx);
    sub_4054e0();
    edx = memoryAGet32(ds, esp + 0xc0);
    esi = eax;
    push32(edx);
    sub_402250();
    push32(ebp);
    sub_401220();
    esp += 0x00000024;
    if (eax)
        goto loc_405740;
    eax = ebx + 8;
    push32(eax);
    sub_401220();
    esp += 0x00000004;
    if (eax)
        goto loc_405740;
    edi |= 0xffffffff;
    goto loc_405742;
loc_405740: // 0000:405740
    edi = 0;
loc_405742: // 0000:405742
    push32(ebp);
    sub_401060();
    ecx = ebx + 8;
    push32(ecx);
    sub_401060();
    esp += 0x00000008;
    if (!esi)
        goto loc_40575d;
    sub_404970();
loc_40575d: // 0000:40575d
    if (esi > 0x00000072)
        goto loc_40588a;
    edx = 0;
    dl = memoryAGet(ds, esi + 0x405960);
    switch (edx)
    {
        case 0: goto loc_4058ac;
        case 1: goto loc_4058d8;
        case 2: goto loc_405775;
        case 3: goto loc_4058e8;
        case 4: goto loc_4058f8;
        case 5: goto loc_405908;
        case 6: goto loc_405918;
        case 7: goto loc_4057b0;
        case 8: goto loc_4057cb;
        case 9: goto loc_4057fe;
        case 10: goto loc_4057e6;
        case 11: goto loc_405816;
        case 12: goto loc_40582a;
        case 13: goto loc_40588a;
        default:
            stop("ind 0000:40576e");
    }
loc_405775: // 0000:405775
    eax = memoryAGet32(ds, esp + 0xb0);
    ecx = memoryAGet32(ds, esp + 0xac);
    edx = memoryAGet32(ds, esp + 0xa8);
    push32(eax);
    eax = memoryAGet32(ds, esp + 0xa8);
    push32(ecx);
    ecx = memoryAGet32(ds, esp + 0x18);
    push32(edx);
    push32(eax);
    push32(ebp);
    push32(ebx);
    push32(ecx);
    memoryASet32(ds, ebx + 0x2c, 0x00000000);
    sub_405680();
    esp += 0x0000001c;
    goto loc_4058ac;
loc_4057b0: // 0000:4057b0
    eax = memoryAGet32(ds, esp + 0x10);
    edx = memoryAGet32(ds, eax + 0xc);
    ecx = memoryAGet32(ds, eax);
    ecx += edx;
    edx = memoryAGet32(ds, eax + 0x8);
    if ((int32_t)ecx < (int32_t)edx)
        goto loc_4057c4;
    ecx = edx;
loc_4057c4: // 0000:4057c4
    memoryASet32(ds, eax, ecx);
    goto loc_4058ac;
loc_4057cb: // 0000:4057cb
    ecx = memoryAGet32(ds, esp + 0x10);
    eax = memoryAGet32(ds, ecx);
    edx = memoryAGet32(ds, ecx + 0xc);
    eax -= edx;
    edx = memoryAGet32(ds, ecx + 0x4);
    if ((int32_t)eax > (int32_t)edx)
        goto loc_4057df;
    eax = edx;
loc_4057df: // 0000:4057df
    memoryASet32(ds, ecx, eax);
    goto loc_4058ac;
loc_4057e6: // 0000:4057e6
    edx = memoryAGet32(ds, esp + 0x10);
    eax = memoryAGet32(ds, edx + 0x4);
    ecx = memoryAGet32(ds, edx);
    eax--;
    ecx++;
    if ((int32_t)ecx >= (int32_t)eax)
        goto loc_4057f7;
    eax = ecx;
loc_4057f7: // 0000:4057f7
    memoryASet32(ds, edx, eax);
    goto loc_4058ac;
loc_4057fe: // 0000:4057fe
    ecx = memoryAGet32(ds, esp + 0x10);
    edx = 0;
    eax = memoryAGet32(ds, ecx);
    eax--;
    dl = (int32_t)eax <= 0;
    edx--;
    eax &= edx;
    memoryASet32(ds, ecx, eax);
    goto loc_4058ac;
loc_405816: // 0000:405816
    eax = memoryAGet32(ds, esp + 0x10);
    ecx = memoryAGet32(ds, eax);
    flags.carry = ecx != 0;
    ecx = -ecx;
    ecx = -flags.carry;
    ecx = -ecx;
    ecx--;
    memoryASet32(ds, eax, ecx);
    goto loc_4058ac;
loc_40582a: // 0000:40582a
    esi = 0;
    eax = 0;
loc_40582e: // 0000:40582e
    edx = memoryAGet32(ds, 0x40d1a4);
    memoryASet(ds, edx + eax, 0x00);
    eax++;
    if ((int32_t)eax < (int32_t)0x00000080)
        goto loc_40582e;
loc_405840: // 0000:405840
    ecx = memoryAGet32(ds, 0x40d1a4);
    eax = 0;
loc_405848: // 0000:405848
    if (!memoryAGet(ds, ecx + eax))
        goto loc_405850;
    esi = eax;
loc_405850: // 0000:405850
    eax++;
    if ((int32_t)eax < (int32_t)0x00000080)
        goto loc_405848;
    push32(esi);
    push32(ebp);
    sub_401170();
    esp += 0x00000008;
    if (!eax)
        goto loc_40586a;
    esi = 0;
    goto loc_405840;
loc_40586a: // 0000:40586a
    if (!esi)
        goto loc_405840;
    eax = 0;
loc_405870: // 0000:405870
    ecx = memoryAGet32(ds, 0x40d1a4);
    memoryASet(ds, ecx + eax, 0x00);
    eax++;
    if ((int32_t)eax < (int32_t)0x00000080)
        goto loc_405870;
    edx = memoryAGet32(ds, esp + 0x10);
    memoryASet32(ds, edx, esi);
    goto loc_4058ac;
loc_40588a: // 0000:40588a
    push32(esi);
    eax = esp + 24;
    push32(0x0040ebec);
    push32(eax);
    sub_406e2b();
    ecx = esp + 32;
    push32(ecx);
    push32(0x0040ebe0);
    sub_401510();
    esp += 0x00000014;
loc_4058ac: // 0000:4058ac
    edx = memoryAGet32(ds, 0x40d1a4);
    al = memoryAGet(ds, edx + 0x40);
    if (al)
        goto loc_4056b3;
    eax = memoryAGet32(ds, 0x42bbc0);
    if (eax)
        goto loc_4056b3;
loc_4058ca: // 0000:4058ca
    eax = memoryAGet32(ds, 0x42bbc0);
    if (!eax)
        goto loc_4058ca;
    goto loc_4056b3;
loc_4058d8: // 0000:4058d8
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    eax = 0x00000065;
    ebx = pop32();
    esp += 0x00000084;
    esp += 4; return;
loc_4058e8: // 0000:4058e8
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    eax = 0x00000068;
    ebx = pop32();
    esp += 0x00000084;
    esp += 4; return;
loc_4058f8: // 0000:4058f8
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    eax = 0x00000069;
    ebx = pop32();
    esp += 0x00000084;
    esp += 4; return;
loc_405908: // 0000:405908
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    eax = 0x0000006b;
    ebx = pop32();
    esp += 0x00000084;
    esp += 4; return;
loc_405918: // 0000:405918
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    eax = 0x0000006c;
    ebx = pop32();
    esp += 0x00000084;
    esp += 4;
}
void sub_4059e0() // 0000:4059e0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    if (eax != 0x00000001)
        goto loc_4059f8;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40eeac);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_4059f8: // 0000:4059f8
    if (eax != 0x00000002)
        goto loc_405a0b;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40eea8);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405a0b: // 0000:405a0b
    if (eax != 0x00000003)
        goto loc_405a1f;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40eea4);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405a1f: // 0000:405a1f
    if (eax != 0x00000004)
        goto loc_405a33;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40eea0);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405a33: // 0000:405a33
    if (eax != 0x00000005)
        goto loc_405a46;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee9c);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405a46: // 0000:405a46
    if (eax != 0x00000006)
        goto loc_405a5a;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee98);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405a5a: // 0000:405a5a
    if (eax != 0x00000007)
        goto loc_405a6e;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ee94);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405a6e: // 0000:405a6e
    if (eax != 0x00000008)
        goto loc_405a81;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee90);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405a81: // 0000:405a81
    if (eax != 0x00000009)
        goto loc_405a95;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee8c);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405a95: // 0000:405a95
    if (eax != 0x0000000a)
        goto loc_405aa9;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ee88);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405aa9: // 0000:405aa9
    if (eax != 0x0000000b)
        goto loc_405abc;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee84);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405abc: // 0000:405abc
    if (eax != 0x0000000c)
        goto loc_405ad0;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee80);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405ad0: // 0000:405ad0
    if (eax != 0x0000000d)
        goto loc_405ae4;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ee7c);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405ae4: // 0000:405ae4
    if (eax != 0x0000000e)
        goto loc_405af7;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee78);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405af7: // 0000:405af7
    if (eax != 0x0000000f)
        goto loc_405b0b;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee74);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405b0b: // 0000:405b0b
    if (eax != 0x00000010)
        goto loc_405b1f;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ee70);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405b1f: // 0000:405b1f
    if (eax != 0x00000011)
        goto loc_405b32;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee6c);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405b32: // 0000:405b32
    if (eax != 0x00000012)
        goto loc_405b46;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee68);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405b46: // 0000:405b46
    if (eax != 0x00000013)
        goto loc_405b5a;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ee64);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405b5a: // 0000:405b5a
    if (eax != 0x00000014)
        goto loc_405b6d;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee60);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405b6d: // 0000:405b6d
    if (eax != 0x00000015)
        goto loc_405b81;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee5c);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405b81: // 0000:405b81
    if (eax != 0x00000016)
        goto loc_405b95;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ee58);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405b95: // 0000:405b95
    if (eax != 0x00000017)
        goto loc_405ba8;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee54);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405ba8: // 0000:405ba8
    if (eax != 0x00000018)
        goto loc_405bbc;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee50);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405bbc: // 0000:405bbc
    if (eax != 0x00000019)
        goto loc_405bd0;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ee4c);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405bd0: // 0000:405bd0
    if (eax != 0x0000001a)
        goto loc_405be3;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee48);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405be3: // 0000:405be3
    if (eax != 0x0000001b)
        goto loc_405bf7;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee44);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405bf7: // 0000:405bf7
    if (eax != 0x0000001c)
        goto loc_405c0b;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ee40);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405c0b: // 0000:405c0b
    if (eax != 0x0000001d)
        goto loc_405c1e;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee3c);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405c1e: // 0000:405c1e
    if (eax != 0x0000001e)
        goto loc_405c32;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee38);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405c32: // 0000:405c32
    if (eax != 0x0000001f)
        goto loc_405c46;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ee34);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405c46: // 0000:405c46
    if (eax != 0x00000020)
        goto loc_405c59;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee30);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405c59: // 0000:405c59
    if (eax != 0x00000021)
        goto loc_405c6d;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee2c);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405c6d: // 0000:405c6d
    if (eax != 0x00000022)
        goto loc_405c81;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ee28);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405c81: // 0000:405c81
    if (eax != 0x00000023)
        goto loc_405c94;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ee24);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405c94: // 0000:405c94
    if (eax != 0x00000024)
        goto loc_405ca8;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ee20);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405ca8: // 0000:405ca8
    if (eax != 0x00000025)
        goto loc_405cc3;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ee18);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ee1c);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_405cc3: // 0000:405cc3
    if (eax != 0x00000026)
        goto loc_405cde;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ee10);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ee14);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_405cde: // 0000:405cde
    if (eax != 0x00000027)
        goto loc_405cf9;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ee08);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ee0c);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_405cf9: // 0000:405cf9
    if (eax != 0x00000028)
        goto loc_405d14;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ee00);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ee04);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_405d14: // 0000:405d14
    if (eax != 0x00000029)
        goto loc_405d2f;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40edf8);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40edfc);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_405d2f: // 0000:405d2f
    if (eax != 0x0000002a)
        goto loc_405d4a;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40edf0);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40edf4);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_405d4a: // 0000:405d4a
    if (eax != 0x0000002b)
        goto loc_405d65;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ede8);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40edec);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_405d65: // 0000:405d65
    if (eax != 0x0000002c)
        goto loc_405d80;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ede0);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ede4);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_405d80: // 0000:405d80
    if (eax != 0x0000002d)
        goto loc_405d9b;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40edd8);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40eddc);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_405d9b: // 0000:405d9b
    if (eax != 0x0000002e)
        goto loc_405db6;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40edd0);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40edd4);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_405db6: // 0000:405db6
    if (eax != 0x0000002f)
        goto loc_405dd3;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40edcc);
    memoryASet16(ds, eax, cx);
    dl = memoryAGet(ds, 0x40edce);
    memoryASet(ds, eax + 0x2, dl);
    esp += 4; return;
loc_405dd3: // 0000:405dd3
    if (eax != 0x00000030)
        goto loc_405df0;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40edc8);
    memoryASet16(ds, eax, cx);
    dl = memoryAGet(ds, 0x40edca);
    memoryASet(ds, eax + 0x2, dl);
    esp += 4; return;
loc_405df0: // 0000:405df0
    if (eax != 0x00000031)
        goto loc_405e0d;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40edc4);
    memoryASet16(ds, eax, cx);
    dl = memoryAGet(ds, 0x40edc6);
    memoryASet(ds, eax + 0x2, dl);
    esp += 4; return;
loc_405e0d: // 0000:405e0d
    if (eax != 0x00000032)
        goto loc_405e2a;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40edc0);
    memoryASet16(ds, eax, cx);
    dl = memoryAGet(ds, 0x40edc2);
    memoryASet(ds, eax + 0x2, dl);
    esp += 4; return;
loc_405e2a: // 0000:405e2a
    if (eax != 0x00000033)
        goto loc_405e47;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40edbc);
    memoryASet16(ds, eax, cx);
    dl = memoryAGet(ds, 0x40edbe);
    memoryASet(ds, eax + 0x2, dl);
    esp += 4; return;
loc_405e47: // 0000:405e47
    if (eax != 0x00000034)
        goto loc_405e64;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40edb8);
    memoryASet16(ds, eax, cx);
    dl = memoryAGet(ds, 0x40edba);
    memoryASet(ds, eax + 0x2, dl);
    esp += 4; return;
loc_405e64: // 0000:405e64
    if (eax != 0x00000035)
        goto loc_405e81;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40edb4);
    memoryASet16(ds, eax, cx);
    dl = memoryAGet(ds, 0x40edb6);
    memoryASet(ds, eax + 0x2, dl);
    esp += 4; return;
loc_405e81: // 0000:405e81
    if (eax != 0x00000036)
        goto loc_405e9e;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40edb0);
    memoryASet16(ds, eax, cx);
    dl = memoryAGet(ds, 0x40edb2);
    memoryASet(ds, eax + 0x2, dl);
    esp += 4; return;
loc_405e9e: // 0000:405e9e
    if (eax != 0x00000037)
        goto loc_405ebb;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40edac);
    memoryASet16(ds, eax, cx);
    dl = memoryAGet(ds, 0x40edae);
    memoryASet(ds, eax + 0x2, dl);
    esp += 4; return;
loc_405ebb: // 0000:405ebb
    if (eax != 0x00000038)
        goto loc_405ecd;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40eda8);
    memoryASet32(ds, eax, ecx);
    esp += 4; return;
loc_405ecd: // 0000:405ecd
    if (eax != 0x00000039)
        goto loc_405ede;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40eda4);
    memoryASet32(ds, edx, eax);
    esp += 4; return;
loc_405ede: // 0000:405ede
    if (eax != 0x0000003a)
        goto loc_405ef0;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40eda0);
    memoryASet32(ds, ecx, edx);
    esp += 4; return;
loc_405ef0: // 0000:405ef0
    if (eax != 0x0000003b)
        goto loc_405f02;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ed9c);
    memoryASet32(ds, eax, ecx);
    esp += 4; return;
loc_405f02: // 0000:405f02
    if (eax != 0x0000003c)
        goto loc_405f15;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ed98);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405f15: // 0000:405f15
    if (eax != 0x0000003d)
        goto loc_405f29;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ed94);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405f29: // 0000:405f29
    if (eax != 0x0000003e)
        goto loc_405f3d;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ed90);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405f3d: // 0000:405f3d
    if (eax != 0x0000003f)
        goto loc_405f61;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40ed84);
    memoryASet32(ds, edx, eax);
    ecx = memoryAGet32(ds, 0x40ed88);
    memoryASet32(ds, edx + 0x4, ecx);
    ax = memoryAGet16(ds, 0x40ed8c);
    memoryASet16(ds, edx + 0x8, ax);
    esp += 4; return;
loc_405f61: // 0000:405f61
    if (eax != 0x00000040)
        goto loc_405f73;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ed80);
    memoryASet32(ds, ecx, edx);
    esp += 4; return;
loc_405f73: // 0000:405f73
    if (eax != 0x00000041)
        goto loc_405f87;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ebd0);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405f87: // 0000:405f87
    if (eax != 0x00000042)
        goto loc_405f9a;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ebd4);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405f9a: // 0000:405f9a
    if (eax != 0x00000043)
        goto loc_405fb6;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ed78);
    memoryASet32(ds, ecx, edx);
    ax = memoryAGet16(ds, 0x40ed7c);
    memoryASet16(ds, ecx + 0x4, ax);
    esp += 4; return;
loc_405fb6: // 0000:405fb6
    if (eax != 0x00000044)
        goto loc_405fca;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ed74);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_405fca: // 0000:405fca
    if (eax != 0x00000045)
        goto loc_405fde;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ed70);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_405fde: // 0000:405fde
    if (eax != 0x00000046)
        goto loc_405ff1;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ed6c);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_405ff1: // 0000:405ff1
    if (eax != 0x00000047)
        goto loc_406005;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ed6c);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_406005: // 0000:406005
    if (eax != 0x00000048)
        goto loc_406019;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ed68);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_406019: // 0000:406019
    if (eax != 0x00000049)
        goto loc_40602c;
    edx = memoryAGet32(ds, esp + 0x8);
    ax = memoryAGet16(ds, 0x40ed64);
    memoryASet16(ds, edx, ax);
    esp += 4; return;
loc_40602c: // 0000:40602c
    if (eax != 0x0000004a)
        goto loc_406040;
    ecx = memoryAGet32(ds, esp + 0x8);
    dx = memoryAGet16(ds, 0x40ed60);
    memoryASet16(ds, ecx, dx);
    esp += 4; return;
loc_406040: // 0000:406040
    if (eax != 0x0000004b)
        goto loc_40605d;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ed58);
    memoryASet32(ds, eax, ecx);
    dx = memoryAGet16(ds, 0x40ed5c);
    memoryASet16(ds, eax + 0x4, dx);
    esp += 4; return;
loc_40605d: // 0000:40605d
    if (eax != 0x0000004c)
        goto loc_406083;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ed50);
    memoryASet32(ds, eax, ecx);
    dx = memoryAGet16(ds, 0x40ed54);
    memoryASet16(ds, eax + 0x4, dx);
    cl = memoryAGet(ds, 0x40ed56);
    memoryASet(ds, eax + 0x6, cl);
    esp += 4; return;
loc_406083: // 0000:406083
    if (eax != 0x0000004d)
        goto loc_4060a7;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40ed48);
    memoryASet32(ds, edx, eax);
    cx = memoryAGet16(ds, 0x40ed4c);
    memoryASet16(ds, edx + 0x4, cx);
    al = memoryAGet(ds, 0x40ed4e);
    memoryASet(ds, edx + 0x6, al);
    esp += 4; return;
loc_4060a7: // 0000:4060a7
    if (eax != 0x0000004e)
        goto loc_4060c1;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ed40);
    memoryASet32(ds, ecx, edx);
    al = memoryAGet(ds, 0x40ed44);
    memoryASet(ds, ecx + 0x4, al);
    esp += 4; return;
loc_4060c1: // 0000:4060c1
    if (eax != 0x0000004f)
        goto loc_4060d3;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ed3c);
    memoryASet32(ds, ecx, edx);
    esp += 4; return;
loc_4060d3: // 0000:4060d3
    if (eax != 0x00000050)
        goto loc_4060ee;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ed34);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ed38);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_4060ee: // 0000:4060ee
    if (eax != 0x00000051)
        goto loc_406114;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ed28);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ed2c);
    memoryASet32(ds, eax + 0x4, edx);
    cx = memoryAGet16(ds, 0x40ed30);
    memoryASet16(ds, eax + 0x8, cx);
    esp += 4; return;
loc_406114: // 0000:406114
    if (eax != 0x00000052)
        goto loc_406141;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40ed1c);
    memoryASet32(ds, edx, eax);
    ecx = memoryAGet32(ds, 0x40ed20);
    memoryASet32(ds, edx + 0x4, ecx);
    ax = memoryAGet16(ds, 0x40ed24);
    memoryASet16(ds, edx + 0x8, ax);
    cl = memoryAGet(ds, 0x40ed26);
    memoryASet(ds, edx + 0xa, cl);
    esp += 4; return;
loc_406141: // 0000:406141
    if (eax != 0x00000053)
        goto loc_406163;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40ed10);
    memoryASet32(ds, edx, eax);
    ecx = memoryAGet32(ds, 0x40ed14);
    memoryASet32(ds, edx + 0x4, ecx);
    eax = memoryAGet32(ds, 0x40ed18);
    memoryASet32(ds, edx + 0x8, eax);
    esp += 4; return;
loc_406163: // 0000:406163
    if (eax != 0x00000054)
        goto loc_406186;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ed04);
    memoryASet32(ds, ecx, edx);
    eax = memoryAGet32(ds, 0x40ed08);
    memoryASet32(ds, ecx + 0x4, eax);
    dl = memoryAGet(ds, 0x40ed0c);
    memoryASet(ds, ecx + 0x8, dl);
    esp += 4; return;
loc_406186: // 0000:406186
    if (eax != 0x00000055)
        goto loc_4061b5;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ecf8);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ecfc);
    memoryASet32(ds, eax + 0x4, edx);
    cx = memoryAGet16(ds, 0x40ed00);
    memoryASet16(ds, eax + 0x8, cx);
    dl = memoryAGet(ds, 0x40ed02);
    memoryASet(ds, eax + 0xa, dl);
    esp += 4; return;
loc_4061b5: // 0000:4061b5
    if (eax != 0x00000056)
        goto loc_4061d0;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ecf0);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ecf4);
    memoryASet32(ds, eax + 0x4, edx);
    esp += 4; return;
loc_4061d0: // 0000:4061d0
    if (eax != 0x00000057)
        goto loc_4061e4;
    eax = memoryAGet32(ds, esp + 0x8);
    cx = memoryAGet16(ds, 0x40ecec);
    memoryASet16(ds, eax, cx);
    esp += 4; return;
loc_4061e4: // 0000:4061e4
    if (eax != 0x00000058)
        goto loc_4061ff;
    eax = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ece4);
    memoryASet32(ds, eax, edx);
    ecx = memoryAGet32(ds, 0x40ece8);
    memoryASet32(ds, eax + 0x4, ecx);
    esp += 4; return;
loc_4061ff: // 0000:4061ff
    if (eax != 0x00000059)
        goto loc_40621a;
    eax = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ecdc);
    memoryASet32(ds, eax, edx);
    ecx = memoryAGet32(ds, 0x40ece0);
    memoryASet32(ds, eax + 0x4, ecx);
    esp += 4; return;
loc_40621a: // 0000:40621a
    if (eax != 0x0000005a)
        goto loc_406245;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40eccc);
    memoryASet32(ds, edx, eax);
    ecx = memoryAGet32(ds, 0x40ecd0);
    memoryASet32(ds, edx + 0x4, ecx);
    eax = memoryAGet32(ds, 0x40ecd4);
    memoryASet32(ds, edx + 0x8, eax);
    cl = memoryAGet(ds, 0x40ecd8);
    memoryASet(ds, edx + 0xc, cl);
    esp += 4; return;
loc_406245: // 0000:406245
    if (eax != 0x0000005b)
        goto loc_406267;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40ecc0);
    memoryASet32(ds, edx, eax);
    ecx = memoryAGet32(ds, 0x40ecc4);
    memoryASet32(ds, edx + 0x4, ecx);
    eax = memoryAGet32(ds, 0x40ecc8);
    memoryASet32(ds, edx + 0x8, eax);
    esp += 4; return;
loc_406267: // 0000:406267
    if (eax != 0x0000005c)
        goto loc_406292;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ecb0);
    memoryASet32(ds, ecx, edx);
    eax = memoryAGet32(ds, 0x40ecb4);
    memoryASet32(ds, ecx + 0x4, eax);
    edx = memoryAGet32(ds, 0x40ecb8);
    memoryASet32(ds, ecx + 0x8, edx);
    al = memoryAGet(ds, 0x40ecbc);
    memoryASet(ds, ecx + 0xc, al);
    esp += 4; return;
loc_406292: // 0000:406292
    if (eax != 0x0000005d)
        goto loc_4062ae;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40eca8);
    memoryASet32(ds, ecx, edx);
    ax = memoryAGet16(ds, 0x40ecac);
    memoryASet16(ds, ecx + 0x4, ax);
    esp += 4; return;
loc_4062ae: // 0000:4062ae
    if (eax != 0x0000005f)
        goto loc_4062c0;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40eca4);
    memoryASet32(ds, ecx, edx);
    esp += 4; return;
loc_4062c0: // 0000:4062c0
    if (eax != 0x00000060)
        goto loc_4062db;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ec9c);
    memoryASet32(ds, eax, ecx);
    dl = memoryAGet(ds, 0x40eca0);
    memoryASet(ds, eax + 0x4, dl);
    esp += 4; return;
loc_4062db: // 0000:4062db
    if (eax != 0x00000067)
        goto loc_40630a;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ec90);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ec94);
    memoryASet32(ds, eax + 0x4, edx);
    cx = memoryAGet16(ds, 0x40ec98);
    memoryASet16(ds, eax + 0x8, cx);
    dl = memoryAGet(ds, 0x40ec9a);
    memoryASet(ds, eax + 0xa, dl);
    esp += 4; return;
loc_40630a: // 0000:40630a
    if (eax != 0x00000068)
        goto loc_40632e;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ec84);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ec88);
    memoryASet32(ds, eax + 0x4, edx);
    ecx = memoryAGet32(ds, 0x40ec8c);
    memoryASet32(ds, eax + 0x8, ecx);
    esp += 4; return;
loc_40632e: // 0000:40632e
    if (eax != 0x00000069)
        goto loc_406359;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40ec74);
    memoryASet32(ds, edx, eax);
    ecx = memoryAGet32(ds, 0x40ec78);
    memoryASet32(ds, edx + 0x4, ecx);
    eax = memoryAGet32(ds, 0x40ec7c);
    memoryASet32(ds, edx + 0x8, eax);
    cl = memoryAGet(ds, 0x40ec80);
    memoryASet(ds, edx + 0xc, cl);
    esp += 4; return;
loc_406359: // 0000:406359
    if (eax != 0x0000006a)
        goto loc_406386;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40ec64);
    memoryASet32(ds, edx, eax);
    ecx = memoryAGet32(ds, 0x40ec68);
    memoryASet32(ds, edx + 0x4, ecx);
    eax = memoryAGet32(ds, 0x40ec6c);
    memoryASet32(ds, edx + 0x8, eax);
    cx = memoryAGet16(ds, 0x40ec70);
    memoryASet16(ds, edx + 0xc, cx);
    esp += 4; return;
loc_406386: // 0000:406386
    if (eax != 0x0000006b)
        goto loc_406397;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40ec60);
    memoryASet32(ds, edx, eax);
    esp += 4; return;
loc_406397: // 0000:406397
    if (eax != 0x0000006c)
        goto loc_4063bc;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ec58);
    memoryASet32(ds, ecx, edx);
    ax = memoryAGet16(ds, 0x40ec5c);
    memoryASet16(ds, ecx + 0x4, ax);
    dl = memoryAGet(ds, 0x40ec5e);
    memoryASet(ds, ecx + 0x6, dl);
    esp += 4; return;
loc_4063bc: // 0000:4063bc
    if (eax != 0x0000006d)
        goto loc_4063e0;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ec4c);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ec50);
    memoryASet32(ds, eax + 0x4, edx);
    cl = memoryAGet(ds, 0x40ec54);
    memoryASet(ds, eax + 0x8, cl);
    esp += 4; return;
loc_4063e0: // 0000:4063e0
    if (eax != 0x0000006e)
        goto loc_406404;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40ec40);
    memoryASet32(ds, edx, eax);
    ecx = memoryAGet32(ds, 0x40ec44);
    memoryASet32(ds, edx + 0x4, ecx);
    ax = memoryAGet16(ds, 0x40ec48);
    memoryASet16(ds, edx + 0x8, ax);
    esp += 4; return;
loc_406404: // 0000:406404
    if (eax != 0x0000006f)
        goto loc_40641e;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ec38);
    memoryASet32(ds, ecx, edx);
    al = memoryAGet(ds, 0x40ec3c);
    memoryASet(ds, ecx + 0x4, al);
    esp += 4; return;
loc_40641e: // 0000:40641e
    if (eax != 0x00000070)
        goto loc_406441;
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ec2c);
    memoryASet32(ds, ecx, edx);
    eax = memoryAGet32(ds, 0x40ec30);
    memoryASet32(ds, ecx + 0x4, eax);
    edx = memoryAGet32(ds, 0x40ec34);
    memoryASet32(ds, ecx + 0x8, edx);
    esp += 4; return;
loc_406441: // 0000:406441
    if (eax != 0x00000071)
        goto loc_406465;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, 0x40ec20);
    memoryASet32(ds, eax, ecx);
    edx = memoryAGet32(ds, 0x40ec24);
    memoryASet32(ds, eax + 0x4, edx);
    cl = memoryAGet(ds, 0x40ec28);
    memoryASet(ds, eax + 0x8, cl);
    esp += 4; return;
loc_406465: // 0000:406465
    if (eax != 0x00000072)
        goto loc_406489;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, 0x40ec14);
    memoryASet32(ds, edx, eax);
    ecx = memoryAGet32(ds, 0x40ec18);
    memoryASet32(ds, edx + 0x4, ecx);
    ax = memoryAGet16(ds, 0x40ec1c);
    memoryASet16(ds, edx + 0x8, ax);
    esp += 4; return;
loc_406489: // 0000:406489
    ecx = memoryAGet32(ds, esp + 0x8);
    edx = memoryAGet32(ds, 0x40ec08);
    memoryASet32(ds, ecx, edx);
    eax = memoryAGet32(ds, 0x40ec0c);
    memoryASet32(ds, ecx + 0x4, eax);
    dx = memoryAGet16(ds, 0x40ec10);
    memoryASet16(ds, ecx + 0x8, dx);
    esp += 4;
}
void sub_4064b0() // 0000:4064b0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, eax);
    esp += 4;
}
void sub_4064c0() // 0000:4064c0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, esp + 0x4);
    push32(eax);
    push32(0x00000018);
    push32(ecx);
    eax = alleg40::pack_fwrite(stack32<const void>(0), stack32<long>(1), stack32<PACKFILE>(2));();
    esp += 0x0000000c;
    esp += 4;
}
void sub_4064e0() // 0000:4064e0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x8);
    ecx = memoryAGet32(ds, esp + 0x4);
    push32(eax);
    push32(0x00000018);
    push32(ecx);
    eax = alleg40::pack_fread(stack32<void>(0), stack32<long>(1), stack32<PACKFILE>(2));();
    esp += 0x0000000c;
    esp += 4;
}
void sub_406500() // 0000:406500 +long
{
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0x4);
    push32(edi);
    edi = 0;
    eax = ecx;
loc_406509: // 0000:406509
    if (!memoryAGet32(ds, eax))
        goto loc_40651a;
    edi++;
    eax += 0x00000018;
    if ((int32_t)edi < (int32_t)0x00000200)
        goto loc_406509;
loc_40651a: // 0000:40651a
    if (edi != 0x00000200)
        goto loc_406526;
    eax = 0;
    edi = pop32();
    esp += 4; return;
loc_406526: // 0000:406526
    edx = memoryAGet32(ds, esp + 0x10);
    eax = edi + (edi * 2);
    push32(esi);
    esi = ecx + (eax * 8);
    ecx = memoryAGet32(ds, esp + 0x10);
    ecx <<= 16;
    edx <<= 16;
    memoryASet32(ds, esi + 0x4, ecx);
    memoryASet32(ds, esi + 0x8, edx);
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000032;
    idiv32(ecx);
    eax = 0x66666667;
    edx -= 0x00000019;
    edx <<= 16;
    imul32(edx);
    edx = sar32(edx, 0x02);
    eax = edx;
    eax >>= 31;
    edx += eax;
    memoryASet32(ds, esi + 0xc, edx);
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000032;
    idiv32(ecx);
    eax = 0x51eb851f;
    edx -= 0x00000019;
    edx <<= 16;
    imul32(edx);
    edx = sar32(edx, 0x04);
    eax = edx;
    eax >>= 31;
    edx += eax;
    memoryASet32(ds, esi + 0x10, edx);
    memoryASet32(ds, esi, 0x000000ff);
    sub_406be3();
    eax &= 0x80000007;
    if ((int32_t)eax >= 0)
        goto loc_4065a6;
    eax--;
    eax |= 0xfffffff8;
    eax++;
loc_4065a6: // 0000:4065a6
    memoryASet32(ds, esi + 0x14, eax);
    eax = edi;
    esi = pop32();
    edi = pop32();
    esp += 4;
}
void sub_4065b0() // 0000:4065b0 +long
{
    esp -= 4;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, esi + 0xc);
    ecx = memoryAGet32(ds, esi + 0x4);
    edx = memoryAGet32(ds, esi + 0x8);
    ecx += eax;
    eax = memoryAGet32(ds, esi + 0x10);
    memoryASet32(ds, esi + 0x4, ecx);
    ecx = memoryAGet32(ds, esi);
    edx += eax;
    eax += 0x00004ccd;
    ecx--;
    memoryASet32(ds, esi + 0x8, edx);
    memoryASet32(ds, esi + 0x10, eax);
    memoryASet32(ds, esi, ecx);
    sub_406be3();
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 0x00000005;
    idiv32(ecx);
    if (edx != 0x00000001)
        goto loc_4065fe;
    sub_406be3();
    eax &= 0x80000007;
    if ((int32_t)eax >= 0)
        goto loc_4065fb;
    eax--;
    eax |= 0xfffffff8;
    eax++;
loc_4065fb: // 0000:4065fb
    memoryASet32(ds, esi + 0x14, eax);
loc_4065fe: // 0000:4065fe
    esi = pop32();
    esp += 4;
}
void sub_406600() // 0000:406600 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    ecx = 0x00000200;
loc_406609: // 0000:406609
    memoryASet32(ds, eax, 0x00000000);
    eax += 0x00000018;
    ecx--;
    if (ecx)
        goto loc_406609;
    esp += 4;
}
void sub_406620() // 0000:406620 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    ecx = 0;
    memoryASet32(ds, eax + 0x10, ecx);
    memoryASet32(ds, eax + 0x18, ecx);
    memoryASet32(ds, eax + 0x20, ecx);
    memoryASet32(ds, eax + 0x14, ecx);
    memoryASet32(ds, eax + 0x1c, ecx);
    memoryASet32(ds, eax + 0x30, ecx);
    memoryASet32(ds, eax + 0x34, 0x00000001);
    memoryASet32(ds, eax + 0x38, ecx);
    memoryASet32(ds, eax + 0x28, ecx);
    memoryASet32(ds, eax + 0x3c, ecx);
    memoryASet32(ds, eax + 0x40, ecx);
    memoryASet32(ds, eax + 0x44, ecx);
    memoryASet32(ds, eax + 0x2c, ecx);
    memoryASet32(ds, eax + 0x48, ecx);
    memoryASet32(ds, eax + 0x24, ecx);
    memoryASet32(ds, eax + 0x4c, ecx);
    memoryASet32(ds, eax + 0x54, ecx);
    memoryASet32(ds, eax + 0x58, ecx);
    memoryASet32(ds, eax + 0x5c, ecx);
    memoryASet32(ds, eax + 0x60, ecx);
    esp += 4;
}
void sub_406670() // 0000:406670 +long
{
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0x4);
    fld64(memoryAGet64(ds, ecx + 0x18));
    fcomp64(memoryAGet64(ds, 0x40d320));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_4066a0;
    fld64(memoryAGet64(ds, ecx + 0x18));
    fld64(memoryAGet64(ds, 0x40d318));
    fcomp80(st(1));
    ax = fnstsw();
    flags.zero = !(ah & 0x41);
    flags.sign = ah & 128;
    st(0) = fstp80();
    if (!flags.zero)
        goto loc_4066a0;
    fld64(memoryAGet64(ds, 0x40d318));
    goto loc_4066bb;
loc_4066a0: // 0000:4066a0
    fld64(memoryAGet64(ds, ecx + 0x18));
    fcomp64(memoryAGet64(ds, 0x40d320));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_4066b5;
    fld64(memoryAGet64(ds, ecx + 0x18));
    goto loc_4066bb;
loc_4066b5: // 0000:4066b5
    fld64(memoryAGet64(ds, 0x40d320));
loc_4066bb: // 0000:4066bb
    memoryASet64(ds, ecx + 0x18, fst64());
    fld64(memoryAGet64(ds, ecx + 0x10));
    fcomp64(memoryAGet64(ds, 0x40d320));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_4066ea;
    fld64(memoryAGet64(ds, ecx + 0x10));
    fld64(memoryAGet64(ds, 0x40d310));
    fcomp80(st(1));
    ax = fnstsw();
    flags.zero = !(ah & 0x41);
    flags.sign = ah & 128;
    st(0) = fstp80();
    if (!flags.zero)
        goto loc_4066ea;
    fld64(memoryAGet64(ds, 0x40d310));
    goto loc_406705;
loc_4066ea: // 0000:4066ea
    fld64(memoryAGet64(ds, ecx + 0x10));
    fcomp64(memoryAGet64(ds, 0x40d320));
    ax = fnstsw();
    flags.zero = !(ah & 0x01);
    flags.sign = ah & 128;
    if (flags.zero)
        goto loc_4066ff;
    fld64(memoryAGet64(ds, ecx + 0x10));
    goto loc_406705;
loc_4066ff: // 0000:4066ff
    fld64(memoryAGet64(ds, 0x40d320));
loc_406705: // 0000:406705
    memoryASet64(ds, ecx + 0x10, fst64());
    fld80(st(0));
    fadd64(memoryAGet64(ds, ecx));
    memoryASet64(ds, ecx, fst64());
    fld80(st(2));
    fadd64(memoryAGet64(ds, ecx + 0x8));
    memoryASet64(ds, ecx + 0x8, fst64());
    fcomp64(memoryAGet64(ds, 0x40d308));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_406731;
    memoryASet32(ds, ecx + 0x8, 0x00000000);
    memoryASet32(ds, ecx + 0xc, 0x408f4000);
loc_406731: // 0000:406731
    fcomp64(memoryAGet64(ds, 0x40d300));
    ax = fnstsw();
    flags.zero = !(ah & 0x41);
    flags.sign = ah & 128;
    if (!flags.zero)
        goto loc_406779;
    fmul64(memoryAGet64(ds, 0x40d2f8));
    memoryASet32(ds, ecx, 0x00000000);
    memoryASet32(ds, ecx + 0x4, 0x40815800);
    fcom64(memoryAGet64(ds, 0x40d1e0));
    memoryASet64(ds, ecx + 0x10, fst64());
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_406763;
    fchs();
loc_406763: // 0000:406763
    fcomp64(memoryAGet64(ds, 0x40d2f0));
    ax = fnstsw();
    flags.zero = !(ah & 0x41);
    flags.sign = ah & 128;
    if (!flags.zero)
        goto loc_40677b;
    memoryASet32(ds, ecx + 0x5c, 0xffffffec);
    goto loc_40677b;
loc_406779: // 0000:406779
    st(0) = fstp80();
loc_40677b: // 0000:40677b
    fld64(memoryAGet64(ds, ecx));
    fcomp64(memoryAGet64(ds, 0x40d2e8));
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_4067c6;
    fld64(memoryAGet64(ds, ecx + 0x10));
    fmul64(memoryAGet64(ds, 0x40d2f8));
    memoryASet32(ds, ecx, 0x00000000);
    memoryASet32(ds, ecx + 0x4, 0x40554000);
    fcom64(memoryAGet64(ds, 0x40d1e0));
    memoryASet64(ds, ecx + 0x10, fst64());
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_4067b2;
    fchs();
loc_4067b2: // 0000:4067b2
    fcomp64(memoryAGet64(ds, 0x40d2f0));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_4067c6;
    memoryASet32(ds, ecx + 0x5c, 0x00000014);
loc_4067c6: // 0000:4067c6
    eax = memoryAGet32(ds, ecx + 0x30);
    if (!eax)
        goto loc_4067d8;
    fadd64(memoryAGet64(ds, 0x40d2e0));
    memoryASet64(ds, ecx + 0x18, fstp64());
    goto loc_4067da;
loc_4067d8: // 0000:4067d8
    st(0) = fstp80();
loc_4067da: // 0000:4067da
    if (eax != 0x00000001)
        goto loc_4067f6;
    fld64(memoryAGet64(ds, ecx + 0x18));
    fcomp64(memoryAGet64(ds, 0x40d1e0));
    ax = fnstsw();
    if (ah & 0x41)
        goto loc_4067f6;
    memoryASet32(ds, ecx + 0x30, 0x00000002);
loc_4067f6: // 0000:4067f6
    esp += 4; return;
}
void sub_406800() // 0000:406800 +long
{
    bool temp_cond0;
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0x4);
    eax = memoryAGet32(ds, ecx + 0x30);
    if (!eax)
        goto loc_40680e;
    eax = 0;
    esp += 4; return;
loc_40680e: // 0000:40680e
    fld64(memoryAGet64(ds, ecx + 0x10));
    fadd80(st(0));
    edx = 0x00000001;
    memoryASet32(ds, ecx + 0x30, edx);
    fcom64(memoryAGet64(ds, 0x40d1e0));
    fld80(st(0));
    ax = fnstsw();
    if (!(dl & ah))
        goto loc_40682b;
    fchs();
loc_40682b: // 0000:40682b
    fchs();
    fcomp64(memoryAGet64(ds, 0x40d310));
    ax = fnstsw();
    temp_cond0 =     stop("FNSTSW reads flags");;
    if (!(ah & 0x01))
        goto loc_40684d;
    fcom64(memoryAGet64(ds, 0x40d1e0));
    ax = fnstsw();
    temp_cond0 =     stop("FNSTSW reads flags");;
    if (!(ah & 0x01))
        goto loc_406849;
    fchs();
loc_406849: // 0000:406849
    fchs();
    goto loc_406855;
loc_40684d: // 0000:40684d
    st(0) = fstp80();
    fld64(memoryAGet64(ds, 0x40d310));
loc_406855: // 0000:406855
    memoryASet64(ds, ecx + 0x18, fst64());
    eax = memoryAGet32(ds, ecx + 0x10);
    fcomp64(memoryAGet64(ds, 0x40d218));
    memoryASet32(ds, ecx + 0x20, eax);
    eax = memoryAGet32(ds, ecx + 0x14);
    memoryASet32(ds, ecx + 0x24, eax);
    ax = fnstsw();
    if (!(ah & 0x01))
        goto loc_406874;
    memoryASet32(ds, ecx + 0x4c, edx);
loc_406874: // 0000:406874
    memoryASet32(ds, ecx + 0x50, 0x00000000);
    eax |= 0xffffffff;
    esp += 4;
}
void sub_406880() // 0000:406880 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x8);
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x8);
    push32(eax);
    memoryASet32(ds, esi + 0x8, eax);
    eax = alleg40::text_height(stack32<const FONT>(0));();
    edx = memoryAGet32(ds, esp + 0x14);
    ecx = memoryAGet32(ds, esp + 0x18);
    memoryASet32(ds, esi + 0xc, eax);
    eax = memoryAGet32(ds, esp + 0x1c);
    memoryASet32(ds, esi + 0x14, eax);
    eax = memoryAGet32(ds, esp + 0x20);
    esp += 0x00000004;
    memoryASet32(ds, esi, eax);
    memoryASet32(ds, esi + 0x4, edx);
    memoryASet32(ds, esi + 0x10, ecx);
    if (!eax)
        goto loc_4068d1;
    push32(edx);
    edx = memoryAGet32(ds, esi + 0x8);
    push32(edx);
    eax = alleg40::text_length(stack32<const FONT>(0), stack32<const char>(1));();
    memoryASet32(ds, esi + 0x20, eax);
    eax = memoryAGet32(ds, esi + 0x10);
    esp += 0x00000008;
    memoryASet32(ds, esi + 0x18, eax);
    esi = pop32();
    esp += 4; return;
loc_4068d1: // 0000:4068d1
    push32(edi);
    edi = edx;
    ecx |= 0xffffffff;
    eax = 0;
    for (flags.zero = 0; ecx != 0 && !flags.zero; --ecx) scasb_inv<ES_EDI>(al);
    ecx = ~ecx;
    ecx--;
    memoryASet32(ds, esi + 0x24, edx);
    memoryASet32(ds, esi + 0x1c, 0x00000001);
    if ((int32_t)ecx <= 0)
        goto loc_406919;
loc_4068ec: // 0000:4068ec
    edx = memoryAGet32(ds, esi + 0x4);
    edx += eax;
    if (memoryAGet(ds, edx) != 0x0a)
        goto loc_406914;
    edi = memoryAGet32(ds, esi + 0x1c);
    if ((int32_t)edi >= (int32_t)0x00000200)
        goto loc_406914;
    edx++;
    memoryASet32(ds, esi + edi * 4 + 0x24, edx);
    edx = memoryAGet32(ds, esi + 0x1c);
    edx++;
    memoryASet32(ds, esi + 0x1c, edx);
    edx = memoryAGet32(ds, esi + 0x4);
    memoryASet(ds, eax + edx, 0x00);
loc_406914: // 0000:406914
    eax++;
    if ((int32_t)eax < (int32_t)ecx)
        goto loc_4068ec;
loc_406919: // 0000:406919
    eax = memoryAGet32(ds, esi + 0x14);
    edi = pop32();
    memoryASet32(ds, esi + 0x18, eax);
    esi = pop32();
    esp += 4;
}
void sub_406930() // 0000:406930 +long
{
    esp -= 4;
    push32(ebx);
    push32(ebp);
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x10);
    push32(edi);
    if (!memoryAGet32(ds, esi))
        goto loc_4069b3;
    eax = memoryAGet32(ds, esi + 0x20);
    ecx = memoryAGet32(ds, esi + 0x18);
    eax = -eax;
    if ((int32_t)ecx >= (int32_t)eax)
        goto loc_406950;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    eax = 0;
    ebx = pop32();
    esp += 4; return;
loc_406950: // 0000:406950
    eax = memoryAGet32(ds, esi + 0x10);
    if ((int32_t)ecx <= (int32_t)eax)
        goto loc_40695e;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    eax = 0;
    ebx = pop32();
    esp += 4; return;
loc_40695e: // 0000:40695e
    ecx = memoryAGet32(ds, esi + 0x14);
    ebx = memoryAGet32(ds, esp + 0x20);
    ebp = memoryAGet32(ds, esp + 0x1c);
    edi = memoryAGet32(ds, esp + 0x18);
    ecx += ebx;
    eax += ebp;
    push32(ecx);
    push32(eax);
    push32(ebx);
    push32(ebp);
    push32(edi);
    alleg40::set_clip(stack32<BITMAP>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));();
    edx = memoryAGet32(ds, esi + 0x18);
    eax = memoryAGet32(ds, esi + 0x4);
    ecx = memoryAGet32(ds, esi + 0x8);
    push32(0xffffffff);
    edx += ebp;
    push32(ebx);
    push32(edx);
    push32(eax);
    push32(ecx);
    push32(edi);
    alleg40::textout(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<const char>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));();
    edx = memoryAGet32(ds, edi + 0x4);
    eax = memoryAGet32(ds, edi);
    edx--;
    eax--;
    push32(edx);
    push32(eax);
    push32(0x00000000);
    push32(0x00000000);
    push32(edi);
    alleg40::set_clip(stack32<BITMAP>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));();
    esp += 0x00000040;
    eax |= 0xffffffff;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 4; return;
loc_4069b3: // 0000:4069b3
    ecx = memoryAGet32(ds, esi + 0xc);
    eax = memoryAGet32(ds, esi + 0x18);
    ecx = (int32_t)ecx * ((int32_t)memoryAGet32(ds, esi + 0x1c));
    ecx = -ecx;
    if ((int32_t)eax >= (int32_t)ecx)
        goto loc_4069ca;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    eax = 0;
    ebx = pop32();
    esp += 4; return;
loc_4069ca: // 0000:4069ca
    ecx = memoryAGet32(ds, esi + 0x14);
    if ((int32_t)eax <= (int32_t)ecx)
        goto loc_4069d8;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    eax = 0;
    ebx = pop32();
    esp += 4; return;
loc_4069d8: // 0000:4069d8
    eax = memoryAGet32(ds, esp + 0x20);
    edx = memoryAGet32(ds, esi + 0x10);
    ecx += eax;
    ebx = memoryAGet32(ds, esp + 0x18);
    push32(ecx);
    ecx = memoryAGet32(ds, esp + 0x20);
    edx += ecx;
    push32(edx);
    push32(eax);
    push32(ecx);
    push32(ebx);
    alleg40::set_clip(stack32<BITMAP>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));();
    eax = memoryAGet32(ds, esi + 0x1c);
    esp += 0x00000014;
    edi = 0;
    if ((int32_t)eax <= 0)
        goto loc_406a64;
    eax = esi + 36;
    memoryASet32(ds, esp + 0x18, eax);
loc_406a09: // 0000:406a09
    ecx = memoryAGet32(ds, esi + 0xc);
    edx = memoryAGet32(ds, esi + 0x18);
    eax = ecx;
    ebp = memoryAGet32(ds, esi + 0x14);
    eax = (int32_t)eax * (int32_t)edi;
    eax += edx;
    if ((int32_t)eax > (int32_t)ebp)
        goto loc_406a51;
    ebp = edi + 1;
    ebp = (int32_t)ebp * (int32_t)ecx;
    ebp += edx;
    if ((int32_t)ebp < 0)
        goto loc_406a51;
    ecx = memoryAGet32(ds, esp + 0x20);
    edx = memoryAGet32(ds, esi + 0x10);
    ebp = memoryAGet32(ds, esp + 0x1c);
    eax += ecx;
    push32(0xffffffff);
    push32(eax);
    eax = memoryAGet32(ds, esp + 0x20);
    edx = sar32(edx, 0x00000001);
    ecx = memoryAGet32(ds, eax);
    edx += ebp;
    push32(edx);
    edx = memoryAGet32(ds, esi + 0x8);
    push32(ecx);
    push32(edx);
    push32(ebx);
    alleg40::textout_centre(stack32<BITMAP>(0), stack32<const FONT>(1), stack32<const char>(2), stack32<int>(3), stack32<int>(4), stack32<int>(5));();
    esp += 0x00000018;
loc_406a51: // 0000:406a51
    ecx = memoryAGet32(ds, esp + 0x18);
    eax = memoryAGet32(ds, esi + 0x1c);
    edi++;
    ecx += 0x00000004;
    memoryASet32(ds, esp + 0x18, ecx);
    if ((int32_t)edi < (int32_t)eax)
        goto loc_406a09;
loc_406a64: // 0000:406a64
    eax = memoryAGet32(ds, ebx + 0x4);
    ecx = memoryAGet32(ds, ebx);
    eax--;
    ecx--;
    push32(eax);
    push32(ecx);
    push32(0x00000000);
    push32(0x00000000);
    push32(ebx);
    alleg40::set_clip(stack32<BITMAP>(0), stack32<int>(1), stack32<int>(2), stack32<int>(3), stack32<int>(4));();
    esp += 0x00000014;
    eax |= 0xffffffff;
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 4;
}
void sub_406a90() // 0000:406a90 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    ecx = memoryAGet32(ds, esp + 0x8);
    memoryASet32(ds, eax + 0x18, memoryAGet32(ds, eax + 0x18) + ecx);
    esp += 4;
}
void sub_406aa0() // 0000:406aa0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    if (!memoryAGet32(ds, eax))
        goto loc_406ab0;
    ecx = memoryAGet32(ds, eax + 0x10);
    memoryASet32(ds, eax + 0x18, ecx);
    esp += 4; return;
loc_406ab0: // 0000:406ab0
    edx = memoryAGet32(ds, eax + 0x14);
    memoryASet32(ds, eax + 0x18, edx);
    esp += 4;
}
void sub_406b00() // 0000:406b00 +long
{
    esp -= 4;
    push32(esi);
    alleg40::install_timer();();
    esi = memoryAGet32(ds, 0x40d0f8);
    push32(0x000003e8);
    push32(0x00406ac0);
    indirectCall(cs, esi); // 0000:406b17
    eax = 0;
    memoryASet32(ds, 0x40fcb0, eax);
    memoryASet32(ds, 0x40ffc4, eax);
    push32(0x00000014);
    push32(0x00406ae0);
    indirectCall(cs, esi); // 0000:406b2c
    esp += 0x00000010;
    eax |= 0xffffffff;
    esi = pop32();
    esp += 4;
}
void sub_406b40() // 0000:406b40 +long
{
    esp -= 4;
    push32(memoryAGet32(ds, 0x40fb18));
    push32(memoryAGet32(ds, esp + 0x8));
    sub_406b52();
    ecx = pop32();
    ecx = pop32();
    esp += 4;
}
void sub_406b52() // 0000:406b52 +long
{
    esp -= 4;
    if (memoryAGet32(ds, esp + 0x4) > 0xffffffe0)
        goto loc_406b7b;
loc_406b59: // 0000:406b59
    push32(memoryAGet32(ds, esp + 0x4));
    sub_406b7e();
    ecx = pop32();
    if (eax)
        goto loc_406b7d;
    if (memoryAGet32(ds, esp + 0x8) == eax)
        goto loc_406b7d;
    push32(memoryAGet32(ds, esp + 0x4));
    sub_406fbc();
    ecx = pop32();
    if (eax)
        goto loc_406b59;
loc_406b7b: // 0000:406b7b
    eax = 0;
loc_406b7d: // 0000:406b7d
    esp += 4; return;
}
void sub_406b7e() // 0000:406b7e +long
{
    esp -= 4;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x8);
    if (esi > memoryAGet32(ds, 0x40eed4))
        goto loc_406b96;
    push32(esi);
    sub_4073a7();
    ecx = pop32();
    if (eax)
        goto loc_406bb2;
loc_406b96: // 0000:406b96
    if (esi)
        goto loc_406b9d;
    push32(0x00000001);
    esi = pop32();
loc_406b9d: // 0000:406b9d
    esi += 0x0000000f;
    esi &= 0xfffffff0;
    push32(esi);
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x42d17c));
    eax = kernel32::HeapAlloc(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<SIZE_T>(2)); esp += 12;();
loc_406bb2: // 0000:406bb2
    esi = pop32();
    esp += 4;
}
void sub_406bb4() // 0000:406bb4 +long
{
    esp -= 4;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x8);
    if (!esi)
        goto loc_406be1;
    push32(esi);
    sub_407051();
    ecx = pop32();
    push32(esi);
    if (!eax)
        goto loc_406bd3;
    push32(eax);
    sub_40707c();
    ecx = pop32();
    ecx = pop32();
    esi = pop32();
    esp += 4; return;
loc_406bd3: // 0000:406bd3
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x42d17c));
    eax = kernel32::HeapFree(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPVOID>(2)); esp += 12;();
loc_406be1: // 0000:406be1
    esi = pop32();
    esp += 4;
}
void sub_406be3() // 0000:406be3 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x40eeb0);
    eax = (int32_t)eax * (int32_t)0x000343fd;
    eax += 0x00269ec3;
    memoryASet32(ds, 0x40eeb0, eax);
    eax = sar32(eax, 0x10);
    eax &= 0x00007fff;
    esp += 4;
}
void sub_406c01() // 0000:406c01 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x40eebc);
    if (!eax)
        goto loc_406c0c;
    indirectCall(cs, eax); // 0000:406c0a
loc_406c0c: // 0000:406c0c
    push32(0x0040e018);
    push32(0x0040e008);
    sub_406ce9();
    push32(0x0040e004);
    push32(0x0040e000);
    sub_406ce9();
    esp += 0x00000010;
    esp += 4;
}
void sub_406c2e() // 0000:406c2e +long
{
    esp -= 4;
    push32(0x00000000);
    push32(0x00000000);
    push32(memoryAGet32(ds, esp + 0xc));
    sub_406c50();
    esp += 0x0000000c;
    esp += 4;
}
void sub_406c50() // 0000:406c50 +long
{
    esp -= 4;
    push32(edi);
    push32(0x00000001);
    edi = pop32();
    if (memoryAGet32(ds, 0x40fb00) != edi)
        goto loc_406c6d;
    push32(memoryAGet32(ds, esp + 0x8));
    eax = kernel32::GetCurrentProcess();();
    push32(eax);
    eax = kernel32::TerminateProcess(stack32<HANDLE>(0), stack32<UINT>(1)); esp += 8;();
loc_406c6d: // 0000:406c6d
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x14);
    memoryASet32(ds, 0x40fafc, edi);
    memoryASet(ds, 0x40faf8, bl);
    if (memoryAGet32(ds, esp + 0xc))
        goto loc_406cc1;
    eax = memoryAGet32(ds, 0x42d190);
    if (!eax)
        goto loc_406cb0;
    ecx = memoryAGet32(ds, 0x42d18c);
    push32(esi);
    esi = ecx - 4;
    if (esi < eax)
        goto loc_406caf;
loc_406c9c: // 0000:406c9c
    eax = memoryAGet32(ds, esi);
    if (!eax)
        goto loc_406ca4;
    indirectCall(cs, eax); // 0000:406ca2
loc_406ca4: // 0000:406ca4
    esi -= 0x00000004;
    if (esi >= memoryAGet32(ds, 0x42d190))
        goto loc_406c9c;
loc_406caf: // 0000:406caf
    esi = pop32();
loc_406cb0: // 0000:406cb0
    push32(0x0040e024);
    push32(0x0040e01c);
    sub_406ce9();
    ecx = pop32();
    ecx = pop32();
loc_406cc1: // 0000:406cc1
    push32(0x0040e02c);
    push32(0x0040e028);
    sub_406ce9();
    ecx = pop32();
    ecx = pop32();
    flags.zero = ebx == 0;
    ebx = pop32();
    if (!flags.zero)
        goto loc_406ce7;
    push32(memoryAGet32(ds, esp + 0x8));
    memoryASet32(ds, 0x40fb00, edi);
    kernel32::ExitProcess(stack32<UINT>(0)); esp += 4;();
loc_406ce7: // 0000:406ce7
    edi = pop32();
    esp += 4;
}
void sub_406ce9() // 0000:406ce9 +long
{
    esp -= 4;
    push32(esi);
    esi = memoryAGet32(ds, esp + 0x8);
loc_406cee: // 0000:406cee
    if (esi >= memoryAGet32(ds, esp + 0xc))
        goto loc_406d01;
    eax = memoryAGet32(ds, esi);
    if (!eax)
        goto loc_406cfc;
    indirectCall(cs, eax); // 0000:406cfa
loc_406cfc: // 0000:406cfc
    esi += 0x00000004;
    goto loc_406cee;
loc_406d01: // 0000:406d01
    esi = pop32();
    esp += 4;
}
void sub_406d82() // 0000:406d82 +long
{
    esp -= 4;
    push32(0x00000080);
    sub_406b40();
    ecx = pop32();
    memoryASet32(ds, 0x42d190, eax);
    if (eax)
        goto loc_406da3;
    push32(0x00000018);
    sub_406f73();
    eax = memoryAGet32(ds, 0x42d190);
    ecx = pop32();
loc_406da3: // 0000:406da3
    memoryASet32(ds, eax, memoryAGet32(ds, eax) & 0x00000000);
    eax = memoryAGet32(ds, 0x42d190);
    memoryASet32(ds, 0x42d18c, eax);
    esp += 4;
}
void sub_406db1() // 0000:406db1 +long
{
    esp -= 4;
    sub_406dc9();
    sub_407ceb();
    memoryASet32(ds, 0x40fb08, eax);
    sub_407c9b();
    stop("disassembly failed at 0000:406dc5 (fnclex )");
    esp += 4;
}
void sub_406dc9() // 0000:406dc9 +long
{
    esp -= 4;
    eax = 0x004080d9;
    memoryASet32(ds, 0x40eedc, 0x00407d6e);
    memoryASet32(ds, 0x40eed8, eax);
    memoryASet32(ds, 0x40eee0, 0x00407dd4);
    memoryASet32(ds, 0x40eee4, 0x00407d14);
    memoryASet32(ds, 0x40eee8, 0x00407dbc);
    memoryASet32(ds, 0x40eeec, eax);
    esp += 4;
}
void sub_406e04() // 0000:406e04 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp += 0xfffffff4;
    memoryASet16(ss, ebp - 2, fnstcw());
    ax = memoryAGet16(ss, ebp - 2);
    ah |= 0x0c;
    memoryASet16(ss, ebp - 4, ax);
    fldcw(memoryAGet16(ss, ebp - 4));
    memoryASet64(ss, ebp - 12, fistp64());
    fldcw(memoryAGet16(ss, ebp - 2));
    eax = memoryAGet32(ss, ebp - 12);
    edx = memoryAGet32(ss, ebp - 8);
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_406e2b() // 0000:406e2b +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000020;
    eax = memoryAGet32(ss, ebp + 0x8);
    push32(esi);
    memoryASet32(ss, ebp - 24, eax);
    memoryASet32(ss, ebp - 32, eax);
    eax = ebp + 16;
    memoryASet32(ss, ebp - 20, 0x00000042);
    push32(eax);
    eax = ebp - 32;
    push32(memoryAGet32(ss, ebp + 0xc));
    memoryASet32(ss, ebp - 28, 0x7fffffff);
    push32(eax);
    sub_408264();
    esp += 0x0000000c;
    memoryASet32(ss, ebp - 28, memoryAGet32(ss, ebp - 28) - 1);
    esi = eax;
    if ((int32_t)memoryAGet32(ss, ebp - 28) < 0)
        goto loc_406e6b;
    eax = memoryAGet32(ss, ebp - 32);
    memoryASet(ds, eax, memoryAGet(ds, eax) & 0x00);
    goto loc_406e78;
loc_406e6b: // 0000:406e6b
    eax = ebp - 32;
    push32(eax);
    push32(0x00000000);
    sub_40814f();
    ecx = pop32();
    ecx = pop32();
loc_406e78: // 0000:406e78
    eax = esi;
    esi = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_406e7d() // 0000:406e7d +entry
{
    push32(ebp);
    ebp = esp;
    push32(0xffffffff);
    push32(0x0040d328);
    push32(0x00409328);
    eax = memoryAGet32(fs, 0x0);
    push32(eax);
    memoryASet32(fs, 0x0, esp);
    esp -= 0x00000058;
    push32(ebx);
    push32(esi);
    push32(edi);
    memoryASet32(ss, ebp - 24, esp);
    eax = kernel32::GetVersion();();
    edx = 0;
    dl = ah;
    memoryASet32(ds, 0x40fad0, edx);
    ecx = eax;
    ecx &= 0x000000ff;
    memoryASet32(ds, 0x40facc, ecx);
    ecx <<= 8;
    ecx += edx;
    memoryASet32(ds, 0x40fac8, ecx);
    eax >>= 16;
    memoryASet32(ds, 0x40fac4, eax);
    esi = 0;
    push32(esi);
    sub_406fd7();
    ecx = pop32();
    if (eax)
        goto loc_406ee9;
    push32(0x0000001c);
    sub_406f98();
    ecx = pop32();
loc_406ee9: // 0000:406ee9
    memoryASet32(ss, ebp - 4, esi);
    sub_409082();
    eax = kernel32::GetCommandLineA();();
    memoryASet32(ds, 0x42d180, eax);
    sub_408f50();
    memoryASet32(ds, 0x40fb0c, eax);
    sub_408d03();
    sub_408c4a();
    sub_406c01();
    memoryASet32(ss, ebp - 48, esi);
    eax = ebp - 92;
    push32(eax);
    kernel32::GetStartupInfoA(stack32<LPSTARTUPINFOA>(0)); esp += 4;();
    sub_408bf2();
    memoryASet32(ss, ebp - 100, eax);
    if (!(memoryAGet(ss, ebp - 48) & 0x01))
        goto loc_406f36;
    eax = memoryAGet16(ss, ebp - 44);
    goto loc_406f39;
loc_406f36: // 0000:406f36
    push32(0x0000000a);
    eax = pop32();
loc_406f39: // 0000:406f39
    push32(eax);
    push32(memoryAGet32(ss, ebp - 100));
    push32(esi);
    push32(esi);
    eax = kernel32::GetModuleHandleA(stack32<LPCSTR>(0)); esp += 4;();
    push32(eax);
    sub_404f90();
    memoryASet32(ss, ebp - 96, eax);
    push32(eax);
    sub_406c2e();
    eax = memoryAGet32(ss, ebp - 20);
    ecx = memoryAGet32(ds, eax);
    ecx = memoryAGet32(ds, ecx);
    memoryASet32(ss, ebp - 104, ecx);
    push32(eax);
    push32(ecx);
    sub_408a6e();
    ecx = pop32();
    ecx = pop32();
    stop("stack_unbalanced");
}
void sub_406f73() // 0000:406f73 +long
{
    esp -= 4;
    if (memoryAGet32(ds, 0x40fb14) != 0x00000001)
        goto loc_406f81;
    sub_409400();
loc_406f81: // 0000:406f81
    push32(memoryAGet32(ds, esp + 0x4));
    sub_409439();
    push32(0x000000ff);
    indirectCall(cs, memoryAGet32(ds, 0x40eec8)); // 0000:406f8f
    ecx = pop32();
    ecx = pop32();
    esp += 4;
}
void sub_406f98() // 0000:406f98 +long
{
    esp -= 4;
    if (memoryAGet32(ds, 0x40fb14) != 0x00000001)
        goto loc_406fa6;
    sub_409400();
loc_406fa6: // 0000:406fa6
    push32(memoryAGet32(ds, esp + 0x4));
    sub_409439();
    ecx = pop32();
    push32(0x000000ff);
    kernel32::ExitProcess(stack32<UINT>(0)); esp += 4;();
    esp += 4;
}
void sub_406fbc() // 0000:406fbc +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x40fb1c);
    if (!eax)
        goto loc_406fd4;
    push32(memoryAGet32(ds, esp + 0x4));
    indirectCall(cs, eax); // 0000:406fc9
    ecx = pop32();
    if (!eax)
        goto loc_406fd4;
    push32(0x00000001);
    eax = pop32();
    esp += 4; return;
loc_406fd4: // 0000:406fd4
    eax = 0;
    esp += 4;
}
void sub_406fd7() // 0000:406fd7 +long
{
    esp -= 4;
    eax = 0;
    push32(0x00000000);
    push32(0x00001000);
    al = memoryAGet32(ds, esp + 0x8) == eax;
    push32(eax);
    eax = kernel32::HeapCreate(stack32<DWORD>(0), stack32<SIZE_T>(1), stack32<SIZE_T>(2)); esp += 12;();
    memoryASet32(ds, 0x42d17c, eax);
    if (!eax)
        goto loc_40700c;
    sub_407013();
    if (eax)
        goto loc_40700f;
    push32(memoryAGet32(ds, 0x42d17c));
    eax = kernel32::HeapDestroy(stack32<HANDLE>(0)); esp += 4;();
loc_40700c: // 0000:40700c
    eax = 0;
    esp += 4; return;
loc_40700f: // 0000:40700f
    push32(0x00000001);
    eax = pop32();
    esp += 4;
}
void sub_407013() // 0000:407013 +long
{
    esp -= 4;
    push32(0x00000140);
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x42d17c));
    eax = kernel32::HeapAlloc(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<SIZE_T>(2)); esp += 12;();
    memoryASet32(ds, 0x42d178, eax);
    if (eax)
        goto loc_407030;
    esp += 4; return;
loc_407030: // 0000:407030
    memoryASet32(ds, 0x42d170, memoryAGet32(ds, 0x42d170) & 0x00000000);
    memoryASet32(ds, 0x42d174, memoryAGet32(ds, 0x42d174) & 0x00000000);
    push32(0x00000001);
    memoryASet32(ds, 0x42d16c, eax);
    memoryASet32(ds, 0x42d164, 0x00000010);
    eax = pop32();
    esp += 4;
}
void sub_407051() // 0000:407051 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x42d174);
    ecx = eax + (eax * 4);
    eax = memoryAGet32(ds, 0x42d178);
    ecx = eax + (ecx * 4);
loc_407061: // 0000:407061
    if (eax >= ecx)
        goto loc_407079;
    edx = memoryAGet32(ds, esp + 0x4);
    edx -= memoryAGet32(ds, eax + 0xc);
    if (edx < 0x00100000)
        goto loc_40707b;
    eax += 0x00000014;
    goto loc_407061;
loc_407079: // 0000:407079
    eax = 0;
loc_40707b: // 0000:40707b
    esp += 4; return;
}
void sub_40707c() // 0000:40707c +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000014;
    edx = memoryAGet32(ss, ebp + 0xc);
    ecx = memoryAGet32(ss, ebp + 0x8);
    push32(ebx);
    push32(esi);
    eax = memoryAGet32(ds, ecx + 0x10);
    esi = edx;
    esi -= memoryAGet32(ds, ecx + 0xc);
    ebx = memoryAGet32(ds, edx - 4);
    edx += 0xfffffffc;
    push32(edi);
    esi >>= 15;
    ecx = esi;
    edi = memoryAGet32(ds, edx - 4);
    ecx = (int32_t)ecx * (int32_t)0x00000204;
    ebx--;
    memoryASet32(ss, ebp - 4, edi);
    ecx = (ecx + eax) + 324;
    memoryASet32(ss, ebp - 12, ebx);
    memoryASet32(ss, ebp - 16, ecx);
    ecx = memoryAGet32(ds, ebx + edx);
    memoryASet32(ss, ebp - 8, ecx);
    if (cl & 0x01)
        goto loc_407142;
    ecx = sar32(ecx, 0x04);
    push32(0x0000003f);
    ecx--;
    edi = pop32();
    memoryASet32(ss, ebp + 0xc, ecx);
    if (ecx <= edi)
        goto loc_4070d4;
    memoryASet32(ss, ebp + 0xc, edi);
loc_4070d4: // 0000:4070d4
    ecx = memoryAGet32(ds, ebx + edx + 0x4);
    if (ecx != memoryAGet32(ds, ebx + edx + 0x8))
        goto loc_407126;
    ecx = memoryAGet32(ss, ebp + 0xc);
    if (ecx >= 0x00000020)
        goto loc_407102;
    edi = 0x80000000;
    edi >>= cl;
    ecx = (ecx + eax) + 4;
    edi = ~edi;
    memoryASet32(ds, eax + esi * 4 + 0x44, memoryAGet32(ds, eax + esi * 4 + 0x44) & edi);
    memoryASet(ds, ecx, memoryAGet(ds, ecx) - 1);
    if (memoryAGet(ds, ecx))
        goto loc_407126;
    ecx = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) & edi);
    goto loc_407126;
loc_407102: // 0000:407102
    ecx += 0xffffffe0;
    edi = 0x80000000;
    edi >>= cl;
    ecx = memoryAGet32(ss, ebp + 0xc);
    ecx = (ecx + eax) + 4;
    edi = ~edi;
    memoryASet32(ds, eax + esi * 4 + 0xc4, memoryAGet32(ds, eax + esi * 4 + 0xc4) & edi);
    memoryASet(ds, ecx, memoryAGet(ds, ecx) - 1);
    if (memoryAGet(ds, ecx))
        goto loc_407126;
    ecx = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, ecx + 0x4, memoryAGet32(ds, ecx + 0x4) & edi);
loc_407126: // 0000:407126
    ecx = memoryAGet32(ds, ebx + edx + 0x8);
    edi = memoryAGet32(ds, ebx + edx + 0x4);
    memoryASet32(ds, ecx + 0x4, edi);
    ecx = memoryAGet32(ds, ebx + edx + 0x4);
    edi = memoryAGet32(ds, ebx + edx + 0x8);
    ebx += memoryAGet32(ss, ebp - 8);
    memoryASet32(ds, ecx + 0x8, edi);
    memoryASet32(ss, ebp - 12, ebx);
loc_407142: // 0000:407142
    edi = ebx;
    edi = sar32(edi, 0x04);
    edi--;
    if (edi <= 0x0000003f)
        goto loc_407150;
    push32(0x0000003f);
    edi = pop32();
loc_407150: // 0000:407150
    ecx = memoryAGet32(ss, ebp - 4);
    ecx &= 0x00000001;
    memoryASet32(ss, ebp - 20, ecx);
    if (ecx)
        goto loc_4071ff;
    edx -= memoryAGet32(ss, ebp - 4);
    ecx = memoryAGet32(ss, ebp - 4);
    ecx = sar32(ecx, 0x04);
    push32(0x0000003f);
    memoryASet32(ss, ebp - 8, edx);
    ecx--;
    edx = pop32();
    memoryASet32(ss, ebp + 0xc, ecx);
    if (ecx <= edx)
        goto loc_40717b;
    memoryASet32(ss, ebp + 0xc, edx);
    ecx = edx;
loc_40717b: // 0000:40717b
    ebx += memoryAGet32(ss, ebp - 4);
    edi = ebx;
    memoryASet32(ss, ebp - 12, ebx);
    edi = sar32(edi, 0x04);
    edi--;
    if (edi <= edx)
        goto loc_40718d;
    edi = edx;
loc_40718d: // 0000:40718d
    if (ecx == edi)
        goto loc_4071fc;
    ecx = memoryAGet32(ss, ebp - 8);
    edx = memoryAGet32(ds, ecx + 0x4);
    if (edx != memoryAGet32(ds, ecx + 0x8))
        goto loc_4071e4;
    ecx = memoryAGet32(ss, ebp + 0xc);
    if (ecx >= 0x00000020)
        goto loc_4071c0;
    edx = 0x80000000;
    edx >>= cl;
    ecx = (ecx + eax) + 4;
    edx = ~edx;
    memoryASet32(ds, eax + esi * 4 + 0x44, memoryAGet32(ds, eax + esi * 4 + 0x44) & edx);
    memoryASet(ds, ecx, memoryAGet(ds, ecx) - 1);
    if (memoryAGet(ds, ecx))
        goto loc_4071e4;
    ecx = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) & edx);
    goto loc_4071e4;
loc_4071c0: // 0000:4071c0
    ecx += 0xffffffe0;
    edx = 0x80000000;
    edx >>= cl;
    ecx = memoryAGet32(ss, ebp + 0xc);
    ecx = (ecx + eax) + 4;
    edx = ~edx;
    memoryASet32(ds, eax + esi * 4 + 0xc4, memoryAGet32(ds, eax + esi * 4 + 0xc4) & edx);
    memoryASet(ds, ecx, memoryAGet(ds, ecx) - 1);
    if (memoryAGet(ds, ecx))
        goto loc_4071e4;
    ecx = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, ecx + 0x4, memoryAGet32(ds, ecx + 0x4) & edx);
loc_4071e4: // 0000:4071e4
    ecx = memoryAGet32(ss, ebp - 8);
    edx = memoryAGet32(ds, ecx + 0x8);
    ecx = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, edx + 0x4, ecx);
    ecx = memoryAGet32(ss, ebp - 8);
    edx = memoryAGet32(ds, ecx + 0x4);
    ecx = memoryAGet32(ds, ecx + 0x8);
    memoryASet32(ds, edx + 0x8, ecx);
loc_4071fc: // 0000:4071fc
    edx = memoryAGet32(ss, ebp - 8);
loc_4071ff: // 0000:4071ff
    if (memoryAGet32(ss, ebp - 20))
        goto loc_40720e;
    if (memoryAGet32(ss, ebp + 0xc) == edi)
        goto loc_407297;
loc_40720e: // 0000:40720e
    ecx = memoryAGet32(ss, ebp - 16);
    ecx = ecx + (edi * 8);
    ecx = memoryAGet32(ds, ecx + 0x4);
    memoryASet32(ds, edx + 0x4, ecx);
    ecx = memoryAGet32(ss, ebp - 16);
    ecx = ecx + (edi * 8);
    memoryASet32(ds, edx + 0x8, ecx);
    memoryASet32(ds, ecx + 0x4, edx);
    ecx = memoryAGet32(ds, edx + 0x4);
    memoryASet32(ds, ecx + 0x8, edx);
    ecx = memoryAGet32(ds, edx + 0x4);
    if (ecx != memoryAGet32(ds, edx + 0x8))
        goto loc_407297;
    cl = memoryAGet(ds, edi + eax + 0x4);
    memoryASet(ss, ebp + 0xf, cl);
    cl++;
    memoryASet(ds, edi + eax + 0x4, cl);
    if (edi >= 0x00000020)
        goto loc_40726b;
    if (memoryAGet(ss, ebp + 0xf))
        goto loc_40725a;
    ebx = 0x80000000;
    ecx = edi;
    ebx >>= cl;
    ecx = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) | ebx);
loc_40725a: // 0000:40725a
    ebx = 0x80000000;
    ecx = edi;
    ebx >>= cl;
    eax = (eax + (esi * 4)) + 68;
    memoryASet32(ds, eax, memoryAGet32(ds, eax) | ebx);
    goto loc_407294;
loc_40726b: // 0000:40726b
    if (memoryAGet(ss, ebp + 0xf))
        goto loc_407281;
    ecx = edi - 32;
    ebx = 0x80000000;
    ebx >>= cl;
    ecx = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, ecx + 0x4, memoryAGet32(ds, ecx + 0x4) | ebx);
loc_407281: // 0000:407281
    ecx = edi - 32;
    edi = 0x80000000;
    edi >>= cl;
    eax = (eax + (esi * 4)) + 196;
    memoryASet32(ds, eax, memoryAGet32(ds, eax) | edi);
loc_407294: // 0000:407294
    ebx = memoryAGet32(ss, ebp - 12);
loc_407297: // 0000:407297
    eax = memoryAGet32(ss, ebp - 16);
    memoryASet32(ds, edx, ebx);
    memoryASet32(ds, ebx + edx - 4, ebx);
    memoryASet32(ds, eax, memoryAGet32(ds, eax) - 1);
    if (memoryAGet32(ds, eax))
        goto loc_4073a2;
    eax = memoryAGet32(ds, 0x42d170);
    if (!eax)
        goto loc_407394;
    ecx = memoryAGet32(ds, 0x42d168);
    edi = memoryAGet32(ds, 0x40d078);
    ecx <<= 15;
    ecx += memoryAGet32(ds, eax + 0xc);
    ebx = 0x00008000;
    push32(0x00004000);
    push32(ebx);
    push32(ecx);
    indirectCall(cs, edi); // 0000:4072d3
    ecx = memoryAGet32(ds, 0x42d168);
    eax = memoryAGet32(ds, 0x42d170);
    edx = 0x80000000;
    edx >>= cl;
    memoryASet32(ds, eax + 0x8, memoryAGet32(ds, eax + 0x8) | edx);
    eax = memoryAGet32(ds, 0x42d170);
    ecx = memoryAGet32(ds, 0x42d168);
    eax = memoryAGet32(ds, eax + 0x10);
    memoryASet32(ds, eax + ecx * 4 + 0xc4, memoryAGet32(ds, eax + ecx * 4 + 0xc4) & 0x00000000);
    eax = memoryAGet32(ds, 0x42d170);
    eax = memoryAGet32(ds, eax + 0x10);
    memoryASet(ds, eax + 0x43, memoryAGet(ds, eax + 0x43) - 1);
    eax = memoryAGet32(ds, 0x42d170);
    ecx = memoryAGet32(ds, eax + 0x10);
    if (memoryAGet(ds, ecx + 0x43))
        goto loc_407322;
    memoryASet32(ds, eax + 0x4, memoryAGet32(ds, eax + 0x4) & 0xfffffffe);
    eax = memoryAGet32(ds, 0x42d170);
loc_407322: // 0000:407322
    if (memoryAGet32(ds, eax + 0x8) != 0xffffffff)
        goto loc_407394;
    push32(ebx);
    push32(0x00000000);
    push32(memoryAGet32(ds, eax + 0xc));
    indirectCall(cs, edi); // 0000:40732e
    eax = memoryAGet32(ds, 0x42d170);
    push32(memoryAGet32(ds, eax + 0x10));
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x42d17c));
    eax = kernel32::HeapFree(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPVOID>(2)); esp += 12;();
    eax = memoryAGet32(ds, 0x42d174);
    edx = memoryAGet32(ds, 0x42d178);
    eax = eax + (eax * 4);
    eax <<= 2;
    ecx = eax;
    eax = memoryAGet32(ds, 0x42d170);
    ecx -= eax;
    ecx = (ecx + edx) + -20;
    push32(ecx);
    ecx = eax + 20;
    push32(ecx);
    push32(eax);
    sub_409590();
    eax = memoryAGet32(ss, ebp + 0x8);
    esp += 0x0000000c;
    memoryASet32(ds, 0x42d174, memoryAGet32(ds, 0x42d174) - 1);
    if (eax <= memoryAGet32(ds, 0x42d170))
        goto loc_407386;
    eax -= 0x00000014;
loc_407386: // 0000:407386
    ecx = memoryAGet32(ds, 0x42d178);
    memoryASet32(ds, 0x42d16c, ecx);
    goto loc_407397;
loc_407394: // 0000:407394
    eax = memoryAGet32(ss, ebp + 0x8);
loc_407397: // 0000:407397
    memoryASet32(ds, 0x42d170, eax);
    memoryASet32(ds, 0x42d168, esi);
loc_4073a2: // 0000:4073a2
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_4073a7() // 0000:4073a7 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000014;
    eax = memoryAGet32(ds, 0x42d174);
    edx = memoryAGet32(ds, 0x42d178);
    push32(ebx);
    push32(esi);
    eax = eax + (eax * 4);
    push32(edi);
    edi = edx + (eax * 4);
    eax = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ss, ebp - 4, edi);
    ecx = eax + 23;
    ecx &= 0xfffffff0;
    memoryASet32(ss, ebp - 16, ecx);
    ecx = sar32(ecx, 0x04);
    ecx--;
    if ((int32_t)ecx >= (int32_t)0x00000020)
        goto loc_4073e7;
    esi |= 0xffffffff;
    esi >>= cl;
    memoryASet32(ss, ebp - 8, memoryAGet32(ss, ebp - 8) | 0xffffffff);
    memoryASet32(ss, ebp - 12, esi);
    goto loc_4073f7;
loc_4073e7: // 0000:4073e7
    ecx += 0xffffffe0;
    eax |= 0xffffffff;
    esi = 0;
    eax >>= cl;
    memoryASet32(ss, ebp - 12, esi);
    memoryASet32(ss, ebp - 8, eax);
loc_4073f7: // 0000:4073f7
    eax = memoryAGet32(ds, 0x42d16c);
    ebx = eax;
    memoryASet32(ss, ebp + 0x8, ebx);
    if (ebx >= edi)
        goto loc_40741e;
loc_407405: // 0000:407405
    ecx = memoryAGet32(ds, ebx + 0x4);
    edi = memoryAGet32(ds, ebx);
    ecx &= memoryAGet32(ss, ebp - 8);
    edi &= esi;
    ecx |= edi;
    if (ecx)
        goto loc_40741e;
    ebx += 0x00000014;
    memoryASet32(ss, ebp + 0x8, ebx);
    if (ebx < memoryAGet32(ss, ebp - 4))
        goto loc_407405;
loc_40741e: // 0000:40741e
    if (ebx != memoryAGet32(ss, ebp - 4))
        goto loc_40749c;
    ebx = edx;
loc_407425: // 0000:407425
    flags.zero = ebx == eax;
    memoryASet32(ss, ebp + 0x8, ebx);
    if (ebx >= eax)
        goto loc_407441;
    ecx = memoryAGet32(ds, ebx + 0x4);
    edi = memoryAGet32(ds, ebx);
    ecx &= memoryAGet32(ss, ebp - 8);
    edi &= esi;
    ecx |= edi;
    if (ecx)
        goto loc_40743f;
    ebx += 0x00000014;
    goto loc_407425;
loc_40743f: // 0000:40743f
    flags.zero = ebx == eax;
loc_407441: // 0000:407441
    if (!flags.zero)
        goto loc_40749c;
loc_407443: // 0000:407443
    flags.zero = ebx == memoryAGet32(ss, ebp - 4);
    if (ebx >= memoryAGet32(ss, ebp - 4))
        goto loc_407459;
    if (memoryAGet32(ds, ebx + 0x8))
        goto loc_407456;
    ebx += 0x00000014;
    memoryASet32(ss, ebp + 0x8, ebx);
    goto loc_407443;
loc_407456: // 0000:407456
    flags.zero = ebx == memoryAGet32(ss, ebp - 4);
loc_407459: // 0000:407459
    if (!flags.zero)
        goto loc_407481;
    ebx = edx;
loc_40745d: // 0000:40745d
    flags.zero = ebx == eax;
    memoryASet32(ss, ebp + 0x8, ebx);
    if (ebx >= eax)
        goto loc_407471;
    if (memoryAGet32(ds, ebx + 0x8))
        goto loc_40746f;
    ebx += 0x00000014;
    goto loc_40745d;
loc_40746f: // 0000:40746f
    flags.zero = ebx == eax;
loc_407471: // 0000:407471
    if (!flags.zero)
        goto loc_407481;
    sub_4076b0();
    ebx = eax;
    memoryASet32(ss, ebp + 0x8, ebx);
    if (!ebx)
        goto loc_407495;
loc_407481: // 0000:407481
    push32(ebx);
    sub_407761();
    ecx = pop32();
    ecx = memoryAGet32(ds, ebx + 0x10);
    memoryASet32(ds, ecx, eax);
    eax = memoryAGet32(ds, ebx + 0x10);
    if (memoryAGet32(ds, eax) != 0xffffffff)
        goto loc_40749c;
loc_407495: // 0000:407495
    eax = 0;
    goto loc_4076ab;
loc_40749c: // 0000:40749c
    memoryASet32(ds, 0x42d16c, ebx);
    eax = memoryAGet32(ds, ebx + 0x10);
    edx = memoryAGet32(ds, eax);
    memoryASet32(ss, ebp - 4, edx);
    if (edx == 0xffffffff)
        goto loc_4074c3;
    ecx = memoryAGet32(ds, eax + edx * 4 + 0xc4);
    edi = memoryAGet32(ds, eax + edx * 4 + 0x44);
    ecx &= memoryAGet32(ss, ebp - 8);
    edi &= esi;
    ecx |= edi;
    if (ecx)
        goto loc_4074fa;
loc_4074c3: // 0000:4074c3
    edx = memoryAGet32(ds, eax + 0xc4);
    esi = memoryAGet32(ds, eax + 0x44);
    edx &= memoryAGet32(ss, ebp - 8);
    esi &= memoryAGet32(ss, ebp - 12);
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) & 0x00000000);
    ecx = eax + 68;
    flags.zero = !(edx | esi);
    edx |= esi;
    esi = memoryAGet32(ss, ebp - 12);
    if (!flags.zero)
        goto loc_4074f7;
loc_4074e0: // 0000:4074e0
    edx = memoryAGet32(ds, ecx + 0x84);
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) + 1);
    edx &= memoryAGet32(ss, ebp - 8);
    ecx += 0x00000004;
    edi = esi;
    edi &= memoryAGet32(ds, ecx);
    edx |= edi;
    if (!edx)
        goto loc_4074e0;
loc_4074f7: // 0000:4074f7
    edx = memoryAGet32(ss, ebp - 4);
loc_4074fa: // 0000:4074fa
    ecx = edx;
    edi = 0;
    ecx = (int32_t)ecx * (int32_t)0x00000204;
    ecx = (ecx + eax) + 324;
    memoryASet32(ss, ebp - 12, ecx);
    ecx = memoryAGet32(ds, eax + edx * 4 + 0x44);
    ecx &= esi;
    if (ecx)
        goto loc_407523;
    ecx = memoryAGet32(ds, eax + edx * 4 + 0xc4);
    push32(0x00000020);
    ecx &= memoryAGet32(ss, ebp - 8);
    edi = pop32();
loc_407523: // 0000:407523
    if ((int32_t)ecx < 0)
        goto loc_40752c;
    ecx <<= 1;
    edi++;
    goto loc_407523;
loc_40752c: // 0000:40752c
    ecx = memoryAGet32(ss, ebp - 12);
    edx = memoryAGet32(ds, ecx + edi * 8 + 0x4);
    ecx = memoryAGet32(ds, edx);
    ecx -= memoryAGet32(ss, ebp - 16);
    esi = ecx;
    memoryASet32(ss, ebp - 8, ecx);
    esi = sar32(esi, 0x04);
    esi--;
    if ((int32_t)esi <= (int32_t)0x0000003f)
        goto loc_407549;
    push32(0x0000003f);
    esi = pop32();
loc_407549: // 0000:407549
    if (esi == edi)
        goto loc_40765e;
    ecx = memoryAGet32(ds, edx + 0x4);
    if (ecx != memoryAGet32(ds, edx + 0x8))
        goto loc_4075ba;
    if ((int32_t)edi >= (int32_t)0x00000020)
        goto loc_407589;
    ebx = 0x80000000;
    ecx = edi;
    ebx >>= cl;
    ecx = memoryAGet32(ss, ebp - 4);
    edi = (eax + edi) + 4;
    ebx = ~ebx;
    memoryASet32(ss, ebp - 20, ebx);
    ebx &= memoryAGet32(ds, eax + ecx * 4 + 0x44);
    memoryASet32(ds, eax + ecx * 4 + 0x44, ebx);
    memoryASet(ds, edi, memoryAGet(ds, edi) - 1);
    if (memoryAGet(ds, edi))
        goto loc_4075b7;
    ebx = memoryAGet32(ss, ebp + 0x8);
    ecx = memoryAGet32(ss, ebp - 20);
    memoryASet32(ds, ebx, memoryAGet32(ds, ebx) & ecx);
    goto loc_4075ba;
loc_407589: // 0000:407589
    ecx = edi - 32;
    ebx = 0x80000000;
    ebx >>= cl;
    ecx = memoryAGet32(ss, ebp - 4);
    edi = (eax + edi) + 4;
    ecx = (eax + (ecx * 4)) + 196;
    ebx = ~ebx;
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) & ebx);
    memoryASet(ds, edi, memoryAGet(ds, edi) - 1);
    memoryASet32(ss, ebp - 20, ebx);
    if (memoryAGet(ds, edi))
        goto loc_4075b7;
    ebx = memoryAGet32(ss, ebp + 0x8);
    ecx = memoryAGet32(ss, ebp - 20);
    memoryASet32(ds, ebx + 0x4, memoryAGet32(ds, ebx + 0x4) & ecx);
    goto loc_4075ba;
loc_4075b7: // 0000:4075b7
    ebx = memoryAGet32(ss, ebp + 0x8);
loc_4075ba: // 0000:4075ba
    ecx = memoryAGet32(ds, edx + 0x8);
    edi = memoryAGet32(ds, edx + 0x4);
    memoryASet32(ds, ecx + 0x4, edi);
    ecx = memoryAGet32(ds, edx + 0x4);
    edi = memoryAGet32(ds, edx + 0x8);
    memoryASet32(ds, ecx + 0x8, edi);
    if (!memoryAGet32(ss, ebp - 8))
        goto loc_40766a;
    ecx = memoryAGet32(ss, ebp - 12);
    edi = memoryAGet32(ds, ecx + esi * 8 + 0x4);
    ecx = ecx + (esi * 8);
    memoryASet32(ds, edx + 0x4, edi);
    memoryASet32(ds, edx + 0x8, ecx);
    memoryASet32(ds, ecx + 0x4, edx);
    ecx = memoryAGet32(ds, edx + 0x4);
    memoryASet32(ds, ecx + 0x8, edx);
    ecx = memoryAGet32(ds, edx + 0x4);
    if (ecx != memoryAGet32(ds, edx + 0x8))
        goto loc_40765b;
    cl = memoryAGet(ds, esi + eax + 0x4);
    memoryASet(ss, ebp + 0xb, cl);
    if ((int32_t)esi >= (int32_t)0x00000020)
        goto loc_40762c;
    cl++;
    memoryASet(ds, esi + eax + 0x4, cl);
    if (memoryAGet(ss, ebp + 0xb))
        goto loc_40761a;
    edi = 0x80000000;
    ecx = esi;
    edi >>= cl;
    memoryASet32(ds, ebx, memoryAGet32(ds, ebx) | edi);
loc_40761a: // 0000:40761a
    edi = 0x80000000;
    ecx = esi;
    edi >>= cl;
    ecx = memoryAGet32(ss, ebp - 4);
    memoryASet32(ds, eax + ecx * 4 + 0x44, memoryAGet32(ds, eax + ecx * 4 + 0x44) | edi);
    goto loc_40765b;
loc_40762c: // 0000:40762c
    cl++;
    memoryASet(ds, esi + eax + 0x4, cl);
    if (memoryAGet(ss, ebp + 0xb))
        goto loc_407645;
    ecx = esi - 32;
    edi = 0x80000000;
    edi >>= cl;
    memoryASet32(ds, ebx + 0x4, memoryAGet32(ds, ebx + 0x4) | edi);
loc_407645: // 0000:407645
    ecx = memoryAGet32(ss, ebp - 4);
    edi = (eax + (ecx * 4)) + 196;
    ecx = esi - 32;
    esi = 0x80000000;
    esi >>= cl;
    memoryASet32(ds, edi, memoryAGet32(ds, edi) | esi);
loc_40765b: // 0000:40765b
    ecx = memoryAGet32(ss, ebp - 8);
loc_40765e: // 0000:40765e
    if (!ecx)
        goto loc_40766d;
    memoryASet32(ds, edx, ecx);
    memoryASet32(ds, ecx + edx - 4, ecx);
    goto loc_40766d;
loc_40766a: // 0000:40766a
    ecx = memoryAGet32(ss, ebp - 8);
loc_40766d: // 0000:40766d
    esi = memoryAGet32(ss, ebp - 16);
    edx += ecx;
    ecx = esi + 1;
    memoryASet32(ds, edx, ecx);
    memoryASet32(ds, edx + esi - 4, ecx);
    esi = memoryAGet32(ss, ebp - 12);
    ecx = memoryAGet32(ds, esi);
    edi = ecx + 1;
    memoryASet32(ds, esi, edi);
    if (ecx)
        goto loc_4076a3;
    if (ebx != memoryAGet32(ds, 0x42d170))
        goto loc_4076a3;
    ecx = memoryAGet32(ss, ebp - 4);
    if (ecx != memoryAGet32(ds, 0x42d168))
        goto loc_4076a3;
    memoryASet32(ds, 0x42d170, memoryAGet32(ds, 0x42d170) & 0x00000000);
loc_4076a3: // 0000:4076a3
    ecx = memoryAGet32(ss, ebp - 4);
    memoryASet32(ds, eax, ecx);
    eax = edx + 4;
loc_4076ab: // 0000:4076ab
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_4076b0() // 0000:4076b0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x42d174);
    ecx = memoryAGet32(ds, 0x42d164);
    push32(esi);
    push32(edi);
    edi = 0;
    if (eax != ecx)
        goto loc_4076f3;
    eax = (ecx + (ecx * 4)) + 80;
    eax <<= 2;
    push32(eax);
    push32(memoryAGet32(ds, 0x42d178));
    push32(edi);
    push32(memoryAGet32(ds, 0x42d17c));
    eax = kernel32::HeapReAlloc(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPVOID>(2), stack32<SIZE_T>(3)); esp += 16;();
    if (eax == edi)
        goto loc_407743;
    memoryASet32(ds, 0x42d164, memoryAGet32(ds, 0x42d164) + 0x00000010);
    memoryASet32(ds, 0x42d178, eax);
    eax = memoryAGet32(ds, 0x42d174);
loc_4076f3: // 0000:4076f3
    ecx = memoryAGet32(ds, 0x42d178);
    push32(0x000041c4);
    push32(0x00000008);
    eax = eax + (eax * 4);
    push32(memoryAGet32(ds, 0x42d17c));
    esi = ecx + (eax * 4);
    eax = kernel32::HeapAlloc(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<SIZE_T>(2)); esp += 12;();
    memoryASet32(ds, esi + 0x10, eax);
    if (eax == edi)
        goto loc_407743;
    push32(0x00000004);
    push32(0x00002000);
    push32(0x00100000);
    push32(edi);
    eax = kernel32::VirtualAlloc(stack32<LPVOID>(0), stack32<SIZE_T>(1), stack32<DWORD>(2), stack32<DWORD>(3)); esp += 16;();
    memoryASet32(ds, esi + 0xc, eax);
    if (eax != edi)
        goto loc_407747;
    push32(memoryAGet32(ds, esi + 0x10));
    push32(edi);
    push32(memoryAGet32(ds, 0x42d17c));
    eax = kernel32::HeapFree(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPVOID>(2)); esp += 12;();
loc_407743: // 0000:407743
    eax = 0;
    goto loc_40775e;
loc_407747: // 0000:407747
    memoryASet32(ds, esi + 0x8, memoryAGet32(ds, esi + 0x8) | 0xffffffff);
    memoryASet32(ds, esi, edi);
    memoryASet32(ds, esi + 0x4, edi);
    memoryASet32(ds, 0x42d174, memoryAGet32(ds, 0x42d174) + 1);
    eax = memoryAGet32(ds, esi + 0x10);
    memoryASet32(ds, eax, memoryAGet32(ds, eax) | 0xffffffff);
    eax = esi;
loc_40775e: // 0000:40775e
    edi = pop32();
    esi = pop32();
    esp += 4;
}
void sub_407761() // 0000:407761 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ecx);
    ecx = memoryAGet32(ss, ebp + 0x8);
    push32(ebx);
    push32(esi);
    push32(edi);
    esi = memoryAGet32(ds, ecx + 0x10);
    eax = memoryAGet32(ds, ecx + 0x8);
    ebx = 0;
loc_407773: // 0000:407773
    if ((int32_t)eax < 0)
        goto loc_40777c;
    eax <<= 1;
    ebx++;
    goto loc_407773;
loc_40777c: // 0000:40777c
    eax = ebx;
    push32(0x0000003f);
    eax = (int32_t)eax * (int32_t)0x00000204;
    edx = pop32();
    eax = (eax + esi) + 324;
    memoryASet32(ss, ebp - 4, eax);
loc_407791: // 0000:407791
    memoryASet32(ds, eax + 0x8, eax);
    memoryASet32(ds, eax + 0x4, eax);
    eax += 0x00000008;
    edx--;
    if (edx)
        goto loc_407791;
    edi = ebx;
    push32(0x00000004);
    edi <<= 15;
    edi += memoryAGet32(ds, ecx + 0xc);
    push32(0x00001000);
    push32(0x00008000);
    push32(edi);
    eax = kernel32::VirtualAlloc(stack32<LPVOID>(0), stack32<SIZE_T>(1), stack32<DWORD>(2), stack32<DWORD>(3)); esp += 16;();
    if (eax)
        goto loc_4077c4;
    eax |= 0xffffffff;
    goto loc_407857;
loc_4077c4: // 0000:4077c4
    edx = edi + 28672;
    if (edi > edx)
        goto loc_40780a;
    eax = edi + 16;
loc_4077d1: // 0000:4077d1
    memoryASet32(ds, eax - 8, memoryAGet32(ds, eax - 8) | 0xffffffff);
    memoryASet32(ds, eax + 0xfec, memoryAGet32(ds, eax + 0xfec) | 0xffffffff);
    ecx = eax + 4092;
    memoryASet32(ds, eax - 4, 0x00000ff0);
    memoryASet32(ds, eax, ecx);
    ecx = eax - 4100;
    memoryASet32(ds, eax + 0x4, ecx);
    memoryASet32(ds, eax + 0xfe8, 0x00000ff0);
    eax += 0x00001000;
    ecx = eax - 16;
    if (ecx <= edx)
        goto loc_4077d1;
loc_40780a: // 0000:40780a
    eax = memoryAGet32(ss, ebp - 4);
    ecx = edi + 12;
    eax += 0x000001f8;
    push32(0x00000001);
    edi = pop32();
    memoryASet32(ds, eax + 0x4, ecx);
    memoryASet32(ds, ecx + 0x8, eax);
    ecx = edx + 12;
    memoryASet32(ds, eax + 0x8, ecx);
    memoryASet32(ds, ecx + 0x4, eax);
    memoryASet32(ds, esi + ebx * 4 + 0x44, memoryAGet32(ds, esi + ebx * 4 + 0x44) & 0x00000000);
    memoryASet32(ds, esi + ebx * 4 + 0xc4, edi);
    al = memoryAGet(ds, esi + 0x43);
    cl = al;
    cl++;
    flags.zero = al == 0;
    eax = memoryAGet32(ss, ebp + 0x8);
    memoryASet(ds, esi + 0x43, cl);
    if (!flags.zero)
        goto loc_407847;
    memoryASet32(ds, eax + 0x4, memoryAGet32(ds, eax + 0x4) | edi);
loc_407847: // 0000:407847
    edx = 0x80000000;
    ecx = ebx;
    edx >>= cl;
    edx = ~edx;
    memoryASet32(ds, eax + 0x8, memoryAGet32(ds, eax + 0x8) & edx);
    eax = ebx;
loc_407857: // 0000:407857
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_407c9b() // 0000:407c9b +long
{
    esp -= 4;
    push32(0x00030000);
    push32(0x00010000);
    sub_409c3a();
    ecx = pop32();
    ecx = pop32();
    esp += 4;
}
void sub_407ceb() // 0000:407ceb +long
{
    esp -= 4;
    goto loc_407ceb;
loc_407cad: // 0000:407cad
    push32(ebp);
    ebp = esp;
    esp -= 0x00000018;
    fld64(memoryAGet64(ds, 0x40d340));
    memoryASet64(ss, ebp - 8, fstp64());
    fld64(memoryAGet64(ds, 0x40d338));
    memoryASet64(ss, ebp - 16, fstp64());
    fld64(memoryAGet64(ss, ebp - 16));
    fdiv64(memoryAGet64(ss, ebp - 8));
    fmul64(memoryAGet64(ss, ebp - 8));
    fsubr64(memoryAGet64(ss, ebp - 16));
    memoryASet64(ss, ebp - 24, fstp64());
    fld64(memoryAGet64(ss, ebp - 24));
    fcomp64(memoryAGet64(ds, 0x40d1b8));
    ax = fnstsw();
    sahf();
    if (stop("TODO: reads sahf"))
        goto loc_407ce7;
    push32(0x00000001);
    eax = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4; return;
loc_407ce7: // 0000:407ce7
    eax = 0;
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4; return;
loc_407ceb: // 0000:407ceb
    push32(0x0040d364);
    eax = kernel32::GetModuleHandleA(stack32<LPCSTR>(0)); esp += 4;();
    if (!eax)
        goto loc_407d0f;
    push32(0x0040d348);
    push32(eax);
    eax = kernel32::GetProcAddress(stack32<HMODULE>(0), stack32<LPCSTR>(1)); esp += 8;();
    if (!eax)
        goto loc_407d0f;
    push32(0x00000000);
    indirectCall(cs, eax); // 0000:407d0c
    stop("stack_unbalanced");
    esp += 4; return;
loc_407d0f: // 0000:407d0f
    goto loc_407cad;
}
void sub_40814f() // 0000:40814f +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0xc);
    eax = memoryAGet32(ds, esi + 0xc);
    ebx = memoryAGet32(ds, esi + 0x10);
    if (!(al & 0x82))
        goto loc_408258;
    if (al & 0x40)
        goto loc_408258;
    if (!(al & 0x01))
        goto loc_408187;
    memoryASet32(ds, esi + 0x4, memoryAGet32(ds, esi + 0x4) & 0x00000000);
    if (!(al & 0x10))
        goto loc_408258;
    ecx = memoryAGet32(ds, esi + 0x8);
    al &= 0xfe;
    memoryASet32(ds, esi, ecx);
    memoryASet32(ds, esi + 0xc, eax);
loc_408187: // 0000:408187
    eax = memoryAGet32(ds, esi + 0xc);
    memoryASet32(ds, esi + 0x4, memoryAGet32(ds, esi + 0x4) & 0x00000000);
    memoryASet32(ss, ebp + 0xc, memoryAGet32(ss, ebp + 0xc) & 0x00000000);
    al &= 0xef;
    al |= 0x02;
    memoryASet32(ds, esi + 0xc, eax);
    if (ax & 0x010c)
        goto loc_4081c1;
    if (esi == 0x0040f2a0)
        goto loc_4081af;
    if (esi != 0x0040f2c0)
        goto loc_4081ba;
loc_4081af: // 0000:4081af
    push32(ebx);
    sub_40a89f();
    ecx = pop32();
    if (eax)
        goto loc_4081c1;
loc_4081ba: // 0000:4081ba
    push32(esi);
    sub_40a85b();
    ecx = pop32();
loc_4081c1: // 0000:4081c1
    push32(edi);
    if (!(memoryAGet16(ds, esi + 0xc) & 0x0108))
        goto loc_40822e;
    eax = memoryAGet32(ds, esi + 0x8);
    edi = memoryAGet32(ds, esi);
    edi -= eax;
    ecx = eax + 1;
    memoryASet32(ds, esi, ecx);
    ecx = memoryAGet32(ds, esi + 0x18);
    ecx--;
    memoryASet32(ds, esi + 0x4, ecx);
    if ((int32_t)edi <= 0)
        goto loc_4081f1;
    push32(edi);
    push32(eax);
    push32(ebx);
    sub_40a6ae();
    esp += 0x0000000c;
    memoryASet32(ss, ebp + 0xc, eax);
    goto loc_408224;
loc_4081f1: // 0000:4081f1
    if (ebx == 0xffffffff)
        goto loc_40820c;
    eax = ebx;
    ecx = ebx;
    eax = sar32(eax, 0x05);
    ecx &= 0x0000001f;
    eax = memoryAGet32(ds, eax * 4 + 0x42d060);
    eax = eax + (ecx * 8);
    goto loc_408211;
loc_40820c: // 0000:40820c
    eax = 0x0040ef80;
loc_408211: // 0000:408211
    if (!(memoryAGet(ds, eax + 0x4) & 0x20))
        goto loc_408224;
    push32(0x00000002);
    push32(0x00000000);
    push32(ebx);
    sub_40a614();
    esp += 0x0000000c;
loc_408224: // 0000:408224
    eax = memoryAGet32(ds, esi + 0x8);
    cl = memoryAGet(ss, ebp + 0x8);
    memoryASet(ds, eax, cl);
    goto loc_408242;
loc_40822e: // 0000:40822e
    push32(0x00000001);
    eax = ebp + 8;
    edi = pop32();
    push32(edi);
    push32(eax);
    push32(ebx);
    sub_40a6ae();
    esp += 0x0000000c;
    memoryASet32(ss, ebp + 0xc, eax);
loc_408242: // 0000:408242
    flags.zero = memoryAGet32(ss, ebp + 0xc) == edi;
    edi = pop32();
    if (flags.zero)
        goto loc_40824e;
    memoryASet32(ds, esi + 0xc, memoryAGet32(ds, esi + 0xc) | 0x00000020);
    goto loc_40825d;
loc_40824e: // 0000:40824e
    eax = memoryAGet32(ss, ebp + 0x8);
    eax &= 0x000000ff;
    goto loc_408260;
loc_408258: // 0000:408258
    al |= 0x20;
    memoryASet32(ds, esi + 0xc, eax);
loc_40825d: // 0000:40825d
    eax |= 0xffffffff;
loc_408260: // 0000:408260
    esi = pop32();
    ebx = pop32();
    ebp = pop32();
    esp += 4;
}
void sub_408264() // 0000:408264 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000248;
    push32(ebx);
    push32(esi);
    push32(edi);
    edi = memoryAGet32(ss, ebp + 0xc);
    esi = 0;
    bl = memoryAGet(ds, edi);
    edi++;
    memoryASet32(ss, ebp - 12, esi);
    memoryASet32(ss, ebp - 20, esi);
    memoryASet32(ss, ebp + 0xc, edi);
    if (!bl)
        goto loc_40897d;
    ecx = memoryAGet32(ss, ebp - 16);
    edx = 0;
    goto loc_408298;
loc_408290: // 0000:408290
    ecx = memoryAGet32(ss, ebp - 16);
    esi = memoryAGet32(ss, ebp - 48);
    edx = 0;
loc_408298: // 0000:408298
    if ((int32_t)memoryAGet32(ss, ebp - 20) < (int32_t)edx)
        goto loc_40897d;
    if ((int8_t)bl < (int8_t)0x20)
        goto loc_4082b9;
    if ((int8_t)bl > (int8_t)0x78)
        goto loc_4082b9;
    eax = (int8_t)bl;
    al = memoryAGet(ds, eax + 0x40d358);
    eax &= 0x0000000f;
    goto loc_4082bb;
loc_4082b9: // 0000:4082b9
    eax = 0;
loc_4082bb: // 0000:4082bb
    eax = (int8_t)memoryAGet(ds, esi + eax * 8 + 0x40d378);
    eax = sar32(eax, 0x04);
    memoryASet32(ss, ebp - 48, eax);
    if (eax > 0x00000007)
        goto loc_40896c;
    switch (eax)
    {
        case 0: goto loc_408403;
        case 1: goto loc_4082d9;
        case 2: goto loc_4082f4;
        case 3: goto loc_408340;
        case 4: goto loc_408377;
        case 5: goto loc_40837f;
        case 6: goto loc_4083b4;
        case 7: goto loc_408447;
        default:
            stop("ind 0000:4082d2");
    }
loc_4082d9: // 0000:4082d9
    memoryASet32(ss, ebp - 16, memoryAGet32(ss, ebp - 16) | 0xffffffff);
    memoryASet32(ss, ebp - 52, edx);
    memoryASet32(ss, ebp - 40, edx);
    memoryASet32(ss, ebp - 32, edx);
    memoryASet32(ss, ebp - 28, edx);
    memoryASet32(ss, ebp - 4, edx);
    memoryASet32(ss, ebp - 36, edx);
    goto loc_40896c;
loc_4082f4: // 0000:4082f4
    eax = (int8_t)bl;
    eax -= 0x00000020;
    if (!eax)
        goto loc_408337;
    eax -= 0x00000003;
    if (!eax)
        goto loc_40832e;
    eax -= 0x00000008;
    if (!eax)
        goto loc_408325;
    eax--;
    eax--;
    if (!eax)
        goto loc_40831c;
    eax -= 0x00000003;
    if (eax)
        goto loc_40896c;
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0x00000008);
    goto loc_40896c;
loc_40831c: // 0000:40831c
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0x00000004);
    goto loc_40896c;
loc_408325: // 0000:408325
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0x00000001);
    goto loc_40896c;
loc_40832e: // 0000:40832e
    memoryASet(ss, ebp - 4, memoryAGet(ss, ebp - 4) | 0x80);
    goto loc_40896c;
loc_408337: // 0000:408337
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0x00000002);
    goto loc_40896c;
loc_408340: // 0000:408340
    if (bl != 0x2a)
        goto loc_408368;
    eax = ebp + 16;
    push32(eax);
    sub_408a43();
    ecx = pop32();
    memoryASet32(ss, ebp - 32, eax);
    if ((int32_t)eax >= 0)
        goto loc_40896c;
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0x00000004);
    eax = -eax;
loc_408360: // 0000:408360
    memoryASet32(ss, ebp - 32, eax);
    goto loc_40896c;
loc_408368: // 0000:408368
    eax = memoryAGet32(ss, ebp - 32);
    ecx = (int8_t)bl;
    eax = eax + (eax * 4);
    eax = (ecx + (eax * 2)) + -48;
    goto loc_408360;
loc_408377: // 0000:408377
    memoryASet32(ss, ebp - 16, edx);
    goto loc_40896c;
loc_40837f: // 0000:40837f
    if (bl != 0x2a)
        goto loc_4083a2;
    eax = ebp + 16;
    push32(eax);
    sub_408a43();
    ecx = pop32();
    memoryASet32(ss, ebp - 16, eax);
    if ((int32_t)eax >= 0)
        goto loc_40896c;
    memoryASet32(ss, ebp - 16, memoryAGet32(ss, ebp - 16) | 0xffffffff);
    goto loc_40896c;
loc_4083a2: // 0000:4083a2
    eax = ecx + (ecx * 4);
    ecx = (int8_t)bl;
    eax = (ecx + (eax * 2)) + -48;
    memoryASet32(ss, ebp - 16, eax);
    goto loc_40896c;
loc_4083b4: // 0000:4083b4
    if (bl == 0x49)
        goto loc_4083e7;
    if (bl == 0x68)
        goto loc_4083de;
    if (bl == 0x6c)
        goto loc_4083d5;
    if (bl != 0x77)
        goto loc_40896c;
    memoryASet(ss, ebp - 3, memoryAGet(ss, ebp - 3) | 0x08);
    goto loc_40896c;
loc_4083d5: // 0000:4083d5
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0x00000010);
    goto loc_40896c;
loc_4083de: // 0000:4083de
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0x00000020);
    goto loc_40896c;
loc_4083e7: // 0000:4083e7
    if (memoryAGet(ds, edi) != 0x36)
        goto loc_408400;
    if (memoryAGet(ds, edi + 0x1) != 0x34)
        goto loc_408400;
    edi++;
    edi++;
    memoryASet(ss, ebp - 3, memoryAGet(ss, ebp - 3) | 0x80);
    memoryASet32(ss, ebp + 0xc, edi);
    goto loc_40896c;
loc_408400: // 0000:408400
    memoryASet32(ss, ebp - 48, edx);
loc_408403: // 0000:408403
    ecx = memoryAGet32(ds, 0x40f03c);
    memoryASet32(ss, ebp - 36, edx);
    eax = bl;
    if (!(memoryAGet(ds, ecx + eax * 2 + 0x1) & 0x80))
        goto loc_40842f;
    eax = ebp - 20;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    eax = (int8_t)bl;
    push32(eax);
    sub_4089a5();
    bl = memoryAGet(ds, edi);
    esp += 0x0000000c;
    edi++;
    memoryASet32(ss, ebp + 0xc, edi);
loc_40842f: // 0000:40842f
    eax = ebp - 20;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    eax = (int8_t)bl;
    push32(eax);
    sub_4089a5();
    esp += 0x0000000c;
    goto loc_40896c;
loc_408447: // 0000:408447
    eax = (int8_t)bl;
    if ((int32_t)eax > (int32_t)0x00000067)
        goto loc_40866f;
    if ((int32_t)eax >= (int32_t)0x00000065)
        goto loc_4084f2;
    if ((int32_t)eax > (int32_t)0x00000058)
        goto loc_408550;
    if (eax == 0x00000058)
        goto loc_4086e3;
    eax -= 0x00000043;
    if (!eax)
        goto loc_408513;
    eax--;
    eax--;
    if (!eax)
        goto loc_4084e8;
    eax--;
    eax--;
    if (!eax)
        goto loc_4084e8;
    eax -= 0x0000000c;
    if (eax)
        goto loc_40886e;
    if (memoryAGet16(ss, ebp - 4) & 0x0830)
        goto loc_408491;
    memoryASet(ss, ebp - 3, memoryAGet(ss, ebp - 3) | 0x08);
loc_408491: // 0000:408491
    esi = memoryAGet32(ss, ebp - 16);
    if (esi != 0xffffffff)
        goto loc_40849e;
    esi = 0x7fffffff;
loc_40849e: // 0000:40849e
    eax = ebp + 16;
    push32(eax);
    sub_408a43();
    ecx = pop32();
    ecx = eax;
    memoryASet32(ss, ebp - 8, ecx);
    if (!(memoryAGet16(ss, ebp - 4) & 0x0810))
        goto loc_4086b7;
    if (ecx)
        goto loc_4084c6;
    ecx = memoryAGet32(ds, 0x40eef4);
    memoryASet32(ss, ebp - 8, ecx);
loc_4084c6: // 0000:4084c6
    memoryASet32(ss, ebp - 36, 0x00000001);
    eax = ecx;
loc_4084cf: // 0000:4084cf
    edx = esi;
    esi--;
    if (!edx)
        goto loc_4086ae;
    if (!memoryAGet16(ds, eax))
        goto loc_4086ae;
    eax++;
    eax++;
    goto loc_4084cf;
loc_4084e8: // 0000:4084e8
    memoryASet32(ss, ebp - 52, 0x00000001);
    bl += 0x20;
loc_4084f2: // 0000:4084f2
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0x00000040);
    edi = ebp - 584;
    memoryASet32(ss, ebp - 8, edi);
    if ((int32_t)ecx >= (int32_t)edx)
        goto loc_4085d6;
    memoryASet32(ss, ebp - 16, 0x00000006);
    goto loc_4085e4;
loc_408513: // 0000:408513
    if (memoryAGet16(ss, ebp - 4) & 0x0830)
        goto loc_40851f;
    memoryASet(ss, ebp - 3, memoryAGet(ss, ebp - 3) | 0x08);
loc_40851f: // 0000:40851f
    eax = ebp + 16;
    push32(eax);
    if (!(memoryAGet16(ss, ebp - 4) & 0x0810))
        goto loc_408566;
    sub_408a60();
    push32(eax);
    eax = ebp - 584;
    push32(eax);
    sub_40a97e();
    esp += 0x0000000c;
    memoryASet32(ss, ebp - 12, eax);
    if ((int32_t)eax >= 0)
        goto loc_408579;
    memoryASet32(ss, ebp - 40, 0x00000001);
    goto loc_408579;
loc_408550: // 0000:408550
    eax -= 0x0000005a;
    if (!eax)
        goto loc_408587;
    eax -= 0x00000009;
    if (!eax)
        goto loc_40851f;
    eax--;
    if (!eax)
        goto loc_408749;
    goto loc_40886e;
loc_408566: // 0000:408566
    sub_408a43();
    ecx = pop32();
    memoryASet(ss, ebp - 584, al);
    memoryASet32(ss, ebp - 12, 0x00000001);
loc_408579: // 0000:408579
    eax = ebp - 584;
    memoryASet32(ss, ebp - 8, eax);
    goto loc_40886e;
loc_408587: // 0000:408587
    eax = ebp + 16;
    push32(eax);
    sub_408a43();
    ecx = pop32();
    if (!eax)
        goto loc_4085c8;
    ecx = memoryAGet32(ds, eax + 0x4);
    if (!ecx)
        goto loc_4085c8;
    if (!(memoryAGet(ss, ebp - 3) & 0x08))
        goto loc_4085b9;
    eax = (int16_t)memoryAGet16(ds, eax);
    eax >>= 1;
    memoryASet32(ss, ebp - 8, ecx);
    memoryASet32(ss, ebp - 12, eax);
    memoryASet32(ss, ebp - 36, 0x00000001);
    goto loc_40886e;
loc_4085b9: // 0000:4085b9
    memoryASet32(ss, ebp - 36, memoryAGet32(ss, ebp - 36) & 0x00000000);
    memoryASet32(ss, ebp - 8, ecx);
    eax = (int16_t)memoryAGet16(ds, eax);
    goto loc_40886b;
loc_4085c8: // 0000:4085c8
    eax = memoryAGet32(ds, 0x40eef0);
    memoryASet32(ss, ebp - 8, eax);
    push32(eax);
    goto loc_408664;
loc_4085d6: // 0000:4085d6
    if (ecx != edx)
        goto loc_4085e4;
    if (bl != 0x67)
        goto loc_4085e4;
    memoryASet32(ss, ebp - 16, 0x00000001);
loc_4085e4: // 0000:4085e4
    eax = memoryAGet32(ss, ebp + 0x10);
    push32(memoryAGet32(ss, ebp - 52));
    eax += 0x00000008;
    memoryASet32(ss, ebp + 0x10, eax);
    push32(memoryAGet32(ss, ebp - 16));
    ecx = memoryAGet32(ds, eax - 8);
    memoryASet32(ss, ebp - 72, ecx);
    eax = memoryAGet32(ds, eax - 4);
    memoryASet32(ss, ebp - 68, eax);
    eax = (int8_t)bl;
    push32(eax);
    eax = ebp - 584;
    push32(eax);
    eax = ebp - 72;
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x40eed8)); // 0000:40860e
    esi = memoryAGet32(ss, ebp - 4);
    esp += 0x00000014;
    esi &= 0x00000080;
    if (!esi)
        goto loc_408636;
    if (memoryAGet32(ss, ebp - 16))
        goto loc_408636;
    eax = ebp - 584;
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x40eee4)); // 0000:40862f
    ecx = pop32();
loc_408636: // 0000:408636
    if (bl != 0x67)
        goto loc_40864d;
    if (esi)
        goto loc_40864d;
    eax = ebp - 584;
    push32(eax);
    indirectCall(cs, memoryAGet32(ds, 0x40eedc)); // 0000:408646
    ecx = pop32();
loc_40864d: // 0000:40864d
    if (memoryAGet(ss, ebp - 584) != 0x2d)
        goto loc_408663;
    memoryASet(ss, ebp - 3, memoryAGet(ss, ebp - 3) | 0x01);
    edi = ebp - 583;
    memoryASet32(ss, ebp - 8, edi);
loc_408663: // 0000:408663
    push32(edi);
loc_408664: // 0000:408664
    sub_40a590();
    ecx = pop32();
    goto loc_40886b;
loc_40866f: // 0000:40866f
    eax -= 0x00000069;
    if (!eax)
        goto loc_408749;
    eax -= 0x00000005;
    if (!eax)
        goto loc_40871f;
    eax--;
    if (!eax)
        goto loc_40870c;
    eax--;
    if (!eax)
        goto loc_4086dc;
    eax -= 0x00000003;
    if (!eax)
        goto loc_408491;
    eax--;
    eax--;
    if (!eax)
        goto loc_40874d;
    eax -= 0x00000003;
    if (eax)
        goto loc_40886e;
    memoryASet32(ss, ebp - 44, 0x00000027);
    goto loc_4086ea;
loc_4086ae: // 0000:4086ae
    eax -= ecx;
    eax = sar32(eax, 0x00000001);
    goto loc_40886b;
loc_4086b7: // 0000:4086b7
    if (ecx)
        goto loc_4086c4;
    ecx = memoryAGet32(ds, 0x40eef0);
    memoryASet32(ss, ebp - 8, ecx);
loc_4086c4: // 0000:4086c4
    eax = ecx;
loc_4086c6: // 0000:4086c6
    edx = esi;
    esi--;
    if (!edx)
        goto loc_4086d5;
    if (!memoryAGet(ds, eax))
        goto loc_4086d5;
    eax++;
    goto loc_4086c6;
loc_4086d5: // 0000:4086d5
    eax -= ecx;
    goto loc_40886b;
loc_4086dc: // 0000:4086dc
    memoryASet32(ss, ebp - 16, 0x00000008);
loc_4086e3: // 0000:4086e3
    memoryASet32(ss, ebp - 44, 0x00000007);
loc_4086ea: // 0000:4086ea
    memoryASet32(ss, ebp - 12, 0x00000010);
    if (!(memoryAGet(ss, ebp - 4) & 0x80))
        goto loc_408754;
    al = memoryAGet(ss, ebp - 44);
    memoryASet(ss, ebp - 22, 0x30);
    al += 0x51;
    memoryASet32(ss, ebp - 28, 0x00000002);
    memoryASet(ss, ebp - 21, al);
    goto loc_408754;
loc_40870c: // 0000:40870c
    memoryASet32(ss, ebp - 12, 0x00000008);
    if (!(memoryAGet(ss, ebp - 4) & 0x80))
        goto loc_408754;
    memoryASet(ss, ebp - 3, memoryAGet(ss, ebp - 3) | 0x02);
    goto loc_408754;
loc_40871f: // 0000:40871f
    eax = ebp + 16;
    push32(eax);
    sub_408a43();
    ecx = pop32();
    if (!(memoryAGet(ss, ebp - 4) & 0x20))
        goto loc_408738;
    cx = memoryAGet16(ss, ebp - 20);
    memoryASet16(ds, eax, cx);
    goto loc_40873d;
loc_408738: // 0000:408738
    ecx = memoryAGet32(ss, ebp - 20);
    memoryASet32(ds, eax, ecx);
loc_40873d: // 0000:40873d
    memoryASet32(ss, ebp - 40, 0x00000001);
    goto loc_40896c;
loc_408749: // 0000:408749
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0x00000040);
loc_40874d: // 0000:40874d
    memoryASet32(ss, ebp - 12, 0x0000000a);
loc_408754: // 0000:408754
    if (!(memoryAGet(ss, ebp - 3) & 0x80))
        goto loc_408766;
    eax = ebp + 16;
    push32(eax);
    sub_408a50();
    ecx = pop32();
    goto loc_4087a7;
loc_408766: // 0000:408766
    if (!(memoryAGet(ss, ebp - 4) & 0x20))
        goto loc_40878d;
    eax = ebp + 16;
    push32(eax);
    if (!(memoryAGet(ss, ebp - 4) & 0x40))
        goto loc_408782;
    sub_408a43();
    ecx = pop32();
    eax = (int16_t)ax;
loc_40877f: // 0000:40877f
    edx = (int32_t)eax < 0 ? -1 : 0;
    goto loc_4087a7;
loc_408782: // 0000:408782
    sub_408a43();
    ecx = pop32();
    eax = ax;
    goto loc_40877f;
loc_40878d: // 0000:40878d
    eax = ebp + 16;
    push32(eax);
    if (!(memoryAGet(ss, ebp - 4) & 0x40))
        goto loc_40879f;
    sub_408a43();
    ecx = pop32();
    goto loc_40877f;
loc_40879f: // 0000:40879f
    sub_408a43();
    ecx = pop32();
    edx = 0;
loc_4087a7: // 0000:4087a7
    if (!(memoryAGet(ss, ebp - 4) & 0x40))
        goto loc_4087c8;
    if ((int32_t)edx > 0)
        goto loc_4087c8;
    if ((int32_t)edx < 0)
        goto loc_4087b7;
    if (true)
        goto loc_4087c8;
loc_4087b7: // 0000:4087b7
    flags.carry = eax != 0;
    eax = -eax;
    edx += (0x00000000 + flags.carry);
    esi = eax;
    edx = -edx;
    memoryASet(ss, ebp - 3, memoryAGet(ss, ebp - 3) | 0x01);
    edi = edx;
    goto loc_4087cc;
loc_4087c8: // 0000:4087c8
    esi = eax;
    edi = edx;
loc_4087cc: // 0000:4087cc
    if (memoryAGet(ss, ebp - 3) & 0x80)
        goto loc_4087d5;
    edi &= 0x00000000;
loc_4087d5: // 0000:4087d5
    if ((int32_t)memoryAGet32(ss, ebp - 16) >= 0x00000000)
        goto loc_4087e4;
    memoryASet32(ss, ebp - 16, 0x00000001);
    goto loc_4087e8;
loc_4087e4: // 0000:4087e4
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) & 0xfffffff7);
loc_4087e8: // 0000:4087e8
    eax = esi;
    eax |= edi;
    if (eax)
        goto loc_4087f2;
    memoryASet32(ss, ebp - 28, memoryAGet32(ss, ebp - 28) & 0x00000000);
loc_4087f2: // 0000:4087f2
    eax = ebp - 73;
    memoryASet32(ss, ebp - 8, eax);
loc_4087f8: // 0000:4087f8
    eax = memoryAGet32(ss, ebp - 16);
    memoryASet32(ss, ebp - 16, memoryAGet32(ss, ebp - 16) - 1);
    if ((int32_t)eax > 0)
        goto loc_408808;
    eax = esi;
    eax |= edi;
    if (!eax)
        goto loc_408843;
loc_408808: // 0000:408808
    eax = memoryAGet32(ss, ebp - 12);
    edx = (int32_t)eax < 0 ? -1 : 0;
    push32(edx);
    push32(eax);
    push32(edi);
    push32(esi);
    memoryASet32(ss, ebp - 64, eax);
    memoryASet32(ss, ebp - 60, edx);
    sub_40aa60();
    push32(memoryAGet32(ss, ebp - 60));
    ebx = eax;
    ebx += 0x00000030;
    push32(memoryAGet32(ss, ebp - 64));
    push32(edi);
    push32(esi);
    sub_40a9f0();
    esi = eax;
    edi = edx;
    if ((int32_t)ebx <= (int32_t)0x00000039)
        goto loc_408839;
    ebx += memoryAGet32(ss, ebp - 44);
loc_408839: // 0000:408839
    eax = memoryAGet32(ss, ebp - 8);
    memoryASet32(ss, ebp - 8, memoryAGet32(ss, ebp - 8) - 1);
    memoryASet(ds, eax, bl);
    goto loc_4087f8;
loc_408843: // 0000:408843
    eax = ebp - 73;
    eax -= memoryAGet32(ss, ebp - 8);
    memoryASet32(ss, ebp - 8, memoryAGet32(ss, ebp - 8) + 1);
    memoryASet32(ss, ebp - 12, eax);
    if (!(memoryAGet(ss, ebp - 3) & 0x02))
        goto loc_40886e;
    ecx = memoryAGet32(ss, ebp - 8);
    if (memoryAGet(ds, ecx) != 0x30)
        goto loc_408861;
    if (eax)
        goto loc_40886e;
loc_408861: // 0000:408861
    memoryASet32(ss, ebp - 8, memoryAGet32(ss, ebp - 8) - 1);
    eax++;
    ecx = memoryAGet32(ss, ebp - 8);
    memoryASet(ds, ecx, 0x30);
loc_40886b: // 0000:40886b
    memoryASet32(ss, ebp - 12, eax);
loc_40886e: // 0000:40886e
    if (memoryAGet32(ss, ebp - 40))
        goto loc_40896c;
    ebx = memoryAGet32(ss, ebp - 4);
    if (!(bl & 0x40))
        goto loc_4088a6;
    if (!(bh & 0x01))
        goto loc_40888b;
    memoryASet(ss, ebp - 22, 0x2d);
    goto loc_40889f;
loc_40888b: // 0000:40888b
    if (!(bl & 0x01))
        goto loc_408896;
    memoryASet(ss, ebp - 22, 0x2b);
    goto loc_40889f;
loc_408896: // 0000:408896
    if (!(bl & 0x02))
        goto loc_4088a6;
    memoryASet(ss, ebp - 22, 0x20);
loc_40889f: // 0000:40889f
    memoryASet32(ss, ebp - 28, 0x00000001);
loc_4088a6: // 0000:4088a6
    esi = memoryAGet32(ss, ebp - 32);
    esi -= memoryAGet32(ss, ebp - 28);
    esi -= memoryAGet32(ss, ebp - 12);
    if (bl & 0x0c)
        goto loc_4088c6;
    eax = ebp - 20;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(esi);
    push32(0x00000020);
    sub_4089da();
    esp += 0x00000010;
loc_4088c6: // 0000:4088c6
    eax = ebp - 20;
    push32(eax);
    eax = ebp - 22;
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(memoryAGet32(ss, ebp - 28));
    push32(eax);
    sub_408a0b();
    esp += 0x00000010;
    if (!(bl & 0x08))
        goto loc_4088f8;
    if (bl & 0x04)
        goto loc_4088f8;
    eax = ebp - 20;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(esi);
    push32(0x00000030);
    sub_4089da();
    esp += 0x00000010;
loc_4088f8: // 0000:4088f8
    if (!memoryAGet32(ss, ebp - 36))
        goto loc_40893f;
    if ((int32_t)memoryAGet32(ss, ebp - 12) <= 0x00000000)
        goto loc_40893f;
    eax = memoryAGet32(ss, ebp - 12);
    ebx = memoryAGet32(ss, ebp - 8);
    edi = eax - 1;
loc_40890d: // 0000:40890d
    ax = memoryAGet16(ds, ebx);
    ebx++;
    push32(eax);
    eax = ebp - 56;
    push32(eax);
    ebx++;
    sub_40a97e();
    ecx = pop32();
    ecx = pop32();
    if ((int32_t)eax <= 0)
        goto loc_408954;
    ecx = ebp - 20;
    push32(ecx);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(eax);
    eax = ebp - 56;
    push32(eax);
    sub_408a0b();
    esp += 0x00000010;
    eax = edi;
    edi--;
    if (eax)
        goto loc_40890d;
    goto loc_408954;
loc_40893f: // 0000:40893f
    eax = ebp - 20;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(memoryAGet32(ss, ebp - 12));
    push32(memoryAGet32(ss, ebp - 8));
    sub_408a0b();
    esp += 0x00000010;
loc_408954: // 0000:408954
    if (!(memoryAGet(ss, ebp - 4) & 0x04))
        goto loc_40896c;
    eax = ebp - 20;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(esi);
    push32(0x00000020);
    sub_4089da();
    esp += 0x00000010;
loc_40896c: // 0000:40896c
    edi = memoryAGet32(ss, ebp + 0xc);
    bl = memoryAGet(ds, edi);
    edi++;
    memoryASet32(ss, ebp + 0xc, edi);
    if (bl)
        goto loc_408290;
loc_40897d: // 0000:40897d
    eax = memoryAGet32(ss, ebp - 20);
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_4089a5() // 0000:4089a5 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    ecx = memoryAGet32(ss, ebp + 0xc);
    memoryASet32(ds, ecx + 0x4, memoryAGet32(ds, ecx + 0x4) - 1);
    if ((int32_t)memoryAGet32(ds, ecx + 0x4) < 0)
        goto loc_4089be;
    edx = memoryAGet32(ds, ecx);
    al = memoryAGet(ss, ebp + 0x8);
    memoryASet(ds, edx, al);
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
    eax = al;
    goto loc_4089c9;
loc_4089be: // 0000:4089be
    push32(ecx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_40814f();
    ecx = pop32();
    ecx = pop32();
loc_4089c9: // 0000:4089c9
    flags.zero = eax == 0xffffffff;
    eax = memoryAGet32(ss, ebp + 0x10);
    if (!flags.zero)
        goto loc_4089d6;
    memoryASet32(ds, eax, memoryAGet32(ds, eax) | 0xffffffff);
    ebp = pop32();
    esp += 4; return;
loc_4089d6: // 0000:4089d6
    memoryASet32(ds, eax, memoryAGet32(ds, eax) + 1);
    ebp = pop32();
    esp += 4;
}
void sub_4089da() // 0000:4089da +long
{
    esp -= 4;
    push32(esi);
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x10);
    eax = edi;
    edi--;
    if ((int32_t)eax <= 0)
        goto loc_408a08;
    esi = memoryAGet32(ds, esp + 0x18);
loc_4089eb: // 0000:4089eb
    push32(esi);
    push32(memoryAGet32(ds, esp + 0x18));
    push32(memoryAGet32(ds, esp + 0x14));
    sub_4089a5();
    esp += 0x0000000c;
    if (memoryAGet32(ds, esi) == 0xffffffff)
        goto loc_408a08;
    eax = edi;
    edi--;
    if ((int32_t)eax > 0)
        goto loc_4089eb;
loc_408a08: // 0000:408a08
    edi = pop32();
    esi = pop32();
    esp += 4;
}
void sub_408a0b() // 0000:408a0b +long
{
    esp -= 4;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0xc);
    eax = ebx;
    ebx--;
    push32(esi);
    push32(edi);
    if ((int32_t)eax <= 0)
        goto loc_408a3f;
    edi = memoryAGet32(ds, esp + 0x1c);
    esi = memoryAGet32(ds, esp + 0x10);
loc_408a21: // 0000:408a21
    eax = (int8_t)memoryAGet(ds, esi);
    push32(edi);
    esi++;
    push32(memoryAGet32(ds, esp + 0x1c));
    push32(eax);
    sub_4089a5();
    esp += 0x0000000c;
    if (memoryAGet32(ds, edi) == 0xffffffff)
        goto loc_408a3f;
    eax = ebx;
    ebx--;
    if ((int32_t)eax > 0)
        goto loc_408a21;
loc_408a3f: // 0000:408a3f
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp += 4;
}
void sub_408a43() // 0000:408a43 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    memoryASet32(ds, eax, memoryAGet32(ds, eax) + 0x00000004);
    eax = memoryAGet32(ds, eax);
    eax = memoryAGet32(ds, eax - 4);
    esp += 4;
}
void sub_408a50() // 0000:408a50 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    memoryASet32(ds, eax, memoryAGet32(ds, eax) + 0x00000008);
    ecx = memoryAGet32(ds, eax);
    eax = memoryAGet32(ds, ecx - 8);
    edx = memoryAGet32(ds, ecx - 4);
    esp += 4;
}
void sub_408a60() // 0000:408a60 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    memoryASet32(ds, eax, memoryAGet32(ds, eax) + 0x00000004);
    eax = memoryAGet32(ds, eax);
    ax = memoryAGet16(ds, eax - 4);
    esp += 4;
}
void sub_408a6e() // 0000:408a6e +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_408baf();
    ecx = pop32();
    if (!eax)
        goto loc_408ba3;
    ebx = memoryAGet32(ds, eax + 0x8);
    if (!ebx)
        goto loc_408ba3;
    if (ebx != 0x00000005)
        goto loc_408a9f;
    memoryASet32(ds, eax + 0x8, memoryAGet32(ds, eax + 0x8) & 0x00000000);
    push32(0x00000001);
    eax = pop32();
    goto loc_408bac;
loc_408a9f: // 0000:408a9f
    if (ebx == 0x00000001)
        goto loc_408b9e;
    ecx = memoryAGet32(ds, 0x40fb30);
    memoryASet32(ss, ebp + 0x8, ecx);
    ecx = memoryAGet32(ss, ebp + 0xc);
    memoryASet32(ds, 0x40fb30, ecx);
    ecx = memoryAGet32(ds, eax + 0x4);
    if (ecx != 0x00000008)
        goto loc_408b8e;
    ecx = memoryAGet32(ds, 0x40ef70);
    edx = memoryAGet32(ds, 0x40ef74);
    edx += ecx;
    push32(esi);
    if ((int32_t)ecx >= (int32_t)edx)
        goto loc_408aee;
    esi = ecx + (ecx * 2);
    edx -= ecx;
    esi = (esi * 4) + 4255488;
loc_408ae5: // 0000:408ae5
    memoryASet32(ds, esi, memoryAGet32(ds, esi) & 0x00000000);
    esi += 0x0000000c;
    edx--;
    if (edx)
        goto loc_408ae5;
loc_408aee: // 0000:408aee
    eax = memoryAGet32(ds, eax);
    esi = memoryAGet32(ds, 0x40ef7c);
    if (eax != 0xc000008e)
        goto loc_408b09;
    memoryASet32(ds, 0x40ef7c, 0x00000083);
    goto loc_408b79;
loc_408b09: // 0000:408b09
    if (eax != 0xc0000090)
        goto loc_408b1c;
    memoryASet32(ds, 0x40ef7c, 0x00000081);
    goto loc_408b79;
loc_408b1c: // 0000:408b1c
    if (eax != 0xc0000091)
        goto loc_408b2f;
    memoryASet32(ds, 0x40ef7c, 0x00000084);
    goto loc_408b79;
loc_408b2f: // 0000:408b2f
    if (eax != 0xc0000093)
        goto loc_408b42;
    memoryASet32(ds, 0x40ef7c, 0x00000085);
    goto loc_408b79;
loc_408b42: // 0000:408b42
    if (eax != 0xc000008d)
        goto loc_408b55;
    memoryASet32(ds, 0x40ef7c, 0x00000082);
    goto loc_408b79;
loc_408b55: // 0000:408b55
    if (eax != 0xc000008f)
        goto loc_408b68;
    memoryASet32(ds, 0x40ef7c, 0x00000086);
    goto loc_408b79;
loc_408b68: // 0000:408b68
    if (eax != 0xc0000092)
        goto loc_408b79;
    memoryASet32(ds, 0x40ef7c, 0x0000008a);
loc_408b79: // 0000:408b79
    push32(memoryAGet32(ds, 0x40ef7c));
    push32(0x00000008);
    indirectCall(cs, ebx); // 0000:408b81
    ecx = pop32();
    memoryASet32(ds, 0x40ef7c, esi);
    ecx = pop32();
    esi = pop32();
    goto loc_408b96;
loc_408b8e: // 0000:408b8e
    memoryASet32(ds, eax + 0x8, memoryAGet32(ds, eax + 0x8) & 0x00000000);
    push32(ecx);
    indirectCall(cs, ebx); // 0000:408b93
    ecx = pop32();
loc_408b96: // 0000:408b96
    eax = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, 0x40fb30, eax);
loc_408b9e: // 0000:408b9e
    eax |= 0xffffffff;
    goto loc_408bac;
loc_408ba3: // 0000:408ba3
    push32(memoryAGet32(ss, ebp + 0xc));
    eax = kernel32::UnhandledExceptionFilter(stack32<struct _EXCEPTION_POINTERS>(0)); esp += 4;();
loc_408bac: // 0000:408bac
    ebx = pop32();
    ebp = pop32();
    esp += 4;
}
void sub_408baf() // 0000:408baf +long
{
    esp -= 4;
    edx = memoryAGet32(ds, esp + 0x4);
    ecx = memoryAGet32(ds, 0x40ef78);
    push32(esi);
    eax = 0x0040eef8;
    if (memoryAGet32(ds, 0x40eef8) == edx)
        goto loc_408bdc;
    esi = ecx + (ecx * 2);
    esi = (esi * 4) + 4255480;
loc_408bd1: // 0000:408bd1
    eax += 0x0000000c;
    if (eax >= esi)
        goto loc_408bdc;
    if (memoryAGet32(ds, eax) != edx)
        goto loc_408bd1;
loc_408bdc: // 0000:408bdc
    ecx = ecx + (ecx * 2);
    esi = pop32();
    ecx = (ecx * 4) + 4255480;
    if (eax >= ecx)
        goto loc_408bef;
    if (memoryAGet32(ds, eax) == edx)
        goto loc_408bf1;
loc_408bef: // 0000:408bef
    eax = 0;
loc_408bf1: // 0000:408bf1
    esp += 4; return;
}
void sub_408bf2() // 0000:408bf2 +long
{
    esp -= 4;
    if (memoryAGet32(ds, 0x42d188))
        goto loc_408c00;
    sub_40aedb();
loc_408c00: // 0000:408c00
    push32(esi);
    esi = memoryAGet32(ds, 0x42d180);
    al = memoryAGet(ds, esi);
    if (al != 0x22)
        goto loc_408c32;
loc_408c0d: // 0000:408c0d
    al = memoryAGet(ds, esi + 0x1);
    esi++;
    if (al == 0x22)
        goto loc_408c2a;
    if (!al)
        goto loc_408c2a;
    eax = al;
    push32(eax);
    sub_40aad5();
    ecx = pop32();
    if (!eax)
        goto loc_408c0d;
    esi++;
    goto loc_408c0d;
loc_408c2a: // 0000:408c2a
    if (memoryAGet(ds, esi) != 0x22)
        goto loc_408c3c;
loc_408c2f: // 0000:408c2f
    esi++;
    goto loc_408c3c;
loc_408c32: // 0000:408c32
    if (al <= 0x20)
        goto loc_408c3c;
loc_408c36: // 0000:408c36
    esi++;
    if (memoryAGet(ds, esi) > 0x20)
        goto loc_408c36;
loc_408c3c: // 0000:408c3c
    al = memoryAGet(ds, esi);
    if (!al)
        goto loc_408c46;
    if (al <= 0x20)
        goto loc_408c2f;
loc_408c46: // 0000:408c46
    eax = esi;
    esi = pop32();
    esp += 4;
}
void sub_408c4a() // 0000:408c4a +long
{
    esp -= 4;
    push32(ebx);
    ebx = 0;
    push32(esi);
    push32(edi);
    if (memoryAGet32(ds, 0x42d188) != ebx)
        goto loc_408c5c;
    sub_40aedb();
loc_408c5c: // 0000:408c5c
    esi = memoryAGet32(ds, 0x40fb0c);
    edi = 0;
loc_408c64: // 0000:408c64
    al = memoryAGet(ds, esi);
    if (al == bl)
        goto loc_408c7c;
    if (al == 0x3d)
        goto loc_408c6f;
    edi++;
loc_408c6f: // 0000:408c6f
    push32(esi);
    sub_40a590();
    ecx = pop32();
    esi = (esi + eax) + 1;
    goto loc_408c64;
loc_408c7c: // 0000:408c7c
    eax = (edi * 4) + 4;
    push32(eax);
    sub_406b40();
    esi = eax;
    ecx = pop32();
    memoryASet32(ds, 0x40fae0, esi);
    if (esi != ebx)
        goto loc_408c9e;
    push32(0x00000009);
    sub_406f73();
    ecx = pop32();
loc_408c9e: // 0000:408c9e
    edi = memoryAGet32(ds, 0x40fb0c);
    if (memoryAGet(ds, edi) == bl)
        goto loc_408ce1;
    push32(ebp);
loc_408ca9: // 0000:408ca9
    push32(edi);
    sub_40a590();
    ebp = eax;
    ecx = pop32();
    ebp++;
    if (memoryAGet(ds, edi) == 0x3d)
        goto loc_408cda;
    push32(ebp);
    sub_406b40();
    ecx = pop32();
    memoryASet32(ds, esi, eax);
    if (eax != ebx)
        goto loc_408ccd;
    push32(0x00000009);
    sub_406f73();
    ecx = pop32();
loc_408ccd: // 0000:408ccd
    push32(edi);
    push32(memoryAGet32(ds, esi));
    sub_40a2a0();
    ecx = pop32();
    esi += 0x00000004;
    ecx = pop32();
loc_408cda: // 0000:408cda
    edi += ebp;
    if (memoryAGet(ds, edi) != bl)
        goto loc_408ca9;
    ebp = pop32();
loc_408ce1: // 0000:408ce1
    push32(memoryAGet32(ds, 0x40fb0c));
    sub_406bb4();
    ecx = pop32();
    memoryASet32(ds, 0x40fb0c, ebx);
    memoryASet32(ds, esi, ebx);
    edi = pop32();
    esi = pop32();
    memoryASet32(ds, 0x42d184, 0x00000001);
    ebx = pop32();
    esp += 4;
}
void sub_408d03() // 0000:408d03 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ecx);
    push32(ecx);
    push32(ebx);
    ebx = 0;
    push32(esi);
    push32(edi);
    if (memoryAGet32(ds, 0x42d188) != ebx)
        goto loc_408d1a;
    sub_40aedb();
loc_408d1a: // 0000:408d1a
    esi = 0x0040fb34;
    push32(0x00000104);
    push32(esi);
    push32(ebx);
    eax = kernel32::GetModuleFileNameA(stack32<HMODULE>(0), stack32<LPSTR>(1), stack32<DWORD>(2)); esp += 12;();
    eax = memoryAGet32(ds, 0x42d180);
    memoryASet32(ds, 0x40faf0, esi);
    edi = esi;
    if (memoryAGet(ds, eax) == bl)
        goto loc_408d3f;
    edi = eax;
loc_408d3f: // 0000:408d3f
    eax = ebp - 8;
    push32(eax);
    eax = ebp - 4;
    push32(eax);
    push32(ebx);
    push32(ebx);
    push32(edi);
    sub_408d9c();
    eax = memoryAGet32(ss, ebp - 8);
    ecx = memoryAGet32(ss, ebp - 4);
    eax = eax + (ecx * 4);
    push32(eax);
    sub_406b40();
    esi = eax;
    esp += 0x00000018;
    if (esi != ebx)
        goto loc_408d6f;
    push32(0x00000008);
    sub_406f73();
    ecx = pop32();
loc_408d6f: // 0000:408d6f
    eax = ebp - 8;
    push32(eax);
    eax = ebp - 4;
    push32(eax);
    eax = memoryAGet32(ss, ebp - 4);
    eax = esi + (eax * 4);
    push32(eax);
    push32(esi);
    push32(edi);
    sub_408d9c();
    eax = memoryAGet32(ss, ebp - 4);
    esp += 0x00000014;
    eax--;
    memoryASet32(ds, 0x40fad8, esi);
    edi = pop32();
    esi = pop32();
    memoryASet32(ds, 0x40fad4, eax);
    ebx = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_408d9c() // 0000:408d9c +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    ecx = memoryAGet32(ss, ebp + 0x18);
    eax = memoryAGet32(ss, ebp + 0x14);
    push32(ebx);
    push32(esi);
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) & 0x00000000);
    esi = memoryAGet32(ss, ebp + 0x10);
    push32(edi);
    edi = memoryAGet32(ss, ebp + 0xc);
    memoryASet32(ds, eax, 0x00000001);
    eax = memoryAGet32(ss, ebp + 0x8);
    if (!edi)
        goto loc_408dc6;
    memoryASet32(ds, edi, esi);
    edi += 0x00000004;
    memoryASet32(ss, ebp + 0xc, edi);
loc_408dc6: // 0000:408dc6
    if (memoryAGet(ds, eax) != 0x22)
        goto loc_408e0f;
loc_408dcb: // 0000:408dcb
    dl = memoryAGet(ds, eax + 0x1);
    eax++;
    if (dl == 0x22)
        goto loc_408dfd;
    if (!dl)
        goto loc_408dfd;
    edx = dl;
    if (!(memoryAGet(ds, edx + 0x42bf21) & 0x04))
        goto loc_408df0;
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
    if (!esi)
        goto loc_408df0;
    dl = memoryAGet(ds, eax);
    memoryASet(ds, esi, dl);
    esi++;
    eax++;
loc_408df0: // 0000:408df0
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
    if (!esi)
        goto loc_408dcb;
    dl = memoryAGet(ds, eax);
    memoryASet(ds, esi, dl);
    esi++;
    goto loc_408dcb;
loc_408dfd: // 0000:408dfd
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
    if (!esi)
        goto loc_408e07;
    memoryASet(ds, esi, memoryAGet(ds, esi) & 0x00);
    esi++;
loc_408e07: // 0000:408e07
    if (memoryAGet(ds, eax) != 0x22)
        goto loc_408e52;
    eax++;
    goto loc_408e52;
loc_408e0f: // 0000:408e0f
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
    if (!esi)
        goto loc_408e1a;
    dl = memoryAGet(ds, eax);
    memoryASet(ds, esi, dl);
    esi++;
loc_408e1a: // 0000:408e1a
    dl = memoryAGet(ds, eax);
    eax++;
    ebx = dl;
    if (!(memoryAGet(ds, ebx + 0x42bf21) & 0x04))
        goto loc_408e35;
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
    if (!esi)
        goto loc_408e34;
    bl = memoryAGet(ds, eax);
    memoryASet(ds, esi, bl);
    esi++;
loc_408e34: // 0000:408e34
    eax++;
loc_408e35: // 0000:408e35
    if (dl == 0x20)
        goto loc_408e43;
    if (!dl)
        goto loc_408e47;
    if (dl != 0x09)
        goto loc_408e0f;
loc_408e43: // 0000:408e43
    if (dl)
        goto loc_408e4a;
loc_408e47: // 0000:408e47
    eax--;
    goto loc_408e52;
loc_408e4a: // 0000:408e4a
    if (!esi)
        goto loc_408e52;
    memoryASet(ds, esi - 1, memoryAGet(ds, esi - 1) & 0x00);
loc_408e52: // 0000:408e52
    memoryASet32(ss, ebp + 0x18, memoryAGet32(ss, ebp + 0x18) & 0x00000000);
loc_408e56: // 0000:408e56
    if (!memoryAGet(ds, eax))
        goto loc_408f3f;
loc_408e5f: // 0000:408e5f
    dl = memoryAGet(ds, eax);
    if (dl == 0x20)
        goto loc_408e6b;
    if (dl != 0x09)
        goto loc_408e6e;
loc_408e6b: // 0000:408e6b
    eax++;
    goto loc_408e5f;
loc_408e6e: // 0000:408e6e
    if (!memoryAGet(ds, eax))
        goto loc_408f3f;
    if (!edi)
        goto loc_408e83;
    memoryASet32(ds, edi, esi);
    edi += 0x00000004;
    memoryASet32(ss, ebp + 0xc, edi);
loc_408e83: // 0000:408e83
    edx = memoryAGet32(ss, ebp + 0x14);
    memoryASet32(ds, edx, memoryAGet32(ds, edx) + 1);
loc_408e88: // 0000:408e88
    memoryASet32(ss, ebp + 0x8, 0x00000001);
    ebx = 0;
loc_408e91: // 0000:408e91
    if (memoryAGet(ds, eax) != 0x5c)
        goto loc_408e9a;
    eax++;
    ebx++;
    goto loc_408e91;
loc_408e9a: // 0000:408e9a
    if (memoryAGet(ds, eax) != 0x22)
        goto loc_408ecb;
    if (bl & 0x01)
        goto loc_408ec9;
    edi = 0;
    if (memoryAGet32(ss, ebp + 0x18) == edi)
        goto loc_408eb8;
    edx = eax + 1;
    if (memoryAGet(ds, eax + 0x1) != 0x22)
        goto loc_408eb8;
    eax = edx;
    goto loc_408ebb;
loc_408eb8: // 0000:408eb8
    memoryASet32(ss, ebp + 0x8, edi);
loc_408ebb: // 0000:408ebb
    edi = memoryAGet32(ss, ebp + 0xc);
    edx = 0;
    dl = memoryAGet32(ss, ebp + 0x18) == edx;
    memoryASet32(ss, ebp + 0x18, edx);
loc_408ec9: // 0000:408ec9
    ebx >>= 1;
loc_408ecb: // 0000:408ecb
    edx = ebx;
    ebx--;
    if (!edx)
        goto loc_408ee0;
    ebx++;
loc_408ed3: // 0000:408ed3
    if (!esi)
        goto loc_408edb;
    memoryASet(ds, esi, 0x5c);
    esi++;
loc_408edb: // 0000:408edb
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
    ebx--;
    if (ebx)
        goto loc_408ed3;
loc_408ee0: // 0000:408ee0
    dl = memoryAGet(ds, eax);
    if (!dl)
        goto loc_408f30;
    if (memoryAGet32(ss, ebp + 0x18))
        goto loc_408ef6;
    if (dl == 0x20)
        goto loc_408f30;
    if (dl == 0x09)
        goto loc_408f30;
loc_408ef6: // 0000:408ef6
    if (!memoryAGet32(ss, ebp + 0x8))
        goto loc_408f2a;
    if (!esi)
        goto loc_408f19;
    ebx = dl;
    if (!(memoryAGet(ds, ebx + 0x42bf21) & 0x04))
        goto loc_408f12;
    memoryASet(ds, esi, dl);
    esi++;
    eax++;
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
loc_408f12: // 0000:408f12
    dl = memoryAGet(ds, eax);
    memoryASet(ds, esi, dl);
    esi++;
    goto loc_408f28;
loc_408f19: // 0000:408f19
    edx = dl;
    if (!(memoryAGet(ds, edx + 0x42bf21) & 0x04))
        goto loc_408f28;
    eax++;
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
loc_408f28: // 0000:408f28
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
loc_408f2a: // 0000:408f2a
    eax++;
    goto loc_408e88;
loc_408f30: // 0000:408f30
    if (!esi)
        goto loc_408f38;
    memoryASet(ds, esi, memoryAGet(ds, esi) & 0x00);
    esi++;
loc_408f38: // 0000:408f38
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) + 1);
    goto loc_408e56;
loc_408f3f: // 0000:408f3f
    if (!edi)
        goto loc_408f46;
    memoryASet32(ds, edi, memoryAGet32(ds, edi) & 0x00000000);
loc_408f46: // 0000:408f46
    eax = memoryAGet32(ss, ebp + 0x14);
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    memoryASet32(ds, eax, memoryAGet32(ds, eax) + 1);
    ebp = pop32();
    esp += 4;
}
void sub_408f50() // 0000:408f50 +long
{
    esp -= 4;
    push32(ecx);
    push32(ecx);
    eax = memoryAGet32(ds, 0x40fc38);
    push32(ebx);
    push32(ebp);
    ebp = memoryAGet32(ds, 0x40d04c);
    push32(esi);
    push32(edi);
    ebx = 0;
    esi = 0;
    edi = 0;
    if (eax != ebx)
        goto loc_408f9e;
    indirectCall(cs, ebp); // 0000:408f6b
    esi = eax;
    if (esi == ebx)
        goto loc_408f7f;
    memoryASet32(ds, 0x40fc38, 0x00000001);
    goto loc_408fa7;
loc_408f7f: // 0000:408f7f
    eax = kernel32::GetEnvironmentStrings();();
    edi = eax;
    if (edi == ebx)
        goto loc_409079;
    memoryASet32(ds, 0x40fc38, 0x00000002);
    goto loc_40902d;
loc_408f9e: // 0000:408f9e
    if (eax != 0x00000001)
        goto loc_409028;
loc_408fa7: // 0000:408fa7
    if (esi != ebx)
        goto loc_408fb7;
    indirectCall(cs, ebp); // 0000:408fab
    esi = eax;
    if (esi == ebx)
        goto loc_409079;
loc_408fb7: // 0000:408fb7
    eax = esi;
    if (memoryAGet16(ds, esi) == bx)
        goto loc_408fcc;
loc_408fbe: // 0000:408fbe
    eax++;
    eax++;
    if (memoryAGet16(ds, eax) != bx)
        goto loc_408fbe;
    eax++;
    eax++;
    if (memoryAGet16(ds, eax) != bx)
        goto loc_408fbe;
loc_408fcc: // 0000:408fcc
    eax -= esi;
    edi = memoryAGet32(ds, 0x40d054);
    eax = sar32(eax, 0x00000001);
    push32(ebx);
    push32(ebx);
    eax++;
    push32(ebx);
    push32(ebx);
    push32(eax);
    push32(esi);
    push32(ebx);
    push32(ebx);
    memoryASet32(ds, esp + 0x34, eax);
    indirectCall(cs, edi); // 0000:408fe3
    ebp = eax;
    if (ebp == ebx)
        goto loc_40901d;
    push32(ebp);
    sub_406b40();
    ecx = pop32();
    memoryASet32(ds, esp + 0x10, eax);
    if (eax == ebx)
        goto loc_40901d;
    push32(ebx);
    push32(ebx);
    push32(ebp);
    push32(eax);
    push32(memoryAGet32(ds, esp + 0x24));
    push32(esi);
    push32(ebx);
    push32(ebx);
    indirectCall(cs, edi); // 0000:409005
    if (eax)
        goto loc_409019;
    push32(memoryAGet32(ds, esp + 0x10));
    sub_406bb4();
    ecx = pop32();
    memoryASet32(ds, esp + 0x10, ebx);
loc_409019: // 0000:409019
    ebx = memoryAGet32(ds, esp + 0x10);
loc_40901d: // 0000:40901d
    push32(esi);
    eax = kernel32::FreeEnvironmentStringsW(stack32<LPWCH>(0)); esp += 4;();
    eax = ebx;
    goto loc_40907b;
loc_409028: // 0000:409028
    if (eax != 0x00000002)
        goto loc_409079;
loc_40902d: // 0000:40902d
    if (edi != ebx)
        goto loc_40903d;
    eax = kernel32::GetEnvironmentStrings();();
    edi = eax;
    if (edi == ebx)
        goto loc_409079;
loc_40903d: // 0000:40903d
    eax = edi;
    if (memoryAGet(ds, edi) == bl)
        goto loc_40904d;
loc_409043: // 0000:409043
    eax++;
    if (memoryAGet(ds, eax) != bl)
        goto loc_409043;
    eax++;
    if (memoryAGet(ds, eax) != bl)
        goto loc_409043;
loc_40904d: // 0000:40904d
    eax -= edi;
    eax++;
    ebp = eax;
    push32(ebp);
    sub_406b40();
    esi = eax;
    ecx = pop32();
    if (esi != ebx)
        goto loc_409063;
    esi = 0;
    goto loc_40906e;
loc_409063: // 0000:409063
    push32(ebp);
    push32(edi);
    push32(esi);
    sub_4098d0();
    esp += 0x0000000c;
loc_40906e: // 0000:40906e
    push32(edi);
    eax = kernel32::FreeEnvironmentStringsA(stack32<LPCH>(0)); esp += 4;();
    eax = esi;
    goto loc_40907b;
loc_409079: // 0000:409079
    eax = 0;
loc_40907b: // 0000:40907b
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    ecx = pop32();
    ecx = pop32();
    esp += 4;
}
void sub_409082() // 0000:409082 +long
{
    esp -= 4;
    esp -= 0x00000044;
    push32(ebx);
    push32(ebp);
    push32(esi);
    push32(edi);
    push32(0x00000100);
    sub_406b40();
    esi = eax;
    ecx = pop32();
    if (esi)
        goto loc_4090a2;
    push32(0x0000001b);
    sub_406f73();
    ecx = pop32();
loc_4090a2: // 0000:4090a2
    memoryASet32(ds, 0x42d060, esi);
    memoryASet32(ds, 0x42d160, 0x00000020);
    eax = esi + 256;
loc_4090b8: // 0000:4090b8
    if (esi >= eax)
        goto loc_4090d6;
    memoryASet(ds, esi + 0x4, memoryAGet(ds, esi + 0x4) & 0x00);
    memoryASet32(ds, esi, memoryAGet32(ds, esi) | 0xffffffff);
    memoryASet(ds, esi + 0x5, 0x0a);
    eax = memoryAGet32(ds, 0x42d060);
    esi += 0x00000008;
    eax += 0x00000100;
    goto loc_4090b8;
loc_4090d6: // 0000:4090d6
    eax = esp + 16;
    push32(eax);
    kernel32::GetStartupInfoA(stack32<LPSTARTUPINFOA>(0)); esp += 4;();
    if (!memoryAGet16(ds, esp + 0x42))
        goto loc_4091b2;
    eax = memoryAGet32(ds, esp + 0x44);
    if (!eax)
        goto loc_4091b2;
    esi = memoryAGet32(ds, eax);
    ebp = eax + 4;
    eax = 0x00000800;
    ebx = esi + ebp;
    if ((int32_t)esi < (int32_t)eax)
        goto loc_40910c;
    esi = eax;
loc_40910c: // 0000:40910c
    if ((int32_t)memoryAGet32(ds, 0x42d160) >= (int32_t)esi)
        goto loc_409166;
    edi = 0x0042d064;
loc_409119: // 0000:409119
    push32(0x00000100);
    sub_406b40();
    ecx = pop32();
    if (!eax)
        goto loc_409160;
    memoryASet32(ds, 0x42d160, memoryAGet32(ds, 0x42d160) + 0x00000020);
    memoryASet32(ds, edi, eax);
    ecx = eax + 256;
loc_409137: // 0000:409137
    if (eax >= ecx)
        goto loc_409153;
    memoryASet(ds, eax + 0x4, memoryAGet(ds, eax + 0x4) & 0x00);
    memoryASet32(ds, eax, memoryAGet32(ds, eax) | 0xffffffff);
    memoryASet(ds, eax + 0x5, 0x0a);
    ecx = memoryAGet32(ds, edi);
    eax += 0x00000008;
    ecx += 0x00000100;
    goto loc_409137;
loc_409153: // 0000:409153
    edi += 0x00000004;
    if ((int32_t)memoryAGet32(ds, 0x42d160) < (int32_t)esi)
        goto loc_409119;
    goto loc_409166;
loc_409160: // 0000:409160
    esi = memoryAGet32(ds, 0x42d160);
loc_409166: // 0000:409166
    edi = 0;
    if ((int32_t)esi <= 0)
        goto loc_4091b2;
loc_40916c: // 0000:40916c
    eax = memoryAGet32(ds, ebx);
    if (eax == 0xffffffff)
        goto loc_4091a9;
    cl = memoryAGet(ss, ebp);
    if (!(cl & 0x01))
        goto loc_4091a9;
    if (cl & 0x08)
        goto loc_40918b;
    push32(eax);
    eax = kernel32::GetFileType(stack32<HANDLE>(0)); esp += 4;();
    if (!eax)
        goto loc_4091a9;
loc_40918b: // 0000:40918b
    eax = edi;
    ecx = edi;
    eax = sar32(eax, 0x05);
    ecx &= 0x0000001f;
    eax = memoryAGet32(ds, eax * 4 + 0x42d060);
    eax = eax + (ecx * 8);
    ecx = memoryAGet32(ds, ebx);
    memoryASet32(ds, eax, ecx);
    cl = memoryAGet(ss, ebp);
    memoryASet(ds, eax + 0x4, cl);
loc_4091a9: // 0000:4091a9
    edi++;
    ebp++;
    ebx += 0x00000004;
    if ((int32_t)edi < (int32_t)esi)
        goto loc_40916c;
loc_4091b2: // 0000:4091b2
    ebx = 0;
loc_4091b4: // 0000:4091b4
    eax = memoryAGet32(ds, 0x42d060);
    esi = eax + (ebx * 8);
    if (memoryAGet32(ds, eax + ebx * 8) != 0xffffffff)
        goto loc_40920f;
    memoryASet(ds, esi + 0x4, 0x81);
    if (ebx)
        goto loc_4091cf;
    push32(0xfffffff6);
    eax = pop32();
    goto loc_4091d9;
loc_4091cf: // 0000:4091cf
    eax = ebx;
    eax--;
    flags.carry = eax != 0;
    eax = -eax;
    eax = -flags.carry;
    eax += 0xfffffff5;
loc_4091d9: // 0000:4091d9
    push32(eax);
    eax = kernel32::GetStdHandle(stack32<DWORD>(0)); esp += 4;();
    edi = eax;
    if (edi == 0xffffffff)
        goto loc_4091fe;
    push32(edi);
    eax = kernel32::GetFileType(stack32<HANDLE>(0)); esp += 4;();
    if (!eax)
        goto loc_4091fe;
    eax &= 0x000000ff;
    memoryASet32(ds, esi, edi);
    if (eax != 0x00000002)
        goto loc_409204;
loc_4091fe: // 0000:4091fe
    memoryASet(ds, esi + 0x4, memoryAGet(ds, esi + 0x4) | 0x40);
    goto loc_409213;
loc_409204: // 0000:409204
    if (eax != 0x00000003)
        goto loc_409213;
    memoryASet(ds, esi + 0x4, memoryAGet(ds, esi + 0x4) | 0x08);
    goto loc_409213;
loc_40920f: // 0000:40920f
    memoryASet(ds, esi + 0x4, memoryAGet(ds, esi + 0x4) | 0x80);
loc_409213: // 0000:409213
    ebx++;
    if ((int32_t)ebx < (int32_t)0x00000003)
        goto loc_4091b4;
    push32(memoryAGet32(ds, 0x42d160));
    eax = kernel32::SetHandleCount(stack32<UINT>(0)); esp += 4;();
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x00000044;
    esp += 4;
}
void sub_409400() // 0000:409400 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x40fb14);
    if (eax == 0x00000001)
        goto loc_409417;
    if (eax)
        goto loc_409438;
    if (memoryAGet32(ds, 0x40eecc) != 0x00000001)
        goto loc_409438;
loc_409417: // 0000:409417
    push32(0x000000fc);
    sub_409439();
    eax = memoryAGet32(ds, 0x40fc3c);
    ecx = pop32();
    if (!eax)
        goto loc_40942d;
    indirectCall(cs, eax); // 0000:40942b
loc_40942d: // 0000:40942d
    push32(0x000000ff);
    sub_409439();
    ecx = pop32();
loc_409438: // 0000:409438
    esp += 4; return;
}
void sub_409439() // 0000:409439 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x000001a4;
    edx = memoryAGet32(ss, ebp + 0x8);
    ecx = 0;
    eax = 0x0040ef98;
loc_40944c: // 0000:40944c
    if (edx == memoryAGet32(ds, eax))
        goto loc_40945b;
    eax += 0x00000008;
    ecx++;
    if ((int32_t)eax < (int32_t)0x0040f028)
        goto loc_40944c;
loc_40945b: // 0000:40945b
    push32(esi);
    esi = ecx;
    esi <<= 3;
    if (edx != memoryAGet32(ds, esi + 0x40ef98))
        goto loc_409589;
    eax = memoryAGet32(ds, 0x40fb14);
    if (eax == 0x00000001)
        goto loc_409563;
    if (eax)
        goto loc_40948c;
    if (memoryAGet32(ds, 0x40eecc) == 0x00000001)
        goto loc_409563;
loc_40948c: // 0000:40948c
    if (edx == 0x000000fc)
        goto loc_409589;
    eax = ebp - 420;
    push32(0x00000104);
    push32(eax);
    push32(0x00000000);
    eax = kernel32::GetModuleFileNameA(stack32<HMODULE>(0), stack32<LPSTR>(1), stack32<DWORD>(2)); esp += 12;();
    if (eax)
        goto loc_4094c3;
    eax = ebp - 420;
    push32(0x0040d6c0);
    push32(eax);
    sub_40a2a0();
    ecx = pop32();
    ecx = pop32();
loc_4094c3: // 0000:4094c3
    eax = ebp - 420;
    push32(edi);
    push32(eax);
    edi = ebp - 420;
    sub_40a590();
    eax++;
    ecx = pop32();
    if (eax <= 0x0000003c)
        goto loc_409506;
    eax = ebp - 420;
    push32(eax);
    sub_40a590();
    edi = eax;
    eax = ebp - 420;
    eax -= 0x0000003b;
    push32(0x00000003);
    edi += eax;
    push32(0x0040eac8);
    push32(edi);
    sub_40af80();
    esp += 0x00000010;
loc_409506: // 0000:409506
    eax = ebp - 160;
    push32(0x0040d6a4);
    push32(eax);
    sub_40a2a0();
    eax = ebp - 160;
    push32(edi);
    push32(eax);
    sub_40a2b0();
    eax = ebp - 160;
    push32(0x0040d6a0);
    push32(eax);
    sub_40a2b0();
    push32(memoryAGet32(ds, esi + 0x40ef9c));
    eax = ebp - 160;
    push32(eax);
    sub_40a2b0();
    push32(0x00012010);
    eax = ebp - 160;
    push32(0x0040d678);
    push32(eax);
    sub_40aef7();
    esp += 0x0000002c;
    edi = pop32();
    goto loc_409589;
loc_409563: // 0000:409563
    eax = ebp + 8;
    esi = esi + 4255644;
    push32(0x00000000);
    push32(eax);
    push32(memoryAGet32(ds, esi));
    sub_40a590();
    ecx = pop32();
    push32(eax);
    push32(memoryAGet32(ds, esi));
    push32(0xfffffff4);
    eax = kernel32::GetStdHandle(stack32<DWORD>(0)); esp += 4;();
    push32(eax);
    eax = kernel32::WriteFile(stack32<HANDLE>(0), stack32<LPCVOID>(1), stack32<DWORD>(2), stack32<LPDWORD>(3), stack32<LPOVERLAPPED>(4)); esp += 20;();
loc_409589: // 0000:409589
    esi = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_409590() // 0000:409590 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(edi);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0xc);
    ecx = memoryAGet32(ss, ebp + 0x10);
    edi = memoryAGet32(ss, ebp + 0x8);
    eax = ecx;
    edx = ecx;
    eax += esi;
    if (edi <= esi)
        goto loc_4095b0;
    if (edi < eax)
        goto loc_409728;
loc_4095b0: // 0000:4095b0
    if (edi & 0x00000003)
        goto loc_4095cc;
    ecx >>= 2;
    edx &= 0x00000003;
    if (ecx < 0x00000008)
        goto loc_4095ec;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    indirectJump(cs, memoryAGet32(ds, edx * 4 + 0x4096d8)); return; // 0000:4095c5
loc_4095cc: // 0000:4095cc
    eax = edi;
    edx = 0x00000003;
    flags.carry = ecx < 0x00000004;
    ecx -= 0x00000004;
    if (flags.carry)
        goto loc_4095e4;
    eax &= 0x00000003;
    ecx += eax;
    indirectJump(cs, memoryAGet32(ds, eax * 4 + 0x4095f0)); return; // 0000:4095dd
loc_4095e4: // 0000:4095e4
    indirectJump(cs, memoryAGet32(ds, ecx * 4 + 0x4096e8)); return; // 0000:4095e4
    // gap 1 bytes // gap 1 bytes
loc_4095ec: // 0000:4095ec
    indirectJump(cs, memoryAGet32(ds, ecx * 4 + 0x40966c)); return; // 0000:4095ec
    // gap 309 bytes // gap 309 bytes
loc_409728: // 0000:409728
    esi = (ecx + esi) + -4;
    edi = (ecx + edi) + -4;
    if (edi & 0x00000003)
        goto loc_40975c;
    ecx >>= 2;
    edx &= 0x00000003;
    if (ecx < 0x00000008)
        goto loc_409750;
    flags.direction = 1;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    flags.direction = 0;
    indirectJump(cs, memoryAGet32(ds, edx * 4 + 0x409870)); return; // 0000:409747
    // gap 2 bytes // gap 2 bytes
loc_409750: // 0000:409750
    ecx = -ecx;
    indirectJump(cs, memoryAGet32(ds, ecx * 4 + 0x409820)); return; // 0000:409752
    // gap 3 bytes // gap 3 bytes
loc_40975c: // 0000:40975c
    eax = edi;
    edx = 0x00000003;
    if (ecx < 0x00000004)
        goto loc_409774;
    eax &= 0x00000003;
    ecx -= eax;
    indirectJump(cs, memoryAGet32(ds, eax * 4 + 0x409778)); return; // 0000:40976d
loc_409774: // 0000:409774
    indirectJump(cs, memoryAGet32(ds, ecx * 4 + 0x409870)); return; // 0000:409774
}
void sub_4098d0() // 0000:4098d0 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(edi);
    push32(esi);
    esi = memoryAGet32(ss, ebp + 0xc);
    ecx = memoryAGet32(ss, ebp + 0x10);
    edi = memoryAGet32(ss, ebp + 0x8);
    eax = ecx;
    edx = ecx;
    eax += esi;
    if (edi <= esi)
        goto loc_4098f0;
    if (edi < eax)
        goto loc_409a68;
loc_4098f0: // 0000:4098f0
    if (edi & 0x00000003)
        goto loc_40990c;
    ecx >>= 2;
    edx &= 0x00000003;
    if (ecx < 0x00000008)
        goto loc_40992c;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    indirectJump(cs, memoryAGet32(ds, edx * 4 + 0x409a18)); return; // 0000:409905
loc_40990c: // 0000:40990c
    eax = edi;
    edx = 0x00000003;
    flags.carry = ecx < 0x00000004;
    ecx -= 0x00000004;
    if (flags.carry)
        goto loc_409924;
    eax &= 0x00000003;
    ecx += eax;
    indirectJump(cs, memoryAGet32(ds, eax * 4 + 0x409930)); return; // 0000:40991d
loc_409924: // 0000:409924
    indirectJump(cs, memoryAGet32(ds, ecx * 4 + 0x409a28)); return; // 0000:409924
    // gap 1 bytes // gap 1 bytes
loc_40992c: // 0000:40992c
    indirectJump(cs, memoryAGet32(ds, ecx * 4 + 0x4099ac)); return; // 0000:40992c
    // gap 309 bytes // gap 309 bytes
loc_409a68: // 0000:409a68
    esi = (ecx + esi) + -4;
    edi = (ecx + edi) + -4;
    if (edi & 0x00000003)
        goto loc_409a9c;
    ecx >>= 2;
    edx &= 0x00000003;
    if (ecx < 0x00000008)
        goto loc_409a90;
    flags.direction = 1;
    for (; ecx != 0; --ecx) movsd<ES_EDI, DS_ESI>();
    flags.direction = 0;
    indirectJump(cs, memoryAGet32(ds, edx * 4 + 0x409bb0)); return; // 0000:409a87
    // gap 2 bytes // gap 2 bytes
loc_409a90: // 0000:409a90
    ecx = -ecx;
    indirectJump(cs, memoryAGet32(ds, ecx * 4 + 0x409b60)); return; // 0000:409a92
    // gap 3 bytes // gap 3 bytes
loc_409a9c: // 0000:409a9c
    eax = edi;
    edx = 0x00000003;
    if (ecx < 0x00000004)
        goto loc_409ab4;
    eax &= 0x00000003;
    ecx -= eax;
    indirectJump(cs, memoryAGet32(ds, eax * 4 + 0x409ab8)); return; // 0000:409aad
loc_409ab4: // 0000:409ab4
    indirectJump(cs, memoryAGet32(ds, ecx * 4 + 0x409bb0)); return; // 0000:409ab4
}
void sub_409c05() // 0000:409c05 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(ecx);
    push32(esi);
    memoryASet16(ss, ebp - 4, fnstcw());
    push32(memoryAGet32(ss, ebp - 4));
    sub_409c50();
    esi = eax;
    eax = memoryAGet32(ss, ebp + 0xc);
    eax = ~eax;
    esi &= eax;
    eax = memoryAGet32(ss, ebp + 0x8);
    eax &= memoryAGet32(ss, ebp + 0xc);
    esi |= eax;
    push32(esi);
    sub_409ce2();
    ecx = pop32();
    memoryASet32(ss, ebp + 0xc, eax);
    ecx = pop32();
    fldcw(memoryAGet16(ss, ebp + 0xc));
    eax = esi;
    esi = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_409c3a() // 0000:409c3a +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x8);
    eax &= 0xfff7ffff;
    push32(eax);
    push32(memoryAGet32(ds, esp + 0x8));
    sub_409c05();
    ecx = pop32();
    ecx = pop32();
    esp += 4;
}
void sub_409c50() // 0000:409c50 +long
{
    esp -= 4;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x8);
    eax = 0;
    push32(ebp);
    push32(edi);
    if (!(bl & 0x01))
        goto loc_409c61;
    push32(0x00000010);
    eax = pop32();
loc_409c61: // 0000:409c61
    if (!(bl & 0x04))
        goto loc_409c68;
    al |= 0x08;
loc_409c68: // 0000:409c68
    if (!(bl & 0x08))
        goto loc_409c6f;
    al |= 0x04;
loc_409c6f: // 0000:409c6f
    if (!(bl & 0x10))
        goto loc_409c76;
    al |= 0x02;
loc_409c76: // 0000:409c76
    if (!(bl & 0x20))
        goto loc_409c7d;
    al |= 0x01;
loc_409c7d: // 0000:409c7d
    if (!(bl & 0x02))
        goto loc_409c87;
    eax |= 0x00080000;
loc_409c87: // 0000:409c87
    ecx = bx;
    push32(esi);
    edx = ecx;
    esi = 0x00000c00;
    edi = 0x00000300;
    edx &= esi;
    ebp = 0x00000200;
    if (!edx)
        goto loc_409cbf;
    if (edx == 0x00000400)
        goto loc_409cbc;
    if (edx == 0x00000800)
        goto loc_409cb8;
    if (edx != esi)
        goto loc_409cbf;
    eax |= edi;
    goto loc_409cbf;
loc_409cb8: // 0000:409cb8
    eax |= ebp;
    goto loc_409cbf;
loc_409cbc: // 0000:409cbc
    ah |= 0x01;
loc_409cbf: // 0000:409cbf
    ecx &= edi;
    esi = pop32();
    if (!ecx)
        goto loc_409ccf;
    if (ecx != ebp)
        goto loc_409cd4;
    eax |= 0x00010000;
    goto loc_409cd4;
loc_409ccf: // 0000:409ccf
    eax |= 0x00020000;
loc_409cd4: // 0000:409cd4
    edi = pop32();
    ebp = pop32();
    flags.zero = !(bh & 0x10);
    ebx = pop32();
    if (flags.zero)
        goto loc_409ce1;
    eax |= 0x00040000;
loc_409ce1: // 0000:409ce1
    esp += 4; return;
}
void sub_409ce2() // 0000:409ce2 +long
{
    esp -= 4;
    push32(ebx);
    ebx = memoryAGet32(ds, esp + 0x8);
    eax = 0;
    push32(esi);
    if (!(bl & 0x10))
        goto loc_409cf2;
    push32(0x00000001);
    eax = pop32();
loc_409cf2: // 0000:409cf2
    if (!(bl & 0x08))
        goto loc_409cf9;
    al |= 0x04;
loc_409cf9: // 0000:409cf9
    if (!(bl & 0x04))
        goto loc_409d00;
    al |= 0x08;
loc_409d00: // 0000:409d00
    if (!(bl & 0x02))
        goto loc_409d07;
    al |= 0x10;
loc_409d07: // 0000:409d07
    if (!(bl & 0x01))
        goto loc_409d0e;
    al |= 0x20;
loc_409d0e: // 0000:409d0e
    if (!(ebx & 0x00080000))
        goto loc_409d18;
    al |= 0x02;
loc_409d18: // 0000:409d18
    ecx = ebx;
    edx = 0x00000300;
    ecx &= edx;
    esi = 0x00000200;
    if (!ecx)
        goto loc_409d45;
    if (ecx == 0x00000100)
        goto loc_409d42;
    if (ecx == esi)
        goto loc_409d3d;
    if (ecx != edx)
        goto loc_409d45;
    ah |= 0x0c;
    goto loc_409d45;
loc_409d3d: // 0000:409d3d
    ah |= 0x08;
    goto loc_409d45;
loc_409d42: // 0000:409d42
    ah |= 0x04;
loc_409d45: // 0000:409d45
    ecx = ebx;
    ecx &= 0x00030000;
    if (!ecx)
        goto loc_409d5b;
    if (ecx != 0x00010000)
        goto loc_409d5d;
    eax |= esi;
    goto loc_409d5d;
loc_409d5b: // 0000:409d5b
    eax |= edx;
loc_409d5d: // 0000:409d5d
    esi = pop32();
    flags.zero = !(ebx & 0x00040000);
    ebx = pop32();
    if (flags.zero)
        goto loc_409d6a;
    ah |= 0x10;
loc_409d6a: // 0000:409d6a
    esp += 4; return;
}
void sub_40a2a0() // 0000:40a2a0 +long
{
    esp -= 4;
    push32(edi);
    edi = memoryAGet32(ds, esp + 0x8);
    goto loc_40a311;
    // gap 106 bytes // gap 106 bytes
loc_40a311: // 0000:40a311
    ecx = memoryAGet32(ds, esp + 0xc);
    if (!(ecx & 0x00000003))
        goto loc_40a336;
loc_40a31d: // 0000:40a31d
    dl = memoryAGet(ds, ecx);
    ecx++;
    if (!dl)
        goto loc_40a388;
    memoryASet(ds, edi, dl);
    edi++;
    if (ecx & 0x00000003)
        goto loc_40a31d;
    goto loc_40a336;
loc_40a331: // 0000:40a331
    memoryASet32(ds, edi, edx);
    edi += 0x00000004;
loc_40a336: // 0000:40a336
    edx = 0x7efefeff;
    eax = memoryAGet32(ds, ecx);
    edx += eax;
    eax ^= 0xffffffff;
    eax ^= edx;
    edx = memoryAGet32(ds, ecx);
    ecx += 0x00000004;
    if (!(eax & 0x81010100))
        goto loc_40a331;
    if (!dl)
        goto loc_40a388;
    if (!dh)
        goto loc_40a37f;
    if (!(edx & 0x00ff0000))
        goto loc_40a372;
    if (!(edx & 0xff000000))
        goto loc_40a36a;
    goto loc_40a331;
loc_40a36a: // 0000:40a36a
    memoryASet32(ds, edi, edx);
    eax = memoryAGet32(ds, esp + 0x8);
    edi = pop32();
    esp += 4; return;
loc_40a372: // 0000:40a372
    memoryASet16(ds, edi, dx);
    eax = memoryAGet32(ds, esp + 0x8);
    memoryASet(ds, edi + 0x2, 0x00);
    edi = pop32();
    esp += 4; return;
loc_40a37f: // 0000:40a37f
    memoryASet16(ds, edi, dx);
    eax = memoryAGet32(ds, esp + 0x8);
    edi = pop32();
    esp += 4; return;
loc_40a388: // 0000:40a388
    memoryASet(ds, edi, dl);
    eax = memoryAGet32(ds, esp + 0x8);
    edi = pop32();
    esp += 4;
}
void sub_40a2b0() // 0000:40a2b0 +long
{
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0x4);
    push32(edi);
    if (!(ecx & 0x00000003))
        goto loc_40a2cc;
loc_40a2bd: // 0000:40a2bd
    al = memoryAGet(ds, ecx);
    ecx++;
    if (!al)
        goto loc_40a2ff;
    if (ecx & 0x00000003)
        goto loc_40a2bd;
loc_40a2cc: // 0000:40a2cc
    eax = memoryAGet32(ds, ecx);
    edx = 0x7efefeff;
    edx += eax;
    eax ^= 0xffffffff;
    eax ^= edx;
    ecx += 0x00000004;
    if (!(eax & 0x81010100))
        goto loc_40a2cc;
    eax = memoryAGet32(ds, ecx - 4);
    if (!al)
        goto loc_40a30e;
    if (!ah)
        goto loc_40a309;
    if (!(eax & 0x00ff0000))
        goto loc_40a304;
    if (!(eax & 0xff000000))
        goto loc_40a2ff;
    goto loc_40a2cc;
loc_40a2ff: // 0000:40a2ff
    edi = ecx - 1;
    goto loc_40a311;
loc_40a304: // 0000:40a304
    edi = ecx - 2;
    goto loc_40a311;
loc_40a309: // 0000:40a309
    edi = ecx - 3;
    goto loc_40a311;
loc_40a30e: // 0000:40a30e
    edi = ecx - 4;
loc_40a311: // 0000:40a311
    ecx = memoryAGet32(ds, esp + 0xc);
    if (!(ecx & 0x00000003))
        goto loc_40a336;
loc_40a31d: // 0000:40a31d
    dl = memoryAGet(ds, ecx);
    ecx++;
    if (!dl)
        goto loc_40a388;
    memoryASet(ds, edi, dl);
    edi++;
    if (ecx & 0x00000003)
        goto loc_40a31d;
    goto loc_40a336;
loc_40a331: // 0000:40a331
    memoryASet32(ds, edi, edx);
    edi += 0x00000004;
loc_40a336: // 0000:40a336
    edx = 0x7efefeff;
    eax = memoryAGet32(ds, ecx);
    edx += eax;
    eax ^= 0xffffffff;
    eax ^= edx;
    edx = memoryAGet32(ds, ecx);
    ecx += 0x00000004;
    if (!(eax & 0x81010100))
        goto loc_40a331;
    if (!dl)
        goto loc_40a388;
    if (!dh)
        goto loc_40a37f;
    if (!(edx & 0x00ff0000))
        goto loc_40a372;
    if (!(edx & 0xff000000))
        goto loc_40a36a;
    goto loc_40a331;
loc_40a36a: // 0000:40a36a
    memoryASet32(ds, edi, edx);
    eax = memoryAGet32(ds, esp + 0x8);
    edi = pop32();
    esp += 4; return;
loc_40a372: // 0000:40a372
    memoryASet16(ds, edi, dx);
    eax = memoryAGet32(ds, esp + 0x8);
    memoryASet(ds, edi + 0x2, 0x00);
    edi = pop32();
    esp += 4; return;
loc_40a37f: // 0000:40a37f
    memoryASet16(ds, edi, dx);
    eax = memoryAGet32(ds, esp + 0x8);
    edi = pop32();
    esp += 4; return;
loc_40a388: // 0000:40a388
    memoryASet(ds, edi, dl);
    eax = memoryAGet32(ds, esp + 0x8);
    edi = pop32();
    esp += 4;
}
void sub_40a530() // 0000:40a530 +long
{
    esp -= 4;
    edx = memoryAGet32(ds, esp + 0xc);
    ecx = memoryAGet32(ds, esp + 0x4);
    if (!edx)
        goto loc_40a583;
    eax = 0;
    al = memoryAGet(ds, esp + 0x8);
    push32(edi);
    edi = ecx;
    if (edx < 0x00000004)
        goto loc_40a577;
    ecx = -ecx;
    ecx &= 0x00000003;
    if (!ecx)
        goto loc_40a559;
    edx -= ecx;
loc_40a553: // 0000:40a553
    memoryASet(ds, edi, al);
    edi++;
    ecx--;
    if (ecx)
        goto loc_40a553;
loc_40a559: // 0000:40a559
    ecx = eax;
    eax <<= 8;
    eax += ecx;
    ecx = eax;
    eax <<= 16;
    eax += ecx;
    ecx = edx;
    edx &= 0x00000003;
    ecx >>= 2;
    if (!ecx)
        goto loc_40a577;
    for (; ecx != 0; --ecx) stosd<ES_EDI>(eax);
    if (!edx)
        goto loc_40a57d;
loc_40a577: // 0000:40a577
    memoryASet(ds, edi, al);
    edi++;
    edx--;
    if (edx)
        goto loc_40a577;
loc_40a57d: // 0000:40a57d
    eax = memoryAGet32(ds, esp + 0x8);
    edi = pop32();
    esp += 4; return;
loc_40a583: // 0000:40a583
    eax = memoryAGet32(ds, esp + 0x4);
    esp += 4;
}
void sub_40a590() // 0000:40a590 +long
{
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0x4);
    if (!(ecx & 0x00000003))
        goto loc_40a5b0;
loc_40a59c: // 0000:40a59c
    al = memoryAGet(ds, ecx);
    ecx++;
    if (!al)
        goto loc_40a5e3;
    if (ecx & 0x00000003)
        goto loc_40a59c;
    eax += 0x00000000;
loc_40a5b0: // 0000:40a5b0
    eax = memoryAGet32(ds, ecx);
    edx = 0x7efefeff;
    edx += eax;
    eax ^= 0xffffffff;
    eax ^= edx;
    ecx += 0x00000004;
    if (!(eax & 0x81010100))
        goto loc_40a5b0;
    eax = memoryAGet32(ds, ecx - 4);
    if (!al)
        goto loc_40a601;
    if (!ah)
        goto loc_40a5f7;
    if (!(eax & 0x00ff0000))
        goto loc_40a5ed;
    if (!(eax & 0xff000000))
        goto loc_40a5e3;
    goto loc_40a5b0;
loc_40a5e3: // 0000:40a5e3
    eax = ecx - 1;
    ecx = memoryAGet32(ds, esp + 0x4);
    eax -= ecx;
    esp += 4; return;
loc_40a5ed: // 0000:40a5ed
    eax = ecx - 2;
    ecx = memoryAGet32(ds, esp + 0x4);
    eax -= ecx;
    esp += 4; return;
loc_40a5f7: // 0000:40a5f7
    eax = ecx - 3;
    ecx = memoryAGet32(ds, esp + 0x4);
    eax -= ecx;
    esp += 4; return;
loc_40a601: // 0000:40a601
    eax = ecx - 4;
    ecx = memoryAGet32(ds, esp + 0x4);
    eax -= ecx;
    esp += 4;
}
void sub_40a614() // 0000:40a614 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    push32(ebx);
    push32(esi);
    push32(edi);
    if (eax >= memoryAGet32(ds, 0x42d160))
        goto loc_40a696;
    ecx = eax;
    esi = eax;
    ecx = sar32(ecx, 0x05);
    esi &= 0x0000001f;
    edi = (ecx * 4) + 4378720;
    esi <<= 3;
    ecx = memoryAGet32(ds, edi);
    if (!(memoryAGet(ds, ecx + esi + 0x4) & 0x01))
        goto loc_40a696;
    push32(eax);
    sub_40bdfc();
    ecx = pop32();
    if (eax != 0xffffffff)
        goto loc_40a658;
    memoryASet32(ds, 0x40fab8, 0x00000009);
    goto loc_40a6a7;
loc_40a658: // 0000:40a658
    push32(memoryAGet32(ds, esp + 0x18));
    push32(0x00000000);
    push32(memoryAGet32(ds, esp + 0x1c));
    push32(eax);
    eax = kernel32::SetFilePointer(stack32<HANDLE>(0), stack32<LONG>(1), stack32<PLONG>(2), stack32<DWORD>(3)); esp += 16;();
    ebx = eax;
    if (ebx != 0xffffffff)
        goto loc_40a678;
    eax = kernel32::GetLastError();();
    goto loc_40a67a;
loc_40a678: // 0000:40a678
    eax = 0;
loc_40a67a: // 0000:40a67a
    if (!eax)
        goto loc_40a687;
    push32(eax);
    sub_40bd1b();
    ecx = pop32();
    goto loc_40a6a7;
loc_40a687: // 0000:40a687
    eax = memoryAGet32(ds, edi);
    memoryASet(ds, eax + esi + 0x4, memoryAGet(ds, eax + esi + 0x4) & 0xfd);
    eax = (eax + esi) + 4;
    eax = ebx;
    goto loc_40a6aa;
loc_40a696: // 0000:40a696
    memoryASet32(ds, 0x40fabc, memoryAGet32(ds, 0x40fabc) & 0x00000000);
    memoryASet32(ds, 0x40fab8, 0x00000009);
loc_40a6a7: // 0000:40a6a7
    eax |= 0xffffffff;
loc_40a6aa: // 0000:40a6aa
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp += 4;
}
void sub_40a6ae() // 0000:40a6ae +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000414;
    ecx = memoryAGet32(ss, ebp + 0x8);
    push32(ebx);
    push32(esi);
    push32(edi);
    if (ecx >= memoryAGet32(ds, 0x42d160))
        goto loc_40a842;
    eax = ecx;
    esi = ecx;
    eax = sar32(eax, 0x05);
    esi &= 0x0000001f;
    ebx = (eax * 4) + 4378720;
    esi <<= 3;
    eax = memoryAGet32(ds, ebx);
    al = memoryAGet(ds, eax + esi + 0x4);
    if (!(al & 0x01))
        goto loc_40a842;
    edi = 0;
    memoryASet32(ss, ebp - 8, edi);
    memoryASet32(ss, ebp - 16, edi);
    if (memoryAGet32(ss, ebp + 0x10) != edi)
        goto loc_40a6ff;
loc_40a6f8: // 0000:40a6f8
    eax = 0;
    goto loc_40a856;
loc_40a6ff: // 0000:40a6ff
    if (!(al & 0x20))
        goto loc_40a70f;
    push32(0x00000002);
    push32(edi);
    push32(ecx);
    sub_40a614();
    esp += 0x0000000c;
loc_40a70f: // 0000:40a70f
    eax = memoryAGet32(ds, ebx);
    eax += esi;
    if (!(memoryAGet(ds, eax + 0x4) & 0x80))
        goto loc_40a7de;
    eax = memoryAGet32(ss, ebp + 0xc);
    memoryASet32(ss, ebp - 4, eax);
    memoryASet32(ss, ebp + 0x8, edi);
    if (memoryAGet32(ss, ebp + 0x10) <= edi)
        goto loc_40a816;
loc_40a72f: // 0000:40a72f
    eax = ebp - 1044;
loc_40a735: // 0000:40a735
    ecx = memoryAGet32(ss, ebp - 4);
    ecx -= memoryAGet32(ss, ebp + 0xc);
    if (ecx >= memoryAGet32(ss, ebp + 0x10))
        goto loc_40a769;
    ecx = memoryAGet32(ss, ebp - 4);
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) + 1);
    cl = memoryAGet(ds, ecx);
    if (cl != 0x0a)
        goto loc_40a754;
    memoryASet32(ss, ebp - 16, memoryAGet32(ss, ebp - 16) + 1);
    memoryASet(ds, eax, 0x0d);
    eax++;
loc_40a754: // 0000:40a754
    memoryASet(ds, eax, cl);
    eax++;
    ecx = eax;
    edx = ebp - 1044;
    ecx -= edx;
    if ((int32_t)ecx < (int32_t)0x00000400)
        goto loc_40a735;
loc_40a769: // 0000:40a769
    edi = eax;
    eax = ebp - 1044;
    edi -= eax;
    eax = ebp - 12;
    push32(0x00000000);
    push32(eax);
    eax = ebp - 1044;
    push32(edi);
    push32(eax);
    eax = memoryAGet32(ds, ebx);
    push32(memoryAGet32(ds, eax + esi));
    eax = kernel32::WriteFile(stack32<HANDLE>(0), stack32<LPCVOID>(1), stack32<DWORD>(2), stack32<LPDWORD>(3), stack32<LPOVERLAPPED>(4)); esp += 20;();
    if (!eax)
        goto loc_40a7d3;
    eax = memoryAGet32(ss, ebp - 12);
    memoryASet32(ss, ebp - 8, memoryAGet32(ss, ebp - 8) + eax);
    if ((int32_t)eax < (int32_t)edi)
        goto loc_40a7a5;
    eax = memoryAGet32(ss, ebp - 4);
    eax -= memoryAGet32(ss, ebp + 0xc);
    if (eax < memoryAGet32(ss, ebp + 0x10))
        goto loc_40a72f;
loc_40a7a5: // 0000:40a7a5
    edi = 0;
loc_40a7a7: // 0000:40a7a7
    eax = memoryAGet32(ss, ebp - 8);
    if (eax != edi)
        goto loc_40a83d;
    if (memoryAGet32(ss, ebp + 0x8) == edi)
        goto loc_40a816;
    push32(0x00000005);
    eax = pop32();
    if (memoryAGet32(ss, ebp + 0x8) != eax)
        goto loc_40a80b;
    memoryASet32(ds, 0x40fab8, 0x00000009);
    memoryASet32(ds, 0x40fabc, eax);
    goto loc_40a853;
loc_40a7d3: // 0000:40a7d3
    eax = kernel32::GetLastError();();
    memoryASet32(ss, ebp + 0x8, eax);
    goto loc_40a7a5;
loc_40a7de: // 0000:40a7de
    ecx = ebp - 12;
    push32(edi);
    push32(ecx);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ds, eax));
    eax = kernel32::WriteFile(stack32<HANDLE>(0), stack32<LPCVOID>(1), stack32<DWORD>(2), stack32<LPDWORD>(3), stack32<LPOVERLAPPED>(4)); esp += 20;();
    if (!eax)
        goto loc_40a800;
    eax = memoryAGet32(ss, ebp - 12);
    memoryASet32(ss, ebp + 0x8, edi);
    memoryASet32(ss, ebp - 8, eax);
    goto loc_40a7a7;
loc_40a800: // 0000:40a800
    eax = kernel32::GetLastError();();
    memoryASet32(ss, ebp + 0x8, eax);
    goto loc_40a7a7;
loc_40a80b: // 0000:40a80b
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_40bd1b();
    ecx = pop32();
    goto loc_40a853;
loc_40a816: // 0000:40a816
    eax = memoryAGet32(ds, ebx);
    if (!(memoryAGet(ds, eax + esi + 0x4) & 0x40))
        goto loc_40a82b;
    eax = memoryAGet32(ss, ebp + 0xc);
    if (memoryAGet(ds, eax) == 0x1a)
        goto loc_40a6f8;
loc_40a82b: // 0000:40a82b
    memoryASet32(ds, 0x40fab8, 0x0000001c);
    memoryASet32(ds, 0x40fabc, edi);
    goto loc_40a853;
loc_40a83d: // 0000:40a83d
    eax -= memoryAGet32(ss, ebp - 16);
    goto loc_40a856;
loc_40a842: // 0000:40a842
    memoryASet32(ds, 0x40fabc, memoryAGet32(ds, 0x40fabc) & 0x00000000);
    memoryASet32(ds, 0x40fab8, 0x00000009);
loc_40a853: // 0000:40a853
    eax |= 0xffffffff;
loc_40a856: // 0000:40a856
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_40a85b() // 0000:40a85b +long
{
    esp -= 4;
    memoryASet32(ds, 0x40fc70, memoryAGet32(ds, 0x40fc70) + 1);
    push32(0x00001000);
    sub_406b40();
    ecx = pop32();
    ecx = memoryAGet32(ds, esp + 0x4);
    memoryASet32(ds, ecx + 0x8, eax);
    if (!eax)
        goto loc_40a884;
    memoryASet32(ds, ecx + 0xc, memoryAGet32(ds, ecx + 0xc) | 0x00000008);
    memoryASet32(ds, ecx + 0x18, 0x00001000);
    goto loc_40a895;
loc_40a884: // 0000:40a884
    memoryASet32(ds, ecx + 0xc, memoryAGet32(ds, ecx + 0xc) | 0x00000004);
    eax = ecx + 20;
    memoryASet32(ds, ecx + 0x8, eax);
    memoryASet32(ds, ecx + 0x18, 0x00000002);
loc_40a895: // 0000:40a895
    eax = memoryAGet32(ds, ecx + 0x8);
    memoryASet32(ds, ecx + 0x4, memoryAGet32(ds, ecx + 0x4) & 0x00000000);
    memoryASet32(ds, ecx, eax);
    esp += 4;
}
void sub_40a89f() // 0000:40a89f +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    if (eax < memoryAGet32(ds, 0x42d160))
        goto loc_40a8ae;
    eax = 0;
    esp += 4; return;
loc_40a8ae: // 0000:40a8ae
    ecx = eax;
    eax &= 0x0000001f;
    ecx = sar32(ecx, 0x05);
    ecx = memoryAGet32(ds, ecx * 4 + 0x42d060);
    al = memoryAGet(ds, ecx + eax * 8 + 0x4);
    eax &= 0x00000040;
    esp += 4;
}
void sub_40a8c5() // 0000:40a8c5 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, 0x42d040);
    push32(esi);
    push32(0x00000014);
    esi = pop32();
    if (eax)
        goto loc_40a8d9;
    eax = 0x00000200;
    goto loc_40a8df;
loc_40a8d9: // 0000:40a8d9
    if ((int32_t)eax >= (int32_t)esi)
        goto loc_40a8e4;
    eax = esi;
loc_40a8df: // 0000:40a8df
    memoryASet32(ds, 0x42d040, eax);
loc_40a8e4: // 0000:40a8e4
    push32(0x00000004);
    push32(eax);
    sub_40be39();
    ecx = pop32();
    memoryASet32(ds, 0x42c028, eax);
    ecx = pop32();
    if (eax)
        goto loc_40a918;
    push32(0x00000004);
    push32(esi);
    memoryASet32(ds, 0x42d040, esi);
    sub_40be39();
    ecx = pop32();
    memoryASet32(ds, 0x42c028, eax);
    ecx = pop32();
    if (eax)
        goto loc_40a918;
    push32(0x0000001a);
    sub_406f73();
    ecx = pop32();
loc_40a918: // 0000:40a918
    ecx = 0;
    eax = 0x0040f280;
loc_40a91f: // 0000:40a91f
    edx = memoryAGet32(ds, 0x42c028);
    memoryASet32(ds, ecx + edx, eax);
    eax += 0x00000020;
    ecx += 0x00000004;
    if ((int32_t)eax < (int32_t)0x0040f500)
        goto loc_40a91f;
    edx = 0;
    ecx = 0x0040f290;
loc_40a93c: // 0000:40a93c
    eax = edx;
    esi = edx;
    eax = sar32(eax, 0x05);
    esi &= 0x0000001f;
    eax = memoryAGet32(ds, eax * 4 + 0x42d060);
    eax = memoryAGet32(ds, eax + esi * 8);
    if (eax == 0xffffffff)
        goto loc_40a959;
    if (eax)
        goto loc_40a95c;
loc_40a959: // 0000:40a959
    memoryASet32(ds, ecx, memoryAGet32(ds, ecx) | 0xffffffff);
loc_40a95c: // 0000:40a95c
    ecx += 0x00000020;
    edx++;
    if ((int32_t)ecx < (int32_t)0x0040f2f0)
        goto loc_40a93c;
    esi = pop32();
    esp += 4;
}
void sub_40a97e() // 0000:40a97e +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    eax = memoryAGet32(ss, ebp + 0x8);
    if (eax)
        goto loc_40a98a;
    ebp = pop32();
    esp += 4; return;
loc_40a98a: // 0000:40a98a
    if (memoryAGet32(ds, 0x40fc94))
        goto loc_40a9a5;
    cx = memoryAGet16(ss, ebp + 0xc);
    if (cx > 0x00ff)
        goto loc_40a9d7;
    push32(0x00000001);
    memoryASet(ds, eax, cl);
    eax = pop32();
    ebp = pop32();
    esp += 4; return;
loc_40a9a5: // 0000:40a9a5
    ecx = ebp + 8;
    memoryASet32(ss, ebp + 0x8, memoryAGet32(ss, ebp + 0x8) & 0x00000000);
    push32(ecx);
    push32(0x00000000);
    push32(memoryAGet32(ds, 0x40f030));
    push32(eax);
    eax = ebp + 12;
    push32(0x00000001);
    push32(eax);
    push32(0x00000220);
    push32(memoryAGet32(ds, 0x40fca4));
    eax = kernel32::WideCharToMultiByte(stack32<UINT>(0), stack32<DWORD>(1), stack32<LPCWSTR>(2), stack32<int>(3), stack32<LPSTR>(4), stack32<int>(5), stack32<LPCSTR>(6), stack32<LPBOOL>(7)); esp += 32;();
    if (!eax)
        goto loc_40a9d7;
    if (!memoryAGet32(ss, ebp + 0x8))
        goto loc_40a9e4;
loc_40a9d7: // 0000:40a9d7
    memoryASet32(ds, 0x40fab8, 0x0000002a);
    eax |= 0xffffffff;
loc_40a9e4: // 0000:40a9e4
    ebp = pop32();
    esp += 4;
}
void sub_40a9f0() // 0000:40a9f0 +long +stackDrop16
{
    esp -= 4;
    push32(ebx);
    push32(esi);
    eax = memoryAGet32(ds, esp + 0x18);
    if (eax)
        goto loc_40aa12;
    ecx = memoryAGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, esp + 0x10);
    edx = 0;
    div32(ecx);
    ebx = eax;
    eax = memoryAGet32(ds, esp + 0xc);
    div32(ecx);
    edx = ebx;
    goto loc_40aa53;
loc_40aa12: // 0000:40aa12
    ecx = eax;
    ebx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, esp + 0x10);
    eax = memoryAGet32(ds, esp + 0xc);
loc_40aa20: // 0000:40aa20
    flags.carry = ecx & 1;
    ecx >>= 1;
    ebx = rcr32(ebx, 0x00000001);
    flags.carry = edx & 1;
    edx >>= 1;
    eax = rcr32(eax, 0x00000001);
    if (ecx)
        goto loc_40aa20;
    div32(ebx);
    esi = eax;
    mul32(memoryAGet32(ds, esp + 0x18));
    ecx = eax;
    eax = memoryAGet32(ds, esp + 0x14);
    mul32(esi);
    flags.carry = (uint64_t)edx + ecx >= 0x100000000;
    edx += ecx;
    if (flags.carry)
        goto loc_40aa4e;
    if (edx > memoryAGet32(ds, esp + 0x10))
        goto loc_40aa4e;
    if (edx < memoryAGet32(ds, esp + 0x10))
        goto loc_40aa4f;
    if (eax <= memoryAGet32(ds, esp + 0xc))
        goto loc_40aa4f;
loc_40aa4e: // 0000:40aa4e
    esi--;
loc_40aa4f: // 0000:40aa4f
    edx = 0;
    eax = esi;
loc_40aa53: // 0000:40aa53
    esi = pop32();
    ebx = pop32();
    esp += 20;
}
void sub_40aa60() // 0000:40aa60 +long +stackDrop16
{
    esp -= 4;
    push32(ebx);
    eax = memoryAGet32(ds, esp + 0x14);
    if (eax)
        goto loc_40aa81;
    ecx = memoryAGet32(ds, esp + 0x10);
    eax = memoryAGet32(ds, esp + 0xc);
    edx = 0;
    div32(ecx);
    eax = memoryAGet32(ds, esp + 0x8);
    div32(ecx);
    eax = edx;
    edx = 0;
    goto loc_40aad1;
loc_40aa81: // 0000:40aa81
    ecx = eax;
    ebx = memoryAGet32(ds, esp + 0x10);
    edx = memoryAGet32(ds, esp + 0xc);
    eax = memoryAGet32(ds, esp + 0x8);
loc_40aa8f: // 0000:40aa8f
    flags.carry = ecx & 1;
    ecx >>= 1;
    ebx = rcr32(ebx, 0x00000001);
    flags.carry = edx & 1;
    edx >>= 1;
    eax = rcr32(eax, 0x00000001);
    if (ecx)
        goto loc_40aa8f;
    div32(ebx);
    ecx = eax;
    mul32(memoryAGet32(ds, esp + 0x14));
    etx = ecx; ecx = eax; eax = etx;
    mul32(memoryAGet32(ds, esp + 0x10));
    flags.carry = (uint64_t)edx + ecx >= 0x100000000;
    edx += ecx;
    if (flags.carry)
        goto loc_40aaba;
    if (edx > memoryAGet32(ds, esp + 0xc))
        goto loc_40aaba;
    if (edx < memoryAGet32(ds, esp + 0xc))
        goto loc_40aac2;
    if (eax <= memoryAGet32(ds, esp + 0x8))
        goto loc_40aac2;
loc_40aaba: // 0000:40aaba
    flags.carry = eax < memoryAGet32(ds, esp + 0x10);
    eax -= memoryAGet32(ds, esp + 0x10);
    edx -= memoryAGet32(ds, esp + 0x14) + flags.carry;
loc_40aac2: // 0000:40aac2
    flags.carry = eax < memoryAGet32(ds, esp + 0x8);
    eax -= memoryAGet32(ds, esp + 0x8);
    edx -= memoryAGet32(ds, esp + 0xc) + flags.carry;
    edx = -edx;
    flags.carry = eax != 0;
    eax = -eax;
    edx -= (0x00000000 + flags.carry);
loc_40aad1: // 0000:40aad1
    ebx = pop32();
    esp += 20;
}
void sub_40aad5() // 0000:40aad5 +long
{
    esp -= 4;
    push32(0x00000004);
    push32(0x00000000);
    push32(memoryAGet32(ds, esp + 0xc));
    sub_40aae6();
    esp += 0x0000000c;
    esp += 4;
}
void sub_40aae6() // 0000:40aae6 +long
{
    esp -= 4;
    eax = memoryAGet(ds, esp + 0x4);
    cl = memoryAGet(ds, esp + 0xc);
    if (memoryAGet(ds, eax + 0x42bf21) & cl)
        goto loc_40ab13;
    if (!memoryAGet32(ds, esp + 0x8))
        goto loc_40ab0c;
    eax = memoryAGet16(ds, eax * 2 + 0x40f046);
    eax &= memoryAGet32(ds, esp + 0x8);
    goto loc_40ab0e;
loc_40ab0c: // 0000:40ab0c
    eax = 0;
loc_40ab0e: // 0000:40ab0e
    if (eax)
        goto loc_40ab13;
    esp += 4; return;
loc_40ab13: // 0000:40ab13
    push32(0x00000001);
    eax = pop32();
    esp += 4;
}
void sub_40ab17() // 0000:40ab17 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000018;
    push32(ebx);
    push32(esi);
    push32(edi);
    push32(memoryAGet32(ss, ebp + 0x8));
    sub_40acb0();
    esi = eax;
    ecx = pop32();
    memoryASet32(ss, ebp + 0x8, esi);
    if (esi == memoryAGet32(ds, 0x42be04))
        goto loc_40aca4;
    ebx = 0;
    if (esi == ebx)
        goto loc_40ac9a;
    edx = 0;
    eax = 0x0040f508;
loc_40ab4b: // 0000:40ab4b
    if (memoryAGet32(ds, eax) == esi)
        goto loc_40abc1;
    eax += 0x00000030;
    edx++;
    if ((int32_t)eax < (int32_t)0x0040f5f8)
        goto loc_40ab4b;
    eax = ebp - 24;
    push32(eax);
    push32(esi);
    eax = kernel32::GetCPInfo(stack32<UINT>(0), stack32<LPCPINFO>(1)); esp += 8;();
    if (eax != 0x00000001)
        goto loc_40ac92;
    push32(0x00000040);
    eax = 0;
    ecx = pop32();
    edi = 0x0042bf20;
    memoryASet32(ds, 0x42be04, esi);
    for (; ecx != 0; --ecx) stosd<ES_EDI>(eax);
    stosb<ES_EDI>(al);
    memoryASet32(ds, 0x42c024, ebx);
    if (memoryAGet32(ss, ebp - 24) <= 0x00000001)
        goto loc_40ac80;
    if (!memoryAGet(ss, ebp - 18))
        goto loc_40ac56;
    ecx = ebp - 17;
loc_40ab9e: // 0000:40ab9e
    dl = memoryAGet(ds, ecx);
    if (!dl)
        goto loc_40ac56;
    eax = memoryAGet(ds, ecx - 1);
    edx = dl;
loc_40abaf: // 0000:40abaf
    if (eax > edx)
        goto loc_40ac4a;
    memoryASet(ds, eax + 0x42bf21, memoryAGet(ds, eax + 0x42bf21) | 0x04);
    eax++;
    goto loc_40abaf;
loc_40abc1: // 0000:40abc1
    push32(0x00000040);
    eax = 0;
    ecx = pop32();
    edi = 0x0042bf20;
    for (; ecx != 0; --ecx) stosd<ES_EDI>(eax);
    esi = edx + (edx * 2);
    memoryASet32(ss, ebp - 4, ebx);
    esi <<= 4;
    stosb<ES_EDI>(al);
    ebx = esi + 4257048;
loc_40abdd: // 0000:40abdd
    ecx = ebx;
    if (!memoryAGet(ds, ebx))
        goto loc_40ac10;
loc_40abe4: // 0000:40abe4
    dl = memoryAGet(ds, ecx + 0x1);
    if (!dl)
        goto loc_40ac10;
    eax = memoryAGet(ds, ecx);
    edi = dl;
    if (eax > edi)
        goto loc_40ac09;
    edx = memoryAGet32(ss, ebp - 4);
    dl = memoryAGet(ds, edx + 0x40f500);
loc_40abfe: // 0000:40abfe
    memoryASet(ds, eax + 0x42bf21, memoryAGet(ds, eax + 0x42bf21) | dl);
    eax++;
    if (eax <= edi)
        goto loc_40abfe;
loc_40ac09: // 0000:40ac09
    ecx++;
    ecx++;
    if (memoryAGet(ds, ecx))
        goto loc_40abe4;
loc_40ac10: // 0000:40ac10
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) + 1);
    ebx += 0x00000008;
    if (memoryAGet32(ss, ebp - 4) < 0x00000004)
        goto loc_40abdd;
    eax = memoryAGet32(ss, ebp + 0x8);
    memoryASet32(ds, 0x42be1c, 0x00000001);
    push32(eax);
    memoryASet32(ds, 0x42be04, eax);
    sub_40acfa();
    esi = esi + 4257036;
    edi = 0x0042be10;
    movsd<ES_EDI, DS_ESI>();
    movsd<ES_EDI, DS_ESI>();
    ecx = pop32();
    memoryASet32(ds, 0x42c024, eax);
    movsd<ES_EDI, DS_ESI>();
    goto loc_40ac9f;
loc_40ac4a: // 0000:40ac4a
    ecx++;
    ecx++;
    if (memoryAGet(ds, ecx - 1))
        goto loc_40ab9e;
loc_40ac56: // 0000:40ac56
    push32(0x00000001);
    eax = pop32();
loc_40ac59: // 0000:40ac59
    memoryASet(ds, eax + 0x42bf21, memoryAGet(ds, eax + 0x42bf21) | 0x08);
    eax++;
    if (eax < 0x000000ff)
        goto loc_40ac59;
    push32(esi);
    sub_40acfa();
    ecx = pop32();
    memoryASet32(ds, 0x42c024, eax);
    memoryASet32(ds, 0x42be1c, 0x00000001);
    goto loc_40ac86;
loc_40ac80: // 0000:40ac80
    memoryASet32(ds, 0x42be1c, ebx);
loc_40ac86: // 0000:40ac86
    eax = 0;
    edi = 0x0042be10;
    stosd<ES_EDI>(eax);
    stosd<ES_EDI>(eax);
    stosd<ES_EDI>(eax);
    goto loc_40ac9f;
loc_40ac92: // 0000:40ac92
    if (memoryAGet32(ds, 0x40fc74) == ebx)
        goto loc_40aca8;
loc_40ac9a: // 0000:40ac9a
    sub_40ad2d();
loc_40ac9f: // 0000:40ac9f
    sub_40ad56();
loc_40aca4: // 0000:40aca4
    eax = 0;
    goto loc_40acab;
loc_40aca8: // 0000:40aca8
    eax |= 0xffffffff;
loc_40acab: // 0000:40acab
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_40acb0() // 0000:40acb0 +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    memoryASet32(ds, 0x40fc74, memoryAGet32(ds, 0x40fc74) & 0x00000000);
    if (eax != 0xfffffffe)
        goto loc_40acd0;
    memoryASet32(ds, 0x40fc74, 0x00000001);
    indirectJump(cs, memoryAGet32(ds, 0x40d024)); return; // 0000:40acca
loc_40acd0: // 0000:40acd0
    if (eax != 0xfffffffd)
        goto loc_40ace5;
    memoryASet32(ds, 0x40fc74, 0x00000001);
    indirectJump(cs, memoryAGet32(ds, 0x40d028)); return; // 0000:40acdf
loc_40ace5: // 0000:40ace5
    if (eax != 0xfffffffc)
        goto loc_40acf9;
    eax = memoryAGet32(ds, 0x40fca4);
    memoryASet32(ds, 0x40fc74, 0x00000001);
loc_40acf9: // 0000:40acf9
    esp += 4; return;
}
void sub_40acfa() // 0000:40acfa +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    eax -= 0x000003a4;
    if (!eax)
        goto loc_40ad27;
    eax -= 0x00000004;
    if (!eax)
        goto loc_40ad21;
    eax -= 0x0000000d;
    if (!eax)
        goto loc_40ad1b;
    eax--;
    if (!eax)
        goto loc_40ad15;
    eax = 0;
    esp += 4; return;
loc_40ad15: // 0000:40ad15
    eax = 0x00000404;
    esp += 4; return;
loc_40ad1b: // 0000:40ad1b
    eax = 0x00000412;
    esp += 4; return;
loc_40ad21: // 0000:40ad21
    eax = 0x00000804;
    esp += 4; return;
loc_40ad27: // 0000:40ad27
    eax = 0x00000411;
    esp += 4;
}
void sub_40ad2d() // 0000:40ad2d +long
{
    esp -= 4;
    push32(edi);
    push32(0x00000040);
    ecx = pop32();
    eax = 0;
    edi = 0x0042bf20;
    for (; ecx != 0; --ecx) stosd<ES_EDI>(eax);
    stosb<ES_EDI>(al);
    eax = 0;
    edi = 0x0042be10;
    memoryASet32(ds, 0x42be04, eax);
    memoryASet32(ds, 0x42be1c, eax);
    memoryASet32(ds, 0x42c024, eax);
    stosd<ES_EDI>(eax);
    stosd<ES_EDI>(eax);
    stosd<ES_EDI>(eax);
    edi = pop32();
    esp += 4;
}
void sub_40ad56() // 0000:40ad56 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    esp -= 0x00000514;
    eax = ebp - 20;
    push32(esi);
    push32(eax);
    push32(memoryAGet32(ds, 0x42be04));
    eax = kernel32::GetCPInfo(stack32<UINT>(0), stack32<LPCPINFO>(1)); esp += 8;();
    if (eax != 0x00000001)
        goto loc_40ae8f;
    eax = 0;
    esi = 0x00000100;
loc_40ad80: // 0000:40ad80
    memoryASet(ss, ebp + eax - 276, al);
    eax++;
    if (eax < esi)
        goto loc_40ad80;
    al = memoryAGet(ss, ebp - 14);
    memoryASet(ss, ebp - 276, 0x20);
    if (!al)
        goto loc_40add1;
    push32(ebx);
    push32(edi);
    edx = ebp - 13;
loc_40ad9f: // 0000:40ad9f
    ecx = memoryAGet(ds, edx);
    eax = al;
    if (eax > ecx)
        goto loc_40adc6;
    ecx -= eax;
    edi = (ebp + eax) + -276;
    ecx++;
    eax = 0x20202020;
    ebx = ecx;
    ecx >>= 2;
    for (; ecx != 0; --ecx) stosd<ES_EDI>(eax);
    ecx = ebx;
    ecx &= 0x00000003;
    for (; ecx != 0; --ecx) stosb<ES_EDI>(al);
loc_40adc6: // 0000:40adc6
    edx++;
    edx++;
    al = memoryAGet(ds, edx - 1);
    if (al)
        goto loc_40ad9f;
    edi = pop32();
    ebx = pop32();
loc_40add1: // 0000:40add1
    push32(0x00000000);
    eax = ebp - 1300;
    push32(memoryAGet32(ds, 0x42c024));
    push32(memoryAGet32(ds, 0x42be04));
    push32(eax);
    eax = ebp - 276;
    push32(esi);
    push32(eax);
    push32(0x00000001);
    sub_40b07e();
    push32(0x00000000);
    eax = ebp - 532;
    push32(memoryAGet32(ds, 0x42be04));
    push32(esi);
    push32(eax);
    eax = ebp - 276;
    push32(esi);
    push32(eax);
    push32(esi);
    push32(memoryAGet32(ds, 0x42c024));
    sub_40b1c7();
    push32(0x00000000);
    eax = ebp - 788;
    push32(memoryAGet32(ds, 0x42be04));
    push32(esi);
    push32(eax);
    eax = ebp - 276;
    push32(esi);
    push32(eax);
    push32(0x00000200);
    push32(memoryAGet32(ds, 0x42c024));
    sub_40b1c7();
    esp += 0x0000005c;
    eax = 0;
    ecx = ebp - 1300;
loc_40ae4c: // 0000:40ae4c
    dx = memoryAGet16(ds, ecx);
    if (!(dl & 0x01))
        goto loc_40ae6a;
    memoryASet(ds, eax + 0x42bf21, memoryAGet(ds, eax + 0x42bf21) | 0x10);
    dl = memoryAGet(ss, ebp + eax - 532);
loc_40ae62: // 0000:40ae62
    memoryASet(ds, eax + 0x42be20, dl);
    goto loc_40ae86;
loc_40ae6a: // 0000:40ae6a
    if (!(dl & 0x02))
        goto loc_40ae7f;
    memoryASet(ds, eax + 0x42bf21, memoryAGet(ds, eax + 0x42bf21) | 0x20);
    dl = memoryAGet(ss, ebp + eax - 788);
    goto loc_40ae62;
loc_40ae7f: // 0000:40ae7f
    memoryASet(ds, eax + 0x42be20, memoryAGet(ds, eax + 0x42be20) & 0x00);
loc_40ae86: // 0000:40ae86
    eax++;
    ecx++;
    ecx++;
    if (eax < esi)
        goto loc_40ae4c;
    goto loc_40aed8;
loc_40ae8f: // 0000:40ae8f
    eax = 0;
    esi = 0x00000100;
loc_40ae96: // 0000:40ae96
    if (eax < 0x00000041)
        goto loc_40aeb4;
    if (eax > 0x0000005a)
        goto loc_40aeb4;
    memoryASet(ds, eax + 0x42bf21, memoryAGet(ds, eax + 0x42bf21) | 0x10);
    cl = al;
    cl += 0x20;
loc_40aeac: // 0000:40aeac
    memoryASet(ds, eax + 0x42be20, cl);
    goto loc_40aed3;
loc_40aeb4: // 0000:40aeb4
    if (eax < 0x00000061)
        goto loc_40aecc;
    if (eax > 0x0000007a)
        goto loc_40aecc;
    memoryASet(ds, eax + 0x42bf21, memoryAGet(ds, eax + 0x42bf21) | 0x20);
    cl = al;
    cl -= 0x20;
    goto loc_40aeac;
loc_40aecc: // 0000:40aecc
    memoryASet(ds, eax + 0x42be20, memoryAGet(ds, eax + 0x42be20) & 0x00);
loc_40aed3: // 0000:40aed3
    eax++;
    if (eax < esi)
        goto loc_40ae96;
loc_40aed8: // 0000:40aed8
    esi = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_40aedb() // 0000:40aedb +long
{
    esp -= 4;
    if (memoryAGet32(ds, 0x42d188))
        goto loc_40aef6;
    push32(0xfffffffd);
    sub_40ab17();
    ecx = pop32();
    memoryASet32(ds, 0x42d188, 0x00000001);
loc_40aef6: // 0000:40aef6
    esp += 4; return;
}
void sub_40aef7() // 0000:40aef7 +long
{
    esp -= 4;
    push32(ebx);
    ebx = 0;
    push32(esi);
    push32(edi);
    if (memoryAGet32(ds, 0x40fc78) != ebx)
        goto loc_40af46;
    push32(0x0040d708);
    eax = kernel32::LoadLibraryA(stack32<LPCSTR>(0)); esp += 4;();
    edi = eax;
    if (edi == ebx)
        goto loc_40af7c;
    esi = memoryAGet32(ds, 0x40d068);
    push32(0x0040d6fc);
    push32(edi);
    indirectCall(cs, esi); // 0000:40af21
    memoryASet32(ds, 0x40fc78, eax);
    if (!eax)
        goto loc_40af7c;
    push32(0x0040d6ec);
    push32(edi);
    indirectCall(cs, esi); // 0000:40af32
    push32(0x0040d6d8);
    push32(edi);
    memoryASet32(ds, 0x40fc7c, eax);
    indirectCall(cs, esi); // 0000:40af3f
    memoryASet32(ds, 0x40fc80, eax);
loc_40af46: // 0000:40af46
    eax = memoryAGet32(ds, 0x40fc7c);
    if (!eax)
        goto loc_40af65;
    indirectCall(cs, eax); // 0000:40af4f
    ebx = eax;
    if (!ebx)
        goto loc_40af65;
    eax = memoryAGet32(ds, 0x40fc80);
    if (!eax)
        goto loc_40af65;
    push32(ebx);
    indirectCall(cs, eax); // 0000:40af61
    ebx = eax;
loc_40af65: // 0000:40af65
    push32(memoryAGet32(ds, esp + 0x18));
    push32(memoryAGet32(ds, esp + 0x18));
    push32(memoryAGet32(ds, esp + 0x18));
    push32(ebx);
    indirectCall(cs, memoryAGet32(ds, 0x40fc78)); // 0000:40af72
loc_40af78: // 0000:40af78
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp += 4; return;
loc_40af7c: // 0000:40af7c
    eax = 0;
    goto loc_40af78;
}
void sub_40af80() // 0000:40af80 +long
{
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0xc);
    push32(edi);
    if (!ecx)
        goto loc_40b003;
    push32(esi);
    push32(ebx);
    ebx = ecx;
    esi = memoryAGet32(ds, esp + 0x14);
    edi = memoryAGet32(ds, esp + 0x10);
    if (esi & 0x00000003)
        goto loc_40afa4;
    ecx >>= 2;
    if (ecx)
        goto loc_40b011;
    goto loc_40afc5;
loc_40afa4: // 0000:40afa4
    al = memoryAGet(ds, esi);
    esi++;
    memoryASet(ds, edi, al);
    edi++;
    ecx--;
    if (!ecx)
        goto loc_40afd2;
    if (!al)
        goto loc_40afda;
    if (esi & 0x00000003)
        goto loc_40afa4;
    ebx = ecx;
    ecx >>= 2;
    if (ecx)
        goto loc_40b011;
loc_40afc0: // 0000:40afc0
    ebx &= 0x00000003;
    if (!ebx)
        goto loc_40afd2;
loc_40afc5: // 0000:40afc5
    al = memoryAGet(ds, esi);
    esi++;
    memoryASet(ds, edi, al);
    edi++;
    if (!al)
        goto loc_40affe;
    ebx--;
    if (ebx)
        goto loc_40afc5;
loc_40afd2: // 0000:40afd2
    eax = memoryAGet32(ds, esp + 0x10);
    ebx = pop32();
    esi = pop32();
    edi = pop32();
    esp += 4; return;
loc_40afda: // 0000:40afda
    if (!(edi & 0x00000003))
        goto loc_40aff4;
loc_40afe2: // 0000:40afe2
    memoryASet(ds, edi, al);
    edi++;
    ecx--;
    if (!ecx)
        goto loc_40b076;
    if (edi & 0x00000003)
        goto loc_40afe2;
loc_40aff4: // 0000:40aff4
    ebx = ecx;
    ecx >>= 2;
    if (ecx)
        goto loc_40b067;
loc_40affb: // 0000:40affb
    memoryASet(ds, edi, al);
    edi++;
loc_40affe: // 0000:40affe
    ebx--;
    if (ebx)
        goto loc_40affb;
    ebx = pop32();
    esi = pop32();
loc_40b003: // 0000:40b003
    eax = memoryAGet32(ds, esp + 0x8);
    edi = pop32();
    esp += 4; return;
loc_40b009: // 0000:40b009
    memoryASet32(ds, edi, edx);
    edi += 0x00000004;
    ecx--;
    if (!ecx)
        goto loc_40afc0;
loc_40b011: // 0000:40b011
    edx = 0x7efefeff;
    eax = memoryAGet32(ds, esi);
    edx += eax;
    eax ^= 0xffffffff;
    eax ^= edx;
    edx = memoryAGet32(ds, esi);
    esi += 0x00000004;
    if (!(eax & 0x81010100))
        goto loc_40b009;
    if (!dl)
        goto loc_40b05b;
    if (!dh)
        goto loc_40b051;
    if (!(edx & 0x00ff0000))
        goto loc_40b047;
    if (edx & 0xff000000)
        goto loc_40b009;
    memoryASet32(ds, edi, edx);
    goto loc_40b05f;
loc_40b047: // 0000:40b047
    edx &= 0x0000ffff;
    memoryASet32(ds, edi, edx);
    goto loc_40b05f;
loc_40b051: // 0000:40b051
    edx &= 0x000000ff;
    memoryASet32(ds, edi, edx);
    goto loc_40b05f;
loc_40b05b: // 0000:40b05b
    edx = 0;
    memoryASet32(ds, edi, edx);
loc_40b05f: // 0000:40b05f
    edi += 0x00000004;
    eax = 0;
    ecx--;
    if (!ecx)
        goto loc_40b071;
loc_40b067: // 0000:40b067
    eax = 0;
loc_40b069: // 0000:40b069
    memoryASet32(ds, edi, eax);
    edi += 0x00000004;
    ecx--;
    if (ecx)
        goto loc_40b069;
loc_40b071: // 0000:40b071
    ebx &= 0x00000003;
    if (ebx)
        goto loc_40affb;
loc_40b076: // 0000:40b076
    eax = memoryAGet32(ds, esp + 0x10);
    ebx = pop32();
    esi = pop32();
    edi = pop32();
    esp += 4;
}
void sub_40b07e() // 0000:40b07e +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(0xffffffff);
    push32(0x0040d720);
    push32(0x00409328);
    eax = memoryAGet32(fs, 0x0);
    push32(eax);
    memoryASet32(fs, 0x0, esp);
    esp -= 0x00000018;
    push32(ebx);
    push32(esi);
    push32(edi);
    memoryASet32(ss, ebp - 24, esp);
    eax = memoryAGet32(ds, 0x40fc84);
    ebx = 0;
    if (eax != ebx)
        goto loc_40b0ed;
    eax = ebp - 28;
    push32(eax);
    push32(0x00000001);
    esi = pop32();
    push32(esi);
    push32(0x0040d718);
    push32(esi);
    eax = kernel32::GetStringTypeW(stack32<DWORD>(0), stack32<LPCWSTR>(1), stack32<int>(2), stack32<LPWORD>(3)); esp += 16;();
    if (!eax)
        goto loc_40b0cb;
    eax = esi;
    goto loc_40b0e8;
loc_40b0cb: // 0000:40b0cb
    eax = ebp - 28;
    push32(eax);
    push32(esi);
    push32(0x0040d714);
    push32(esi);
    push32(ebx);
    eax = kernel32::GetStringTypeA(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPWORD>(4)); esp += 20;();
    if (!eax)
        goto loc_40b1b3;
    push32(0x00000002);
    eax = pop32();
loc_40b0e8: // 0000:40b0e8
    memoryASet32(ds, 0x40fc84, eax);
loc_40b0ed: // 0000:40b0ed
    if (eax != 0x00000002)
        goto loc_40b116;
    eax = memoryAGet32(ss, ebp + 0x1c);
    if (eax != ebx)
        goto loc_40b0fe;
    eax = memoryAGet32(ds, 0x40fc94);
loc_40b0fe: // 0000:40b0fe
    push32(memoryAGet32(ss, ebp + 0x14));
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    push32(eax);
    eax = kernel32::GetStringTypeA(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPWORD>(4)); esp += 20;();
    goto loc_40b1b5;
loc_40b116: // 0000:40b116
    if (eax != 0x00000001)
        goto loc_40b1b3;
    if (memoryAGet32(ss, ebp + 0x18) != ebx)
        goto loc_40b12c;
    eax = memoryAGet32(ds, 0x40fca4);
    memoryASet32(ss, ebp + 0x18, eax);
loc_40b12c: // 0000:40b12c
    push32(ebx);
    push32(ebx);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    eax = memoryAGet32(ss, ebp + 0x20);
    flags.carry = eax != 0;
    eax = -eax;
    eax = -flags.carry;
    eax &= 0x00000008;
    eax++;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x18));
    eax = kernel32::MultiByteToWideChar(stack32<UINT>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;();
    memoryASet32(ss, ebp - 32, eax);
    if (eax == ebx)
        goto loc_40b1b3;
    memoryASet32(ss, ebp - 4, ebx);
    edi = eax + eax;
    eax = edi;
    eax += 0x00000003;
    al &= 0xfc;
    sub_40c020();
    memoryASet32(ss, ebp - 24, esp);
    esi = esp;
    memoryASet32(ss, ebp - 36, esi);
    push32(edi);
    push32(ebx);
    push32(esi);
    sub_40a530();
    esp += 0x0000000c;
    goto loc_40b182;
    // gap 11 bytes // gap 11 bytes
loc_40b182: // 0000:40b182
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0xffffffff);
    if (esi == ebx)
        goto loc_40b1b3;
    push32(memoryAGet32(ss, ebp - 32));
    push32(esi);
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(0x00000001);
    push32(memoryAGet32(ss, ebp + 0x18));
    eax = kernel32::MultiByteToWideChar(stack32<UINT>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;();
    if (eax == ebx)
        goto loc_40b1b3;
    push32(memoryAGet32(ss, ebp + 0x14));
    push32(eax);
    push32(esi);
    push32(memoryAGet32(ss, ebp + 0x8));
    eax = kernel32::GetStringTypeW(stack32<DWORD>(0), stack32<LPCWSTR>(1), stack32<int>(2), stack32<LPWORD>(3)); esp += 16;();
    goto loc_40b1b5;
loc_40b1b3: // 0000:40b1b3
    eax = 0;
loc_40b1b5: // 0000:40b1b5
    esp = ebp - 52;
    ecx = memoryAGet32(ss, ebp - 16);
    memoryASet32(fs, 0x0, ecx);
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4;
}
void sub_40b1c7() // 0000:40b1c7 +long
{
    esp -= 4;
    push32(ebp);
    ebp = esp;
    push32(0xffffffff);
    push32(0x0040d730);
    push32(0x00409328);
    eax = memoryAGet32(fs, 0x0);
    push32(eax);
    memoryASet32(fs, 0x0, esp);
    esp -= 0x0000001c;
    push32(ebx);
    push32(esi);
    push32(edi);
    memoryASet32(ss, ebp - 24, esp);
    edi = 0;
    if (memoryAGet32(ds, 0x40fc88) != edi)
        goto loc_40b23d;
    push32(edi);
    push32(edi);
    push32(0x00000001);
    ebx = pop32();
    push32(ebx);
    push32(0x0040d718);
    esi = 0x00000100;
    push32(esi);
    push32(edi);
    eax = kernel32::LCMapStringW(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCWSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;();
    if (!eax)
        goto loc_40b21b;
    memoryASet32(ds, 0x40fc88, ebx);
    goto loc_40b23d;
loc_40b21b: // 0000:40b21b
    push32(edi);
    push32(edi);
    push32(ebx);
    push32(0x0040d714);
    push32(esi);
    push32(edi);
    eax = kernel32::LCMapStringA(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPSTR>(4), stack32<int>(5)); esp += 24;();
    if (!eax)
        goto loc_40b355;
    memoryASet32(ds, 0x40fc88, 0x00000002);
loc_40b23d: // 0000:40b23d
    if ((int32_t)memoryAGet32(ss, ebp + 0x14) <= (int32_t)edi)
        goto loc_40b252;
    push32(memoryAGet32(ss, ebp + 0x14));
    push32(memoryAGet32(ss, ebp + 0x10));
    sub_40b3eb();
    ecx = pop32();
    ecx = pop32();
    memoryASet32(ss, ebp + 0x14, eax);
loc_40b252: // 0000:40b252
    eax = memoryAGet32(ds, 0x40fc88);
    if (eax != 0x00000002)
        goto loc_40b279;
    push32(memoryAGet32(ss, ebp + 0x1c));
    push32(memoryAGet32(ss, ebp + 0x18));
    push32(memoryAGet32(ss, ebp + 0x14));
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    eax = kernel32::LCMapStringA(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPSTR>(4), stack32<int>(5)); esp += 24;();
    goto loc_40b357;
loc_40b279: // 0000:40b279
    if (eax != 0x00000001)
        goto loc_40b355;
    if (memoryAGet32(ss, ebp + 0x20) != edi)
        goto loc_40b28f;
    eax = memoryAGet32(ds, 0x40fca4);
    memoryASet32(ss, ebp + 0x20, eax);
loc_40b28f: // 0000:40b28f
    push32(edi);
    push32(edi);
    push32(memoryAGet32(ss, ebp + 0x14));
    push32(memoryAGet32(ss, ebp + 0x10));
    eax = memoryAGet32(ss, ebp + 0x24);
    flags.carry = eax != 0;
    eax = -eax;
    eax = -flags.carry;
    eax &= 0x00000008;
    eax++;
    push32(eax);
    push32(memoryAGet32(ss, ebp + 0x20));
    eax = kernel32::MultiByteToWideChar(stack32<UINT>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;();
    ebx = eax;
    memoryASet32(ss, ebp - 28, ebx);
    if (ebx == edi)
        goto loc_40b355;
    memoryASet32(ss, ebp - 4, edi);
    eax = ebx + ebx;
    eax += 0x00000003;
    al &= 0xfc;
    sub_40c020();
    memoryASet32(ss, ebp - 24, esp);
    eax = esp;
    memoryASet32(ss, ebp - 36, eax);
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0xffffffff);
    goto loc_40b2ea;
    // gap 19 bytes // gap 19 bytes
loc_40b2ea: // 0000:40b2ea
    if (memoryAGet32(ss, ebp - 36) == edi)
        goto loc_40b355;
    push32(ebx);
    push32(memoryAGet32(ss, ebp - 36));
    push32(memoryAGet32(ss, ebp + 0x14));
    push32(memoryAGet32(ss, ebp + 0x10));
    push32(0x00000001);
    push32(memoryAGet32(ss, ebp + 0x20));
    eax = kernel32::MultiByteToWideChar(stack32<UINT>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;();
    if (!eax)
        goto loc_40b355;
    push32(edi);
    push32(edi);
    push32(ebx);
    push32(memoryAGet32(ss, ebp - 36));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    eax = kernel32::LCMapStringW(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCWSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;();
    esi = eax;
    memoryASet32(ss, ebp - 40, esi);
    if (esi == edi)
        goto loc_40b355;
    if (!(memoryAGet(ss, ebp + 0xd) & 0x04))
        goto loc_40b369;
    if (memoryAGet32(ss, ebp + 0x1c) == edi)
        goto loc_40b3e4;
    if ((int32_t)esi > (int32_t)memoryAGet32(ss, ebp + 0x1c))
        goto loc_40b355;
    push32(memoryAGet32(ss, ebp + 0x1c));
    push32(memoryAGet32(ss, ebp + 0x18));
    push32(ebx);
    push32(memoryAGet32(ss, ebp - 36));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    eax = kernel32::LCMapStringW(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCWSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;();
    if (eax)
        goto loc_40b3e4;
loc_40b355: // 0000:40b355
    eax = 0;
loc_40b357: // 0000:40b357
    esp = ebp - 56;
    ecx = memoryAGet32(ss, ebp - 16);
    memoryASet32(fs, 0x0, ecx);
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp = ebp; ebp = pop32();
    stop("stack_unbalanced");
    esp += 4; return;
loc_40b369: // 0000:40b369
    memoryASet32(ss, ebp - 4, 0x00000001);
    eax = esi + esi;
    eax += 0x00000003;
    al &= 0xfc;
    sub_40c020();
    memoryASet32(ss, ebp - 24, esp);
    ebx = esp;
    memoryASet32(ss, ebp - 32, ebx);
    memoryASet32(ss, ebp - 4, memoryAGet32(ss, ebp - 4) | 0xffffffff);
    goto loc_40b39d;
    // gap 18 bytes // gap 18 bytes
loc_40b39d: // 0000:40b39d
    if (ebx == edi)
        goto loc_40b355;
    push32(esi);
    push32(ebx);
    push32(memoryAGet32(ss, ebp - 28));
    push32(memoryAGet32(ss, ebp - 36));
    push32(memoryAGet32(ss, ebp + 0xc));
    push32(memoryAGet32(ss, ebp + 0x8));
    eax = kernel32::LCMapStringW(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCWSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;();
    if (!eax)
        goto loc_40b355;
    push32(edi);
    push32(edi);
    if (memoryAGet32(ss, ebp + 0x1c) != edi)
        goto loc_40b3c4;
    push32(edi);
    push32(edi);
    goto loc_40b3ca;
loc_40b3c4: // 0000:40b3c4
    push32(memoryAGet32(ss, ebp + 0x1c));
    push32(memoryAGet32(ss, ebp + 0x18));
loc_40b3ca: // 0000:40b3ca
    push32(esi);
    push32(ebx);
    push32(0x00000220);
    push32(memoryAGet32(ss, ebp + 0x20));
    eax = kernel32::WideCharToMultiByte(stack32<UINT>(0), stack32<DWORD>(1), stack32<LPCWSTR>(2), stack32<int>(3), stack32<LPSTR>(4), stack32<int>(5), stack32<LPCSTR>(6), stack32<LPBOOL>(7)); esp += 32;();
    esi = eax;
    if (esi == edi)
        goto loc_40b355;
loc_40b3e4: // 0000:40b3e4
    eax = esi;
    goto loc_40b357;
}
void sub_40b3eb() // 0000:40b3eb +long
{
    esp -= 4;
    edx = memoryAGet32(ds, esp + 0x8);
    eax = memoryAGet32(ds, esp + 0x4);
    push32(esi);
    ecx = edx - 1;
    if (!edx)
        goto loc_40b408;
loc_40b3fb: // 0000:40b3fb
    if (!memoryAGet(ds, eax))
        goto loc_40b408;
    eax++;
    esi = ecx;
    ecx--;
    if (esi)
        goto loc_40b3fb;
loc_40b408: // 0000:40b408
    esi = pop32();
    if (memoryAGet(ds, eax))
        goto loc_40b413;
    eax -= memoryAGet32(ds, esp + 0x4);
    esp += 4; return;
loc_40b413: // 0000:40b413
    eax = edx;
    esp += 4;
}
void sub_40bd1b() // 0000:40bd1b +long
{
    esp -= 4;
    ecx = memoryAGet32(ds, esp + 0x4);
    edx = 0;
    memoryASet32(ds, 0x40fabc, ecx);
    eax = 0x0040f600;
loc_40bd2c: // 0000:40bd2c
    if (ecx == memoryAGet32(ds, eax))
        goto loc_40bd50;
    eax += 0x00000008;
    edx++;
    if ((int32_t)eax < (int32_t)0x0040f768)
        goto loc_40bd2c;
    if (ecx < 0x00000013)
        goto loc_40bd5d;
    if (ecx > 0x00000024)
        goto loc_40bd5d;
    memoryASet32(ds, 0x40fab8, 0x0000000d);
    esp += 4; return;
loc_40bd50: // 0000:40bd50
    eax = memoryAGet32(ds, edx * 8 + 0x40f604);
    memoryASet32(ds, 0x40fab8, eax);
    esp += 4; return;
loc_40bd5d: // 0000:40bd5d
    if (ecx < 0x000000bc)
        goto loc_40bd77;
    memoryASet32(ds, 0x40fab8, 0x00000008);
    if (ecx <= 0x000000ca)
        goto loc_40bd81;
loc_40bd77: // 0000:40bd77
    memoryASet32(ds, 0x40fab8, 0x00000016);
loc_40bd81: // 0000:40bd81
    esp += 4; return;
}
void sub_40bdfc() // 0000:40bdfc +long
{
    esp -= 4;
    eax = memoryAGet32(ds, esp + 0x4);
    if (eax >= memoryAGet32(ds, 0x42d160))
        goto loc_40be24;
    ecx = eax;
    eax &= 0x0000001f;
    ecx = sar32(ecx, 0x05);
    ecx = memoryAGet32(ds, ecx * 4 + 0x42d060);
    flags.zero = !(memoryAGet(ds, ecx + eax * 8 + 0x4) & 0x01);
    eax = ecx + (eax * 8);
    if (flags.zero)
        goto loc_40be24;
    eax = memoryAGet32(ds, eax);
    esp += 4; return;
loc_40be24: // 0000:40be24
    memoryASet32(ds, 0x40fabc, memoryAGet32(ds, 0x40fabc) & 0x00000000);
    memoryASet32(ds, 0x40fab8, 0x00000009);
    eax |= 0xffffffff;
    esp += 4;
}
void sub_40be39() // 0000:40be39 +long
{
    esp -= 4;
    push32(ebx);
    push32(esi);
    esi = memoryAGet32(ds, esp + 0xc);
    push32(edi);
    esi = (int32_t)esi * ((int32_t)memoryAGet32(ds, esp + 0x14));
    ebx = esi;
    if (esi > 0xffffffe0)
        goto loc_40be59;
    if (esi)
        goto loc_40be53;
    push32(0x00000001);
    esi = pop32();
loc_40be53: // 0000:40be53
    esi += 0x0000000f;
    esi &= 0xfffffff0;
loc_40be59: // 0000:40be59
    edi = 0;
    if (esi > 0xffffffe0)
        goto loc_40be8a;
    if (ebx > memoryAGet32(ds, 0x40eed4))
        goto loc_40be75;
    push32(ebx);
    sub_4073a7();
    edi = eax;
    ecx = pop32();
    if (edi)
        goto loc_40bea0;
loc_40be75: // 0000:40be75
    push32(esi);
    push32(0x00000008);
    push32(memoryAGet32(ds, 0x42d17c));
    eax = kernel32::HeapAlloc(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<SIZE_T>(2)); esp += 12;();
    edi = eax;
    if (edi)
        goto loc_40beac;
loc_40be8a: // 0000:40be8a
    if (!memoryAGet32(ds, 0x40fb18))
        goto loc_40beac;
    push32(esi);
    sub_406fbc();
    ecx = pop32();
    if (!eax)
        goto loc_40beb2;
    goto loc_40be59;
loc_40bea0: // 0000:40bea0
    push32(ebx);
    push32(0x00000000);
    push32(edi);
    sub_40a530();
    esp += 0x0000000c;
loc_40beac: // 0000:40beac
    eax = edi;
loc_40beae: // 0000:40beae
    edi = pop32();
    esi = pop32();
    ebx = pop32();
    esp += 4; return;
loc_40beb2: // 0000:40beb2
    eax = 0;
    goto loc_40beae;
}
void sub_40c020() // 0000:40c020 +long
{
    esp -= 4;
    push32(ecx);
    ecx = esp + 8;
    if (eax < 0x00001000)
        goto loc_40c040;
loc_40c02c: // 0000:40c02c
    ecx -= 0x00001000;
    eax -= 0x00001000;
    if (eax >= 0x00001000)
        goto loc_40c02c;
loc_40c040: // 0000:40c040
    ecx -= eax;
    eax = esp;
    esp = ecx;
    ecx = memoryAGet32(ds, eax);
    eax = memoryAGet32(ds, eax + 0x4);
    push32(eax);
    stop("stack_unbalanced");
    esp += 4;
}
void fixReloc(uint16_t seg)
{
}


