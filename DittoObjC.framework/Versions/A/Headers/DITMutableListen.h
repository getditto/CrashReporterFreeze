//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITListen.h>

#import <DittoObjC/DITMutableHTTPListenConfig.h>
#import <DittoObjC/DITMutableTCPListenConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableListen : DITListen

@property (nonatomic, readonly, copy) DITMutableTCPListenConfig *tcp;
@property (nonatomic, readonly, copy) DITMutableHTTPListenConfig *http;

- (void)setTcp:(DITTCPListenConfig *)tcp;
- (void)setHttp:(DITHTTPListenConfig *)http;

@end

NS_ASSUME_NONNULL_END
