//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITAuthenticationStatus.h>
#import <DittoObjC/DITAuthenticationDelegate.h>

#import <DittoObjC/DITObserver.h>
#import <Foundation/Foundation.h>

@class DITDitto;

NS_ASSUME_NONNULL_BEGIN

/**
 Posted whenever the authentication status for a specific authenticator did
 change. You can use `authenticator` property `status` to query for the new
 authentication status.
 */
extern NSNotificationName const DITAuthenticationStatusDidChangeNotification;

/**
 Provides access to authentication information and methods for logging on to
 Ditto Cloud. Relevant when using an `OnlineWithAuthentication` or an `Online`
 identity.
 */
@interface DITAuthenticator : NSObject

/**
 Returns the current authentication status.
 */
@property (nonatomic, readonly) DITAuthenticationStatus *status;

/**
 Log in to Ditto with a third-party token.

 @param token the authentication token required to log in.
 @param provider the name of the authentication provider.
 @param completion a block that will get called when the login attempt has
 completed.
 */
- (void)loginWithToken:(NSString *)token
              provider:(nullable NSString *)provider
            completion:(void (^)(NSError *__nullable))completion;

/**
 Log in to Ditto with a username and password.

 @param username the username component of the credentials used for log in.
 @param password the password component of the credentials used for log in.
 @param provider the name of the authentication provider.
 @param completion a block that will get called when the login attempt has
 completed.
 */
- (void)loginWithUsername:(NSString *)username
                 password:(NSString *)password
                 provider:(nullable NSString *)provider
               completion:(void (^)(NSError *__nullable))completion;

/**
 Log out of Ditto.

 This will stop sync, shut down all replication sessions, and remove any cached
 authentication credentials. Note that this does not remove any data from the
 store. If you wish to delete data from the store then use
 `logout(cleanupBlock:)` instead.

 */
- (void)logout;

/**
 Log out of Ditto.

 This will stop sync, shut down all replication sessions, and remove any cached
 authentication credentials. Note that this does not remove any data from the
 store. If you wish to delete data from the store then use the optional
 `cleanupBlock` argument to perform any required cleanup.

 @param cleanupBlock an optional action that will be called with the relevant
 `Ditto` instance as the sole argument that allows you to perform any required
 cleanup of the store as part of the logout process.
 */
- (void)logout:(nullable void (^)(DITDitto *))cleanupBlock;

/**
 * Registers a block that will be called whenever authentication `status`
 * changes. Returns a `DITObserver` that needs to be retained as long as
 * you want to receive the updates.
 */
- (id<DITObserver>)observeStatus:(void (^)(DITAuthenticationStatus *))handler;

@end

NS_ASSUME_NONNULL_END
