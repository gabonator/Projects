document.body.innerHTML += `
  <div id="debug" style="color:#808080;"></div>
  <canvas id="map" width="1024" height="480" style="padding-top:20px;"></canvas>
`;

var mcanvas = document.getElementById('map');
var mctx = mcanvas.getContext('2d');
var mazeGenerated = false;
//var mimageData = mctx.getImageData(0, 0, mcanvas.width, mcanvas.height);
//var step = 0;
//var iter = 0;

function generateMaze()
{
  var setPixel = (x, y, c) => {
    var b = session.gameLocal.memoryBuffer[64100+y*512+(x>>1)];
    if (x&1) 
      b = b & 0x0f | (c<<4);
    else
      b = b & 0xf0 | c;
    session.gameLocal.memoryBuffer[64100+y*512+(x>>1)] = b;
    session.gameRemote.memoryBuffer[64100+y*512+(x>>1)] = b;
  }

//  for (var y=0; y<480; y++)
//    setPixel(512, y, 7);
  var state = session.gameLocal.state();
  var mulberry32 = a => {
    return function() {
      let t = a += 0x6D2B79F5;
      t = Math.imul(t ^ t >>> 15, t | 1);
      t ^= t + Math.imul(t ^ t >>> 7, t | 61);
      return ((t ^ t >>> 14) >>> 0) / 4294967296;
    }
  }
  var random = mulberry32(session.gameLocal.seed);

  const maze = new MazeGenerator(random);
  maze.generateMaze(10, 10);
  const render = new MazeTextRenderer(maze, 15);
  render.render();
  let {width:w, height:h} = render.getSize();
  let colormap = {' ': 0, 'S': 0, 'F': 0, '#': 7}
  var bx = 1024/2, by = 480/2, bmax = 100;
  for (var i=0; i<20; i++)
  {
    var nx = Math.floor(random()*(1024-w-600) +300+ w/2);
    var ny = Math.floor(random()*(512-h-400) +200+ h/2);
    nmax = Math.min(Math.abs(nx - state.green.x), Math.abs(nx - state.blue.x))
    if (nmax > bmax)
    {
      bmax = nmax;
      bx = nx;
      by = ny;
    }
  }

  for (var x=0; x<w; x++) 
    for (var y=0; y<h; y++)
      if (render.getPixel(x, y)=='#')
        setPixel(Math.floor(bx-w/2)+x, Math.floor(by-h/2)+y, 7)
//      setPixel(Math.floor((1024-w)/2)+x, Math.floor((480-h)/2)+y, colormap[render.getPixel(x, y)])
}

setInterval(()=>{
  var game = session.gameLocal;
  if (!game.memoryBuffer)
    return
  if (!mazeGenerated)
  {
    mazeGenerated = true;
    generateMaze();
  }
  const myImageData = mctx.createImageData(1024, 480);
  var pal = [0x000000, 0x0000b0, 0x00b000, 0x00b0b0, 0xb00000, 0xb000b0, 0xb0b000, 0xb0b0b0,
      0x808080, 0x0000ff, 0x00ff00, 0x00ffff, 0xff0000, 0xff00ff, 0xffff00, 0xffffff];

/*

  var setPixel = (x, y, c) => {
    var b = game.memoryBuffer[64100+y*512+(x>>1)];
    if (x&1) 
      b = b & 0x0f | (c<<4);
    else
      b = b & 0xf0 | c;
    game.memoryBuffer[64100+y*512+(x>>1)] = b;
  }

  // passage through the end of the world
  for (var x=0; x<10; x++)
    for (var y=0; y<200; y++)
      setPixel(1024-y+70, 200+x, 0);

  // render letter 'G'
  step++;
  var fun = [10, 11, 12, 14];
  var egafont14x8 = new Uint8ClampedArray(game.app.memory.buffer, game.app.symbols.egafont14x8.value, 256*14);
  for (var x=0; x<8*10; x++)
    for (var y=0; y<14*10; y++)
    {
      if (x%10 >= 3 && x%10 <= 6 && y%10 >= 3 && y%10 <= 6)
        continue;
      var bx = Math.floor(x/10)
      var by = Math.floor(y/10)
      if (egafont14x8[71*14+by] & (128>>bx))
        setPixel(480+x, 150+y, fun[((step+y+x)>>3)%fun.length]);
    }
*/
  // render map
  var i=0;
  for (var y=0; y<480; y++)
    for (var x=0; x<1024/2; x++)
    {
      var c = game.memoryBuffer[64100+y*512+x]
      var cc = pal[c&15];
      myImageData.data[i++] = (cc>>16)&255; 
      myImageData.data[i++] = (cc>>8)&255;
      myImageData.data[i++] = (cc>>0)&255;
      myImageData.data[i++] = 255;
      var cc = pal[c>>4];
      myImageData.data[i++] = (cc>>16)&255; 
      myImageData.data[i++] = (cc>>8)&255;
      myImageData.data[i++] = (cc>>0)&255;
      myImageData.data[i++] = 255;
    }
    mctx.putImageData(myImageData, 0, 0);                                      

  document.querySelector("#debug").innerHTML = JSON.stringify(game.state());
}, 1000);
