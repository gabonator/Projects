function indirectCall(s, o)
{
  switch (o)
  {
    // add methods referenced through indirectCall, e.g.:
    //case 0x10008810: sub_10008810(); break;
    //case 0x1000aee0: sub_1000aee0(); break;
    //case 0x10011e80: sub_10011e80(); break;

    case 0x77778888: audioMasterHandler(); break;  // audioMaster callback
    case 0x10001000: sub_10001000(); break;        // VST dispatcher
    case 0x100010c0: sub_100010c0(); break;        // VST processReplacing
    case 0x10001ab0: sub_10001ab0(); break;        // dispatcher impl
    case 0x10002810: sub_10002810(); break;        // default ctor stub (returns this in eax)
    case 0x10002db0: sub_10002db0(); break;        // parameter/state dispatcher (opcodes 0-11)
    case 0x10002b10: sub_10002b10(); break;        // sets sample-rate/tempo via sub_10002db0 opcodes 0,2,3
    case 0x10003530: sub_10003530(); break;        // vtable[1]: wraps sub_10002db0, also calls sub-obj vtable
    case 0x100040c0: sub_100040c0(); break;        // sub-obj opcode switch (opcodes 0-6)
    case 0x100061e0: sub_100061e0(); break;        // processEvents: copies MIDI into plugin buffer
    case 0x100054c0: sub_100054c0(); break;        // processReplacing implementation (vtable+0x14)
    case 0x10006400: sub_10006400(); break;        // vtable call from processReplacing
    case 0x10004870: sub_10004870(); break;        // vtable+0x4c: effSetSampleRate handler
    case 0x10004890: sub_10004890(); break;        // vtable+0x50: effSetBlockSize handler
    case 0x100048b0: sub_100048b0(); break;        // vtable+0x58: effMainsChanged=1 handler
    case 0x100048d0: sub_100048d0(); break;        // delay buffer init / activation
    case 0x10002060: sub_10002060(); break;        // vtable+0x88: sample-rate getter callback
    case 0x10001970: sub_10001970(); break;
    case 0x10001080: sub_10001080(); break;        // AEffect.setParameter (cdecl, caller pops 12)
    case 0x10001060: sub_10001060(); break;        // AEffect.getParameter (cdecl, caller pops 8)
    case 0x10002fd0: sub_10002fd0(); break;        // vtable[2]: getParameter impl

    // Windows API stubs (6ab000xx enum values from IAT)
    // stdcall: callee pops args (r32[esp] += N)
    // cdecl: caller pops (no cleanup here)
    case 0x6ab00048: r32[esp] += 4;  r32[eax] = 0; break;  // OleInitialize(lpv) -> S_OK
    case 0x6ab00049:                  r32[eax] = 0; break;  // OleUninitialize() -> void
    case 0x6ab0004a: r32[esp] += 4;  r32[eax] = 0; break;  // RevokeDragDrop(hwnd)
    case 0x6ab0004b: r32[esp] += 8;  r32[eax] = 0; break;  // RegisterDragDrop(hwnd,target)
    case 0x6ab0004c: r32[esp] += 20; r32[eax] = 0x80004002; break;  // CoCreateInstance -> E_NOINTERFACE
    case 0x6ab0001a: r32[esp] += 4;  r32[eax] = 0; break;  // Sleep(ms)
    case 0x6ab0001b: r32[esp] += 4;  r32[eax] = 1; break;  // GlobalFree(h) -> success
    case 0x6ab0001c:                  r32[eax] = 0; break;  // GetLastError()
    case 0x6ab0001d:                  r32[eax] = Date.now() & 0xffffffff; break;  // GetTickCount()
    case 0x6ab0001e: r32[eax] = 0; break;  // _stricmp (cdecl, caller pops)
    case 0x6ab0001f: r32[eax] = 0; break;  // _adjust_fdiv (cdecl, no-op)
    case 0x6ab00020: r32[eax] = 0; break;  // _initterm (cdecl, no-op)
    case 0x6ab00022: r32[eax] = 0; break;  // _except_handler3 (cdecl, no-op)
    case 0x6ab00023: throw "_purecall";    // _purecall - fatal
    case 0x6ab00024: r32[eax] = 0; break;  // strrchr (cdecl) -> null
    case 0x6ab00025: {  // realloc (cdecl, caller pops)
        const size = memoryAGet32(ds, r32[esp] + 8);
        r32[eax] = allocatorPtr; allocatorPtr += size;
        console.log("realloc => 0x" + r32[eax].toString(16)); break;
    }
    case 0x6ab00027: r32[eax] = 0; break;  // free (cdecl, no-op in bump allocator)
    case 0x6ab00028: {  // malloc (cdecl, caller pops)
        const size = memoryAGet32(ds, r32[esp] + 4);
        r32[eax] = allocatorPtr; allocatorPtr += size;
        console.log("malloc(" + size + ") => 0x" + r32[eax].toString(16)); break;
    }
    case 0x6ab00029: r32[eax] = 0; break;  // __CxxFrameHandler (cdecl, no-op)
    case 0x6ab0002a: {  // operator new ??2@YAPAXI@Z (cdecl, caller pops)
        const size = memoryAGet32(ds, r32[esp] + 4);
        r32[eax] = allocatorPtr; allocatorPtr += size;
        console.log("new(" + size + ") => 0x" + r32[eax].toString(16)); break;
    }
    case 0x6ab0002b: r32[eax] = 0; break;  // sprintf (cdecl, caller pops)
    case 0x6ab0002e: r32[eax] = 0; break;  // floor (cdecl)
    case 0x6ab0002f: r32[eax] = 0; break;  // _ftol (cdecl)

    // gdi32 stubs (enum base 0x6ab00001 = IAT 0x1000b000, each +4 bytes in IAT)
    case 0x6ab00001: r32[esp] += 8;  r32[eax] = 0; break;  // GetCurrentObject(hdc,type)
    case 0x6ab00002: r32[esp] += 4;  r32[eax] = 1; break;  // DeleteObject(h)
    case 0x6ab00003: r32[esp] += 8;  r32[eax] = 0; break;  // SelectObject
    case 0x6ab00004: r32[esp] += 12; r32[eax] = 1; break;  // MoveToEx
    case 0x6ab00005: r32[esp] += 8;  r32[eax] = 1; break;  // LineTo
    case 0x6ab00006: r32[esp] += 4;  r32[eax] = 0; break;  // CreatePenIndirect
    case 0x6ab00007: r32[esp] += 4;  r32[eax] = 0; break;  // GetStockObject
    case 0x6ab00008: r32[esp] += 8;  r32[eax] = 0; break;  // SetTextColor
    case 0x6ab00009: r32[esp] += 4;  r32[eax] = 0; break;  // CreateBrushIndirect
    case 0x6ab0000a: r32[esp] += 8;  r32[eax] = 0; break;  // SetBkColor
    case 0x6ab0000b: r32[esp] += 12; r32[eax] = 0; break;  // CreateCompatibleBitmap
    case 0x6ab0000c: r32[esp] += 4;  r32[eax] = 0; break;  // CreateCompatibleDC
    case 0x6ab0000d: r32[esp] += 4;  r32[eax] = 1; break;  // DeleteDC
    case 0x6ab0000e: r32[esp] += 28; r32[eax] = 1; break;  // BitBlt(7 args)
    case 0x6ab0000f: r32[esp] += 12; r32[eax] = 0; break;  // GetObjectA(h,n,lpvObject)
    case 0x6ab00010: r32[esp] += 20; r32[eax] = 0; break;  // CreateBitmap(5 args)
    case 0x6ab00011: r32[esp] += 8;  r32[eax] = 1; break;  // DPtoLP
    case 0x6ab00012: r32[esp] += 4;  r32[eax] = 0; break;  // CreateSolidBrush
    case 0x6ab00013: r32[esp] += 8;  r32[eax] = 0; break;  // SetMapMode
    case 0x6ab00014: r32[esp] += 4;  r32[eax] = 0; break;  // GetMapMode
    case 0x6ab00015: r32[esp] += 8;  r32[eax] = 0; break;  // SetBkMode

    // user32 GUI stubs
    case 0x6ab00038: r32[esp] += 8;  r32[eax] = 0; break;  // LoadBitmapA(hInst, name) -> NULL
    case 0x6ab00039: r32[esp] += 4;  r32[eax] = 0; break;  // SetCursor
    case 0x6ab0003a: r32[esp] += 8;  r32[eax] = 0; break;  // LoadCursorA
    case 0x6ab0003b: r32[esp] += 12; r32[eax] = 0; break;  // GetWindowLongA
    case 0x6ab0003c: r32[esp] += 48; r32[eax] = 0; break;  // CreateWindowExA(12 args)
    case 0x6ab0003d: r32[esp] += 12; r32[eax] = 0; break;  // SetWindowLongA
    case 0x6ab0003e: r32[esp] += 4;  r32[eax] = 1; break;  // DestroyWindow
    case 0x6ab0003f: r32[esp] += 4;  r32[eax] = 0; break;  // GetDC
    case 0x6ab00040: r32[esp] += 8;  r32[eax] = 1; break;  // ReleaseDC
    case 0x6ab00041: r32[esp] += 4;  r32[eax] = 1; break;  // GetCursorPos
    case 0x6ab00042: r32[esp] += 4;  r32[eax] = 0; break;  // GetAsyncKeyState
    case 0x6ab00043: r32[esp] += 12; r32[eax] = 0; break;  // FillRect
    case 0x6ab00044: r32[esp] += 8;  r32[eax] = 1; break;  // GetWindowRect
    case 0x6ab00045: r32[esp] += 16; r32[eax] = 0; break;  // PeekMessageA
    case 0x6ab00046: r32[esp] += 4;  r32[eax] = 0; break;  // DispatchMessageA
    case 0x6ab00047: r32[esp] += 0;  r32[eax] = 0; break;  // GetCursor
    case 0x6ab00037: r32[esp] += 4;  r32[eax] = 0; break;  // RegisterClassA -> 0 = fail

    default:
      console.log("indirect call:", o.toString(16))
      console.trace();
      throw "unimplemented indirect";
  }
}


function allocate(size)
{
    let ptr = allocatorPtr;
    console.log("Alloc 0x" + size.toString(16) + " @ 0x" + ptr.toString(16))
    for (var i=0; i<size; i++) if (memoryAGet(0, ptr+i) != 0) throw "not clean"
    allocatorPtr += size;
    return ptr;
}

// STOSD: store eax to [es:edi], advance edi by 4
function stosd_ESEDI(v) {
    memoryASet32(es, r32[edi], v);
    r32[edi] += 4;
}

// operator new(size_t) — msvcrt ??2@YAPAXI@Z
// called via sub_1000a7fc thunk; size is at [esp+4] (first cdecl arg after sub esp,4 in thunk)
function sub_1000a7fc()
{
    const size = memoryAGet32(ds, r32[esp]); // no emulated return addr; arg is at [esp+0]
    r32[eax] = allocatorPtr;
    allocatorPtr += size;
    console.log("operator new(" + size + ") => 0x" + r32[eax].toString(16));
}

// implement missing kernel methods or fpu helpers, e.g.
// function sub_10035630(x) {
//   setst(0, Math.cos(st(0)));
// }
