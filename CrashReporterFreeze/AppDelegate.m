//
//  AppDelegate.m
//  CrashReporterFreeze
//
//  Created by Konstantin Bender on 10.05.23.
//

#import "AppDelegate.h"

#import <CrashReporter/CrashReporter.h>
#import <Foundation/Foundation.h>

@interface AppDelegate ()

@property (strong) PLCrashReporter *crashReporter;
@property (strong) IBOutlet NSWindow *window;

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
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}


@end
