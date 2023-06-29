//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITDocumentID;

@class DITUpdateResultSet;
@class DITUpdateResultRemoved;
@class DITUpdateResultIncremented;

/**
 The types of update result.
 */
typedef NS_ENUM(NSUInteger, DITUpdateResultType) {
    DITUpdateResultTypeSet = 0,
    DITUpdateResultTypeRemoved,
    DITUpdateResultTypeIncremented,
};

NS_ASSUME_NONNULL_BEGIN

/**
 Provides information about a successful update operation on a document.

 The update result can be one of the following types:
   * `set`
   * `removed`
   * `incremented`
 */
@interface DITUpdateResult : NSObject

/**
 The update result's type.

 Check this value before using one of `asSet`, `asRemoved`, or
 `asIncremented` to ensure that you get the correct richer update result
 object.
 */
@property (nonatomic, readonly) DITUpdateResultType type;

/**
 The ID of the document that was updated.
 */
@property (nonatomic, readonly) DITDocumentID *docID;

/**
 The path to the key in the document that was updated.
 */
@property (nonatomic, readonly) NSString *path;

/**
 Return the update result object as a `DITUpdateResultSet` object.

 @return A `DITUpdateResultSet` object or `nil` if the update result's type is not `set`.
 */
- (nullable DITUpdateResultSet *)asSet;

/**
 Return the update result object as a `DITUpdateResultRemoved` object.

 @return A `DITUpdateResultRemoved` object or `nil` if the update result's type is not `removed`.
 */
- (nullable DITUpdateResultRemoved *)asRemoved;

/**
 Return the update result object as a `DITUpdateResultIncremented` object.

 @return A `DITUpdateResultIncremented` object or `nil` if the update result's type is not
 `incremented`.
 */
- (nullable DITUpdateResultIncremented *)asIncremented;

@end

/**
 An update result when the update result's type is `set`.
 */
@interface DITUpdateResultSet : DITUpdateResult

/**
 The value that was set.
 */
@property (nonatomic, readonly, nullable) id value;

@end

/**
 An update result when the update result's type is `removed`.
 */
@interface DITUpdateResultRemoved : DITUpdateResult
@end

/**
 An update result when the update result's type is `incremented`.
 */
@interface DITUpdateResultIncremented : DITUpdateResult

/**
 The amount that the counter was incremented by.
 */
@property (nonatomic, readonly) double amount;

@end

NS_ASSUME_NONNULL_END
