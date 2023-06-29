//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITAddress;

@interface DITBusMessage : NSObject

@property (nonatomic, strong, readonly) DITAddress *sender;
@property (nonatomic, copy, readonly) NSData *data;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
