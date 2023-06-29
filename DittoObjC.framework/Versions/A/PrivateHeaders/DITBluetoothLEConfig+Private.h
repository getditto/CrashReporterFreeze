//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import "DITBluetoothLEConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface DITBluetoothLEConfig () {
    @protected
    BOOL _enabled;
}

- (instancetype)initWithEnabled:(BOOL)enabled copy:(BOOL)shouldCopy NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
