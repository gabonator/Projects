extern int lastKey;
void sub_25f7(int scancode);

void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
    static int keys = 0;
    int scancode;
    switch (k)
    {
        case SDL_SCANCODE_UP: keys = p ? keys | 8 : keys & ~8; break;
        case SDL_SCANCODE_DOWN: keys = p ? keys | 4 : keys & ~4; break;
        case SDL_SCANCODE_LEFT: keys = p ? keys | 2 : keys & ~2; break;
        case SDL_SCANCODE_RIGHT: keys = p ? keys | 1 : keys & ~1; break;
        case SDL_SCANCODE_RSHIFT:
        case SDL_SCANCODE_LSHIFT:
        case SDL_SCANCODE_Z:
//        case SDL_SCANCODE_SPACE:
//            CicoContext::ctx->memory8(0x2ec1, 0x2b5e) = keys ? (0x31 | 0x80) : 0x31;
//            // if ((short)memoryAGet16(ds, 0x2b5e) < (short)0x0080)
//            lastKey = 1; keys = p ? keys | 16 : keys & ~16; break;
//        //case SDL_SCANCODE_LCTRL:
//        //case SDL_SCANCODE_RCTRL: slowdown = p;
        case SDL_SCANCODE_SPACE: lastKey = 1; scancode = 0x29 + p * 128; break;
        case SDL_SCANCODE_N: scancode = 0x31 + p * 128; break;
    }
//    CicoContext::ctx->memory8(0x1040, 0xB884) = keys;
    if (scancode)
        sub_25f7(scancode);

}

