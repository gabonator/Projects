#include "cpu.h"

extern "C" void js_debug(int);

void _out(WORD port, WORD val);
void _out(WORD port, BYTE val);
void _interrupt(BYTE i);
void _in(BYTE& val, WORD port);
BYTE memoryVideoGet(WORD seg, WORD ofs);
void memoryVideoSet(WORD seg, WORD ofs, BYTE b);
WORD memoryBiosGet16(WORD seg, WORD ofs);
BYTE& memory(WORD segment, WORD offset);
WORD& memory16(WORD segment, WORD offset);
void _push(WORD data);
WORD _pop();

//void updateVideoBuffer();
