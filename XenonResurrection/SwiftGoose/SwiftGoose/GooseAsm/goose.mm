#include <algorithm>
#import "SwiftGoose-Bridging-Header.h"

void gooseInit();
void gooseLoop();
extern uint8_t datasegment[0x10000*5];
extern uint8_t segment0[0x10000];
extern uint8_t pixelBuffer[320*200*3];
extern uint8_t& memory(uint16_t segment, uint16_t offset);

NSData* commonFile;

bool commonFileOpen(char* name)
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

void commonFileRead(uint8_t* ptr, int offset, int length)
{
    assert(commonFile && ptr);
    uint8_t *fileBytes = (uint8_t *)[commonFile bytes];
    int l = std::min<int>((int)[commonFile length]-offset, length);
    assert(ptr-datasegment + length < sizeof(datasegment));
    memcpy(ptr, fileBytes + offset, l);
}


@implementation GooseWrapper

- (id) init {
    self = [super init];
    if (self!=nil) {
        [self initApp];
    }
    return self;
}

- (void) initApp {
    gooseInit();
    
    NSString *filepath=[[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"goose.dseg"];
    NSData *fileData = [NSData dataWithContentsOfFile: filepath];

    char *fileBytes = (char *)[fileData bytes];
    NSUInteger length = [fileData length];

    memcpy(datasegment, fileBytes, length);
}

- (void) run {
    gooseLoop();
}

- (NSData*)getImageData {
    return [NSData dataWithBytesNoCopy:pixelBuffer length:320*200*3 freeWhenDone:NO];
}

- (void) setPosition:(int)x
{
    x = x-160+128;
    x = std::max(std::max(0, x), 256);
    memory(0x13A5, 0x1B8F) = x-160+128;
}

@end
