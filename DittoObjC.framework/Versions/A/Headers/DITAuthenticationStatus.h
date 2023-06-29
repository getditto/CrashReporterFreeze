//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** Provides info about the authentication status. */
@interface DITAuthenticationStatus : NSObject

/** Returns `YES` if authenticated, otherwise returns `NO`. */
@property (nonatomic, readonly, getter=isAuthenticated) BOOL authenticated;

/**
 If authenticated, returns the user ID if one was provided by the
 authentication service. Otherwise returns `nil`.
 */
@property (nonatomic, readonly, nullable, copy) NSString *userID;

/** Convenience initializer, same as `[... initAuthenticated:NO userID:nil]`. */
- (instancetype)init;

/** Initializes an authentication status object with the given parameters. */
- (instancetype)initAuthenticated:(BOOL)isAuthenticated
                           userID:(nullable NSString *)userID NS_DESIGNATED_INITIALIZER;

/**
 Returns `YES` if passed object is an instance of DITAuthenticationStatus
 and equal to the receiver. Otherwise returns `NO`.
 */
- (BOOL)isEqual:(nullable id)object;

/**
 Returns `YES` if passed `authenticationStatus` is equal to the receiver.
 Otherwise returns `NO`. This is a faster variant of `isEqual:`, use this if
 you know for sure `authenticationStatus` to be a kind of
 `DITAuthenticationStatus`.
 */
- (BOOL)isEqualToAuthenticationStatus:(DITAuthenticationStatus *)authenticationStatus;

/** Returns the hash for the receiver. */
- (NSUInteger)hash;

/** Returns a string representation of the receiver. */
- (NSString *)description;

@end

NS_ASSUME_NONNULL_END
