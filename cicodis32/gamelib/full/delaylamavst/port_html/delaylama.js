// Missing imports for msvcrt.h!
// Missing imports for kernel32.h!
// Missing imports for user32.h!
// Missing imports for gdi32.h!
// Missing imports for shell32.h!
// Missing imports for ole32.h!
// No RTTI information found

// Sections of Delay Lama.dll:
//  - .text: 10001000 .. 1000ae75 (40565 bytes)
//  - .rdata: 1000b000 .. 1000ce12 (7698 bytes)
//  - .data: 1000d000 .. 1000d890 (2192 bytes)
//  - .rsrc: 1000e000 .. 10387c68 (3644520 bytes)
//  - .reloc: 10388000 .. 1038b9d8 (14808 bytes)
/*
function init()
{
#include "msvcrt.h"
#include "kernel32.h"
#include "user32.h"
#include "gdi32.h"
#include "shell32.h"
#include "ole32.h"

void sub_1000a9a7();

void init()
{
    loadOverlay("Delay Lama_text.bin", 0x10001000);
    loadOverlay("Delay Lama_rdata.bin", 0x1000b000);
    loadOverlay("Delay Lama_data.bin", 0x1000d000);
    loadOverlay("Delay Lama_rsrc.bin", 0x1000e000);
    loadOverlay("Delay Lama_reloc.bin", 0x10388000);
    esp = 0x1038c000;
    ebp = 0x1038c000;
}

void start()
{
    sub_1000a9a7();
}

enum class ptrImportTable {
    ptr_begin = 0x6ab00000,
    ptr_gdi32_GetCurrentObject, // 0x1000b000 
    ptr_gdi32_DeleteObject, // 0x1000b004 
    ptr_gdi32_SelectObject, // 0x1000b008 
    ptr_gdi32_MoveToEx, // 0x1000b00c 
    ptr_gdi32_LineTo, // 0x1000b010 
    ptr_gdi32_CreatePenIndirect, // 0x1000b014 
    ptr_gdi32_GetStockObject, // 0x1000b018 
    ptr_gdi32_SetTextColor, // 0x1000b01c 
    ptr_gdi32_CreateBrushIndirect, // 0x1000b020 
    ptr_gdi32_SetBkColor, // 0x1000b024 
    ptr_gdi32_CreateCompatibleBitmap, // 0x1000b028 
    ptr_gdi32_CreateCompatibleDC, // 0x1000b02c 
    ptr_gdi32_DeleteDC, // 0x1000b030 
    ptr_gdi32_BitBlt, // 0x1000b034 
    ptr_gdi32_GetObjectA, // 0x1000b038 
    ptr_gdi32_CreateBitmap, // 0x1000b03c 
    ptr_gdi32_DPtoLP, // 0x1000b040 
    ptr_gdi32_CreateSolidBrush, // 0x1000b044 
    ptr_gdi32_SetMapMode, // 0x1000b048 
    ptr_gdi32_GetMapMode, // 0x1000b04c 
    ptr_gdi32_SetBkMode, // 0x1000b050 
    ptr_kernel32_GlobalUnlock, // 0x1000b058 
    ptr_kernel32_MultiByteToWideChar, // 0x1000b05c 
    ptr_kernel32_GlobalLock, // 0x1000b060 
    ptr_kernel32_GlobalSize, // 0x1000b064 
    ptr_kernel32_Sleep, // 0x1000b068 
    ptr_kernel32_GlobalFree, // 0x1000b06c 
    ptr_kernel32_GetLastError, // 0x1000b070 
    ptr_kernel32_GetTickCount, // 0x1000b074 
    ptr_msvcrt__stricmp, // 0x1000b07c 
    ptr_msvcrt__adjust_fdiv, // 0x1000b080 
    ptr_msvcrt__initterm, // 0x1000b084 
    ptr_msvcrt_?terminate@@YAXXZ, // 0x1000b088 
    ptr_msvcrt__except_handler3, // 0x1000b08c 
    ptr_msvcrt__purecall, // 0x1000b090 
    ptr_msvcrt_strrchr, // 0x1000b094 
    ptr_msvcrt_realloc, // 0x1000b098 
    ptr_msvcrt_??3@YAXPAX@Z, // 0x1000b09c 
    ptr_msvcrt_free, // 0x1000b0a0 
    ptr_msvcrt_malloc, // 0x1000b0a4 
    ptr_msvcrt___CxxFrameHandler, // 0x1000b0a8 
    ptr_msvcrt_??2@YAPAXI@Z, // 0x1000b0ac 
    ptr_msvcrt_sprintf, // 0x1000b0b0 
    ptr_msvcrt__CIfmod, // 0x1000b0b4 
    ptr_msvcrt__CIpow, // 0x1000b0b8 
    ptr_msvcrt_floor, // 0x1000b0bc 
    ptr_msvcrt__ftol, // 0x1000b0c0 
    ptr_shell32_DragQueryFileA, // 0x1000b0c8 
    ptr_user32_EndPaint, // 0x1000b0d0 
    ptr_user32_BeginPaint, // 0x1000b0d4 
    ptr_user32_GetUpdateRect, // 0x1000b0d8 
    ptr_user32_DefWindowProcA, // 0x1000b0dc 
    ptr_user32_UnregisterClassA, // 0x1000b0e0 
    ptr_user32_GetSysColorBrush, // 0x1000b0e4 
    ptr_user32_RegisterClassA, // 0x1000b0e8 
    ptr_user32_LoadBitmapA, // 0x1000b0ec 
    ptr_user32_SetCursor, // 0x1000b0f0 
    ptr_user32_LoadCursorA, // 0x1000b0f4 
    ptr_user32_GetWindowLongA, // 0x1000b0f8 
    ptr_user32_CreateWindowExA, // 0x1000b0fc 
    ptr_user32_SetWindowLongA, // 0x1000b100 
    ptr_user32_DestroyWindow, // 0x1000b104 
    ptr_user32_GetDC, // 0x1000b108 
    ptr_user32_ReleaseDC, // 0x1000b10c 
    ptr_user32_GetCursorPos, // 0x1000b110 
    ptr_user32_GetAsyncKeyState, // 0x1000b114 
    ptr_user32_FillRect, // 0x1000b118 
    ptr_user32_GetWindowRect, // 0x1000b11c 
    ptr_user32_PeekMessageA, // 0x1000b120 
    ptr_user32_DispatchMessageA, // 0x1000b124 
    ptr_user32_GetCursor, // 0x1000b128 
    ptr_ole32_OleInitialize, // 0x1000b130 
    ptr_ole32_OleUninitialize, // 0x1000b134 
    ptr_ole32_RevokeDragDrop, // 0x1000b138 
    ptr_ole32_RegisterDragDrop, // 0x1000b13c 
    ptr_ole32_CoCreateInstance, // 0x1000b140 
};

void indirectCall(int s, int o) {
    switch ((ptrImportTable)o) {
        case ptrImportTable::ptr_gdi32_GetCurrentObject:
            eax = gdi32::GetCurrentObject();
            break; // 6ab00001
        case ptrImportTable::ptr_gdi32_DeleteObject:
            eax = gdi32::DeleteObject();
            break; // 6ab00002
        case ptrImportTable::ptr_gdi32_SelectObject:
            eax = gdi32::SelectObject();
            break; // 6ab00003
        case ptrImportTable::ptr_gdi32_MoveToEx:
            eax = gdi32::MoveToEx();
            break; // 6ab00004
        case ptrImportTable::ptr_gdi32_LineTo:
            eax = gdi32::LineTo();
            break; // 6ab00005
        case ptrImportTable::ptr_gdi32_CreatePenIndirect:
            eax = gdi32::CreatePenIndirect();
            break; // 6ab00006
        case ptrImportTable::ptr_gdi32_GetStockObject:
            eax = gdi32::GetStockObject();
            break; // 6ab00007
        case ptrImportTable::ptr_gdi32_SetTextColor:
            eax = gdi32::SetTextColor();
            break; // 6ab00008
        case ptrImportTable::ptr_gdi32_CreateBrushIndirect:
            eax = gdi32::CreateBrushIndirect();
            break; // 6ab00009
        case ptrImportTable::ptr_gdi32_SetBkColor:
            eax = gdi32::SetBkColor();
            break; // 6ab0000a
        case ptrImportTable::ptr_gdi32_CreateCompatibleBitmap:
            eax = gdi32::CreateCompatibleBitmap();
            break; // 6ab0000b
        case ptrImportTable::ptr_gdi32_CreateCompatibleDC:
            eax = gdi32::CreateCompatibleDC();
            break; // 6ab0000c
        case ptrImportTable::ptr_gdi32_DeleteDC:
            eax = gdi32::DeleteDC();
            break; // 6ab0000d
        case ptrImportTable::ptr_gdi32_BitBlt:
            eax = gdi32::BitBlt();
            break; // 6ab0000e
        case ptrImportTable::ptr_gdi32_GetObjectA:
            eax = gdi32::GetObjectA();
            break; // 6ab0000f
        case ptrImportTable::ptr_gdi32_CreateBitmap:
            eax = gdi32::CreateBitmap();
            break; // 6ab00010
        case ptrImportTable::ptr_gdi32_DPtoLP:
            eax = gdi32::DPtoLP();
            break; // 6ab00011
        case ptrImportTable::ptr_gdi32_CreateSolidBrush:
            eax = gdi32::CreateSolidBrush();
            break; // 6ab00012
        case ptrImportTable::ptr_gdi32_SetMapMode:
            eax = gdi32::SetMapMode();
            break; // 6ab00013
        case ptrImportTable::ptr_gdi32_GetMapMode:
            eax = gdi32::GetMapMode();
            break; // 6ab00014
        case ptrImportTable::ptr_gdi32_SetBkMode:
            eax = gdi32::SetBkMode();
            break; // 6ab00015
        case ptrImportTable::ptr_kernel32_GlobalUnlock:
            eax = kernel32::GlobalUnlock();
            break; // 6ab00016
        case ptrImportTable::ptr_kernel32_MultiByteToWideChar:
            eax = kernel32::MultiByteToWideChar();
            break; // 6ab00017
        case ptrImportTable::ptr_kernel32_GlobalLock:
            eax = kernel32::GlobalLock();
            break; // 6ab00018
        case ptrImportTable::ptr_kernel32_GlobalSize:
            eax = kernel32::GlobalSize();
            break; // 6ab00019
        case ptrImportTable::ptr_kernel32_Sleep:
            eax = kernel32::Sleep();
            break; // 6ab0001a
        case ptrImportTable::ptr_kernel32_GlobalFree:
            eax = kernel32::GlobalFree();
            break; // 6ab0001b
        case ptrImportTable::ptr_kernel32_GetLastError:
            eax = kernel32::GetLastError();
            break; // 6ab0001c
        case ptrImportTable::ptr_kernel32_GetTickCount:
            eax = kernel32::GetTickCount();
            break; // 6ab0001d
        case ptrImportTable::ptr_msvcrt__stricmp:
            eax = msvcrt::_stricmp();
            break; // 6ab0001e
        case ptrImportTable::ptr_msvcrt__adjust_fdiv:
            eax = msvcrt::_adjust_fdiv();
            break; // 6ab0001f
        case ptrImportTable::ptr_msvcrt__initterm:
            eax = msvcrt::_initterm();
            break; // 6ab00020
//        case ptrImportTable::ptr_msvcrt_?terminate@@YAXXZ:
//            eax = msvcrt::terminate(?, void, void, ?)();
//            break; // 6ab00021
        case ptrImportTable::ptr_msvcrt__except_handler3:
            eax = msvcrt::_except_handler3();
            break; // 6ab00022
        case ptrImportTable::ptr_msvcrt__purecall:
            eax = msvcrt::_purecall();
            break; // 6ab00023
        case ptrImportTable::ptr_msvcrt_strrchr:
            eax = msvcrt::strrchr();
            break; // 6ab00024
        case ptrImportTable::ptr_msvcrt_realloc:
            eax = msvcrt::realloc();
            break; // 6ab00025
//        case ptrImportTable::ptr_msvcrt_??3@YAXPAX@Z:
//            eax = msvcrt::YAXPAX::?3()();
//            break; // 6ab00026
        case ptrImportTable::ptr_msvcrt_free:
            eax = msvcrt::free();
            break; // 6ab00027
        case ptrImportTable::ptr_msvcrt_malloc:
            eax = msvcrt::malloc();
            break; // 6ab00028
        case ptrImportTable::ptr_msvcrt___CxxFrameHandler:
            eax = msvcrt::__CxxFrameHandler();
            break; // 6ab00029
        case ptrImportTable::ptr_msvcrt_??2@YAPAXI@Z:
            eax = msvcrt::YAPAXI::?2()();
            break; // 6ab0002a
        case ptrImportTable::ptr_msvcrt_sprintf:
            eax = msvcrt::sprintf();
            break; // 6ab0002b
        case ptrImportTable::ptr_msvcrt__CIfmod:
            eax = msvcrt::_CIfmod();
            break; // 6ab0002c
        case ptrImportTable::ptr_msvcrt__CIpow:
            eax = msvcrt::_CIpow();
            break; // 6ab0002d
        case ptrImportTable::ptr_msvcrt_floor:
            eax = msvcrt::floor();
            break; // 6ab0002e
        case ptrImportTable::ptr_msvcrt__ftol:
            eax = msvcrt::_ftol();
            break; // 6ab0002f
        case ptrImportTable::ptr_shell32_DragQueryFileA:
            eax = shell32::DragQueryFileA();
            break; // 6ab00030
        case ptrImportTable::ptr_user32_EndPaint:
            eax = user32::EndPaint();
            break; // 6ab00031
        case ptrImportTable::ptr_user32_BeginPaint:
            eax = user32::BeginPaint();
            break; // 6ab00032
        case ptrImportTable::ptr_user32_GetUpdateRect:
            eax = user32::GetUpdateRect();
            break; // 6ab00033
        case ptrImportTable::ptr_user32_DefWindowProcA:
            eax = user32::DefWindowProcA();
            break; // 6ab00034
        case ptrImportTable::ptr_user32_UnregisterClassA:
            eax = user32::UnregisterClassA();
            break; // 6ab00035
        case ptrImportTable::ptr_user32_GetSysColorBrush:
            eax = user32::GetSysColorBrush();
            break; // 6ab00036
        case ptrImportTable::ptr_user32_RegisterClassA:
            eax = user32::RegisterClassA();
            break; // 6ab00037
        case ptrImportTable::ptr_user32_LoadBitmapA:
            eax = user32::LoadBitmapA();
            break; // 6ab00038
        case ptrImportTable::ptr_user32_SetCursor:
            eax = user32::SetCursor();
            break; // 6ab00039
        case ptrImportTable::ptr_user32_LoadCursorA:
            eax = user32::LoadCursorA();
            break; // 6ab0003a
        case ptrImportTable::ptr_user32_GetWindowLongA:
            eax = user32::GetWindowLongA();
            break; // 6ab0003b
        case ptrImportTable::ptr_user32_CreateWindowExA:
            eax = user32::CreateWindowExA();
            break; // 6ab0003c
        case ptrImportTable::ptr_user32_SetWindowLongA:
            eax = user32::SetWindowLongA();
            break; // 6ab0003d
        case ptrImportTable::ptr_user32_DestroyWindow:
            eax = user32::DestroyWindow();
            break; // 6ab0003e
        case ptrImportTable::ptr_user32_GetDC:
            eax = user32::GetDC();
            break; // 6ab0003f
        case ptrImportTable::ptr_user32_ReleaseDC:
            eax = user32::ReleaseDC();
            break; // 6ab00040
        case ptrImportTable::ptr_user32_GetCursorPos:
            eax = user32::GetCursorPos();
            break; // 6ab00041
        case ptrImportTable::ptr_user32_GetAsyncKeyState:
            eax = user32::GetAsyncKeyState();
            break; // 6ab00042
        case ptrImportTable::ptr_user32_FillRect:
            eax = user32::FillRect();
            break; // 6ab00043
        case ptrImportTable::ptr_user32_GetWindowRect:
            eax = user32::GetWindowRect();
            break; // 6ab00044
        case ptrImportTable::ptr_user32_PeekMessageA:
            eax = user32::PeekMessageA();
            break; // 6ab00045
        case ptrImportTable::ptr_user32_DispatchMessageA:
            eax = user32::DispatchMessageA();
            break; // 6ab00046
        case ptrImportTable::ptr_user32_GetCursor:
            eax = user32::GetCursor();
            break; // 6ab00047
        case ptrImportTable::ptr_ole32_OleInitialize:
            eax = ole32::OleInitialize();
            break; // 6ab00048
        case ptrImportTable::ptr_ole32_OleUninitialize:
            eax = ole32::OleUninitialize();
            break; // 6ab00049
        case ptrImportTable::ptr_ole32_RevokeDragDrop:
            eax = ole32::RevokeDragDrop();
            break; // 6ab0004a
        case ptrImportTable::ptr_ole32_RegisterDragDrop:
            eax = ole32::RegisterDragDrop();
            break; // 6ab0004b
        case ptrImportTable::ptr_ole32_CoCreateInstance:
            eax = ole32::CoCreateInstance();
            break; // 6ab0004c
    }
}

}

function start()
{
    sub_1000a9a7();
}

function fixReloc(seg)
{
}
 */

function init()
{
    loadOverlay("Delay Lama_text.bin", 0x10001000);
    loadOverlay("Delay Lama_rdata.bin", 0x1000b000);
    loadOverlay("Delay Lama_data.bin", 0x1000d000);
    loadOverlay("Delay Lama_rsrc.bin", 0x1000e000);
    loadOverlay("Delay Lama_reloc.bin", 0x10388000);
    r32[esp] = 0x1038c000;
    r32[ebp] = 0x1038c000;
}

function sub_10002db0() // 0000:10002db0 — parameter/state dispatcher (opcodes 0-11)
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    if (r32[eax] > 0x0000000b)
        { pc = 0x10002f9a; break; }
    switch (r32[eax])
    {
        case 0: { pc = 0x10002dc7; break; }
        case 1: { pc = 0x10002de3; break; }
        case 2: { pc = 0x10002e74; break; }
        case 3: { pc = 0x10002e82; break; }
        case 4: { pc = 0x10002f9a; break; }
        case 5: { pc = 0x10002dd5; break; }
        case 6: { pc = 0x10002e58; break; }
        case 7: { pc = 0x10002f9a; break; }
        case 8: { pc = 0x10002f9a; break; }
        case 9: { pc = 0x10002eac; break; }
        case 10: { pc = 0x10002f62; break; }
        case 11: { pc = 0x10002f26; break; }
        default:
            stop("ind 0000:10002dc0");
    }
    break;
  case 0x10002dc7: // opcode 0: set sample rate (raw)
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet32(ds, r32[esi] + 0xb0, r32[eax]);
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x10002dd5: // opcode 5: set something at +0xc8
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet32(ds, r32[esi] + 0xc8, r32[ecx]);
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x10002de3: // opcode 1: set tempo/BPM — FPU ops, calls vtable+4 (opcode 6), sub_10005fb0
    r8[al] = memoryAGet(ds, r32[esi] + 0x6174);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet32(ds, r32[esi] + 0xb4, r32[edx]);
    if (!r8[al])
        { pc = 0x10002e48; break; }
    fld32(memoryAGet32(ds, r32[esp] + 0xc));
    fmul32(memoryAGet32(ds, 0x1000b690));
    r32[eax] = memoryAGet32(ds, r32[esi]);
    fmul32(memoryAGet32(ds, 0x1000b68c));
    fadd32(memoryAGet32(ds, 0x1000b688));
    memoryASet32(ds, r32[esp] + 0xc, fst32());
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet32(ds, r32[esi] + 0xc0, fstp32());
    push32(r32[ecx]);
    push32(0x00000006);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x4));
    fld32(memoryAGet32(ds, r32[esi] + 0xb4));
    memoryASet32(ds, r32[esp] + 0xc, fst32());
    fcomp32(memoryAGet32(ds, r32[esi] + 0xb8));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x40)
        { pc = 0x10002e48; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[ecx] = r32[esi];
    push32(r32[edx]);
    sub_10005fb0();
  case 0x10002e48: // opcode 1 exit
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xb4);
    memoryASet32(ds, r32[esi] + 0xb8, r32[eax]);
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x10002e58: // opcode 6: set computed sample rate at +0xc0 (only if not active)
    r8[al] = memoryAGet(ds, r32[esi] + 0x6174);
    if (r8[al])
        { pc = 0x10002f9a; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet32(ds, r32[esi] + 0xc0, r32[ecx]);
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x10002e74: // opcode 2: set at +0xbc
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet32(ds, r32[esi] + 0xbc, r32[edx]);
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x10002e82: // opcode 3: set at +0xc4, call sub_10005fb0 if active
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet32(ds, r32[esi] + 0xc4, r32[eax]);
    r8[al] = memoryAGet(ds, r32[esi] + 0x6174);
    if (!r8[al])
        { pc = 0x10002f9a; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xb4);
    push32(r32[ecx]);
    r32[ecx] = r32[esi];
    sub_10005fb0();
    r32[esi] = pop32();
    stop("stack_below, 8/4");
    r32[esp] += 12; return;
  case 0x10002eac: // opcode 9: activate — set flag, call vtable+0x218
    fld32(memoryAGet32(ds, r32[esp] + 0xc));
    fcomp32(memoryAGet32(ds, 0x1000b208));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x40)
        { pc = 0x10002edb; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(0x00000040);
    push32(0x00000028);
    push32(0x00000090);
    r32[ecx] = r32[esi];
    memoryASet(ds, r32[esi] + 0x6174, 0x01);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x218));
    r32[esi] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 12; return;
  case 0x10002edb: // opcode 9 alt: deactivate
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6178);
    if (r32[eax])
        { pc = 0x10002f9a; break; }
    r32[eax] = memoryAGet32(ds, r32[esi]);
    push32(0x3e2ab368);
    push32(0x00000006);
    r32[ecx] = r32[esi];
    memoryASet(ds, r32[esi] + 0x6174, 0x00);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x4));
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(0x00000040);
    push32(0x00000028);
    push32(0x00000080);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x6464, 0x00000000);
    memoryASet(ds, r32[esi] + 0x6400, 0x01);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x218));
    r32[esi] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 12; return;
  case 0x10002f26: // opcode 11: set pitch param, call sub_1000a75c, notify via vtable+0x218
    fld32(memoryAGet32(ds, r32[esp] + 0xc));
    fmul32(memoryAGet32(ds, 0x1000b684));
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet(ds, r32[esi] + 0xd4, 0x01);
    memoryASet32(ds, r32[esi] + 0xcc, r32[eax]);
    sub_1000a75c();
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(r32[eax]);
    push32(0x0000000b);
    push32(0x000000b0);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x4110, r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x218));
    r32[esi] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 12; return;
  case 0x10002f62: // opcode 10: similar to 11
    fld32(memoryAGet32(ds, r32[esp] + 0xc));
    fmul32(memoryAGet32(ds, 0x1000b684));
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet(ds, r32[esi] + 0xd5, 0x01);
    memoryASet32(ds, r32[esi] + 0xd0, r32[eax]);
    sub_1000a75c();
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(r32[eax]);
    push32(0x00000000);
    push32(0x000000e0);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x4110, r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x218));
  case 0x10002f9a: // exit
    r32[esi] = pop32();
    r32[esp] += 12;
    return;
  }
}

function sub_100010e0() // 0000:100010e0 +long +stackDrop12
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[edx] = r32[ecx];
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    push32(r32[ebx]);
    push32(r32[ebp]);
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[esi]);
    r32[ebx] = r32[edx] + 32;
    push32(r32[edi]);
    memoryASet32(ds, r32[edx] + 0xc, r32[eax]);
    r32[esi] = 0;
    memoryASet32(ds, r32[edx] + 0x14, r32[ecx]);
    r32[ecx] = 0x00000024;
    r32[eax] = 0;
    r32[edi] = r32[ebx];
    memoryASet32(ds, r32[edx], 0x1000b148);
    memoryASet32(ds, r32[edx] + 0x8, r32[esi]);
    memoryASet32(ds, r32[edx] + 0x10, r32[ebp]);
    memoryASet32(ds, r32[edx] + 0x18, r32[esi]);
    for (; r32[ecx] != 0; --r32[ecx]) stosd_ESEDI(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    memoryASet32(ds, r32[edx] + 0x44, r32[esi]);
    memoryASet32(ds, r32[edx] + 0x38, r32[eax]);
    r32[eax] = 0x00000001;
    memoryASet32(ds, r32[edx] + 0x48, r32[esi]);
    memoryASet32(ds, r32[edx] + 0x4c, r32[esi]);
    memoryASet32(ds, r32[edx] + 0x50, r32[esi]);
    memoryASet32(ds, r32[edx] + 0x54, r32[esi]);
    memoryASet32(ds, r32[edx] + 0x58, r32[esi]);
    memoryASet32(ds, r32[edx] + 0x64, r32[esi]);
    r32[edi] = pop32();
    memoryASet32(ds, r32[edx] + 0x34, r32[ebp]);
    r32[esi] = pop32();
    memoryASet32(ds, r32[ebx], 0x56737450);
    memoryASet32(ds, r32[edx] + 0x3c, r32[eax]);
    memoryASet32(ds, r32[edx] + 0x6c, r32[eax]);
    r32[ebp] = pop32();
    memoryASet32(ds, r32[edx] + 0x24, 0x10001000);
    memoryASet32(ds, r32[edx] + 0x28, 0x100010a0);
    memoryASet32(ds, r32[edx] + 0x2c, 0x10001080);
    memoryASet32(ds, r32[edx] + 0x30, 0x10001060);
    memoryASet32(ds, r32[edx] + 0x40, 0x00000002);
    memoryASet32(ds, r32[edx] + 0x5c, 0x3f800000);
    memoryASet32(ds, r32[edx] + 0x60, r32[edx]);
    memoryASet32(ds, r32[edx] + 0x68, 0x4e6f4566);
    memoryASet32(ds, r32[edx] + 0x70, 0x100010c0);
    memoryASet32(ds, r32[edx] + 0x4, 0x472c4400);
    memoryASet32(ds, r32[edx] + 0x1c, 0x00000400);
    r32[eax] = r32[edx];
    r32[ebx] = pop32();
    r32[esp] += 16;
}

function sub_10002b10() // 0000:10002b10 — set sample rate/tempo via dispatcher vtable calls (opcodes 0,2,3)
{
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0xd8);
    memoryASet32(ds, r32[esi] + 0x18, r32[ecx]);
    r32[eax] = r32[ecx] + (r32[ecx] * 8);
    r32[ecx] = memoryAGet32(ds, r32[edx] + r32[eax] * 4);
    r32[eax] = r32[edx] + (r32[eax] * 4);
    memoryASet32(ds, r32[esi] + 0xb0, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    memoryASet32(ds, r32[esi] + 0xbc, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x8);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    memoryASet32(ds, r32[esi] + 0xc4, r32[eax]);
    r32[eax] = r32[ecx];
    r32[ecx] = r32[esi];
    push32(r32[eax]);
    push32(0x00000000);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xbc);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(r32[eax]);
    push32(0x00000002);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xc4);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(r32[eax]);
    push32(0x00000003);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
    r32[esi] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 8;
}

function sub_100032c0() // 0000:100032c0 — init default parameter values (floats + string copies)
{
    r32[esp] -= 4;
    push32(r32[ecx]);
    r32[edx] = r32[ecx];
    push32(r32[ebx]);
    push32(r32[ebp]);
    r32[ebp] = 0x3f4ccccd;
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edi] = 0x1000d384;
    memoryASet32(ds, r32[eax], 0x3f000000);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0xd8);
    memoryASet32(ds, r32[ecx] + 0x4, r32[ebp]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[ecx] |= 0xffffffff;
    memoryASet32(ds, r32[eax] + 0x8, 0x3f000000);
    r32[ebx] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[eax] = 0;
    r32[ebx] += 0x0000000c;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = ~r32[ecx];
    r32[edi] -= r32[ecx];
    r32[eax] = r32[ecx];
    r32[esi] = r32[edi];
    r32[edi] = r32[ebx];
    r32[ebx] = 0;
    r32[ecx] >>>= 2;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    r32[ecx] = r32[eax];
    r32[ecx] &= 0x00000003;
    for (; r32[ecx] != 0; --r32[ecx]) movsb_ESEDI_DSESI();
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[edi] = 0x1000d37c;
    memoryASet32(ds, r32[ecx] + 0x24, 0x3ecccccd);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    memoryASet32(ds, r32[eax] + 0x28, 0x3e99999a);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[eax] = 0;
    memoryASet32(ds, r32[ecx] + 0x2c, r32[ebx]);
    r32[esi] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[ecx] |= 0xffffffff;
    r32[esi] += 0x00000030;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = ~r32[ecx];
    r32[edi] -= r32[ecx];
    memoryASet32(ds, r32[esp] + 0x10, r32[esi]);
    r32[eax] = r32[ecx];
    r32[esi] = r32[edi];
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[ecx] >>>= 2;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    r32[ecx] = r32[eax];
    r32[ecx] &= 0x00000003;
    for (; r32[ecx] != 0; --r32[ecx]) movsb_ESEDI_DSESI();
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[edi] = 0x1000d374;
    memoryASet32(ds, r32[ecx] + 0x48, r32[ebp]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    memoryASet32(ds, r32[eax] + 0x4c, 0x3f19999a);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[eax] = 0;
    memoryASet32(ds, r32[ecx] + 0x50, 0x3e800000);
    r32[ebp] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[ecx] |= 0xffffffff;
    r32[ebp] += 0x00000054;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = ~r32[ecx];
    r32[edi] -= r32[ecx];
    r32[eax] = r32[ecx];
    r32[esi] = r32[edi];
    r32[edi] = r32[ebp];
    r32[ecx] >>>= 2;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    r32[ecx] = r32[eax];
    r32[ecx] &= 0x00000003;
    for (; r32[ecx] != 0; --r32[ecx]) movsb_ESEDI_DSESI();
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0xd8);
    memoryASet32(ds, r32[ecx] + 0x6c, 0x3f000000);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0xd8);
    memoryASet32(ds, r32[eax] + 0x70, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0xd8);
    memoryASet32(ds, r32[ecx] + 0x74, 0x3f400000);
    r32[ebx] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[edi] = 0x1000d36c;
    r32[ecx] |= 0xffffffff;
    r32[eax] = 0;
    r32[ebx] += 0x00000078;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = ~r32[ecx];
    r32[edi] -= r32[ecx];
    r32[eax] = r32[ecx];
    r32[esi] = r32[edi];
    r32[edi] = r32[ebx];
    r32[ecx] >>>= 2;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    r32[ecx] = r32[eax];
    r32[eax] = 0x3f800000;
    r32[ecx] &= 0x00000003;
    for (; r32[ecx] != 0; --r32[ecx]) movsb_ESEDI_DSESI();
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[edi] = 0x1000d364;
    memoryASet32(ds, r32[ecx] + 0x90, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0xd8);
    memoryASet32(ds, r32[ecx] + 0x94, 0x3f666666);
    r32[ecx] = memoryAGet32(ds, r32[edx] + 0xd8);
    memoryASet32(ds, r32[ecx] + 0x98, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edx] + 0xd8);
    r32[ecx] |= 0xffffffff;
    r32[eax] = 0;
    r32[edx] += 0x0000009c;
    for (flags.zero = 0; r32[ecx] != 0 && !flags.zero; --r32[ecx]) scasb_inv_ESEDI(r8[al]);
    r32[ecx] = ~r32[ecx];
    r32[edi] -= r32[ecx];
    r32[eax] = r32[ecx];
    r32[esi] = r32[edi];
    r32[edi] = r32[edx];
    r32[ecx] >>>= 2;
    for (; r32[ecx] != 0; --r32[ecx]) movsd_ESEDI_DSESI();
    r32[ecx] = r32[eax];
    r32[ecx] &= 0x00000003;
    for (; r32[ecx] != 0; --r32[ecx]) movsb_ESEDI_DSESI();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[ecx] = pop32();
    r32[esp] += 4;
}

function sub_10002810() // 0000:10002810 — default ctor stub: return this (ecx) in eax
{
    r32[esp] -= 4;
    r32[eax] = r32[ecx];
    r32[esp] += 4;
}

function sub_1000a7e4() // 0000:1000a7e4 — loop cleanup: call sub_1000a888 if loop did not complete
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    if (memoryAGet32(ss, r32[ebp] - 32))
        { pc = 0x1000a7fb; break; }
    push32(memoryAGet32(ss, r32[ebp] + 0x18));
    push32(memoryAGet32(ss, r32[ebp] - 28));
    push32(memoryAGet32(ss, r32[ebp] + 0xc));
    push32(memoryAGet32(ss, r32[ebp] + 0x8));
    sub_1000a888();
  case 0x1000a7fb: // 0000:1000a7fb
    r32[esp] += 4; return;
    return;
  }
}

function sub_1000a77a() // 0000:1000a77a +long +stackDrop20 — loop: call callback(ptr) N times, advance ptr by stride
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    push32(0xffffffff);
    push32(0x1000c1f8);
    push32(0x1000aa80);
    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    memoryASet32(fs, 0x0, r32[esp]);
    r32[esp] -= 0x00000010;
    push32(r32[ebx]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = 0;
    memoryASet32(ss, r32[ebp] - 32, r32[eax]);
    memoryASet32(ss, r32[ebp] - 4, r32[eax]);
    memoryASet32(ss, r32[ebp] - 28, r32[eax]);
  case 0x1000a7a8: // 0000:1000a7a8
    r32[eax] = memoryAGet32(ss, r32[ebp] - 28);
    if (r32s[eax] >= signed32(memoryAGet32(ss, r32[ebp] + 0x10)))
        { pc = 0x1000a7c3; break; }
    r32[esi] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ss, r32[ebp] + 0x14));
    r32[esi] += memoryAGet32(ss, r32[ebp] + 0xc);
    memoryASet32(ss, r32[ebp] + 0x8, r32[esi]);
    memoryASet32(ss, r32[ebp] - 28, memoryAGet32(ss, r32[ebp] - 28) + 1);
    { pc = 0x1000a7a8; break; }
  case 0x1000a7c3: // 0000:1000a7c3
    memoryASet32(ss, r32[ebp] - 32, 0x00000001);
    memoryASet32(ss, r32[ebp] - 4, memoryAGet32(ss, r32[ebp] - 4) | 0xffffffff);
    sub_1000a7e4();
    r32[ecx] = memoryAGet32(ss, r32[ebp] - 16);
    memoryASet32(fs, 0x0, r32[ecx]);
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp]; r32[ebp] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 24;
    return;
  }
}

function sub_10001a50() // 0000:10001a50 +long +stackDrop12
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    push32(r32[eax]);
    push32(r32[ecx]);
    push32(r32[edx]);
    r32[ecx] = r32[esi];
    sub_100010e0();
    memoryASet32(ds, r32[esi], 0x1000b250);
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 16;
}

function sub_10002820() // 0000:10002820 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1000aab3);
    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    memoryASet32(fs, 0x0, r32[esp]);
    push32(r32[ecx]);
    push32(r32[ebx]);
    push32(r32[ebp]);
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[esi]);
    push32(0x00000004);
    r32[esi] = r32[ecx];
    push32(0x00000005);
    push32(r32[ebp]);
    memoryASet32(ds, r32[esp] + 0x18, r32[esi]);
    sub_10001a50();
    r32[ebx] = 0;
    push32(0x000000b8);
    memoryASet32(ds, r32[esp] + 0x1c, r32[ebx]);
    memoryASet32(ds, r32[esi], 0x1000b460);
    memoryASet32(ds, r32[esi] + 0x64a4, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64ac, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64c0, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64cc, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64d8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64b8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64c8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64dc, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x648c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6490, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64e4, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64e8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64ec, r32[ebx]);
    memoryASet(ds, r32[esi] + 0x6174, r8[bl]);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x20, r32[eax]);
    memoryASet(ds, r32[esp] + 0x18, 0x01);
    if (r32[eax] == r32[ebx])
        { pc = 0x100028ea; break; }
    push32(r32[edi]);
    push32(0x100015b0);
    push32(0x10002810);
    r32[edi] = r32[eax] + 4;
    push32(0x00000005);
    push32(0x00000024);
    push32(r32[edi]);
    memoryASet32(ds, r32[eax], 0x00000005);
    sub_1000a77a();
    r32[eax] = r32[edi];
    r32[edi] = pop32();
    { pc = 0x100028ec; break; }
  case 0x100028ea: // 0000:100028ea
    r32[eax] = 0;
  case 0x100028ec: // 0000:100028ec
    memoryASet(ds, r32[esp] + 0x18, r8[bl]);
    memoryASet32(ds, r32[esi] + 0xd8, r32[eax]);
    if (r32[eax] == r32[ebx])
        { pc = 0x10002909; break; }
    r32[ecx] = r32[esi];
    sub_100032c0();
    push32(r32[ebx]);
    r32[ecx] = r32[esi];
    sub_10002b10();
  case 0x10002909: // 0000:10002909
    if (r32[ebp] == r32[ebx])
        { pc = 0x10002940; break; }
    push32(0x00000001);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x3c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x40, 0x00000002);
    sub_10001520();
    push32(r32[ebx]);
    r32[ecx] = r32[esi];
    sub_100014c0();
    push32(r32[ebx]);
    r32[ecx] = r32[esi];
    sub_100014e0();
    push32(0x00000001);
    r32[ecx] = r32[esi];
    sub_10002670();
    memoryASet32(ds, r32[esi] + 0x68, 0x416e446c);
  case 0x10002940: // 0000:10002940
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
    memoryASet32(ds, r32[esi] + 0x63f0, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x63ec, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0xb4, 0x3f000000);
    memoryASet32(ds, r32[esi] + 0xc8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0xc0, 0x3e2ab368);
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    memoryASet32(fs, 0x0, r32[ecx]);
    r32[esp] += 0x00000010;
    stop("stack_unbalanced");
    r32[esp] += 8;
    return;
  }
}

function sub_10003470() // 0000:10003470 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1000aaf3);
    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    memoryASet32(fs, 0x0, r32[esp]);
    push32(r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0x8, r32[esi]);
    sub_10002820();
    push32(0x00000068);
    memoryASet32(ds, r32[esp] + 0x14, 0x00000000);
    memoryASet32(ds, r32[esi], 0x1000b694);
    memoryASet32(ds, r32[esi] + 0x68, 0x416e446c);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x18, r32[eax]);
    memoryASet(ds, r32[esp] + 0x10, 0x01);
    if (!r32[eax])
        { pc = 0x100034cd; break; }
    push32(r32[esi]);
    r32[ecx] = r32[eax];
    sub_10003640();
    { pc = 0x100034cf; break; }
  case 0x100034cd: // 0000:100034cd
    r32[eax] = 0;
  case 0x100034cf: // 0000:100034cf
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
    if (r32[eax])
        { pc = 0x100034dd; break; }
    memoryASet(ds, 0x1000d404, 0x01);
  case 0x100034dd: // 0000:100034dd
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    memoryASet32(fs, 0x0, r32[ecx]);
    r32[esp] += 0x00000010;
    r32[esp] += 8;
    return;
  }
}

// sub_1000a7fc: thunk for operator new(size_t) — implemented manually in crt.js
// function sub_1000a7fc() // 0000:1000a7fc +long
// {
//     r32[esp] -= 4;
//     indirectJump(cs, memoryAGet32(ds, 0x1000b0ac)); return; // 0000:1000a7fc
// }

function sub_10003560() // 0000:10003560 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(fs, 0x0);
    push32(0xffffffff);
    push32(0x1000ab0b);
    push32(r32[eax]);
    memoryASet32(fs, 0x0, r32[esp]);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x14);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000001);
    push32(0x00000000);
    indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000018;
    if (r32[eax])
        { pc = 0x1000359f; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(fs, 0x0, r32[ecx]);
    r32[esi] = pop32();
    r32[esp] += 0x0000000c;
    r32[esp] += 4; return;
  case 0x1000359f: // 0000:1000359f
    push32(0x000064f0);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x14, r32[eax]);
    memoryASet32(ds, r32[esp] + 0xc, 0x00000000);
    if (!r32[eax])
        { pc = 0x100035c6; break; }
    push32(r32[esi]);
    r32[ecx] = r32[eax];
    sub_10003470();
    { pc = 0x100035c8; break; }
  case 0x100035c6: // 0000:100035c6
    r32[eax] = 0;
  case 0x100035c8: // 0000:100035c8
    memoryASet32(ds, r32[esp] + 0xc, 0xffffffff);
    if (r32[eax])
        { pc = 0x100035e4; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(fs, 0x0, r32[ecx]);
    r32[esi] = pop32();
    r32[esp] += 0x0000000c;
    r32[esp] += 4; return;
  case 0x100035e4: // 0000:100035e4
    r8[cl] = memoryAGet(ds, 0x1000d404);
    if (!r8[cl])
        { pc = 0x10003608; break; }
    r32[edx] = memoryAGet32(ds, r32[eax]);
    push32(0x00000001);
    r32[ecx] = r32[eax];
    indirectCall(cs, memoryAGet32(ds, r32[edx]));
    r32[eax] = 0;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(fs, 0x0, r32[ecx]);
    r32[esi] = pop32();
    r32[esp] += 0x0000000c;
    stop("stack_unbalanced");
    r32[esp] += 4; return;
  case 0x10003608: // 0000:10003608
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[eax] += 0x00000020;
    memoryASet32(fs, 0x0, r32[ecx]);
    r32[esi] = pop32();
    r32[esp] += 0x0000000c;
    r32[esp] += 4;
    return;
  }
}


function sub_10001520() // 0000:10001520 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r8[al] = memoryAGet(ds, r32[esp] + 0x4);
    flags.zero = r8[al] == 0;
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x44);
    if (flags.zero)
        { pc = 0x10001533; break; }
    r8[al] |= 0x10;
    memoryASet32(ds, r32[ecx] + 0x44, r32[eax]);
    r32[esp] += 8; return;
  case 0x10001533: // 0000:10001533
    r8[al] &= 0xef;
    memoryASet32(ds, r32[ecx] + 0x44, r32[eax]);
    r32[esp] += 8;
    return;
  }
}


function sub_100014c0() // 0000:100014c0 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r8[al] = memoryAGet(ds, r32[esp] + 0x4);
    flags.zero = r8[al] == 0;
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x44);
    if (flags.zero)
        { pc = 0x100014d3; break; }
    r8[al] |= 0x04;
    memoryASet32(ds, r32[ecx] + 0x44, r32[eax]);
    r32[esp] += 8; return;
  case 0x100014d3: // 0000:100014d3
    r8[al] &= 0xfb;
    memoryASet32(ds, r32[ecx] + 0x44, r32[eax]);
    r32[esp] += 8;
    return;
  }
}


function sub_100014e0() // 0000:100014e0 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r8[al] = memoryAGet(ds, r32[esp] + 0x4);
    flags.zero = r8[al] == 0;
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x44);
    if (flags.zero)
        { pc = 0x100014f3; break; }
    r8[al] |= 0x02;
    memoryASet32(ds, r32[ecx] + 0x44, r32[eax]);
    r32[esp] += 8; return;
  case 0x100014f3: // 0000:100014f3
    r8[al] &= 0xfd;
    memoryASet32(ds, r32[ecx] + 0x44, r32[eax]);
    r32[esp] += 8;
    return;
  }
}
function sub_10002670() // 0000:10002670 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r8[al] = memoryAGet(ds, r32[esp] + 0x4);
    flags.zero = r8[al] == 0;
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x44);
    if (flags.zero)
        { pc = 0x10002684; break; }
    r8[ah] |= 0x01;
    memoryASet32(ds, r32[ecx] + 0x44, r32[eax]);
    r32[esp] += 8; return;
  case 0x10002684: // 0000:10002684
    r8[ah] &= 0xfe;
    memoryASet32(ds, r32[ecx] + 0x44, r32[eax]);
    r32[esp] += 8;
    return;
  }
}


function sub_10003640() // 0000:10003640 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1000ab33);
    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    memoryASet32(fs, 0x0, r32[esp]);
    push32(r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[esi] = r32[ecx];
    push32(r32[eax]);
    memoryASet32(ds, r32[esp] + 0xc, r32[esi]);
    sub_10006680();
    r32[edi] = 0;
    memoryASet32(ds, r32[esi] + 0x24, 0x1000b8f0);
    push32(0x00000018);
    memoryASet32(ds, r32[esp] + 0x18, r32[edi]);
    memoryASet32(ds, r32[esi], 0x1000b8b8);
    memoryASet32(ds, r32[esi] + 0x24, 0x1000b8b4);
    memoryASet32(ds, r32[esi] + 0x58, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x4c, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x50, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x54, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x64, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x5c, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x60, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x38, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x30, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x34, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x3c, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x40, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x28, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x44, r32[edi]);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x1c, r32[eax]);
    memoryASet(ds, r32[esp] + 0x14, 0x01);
    if (r32[eax] == r32[edi])
        { pc = 0x100036d1; break; }
    push32(0x00000082);
    r32[ecx] = r32[eax];
    sub_10007e20();
    { pc = 0x100036d3; break; }
  case 0x100036d1: // 0000:100036d1
    r32[eax] = 0;
  case 0x100036d3: // 0000:100036d3
    memoryASet32(ds, r32[esi] + 0x48, r32[eax]);
    memoryASet16(ds, r32[esi] + 0x12, r16[di]);
    memoryASet16(ds, r32[esi] + 0x10, r16[di]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x8);
    memoryASet16(ds, r32[esi] + 0x16, r16[cx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xc);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet16(ds, r32[esi] + 0x14, r16[dx]);
    r32[eax] = r32[esi];
    r32[edi] = pop32();
    r32[esi] = pop32();
    memoryASet32(fs, 0x0, r32[ecx]);
    r32[esp] += 0x00000010;
    r32[esp] += 8;
    return;
  }
}


function sub_10006680() // 0000:10006680 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1000ac28);
    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    memoryASet32(fs, 0x0, r32[esp]);
    push32(r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    r32[ebx] = 0;
    memoryASet32(ds, r32[esp] + 0x8, r32[esi]);
    memoryASet32(ds, r32[esi] + 0x4, r32[eax]);
    memoryASet32(ds, r32[esi] + 0xc, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x18, r32[ebx]);
    memoryASet(ds, r32[esi] + 0x20, r8[bl]);
    memoryASet32(ds, r32[esi], 0x1000bb80);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x44);
    memoryASet32(ds, r32[esp] + 0x14, r32[ebx]);
    memoryASet32(ds, r32[eax] + 0x8, r32[esi]);
    if (r32[esi] == r32[ebx])
        { pc = 0x100066c9; break; }
    r32[ecx] |= 0x00000001;
    { pc = 0x100066cc; break; }
  case 0x100066c9: // 0000:100066c9
    r32[ecx] &= 0xfffffffe;
  case 0x100066cc: // 0000:100066cc
    memoryASet32(ds, r32[eax] + 0x44, r32[ecx]);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x8, r32[ebx]);
    sub_100068b0();
    push32(r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
    indirectCall(cs, memoryAGet32(ds, 0x1000b130));
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[ebx] = pop32();
    memoryASet32(fs, 0x0, r32[ecx]);
    r32[esp] += 0x00000010;
    r32[esp] += 8;
    return;
  }
}


function sub_100068b0() // 0000:100068b0 — thunk: kernel32.GetTickCount (simple jmp thunk, no esp manip)
{
    r32[eax] = Date.now() & 0xffffffff;
}


function sub_10007e20() // 0000:10007e20 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[esp] -= 0x00000018;
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    memoryASet32(ds, r32[esi], r32[eax]);
    r32[eax] &= 0x0000ffff;
    memoryASet32(ds, r32[esi] + 0x4, 0x00000001);
    memoryASet32(ds, r32[esi] + 0x8, 0x00000000);
    memoryASet32(ds, r32[esi] + 0xc, 0x00000000);
    memoryASet32(ds, r32[esi] + 0x14, 0x00000000);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, 0x1000d400);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, 0x1000b0ec));
    memoryASet32(ds, r32[esi] + 0x10, r32[eax]);
    if (!r32[eax])
        { pc = 0x10007e81; break; }
    r32[ecx] = r32[esp] + 4;
    push32(r32[ecx]);
    push32(0x00000018);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, 0x1000b038));
    if (!r32[eax])
        { pc = 0x10007e81; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);
    memoryASet32(ds, r32[esi] + 0x8, r32[edx]);
    memoryASet32(ds, r32[esi] + 0xc, r32[eax]);
  case 0x10007e81: // 0000:10007e81
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 0x00000018;
    stop("stack_unbalanced");
    r32[esp] += 8;
    return;
  }
}


function sub_10001000() // 0000:10001000 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[eax] + 0x40);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    if (r32[eax] != 0x00000001)
        { pc = 0x10001041; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    push32(r32[ecx]);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x18));
    if (!r32[esi])
        { pc = 0x1000103a; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(0x00000001);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[edx]));
  case 0x1000103a: // 0000:1000103a
    r32[eax] = 0x00000001;
    r32[esi] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4; return;
  case 0x10001041: // 0000:10001041
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[ecx]);
    push32(r32[eax]);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x18));
    r32[esi] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}
function sub_100010c0() // 0000:100010c0 +long
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x40);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x14));
    stop("stack_unbalanced");
    r32[esp] += 4;
}


function sub_10001ab0() // 0000:10001ab0 +long +stackDrop20
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x00000008;
    r32[eax] = 0;
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = r32[esi] - 25;
    if (r32[edx] > 0x0000002b)
        { pc = 0x10001f6e; break; }
    switch (r32[edx])
    {
        case 0: { pc = 0x10001acd; break; }
        case 1: { pc = 0x10001ae1; break; }
        case 2: { pc = 0x10001afb; break; }
        case 3: { pc = 0x10001b1a; break; }
        case 4: { pc = 0x10001b29; break; }
        case 5: { pc = 0x10001b4d; break; }
        case 6: { pc = 0x10001b67; break; }
        case 7: { pc = 0x10001b8a; break; }
        case 8: { pc = 0x10001bad; break; }
        case 9: { pc = 0x10001bcc; break; }
        case 10: { pc = 0x10001beb; break; }
        case 11: { pc = 0x10001bfa; break; }
        case 12: { pc = 0x10001c09; break; }
        case 13: { pc = 0x10001c18; break; }
        case 14: { pc = 0x10001c40; break; }
        case 15: { pc = 0x10001c5e; break; }
        case 16: { pc = 0x10001c9b; break; }
        case 17: { pc = 0x10001c7c; break; }
        case 18: { pc = 0x10001cb5; break; }
        case 19: { pc = 0x10001cd3; break; }
        case 20: { pc = 0x10001cf2; break; }
        case 21: { pc = 0x10001d0c; break; }
        case 22: { pc = 0x10001d26; break; }
        case 23: { pc = 0x10001d40; break; }
        case 24: { pc = 0x10001d5a; break; }
        case 25: { pc = 0x10001d69; break; }
        case 26: { pc = 0x10001d8c; break; }
        case 27: { pc = 0x10001dce; break; }
        case 28: { pc = 0x10001ddd; break; }
        case 29: { pc = 0x10001da0; break; }
        case 30: { pc = 0x10001daf; break; }
        case 31: { pc = 0x10001dec; break; }
        case 32: { pc = 0x10001e0b; break; }
        case 33: { pc = 0x10001e1f; break; }
        case 34: { pc = 0x10001e2e; break; }
        case 35: { pc = 0x10001e69; break; }
        case 36: { pc = 0x10001ea4; break; }
        case 37: { pc = 0x10001ec0; break; }
        case 38: { pc = 0x10001ed9; break; }
        case 39: { pc = 0x10001ef2; break; }
        case 40: { pc = 0x10001f0b; break; }
        case 41: { pc = 0x10001f25; break; }
        case 42: { pc = 0x10001f44; break; }
        case 43: { pc = 0x10001f59; break; }
        default:
            stop("ind 0000:10001ac6");
    }
    break;
  case 0x10001acd: // 0000:10001acd
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0xc8));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001ae1: // 0000:10001ae1
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0xd4));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001afb: // 0000:10001afb
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0xd8));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001b1a: // 0000:10001b1a
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0xe0));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001b29: // 0000:10001b29
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0xe4));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/8");
    r32[esp] += 24; return;
  case 0x10001b4d: // 0000:10001b4d
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0xe8));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001b67: // 0000:10001b67
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r8[al] = r32[eax] != 0;
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x110));
    r32[eax] = 0x00000001;
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001b8a: // 0000:10001b8a
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    r8[al] = r32[eax] != 0;
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x114));
    r32[eax] = 0x00000001;
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001bad: // 0000:10001bad
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x118));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001bcc: // 0000:10001bcc
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x11c));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001beb: // 0000:10001beb
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x120));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001bfa: // 0000:10001bfa
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x138));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001c09: // 0000:10001c09
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x13c));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001c18: // 0000:10001c18
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r8[dl] = r32[edx] != 0;
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x24);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x154));
    r32[eax] &= 0x000000ff;
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/8");
    r32[esp] += 24; return;
  case 0x10001c40: // 0000:10001c40
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x20);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x158));
    r32[eax] &= 0x000000ff;
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001c5e: // 0000:10001c5e
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x20);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x15c));
    r32[eax] &= 0x000000ff;
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001c7c: // 0000:10001c7c
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1a4));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001c9b: // 0000:10001c9b
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1a0));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001cb5: // 0000:10001cb5
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1a8));
    r32[eax] = 0x00000001;
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001cd3: // 0000:10001cd3
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r8[dl] = r32[edx] != 0;
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1ac));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001cf2: // 0000:10001cf2
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1b0));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001d0c: // 0000:10001d0c
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1b4));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001d26: // 0000:10001d26
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1b8));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001d40: // 0000:10001d40
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1bc));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001d5a: // 0000:10001d5a
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1c0));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001d69: // 0000:10001d69
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1c4));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/4");
    r32[esp] += 24; return;
  case 0x10001d8c: // 0000:10001d8c
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1c8));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001da0: // 0000:10001da0
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1cc));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001daf: // 0000:10001daf
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1d0));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001dce: // 0000:10001dce
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1d4));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001ddd: // 0000:10001ddd
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1d8));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001dec: // 0000:10001dec
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1dc));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001e0b: // 0000:10001e0b
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1e0));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax]++;
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001e1f: // 0000:10001e1f
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1e4));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001e2e: // 0000:10001e2e
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x8);
    if (!r32[esi])
        { pc = 0x10001f88; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    r8[cl] = memoryAGet(ds, r32[esp] + 0x18);
    fld32(memoryAGet32(ds, r32[esp] + 0x20));
    memoryASet32(ds, r32[esp] + 0x4, r32[eax]);
    memoryASet(ds, r32[esp] + 0x8, r8[cl]);
    sub_1000a75c();
    memoryASet(ds, r32[esp] + 0x9, r8[al]);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[eax] = r32[esp] + 4;
    r32[ecx] = r32[esi];
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1c));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001e69: // 0000:10001e69
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x8);
    if (!r32[esi])
        { pc = 0x10001f88; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
    r8[dl] = memoryAGet(ds, r32[esp] + 0x18);
    fld32(memoryAGet32(ds, r32[esp] + 0x20));
    memoryASet32(ds, r32[esp] + 0x4, r32[ecx]);
    memoryASet(ds, r32[esp] + 0x8, r8[dl]);
    sub_1000a75c();
    r32[ecx] = r32[esp] + 4;
    memoryASet(ds, r32[esp] + 0x9, r8[al]);
    r32[eax] = memoryAGet32(ds, r32[esi]);
    push32(r32[ecx]);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x20));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001ea4: // 0000:10001ea4
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    if (!r32[ecx])
        { pc = 0x10001f88; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x24));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001ec0: // 0000:10001ec0
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1e8));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001ed9: // 0000:10001ed9
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1ec));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001ef2: // 0000:10001ef2
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1f0));
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001f0b: // 0000:10001f0b
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1f4));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001f25: // 0000:10001f25
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1f8));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001f44: // 0000:10001f44
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x1fc));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001f59: // 0000:10001f59
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x200));
    flags.carry = r8[al] != 0;
    r8[al] = -r8[al];
    r32[eax] = -flags.carry;
    r32[esi] = pop32();
    r32[eax] = -r32[eax];
    r32[esp] += 0x00000008;
    r32[esp] += 24; return;
  case 0x10001f6e: // 0000:10001f6e
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[edx]);
    push32(r32[eax]);
    push32(r32[esi]);
    sub_100011e0();
  case 0x10001f88: // 0000:10001f88
    r32[esi] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 24;
    return;
  }
}


function sub_100011e0() // 0000:100011e0 +long +stackDrop20
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(r32[esi]);
    r32[esi] = 0;
    if (r32[eax] > 0x00000018)
        { pc = 0x1000137c; break; }
    switch (r32[eax])
    {
        case 0: { pc = 0x100011f7; break; }
        case 1: { pc = 0x10001202; break; }
        case 2: { pc = 0x1000120d; break; }
        case 3: { pc = 0x10001228; break; }
        case 4: { pc = 0x10001233; break; }
        case 5: { pc = 0x10001243; break; }
        case 6: { pc = 0x10001253; break; }
        case 7: { pc = 0x10001268; break; }
        case 8: { pc = 0x1000127d; break; }
        case 9: { pc = 0x100012d0; break; }
        case 10: { pc = 0x10001292; break; }
        case 11: { pc = 0x100012a2; break; }
        case 12: { pc = 0x100012b2; break; }
        case 13: { pc = 0x100012e6; break; }
        case 14: { pc = 0x10001301; break; }
        case 15: { pc = 0x10001318; break; }
        case 16: { pc = 0x1000137c; break; }
        case 17: { pc = 0x1000137c; break; }
        case 18: { pc = 0x1000137c; break; }
        case 19: { pc = 0x1000132a; break; }
        case 20: { pc = 0x1000137c; break; }
        case 21: { pc = 0x1000137c; break; }
        case 22: { pc = 0x1000133c; break; }
        case 23: { pc = 0x10001347; break; }
        case 24: { pc = 0x10001361; break; }
        default:
            stop("ind 0000:100011f0");
    }
    break;
  case 0x100011f7: // 0000:100011f7
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x1c));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 24; return;
  case 0x10001202: // 0000:10001202
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x20));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 24; return;
  case 0x1000120d: // 0000:1000120d
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x10);
    if (r32s[eax] >= r32s[edx])
        { pc = 0x1000137c; break; }
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x28));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001228: // 0000:10001228
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x24));
    r32[esi] = r32[eax];
    r32[esi] = pop32();
    r32[esp] += 24; return;
  case 0x10001233: // 0000:10001233
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x2c));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001243: // 0000:10001243
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x30));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001253: // 0000:10001253
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x34));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001268: // 0000:10001268
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x38));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x1000127d: // 0000:1000127d
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x3c));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001292: // 0000:10001292
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4c));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x100012a2: // 0000:100012a2
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    push32(r32[eax]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x50));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x100012b2: // 0000:100012b2
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    if (r32[eax])
        { pc = 0x100012c5; break; }
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x54));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 24; return;
  case 0x100012c5: // 0000:100012c5
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x58));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 24; return;
  case 0x100012d0: // 0000:100012d0
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x40));
    fmul64(memoryAGet64(ds, 0x1000b200));
    sub_1000a75c();
    r32[esi] = r32[eax];
    r32[esi] = pop32();
    r32[esp] += 24; return;
  case 0x100012e6: // 0000:100012e6
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    if (!r32[ecx])
        { pc = 0x1000137c; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x4));
    r32[esi] = r32[eax];
    r32[esi] = pop32();
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001301: // 0000:10001301
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    if (!r32[ecx])
        { pc = 0x1000137c; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x8));
    r32[esi] = r32[eax];
    r32[esi] = pop32();
    stop("stack_below, 20/16");
    r32[esp] += 24; return;
  case 0x10001318: // 0000:10001318
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    if (!r32[ecx])
        { pc = 0x1000137c; break; }
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0xc));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 24; return;
  case 0x1000132a: // 0000:1000132a
    r32[ecx] = memoryAGet32(ds, r32[ecx] + 0x8);
    if (!r32[ecx])
        { pc = 0x1000137c; break; }
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x10));
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 24; return;
  case 0x1000133c: // 0000:1000133c
    r32[esi] = 0x4e764566;
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 24; return;
  case 0x10001347: // 0000:10001347
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r8[dl] = r32[edx] != 0;
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x44));
    r32[esi] = r32[eax];
    r32[esi] = pop32();
    stop("stack_below, 20/12");
    r32[esp] += 24; return;
  case 0x10001361: // 0000:10001361
    r32[edx] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    r8[dl] = r32[edx] != 0;
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    push32(r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x1c);
    push32(r32[edx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x48));
    r32[esi] = r32[eax];
  case 0x1000137c: // 0000:1000137c
    r32[eax] = r32[esi];
    r32[esi] = pop32();
    r32[esp] += 24;
    return;
  }
}


function sub_10002b10() // 0000:10002b10 +long +stackDrop4
{
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0xd8);
    memoryASet32(ds, r32[esi] + 0x18, r32[ecx]);
    r32[eax] = r32[ecx] + (r32[ecx] * 8);
    r32[ecx] = memoryAGet32(ds, r32[edx] + r32[eax] * 4);
    r32[eax] = r32[edx] + (r32[eax] * 4);
    memoryASet32(ds, r32[esi] + 0xb0, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    memoryASet32(ds, r32[esi] + 0xbc, r32[edx]);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x8);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    memoryASet32(ds, r32[esi] + 0xc4, r32[eax]);
    r32[eax] = r32[ecx];
    r32[ecx] = r32[esi];
    push32(r32[eax]);
    push32(0x00000000);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xbc);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(r32[eax]);
    push32(0x00000002);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xc4);
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(r32[eax]);
    push32(0x00000003);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
    r32[esi] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 8;
}


function sub_10003530() // 0000:10003530 +long +stackDrop8
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
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[esi] = r32[ecx];
    push32(r32[edi]);
    push32(r32[ebx]);
    sub_10002db0();
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x8);
    if (!r32[ecx])
        { pc = 0x10003552; break; }
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    push32(r32[edi]);
    push32(r32[ebx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x2c));
  case 0x10003552: // 0000:10003552
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 12;
    return;
  }
}


function sub_100040c0() // 0000:100040c0 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x18);
    if (!r32[eax])
        { pc = 0x100041e1; break; }
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[edi]);
    if (r32[eax] > 0x00000006)
        { pc = 0x100041d9; break; }
    switch (r32[eax])
    {
        case 0: { pc = 0x100040e3; break; }
        case 1: { pc = 0x1000413d; break; }
        case 2: { pc = 0x10004193; break; }
        case 3: { pc = 0x10004110; break; }
        case 4: { pc = 0x100041d9; break; }
        case 5: { pc = 0x100041bc; break; }
        case 6: { pc = 0x1000416a; break; }
        default:
            stop("ind 0000:100040dc");
    }
    break;
  case 0x100040e3: // 0000:100040e3
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x3c);
    if (!r32[eax])
        { pc = 0x100041d9; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[eax]);
    push32(0x00000000);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x8));
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x3c);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, memoryAGet32(ds, r32[edi] + 0x60));
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x18));
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x10004110: // 0000:10004110
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x40);
    if (!r32[eax])
        { pc = 0x100041d9; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[eax]);
    push32(0x00000003);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x8));
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x40);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, memoryAGet32(ds, r32[edi] + 0x60));
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x18));
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x1000413d: // 0000:1000413d
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x30);
    if (!r32[eax])
        { pc = 0x100041d9; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[eax]);
    push32(0x00000001);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x8));
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x30);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, memoryAGet32(ds, r32[edi] + 0x60));
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x18));
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x1000416a: // 0000:1000416a
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x28);
    if (!r32[eax])
        { pc = 0x100041d9; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[eax]);
    push32(0x00000006);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x8));
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x28);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, memoryAGet32(ds, r32[edi] + 0x60));
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x18));
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x10004193: // 0000:10004193
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x38);
    if (!r32[eax])
        { pc = 0x100041d9; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[eax]);
    push32(0x00000002);
    r32[eax] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x8));
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x38);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, memoryAGet32(ds, r32[edi] + 0x60));
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x18));
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 12; return;
  case 0x100041bc: // 0000:100041bc
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x34);
    if (!r32[eax])
        { pc = 0x100041d9; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[edi] = memoryAGet32(ds, r32[eax]);
    push32(0x00000005);
    r32[edx] = memoryAGet32(ds, r32[ecx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x8));
    push32(r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x34);
    memoryASet32(ds, r32[esp], fstp32());
    indirectCall(cs, memoryAGet32(ds, r32[edi] + 0x60));
  case 0x100041d9: // 0000:100041d9
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x18));
    r32[edi] = pop32();
  case 0x100041e1: // 0000:100041e1
    r32[esi] = pop32();
    r32[esp] += 12;
    return;
  }
}


function sub_100061e0() // 0000:100061e0 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0xc);
    r32[esi] = 0;
    if (signed32(memoryAGet32(ds, r32[edi])) <= signed32(0x00000000))
        { pc = 0x10006231; break; }
    push32(r32[ebx]);
    r32[ecx] += 0x000000e4;
    r32[edx] = r32[edi] + 8;
  case 0x100061f7: // 0000:100061f7
    r32[eax] = memoryAGet32(ds, r32[edx]);
    if (memoryAGet32(ds, r32[eax]) != 0x00000001)
        { pc = 0x1000621c; break; }
    r32[ebx] = memoryAGet32(ds, r32[eax] + 0x8);
    memoryASet32(ds, r32[ecx] - 4, r32[ebx]);
    r32[ecx] += 0x00000010;
    r32[ebx] = signed8(memoryAGet(ds, r32[eax] + 0x18));
    memoryASet32(ds, r32[ecx] - 16, r32[ebx]);
    r32[ebx] = signed8(memoryAGet(ds, r32[eax] + 0x19));
    memoryASet32(ds, r32[ecx] - 12, r32[ebx]);
    r32[eax] = signed8(memoryAGet(ds, r32[eax] + 0x1a));
    memoryASet32(ds, r32[ecx] - 8, r32[eax]);
  case 0x1000621c: // 0000:1000621c
    r32[eax] = memoryAGet32(ds, r32[edi]);
    r32[esi]++;
    r32[edx] += 0x00000004;
    if (r32s[esi] < r32s[eax])
        { pc = 0x100061f7; break; }
    r32[ebx] = pop32();
    r32[edi] = pop32();
    r32[eax] = 0x00000001;
    r32[esi] = pop32();
    r32[esp] += 8; return;
  case 0x10006231: // 0000:10006231
    r32[edi] = pop32();
    r32[eax] = 0x00000001;
    r32[esi] = pop32();
    r32[esp] += 8;
    return;
  }
}


function sub_100054c0() // 0000:100054c0 +long +stackDrop12
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x00000008;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[esi]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    r32[esi] = r32[ecx];
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    r32[ebx] = 0;
    memoryASet32(ds, r32[esp] + 0x10, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0xdc, r32[ebx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6388);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64b0);
    push32(r32[edi]);
    r32[edi] = 0;
    memoryASet32(ds, r32[esp] + 0x10, r32[edx]);
    if (r32s[eax] < r32s[ecx])
        { pc = 0x100054fc; break; }
    r32[eax] -= r32[ecx];
    memoryASet32(ds, r32[esi] + 0x6388, r32[eax]);
  case 0x100054fc: // 0000:100054fc
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6388);
    if (r32s[eax] >= r32s[ebx])
        { pc = 0x10005512; break; }
    r32[eax] += memoryAGet32(ds, r32[esi] + 0x64b0);
    memoryASet32(ds, r32[esi] + 0x6388, r32[eax]);
  case 0x10005512: // 0000:10005512
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x24);
    r32[eax] = r32[ebp] - 1;
    if (r32s[eax] < r32s[ebx])
        { pc = 0x10005a76; break; }
    r32[eax]++;
    memoryASet32(ds, r32[esp] + 0x20, r32[eax]);
  case 0x10005526: // 0000:10005526
    push32(r32[ebp]);
    push32(r32[edi]);
    r32[ecx] = r32[esi];
    sub_10005ca0();
    if (memoryAGet(ds, r32[esi] + 0x6140) != 0x01)
        { pc = 0x10005584; break; }
    memoryASet(ds, r32[esi] + 0x6140, r8[bl]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x4120);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x411c);
    r32[eax] <<= 7;
    r32[eax] += r32[ecx];
    memoryASet32(ds, r32[esi] + 0x63c8, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x63c4);
    r32[eax] -= r32[ecx];
    memoryASet32(ds, r32[esi] + 0x63cc, r32[eax]);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(memoryAGet32(ds, r32[esi] + 0x63bc));
    memoryASet32(ds, r32[esp] + 0x24, r32[eax]);
    fild32(memoryAGet32(ds, r32[esp] + 0x24));
    memoryASet32(ds, r32[esi] + 0x63d4, fstp32());
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x63bc);
    memoryASet32(ds, r32[esi] + 0x63d0, r32[edx]);
  case 0x10005584: // 0000:10005584
    if (memoryAGet(ds, r32[esi] + 0xd5) != 0x01)
        { pc = 0x100055d9; break; }
    memoryASet(ds, r32[esi] + 0xd5, r8[bl]);
    fld32(memoryAGet32(ds, r32[esi] + 0xd0));
    fmul32(memoryAGet32(ds, 0x1000bb68));
    sub_1000a75c();
    memoryASet32(ds, r32[esi] + 0x63c8, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x63c4);
    r32[eax] -= r32[ecx];
    memoryASet32(ds, r32[esi] + 0x63cc, r32[eax]);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(memoryAGet32(ds, r32[esi] + 0x63bc));
    memoryASet32(ds, r32[esp] + 0x24, r32[eax]);
    fild32(memoryAGet32(ds, r32[esp] + 0x24));
    memoryASet32(ds, r32[esi] + 0x63d4, fstp32());
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x63bc);
    memoryASet32(ds, r32[esi] + 0x63d0, r32[eax]);
  case 0x100055d9: // 0000:100055d9
    if (memoryAGet(ds, r32[esi] + 0xd4) != 0x01)
        { pc = 0x10005628; break; }
    memoryASet(ds, r32[esi] + 0xd4, r8[bl]);
    fld32(memoryAGet32(ds, r32[esi] + 0xcc));
    fmul32(memoryAGet32(ds, 0x1000bb64));
    fadd32(memoryAGet32(ds, 0x1000bb60));
    memoryASet32(ds, r32[esi] + 0x63dc, fst32());
    fsub32(memoryAGet32(ds, r32[esi] + 0x63d8));
    memoryASet32(ds, r32[esi] + 0x63e0, fst32());
    fild32(memoryAGet32(ds, r32[esi] + 0x63bc));
    fdivr80(st(1));
    memoryASet32(ds, r32[esi] + 0x63e4, fstp32());
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x63bc);
    fstpst(0);
    memoryASet32(ds, r32[esi] + 0x63e8, r32[ecx]);
  case 0x10005628: // 0000:10005628
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x63c0);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x63b8);
    if (r32s[edx] < r32s[eax])
        { pc = 0x100056e7; break; }
    memoryASet32(ds, r32[esi] + 0x63c0, r32[ebx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x63d0);
    if (r32s[eax] <= r32s[ebx])
        { pc = 0x10005694; break; }
    r32[eax]--;
    memoryASet32(ds, r32[esi] + 0x63d0, r32[eax]);
    fld32(memoryAGet32(ds, r32[esi] + 0x63d4));
    sub_1000a75c();
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x63c4);
    r32[ecx] = r32[esi];
    r32[edx] += r32[eax];
    r32[eax] = r32[edx];
    memoryASet32(ds, r32[esi] + 0x63c4, r32[edx]);
    memoryASet32(ds, r32[esp] + 0x24, r32[eax]);
    fild32(memoryAGet32(ds, r32[esp] + 0x24));
    fmul32(memoryAGet32(ds, 0x1000bb5c));
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x24);
    memoryASet32(ds, r32[esi] + 0xb4, fstp32());
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(r32[eax]);
    push32(0x00000001);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
  case 0x10005694: // 0000:10005694
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x63e8);
    if (r32s[eax] <= r32s[ebx])
        { pc = 0x100056e7; break; }
    r32[eax]--;
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x63e8, r32[eax]);
    fld32(memoryAGet32(ds, r32[esi] + 0x63e4));
    fadd32(memoryAGet32(ds, r32[esi] + 0x63d8));
    memoryASet32(ds, r32[esi] + 0x63d8, fst32());
    fsub32(memoryAGet32(ds, 0x1000bb60));
    fmul32(memoryAGet32(ds, 0x1000bb58));
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x24);
    memoryASet32(ds, r32[esi] + 0xc8, fstp32());
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(r32[eax]);
    push32(0x00000005);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x63d8);
    memoryASet32(ds, r32[esi] + 0x6144, r32[ecx]);
  case 0x100056e7: // 0000:100056e7
    if (memoryAGet(ds, r32[esi] + 0x6174) == r8[bl])
        { pc = 0x10005926; break; }
    memoryASet32(ds, r32[esi] + 0x6468, r32[ebx]);
    r8[al] = memoryAGet(ds, r32[esi] + 0x6400);
    if (r8[al] == r8[bl])
        { pc = 0x10005739; break; }
    fld32(memoryAGet32(ds, r32[esi] + 0xb4));
    fmul32(memoryAGet32(ds, 0x1000b690));
    r32[ecx] = r32[esi];
    fmul32(memoryAGet32(ds, 0x1000b68c));
    fadd32(memoryAGet32(ds, 0x1000b688));
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x24);
    memoryASet32(ds, r32[esi] + 0xc0, fstp32());
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(r32[eax]);
    push32(0x00000006);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
    memoryASet(ds, r32[esi] + 0x6400, r8[bl]);
  case 0x10005739: // 0000:10005739
    if (memoryAGet(ds, r32[esi] + 0x6150) == r8[bl])
        { pc = 0x100057dd; break; }
    fld32(memoryAGet32(ds, r32[esi] + 0x6144));
    fadd32(memoryAGet32(ds, 0x1000b688));
    fcomp32(memoryAGet32(ds, r32[esi] + 0x614c));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x01))
        { pc = 0x1000577e; break; }
    fld32(memoryAGet32(ds, r32[esi] + 0xb0));
    fadd32(memoryAGet32(ds, 0x1000bb54));
    fmul32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fdivr32(memoryAGet32(ds, 0x1000bb50));
    memoryASet32(ds, r32[esi] + 0x6148, fstp32());
    { pc = 0x100057c9; break; }
  case 0x1000577e: // 0000:1000577e
    fld32(memoryAGet32(ds, r32[esi] + 0x6144));
    fsub32(memoryAGet32(ds, 0x1000b688));
    fcomp32(memoryAGet32(ds, r32[esi] + 0x614c));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x100057b7; break; }
    fld32(memoryAGet32(ds, r32[esi] + 0xb0));
    fadd32(memoryAGet32(ds, 0x1000bb54));
    fmul32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fdivr32(memoryAGet32(ds, 0x1000bb64));
    memoryASet32(ds, r32[esi] + 0x6148, fstp32());
    { pc = 0x100057c9; break; }
  case 0x100057b7: // 0000:100057b7
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6144);
    memoryASet32(ds, r32[esi] + 0x614c, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x6148, r32[ebx]);
  case 0x100057c9: // 0000:100057c9
    fld32(memoryAGet32(ds, r32[esi] + 0x614c));
    fadd32(memoryAGet32(ds, r32[esi] + 0x6148));
    memoryASet32(ds, r32[esi] + 0x614c, fstp32());
    { pc = 0x100057e9; break; }
  case 0x100057dd: // 0000:100057dd
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x6144);
    memoryASet32(ds, r32[esi] + 0x614c, r32[edx]);
  case 0x100057e9: // 0000:100057e9
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x614c);
    memoryASet32(ds, r32[esi] + 0x6154, r32[eax]);
    fild32(memoryAGet32(ds, r32[esi] + 0x64bc));
    fcom32(memoryAGet32(ds, r32[esi] + 0x6158));
    r16[ax] = fnstsw();
    if (!(r8[ah] & 0x41))
        { pc = 0x10005816; break; }
    fld32(memoryAGet32(ds, r32[esi] + 0x6158));
    fsubst(1);
    memoryASet32(ds, r32[esi] + 0x6158, fstp32());
  case 0x10005816: // 0000:10005816
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6170);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x616c);
    fstpst(0);
    if (r32s[ecx] < r32s[eax])
        { pc = 0x10005846; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x6170, r32[ebx]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x214));
    faddst2(0, 0);
    fadd32(memoryAGet32(ds, 0x1000bb4c));
    memoryASet32(ds, r32[esi] + 0x615c, fstp32());
  case 0x10005846: // 0000:10005846
    fld32(memoryAGet32(ds, r32[esi] + 0x6158));
    sub_1000a75c();
    fld32(memoryAGet32(ds, r32[esi] + 0x6160));
    fadd32(memoryAGet32(ds, 0x1000b688));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64b8);
    fmul32(memoryAGet32(ds, r32[ecx] + r32[eax] * 4));
    memoryASet32(ds, r32[esi] + 0x6164, fstp32());
    fld32(memoryAGet32(ds, r32[esi] + 0x6160));
    fmul32(memoryAGet32(ds, 0x1000b688));
    fadd32(memoryAGet32(ds, 0x1000b8fc));
    fmul32(memoryAGet32(ds, r32[esi] + 0x615c));
    fdiv32(memoryAGet32(ds, r32[esi] + 0x6168));
    fadd32(memoryAGet32(ds, r32[esi] + 0x6158));
    memoryASet32(ds, r32[esi] + 0x6158, fstp32());
    fld32(memoryAGet32(ds, r32[esi] + 0x6164));
    fadd32(memoryAGet32(ds, r32[esi] + 0x6154));
    memoryASet32(ds, r32[esi] + 0x6154, fst32());
    fmul32(memoryAGet32(ds, 0x1000bb48));
    sub_1000a75c();
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64dc);
    r32[eax] <<= 2;
    r32[edx] -= r32[eax];
    fld32(memoryAGet32(ds, r32[edx]));
    memoryASet32(ds, r32[esi] + 0x6384, fst32());
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fdiv80(st(1));
    sub_1000a75c();
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6388);
    memoryASet32(ds, r32[esi] + 0x637c, r32[eax]);
    fstpst(0);
    if (r32s[ecx] >= r32s[eax])
        { pc = 0x100058f1; break; }
    if (memoryAGet(ds, r32[esi] + 0x6142) == r8[bl])
        { pc = 0x10005a18; break; }
  case 0x100058f1: // 0000:100058f1
    if (memoryAGet(ds, r32[esi] + 0x6142) == r8[bl])
        { pc = 0x10005907; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xb4);
    r32[ecx] = r32[esi];
    push32(r32[eax]);
    sub_10005fb0();
  case 0x10005907: // 0000:10005907
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6388);
    push32(r32[ecx]);
    r32[ecx] = r32[esi];
    sub_10005eb0();
    memoryASet32(ds, r32[esi] + 0x6388, r32[ebx]);
    memoryASet(ds, r32[esi] + 0x6142, r8[bl]);
    { pc = 0x10005a18; break; }
  case 0x10005926: // 0000:10005926
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x6468);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6474);
    memoryASet(ds, r32[esi] + 0x6142, 0x01);
    if (r32[edx] != r32[eax])
        { pc = 0x1000594b; break; }
    r32[eax] = memoryAGet32(ds, r32[esi]);
    push32(0x3d888a48);
    push32(0x00000006);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x4));
  case 0x1000594b: // 0000:1000594b
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6468);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6478);
    if (r32[ecx] != r32[eax])
        { pc = 0x10005969; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(0x3e2aab8a);
    push32(0x00000006);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
  case 0x10005969: // 0000:10005969
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6468);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x647c);
    if (r32[eax] != r32[ecx])
        { pc = 0x10005987; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(0x3d888a48);
    push32(0x00000006);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
  case 0x10005987: // 0000:10005987
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6468);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6480);
    if (r32[eax] != r32[ecx])
        { pc = 0x100059a5; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(0x3e2aab8a);
    push32(0x00000006);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
  case 0x100059a5: // 0000:100059a5
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x646c);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6470);
    if (r32s[eax] < r32s[ecx])
        { pc = 0x10005a18; break; }
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6468);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6484);
    if (r32s[ecx] < r32s[eax])
        { pc = 0x10005a18; break; }
    if (signed32(memoryAGet32(ds, r32[esi] + 0x6464)) < signed32(0x00000018))
        { pc = 0x100059d4; break; }
    memoryASet32(ds, r32[esi] + 0x6464, r32[ebx]);
  case 0x100059d4: // 0000:100059d4
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x6464);
    memoryASet32(ds, r32[esi] + 0x646c, r32[ebx]);
    fld32(memoryAGet32(ds, r32[esi] + r32[edx] * 4 + 0x6404));
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x24);
    memoryASet32(ds, r32[esi] + 0xc0, fstp32());
    r32[eax] = memoryAGet32(ds, r32[esi]);
    push32(r32[ecx]);
    push32(0x00000006);
    r32[ecx] = r32[esi];
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x4));
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6464);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x6484);
    r32[eax]++;
    memoryASet32(ds, r32[esi] + 0x6468, r32[edx]);
    memoryASet32(ds, r32[esi] + 0x6464, r32[eax]);
  case 0x10005a18: // 0000:10005a18
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6170);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6468);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x646c);
    r32[ecx]++;
    r32[eax]++;
    memoryASet32(ds, r32[esi] + 0x6170, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x6468, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6388);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6138);
    r32[edx]++;
    r32[ecx]++;
    r32[eax]++;
    memoryASet32(ds, r32[esi] + 0x6388, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x63c0);
    memoryASet32(ds, r32[esi] + 0x6138, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[edi]++;
    r32[ecx]++;
    r32[eax]--;
    memoryASet32(ds, r32[esi] + 0x646c, r32[edx]);
    memoryASet32(ds, r32[esi] + 0x63c0, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x20, r32[eax]);
    if (r32[eax])
        { pc = 0x10005526; break; }
  case 0x10005a76: // 0000:10005a76
    if (r32s[ebp] <= r32s[ebx])
        { pc = 0x10005c8c; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x10);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[eax] = r32[ecx];
    memoryASet32(ds, r32[esp] + 0x20, r32[ebp]);
    r32[edx] -= r32[eax];
  case 0x10005a8e: // 0000:10005a8e
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64b0);
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x64b4);
    if (r32s[edi] < r32s[eax])
        { pc = 0x10005ab2; break; }
  case 0x10005a9e: // 0000:10005a9e
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x64b4);
    r32[ebp] -= r32[eax];
    r32[edi] = r32[ebp];
    memoryASet32(ds, r32[esi] + 0x64b4, r32[ebp]);
    if (r32s[edi] >= r32s[eax])
        { pc = 0x10005a9e; break; }
  case 0x10005ab2: // 0000:10005ab2
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6488);
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x6498);
    if (r32s[edi] < r32s[eax])
        { pc = 0x10005ad6; break; }
  case 0x10005ac2: // 0000:10005ac2
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x6498);
    r32[ebp] -= r32[eax];
    r32[edi] = r32[ebp];
    memoryASet32(ds, r32[esi] + 0x6498, r32[ebp]);
    if (r32s[edi] >= r32s[eax])
        { pc = 0x10005ac2; break; }
  case 0x10005ad6: // 0000:10005ad6
    if (signed32(memoryAGet32(ds, r32[esi] + 0x6498)) >= r32s[ebx])
        { pc = 0x10005aee; break; }
  case 0x10005ade: // 0000:10005ade
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x6498);
    r32[edi] += r32[eax];
    memoryASet32(ds, r32[esi] + 0x6498, r32[edi]);
    if (r32s[edi] < 0)
        { pc = 0x10005ade; break; }
  case 0x10005aee: // 0000:10005aee
    if (signed32(memoryAGet32(ds, r32[esi] + 0x649c)) < r32s[eax])
        { pc = 0x10005b0a; break; }
  case 0x10005af6: // 0000:10005af6
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x649c);
    r32[ebp] -= r32[eax];
    r32[edi] = r32[ebp];
    memoryASet32(ds, r32[esi] + 0x649c, r32[ebp]);
    if (r32s[edi] >= r32s[eax])
        { pc = 0x10005af6; break; }
  case 0x10005b0a: // 0000:10005b0a
    if (signed32(memoryAGet32(ds, r32[esi] + 0x649c)) >= r32s[ebx])
        { pc = 0x10005b22; break; }
  case 0x10005b12: // 0000:10005b12
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x649c);
    r32[edi] += r32[eax];
    memoryASet32(ds, r32[esi] + 0x649c, r32[edi]);
    if (r32s[edi] < 0)
        { pc = 0x10005b12; break; }
  case 0x10005b22: // 0000:10005b22
    if (signed32(memoryAGet32(ds, r32[esi] + 0x64a0)) < r32s[eax])
        { pc = 0x10005b3e; break; }
  case 0x10005b2a: // 0000:10005b2a
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x64a0);
    r32[ebp] -= r32[eax];
    r32[edi] = r32[ebp];
    memoryASet32(ds, r32[esi] + 0x64a0, r32[ebp]);
    if (r32s[edi] >= r32s[eax])
        { pc = 0x10005b2a; break; }
  case 0x10005b3e: // 0000:10005b3e
    if (signed32(memoryAGet32(ds, r32[esi] + 0x64a0)) >= r32s[ebx])
        { pc = 0x10005b56; break; }
  case 0x10005b46: // 0000:10005b46
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x64a0);
    r32[edi] += r32[eax];
    memoryASet32(ds, r32[esi] + 0x64a0, r32[edi]);
    if (r32s[edi] < 0)
        { pc = 0x10005b46; break; }
  case 0x10005b56: // 0000:10005b56
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x648c);
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x649c);
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x64ac);
    r32[ecx] += 0x00000004;
    fld32(memoryAGet32(ds, r32[eax] + r32[edi] * 4));
    fmul32(memoryAGet32(ds, r32[esi] + 0x6494));
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x64b4);
    fadd32(memoryAGet32(ds, r32[ebx] + r32[edi] * 4));
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x6498);
    fmul32(memoryAGet32(ds, r32[esi] + 0xbc));
    memoryASet32(ds, r32[eax] + r32[edi] * 4, fstp32());
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6490);
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x64a0);
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x64ac);
    fld32(memoryAGet32(ds, r32[eax] + r32[edi] * 4));
    fmul32(memoryAGet32(ds, r32[esi] + 0x6494));
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x64b4);
    fadd32(memoryAGet32(ds, r32[ebx] + r32[edi] * 4));
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x6498);
    fmul32(memoryAGet32(ds, r32[esi] + 0xbc));
    memoryASet32(ds, r32[eax] + r32[edi] * 4, fstp32());
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x6498);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64b4);
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x64ac);
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x648c);
    r32[ebx]++;
    memoryASet32(ds, r32[esi] + 0x6498, r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x649c);
    fld32(memoryAGet32(ds, r32[edi] + r32[eax] * 4));
    fadd32(memoryAGet32(ss, r32[ebp] + r32[ebx] * 4));
    fld32(memoryAGet32(ds, r32[esi] + 0x614c));
    fmul32(memoryAGet32(ds, 0x1000bb44));
    fadd32(memoryAGet32(ds, 0x1000bb40));
    fmul32(memoryAGet32(ds, r32[esi] + 0x4124));
    fmulpst(1);
    memoryASet32(ds, (r32[edx] + r32[ecx] - 4) >>> 0, fstp32());
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x649c);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64b4);
    r32[ebx] = memoryAGet32(ds, r32[esi] + 0x64a0);
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x6490);
    r32[edi]++;
    memoryASet32(ds, r32[esi] + 0x649c, r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x64ac);
    fld32(memoryAGet32(ds, r32[edi] + r32[eax] * 4));
    fadd32(memoryAGet32(ss, r32[ebp] + r32[ebx] * 4));
    fld32(memoryAGet32(ds, r32[esi] + 0x614c));
    fmul32(memoryAGet32(ds, 0x1000bb44));
    r32[ebx] = 0;
    fadd32(memoryAGet32(ds, 0x1000bb40));
    fmul32(memoryAGet32(ds, r32[esi] + 0x4124));
    fmulpst(1);
    memoryASet32(ds, r32[ecx] - 4, fstp32());
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64a0);
    r32[edi] = memoryAGet32(ds, r32[esi] + 0x64ac);
    r32[eax]++;
    memoryASet32(ds, r32[esi] + 0x64a0, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64b4);
    memoryASet32(ds, r32[edi] + r32[eax] * 4, r32[ebx]);
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x64b4);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[ebp]++;
    r32[eax]--;
    memoryASet32(ds, r32[esi] + 0x64b4, r32[ebp]);
    memoryASet32(ds, r32[esp] + 0x20, r32[eax]);
    if (r32[eax])
        { pc = 0x10005a8e; break; }
  case 0x10005c8c: // 0000:10005c8c
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000008;
    r32[esp] += 16;
    return;
  }
}


function sub_10005ca0() // 0000:10005ca0 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    r32[ebx] = 0;
    r32[ebp] = 0;
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xdc);
    r32[eax] += 0x0000000e;
    r32[eax] <<= 4;
    r32[ecx] = memoryAGet32(ds, r32[eax] + r32[esi]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    if (r32[ecx] != r32[eax])
        { pc = 0x10005e4a; break; }
    push32(r32[edi]);
    r32[edi] = r32[esi] + 20776;
  case 0x10005ccb: // 0000:10005ccb
    r32[edx] = memoryAGet32(ds, r32[esi] + 0xdc);
    r32[edx] <<= 4;
    r32[eax] = r32[edx] + r32[esi];
    r32[edx] = memoryAGet32(ds, r32[edx] + r32[esi] + 0xe4);
    if (r32[edx] == r32[ebx])
        { pc = 0x10005e1f; break; }
    r32[edx] &= 0x000000f0;
    if (r32[edx] == 0x00000090)
        { pc = 0x10005d99; break; }
    if (r32[edx] == 0x00000080)
        { pc = 0x10005d99; break; }
    if (r32[edx] != 0x000000b0)
        { pc = 0x10005d3a; break; }
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0xe8);
    r32[ecx] &= 0x0000007f;
    memoryASet32(ds, r32[esi] + 0x4114, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0xec);
    r32[eax] &= 0x0000007f;
    r32[edx] = r32[ecx];
    push32(r32[eax]);
    push32(r32[edx]);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x4118, r32[eax]);
    sub_10006330();
    { pc = 0x10005dbe; break; }
  case 0x10005d3a: // 0000:10005d3a
    if (r32[edx] != 0x000000e0)
        { pc = 0x10005dbe; break; }
    if (memoryAGet32(ds, r32[esp] + 0x14) == r32[ebx])
        { pc = 0x10005d6f; break; }
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0xe8);
    r32[ecx] &= 0x0000007f;
    memoryASet32(ds, r32[esi] + 0x411c, r32[ecx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0xec);
    r32[edx] &= 0x0000007f;
    memoryASet(ds, r32[esi] + 0x6140, 0x01);
    memoryASet32(ds, r32[esi] + 0x4120, r32[edx]);
    { pc = 0x10005dbe; break; }
  case 0x10005d6f: // 0000:10005d6f
    r32[eax] = memoryAGet32(ds, r32[eax] + 0xe8);
    r32[eax] &= 0x0000007f;
    memoryASet32(ds, r32[edi] - 4096, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xdc);
    r32[ecx] <<= 4;
    r32[edx] = memoryAGet32(ds, r32[ecx] + r32[esi] + 0xec);
    r32[edx] &= 0x0000007f;
    r32[ebp]++;
    memoryASet32(ds, r32[edi], r32[edx]);
    r32[edi] += 0x00000004;
    { pc = 0x10005dbe; break; }
  case 0x10005d99: // 0000:10005d99
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0xe8);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0xec);
    r32[ecx] &= 0x0000007f;
    r32[eax] &= 0x0000007f;
    if (r32[edx] != 0x00000080)
        { pc = 0x10005db5; break; }
    r32[eax] = 0;
  case 0x10005db5: // 0000:10005db5
    push32(r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = r32[esi];
    sub_10006240();
  case 0x10005dbe: // 0000:10005dbe
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xdc);
    r32[eax] += 0x0000000e;
    r32[eax] <<= 4;
    memoryASet32(ds, r32[eax] + r32[esi], r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0xdc);
    r32[ecx] <<= 4;
    memoryASet32(ds, r32[ecx] + r32[esi] + 0xe4, r32[ebx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0xdc);
    r32[edx] <<= 4;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
    memoryASet32(ds, r32[edx] + r32[esi] + 0xe8, r32[ebx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0xdc);
    r32[eax] <<= 4;
    memoryASet32(ds, r32[eax] + r32[esi] + 0xec, r32[ebx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0xdc);
    r32[edx]++;
    r32[eax] = r32[edx];
    memoryASet32(ds, r32[esi] + 0xdc, r32[edx]);
    r32[eax] += 0x0000000e;
    r32[eax] <<= 4;
    if (memoryAGet32(ds, r32[eax] + r32[esi]) == r32[ecx])
        { pc = 0x10005ccb; break; }
  case 0x10005e1f: // 0000:10005e1f
    r32[edi] = pop32();
    if (r32[ebp] == r32[ebx])
        { pc = 0x10005e4a; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x14);
    memoryASet32(ds, r32[esi] + 0x6128, 0x00000001);
    memoryASet32(ds, r32[esi] + 0x612c, r32[ebp]);
    memoryASet32(ds, r32[esi] + 0x6134, r32[ebx]);
    r32[eax] = r32[edx] - 2;
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[ebp]);
    memoryASet32(ds, r32[esi] + 0x6130, r32[eax]);
  case 0x10005e4a: // 0000:10005e4a
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6128);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x10);
    if (r32[eax] != r32[ecx])
        { pc = 0x10005ea2; break; }
    if (r32[eax] == r32[ebx])
        { pc = 0x10005ea2; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6134);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x612c);
    if (r32s[eax] >= r32s[edx])
        { pc = 0x10005ea2; break; }
    r32[edx] = memoryAGet32(ds, r32[esi] + r32[eax] * 4 + 0x4128);
    r32[eax]++;
    memoryASet32(ds, r32[esi] + 0x411c, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + r32[eax] * 4 + 0x5124);
    memoryASet32(ds, r32[esi] + 0x6134, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6130);
    r32[eax] += r32[ecx];
    memoryASet32(ds, r32[esi] + 0x4120, r32[edx]);
    memoryASet(ds, r32[esi] + 0x6140, 0x01);
    memoryASet32(ds, r32[esi] + 0x6128, r32[eax]);
  case 0x10005ea2: // 0000:10005ea2
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 12;
    return;
  }
}


function sub_10006240() // 0000:10006240 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[ebx]);
    r32[ebx] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[esi]);
    r32[ebx] -= 0x0000000c;
    r32[esi] = r32[ecx];
    if (!r32[eax])
        { pc = 0x1000628a; break; }
    if (r32s[ebx] > signed32(0x00000048))
        { pc = 0x100062c2; break; }
    if (r32s[ebx] <= signed32(0x00000003))
        { pc = 0x100062c2; break; }
    push32(r32[edi]);
    r32[edi] = r32[esi] + 25460;
    r32[edx] = 0x0000007f;
    r32[eax] = r32[edi];
  case 0x1000626b: // 0000:1000626b
    if (memoryAGet32(ds, r32[edi]))
        { pc = 0x10006281; break; }
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    if (!r32[ecx])
        { pc = 0x10006279; break; }
    memoryASet32(ds, r32[eax] + 0x4, r32[ecx]);
  case 0x10006279: // 0000:10006279
    r32[edx]--;
    r32[eax] -= 0x00000004;
    if (r32s[edx] >= 0)
        { pc = 0x1000626b; break; }
  case 0x10006281: // 0000:10006281
    memoryASet32(ds, r32[esi] + 0x6178, r32[ebx]);
    r32[edi] = pop32();
    { pc = 0x100062c2; break; }
  case 0x1000628a: // 0000:1000628a
    if (r32s[ebx] > signed32(0x00000048))
        { pc = 0x100062c2; break; }
    if (r32s[ebx] <= signed32(0x00000003))
        { pc = 0x100062c2; break; }
    r32[ecx] = 0;
  case 0x10006296: // 0000:10006296
    r32[edx] = memoryAGet32(ds, r32[esi] + r32[ecx] * 4 + 0x6178);
    r32[eax] = (r32[esi] + (r32[ecx] * 4)) + 24952;
    if (r32[edx] != r32[ebx])
        { pc = 0x100062bc; break; }
    if (!r32[edx])
        { pc = 0x100062bc; break; }
  case 0x100062ac: // 0000:100062ac
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    r32[ecx]++;
    memoryASet32(ds, r32[eax], r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x4);
    r32[eax] += 0x00000004;
    if (r32[edx])
        { pc = 0x100062ac; break; }
  case 0x100062bc: // 0000:100062bc
    r32[ecx]++;
    if (r32s[ecx] <= signed32(0x0000007f))
        { pc = 0x10006296; break; }
  case 0x100062c2: // 0000:100062c2
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6178);
    r8[bl] = 0x01;
    memoryASet32(ds, r32[esp] + 0xc, r32[eax]);
    fild32(memoryAGet32(ds, r32[esp] + 0xc));
    r8[cl] = r32[eax] != 0;
    memoryASet32(ds, r32[esi] + 0x6144, fstp32());
    memoryASet(ds, r32[esi] + 0x6174, r8[cl]);
    if (r32[eax])
        { pc = 0x1000630b; break; }
    r32[edx] = memoryAGet32(ds, r32[esi]);
    push32(0x3e2ab368);
    push32(0x00000006);
    r32[ecx] = r32[esi];
    memoryASet(ds, r32[esi] + 0x6150, r8[al]);
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4));
    memoryASet32(ds, r32[esi] + 0x6464, 0x00000000);
    memoryASet(ds, r32[esi] + 0x6400, r8[bl]);
  case 0x1000630b: // 0000:1000630b
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x617c);
    if (!r32[eax])
        { pc = 0x10006325; break; }
    r8[al] = memoryAGet(ds, r32[esi] + 0x6150);
    if (r8[al])
        { pc = 0x10006325; break; }
    memoryASet(ds, r32[esi] + 0x6150, r8[bl]);
  case 0x10006325: // 0000:10006325
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 12;
    return;
  }
}


function sub_10006400() // 0000:10006400 +long
{
    r32[esp] -= 4;
    push32(r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x63f8);
    r32[eax] = r32s[eax] * signed32(0x0019660d);
    r32[eax] += 0x3c6ef35f;
    memoryASet32(ds, r32[esp], r32[eax]);
    memoryASet32(ds, r32[ecx] + 0x63f8, r32[eax]);
    fild32(memoryAGet32(ds, r32[esp]));
    fmul32(memoryAGet32(ds, r32[ecx] + 0x63fc));
    r32[ecx] = pop32();
    r32[esp] += 4;
}



function sub_1000a75c() // 0000:1000a75c thunk: msvcrt._ftol (truncate ST(0) to int32 in eax)
{
    r32[eax] = Math.trunc(fppop()) | 0;
}
function sub_10004870() // 0000:10004870 +long +stackDrop4
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[edx] = r32[eax];
    memoryASet32(ds, r32[ecx] + 0x4, r32[eax]);
    memoryASet32(ds, r32[ecx] + 0x63ec, r32[edx]);
    r32[esp] += 8;
}


function sub_10004890() // 0000:10004890 +long +stackDrop4
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    memoryASet32(ds, r32[ecx] + 0x1c, r32[eax]);
    memoryASet32(ds, r32[ecx] + 0x63f4, r32[eax]);
    r32[esp] += 8;
}


function sub_100048b0() // 0000:100048b0 +long
{
    r32[esp] -= 4;
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    push32(0x00000001);
    r32[eax] = memoryAGet32(ds, r32[esi]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0xbc));
    r32[ecx] = r32[esi];
    sub_100048d0();
    r32[esi] = pop32();
    stop("stack_unbalanced");
    r32[esp] += 4;
}
function sub_100048d0() // 0000:100048d0 +long
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
    r32[esi] = r32[ecx];
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[esi]);
    indirectCall(cs, memoryAGet32(ds, r32[eax] + 0x88));
    memoryASet32(ds, r32[esi] + 0x63ec, fst32());
    fcomp32(memoryAGet32(ds, r32[esi] + 0x63f0));
    r32[ebx] = 0;
    r16[ax] = fnstsw();
    if (r8[ah] & 0x40)
        { pc = 0x10004a3f; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64a4);
    if (r32[eax] == r32[ebx])
        { pc = 0x1000490d; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x1000490d: // 0000:1000490d
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64ac);
    if (r32[eax] == r32[ebx])
        { pc = 0x10004920; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x10004920: // 0000:10004920
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64b8);
    if (r32[eax] == r32[ebx])
        { pc = 0x10004933; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x10004933: // 0000:10004933
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64c0);
    if (r32[eax] == r32[ebx])
        { pc = 0x10004946; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x10004946: // 0000:10004946
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64c8);
    if (r32[eax] == r32[ebx])
        { pc = 0x10004959; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x10004959: // 0000:10004959
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64cc);
    if (r32[eax] == r32[ebx])
        { pc = 0x1000496c; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x1000496c: // 0000:1000496c
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64d8);
    if (r32[eax] == r32[ebx])
        { pc = 0x1000497f; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x1000497f: // 0000:1000497f
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64dc);
    if (r32[eax] == r32[ebx])
        { pc = 0x10004992; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x10004992: // 0000:10004992
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x648c);
    if (r32[eax] == r32[ebx])
        { pc = 0x100049a5; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x100049a5: // 0000:100049a5
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6490);
    if (r32[eax] == r32[ebx])
        { pc = 0x100049b8; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x100049b8: // 0000:100049b8
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64e4);
    if (r32[eax] == r32[ebx])
        { pc = 0x100049cb; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x100049cb: // 0000:100049cb
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64e8);
    if (r32[eax] == r32[ebx])
        { pc = 0x100049de; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x100049de: // 0000:100049de
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64ec);
    if (r32[eax] == r32[ebx])
        { pc = 0x100049f1; break; }
    push32(r32[eax]);
    sub_1000a756();
    r32[esp] += 0x00000004;
  case 0x100049f1: // 0000:100049f1
    memoryASet32(ds, r32[esi] + 0x64a4, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64ac, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64c0, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64cc, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64d8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64b8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64c8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64dc, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x648c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6490, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64e4, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64e8, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64ec, r32[ebx]);
  case 0x10004a3f: // 0000:10004a3f
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x63ec);
    memoryASet32(ds, r32[esi] + 0x63f0, r32[ecx]);
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul64(memoryAGet64(ds, 0x1000bb28));
    sub_1000a75c();
    memoryASet32(ds, r32[esi] + 0x64a8, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64a4);
    if (r32[ecx] != r32[ebx])
        { pc = 0x10004a82; break; }
    r32[edx] = (r32[eax] * 4) + 0;
    push32(r32[edx]);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64a4, r32[eax]);
  case 0x10004a82: // 0000:10004a82
    memoryASet32(ds, r32[esi] + 0x64b0, 0x00002800);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64ac);
    if (r32[eax] != r32[ebx])
        { pc = 0x10004aa9; break; }
    push32(0x0000a000);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64ac, r32[eax]);
  case 0x10004aa9: // 0000:10004aa9
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64b0);
    r32[eax] = 0;
    if (r32s[ecx] <= r32s[ebx])
        { pc = 0x10004aca; break; }
  case 0x10004ab5: // 0000:10004ab5
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64ac);
    r32[eax]++;
    memoryASet32(ds, r32[ecx] + r32[eax] * 4 - 4, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64b0);
    if (r32s[eax] < r32s[ecx])
        { pc = 0x10004ab5; break; }
  case 0x10004aca: // 0000:10004aca
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64a8);
    r32[eax] <<= 2;
    memoryASet32(ds, r32[esi] + 0x64c4, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64c0);
    if (r32[ecx] != r32[ebx])
        { pc = 0x10004af9; break; }
    r32[edx] = (r32[eax] * 4) + 0;
    push32(r32[edx]);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64c0, r32[eax]);
  case 0x10004af9: // 0000:10004af9
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fdivr64(memoryAGet64(ds, 0x1000bb20));
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64c4);
    r32[edi] = 0;
    memoryASet32(ds, r32[esp] + 0x10, r32[edi]);
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    if (r32s[eax] <= r32s[ebx])
        { pc = 0x10004b45; break; }
  case 0x10004b19: // 0000:10004b19
    fld64(memoryAGet64(ds, 0x1000bb18));
    fild32(memoryAGet32(ds, r32[esp] + 0x10));
    fmul32(memoryAGet32(ds, r32[esp] + 0x14));
    fchs();
    sub_1000a768();
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64c0);
    r32[edi]++;
    memoryASet32(ds, r32[esp] + 0x10, r32[edi]);
    memoryASet32(ds, r32[eax] + r32[edi] * 4 - 4, fstp32());
    if (r32s[edi] < signed32(memoryAGet32(ds, r32[esi] + 0x64c4)))
        { pc = 0x10004b19; break; }
  case 0x10004b45: // 0000:10004b45
    memoryASet32(ds, r32[esi] + 0x64d0, 0x00000400);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64cc);
    if (r32[eax] != r32[ebx])
        { pc = 0x10004b6c; break; }
    push32(0x00001000);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64cc, r32[eax]);
  case 0x10004b6c: // 0000:10004b6c
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64d0);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x10, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
    if (r32s[ecx] <= r32s[ebx])
        { pc = 0x10004bad; break; }
  case 0x10004b80: // 0000:10004b80
    fild32(memoryAGet32(ds, r32[esp] + 0x10));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64cc);
    r32[eax]++;
    memoryASet32(ds, r32[esp] + 0x10, r32[eax]);
    fmul64(memoryAGet64(ds, 0x1000bb10));
    fidiv32(memoryAGet32(ds, r32[esp] + 0x14));
    fsin();
    memoryASet32(ds, r32[ecx] + r32[eax] * 4 - 4, fstp32());
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64d0);
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
    if (r32s[eax] < r32s[ecx])
        { pc = 0x10004b80; break; }
  case 0x10004bad: // 0000:10004bad
    fild32(memoryAGet32(ds, r32[esi] + 0x64d0));
    fdiv32(memoryAGet32(ds, r32[esi] + 0x63ec));
    memoryASet32(ds, r32[esi] + 0x64d4, fstp32());
    if (memoryAGet32(ds, r32[esi] + 0x64d8) != r32[ebx])
        { pc = 0x10004bdf; break; }
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64a8);
    r32[edx] <<= 2;
    push32(r32[edx]);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64d8, r32[eax]);
  case 0x10004bdf: // 0000:10004bdf
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64a8);
    r32[edi] = 0;
    fld32(memoryAGet32(ds, 0x1000b208));
    fld32(memoryAGet32(ds, 0x1000b208));
    memoryASet32(ds, r32[esp] + 0x10, r32[edi]);
    if (r32s[eax] <= r32s[ebx])
        { pc = 0x10004c84; break; }
  case 0x10004bff: // 0000:10004bff
    fild32(memoryAGet32(ds, r32[esp] + 0x10));
    fmul64(memoryAGet64(ds, 0x1000bb10));
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul32(memoryAGet32(ds, 0x1000bb08));
    fdivr80(st(1));
    fsin();
    fldst(3);
    sub_1000a75c();
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64c0);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64d8);
    fmul32(memoryAGet32(ds, r32[ecx] + r32[eax] * 4));
    memoryASet32(ds, r32[edx] + r32[edi] * 4, fstp32());
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul32(memoryAGet32(ds, 0x1000bb04));
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64d8);
    fdivp80(st(1));
    r32[ebp] = r32[eax] + (r32[edi] * 4);
    fsin();
    fldst(1);
    sub_1000a75c();
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64c0);
    r32[edi]++;
    memoryASet32(ds, r32[esp] + 0x10, r32[edi]);
    fmul32(memoryAGet32(ds, r32[ecx] + r32[eax] * 4));
    fadd32(memoryAGet32(ss, r32[ebp]));
    memoryASet32(ss, r32[ebp], fstp32());
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64a8);
    fxchst2(0, 1);
    fadd32(memoryAGet32(ds, 0x1000b90c));
    fxchst2(0, 1);
    fadd32(memoryAGet32(ds, 0x1000bb00));
    if (r32s[edi] < r32s[eax])
        { pc = 0x10004bff; break; }
  case 0x10004c84: // 0000:10004c84
    memoryASet32(ds, r32[esi] + 0x64bc, 0x00000400);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64b8);
    fstpst(0);
    fstpst(0);
    if (r32[eax] != r32[ebx])
        { pc = 0x10004caf; break; }
    push32(0x00001000);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64b8, r32[eax]);
  case 0x10004caf: // 0000:10004caf
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64bc);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x10, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
    if (r32s[ecx] <= r32s[ebx])
        { pc = 0x10004cf0; break; }
  case 0x10004cc3: // 0000:10004cc3
    fild32(memoryAGet32(ds, r32[esp] + 0x10));
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64b8);
    r32[eax]++;
    memoryASet32(ds, r32[esp] + 0x10, r32[eax]);
    fmul64(memoryAGet64(ds, 0x1000bb10));
    fidiv32(memoryAGet32(ds, r32[esp] + 0x14));
    fsin();
    memoryASet32(ds, r32[edx] + r32[eax] * 4 - 4, fstp32());
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64bc);
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
    if (r32s[eax] < r32s[ecx])
        { pc = 0x10004cc3; break; }
  case 0x10004cf0: // 0000:10004cf0
    fild32(memoryAGet32(ds, r32[esi] + 0x64bc));
    fdivr32(memoryAGet32(ds, r32[esi] + 0x63ec));
    memoryASet32(ds, r32[esi] + 0x6168, fstp32());
    if (memoryAGet32(ds, r32[esi] + 0x64c8) != r32[ebx])
        { pc = 0x10004d22; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64a8);
    r32[eax] <<= 2;
    push32(r32[eax]);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64c8, r32[eax]);
  case 0x10004d22: // 0000:10004d22
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul64(memoryAGet64(ds, 0x1000baf8));
    sub_1000a75c();
    memoryASet32(ds, r32[esi] + 0x638c, r32[eax]);
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul64(memoryAGet64(ds, 0x1000baf0));
    sub_1000a75c();
    memoryASet32(ds, r32[esi] + 0x6390, r32[eax]);
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul64(memoryAGet64(ds, 0x1000bae8));
    sub_1000a75c();
    memoryASet32(ds, r32[esi] + 0x6394, r32[eax]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64a8);
    r32[eax] = 0;
    if (r32s[ecx] <= r32s[ebx])
        { pc = 0x10004d8c; break; }
  case 0x10004d73: // 0000:10004d73
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64c8);
    r32[eax]++;
    memoryASet32(ds, r32[ecx] + r32[eax] * 4 - 4, 0x3f800000);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64a8);
    if (r32s[eax] < r32s[ecx])
        { pc = 0x10004d73; break; }
  case 0x10004d8c: // 0000:10004d8c
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x638c);
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x10, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
    if (r32s[ecx] <= r32s[ebx])
        { pc = 0x10004dd9; break; }
  case 0x10004da0: // 0000:10004da0
    fild32(memoryAGet32(ds, r32[esp] + 0x10));
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64c8);
    r32[eax]++;
    memoryASet32(ds, r32[esp] + 0x10, r32[eax]);
    fmul64(memoryAGet64(ds, 0x1000bae0));
    fidiv32(memoryAGet32(ds, r32[esp] + 0x14));
    fcos();
    fsubr64(memoryAGet64(ds, 0x1000b220)); // dc 2d 20 b2 00 10 : fsubr qword ptr [0x1000b220]
    fmul64(memoryAGet64(ds, 0x1000ba78));
    memoryASet32(ds, r32[edx] + r32[eax] * 4 - 4, fstp32());
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x638c);
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
    if (r32s[eax] < r32s[ecx])
        { pc = 0x10004da0; break; }
  case 0x10004dd9: // 0000:10004dd9
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6390);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64a8);
    if (r32s[eax] >= r32s[ecx])
        { pc = 0x10004e28; break; }
  case 0x10004de9: // 0000:10004de9
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6394);
    memoryASet32(ds, r32[esp] + 0x10, r32[ecx]);
    r32[ecx] += r32[eax];
    memoryASet32(ds, r32[esp] + 0x14, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64c8);
    fild32(memoryAGet32(ds, r32[esp] + 0x14));
    r32[eax]++;
    fmul64(memoryAGet64(ds, 0x1000bae0));
    fidiv32(memoryAGet32(ds, r32[esp] + 0x10));
    fcos();
    fsubr64(memoryAGet64(ds, 0x1000b220)); // dc 2d 20 b2 00 10 : fsubr qword ptr [0x1000b220]
    fmul64(memoryAGet64(ds, 0x1000ba78));
    memoryASet32(ds, r32[ecx] + r32[eax] * 4 - 4, fstp32());
    if (r32s[eax] < signed32(memoryAGet32(ds, r32[esi] + 0x64a8)))
        { pc = 0x10004de9; break; }
  case 0x10004e28: // 0000:10004e28
    memoryASet32(ds, r32[esi] + 0x64e0, 0x00001000);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64dc);
    if (r32[eax] != r32[ebx])
        { pc = 0x10004e4f; break; }
    push32(0x00004000);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64dc, r32[eax]);
  case 0x10004e4f: // 0000:10004e4f
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64e0);
    r32[edi] = 0;
    memoryASet32(ds, r32[esp] + 0x10, r32[edi]);
    if (r32s[eax] <= r32s[ebx])
        { pc = 0x10004e93; break; }
  case 0x10004e5f: // 0000:10004e5f
    fld64(memoryAGet64(ds, 0x1000bad8));
    fild32(memoryAGet32(ds, r32[esp] + 0x10));
    fmul64(memoryAGet64(ds, 0x1000bad0));
    sub_1000a768();
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64dc);
    r32[edi]++;
    fmul64(memoryAGet64(ds, 0x1000bac8));
    memoryASet32(ds, r32[edx] + r32[edi] * 4 - 4, fstp32());
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64e0);
    memoryASet32(ds, r32[esp] + 0x10, r32[edi]);
    if (r32s[edi] < r32s[eax])
        { pc = 0x10004e5f; break; }
  case 0x10004e93: // 0000:10004e93
    r32[eax] = 0x00000320;
    memoryASet32(ds, r32[esp] + 0x18, 0x00000118);
    memoryASet32(ds, r32[esp] + 0x20, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x30, r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64e4);
    memoryASet32(ds, r32[esp] + 0x1c, 0x000001c2);
    memoryASet32(ds, r32[esp] + 0x24, 0x0000015e);
    memoryASet32(ds, r32[esp] + 0x28, 0x0000010e);
    memoryASet32(ds, r32[esp] + 0x2c, 0x00000258);
    memoryASet32(ds, r32[esp] + 0x34, 0x0000047e);
    memoryASet32(ds, r32[esp] + 0x38, 0x000007d0);
    memoryASet32(ds, r32[esp] + 0x3c, 0x0000085c);
    memoryASet32(ds, r32[esp] + 0x40, 0x000008c0);
    memoryASet32(ds, r32[esp] + 0x44, 0x00000b0e);
    memoryASet32(ds, r32[esp] + 0x48, 0x00000b54);
    memoryASet32(ds, r32[esp] + 0x4c, 0x00000af0);
    memoryASet32(ds, r32[esp] + 0x50, 0x00000b86);
    if (r32[eax] != r32[ebx])
        { pc = 0x10004f25; break; }
    push32(0x00001400);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64e4, r32[eax]);
  case 0x10004f25: // 0000:10004f25
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64e4);
    r32[ecx] = r32[esp] + 24;
    push32(r32[eax]);
    push32(r32[ecx]);
    r32[ecx] = r32[esi];
    sub_10005350();
    if (memoryAGet32(ds, r32[esi] + 0x64e8) != r32[ebx])
        { pc = 0x10004f53; break; }
    push32(0x00001400);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64e8, r32[eax]);
  case 0x10004f53: // 0000:10004f53
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64e8);
    r32[eax] = r32[esp] + 44;
    push32(r32[edx]);
    push32(r32[eax]);
    r32[ecx] = r32[esi];
    sub_10005350();
    if (memoryAGet32(ds, r32[esi] + 0x64ec) != r32[ebx])
        { pc = 0x10004f81; break; }
    push32(0x00001400);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x64ec, r32[eax]);
  case 0x10004f81: // 0000:10004f81
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64ec);
    r32[edx] = r32[esp] + 64;
    push32(r32[ecx]);
    push32(r32[edx]);
    r32[ecx] = r32[esi];
    sub_10005350();
    memoryASet32(ds, r32[esi] + 0x639c, 0x42020000);
    memoryASet32(ds, r32[esi] + 0x63a0, 0x423e0000);
    memoryASet32(ds, r32[esi] + 0x63a4, 0x427a0000);
    r32[eax] = r32[esi] + 228;
    fld32(memoryAGet32(ds, r32[esi] + 0x639c));
    fmul32(memoryAGet32(ds, 0x1000bac4));
    r32[ecx] = 0x00000400;
    memoryASet32(ds, r32[esi] + 0x639c, fstp32());
    fld32(memoryAGet32(ds, r32[esi] + 0x63a0));
    fmul32(memoryAGet32(ds, 0x1000bac4));
    memoryASet32(ds, r32[esi] + 0x63a0, fstp32());
    fld32(memoryAGet32(ds, r32[esi] + 0x63a4));
    fmul32(memoryAGet32(ds, 0x1000bac4));
    memoryASet32(ds, r32[esi] + 0x63a4, fstp32());
  case 0x10004ff3: // 0000:10004ff3
    memoryASet32(ds, r32[eax] - 4, r32[ebx]);
    memoryASet32(ds, r32[eax], r32[ebx]);
    memoryASet32(ds, r32[eax] + 0x4, r32[ebx]);
    memoryASet32(ds, r32[eax] + 0x8, r32[ebx]);
    r32[eax] += 0x00000010;
    r32[ecx]--;
    if (r32[ecx])
        { pc = 0x10004ff3; break; }
    r32[edi] = r32[esi] + 24952;
    r32[ecx] = 0x00000080;
    r32[eax] = 0;
    r32[edx] = 0x3e087fcc;
    for (; r32[ecx] != 0; --r32[ecx]) stosd_ESEDI(r32[eax]);
    r32[ecx] = 0x3e2ab368;
    r32[edi] = 0x3dcccccd;
    memoryASet32(ds, r32[esi] + 0x6404, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x6408, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x640c, r32[edx]);
    r32[ebp] = 0x3d889a02;
    memoryASet32(ds, r32[esi] + 0x6410, r32[edi]);
    r32[eax] = 0x3d086595;
    memoryASet32(ds, r32[esi] + 0x6414, r32[ebp]);
    memoryASet32(ds, r32[esi] + 0x6418, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x641c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6420, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x6424, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x6428, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x642c, r32[edx]);
    memoryASet32(ds, r32[esi] + 0x6430, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x6434, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x6438, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x643c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6440, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x6444, r32[ebp]);
    memoryASet32(ds, r32[esi] + 0x6448, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x644c, r32[edx]);
    memoryASet32(ds, r32[esi] + 0x6450, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x6454, r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x6458, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x645c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6460, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x6488, 0x00004e20);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x648c);
    if (r32[eax] != r32[ebx])
        { pc = 0x100050e3; break; }
    push32(0x00013880);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x648c, r32[eax]);
  case 0x100050e3: // 0000:100050e3
    if (memoryAGet32(ds, r32[esi] + 0x6490) != r32[ebx])
        { pc = 0x10005103; break; }
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x6488);
    r32[eax] <<= 2;
    push32(r32[eax]);
    sub_1000a7fc();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esi] + 0x6490, r32[eax]);
  case 0x10005103: // 0000:10005103
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6488);
    r32[eax] = 0;
    if (r32s[ecx] <= r32s[ebx])
        { pc = 0x1000512e; break; }
  case 0x1000510f: // 0000:1000510f
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x648c);
    r32[eax]++;
    memoryASet32(ds, r32[ecx] + r32[eax] * 4 - 4, r32[ebx]);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x6490);
    memoryASet32(ds, r32[edx] + r32[eax] * 4 - 4, r32[ebx]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x6488);
    if (r32s[eax] < r32s[ecx])
        { pc = 0x1000510f; break; }
  case 0x1000512e: // 0000:1000512e
    r32[eax] = 0x00000040;
    memoryASet32(ds, r32[esi] + 0x6138, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x411c, r32[eax]);
    r32[ebp] = 0x3f000000;
    memoryASet32(ds, r32[esi] + 0x4120, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x613c, r32[ebp]);
    memoryASet(ds, r32[esi] + 0x6140, r8[bl]);
    memoryASet(ds, r32[esi] + 0x6141, r8[bl]);
    memoryASet(ds, r32[esi] + 0x6174, r8[bl]);
    memoryASet(ds, r32[esi] + 0x6142, 0x01);
    memoryASet32(ds, r32[esi] + 0x4118, r32[ebx]);
    push32(r32[ebp]);
    r32[ecx] = r32[esi];
    memoryASet32(ds, r32[esi] + 0x4114, 0x00000001);
    memoryASet32(ds, r32[esi] + 0x4124, r32[edi]);
    memoryASet(ds, r32[esi] + 0xd5, r8[bl]);
    memoryASet(ds, r32[esi] + 0xd4, r8[bl]);
    sub_10005fb0();
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul32(memoryAGet32(ds, 0x1000bac0));
    memoryASet32(ds, r32[esi] + 0xb8, r32[ebp]);
    memoryASet(ds, r32[esi] + 0x6150, r8[bl]);
    memoryASet32(ds, r32[esi] + 0x6154, 0x42100000);
    memoryASet32(ds, r32[esi] + 0x615c, 0x40800000);
    fmul64(memoryAGet64(ds, 0x1000bab8));
    memoryASet32(ds, r32[esi] + 0x6160, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6164, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6158, r32[ebx]);
    sub_1000a75c();
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul64(memoryAGet64(ds, 0x1000bab0));
    memoryASet32(ds, r32[esi] + 0x616c, r32[eax]);
    memoryASet(ds, r32[esi] + 0x6400, 0x01);
    memoryASet32(ds, r32[esi] + 0x646c, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6468, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6464, r32[ebx]);
    sub_1000a75c();
    r32[edi] = r32[eax];
    memoryASet32(ds, r32[esp] + 0x14, r32[edi]);
    memoryASet32(ds, r32[esi] + 0x6470, r32[edi]);
    fild32(memoryAGet32(ds, r32[esp] + 0x14));
    r32[eax] = (r32[edi] * 8) + 0;
    r32[eax] -= r32[edi];
    fmul64(memoryAGet64(ds, 0x1000baa8));
    memoryASet32(ds, r32[esi] + 0x6474, r32[eax]);
    sub_1000a75c();
    memoryASet32(ds, r32[esi] + 0x6478, r32[eax]);
    r32[eax] = r32[edi] + (r32[edi] * 2);
    fld64(memoryAGet64(ds, 0x1000baa0));
    fld64(memoryAGet64(ds, 0x1000ba98));
    r32[ecx] = r32[eax] + (r32[eax] * 4);
    r32[edx] = r32[edi];
    r32[eax] = r32[edi] + (r32[edi] * 2);
    memoryASet32(ds, r32[esi] + 0x647c, r32[ecx]);
    r32[edx] <<= 4;
    r32[eax] <<= 3;
    r32[edx] += r32[edi];
    r32[eax] -= r32[edi];
    memoryASet32(ds, r32[esi] + 0x6480, r32[edx]);
    memoryASet32(ds, r32[esi] + 0x6484, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x6378, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x64b4, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6388, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x6170, r32[ebx]);
    sub_1000a768();
    fdivr32(memoryAGet32(ds, 0x1000b8fc));
    memoryASet32(ds, r32[esi] + 0x6498, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x63fc, fstp32());
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul64(memoryAGet64(ds, 0x1000ba90));
    sub_1000a75c();
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul64(memoryAGet64(ds, 0x1000ba88));
    memoryASet32(ds, r32[esi] + 0x649c, r32[eax]);
    sub_1000a75c();
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul32(memoryAGet32(ds, 0x1000ba84));
    memoryASet32(ds, r32[esi] + 0x64a0, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x6494, r32[ebp]);
    fmul32(memoryAGet32(ds, 0x1000b8b0));
    sub_1000a75c();
    fld32(memoryAGet32(ds, r32[esi] + 0x63ec));
    fmul32(memoryAGet32(ds, 0x1000ba80));
    memoryASet32(ds, r32[esi] + 0x63b4, r32[eax]);
    sub_1000a75c();
    r32[ecx] = r32[eax];
    r32[edi] = pop32();
    memoryASet32(ds, r32[esi] + 0x63b8, r32[ecx]);
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x63b4);
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    idiv32(r32[ecx]);
    memoryASet32(ds, r32[esi] + 0x63bc, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x63c4, 0x00002000);
    memoryASet32(ds, r32[esi] + 0x63d8, 0x42100000);
    memoryASet32(ds, r32[esi] + 0x63c0, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x63d0, r32[ebx]);
    memoryASet32(ds, r32[esi] + 0x63e8, r32[ebx]);
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000044;
    stop("stack_unbalanced");
    r32[esp] += 4;
    return;
  }
}


function sub_10002060() // 0000:10002060 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0xc);
    if (!r32[eax])
        { pc = 0x1000207d; break; }
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x4);
    push32(0x00000000);
    push32(0x00000000);
    push32(r32[edx]);
    push32(0x00000000);
    r32[ecx] += 0x00000020;
    push32(0x00000006);
    push32(r32[ecx]);
    indirectCall(cs, r32[eax]);
    r32[esp] += 0x00000018;
  case 0x1000207d: // 0000:1000207d
    r32[esp] += 8; return;
    return;
  }
}


function sub_10001970() // 0000:10001970 +long
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, r32[ecx] + 0x4));
    r32[esp] += 4;
}


function sub_1000a768() // 0000:1000a768 thunk: msvcrt._CIpow — pow(ST(1), ST(0)), FPU stack
{
    const y = fppop();
    setst(0, Math.pow(st(0), y));
}


function sub_10005350() // 0000:10005350 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x00000038;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x3c);
    push32(r32[ebx]);
    push32(r32[ebp]);
    push32(r32[esi]);
    r32[ecx] = memoryAGet32(ds, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[eax] + 0x8);
    memoryASet32(ds, r32[esp] + 0x28, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x2c, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x4);
    memoryASet32(ds, r32[esp] + 0x34, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x4c);
    memoryASet32(ds, r32[esp] + 0x30, r32[ecx]);
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0xc);
    r32[eax] = memoryAGet32(ds, r32[eax] + 0x10);
    push32(r32[edi]);
    memoryASet32(ds, r32[esp] + 0x3c, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x40, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x44, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x4c, 0x00000001);
    r32[edi] = 0x00000140;
    r32[esi] = r32[esp] + 48;
    memoryASet32(ds, r32[esp] + 0x50, r32[edx]);
  case 0x1000539e: // 0000:1000539e
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4c);
    r32[ebp] = r32[edi] - 320;
    r32[eax]--;
    memoryASet32(ds, r32[esp] + 0x14, r32[eax]);
    fild32(memoryAGet32(ds, r32[esp] + 0x14));
    memoryASet32(ds, r32[esp] + 0x14, r32[ebp]);
    fmul64(memoryAGet64(ds, 0x1000bb38));
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    if (r32s[ebp] >= r32s[edi])
        { pc = 0x1000546a; break; }
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x8);
    r32[eax] = memoryAGet32(ds, r32[esi]);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x4);
    r32[ebx] = memoryAGet32(ds, r32[esi] - 4);
    memoryASet32(ds, r32[esp] + 0x10, r32[edx]);
    r32[edx] = r32[eax];
    r32[edx] -= r32[ecx];
    memoryASet32(ds, r32[esp] + 0x1c, r32[ecx]);
    memoryASet32(ds, r32[esp] + 0x24, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x20, r32[ebx]);
    r32[edx] = r32[edx] + (r32[edx] * 2);
    r32[edx] -= r32[ebx];
    r32[edx] += memoryAGet32(ds, r32[esp] + 0x10);
    memoryASet32(ds, r32[esp] + 0x18, r32[edx]);
    r32[edx] = memoryAGet32(ds, r32[esp] + 0x10);
    fild32(memoryAGet32(ds, r32[esp] + 0x18));
    r32[edx] = r32[edx] + (r32[eax] * 4);
    r32[eax] += r32[edx];
    fmul32(memoryAGet32(ds, 0x1000bb34));
    fild32(memoryAGet32(ds, r32[esp] + 0x1c));
    r32[edx] = r32s[eax] < 0 ? -1 : 0;
    faddst2(0, 0);
    r32[eax] -= r32[edx];
    r32[eax] = sar32(r32[eax], 0x00000001);
    fiadd32(memoryAGet32(ds, r32[esp] + 0x20));
    memoryASet32(ds, r32[esp] + 0x20, r32[eax]);
    r32[ecx] -= r32[ebx];
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x50);
    fisub32(memoryAGet32(ds, r32[esp] + 0x20));
    memoryASet32(ds, r32[esp] + 0x20, r32[ecx]);
    fild32(memoryAGet32(ds, r32[esp] + 0x20));
    fmul32(memoryAGet32(ds, 0x1000bb34));
    fild32(memoryAGet32(ds, r32[esp] + 0x24));
  case 0x10005435: // 0000:10005435
    fild32(memoryAGet32(ds, r32[esp] + 0x14));
    r32[ebp]++;
    r32[eax] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x14, r32[ebp]);
    fsub32(memoryAGet32(ds, r32[esp] + 0x28));
    fmul32(memoryAGet32(ds, 0x1000bb30));
    fldst(0);
    fmulst(5);
    faddst(4);
    fmulst(1);
    faddst(3);
    fmulst(1);
    faddst(2);
    memoryASet32(ds, r32[eax] - 4, fstp32());
    fstpst(0);
    if (r32s[ebp] < r32s[edi])
        { pc = 0x10005435; break; }
    fstpst(0);
    fstpst(0);
    fstpst(0);
    fstpst(0);
  case 0x1000546a: // 0000:1000546a
    r32[ebp] = memoryAGet32(ds, r32[esp] + 0x4c);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x50);
    r32[edi] += 0x00000140;
    r32[ebp]++;
    r32[esi] += 0x00000004;
    r32[ecx] += 0x00000500;
    memoryASet32(ds, r32[esp] + 0x4c, r32[ebp]);
    memoryASet32(ds, r32[esp] + 0x50, r32[ecx]);
    if (r32s[edi] < signed32(0x00000640))
        { pc = 0x1000539e; break; }
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebp] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 0x00000038;
    r32[esp] += 12;
    return;
  }
}


function sub_10005fb0() // 0000:10005fb0 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[esp] -= 0x0000000c;
    fld32(memoryAGet32(ds, 0x1000b208));
    fld32(memoryAGet32(ds, 0x1000b208));
    fld32(memoryAGet32(ds, 0x1000b208));
    fld32(memoryAGet32(ds, 0x1000b208));
    fld32(memoryAGet32(ds, 0x1000b208));
    fld32(memoryAGet32(ds, 0x1000b208));
    fld32(memoryAGet32(ds, r32[esp] + 0x10));
    fmul32(memoryAGet32(ds, 0x1000bb78));
    push32(r32[esi]);
    r32[esi] = r32[ecx];
    push32(r32[edi]);
    memoryASet32(ds, r32[esi] + 0x6398, fst32());
    fld32(memoryAGet32(ds, r32[esi] + 0xc4));
    fmul64(memoryAGet64(ds, 0x1000ba78));
    fadd64(memoryAGet64(ds, 0x1000bb70));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x18);
    memoryASet32(ds, r32[esi] + 0x63b0, r32[eax]);
    sub_1000a75c();
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64e4);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64e8);
    fld32(memoryAGet32(ds, r32[esp] + 0x18));
    r32[eax] <<= 2;
    r32[edi] = 0;
    fmul32(memoryAGet32(ds, r32[ecx] + r32[eax]));
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64ec);
    fmul32(memoryAGet32(ds, r32[esi] + 0x64d4));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, r32[esp] + 0x18));
    fmul32(memoryAGet32(ds, r32[edx] + r32[eax]));
    fmul32(memoryAGet32(ds, r32[esi] + 0x64d4));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, r32[esp] + 0x18));
    fmul32(memoryAGet32(ds, r32[ecx] + r32[eax]));
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64a8);
    fmul32(memoryAGet32(ds, r32[esi] + 0x64d4));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    if (r32s[eax] <= 0)
        { pc = 0x100061c1; break; }
    push32(r32[ebx]);
    push32(r32[ebp]);
  case 0x1000606a: // 0000:1000606a
    fldst(2);
    sub_1000a75c();
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x64cc);
    r32[ebx] = r32[eax];
    fldst(5);
    sub_1000a75c();
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64c0);
    fld32(memoryAGet32(ss, r32[ebp] + r32[ebx] * 4));
    fmul32(memoryAGet32(ds, r32[edx] + r32[eax] * 4));
    r32[eax] = memoryAGet32(ds, r32[esi] + 0x64a4);
    memoryASet32(ds, r32[eax] + r32[edi] * 4, fstp32());
    fxchst2(0, 5);
    fadd32(memoryAGet32(ds, r32[esi] + 0x639c));
    fxchst2(0, 5);
    fld32(memoryAGet32(ds, r32[esp] + 0x10));
    faddpst(3);
    fild32(memoryAGet32(ds, r32[esi] + 0x64d0));
    fldst(3);
    fcompst(1);
    r16[ax] = fnstsw();
    if (r8[ah] & 0x01)
        { pc = 0x100060bd; break; }
    fxchst2(0, 3);
    fsubst(3);
    fxchst2(0, 3);
  case 0x100060bd: // 0000:100060bd
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64a4);
    fstpst(0);
    r32[edx] = r32[ecx] + (r32[edi] * 4);
    fldst(1);
    memoryASet32(ds, r32[esp] + 0x20, r32[edx]);
    sub_1000a75c();
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x64cc);
    r32[ebx] = r32[eax];
    fldst(4);
    sub_1000a75c();
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64c0);
    fld32(memoryAGet32(ss, r32[ebp] + r32[ebx] * 4));
    fmul32(memoryAGet32(ds, r32[ecx] + r32[eax] * 4));
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    fadd32(memoryAGet32(ds, r32[eax]));
    memoryASet32(ds, r32[eax], fstp32());
    fxchst2(0, 4);
    fadd32(memoryAGet32(ds, r32[esi] + 0x63a0));
    fxchst2(0, 4);
    fld32(memoryAGet32(ds, r32[esp] + 0x14));
    faddpst(2);
    fild32(memoryAGet32(ds, r32[esi] + 0x64d0));
    fldst(2);
    fcompst(1);
    r16[ax] = fnstsw();
    if (r8[ah] & 0x01)
        { pc = 0x1000611e; break; }
    fxchst2(0, 2);
    fsubst(2);
    fxchst2(0, 2);
  case 0x1000611e: // 0000:1000611e
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64a4);
    fstpst(0);
    r32[eax] = r32[edx] + (r32[edi] * 4);
    fldst(0);
    memoryASet32(ds, r32[esp] + 0x20, r32[eax]);
    sub_1000a75c();
    r32[ebp] = memoryAGet32(ds, r32[esi] + 0x64cc);
    r32[ebx] = r32[eax];
    fldst(3);
    sub_1000a75c();
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64c0);
    fld32(memoryAGet32(ss, r32[ebp] + r32[ebx] * 4));
    fmul32(memoryAGet32(ds, r32[ecx] + r32[eax] * 4));
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    fadd32(memoryAGet32(ds, r32[eax]));
    memoryASet32(ds, r32[eax], fstp32());
    fxchst2(0, 3);
    fadd32(memoryAGet32(ds, r32[esi] + 0x63a4));
    fxchst2(0, 3);
    fadd32(memoryAGet32(ds, r32[esp] + 0x18));
    fild32(memoryAGet32(ds, r32[esi] + 0x64d0));
    fldst(1);
    fcompst(1);
    r16[ax] = fnstsw();
    if (r8[ah] & 0x01)
        { pc = 0x1000617d; break; }
    fxchst2(0, 1);
    fsubst(1);
    fxchst2(0, 1);
  case 0x1000617d: // 0000:1000617d
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64d8);
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64a4);
    fstpst(0);
    fld32(memoryAGet32(ds, r32[ecx] + r32[edi] * 4));
    fmul64(memoryAGet64(ds, 0x1000ba78));
    r32[eax] = r32[edx] + (r32[edi] * 4);
    fadd32(memoryAGet32(ds, r32[eax]));
    memoryASet32(ds, r32[eax], fstp32());
    r32[edx] = memoryAGet32(ds, r32[esi] + 0x64a4);
    r32[ecx] = memoryAGet32(ds, r32[esi] + 0x64c8);
    fld32(memoryAGet32(ds, r32[ecx] + r32[edi] * 4));
    fmul32(memoryAGet32(ds, r32[edx] + r32[edi] * 4));
    r32[eax] = r32[edx] + (r32[edi] * 4);
    r32[edi]++;
    memoryASet32(ds, r32[eax], fstp32());
    if (r32s[edi] < signed32(memoryAGet32(ds, r32[esi] + 0x64a8)))
        { pc = 0x1000606a; break; }
    r32[ebp] = pop32();
    r32[ebx] = pop32();
  case 0x100061c1: // 0000:100061c1
    fstpst(0);
    fstpst(0);
    fstpst(0);
    fstpst(0);
    fstpst(0);
    r32[edi] = pop32();
    r32[esi] = pop32();
    fstpst(0);
    r32[esp] += 0x0000000c;
    r32[esp] += 8;
    return;
  }
}


function sub_10005eb0() // 0000:10005eb0 +long +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x6378);
    r32[edx] += r32[eax];
    push32(r32[esi]);
    memoryASet32(ds, r32[ecx] + 0x6378, r32[edx]);
    r32[eax] = r32[edx];
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x64a8);
    push32(r32[edi]);
    r32[edi] = memoryAGet32(ds, r32[ecx] + 0x64b0);
    r32[esi] = r32[edx] + r32[eax];
    if (r32s[esi] > r32s[edi])
        { pc = 0x10005f1d; break; }
    if (r32s[eax] < 0)
        { pc = 0x10005f1d; break; }
    r32[eax] = 0;
    if (r32s[edx] <= 0)
        { pc = 0x10005f95; break; }
  case 0x10005ee7: // 0000:10005ee7
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x6378);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x64ac);
    r32[edx] = r32[esi] + (r32[edx] * 4);
    r32[esi] = memoryAGet32(ds, r32[ecx] + 0x64a4);
    fld32(memoryAGet32(ds, r32[esi] + r32[eax] * 4));
    fadd32(memoryAGet32(ds, r32[edx]));
    memoryASet32(ds, r32[edx], fstp32());
    r32[edi] = memoryAGet32(ds, r32[ecx] + 0x6378);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x64a8);
    r32[edi]++;
    r32[eax]++;
    memoryASet32(ds, r32[ecx] + 0x6378, r32[edi]);
    if (r32s[eax] < r32s[edx])
        { pc = 0x10005ee7; break; }
    { pc = 0x10005f95; break; }
  case 0x10005f1d: // 0000:10005f1d
    r32[esi] = 0;
    if (r32s[edx] <= 0)
        { pc = 0x10005f95; break; }
  case 0x10005f23: // 0000:10005f23
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x64b0);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x6378);
    if (r32s[edx] < r32s[eax])
        { pc = 0x10005f47; break; }
  case 0x10005f33: // 0000:10005f33
    r32[edi] = memoryAGet32(ds, r32[ecx] + 0x6378);
    r32[edi] -= r32[eax];
    r32[edx] = r32[edi];
    memoryASet32(ds, r32[ecx] + 0x6378, r32[edi]);
    if (r32s[edx] >= r32s[eax])
        { pc = 0x10005f33; break; }
  case 0x10005f47: // 0000:10005f47
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x6378);
    if (r32s[edx] >= 0)
        { pc = 0x10005f61; break; }
  case 0x10005f51: // 0000:10005f51
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x6378);
    r32[edx] += r32[eax];
    memoryASet32(ds, r32[ecx] + 0x6378, r32[edx]);
    if (r32s[edx] < 0)
        { pc = 0x10005f51; break; }
  case 0x10005f61: // 0000:10005f61
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x6378);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x64ac);
    r32[eax] = r32[eax] + (r32[edx] * 4);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x64a4);
    fld32(memoryAGet32(ds, r32[edx] + r32[esi] * 4));
    fadd32(memoryAGet32(ds, r32[eax]));
    memoryASet32(ds, r32[eax], fstp32());
    r32[edi] = memoryAGet32(ds, r32[ecx] + 0x6378);
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x64a8);
    r32[edi]++;
    r32[esi]++;
    memoryASet32(ds, r32[ecx] + 0x6378, r32[edi]);
    if (r32s[esi] < r32s[eax])
        { pc = 0x10005f23; break; }
  case 0x10005f95: // 0000:10005f95
    r32[eax] = memoryAGet32(ds, r32[ecx] + 0x64a8);
    r32[edx] = memoryAGet32(ds, r32[ecx] + 0x6378);
    r32[edx] -= r32[eax];
    r32[edi] = pop32();
    memoryASet32(ds, r32[ecx] + 0x6378, r32[edx]);
    r32[esi] = pop32();
    r32[esp] += 8;
    return;
  }
}

// AEffect.setParameter(AEffect*, VstInt32 index, float value) — cdecl, caller pops 12
function sub_10001080() // 0000:10001080
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);    // AEffect*
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x40);   // C++ plugin object
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);    // float value (arg3)
    push32(r32[eax]);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0xc);    // param index (arg2, was at esp+8)
    r32[edx] = memoryAGet32(ds, r32[ecx]);           // vtable ptr
    push32(r32[eax]);                                // push param index (= opcode for sub_10002db0)
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x4)); // vtable[1] = sub_10002db0 (+stackDrop8)
    r32[esp] += 4;  // undo synthetic
}

// AEffect.getParameter(AEffect*, VstInt32 index) — cdecl, caller pops 8; returns float in ST(0)
function sub_10001060() // 0000:10001060
{
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);    // AEffect*
    r32[ecx] = memoryAGet32(ds, r32[eax] + 0x40);   // C++ plugin object
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x8);    // param index (arg2)
    push32(r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[ecx]);           // vtable ptr
    indirectCall(cs, memoryAGet32(ds, r32[edx] + 0x8)); // vtable[2] = sub_10002fd0 (+stackDrop4)
    r32[esp] += 4;  // undo synthetic; float result left in ST(0)
}

// vtable[2]: getParameter implementation — reads param value from C++ object
function sub_10002fd0() // 0000:10002fd0 +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x4);  // param index
    fld32(memoryAGet32(ds, 0x1000b208));           // push 0.0 as default
    if (r32[eax] > 0x00000006)
        { pc = 0x10003025; break; }
    switch (r32[eax])
    {
        case 0: { pc = 0x10002fe6; break; }
        case 1: { pc = 0x10002ff1; break; }
        case 2: { pc = 0x10002ffc; break; }
        case 3: { pc = 0x10003007; break; }
        case 4: { pc = 0x10003025; break; }
        case 5: { pc = 0x1000301d; break; }
        case 6: { pc = 0x10003012; break; }
        default:
            stop("ind 0000:10002fdf");
    }
    break;
  case 0x10002fe6: // param 0: volume
    fstpst(0);
    fld32(memoryAGet32(ds, r32[ecx] + 0xb0));
    r32[esp] += 8; return;
  case 0x10002ff1: // param 1: vowel
    fstpst(0);
    fld32(memoryAGet32(ds, r32[ecx] + 0xb4));
    r32[esp] += 8; return;
  case 0x10002ffc: // param 2: portamento
    fstpst(0);
    fld32(memoryAGet32(ds, r32[ecx] + 0xbc));
    r32[esp] += 8; return;
  case 0x10003007: // param 3: depth
    fstpst(0);
    fld32(memoryAGet32(ds, r32[ecx] + 0xc4));
    r32[esp] += 8; return;
  case 0x10003012: // param 6
    fstpst(0);
    fld32(memoryAGet32(ds, r32[ecx] + 0xc0));
    r32[esp] += 8; return;
  case 0x1000301d: // param 5
    fstpst(0);
    fld32(memoryAGet32(ds, r32[ecx] + 0xc8));
  case 0x10003025:
    r32[esp] += 8; return;
  }
}

