void onKey(int k, int p)
{
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
    switch (k)
    {
case SDL_SCANCODE_UP: CicoContext::ctx->memory8(0x168f, 0x488) = p; break; // up
case SDL_SCANCODE_DOWN: CicoContext::ctx->memory8(0x168f, 0x490) = p; break; // down
case SDL_SCANCODE_RIGHT: CicoContext::ctx->memory8(0x168f, 0x48d) = p; break; // left
case SDL_SCANCODE_LEFT: CicoContext::ctx->memory8(0x168f, 0x48b) = p; break; // right
case SDL_SCANCODE_SPACE: CicoContext::ctx->memory8(0x168f, 0x45c) = p;
            CicoContext::ctx->memory8(0x168f, 0x042b) = p; break; // enter
    }
}

