// kernel32.h — Windows KERNEL32.dll stubs for Nexus emulator
// All functions are parameterless — they read args from emulated stack (esp)
// Stdcall convention: callee pops args by adjusting esp

#include <dirent.h>
#include <sys/stat.h>
#ifndef KERNEL32_H
#define KERNEL32_H

// memory access via memoryASet/memoryAGet (defined in cico32.h)

namespace kernel32 {

// Helper to read string from emulated memory
static std::string readString(uint32_t addr) {
    std::string s;
    for (int i = 0; i < 1024; i++) {
        char c = (char)memoryAGet(ds, addr + i);
        if (!c) break;
        s += c;
    }
    return s;
}

// --- File I/O ---
// Simple file handle table
static struct FileSlot {
    bool opened = false;
    FILE* fp = nullptr;
    uint32_t size = 0;
} fileSlots[64];

static int nextHandle = 0x100;

static const char* VFS_SANDBOX = "/Users/gabrielvalky/Documents/git/CleanRoom/jsfun4/installer/";
static std::string vfsTranslate(const std::string& winPath) {
    std::string p = winPath;
    for (auto& c : p) if (c == '\\') c = '/';
    // Strip drive prefix and map to sandbox
    size_t start = 0;
    if (p.size() > 2 && p[1] == ':') start = 2;  // "C:/" → skip "C:"
    while (start < p.size() && p[start] == '/') start++; // skip leading slashes
    p = std::string(VFS_SANDBOX) + p.substr(start);
    // Remove trailing wildcard pattern
    auto star = p.rfind('*');
    if (star != std::string::npos) {
        auto lastSlash = p.rfind('/', star);
        if (lastSlash != std::string::npos) p = p.substr(0, lastSlash);
    }
    // Sandbox enforcement
    if (p.find(VFS_SANDBOX) != 0) return "";
    return p;
}

uint32_t CreateFileA() { // 7 args, stdcall +28
    uint32_t namePtr = memoryAGet32(ss, esp);
    uint32_t access = memoryAGet32(ss, esp + 4);
    uint32_t share = memoryAGet32(ss, esp + 8);
    uint32_t secAttr = memoryAGet32(ss, esp + 12);
    uint32_t creation = memoryAGet32(ss, esp + 16);
    uint32_t flagsAttr = memoryAGet32(ss, esp + 20);
    uint32_t hTemplate = memoryAGet32(ss, esp + 24);
    esp += 28;

    std::string name = readString(namePtr);
    // Convert backslashes
    for (auto& c : name) if (c == '\\') c = '/';
    // Match Windows: these files don't exist on the test system
    if (name.find("!Info.ned") != std::string::npos ||
        name.find(".nsk") != std::string::npos) {
        printf("CreateFileA BLOCKED (match Windows): %s\n", name.c_str());
        return 0xffffffff;
    }

    // Map Windows paths to local res/ directory
    std::string localPath;
    // Check if it's a SYNSOEMU or content path
    if (name.find("SYNSOEMU") != std::string::npos ||
        name.find("synsoemu") != std::string::npos) {
        localPath = std::string(appRootPath) + "SYNSOEMU.DLL";
    } else {
        // Try to find the file relative to res/
        size_t lastSlash = name.rfind('/');
        std::string basename = (lastSlash != std::string::npos) ? name.substr(lastSlash + 1) : name;
        localPath = std::string(appRootPath) + basename;
    }

    FILE* fp = fopen(localPath.c_str(), "rb");
    if (!fp) {
        // Try VFS-translated path
        std::string vfsPath = vfsTranslate(name);
        fp = fopen(vfsPath.c_str(), "rb");
    }
    if (!fp) {
        // Try the original path directly
        fp = fopen(name.c_str(), "rb");
    }
    if (!fp) {
        printf("CreateFileA FAIL: %s (tried %s)\n", name.c_str(), localPath.c_str());
        return 0xffffffff; // INVALID_HANDLE_VALUE
    }

    fseek(fp, 0, SEEK_END);
    uint32_t sz = (uint32_t)ftell(fp);
    rewind(fp);

    int handle = nextHandle++;
    int slot = handle - 0x100;
    if (slot >= 0 && slot < 64) {
        fileSlots[slot].opened = true;
        fileSlots[slot].fp = fp;
        fileSlots[slot].size = sz;
    }
    printf("CreateFileA: '%s' (namePtr=0x%08x) -> handle 0x%x (%u bytes)\n", name.c_str(), namePtr, handle, sz);
    return handle;
}

uint32_t ReadFile() { // 5 args, stdcall +20
    uint32_t hFile = memoryAGet32(ss, esp);
    uint32_t bufPtr = memoryAGet32(ss, esp + 4);
    uint32_t nBytes = memoryAGet32(ss, esp + 8);
    uint32_t pBytesRead = memoryAGet32(ss, esp + 12);
    uint32_t pOverlapped = memoryAGet32(ss, esp + 16);
    esp += 20;

    int slot = hFile - 0x100;
    if (slot < 0 || slot >= 64 || !fileSlots[slot].opened) {
        if (pBytesRead) memoryASet32(ds, pBytesRead, 0);
        return 0;
    }

    // Read into temp buffer then copy to emulated memory
    printf("ReadFile: h=0x%x buf=0x%08x sz=%u\n", hFile, bufPtr, nBytes);
    std::vector<uint8_t> buf(nBytes);
    size_t nRead = fread(buf.data(), 1, nBytes, fileSlots[slot].fp);
    for (size_t i = 0; i < nRead; i++)
        memoryASet(ds, bufPtr + i, buf[i]);

    if (pBytesRead) memoryASet32(ds, pBytesRead, (uint32_t)nRead);
    return 1;
}

uint32_t WriteFile() { esp += 20; return 1; } // stub
uint32_t CloseHandle() {
    uint32_t h = memoryAGet32(ss, esp); esp += 4;
    int slot = h - 0x100;
    if (slot >= 0 && slot < 64 && fileSlots[slot].opened) {
        fclose(fileSlots[slot].fp);
        fileSlots[slot].opened = false;
        fileSlots[slot].fp = nullptr;
    }
    return 1;
}

uint32_t SetFilePointer() { // 4 args +16
    uint32_t hFile = memoryAGet32(ss, esp);
    int32_t dist = (int32_t)memoryAGet32(ss, esp + 4);
    uint32_t pHigh = memoryAGet32(ss, esp + 8);
    uint32_t method = memoryAGet32(ss, esp + 12);
    esp += 16;

    int slot = hFile - 0x100;
    if (slot < 0 || slot >= 64 || !fileSlots[slot].opened) return 0xffffffff;

    int whence = (method == 0) ? SEEK_SET : (method == 1) ? SEEK_CUR : SEEK_END;
    fseek(fileSlots[slot].fp, dist, whence);
    return (uint32_t)ftell(fileSlots[slot].fp);
}

uint32_t GetFileSize() { // 2 args +8
    uint32_t hFile = memoryAGet32(ss, esp);
    uint32_t pHigh = memoryAGet32(ss, esp + 4);
    esp += 8;
    int slot = hFile - 0x100;
    if (slot < 0 || slot >= 64 || !fileSlots[slot].opened) return 0xffffffff;
    if (pHigh) memoryASet32(ds, pHigh, 0);
    return fileSlots[slot].size;
}

// --- Heap/Memory ---
uint32_t HeapAlloc() { // 3 args +12
    uint32_t hHeap = memoryAGet32(ss, esp);
    uint32_t flags = memoryAGet32(ss, esp + 4);
    uint32_t size = memoryAGet32(ss, esp + 8);
    esp += 12;
    return allocate(size);
}

uint32_t HeapFree() { esp += 12; return 1; } // stub — no real free

uint32_t HeapReAlloc() { // 4 args +16
    uint32_t hHeap = memoryAGet32(ss, esp);
    uint32_t flags = memoryAGet32(ss, esp + 4);
    uint32_t oldPtr = memoryAGet32(ss, esp + 8);
    uint32_t size = memoryAGet32(ss, esp + 12);
    esp += 16;
    return allocate(size);
}

uint32_t VirtualAlloc() { // 4 args +16
    uint32_t addr = memoryAGet32(ss, esp);
    uint32_t size = memoryAGet32(ss, esp + 4);
    uint32_t type = memoryAGet32(ss, esp + 8);
    uint32_t protect = memoryAGet32(ss, esp + 12);
    esp += 16;
    // Align to 4KB
    int ptr = allocatorPtr;
    ptr = (ptr + 0xfff) & ~0xfff;
    allocatorPtr = ptr + size;
    // Zero-init byte by byte through memoryASet for watchpoint coverage
    for (uint32_t i = 0; i < size; i++)
        memoryASet(0, ptr + i, 0);
    return ptr;
}

uint32_t VirtualFree() { esp += 12; return 1; }
uint32_t HeapCreate() { esp += 12; return 0x10000002; }
uint32_t HeapDestroy() { esp += 4; return 1; }
uint32_t GetProcessHeap() { return 0x10000003; }
uint32_t HeapSize() { esp += 12; return 0; }
uint32_t GlobalAlloc() { esp += 8; return allocate(256); }
uint32_t GlobalLock() { uint32_t p = memoryAGet32(ss, esp); esp += 4; return p; }
uint32_t GlobalUnlock() { esp += 4; return 1; }
uint32_t GlobalFree() { esp += 4; return 0; }
uint32_t GlobalSize() { esp += 4; return 0; }

// --- Threading (single-threaded stubs) ---
uint32_t CreateThread() { // 6 args +24
    uint32_t sec = memoryAGet32(ss, esp);
    uint32_t stackSize = memoryAGet32(ss, esp + 4);
    uint32_t startAddr = memoryAGet32(ss, esp + 8);
    uint32_t param = memoryAGet32(ss, esp + 12);
    uint32_t createFlags = memoryAGet32(ss, esp + 16);
    uint32_t tidPtr = memoryAGet32(ss, esp + 20);
    esp += 24;
    // Execute synchronously
    printf("CreateThread: start=0x%08x param=0x%08x\n", startAddr, param);
    push32(param);
    indirectCall(cs, startAddr);
    if (tidPtr) memoryASet32(ds, tidPtr, 2);
    return 0x6ab60001; // fake thread handle
}

uint32_t SetThreadPriority() { esp += 8; return 1; }
uint32_t WaitForSingleObject() { esp += 8; return 0; } // WAIT_OBJECT_0
uint32_t TerminateThread() { esp += 8; return 1; }
uint32_t GetCurrentThreadId() { return 1; }
uint32_t GetCurrentProcessId() { return 1; }

// --- Synchronization ---
uint32_t InitializeCriticalSection() { esp += 4; return 0; }
uint32_t InitializeCriticalSectionAndSpinCount() { esp += 8; return 1; }
uint32_t EnterCriticalSection() { esp += 4; return 0; }
uint32_t LeaveCriticalSection() { esp += 4; return 0; }
uint32_t DeleteCriticalSection() { esp += 4; return 0; }
uint32_t InterlockedExchange() { esp += 8; return 0; }
uint32_t InterlockedCompareExchange() { esp += 12; return 0; }
uint32_t InterlockedIncrement() {
    uint32_t ptr = memoryAGet32(ss, esp); esp += 4;
    uint32_t val = memoryAGet32(ds, ptr) + 1;
    memoryASet32(ds, ptr, val);
    return val;
}
uint32_t InterlockedDecrement() {
    uint32_t ptr = memoryAGet32(ss, esp); esp += 4;
    uint32_t val = memoryAGet32(ds, ptr) - 1;
    memoryASet32(ds, ptr, val);
    return val;
}

// --- Events ---
static uint32_t nextEvent = 0x6ab70001;
uint32_t CreateEventA() { esp += 16; return nextEvent++; }
uint32_t SetEvent() { esp += 4; return 1; }

// --- Perf counter ---
uint32_t QueryPerformanceFrequency() {
    uint32_t p = memoryAGet32(ss, esp); esp += 4;
    memoryASet32(ds, p, 1000000); memoryASet32(ds, p + 4, 0);
    return 1;
}
uint32_t QueryPerformanceCounter() {
    uint32_t p = memoryAGet32(ss, esp); esp += 4;
    static uint64_t counter = 0;
    counter += 1000;
    memoryASet32(ds, p, (uint32_t)counter); memoryASet32(ds, p + 4, (uint32_t)(counter >> 32));
    return 1;
}

// --- Module/process ---
uint32_t GetModuleHandleA() { esp += 4; return 0x10000001; }
uint32_t GetModuleHandleW() { esp += 4; return 0; }
uint32_t GetModuleFileNameA() {
    // IAT 0x100e60a4 is actually lstrcpynA(src, dst, maxlen), NOT GetModuleFileNameA
    uint32_t src = memoryAGet32(ss, esp);
    uint32_t dst = memoryAGet32(ss, esp + 4);
    uint32_t maxLen = memoryAGet32(ss, esp + 8);
    esp += 12;
    if (src < 0x10000000 || dst < 0x10000000) return dst;
    uint32_t i;
    for (i = 0; i < maxLen - 1; i++) {
        uint8_t c = memoryAGet(ds, src + i);
        memoryASet(ds, dst + i, c);
        if (!c) break;
    }
    if (i == maxLen - 1) memoryASet(ds, dst + i, 0);
    return dst;
}
uint32_t LoadLibraryA() {
    uint32_t namePtr = memoryAGet32(ss, esp); esp += 4;
    std::string name = readString(namePtr);
    printf("LoadLibraryA: %s\n", name.c_str());
    if (name.find("SYNSOEMU") != std::string::npos)
        return 0x11000000; // SYNSOEMU base address in our memory layout
    return 0x10000004; // fake module handle for other DLLs
}
uint32_t GetProcAddress() {
    uint32_t hModule = memoryAGet32(ss, esp);
    uint32_t namePtr = memoryAGet32(ss, esp + 4);
    esp += 8;

    // Check if ordinal (< 0x10000) or name pointer
    if (namePtr < 0x10000) {
        // SYNSOEMU ordinal exports — return real SYNSOEMU function addresses
        // Parsed from SYNSOEMU.DLL export table
        static const uint32_t synsoOrdinals[29] = {
            0,           // ordinal 0: unused
            0x110018fa,  // ord 1
            0x110018fa,  // ord 2 (posInstantiateObject thunk)
            0x11001582,  // ord 3 (posInstantiateObject)
            0x110015fc,  // ord 4 (posCallMethod)
            0x110015ed,  // ord 5
            0x110015a2,  // ord 6 (posDeleteObject)
            0x110018fa,  // ord 7
            0x110018fa,  // ord 8
            0x110018fa,  // ord 9
            0x110018fa,  // ord 10
            0x110018fa,  // ord 11
            0x110018fa,  // ord 12
            0x110018fa,  // ord 13
            0x110018fa,  // ord 14
            0x110018fa,  // ord 15
            0x110015de,  // ord 16
            0x11001531,  // ord 17 (posRegisterApplicationWithClasses)
            0x110015b7,  // ord 18 (posGetInfoWithCommand)
            0x110018fa,  // ord 19
            0x110018fa,  // ord 20
            0x110018fa,  // ord 21
            0x110018fa,  // ord 22
            0x110018fa,  // ord 23
            0x110018fa,  // ord 24
            0x110018fa,  // ord 25
            0x110018bb,  // ord 26 (posDCPCreateEncryptionContext)
            0x110018e5,  // ord 27 (posDCPEncryptData)
            0x110018d0,  // ord 28
        };
        if (namePtr >= 1 && namePtr <= 28) {
            printf("GetProcAddress(0x%08x, ordinal %d) -> 0x%08x\n", hModule, namePtr, synsoOrdinals[namePtr]);
            return synsoOrdinals[namePtr];
        }
        printf("GetProcAddress(0x%08x, ordinal %d) -> 0\n", hModule, namePtr);
        return 0;
    }

    std::string name = readString(namePtr);
    printf("GetProcAddress(0x%08x, \"%s\")\n", hModule, name.c_str());
    // SYNSOEMU name exports
    if (name == "posRegisterApplicationWithClasses") return 0x77779001;
    if (name == "posInstantiateObject") return 0x77779002;
    if (name == "posCallMethod") return 0x77779003;
    if (name == "posDCPDecryptData") return 0x77779004;
    return 0;
}
uint32_t GetCurrentProcess() { return 0xffffffff; }
uint32_t TerminateProcess() {
    uint32_t hProc = memoryAGet32(ss, esp); uint32_t exitCode = memoryAGet32(ss, esp+4);
    esp += 8;
    printf("TerminateProcess(0x%x, 0x%x)\n", hProc, exitCode);
    abort();
    return 1;
}
uint32_t ExitProcess() { esp += 4; printf("ExitProcess\n"); return 0; }

// --- Error handling ---
uint32_t GetLastError() { return 0; }
uint32_t SetLastError() { esp += 4; return 0; }
uint32_t RaiseException() { esp += 16; return 0; } // silent — CRT uses this
uint32_t RtlUnwind() { esp += 16; return 0; }
uint32_t SetUnhandledExceptionFilter() { esp += 4; return 0; }
uint32_t UnhandledExceptionFilter() { esp += 4; return 0; }
uint32_t IsDebuggerPresent() { return 0; }

// --- Time ---
uint32_t GetTickCount() {
    static uint32_t tick = 470000000; // ~5.4 days, realistic Windows uptime
    return tick += 16;
}
uint32_t GetSystemTimeAsFileTime() { esp += 4; return 0; }
uint32_t Sleep() { esp += 4; return 0; }

// --- Locale/codepage ---
uint32_t GetACP() { return 1252; }
uint32_t GetOEMCP() { return 437; }
uint32_t IsValidCodePage() { esp += 4; return 1; }
uint32_t GetCPInfo() { esp += 8; return 1; }
uint32_t GetLocaleInfoA() { esp += 16; return 0; }
uint32_t GetStringTypeA() { esp += 20; return 0; }
uint32_t GetStringTypeW() { esp += 16; return 0; }
uint32_t LCMapStringA() { esp += 24; return 0; }
uint32_t LCMapStringW() { esp += 24; return 0; }
uint32_t MultiByteToWideChar() { esp += 24; return 0; }
uint32_t WideCharToMultiByte() { esp += 32; return 0; }

// --- Console/stdio ---
uint32_t GetStdHandle() { esp += 4; return 0; }
uint32_t SetHandleCount() { esp += 4; return 0; }
uint32_t GetFileType() { esp += 4; return 0; }
uint32_t GetConsoleCP() { return 0; }
uint32_t GetConsoleMode() { esp += 8; return 0; }
uint32_t GetConsoleOutputCP() { return 0; }
uint32_t FlushFileBuffers() { esp += 4; return 1; }
uint32_t SetStdHandle() { esp += 8; return 1; }
uint32_t WriteConsoleA() { esp += 20; return 1; }
uint32_t WriteConsoleW() { esp += 20; return 1; }
uint32_t SetEndOfFile() { esp += 4; return 1; }

// --- Startup ---
uint32_t GetCommandLineA() { return 0; }
uint32_t GetStartupInfoA() { esp += 4; return 0; }

// --- Environment ---
uint32_t GetEnvironmentStrings() { return 0; }
uint32_t GetEnvironmentStringsW() { return 0; }
uint32_t FreeEnvironmentStringsA() { esp += 4; return 1; }
uint32_t FreeEnvironmentStringsW() { esp += 4; return 1; }

// --- File attributes/search ---
uint32_t GetFileAttributesA() {
    uint32_t namePtr = memoryAGet32(ss, esp); esp += 4;
    std::string name = readString(namePtr);
    for (auto& c : name) if (c == '\\') c = '/';
    // Check if file exists
    FILE* f = fopen(name.c_str(), "rb");
    if (f) { fclose(f); return 0x20; } // FILE_ATTRIBUTE_ARCHIVE
    // Try in res/
    size_t ls = name.rfind('/');
    std::string bn = (ls != std::string::npos) ? name.substr(ls + 1) : name;
    std::string localPath = std::string(appRootPath) + bn;
    f = fopen(localPath.c_str(), "rb");
    if (f) { fclose(f); return 0x20; }
    return 0xffffffff; // INVALID_FILE_ATTRIBUTES
}

// --- VFS: FindFirstFileA / FindNextFileA ---
static void scanDirRecursive(const std::string& base, const std::string& rel, std::vector<std::pair<std::string,bool>>& out) {
    DIR* d = opendir(base.c_str());
    if (!d) return;
    struct dirent* ent;
    while ((ent = readdir(d)) != nullptr) {
        if (ent->d_name[0] == '.') continue;
        std::string full = base + "/" + ent->d_name;
        std::string rpath = rel.empty() ? ent->d_name : rel + "/" + ent->d_name;
        struct stat st; stat(full.c_str(), &st);
        out.push_back({rpath, S_ISDIR(st.st_mode)});
        if (S_ISDIR(st.st_mode)) scanDirRecursive(full, rpath, out);
    }
    closedir(d);
}

struct FindHandle {
    std::vector<std::pair<std::string,bool>> files; // {name, isDir}
    std::string dir;
    int index;
    bool active;
};
static FindHandle findHandles[16];
static int nextFindHandle = 0x200;

uint32_t FindFirstFileA() {
    uint32_t fnPtr = memoryAGet32(ss, esp);
    uint32_t dataPtr = memoryAGet32(ss, esp + 4);
    esp += 8;
    std::string pattern = readString(fnPtr);
    std::string realDir = vfsTranslate(pattern);
    printf("FindFirstFileA: \"%s\" -> \"%s\"\n", pattern.c_str(), realDir.c_str());
    if (realDir.empty()) return 0xffffffff;
    // Match Windows: Skins directory is empty (no .nsk files) — skip skin scanning
    if (pattern.find("Skins") != std::string::npos) {
        printf("  -> Skins dir: returning empty (matches Windows)\n");
        return 0xffffffff;
    }

    int slot = (nextFindHandle - 0x200) % 16;
    findHandles[slot] = {{}, realDir, 0, true};
    // Single-level scan (like Windows FindFirstFileA — caller handles recursion)
    { DIR* d = opendir(realDir.c_str());
      if (d) {
          struct dirent* ent;
          while ((ent = readdir(d)) != nullptr) {
              if (ent->d_name[0] == '.') continue;
              std::string full = realDir + "/" + ent->d_name;
              struct stat st; memset(&st, 0, sizeof(st)); stat(full.c_str(), &st);
              findHandles[slot].files.push_back({ent->d_name, S_ISDIR(st.st_mode)});
          }
          closedir(d);
      }
    }

    if (findHandles[slot].files.empty()) { findHandles[slot].active = false; return 0xffffffff; }

    auto& fh = findHandles[slot];
    auto& [name, isDir] = fh.files[0];
    std::string fullPath = fh.dir + "/" + name;
    struct stat st; memset(&st, 0, sizeof(st)); stat(fullPath.c_str(), &st);
    memoryASet32(ds, dataPtr + 0, isDir ? 0x10 : 0x80);
    memoryASet32(ds, dataPtr + 28, 0);
    memoryASet32(ds, dataPtr + 32, (uint32_t)st.st_size);
    for (int i = 0; i < 260; i++) memoryASet(ds, dataPtr + 44 + i, 0);
    for (size_t i = 0; i < name.size() && i < 259; i++)
        memoryASet(ds, dataPtr + 44 + i, name[i]);

    uint32_t h = nextFindHandle++;
    printf("  -> handle=0x%x first=\"%s\" total=%zu\n", h, name.c_str(), fh.files.size());
    return h;
}

uint32_t FindNextFileA() {
    uint32_t hFind = memoryAGet32(ss, esp);
    uint32_t dataPtr = memoryAGet32(ss, esp + 4);
    esp += 8;
    int slot = (hFind - 0x200) % 16;
    if (slot < 0 || slot >= 16 || !findHandles[slot].active) return 0;

    auto& fh = findHandles[slot];
    fh.index++;
    if (fh.index >= (int)fh.files.size()) return 0;

    auto& [name, isDir] = fh.files[fh.index];
    std::string fullPath = fh.dir + "/" + name;
    struct stat st; memset(&st, 0, sizeof(st)); stat(fullPath.c_str(), &st);
    memoryASet32(ds, dataPtr + 0, isDir ? 0x10 : 0x80);
    memoryASet32(ds, dataPtr + 28, 0);
    memoryASet32(ds, dataPtr + 32, (uint32_t)st.st_size);
    for (int i = 0; i < 260; i++) memoryASet(ds, dataPtr + 44 + i, 0);
    for (size_t i = 0; i < name.size() && i < 259; i++)
        memoryASet(ds, dataPtr + 44 + i, name[i]);
    return 1;
}
uint32_t FindClose() {
    uint32_t hFind = memoryAGet32(ss, esp); esp += 4;
    int slot = (hFind - 0x200) % 16;
    if (slot >= 0 && slot < 16) findHandles[slot].active = false;
    return 1;
}

// --- Disk ---
uint32_t GetLogicalDrives() { return 0; }
uint32_t GetDiskFreeSpaceExA() { esp += 16; return 0; }
uint32_t GetVolumeInformationA() { esp += 32; return 0; }
uint32_t SetErrorMode() { esp += 4; return 0; }
uint32_t GetDriveTypeA() { esp += 4; return 0; }

// --- File ops ---
uint32_t DeleteFileA() { esp += 4; return 1; }
uint32_t CreateDirectoryA() { esp += 8; return 1; }
uint32_t MoveFileA() { esp += 8; return 1; }
uint32_t RemoveDirectoryA() { esp += 4; return 1; }

// --- TLS ---
uint32_t TlsAlloc() { return 1; }
uint32_t TlsGetValue() { esp += 4; return 0; }
uint32_t TlsSetValue() { esp += 8; return 1; }
uint32_t TlsFree() { esp += 4; return 1; }

} // namespace kernel32

#endif // KERNEL32_H
