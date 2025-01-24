#include <stdint.h>
#include <cassert>
#include "sdl.h"
#include "controls.h"

extern "C" 
{
    bool appBlit();
    void appLoop();
    void apiPrint(char* msg);
    int apiRead(char* name, int readofs, int readlen, void* targetofs);
    void emscripten_sleep(int);

    extern uint32_t* appVideo;
    extern uint8_t* appMemory;
}

CSdl mSdl;

void apiPrint(char* msg)
{
    puts(msg);
}

int apiRead(char* name, int readofs, int readlen, void* targetofs)
{
    char fullName[128];
    strcpy(fullName, "../dos/");
    strcat(fullName, name);
    FILE* f = fopen(fullName, "rb");
    fseek(f, readofs, SEEK_SET);
    int r = fread(targetofs, readlen, 1, f);
    fclose(f);
    return r;
}

void emscripten_sleep(int)
{
    appBlit();
    memcpy(mSdl.Pixels(), appVideo, 320*200*4);
    mSdl.Loop();
}

int main(int argc, const char * argv[])
{
    mSdl.Init();
    appLoop();
    mSdl.Deinit();
    return 0;
}
