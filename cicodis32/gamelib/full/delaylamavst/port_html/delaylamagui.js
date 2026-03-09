// delaylamagui.js — Delay Lama GUI rendering analysis
// ─────────────────────────────────────────────────────────
// This file documents the Win32 GDI rendering pipeline found by analysing
// the calls to GetObjectA at 10007e69, 10008007, 100085d0.
// The actual browser GUI is implemented with CSS sprites in index.html.

// ── Bitmap resources (Win32 resource IDs from rsrc section) ──────────────
// 130  bitmap_130_1043.png   360×510   Full GUI background
// 131  bitmap_131_1043.png  1570×1866  Face animation sprite map  5 cols × 6 rows = 30 frames, each 314×311
// 141  bitmap_141_1043.png    10×10    Arrow-right  (Y-axis pad indicator)
// 142  bitmap_142_1043.png    10×10    Arrow-down   (X-axis pad indicator)
// 151  bitmap_151_1043.png    20×17    Arrow-down large (slider handle)
// 152  bitmap_152_1043.png    50×3000  Rotary knob sprite  1 col × 30 rows, each 50×100
// 153  bitmap_153_1043.png    50×3000  Rotary knob highlight sprite  (same layout)
// 160  bitmap_160_1043.png   253×275   About screen

// ── Win32 rendering pipeline ──────────────────────────────────────────────
//
// sub_10007e20(ecx=&BitmapResource, arg=resource_id)          +stackDrop4
//   BitmapResource ctor. Calls LoadBitmapA(hInstance, id) then
//   GetObjectA(hBitmap, 24, &BITMAP) to fill width/height.
//   BitmapResource layout:
//     +0x00  resource_id
//     +0x04  1 (loaded flag)
//     +0x08  bmWidth
//     +0x0c  bmHeight
//     +0x10  HBITMAP
//     +0x14  HDC  (lazy-created, zero until first use)
//
// sub_10007f00(ecx=BitmapCtrl, arg1=WinObj, arg2=destRect, arg3=srcOfs) +stackDrop12
//   Static blit (plain SRCCOPY). Used when widget[+0x32] == 0.
//   Single BitBlt: source region (srcOfs.x, srcOfs.y, destRect.w, destRect.h)
//   → dest window DC at (WinObj.x + destRect.x, WinObj.y + destRect.y).
//   Returns early if BitmapCtrl[+0x10] (hBitmap) is NULL.
//
// sub_10007f90(ecx=BitmapCtrl, arg1=WinObj, arg2=destRect, arg3=srcOfs) +stackDrop12
//   Transparent/animated blit. Used when widget[+0x32] == 1.
//   Win32 mask-composite technique (no alpha channel):
//     1. CreateCompatibleDC + SelectObject (hBitmap)
//     2. GetObjectA → bitmap dimensions                ← GetObjectA at 10008007
//     3. CreateCompatibleBitmap  (dest-size work bitmap)
//     4. CreateCompatibleDC × 2  (work DCs)
//     5. BitBlt SRCCOPY   src → workDC1
//     6. BitBlt SRCCOPY   src → workDC2
//     7. BitBlt 0x008800c6 (SRCAND)   workDC2 → dest  (black out sprite area)
//     8. BitBlt 0x00ee0086 (MERGEPAINT) → dest         (paint sprite pixels)
//     9. Cleanup (DeleteObject, DeleteDC)
//   The SRCAND + MERGEPAINT pair implements colour-key transparency:
//   the source bitmap was drawn with the sprite against a black mask so that
//   non-sprite pixels stay black after SRCAND and the colour is OR'd in by MERGEPAINT.
//
// sub_100085a0(arg1=parentDC, arg2=hBitmap, arg3=bgColour)
//   Background fill. Called from sub_10007f90 when HDC cache is cold.
//   Creates compatible DC, selects hBitmap, GetObjectA dims  ← GetObjectA at 100085d0
//   Creates 1×1 solid colour bitmap, SetBkColor, BitBlt SRCCOPY to fill region.
//
// sub_10008fe0(ecx=Widget, arg1=HWND/HDC)                      +stackDrop4
//   Vtable render dispatcher (vtable PTR_FUN_1000bd78 → FUN_10008fe0).
//   if Widget[+0x54]==NULL: skip
//   if Widget[+0x32]!=0:  sub_10007f90(Widget[+0x54], arg1, Widget+8, Widget+88)
//   else:                  sub_10007f00(Widget[+0x54], arg1, Widget+8, Widget+88)
//   Then chains to vtable[+0xa0](arg1) and vtable[+0x24](0).
//
// sub_1000a5d0(ecx=Widget, arg1=HWND/HDC)                      +stackDrop4
//   Vtable render dispatcher (vtable PTR_FUN_1000c154 → FUN_1000a5d0).
//   Identical to sub_10008fe0 but also checks Widget[+0x44] (float) against 0.0:
//   if Widget[+0x44] == 0.0: skip entirely (used during silence).
//   Sprite alt frame: passes Widget+88 and Widget+120 instead of Widget+8/Widget+88.
//
// ── GUI widget memory layout (object at 'esi' in the dispatch functions) ──
//   +0x00  vtable ptr
//   +0x08  RECT destRect  {left, top, right, bottom}  — dest window region
//   +0x32  BYTE  animation flag  0=static, 1=animated+transparent
//   +0x44  float animation value; 0.0 → skip render (sub_1000a5d0 only)
//   +0x54  ptr → BitmapControl  (source bitmap + lazy HDC)
//   +0x58  sprite sub-region descriptor A  (srcX,srcY for frame selection)
//   +0x88 (=136) sprite descriptor B       (arg3 to f90/f00 from sub_10008fe0)
//   +0x78 (=120) sprite descriptor C       (alt frame, sub_1000a5d0 path)
//
// ── CSS sprite constants used by index.html ───────────────────────────────

const GUI = {
  // background image
  BG_W: 360, BG_H: 510,

  // face animation sprite map (resource 131)
  // 5 columns × 6 rows = 30 frames, each 314×311
  FACE_SPRITE_W: 1570, FACE_SPRITE_H: 1866,
  FACE_FRAME_W:   314, FACE_FRAME_H:   311,
  FACE_COLS:        5, FACE_ROWS:        6,
  FACE_FRAMES:     30,
  // position within background
  FACE_LEFT:  23, FACE_TOP: 0,

  // touchpad (Tibetan flag area)
  PAD_LEFT: 27, PAD_TOP: 350, PAD_W: 265, PAD_H: 100,

  // X indicator arrow (resource 142, arrow-down 10×10)
  // sits 10px above the pad top, x tracks vowel
  XARROW_W: 10, XARROW_H: 10,
  XARROW_TOP: 340,   // PAD_TOP - XARROW_H

  // Y indicator arrow (resource 141, arrow-right 10×10)
  // sits 10px left of pad left, y tracks depth
  YARROW_W: 10, YARROW_H: 10,
  YARROW_LEFT: 17,   // PAD_LEFT - YARROW_W

  // rotary knobs (resource 152/153, 1×30 sprite, each frame 50×100)
  // top=430 so that 430+80=510 = GUI height, knob fills to exact bottom edge
  KNOB_FRAME_W: 50, KNOB_FRAME_H: 100, KNOB_FRAMES: 30,
  KNOB_DISPLAY_H: 80,   // show top 80px (dial face); bottom 20px shadow clips below GUI
  KNOB_L_LEFT:  10, KNOB_L_TOP: 430,
  KNOB_R_LEFT: 300, KNOB_R_TOP: 430,

  // slider (resource 151 handle, 20×27 per rsrc notes; track between the two knobs)
  SLIDER_LEFT:  70, SLIDER_TOP: 462, SLIDER_W: 220, SLIDER_H: 30,
  HANDLE_W: 20, HANDLE_H: 27,

  // ? button area (shows about image, resource 160)
  ABOUT_BTN_LEFT: 308, ABOUT_BTN_TOP: 334, ABOUT_BTN_W: 28, ABOUT_BTN_H: 28,
  ABOUT_W: 253, ABOUT_H: 275,

  // animation frame from vowel parameter (0..1) → frame index (0..29)
  vowelToFrame(vowel) {
    return Math.min(GUI.FACE_FRAMES - 1, Math.floor(vowel * GUI.FACE_FRAMES));
  },

  // CSS background-position for a face animation frame
  faceFramePos(frame) {
    const col = frame % GUI.FACE_COLS;
    const row = Math.floor(frame / GUI.FACE_COLS);
    return `-${col * GUI.FACE_FRAME_W}px -${row * GUI.FACE_FRAME_H}px`;
  },

  // CSS background-position for a knob frame (0..29)
  knobFramePos(frame) {
    return `0 -${frame * GUI.KNOB_FRAME_H}px`;
  },
};
