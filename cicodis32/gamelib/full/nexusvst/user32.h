// user32.h — USER32.dll stubs (all no-ops for headless VST)
#ifndef USER32_H
#define USER32_H
namespace user32 {
uint32_t GetWindowRect() { esp += 8; return 1; }
uint32_t UnregisterClassA() { esp += 8; return 1; }
uint32_t SetCapture() { esp += 4; return 0; }
uint32_t DefWindowProcA() { esp += 16; return 0; }
uint32_t ReleaseDC() { esp += 8; return 1; }
uint32_t EndPaint() { esp += 8; return 1; }
uint32_t BeginPaint() { esp += 8; return 0; }
uint32_t GetUpdateRect() { esp += 12; return 0; }
uint32_t GetWindowLongA() { esp += 8; return 0; }
uint32_t RegisterClassA() { esp += 4; return 0; }
uint32_t GetSysColorBrush() { esp += 4; return 0; }
uint32_t DestroyWindow() { esp += 4; return 1; }
uint32_t CreateWindowExA() { esp += 48; return 0; }
uint32_t GetDoubleClickTime() { return 500; }
uint32_t GetAsyncKeyState() { esp += 4; return 0; }
uint32_t GetCursor() { return 0; }
uint32_t SetFocus() { esp += 4; return 0; }
uint32_t DestroyMenu() { esp += 4; return 1; }
uint32_t AppendMenuA() { esp += 16; return 1; }
uint32_t CreatePopupMenu() { return 0; }
uint32_t PeekMessageA() { esp += 20; return 0; }
uint32_t TrackPopupMenu() { esp += 28; return 0; }
uint32_t SetWindowTextA() { esp += 8; return 1; }
uint32_t GetWindowTextA() { esp += 12; return 0; }
uint32_t GetParent() { esp += 4; return 0; }
uint32_t SendMessageA() { esp += 16; return 0; }
uint32_t CallWindowProcA() { esp += 20; return 0; }
uint32_t PostMessageA() { esp += 16; return 1; }
uint32_t SetTimer() { esp += 16; return 1; }
uint32_t KillTimer() { esp += 8; return 1; }
uint32_t MessageBoxW() { esp += 16; return 0; }
uint32_t GetSystemMetrics() { esp += 4; return 0; }
uint32_t SetCursor() { esp += 4; return 0; }
uint32_t LoadCursorA() { esp += 8; return 0; }
uint32_t GetDC() { esp += 4; return 0; }
uint32_t GetDlgItem() { esp += 8; return 0; }
uint32_t GetCursorPos() { esp += 4; return 0; }
uint32_t SetWindowLongA() { esp += 12; return 0; }
uint32_t MessageBoxA() { esp += 16; return 0; }
} // namespace user32
#endif
