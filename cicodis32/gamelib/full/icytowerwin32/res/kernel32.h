// kernel32.h
// Windows KERNEL32.dll Function Declarations
// Generated from Import Address Table at 0x40d000

#ifndef KERNEL32_H
#define KERNEL32_H

#ifdef __cplusplus
extern "C" {
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
typedef unsigned __int64 SIZE_T;
typedef long LONG;
typedef LONG* PLONG;
typedef WORD* LPWORD;
typedef DWORD* LPDWORD;
typedef BOOL* LPBOOL;
typedef unsigned int LCID;
typedef void* FARPROC;

#define WINAPI __stdcall

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

BOOL WINAPI CloseHandle(HANDLE hObject);
BOOL WINAPI FlushFileBuffers(HANDLE hFile);
BOOL WINAPI SetStdHandle(DWORD nStdHandle, HANDLE hHandle);
int WINAPI LCMapStringW(LCID Locale, DWORD dwMapFlags, LPCWSTR lpSrcStr, int cchSrc, LPWSTR lpDestStr, int cchDest);
int WINAPI LCMapStringA(LCID Locale, DWORD dwMapFlags, LPCSTR lpSrcStr, int cchSrc, LPSTR lpDestStr, int cchDest);
BOOL WINAPI GetStringTypeW(DWORD dwInfoType, LPCWSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
BOOL WINAPI GetStringTypeA(LCID Locale, DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
int WINAPI MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
HMODULE WINAPI LoadLibraryA(LPCSTR lpLibFileName);
UINT WINAPI GetOEMCP(void);
UINT WINAPI GetACP(void);
BOOL WINAPI GetCPInfo(UINT CodePage, LPCPINFO lpCPInfo);
DWORD WINAPI SetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
DWORD WINAPI GetLastError(void);
BOOL WINAPI WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
void WINAPI RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue);
DWORD WINAPI GetFileType(HANDLE hFile);
HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
UINT WINAPI SetHandleCount(UINT uNumber);
LPWCH WINAPI GetEnvironmentStringsW(void);
LPCH WINAPI GetEnvironmentStrings(void);
int WINAPI WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cbMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar);
BOOL WINAPI FreeEnvironmentStringsW(LPWCH penv);
BOOL WINAPI FreeEnvironmentStringsA(LPCH penv);
DWORD WINAPI GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
LONG WINAPI UnhandledExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo);
FARPROC WINAPI GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
SIZE_T WINAPI HeapSize(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);
LPVOID WINAPI HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);
LPVOID WINAPI VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
BOOL WINAPI VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
HANDLE WINAPI HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
BOOL WINAPI HeapDestroy(HANDLE hHeap);
DWORD WINAPI GetVersion(void);
LPSTR WINAPI GetCommandLineA(void);
void WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
HANDLE WINAPI GetCurrentProcess(void);
BOOL WINAPI TerminateProcess(HANDLE hProcess, UINT uExitCode);
void WINAPI ExitProcess(UINT uExitCode);
BOOL WINAPI HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
LPVOID WINAPI HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);

#ifdef __cplusplus
}
#endif

#endif // KERNEL32_H
