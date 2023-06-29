//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A summary snapshot of the types of connections currently active to a remote peer.

 @deprecated has been replaced by `DITPeer`.
 */
__deprecated_msg("Replaced by `DITPeer`.") @interface DITRemotePeer : NSObject

/**
 The unique network identifier of the remote peer.
 */
@property (nonatomic, readonly) NSString *networkId;

/**
 The human-readable device name of the remote peer. This defaults to the hostname
 but can be manually set by the application developer of the other peer.
 It is not necessarily unique.
 */
@property (nonatomic, readonly) NSString *deviceName;

/**
 The connections that are currently active with the remote peer.
 */
@property (nonatomic, readwrite) NSArray<NSString *> *connections;

/**
 Received Signal Strength Indicator

 This value is primarily derived from Bluetooth Low Energy, so if the device's Bluetooth settings
 are not enabled, then this value will be nil even though there might be a connection from
 another transport.
 */
@property (nonatomic, readwrite, nullable) NSNumber *rssi;

/**
 An estimate of distance to the remote peer. This value is inaccurate. The environment, hardware,
 and several other factors can greatly affect this value. It is currently derived from RSSI.
 */
@property (nonatomic, readwrite, nullable) NSNumber *approximateDistanceInMeters;

@end

NS_ASSUME_NONNULL_END
