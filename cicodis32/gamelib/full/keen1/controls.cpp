void onKey(int k, int p)
{
    int scancode = 0;
    switch (k)
    {
        case SDL_SCANCODE_SPACE: scancode = 0x39; break;
        case SDL_SCANCODE_UP: scancode = 0x48; break;
        case SDL_SCANCODE_LEFT: scancode = 0x4b; break;
        case SDL_SCANCODE_RIGHT: scancode = 0x4d; break;
        case SDL_SCANCODE_DOWN: scancode = 0x50; break;
        case SDL_SCANCODE_LCTRL: scancode = 0x1d; break;
        case SDL_SCANCODE_1: scancode = 0x1c; break;
        case SDL_SCANCODE_LALT: scancode = 0x38; break;
    }
    if (scancode)
    {
        if (p)
        {
            memoryASet(0x14f2, 0x50ac, scancode);
            memoryASet(0x14f2, 0x50ac, memoryAGet(0x14f2, 0x50ac) | 0x80);
        }
        memoryASet(0x14f2, scancode + 20524, p);
    }
}

void sync()
{
    memoryASet16(ds, 0x5135, memoryAGet16(ds, 0x5135) + 6);
    int t = memoryAGet16(ds, 0x514a);
    if (memoryAGet16(ds, 0x514a) > 0)
    {
        t = t - 1000;
        if (t<0) t = 0;
        memoryASet16(ds, 0x514a, t);
    }
}
