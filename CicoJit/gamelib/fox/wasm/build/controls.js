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
    case 38: cbit(0x168f, 0x488, pressed); break;
    case 40: cbit(0x168f, 0x490, pressed); break;
    case 37: cbit(0x168f, 0x48b, pressed); break;
    case 39: cbit(0x168f, 0x48d, pressed); break;
    case 32: cbit(0x168f, 0x45c, pressed); 
             cbit(0x168f, 0x042b, pressed); 
    break;
    default:
      return false;
  }
  return true;   
}
