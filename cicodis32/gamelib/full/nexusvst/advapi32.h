// advapi32.h — ADVAPI32.dll stubs (registry emulation)
#ifndef ADVAPI32_H
#define ADVAPI32_H

namespace advapi32 {

static uint32_t _regHandle = 0xAA000001;

static std::string readStr(uint32_t addr) {
    char buf[260] = {0};
    for (int i = 0; i < 259 && memoryAGet(ds, addr + i); i++) buf[i] = memoryAGet(ds, addr + i);
    return buf;
}

uint32_t RegOpenKeyExA() { // 5 args +20
    uint32_t hKey = memoryAGet32(ss, esp);
    uint32_t subKeyPtr = memoryAGet32(ss, esp + 4);
    uint32_t reserved = memoryAGet32(ss, esp + 8);
    uint32_t access = memoryAGet32(ss, esp + 12);
    uint32_t phkResult = memoryAGet32(ss, esp + 16);
    esp += 20;
    std::string subKey = subKeyPtr ? readStr(subKeyPtr) : "";
    printf("REG: RegOpenKeyExA(hKey=0x%x, subKeyPtr=0x%08x, \"%s\") -> handle 0x%x\n", hKey, subKeyPtr, subKey.c_str(), _regHandle);
    if (phkResult) memoryASet32(ds, phkResult, _regHandle++);
    return 0; // ERROR_SUCCESS
}

uint32_t RegQueryValueExA() { // 6 args +24
    uint32_t hKey = memoryAGet32(ss, esp);
    uint32_t namePtr = memoryAGet32(ss, esp + 4);
    uint32_t reserved = memoryAGet32(ss, esp + 8);
    uint32_t pType = memoryAGet32(ss, esp + 12);
    uint32_t pData = memoryAGet32(ss, esp + 16);
    uint32_t pcbData = memoryAGet32(ss, esp + 20);
    esp += 24;
    std::string name = namePtr ? readStr(namePtr) : "";
    printf("REG: RegQueryValueExA(0x%x, \"%s\", data=0x%08x)\n", hKey, name.c_str(), pData);
    // Serve content path for known keys
    if (name.find("Content") != std::string::npos || name.find("content") != std::string::npos ||
        name.find("Path") != std::string::npos || name.find("path") != std::string::npos ||
        name.find("Dir") != std::string::npos) {
        const char* val = "C:/Nexus Content/";
        uint32_t len = (uint32_t)strlen(val) + 1;
        if (pData) {
            for (uint32_t i = 0; i < len; i++) memoryASet(ds, pData + i, val[i]);
            printf("  -> served: \"%s\"\n", val);
        }
        if (pcbData) memoryASet32(ds, pcbData, len);
        if (pType) memoryASet32(ds, pType, 1); // REG_SZ
        return 0;
    }
    // Unknown key — return empty/zero
    if (pData && pcbData) {
        uint32_t sz = memoryAGet32(ds, pcbData);
        if (sz > 0) memoryASet(ds, pData, 0);
    }
    if (pType) memoryASet32(ds, pType, 4); // REG_DWORD
    return 0; // pretend success with empty data
}

uint32_t RegCreateKeyExA() { // 9 args +36
    uint32_t subKeyPtr = memoryAGet32(ss, esp + 4);
    uint32_t phkResult = memoryAGet32(ss, esp + 28);
    esp += 36;
    std::string subKey = subKeyPtr ? readStr(subKeyPtr) : "";
    printf("REG: RegCreateKeyExA(\"%s\")\n", subKey.c_str());
    if (phkResult) memoryASet32(ds, phkResult, _regHandle++);
    return 0;
}

uint32_t RegSetValueExA() { // 6 args +24
    uint32_t namePtr = memoryAGet32(ss, esp + 4);
    esp += 24;
    std::string name = namePtr ? readStr(namePtr) : "";
    printf("REG: RegSetValueExA(\"%s\")\n", name.c_str());
    return 0;
}

uint32_t RegCloseKey() { esp += 4; return 0; }
uint32_t RegFlushKey() { esp += 4; return 0; }

} // namespace advapi32
#endif
