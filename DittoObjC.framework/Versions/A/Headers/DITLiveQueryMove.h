//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An object that describes how a document's position in a live query's list of matching documents has
 changed since the previous live query event.
 */
@interface DITLiveQueryMove : NSObject

/**
 The index of the document in the list of matching documents from the previous live query event.
 */
@property (nonatomic, readonly) NSInteger from;

/**
 The index of the document in the list of matching documents from the new live query event.
 */
@property (nonatomic, readonly) NSInteger to;

@end

NS_ASSUME_NONNULL_END
