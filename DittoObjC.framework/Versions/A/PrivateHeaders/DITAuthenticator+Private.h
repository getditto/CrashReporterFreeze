//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITAuthenticator.h>
#import <DittoObjC/dittoffi.h>
#import <DittoObjC/DITAuthenticator.h>

@class _DITAuthClientWrapper;
@class _DITAuthenticationStatusObserver;
@class _DITWeakWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITAuthenticator () <DITAuthenticationDelegate>

@property (nonatomic, nullable, weak) DITDitto *ditto;
@property (nonatomic, readonly, nullable) _DITAuthClientWrapper *authClientWrapper;
@property (nonatomic, readonly, strong) NSMutableArray<_DITWeakWrapper *> *statusObservers;
@property (nonatomic, readonly, strong) dispatch_queue_t loginQueue;
@property (nonatomic, nullable, readwrite, weak) id<DITAuthenticationDelegate> delegate;

// Ensure that `ditto` gets set before anyone else can use the `DITAuthenticator` instace
- (instancetype)initWithAuthClient:(nullable _DITAuthClientWrapper *)authClient;

- (void)validityUpdatedWithWebValid:(BOOL)webValid x509Valid:(BOOL)x509Valid;
- (void)authenticationExpiring:(uint32_t)timeRemaining;
- (void)updateAndNotify:(BOOL)shouldNotify;
- (void)stopStatusObserver:(_DITAuthenticationStatusObserver *)authenticationStatusObserver;

@end

NS_ASSUME_NONNULL_END
