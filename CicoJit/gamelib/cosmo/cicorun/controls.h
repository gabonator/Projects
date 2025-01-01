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
        case SDL_SCANCODE_SPACE: CicoContext::ctx->memory8(0x1a91, 0x59e2) = p ? 0x80 : 0; break; // enter
        case SDL_SCANCODE_1: CicoContext::ctx->memory8(0x1a91, 0x59e2) = p ? (0x80+0x1) : 0x1; break; // enter
        case SDL_SCANCODE_2: CicoContext::ctx->memory8(0x1a91, 0x59e2) = p ? (0x80+0x17) : 0x17; break; // enter
        case SDL_SCANCODE_3: CicoContext::ctx->memory8(0x1a91, 0x59e2) = p ? (0x80+0x18) : 0x18; break; // enter
    }
}

// 66 46 49 69

/*
 compare char 0 == 1 '' EXIT
 compare char 0 == 10 '' EXIT
 compare char 0 == 13 '' restore a game
 compare char 0 == 14 '' ?
 compare char 0 == 17 '' instructions
 compare char 0 == 18 ''
 compare char 0 == 1c ''
 compare char 0 == 1e ''
 compare char 0 == 1f ''
 compare char 0 == 20 ' '
 compare char 0 == 21 '!'
 compare char 0 == 22 '"'
 compare char 0 == 23 '#'
 compare char 0 == 2e '.'
 compare char 0 == 30 '0'
 compare char 0 == 39 '9'
 compare char 0 == 57 'W'
 */
