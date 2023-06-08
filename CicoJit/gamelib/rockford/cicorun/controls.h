extern int lastKey;
void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
    static int keys = 0;
    switch (k)
    {
        case SDL_SCANCODE_UP:
            CicoContext::ctx->memory8(0x2cfb, 0x001a) = p;
            keys = p ? keys | 8 : keys & ~8; break;
        case SDL_SCANCODE_DOWN:
            CicoContext::ctx->memory8(0x2cfb, 0x001b) = p;

            keys = p ? keys | 4 : keys & ~4; break;
        case SDL_SCANCODE_LEFT:
            CicoContext::ctx->memory8(0x2cfb, 0x001c) = p;
            
            keys = p ? keys | 2 : keys & ~2; break;
            
        case SDL_SCANCODE_RIGHT:
            CicoContext::ctx->memory8(0x2cfb, 0x001d) = p;
            keys = p ? keys | 1 : keys & ~1; break;
        case SDL_SCANCODE_RSHIFT:
        case SDL_SCANCODE_LSHIFT:
        case SDL_SCANCODE_Z:
        case SDL_SCANCODE_SPACE: keys = p ? keys | 16 : keys & ~16; break;
        //case SDL_SCANCODE_LCTRL:
        //case SDL_SCANCODE_RCTRL: slowdown = p;
        case SDL_SCANCODE_Y: lastKey = 0x79; break;
        case SDL_SCANCODE_N: lastKey = 0x6e; break;
        case SDL_SCANCODE_RETURN: lastKey = 0x0d; break;
        case SDL_SCANCODE_Q: lastKey = 0x71; break;
        case SDL_SCANCODE_W: lastKey = 0x51; break;
//        case SDL_SCANCODE_E: CicoContext::ctx->memory8(0x1000, 0x35ac) = p ? 0xff : 0; break;
    }
    CicoContext::ctx->memory8(0x1040, 0xB884) = keys;
}

