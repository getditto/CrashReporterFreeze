//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITMutableAWDLConfig;

@interface DITAWDLConfig : NSObject <NSCopying, NSMutableCopying>

+ (instancetype)awdlConfig;

@property (nonatomic, readonly, getter=isEnabled) BOOL enabled;

- (instancetype)initWithDITAWDLConfig:(DITAWDLConfig *)config;
- (instancetype)initWithEnabled:(BOOL)enabled;

- (BOOL)isEqualToDITAWDLConfig:(DITAWDLConfig *)config;

@end

// MARK: -

@interface DITAWDLConfig (DITTypeCorrections)

- (DITAWDLConfig *)copy;
- (DITMutableAWDLConfig *)mutableCopy;

@end

NS_ASSUME_NONNULL_END
