void _indirectCall(WORD ptr)
{
    switch(ptr)
    {
        default:
            std::cout << "Undefined indirect: case 0x" << std::hex << ptr << ": sub_"
                << std::uppercase << (ptr + 0x13EC0) << std::nouppercase << "(); break; \n";
            _ASSERT(0);
    }
}

