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
    case 38: cbit(8, pressed); break;
    case 40: cbit(4, pressed); break;
    case 37: cbit(2, pressed); break;
    case 39: cbit(1, pressed); break;
    case 32: cbit(16, pressed); break;
    case 16: {
      if (!userShift && pressed)
        userShiftFrames = gameLive.pathLength();
      userShift = pressed ? new Date().getTime() : 0;
      break;
    }
    case "D".charCodeAt(0): document.querySelector("#overlay").classList.remove("hidden"); break;
    default:
      return false;
  }
  return true;   
}

function applyState(game_memoryBuffer, state)
{
  game_memoryBuffer[0x10400 + 0xB884] = state;
  game_memoryBuffer[0x10400 + 0xa85e] = state & 16 ? 0 : 0xff;
}
