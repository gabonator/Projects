//extern std::list<int> keyboardBuffer;
extern int lastKey;

void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
    if (!p)
        return;

    int key = 0;
    switch (k)
    {
        case SDL_SCANCODE_1: key = 0x3B00; break; // press '1' at startup
        case SDL_SCANCODE_2: key = 0x3C00; break;
        case SDL_SCANCODE_3: key = 0x3D00; break;
        case SDL_SCANCODE_0: key = 0x4400; break;
        case SDL_SCANCODE_UP: key = 0x4800; break;
        case SDL_SCANCODE_DOWN: key = 0x5000; break;
        case SDL_SCANCODE_LEFT: key = 0x4b00; break;
        case SDL_SCANCODE_RIGHT: key = 0x4d00; break;
        case SDL_SCANCODE_SPACE: key = 0x3920; break;
        case SDL_SCANCODE_RETURN: key = 0x1c0d; break;
//        case SDL_SCANCODE_5:
//            for (int i=0; i<4; i++)
//            {
//                CicoContext::ctx->memory8(_ds, i + 104) = 0x4d;
//                CicoContext::ctx->memory16(_ds, i*2 + 491) = CicoContext::ctx->memory16(_ds, 0x1059);
//                CicoContext::ctx->memory16(_ds, i*2 + 499) = CicoContext::ctx->memory16(_ds, 0x1059 + 2);
//                CicoContext::ctx->memory16(_ds, i*2 + 507) = CicoContext::ctx->memory16(_ds, 0x1059 + 4);
//            }
//            break;
    }

    if (key)
    {
        lastKey = key;
//        keyboardBuffer.push_back(key);
    }
}

