//
//  Copyright © 2019 DittoLive Incorporated. All rights reserved.
//

// HACK: This style @import disables sorting of imports following it (works in clang-format 14.0.0)
// https://github.com/llvm/llvm-project/issues/38995
@import Foundation;

//! Project version number for DittoObjC.
FOUNDATION_EXPORT double DittoObjCVersionNumber;

//! Project version string for DittoObjC.
FOUNDATION_EXPORT const unsigned char DittoObjCVersionString[];

// General
#import <DittoObjC/DITAuthenticationDelegate.h>
#import <DittoObjC/DITAuthenticationStatus.h>
#import <DittoObjC/DITAuthenticator.h>
#import <DittoObjC/DITDitto.h>
#import <DittoObjC/DITDittoDelegate.h>
#import <DittoObjC/DITErrors.h>
#import <DittoObjC/DITIdentity.h>
#import <DittoObjC/DITLogger.h>
#import <DittoObjC/DITLogLevel.h>
#import <DittoObjC/DITExperimental.h>
#import <DittoObjC/DITObserver.h>

// Store
#import <DittoObjC/DITAttachment.h>
#import <DittoObjC/DITAttachmentFetcher.h>
#import <DittoObjC/DITAttachmentFetchEvent.h>
#import <DittoObjC/DITAttachmentToken.h>
#import <DittoObjC/DITCollection.h>
#import <DittoObjC/DITCollectionsEvent.h>
#import <DittoObjC/DITCounter.h>
#import <DittoObjC/DITDocument.h>
#import <DittoObjC/DITDocumentID.h>
#import <DittoObjC/DITDocumentIDPath.h>
#import <DittoObjC/DITDocumentPath.h>
#import <DittoObjC/DITLiveQuery.h>
#import <DittoObjC/DITLiveQueryEvent.h>
#import <DittoObjC/DITLiveQueryMove.h>
#import <DittoObjC/DITMutableCounter.h>
#import <DittoObjC/DITMutableDocument.h>
#import <DittoObjC/DITMutableDocumentPath.h>
#import <DittoObjC/DITMutableRegister.h>
#import <DittoObjC/DITPendingCollectionsOperation.h>
#import <DittoObjC/DITPendingCursorOperation.h>
#import <DittoObjC/DITPendingIDSpecificOperation.h>
#import <DittoObjC/DITRegister.h>
#import <DittoObjC/DITRGA.h>
#import <DittoObjC/DITScopedWriteTransaction.h>
#import <DittoObjC/DITSignalNext.h>
#import <DittoObjC/DITSingleDocumentLiveQueryEvent.h>
#import <DittoObjC/DITSortDirection.h>
#import <DittoObjC/DITStore.h>
#import <DittoObjC/DITSubscription.h>
#import <DittoObjC/DITUpdateResult.h>
#import <DittoObjC/DITWriteStrategy.h>
#import <DittoObjC/DITWriteTransaction.h>
#import <DittoObjC/DITWriteTransactionPendingCursorOperation.h>
#import <DittoObjC/DITWriteTransactionPendingIDSpecificOperation.h>
#import <DittoObjC/DITWriteTransactionResult.h>

// Transport
#import <DittoObjC/DITPeersObserver.h>
#import <DittoObjC/DITPeersObserverV2.h>
#import <DittoObjC/DITRemotePeer.h>
#import <DittoObjC/DITTransportConfig.h>
#import <DittoObjC/DITMutableTransportConfig.h>
#import <DittoObjC/DITTCPListenConfig.h>
#import <DittoObjC/DITMutableTCPListenConfig.h>
#import <DittoObjC/DITHTTPListenConfig.h>
#import <DittoObjC/DITMutableHTTPListenConfig.h>
#import <DittoObjC/DITPeerToPeer.h>
#import <DittoObjC/DITMutablePeerToPeer.h>
#import <DittoObjC/DITListen.h>
#import <DittoObjC/DITMutableListen.h>
#import <DittoObjC/DITConnect.h>
#import <DittoObjC/DITMutableConnect.h>
#import <DittoObjC/DITBluetoothLEConfig.h>
#import <DittoObjC/DITMutableBluetoothLEConfig.h>
#import <DittoObjC/DITLANConfig.h>
#import <DittoObjC/DITMutableLANConfig.h>
#import <DittoObjC/DITAWDLConfig.h>
#import <DittoObjC/DITMutableAWDLConfig.h>
#import <DittoObjC/DITTransportCondition.h>
#import <DittoObjC/DITTransportDiagnostics.h>
#import <DittoObjC/DITTransportSnapshot.h>
#import <DittoObjC/DITAuthenticationRequest.h>
#import <DittoObjC/DITAuthenticationSuccess.h>
#import <DittoObjC/DITBus.h>
#import <DittoObjC/DITBusDelegate.h>
#import <DittoObjC/DITBusStreamDelegate.h>
#import <DittoObjC/DITBusReliability.h>
#import <DittoObjC/DITBusMessage.h>
#import <DittoObjC/DITBusStream.h>
#import <DittoObjC/DITPeerV2Parser.h>
#import <DittoObjC/DITRemotePeerV2.h>
#import <DittoObjC/DITAddress.h>
#import <DittoObjC/DITConnectionPriority.h>

// Presence
#import <DittoObjC/DITConnection.h>
#import <DittoObjC/DITConnectionType.h>
#import <DittoObjC/DITPeer.h>
#import <DittoObjC/DITPresence.h>
#import <DittoObjC/DITPresenceGraph.h>

// DiskUsage
#import <DittoObjC/DITDiskUsage.h>
#import <DittoObjC/DITDiskUsageItem.h>
#import <DittoObjC/DITDiskUsageObserverHandle.h>
#import <DittoObjC/DITFileSystemType.h>
