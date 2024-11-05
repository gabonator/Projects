extern int lastKey;
void onKey(int k, int p)
{
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
    switch (k)
    {
        case SDL_SCANCODE_UP:lastKey = 0x4800; break; // up
        case SDL_SCANCODE_DOWN: lastKey == 0x5000; break; // down
case SDL_SCANCODE_RIGHT: CicoContext::ctx->memory8(0x168f, 0x48d) = p; break; // left
case SDL_SCANCODE_LEFT: CicoContext::ctx->memory8(0x168f, 0x48b) = p; break; // right
        case SDL_SCANCODE_A: lastKey='A'; break; // enter
        case SDL_SCANCODE_SPACE: lastKey='\r'; break; // enter
    }
}

// 66 46 49 69
