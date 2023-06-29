//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITRemotePeerV2;

@interface DITPeerV2Parser : NSObject

+ (NSArray<DITRemotePeerV2 *> *__nullable)parseJSON:(NSString *)json;

@end

NS_ASSUME_NONNULL_END
