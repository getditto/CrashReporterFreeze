//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITAuthenticationSuccess.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITAuthenticationRequest : NSObject

@property (nonatomic, nullable, readonly) NSString *appId;
@property (nonatomic, nullable, readonly) NSNumber *siteID;
@property (nonatomic, nullable, readonly) NSString *thirdPartyToken;
@property (nonatomic, nullable, readonly) NSString *tokenSource;
@property (nonatomic, nullable, readonly) NSString *username;
@property (nonatomic, nullable, readonly) NSString *password;

- (void)allow:(DITAuthenticationSuccess *)success;
- (void)deny;

@end

NS_ASSUME_NONNULL_END
