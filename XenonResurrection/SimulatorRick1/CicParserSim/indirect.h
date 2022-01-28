void sub_1448();
void sub_22cb();

void _indirectCall(WORD ptr)
{
    switch (ptr)
    {
        case 0x1448: sub_1448(); break;
        case 0x22cb: sub_22cb(); break;
        default:
            std::cout << "Indirect call " << ptr << "\n";
            assert(0);
    }
}
