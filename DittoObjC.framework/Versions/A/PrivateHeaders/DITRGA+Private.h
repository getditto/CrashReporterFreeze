//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITRGA.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITRGA () {
    @protected
    NSArray<id> *_value;
}

/**
 Initializes a new RGA that can be used as part of a document's content.

 @param array the array to use as the RGA's representation.

 @deprecated `DITRGA` usage should be replaced. Use arrays inside `DITRegister`s instead.
 */
- (instancetype)initWithArray:(NSArray<id> *)array NS_DESIGNATED_INITIALIZER
    __deprecated_msg("DITRGA usage should be replaced. Use arrays inside DITRegisters instead.");

@end

NS_ASSUME_NONNULL_END
