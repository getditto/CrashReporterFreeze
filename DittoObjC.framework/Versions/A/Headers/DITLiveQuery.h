//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The type that is returned when calling when calling `observeLocal` on a `DITPendingCursorOperation`
 object. It handles the logic for calling the event handler that is provided to `observeLocal`
 calls.

 `DITLiveQuery` objects must be kept in scope for as long as you with to have your event handler
 be called when there is an update to a document matching the query you provide. When you no
 longer want to receive updates about documents matching a query then you must call `stop` on the
 `DITLiveQuery` object.
 */
@interface DITLiveQuery : NSObject

/**
 The query that the live query is based on.
 */
@property (nonatomic, readonly) NSString *query;

/**
 The name of the collection that the live query is based on.
 */
@property (nonatomic, readonly) NSString *collectionName;

/**
 Stop the live query from delivering updates.

 When you no longer want to receive updates about documents matching a query then you must call
 `stop` on the `DITLiveQuery` object.
 */
- (void)stop;

@end

NS_ASSUME_NONNULL_END
