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
