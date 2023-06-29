//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface _DITDittoHandleWrapper : NSObject

@property (nonatomic, readonly) void *dittoHandle;

- (instancetype)initWithHandle:(void *)handle;

@end

NS_ASSUME_NONNULL_END
