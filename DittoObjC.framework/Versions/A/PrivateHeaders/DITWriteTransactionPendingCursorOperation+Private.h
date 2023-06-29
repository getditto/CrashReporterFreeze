//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITWriteTransactionPendingCursorOperation.h>
#import <DittoObjC/dittoffi.h>

@class _DITDocumentHandleWrapper;
@class _DITOrderBy;
@class DITDocumentID;
@class DITMutableDocument;
@class DITWriteTransaction;

NS_ASSUME_NONNULL_BEGIN

@interface DITWriteTransactionPendingCursorOperation ()
@property (nonatomic, readonly) NSString *query;
@property (nonatomic, readonly, nullable) NSData *queryArgsData;
@property (nonatomic, readonly) NSString *collectionName;
@property (nonatomic, readwrite) int limit;
@property (nonatomic, readwrite) uint offset;
@property (nonatomic, readwrite) _DITOrderBy *orderBy;
// This holds a `DittoHandleWrapper` reference, so we don't have to hold another
// reference explicitly as we are already implicitly holding one here.
@property (nonatomic, readonly) DITWriteTransaction *baseTransaction;
@property (nonatomic, readwrite, nullable) NSError *error;

- (instancetype)initWithQuery:(NSString *)query
                queryArgsData:(nullable NSData *)queryArgsData
               collectionName:(NSString *)collectionName
              baseTransaction:(DITWriteTransaction *)baseTransaction;

// MARK: Swift internals

- (nullable NSArray<_DITDocumentHandleWrapper *> *)execWithErr:
    (NSError *_Nullable __autoreleasing *)error;
- (nullable NSArray<DITDocumentID *> *)removeWithErr:(NSError *_Nullable __autoreleasing *)error;
- (nullable NSArray<DITDocumentID *> *)evictWithErr:(NSError *_Nullable __autoreleasing *)error;
- (nullable NSDictionary<DITDocumentID *, NSArray<DITUpdateResult *> *> *)
    updateWithBlock:(void (^)(NSArray<DITMutableDocument *> *))block
              error:(NSError *_Nullable __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
