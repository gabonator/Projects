var autopilotMap = null;
var autopilotTimer = null;
var autopilotDemo = false;

function pacGraphAt(x, y)
{
  if (x < 0 || x >= 20 || y < 0 || y >= 12)
    return {up: 0, down: 0, left: 0, right: 0};

  var mask = game.memoryBuffer[0x10200 + 124 + y*21+x+22];
  return {up: !!(mask & 128), down: !!(mask & 64), left: !!(mask & 32), right: !!(mask & 16)}
}

function autopilotSet(targetx, targety)
{
  autopilotMap = [...Array(12)].map(e => Array(20).fill(false));
  autopilotMap[targety][targetx] = 'S';
  var newpts;

  do {
    newpts = [];
    for (var y=0; y<11; y++)
      for (var x=0; x<19; x++) {
        if (!autopilotMap[y][x])
          continue;

        var graph = pacGraphAt(x, y);
        if (graph.up && !autopilotMap[y-1][x])
          newpts.push({x:x, y:y-1, c:"d"});
        if (graph.down && !autopilotMap[y+1][x])
          newpts.push({x:x, y:y+1, c:"u"});
        if (graph.left && !autopilotMap[y][x-1])
          newpts.push({x:x-1, y:y, c:"r"});
        if (graph.right && !autopilotMap[y][x+1])
          newpts.push({x:x+1, y:y, c:"l"});
      }

    for (var p of newpts)
      if (!autopilotMap[p.y][p.x])
        autopilotMap[p.y][p.x] = p.c;
  } while (newpts.length > 0)

  clearInterval(autopilotTimer);
  autopilotTimer = setInterval(autopilot, 50)
}

function autopilot()
{
  let {x, y} = getState();
  if (!autopilotMap)
  {
    clearInterval(autopilotTimer);
    return;
  }
  var c = autopilotMap[y][x];
  if (!c || c == "S")
  {
    clearInterval(autopilotTimer);
    autopilotMap = null;
    return;
  }
  onKey({"u":38, "d":40, "l":37, "r":39}[c], 1)
}

// demo
async function wait(ms)
{
  return new Promise(resolve=>setTimeout(resolve, ms));
}

async function renderGrid()
{
  var bx = 16, by = 58;
  var sx = 32, sy = 24;
  bx *= 1.5; by *= 1.5; sx *= 1.5; sy *= 1.5;
  var container = document.querySelector("#container");
  canvas.style = "position: absolute; width:960px; height:525px;";
  const overlay = document.createElement('canvas');
  overlay.id = "overlay";
  overlay.width = 960;
  overlay.height = 525;
  overlay.style = "position:absolute;";
  container.appendChild(overlay);
  overlay.classList.add('transition')
  var ctx = overlay.getContext('2d');
  
  ctx.lineWidth = 3
  ctx.strokeStyle = "#202020";
  for (var y=0; y<=12; y++)
    for (var x=0; x<=20; x++)
    {
      if (y < 12 && x < 19)
      {
        ctx.beginPath();
        ctx.moveTo(bx+x*sx, by+y*sy);
        ctx.lineTo(bx+(x+1)*sx, by+y*sy);
        ctx.stroke();
      }
      if (x<20 && y < 11)
      {
        ctx.beginPath();
        ctx.moveTo(bx+x*sx, by+y*sy);
        ctx.lineTo(bx+x*sx, by+(y+1)*sy);
        ctx.stroke();
      }
    }

  await wait(500);
  overlay.classList.toggle('visible')
  ctx.strokeStyle = "#b0b0b0";
  for (var y=0; y<=12; y++)
    for (var x=0; x<=20; x++)
    {
      var top = pacGraphAt(x, y).up && pacGraphAt(x, y-1).down
      if (y < 12 && x < 19 && !top)
      {
        ctx.beginPath();
        ctx.moveTo(bx+x*sx, by+y*sy);
        ctx.lineTo(bx+(x+1)*sx, by+y*sy);
        ctx.stroke();
      }
      var left = pacGraphAt(x, y).left && pacGraphAt(x-1, y).right
      if (x<20 && y < 11 && !left)
      {
        ctx.beginPath();
        ctx.moveTo(bx+x*sx, by+y*sy);
        ctx.lineTo(bx+x*sx, by+(y+1)*sy);
        ctx.stroke();
      }
    }
  return ctx;
}

document.querySelector("#canvas").addEventListener("click", async evt => {
  var bx = 16, by = 58;
  var sx = 32, sy = 24;
  var blkx = Math.floor((evt.offsetX/1.5-bx)/sx)
  var blky = Math.floor((evt.offsetY/1.5-by)/sy)
  autopilotSet(blkx, blky);
  if (autopilotDemo)
    autopilotDemo = false;
  else
    return;

  bx *= 1.5; by *= 1.5; sx *= 1.5; sy *= 1.5;

  var playerx = getState().x, playery = getState().y;
  if (playerx < 0 || playerx >= 20 || playery < 0 || playery >= 12)
    return;

  if (blkx < 0 || blkx >= 20 || blky < 0 || blky >= 12)
    return;

  var map; 
  var newpts;

  var reset = () => {
    map = [...Array(12)].map(e => Array(20).fill(" "));
    map[blky][blkx] = 'S';
    newpts = [];
  }
  var fill = (x, y, c) => {
    ctx.fillStyle = c;
    ctx.fillRect(bx+x*sx, by+y*sy, sx, sy);
  }
  var setPath = (x, y, c, rev, clr) => {
    if (newpts.find(p=>p[0] == x && p[1] == y))
      return;
    newpts.push([x, y, c]);
    ctx.font = "30px Arial";
    ctx.fillStyle = clr;
    if (rev)
     c = {"r":"l", "l":"r", "u":"d", "d":"u", "S":"S"}[c];

    var syms = {"r": "\u2190", "l": "\u2192", "d": "\u2191", "u": "\u2193", "S" : "\u2605"}
    var symx = {"r": 9, "l": 9, "d": 17, "u": 17, "S": 9};
    var symy = {"r": 25, "l": 25, "d": 24, "u": 24, "S": 27};
    ctx.clearRect(bx+x*sx+4, by+y*sy+4, sx-8, sy-8);
    ctx.fillText(syms[c], bx+x*sx+symx[c], by+y*sy+symy[c]);
  }
  var scan = (rev) =>
  {
    newpts = [];
    for (var y=0; y<11; y++)
      for (var x=0; x<19; x++)
      {
        if (map[y][x] == " ")
          continue;
        var graph = pacGraphAt(x, y);
        if (y>0 && graph.up && map[y-1][x] == " ")
          setPath(x, y-1, "d", rev, "#ffffff");
        if (y<11-1 && graph.down && map[y+1][x] == " ")
          setPath(x, y+1, "u", rev, "#ffffff");
        if (x>0 && graph.left && map[y][x-1] == " ")
          setPath(x-1, y, "r", rev, "#ffffff");
        if (x<19-1 && graph.right && map[y][x+1] == " ")
          setPath(x+1, y, "l", rev, "#ffffff");
      }
    for (var p of newpts)
      map[p[1]][p[0]] = p[2];
    return newpts.length > 0;
  }
  var tracebackFirst = true;
  var traceback = () =>
  {
    setPath(playerx, playery, map[playery][playerx], true, "#ff0000")
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

  game.paused = true;
  var ctx = await renderGrid();
  fill(blkx, blky, "#00ff0080")

  await wait(5000);
  reset();
  scan(false);
  await wait(2000);
  scan(false);
  await wait(2000);
  scan(false);
  await wait(2000);
  scan(false);
  await wait(2000);
  while (scan(false))
    await wait(500);
  await wait(2000);
  reset();
  while (scan(true));
  await wait(2000);
  while (traceback(false))
    await wait(500);
  await wait(2000);
  game.paused = false
  overlay.classList.toggle('visible')
  await wait(2500);
  document.querySelector("#container").removeChild(document.querySelector("#overlay"));
});
