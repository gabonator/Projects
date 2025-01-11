document.onkeydown = evt => {
  if (onKey(evt.keyCode, 1))
    evt.preventDefault();
}
document.onkeyup = evt => {
  if (onKey(evt.keyCode, 0))
    evt.preventDefault();
}

function onKey(code, pressed)
{
  var cbit = (k, p) => p ? game.HEAP32[game.symbols.lastKey.value>>2]=k : 0;
  switch (code)                     
  {
    case 38: cbit(0x4800, pressed); break;
    case 40: cbit(0x5000, pressed); break;
    case 37: cbit(0x4b00, pressed); break;
    case 39: cbit(0x4d00, pressed); break;
    case 32: cbit(0x3920, pressed); break;
    default:
      return false;
  }
  return true;   
}

function renderGrid()
{
  var bx = 16, by = 58;
  var sx = 32, sy = 24;
  for (var y=0; y<11; y++)
    for (var x=0; x<19; x++)
    {
      ctx.strokeStyle = (x==getState().x && y == getState().y)  ? "#ff0000" : "#808080"
      ctx.beginPath();
      ctx.rect(bx+x*sx, by+y*sy, sx-1, sy-1);
      ctx.stroke();
    }
}
function pacGraphAt(x, y)
{
  var mask = game.memoryBuffer[0x10200 + 124 + y*21+x+22];
  return {up: mask & 128, down: mask & 64, left: mask & 32, right: mask & 16}
}

document.querySelector("#canvas").addEventListener("click", evt => {
  var bx = 16, by = 58;
  var sx = 32, sy = 24;

  var playerx = getState().x, playery = getState().y;
  if (playerx < 0 || playerx >= 20 || playery < 0 || playery >= 12)
    return;

  var blkx = Math.floor((evt.offsetX-bx)/sx)
  var blky = Math.floor((evt.offsetY-by)/sy)
  if (blkx < 0 || blkx >= 20 || blky < 0 || blky >= 12)
    return;

  game.paused = true;
  renderGrid();
  ctx.strokeStyle = "#ffffff"
  ctx.beginPath();
  ctx.rect(bx+blkx*sx, by+blky*sy, sx-1, sy-1);
  ctx.stroke();

//  map[playery][playerx] = 'F';
  var map = [...Array(12)].map(e => Array(20).fill(" "))
  map[blky][blkx] = 'S';
  var newpts = [];
  
  var setPath = (x, y, c) => {
    if (newpts.find(p=>p[0] == x && p[1] == y))
      return;
    newpts.push([x, y, c]);
//console.log(x, y, c);
    //map2[y][x] = c;
    ctx.font = "20px Arial";
    ctx.fillStyle = "#ffffff";
//    var syms = {"l": "&larr;", "r": "&rarr;", "u": "&uarr;", "d": "&darr;"}
    var syms = {"l": "\u2190", "r": "\u2192", "u": "\u2191", "d": "\u2193"}
    var syms = {"r": "\u2190", "l": "\u2192", "d": "\u2191", "u": "\u2193"}
    ctx.fillText(syms[c], bx+x*sx+8, by+y*sy+16);
  }
  var tracePath = (x, y, oc) =>
  {
    var c = map[y][x];

    ctx.font = "20px Arial";
    ctx.fillStyle = oc || "#0000b0";
    var syms = {"r": "\u2190", "l": "\u2192", "d": "\u2191", "u": "\u2193", "S": ""}
    ctx.fillText(syms[c], bx+x*sx+8, by+y*sy+16);


    ctx.font = "bold 20px Arial";
    ctx.fillStyle = "#ff0000";
//    var syms = {"l": "&larr;", "r": "&rarr;", "u": "&uarr;", "d": "&darr;"}
    var syms = {"l": "\u2190", "r": "\u2192", "u": "\u2191", "d": "\u2193", "S" : "\u2605"}
//    var syms = {"r": "\u2190", "l": "\u2192", "d": "\u2191", "u": "\u2193"}
    ctx.fillText(syms[c], bx+x*sx+8, by+y*sy+16);
    ctx.fillText(syms[c], bx+x*sx+8-1, by+y*sy+16);
    ctx.fillText(syms[c], bx+x*sx+8, by+y*sy+16-1);
    ctx.fillText(syms[c], bx+x*sx+8+1, by+y*sy+16);
    ctx.fillText(syms[c], bx+x*sx+8, by+y*sy+16+1);
  }
  //for (var iter=0; iter<30; iter++)
  var scan = () =>
  {
    newpts = [];
    for (var y=0; y<11; y++)
      for (var x=0; x<19; x++)
      {
        if (map[y][x] == " ")
          continue;
        var graph = pacGraphAt(x, y);
        if (y>0 && graph.up && map[y-1][x] == " ")
          setPath(x, y-1, "d");
        if (y<11-1 && graph.down && map[y+1][x] == " ")
          setPath(x, y+1, "u");
        if (x>0 && graph.left && map[y][x-1] == " ")
          setPath(x-1, y, "r");
        if (x<19-1 && graph.right && map[y][x+1] == " ")
          setPath(x+1, y, "l");
      }
    for (var p of newpts)
      map[p[1]][p[0]] = p[2];
    return newpts.length > 0;
  }
  var tracebackFirst = true;
  var traceback = () =>
  {
    tracePath(playerx, playery, tracebackFirst ? "#ffff00" : "#0000b0");
    tracebackFirst = false;
    switch (map[playery][playerx])
    {
      case "u": playery--; break;
      case "d": playery++; break;
      case "l": playerx--; break;
      case "r": playerx++; break;
      default:
        return false;
    }
    return true;
  }
  var scanTimer = setInterval(() => {
    if (!scan())
      if (!traceback())
      {
        clearInterval(scanTimer);
        setTimeout( ()=>game.paused = false, 10000);
      }
  }, 100);
  //console.log(map.map(x=>x.join("")).join("\n"))
});
