const kernel32 = {
  GetVersion: () => 0x0A280105,
  HeapCreate: () => 0xaa000001,
  HeapAlloc: (hHeap, dwFlags, dwBytes) => cico.alloc(dwBytes),
  VirtualAlloc: (lpAddress, dwSize, flAllocationType, flProtect) => cico.alloc(dwSize),
  GetStartupInfoA: (lpStartupInfo) => memoryASet16(0, lpStartupInfo+50, 1), // WORD wShowWindow = SW_SHOW, SW_HIDE, etc.
  SetHandleCount: (uNumber) => uNumber,
  GetCommandLineA: () => {
    let ptr = cico.alloc(32)
    cico.writeString(ptr, "\"PROGRAM.EXE\"\0")
    return ptr;
  },
  GetEnvironmentStringsW: () => cico.alloc(2),
  GetModuleHandleA: (lpModuleName) => 0xcc000006,
}