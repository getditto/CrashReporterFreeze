//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A handle used to control disk usage observation.
@interface DITDiskUsageObserverHandle : NSObject

/// Use to terminate callbacks.
- (void)stop;

@end

NS_ASSUME_NONNULL_END
