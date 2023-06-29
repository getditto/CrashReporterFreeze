//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITGlobalConfig.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Settings not associated with any specific type of transport.
 */
@interface DITMutableGlobalConfig : DITGlobalConfig

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
@property (nonatomic, readwrite) uint32_t syncGroup;

@end

NS_ASSUME_NONNULL_END
