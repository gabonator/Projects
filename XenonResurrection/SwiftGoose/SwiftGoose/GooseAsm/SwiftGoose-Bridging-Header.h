#import <Foundation/Foundation.h>

@interface GooseWrapper : NSObject
- (void)initApp;
- (void)run;
- (NSData*)getImageData;
- (void)setPosition:(int)x;
@end
