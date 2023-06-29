//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITRemotePeer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITRemotePeer ()

/**
 Dedicated initializer for a `DITRemotePeer`.

 - Parameter networkId: The unique network identifier of the remote peer.
 - Parameter deviceName: The human-readable device name of the remote peer.
 - Parameter connections: The connections that are currently active with the remote peer.
 - Parameter rssi: The Bluetooth RSSI of the peer if known
 - Parameter approximateDistanceInMeters: A distance estimate in meters if known
 - Returns: A newly initialized `DITRemotePeer`.
 */
- (instancetype)initWithNetworkId:(NSString *)networkId
                       deviceName:(NSString *)deviceName
                      connections:(NSArray<NSString *> *)connections
                             rssi:(nullable NSNumber *)rssi
      approximateDistanceInMeters:(nullable NSNumber *)approximateDistanceInMeters;

@end

NS_ASSUME_NONNULL_END
