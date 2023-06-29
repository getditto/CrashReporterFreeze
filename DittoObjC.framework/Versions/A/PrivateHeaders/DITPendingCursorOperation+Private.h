//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITPendingCursorOperation.h>
#import <DittoObjC/dittoffi.h>

@class _DITDittoHandleWrapper;
@class _DITDocumentHandleWrapper;
@class _DITOrderBy;
@class DITLiveQuery;
@class DITLiveQueryEvent;
@class DITLiveQueryMove;
@class DITSubscription;

NS_ASSUME_NONNULL_BEGIN

@interface DITPendingCursorOperation ()
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) NSString *collectionName;
@property (nonatomic, readonly) NSString *query;
@property (nonatomic, readonly, nullable) NSData *queryArgsData;
@property (nonatomic, readwrite) int limit;
@property (nonatomic, readwrite) uint offset;
@property (nonatomic, readonly) _DITOrderBy *orderBy;

- (instancetype)initWithQuery:(NSString *)query
                queryArgsData:(nullable NSData *)queryArgsData
               collectionName:(NSString *)collectionName
           dittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper;

// MARK: Observe (internal for Swift)

- (nullable DITLiveQuery *)observeLocalWithDeliveryQueue:(dispatch_queue_t)dispatchQueue
                                                   error:(NSError *_Nullable __autoreleasing *)error
                        eventHandlerUsingDocumentHandles:
                            (void (^)(BOOL,
                                      NSArray<_DITDocumentHandleWrapper *> *,
                                      NSArray<_DITDocumentHandleWrapper *> *,
                                      NSArray<NSNumber *> *,
                                      NSArray<NSNumber *> *,
                                      NSArray<NSNumber *> *,
                                      NSArray<DITLiveQueryMove *> *))eventHandler;

- (nullable DITLiveQuery *)
    observeLocalWithNextSignalAndDeliveryQueue:(dispatch_queue_t)dispatchQueue
                                         error:(NSError *_Nullable __autoreleasing *)error
              eventHandlerUsingDocumentHandles:(void (^)(BOOL,
                                                         NSArray<_DITDocumentHandleWrapper *> *,
                                                         NSArray<_DITDocumentHandleWrapper *> *,
                                                         NSArray<NSNumber *> *,
                                                         NSArray<NSNumber *> *,
                                                         NSArray<NSNumber *> *,
                                                         NSArray<DITLiveQueryMove *> *,
                                                         void (^_Nullable)(void)))eventHandler
    NS_SWIFT_NAME(observeLocalWithNextSignal(deliveryQueue:eventHandlerUsingDocumentHandles:));

- (nullable DITLiveQuery *)observeWithSubscription:(nullable DITSubscription *)subscription
                                     deliveryQueue:(dispatch_queue_t)deliveryQueue
                                      availability:(LiveQueryAvailability_t)availability
                                             error:(NSError *_Nullable __autoreleasing *)error
                  eventHandlerUsingDocumentHandles:(void (^)(BOOL,
                                                             NSArray<_DITDocumentHandleWrapper *> *,
                                                             NSArray<_DITDocumentHandleWrapper *> *,
                                                             NSArray<NSNumber *> *,
                                                             NSArray<NSNumber *> *,
                                                             NSArray<NSNumber *> *,
                                                             NSArray<DITLiveQueryMove *> *,
                                                             void (^_Nullable)(void)))eventHandler;

// MARK: More Swift internals

- (nullable NSArray<_DITDocumentHandleWrapper *> *)execWithErr:
    (NSError *_Nullable __autoreleasing *)error;
- (nullable NSArray<DITDocumentID *> *)removeWithErr:(NSError *_Nullable __autoreleasing *)error;
- (nullable NSArray<DITDocumentID *> *)removeWithLogHint:(NSString *)logHint
                                                     err:(NSError *_Nullable __autoreleasing *)
                                                             error;
- (nullable NSArray<DITDocumentID *> *)evictWithErr:(NSError *_Nullable __autoreleasing *)error;
- (nullable NSArray<DITDocumentID *> *)evictWithLogHint:(NSString *)logHint
                                                    err:(NSError *_Nullable __autoreleasing *)error;

- (nullable NSDictionary<DITDocumentID *, NSArray<DITUpdateResult *> *> *)
    updateWithBlock:(void (^)(NSArray<DITMutableDocument *> *))block
              error:(NSError *_Nullable __autoreleasing *)error;
- (nullable NSDictionary<DITDocumentID *, NSArray<DITUpdateResult *> *> *)
    updateWithLogHint:(NSString *)logHint
                block:(void (^)(NSArray<DITMutableDocument *> *))block
                error:(NSError *_Nullable __autoreleasing *)error;

- (nullable DITSubscription *)subscribeWithError:(NSError *_Nullable __autoreleasing *)error
    NS_SWIFT_NAME(subscribe());

@end

NS_ASSUME_NONNULL_END
