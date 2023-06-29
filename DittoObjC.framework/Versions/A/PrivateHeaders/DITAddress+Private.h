//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITAddress.h>

@interface DITAddress ()

@property (nonatomic) uint64_t siteID;
@property (nonatomic, readonly) NSData *pubkey;

- (instancetype)initWithDictionaryRepresentation:(NSDictionary *)dictionaryRepresentation;
- (instancetype)initWithSiteID:(uint64_t)address pubkey:(NSData *)pubkey NS_DESIGNATED_INITIALIZER;

@end
