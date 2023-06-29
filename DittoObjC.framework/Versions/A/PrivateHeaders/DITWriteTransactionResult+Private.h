//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITWriteTransactionResult.h>

@class DITDocumentID;

NS_ASSUME_NONNULL_BEGIN

@interface DITWriteTransactionResultInserted ()
- (instancetype)initWithDocID:(DITDocumentID *)docID collectionName:(NSString *)collectionName;
@end

@interface DITWriteTransactionResultRemoved ()
- (instancetype)initWithDocID:(DITDocumentID *)docID collectionName:(NSString *)collectionName;
@end

@interface DITWriteTransactionResultEvicted ()
- (instancetype)initWithDocID:(DITDocumentID *)docID collectionName:(NSString *)collectionName;
@end

@interface DITWriteTransactionResultUpdated ()
- (instancetype)initWithDocID:(DITDocumentID *)docID collectionName:(NSString *)collectionName;
@end

NS_ASSUME_NONNULL_END
