extern std::list<char> keyBuffer;

void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
      if (p)
          switch (k)
          {
              case SDL_SCANCODE_ESCAPE: keyBuffer.push_back(27); break;
              case SDL_SCANCODE_RETURN: keyBuffer.push_back(13); break;
              case SDL_SCANCODE_LEFT:
                 //a57:9c8 = 2|0xfffe, a57:9ca = 0/2
                  keyBuffer.push_back(0);
                  keyBuffer.push_back('M'); break;
              case SDL_SCANCODE_RIGHT:
                  keyBuffer.push_back(0);
                  keyBuffer.push_back('K'); break;
              case SDL_SCANCODE_UP:
                  keyBuffer.push_back(0);
                  keyBuffer.push_back('H'); break;
              case SDL_SCANCODE_DOWN:
                  keyBuffer.push_back(0);
                  keyBuffer.push_back('P'); break;
          }

    switch (k)
    {
        case SDL_SCANCODE_LEFT:
            CicoContext::ctx->memory16(0xa57, 0x9c8) = p ? -2 : 0;
            break;
        case SDL_SCANCODE_RIGHT:
            CicoContext::ctx->memory16(0xa57, 0x9c8) = p ? 2 : 0;
            break;
        case SDL_SCANCODE_UP:
            CicoContext::ctx->memory16(0xa57, 0x9c8+4) = p ? 1 : 0;
            break;
    }
}

