//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITAttachment.h>

NS_ASSUME_NONNULL_BEGIN

@class _DITDittoHandleWrapper;

struct AttachmentHandle;

@interface DITAttachment ()

@property (nonatomic, readonly) NSData *id;
@property (nonatomic, readonly) NSUInteger len;
@property (nonatomic, readonly) struct AttachmentHandle *handle;
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readwrite, nullable) NSString *path;

- (instancetype)initWithID:(NSData *)id
                       len:(NSUInteger)len
                  metadata:(NSDictionary<NSString *, NSString *> *)metadata
                    handle:(struct AttachmentHandle *)handle
        dittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper;

@end

NS_ASSUME_NONNULL_END
