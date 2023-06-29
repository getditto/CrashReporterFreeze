//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITPendingIDSpecificOperation.h>
#import <DittoObjC/dittoffi.h>

@class DITDocument;
@class DITDocumentID;
@class DITLiveQuery;
@class DITSingleDocumentLiveQueryEvent;
@class DITSubscription;

@class _DITDittoHandleWrapper;
@class _DITDocumentHandleWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITPendingIDSpecificOperation ()
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) DITDocumentID *documentID;
@property (nonatomic, readonly) NSString *collectionName;
@property (nonatomic, readonly) NSString *query;

- (instancetype)initWithDocumentID:(DITDocumentID *)documentID
                    collectionName:(NSString *)collectionName
                dittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper;

// MARK: Observe (internal for ObjC)

- (DITLiveQuery *)observeWithSubscription:(nullable DITSubscription *)subscription
                            deliveryQueue:(dispatch_queue_t)deliveryQueue
                             availability:(LiveQueryAvailability_t)availability
                             eventHandler:(void (^)(DITDocument *_Nullable,
                                                    DITSingleDocumentLiveQueryEvent *,
                                                    void (^_Nullable)(void)))eventHandler;

// MARK: Observe (internal for Swift)

- (DITLiveQuery *)observeLocalWithDeliveryQueue:(dispatch_queue_t)dispatchQueue
                eventHandlerUsingDocumentHandle:
                    (void (^)(BOOL,
                              _DITDocumentHandleWrapper *_Nullable,
                              _DITDocumentHandleWrapper *_Nullable))eventHandlerUsingDocumentHandle;

- (DITLiveQuery *)observeLocalWithNextSignalAndDeliveryQueue:(dispatch_queue_t)dispatchQueue
                             eventHandlerUsingDocumentHandle:
                                 (void (^)(BOOL,
                                           _DITDocumentHandleWrapper *_Nullable,
                                           _DITDocumentHandleWrapper *_Nullable,
                                           void (^_Nullable)(void)))eventHandlerUsingDocumentHandle
    NS_SWIFT_NAME(observeLocalWithNextSignal(deliveryQueue:eventHandlerUsingDocumentHandle:));

- (DITLiveQuery *)observeWithSubscription:(nullable DITSubscription *)subscription
                            deliveryQueue:(dispatch_queue_t)dispatchQueue
                             availability:(LiveQueryAvailability_t)availability
          eventHandlerUsingDocumentHandle:
              (void (^)(BOOL,
                        _DITDocumentHandleWrapper *_Nullable,
                        _DITDocumentHandleWrapper *_Nullable,
                        void (^_Nullable)(void)))eventHandlerUsingDocumentHandle;

// MARK: Other internal

- (void)updateUsingData:(NSData *)data;
- (nullable _DITDocumentHandleWrapper *)execReturningDocumentHandle;
@end

NS_ASSUME_NONNULL_END
