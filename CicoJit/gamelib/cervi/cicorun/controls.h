extern int lastKey;
void onKey(int k, int p)
{
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
    switch (k)
    {
        case SDL_SCANCODE_UP:lastKey = 0x4800; break; // up
        case SDL_SCANCODE_DOWN: lastKey = 0x5000; break; // down
//        case SDL_SCANCODE_1: lastKey == 'H'<<8; break; // down
//        case SDL_SCANCODE_2: lastKey == 'M'<<8; break; // down
        case SDL_SCANCODE_N: lastKey == 'N'<<8; break; // down
        case SDL_SCANCODE_M: lastKey == 'M'<<8; break; // down
            // 58, 29, 49
            // 50, 42, 56
case SDL_SCANCODE_RIGHT: CicoContext::ctx->memory8(0xba6, 0x20d0+42) = p; break; // left
case SDL_SCANCODE_LEFT: CicoContext::ctx->memory8(0xba6, 0x20d0+58) = p; break; // right
        case SDL_SCANCODE_Z: CicoContext::ctx->memory8(0xba6, 0x20d0+29) = p; break; // left
        case SDL_SCANCODE_X: CicoContext::ctx->memory8(0xba6, 0x20d0+56) = p; break; // right
        case SDL_SCANCODE_A: lastKey='A'; break; // enter
        case SDL_SCANCODE_D: lastKey='D'; break; // enter
        case SDL_SCANCODE_SPACE: lastKey='\r'; break; // enter
    }
}

// 66 46 49 69
