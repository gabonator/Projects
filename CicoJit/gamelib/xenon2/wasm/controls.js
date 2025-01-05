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
    case 38: cbit(0x2853, 0x8f59, 1, pressed); break;
    case 40: cbit(0x2853, 0x8f59, 2, pressed); break;
    case 37: cbit(0x2853, 0x8f59, 4, pressed); break;
    case 39: cbit(0x2853, 0x8f59, 8, pressed); break;
    case 32: cbit(0x2853, 0x8f59, 128, pressed); 
      game.memoryBuffer[0x28530 + 0x8F5B] = pressed ? 0xff : 0; 
    break;
    default:
      return false;
  }
  return true;   
}
