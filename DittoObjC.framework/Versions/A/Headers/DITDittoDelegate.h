//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITTransportCondition.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITDitto;
@class DITAuthenticationRequest;

/**
 An optional delegate object that can be used to get updates about events occurring that relate to
 the `DITDitto` object that the delegate was tied to.
 */
@protocol DITDittoDelegate <NSObject>
@optional

/**
 Called when the condition of one of the underlying transports that DITDitto uses changes.

 @param condition The new condition of the transport.
 @param source The transport source.
 */
- (void)ditto:(DITDitto *)ditto
    transportConditionChanged:(enum DITTransportCondition)condition
                 forSubsystem:(enum DITConditionSource)source;

- (void)ditto:(DITDitto *)ditto
    identityProviderAuthenticationRequest:(DITAuthenticationRequest *)request;

@end

NS_ASSUME_NONNULL_END
