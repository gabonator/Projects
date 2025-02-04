void sub_13e6f();

extern "C" void lemmingsMouse(int x, int y)
{
    if (x < 12)
        CicoContext::ctx.memoryASet16(0x19a9, 0x10, 8);
    else if (x >= 640-12)
        CicoContext::ctx.memoryASet16(0x19a9, 0x10, 640/2+8);
    else
        CicoContext::ctx.memoryASet16(0x19a9, 0x10, x/2+8);
    CicoContext::ctx.memoryASet16(0x19a9, 0x12, y/2+8);
}

extern "C" void lemmingsButton(int b)
{
    CicoContext::ctx.memoryASet16(0x19a9, 0x0014, b);
    CicoContext::ctx.push(CicoContext::ctx.a.r16);
    CicoContext::ctx.push(CicoContext::ctx.b.r16);
    sub_13e6f();
    CicoContext::ctx.a.r16 = CicoContext::ctx.pop();
    CicoContext::ctx.b.r16 = CicoContext::ctx.pop();
}
