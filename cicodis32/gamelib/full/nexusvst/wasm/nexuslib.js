(function () {
'use strict';

// ── Constants ─────────────────────────────────────────────────────────────────
const BLOCK_SIZE     = 512;
const SAMPLE_RATE    = 44100;
const OUT_L_FI       = 0x2000 >> 2;   // HEAPF32 index for left channel
const OUT_R_FI       = 0x2800 >> 2;   // HEAPF32 index for right channel
const PRESET_SCRATCH = 0x4000;         // low-memory scratch area for FXP chunk

const SECTIONS = [
  { name: 'Nexus_rdata.bin',    addr: 0x000e6000 },
  { name: 'Nexus_data.bin',     addr: 0x003fb000 },
  { name: 'SYNSOEMU_rdata.bin', addr: 0x01007000 },
  { name: 'SYNSOEMU_data.bin',  addr: 0x010a6000 },
];

// ── FXP preset parser ─────────────────────────────────────────────────────────
// Accepts ArrayBuffer (browser) or Buffer/TypedArray (Node.js).
// Returns raw chunk Uint8Array, or null on error.
function parseFxp(input) {
  const v = input instanceof ArrayBuffer
    ? new DataView(input)
    : new DataView(input.buffer, input.byteOffset, input.byteLength);
  const tag = o => String.fromCharCode(v.getUint8(o), v.getUint8(o+1), v.getUint8(o+2), v.getUint8(o+3));
  if (tag(0) !== 'CcnK' || tag(8) !== 'FPCh') return null;
  return new Uint8Array(v.buffer, v.byteOffset + 60, v.getUint32(56, false));
}

// ── Section loader ────────────────────────────────────────────────────────────
// getData(sectionName) → Promise<Uint8Array | Buffer>
async function loadSections(M, getData) {
  for (const { name, addr } of SECTIONS)
    M.HEAPU8.set(await getData(name), addr);
}

// ── Plugin helpers ────────────────────────────────────────────────────────────
function nexusInit(M, presetChunk) {
  M._nexus_init();
  if (presetChunk) {
    M.HEAPU8.set(presetChunk, PRESET_SCRATCH);
    M._nexus_load_preset(PRESET_SCRATCH, presetChunk.length);
  }
}

function renderBlock(M, bufL, bufR, blockIdx) {
  M._nexus_process();
  const off = blockIdx * BLOCK_SIZE;
  bufL.set(M.HEAPF32.subarray(OUT_L_FI, OUT_L_FI + BLOCK_SIZE), off);
  bufR.set(M.HEAPF32.subarray(OUT_R_FI, OUT_R_FI + BLOCK_SIZE), off);
}

// ── WASM module factory ───────────────────────────────────────────────────────
// Replaces the emscripten-generated nexus.js.
// Returns a module object with HEAPU8, HEAPF32, and the four nexus functions.
async function NexusModule(opts = {}) {
  const IS_NODE  = typeof process === 'object' && typeof process.versions?.node === 'string';
  const printErr = opts.printErr || console.error.bind(console);
  const locate   = opts.locateFile || (f => f);

  // Heap views — undefined until updateViews() is called after WASM instantiation.
  // Closures below capture the let-binding, so they see the updated values at call time.
  let HEAPU8, HEAPU32, HEAPF32;
  function updateViews(buf) {
    HEAPU8  = new Uint8Array(buf);
    HEAPU32 = new Uint32Array(buf);
    HEAPF32 = new Float32Array(buf);
  }

  // UTF-8 string reader from WASM memory
  const _dec = typeof TextDecoder !== 'undefined' ? new TextDecoder() : null;
  function UTF8ToString(ptr) {
    if (!ptr) return '';
    let end = ptr;
    while (HEAPU8[end]) end++;
    return _dec ? _dec.decode(HEAPU8.subarray(ptr, end))
                : String.fromCharCode(...HEAPU8.subarray(ptr, end));
  }

  // VFS state — shared across all kernel32 file/dir calls
  const _fileCache = {};   // slot → { data: Uint8Array, pos: number }
  const _findHandles = {}; // handle → { entries, index }
  let _findHandleNext = 0;

  // nexusDirCache is populated by the host (test.js / nexus.html) before nexus_init()
  const _gbl = typeof window !== 'undefined' ? window : (typeof globalThis !== 'undefined' ? globalThis : global);

  // Helper: write a WIN32_FIND_DATA entry into WASM memory at dp
  function _writeFindData(dp, e) {
    HEAPU32[ dp        >> 2] = e.isDir ? 16 : 128;
    HEAPU32[(dp + 28)  >> 2] = 0;
    HEAPU32[(dp + 32)  >> 2] = e.size >>> 0;
    for (let i = 0; i < 260; i++) HEAPU8[dp+44+i] = 0;
    for (let i = 0; i < e.name.length && i < 259; i++) HEAPU8[dp+44+i] = e.name.charCodeAt(i);
  }

  // fd_write — routes WASM printf to console
  const _bufs = [null, [], []];  // fd 0 unused, 1=stdout, 2=stderr
  function _fdWrite(fd, iov, iovcnt, pnum) {
    const buf = fd === 1 ? _bufs[1] : _bufs[2];
    let num = 0;
    for (let i = 0; i < iovcnt; i++) {
      const ptr = HEAPU32[iov >> 2], len = HEAPU32[(iov+4) >> 2];
      iov += 8;
      for (let j = 0; j < len; j++) {
        const c = HEAPU8[ptr+j];
        if (c === 0 || c === 10) {
          (fd === 1 ? console.log : printErr)(new TextDecoder().decode(new Uint8Array(buf)));
          buf.length = 0;
        } else buf.push(c);
      }
      num += len;
    }
    HEAPU32[pnum >> 2] = num;
    return 0;
  }

  const wasmImports = {
    __assert_fail:        (cond) => { throw new Error('Assertion failed: ' + UTF8ToString(cond)); },
    __cxa_throw:          (ptr, type, dtor) => { HEAPU32[(ptr-20) >> 2] = type; HEAPU32[(ptr-16) >> 2] = dtor; throw ptr; },
    _abort_js:            () => { throw new Error('abort'); },
    emscripten_resize_heap: () => { throw new Error('OOM'); },
    fd_close:             () => 52,
    fd_seek:              () => 70,
    fd_write:             _fdWrite,

    // VFS imports — replace all EM_ASM blocks in kernel32.h
    nexus_vfs_open: (urlPtr, slot) => {
      const winPath = UTF8ToString(urlPtr);
      const IS_BROWSER = typeof document !== 'undefined';
      const url = (IS_BROWSER && winPath.startsWith('Nexus Content/'))
        ? '/file?path=' + encodeURIComponent(winPath.slice('Nexus Content/'.length))
        : winPath;
      const xhr = new XMLHttpRequest();
      xhr.open('GET', url, false);
      xhr.overrideMimeType?.('text/plain; charset=x-user-defined');
      xhr.send(null);
      if (xhr.status !== 200) { printErr('nexus_vfs_open: HTTP ' + xhr.status + ' ' + url); return -1; }
      let bytes;
      if (xhr.response instanceof ArrayBuffer) {
        bytes = new Uint8Array(xhr.response);
      } else {
        const t = xhr.responseText;
        bytes = new Uint8Array(t.length);
        for (let i = 0; i < t.length; i++) bytes[i] = t.charCodeAt(i) & 0xff;
      }
      _fileCache[slot] = { data: bytes, pos: 0 };
      return bytes.length;
    },
    nexus_vfs_read: (slot, bufPtr, nBytes) => {
      const f = _fileCache[slot];
      if (!f) return 0;
      const n = Math.min(nBytes, f.data.length - f.pos);
      HEAPU8.set(f.data.subarray(f.pos, f.pos + n), bufPtr);
      f.pos += n;
      return n;
    },
    nexus_vfs_close: (slot) => { delete _fileCache[slot]; },
    nexus_vfs_seek: (slot, dist, method) => {
      const f = _fileCache[slot];
      if (!f) return 0xffffffff;
      f.pos = method === 0 ? dist : method === 1 ? f.pos + dist : f.data.length + dist;
      f.pos = Math.max(0, Math.min(f.pos, f.data.length));
      return f.pos;
    },
    nexus_vfs_find_first: (keyPtr, dataPtr) => {
      const key = UTF8ToString(keyPtr);
      const cache = _gbl.nexusDirCache?.[key];
      if (!cache?.length) return -1;
      const h = _findHandleNext++;
      _findHandles[h] = { entries: cache, index: 0 };
      _writeFindData(dataPtr, cache[0]);
      return h;
    },
    nexus_vfs_find_next: (handle, dataPtr) => {
      const fh = _findHandles[handle];
      if (!fh || ++fh.index >= fh.entries.length) return 0;
      _writeFindData(dataPtr, fh.entries[fh.index]);
      return 1;
    },
    nexus_vfs_find_close: (handle) => { delete _findHandles[handle]; },
  };
  const imports = { env: wasmImports, wasi_snapshot_preview1: wasmImports };

  // Instantiate nexus.wasm
  let instance;
  if (IS_NODE) {
    const buf = require('fs').readFileSync(locate('nexus.wasm'));
    ({ instance } = await WebAssembly.instantiate(buf, imports));
  } else {
    try {
      ({ instance } = await WebAssembly.instantiateStreaming(
        fetch(locate('nexus.wasm'), { credentials: 'same-origin' }), imports));
    } catch {
      const buf = await fetch(locate('nexus.wasm')).then(r => r.arrayBuffer());
      ({ instance } = await WebAssembly.instantiate(buf, imports));
    }
  }

  const exp = instance.exports;
  updateViews(exp.memory.buffer);
  exp.__wasm_call_ctors?.();

  return {
    HEAPU8,
    HEAPF32,
    _nexus_init:        exp.nexus_init,
    _nexus_load_preset: exp.nexus_load_preset,
    _nexus_midi:        exp.nexus_midi,
    _nexus_process:     exp.nexus_process,
    _nexus_out_l:       exp.nexus_out_l,
    _nexus_out_r:       exp.nexus_out_r,
  };
}

// ── Export ────────────────────────────────────────────────────────────────────
const _exports = { NexusModule, BLOCK_SIZE, SAMPLE_RATE, OUT_L_FI, OUT_R_FI, PRESET_SCRATCH, SECTIONS, parseFxp, loadSections, nexusInit, renderBlock };
if (typeof module !== 'undefined')
  module.exports = _exports;
else
  window.NexusLib = _exports;

})();
