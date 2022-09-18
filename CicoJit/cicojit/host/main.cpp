#include <dlfcn.h>
#include <stdio.h>
#define _HOST
#include "cicoemu.h"
#include "impl.h"
#include <map>
#include <string>
#include <functional>

std::vector<std::string> callStack;
std::map<std::string, std::function<void()> > functionCache;
void printStack();
int currentLine = -1;
long counter = 0;
void printStack();

void CicoContext::cicocontext_t::onLine(int a)
{
//  printf("%x\n", a);
  currentLine = a;
//  if (counter++ > 10000000)
  {
//    stop("no sync!");
//    printStack();
//    sync();
//    counter = 0;
  }
}

void CicoContext::cicocontext_t::callIndirect(int a)
{
  char funcname[128];       
  sprintf(funcname, "sub_%x", _cs*16+a);
//  printf("Calling indirect %s\n", funcname);
  /*void* pfunc =*/ call(funcname);
 // ((void(*)())pfunc)();
}

bool CicoContext::cicocontext_t::stop(const char* msg)
{
    printf("\nApp terminated '%s': in %s() on 0x%x\n", msg ? msg : "", callStack.back().c_str(), currentLine);
    printStack();
    printf("\n");
    assert(0);
    return false;
}
extern int watchdog;

void CicoContext::cicocontext_t::sync()
{
watchdog = 0;
counter = 0;
    printStack();
    for (int y=0; y<200; y++)
      for (int x=0; x<320; x++)
        mSdl.SetPixel(x, y, mVideo.GetPixel(x, y));
    mSdl.Loop();
}

void nullfunc() {}

void printStack()
{
  int chars = 0;
/*
  for (int i=0; i<100; i++)
    printf(" ");
  for (int i=0; i<100; i++)
    printf("\x08");
*/
  for (int i=0; i<callStack.size(); i++)
  {
    if (i>0)
    {
      printf(" > ");
      chars += 3;
    }
    printf("%s", callStack[i].c_str());
    chars += callStack[i].size();
  }
  chars += printf(":%x                ", currentLine);
//  printf("                ");
//  chars+=16;
  for (int i=0; i<chars; i++)
  {
    printf("\x08");
  }
}

void CicoContext::cicocontext_t::call(const char* a)
{
  auto lookup = functionCache.find(std::string(a));
  if (lookup != functionCache.end())
  {
    callStack.push_back(a);
    lookup->second();
    callStack.pop_back();
    return;
  }

  if (strcmp(a, "sub_1c4bd") == 0)
  {
    functionCache.insert(std::pair<std::string, std::function<void()> >(a, nullfunc));
    return; //(void*)nullfunc;
  }
  

  printf("Loading %s\n", a);

  char strpath[1024];
  sprintf(strpath, "../intermediate/%s", a);
  char strsym[128];
  sprintf(strsym, "_Z%ld%sv", strlen(a), a);

  void *lib = dlopen(strpath, RTLD_NOW);
  if (!lib)
  {
    printf("Library '%s' not found!\n", strpath);
  }
  assert(lib);
  void *pctx = dlsym(lib, "_ZN11CicoContext3ctxE");
  void *psym = dlsym(lib, strsym);
  assert(pctx && psym);
  *((uintptr_t*)pctx) = (uintptr_t)CicoContext::ctx;

  functionCache.insert(std::pair<std::string, std::function<void()> >(a, (void(*)())psym));
  callStack.push_back(a);
  ((void(*)())psym)();
  callStack.pop_back();
}

namespace CicoContext {
  cicocontext_t* ctx{nullptr};
}

int main()
{
  CicoContext::ctx = new CicoContext::cicocontext_t();

  memset(mem, 0, sizeof(mem));
  FILE* f = fopen("../goose/GOOSE.EXE", "rb");
  fread(mem, 53684, 1, f);
  fclose(f);

  mSdl.Init();
  CicoContext::ctx->call("start");
  mSdl.Deinit();
  return 0;
}