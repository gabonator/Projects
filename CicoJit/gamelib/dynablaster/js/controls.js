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
  var cbit = (seg, ofs, mask, e) => e ? memory[seg*16+ofs] |= mask : memory[seg*16+ofs] &= ~mask;
  switch (code)                     
  {
    case 38: cbit(0x0b52, 0x37f7, 1, pressed); break;
    case 40: cbit(0x0b52, 0x37f7, 2, pressed); break;
    case 37: cbit(0x0b52, 0x37f7, 4, pressed); break;
    case 39: cbit(0x0b52, 0x37f7, 8, pressed); break;
    case 32: cbit(0x0b52, 0x37f7, 16, pressed); break;
    case 87: cbit(0x0b52, 0x37f8, 1, pressed); break;
    case 83: cbit(0x0b52, 0x37f8, 2, pressed); break;
    case 65: cbit(0x0b52, 0x37f8, 4, pressed); break;
    case 68: cbit(0x0b52, 0x37f8, 8, pressed); break;
    case 16: cbit(0x0b52, 0x37f8, 16, pressed); break;
    default:
      return false;
  }
  return true;   
}
