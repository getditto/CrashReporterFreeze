//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Defines the various strategies available when inserting a document into a
 collection.
 */
typedef NS_CLOSED_ENUM(NSUInteger, DITWriteStrategy) {
    /**
     The existing document will be merged with the document being inserted, if there is a
     pre-existing document.
     */
    DITWriteStrategyMerge = 1,

    /**
     Insert the document only if there is not already a document with the same ID in the
     store. If there is already a document in the store with the same ID then this will be a
     no-op.
     */
    DITWriteStrategyInsertIfAbsent = 2,

    /**
     Insert the document, with its contents treated as default data, only if there is not
     already a document with the same ID in the store. If there is already a document
     in the store with the same ID then this will be a no-op. Use this strategy if you
     want to insert default data for a given document ID, which you want to treat as
     common initial data amongst all peers and that you expect to be mutated or
     overwritten in due course.
     */
    DITWriteStrategyInsertDefaultIfAbsent = 3,
};
