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
  switch (code)                     
  {
            case SDL_SCANCODE_SPACE: memoryASet(0x30d4, 0xc643, p); break;
            case SDL_SCANCODE_RETURN: memoryASet(0x30d4, 0xa545, p ? 0x1c : 0);break;
            case SDL_SCANCODE_LEFT: memoryASet(0x30d4, 0xc647+0x4b*2, p); break;
            case SDL_SCANCODE_RIGHT: memoryASet(0x30d4, 0xc647+0x4d*2, p); break;
            case SDL_SCANCODE_UP: memoryASet(0x30d4, 0xc647+0x48*2, p); break;
            case SDL_SCANCODE_DOWN: memoryASet(0x30d4, 0xc647+0x50*2, p); break;
            case SDL_SCANCODE_LCTRL: memoryASet(0x30d4, 0xc647+0x1d*2, p); break;
    default:
      return false;
  }
  return true;   
}
