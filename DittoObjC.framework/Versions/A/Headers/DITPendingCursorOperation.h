//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITSignalNext.h>
#import <DittoObjC/DITSortDirection.h>

@class DITDocument;
@class DITDocumentID;
@class DITLiveQuery;
@class DITLiveQueryEvent;
@class DITMutableDocument;
@class DITSubscription;
@class DITUpdateResult;

NS_ASSUME_NONNULL_BEGIN

/**
 These objects are returned when using `find`-like functionality on `DITCollection`s.

 They allow chaining of further query-related functions to do things like add a limit to the number
 of documents you want returned or specify how you want the documents to be sorted and ordered.

 You can either call `exec` on the object to get an array of `DITDocument`s as an immediate return
 value, or you can establish either a live query or a subscription, which both work over time.

 A live query, established by calling `observeLocal`, will notify you every time there's an update
 to a document that matches the query you provided in the preceding `find`-like call.

 A subscription, established by calling `subscribe`, will act as a signal to other peers that the
 device connects to that you would like to receive updates from them about documents that match the
 query you provided in the preceding `find`-like call.

 Typically, an app would set up a `subscribe` in some part of the application which is long-lived to
 ensure the device receives updates from the mesh. These updates will be automatically received and
 written into the local store. Elsewhere, where you need to use this data, an `observeLocal` can be
 used to notify you of the data, and all subsequent changes to the data.

 If you want to observe changes in such a way that you can signal when you're ready for the live
 query to deliver a new update then you can call `observeLocalWithNextSignal`.

 Update and remove functionality is also exposed through this object.
 */
@interface DITPendingCursorOperation : NSObject

/**
 Limit the number of documents that get returned when querying a collection for matching documents.

 @param limit The maximum number of documents that will be returned.

 @return A `DITPendingCursorOperation` that you can chain further function calls and then either get
 the matching documents immediately or get updates about them over time.
 */
- (DITPendingCursorOperation *)limit:(int)limit;

/**
 Offset the resulting set of matching documents.

 This is useful if you aren't interested in the first N matching documents for one reason or
 another. For example, you might already have queried the collection and obtained the first 20
 matching documents and so you might want to run the same query as you did previously but ignore the
 first 20 matching documents, and that is when you would use `offset`.

 @param offset The number of matching documents that you want the eventual resulting set of matching
 documents to be offset by (and thus not include).

 @return A `DITPendingCursorOperation` that you can chain further function calls and then either get
 the matching documents immediately or get updates about them over time.
 */
- (DITPendingCursorOperation *)offset:(uint)offset;

/**
 Sort the documents that match the query provided in the preceding `find`-like function call.

 @param query The query specifies the logic to be used when sorting the matching documents.
 @param direction Specify whether you want the sorting order to be ascending or descending.

 @return A `DITPendingCursorOperation` that you can chain further function calls and then either get
 the matching documents immediately or get updates about them over time.
 */
- (DITPendingCursorOperation *)sort:(NSString *)query direction:(DITSortDirection)direction;

/**
 Execute the query generated by the preceding function chaining and return the list of matching
 documents.

 @return A list of `DITDocument`s matching the query generated by the preceding function chaining.
 */
- (NSArray<DITDocument *> *)exec NS_SWIFT_UNAVAILABLE("Use execWithErr instead");

/**
 Remove all documents that match the query generated by the preceding function chaining.

 @return A list containing the IDs of the documents that were removed.
 */
- (NSArray<DITDocumentID *> *)remove NS_SWIFT_UNAVAILABLE("Use removeWithErr instead");

/**
 Evict all documents that match the query generated by the preceding function chaining.

 @return A list containing the IDs of the documents that were evicted.
 */
- (NSArray<DITDocumentID *> *)evict NS_SWIFT_UNAVAILABLE("Use evictWithErr instead");

/**
 Update documents that match the query generated by the preceding function chaining.

 @param block A block that gets called with all of the documents matching the query. The documents
 are `DITMutableDocument`s so you can call update-related functions on them.

 @return A dictionary mapping document IDs to lists of `DITUpdateResult`s that describes the updates
 that were performed for each document.
 */
- (NSDictionary<DITDocumentID *, NSArray<DITUpdateResult *> *> *)updateWithBlock:
    (void (^)(NSArray<DITMutableDocument *> *))block
    NS_SWIFT_UNAVAILABLE("Use version that accepts an error out param instead");

/**
 Enables you to subscribe to changes that occur in a collection remotely.

 Having a subscription acts as a signal to other peers that you are interested in receiving updates
 when local or remote changes are made to documents that match the query generated by the chain of
 operations that precedes the call to `subscribe`.

 The returned `DITSubscription` object must be kept in scope for as long as you want to keep
 receiving updates.

 @return A `DITSubscription` object that must be kept in scope for as long as you want to keep
 receiving updates for documents that match the query specified in the preceding chain.
 */
- (DITSubscription *)subscribe NS_SWIFT_UNAVAILABLE("Use subscribeWithError: instead");

/**
 Enables you to subscribe to changes that occur in a collection locally.

 This won't subscribe to receive changes made remotely by others and so it will only fire updates
 when a local change is made. If you want to receive remotely performed updates as well then also
 call `subscribe` with the relevant query. The returned `DITLiveQuery` object must be kept in scope
 for as long as you want the provided `eventHandler` to be called when an update occurs.

 @param eventHandler A block that will be called every time there is a transaction committed to the
 store that involves modifications to documents matching the query in the collection that
 `observeLocal` was called on.

 @return A `DITLiveQuery` object that must be kept in scope for as long as you want to keep
 receiving updates.
 */
- (DITLiveQuery *)observeLocal:(void (^)(NSArray<DITDocument *> *,
                                         DITLiveQueryEvent *))eventHandler;

/**
 Enables you to subscribe to changes that occur in a collection locally.

 This won't subscribe to receive changes made remotely by others and so it will only fire updates
 when a local change is made. If you want to receive remotely performed updates as well then also
 call `subscribe` with the relevant query. The returned `DITLiveQuery` object must be kept in scope
 for as long as you want the provided `eventHandler` to be called when an update occurs.

 @param dispatchQueue The dispatch queue that will be used to deliver live query updates. Defaults
 to the main queue.
 @param eventHandler A block that will be called every time there is a transaction committed to the
 store that involves modifications to documents matching the query in the collection that
 `observeLocalWithDeliveryQueue` was called on.

 @return A `DITLiveQuery` object that must be kept in scope for as long as you want to keep
 receiving updates.
 */
- (DITLiveQuery *)observeLocalWithDeliveryQueue:(dispatch_queue_t)dispatchQueue
                                   eventHandler:(void (^)(NSArray<DITDocument *> *,
                                                          DITLiveQueryEvent *))eventHandler;

/**
 Enables you to subscribe to changes that occur in a collection locally and to signal when you are
 ready for the live query to deliver the next event.

 This won't subscribe to receive changes made remotely by others and so it will only fire updates
 when a local change is made. If you want to receive remotely performed updates as well then also
 call `subscribe` with the relevant query. The returned `DITLiveQuery` object must be kept in scope
 for as long as you want the provided `eventHandler` to be called when an update occurs.

 @param eventHandler A block that will be called every time there is a transaction committed to the
 store that involves modifications to documents matching the query in the collection that
 `observeLocalWithNextSignal` was called on.

 @return A `DITLiveQuery` object that must be kept in scope for as long as you want to keep
 receiving updates.
 */
- (DITLiveQuery *)observeLocalWithNextSignal:
    (void (^)(NSArray<DITDocument *> *, DITLiveQueryEvent *, DITSignalNextBlock))eventHandler;

/**
 Enables you to subscribe to changes that occur in a collection locally and to signal when you are
 ready for the live query to deliver the next event.

 This won't subscribe to receive changes made remotely by others and so it will only fire updates
 when a local change is made. If you want to receive remotely performed updates as well then also
 call `subscribe` with the relevant query. The returned `DITLiveQuery` object must be kept in scope
 for as long as you want the provided `eventHandler` to be called when an update occurs.

 @param dispatchQueue The dispatch queue that will be used to deliver live query updates. Defaults
 to the main queue.
 @param eventHandler A block that will be called every time there is a transaction committed to the
 store that involves modifications to documents matching the query in the collection that
 `observeLocalWithNextSignalAndDeliveryQueue` was called on.

 @return A `DITLiveQuery` object that must be kept in scope for as long as you want to keep
 receiving updates.
 */
- (DITLiveQuery *)observeLocalWithNextSignalAndDeliveryQueue:(dispatch_queue_t)dispatchQueue
                                                eventHandler:
                                                    (void (^)(NSArray<DITDocument *> *,
                                                              DITLiveQueryEvent *,
                                                              DITSignalNextBlock))eventHandler;

@end

NS_ASSUME_NONNULL_END