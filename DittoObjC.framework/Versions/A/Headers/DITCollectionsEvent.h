//
//  Copyright © 2021 Ditto. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITCollection;
@class DITLiveQueryMove;

NS_ASSUME_NONNULL_BEGIN

/**
 Describes events delivered when observing collections in the store.

 Only the first event will have the `isInitial` `BOOL` set to `true`. The first event will return
 empty arrays for all values because there can't be any modifications to the set of collections if
 it's the first time event handler is being called.
 */
@interface DITCollectionsEvent : NSObject

/**
  Whether or not this is the initial event being delivered.
 */
@property (nonatomic, readonly) BOOL isInitial;

/**
 The collections that are known about by the store.
 */
@property (nonatomic, readonly) NSArray<DITCollection *> *collections;

/**
 The collections that were previously known about by the store.
 */
@property (nonatomic, readonly) NSArray<DITCollection *> *oldCollections;

/**
 The indexes in the `collections` array that relate to a collection that was not in the previous
 list of collections, but is now.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *insertions;

/**
 The indexes in the `oldCollections` array that relate to collections that were previously known
 about by the store but that are now no longer being tracked.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *deletions;

/**
 The indexes in the `collections` array that relate to collections that have been updated since the
 previous event.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *updates;

/**
 Objects that describe how collections' positions in the `collections` array have changed since the
 previous event.
 */
@property (nonatomic, readonly) NSArray<DITLiveQueryMove *> *moves;

@end

NS_ASSUME_NONNULL_END
