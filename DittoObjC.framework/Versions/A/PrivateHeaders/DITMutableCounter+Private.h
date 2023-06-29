//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITMutableCounter.h>
#import <DittoObjC/DITCounter+Private.h>

@class DITMutableDocumentPath;

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableCounter ()

@property (nonatomic, readonly, nullable) DITMutableDocumentPath *documentPath;

- (instancetype)initWithValue:(double)value NS_UNAVAILABLE;
- (instancetype)initWithValue:(double)value
                 documentPath:(DITMutableDocumentPath *)documentPath NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
