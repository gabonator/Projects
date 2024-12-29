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
  var cbit = (seg, ofs, b, e) => e ? game.memoryBuffer[seg*16+ofs] |= b : game.memoryBuffer[seg*16+ofs] &= ~b;
  switch (code)                     
  {
    case 38: cbit(0x1040, 0xB884, 8, pressed); break;
    case 40: cbit(0x1040, 0xB884, 4, pressed); break;
    case 37: cbit(0x1040, 0xB884, 2, pressed); break;
    case 39: cbit(0x1040, 0xB884, 1, pressed); break;
    case 32: cbit(0x1040, 0xB884, 16, pressed); 
      game.memoryBuffer[0x10400 + 0xa85e] = pressed ? 0 : 0xff; break;
    default:
      return false;
  }
  return true;   
}
