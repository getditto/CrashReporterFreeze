//
//  Copyright © 2021 Ditto. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITSignalNext.h>
#import <DittoObjC/DITSortDirection.h>

@class DITCollection;
@class DITCollectionsEvent;
@class DITLiveQuery;
@class DITSubscription;

NS_ASSUME_NONNULL_BEGIN

/**
 These objects are returned when calling `collections` on `DITStore`.

 They allow chaining of further collections-related functions. You can either call `exec` on the
 object to get an array of `DITCollection`s as an immediate return value, or you can establish
 either a live query or a subscription, which both work over time.

 A live query, established by calling `observeLocal`, will notify you every time there's a change in
 the collections that the device knows about.

 A subscription, established by calling `subscribe`, will act as a signal to other peers that
 you would like to receive updates from them about the collections that they know about.

 Typically, an app would set up a `subscribe` in some part of the application which is long-lived to
 ensure the device receives updates from the mesh. These updates will be automatically received and
 written into the local store. Elsewhere, where you need to use this data, an `observeLocal` can be
 used to notify you of the data, and all subsequent changes to the data.

 If you want to observe changes in such a way that you can signal when you're ready for the live
 query to deliver a new update then you can call `observeLocalWithNextSignal`.
 */
@interface DITPendingCollectionsOperation : NSObject

/**
 Limit the number of collections that get returned.

 @param limit The maximum number of collections that will be returned.

 @return A `DITPendingCollectionsOperation` that you can chain further function calls to.
 */
- (DITPendingCollectionsOperation *)limit:(int)limit;

/**
 Offset the resulting set of collections.

 This is useful if you aren't interested in the first N collections for one reason or another. For
 example, you might already have obtained the first 20 collections and so you might want to get the
 next 20 collections, and that is when you would use `offset`.

 @param offset The number of collections that you want the eventual resulting set of collections to
 be offset by (and thus not include).

 @return A `DITPendingCollectionsOperation` that you can chain further function calls to.
 */
- (DITPendingCollectionsOperation *)offset:(uint)offset;

/**
 Sort the collections based on a property of the collection.

 @param query The query specifies the logic to be used when sorting the collections.
 @param direction Specify whether you want the sorting order to be ascending or descending.

 @return A `DITPendingCollectionsOperation` that you can chain further function calls to.
 */
- (DITPendingCollectionsOperation *)sort:(NSString *)query direction:(DITSortDirection)direction;

/**
 Return the list of collections requested based on the preceding function chaining.

 @return A list of `DITCollections`s based on the preceding function chaining.
 */
- (NSArray<DITCollection *> *)exec;

/**
 Subscribes the device to updates about collections that other devices know about.

 The returned `DITSubscription` object must be kept in scope for as long as you want to keep
 receiving updates.

 @return A `DITSubscription` object that must be kept in scope for as long as you want to keep
 receiving updates from other devices about the collections that they know about.
 */
- (DITSubscription *)subscribe;

/**
 Enables you to subscribe to updates about collections local to this device.

 This won't subscribe to receive updates from other devices and so it will only fire when a local
 change to the known collections occurs. If you want to receive remote updates as well then use
 `subscribe`.

 The returned `DITLiveQuery` object must be kept in scope for as long as you want the provided
 `eventHandler` to be called when an update occurs.

 @param eventHandler A block that will be called every time there is an update about the list of
 known about collections.

 @return A `DITLiveQuery` object that must be kept in scope for as long as you want to keep
 receiving updates.
 */
- (DITLiveQuery *)observeLocal:(void (^)(DITCollectionsEvent *))eventHandler;

/**
 Enables you to subscribe to updates about collections local to this device.

 This won't subscribe to receive updates from other devices and so it will only fire when a local
 change to the known collections occurs. If you want to receive remote updates as well then use
 `subscribe`.

 The returned `DITLiveQuery` object must be kept in scope for as long as you want the provided
 `eventHandler` to be called when an update occurs.

 @param dispatchQueue The dispatch queue that will be used to deliver live query updates. Defaults
 to the main queue.
 @param eventHandler A block that will be called every time there is an update about the list of
 known about collections.

 @return A `DITLiveQuery` object that must be kept in scope for as long as you want to keep
 receiving updates.
 */
- (DITLiveQuery *)observeLocalWithDeliveryQueue:(dispatch_queue_t)dispatchQueue
                                   eventHandler:(void (^)(DITCollectionsEvent *))eventHandler;

/**
 Enables you to subscribe to updates about collections local to this device.

 This won't subscribe to receive updates from other devices and so it will only fire when a local
 change to the known collections occurs. If you want to receive remote updates as well then use
 `subscribe`.

 You wont receive any further callbacks until you explicitly signal that you are ready for the next
 event to be delivered.

 This is a power-user API. If you're unsure about which to use, you should probably default to using
 the simpler `observeLocal:` API.

 The returned `DITLiveQuery` object must be kept in scope for as long as you want the provided
 `eventHandler` to be called when an update occurs.

 @param eventHandler A block that will be called every time there is an update about the list of
 known about collections.

 @return A `DITLiveQuery` object that must be kept in scope for as long as you want to keep
 receiving updates.
 */
- (DITLiveQuery *)observeLocalWithNextSignal:(void (^)(DITCollectionsEvent *,
                                                       DITSignalNextBlock))eventHandler;

/**
 Enables you to subscribe to updates about collections local to this device.

 This won't subscribe to receive updates from other devices and so it will only fire when a local
 change to the known collections occurs. If you want to receive remote updates as well then use
 `subscribe`.

 You wont receive any further callbacks until you explicitly signal that you are ready for the next
 event to be delivered.

 This is a power-user API. If you're unsure about which to use, you should probably default to using
 the simpler `observeLocal:` API.

 The returned `DITLiveQuery` object must be kept in scope for as long as you want the provided
 `eventHandler` to be called when an update occurs.

 @param dispatchQueue The dispatch queue that will be used to deliver live query updates. Defaults
 to the main queue.
 @param eventHandler A block that will be called every time there is an update about the list of
 known about collections.

 @return A `DITLiveQuery` object that must be kept in scope for as long as you want to keep
 receiving updates.
 */
- (DITLiveQuery *)observeLocalWithNextSignalAndDeliveryQueue:(dispatch_queue_t)dispatchQueue
                                                eventHandler:
                                                    (void (^)(DITCollectionsEvent *,
                                                              DITSignalNextBlock))eventHandler
    NS_SWIFT_NAME(observeLocalWithNextSignal(deliveryQueue:eventHandler:));

@end

NS_ASSUME_NONNULL_END
