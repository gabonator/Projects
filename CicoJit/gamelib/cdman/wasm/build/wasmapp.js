"use strict"

class WasmApp
{
  constructor(getFile, imports)
  {
    this.memory = null;
    this.HEAPU32 = null;
    this.getFile = getFile;
    this.appImports = imports || [];
  }

  load()
  {
    var WASM_PAGE_SIZE = 65536;
    var TOTAL_MEMORY = 65536;
    var DYNAMICTOP_PTR = 11856;

    var abort = (what) => { throw 'abort(' + what + '). Build with -s ASSERTIONS=1 for more info.'};
    var env = {
      "abort": () => abort(1), 
      "_abort": () => abort(2),
      "_abort_js": () => abort(3),
      "__assert_fail": (condition, filename, line, func) =>
        abort('Assertion failed: ' + env.string(condition) + ', at: ' + [filename ? env.string(filename) : 'unknown filename', line, func ? env.string(func) : 'unknown function']),
      "__setErrNo": () => abort(3), 
      "emscripten_get_heap_size": () => abort(4),
      "emscripten_memcpy_big": (dest, src, num) => this.memory.copyWithin(dest, src, src + num), 
      "emscripten_memcpy_js": (dest, src, num) => this.memory.copyWithin(dest, src, src + num),
      "_emscripten_memcpy_js": (dest, src, num) => this.memory.copyWithin(dest, src, src + num),
      "emscripten_resize_heap": () => abort(6),
      "abortOnCannotGrowMemory": () => abort(7), 
      "DYNAMICTOP_PTR": DYNAMICTOP_PTR,
      memory: new WebAssembly.Memory({ 'initial': TOTAL_MEMORY / WASM_PAGE_SIZE, 'maximum': TOTAL_MEMORY / WASM_PAGE_SIZE }),
      table: new WebAssembly.Table({'initial': 84,'maximum': 84,'element': 'anyfunc'}),
      '__memory_base': 1024, 
      '__table_base': 0
    };

    var localImports = this.imports();
    for (var i in localImports)
      env[i] = localImports[i];
    for (var i in this.appImports)
      env[i] = this.appImports[i];

    return WebAssembly.instantiate(new Uint8Array(this.getFile('wasmBinary')), {env: env, wasi_snapshot_preview1: env})
    .then( output => 
    {
      this.symbols = output.instance.exports;
      this.memory = new Uint8Array(this.symbols.memory.buffer);
      this.HEAP32 = new Int32Array(this.symbols.memory.buffer);
      if (this.symbols["__wasm_call_ctors"]) 
        this.symbols["__wasm_call_ctors"]();
    });
  }

  imports()
  {
    return {
      apiPrint: (ptr) => { 
        var msg = this.imports().string(ptr);
        console.log(msg);
      },
      string: (ptr) => {
        var text = "";
        for (var i=0; i<256 && this.memory[ptr+i] != 0; i++)
          text += String.fromCharCode(this.memory[ptr+i]);
        return text;
      },
      apiRead: (ptrName, readOfs, readLen, ptrData) =>
      {
        var name = this.imports().string(ptrName);
        var b = this.getFile(name.toLowerCase().split("\\").join("/"));
        if (!ptrData)
          return b.length;
        if (!b)
          return 0;
        var willRead = Math.min(b.length-readOfs, readLen);
        console.log("Read", name, readOfs, readLen);
        for (var i=0; i<willRead; i++)
          this.memory[i+ptrData] = b[i+readOfs];
        return willRead;
      },
      // https://gov.near.org/t/discussion-synchronous-contracts/11869/8
      emscripten_sleep: () => {
          if (!this.rewinding)
          {
            var ptr = this.symbols.asyncifyBuffer.value;
            this.HEAP32[((ptr)>>2)] = ptr+12;
            this.HEAP32[(((ptr)+(4))>>2)] = ptr+12 + 1024;
            this.HEAP32[(((ptr)+(8))>>2)] = 0;
            this.symbols.asyncify_start_unwind(ptr);
          } else {
            this.symbols.asyncify_stop_rewind();
            this.rewinding = false;
            return 0;
          }
      },
      fd_close: () => { throw "close" },
      fd_write: (handle, x, y, ptr) => { throw "write" },
      fd_seek: () => { throw "seek" }
    }
  }
  asyncifyResume()
  {
    var ptr = this.symbols.asyncifyBuffer.value;
    this.rewinding = true;

    this.symbols.asyncify_start_rewind(ptr);
    this.symbols.appLoop();
    this.symbols.asyncify_stop_unwind();
  }
}
