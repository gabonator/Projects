document.onkeydown = evt => {
  if (onKey(evt.keyCode, 1))
    evt.preventDefault();
}
document.onkeyup = evt => {
  if (onKey(evt.keyCode, 0))
    evt.preventDefault();
}
var keys = [];
function onKey(code, pressed)
{
  var cbit = (seg, ofs, e) => memory[seg*16+ofs] = e;
  var keyMap = [38, 40, 37, 39, 32];
  var scanCode = [0, 0, 0x4b, 0x4d, 0x39]
  if (keyMap.includes(code))
  {
    keys[code] = pressed;
    var latest = keyMap.map((k, i) => keys[k] ? scanCode[i] : 0).find(k=>k)
    memory[0x1b0c*16+0x1339] = latest;
    return true;
  }
  return false;
}
/*
  switch (code)                     
  {
    case 38: cbit(0x1f86, 0x8db4, pressed); break;
    case 40: cbit(0x1f86, 0x92b6, pressed); break;
    case 37: cbit(0x1f86, 0x8baf, pressed); break;
    case 39: cbit(0x1f86, 0x8da6, pressed); break;
    case 32: cbit(0x1f86, 0x92b5, pressed); break;
    case 77: memory[0x1f86*16+0x8b94]=1; break; // m
    default:
      return false;
  }
  return true;
}

document.onmousedown = evt => onKey(32, true)
document.onmouseup = evt => onKey(32, false)
document.ontouchstart = evt => onKey(32, true)
document.ontouchend = evt => onKey(32, false)

new JoyStick('joystick', {}, stickData => {
    onKey(38, stickData.yPosition < 80)
    onKey(40, stickData.yPosition > 120)
    onKey(37, stickData.xPosition < 80)
    onKey(39, stickData.xPosition > 120)
});*/