#import <Foundation/Foundation.h>

@interface GooseWrapper : NSObject
- (void)initApp;
- (void)run;
- (void)sound;
- (NSData*)getImageData;
- (void)setPosition:(int)x;
- (void)pressKey:(int)k;
- (void)releaseKey:(int)k;
- (int)getPlayFrequency;
@end
