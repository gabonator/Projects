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
  let HEAPU8, HEAPU32, HEAP32, HEAPF32, HEAPF64, HEAP64;
  function updateViews(buf) {
    HEAPU8  = new Uint8Array(buf);
    HEAPU32 = new Uint32Array(buf);
    HEAP32  = new Int32Array(buf);
    HEAPF32 = new Float32Array(buf);
    HEAPF64 = new Float64Array(buf);
    HEAP64  = new BigInt64Array(buf);
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

  // EM_ASM argument unpacker (mirrors emscripten's readEmAsmArgs)
  const _emArgs = [];
  function readEmAsmArgs(sigPtr, buf) {
    _emArgs.length = 0;
    let ch;
    while ((ch = HEAPU8[sigPtr++])) {
      const wide = ch !== 105 && ch !== 112;  // 'i'=int32, 'p'=ptr are 32-bit; rest are 64-bit
      if (wide && buf % 8) buf += 4;
      _emArgs.push(ch === 112 ? HEAPU32[buf >> 2] :
                   ch === 105 ? HEAP32 [buf >> 2] :
                   ch === 106 ? HEAP64 [buf >> 3] :
                                HEAPF64[buf >> 3]);
      buf += wide ? 8 : 4;
    }
    return _emArgs;
  }

  // EM_ASM constants — indices are byte-offsets baked into the WASM binary by emscripten.
  // These implement the Win32 file / directory API used by kernel32.h.
  const ASM_CONSTS = {
    // CreateFileA: XHR-fetch path, cache result in nexusFileCache[slot]
    46964: ($0, $1) => {
      const winPath = UTF8ToString($0), slot = $1;
      // In browser: rewrite "Nexus Content/foo" → "/file?path=foo" (served by server.js).
      // In Node.js: MockXHR handles the path directly.
      const IS_BROWSER = typeof document !== 'undefined';
      const url = (IS_BROWSER && winPath.startsWith('Nexus Content/'))
        ? '/file?path=' + encodeURIComponent(winPath.slice('Nexus Content/'.length))
        : winPath;
      const xhr = new XMLHttpRequest();
      xhr.open('GET', url, false);
      // Browser sync XHR cannot use responseType='arraybuffer' — use overrideMimeType instead.
      // Node.js MockXHR ignores overrideMimeType (optional chain) and returns xhr.response as ArrayBuffer.
      xhr.overrideMimeType?.('text/plain; charset=x-user-defined');
      xhr.send(null);
      if (xhr.status !== 200) { printErr('CreateFileA: HTTP ' + xhr.status + ' ' + url); return -1; }
      let bytes;
      if (xhr.response instanceof ArrayBuffer) {
        bytes = new Uint8Array(xhr.response);  // Node.js MockXHR path
      } else {
        const t = xhr.responseText;             // Browser path: extract binary from string
        bytes = new Uint8Array(t.length);
        for (let i = 0; i < t.length; i++) bytes[i] = t.charCodeAt(i) & 0xff;
      }
      window.nexusFileCache[slot] = { data: bytes, pos: 0 };
      return bytes.length;
    },
    // ReadFile
    47463: ($0, $1, $2) => {
      const f = window.nexusFileCache[$0];
      if (!f) return 0;
      const n = Math.min($2, f.data.length - f.pos);
      HEAPU8.set(f.data.subarray(f.pos, f.pos + n), $1);
      f.pos += n;
      return n;
    },
    // CloseHandle (file)
    47657: ($0) => { delete window.nexusFileCache[$0]; },
    // SetFilePointer
    47695: ($0, $1, $2) => {
      const f = window.nexusFileCache[$0];
      if (!f) return 0xffffffff;
      f.pos = $2 === 0 ? $1 : $2 === 1 ? f.pos + $1 : f.data.length + $1;
      f.pos = Math.max(0, Math.min(f.pos, f.data.length));
      return f.pos;
    },
    // FindFirstFileA
    47929: ($0, $1) => {
      const key = UTF8ToString($0), dp = $1;
      const cache = window.nexusDirCache?.[key];
      if (!cache?.length) return -1;
      const h = window.nexusFindHandleNext++;
      window.nexusFindHandles[h] = { entries: cache, index: 0 };
      const e = cache[0];
      HEAPU32[ dp        >> 2] = e.isDir ? 16 : 128;
      HEAPU32[(dp + 28)  >> 2] = 0;
      HEAPU32[(dp + 32)  >> 2] = e.size >>> 0;
      for (let i = 0; i < 260; i++) HEAPU8[dp+44+i] = 0;
      for (let i = 0; i < e.name.length && i < 259; i++) HEAPU8[dp+44+i] = e.name.charCodeAt(i);
      return h;
    },
    // FindNextFileA
    48488: ($0, $1) => {
      const fh = window.nexusFindHandles?.[$0];
      if (!fh || ++fh.index >= fh.entries.length) return 0;
      const e = fh.entries[fh.index], dp = $1;
      HEAPU32[ dp        >> 2] = e.isDir ? 16 : 128;
      HEAPU32[(dp + 28)  >> 2] = 0;
      HEAPU32[(dp + 32)  >> 2] = e.size >>> 0;
      for (let i = 0; i < 260; i++) HEAPU8[dp+44+i] = 0;
      for (let i = 0; i < e.name.length && i < 259; i++) HEAPU8[dp+44+i] = e.name.charCodeAt(i);
      return 1;
    },
    // FindClose
    48982: ($0) => { if (window.nexusFindHandles) delete window.nexusFindHandles[$0]; return 0; },
  };

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
    __assert_fail:            (cond) => { throw new Error('Assertion failed: ' + UTF8ToString(cond)); },
    __cxa_throw:              (ptr, type, dtor) => { HEAPU32[(ptr-20) >> 2] = type; HEAPU32[(ptr-16) >> 2] = dtor; throw ptr; },
    _abort_js:                () => { throw new Error('abort'); },
    emscripten_asm_const_int: (code, sigPtr, argbuf) => ASM_CONSTS[code](...readEmAsmArgs(sigPtr, argbuf)),
    emscripten_resize_heap:   () => { throw new Error('OOM'); },
    fd_close:                 () => 52,
    fd_seek:                  () => 70,
    fd_write:                 _fdWrite,
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
