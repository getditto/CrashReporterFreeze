//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITHTTPListenConfig.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableHTTPListenConfig : DITHTTPListenConfig

@property (nonatomic, readwrite, getter=isEnabled) BOOL enabled;
/**
 IP interface to bind to. [::] by default.
 */
@property (nonatomic, readwrite, copy) NSString *interfaceIp;
/**
 Listening port. 80 by default.
 */
@property (nonatomic, readwrite) uint16_t port;
/**
 An absolute path to a directory of static HTTP content that should be served by this device.

 If nil (default), this feature is disabled.
 */
@property (nonatomic, readwrite, copy, nullable) NSString *staticContentPath;
/**
 If YES (default), peers can connect over websocket to sync with this peer.

 This feature has security implications and should only be used together with documentation on
 Ditto's website.
 */
@property (nonatomic, readwrite) BOOL websocketSync;
/**
 An absolute path to the PEM-formatted private key for HTTPS. Must be set together with
 tlsCertificatePath.

 If nil (default), the server runs as unencrypted HTTP.
 */
@property (nonatomic, readwrite, copy, nullable) NSString *tlsKeyPath;
/**
 An absolute path to the PEM-formatted certificate for HTTPS. Must be set together with tlsKeyPath.

 If nil (default), the server runs as unencrypted HTTP.
 */
@property (nonatomic, readwrite, copy, nullable) NSString *tlsCertificatePath;
/**
 Enable acting as a provider of Ditto identities.
 */
@property (nonatomic, readwrite, getter=isIdentityProvider) BOOL identityProvider;
/**
 PEM-encoded private key for signing tokens and certificates when acting as an identity provider.
 */
@property (nonatomic, readwrite, copy, nullable) NSString *identityProviderSigningKey;
/**
 PEM-encoded public keys for verifying tokens and certificates when acting as an identity provider.
 */
@property (nonatomic, readwrite, copy, nullable) NSArray<NSString *> *identityProviderVerifyingKeys;
/**
 PEM-encoded private key that should be used to issue certificates for clients in peer-to-peer mode.
 */
@property (nonatomic, readwrite, copy, nullable) NSString *caKey;

@end

NS_ASSUME_NONNULL_END
