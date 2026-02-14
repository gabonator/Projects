document.onkeydown = evt => {
  if (onKey(evt.keyCode, 1))
    evt.preventDefault();
}
document.onkeyup = evt => {
  if (onKey(evt.keyCode, 0))
    evt.preventDefault();
}

function onKey(code, p)
{
  const SDL_SCANCODE_SPACE = 32;
  const SDL_SCANCODE_RETURN = 13;
  const SDL_SCANCODE_LEFT = 37;
  const SDL_SCANCODE_RIGHT = 39;
  const SDL_SCANCODE_UP = 38;
  const SDL_SCANCODE_DOWN = 40;
  const SDL_SCANCODE_LCTRL = 17;
//80 (up) 88 (left) 71 (esc) 8c (enter) 8e (enter) ec (enter)
// 70..80, 80..90 .. 90..9f
// 0x30b118 0x30b120 0x30b11d 0x30b11b
  switch (code)                     
  {
      case SDL_SCANCODE_LEFT: 
        memoryASet(0, 0x30b11b, p);
        memoryASet(0, 0x30b088, p); break;
      case SDL_SCANCODE_RIGHT: 
        memoryASet(0, 0x30b11d, p);
        memoryASet(0, 0x30b089, p); break;
      case SDL_SCANCODE_UP: 
        memoryASet(0, 0x30b118, p);
        memoryASet(0, 0x30b080, p); break;
      case SDL_SCANCODE_DOWN: memoryASet(0, 0x30b120, p); break;
      case SDL_SCANCODE_SPACE: memoryASet(0, 0x30b0ec, p); break;
    default:
      return false;
  }
  return true;   
}

function tst(k)
{
memoryASet(0, k, 1);
setTimeout(()=>memoryASet(0, k, 0), 100);
}