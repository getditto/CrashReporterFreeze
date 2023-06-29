//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITWriteStrategy.h>

@class DITDocumentID;
@class DITWriteTransactionPendingCursorOperation;
@class DITWriteTransactionPendingIDSpecificOperation;

NS_ASSUME_NONNULL_BEGIN

/**
 Exposes functionality that allows you to perform multiple operations on the store within a single
 write transaction.

 A `DITScopedWriteTransaction` is scoped to a specific collection, obtained by calling `scoped` on a
 `DITWriteTransaction`.
 */
@interface DITScopedWriteTransaction : NSObject

/**
 The name of the collection that the scoped write transaction is scoped to.
 */
@property (nonatomic, readonly) NSString *collectionName;

/**
 Convenience method, same as `upsert:writeStrategy:error:` where
 `DITWriteStrategyMerge` is passed for `writeStrategy`.
 */
- (nullable DITDocumentID *)upsert:(NSDictionary<NSString *, id> *)content
                             error:(NSError *_Nullable __autoreleasing *)error;

/**
 Inserts a new document into the collection and returns its ID. If the
 document already exists, the behavior is determined by the given
 `writeStrategy`.

 @param content The new document to insert.
 @param writeStrategy Specifies the desired strategy for inserting a document.
 @param error On input, a pointer to an error object. If an error occurs, this pointer
 is set to an actual error object containing the error information. You may specify nil for this
 parameter if you do not want the error information.

 @return The ID of the upserted document, or `nil` if upsertion failed.
 */
- (nullable DITDocumentID *)upsert:(NSDictionary<NSString *, id> *)content
                     writeStrategy:(DITWriteStrategy)writeStrategy
                             error:(NSError *_Nullable __autoreleasing *)error
    NS_SWIFT_NAME(upsert(_:writeStrategy:));

/**
 Generates a `DITWriteTransactionPendingIDSpecificOperation` with the provided document ID that can
 be used to update, remove, or evict the document.

 @param docID The ID of the document.

 @return A `DITWriteTransactionPendingIDSpecificOperation` that you can chain function calls to to
 update, remove, or evict the document.
 */
- (DITWriteTransactionPendingIDSpecificOperation *)findByID:(DITDocumentID *)docID
    NS_SWIFT_NAME(findByID(_:));

/**
 Generates a `DITWriteTransactionPendingCursorOperation` with the provided query that can be used to
 update, remove, or evict documents.

 @param query The query to run against the collection.

 @return A `DITWriteTransactionPendingCursorOperation` that you can use to chain further
 query-related function calls to update, remove, or evict the documents.
 */
- (DITWriteTransactionPendingCursorOperation *)find:(NSString *)query;

/**
 Generates a `DITWriteTransactionPendingCursorOperation` with the provided query that can be used to
 update, remove, or evict documents.

 This is the recommended method to use when performing queries on a collection if you have any
 dynamic data included in the query string. It allows you to provide a query string with
 placeholders, in the form of `$args.my_arg_name`, along with an accompanying dictionary of
 arguments, in the form of `{ "my_arg_name": "some value" }`, and the placeholders will be
 appropriately replaced by the matching provided arguments from the dictionary. This includes
 handling things like wrapping strings in quotation marks and arrays in square brackets, for
 example.

 @param query The query to run against the collection.
 @param queryArgs The arguments to use to replace placeholders in the provided query.

 @return A `DITWriteTransactionPendingCursorOperation` that you can use to chain further
 query-related function calls to update, remove, or evict the documents.
 */
- (DITWriteTransactionPendingCursorOperation *)find:(NSString *)query
                                           withArgs:(NSDictionary<NSString *, id> *)queryArgs;

/**
 Generates a `DITWriteTransactionPendingCursorOperation` that can be used to update, remove or evict
 documents.

 @return A `DITWriteTransactionPendingCursorOperation` that you can use to chain further
 query-related function calls to update, remove, or evict the documents.
 */
- (DITWriteTransactionPendingCursorOperation *)findAll;

@end

NS_ASSUME_NONNULL_END
