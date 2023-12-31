//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITDocument;
@class DITMutableDocument;
@class DITUpdateResult;

NS_ASSUME_NONNULL_BEGIN

/**
 These objects are returned when using `findByID` functionality on `DITScopedWriteTransaction`s.

 You can use them to perform updates on a document and remove or evict a document.
 */
@interface DITWriteTransactionPendingIDSpecificOperation : NSObject

/**
 Execute the find operation to return the document with the matching ID.

 @return The `DITDocument` with the ID provided in the `findByID` call or `nil` if the document was
 not found.
 */
- (DITDocument *_Nullable)exec;

/**
 Remove the document with the matching ID.

 @return `true` if the document was found and removed. `false` if the document wasn't found and
 therefore wasn't removed.
 */
- (BOOL)remove;

/**
 Evict the document with the matching ID.

 @return `true` if the document was found and evicted. `false` if the document wasn't found and
 therefore wasn't evicted.
 */
- (BOOL)evict;

/**
 Update the document with the matching ID.

 @param block A block that gets called with the document matching the ID. If found, the document is
 a `DITMutableDocument`, so you can call update-related functions on it. If the document is not
 found then the value provided to the block will be `nil`.

 @return A list of `DITUpdateResult`s that describe the updates that were performed on the document.
 */
- (NSArray<DITUpdateResult *> *)updateWithBlock:(void (^)(DITMutableDocument *_Nullable))block;

@end

NS_ASSUME_NONNULL_END
