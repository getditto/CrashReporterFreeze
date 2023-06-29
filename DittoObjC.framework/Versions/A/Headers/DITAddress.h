//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An address uniquely identifying another peer on the Ditto network.
 */
@interface DITAddress : NSObject <NSCopying>

- (instancetype)init NS_UNAVAILABLE;
- (BOOL)isEqualToAddress:(DITAddress *)address;

- (DITAddress *)copy;
- (DITAddress *)copyWithZone:(nullable NSZone *)zone;

@end

NS_ASSUME_NONNULL_END
