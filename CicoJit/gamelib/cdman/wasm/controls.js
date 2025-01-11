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
    case "D".charCodeAt(0): autopilotDemo = true; break;
    default:
      return false;
  }
  return true;   
}
