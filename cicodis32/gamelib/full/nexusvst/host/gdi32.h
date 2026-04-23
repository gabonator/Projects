// gdi32.h — GDI32.dll stubs (all no-ops for headless VST)
namespace gdi32 {
uint32_t SelectObject() { esp += 8; return 0; }
uint32_t DeleteObject() { esp += 4; return 1; }
uint32_t CreateCompatibleDC() { esp += 4; return 0; }
uint32_t CreateDIBSection() { esp += 24; return 0; }
uint32_t SetStretchBltMode() { esp += 8; return 0; }
uint32_t StretchBlt() { esp += 44; return 1; }
uint32_t BitBlt() { esp += 36; return 1; }
uint32_t SetTextColor() { esp += 8; return 0; }
uint32_t SetBkColor() { esp += 8; return 0; }
uint32_t CreateFontIndirectA() { esp += 4; return 0; }
uint32_t CreateSolidBrush() { esp += 4; return 0; }
} // namespace gdi32
