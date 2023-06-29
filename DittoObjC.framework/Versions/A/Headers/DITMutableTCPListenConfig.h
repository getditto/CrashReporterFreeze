//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITTCPListenConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableTCPListenConfig : DITTCPListenConfig

@property (nonatomic, readwrite, getter=isEnabled) BOOL enabled;
/**
 IP interface to bind to. [::] by default.
 */
@property (nonatomic, readwrite, copy) NSString *interfaceIp;
/**
 Listening port. 4040 by default.
 */
@property (nonatomic, readwrite) uint16_t port;

@end

NS_ASSUME_NONNULL_END
