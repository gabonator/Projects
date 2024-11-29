void cbit(uint8_t& v, int b, int l)
{
    if (l)
        v |= b;
    else
        v &= ~b;
}
void onKey(int k, int p)
{
//    memoryASet(0x0b52, 0x37f7, bh);
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
      switch (k)
      {
          case SDL_SCANCODE_UP: cbit(CicoContext::ctx->memory8(0x0b52, 0x37f7), 1, p); break;
          case SDL_SCANCODE_DOWN: cbit(CicoContext::ctx->memory8(0x0b52, 0x37f7), 2, p);break;
          case SDL_SCANCODE_LEFT: cbit(CicoContext::ctx->memory8(0x0b52, 0x37f7), 4, p); break;
          case SDL_SCANCODE_RIGHT: cbit(CicoContext::ctx->memory8(0x0b52, 0x37f7), 8, p); break;
          case SDL_SCANCODE_SPACE: cbit(CicoContext::ctx->memory8(0x0b52, 0x37f7), 16, p); break;
          case SDL_SCANCODE_1: cbit(CicoContext::ctx->memory8(0x0b52, 0x37f7), 32, p); break;
          case SDL_SCANCODE_2: cbit(CicoContext::ctx->memory8(0x0b52, 0x37f7), 64, p); break;
          case SDL_SCANCODE_3: cbit(CicoContext::ctx->memory8(0x0b52, 0x37f7), 128, p); break;
//          case SDL_SCANCODE_UP: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'H') = p; break;
//          case SDL_SCANCODE_RIGHT: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'M') = p; break;
//          case SDL_SCANCODE_DOWN: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'P') = p; break;
//          case SDL_SCANCODE_LEFT: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'K') = p; break;
//          case SDL_SCANCODE_SPACE: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x1c) = p; break;
          }
}
