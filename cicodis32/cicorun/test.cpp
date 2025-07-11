//
//  apple.cpp
//  cicodis32
//
//  Created by Gabriel Valky on 11/07/2025.
//

//#ifdef __APPLE__
#include <Carbon/Carbon.h>

extern "C" void
ApplicationEventHandler(const AppleEvent* /*inAppleEvent*/, AppleEvent* /*outAppleEventReply*/, long /*refCon*/)
{
    // Do nothing, just prevent the reopen event from launching another instance
    printf("Gabo!!!!!!!!!!!!!!\n");
}
OSErr ReopenAppHandler(const AppleEvent* /*ev*/, AppleEvent* /*reply*/, void* /*refcon*/) {
    // Do nothing on reopen event (prevents second launch)
    return noErr;
}

void SuppressAppleEvents() {
    nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);

    unsetenv("NSDocumentRevisionsDebugMode");
    setenv("NSDocumentRevisionsDebugMode", "NO", 1);
    AEInstallEventHandler(kCoreEventClass,
                          kAEReopenApplication,
                          NewAEEventHandlerUPP(ReopenAppHandler),
                          nullptr,
                          false);
}
//#endif

