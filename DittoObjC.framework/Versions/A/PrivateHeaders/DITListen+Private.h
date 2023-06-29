//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITListen.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITListen () {
    @protected
    DITTCPListenConfig *_tcp;
    @protected
    DITHTTPListenConfig *_http;
}

- (instancetype)initWithTCP:(DITTCPListenConfig *)tcp
                       HTTP:(DITHTTPListenConfig *)http
                       copy:(BOOL)shouldCopy NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
