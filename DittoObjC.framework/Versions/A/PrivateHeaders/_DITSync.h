//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DITDitto;
@class _DITSyncParameters;

@interface _DITSync : NSObject

@property (nonatomic, readonly, weak, nullable) DITDitto *ditto;
@property (nonatomic, readonly, copy) _DITSyncParameters *parameters;

- (instancetype)initWithDitto:(DITDitto *)ditto;
- (void)updateWithParameters:(_DITSyncParameters *)parameters;

@end

NS_ASSUME_NONNULL_END
