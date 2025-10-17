"use strict"

class WasmApp
{
  constructor(requestFile, imports)
  {
    this.memory = null;
    this.HEAPU32 = null;
    this.HEAPS8 = null;
    this.HEAPU8 = null;
    this.requestFile = requestFile;
    this.appImports = imports || [];
    this.asyncFirst = true;
    this.sleeping = false;
    this.currentFile = null;
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

    return this.requestFile("app.wasm")
      .then(bin => WebAssembly.instantiate(bin, {env: env, wasi_snapshot_preview1: env}))
      .then(output => 
    {
      this.symbols = output.instance.exports;
      this.memory = new Uint8Array(this.symbols.memory.buffer);
      this.HEAP32 = new Int32Array(this.symbols.memory.buffer);
      this.HEAPS8 = new Int8Array(this.symbols.memory.buffer);
      this.HEAPU8 = new Uint8Array(this.symbols.memory.buffer);
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
      apiOpen: (ptrName) =>
      {
        var name = this.imports().string(ptrName);
        console.log("apiOpen", ptrName);
        this.requestFile(name.split("\\").join("/"))
          .then( x=>this.currentFile = x )
          .then( ()=>this.asyncifyResume() )
      },
      apiRead: (ptrName, readOfs, readLen, ptrData) =>
      {
        var name = this.imports().string(ptrName);

        if (!ptrData && !readLen && !readOfs)
          return this.currentFile.length; //this.getFile(name.split("\\").join("/")).length;
        if (!ptrData)
          throw "no target"

        var b = this.currentFile; //this.getFile(name.split("\\").join("/"));
        if (readLen == -1)
          readLen = b.length;
        var willRead = Math.min(b.length-readOfs, readLen);
        console.log("Read", name, "0x"+readOfs.toString(16), "0x"+readLen.toString(16), "0x"+willRead.toString(16), "0x"+ptrData.toString(16));
        for (var i=0; i<willRead; i++)
          this.memory[i+ptrData] = b[i+readOfs];
        return willRead;
      },
      // https://gov.near.org/t/discussion-synchronous-contracts/11869/8
      emscripten_sleep: (d) => {
          if (!this.rewinding)
          {
            this.sleeping = d;
            var ptr = this.symbols.asyncifyBuffer.value;
            this.HEAP32[((ptr)>>2)] = ptr+12;
            this.HEAP32[(((ptr)+(4))>>2)] = ptr+12 + 1024;
            this.HEAP32[(((ptr)+(8))>>2)] = 0;
            this.symbols.asyncify_start_unwind(ptr);
          } else {
            this.sleeping = false;
            this.symbols.asyncify_stop_rewind();
            this.rewinding = false;
            return 0;
          }
      },
      fd_close: () => { throw "close" },
      fd_write: (fd, iovs, len, nwritten) => { 
        var text = "";
        var sum = 0;
        while (len--)
        {
          var ptr = this.memory[iovs]+this.memory[iovs+1]*0x100+this.memory[iovs+2]*0x10000+this.memory[iovs+3]*0x1000000;
          var blen = this.memory[iovs+4]+this.memory[iovs+5]*0x100+this.memory[iovs+6]*0x10000+this.memory[iovs+7]*0x1000000;
          iovs += 8;
          sum += blen;
          for (var i=0; i<blen; i++)
            text += String.fromCharCode(this.memory[ptr+i]);
        }
        console.log(text);
        this.memory[nwritten] = sum;
        this.memory[nwritten+1] = sum>>8;
        return 0;
      },
      fd_seek: () => { throw "seek" }
    }
  }
  asyncifyResume()
  {
    if (!this.symbols)
      return;

    if (this.asyncFirst)
    {
      this.symbols.asyncify_stop_unwind();
      this.asyncFirst = false;
    }

    var ptr = this.symbols.asyncifyBuffer.value;
    this.rewinding = true;
    this.sleeping = false;

    this.symbols.asyncify_start_rewind(ptr);
    this.symbols.appMain();
    this.symbols.asyncify_stop_unwind();
  }
}
