//
//  Copyright © 2019 DittoLive Incorporated. All rights reserved.
//

#import <DittoTransportsObjC/DITL2CAPConnectionDelegate.h>
#import <DittoTransportsObjC/dittoffi.h>

#import <CoreBluetooth/CoreBluetooth.h>
#import <Foundation/Foundation.h>

@class DITTransportHandleWrapper;
@class DITL2CAPConnection;
@class DITPeerCache;

NS_ASSUME_NONNULL_BEGIN

// REFACTORING NOTE: In future this class should be split into two platforms registered independently, the same as
// AWDL Client and AWDL Server. This split has already been done at the transport level. They are completely
// different classes with different connection patterns and it will be much more maintainable if they're not both
// in the same file.

/// Implements iOS-specific Bluetooth functionality. It is assumed there is only one instance.
@interface DITBluetoothPlatform : NSObject <CBCentralManagerDelegate, CBPeripheralDelegate, CBPeripheralManagerDelegate, DITL2CAPConnectionDelegate>

@property(nonatomic, nullable) DITTransportHandleWrapper *clientHandleWrapper;
@property(nonatomic, nullable) DITTransportHandleWrapper *serverHandleWrapper;

+ (BleServerCallbacks_t)serverCallbacks;
+ (BleClientCallbacks_t)clientCallbacks;

- (instancetype)init NS_UNAVAILABLE;

/// Must be called on a thread with a *running* run-loop. For regular apps on apple platforms, this is the
/// main thread. For environments that already have some kind of event loop, such as Node, you'll have to
/// create a dedicated thread, run its run loop, and make sure to call the initializer from that thread.
- (instancetype)initWithDittoHandle:(void *)dittoHandle NS_DESIGNATED_INITIALIZER;

- (void)shutdown;

@end

NS_ASSUME_NONNULL_END
