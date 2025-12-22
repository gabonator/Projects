extern uint8_t appMemory[];

void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
    static int keys = 0;
    switch (k)
    {
        case SDL_SCANCODE_UP: keys = p ? keys | 8 : keys & ~8; break;
        case SDL_SCANCODE_DOWN: keys = p ? keys | 4 : keys & ~4; break;
        case SDL_SCANCODE_LEFT: keys = p ? keys | 2 : keys & ~2; break;
        case SDL_SCANCODE_RIGHT: keys = p ? keys | 1 : keys & ~1; break;
        case SDL_SCANCODE_RSHIFT:
        case SDL_SCANCODE_LSHIFT:
        case SDL_SCANCODE_Z:
        case SDL_SCANCODE_SPACE:
            appMemory[0x1040*16+ 0xa85e] = p ? 0 : 0xff;
            
            keys = p ? keys | 16 : keys & ~16; break;
    }
    appMemory[0x1040*16+ 0xB884] = keys;
}

