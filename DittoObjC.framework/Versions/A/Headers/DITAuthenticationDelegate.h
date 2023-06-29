//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITAuthenticator;

NS_ASSUME_NONNULL_BEGIN

/**
 Provides feedback to the developer about Ditto authentication status.
 */
@protocol DITAuthenticationDelegate <NSObject>

/**
 There is no Ditto authentication token or it has expired. Sync will not work
 until there is a successful login using one of the login methods on
 `DITAuthenticator`.
 */
- (void)authenticationRequired:(DITAuthenticator *)authenticator;

/**
 Warns that the Ditto authentication token is getting old.

 Ditto will attempt to refresh tokens periodically, starting from halfway
 through the token's validity period. This reduces the risk of authentication
 expiring while the user is offline.

 The refresh will happen automatically if Ditto has a suitable refresh token. If
 new credentials are required, such as a third-party token or a
 username/password, then Ditto does not cache that information and you must
 submit it again using one of the `login` methods on `DITAuthenticator`.
 */
- (void)authenticationExpiringSoon:(DITAuthenticator *)authenticator
                  secondsRemaining:(int64_t)secondsRemaining;

@optional

/**
 * Notifies the authentication delegate that the authentication status did
 * change. Use the `authenticator`s property `status` to query for the current
 * authentication status.
 *
 * This method is **optional**.
 */
- (void)authenticationStatusDidChange:(DITAuthenticator *)authenticator;

@end

NS_ASSUME_NONNULL_END
