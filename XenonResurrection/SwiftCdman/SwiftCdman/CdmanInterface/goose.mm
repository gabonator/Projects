#include <algorithm>
#import "SwiftCdman-Bridging-Header.h"
#include "../CdmanCpu/interface.h"

void appInit();
bool appLoop();
uint8_t* appVideoBuffer();
uint16_t* appKeyboardBuffer();

extern uint8_t& memory(uint16_t segment, uint16_t offset);
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

- (void)pressKey:(int)k
{
    //keys[k] = 1;
    memory(0x13A5, 0x8e8a+k) = 1;
//    if (keys[75] && keys[77]) // left & right
//    {
//        memory(0x13A5, 0x8e8a+75) = 0;
//        memory(0x13A5, 0x8e8a+77) = 0;
//    }
}

- (void)releaseKey:(int)k
{
    //keys[k] = 0;
    memory(0x13A5, 0x8e8a+k) = 0;
//    if (keys[75] && keys[77]) // left & right
//    {
//        memory(0x13A5, 0x8e8a+75) = 0;
//        memory(0x13A5, 0x8e8a+77) = 0;
//    }
}

- (int)getPlayFrequency
{
    return 0;
}

@end
