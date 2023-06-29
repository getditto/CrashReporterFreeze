//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITObserver.h>
#import <Foundation/Foundation.h>

@class DITAuthenticator;
@class DITAuthenticationStatus;

NS_ASSUME_NONNULL_BEGIN

@interface _DITAuthenticationStatusObserver : NSObject <DITObserver>

@property (nonatomic, nullable, weak) DITAuthenticator *authenticator;
@property (nonatomic, copy) void (^block)(DITAuthenticationStatus *status);

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithAuthenticator:(DITAuthenticator *)authenticator
                                block:(void (^)(DITAuthenticationStatus *status))block
    NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
