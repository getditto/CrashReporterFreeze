//
// Copyright © 2022 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITMutableRegister.h>
#import <DittoObjC/DITRegister+Private.h>

@class DITMutableDocumentPath;

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableRegister ()

@property (nonatomic, readonly, nullable) DITMutableDocumentPath *documentPath;

- (instancetype)initWithValue:(id)value NS_UNAVAILABLE;
- (instancetype)initWithValue:(id)value
                 documentPath:(DITMutableDocumentPath *)documentPath NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
