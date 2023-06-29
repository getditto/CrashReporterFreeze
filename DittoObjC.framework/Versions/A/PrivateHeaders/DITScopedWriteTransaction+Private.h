//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITScopedWriteTransaction.h>
#import <DittoObjC/DITWriteStrategy.h>

@class DITDocumentID;
@class DITWriteTransaction;
@class DITWriteTransactionPendingCursorOperation;

NS_ASSUME_NONNULL_BEGIN

@interface DITScopedWriteTransaction ()
@property (nonatomic, readonly) DITWriteTransaction *baseTransaction;

- (instancetype)initWithBaseTransaction:(DITWriteTransaction *)baseTransaction
                         collectionName:(NSString *)collectionName;

- (nullable DITDocumentID *)upsert:(NSDictionary<NSString *, id> *)content
                            withID:(nullable DITDocumentID *)id
                     writeStrategy:(DITWriteStrategy)writeStrategy
                             error:(NSError *_Nullable __autoreleasing *)error
    NS_SWIFT_NAME(upsert(_:withID:writeStrategy:));

- (nullable DITDocumentID *)upsertCBORData:(NSData *)data
                                    withID:(nullable DITDocumentID *)id
                             writeStrategy:(DITWriteStrategy)writeStrategy
                                     error:(NSError *_Nullable __autoreleasing *)error
    NS_SWIFT_NAME(upsertCBORData(_:withID:writeStrategy:));

- (DITWriteTransactionPendingCursorOperation *)find:(NSString *)query
                                       withArgsData:(nullable NSData *)queryArgsData;

@end

NS_ASSUME_NONNULL_END
