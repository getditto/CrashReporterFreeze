//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDocument.h>

#import <Foundation/Foundation.h>

@class _DITDocumentHandleWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITDocument ()
@property (nonatomic, readonly) _DITDocumentHandleWrapper *documentHandleWrapper;

- (instancetype)initWithDocumentHandleWrapper:(_DITDocumentHandleWrapper *)documentHandleWrapper;
@end

NS_ASSUME_NONNULL_END
