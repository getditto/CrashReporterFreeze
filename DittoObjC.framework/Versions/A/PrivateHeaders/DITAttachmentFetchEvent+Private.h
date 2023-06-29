//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITAttachmentFetchEvent.h>

@class DITAttachment;

NS_ASSUME_NONNULL_BEGIN

@interface DITAttachmentFetchEventCompleted ()
- (instancetype)initWithAttachment:(DITAttachment *)attachment;
@end

@interface DITAttachmentFetchEventProgress ()
- (instancetype)initWithDownloadedBytes:(NSUInteger)downloadedBytes
                             totalBytes:(NSUInteger)totalBytes;
@end

@interface DITAttachmentFetchEventDeleted ()
- (instancetype)init;
@end

NS_ASSUME_NONNULL_END
