// ws2_32.h — WinSock2 ordinal stubs
// These are referenced as bare macros in nexus.cpp's indirectCall:
//   ordinal_116   (not ordinal_116())
// So we define them as macros that include the semicolon-free statement.
// ordinal 116 = WSAStartup(2 args, stdcall +8)
#define ordinal_116 { esp += 8; eax = 1; }
// ordinal 3 = closesocket(1 arg, stdcall +4)
#define ordinal_3 { esp += 4; eax = 0xffffffff; }
// ordinal 16 = recv(4 args, stdcall +16)
#define ordinal_16 { esp += 16; eax = 0xffffffff; }
// ordinal 19 = send(4 args, stdcall +16)
#define ordinal_19 { esp += 16; eax = 0xffffffff; }
// ordinal 4 = closesocket(1 arg, stdcall +4)
#define ordinal_4 { esp += 4; eax = 0xffffffff; }
// ordinal 9 = connect(3 args, stdcall +12)
#define ordinal_9 { esp += 12; eax = 0xffffffff; }
// ordinal 52 = WSAGetLastError(0 args)
#define ordinal_52 { eax = 0; }
// ordinal 115 = WSACleanup(0 args)
#define ordinal_115 { eax = 0; }
// ordinal 23 = socket(3 args, stdcall +12)
#define ordinal_23 { esp += 12; eax = 0xffffffff; }
