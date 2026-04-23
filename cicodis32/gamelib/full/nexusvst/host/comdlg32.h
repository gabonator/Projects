// comdlg32.h — COMDLG32.dll stubs
namespace comdlg32 {
uint32_t GetSaveFileNameA() { esp += 4; return 0; }
uint32_t GetOpenFileNameA() { esp += 4; return 0; }
} // namespace comdlg32
