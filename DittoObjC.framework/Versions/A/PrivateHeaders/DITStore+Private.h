//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITStore.h>

@class _DITDittoHandleWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITStore ()
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper;

@end

NS_ASSUME_NONNULL_END
