//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITMutableConnect;

/**
 Specific servers that Ditto should attempt to connect to.

 TCP servers are specified as "host:port". Websocket URLs take the form "wss://hydra.ditto.live".

 Please refer to the documentation on Ditto's website for configuring cloud or client/server
 scenarios.
 */
@interface DITConnect : NSObject <NSCopying, NSMutableCopying>

+ (instancetype)connect;

@property (nonatomic, readonly) NSSet<NSString *> *tcpServers;
@property (nonatomic, readonly) NSSet<NSString *> *websocketURLs;

- (instancetype)initWithDITConnect:(DITConnect *)connect;
- (instancetype)initWithTcpServers:(NSSet<NSString *> *)tcpServers
                     websocketURLs:(NSSet<NSString *> *)websocketUrls;

@end

// MARK: -

@interface DITConnect (DITTypeCorrections)

- (DITConnect *)copy;
- (DITMutableConnect *)mutableCopy;

@end

NS_ASSUME_NONNULL_END
