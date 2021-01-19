#include "interface.h"

extern BYTE memoryBuffer[0x10000*3];
extern WORD keyboardBuffer[1];

uint8_t* getEgaPlanes();
uint32_t* getEgaPalette();
uint32_t videoBuffer[640*350];

uint8_t* appMemory()
{  
    return memoryBuffer;
}

uint16_t* appKeyboardBuffer()
{
    return keyboardBuffer;
}

uint8_t* appVideoBuffer()
{
    return (uint8_t*)videoBuffer;
}

void updateVideoBuffer()
{
    uint8_t* planes = getEgaPlanes(); 
    uint32_t* palette = getEgaPalette();
        
    uint32_t* p = videoBuffer;
    for (int y=0; y<350; y++)
        for (int x=0; x<640/8; x++)
        {
            int plane0 = *planes++;
            int plane1 = *planes++;
            int plane2 = *planes++;
            int plane3 = *planes++;

            for (int i=0; i<8; i++)
            {
                int index = (plane0 & 128) + (plane1 & 128)*2 + (plane2 & 128)*4 + (plane3 & 128)*8;
                plane0 <<= 1;
                plane1 <<= 1;
                plane2 <<= 1;
                plane3 <<= 1;
                *p++ = palette[index >> 7];
            }
        }
//    return (uint8_t*)videoBuffer;
}

