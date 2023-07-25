# CrashReporterFreeze

This is a demo for a bug report posted on the ``PLCrashReporter`` repo.

---

## Hangs and Unresponsive Behavior in App Crashes (Ditto SDK and Rust 1.65+ on Apple arm64 Devices)

### Description

We are experiencing hangs when hitting a crash in an iOS app, if used together with our [Ditto SDK](https://www.ditto.live/). The core of our SDK is built with **Rust**. The problem surfaces when we build our Core with Rust starting with version >= **1.65** and *only* on **arm64** devices (Mac & iOS).

To demonstrate the issue, we’ve prepared the minimal Mac app: *[CrashReporterFreeze](https://github.com/getditto/CrashReporterFreeze)*. Complete the following steps to reproduce the unresponsive behavior:

### Repro Steps

Trigger a crash within an app by doing the following steps:

1. If not already installed, install [Git LFS](https://git-lfs.com/).
2. Clone [CrashReporterFreeze](https://github.com/getditto/CrashReporterFreeze) on either a “M1” or “M2” Mac.
3. In Xcode, open CrashReporterFreeze.xcodeproj, select target CrashReporterFreeze, build & run the app. Once running, the app appears in the Dock as an icon.
4. Click and drag the app icon to the permanent section in the Dock.
5. In Xcode, stop the app from running.
6. Open the Finder > then go to Applications > Utilities > open the Console app > and then click **Start Streaming**.
7. Type "CrashReporterFreeze" into the search field, and then select the **Process** query item that appears.
8. From the Dock, click to launch the just built CrashReporterFreeze app.
9. Once launched, click **Crash!**. At this time, you may notice the app becoming unresponsive, as indicated by the “beachball of death” and the debug logs being printed within the Console.app. These logs were embedded by us deep within the crash processing functionality of the `PLCrashReporter`.

Although most of the time the crash processing eventually completes, sometimes it seems to hang indefinitely.

If you want to test the exact same version of the Ditto SDK built with different versions of Rust, repeat the previous steps on any of the following commits in the CrashReporterFreeze repo:

    79d8fa2 Add DittoObjC v3.0.9 built with Rust 1.70 | Bad Konstantin Bender (4 weeks ago) (HEAD -> main, origin/main)
    ec72757 Add DittoObjC v3.0.9 built with Rust 1.65 | Bad Konstantin Bender (4 weeks ago)
    4ede7dd Add DittoObjC v3.0.9 built with Rust 1.64 | Good Konstantin Bender (4 weeks ago)

### **Debugging**

While there may be alternative approaches to debugging the issue, the following approach is the method that has proven most effective for us.

In this approach, we combine the use of the Console.app and manually attach the Xcode debugger following the crash by doing the following:

1. In Xcode, build the app by pressing Command + B.
2. From the Dock, launch the CrashReporterFreeze app and then click **Crash!**.
3. Monitor the Console app to observe the unresponsive behavior: The crash processing repeatedly prints the same debug message. 
4. In Xcode:
    1. Attach the debugger by clicking **Debug** > **Attach to Process** > **CrashReporterFreeze**.
    2. Use search to locate the line for "[DEBUG] entry_idx," and then set a breakpoint on it.
    3. Eventually, Xcode should hit that breakpoint.

### **Details**

1. Which SDK version are you using? **Latest commit** on `master` of the PLCrashReporter repo.
2. Which OS version did you experience the issue on? **macOS 13**.
3. Which CocoaPods/Carthage/Xcode version are you using? **Xcode 14.3**.
4. What device version did you see this error on? Were you using an emulator or a physical device? **Apple MacBook Pro 16" M1 Pro, 32 GB RAM, 2 TB SSD.**
5. What language are you using?
    - [ ]  Objective C
    - [ ]  Swift
6. What third party libraries are you using? [Ditto SDK](https://www.ditto.live/).
