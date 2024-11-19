void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
      switch (k)
      {
          case SDL_SCANCODE_2: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x3c) = p; break;
          case SDL_SCANCODE_3: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x3d) = p; break;
          case SDL_SCANCODE_4: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x3e) = p; break;
          case SDL_SCANCODE_5: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x3f) = p; break;
          case SDL_SCANCODE_6: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x40) = p; break;
          case SDL_SCANCODE_7: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x41) = p; break;
          case SDL_SCANCODE_0: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x01) = p; break;
          case SDL_SCANCODE_UP: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'H') = p; break;
          case SDL_SCANCODE_RIGHT: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'M') = p; break;
          case SDL_SCANCODE_DOWN: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'P') = p; break;
          case SDL_SCANCODE_LEFT: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'K') = p; break;
          case SDL_SCANCODE_SPACE: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x1c) = p; break;
          }
}
