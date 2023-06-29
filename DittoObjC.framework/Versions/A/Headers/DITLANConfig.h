//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITMutableLANConfig;

@interface DITLANConfig : NSObject <NSCopying, NSMutableCopying>

+ (instancetype)lanConfig;

@property (nonatomic, readonly, getter=isEnabled) BOOL enabled;
@property (nonatomic, readonly, getter=ismDNSEnabled) BOOL mDNSEnabled;
@property (nonatomic, readonly, getter=isMulticastEnabled) BOOL multicastEnabled;

- (instancetype)initWithDITLANConfig:(DITLANConfig *)config;
- (instancetype)initWithEnabled:(BOOL)enabled
                    mDNSEnabled:(BOOL)mDNSEnabled
               multicastEnabled:(BOOL)multicastEnabled;

- (BOOL)isEqualToDITLANConfig:(DITLANConfig *)config;

@end

// MARK: -

@interface DITLANConfig (DITTypeCorrections)

- (DITLANConfig *)copy;
- (DITMutableLANConfig *)mutableCopy;

@end

NS_ASSUME_NONNULL_END
