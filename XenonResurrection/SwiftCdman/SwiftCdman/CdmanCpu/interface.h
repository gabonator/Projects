#include "cpu.h"

// main interface
void appInit();
bool appLoop();
void appFinish();

// js to wasm interface
uint8_t* appVideoBuffer();
uint8_t* appMemory();
uint16_t* appKeyboardBuffer();

// wasm to js interface
void debugPrint(char*);
void assertionHandler(char*);

int _filesize();
int _fileopen(char* name);
int _fileclose();
int _fileread(int ofs, int size, int mseg, int mofs);
int _tone(int freq);

// internal
void updateVideoBuffer();
