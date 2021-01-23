#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface CdmanWrapper : NSObject
- (void)initApp;
- (void)run;
- (void)sound;
- (NSData*)getImageData;
- (void)setPosition:(int)x y:(int)y;
- (void)pressKey:(int)k;
- (void)releaseKey:(int)k;
- (int)getPlayFrequency;
@end
