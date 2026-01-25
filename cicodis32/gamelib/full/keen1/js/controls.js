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
    const SDL_SCANCODE_LALT = 18;
    const SDL_SCANCODE_ESC = 27;
    const SDL_SCANCODE_G = 34;  // SDL scancode for 'G'
    const SDL_SCANCODE_O = 24;  // SDL scancode for 'O'
    const SDL_SCANCODE_D = 32;  // SDL scancode for 'D'

    let scancode = 0;
    switch (code)
    {
        case SDL_SCANCODE_SPACE: scancode = 0x39; break;
        case SDL_SCANCODE_UP: scancode = 0x48; break;
        case SDL_SCANCODE_LEFT: scancode = 0x4b; break;
        case SDL_SCANCODE_RIGHT: scancode = 0x4d; break;
        case SDL_SCANCODE_DOWN: scancode = 0x50; break;
        case SDL_SCANCODE_LCTRL: scancode = 0x1d; break;
        case SDL_SCANCODE_ESC: scancode = 0x1c; break;
        case SDL_SCANCODE_LALT: scancode = 0x38; break;
        case SDL_SCANCODE_RETURN: scancode = 0x1c; break;

        // Added letters
        case SDL_SCANCODE_G: scancode = 0x22; break; // example scancode for 'G'
        case SDL_SCANCODE_O: scancode = 0x18; break; // example scancode for 'O'
        case SDL_SCANCODE_D: scancode = 0x20; break; // example scancode for 'D'
    }

    if (scancode)
    {
        if (p)
        {
            memoryASet(0x14f2, 0x50ac, scancode);
            memoryASet(0x14f2, 0x50ac, memoryAGet(0x14f2, 0x50ac) | 0x80);
        }
        memoryASet(0x14f2, scancode + 20524, p);
        return true;
    }

    return false;   
}
