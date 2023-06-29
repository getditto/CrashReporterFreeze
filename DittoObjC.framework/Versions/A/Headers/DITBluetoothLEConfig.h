//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITMutableBluetoothLEConfig;

@interface DITBluetoothLEConfig : NSObject <NSCopying, NSMutableCopying>

+ (instancetype)bluetoothLEConfig;

@property (nonatomic, readonly, getter=isEnabled) BOOL enabled;

- (instancetype)initWithDITBluetoothLEConfig:(DITBluetoothLEConfig *)config;
- (instancetype)initWithEnabled:(BOOL)enabled;

- (BOOL)isEqualToDITBluetoothLEConfig:(DITBluetoothLEConfig *)config;

@end

// MARK: -

@interface DITBluetoothLEConfig (DITTypeCorrections)

- (DITBluetoothLEConfig *)copy;
- (DITMutableBluetoothLEConfig *)mutableCopy;

@end

NS_ASSUME_NONNULL_END
