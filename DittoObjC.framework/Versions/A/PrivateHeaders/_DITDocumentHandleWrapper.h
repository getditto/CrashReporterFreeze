//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/dittoffi.h>

struct Ditto_Document;

NS_ASSUME_NONNULL_BEGIN

@interface _DITDocumentHandleWrapper : NSObject
@property (nonatomic, readonly, unsafe_unretained) CDocument_t *documentHandle;

- (instancetype)initWithDocumentHandle:(CDocument_t *)documentHandle;
@end

NS_ASSUME_NONNULL_END
