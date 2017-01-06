#ifndef MAC_LOAD
#define MAC_LOAD

/** mac_load: create GUI apps for OS X in pure C; no ObjC knowledge required.
    Original author: hidefromkgb (hidefromkgb@gmail.com)
    _________________________________________________________________________

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or
    distribute this software, either in source code form or as a compiled
    binary, for any purpose, commercial or non-commercial, and by any means.

    In jurisdictions that recognize copyright laws, the author or authors
    of this software dedicate any and all copyright interest in the
    software to the public domain. We make this dedication for the benefit
    of the public at large and to the detriment of our heirs and
    successors. We intend this dedication to be an overt act of
    relinquishment in perpetuity of all present and future rights to this
    software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
    _________________________________________________________________________
**/

/// [IMPORTANT:] use CoreFoundation classes wherever possible!
/// There is no ARC in pure C, so the bridging will be direct!

#ifdef __cplusplus
extern "C" {
#endif

#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <objc/objc-runtime.h>
#include <stdarg.h>



enum {
    NSBorderlessWindowMask         = (0     ),
    NSTitledWindowMask             = (1 << 0),
    NSClosableWindowMask           = (1 << 1),
    NSMiniaturizableWindowMask     = (1 << 2),
    NSResizableWindowMask          = (1 << 3),
    NSNonactivatingPanelMask       = (1 << 7),
    NSTexturedBackgroundWindowMask = (1 << 8),
};
enum {
    NSSquareStatusItemLength   = -2,
    NSVariableStatusItemLength = -1,
};
enum {
    NSUserDomainMask    = 0x0001,
    NSLocalDomainMask   = 0x0002,
    NSNetworkDomainMask = 0x0004,
    NSSystemDomainMask  = 0x0008,
    NSAllDomainsMask    = 0xFFFF,
};
enum {
    NSApplicationDirectory          =   1,
    NSDemoApplicationDirectory      =   2,
    NSDeveloperApplicationDirectory =   3,
    NSAdminApplicationDirectory     =   4,
    NSLibraryDirectory              =   5,
    NSDeveloperDirectory            =   6,
    NSUserDirectory                 =   7,
    NSDocumentationDirectory        =   8,
    NSDocumentDirectory             =   9,
    NSCoreServiceDirectory          =  10,
    NSAutosavedInformationDirectory =  11,
    NSDesktopDirectory              =  12,
    NSCachesDirectory               =  13,
    NSApplicationSupportDirectory   =  14,
    NSDownloadsDirectory            =  15,
    NSInputMethodsDirectory         =  16,
    NSMoviesDirectory               =  17,
    NSMusicDirectory                =  18,
    NSPicturesDirectory             =  19,
    NSPrinterDescriptionDirectory   =  20,
    NSSharedPublicDirectory         =  21,
    NSPreferencePanesDirectory      =  22,
    NSItemReplacementDirectory      =  99,
    NSAllApplicationsDirectory      = 100,
    NSAllLibrariesDirectory         = 101,
};
enum {
    NSNumberFormatterBehaviorDefault =    0,
    NSNumberFormatterBehavior10_0    = 1000,
    NSNumberFormatterBehavior10_4    = 1040,
};
enum {
    NSTableColumnNoResizing        = (0     ),
    NSTableColumnAutoresizingMask  = (1 << 0),
    NSTableColumnUserResizingMask  = (1 << 1),
};
enum {
    NSApplicationActivationPolicyRegular    = 0,
    NSApplicationActivationPolicyAccessory  = 1,
    NSApplicationActivationPolicyProhibited = 2,
};
enum {
    NSMixedState = -1,
    NSOffState   =  0,
    NSOnState    =  1,
};
enum {
    NSLeftTextAlignment      = 0,
    NSRightTextAlignment     = 1,
    NSCenterTextAlignment    = 2,
    NSJustifiedTextAlignment = 3,
    NSNaturalTextAlignment   = 4
};
enum {
    NSMomentaryLightButton        = 0,
    NSMomentaryPushButton         = 0,
    NSPushOnPushOffButton         = 1,
    NSToggleButton                = 2,
    NSSwitchButton                = 3,
    NSRadioButton                 = 4,
    NSMomentaryChangeButton       = 5,
    NSOnOffButton                 = 6,
    NSMomentaryLight              = 7,
    NSMomentaryPushInButton       = 7,
    NSAcceleratorButton           = 8,
    NSMultiLevelAcceleratorButton = 9,
};
enum {
    NSRoundedBezelStyle           =  1,
    NSRegularSquareBezelStyle     =  2,
    NSSmallIconButtonBezelStyle   =  2,
    NSThickSquareBezelStyle       =  3,
    NSThickerSquareBezelStyle     =  4,
    NSDisclosureBezelStyle        =  5,
    NSShadowlessSquareBezelStyle  =  6,
    NSCircularBezelStyle          =  7,
    NSTexturedSquareBezelStyle    =  8,
    NSHelpButtonBezelStyle        =  9,
    NSSmallSquareBezelStyle       = 10,
    NSTexturedRoundedBezelStyle   = 11,
    NSRoundRectBezelStyle         = 12,
    NSRecessedBezelStyle          = 13,
    NSRoundedDisclosureBezelStyle = 14,
    NSInlineBezelStyle            = 15,
};
enum {
    NSNoImage       = 0,
    NSImageOnly     = 1,
    NSImageLeft     = 2,
    NSImageRight    = 3,
    NSImageBelow    = 4,
    NSImageAbove    = 5,
    NSImageOverlaps = 6,
};
enum {
    NSNormalWindowLevel   =  0,
    NSFloatingWindowLevel =  3,
    NSDockWindowLevel     =  5,
    NSSubmenuWindowLevel  = 10,
    NSMainMenuWindowLevel = 20,
};
enum {
    NSLeftMouseDown      =  1,
    NSLeftMouseUp        =  2,
    NSRightMouseDown     =  3,
    NSRightMouseUp       =  4,
    NSMouseMoved         =  5,
    NSLeftMouseDragged   =  6,
    NSRightMouseDragged  =  7,
    NSMouseEntered       =  8,
    NSMouseExited        =  9,
    NSKeyDown            = 10,
    NSKeyUp              = 11,
    NSFlagsChanged       = 12,
    NSAppKitDefined      = 13,
    NSSystemDefined      = 14,
    NSApplicationDefined = 15,
    NSPeriodic           = 16,
    NSCursorUpdate       = 17,
    NSScrollWheel        = 22,
    NSTabletPoint        = 23,
    NSTabletProximity    = 24,
    NSOtherMouseDown     = 25,
    NSOtherMouseUp       = 26,
    NSOtherMouseDragged  = 27,
};
enum {
    NSOpenGLPFAAllRenderers          =   1,
    NSOpenGLPFATripleBuffer          =   3,
    NSOpenGLPFADoubleBuffer          =   5,
    NSOpenGLPFAStereo                =   6,
    NSOpenGLPFAAuxBuffers            =   7,
    NSOpenGLPFAColorSize             =   8,
    NSOpenGLPFAAlphaSize             =  11,
    NSOpenGLPFADepthSize             =  12,
    NSOpenGLPFAStencilSize           =  13,
    NSOpenGLPFAAccumSize             =  14,
    NSOpenGLPFAMinimumPolicy         =  51,
    NSOpenGLPFAMaximumPolicy         =  52,
    NSOpenGLPFAOffScreen             =  53,
    NSOpenGLPFAFullScreen            =  54,
    NSOpenGLPFASampleBuffers         =  55,
    NSOpenGLPFASamples               =  56,
    NSOpenGLPFAAuxDepthStencil       =  57,
    NSOpenGLPFAColorFloat            =  58,
    NSOpenGLPFAMultisample           =  59,
    NSOpenGLPFASupersample           =  60,
    NSOpenGLPFASampleAlpha           =  61,
    NSOpenGLPFARendererID            =  70,
    NSOpenGLPFASingleRenderer        =  71,
    NSOpenGLPFANoRecovery            =  72,
    NSOpenGLPFAAccelerated           =  73,
    NSOpenGLPFAClosestPolicy         =  74,
    NSOpenGLPFARobust                =  75,
    NSOpenGLPFABackingStore          =  76,
    NSOpenGLPFAMPSafe                =  78,
    NSOpenGLPFAWindow                =  80,
    NSOpenGLPFAMultiScreen           =  81,
    NSOpenGLPFACompliant             =  83,
    NSOpenGLPFAScreenMask            =  84,
    NSOpenGLPFAPixelBuffer           =  90,
    NSOpenGLPFARemotePixelBuffer     =  91,
    NSOpenGLPFAAllowOfflineRenderers =  96,
    NSOpenGLPFAAcceleratedCompute    =  97,
    NSOpenGLPFAOpenGLProfile         =  99,
    NSOpenGLPFAVirtualScreenCount    = 128,
};
enum {
    NSOpenGLCPSwapInterval           = 222,
    NSOpenGLCPSurfaceOrder           = 235,
    NSOpenGLCPSurfaceOpacity         = 236,
    NSOpenGLCPSurfaceBackingSize     = 304,
    NSOpenGLCPReclaimResources       = 308,
    NSOpenGLCPCurrentRendererID      = 309,
    NSOpenGLCPGPUVertexProcessing    = 310,
    NSOpenGLCPGPUFragmentProcessing  = 311,
    NSOpenGLCPHasDrawable            = 314,
    NSOpenGLCPMPSwapsInFlight        = 315,
};



static struct {
    Class uuid;
    char *name;
    long icnt;
} *SubclassedObjCClasses = 0;



/// OSX versions
#define OSX_10_05_PLUS (kCFCoreFoundationVersionNumber >=  476.00)
#define OSX_10_06_PLUS (kCFCoreFoundationVersionNumber >=  550.00)
#define OSX_10_07_PLUS (kCFCoreFoundationVersionNumber >=  635.00)
#define OSX_10_08_PLUS (kCFCoreFoundationVersionNumber >=  744.00)
#define OSX_10_09_PLUS (kCFCoreFoundationVersionNumber >=  855.11)
#define OSX_10_10_PLUS (kCFCoreFoundationVersionNumber >= 1151.16)

/// NSString creation macro
#define UTF8(s) CFStringCreateWithBytes(0, (s)? (uint8_t*)(s) : (uint8_t*)"", strlen((s)? (char*)(s) : (char*)""), kCFStringEncodingUTF8, false)

/// class instance variable management macros
#define GET_IVAR(inst, name, data) object_getInstanceVariable((void*)(inst), name, (void**)(data))
#define SET_IVAR(inst, name, data) object_setInstanceVariable((void*)(inst), name, (void*)(data))



__attribute__((unused))
static char *CopyUTF8(CFStringRef cfsr) {
    CFIndex slen, size;
    uint8_t *retn = 0;

    if (CFStringGetBytes(cfsr, CFRangeMake(0, slen = CFStringGetLength(cfsr)),
                         kCFStringEncodingUTF8, '?', false, 0, 0, &size) > 0)
        CFStringGetBytes(cfsr, CFRangeMake(0, slen), kCFStringEncodingUTF8,
                         '?', false, retn = calloc(1, 1 + size), size, 0);
    return (char*)retn;
}



/// When the official documentation states that there is an NSDictionary to
/// be created with some NS<Whatever> values used as keys, remember that in
/// the CoreFoundation framework their equivalents are named kCT<Whatever>.
/// If there are none in CF, just import them: "extern void *NS<Whatever>".
#define MakeDict(k, ...) __MakeDict(k, ##__VA_ARGS__, nil)
__attribute__((unused))
static CFDictionaryRef __MakeDict(CFStringRef key1, ...) {
    CFDictionaryRef retn = 0;
    CFStringRef iter;
    va_list list;
    long size;

    CFStringRef *keys;
    void **vals;

    size = 0;
    iter = key1;
    va_start(list, key1);
    while (iter) {
        va_arg(list, void*);
        iter = va_arg(list, typeof(iter));
        size++;
    }
    va_end(list);
    if (size) {
        keys = malloc(size * sizeof(*keys));
        vals = malloc(size * sizeof(*vals));
        size = 0;
        iter = key1;
        va_start(list, key1);
        while (iter) {
            keys[size] = iter;
            vals[size++] = va_arg(list, typeof(*vals));
            iter = va_arg(list, typeof(iter));
        }
        va_end(list);
        retn = CFDictionaryCreate(0, (const void**)keys, (const void**)vals,
                                  size, &kCFTypeDictionaryKeyCallBacks,
                                        &kCFTypeDictionaryValueCallBacks);
        free(vals);
        free(keys);
    }
    return retn;
}



#define PutToArr(...) __PutToArr(nil, ##__VA_ARGS__, nil)
__attribute__((unused))
static void **__PutToArr(void *head, ...) {
    va_list list;
    long size;
    void **retn;

    retn = 0;
    va_start(list, head);
    for (size = 0; va_arg(list, typeof(*retn)); size++);
    va_end(list);
    if (size) {
        retn = malloc((size + 1) * sizeof(*retn));
        va_start(list, head);
        for (size = 0; (retn[size] = va_arg(list, typeof(*retn))); size++);
        va_end(list);
    }
    return retn;
}

__attribute__((unused))
static void *NewClass(void *base, char *name, void **flds, void **mths) {
    Class retn;
    long iter;

    for (retn = 0, iter = 0;
         SubclassedObjCClasses && SubclassedObjCClasses[iter].name; iter++)
        if (!strcmp(name, SubclassedObjCClasses[iter].name)) {
            retn = SubclassedObjCClasses[iter].uuid;
            if (base)
                SubclassedObjCClasses[iter].icnt++;
            break;
        }
    if (!retn) {
        retn = objc_allocateClassPair((Class)base, name, 0);
        SubclassedObjCClasses = realloc(SubclassedObjCClasses, (iter + 2)
                                      * sizeof(*SubclassedObjCClasses));
        SubclassedObjCClasses[iter] =
            (typeof(*SubclassedObjCClasses)){retn, strdup(name), 1};
        SubclassedObjCClasses[iter + 1].name = 0;

        iter = -1;
        /// adding fields
        while (flds && flds[++iter])
            class_addIvar(retn, (char*)flds[iter],
                          sizeof(void*), (sizeof(void*) >= 8)? 3 : 2, 0);
        iter = -2;
        /// overloading methods
        while (mths && mths[iter += 2])
            class_addMethod(retn, (SEL)mths[iter], (IMP)mths[iter + 1], 0);

        objc_registerClassPair(retn);
    }
    return (void*)retn;
}



__attribute__((unused))
static void DelClass(Class uuid) {
    long iter, size = 0;

    for (; SubclassedObjCClasses && SubclassedObjCClasses[size].name; size++);
    for (iter = 0; iter < size; iter++)
        if (uuid == SubclassedObjCClasses[iter].uuid) {
            SubclassedObjCClasses[iter].icnt--;
            if (!SubclassedObjCClasses[iter].icnt) {
                objc_disposeClassPair(SubclassedObjCClasses[iter].uuid);
                free(SubclassedObjCClasses[iter].name);
                if (iter < --size) {
                    SubclassedObjCClasses[iter] = SubclassedObjCClasses[size];
                    iter = size;
                }
                SubclassedObjCClasses[iter].name = 0;
            }
            break;
        }
    if (SubclassedObjCClasses && !SubclassedObjCClasses[0].name) {
        free(SubclassedObjCClasses);
        SubclassedObjCClasses = 0;
    }
}



#define L(c, ...) \
L4(c,1,0,,,,,,,,,,,,,##__VA_ARGS__) L4(c,0,1,,,,,,,,,##__VA_ARGS__) \
L4(c,0,2,,,,,        ##__VA_ARGS__) L4(c,0,3,        ##__VA_ARGS__)

#define L4(c, f, n, ...) \
L3(c,f,n##0,,,,__VA_ARGS__) L3(c,0,n##1,,,__VA_ARGS__) \
L3(c,0,n##2,,  __VA_ARGS__) L3(c,0,n##3,  __VA_ARGS__)

#define L3(...) L2(__VA_ARGS__, \
1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,  0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, )

#define L2(c, f, \
n00,n01,n02,n03, n04,n05,n06,n07, n08,n09,n0A,n0B, n0C,n0D,n0E,n0F, \
a00,a01,a02,a03, a04,a05,a06,a07, a08,a09,a0A,a0B, a0C,a0D,a0E,a0F, \
s, ...) L##s(c, f, n00, a00)

#define L1(c, f, n, a) c##f(n, a)
#define L0(c, f, n, a)

#define CONCAT(a, b) a##b
#define SELECT(a, b) CONCAT(b, a)
#define NONNIL(n, a) __

#define P1(n, a) , a _##n
#define P0(n, a) P1(n, a)
#define A1(n, a) P1(n,  )
#define A0(n, a) P0(n,  )

#define F(tnfv, text, retn, name, ...) __attribute__((unused))      \
static SEL name() { static SEL what = 0;                            \
    if (!what) what = sel_registerName(text); return what;          \
} __attribute__((unused))                                           \
static retn __ ##name(void *inst L(P, ##__VA_ARGS__)) {             \
    retn (*func)(void*, SEL, ##__VA_ARGS__) =                       \
         (tnfv < 4)? (tnfv != 1)? (void*)objc_msgSend               \
                                : (void*)objc_msgSend_fpret         \
                                : (void*)objc_msgSend_stret;        \
    return func(inst, name() L(A, ##__VA_ARGS__));                  \
}

#define T(name) __attribute__((unused))                             \
static void *__ ##name() { static void *what = 0;                   \
    if (!what) what = (void*)objc_getClass(#name); return what;     \
} typedef struct name name

T(NSObject);
#define NSObject() \
      __NSObject()
T(NSApplication);
#define NSApplication() \
      __NSApplication()
T(NSAutoreleasePool);
#define NSAutoreleasePool() \
      __NSAutoreleasePool()
T(NSBundle);
#define NSBundle() \
      __NSBundle()
T(NSEvent);
#define NSEvent() \
      __NSEvent()
T(NSFont);
#define NSFont() \
      __NSFont()
T(NSMutableParagraphStyle);
#define NSMutableParagraphStyle() \
      __NSMutableParagraphStyle()
T(NSFileManager);
#define NSFileManager() \
      __NSFileManager()
T(NSNumberFormatter);
#define NSNumberFormatter() \
      __NSNumberFormatter()
T(NSGraphicsContext);
#define NSGraphicsContext() \
      __NSGraphicsContext()
T(NSImage);
#define NSImage() \
      __NSImage()
T(NSMenu);
#define NSMenu() \
      __NSMenu()
T(NSMenuItem);
#define NSMenuItem() \
      __NSMenuItem()
T(NSStatusItem);
#define NSStatusItem() \
      __NSStatusItem()
T(NSStatusBar);
#define NSStatusBar() \
      __NSStatusBar()
T(NSScreen);
#define NSScreen() \
      __NSScreen()
T(NSWindow);
#define NSWindow() \
      __NSWindow()
T(NSTextField);
#define NSTextField() \
      __NSTextField()
T(NSButtonCell);
#define NSButtonCell() \
      __NSButtonCell()
T(NSButton);
#define NSButton() \
      __NSButton()
T(NSProgressIndicator);
#define NSProgressIndicator() \
      __NSProgressIndicator()
T(NSStepper);
#define NSStepper() \
      __NSStepper()
T(NSView);
#define NSView() \
      __NSView()
T(NSCell);
#define NSCell() \
      __NSCell()
T(NSScrollView);
#define NSScrollView() \
      __NSScrollView()
T(NSTableView);
#define NSTableView() \
      __NSTableView()
T(NSTableColumn);
#define NSTableColumn() \
      __NSTableColumn()
T(NSColor);
#define NSColor() \
      __NSColor()
T(NSCursor);
#define NSCursor() \
      __NSCursor()
T(NSPanel);
#define NSPanel() \
      __NSPanel()
T(NSOpenGLView);
#define NSOpenGLView() \
      __NSOpenGLView()
T(NSOpenGLContext);
#define NSOpenGLContext() \
      __NSOpenGLContext()
T(NSOpenGLPixelFormat);
#define NSOpenGLPixelFormat() \
      __NSOpenGLPixelFormat()

#if __LP64__ || TARGET_OS_EMBEDDED || TARGET_OS_IPHONE || TARGET_OS_WIN32 || NS_BUILD_32_LIKE_64
    typedef long NSInteger;
    typedef unsigned long NSUInteger;
#else
    typedef int NSInteger;
    typedef unsigned int NSUInteger;
#endif

static inline void *GetMsgSend(long tnfv) {
    switch (tnfv) {
        case 4:  return objc_msgSend_stret;
        case 1:  return objc_msgSend_fpret;
        default: return objc_msgSend;
    }
}

F(0, "init", void*,
      init);
#define init(...) \
      SELECT(init, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "alloc", void*,
      alloc);
#define alloc(...) \
      SELECT(alloc, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "release", void*,
      release);
#define release(...) \
      SELECT(release, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "retain", void*,
      retain);
#define retain(...) \
      SELECT(retain, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "class", Class,
      class);
#define class(...) \
      SELECT(class, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "cell", NSCell*,
      cell);
#define cell(...) \
      SELECT(cell, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "button", NSButton*,
      button);
#define button(...) \
      SELECT(button, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setAction:", void,
      setAction_,
      SEL);
#define setAction_(...) \
      SELECT(setAction_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setTarget:", void,
      setTarget_,
      void*);
#define setTarget_(...) \
      SELECT(setTarget_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setActivationPolicy:", bool,
      setActivationPolicy_,
      NSInteger);
#define setActivationPolicy_(...) \
      SELECT(setActivationPolicy_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "activateIgnoringOtherApps:", void,
      activateIgnoringOtherApps_,
      bool);
#define activateIgnoringOtherApps_(...) \
      SELECT(activateIgnoringOtherApps_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "sharedApplication", NSApplication*,
      sharedApplication);
#define sharedApplication(...) \
      SELECT(sharedApplication, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "run", void,
      run);
#define run(...) \
      SELECT(run, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "stop:", void,
      stop_,
      void*);
#define stop_(...) \
      SELECT(stop_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "mainBundle", NSBundle*,
      mainBundle);
#define mainBundle(...) \
      SELECT(mainBundle, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "bundlePath", CFStringRef,
      bundlePath);
#define bundlePath(...) \
      SELECT(bundlePath, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "URLsForDirectory:inDomains:", CFArrayRef,
      URLsForDirectory_inDomains_,
      NSInteger, NSInteger);
#define URLsForDirectory_inDomains_(...) \
      SELECT(URLsForDirectory_inDomains_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "separatorItem", NSMenuItem*,
      separatorItem);
#define separatorItem(...) \
      SELECT(separatorItem, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "addItem:", void,
      addItem_,
      NSMenuItem*);
#define addItem_(...) \
      SELECT(addItem_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setAutoenablesItems:", void,
      setAutoenablesItems_,
      bool);
#define setAutoenablesItems_(...) \
      SELECT(setAutoenablesItems_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "imageNamed:", NSImage*,
      imageNamed_,
      CFStringRef);
#define imageNamed_(...) \
      SELECT(imageNamed_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setImage:", void,
      setImage_,
      NSImage*);
#define setImage_(...) \
      SELECT(setImage_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setOnStateImage:", void,
      setOnStateImage_,
      NSImage*);
#define setOnStateImage_(...) \
      SELECT(setOnStateImage_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setSubmenu:", void,
      setSubmenu_,
      NSMenu*);
#define setSubmenu_(...) \
      SELECT(setSubmenu_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "popUpMenuPositioningItem:atLocation:inView:", bool,
      popUpMenuPositioningItem_atLocation_inView_,
      NSMenuItem*, CGPoint, NSView*);
#define popUpMenuPositioningItem_atLocation_inView_(...) \
      SELECT(popUpMenuPositioningItem_atLocation_inView_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "initWithCGImage:size:", NSImage*,
      initWithCGImage_size_,
      CGImageRef, CGPoint);
#define initWithCGImage_size_(...) \
      SELECT(initWithCGImage_size_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "initWithContentRect:styleMask:backing:defer:", NSWindow*,
      initWithContentRect_styleMask_backing_defer_,
      CGRect, NSInteger, NSInteger, bool);
#define initWithContentRect_styleMask_backing_defer_(...) \
      SELECT(initWithContentRect_styleMask_backing_defer_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "initWithTitle:action:keyEquivalent:", NSMenuItem*,
      initWithTitle_action_keyEquivalent_,
      CFStringRef, SEL, CFStringRef);
#define initWithTitle_action_keyEquivalent_(...) \
      SELECT(initWithTitle_action_keyEquivalent_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(4, "contentRectForFrameRect:", CGRect,
      contentRectForFrameRect_,
      CGRect);
#define contentRectForFrameRect_(...) \
      SELECT(contentRectForFrameRect_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(4, "frameRectForContentRect:", CGRect,
      frameRectForContentRect_,
      CGRect);
#define frameRectForContentRect_(...) \
      SELECT(frameRectForContentRect_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(4, "visibleFrame", CGRect,
      visibleFrame);
#define visibleFrame(...) \
      SELECT(visibleFrame, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(4, "frame", CGRect,
      frame);
#define frame(...) \
      SELECT(frame, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setFrame:", void,
      setFrame_,
      CGRect);
#define setFrame_(...) \
      SELECT(setFrame_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setFrame:display:animate:", void,
      setFrame_display_animate_,
      CGRect, bool, bool);
#define setFrame_display_animate_(...) \
      SELECT(setFrame_display_animate_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setInitialFirstResponder:", void,
      setInitialFirstResponder_,
      NSView*);
#define setInitialFirstResponder_(...) \
      SELECT(setInitialFirstResponder_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setMinSize:", void,
      setMinSize_,
      CGSize);
#define setMinSize_(...) \
      SELECT(setMinSize_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setTitle:", void,
      setTitle_,
      CFStringRef);
#define setTitle_(...) \
      SELECT(setTitle_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setStringValue:", void,
      setStringValue_,
      CFStringRef);
#define setStringValue_(...) \
      SELECT(setStringValue_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "windowShouldClose:", bool,
      windowShouldClose_,
      void*);
#define windowShouldClose_(...) \
      SELECT(windowShouldClose_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "windowDidResize:", void,
      windowDidResize_,
      void*);
#define windowDidResize_(...) \
      SELECT(windowDidResize_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "makeKeyWindow", void,
      makeKeyWindow);
#define makeKeyWindow(...) \
      SELECT(makeKeyWindow, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "orderFront:", void,
      orderFront_,
      void*);
#define orderFront_(...) \
      SELECT(orderFront_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "orderOut:", void,
      orderOut_,
      void*);
#define orderOut_(...) \
      SELECT(orderOut_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setNeedsDisplay:", void,
      setNeedsDisplay_,
      bool);
#define setNeedsDisplay_(...) \
      SELECT(setNeedsDisplay_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setDelegate:", void,
      setDelegate_,
      void*);
#define setDelegate_(...) \
      SELECT(setDelegate_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setEnabled:", void,
      setEnabled_,
      bool);
#define setEnabled_(...) \
      SELECT(setEnabled_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setNextKeyView:", void,
      setNextKeyView_,
      NSView*);
#define setNextKeyView_(...) \
      SELECT(setNextKeyView_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setDefaultButtonCell:", void,
      setDefaultButtonCell_,
      NSButtonCell*);
#define setDefaultButtonCell_(...) \
      SELECT(setDefaultButtonCell_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "verticalScroller", NSView*,
      verticalScroller);
#define verticalScroller(...) \
      SELECT(verticalScroller, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setHasVerticalScroller:", void,
      setHasVerticalScroller_,
      bool);
#define setHasVerticalScroller_(...) \
      SELECT(setHasVerticalScroller_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "isEnabled", bool,
      isEnabled);
#define isEnabled(...) \
      SELECT(isEnabled, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "state", NSInteger,
      state);
#define state(...) \
      SELECT(state, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setState:", void,
      setState_,
      NSInteger);
#define setState_(...) \
      SELECT(setState_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setToolTip:", void,
      setToolTip_,
      CFStringRef);
#define setToolTip_(...) \
      SELECT(setToolTip_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setButtonType:", void,
      setButtonType_,
      NSInteger);
#define setButtonType_(...) \
      SELECT(setButtonType_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setBezelStyle:", void,
      setBezelStyle_,
      NSInteger);
#define setBezelStyle_(...) \
      SELECT(setBezelStyle_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setImagePosition:", void,
      setImagePosition_,
      NSInteger);
#define setImagePosition_(...) \
      SELECT(setImagePosition_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setSendsActionOnEndEditing:", void,
      setSendsActionOnEndEditing_,
      bool);
#define setSendsActionOnEndEditing_(...) \
      SELECT(setSendsActionOnEndEditing_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "control:textView:doCommandBySelector:", bool,
      control_textView_doCommandBySelector_,
      void*, NSView*, SEL);
#define control_textView_doCommandBySelector_(...) \
      SELECT(control_textView_doCommandBySelector_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "moveDown:", void,
      moveDown_,
      void*);
#define moveDown_(...) \
      SELECT(moveDown_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "moveUp:", void,
      moveUp_,
      void*);
#define moveUp_(...) \
      SELECT(moveUp_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setEditable:", void,
      setEditable_,
      bool);
#define setEditable_(...) \
      SELECT(setEditable_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setSelectable:", void,
      setSelectable_,
      bool);
#define setSelectable_(...) \
      SELECT(setSelectable_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setBezeled:", void,
      setBezeled_,
      bool);
#define setBezeled_(...) \
      SELECT(setBezeled_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setBordered:", void,
      setBordered_,
      bool);
#define setBordered_(...) \
      SELECT(setBordered_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setDrawsBackground:", void,
      setDrawsBackground_,
      bool);
#define setDrawsBackground_(...) \
      SELECT(setDrawsBackground_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "statusItemWithLength:", NSStatusItem*,
      statusItemWithLength_,
      CGFloat);
#define statusItemWithLength_(...) \
      SELECT(statusItemWithLength_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "removeStatusItem:", void,
      removeStatusItem_,
      NSStatusItem*);
#define removeStatusItem_(...) \
      SELECT(removeStatusItem_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "systemStatusBar", NSStatusBar*,
      systemStatusBar);
#define systemStatusBar(...) \
      SELECT(systemStatusBar, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "mainScreen", NSScreen*,
      mainScreen);
#define mainScreen(...) \
      SELECT(mainScreen, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(1, "thickness", CGFloat,
      thickness);
#define thickness(...) \
      SELECT(thickness, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(2, "cellSize", CGPoint,
      cellSize);
#define cellSize(...) \
      SELECT(cellSize, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "tag", NSInteger,
      tag);
#define tag(...) \
      SELECT(tag, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setTag:", void,
      setTag_,
      NSInteger);
#define setTag_(...) \
      SELECT(setTag_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setHighlightMode:", void,
      setHighlightMode_,
      NSInteger);
#define setHighlightMode_(...) \
      SELECT(setHighlightMode_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setHidden:", void,
      setHidden_,
      bool);
#define setHidden_(...) \
      SELECT(setHidden_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setContentView:", void,
      setContentView_,
      NSView*);
#define setContentView_(...) \
      SELECT(setContentView_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setDocumentView:", void,
      setDocumentView_,
      NSView*);
#define setDocumentView_(...) \
      SELECT(setDocumentView_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "addSubview:", void,
      addSubview_,
      NSView*);
#define addSubview_(...) \
      SELECT(addSubview_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "isFlipped", bool,
      isFlipped);
#define isFlipped(...) \
      SELECT(isFlipped, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "drawRect:", void,
      drawRect_,
      CGRect);
#define drawRect_(...) \
      SELECT(drawRect_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(2, "mouseLocation", CGPoint,
      mouseLocation);
#define mouseLocation(...) \
      SELECT(mouseLocation, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "pressedMouseButtons", NSInteger,
      pressedMouseButtons);
#define pressedMouseButtons(...) \
      SELECT(pressedMouseButtons, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setIgnoresMouseEvents:", void,
      setIgnoresMouseEvents_,
      bool);
#define setIgnoresMouseEvents_(...) \
      SELECT(setIgnoresMouseEvents_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "graphicsPort", CGContextRef,
      graphicsPort);
#define graphicsPort(...) \
      SELECT(graphicsPort, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "currentContext", NSGraphicsContext*,
      currentContext);
#define currentContext(...) \
      SELECT(currentContext, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "defaultManager", NSFileManager*,
      defaultManager);
#define defaultManager(...) \
      SELECT(defaultManager, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "systemFontOfSize:", NSFont*,
      systemFontOfSize_,
      CGFloat);
#define systemFontOfSize_(...) \
      SELECT(systemFontOfSize_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(1, "systemFontSize", CGFloat,
      systemFontSize);
#define systemFontSize(...) \
      SELECT(systemFontSize, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(2, "maximumAdvancement", CGPoint,
      maximumAdvancement);
#define maximumAdvancement(...) \
      SELECT(maximumAdvancement, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setIndeterminate:", void,
      setIndeterminate_,
      bool);
#define setIndeterminate_(...) \
      SELECT(setIndeterminate_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setAlignment:", void,
      setAlignment_,
      NSInteger);
#define setAlignment_(...) \
      SELECT(setAlignment_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "addTableColumn:", void,
      addTableColumn_,
      NSTableColumn*);
#define addTableColumn_(...) \
      SELECT(addTableColumn_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "headerCell", NSCell*,
      headerCell);
#define headerCell(...) \
      SELECT(headerCell, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setWantsLayer:", void,
      setWantsLayer_,
      bool);
#define setWantsLayer_(...) \
      SELECT(setWantsLayer_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "scaleUnitSquareToSize:", void,
      scaleUnitSquareToSize_,
      CGSize);
#define scaleUnitSquareToSize_(...) \
      SELECT(scaleUnitSquareToSize_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "drawInRect:withAttributes:", void,
      drawInRect_withAttributes_,
      CGRect, CFDictionaryRef);
#define drawInRect_withAttributes_(...) \
      SELECT(drawInRect_withAttributes_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "textDidChange:", void,
      textDidChange_,
      void*);
#define textDidChange_(...) \
      SELECT(textDidChange_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "stringValue", CFStringRef,
      stringValue);
#define stringValue(...) \
      SELECT(stringValue, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(1, "doubleValue", double,
      doubleValue);
#define doubleValue(...) \
      SELECT(doubleValue, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setDoubleValue:", void,
      setDoubleValue_,
      double);
#define setDoubleValue_(...) \
      SELECT(setDoubleValue_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setIntegerValue:", void,
      setIntegerValue_,
      NSInteger);
#define setIntegerValue_(...) \
      SELECT(setIntegerValue_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "displayIfNeeded", void,
      displayIfNeeded);
#define displayIfNeeded(...) \
      SELECT(displayIfNeeded, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setMinValue:", void,
      setMinValue_,
      double);
#define setMinValue_(...) \
      SELECT(setMinValue_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setMaxValue:", void,
      setMaxValue_,
      double);
#define setMaxValue_(...) \
      SELECT(setMaxValue_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setValueWraps:", void,
      setValueWraps_,
      bool);
#define setValueWraps_(...) \
      SELECT(setValueWraps_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setFormatter:", void,
      setFormatter_,
      NSNumberFormatter*);
#define setFormatter_(...) \
      SELECT(setFormatter_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setFormatterBehavior:", void,
      setFormatterBehavior_,
      NSInteger);
#define setFormatterBehavior_(...) \
      SELECT(setFormatterBehavior_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setNumberStyle:", void,
      setNumberStyle_,
      NSInteger);
#define setNumberStyle_(...) \
      SELECT(setNumberStyle_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setPartialStringValidationEnabled:", void,
      setPartialStringValidationEnabled_,
      bool);
#define setPartialStringValidationEnabled_(...) \
      SELECT(setPartialStringValidationEnabled_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "isPartialStringValid:newEditingString:errorDescription:", bool,
      isPartialStringValid_newEditingString_errorDescription_,
      CFStringRef, CFStringRef, CFStringRef);
#define isPartialStringValid_newEditingString_errorDescription_(...) \
      SELECT(isPartialStringValid_newEditingString_errorDescription_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "getObjectValue:forString:errorDescription:", bool,
      getObjectValue_forString_errorDescription_,
      void**, CFStringRef, CFStringRef);
#define getObjectValue_forString_errorDescription_(...) \
      SELECT(getObjectValue_forString_errorDescription_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "reloadData", void,
      reloadData);
#define reloadData(...) \
      SELECT(reloadData, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "dataCell", void*,
      dataCell);
#define dataCell(...) \
      SELECT(dataCell, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setDataCell:", void,
      setDataCell_,
      NSCell*);
#define setDataCell_(...) \
      SELECT(setDataCell_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setDataSource:", void,
      setDataSource_,
      void*);
#define setDataSource_(...) \
      SELECT(setDataSource_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setResizingMask:", void,
      setResizingMask_,
      NSInteger);
#define setResizingMask_(...) \
      SELECT(setResizingMask_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "numberOfRowsInTableView:", NSInteger,
      numberOfRowsInTableView_,
      NSTableView*);
#define numberOfRowsInTableView_(...) \
      SELECT(numberOfRowsInTableView_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "tableView:objectValueForTableColumn:row:", void*,
      tableView_objectValueForTableColumn_row_,
      NSTableView*, NSTableColumn*, NSInteger);
#define tableView_objectValueForTableColumn_row_(...) \
      SELECT(tableView_objectValueForTableColumn_row_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "tableView:setObjectValue:forTableColumn:row:", void,
      tableView_setObjectValue_forTableColumn_row_,
      NSTableView*, void*, NSTableColumn*, NSInteger);
#define tableView_setObjectValue_forTableColumn_row_(...) \
      SELECT(tableView_setObjectValue_forTableColumn_row_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "tableView:dataCellForTableColumn:row:", NSCell*,
      tableView_dataCellForTableColumn_row_,
      NSTableView*, NSTableColumn*, NSInteger);
#define tableView_dataCellForTableColumn_row_(...) \
      SELECT(tableView_dataCellForTableColumn_row_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "tableView:viewForTableColumn:row:", NSView*,
      tableView_viewForTableColumn_row_,
      NSTableView*, NSTableColumn*, NSInteger);
#define tableView_viewForTableColumn_row_(...) \
      SELECT(tableView_viewForTableColumn_row_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "push", void,
      push);
#define push(...) \
      SELECT(push, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "pop", void,
      pop);
#define pop(...) \
      SELECT(pop, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "pointingHandCursor", NSCursor*,
      pointingHandCursor);
#define pointingHandCursor(...) \
      SELECT(pointingHandCursor, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "flushBuffer", void,
      flushBuffer);
#define flushBuffer(...) \
      SELECT(flushBuffer, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "openGLContext", NSOpenGLContext*,
      openGLContext);
#define openGLContext(...) \
      SELECT(openGLContext, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "isOpaque", bool,
      isOpaque);
#define isOpaque(...) \
      SELECT(isOpaque, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setOpaque:", void,
      setOpaque_,
      bool);
#define setOpaque_(...) \
      SELECT(setOpaque_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "initWithAttributes:", NSOpenGLPixelFormat*,
      initWithAttributes_,
      int*);
#define initWithAttributes_(...) \
      SELECT(initWithAttributes_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "initWithFrame:pixelFormat:", NSOpenGLView*,
      initWithFrame_pixelFormat_,
      CGRect, NSOpenGLPixelFormat*);
#define initWithFrame_pixelFormat_(...) \
      SELECT(initWithFrame_pixelFormat_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "makeCurrentContext", void,
      makeCurrentContext);
#define makeCurrentContext(...) \
      SELECT(makeCurrentContext, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setValues:forParameter:", void,
      setValues_forParameter_,
      int*, NSInteger);
#define setValues_forParameter_(...) \
      SELECT(setValues_forParameter_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setLevel:", void,
      setLevel_,
      NSInteger);
#define setLevel_(...) \
      SELECT(setLevel_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setHasShadow:", void,
      setHasShadow_,
      bool);
#define setHasShadow_(...) \
      SELECT(setHasShadow_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "clearColor", NSColor*,
      clearColor);
#define clearColor(...) \
      SELECT(clearColor, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "setBackgroundColor:", void,
      setBackgroundColor_,
      NSColor*);
#define setBackgroundColor_(...) \
      SELECT(setBackgroundColor_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "postEvent:atStart:", void,
      postEvent_atStart_,
      NSEvent*, bool);
#define postEvent_atStart_(...) \
      SELECT(postEvent_atStart_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)
F(0, "otherEventWithType:location:modifierFlags:timestamp:windowNumber:context:subtype:data1:data2:", NSEvent*,
      otherEventWithType_location_modifierFlags_timestamp_windowNumber_context_subtype_data1_data2_,
      NSInteger, CGPoint, NSInteger, CGFloat, NSInteger, NSGraphicsContext*, short, NSInteger, NSInteger);
#define otherEventWithType_location_modifierFlags_timestamp_windowNumber_context_subtype_data1_data2_(...) \
      SELECT(otherEventWithType_location_modifierFlags_timestamp_windowNumber_context_subtype_data1_data2_, \
      L3(NONNIL,, ,,,, ,,,, ,,,, ,,,, ##__VA_ARGS__))(__VA_ARGS__)

/// [TODO:] implement this:
/**
F(0, NSEvent*,
     otherEventWithType, NSInteger, location, CGPoint,
     modifierFlags, NSInteger, timestamp, CGFloat,
     windowNumber, NSInteger, context, NSGraphicsContext*,
     subtype, short, data1, NSInteger, data2, NSInteger);
 **/

#undef L
#undef L4
//#undef L3
//#undef L2
//#undef L1
//#undef L0
#undef P1
#undef P0
#undef A1
#undef A0
#undef F
#undef T

extern void NSBeep();
extern void CGSSetConnectionProperty(int, int, CFStringRef, CFBooleanRef);
extern int _CGSDefaultConnection();

#ifdef __cplusplus
}
#endif

#endif /** MAC_LOAD **/
