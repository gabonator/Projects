extern int lastKey;
extern int keybMove;
void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);

    switch (k)
    {
        case SDL_SCANCODE_1: lastKey = 0x3b00; break;
        case SDL_SCANCODE_2: lastKey = 0x3c00; break;
        case SDL_SCANCODE_3: lastKey = 0x3d00;  break;
        case SDL_SCANCODE_4: lastKey = 0x3e00;  break;
        case SDL_SCANCODE_5: lastKey = 0x3f00; break;
        case SDL_SCANCODE_6: lastKey = 0x4000; break;
        case SDL_SCANCODE_7: lastKey = 0x4100; break;
        case SDL_SCANCODE_8: lastKey = 0x4200; break;
        case SDL_SCANCODE_9: lastKey = 0x4300;  break;
        case SDL_SCANCODE_0: lastKey = 0x4400; break;
            
        case SDL_SCANCODE_Z: lastKey = 0x4300; break;
        case SDL_SCANCODE_X: lastKey = 0x011b; break;
        case SDL_SCANCODE_C: lastKey = 0x4400; break;
            
    }

    int code = 0;
    switch (k)
    {
        case SDL_SCANCODE_UP: CicoContext::ctx->memory8(0x1000, 0x2d4c) = p; break;
        case SDL_SCANCODE_DOWN:  break;
        case SDL_SCANCODE_LEFT: CicoContext::ctx->memory8(0x1000, 0x2d4e) = p; break;
        case SDL_SCANCODE_RIGHT: CicoContext::ctx->memory8(0x1000, 0x2d4d) = p; break;
        case SDL_SCANCODE_SPACE: CicoContext::ctx->memory8(0x1000, 0x2d4c) = p; break;
    }
}

