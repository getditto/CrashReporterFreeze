//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITPeersObserver.h>

@class _DITPresenceManagerV1;
@class DITRemotePeer;

NS_ASSUME_NONNULL_BEGIN

@interface DITPeersObserver ()
@property (nonatomic, readonly) _DITPresenceManagerV1 *manager;
@property (nonatomic) void (^callback)(NSArray<DITRemotePeer *> *);
@property (nonatomic, readonly) dispatch_queue_t queue;

- (instancetype)initWithPresenceManager:(_DITPresenceManagerV1 *)manager
                               callback:(void (^)(NSArray<DITRemotePeer *> *))callback
                                  queue:(dispatch_queue_t)queue;
- (void)invoke:(NSArray<DITRemotePeer *> *)data;
@end

NS_ASSUME_NONNULL_END
