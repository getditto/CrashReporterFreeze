//
//  AppDelegate.m
//  CrashReporterFreeze
//
//  Created by Konstantin Bender on 10.05.23.
//

#import "AppDelegate.h"

#import <DittoObjC/DittoObjC.h>
#import <CrashReporter/CrashReporter.h>
#import <Foundation/Foundation.h>

@interface AppDelegate ()

@property (strong) DITDitto* ditto;
@property (strong) PLCrashReporter *crashReporter;
@property (strong) IBOutlet NSWindow *window;

@end

@interface AppDelegate (SwiftAPI)

- (void)crashInSwiftLand;

@end

@implementation AppDelegate

- (IBAction)crash:(id)sender {
    [self crashInSwiftLand];
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    PLCrashReporterConfig *const config = [[PLCrashReporterConfig alloc] initWithSignalHandlerType:PLCrashReporterSignalHandlerTypeBSD symbolicationStrategy:PLCrashReporterSymbolicationStrategyNone];
    self.crashReporter = [[PLCrashReporter alloc] initWithConfiguration:config];

    if (!self.crashReporter) {
        NSLog(@"❤️ [ERROR] Failed to INIT the crash reporter.");
    }
    NSError *error = nil;

    if (![self.crashReporter enableCrashReporterAndReturnError:&error]) {
        NSLog(@"❤️ [ERROR] Failed to enable crash reporter due to error: %@", error);
    }

    DITIdentity *const identity = [[DITIdentity alloc] initOnlinePlaygroundWithAppID:@"2aaba4c6-c49b-48b6-8452-e99adbb13b77"token:@"a114ff5b-8bf9-4ffc-bcc4-eccd7d80622c"];
    self.ditto = [[DITDitto alloc] initWithIdentity:identity];

    NSLog(@"💚 [DEBUG] Created Ditto: %@", self.ditto);
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}


@end
