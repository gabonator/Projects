#include <algorithm>
#import "SwiftCdman-Bridging-Header.h"
#include "../CdmanCpu/interface.h"

void appInit();
bool appLoop();
uint8_t* appVideoBuffer();
uint16_t* appKeyboardBuffer();

extern uint8_t& memory(uint16_t segment, uint16_t offset);
extern uint16_t& memory16(uint16_t segment, uint16_t offset);
//bool keys[128] = {0};
extern int getPlayFrequency();

//BYTE memoryBuffer[0x10000*3];;

NSData* commonFile;

int _tone(int f)
{
    return 0;
}

int _fileclose()
{
    commonFile = nil;
    return 0;
}

int _fileopen(char* name)
{
    NSString* strLocal = [NSString stringWithCString:name encoding:NSASCIIStringEncoding];
    NSString *filepath=[[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:strLocal];
    NSLog(@"open: %@", strLocal);
    
    commonFile = [NSData dataWithContentsOfFile: filepath];
    if (!commonFile)
        return false;
    assert(commonFile);
    return true;
}

int _fileread(int ofs, int size, int mseg, int mofs)
{
    assert(commonFile);
    uint8_t* ptr = &memory(mseg, mofs);
    uint8_t *fileBytes = (uint8_t *)[commonFile bytes];
    int l = std::min<int>((int)[commonFile length]-ofs, size);
    //assert(ptr-datasegment + length < sizeof(datasegment));
    memcpy(ptr, fileBytes + ofs, l);
    return 1;
}

int _filesize()
{
    assert(commonFile);
    return (int)[commonFile length];
}

void debugPrint(char*)
{
    
}

void assertionHandler(char*)
{
    assert(0);
}

@implementation CdmanWrapper

- (id) init {
    self = [super init];
    if (self!=nil) {
    }
    return self;
}

- (void) initApp {
    appInit();
    
    NSString *filepath=[[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"cdman.data"];
    NSData *fileData = [NSData dataWithContentsOfFile: filepath];

    char *fileBytes = (char *)[fileData bytes];
    NSUInteger length = [fileData length];

    memcpy(appMemory(), fileBytes+0x200, length-0x200);
}

- (void) run {
    appLoop();
}

- (NSData*)getImageData {
    return [NSData dataWithBytesNoCopy:appVideoBuffer() length:640*350*4 freeWhenDone:NO];
}

- (void)setPosition:(int)x y:(int)y
{
    appKeyboardBuffer()[0] = 0x1c0d;
}

- (void)pressKey:(CdmanKey)k
{
    switch (k)
    {
        case CdmanKeyEnter:
            appKeyboardBuffer()[0] = 0x1c0d;
            break;
        case CdmanKeyUp:
            appKeyboardBuffer()[0] = 0x5000;
            break;
        case CdmanKeyDown:
            appKeyboardBuffer()[0] = 0x4800;
            break;
        case CdmanKeyLeft:
            appKeyboardBuffer()[0] = 0x4b00;
            break;
        case CdmanKeyRight:
            appKeyboardBuffer()[0] = 0x4d00;
            break;

    }
}

- (void)releaseKey:(CdmanKey)k
{
}

- (int)getPlayFrequency
{
    return 0;
}

// extension extra

- (nullable CdmanPos*)pacPos
{
    int pos = memory16(0x0000, 0x0190) - 22;
    int px = pos % 21;
    int py = pos / 21;
    if (px >= 0 && py >= 0 && px < 19 && py < 13)
        return [[CdmanPos alloc] initWithX:px y:py];
    return nil;
}

- (CdmanDirection)pacGraphAt:(nullable CdmanPos*)pos
{
    CdmanDirection dir = 0;
    
    if (!pos)
        return dir;
        
    NSInteger ptr = pos.y*21+pos.x+22;
    int mask = memory(0x0000, ptr + 124);
    
    if (mask & 128)
        dir |= CdmanDirectionUp;
    if (mask & 64)
        dir |= CdmanDirectionDown;
    if (mask & 32)
        dir |= CdmanDirectionLeft;
    if (mask & 16)
        dir |= CdmanDirectionRight;
    return dir;
}

- (void)pacGo:(CdmanDirection)dir
{
    switch (dir)
    {
        case CdmanDirectionUp:
            memory(0x0000, 0x018E) = 24;
            break;
        case CdmanDirectionDown:
            memory(0x0000, 0x018E) = 16;
            break;
        case CdmanDirectionLeft:
            memory(0x0000, 0x018E) = 8;
            break;
        case CdmanDirectionRight:
            memory(0x0000, 0x018E) = 0;
            break;
    }
}

@end

@implementation CdmanPos
- (instancetype)initWithX: (NSInteger)x y:(NSInteger)y
{
    if (self = [super init])
    {
        self.x = x;
        self.y = y;
    }
    return self;
}

@end
