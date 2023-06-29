//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITObserver.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A token returned by calling `observePeersV2` on a `DITDitto` object.

 Retain this object to continue receiving callback updates.

 @deprecated replaced by `DITObserver` protocol.
 */
__deprecated_msg("Replaced by `DITObserver` protocol.") @interface DITPeersObserverV2
    : NSObject<DITObserver>

- (void)stop;

@end

NS_ASSUME_NONNULL_END
