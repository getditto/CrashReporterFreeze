//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITCounter.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a mutable CRDT counter that can be incremented by a specific
 amount while updating a document.

 This class can't be instantiated directly, it's returned automatically for
 any counter property within an update block.

 See also the `counter` properties of `DITDocumentPath` and
 `DITMutableDocumentPath`.
 */
@interface DITMutableCounter : DITCounter

- (instancetype)init NS_UNAVAILABLE;

/**
 Increments the counter by `amount`, which can be any valid 64 bit float. Only
 valid within the closure of `DITCollection`'s `updateWithBlock:` method,
 otherwise an exception is thrown.
 */
- (void)incrementBy:(double)amount;

@end

NS_ASSUME_NONNULL_END
