//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITHTTPListenConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITHTTPListenConfig () {
    @protected
    BOOL _enabled;
    @protected
    NSString *_interfaceIp;
    @protected
    uint16_t _port;
    @protected
    NSString *_staticContentPath;
    @protected
    BOOL _websocketSync;
    @protected
    NSString *_tlsKeyPath;
    @protected
    NSString *_tlsCertificatePath;
    @protected
    BOOL _identityProvider;
    @protected
    NSString *_identityProviderSigningKey;
    @protected
    NSArray<NSString *> *_identityProviderVerifyingKeys;
    @protected
    NSString *_caKey;
}

- (instancetype)initWithEnabled:(BOOL)enabled
                      interfaceIp:(NSString *)interfaceIp
                             port:(uint16_t)port
                staticContentPath:(nullable NSString *)staticContentPath
                    websocketSync:(BOOL)websocketSync
                       tlsKeyPath:(nullable NSString *)tlsKeyPath
               tlsCertificatePath:(nullable NSString *)tlsCertificatePath
               isIdentityProvider:(BOOL)isIdentityProvider
       identityProviderSigningKey:(nullable NSString *)identityProviderSigningKey
    identityProviderVerifyingKeys:(nullable NSArray<NSString *> *)identityProviderVerifyingKeys
                            caKey:(nullable NSString *)caKey
                             copy:(BOOL)shouldCopy NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
