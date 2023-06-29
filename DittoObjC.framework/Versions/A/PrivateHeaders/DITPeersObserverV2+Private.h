//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITPeersObserverV2.h>

@class _DITPresenceManagerV2;

NS_ASSUME_NONNULL_BEGIN

__deprecated_msg("Replaced by `DITObserver` protocol.") @interface DITPeersObserverV2()
@property (nonatomic, readonly) _DITPresenceManagerV2 *manager;
@property (nonatomic) void (^callback)(NSString *);
@property (nonatomic, readonly) dispatch_queue_t queue;

- (instancetype)initWithPresenceManager:(_DITPresenceManagerV2 *)manager
                               callback:(void (^)(NSString *))callback
                                  queue:(dispatch_queue_t)queue;
- (void)invoke:(NSString *)data;
@end

NS_ASSUME_NONNULL_END
