//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITL2CAPConnection;

@protocol DITL2CAPConnectionDelegate <NSObject>

- (void)l2capConnectionDidFail:(DITL2CAPConnection *)connection;

@end

NS_ASSUME_NONNULL_END
