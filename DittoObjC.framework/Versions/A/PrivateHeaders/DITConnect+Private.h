//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITConnect.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITConnect () {
    @protected
    NSSet<NSString *> *_tcpServers;
    @protected
    NSSet<NSString *> *_websocketURLs;
}

- (instancetype)initWithTcpServers:(NSSet<NSString *> *)tcpServers
                     websocketURLs:(NSSet<NSString *> *)websocketUrls
                              copy:(BOOL)shouldCopy NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
