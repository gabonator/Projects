var userState = 0;
var userShift = 0;
var userShiftFrames = -1;

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
  var cbit = (b, e) => e ? userState |= b : userState &= ~b;
  switch (code)                     
  {
    case 38: cbit(1, pressed); break;
    case 40: cbit(2, pressed); break;
    case 37: cbit(4, pressed); break;
    case 39: cbit(8, pressed); break;
    case 32: cbit(16, pressed); break;
    case "N".charCodeAt(0): cbit(32, pressed); break;
    case "M".charCodeAt(0): cbit(64, pressed); break;
    case 16: {
      if (!userShift && pressed)
        userShiftFrames = gameLive.pathLength();
      userShift = pressed ? new Date().getTime() : 0;
      break;
    }
    default:
      return false;
  }
  return true;   
}

function applyState(game_memoryBuffer, state)
{
  var cbit = (seg, ofs, e) => game_memoryBuffer[seg*16+ofs] = !!e;
  cbit(0x13a5, 0x8e8a+72, state & 1);
  cbit(0x13a5, 0x8e8a+80, state & 2);
  cbit(0x13a5, 0x8e8a+75, state & 4);
  cbit(0x13a5, 0x8e8a+77, state & 8);
  cbit(0x13a5, 0x8e8a+57, state & 16);
  cbit(0x13a5, 0x8e8a+49, state & 32);
  cbit(0x13a5, 0x8e8a+50, state & 64);
}

document.onkeydown = evt => {
  if (onKey(evt.keyCode, 1))
    evt.preventDefault();
}
document.onkeyup = evt => {
  if (onKey(evt.keyCode, 0))
    evt.preventDefault();
}
/*
function onKey(code, pressed)
{
  var cbit = (seg, ofs, e) => game.memoryBuffer[seg*16+ofs] = e;
  switch (code)                     
  {
    case 38: cbit(0x13a5, 0x8e8a+72, pressed); break;
    case 40: cbit(0x13a5, 0x8e8a+80, pressed); break;
    case 37: cbit(0x13a5, 0x8e8a+75, pressed); break;
    case 39: cbit(0x13a5, 0x8e8a+77, pressed); break;
    case 32: cbit(0x13a5, 0x8e8a+57, pressed); break;
    case "N".charCodeAt(0): cbit(0x13a5, 0x8e8a+49, pressed); break;
    case "M".charCodeAt(0): cbit(0x13a5, 0x8e8a+50, pressed); break;
//    case "Q".charCodeAt(0): cbit(0x13a5, 0x8e8a+16, pressed); break;
//    case "Y".charCodeAt(0): cbit(0x13a5, 0x8e8a+21, pressed); break;
    default:
      return false;
  }
  return true;   
}
*/