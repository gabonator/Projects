void onKey(int k, int p)
{
//    if (p && k == SDL_SCANCODE_RETURN)
//        keyboardBuffer.push_back(0x1c0d);
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
        
    int code = 0;
    switch (k)
    {
        case SDL_SCANCODE_UP: code = 1; break;
        case SDL_SCANCODE_DOWN: code = 2; break;
        case SDL_SCANCODE_LEFT: code = 4; break;
        case SDL_SCANCODE_RIGHT: code = 8; break;
        case SDL_SCANCODE_SPACE: code = 0x80;
            if (p && !(CicoContext::ctx->memory8(0x2853, 0x8f59) & 0x80))
                CicoContext::ctx->memory8(0x2853, 0x8F5B) = 0xff;
            break;
        case SDL_SCANCODE_A: CicoContext::ctx->memoryASet16(0x2853, 0x9190, CicoContext::ctx->memoryAGet16(0x2853, 0x9190) - 0x100); break;
        case SDL_SCANCODE_B: code = 0x20; break;
        case SDL_SCANCODE_C: code = 0x40; break;
            
        case SDL_SCANCODE_RETURN: code = 0x80;
            CicoContext::ctx->memory8(0x2853, 0x8f5b) = 0xff; break;
    }
    if (p)
        CicoContext::ctx->memory8(0x2853, 0x8f59) |= code;
    else
        CicoContext::ctx->memory8(0x2853, 0x8f59) &= ~code;    
}
