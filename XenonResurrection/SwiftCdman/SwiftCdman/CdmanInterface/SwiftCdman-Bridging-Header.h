#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface CdmanPos : NSObject
@property NSInteger x;
@property NSInteger y;

- (nonnull instancetype)initWithX: (NSInteger)x y:(NSInteger)y;
@end

typedef NS_OPTIONS(NSUInteger, CdmanDirection) {
    CdmanDirectionUp = 1 << 0,
    CdmanDirectionDown = 1 << 1,
    CdmanDirectionLeft = 1 << 2,
    CdmanDirectionRight = 1 << 3,
};

typedef NS_OPTIONS(NSUInteger, CdmanKey) {
    CdmanKeyEnter = 1 << 0,
    CdmanKeyUp = 1 << 1,
    CdmanKeyDown = 1 << 2,
    CdmanKeyLeft = 1 << 3,
    CdmanKeyRight = 1 << 4,
};

@interface CdmanWrapper : NSObject
- (void)initApp;
- (void)run;
- (nonnull NSData*)getImageData;
- (void)pressKey:(CdmanKey)k;
- (void)releaseKey:(CdmanKey)k;
- (int)getPlayFrequency;
@end

@interface CdmanWrapper (navigation)
- (nullable CdmanPos*)pacPos;
- (CdmanDirection)pacGraphAt:(nullable CdmanPos*)pos;
- (void)pacGo:(CdmanDirection)dir;
@end


