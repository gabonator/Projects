// kernel32.h
// Windows KERNEL32.dll Function Declarations
// Generated from Import Address Table at 0x40d000

#ifndef KERNEL32_H
#define KERNEL32_H

#include <stdint.h>

extern int allocatorLast;
extern std::vector<uint8_t> allocator;
uint8_t* MemoryGetPtr(int s, int o);

#ifdef __cplusplus
//extern "C" {
namespace kernel32 {
#endif

// Windows type definitions (if not already included via windows.h)
#ifndef _WINDOWS_
typedef void* HANDLE;
typedef void* HMODULE;
typedef void* LPVOID;
typedef const void* LPCVOID;
typedef void* PVOID;
typedef char* LPSTR;
typedef const char* LPCSTR;
typedef wchar_t* LPWSTR;
typedef const wchar_t* LPCWSTR;
typedef char* LPCH;
typedef wchar_t* LPWCH;
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef int BOOL;
typedef unsigned short WORD;
typedef unsigned long ULONG;
typedef uint32_t SIZE_T;
typedef long LONG;
typedef LONG* PLONG;
typedef WORD* LPWORD;
typedef DWORD* LPDWORD;
typedef BOOL* LPBOOL;
typedef unsigned int LCID;
typedef void* FARPROC;

//#define WINAPI __stdcall
#define WINAPI

// Forward declarations for structures
struct _OVERLAPPED;
typedef struct _OVERLAPPED OVERLAPPED;
typedef OVERLAPPED* LPOVERLAPPED;

struct _CPINFO;
typedef struct _CPINFO CPINFO;
typedef CPINFO* LPCPINFO;

struct _STARTUPINFOA;
typedef struct _STARTUPINFOA STARTUPINFOA;
typedef STARTUPINFOA* LPSTARTUPINFOA;

struct _EXCEPTION_RECORD;
typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;
typedef EXCEPTION_RECORD* PEXCEPTION_RECORD;

struct _EXCEPTION_POINTERS;
#endif

BOOL WINAPI CloseHandle(CicoPtr<HANDLE> hObject) {assert(0);}
BOOL WINAPI FlushFileBuffers(CicoPtr<HANDLE> hFile) {assert(0);}
BOOL WINAPI SetStdHandle(DWORD nStdHandle, CicoPtr<HANDLE> hHandle) {assert(0);}
int WINAPI LCMapStringW(LCID Locale, DWORD dwMapFlags, CicoPtr<LPCWSTR> lpSrcStr, int cchSrc, CicoPtr<LPWSTR> lpDestStr, int cchDest) {assert(0);}
int WINAPI LCMapStringA(LCID Locale, DWORD dwMapFlags, CicoPtr<LPCSTR> lpSrcStr, int cchSrc, CicoPtr<LPSTR> lpDestStr, int cchDest) {assert(0);}
BOOL WINAPI GetStringTypeW(DWORD dwInfoType, CicoPtr<LPCWSTR> lpSrcStr, int cchSrc, CicoPtr<LPWORD> lpCharType) {assert(0);}
BOOL WINAPI GetStringTypeA(LCID Locale, DWORD dwInfoType, CicoPtr<LPCSTR> lpSrcStr, int cchSrc, CicoPtr<LPWORD> lpCharType) {assert(0);}
int WINAPI MultiByteToWideChar(UINT CodePage, DWORD dwFlags, CicoPtr<LPCSTR> lpMultiByteStr, int cbMultiByte, CicoPtr<LPWSTR> lpWideCharStr, int cchWideChar) {assert(0);}
CicoPtr<HMODULE> WINAPI LoadLibraryA(CicoPtr<LPCSTR> lpLibFileName) {assert(0);}
UINT WINAPI GetOEMCP(void) {assert(0);}
UINT WINAPI GetACP(void) {assert(0);}
BOOL WINAPI GetCPInfo(UINT CodePage, CicoPtr<LPCPINFO> lpCPInfo) {assert(0);}
DWORD WINAPI SetFilePointer(CicoPtr<HANDLE> hFile, LONG lDistanceToMove, CicoPtr<PLONG> lpDistanceToMoveHigh, DWORD dwMoveMethod) {assert(0);}
DWORD WINAPI GetLastError(void) {assert(0);}
BOOL WINAPI WriteFile(CicoPtr<HANDLE> hFile, CicoPtr<LPCVOID> lpBuffer, DWORD nNumberOfBytesToWrite, CicoPtr<LPDWORD> lpNumberOfBytesWritten, CicoPtr<LPOVERLAPPED> lpOverlapped) {assert(0);}
void WINAPI RtlUnwind(CicoPtr<PVOID> TargetFrame, CicoPtr<PVOID> TzargetIp, CicoPtr<PEXCEPTION_RECORD> ExceptionRecord, CicoPtr<PVOID> ReturnValue) {assert(0);}
DWORD WINAPI GetFileType(CicoPtr<HANDLE> hFile) {
    if(hFile == 0xbb000002);
        return 2;
    if(hFile == 0xbb000003);
        return 2;
    if(hFile == 0xbb000004);
        return 2;
    assert(0);
    return 0;
}
CicoPtr<HANDLE> WINAPI GetStdHandle(DWORD nStdHandle) {
    if(nStdHandle == 0xfffffff6) // input
        return 0xbb000002;
    if(nStdHandle == 0xfffffff4) // stderr
        return 0xbb000004;
    if(nStdHandle == 0xfffffff5) // stderr
        return 0xbb000003;
    assert(0);
//    return 0;
}
UINT WINAPI SetHandleCount(UINT uNumber) { return uNumber; }
CicoPtr<LPWCH> WINAPI GetEnvironmentStringsW(void) {
    uint32_t envString = _alloc(32);
    return envString;
}
CicoPtr<LPCH> WINAPI GetEnvironmentStrings(void) {assert(0);}
int WINAPI WideCharToMultiByte(UINT CodePage, DWORD dwFlags, CicoPtr<LPCWSTR> lpWideCharStr, int cchWideChar, CicoPtr<LPSTR> lpMultiByteStr, int cbMultiByte, CicoPtr<LPCSTR> lpDefaultChar, CicoPtr<LPBOOL> lpUsedDefaultChar) {assert(0);}
BOOL WINAPI FreeEnvironmentStringsW(CicoPtr<LPWCH> penv) {assert(0);}
BOOL WINAPI FreeEnvironmentStringsA(CicoPtr<LPCH> penv) {assert(0);}
DWORD WINAPI GetModuleFileNameA(CicoPtr<HMODULE> hModule, CicoPtr<LPSTR> lpFilename, DWORD nSize) {
    char name[] = "C:\\TEMP\\GABO.EXE\0\0";
    memcpy(MemoryGetPtr(0, lpFilename), name, sizeof(name));
    return strlen(name);
}
LONG WINAPI UnhandledExceptionFilter(CicoPtr<struct _EXCEPTION_POINTERS *>ExceptionInfo) {assert(0);}
CicoPtr<FARPROC> WINAPI GetProcAddress(CicoPtr<HMODULE> hModule, LPCSTR lpProcName) {assert(0);}
SIZE_T WINAPI HeapSize(CicoPtr<HANDLE> hHeap, DWORD dwFlags, CicoPtr<LPCVOID> lpMem) {assert(0);}
CicoPtr<LPVOID> WINAPI HeapReAlloc(CicoPtr<HANDLE> hHeap, DWORD dwFlags, CicoPtr<LPVOID> lpMem, SIZE_T dwBytes) {assert(0);}
CicoPtr<LPVOID> WINAPI VirtualAlloc(CicoPtr<LPVOID> lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect) {
    uint32_t ptr = allocatorLast;
    allocatorLast += dwSize;
    printf("VirtualAlloc %d @ 0x%x\n", dwSize, ptr);
    return ptr;
}
BOOL WINAPI VirtualFree(CicoPtr<LPVOID> lpAddress, SIZE_T dwSize, DWORD dwFreeType) {assert(0);}
CicoPtr<HANDLE> WINAPI HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize) { return 0xaa000001; }
BOOL WINAPI HeapDestroy(CicoPtr<HANDLE> hHeap) {assert(0);}
DWORD WINAPI GetVersion(void) {return 0x0A280105;}
CicoPtr<LPSTR> WINAPI GetCommandLineA(void) {
    const char* cmd = "\"PROGRAM.EXE\"\0";

    uint32_t ptr = allocatorLast;
    allocatorLast += 32;
    memcpy(&allocator[allocatorLast-allocatorBase], cmd, sizeof(cmd));
    printf("GetCommandLineA %s @ 0x%x\n", cmd, ptr);
    return ptr;

    assert(0);
}
void WINAPI GetStartupInfoA(CicoPtr<LPSTARTUPINFOA> lpStartupInfo) {
    memoryASet16(0, lpStartupInfo+50, 1); // WORD   wShowWindow;        // SW_SHOW, SW_HIDE, etc.
//    memoryASet16(0, lpStartupInfo+52, 1);
}
CicoPtr<HMODULE> WINAPI GetModuleHandleA(CicoPtr<LPCSTR> lpModuleName) {
    return 0xcc000006;
//    assert(0);
}
CicoPtr<HANDLE> WINAPI GetCurrentProcess(void) {assert(0);}
BOOL WINAPI TerminateProcess(CicoPtr<HANDLE> hProcess, UINT uExitCode) {exit(1);}
void WINAPI ExitProcess(UINT uExitCode) {assert(0);}
BOOL WINAPI HeapFree(CicoPtr<HANDLE> hHeap, DWORD dwFlags, CicoPtr<LPVOID> lpMem) {
    printf("HeapFree h=0x%x p=0x%x\n", hHeap, lpMem);
    return 1;
}
CicoPtr<LPVOID> WINAPI HeapAlloc(CicoPtr<HANDLE> hHeap, DWORD dwFlags, SIZE_T dwBytes) {
    uint32_t ptr = allocatorLast;
    allocatorLast += dwBytes;
    printf("HeapAlloc %d @ 0x%x\n", dwBytes, ptr);
    return ptr;
}

#ifdef __cplusplus
}
#endif

#endif // KERNEL32_H
