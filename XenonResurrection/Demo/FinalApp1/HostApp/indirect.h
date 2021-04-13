void _indirectCall(WORD ptr)
{
    switch(ptr)
    {
        case 0x3c86: sub_17B46(); break;
        case 0x3ba7: break;
        case 0x3ba8: sub_17A68(); break;
        case 0x3c54: sub_17B14(); break;
        case 0x3c0e: sub_17ACE(); break;
        case 0x3bcc: sub_17A8C(); break;
        case 0x3bb1: sub_17A71(); break;
        case 0x3c50: sub_17B10(); break;
        case 0x3bed: sub_17AAD(); break;
        case 0x3c6a: sub_17B2A(); break;
        case 0x3c2f: sub_17AEF(); break;
        case 0x3cbe: sub_17B7E(); break;
        case 0x3ca2: sub_17B62(); break;
        case 0x2356: sub_16216(); break;
        case 0x2b6a: sub_16A2A(); break;
        case 0x2b47: sub_16A07(); break;
        case 0x236f: sub_1622F(); break;
        default:
            std::cout << "Undefined indirect: case 0x" << std::hex << ptr << ": sub_"
                << std::uppercase << (ptr + 0x13EC0) << std::nouppercase << "(); break; \n";
            _ASSERT(0);
    }
}

