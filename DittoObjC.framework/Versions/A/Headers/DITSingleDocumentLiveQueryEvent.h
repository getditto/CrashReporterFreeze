//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITDocument;

NS_ASSUME_NONNULL_BEGIN

/**
 Provides information about a live query event relating to a single document live query.
 */
@interface DITSingleDocumentLiveQueryEvent : NSObject

/**
 Whether or not the event is the initial event delivered as part of an `observeLocal` call.
 */
@property (nonatomic, readonly) BOOL isInitial;

/**
 The old representation of the document with the relveant document ID.
 */
@property (nonatomic, readonly, nullable) DITDocument *oldDocument;

/**
 Returns a hash that represents the document.
 */
- (uint64_t)hash:(nullable DITDocument *)document;

/**
 Returns a pattern of words that together create a mnemonic, which represents the document
 */
- (NSString *)hashMnemonic:(nullable DITDocument *)document;

@end

NS_ASSUME_NONNULL_END
