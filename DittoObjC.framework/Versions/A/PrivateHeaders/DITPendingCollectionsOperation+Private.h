//
//  Copyright © 2021 Ditto. All rights reserved.
//

#import <DittoObjC/DITPendingCollectionsOperation.h>

@class _DITDittoHandleWrapper;
@class DITPendingCursorOperation;

NS_ASSUME_NONNULL_BEGIN

@interface DITPendingCollectionsOperation ()

@property (nonatomic, readonly) DITPendingCursorOperation *pendingCursorOperation;

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper;

@end

NS_ASSUME_NONNULL_END
