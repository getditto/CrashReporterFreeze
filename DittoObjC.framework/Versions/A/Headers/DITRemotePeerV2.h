//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITAddress;

/**
 Represents a remote peer in the Ditto network.
 */
@interface DITRemotePeerV2 : NSObject

/**
 Address to contact this peer via Ditto Bus.
 */
@property (nonatomic, readonly) DITAddress *address;

/**
 Advertising identifier of the remote peer.
 */
@property (nonatomic, readonly) uint32_t networkID;

/**
 The human-readable device name of the remote peer. This defaults to the hostname
 but can be manually set by the application developer of the other peer.
 It is not necessarily unique.
 */
@property (nonatomic, readonly, strong) NSString *deviceName;

/**
 Operating system of the remote peer.
 */
@property (nonatomic, readonly, strong) NSString *os;

/**
 An optional Query Overlap Group which can be assigned to group certain
 types of peers together and configure relative connection priorities.
 Defaults to 0 if not set.
 */
@property (nonatomic, readonly) UInt8 queryOverlapGroup;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
