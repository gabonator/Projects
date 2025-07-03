#include <stdint.h>

extern int headerSize, loadAddress, endAddress;
void start();

void load(const char*, const char*, int)
{
}
void memoryASet(int s, int o, int v)
{
}
void memoryASet16(int s, int o, int v)
{
}
uint8_t memoryAGet(int s, int o)
{
  return 0;
}
uint16_t memoryAGet16(int s, int o)
{
  return 0;
}

void interrupt(int)
{
}

void out16(int, int)
{
}
void out8(int, int)
{
}
int in8(int)
{
  return 0;
}

int main()
{
  start();
  return 0;
}
