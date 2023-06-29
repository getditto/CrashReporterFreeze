//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITLiveQuery.h>
#import <DittoObjC/dittoffi.h>

@class DITDocument;
@class DITLiveQueryEvent;
@class DITLiveQueryMove;
@class DITSubscription;

@class _DITDittoHandleWrapper;
@class _DITDocumentHandleWrapper;
@class _DITOrderBy;

NS_ASSUME_NONNULL_BEGIN

@interface DITLiveQuery ()
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly, nullable) NSData *queryArgsData;
@property (nonatomic, readonly) int limit;
@property (nonatomic, readonly) uint offset;
@property (nonatomic, readonly, nullable) DITSubscription *subscription;
@property (nonatomic, readonly) int64_t lqID;
@property (nonatomic, readonly) dispatch_queue_t deliveryDispatchQueue;
@property (nonatomic, readonly, nullable) void (^eventHandler)
    (NSArray<DITDocument *> *, DITLiveQueryEvent *, void (^_Nullable)(void));
@property (nonatomic, readonly, nullable) void (^documentHandleEventHandler)
    (BOOL,
     NSArray<_DITDocumentHandleWrapper *> *,
     NSArray<_DITDocumentHandleWrapper *> *,
     NSArray<NSNumber *> *,
     NSArray<NSNumber *> *,
     NSArray<NSNumber *> *,
     NSArray<DITLiveQueryMove *> *,
     void (^_Nullable)(void));
@property (nonatomic, readonly, nullable) void (^signalNextBlock)(void);

- (instancetype)initWithQuery:(NSString *)query
                queryArgsData:(nullable NSData *)queryArgsData
               collectionName:(NSString *)collectionName
                      orderBy:(_DITOrderBy *)orderBy
                        limit:(int)limit
                       offset:(uint)offset
                 availability:(LiveQueryAvailability_t)availability
                 subscription:(nullable DITSubscription *)subscription
           dittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper
        deliveryDispatchQueue:(dispatch_queue_t)dispatchQueue
                 eventHandler:(void (^)(NSArray<DITDocument *> *,
                                        DITLiveQueryEvent *,
                                        void (^_Nullable)(void)))eventHandler;

- (instancetype)initWithQuery:(NSString *)query
                 queryArgsData:(nullable NSData *)queryArgsData
                collectionName:(NSString *)collectionName
                       orderBy:(_DITOrderBy *)orderBy
                         limit:(int)limit
                        offset:(uint)offset
                  availability:(LiveQueryAvailability_t)availability
                  subscription:(nullable DITSubscription *)subscription
            dittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper
         deliveryDispatchQueue:(dispatch_queue_t)dispatchQueue
    documentHandleEventHandler:(void (^)(BOOL,
                                         NSArray<_DITDocumentHandleWrapper *> *,
                                         NSArray<_DITDocumentHandleWrapper *> *,
                                         NSArray<NSNumber *> *,
                                         NSArray<NSNumber *> *,
                                         NSArray<NSNumber *> *,
                                         NSArray<DITLiveQueryMove *> *,
                                         void (^_Nullable)(void)))documentHandleEventHandler;

- (instancetype)initWithQuery:(NSString *)query
                 queryArgsData:(nullable NSData *)queryArgsData
                collectionName:(NSString *)collectionName
                       orderBy:(nullable _DITOrderBy *)orderBy
                         limit:(int)limit
                        offset:(uint)offset
                  availability:(LiveQueryAvailability_t)availability
                  subscription:(nullable DITSubscription *)subscription
            dittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper
         deliveryDispatchQueue:(dispatch_queue_t)dispatchQueue
                  eventHandler:(void (^_Nullable)(NSArray<DITDocument *> *,
                                                  DITLiveQueryEvent *,
                                                  void (^_Nullable)(void)))eventHandler
    documentHandleEventHandler:
        (void (^_Nullable)(BOOL,
                           NSArray<_DITDocumentHandleWrapper *> *,
                           NSArray<_DITDocumentHandleWrapper *> *,
                           NSArray<NSNumber *> *,
                           NSArray<NSNumber *> *,
                           NSArray<NSNumber *> *,
                           NSArray<DITLiveQueryMove *> *,
                           void (^_Nullable)(void)))documentHandleEventHandler;

+ (NSArray<DITDocument *> *)documentsFrom:(Vec_CDocument_ptr_t)docsVec;
+ (NSArray<NSNumber *> *)indexesFrom:(slice_boxed_size_t)idxs_boxed;
@end

NS_ASSUME_NONNULL_END
