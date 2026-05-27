// shell32.h — SHELL32.dll stubs
namespace shell32 {
uint32_t ShellExecuteExA() { esp += 4; return 0; }
uint32_t SHGetPathFromIDListA() { esp += 8; return 0; }
uint32_t SHGetSpecialFolderLocation() { esp += 12; return 0; }
uint32_t DragQueryFileA() { esp += 16; return 0; }
uint32_t SHGetMalloc() { esp += 4; return 0; }
} // namespace shell32
