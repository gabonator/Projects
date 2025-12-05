void sync()
{
    video->sync();
    int x = memoryAGet16(ds, 0xa53d);
    x += 5;
    memoryASet16(ds, 0xa53d, x);
    if (x >= 0x10000)
        memoryASet16(ds, 0xa53e, memoryAGet16(ds, 0xa53e)+1);
}

void onKey(int k, int p)
{
    if (strstr(root, "keen4."))
    {
        int scancode = 0;
        switch (k)
        {
            case SDL_SCANCODE_SPACE: memoryASet(0x30d4, 0xc643, p); break;
//            case SDL_SCANCODE_UP: memoryASet(0x30d4, 0xa545, p ? 0x48 : 0); break;
            //case SDL_SCANCODE_DOWN: memoryASet(0x30d4, 0xa545, p ? 0x50 : 0); break;
            case SDL_SCANCODE_RETURN: memoryASet(0x30d4, 0xa545, p ? 0x1c : 0);break;
//            case SDL_SCANCODE_LEFT: memoryASet(0x30d4, 0xc6dd, p); break;
//            case SDL_SCANCODE_RIGHT: memoryASet(0x30d4, 0xc6e1, p); break;
            case SDL_SCANCODE_LEFT: memoryASet(0x30d4, 0xc647+0x4b*2, p); break;
            case SDL_SCANCODE_RIGHT: memoryASet(0x30d4, 0xc647+0x4d*2, p); break;
            case SDL_SCANCODE_UP: memoryASet(0x30d4, 0xc647+0x48*2, p); break;
            case SDL_SCANCODE_DOWN: memoryASet(0x30d4, 0xc647+0x50*2, p); break;
            case SDL_SCANCODE_LCTRL: memoryASet(0x30d4, 0xc647+0x1d*2, p); break;
        }
    }
}