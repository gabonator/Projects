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
            case SDL_SCANCODE_UP: memoryASet(0x168f, 0x488, p); break; // up
            case SDL_SCANCODE_DOWN: memoryASet(0x168f, 0x490, p); break; // down
            case SDL_SCANCODE_RIGHT: memoryASet(0x168f, 0x48d, p); break; // left
            case SDL_SCANCODE_LEFT: memoryASet(0x168f, 0x48b, p); break; // right
            case SDL_SCANCODE_SPACE: memoryASet(0x168f, 0x45c, p);
                memoryASet(0x168f, 0x042b, p); break; // enter
    default:
      return false;
  }
  return true;   
}
