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
  var game = {memoryBuffer:memory}
  var cbit = (seg, ofs, mask, e) => e ? game.memoryBuffer[seg*16+ofs] |= mask : game.memoryBuffer[seg*16+ofs] &= ~mask;
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

/*
function onKey(e, pressed)
{
  var consumed = true;
  switch (e.keyCode)
  {
    case 38: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + "H".charCodeAt(0)] = pressed; break; // up
    case 39: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + "M".charCodeAt(0)] = pressed; break; // right
    case 40: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + "P".charCodeAt(0)] = pressed; break; // down
    case 37: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + "K".charCodeAt(0)] = pressed; break; // left
    case 32: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + 0x1c] = pressed; break; // space -> enter
    case 27: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + 1] = pressed; break; // esc
    case 87: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + 0x11] = pressed; break; // up
    case 83: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + 0x2d] = pressed; break; // down
    case 65: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + 0x1e] = pressed; break; // left
    case 68: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + 0x20] = pressed; break; // right
    case 16: game.memoryBuffer[0x0ac3 * 16 + 0x14f0 + 0x1d] = pressed; break; // fire
    default:
      consumed = false;
  }
  if (consumed)
    e.preventDefault();
}

*/