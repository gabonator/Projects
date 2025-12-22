#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "replay.h"
#ifdef USE_SDL
#include "sdl.h"
#include "controls.h"
CSdl sdl;
#endif

extern uint32_t mVideoPixels[];
extern uint8_t appMemory[];
int frames = 0;

extern "C" bool appBlit();
void init();
void start();

extern void appSync();
void sync()
{
#if USE_REPLAY
  applyState(getState(frames++));
#endif
  appSync();

#if USE_SDL
  for (int y=0; y<200; y++)
    for (int x=0; x<320; x++)
      sdl.SetPixel(x, y, mVideoPixels[y*320+x]);
  sdl.Loop();
#endif

#if USE_STREAM
  fwrite(mVideoPixels, 1, 320*200*4, stdout);
#endif
}

extern "C" void apiPrint(char* msg)
{
}

extern "C" int apiRead(char* name, int readofs, int readlen, void* targetofs)
{
  char path[128] = "../dos/";
  strcat(path, name);  
  FILE* f = fopen(path, "rb");
  if (!f)
  {
    printf("Error %s\n", path);
    exit(0);
  }
  fseek(f, readofs, SEEK_SET);
  int read = fread(targetofs, 1, readlen, f);
  fclose(f);
  return read;
}

int main()
{
#ifdef USE_SDL
  sdl.Init();
#endif
  init();
  start();
  return 0;
}
