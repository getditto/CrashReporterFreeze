//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An observation token returned by any observation API in the Ditto SDK. Retain
 this object to continue receiving updates.
 */
@protocol DITObserver

/**
 * Stops the observation and cleans up all associated resources. This method
 * does _not guarantee_ the observation will have completely stopped by the time
 * this method returns and should be considered merely a request to stop the
 * observation asynchronously.
 */
- (void)stop;

@end

NS_ASSUME_NONNULL_END
