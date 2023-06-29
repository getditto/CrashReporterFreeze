//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITTransportDiagnostics.h>

@class DITTransportSnapshot;

NS_ASSUME_NONNULL_BEGIN

@interface DITTransportDiagnostics ()
- (instancetype)initWithSnapshots:(NSArray<DITTransportSnapshot *> *)snapshots;
@end

NS_ASSUME_NONNULL_END
