//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class _DITDittoHandleWrapper;
@class DITPeersObserver;
@class DITRemotePeer;
@class _DITWeakWrapper;

NS_ASSUME_NONNULL_BEGIN

__deprecated_msg("Replaced by `DITPeer`.") @interface _DITPresenceManagerV1 : NSObject
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) dispatch_queue_t internalQueue;
@property (nonatomic, readonly) NSMutableArray<_DITWeakWrapper *> *observers;

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper;
- (void)presenceUpdate:(NSString *)json targetObservers:(NSArray<_DITWeakWrapper *> *)observers;
- (DITPeersObserver *)observePeers:(void (^)(NSArray<DITRemotePeer *> *))callback
                             queue:(dispatch_queue_t)queue;
- (void)scheduleFlush;
@end

NS_ASSUME_NONNULL_END
