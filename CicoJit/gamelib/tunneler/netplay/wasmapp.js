"use strict"

class WasmApp
{
  constructor()
  {
    this.memory = null;
    this.HEAPU32 = null;
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
      "__assert_fail": (condition, filename, line, func) =>
        abort('Assertion failed: ' + env.string(condition) + ', at: ' + [filename ? UTF8ToString(filename) : 'unknown filename', line, func ? UTF8ToString(func) : 'unknown function']),
      "__setErrNo": () => abort(3), 
      "emscripten_get_heap_size": () => abort(4),
      "emscripten_memcpy_big": (dest, src, num) => this.memory.copyWithin(dest, src, src + num), 
      "emscripten_memcpy_js": (dest, src, num) => this.memory.copyWithin(dest, src, src + num),
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

    return WebAssembly.instantiate(new Uint8Array(Module['wasmBinary']), {env: env, wasi_snapshot_preview1: env})
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
        for (var i=0; i<50 && this.memory[ptr+i] != 0; i++)
          text += String.fromCharCode(this.memory[ptr+i]);
        return text;
      },
      apiRead: (ptrName, readOfs, readLen, ptrData) =>
      {
        var name = this.imports().string(ptrName);
        console.log("Read", name, readOfs, readLen);
        var b = Module[name];
        var willRead = Math.min(b.length-readOfs, readLen);
        for (var i=0; i<readLen; i++)
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
