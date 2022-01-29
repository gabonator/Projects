void sub_1448();
void sub_22cb();
void sub_228c();
void sub_259b();

void _indirectCall(WORD ptr)
{
    switch (ptr)
    {
        case 0x1448: sub_1448(); break;
        case 0x22cb: sub_22cb(); break;
        case 0x228c: sub_228c(); break;
        case 0x259b: sub_259b(); break;
        default:
            std::cout << "Indirect call " << ptr << "\n";
            assert(0);
    }
}
