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
  var cbit = (seg, ofs, e) => memory[seg*16+ofs] = e;
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
