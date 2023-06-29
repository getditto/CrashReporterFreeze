//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITObserver.h>

#import <Foundation/Foundation.h>

@class DITDitto;
@class DITPresenceGraph;

NS_ASSUME_NONNULL_BEGIN

/**
 The entrypoint for all actions that relate presence of other peers known by
 the current peer, either directly or through other peers.

 You don't create one directly but can access it from a particular `DITDitto`
 instance via its `presence` property.
 */
@interface DITPresence : NSObject

/**
 Returns the current presence graph capturing all known peers and connections
 between them.
 */
@property (nonatomic, readonly, copy) DITPresenceGraph *graph;

- (instancetype)init NS_UNAVAILABLE;

/**
 Request information about Ditto peers in range of this device.

 This method returns an observer which should be held as long as updates are
 required. A newly registered observer will have a peers update delivered to it
 immediately. From then on it will be invoked repeatedly when Ditto devices come
 and go, or the active connections to them change.
 */
- (id<DITObserver>)observe:(void (^)(DITPresenceGraph *))didChangeHandler;

@end

NS_ASSUME_NONNULL_END
