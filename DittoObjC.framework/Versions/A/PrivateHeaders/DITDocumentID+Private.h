//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDocumentID.h>

#import <DittoObjC/dittoffi.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITDocumentID ()

@property (nonatomic, readonly) NSData *idData;
@property (nonatomic, readwrite) BOOL valueInitialized;
@property (nonatomic, readonly, strong, nullable) id decodedValue;

- (instancetype)initWithCBOR:(slice_boxed_uint8_t)idSliceBoxed;
- (instancetype)initFromDocumentHandle:(CDocument_t const *)docHandle;
- (instancetype)initWithData:(NSData *)data;

- (NSString *)formattedForQueryString:(StringPrimitiveFormat_t)stringPrimitiveFormat
    NS_SWIFT_NAME(formattedForQueryString(_:));
;

@end

NSString *ObjectFormattedForQueryString(id object);

NS_ASSUME_NONNULL_END
