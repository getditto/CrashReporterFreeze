//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITLANConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableLANConfig : DITLANConfig

@property (nonatomic, readwrite, getter=isEnabled) BOOL enabled;
@property (nonatomic, readwrite, getter=ismDNSEnabled) BOOL mDNSEnabled;
@property (nonatomic, readwrite, getter=isMulticastEnabled) BOOL multicastEnabled;

@end

NS_ASSUME_NONNULL_END
