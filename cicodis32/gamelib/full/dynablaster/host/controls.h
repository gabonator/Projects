void cbit(int seg, int ofs, int b, int l)
{
    uint8_t v = memoryAGet(seg, ofs);
    if (l)
        v |= b;
    else
        v &= ~b;
    memoryASet(seg, ofs, v);
}

void onKey(int k, int p)
{
#ifndef HEADLESS
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
    switch (k)
    {
        case SDL_SCANCODE_UP: cbit(0x0b52, 0x37f7, 1, p); break;
        case SDL_SCANCODE_DOWN: cbit(0x0b52, 0x37f7, 2, p); break;
        case SDL_SCANCODE_LEFT: cbit(0x0b52, 0x37f7, 4, p); break;
        case SDL_SCANCODE_RIGHT: cbit(0x0b52, 0x37f7, 8, p); break;
        case SDL_SCANCODE_SPACE: cbit(0x0b52, 0x37f7, 16, p); break;
        case SDL_SCANCODE_1: cbit(0x0b52, 0x37f7, 32, p); break;
        case SDL_SCANCODE_2: cbit(0x0b52, 0x37f7, 64, p); break;
        case SDL_SCANCODE_3: cbit(0x0b52, 0x37f7, 128, p); break;

        case SDL_SCANCODE_T: cbit(0x0b52, 0x37f1, 1, p); break;
        case SDL_SCANCODE_G: cbit(0x0b52, 0x37f1, 2, p); break;
        case SDL_SCANCODE_F: cbit(0x0b52, 0x37f1, 4, p); break;
        case SDL_SCANCODE_H: cbit(0x0b52, 0x37f1, 8, p); break;
        case SDL_SCANCODE_R: cbit(0x0b52, 0x37f1, 16, p); break;

        case SDL_SCANCODE_W: cbit(0x0b52, 0x37f8, 1, p); break;
        case SDL_SCANCODE_S: cbit(0x0b52, 0x37f8, 2, p); break;
        case SDL_SCANCODE_A: cbit(0x0b52, 0x37f8, 4, p); break;
        case SDL_SCANCODE_D: cbit(0x0b52, 0x37f8, 8, p); break;
        case SDL_SCANCODE_LSHIFT: cbit(0x0b52, 0x37f8, 16, p); break;
    }

    // Menu keyboard input (INT 0x16)
    if (p)
    {
        switch (k)
        {
            case SDL_SCANCODE_RETURN: lastKey = 0x1c0d; break;
            case SDL_SCANCODE_UP: lastKey = 0x4800; break;
            case SDL_SCANCODE_DOWN: lastKey = 0x5000; break;
            case SDL_SCANCODE_LEFT: lastKey = 0x4b00; break;
            case SDL_SCANCODE_RIGHT: lastKey = 0x4d00; break;
            case SDL_SCANCODE_SPACE: lastKey = 0x3920; break;
        }
    }
#endif
}
