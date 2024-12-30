let Path = {
  Extract(path, f) {
    var binarySearch = (a, t) => {
        let low = 0, high = a.length - 1, result = -1;
        while (low <= high) {
            let mid = Math.floor((low + high) / 2);
            if (a[mid][0] <= t) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    };

    if (f <= path[0][0]) 
      return path[0][1];
    var i = binarySearch(path, f);
    return path[i][1];
  },
  Append(path, frame, keyState)
  {
    if (path.length == 0 && keyState == 0)
      return;
    if (path.length > 0 && path[path.length-1][1] == keyState)
      ;
    else
      path.push([frame, keyState]);
  },
  Sub(path, l, r)
  {
    var aux = [];
    for (var i=0; i<path.length; i++)
      if (path[i][0] > l && path[i][0] <= r)
        aux.push([path[i][0], path[i][1]])
    return aux;
  },
  New()
  {
    return [[0, 0]];
  },
  Copy(p)
  {
    return [...p];
  },
  From(s)
  {
    s = s.split(",").map(x=>parseInt(x));
    var p = [];
    for (var i=0; i<s.length; i+=2)
      p.push([s[i], s[i+1]])
    return p;
  },
  Length(p)
  {
    return p[p.length-1][0];
  }
}
/*
let Path = {
  New() { return []; },
  Append(path, f, s) {
    if (f != path.length) 
      throw "bad"; 
    path.push(s);
   },
  Extract(path, f) {return path[f];},
  Copy(path) {return [...path]; }
}
*/
class Game
{
  constructor()
  {
    this.app = new WasmApp(f=>Module[f])
    this.videoBuffer = null;
    this.memoryBuffer = null;
    this.frame = 0;
    this.path = Path.New();
    this.ready = new Promise((resolve, reject)=>{this.resolveReady = resolve})
    this.seed = Math.floor(Math.random()*0x10000) | (Math.floor(Math.random()*0x10000)<<16)
  }

  load()
  {
    return this.app.load().then(() => {
      this.videoBuffer = new Uint8ClampedArray(this.app.memory.buffer, this.app.HEAP32[this.app.symbols.appVideo.value>>2], 320 * 200 * 4);
      this.memoryBuffer = new Uint8Array(this.app.memory.buffer, this.app.HEAP32[this.app.symbols.appMemory.value>>2], 0x10000*18);
      this.asyncifyBuffer = new Uint8Array(this.app.memory.buffer, this.app.HEAP32[this.app.symbols.asyncifyBuffer.value>>2], 1024+12);

      this.app.HEAP32[this.app.symbols.seed.value>>2] = this.seed;
      this.app.symbols.appLoop();
      this.app.symbols.asyncify_stop_unwind();
      this.frame = 0;
      this.resolveReady();
    });
  }

  step(keyState)
  {
    applyState(this.memoryBuffer, keyState)
    Path.Append(this.path, this.frame, keyState);
    this.app.asyncifyResume();
    this.frame++;
    return true;
  }

  state()
  {
    return {};
  }

  render(ctx)
  {
    if (this.app.symbols.appBlit())
    {
      const img = new ImageData(this.videoBuffer, 320, 200);
      ctx.putImageData(img, 0, 0);
    }
  }

  copy(netGame)
  {
    this.app.memory.set(netGame.app.memory);
    this.path = Path.Copy(netGame.path);
    this.seed = netGame.seed;
    this.frame = netGame.frame;
  }

  pathLength()
  {
    return this.frame;
  }
}
