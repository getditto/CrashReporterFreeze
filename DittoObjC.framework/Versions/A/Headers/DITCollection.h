//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITWriteStrategy.h>

@class DITAttachment;
@class DITAttachmentFetcher;
@class DITAttachmentFetchEvent;
@class DITAttachmentToken;
@class DITDocumentID;
@class DITPendingCursorOperation;
@class DITPendingIDSpecificOperation;

NS_ASSUME_NONNULL_BEGIN

/**
 Represents collection names.
 */
typedef NSString *DITCollectionName NS_TYPED_EXTENSIBLE_ENUM;

/**
 The name of the history collection.

 @warning History Tracking is **experimental** and shouldn't be used in production.
 */
extern DITCollectionName const DITCollectionNameHistory;

/**
 A reference to a collection in a `DITStore`.

 This is the entrypoint for inserting documents into a collection, as well as
 querying a collection.
 */
@interface DITCollection : NSObject

/**
 The name of the collection.
 */
@property (nonatomic, readonly) NSString *name;

/**
 Convenience method, same as `upsert:writeStrategy:error:` where
 `DITWriteStrategyMerge` is passed for `writeStrategy`.
 */
- (nullable DITDocumentID *)upsert:(NSDictionary<NSString *, id> *)content
                             error:(NSError *_Nullable *)error;

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
                             error:(NSError *_Nullable *)error
    NS_SWIFT_NAME(upsert(_:writeStrategy:));

/**
 Generates a `DITPendingIDSpecificOperation` with the provided document ID.

 The returned object can be used to find and return the document or you can
 chain a call to `observeLocal` or `subscribe` if you want to get
 updates about the document over time. It can also be used to update, remove
 or evict the document.

 @param docID The ID of the document.

 @return A `DITPendingIDSpecificOperation` that you can chain function calls to either get the
 document immediately or get updates about it over time.
 */
- (DITPendingIDSpecificOperation *)findByID:(DITDocumentID *)docID NS_SWIFT_NAME(findByID(_:));

/**
 Generates a `DITPendingCursorOperation` using the provided query.

 The returned object can be used to find and return the documents or you can
 chain a call to `observeLocal` or `subscribe` if you want to get
 updates about the list of matching documents over time. It can also be used
 to update, remove or evict the matching documents.

 @param query The query to run against the collection.

 @return A `DITPendingCursorOperation` that you can chain function calls to chain further
 query-related function calls.
 */
- (DITPendingCursorOperation *)find:(NSString *)query;

/**
 Generates a `DITPendingCursorOperation` using the provided query and query arguments.

 The returned object can be used to find and return the documents or you can
 chain a call to `observeLocal` or `subscribe` if you want to get
 updates about the list of matching documents over time. It can also be used
 to update, remove or evict the matching documents.

 This is the recommended method to use when performing queries on a collection if you have any
 dynamic data included in the query string. It allows you to provide a query string with
 placeholders, in the form of `$args.my_arg_name`, along with an accompanying dictionary of
 arguments, in the form of `{ "my_arg_name": "some value" }`, and the placeholders will be
 appropriately replaced by the matching provided arguments from the dictionary. This includes
 handling things like wrapping strings in quotation marks and arrays in square brackets, for
 example.

 @param query The query to run against the collection.
 @param queryArgs The arguments to use to replace placeholders in the provided query.

 @return A `DITPendingCursorOperation` that you can chain function calls to chain further
 query-related function calls.
 */
- (DITPendingCursorOperation *)find:(NSString *)query
                           withArgs:(NSDictionary<NSString *, id> *)queryArgs;

/**
 Generates a `DITPendingCursorOperation` that relates to all documents in the
 collection.

 The returned object can be used to find and return all of the documents in
 the collection or you can chain a call to `observeLocal` or `subscribe` if you want to get updates
 about the documents over time. It can also be used to update, remove or evict the documents.

 @return A `DITPendingCursorOperation` that you can chain function calls to chain further
 query-related function calls.
 */
- (DITPendingCursorOperation *)findAll;

/**
 Creates a new attachment, which can then be inserted into a document.

 The file residing at the provided path will be copied into Ditto's store. The `DITAttachment`
 object that is returned is what you can then use to insert an attachment into a document.

 You can provide metadata about the attachment, which will be replicated to
 other peers alongside the file attachment.

 Below is a snippet to show how you can use the `newAttachment` functionality to insert an
 attachment into a document.

 ```
 DITAttachment *attachment = [collection newAttachment:@"/path/to/my/file.pdf"];
 DITDocumentID docID = [collection insert:@{@"attachment": attachment, @"other": @"string"}];
 }
 ```

 @param path The path to the file that you want to create an attachment with.
 @param metadata Metadata relating to the attachment.

 @return A `DITAttachment` object, which can be used to insert the attachment into a document.
 */
- (nullable DITAttachment *)newAttachment:(NSString *)path
                                 metadata:(nullable NSDictionary<NSString *, NSString *> *)metadata;

/**
 Trigger an attachment to be downloaded locally to the device and observe its
 progress as it does so.

 When you encounter a document that contains an attachment the attachment
 will not automatically be downloaded along with the document. You trigger an
 attachment to be downloaded locally to a device by calling this method. It
 will report events relating to the attachment fetch attempt as it tries to
 download it. The `onFetchEvent` block may be called multiple times with
 progress events. It will then be called with either a
 `DITAttachmentFetchEventCompleted` event or a
 `DITAttachmentFetchEventDeleted` event. If downloading the attachment
 succeeds then the `DITAttachmentFetchEventCompleted` event that the
 `onFetchEvent`  block will be called with will hold a reference to the
 downloaded attachment.

 @param token The `DITAttachmentToken` relevant to the attachment that you
 wish to download and observe.
 @param onFetchEvent A block that will be called when there is a update to the status of the
 attachment fetch attempt.

 @return A `DITAttachmentFetcher` object, which must be kept alive for the fetch request to proceed
 and for you to be notified about the attachment's fetch status changes. If the attachment fetcher
 could not be created then `nil` will be returned. This can happen if, for example, an invalid
 attachment token was provided.
 */
- (nullable DITAttachmentFetcher *)fetchAttachment:(DITAttachmentToken *)token
                                      onFetchEvent:
                                          (void (^)(DITAttachmentFetchEvent *))onFetchEvent;

/**
 Trigger an attachment to be downloaded locally to the device and observe its
 progress as it does so.

 When you encounter a document that contains an attachment the attachment
 will not automatically be downloaded along with the document. You trigger an
 attachment to be downloaded locally to a device by calling this method. It
 will report events relating to the attachment fetch attempt as it tries to
 download it. The `onFetchEvent` block may be called multiple times with
 progress events. It will then be called with either a
 `DITAttachmentFetchEventCompleted` event or a
 `DITAttachmentFetchEventDeleted` event. If downloading the attachment
 succeeds then the `DITAttachmentFetchEventCompleted` event that the
 `onFetchEvent`  block will be called with will hold a reference to the
 downloaded attachment.

 @param token The `DITAttachmentToken` relevant to the attachment that you
 wish to download and observe.
 @param dispatchQueue The dispatch queue that will be used when calling
 the provided block to deliver fetch events. You can use the version of this
 method that does not take a `dispatch_queue_t` argument if you want the main
 queue to be used.
 @param onFetchEvent A block that will be called when there is a update to the status of the
 attachment fetch attempt.

 @return A `DITAttachmentFetcher` object, which must be kept alive for the fetch request to proceed
 and for you to be notified about the attachment's fetch status changes. If the attachment fetcher
 could not be created then `nil` will be returned. This can happen if, for example, an invalid
 attachment token was provided.
 */
- (nullable DITAttachmentFetcher *)fetchAttachment:(DITAttachmentToken *)token
                                     deliveryQueue:(dispatch_queue_t)dispatchQueue
                                      onFetchEvent:
                                          (void (^)(DITAttachmentFetchEvent *))onFetchEvent;

@end

NS_ASSUME_NONNULL_END
