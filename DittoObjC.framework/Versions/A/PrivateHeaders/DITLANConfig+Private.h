//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITLANConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITLANConfig () {
    @protected
    BOOL _enabled;
    @protected
    BOOL _mDNSEnabled;
    @protected
    BOOL _multicastEnabled;
}

- (instancetype)initWithEnabled:(BOOL)enabled
                    mDNSEnabled:(BOOL)mDNSEnabled
               multicastEnabled:(BOOL)multicastEnabled
                           copy:(BOOL)shouldCopy NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
