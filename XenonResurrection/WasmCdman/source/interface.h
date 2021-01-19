#include "cpu.h"

// main interface
extern "C" void appInit();
extern "C" bool appLoop();
extern "C" void appFinish();

// js to wasm interface
extern "C" uint8_t* appVideoBuffer();
extern "C" uint8_t* appMemory();
extern "C" uint16_t* appKeyboardBuffer();

// wasm to js interface
extern "C" void debugPrint(char*);
extern "C" void assertionHandler(char*);

int _filesize();
int _fileopen(char* name);
int _fileclose();
int _fileread(int ofs, int size, int mseg, int mofs);
int _tone(int freq);

// internal
void updateVideoBuffer();