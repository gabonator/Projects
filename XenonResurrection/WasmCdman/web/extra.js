var pacMap = [];
pacClear();

  setInterval(() => {
    pacAuto();
  }, 100);

function pacAuto()
{
    var ppos = pacPos();
    if (ppos && pacMap[ppos.y][ppos.x] != ' ')
    {
      if (pacMap[ppos.y][ppos.x] == 'S')
        pacClear();
      else
        pacGo(pacMap[ppos.y][ppos.x]);
    }

}

function pacPos()
{                               
    var pos = memory[memoryPtr+0x190] + memory[memoryPtr+0x191]*256;
    var px = (pos - 22)%21;
    var py = Math.floor((pos - 22)/21);
    var mask = memory[memoryPtr+pos + 124];    // right, left, down, up
    if (px >= 0 && py >= 0 && px < 19 && py < 13)
      return {x:px, y:py, mask:[mask&16, mask&32, mask&64, mask&128].map(x=>x?"1":"0").join("")};
}

function pacPath(x, y)
{
  var pos = y*21+x+22;
  var mask = memory[memoryPtr+pos + 124];    // right, left, down, up
  return {up:(mask & 128) ? true : false,
    down:(mask & 64) ? true : false,
    left:(mask & 32) ? true : false,
    right:(mask & 16) ? true : false};
}


function pacGo(dir)
{
  var d = -1;
        if (dir == 'r')
            d = 0;
        if (dir == 'l')
            d = 8;
        if (dir == 'u')
            d = 24;
        if (dir == 'd')
            d = 16;
        if (d!=-1)
           memory[memoryPtr+0x18E] = d;
}

function pacMapSet(x, y, v)
{          
//  if (v>=15)
//    return;          
  if (pacMap[y][x] != ' ')
    return;
  pacMap[y][x] = v;
  var path = pacPath(x, y);

  v++;
  if (path.up)
    pacMapSet(x, y-1, 'd');
  if (path.down)
    pacMapSet(x, y+1, 'u');
  if (path.left)
    pacMapSet(x-1, y, 'r');
  if (path.right)
    pacMapSet(x+1, y, 'l');
}

function pacClear()
{
  for (var y=0; y<13; y++)
  {
    pacMap[y] = [];
    for (var x=0; x<19; x++)    
      pacMap[y][x] = ' ';
  }
}

function pacClick(sx, sy)
{
  window.miniApp.lastKey = 0x1c0d;

  pacClear();
  pacMap[sy][sx] = 'S';
  var pac = pacPos();

  for (var i=0; i<30; i++)
  {
    var oldMap = [];
    for (var y=0; y<13; y++)
      oldMap[y] = [...pacMap[y]];
        
    for (var y=0; y<13; y++)
      for (var x=0; x<19; x++)    
        if (oldMap[y][x] != ' ')
        {
          pacMap[y][x] = oldMap[y][x];
          var path = pacPath(x, y);
          if (path.up && pacMap[y-1][x] == ' ')
            pacMap[y-1][x] = 'd';
          if (path.down && pacMap[y+1][x] == ' ')
            pacMap[y+1][x] = 'u';
          if (path.right && pacMap[y][x+1] == ' ')
            pacMap[y][x+1] = 'l';
          if (path.left && pacMap[y][x-1] == ' ')
            pacMap[y][x-1] = 'r';
        }
     if (pacMap[pac.y][pac.x] != ' ')
       break;     
  }


//  for(var y=0; y<13; y++)
//    console.log(pacMap[y].join(""));
}






function mousepos(evt)
{
  var rect = document.querySelector("#canvas").getBoundingClientRect();
  var x = evt.clientX, y = evt.clientY;
  if ( evt.changedTouches ) 
  {
    x = evt.changedTouches[0].screenX*2; // iphone4
    y = evt.changedTouches[0].screenY*2;
  }
  x = (x - rect.left)*640/rect.width;
  y = (y - rect.top)*350/rect.height;
  return {x:Math.floor(x), y:Math.floor(y)};
}

canvas.addEventListener('mousedown', _mousedown, false);
canvas.addEventListener('touchstart', _mousedown, false);
canvas.addEventListener('mouseup', _mouseup, false);
canvas.addEventListener('touchend', _mouseup, false);

function _mousedown(evt) 
{
  evt.preventDefault();
  var pos = mousepos(evt);
  
  var x = Math.floor((pos.x - 16)/32);
  var y = Math.floor((pos.y - 58)/24);
  pacClick(x, y);
}

function _mouseup(evt)
{
  evt.preventDefault();
}
