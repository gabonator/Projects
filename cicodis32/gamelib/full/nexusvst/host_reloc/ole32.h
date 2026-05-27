// ole32.h — OLE32.dll stubs
namespace ole32 {
uint32_t OleInitialize() { esp += 4; return 0; }
uint32_t OleUninitialize() { return 0; }
uint32_t RevokeDragDrop() { esp += 4; return 0; }
uint32_t RegisterDragDrop() { esp += 8; return 0; }
uint32_t CoCreateInstance() { esp += 20; return 0x80004002; } // E_NOINTERFACE
} // namespace ole32
