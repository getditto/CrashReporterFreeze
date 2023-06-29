//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/_DITPresenceObserver.h>

NS_ASSUME_NONNULL_BEGIN

@interface _DITPresenceObserver ()

@property (nonatomic, readwrite, copy) void (^block)(id presenceGraphOrCBOR);
@property (nonatomic, readwrite) BOOL hasBeenNotifiedAtLeastOnce;

@end

NS_ASSUME_NONNULL_END
