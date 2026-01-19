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
    case SDL_SCANCODE_LEFT: memoryASet(0, memoryAGet32(0, 0x40d1a4)+82, p); break;
    case SDL_SCANCODE_RIGHT: memoryASet(0, memoryAGet32(0, 0x40d1a4)+83, p); break;
    case SDL_SCANCODE_UP: memoryASet(0, memoryAGet32(0, 0x40d1a4)+84, p); break;
    case SDL_SCANCODE_DOWN: memoryASet(0, memoryAGet32(0, 0x40d1a4)+85, p); break;
    case SDL_SCANCODE_RETURN: memoryASet(0, memoryAGet32(0, 0x40d1a4)+67, p); break;
    case SDL_SCANCODE_SPACE: memoryASet(0, memoryAGet32(0, 0x40d1a4)+75, p); break;
    default:
      return false;
  }
  return true;   
}
