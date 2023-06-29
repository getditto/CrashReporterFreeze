//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a CRDT counter that can be upserted as part of a document or
 * assigned to a property during an update of a document.
 */
@interface DITCounter : NSObject

/**
 The value of the counter.
 */
@property (nonatomic, readonly) double value;

/**
 Initializes a new counter that can be used as part of a document's content.
 */
- (instancetype)init;

/**
 Returns `YES` if passed in counter has the same value, otherwise returns
 `NO`.
 */
- (BOOL)isEqualToCounter:(DITCounter *)counter;

@end

NS_ASSUME_NONNULL_END
