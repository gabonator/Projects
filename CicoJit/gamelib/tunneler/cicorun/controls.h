//extern std::list<int> keyboardBuffer;
extern int lastKey;

void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);

    int key = 0;
    switch (k)
    {
        case SDL_SCANCODE_1: key = 0x3B00; break; // press '1' at startup
        case SDL_SCANCODE_2: key = 0x3C00; break;
        case SDL_SCANCODE_3: key = 0x3D00; break;
//        case SDL_SCANCODE_0: key = 0x4400; break;
        case SDL_SCANCODE_UP: key = 0x4800; break;
        case SDL_SCANCODE_DOWN: key = 0x5000; break;
        case SDL_SCANCODE_LEFT: key = 0x4b00; break;
        case SDL_SCANCODE_RIGHT: key = 0x4d00; break;
        case SDL_SCANCODE_SPACE: key = 0x3920; break;
        case SDL_SCANCODE_RETURN: key = 0x1c0d; break;

        case SDL_SCANCODE_W: key = 0x1100; break;
        case SDL_SCANCODE_S: key = 0x1f00; break;
        case SDL_SCANCODE_A: key = 0x1e00; break;
        case SDL_SCANCODE_D: key = 0x2000; break;
        case SDL_SCANCODE_0: key = 0x0100; break;

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

    if (k == SDL_SCANCODE_1)
        lastKey = k ? key : 0;
    else
        CicoContext::ctx->memory8(0x0ac3, (key >>8) + 5360) = p;
//    if (key && k == SDL_SCANCODE_1)
//    {
//        lastKey = key;
////        keyboardBuffer.push_back(key);
//    }
}



/*
 
 memoryASet(0x0ac3, scancode + 5360, 0x01);
 
 ax = 0x0ac3;
 ds = ax;
 //in(al, 0x60);
 al = scancode;
 memoryASet(ss, bp - 1, al);
 in(al, 0x61);
 al |= 0x80;
 out(0x61, al);
 in(al, 0x61);
 al &= 0x7f;
 out(0x61, al);
 al = memoryAGet(ss, bp - 1);
 al &= 0x80;
 if (al)
     goto loc_8ca5;
 al = memoryAGet(ss, bp - 1);
 ah = 0;
 di = ax;
 memoryASet(ds, di + 5360, 0x01);

 */
