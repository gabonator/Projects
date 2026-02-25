/*
Missing imports for user32.h!
Missing imports for gdi32.h!
Missing imports for comdlg32.h!
Missing imports for shell32.h!
Missing imports for ole32.h!
Missing imports for gdiplus.h!
// Sections of ddx10.dll:
//  - .text: 10001000 .. 1003b429 (238633 bytes)
//  - .rdata: 1003c000 .. 1004c419 (66585 bytes)
//  - .data: 1004d000 .. 10051768 (18280 bytes)
//  - .rsrc: 10052000 .. 10063d88 (73096 bytes)
//  - .reloc: 10064000 .. 100697fa (22522 bytes)

function init()
{
#include "kernel32.h"
#include "user32.h"
#include "gdi32.h"
#include "comdlg32.h"
#include "shell32.h"
#include "ole32.h"
#include "gdiplus.h"

void sub_1002195c();

void init()
{
    loadOverlay("ddx10_text.bin", 0x10001000);
    loadOverlay("ddx10_rdata.bin", 0x1003c000);
    loadOverlay("ddx10_data.bin", 0x1004d000);
    loadOverlay("ddx10_rsrc.bin", 0x10052000);
    loadOverlay("ddx10_reloc.bin", 0x10064000);
    esp = 0x1006a000;
    ebp = 0x1006a000;
}

void start()
{
    sub_1002195c();
}

enum class ptrImportTable {
    ptr_begin = 0x6ab00000,
    ptr_comdlg32_GetOpenFileNameW,
    ptr_comdlg32_GetSaveFileNameW,
    ptr_gdi32_SetBkColor,
    ptr_gdi32_CreateRectRgn,
    ptr_gdi32_CreateSolidBrush,
    ptr_gdi32_CreateFontIndirectW,
    ptr_gdi32_DeleteObject,
    ptr_gdi32_SetTextColor,
    ptr_kernel32_GlobalUnlock,
    ptr_kernel32_GlobalFree,
    ptr_kernel32_LockResource,
    ptr_kernel32_GetProcessHeap,
    ptr_kernel32_SetEndOfFile,
    ptr_kernel32_CreateFileA,
    ptr_kernel32_CreateFileW,
    ptr_kernel32_GetModuleHandleA,
    ptr_kernel32_SetStdHandle,
    ptr_kernel32_WriteConsoleW,
    ptr_kernel32_GetConsoleOutputCP,
    ptr_kernel32_WriteConsoleA,
    ptr_kernel32_InitializeCriticalSectionAndSpinCount,
    ptr_kernel32_GetLocaleInfoW,
    ptr_kernel32_LoadLibraryA,
    ptr_kernel32_GetStringTypeW,
    ptr_kernel32_GetStringTypeA,
    ptr_kernel32_IsValidLocale,
    ptr_kernel32_GetVersionExW,
    ptr_kernel32_GetLocaleInfoA,
    ptr_kernel32_GetUserDefaultLCID,
    ptr_kernel32_GetSystemTimeAsFileTime,
    ptr_kernel32_GetCurrentProcessId,
    ptr_kernel32_QueryPerformanceCounter,
    ptr_kernel32_GetEnvironmentStringsW,
    ptr_kernel32_FreeEnvironmentStringsW,
    ptr_kernel32_GetEnvironmentStrings,
    ptr_kernel32_FreeEnvironmentStringsA,
    ptr_kernel32_HeapSize,
    ptr_kernel32_ExitProcess,
    ptr_kernel32_IsValidCodePage,
    ptr_kernel32_GetOEMCP,
    ptr_kernel32_GetACP,
    ptr_kernel32_CloseHandle,
    ptr_kernel32_SetFilePointer,
    ptr_kernel32_FlushFileBuffers,
    ptr_kernel32_GetConsoleMode,
    ptr_kernel32_GetConsoleCP,
    ptr_kernel32_ReadFile,
    ptr_kernel32_SizeofResource,
    ptr_kernel32_GlobalLock,
    ptr_kernel32_GlobalSize,
    ptr_kernel32_InterlockedDecrement,
    ptr_kernel32_InterlockedIncrement,
    ptr_kernel32_LoadResource,
    ptr_kernel32_FindResourceA,
    ptr_kernel32_WideCharToMultiByte,
    ptr_kernel32_MultiByteToWideChar,
    ptr_kernel32_Sleep,
    ptr_kernel32_EnumSystemLocalesA,
    ptr_kernel32_GetTickCount,
    ptr_kernel32_HeapReAlloc,
    ptr_kernel32_VirtualAlloc,
    ptr_kernel32_VirtualFree,
    ptr_kernel32_HeapDestroy,
    ptr_kernel32_HeapCreate,
    ptr_kernel32_GetStartupInfoA,
    ptr_kernel32_GetFileType,
    ptr_kernel32_SetHandleCount,
    ptr_kernel32_SetLastError,
    ptr_kernel32_TlsFree,
    ptr_kernel32_TlsSetValue,
    ptr_kernel32_TlsAlloc,
    ptr_kernel32_TlsGetValue,
    ptr_kernel32_GetProcAddress,
    ptr_kernel32_GetModuleHandleW,
    ptr_kernel32_GetModuleFileNameA,
    ptr_kernel32_GetStdHandle,
    ptr_kernel32_WriteFile,
    ptr_kernel32_GetCPInfo,
    ptr_kernel32_LCMapStringW,
    ptr_kernel32_LCMapStringA,
    ptr_kernel32_RaiseException,
    ptr_kernel32_RtlUnwind,
    ptr_kernel32_GetCommandLineA,
    ptr_kernel32_GetCurrentThreadId,
    ptr_kernel32_HeapAlloc,
    ptr_kernel32_IsDebuggerPresent,
    ptr_kernel32_SetUnhandledExceptionFilter,
    ptr_kernel32_UnhandledExceptionFilter,
    ptr_kernel32_GetCurrentProcess,
    ptr_kernel32_TerminateProcess,
    ptr_kernel32_HeapFree,
    ptr_kernel32_GetLastError,
    ptr_kernel32_LeaveCriticalSection,
    ptr_kernel32_EnterCriticalSection,
    ptr_kernel32_DeleteCriticalSection,
    ptr_kernel32_InitializeCriticalSection,
    ptr_kernel32_InterlockedExchange,
    ptr_shell32_DragQueryFileW,
    ptr_user32_SetWindowLongW,
    ptr_user32_GetWindowTextW,
    ptr_user32_AppendMenuW,
    ptr_user32_GetWindowLongW,
    ptr_user32_GetDoubleClickTime,
    ptr_user32_GetMenuItemInfoW,
    ptr_user32_SetFocus,
    ptr_user32_TrackPopupMenu,
    ptr_user32_GetWindowRect,
    ptr_user32_DestroyWindow,
    ptr_user32_DefWindowProcW,
    ptr_user32_MapWindowPoints,
    ptr_user32_GetSystemMetrics,
    ptr_user32_RegisterClassW,
    ptr_user32_ReleaseCapture,
    ptr_user32_GetCursor,
    ptr_user32_CreatePopupMenu,
    ptr_user32_SetWindowPos,
    ptr_user32_GetClassNameW,
    ptr_user32_InvalidateRect,
    ptr_user32_GetAsyncKeyState,
    ptr_user32_GetDC,
    ptr_user32_wsprintfW,
    ptr_user32_BeginPaint,
    ptr_user32_LoadCursorW,
    ptr_user32_TrackMouseEvent,
    ptr_user32_GetParent,
    ptr_user32_GetKeyState,
    ptr_user32_UnregisterClassW,
    ptr_user32_SetCapture,
    ptr_user32_GetUpdateRgn,
    ptr_user32_SetCursor,
    ptr_user32_EndPaint,
    ptr_user32_GetCursorPos,
    ptr_user32_SendMessageW,
    ptr_user32_DestroyMenu,
    ptr_user32_SetMenuItemInfoW,
    ptr_user32_CallWindowProcW,
    ptr_user32_PeekMessageW,
    ptr_user32_DispatchMessageW,
    ptr_user32_MessageBoxW,
    ptr_user32_CreateWindowExW,
    ptr_gdiplus_GdipMeasureString,
    ptr_gdiplus_GdipDrawImageRectRectI,
    ptr_gdiplus_GdipGetImageHeight,
    ptr_gdiplus_GdipSetImageAttributesColorMatrix,
    ptr_gdiplus_GdipSetTextRenderingHint,
    ptr_gdiplus_GdipCreateBitmapFromStreamICM,
    ptr_gdiplus_GdipCloneBrush,
    ptr_gdiplus_GdipDeletePen,
    ptr_gdiplus_GdipFree,
    ptr_gdiplus_GdipDeleteBrush,
    ptr_gdiplus_GdiplusShutdown,
    ptr_gdiplus_GdipCreateHBITMAPFromBitmap,
    ptr_gdiplus_GdipGetImagePixelFormat,
    ptr_gdiplus_GdipGetFontHeightGivenDPI,
    ptr_gdiplus_GdipDeleteFont,
    ptr_gdiplus_GdipCreateBitmapFromScan0,
    ptr_gdiplus_GdipDeleteGraphics,
    ptr_gdiplus_GdipGetDpiY,
    ptr_gdiplus_GdipSetClipRectI,
    ptr_gdiplus_GdipGetImageGraphicsContext,
    ptr_gdiplus_GdipSetSmoothingMode,
    ptr_gdiplus_GdipDeleteFontFamily,
    ptr_gdiplus_GdipCreateSolidFill,
    ptr_gdiplus_GdipDisposeImageAttributes,
    ptr_gdiplus_GdipSetPenColor,
    ptr_gdiplus_GdiplusStartup,
    ptr_gdiplus_GdipCreatePen1,
    ptr_gdiplus_GdipSetPixelOffsetMode,
    ptr_gdiplus_GdipGetImageWidth,
    ptr_gdiplus_GdipSetPenDashStyle,
    ptr_gdiplus_GdipDrawLineI,
    ptr_gdiplus_GdipCloneImage,
    ptr_gdiplus_GdipCreateBitmapFromResource,
    ptr_gdiplus_GdipSetInterpolationMode,
    ptr_gdiplus_GdipSetSolidFillColor,
    ptr_gdiplus_GdipCreateFromHDC,
    ptr_gdiplus_GdipCreateFontFamilyFromName,
    ptr_gdiplus_GdipFillRectangle,
    ptr_gdiplus_GdipDrawString,
    ptr_gdiplus_GdipDrawRectangle,
    ptr_gdiplus_GdipCreateImageAttributes,
    ptr_gdiplus_GdipGetGenericFontFamilySansSerif,
    ptr_gdiplus_GdipCreateBitmapFromHBITMAP,
    ptr_gdiplus_GdipSetPageUnit,
    ptr_gdiplus_GdipCreateFont,
    ptr_gdiplus_GdipSetPenWidth,
    ptr_gdiplus_GdipDisposeImage,
    ptr_gdiplus_GdipAlloc,
    ptr_ole32_RevokeDragDrop,
    ptr_ole32_CoCreateInstance,
    ptr_ole32_RegisterDragDrop,
    ptr_ole32_OleUninitialize,
    ptr_ole32_OleInitialize,
};

void indirectCall(int s, int o) {
    switch ((ptrImportTable)o) {
        case ptrImportTable::ptr_comdlg32_GetOpenFileNameW:
            eax = comdlg32::GetOpenFileNameW();
            break; // 6ab00001
        case ptrImportTable::ptr_comdlg32_GetSaveFileNameW:
            eax = comdlg32::GetSaveFileNameW();
            break; // 6ab00002
        case ptrImportTable::ptr_gdi32_SetBkColor:
            eax = gdi32::SetBkColor();
            break; // 6ab00003
        case ptrImportTable::ptr_gdi32_CreateRectRgn:
            eax = gdi32::CreateRectRgn();
            break; // 6ab00004
        case ptrImportTable::ptr_gdi32_CreateSolidBrush:
            eax = gdi32::CreateSolidBrush();
            break; // 6ab00005
        case ptrImportTable::ptr_gdi32_CreateFontIndirectW:
            eax = gdi32::CreateFontIndirectW();
            break; // 6ab00006
        case ptrImportTable::ptr_gdi32_DeleteObject:
            eax = gdi32::DeleteObject();
            break; // 6ab00007
        case ptrImportTable::ptr_gdi32_SetTextColor:
            eax = gdi32::SetTextColor();
            break; // 6ab00008
        case ptrImportTable::ptr_kernel32_GlobalUnlock:
            eax = kernel32::GlobalUnlock();
            break; // 6ab00009
        case ptrImportTable::ptr_kernel32_GlobalFree:
            eax = kernel32::GlobalFree();
            break; // 6ab0000a
        case ptrImportTable::ptr_kernel32_LockResource:
            eax = kernel32::LockResource();
            break; // 6ab0000b
        case ptrImportTable::ptr_kernel32_GetProcessHeap:
            eax = kernel32::GetProcessHeap();
            break; // 6ab0000c
        case ptrImportTable::ptr_kernel32_SetEndOfFile:
            eax = kernel32::SetEndOfFile();
            break; // 6ab0000d
        case ptrImportTable::ptr_kernel32_CreateFileA:
            eax = kernel32::CreateFileA();
            break; // 6ab0000e
        case ptrImportTable::ptr_kernel32_CreateFileW:
            eax = kernel32::CreateFileW();
            break; // 6ab0000f
        case ptrImportTable::ptr_kernel32_GetModuleHandleA:
            eax = kernel32::GetModuleHandleA(stack32<LPCSTR>(0)); esp += 4;
            break; // 6ab00010
        case ptrImportTable::ptr_kernel32_SetStdHandle:
            eax = kernel32::SetStdHandle(stack32<DWORD>(0), stack32<HANDLE>(1)); esp += 8;
            break; // 6ab00011
        case ptrImportTable::ptr_kernel32_WriteConsoleW:
            eax = kernel32::WriteConsoleW();
            break; // 6ab00012
        case ptrImportTable::ptr_kernel32_GetConsoleOutputCP:
            eax = kernel32::GetConsoleOutputCP();
            break; // 6ab00013
        case ptrImportTable::ptr_kernel32_WriteConsoleA:
            eax = kernel32::WriteConsoleA();
            break; // 6ab00014
        case ptrImportTable::ptr_kernel32_InitializeCriticalSectionAndSpinCount:
            eax = kernel32::InitializeCriticalSectionAndSpinCount();
            break; // 6ab00015
        case ptrImportTable::ptr_kernel32_GetLocaleInfoW:
            eax = kernel32::GetLocaleInfoW();
            break; // 6ab00016
        case ptrImportTable::ptr_kernel32_LoadLibraryA:
            eax = kernel32::LoadLibraryA(stack32<LPCSTR>(0)); esp += 4;
            break; // 6ab00017
        case ptrImportTable::ptr_kernel32_GetStringTypeW:
            eax = kernel32::GetStringTypeW(stack32<DWORD>(0), stack32<LPCWSTR>(1), stack32<int>(2), stack32<LPWORD>(3)); esp += 16;
            break; // 6ab00018
        case ptrImportTable::ptr_kernel32_GetStringTypeA:
            eax = kernel32::GetStringTypeA(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPWORD>(4)); esp += 20;
            break; // 6ab00019
        case ptrImportTable::ptr_kernel32_IsValidLocale:
            eax = kernel32::IsValidLocale();
            break; // 6ab0001a
        case ptrImportTable::ptr_kernel32_GetVersionExW:
            eax = kernel32::GetVersionExW();
            break; // 6ab0001b
        case ptrImportTable::ptr_kernel32_GetLocaleInfoA:
            eax = kernel32::GetLocaleInfoA();
            break; // 6ab0001c
        case ptrImportTable::ptr_kernel32_GetUserDefaultLCID:
            eax = kernel32::GetUserDefaultLCID();
            break; // 6ab0001d
        case ptrImportTable::ptr_kernel32_GetSystemTimeAsFileTime:
            eax = kernel32::GetSystemTimeAsFileTime();
            break; // 6ab0001e
        case ptrImportTable::ptr_kernel32_GetCurrentProcessId:
            eax = kernel32::GetCurrentProcessId();
            break; // 6ab0001f
        case ptrImportTable::ptr_kernel32_QueryPerformanceCounter:
            eax = kernel32::QueryPerformanceCounter();
            break; // 6ab00020
        case ptrImportTable::ptr_kernel32_GetEnvironmentStringsW:
            eax = kernel32::GetEnvironmentStringsW();
            break; // 6ab00021
        case ptrImportTable::ptr_kernel32_FreeEnvironmentStringsW:
            eax = kernel32::FreeEnvironmentStringsW(stack32<LPWCH>(0)); esp += 4;
            break; // 6ab00022
        case ptrImportTable::ptr_kernel32_GetEnvironmentStrings:
            eax = kernel32::GetEnvironmentStrings();
            break; // 6ab00023
        case ptrImportTable::ptr_kernel32_FreeEnvironmentStringsA:
            eax = kernel32::FreeEnvironmentStringsA(stack32<LPCH>(0)); esp += 4;
            break; // 6ab00024
        case ptrImportTable::ptr_kernel32_HeapSize:
            eax = kernel32::HeapSize(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPCVOID>(2)); esp += 12;
            break; // 6ab00025
        case ptrImportTable::ptr_kernel32_ExitProcess:
            kernel32::ExitProcess(stack32<UINT>(0)); esp += 4;
            break; // 6ab00026
        case ptrImportTable::ptr_kernel32_IsValidCodePage:
            eax = kernel32::IsValidCodePage();
            break; // 6ab00027
        case ptrImportTable::ptr_kernel32_GetOEMCP:
            eax = kernel32::GetOEMCP();
            break; // 6ab00028
        case ptrImportTable::ptr_kernel32_GetACP:
            eax = kernel32::GetACP();
            break; // 6ab00029
        case ptrImportTable::ptr_kernel32_CloseHandle:
            eax = kernel32::CloseHandle(stack32<HANDLE>(0)); esp += 4;
            break; // 6ab0002a
        case ptrImportTable::ptr_kernel32_SetFilePointer:
            eax = kernel32::SetFilePointer(stack32<HANDLE>(0), stack32<LONG>(1), stack32<PLONG>(2), stack32<DWORD>(3)); esp += 16;
            break; // 6ab0002b
        case ptrImportTable::ptr_kernel32_FlushFileBuffers:
            eax = kernel32::FlushFileBuffers(stack32<HANDLE>(0)); esp += 4;
            break; // 6ab0002c
        case ptrImportTable::ptr_kernel32_GetConsoleMode:
            eax = kernel32::GetConsoleMode();
            break; // 6ab0002d
        case ptrImportTable::ptr_kernel32_GetConsoleCP:
            eax = kernel32::GetConsoleCP();
            break; // 6ab0002e
        case ptrImportTable::ptr_kernel32_ReadFile:
            eax = kernel32::ReadFile();
            break; // 6ab0002f
        case ptrImportTable::ptr_kernel32_SizeofResource:
            eax = kernel32::SizeofResource();
            break; // 6ab00030
        case ptrImportTable::ptr_kernel32_GlobalLock:
            eax = kernel32::GlobalLock();
            break; // 6ab00031
        case ptrImportTable::ptr_kernel32_GlobalSize:
            eax = kernel32::GlobalSize();
            break; // 6ab00032
        case ptrImportTable::ptr_kernel32_InterlockedDecrement:
            eax = kernel32::InterlockedDecrement();
            break; // 6ab00033
        case ptrImportTable::ptr_kernel32_InterlockedIncrement:
            eax = kernel32::InterlockedIncrement();
            break; // 6ab00034
        case ptrImportTable::ptr_kernel32_LoadResource:
            eax = kernel32::LoadResource();
            break; // 6ab00035
        case ptrImportTable::ptr_kernel32_FindResourceA:
            eax = kernel32::FindResourceA();
            break; // 6ab00036
        case ptrImportTable::ptr_kernel32_WideCharToMultiByte:
            eax = kernel32::WideCharToMultiByte(stack32<UINT>(0), stack32<DWORD>(1), stack32<LPCWSTR>(2), stack32<int>(3), stack32<LPSTR>(4), stack32<int>(5), stack32<LPCSTR>(6), stack32<LPBOOL>(7)); esp += 32;
            break; // 6ab00037
        case ptrImportTable::ptr_kernel32_MultiByteToWideChar:
            eax = kernel32::MultiByteToWideChar(stack32<UINT>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;
            break; // 6ab00038
        case ptrImportTable::ptr_kernel32_Sleep:
            eax = kernel32::Sleep();
            break; // 6ab00039
        case ptrImportTable::ptr_kernel32_EnumSystemLocalesA:
            eax = kernel32::EnumSystemLocalesA();
            break; // 6ab0003a
        case ptrImportTable::ptr_kernel32_GetTickCount:
            eax = kernel32::GetTickCount();
            break; // 6ab0003b
        case ptrImportTable::ptr_kernel32_HeapReAlloc:
            eax = kernel32::HeapReAlloc(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPVOID>(2), stack32<SIZE_T>(3)); esp += 16;
            break; // 6ab0003c
        case ptrImportTable::ptr_kernel32_VirtualAlloc:
            eax = kernel32::VirtualAlloc(stack32<LPVOID>(0), stack32<SIZE_T>(1), stack32<DWORD>(2), stack32<DWORD>(3)); esp += 16;
            break; // 6ab0003d
        case ptrImportTable::ptr_kernel32_VirtualFree:
            eax = kernel32::VirtualFree(stack32<LPVOID>(0), stack32<SIZE_T>(1), stack32<DWORD>(2)); esp += 12;
            break; // 6ab0003e
        case ptrImportTable::ptr_kernel32_HeapDestroy:
            eax = kernel32::HeapDestroy(stack32<HANDLE>(0)); esp += 4;
            break; // 6ab0003f
        case ptrImportTable::ptr_kernel32_HeapCreate:
            eax = kernel32::HeapCreate(stack32<DWORD>(0), stack32<SIZE_T>(1), stack32<SIZE_T>(2)); esp += 12;
            break; // 6ab00040
        case ptrImportTable::ptr_kernel32_GetStartupInfoA:
            kernel32::GetStartupInfoA(stack32<LPSTARTUPINFOA>(0)); esp += 4;
            break; // 6ab00041
        case ptrImportTable::ptr_kernel32_GetFileType:
            eax = kernel32::GetFileType(stack32<HANDLE>(0)); esp += 4;
            break; // 6ab00042
        case ptrImportTable::ptr_kernel32_SetHandleCount:
            eax = kernel32::SetHandleCount(stack32<UINT>(0)); esp += 4;
            break; // 6ab00043
        case ptrImportTable::ptr_kernel32_SetLastError:
            eax = kernel32::SetLastError();
            break; // 6ab00044
        case ptrImportTable::ptr_kernel32_TlsFree:
            eax = kernel32::TlsFree();
            break; // 6ab00045
        case ptrImportTable::ptr_kernel32_TlsSetValue:
            eax = kernel32::TlsSetValue();
            break; // 6ab00046
        case ptrImportTable::ptr_kernel32_TlsAlloc:
            eax = kernel32::TlsAlloc();
            break; // 6ab00047
        case ptrImportTable::ptr_kernel32_TlsGetValue:
            eax = kernel32::TlsGetValue();
            break; // 6ab00048
        case ptrImportTable::ptr_kernel32_GetProcAddress:
            eax = kernel32::GetProcAddress(stack32<HMODULE>(0), stack32<LPCSTR>(1)); esp += 8;
            break; // 6ab00049
        case ptrImportTable::ptr_kernel32_GetModuleHandleW:
            eax = kernel32::GetModuleHandleW();
            break; // 6ab0004a
        case ptrImportTable::ptr_kernel32_GetModuleFileNameA:
            eax = kernel32::GetModuleFileNameA(stack32<HMODULE>(0), stack32<LPSTR>(1), stack32<DWORD>(2)); esp += 12;
            break; // 6ab0004b
        case ptrImportTable::ptr_kernel32_GetStdHandle:
            eax = kernel32::GetStdHandle(stack32<DWORD>(0)); esp += 4;
            break; // 6ab0004c
        case ptrImportTable::ptr_kernel32_WriteFile:
            eax = kernel32::WriteFile(stack32<HANDLE>(0), stack32<LPCVOID>(1), stack32<DWORD>(2), stack32<LPDWORD>(3), stack32<LPOVERLAPPED>(4)); esp += 20;
            break; // 6ab0004d
        case ptrImportTable::ptr_kernel32_GetCPInfo:
            eax = kernel32::GetCPInfo(stack32<UINT>(0), stack32<LPCPINFO>(1)); esp += 8;
            break; // 6ab0004e
        case ptrImportTable::ptr_kernel32_LCMapStringW:
            eax = kernel32::LCMapStringW(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCWSTR>(2), stack32<int>(3), stack32<LPWSTR>(4), stack32<int>(5)); esp += 24;
            break; // 6ab0004f
        case ptrImportTable::ptr_kernel32_LCMapStringA:
            eax = kernel32::LCMapStringA(stack32<LCID>(0), stack32<DWORD>(1), stack32<LPCSTR>(2), stack32<int>(3), stack32<LPSTR>(4), stack32<int>(5)); esp += 24;
            break; // 6ab00050
        case ptrImportTable::ptr_kernel32_RaiseException:
            eax = kernel32::RaiseException();
            break; // 6ab00051
        case ptrImportTable::ptr_kernel32_RtlUnwind:
            kernel32::RtlUnwind(stack32<PVOID>(0), stack32<PVOID>(1), stack32<PEXCEPTION_RECORD>(2), stack32<PVOID>(3)); esp += 16;
            break; // 6ab00052
        case ptrImportTable::ptr_kernel32_GetCommandLineA:
            eax = kernel32::GetCommandLineA();
            break; // 6ab00053
        case ptrImportTable::ptr_kernel32_GetCurrentThreadId:
            eax = kernel32::GetCurrentThreadId();
            break; // 6ab00054
        case ptrImportTable::ptr_kernel32_HeapAlloc:
            eax = kernel32::HeapAlloc(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<SIZE_T>(2)); esp += 12;
            break; // 6ab00055
        case ptrImportTable::ptr_kernel32_IsDebuggerPresent:
            eax = kernel32::IsDebuggerPresent();
            break; // 6ab00056
        case ptrImportTable::ptr_kernel32_SetUnhandledExceptionFilter:
            eax = kernel32::SetUnhandledExceptionFilter();
            break; // 6ab00057
        case ptrImportTable::ptr_kernel32_UnhandledExceptionFilter:
            eax = kernel32::UnhandledExceptionFilter(stack32<struct _EXCEPTION_POINTERS>(0)); esp += 4;
            break; // 6ab00058
        case ptrImportTable::ptr_kernel32_GetCurrentProcess:
            eax = kernel32::GetCurrentProcess();
            break; // 6ab00059
        case ptrImportTable::ptr_kernel32_TerminateProcess:
            eax = kernel32::TerminateProcess(stack32<HANDLE>(0), stack32<UINT>(1)); esp += 8;
            break; // 6ab0005a
        case ptrImportTable::ptr_kernel32_HeapFree:
            eax = kernel32::HeapFree(stack32<HANDLE>(0), stack32<DWORD>(1), stack32<LPVOID>(2)); esp += 12;
            break; // 6ab0005b
        case ptrImportTable::ptr_kernel32_GetLastError:
            eax = kernel32::GetLastError();
            break; // 6ab0005c
        case ptrImportTable::ptr_kernel32_LeaveCriticalSection:
            eax = kernel32::LeaveCriticalSection();
            break; // 6ab0005d
        case ptrImportTable::ptr_kernel32_EnterCriticalSection:
            eax = kernel32::EnterCriticalSection();
            break; // 6ab0005e
        case ptrImportTable::ptr_kernel32_DeleteCriticalSection:
            eax = kernel32::DeleteCriticalSection();
            break; // 6ab0005f
        case ptrImportTable::ptr_kernel32_InitializeCriticalSection:
            eax = kernel32::InitializeCriticalSection();
            break; // 6ab00060
        case ptrImportTable::ptr_kernel32_InterlockedExchange:
            eax = kernel32::InterlockedExchange();
            break; // 6ab00061
        case ptrImportTable::ptr_shell32_DragQueryFileW:
            eax = shell32::DragQueryFileW();
            break; // 6ab00062
        case ptrImportTable::ptr_user32_SetWindowLongW:
            eax = user32::SetWindowLongW();
            break; // 6ab00063
        case ptrImportTable::ptr_user32_GetWindowTextW:
            eax = user32::GetWindowTextW();
            break; // 6ab00064
        case ptrImportTable::ptr_user32_AppendMenuW:
            eax = user32::AppendMenuW();
            break; // 6ab00065
        case ptrImportTable::ptr_user32_GetWindowLongW:
            eax = user32::GetWindowLongW();
            break; // 6ab00066
        case ptrImportTable::ptr_user32_GetDoubleClickTime:
            eax = user32::GetDoubleClickTime();
            break; // 6ab00067
        case ptrImportTable::ptr_user32_GetMenuItemInfoW:
            eax = user32::GetMenuItemInfoW();
            break; // 6ab00068
        case ptrImportTable::ptr_user32_SetFocus:
            eax = user32::SetFocus();
            break; // 6ab00069
        case ptrImportTable::ptr_user32_TrackPopupMenu:
            eax = user32::TrackPopupMenu();
            break; // 6ab0006a
        case ptrImportTable::ptr_user32_GetWindowRect:
            eax = user32::GetWindowRect();
            break; // 6ab0006b
        case ptrImportTable::ptr_user32_DestroyWindow:
            eax = user32::DestroyWindow();
            break; // 6ab0006c
        case ptrImportTable::ptr_user32_DefWindowProcW:
            eax = user32::DefWindowProcW();
            break; // 6ab0006d
        case ptrImportTable::ptr_user32_MapWindowPoints:
            eax = user32::MapWindowPoints();
            break; // 6ab0006e
        case ptrImportTable::ptr_user32_GetSystemMetrics:
            eax = user32::GetSystemMetrics();
            break; // 6ab0006f
        case ptrImportTable::ptr_user32_RegisterClassW:
            eax = user32::RegisterClassW();
            break; // 6ab00070
        case ptrImportTable::ptr_user32_ReleaseCapture:
            eax = user32::ReleaseCapture();
            break; // 6ab00071
        case ptrImportTable::ptr_user32_GetCursor:
            eax = user32::GetCursor();
            break; // 6ab00072
        case ptrImportTable::ptr_user32_CreatePopupMenu:
            eax = user32::CreatePopupMenu();
            break; // 6ab00073
        case ptrImportTable::ptr_user32_SetWindowPos:
            eax = user32::SetWindowPos();
            break; // 6ab00074
        case ptrImportTable::ptr_user32_GetClassNameW:
            eax = user32::GetClassNameW();
            break; // 6ab00075
        case ptrImportTable::ptr_user32_InvalidateRect:
            eax = user32::InvalidateRect();
            break; // 6ab00076
        case ptrImportTable::ptr_user32_GetAsyncKeyState:
            eax = user32::GetAsyncKeyState();
            break; // 6ab00077
        case ptrImportTable::ptr_user32_GetDC:
            eax = user32::GetDC();
            break; // 6ab00078
        case ptrImportTable::ptr_user32_wsprintfW:
            eax = user32::wsprintfW();
            break; // 6ab00079
        case ptrImportTable::ptr_user32_BeginPaint:
            eax = user32::BeginPaint();
            break; // 6ab0007a
        case ptrImportTable::ptr_user32_LoadCursorW:
            eax = user32::LoadCursorW();
            break; // 6ab0007b
        case ptrImportTable::ptr_user32_TrackMouseEvent:
            eax = user32::TrackMouseEvent();
            break; // 6ab0007c
        case ptrImportTable::ptr_user32_GetParent:
            eax = user32::GetParent();
            break; // 6ab0007d
        case ptrImportTable::ptr_user32_GetKeyState:
            eax = user32::GetKeyState();
            break; // 6ab0007e
        case ptrImportTable::ptr_user32_UnregisterClassW:
            eax = user32::UnregisterClassW();
            break; // 6ab0007f
        case ptrImportTable::ptr_user32_SetCapture:
            eax = user32::SetCapture();
            break; // 6ab00080
        case ptrImportTable::ptr_user32_GetUpdateRgn:
            eax = user32::GetUpdateRgn();
            break; // 6ab00081
        case ptrImportTable::ptr_user32_SetCursor:
            eax = user32::SetCursor();
            break; // 6ab00082
        case ptrImportTable::ptr_user32_EndPaint:
            eax = user32::EndPaint();
            break; // 6ab00083
        case ptrImportTable::ptr_user32_GetCursorPos:
            eax = user32::GetCursorPos();
            break; // 6ab00084
        case ptrImportTable::ptr_user32_SendMessageW:
            eax = user32::SendMessageW();
            break; // 6ab00085
        case ptrImportTable::ptr_user32_DestroyMenu:
            eax = user32::DestroyMenu();
            break; // 6ab00086
        case ptrImportTable::ptr_user32_SetMenuItemInfoW:
            eax = user32::SetMenuItemInfoW();
            break; // 6ab00087
        case ptrImportTable::ptr_user32_CallWindowProcW:
            eax = user32::CallWindowProcW();
            break; // 6ab00088
        case ptrImportTable::ptr_user32_PeekMessageW:
            eax = user32::PeekMessageW();
            break; // 6ab00089
        case ptrImportTable::ptr_user32_DispatchMessageW:
            eax = user32::DispatchMessageW();
            break; // 6ab0008a
        case ptrImportTable::ptr_user32_MessageBoxW:
            eax = user32::MessageBoxW();
            break; // 6ab0008b
        case ptrImportTable::ptr_user32_CreateWindowExW:
            eax = user32::CreateWindowExW();
            break; // 6ab0008c
        case ptrImportTable::ptr_gdiplus_GdipMeasureString:
            eax = gdiplus::GdipMeasureString();
            break; // 6ab0008d
        case ptrImportTable::ptr_gdiplus_GdipDrawImageRectRectI:
            eax = gdiplus::GdipDrawImageRectRectI();
            break; // 6ab0008e
        case ptrImportTable::ptr_gdiplus_GdipGetImageHeight:
            eax = gdiplus::GdipGetImageHeight();
            break; // 6ab0008f
        case ptrImportTable::ptr_gdiplus_GdipSetImageAttributesColorMatrix:
            eax = gdiplus::GdipSetImageAttributesColorMatrix();
            break; // 6ab00090
        case ptrImportTable::ptr_gdiplus_GdipSetTextRenderingHint:
            eax = gdiplus::GdipSetTextRenderingHint();
            break; // 6ab00091
        case ptrImportTable::ptr_gdiplus_GdipCreateBitmapFromStreamICM:
            eax = gdiplus::GdipCreateBitmapFromStreamICM();
            break; // 6ab00092
        case ptrImportTable::ptr_gdiplus_GdipCloneBrush:
            eax = gdiplus::GdipCloneBrush();
            break; // 6ab00093
        case ptrImportTable::ptr_gdiplus_GdipDeletePen:
            eax = gdiplus::GdipDeletePen();
            break; // 6ab00094
        case ptrImportTable::ptr_gdiplus_GdipFree:
            eax = gdiplus::GdipFree();
            break; // 6ab00095
        case ptrImportTable::ptr_gdiplus_GdipDeleteBrush:
            eax = gdiplus::GdipDeleteBrush();
            break; // 6ab00096
        case ptrImportTable::ptr_gdiplus_GdiplusShutdown:
            eax = gdiplus::GdiplusShutdown();
            break; // 6ab00097
        case ptrImportTable::ptr_gdiplus_GdipCreateHBITMAPFromBitmap:
            eax = gdiplus::GdipCreateHBITMAPFromBitmap();
            break; // 6ab00098
        case ptrImportTable::ptr_gdiplus_GdipGetImagePixelFormat:
            eax = gdiplus::GdipGetImagePixelFormat();
            break; // 6ab00099
        case ptrImportTable::ptr_gdiplus_GdipGetFontHeightGivenDPI:
            eax = gdiplus::GdipGetFontHeightGivenDPI();
            break; // 6ab0009a
        case ptrImportTable::ptr_gdiplus_GdipDeleteFont:
            eax = gdiplus::GdipDeleteFont();
            break; // 6ab0009b
        case ptrImportTable::ptr_gdiplus_GdipCreateBitmapFromScan0:
            eax = gdiplus::GdipCreateBitmapFromScan0();
            break; // 6ab0009c
        case ptrImportTable::ptr_gdiplus_GdipDeleteGraphics:
            eax = gdiplus::GdipDeleteGraphics();
            break; // 6ab0009d
        case ptrImportTable::ptr_gdiplus_GdipGetDpiY:
            eax = gdiplus::GdipGetDpiY();
            break; // 6ab0009e
        case ptrImportTable::ptr_gdiplus_GdipSetClipRectI:
            eax = gdiplus::GdipSetClipRectI();
            break; // 6ab0009f
        case ptrImportTable::ptr_gdiplus_GdipGetImageGraphicsContext:
            eax = gdiplus::GdipGetImageGraphicsContext();
            break; // 6ab000a0
        case ptrImportTable::ptr_gdiplus_GdipSetSmoothingMode:
            eax = gdiplus::GdipSetSmoothingMode();
            break; // 6ab000a1
        case ptrImportTable::ptr_gdiplus_GdipDeleteFontFamily:
            eax = gdiplus::GdipDeleteFontFamily();
            break; // 6ab000a2
        case ptrImportTable::ptr_gdiplus_GdipCreateSolidFill:
            eax = gdiplus::GdipCreateSolidFill();
            break; // 6ab000a3
        case ptrImportTable::ptr_gdiplus_GdipDisposeImageAttributes:
            eax = gdiplus::GdipDisposeImageAttributes();
            break; // 6ab000a4
        case ptrImportTable::ptr_gdiplus_GdipSetPenColor:
            eax = gdiplus::GdipSetPenColor();
            break; // 6ab000a5
        case ptrImportTable::ptr_gdiplus_GdiplusStartup:
            eax = gdiplus::GdiplusStartup();
            break; // 6ab000a6
        case ptrImportTable::ptr_gdiplus_GdipCreatePen1:
            eax = gdiplus::GdipCreatePen1();
            break; // 6ab000a7
        case ptrImportTable::ptr_gdiplus_GdipSetPixelOffsetMode:
            eax = gdiplus::GdipSetPixelOffsetMode();
            break; // 6ab000a8
        case ptrImportTable::ptr_gdiplus_GdipGetImageWidth:
            eax = gdiplus::GdipGetImageWidth();
            break; // 6ab000a9
        case ptrImportTable::ptr_gdiplus_GdipSetPenDashStyle:
            eax = gdiplus::GdipSetPenDashStyle();
            break; // 6ab000aa
        case ptrImportTable::ptr_gdiplus_GdipDrawLineI:
            eax = gdiplus::GdipDrawLineI();
            break; // 6ab000ab
        case ptrImportTable::ptr_gdiplus_GdipCloneImage:
            eax = gdiplus::GdipCloneImage();
            break; // 6ab000ac
        case ptrImportTable::ptr_gdiplus_GdipCreateBitmapFromResource:
            eax = gdiplus::GdipCreateBitmapFromResource();
            break; // 6ab000ad
        case ptrImportTable::ptr_gdiplus_GdipSetInterpolationMode:
            eax = gdiplus::GdipSetInterpolationMode();
            break; // 6ab000ae
        case ptrImportTable::ptr_gdiplus_GdipSetSolidFillColor:
            eax = gdiplus::GdipSetSolidFillColor();
            break; // 6ab000af
        case ptrImportTable::ptr_gdiplus_GdipCreateFromHDC:
            eax = gdiplus::GdipCreateFromHDC();
            break; // 6ab000b0
        case ptrImportTable::ptr_gdiplus_GdipCreateFontFamilyFromName:
            eax = gdiplus::GdipCreateFontFamilyFromName();
            break; // 6ab000b1
        case ptrImportTable::ptr_gdiplus_GdipFillRectangle:
            eax = gdiplus::GdipFillRectangle();
            break; // 6ab000b2
        case ptrImportTable::ptr_gdiplus_GdipDrawString:
            eax = gdiplus::GdipDrawString();
            break; // 6ab000b3
        case ptrImportTable::ptr_gdiplus_GdipDrawRectangle:
            eax = gdiplus::GdipDrawRectangle();
            break; // 6ab000b4
        case ptrImportTable::ptr_gdiplus_GdipCreateImageAttributes:
            eax = gdiplus::GdipCreateImageAttributes();
            break; // 6ab000b5
        case ptrImportTable::ptr_gdiplus_GdipGetGenericFontFamilySansSerif:
            eax = gdiplus::GdipGetGenericFontFamilySansSerif();
            break; // 6ab000b6
        case ptrImportTable::ptr_gdiplus_GdipCreateBitmapFromHBITMAP:
            eax = gdiplus::GdipCreateBitmapFromHBITMAP();
            break; // 6ab000b7
        case ptrImportTable::ptr_gdiplus_GdipSetPageUnit:
            eax = gdiplus::GdipSetPageUnit();
            break; // 6ab000b8
        case ptrImportTable::ptr_gdiplus_GdipCreateFont:
            eax = gdiplus::GdipCreateFont();
            break; // 6ab000b9
        case ptrImportTable::ptr_gdiplus_GdipSetPenWidth:
            eax = gdiplus::GdipSetPenWidth();
            break; // 6ab000ba
        case ptrImportTable::ptr_gdiplus_GdipDisposeImage:
            eax = gdiplus::GdipDisposeImage();
            break; // 6ab000bb
        case ptrImportTable::ptr_gdiplus_GdipAlloc:
            eax = gdiplus::GdipAlloc();
            break; // 6ab000bc
        case ptrImportTable::ptr_ole32_RevokeDragDrop:
            eax = ole32::RevokeDragDrop();
            break; // 6ab000bd
        case ptrImportTable::ptr_ole32_CoCreateInstance:
            eax = ole32::CoCreateInstance();
            break; // 6ab000be
        case ptrImportTable::ptr_ole32_RegisterDragDrop:
            eax = ole32::RegisterDragDrop();
            break; // 6ab000bf
        case ptrImportTable::ptr_ole32_OleUninitialize:
            eax = ole32::OleUninitialize();
            break; // 6ab000c0
        case ptrImportTable::ptr_ole32_OleInitialize:
            eax = ole32::OleInitialize();
            break; // 6ab000c1
    }
}

}

function start()
{
    sub_1002195c();
}
*/
function init()
{
    loadOverlay("ddx10_text.bin", 0x10001000);
    loadOverlay("ddx10_rdata.bin", 0x1003c000);
    loadOverlay("ddx10_data.bin", 0x1004d000);
    loadOverlay("ddx10_rsrc.bin", 0x10052000);
    loadOverlay("ddx10_reloc.bin", 0x10064000);
    r32[esp] = 0x1006a000;
    r32[ebp] = 0x1006a000;
}

function sub_10008ac0() // 0000:10008ac0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1003a88b);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    push32(r32[ecx]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 8;
//    memoryASet32(fs, 0x0, r32[eax]);
    push32(0x00001080);
    sub_1001fa1d();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x4, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x10, 0x00000000);
    if (!r32[eax])
        { pc = 0x10008b19; break; }
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x18);
    push32(r32[ecx]);
    push32(r32[eax]);
    sub_10008b40();
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[esp] += 0x00000010;
    r32[esp] += 4; return;
  case 0x10008b19: // 0000:10008b19
    r32[eax] = 0;
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x8);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[esp] += 0x00000010;
    r32[esp] += 4;
    return;
  }
}
function sub_10008b40() // 0000:10008b40 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(0xffffffff);
    push32(0x1003a0eb);
//    r32[eax] = memoryAGet32(fs, 0x0);
    push32(r32[eax]);
    push32(r32[esi]);
    push32(r32[edi]);
    r32[eax] = memoryAGet32(ds, 0x1004d1dc);
    r32[eax] ^= r32[esp];
    push32(r32[eax]);
    r32[eax] = r32[esp] + 12;
//    memoryASet32(fs, 0x0, r32[eax]);
    r32[edi] = memoryAGet32(ds, r32[esp] + 0x1c);
    r32[eax] = memoryAGet32(ds, r32[esp] + 0x20);
    r32[esi] = r32[edi];
    sub_10010790();
    push32(0x10008800);
    push32(0x100105f0);
    push32(0x00000020);
    push32(0x00000068);
    r32[eax] = r32[edi] + 184;
    memoryASet32(ds, r32[esp] + 0x24, 0x00000000);
    push32(r32[eax]);
    memoryASet32(ds, r32[edi], 0x1003f404);
    sub_10020d33(); // eh_vector_constructor_iterator
    memoryASet(ds, r32[esp] + 0x14, 0x01);
    memoryASet32(ds, r32[edi] + 0x44, memoryAGet32(ds, r32[edi] + 0x44) | 0x00001110);
    push32(0x00002524);
    memoryASet32(ds, r32[edi] + 0x3c, 0x00000000);
    memoryASet32(ds, r32[edi] + 0x40, 0x00000002);
    memoryASet32(ds, r32[edi] + 0x68, 0x2d535e31);
    sub_1001ef91();
    r32[esp] += 0x00000004;
    memoryASet32(ds, r32[esp] + 0x20, r32[eax]);
    memoryASet(ds, r32[esp] + 0x14, 0x02);
    if (!r32[eax])
        { pc = 0x10008bf5; break; }
    push32(0x10008800);
    push32(0x1000c040);
    push32(0x00000063);
    r32[esi] = r32[eax] + 4;
    push32(0x00000060);
    push32(r32[esi]);
    memoryASet32(ds, r32[eax], 0x00000063);
    sub_10020d33(); // eh_vector_constructor_iterator
    r32[eax] = r32[esi];
    { pc = 0x10008bf7; break; }
  case 0x10008bf5: // 0000:10008bf5
    r32[eax] = 0;
  case 0x10008bf7: // 0000:10008bf7
    memoryASet(ds, r32[esp] + 0x14, 0x01);
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x1004185c));
    memoryASet32(ds, r32[edi] + 0xb0, r32[eax]);
    memoryASet32(ds, r32[esp] + 0x3c, fstp32());
    r32[ecx] = 0x1003f29c;
    fldz();
    r32[eax] = 0;
    memoryASet32(ds, r32[esp] + 0x38, fst32());
    fld32(memoryAGet32(ds, 0x10041858));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fld32(memoryAGet32(ds, 0x10041854));
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041850));
    memoryASet32(ds, r32[esp] + 0x20, fst32());
    fld32(memoryAGet32(ds, 0x1004184c));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041848));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fld32(memoryAGet32(ds, 0x10041844));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x10041840));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x1004183c));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041838));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f2ac;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x00000001;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x38, fst32());
    fld32(memoryAGet32(ds, 0x10041834));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fld32(memoryAGet32(ds, 0x10041850));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041830));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x1004182c));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x1004183c));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x10041828));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041824));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041820));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    r32[ecx] = 0x1003f2bc;
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    r32[eax] = 0x00000002;
    fld32(memoryAGet32(ds, 0x1004181c));
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    fld32(memoryAGet32(ds, 0x10041818));
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041850));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041814));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x10041810));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x1004180c));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fld32(memoryAGet32(ds, 0x10041808));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x10041848));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041800));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fldz();
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x100417fc));
    r32[ecx] = 0x1003f2c8;
    memoryASet32(ds, r32[esp] + 0x3c, fstp32());
    r32[eax] = 0x00000003;
    fld32(memoryAGet32(ds, 0x100417f8));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x100417f4));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x100417f0));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fld32(memoryAGet32(ds, 0x100417ec));
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041850));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x100417e8));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x100417e4));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x100417e0));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fld32(memoryAGet32(ds, 0x100417dc));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x100417d8));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041800));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fldz();
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x100417d4));
    memoryASet32(ds, r32[esp] + 0x3c, fstp32());
    fld32(memoryAGet32(ds, 0x100417d0));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x100417cc));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fld32(memoryAGet32(ds, 0x100417c8));
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041854));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x100417c4));
    r32[ecx] = 0x1003f2d8;
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    r32[eax] = 0x00000004;
    fld32(memoryAGet32(ds, 0x1004181c));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x100417c0));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x100417bc));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041838));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x100417b8));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    r32[ecx] = 0x1003f2e4;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    r32[eax] = 0x00000005;
    fld32(memoryAGet32(ds, 0x100417b4));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041840));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fstp32());
    fld32(memoryAGet32(ds, 0x100417b8));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fld32(memoryAGet32(ds, 0x100417b0));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x100417ac));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x100417a8));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x100417a4));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    memoryASet32(ds, r32[esp] + 0x8, fst32());
    fld32(memoryAGet32(ds, 0x100417a0));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x1004179c));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041798));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041850));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041794));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x100417c4));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041790));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x1004178c));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    r32[ecx] = 0x1003f2f0;
    r32[eax] = 0x00000006;
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f2fc;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x00000007;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041788));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041784));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fld32(memoryAGet32(ds, 0x10041780));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x100417d4));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x1004177c));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041778));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x10041848));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041774));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f304;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x00000008;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041770));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x1004176c));
    memoryASet32(ds, r32[esp] + 0x34, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fld32(memoryAGet32(ds, 0x10041768));
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041764));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x1004184c));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x10041760));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x1004175c));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x100417d8));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041758));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fld32(memoryAGet32(ds, 0x100417b8));
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x1004185c));
    r32[ecx] = 0x1003f310;
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    r32[eax] = 0x00000009;
    fldz();
    memoryASet32(ds, r32[esp] + 0x34, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041850));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fld32(memoryAGet32(ds, 0x10041760));
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fld32(memoryAGet32(ds, 0x10041854));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041754));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x10041750));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x1004174c));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fld32(memoryAGet32(ds, 0x100417b4));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x10041748));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041838));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f318;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x0000000a;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041820));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x1004182c));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fld32(memoryAGet32(ds, 0x1004181c));
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041744));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x100417a4));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x10041740));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x1004173c));
    memoryASet32(ds, r32[esp] + 0x14, fst32());
    fld32(memoryAGet32(ds, 0x10041738));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x10041848));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041800));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fldz();
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041734));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x100417fc));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x100417b0));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x100417b8));
    r32[ecx] = 0x1003f324;
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    r32[eax] = 0x0000000b;
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x100417a8));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x100417c0));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    memoryASet32(ds, r32[esp] + 0x8, fst32());
    fld32(memoryAGet32(ds, 0x10041764));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f32c;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x0000000c;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x38, fst32());
    fld32(memoryAGet32(ds, 0x100417cc));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041730));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fld32(memoryAGet32(ds, 0x10041854));
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x100417a4));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    memoryASet32(ds, r32[esp] + 0x1c, fst32());
    fld32(memoryAGet32(ds, 0x1004172c));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041728));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x100417c4));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041800));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041724));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x100417ec));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fld32(memoryAGet32(ds, 0x10041850));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x1004181c));
    memoryASet32(ds, r32[esp] + 0x1c, fst32());
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041720));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x100417c0));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    r32[ecx] = 0x1003f334;
    memoryASet32(ds, r32[esp], fstp32());
    r32[eax] = 0x0000000d;
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fst32());
    fld32(memoryAGet32(ds, 0x10041500));
    r32[ecx] = 0x1003f340;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    r32[eax] = 0x0000000e;
    fldz();
    memoryASet32(ds, r32[esp] + 0x38, fst32());
    fld32(memoryAGet32(ds, 0x1004171c));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x30, fstp32());
    fld32(memoryAGet32(ds, 0x100417b8));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041744));
    memoryASet32(ds, r32[esp] + 0x20, fst32());
    fld32(memoryAGet32(ds, 0x10041798));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x14, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x10041734));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x100417f0));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041760));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f34c;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x0000000f;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041718));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041778));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    memoryASet32(ds, r32[esp] + 0x20, fst32());
    fld32(memoryAGet32(ds, 0x10041728));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x10041714));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041710));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x100417d8));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041760));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x100417cc));
    memoryASet32(ds, r32[esp] + 0x3c, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x38, fst32());
    r32[ecx] = 0x1003f358;
    fld32(memoryAGet32(ds, 0x1004170c));
    r32[eax] = 0x00000010;
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x30, fstp32());
    fld32(memoryAGet32(ds, 0x100417b8));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fld32(memoryAGet32(ds, 0x10041708));
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fld32(memoryAGet32(ds, 0x10041850));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041704));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x10041700));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    memoryASet32(ds, r32[esp] + 0x14, fst32());
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x10041848));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041758));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f360;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x00000011;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041734));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x100417dc));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041850));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041760));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x100416fc));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x10041848));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x100417a4));
    memoryASet32(ds, r32[esp] + 0x8, fst32());
    fld32(memoryAGet32(ds, 0x10041758));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x100416f8));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x100416f4));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fld32(memoryAGet32(ds, 0x100416f0));
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041854));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041754));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x100416ec));
    r32[ecx] = 0x1003f368;
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    r32[eax] = 0x00000012;
    fld32(memoryAGet32(ds, 0x10041764));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x100416e8));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x1004181c));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041758));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fld32(memoryAGet32(ds, 0x100416e4));
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f370;
    fld32(memoryAGet32(ds, 0x1004185c));
    r32[eax] = 0x00000013;
    memoryASet32(ds, r32[esp] + 0x3c, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041808));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fld32(memoryAGet32(ds, 0x100416e0));
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041854));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x1004178c));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x100416ec));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041764));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fld32(memoryAGet32(ds, 0x100416dc));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x10041704));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x1004181c));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041758));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fld32(memoryAGet32(ds, 0x100416e4));
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x100416d8));
    memoryASet32(ds, r32[esp] + 0x3c, fstp32());
    fld32(memoryAGet32(ds, 0x100416f0));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x100416d4));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x30, fstp32());
    fld32(memoryAGet32(ds, 0x100416d0));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fld32(memoryAGet32(ds, 0x10041710));
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    fld32(memoryAGet32(ds, 0x100416cc));
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041850));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x100416c8));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x100417c0));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x1004177c));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fld32(memoryAGet32(ds, 0x10041768));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x10041848));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041784));
    r32[ecx] = 0x1003f378;
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    r32[eax] = 0x00000014;
    fld32(memoryAGet32(ds, 0x10041758));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fld32(memoryAGet32(ds, 0x100416f4));
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f380;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x00000015;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041794));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x1004171c));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x1004181c));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041810));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fld32(memoryAGet32(ds, 0x100416c4));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x100417a4));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x8, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f38c;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x00000016;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041770));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041834));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041700));
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    memoryASet32(ds, r32[esp] + 0x28, fstp32());
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fld32(memoryAGet32(ds, 0x100416c0));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x1004181c));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x100416bc));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x100416b8));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x1004174c));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fld32(memoryAGet32(ds, 0x10041848));
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    r32[ecx] = 0x1003f394;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    r32[eax] = 0x00000017;
    fld32(memoryAGet32(ds, 0x100416b4));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x1004173c));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041700));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041854));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x1004184c));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x100417d8));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041704));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x10041848));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x100417b8));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f3a0;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x00000018;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x100417e8));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x1004183c));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x10041854));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    fld32(memoryAGet32(ds, 0x100416b0));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x100416ac));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fld32(memoryAGet32(ds, 0x10041724));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x100416e8));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x100417b8));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x100416a8));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x100416a4));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    r32[ecx] = 0x1003f3ac;
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    r32[eax] = 0x00000019;
    fld32(memoryAGet32(ds, 0x10041854));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x1c, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x100416a0));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fld32(memoryAGet32(ds, 0x10041778));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x100416e8));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fld32(memoryAGet32(ds, 0x10041720));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x100417b8));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f3b8;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x0000001a;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041744));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041798));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041700));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fstp32());
    fld32(memoryAGet32(ds, 0x100416c0));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041634));
    memoryASet32(ds, r32[esp] + 0x1c, fst32());
    fld32(memoryAGet32(ds, 0x100417e4));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x100416b0));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x100417d8));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x100417b8));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x1004169c));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x100417d0));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fld32(memoryAGet32(ds, 0x10041800));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x1c, fst32());
    fld32(memoryAGet32(ds, 0x10041698));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x100416fc));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    r32[ecx] = 0x1003f3c4;
    r32[eax] = 0x0000001b;
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x100417a4));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fld32(memoryAGet32(ds, 0x10041760));
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f3d4;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x0000001c;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041710));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041694));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x10041804));
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fld32(memoryAGet32(ds, 0x10041800));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x100416dc));
    memoryASet32(ds, r32[esp] + 0x1c, fst32());
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041690));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    fld32(memoryAGet32(ds, 0x1004178c));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    fld32(memoryAGet32(ds, 0x10041760));
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    r32[ecx] = 0x1003f3e4;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x0000001d;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x10041714));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041778));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    memoryASet32(ds, r32[esp] + 0x2c, fst32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fld32(memoryAGet32(ds, 0x10041800));
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x1c, fst32());
    fld32(memoryAGet32(ds, 0x10041700));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x1004168c));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    memoryASet32(ds, r32[esp] + 0x10, fst32());
    fld32(memoryAGet32(ds, 0x100417a4));
    memoryASet32(ds, r32[esp] + 0xc, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x8, fst32());
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fstp32());
    fld32(memoryAGet32(ds, 0x10041500));
    r32[ecx] = 0x1003f3f0;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    r32[eax] = 0x0000001e;
    fld32(memoryAGet32(ds, 0x10041830));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fld32(memoryAGet32(ds, 0x10041688));
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x100417b8));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x20, fst32());
    memoryASet32(ds, r32[esp] + 0x1c, fst32());
    fld32(memoryAGet32(ds, 0x10041684));
    memoryASet32(ds, r32[esp] + 0x18, fstp32());
    fld32(memoryAGet32(ds, 0x10041680));
    memoryASet32(ds, r32[esp] + 0x14, fstp32());
    fld32(memoryAGet32(ds, 0x10041764));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    memoryASet32(ds, r32[esp] + 0xc, fst32());
    memoryASet32(ds, r32[esp] + 0x8, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    fld1();
    r32[esp] -= 0x00000044;
    memoryASet32(ds, r32[esp] + 0x40, fst32());
    r32[ecx] = 0x1003f3f8;
    fld32(memoryAGet32(ds, 0x10041500));
    r32[eax] = 0x0000001f;
    memoryASet32(ds, r32[esp] + 0x3c, fst32());
    fld32(memoryAGet32(ds, 0x100417d0));
    memoryASet32(ds, r32[esp] + 0x38, fstp32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x34, fstp32());
    memoryASet32(ds, r32[esp] + 0x30, fst32());
    fld32(memoryAGet32(ds, 0x1004167c));
    memoryASet32(ds, r32[esp] + 0x2c, fstp32());
    fldz();
    memoryASet32(ds, r32[esp] + 0x28, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[esp] + 0x24, fst32());
    memoryASet32(ds, r32[esp] + 0x20, fstp32());
    fld32(memoryAGet32(ds, 0x10041700));
    memoryASet32(ds, r32[esp] + 0x1c, fstp32());
    memoryASet32(ds, r32[esp] + 0x18, fst32());
    memoryASet32(ds, r32[esp] + 0x14, fst32());
    fld32(memoryAGet32(ds, 0x100416b4));
    memoryASet32(ds, r32[esp] + 0x10, fstp32());
    memoryASet32(ds, r32[esp] + 0xc, fst32());
    fld32(memoryAGet32(ds, 0x100416b0));
    memoryASet32(ds, r32[esp] + 0x8, fstp32());
    fld32(memoryAGet32(ds, 0x10041678));
    memoryASet32(ds, r32[esp] + 0x4, fstp32());
    memoryASet32(ds, r32[esp], fstp32());
    sub_1000bd60();
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x260);
    r32[ecx] = r32[edi];
    memoryASet32(ds, r32[edi] + 0x1c, 0x00000000);
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x26c);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[eax]);
    r32[edx] = memoryAGet32(ds, r32[edi]);
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x1a4);
    r32[ecx] = r32[edi];
    indirectCall(cs, r32[eax]);
    push32(0x000000cc);
    sub_1001fa1d();
    r32[esi] = r32[eax];
    r32[esp] += 0x00000004;
    if (!r32[esi])
        { pc = 0x10009f9e; break; }
    r32[eax] = r32[edi];
    sub_10010470();
    memoryASet32(ds, r32[esi], 0x1003edd4);
    memoryASet32(ds, r32[esi] + 0xc, 0x1003ee14);
    memoryASet32(ds, r32[esi] + 0x24, 0x1003ee2c);
    memoryASet32(ds, 0x10050558, 0x00000002);
    { pc = 0x10009fa0; break; }
  case 0x10009f9e: // 0000:10009f9e
    r32[esi] = 0;
  case 0x10009fa0: // 0000:10009fa0
    memoryASet32(ds, r32[edi] + 0x8, r32[esi]);
    r32[eax] = r32[edi];
    if (!r32[esi])
        { pc = 0x10009fc1; break; }
    memoryASet32(ds, r32[edi] + 0x44, memoryAGet32(ds, r32[edi] + 0x44) | 0x00000001);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 0x0000000c;
    stop("stack_unbalanced");
    r32[esp] += 12; return;
  case 0x10009fc1: // 0000:10009fc1
    memoryASet32(ds, r32[edi] + 0x44, memoryAGet32(ds, r32[edi] + 0x44) & 0xfffffffe);
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0xc);
//    memoryASet32(fs, 0x0, r32[ecx]);
    r32[ecx] = pop32();
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] += 0x0000000c;
    stop("stack_unbalanced");
    r32[esp] += 12;
    return;
  }
}
function sub_1000ba30() // 0000:1000ba30 +long +stackDrop8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] &= 0xfffffff8;
    r32[esp] -= 0x0000000c;
    fld1();
    push32(r32[ebx]);
    push32(r32[esi]);
    fld80(st(0));
    push32(r32[edi]);
    r32[edi] = r32[ecx];
    r32[eax] = memoryAGet32(ds, r32[edi] + 0x1c);
    r32[esi] = r32[eax] + (r32[eax] * 2);
    r32[esi] <<= 5;
    r32[esi] += memoryAGet32(ds, r32[edi] + 0xb0);
    r32[ebx] = 0;
    memoryASet32(ds, r32[esp] + 0x14, r32[esi]);
    if (signed32(memoryAGet32(ss, r32[ebp] + 0xc)) <= r32s[ebx])
        { pc = 0x1000bbf7; break; }
    r32[edx] = r32[ebx] + 2;
    r32[ecx] = r32[edi] + 288;
  case 0x1000ba69: // 0000:1000ba69
    fcom64(memoryAGet64(ds, r32[ecx] - 104));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x1000ba7b; break; }
    fstp80();
    r32[ebx] = r32[edx] - 2;
    fld64(memoryAGet64(ds, r32[ecx] - 104));
  case 0x1000ba7b: // 0000:1000ba7b
    fcom64(memoryAGet64(ds, r32[ecx]));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x1000ba8b; break; }
    fstp80();
    r32[ebx] = r32[edx] - 1;
    fld64(memoryAGet64(ds, r32[ecx]));
  case 0x1000ba8b: // 0000:1000ba8b
    fcom64(memoryAGet64(ds, r32[ecx] + 0x68));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x1000ba9c; break; }
    fstp80();
    r32[ebx] = r32[edx];
    fld64(memoryAGet64(ds, r32[ecx] + 0x68));
  case 0x1000ba9c: // 0000:1000ba9c
    fcom64(memoryAGet64(ds, r32[ecx] + 0xd0));
    r16[ax] = fnstsw();
    if (r8[ah] & 0x41)
        { pc = 0x1000bab4; break; }
    fstp80();
    r32[ebx] = r32[edx] + 1;
    fld64(memoryAGet64(ds, r32[ecx] + 0xd0));
  case 0x1000bab4: // 0000:1000bab4
    r32[edx] += 0x00000004;
    r32[eax] = r32[edx] - 2;
    r32[ecx] += 0x000001a0;
    if (r32s[eax] < signed32(0x00000020))
        { pc = 0x1000ba69; break; }
    fstp80();
    fld32(memoryAGet32(ds, r32[esi] + 0x30));
    stop("disassembly failed at 0000:1000baca (fiadd dword ptr [ebp + 8])");
    fadd32(memoryAGet32(ds, r32[esi] + 0x30));
    stop("disassembly failed at 0000:1000bad0 (fsubrp st(1))");
    fmul64(memoryAGet64(ds, 0x10041520));
    sub_100358cc();
    fldz();
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0x8);
    r32[ecx] = r32[ebx];
    r32[ecx] = r32s[ecx] * signed32(0x00000068);
    memoryASet64(ds, r32[ecx] + r32[edi] + 0xf0, fst64());
    r32[esi] = r32[ecx] + r32[edi];
    memoryASet32(ds, r32[esi] + 0x118, r32[edx]);
    fld64(memoryAGet64(ds, r32[edi] + 0x1048));
    fmul64(memoryAGet64(ds, r32[edi] + 0xfc8));
    fmul80(st(2));
    memoryASet64(ds, r32[esi] + 0xf8, fstp64());
    fld64(memoryAGet64(ds, 0x10041518));
    fcom80(st(2));
    r16[ax] = fnstsw();
    if (stop("bad condition - jp"))
        { pc = 0x1000bb1e; break; }
    st(2) = fstp_check80();
    { pc = 0x1000bb20; break; }
  case 0x1000bb1e: // 0000:1000bb1e
    fstp80();
  case 0x1000bb20: // 0000:1000bb20
    r32[eax] = memoryAGet32(ss, r32[ebp] + 0xc);
    r32[eax] += 0xffffffc0;
    memoryASet32(ds, r32[esp] + 0x10, r32[eax]);
    fild32(memoryAGet32(ds, r32[esp] + 0x10));
    fmul64(memoryAGet64(ds, r32[edi] + 0x1050));
    fadd64(memoryAGet64(ds, 0x10041510));
    stop("disassembly failed at 0000:1000bb3a (fmulp st(2))");
    fld64(memoryAGet64(ds, r32[edi] + 0x1000));
    fmul80(st(2));
    memoryASet64(ds, r32[esi] + 0xd8, fstp64());
    fld64(memoryAGet64(ds, r32[edi] + 0x1008));
    stop("disassembly failed at 0000:1000bb50 (fmulp st(2))");
    fxch80st(0, 1);
    memoryASet64(ds, r32[esi] + 0xe0, fstp64());
    fld64(memoryAGet64(ds, r32[edi] + 0x1010));
    memoryASet64(ds, r32[esi] + 0xe8, fstp64());
    fld64(memoryAGet64(ds, r32[edi] + 0xfe0));
    fmul64(memoryAGet64(ds, r32[esi] + 0xf8));
    memoryASet64(ds, r32[esi] + 0xc0, fstp64());
    memoryASet64(ds, r32[esi] + 0xc8, fstp64());
    fld64(memoryAGet64(ds, r32[esi] + 0xc0));
    sub_10035500();
    r32[ebx] += 0x00000002;
    r32[ebx] = r32s[ebx] * signed32(0x00000068);
    memoryASet64(ds, r32[ebx] + r32[edi], fstp64());
    fld64(memoryAGet64(ds, r32[esi] + 0xc0));
    sub_10035630();
    fadd80(st(0));
    r32[ecx] = memoryAGet32(ds, r32[esp] + 0x14);
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0xc);
    memoryASet64(ds, r32[esi] + 0xc0, fstp64());
    r32[edx] += 0x0000000a;
    fld32(memoryAGet32(ds, r32[ecx] + 0x34));
    memoryASet32(ds, r32[esp] + 0x14, r32[edx]);
    fsubr64(memoryAGet64(ds, 0x10041508)); // dc 2d 08 15 04 10 : fsubr qword ptr [0x10041508]
    fmul64(memoryAGet64(ds, r32[edi] + 0x1058));
    fild32(memoryAGet32(ds, r32[esp] + 0x14));
    stop("disassembly failed at 0000:1000bbc6 (fmulp st(1))");
    memoryASet64(ds, r32[esi] + 0xb8, fstp64());
    fld64(memoryAGet64(ds, r32[edi] + 0xfe8));
    memoryASet64(ds, r32[esi] + 0x108, fstp64());
    fldz();
    memoryASet64(ds, r32[esi] + 0x100, fstp64());
    fld64(memoryAGet64(ds, r32[edi] + 0xff0));
    memoryASet64(ds, r32[esi] + 0x110, fstp64());
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp];
    r32[ebp] = pop32();
    r32[esp] += 12; return;
  case 0x1000bbf7: // 0000:1000bbf7
    r32[edx] = memoryAGet32(ss, r32[ebp] + 0x8);
    fstp80();
    fldz();
    r32[ecx] = 0x00000020;
    r32[eax] = r32[edi] + 256;
    r32[esi] = r32[ecx] + 96;
  case 0x1000bc0c: // 0000:1000bc0c
    if (memoryAGet32(ds, r32[eax] + 0x18) != r32[edx])
        { pc = 0x1000bc3f; break; }
    if (memoryAGet32(ds, r32[edi] + 0xfb8) != r32[ebx])
        { pc = 0x1000bc3c; break; }
    fld64(memoryAGet64(ds, r32[edi] + 0xff8));
    memoryASet64(ds, r32[eax] + 0x10, fstp64());
    fld64(memoryAGet64(ds, r32[eax]));
    memoryASet64(ds, r32[eax] - 72, fstp64());
    fxch80st(0, 1);
    memoryASet64(ds, r32[eax] + 0x8, fst64());
    fxch80st(0, 1);
    memoryASet64(ds, r32[eax] - 32, fst64());
    fld64(memoryAGet64(ds, r32[edi] + 0x1018));
    memoryASet64(ds, r32[eax] - 24, fstp64());
    { pc = 0x1000bc3f; break; }
  case 0x1000bc3c: // 0000:1000bc3c
    memoryASet32(ds, r32[eax] + 0x18, r32[esi]);
  case 0x1000bc3f: // 0000:1000bc3f
    r32[eax] += 0x00000068;
    r32[ecx]--;
    if (r32[ecx])
        { pc = 0x1000bc0c; break; }
    r32[edi] = pop32();
    fstp80();
    r32[esi] = pop32();
    fstp80();
    r32[ebx] = pop32();
    r32[esp] = r32[ebp];
    r32[ebp] = pop32();
    r32[esp] += 12;
    return;
  }
}
function sub_1000bd60() // 0000:1000bd60 +long +stackDrop68
{
    r32[esp] -= 4;
    push32(r32[ebx]);
    push32(r32[esi]);
    r32[esi] = r32[eax] + (r32[eax] * 2);
    r32[eax] = memoryAGet32(ds, r32[edi] + 0xb0);
    push32(0x00000018);
    r32[esi] <<= 5;
    r32[ebx] = (r32[eax] + r32[esi]) + 68;
    push32(r32[ecx]);
    push32(r32[ebx]);
    sub_10020480();
    fld32(memoryAGet32(ds, r32[esp] + 0x18));
    memoryASet(ds, r32[ebx] + 0x18, 0x00);
    r32[edx] = memoryAGet32(ds, r32[edi] + 0xb0);
    memoryASet32(ds, r32[esi] + r32[edx], fstp32());
    r32[eax] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x1c));
    r32[esp] += 0x0000000c;
    memoryASet32(ds, r32[eax] + r32[esi] + 0x4, fstp32());
    r32[ecx] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x14));
    memoryASet32(ds, r32[ecx] + r32[esi] + 0x8, fstp32());
    r32[edx] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x18));
    memoryASet32(ds, r32[edx] + r32[esi] + 0xc, fstp32());
    r32[eax] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x1c));
    memoryASet32(ds, r32[eax] + r32[esi] + 0x10, fstp32());
    r32[ecx] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x20));
    memoryASet32(ds, r32[ecx] + r32[esi] + 0x14, fstp32());
    r32[edx] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x24));
    memoryASet32(ds, r32[edx] + r32[esi] + 0x18, fstp32());
    r32[eax] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x28));
    memoryASet32(ds, r32[eax] + r32[esi] + 0x1c, fstp32());
    r32[ecx] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x2c));
    memoryASet32(ds, r32[ecx] + r32[esi] + 0x20, fstp32());
    r32[edx] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x30));
    memoryASet32(ds, r32[edx] + r32[esi] + 0x24, fstp32());
    r32[eax] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x34));
    memoryASet32(ds, r32[eax] + r32[esi] + 0x28, fstp32());
    r32[ecx] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x38));
    memoryASet32(ds, r32[ecx] + r32[esi] + 0x2c, fstp32());
    r32[edx] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x3c));
    memoryASet32(ds, r32[edx] + r32[esi] + 0x30, fstp32());
    r32[eax] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x40));
    memoryASet32(ds, r32[eax] + r32[esi] + 0x34, fstp32());
    r32[ecx] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x44));
    memoryASet32(ds, r32[ecx] + r32[esi] + 0x38, fstp32());
    r32[edx] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x48));
    memoryASet32(ds, r32[edx] + r32[esi] + 0x3c, fstp32());
    r32[eax] = memoryAGet32(ds, r32[edi] + 0xb0);
    fld32(memoryAGet32(ds, r32[esp] + 0x4c));
    memoryASet32(ds, r32[eax] + r32[esi] + 0x40, fstp32());
    r32[esi] = pop32();
    r32[ebx] = pop32();
    r32[esp] += 72;
}
function sub_10012170() // 0000:10012170 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    fldz();
    push32(r32[esi]);
    r32[esi] = memoryAGet32(ds, r32[esp] + 0x8);
    push32(r32[ecx]);
    memoryASet32(ds, r32[esp], fstp32());
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000000);
    push32(0x00000001);
    push32(0x00000000);
    indirectCall(cs, r32[esi]);
    r32[esp] += 0x00000018;
    if (r32[eax])
        { pc = 0x10012192; break; }
  case 0x1001218e: // 0000:1001218e
    r32[eax] = 0;
    r32[esi] = pop32();
    r32[esp] += 4; return;
  case 0x10012192: // 0000:10012192
    push32(r32[esi]);
    sub_10008ac0();
    r32[esp] += 0x00000004;
    if (!r32[eax])
        { pc = 0x1001218e; break; }
    r32[edx] = memoryAGet32(ds, r32[eax]);
    r32[ecx] = r32[eax];
    r32[eax] = memoryAGet32(ds, r32[edx] + 0x78);
    r32[esi] = pop32();
    indirectJump(cs, r32[eax]); return; // 0000:100121a7
    return;
  }
}
function fixReloc(seg)
{
}


function sub_10010790() // 0000:10010790 +long
{
    r32[esp] -= 4;
    fld32(memoryAGet32(ds, 0x10041650));
    push32(r32[edi]);
    memoryASet32(ds, r32[esi] + 0x4, r32[eax]);
    memoryASet32(ds, r32[esi] + 0xc, fstp32());
    r32[eax] = 0;
    push32(0x00000090);
    push32(r32[eax]);
    r32[edi] = r32[esi] + 32;
    push32(r32[edi]);
    memoryASet32(ds, r32[esi], 0x1003fd44);
    memoryASet32(ds, r32[esi] + 0x8, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x10, 0x00000400);
    memoryASet32(ds, r32[esi] + 0x14, 0x00000063);
    memoryASet32(ds, r32[esi] + 0x18, 0x00000011);
    memoryASet32(ds, r32[esi] + 0x1c, r32[eax]);
    //sub_10028e30(); // _memset(unaff_ESI + 8,0,0x90); gabo
    fld1();
    memoryASet32(ds, r32[esi] + 0x44, memoryAGet32(ds, r32[esi] + 0x44) | 0x00000010);
    memoryASet32(ds, r32[esi] + 0x5c, fstp32());
    r32[eax] = 0x00000001;
    r32[esp] += 0x0000000c;
    memoryASet32(ds, r32[edi], 0x56737450);
    memoryASet32(ds, r32[esi] + 0x3c, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x6c, r32[eax]);
    memoryASet32(ds, r32[esi] + 0x24, 0x10010680);
    memoryASet32(ds, r32[esi] + 0x28, 0x10010720);
    memoryASet32(ds, r32[esi] + 0x2c, 0x10010700);
    memoryASet32(ds, r32[esi] + 0x30, 0x100106e0);
    memoryASet32(ds, r32[esi] + 0x34, 0x00000063);
    memoryASet32(ds, r32[esi] + 0x38, 0x00000011);
    memoryASet32(ds, r32[esi] + 0x40, 0x00000002);
    memoryASet32(ds, r32[esi] + 0x60, r32[esi]);
    memoryASet32(ds, r32[esi] + 0x68, 0x4e6f4566);
    memoryASet32(ds, r32[esi] + 0x70, 0x10010750);
    memoryASet32(ds, r32[esi] + 0x74, 0x10010770);
    r32[eax] = r32[esi];
    r32[edi] = pop32();
    r32[esp] += 4;
}


function sub_100105f0() // 0000:100105f0 +long
{
    r32[esp] -= 4;
    fldz();
    r32[eax] = r32[ecx];
    memoryASet64(ds, r32[eax], fst64());
    memoryASet32(ds, r32[eax] + 0x60, 0x00000000);
    memoryASet64(ds, r32[eax] + 0x8, fst64());
    memoryASet64(ds, r32[eax] + 0x10, fst64());
    memoryASet64(ds, r32[eax] + 0x18, fst64());
    memoryASet64(ds, r32[eax] + 0x20, fst64());
    memoryASet64(ds, r32[eax] + 0x28, fst64());
    memoryASet64(ds, r32[eax] + 0x30, fst64());
    memoryASet64(ds, r32[eax] + 0x38, fst64());
    memoryASet64(ds, r32[eax] + 0x40, fst64());
    memoryASet64(ds, r32[eax] + 0x48, fst64());
    memoryASet64(ds, r32[eax] + 0x50, fstp64());
    fld64(memoryAGet64(ds, 0x100414f0));
    memoryASet64(ds, r32[eax] + 0x58, fstp64());
    r32[esp] += 4;
}

function sub_1000c040() // 0000:1000c040 +long
{
    r32[esp] -= 4;
    fldz();
    r32[eax] = r32[ecx];
    memoryASet32(ds, r32[eax], fst32());
    fld1();
    memoryASet32(ds, r32[eax] + 0x4, fst32());
    fxch80st(0, 1);
    memoryASet32(ds, r32[eax] + 0x8, fst32());
    memoryASet32(ds, r32[eax] + 0xc, fst32());
    memoryASet32(ds, r32[eax] + 0x10, fst32());
    memoryASet32(ds, r32[eax] + 0x14, fst32());
    memoryASet32(ds, r32[eax] + 0x18, fst32());
    fld32(memoryAGet32(ds, 0x10041500));
    memoryASet32(ds, r32[eax] + 0x1c, fst32());
    memoryASet32(ds, r32[eax] + 0x2c, fst32());
    memoryASet32(ds, r32[eax] + 0x30, fstp32());
    memoryASet32(ds, r32[eax] + 0x20, fst32());
    memoryASet32(ds, r32[eax] + 0x24, fst32());
    memoryASet32(ds, r32[eax] + 0x28, fst32());
    memoryASet32(ds, r32[eax] + 0x34, fst32());
    memoryASet32(ds, r32[eax] + 0x38, fst32());
    memoryASet32(ds, r32[eax] + 0x3c, fstp32());
    memoryASet32(ds, r32[eax] + 0x40, fstp32());
    r32[ecx] = memoryAGet32(ds, 0x1003f764);
    memoryASet32(ds, r32[eax] + 0x44, r32[ecx]);
    r16[dx] = memoryAGet16(ds, 0x1003f768);
    memoryASet16(ds, r32[eax] + 0x48, r16[dx]);
    r32[esp] += 4;
}

function sub_10008810() // 0000:10008810 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    fldz();
    r32[edx] = 0;
    memoryASet64(ds, r32[ecx] + 0xfc8, fst64());
    memoryASet32(ds, r32[ecx] + 0xdb8, 0x05f5e0ff);
    memoryASet64(ds, r32[ecx] + 0xfd0, fst64());
    memoryASet32(ds, r32[ecx] + 0xfb8, r32[edx]);
    memoryASet64(ds, r32[ecx] + 0xfd8, fst64());
    memoryASet32(ds, r32[ecx] + 0xfbc, r32[edx]);
    memoryASet64(ds, r32[ecx] + 0xfe0, fst64());
    memoryASet32(ds, r32[ecx] + 0xfc0, r32[edx]);
    memoryASet64(ds, r32[ecx] + 0xfe8, fst64());
    r32[eax] = r32[ecx] + 200;
    memoryASet64(ds, r32[ecx] + 0xff0, fst64());
    memoryASet64(ds, r32[ecx] + 0xff8, fst64());
    memoryASet64(ds, r32[ecx] + 0x1000, fst64());
    memoryASet64(ds, r32[ecx] + 0x1008, fst64());
    memoryASet64(ds, r32[ecx] + 0x1010, fst64());
    memoryASet64(ds, r32[ecx] + 0x1018, fst64());
    memoryASet64(ds, r32[ecx] + 0x1020, fst64());
    memoryASet64(ds, r32[ecx] + 0x1030, fst64());
    memoryASet64(ds, r32[ecx] + 0x1038, fst64());
    memoryASet64(ds, r32[ecx] + 0x1040, fst64());
    memoryASet64(ds, r32[ecx] + 0x1050, fst64());
    memoryASet64(ds, r32[ecx] + 0x1060, fst64());
    memoryASet64(ds, r32[ecx] + 0x1070, fst64());
    memoryASet64(ds, r32[ecx] + 0x1078, fst64());
    fld1();
    memoryASet64(ds, r32[ecx] + 0x1028, fst64());
    memoryASet64(ds, r32[ecx] + 0x1048, fstp64());
    memoryASet64(ds, r32[ecx] + 0x1068, fst64());
    fld64(memoryAGet64(ds, 0x10041600));
    memoryASet64(ds, r32[ecx] + 0x1058, fstp64());
    r32[ecx] = r32[edx] + 32;
    fld64(memoryAGet64(ds, 0x100414f0));
  case 0x100088d1: // 0000:100088d1
    fxch80st(0, 1);
    memoryASet32(ds, r32[eax] + 0x50, r32[edx]);
    memoryASet64(ds, r32[eax] - 16, fst64());
    r32[eax] += 0x00000068;
    r32[ecx]--;
    memoryASet64(ds, r32[eax] - 112, fst64());
    memoryASet64(ds, r32[eax] - 104, fst64());
    memoryASet64(ds, r32[eax] - 96, fst64());
    memoryASet64(ds, r32[eax] - 88, fst64());
    memoryASet64(ds, r32[eax] - 80, fst64());
    memoryASet64(ds, r32[eax] - 72, fst64());
    memoryASet64(ds, r32[eax] - 64, fst64());
    memoryASet64(ds, r32[eax] - 56, fst64());
    memoryASet64(ds, r32[eax] - 48, fst64());
    memoryASet64(ds, r32[eax] - 40, fst64());
    fxch80st(0, 1);
    memoryASet64(ds, r32[eax] - 32, fst64());
    if (r32[ecx])
        { pc = 0x100088d1; break; }
    fstp80(); //st(1) = fstp_check80();
    fstp80();
    r32[esp] += 4;
    return;
  }
}
function sub_1000aee0() // 0000:1000aee0 +long
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r32[esp] -= 4;
    push32(r32[ebp]);
    r32[ebp] = r32[esp];
    r32[esp] &= 0xffffffc0;
    r32[esp] -= 0x00000038;
    push32(r32[esi]);
    push32(r32[edi]);
    r32[edi] = r32[ecx];
    fld32(memoryAGet32(ds, r32[edi] + 0xc));
    r32[eax] = memoryAGet32(ds, r32[edi] + 0x1c);
    fld1();
    r32[esi] = r32[eax] + (r32[eax] * 2);
    stop("disassembly failed at 0000:1000aef8 (fdivrp st(1))");
    r32[esi] <<= 5;
    r32[esi] += memoryAGet32(ds, r32[edi] + 0xb0);
    r32[esp] -= 0x00000008;
    memoryASet64(ds, r32[esp] + 0x40, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x2c));
    fmul64(memoryAGet64(ds, 0x100415f8));
    memoryASet64(ds, r32[esp], fstp64());
    sub_10035bb0();
    fld64(memoryAGet64(ds, 0x10041548));
    r32[esp] += 0x00000008;
    fsub80(st(1));
    fxch80st(0, 1);
    sub_10035960();
    fld64(memoryAGet64(ds, r32[esp] + 0x38));
    fmul64(memoryAGet64(ds, 0x100415f0));
    r32[esp] -= 0x00000008;
    stop("disassembly failed at 0000:1000af3a (fmulp st(1))");
    memoryASet64(ds, r32[edi] + 0xfc8, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0xc));
    fld64(memoryAGet64(ds, 0x100415e8));
    fmul80(st(1));
    stop("disassembly failed at 0000:1000af4d (fmulp st(1))");
    memoryASet64(ds, r32[esp], fstp64());
    sub_10035bb0();
    memoryASet64(ds, r32[edi] + 0xfd0, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x10));
    memoryASet64(ds, r32[esp], fstp64());
    sub_1000b100();
    memoryASet64(ds, r32[edi] + 0xfd8, fst64());
    r32[esp] += 0x00000008;
    fadd64(memoryAGet64(ds, r32[edi] + 0xfd0));
    fmul64(memoryAGet64(ds, 0x100415e0));
    memoryASet64(ds, r32[edi] + 0xfe0, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x14));
    fld64(memoryAGet64(ds, 0x100415d8));
    fmul80(st(1));
    fld32(memoryAGet32(ds, r32[esi] + 0x14));
    stop("disassembly failed at 0000:1000af91 (fmulp st(2))");
    fxch80st(0, 1);
    memoryASet64(ds, r32[edi] + 0x1000, fstp64());
    fmul32(memoryAGet32(ds, r32[esi] + 0x1c));
    fmul32(memoryAGet32(ds, r32[esi] + 0x1c));
    memoryASet64(ds, r32[edi] + 0x1008, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x24));
    memoryASet64(ds, r32[edi] + 0x1050, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x28));
    fmul64(memoryAGet64(ds, 0x100415d0));
    fmul32(memoryAGet32(ds, r32[esi] + 0x28));
    memoryASet64(ds, r32[edi] + 0x1060, fstp64());
    fld32(memoryAGet32(ds, r32[esi]));
    fld64(memoryAGet64(ds, 0x100415c8));
    fmul80(st(1));
    stop("disassembly failed at 0000:1000afcc (fsubrp st(1))");
    sub_100358cc();
    fmul64(memoryAGet64(ds, r32[esp] + 0x38));
    fchs();
    sub_100358cc();
    fld1();
    fld80(st(0));
    stop("disassembly failed at 0000:1000afe2 (fsubrp st(2))");
    fxch80st(0, 1);
    memoryASet64(ds, r32[edi] + 0xfe8, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x4));
    fcomp64(memoryAGet64(ds, 0x100415c0));
    r16[ax] = fnstsw();
    fld64(memoryAGet64(ds, 0x100415b8));
    if (r8[ah] & 0x41)
        { pc = 0x1000b00c; break; }
    fxch80st(0, 1);
    memoryASet64(ds, r32[edi] + 0xff0, fstp64());
    { pc = 0x1000b035; break; }
  case 0x1000b00c: // 0000:1000b00c
    st(1) = fstp_check80();
    fld32(memoryAGet32(ds, r32[esi] + 0x4));
    fmul64(memoryAGet64(ds, 0x100415c8));
    fsubp80(st(1));
    sub_100358cc();
    fmul64(memoryAGet64(ds, r32[esp] + 0x38));
    fchs();
    sub_100358cc();
    memoryASet64(ds, r32[edi] + 0xff0, fstp64());
    fld64(memoryAGet64(ds, 0x100415b8));
  case 0x1000b035: // 0000:1000b035
    fld32(memoryAGet32(ds, r32[esi] + 0x8));
    fmul80(st(1));
    fsubp80(st(1));
    sub_100358cc();
    fmul64(memoryAGet64(ds, r32[esp] + 0x38));
    fchs();
    sub_100358cc();
    memoryASet64(ds, r32[edi] + 0xff8, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x18));
    fmul64(memoryAGet64(ds, 0x100415b0));
    fsubr64(memoryAGet64(ds, 0x100415a8)); // dc 2d a8 15 04 10 : fsubr qword ptr [0x100415a8]
    sub_100358cc();
    fmul64(memoryAGet64(ds, r32[esp] + 0x38));
    fchs();
    sub_100358cc();
    fld1();
    stop("disassembly failed at 0000:1000b073 (fsubrp st(1))");
    memoryASet64(ds, r32[edi] + 0x1010, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x20));
    fmul64(memoryAGet64(ds, 0x100415c8));
    fsubr64(memoryAGet64(ds, 0x100415b8)); // dc 2d b8 15 04 10 : fsubr qword ptr [0x100415b8]
    sub_100358cc();
    fmul64(memoryAGet64(ds, r32[esp] + 0x38));
    fchs();
    sub_100358cc();
    fld1();
    stop("disassembly failed at 0000:1000b09c (fsubrp st(1))");
    memoryASet64(ds, r32[edi] + 0x1018, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x34));
    fmul64(memoryAGet64(ds, 0x100415a0));
    fmul32(memoryAGet32(ds, r32[esi] + 0x34));
    fsubr64(memoryAGet64(ds, 0x10041588)); // dc 2d 88 15 04 10 : fsubr qword ptr [0x10041588]
    memoryASet64(ds, r32[edi] + 0x1070, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x38));
    fmul64(memoryAGet64(ds, 0x10041570));
    fmul32(memoryAGet32(ds, r32[esi] + 0x38));
    memoryASet64(ds, r32[edi] + 0x1078, fstp64());
    fld64(memoryAGet64(ds, r32[esp] + 0x38));
    fmul64(memoryAGet64(ds, 0x10041598));
    fmul64(memoryAGet64(ds, 0x10041590));
    fmul32(memoryAGet32(ds, r32[esi] + 0x3c));
    fmul32(memoryAGet32(ds, r32[esi] + 0x3c));
    memoryASet64(ds, r32[edi] + 0x1030, fstp64());
    fld32(memoryAGet32(ds, r32[esi] + 0x40));
    fmul80(st(0));
    memoryASet64(ds, r32[edi] + 0x1068, fstp64());
    r32[edi] = pop32();
    r32[esi] = pop32();
    r32[esp] = r32[ebp];
    r32[ebp] = pop32();
    r32[esp] += 4;
    return;
  }
}

function indirectCall(s, o)
{
  switch (o)
  {
    case 0x10008810: sub_10008810(); break;
    case 0x1000aee0: sub_1000aee0(); break;
    default:
      console.log(o.toString(16))
      throw "unimplemented indirect";
  }
}