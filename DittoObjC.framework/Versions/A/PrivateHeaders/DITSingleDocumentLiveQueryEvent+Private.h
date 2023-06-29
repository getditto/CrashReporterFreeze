//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITSingleDocumentLiveQueryEvent.h>

@class DITDocument;

NS_ASSUME_NONNULL_BEGIN

@interface DITSingleDocumentLiveQueryEvent ()

- (instancetype)initWithIsInitial:(BOOL)isInitial oldDocument:(nullable DITDocument *)oldDocument;

@end

NS_ASSUME_NONNULL_END
