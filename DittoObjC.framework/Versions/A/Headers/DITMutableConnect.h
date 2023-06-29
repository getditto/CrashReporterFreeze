//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITConnect.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableConnect : DITConnect

@property (nonatomic, readonly) NSMutableSet<NSString *> *tcpServers;
@property (nonatomic, readonly) NSMutableSet<NSString *> *websocketURLs;

- (void)setTcpServers:(NSSet<NSString *> *)tcpServers;
- (void)setWebsocketURLs:(NSSet<NSString *> *)websocketURLs;

@end

NS_ASSUME_NONNULL_END
