//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITHTTPListenConfig.h>
#import <DittoObjC/DITTCPListenConfig.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITMutableListen;

/**
 Configure this device as a Ditto server. Disabled by default.

 This is advanced usage that is not needed in most situations. Please refer to the documentation
 on Ditto's website for scenarios and example configurations.
 */
@interface DITListen : NSObject <NSCopying, NSMutableCopying>

+ (instancetype)listen;

@property (nonatomic, readonly) DITTCPListenConfig *tcp;
@property (nonatomic, readonly) DITHTTPListenConfig *http;

- (instancetype)initWithDITListen:(DITListen *)listen;
- (instancetype)initWithTCP:(DITTCPListenConfig *)tcp HTTP:(DITHTTPListenConfig *)http;

@end

// MARK: -

@interface DITListen (DITTypeCorrections)

- (DITListen *)copy;
- (DITMutableListen *)mutableCopy;

@end

NS_ASSUME_NONNULL_END
