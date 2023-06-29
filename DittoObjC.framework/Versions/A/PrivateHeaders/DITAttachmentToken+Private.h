//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITAttachmentToken.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITAttachmentToken ()

@property (nonatomic, readonly) NSData *id;
@property (nonatomic, readonly) NSUInteger len;
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *metadata;

- (nullable instancetype)initWithInfo:(NSDictionary<NSString *, id> *)info;

@end

NS_ASSUME_NONNULL_END
