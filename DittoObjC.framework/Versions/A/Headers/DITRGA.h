//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a CRDT Replicated Growable Array (RGA) that can be
 * upserted as part of a document or assigned to a property during an
 * update of a document.
 */
@interface DITRGA : NSObject

/**
 The array representation of the RGA.
 */
@property (nonatomic, readonly) NSArray<id> *value;

- (instancetype)init NS_UNAVAILABLE;

/**
 Returns `YES` if passed in RGA has the same value, otherwise returns
 `NO`.
 */
- (BOOL)isEqualToRGA:(DITRGA *)rga;

@end

NS_ASSUME_NONNULL_END
