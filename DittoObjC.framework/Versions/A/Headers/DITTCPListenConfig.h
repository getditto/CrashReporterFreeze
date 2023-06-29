//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITMutableTCPListenConfig;

@interface DITTCPListenConfig : NSObject <NSCopying, NSMutableCopying>

+ (instancetype)tcpListenConfig;

@property (nonatomic, readonly, getter=isEnabled) BOOL enabled;
/**
 IP interface to bind to. [::] by default.
 */
@property (nonatomic, readonly) NSString *interfaceIp;
/**
 Listening port. 4040 by default.
 */
@property (nonatomic, readonly) uint16_t port;

- (instancetype)initWithDITTCPListenConfig:(DITTCPListenConfig *)config;
- (instancetype)initWithEnabled:(BOOL)enabled
                    interfaceIp:(NSString *)interfaceIp
                           port:(uint16_t)port;

- (BOOL)isEqualToDITTCPListenConfig:(DITTCPListenConfig *)config;

@end

// MARK: -

@interface DITTCPListenConfig (DITTypeCorrections)

- (DITTCPListenConfig *)copy;
- (DITMutableTCPListenConfig *)mutableCopy;

@end

NS_ASSUME_NONNULL_END
