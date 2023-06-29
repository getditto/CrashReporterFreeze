//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class _DITDittoHandleWrapper;

NS_ASSUME_NONNULL_BEGIN

/**
 Used to subscribe to receive updates from remote peers about matching documents.

 While `DITSubscription` objects remain in scope they ensure that documents in the collection
 specified and that match the query provided will try to be kept up-to-date with the latest changes
 from remote peers.
 */
@interface DITSubscription : NSObject

/**
 The query that the subscription is based on.
 */
@property (nonatomic, readonly) NSString *query;

/**
 The name of the collection that the subscription is based on.
 */
@property (nonatomic, readonly) NSString *collectionName;

/** Cancels the subscription and releases all associated resources. */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
