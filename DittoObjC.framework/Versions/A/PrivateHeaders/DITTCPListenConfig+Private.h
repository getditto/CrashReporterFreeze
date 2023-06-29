//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITTCPListenConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITTCPListenConfig () {
    @protected
    BOOL _enabled;
    @protected
    NSString *_interfaceIp;
    @protected
    uint16_t _port;
}

- (instancetype)initWithEnabled:(BOOL)enabled
                    interfaceIP:(NSString *)interfaceIP
                           port:(uint16_t)port
                           copy:(BOOL)shouldCopy NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
