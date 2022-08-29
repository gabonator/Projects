void sub_1448();
void sub_22cb();
void sub_228c();
void sub_259b();
void sub_2575();
void sub_1a01();
void sub_1a48();
void sub_2313(int pc);
void sub_2861();

void _indirectCall(WORD ptr)
{
    switch (ptr)
    {
        case 0x1448: sub_1448(); break;
        case 0x22cb: sub_22cb(); break;
        case 0x228c: sub_228c(); break;
        case 0x259b: sub_259b(); break;
        case 0x2575: sub_2575(); break;
        case 0x1a01: sub_1a01(); break;
        case 0x1a48: sub_1a48(); break;
        case 0x2313: sub_2313(0); break;
        case 0x2861: sub_2861(); break;
        default:
            std::cout << "Indirect call " << ptr << "\n";
            //assert(0);
    }
}
