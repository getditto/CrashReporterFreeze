//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITMutableGlobalConfig;

/**
 Settings not associated with any specific type of transport.
 */
@interface DITGlobalConfig : NSObject

+ (instancetype)globalConfig;

/**
 The sync group for this device.

 When peer-to-peer transports are enabled, all devices with the same App ID will
 normally form an interconnected mesh network. In some situations it may be
 desirable to have distinct groups of devices within the same app, so that
 connections will only be formed within each group. The `syncGroup` parameter
 changes that group membership. A device can only ever be in one sync group, which
 by default is group 0. Up to 2^32 distinct group numbers can be used in an app.

 This is an optimization, not a security control. If a connection is created
 manually, such as by specifying a `connect` transport, then devices from
 different sync groups will still sync as normal. If two groups of devices are
 intended to have access to different data sets, this must be enforced using
 Ditto's permissions system.
 */
@property (nonatomic, readonly) uint32_t syncGroup;

/**
 The routing hint for this device.

 A routing hint is a performance tuning option which can improve the performance of
 applications that use large collections. Ditto will make a best effort to co-locate data for
 the same routing key. In most circumstances, this should substantially improve responsiveness
 of the Ditto Cloud.

 The value of the routing hint is application specific - you are free to chose any value.
 Devices which you expect to operate on much the same data should be configured to
 use the same value.

 A routing hint does not partition data. The value of the routing hint will not affect the data
 returned for a query. The routing hint only improves the efficiency of the Cloud's
 ability to satisfy the query.
 */
@property (nonatomic, readonly) uint32_t routingHint;

- (instancetype)initWithDITGlobalConfig:(DITGlobalConfig *)config;
- (instancetype)initWithSyncGroup:(uint32_t)syncGroup;
- (instancetype)initWithSyncGroup:(uint32_t)syncGroup routingHint:(uint32_t)routingHint;

- (BOOL)isEqualToDITGlobalConfig:(DITGlobalConfig *)config;

@end

extern const uint32_t NO_PREFERRED_ROUTE_HINT;

// MARK: -

@interface DITGlobalConfig (DITTypeCorrections)

- (DITGlobalConfig *)copy;
- (DITMutableGlobalConfig *)mutableCopy;

@end

NS_ASSUME_NONNULL_END
