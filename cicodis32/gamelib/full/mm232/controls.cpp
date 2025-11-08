void sync()
{
    memoryASet32(ds, 0x2eebd0, memoryAGet32(ds, 0x2eebd0)+4);
    
    for (int i=0; i<10; i++)
        sub_1a88e4();
}


void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) 
        exit(1);

    auto toggle = [](int a, int p)
    {
        memoryASet(0x168, a, p);
    };
    
    switch (k)
    {
        case SDL_SCANCODE_LEFT: toggle(0x30b088, p); break;
        case SDL_SCANCODE_RIGHT: toggle(0x30b089, p); break;
        case SDL_SCANCODE_UP: toggle(0x30b118, p); toggle(0x30b080, p); break;
        case SDL_SCANCODE_DOWN: toggle(0x30b120, p); break;
        case SDL_SCANCODE_SPACE: toggle(0x30b0ec, p); break; // return
    }
}
