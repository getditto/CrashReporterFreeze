//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITWriteTransaction.h>
#import <DittoObjC/dittoffi.h>

@class _DITDittoHandleWrapper;
@class DITWriteTransactionResult;

NS_ASSUME_NONNULL_BEGIN

@interface DITWriteTransaction ()
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) CWriteTransaction_t *writeTxn;
@property (nonatomic, readonly) NSMutableArray<DITWriteTransactionResult *> *results;

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper
                                  writeTxn:(CWriteTransaction_t *)writeTxn;
@end

NS_ASSUME_NONNULL_END
