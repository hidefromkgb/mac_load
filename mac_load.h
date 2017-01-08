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
    NSNaturalTextAlignment   = 4,
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
    NSUpArrowFunctionKey      = 0xF700,
    NSDownArrowFunctionKey    = 0xF701,
    NSLeftArrowFunctionKey    = 0xF702,
    NSRightArrowFunctionKey   = 0xF703,
    NSF1FunctionKey           = 0xF704,
    NSF2FunctionKey           = 0xF705,
    NSF3FunctionKey           = 0xF706,
    NSF4FunctionKey           = 0xF707,
    NSF5FunctionKey           = 0xF708,
    NSF6FunctionKey           = 0xF709,
    NSF7FunctionKey           = 0xF70A,
    NSF8FunctionKey           = 0xF70B,
    NSF9FunctionKey           = 0xF70C,
    NSF10FunctionKey          = 0xF70D,
    NSF11FunctionKey          = 0xF70E,
    NSF12FunctionKey          = 0xF70F,
    NSF13FunctionKey          = 0xF710,
    NSF14FunctionKey          = 0xF711,
    NSF15FunctionKey          = 0xF712,
    NSF16FunctionKey          = 0xF713,
    NSF17FunctionKey          = 0xF714,
    NSF18FunctionKey          = 0xF715,
    NSF19FunctionKey          = 0xF716,
    NSF20FunctionKey          = 0xF717,
    NSF21FunctionKey          = 0xF718,
    NSF22FunctionKey          = 0xF719,
    NSF23FunctionKey          = 0xF71A,
    NSF24FunctionKey          = 0xF71B,
    NSF25FunctionKey          = 0xF71C,
    NSF26FunctionKey          = 0xF71D,
    NSF27FunctionKey          = 0xF71E,
    NSF28FunctionKey          = 0xF71F,
    NSF29FunctionKey          = 0xF720,
    NSF30FunctionKey          = 0xF721,
    NSF31FunctionKey          = 0xF722,
    NSF32FunctionKey          = 0xF723,
    NSF33FunctionKey          = 0xF724,
    NSF34FunctionKey          = 0xF725,
    NSF35FunctionKey          = 0xF726,
    NSInsertFunctionKey       = 0xF727,
    NSDeleteFunctionKey       = 0xF728,
    NSHomeFunctionKey         = 0xF729,
    NSBeginFunctionKey        = 0xF72A,
    NSEndFunctionKey          = 0xF72B,
    NSPageUpFunctionKey       = 0xF72C,
    NSPageDownFunctionKey     = 0xF72D,
    NSPrintScreenFunctionKey  = 0xF72E,
    NSScrollLockFunctionKey   = 0xF72F,
    NSPauseFunctionKey        = 0xF730,
    NSSysReqFunctionKey       = 0xF731,
    NSBreakFunctionKey        = 0xF732,
    NSResetFunctionKey        = 0xF733,
    NSStopFunctionKey         = 0xF734,
    NSMenuFunctionKey         = 0xF735,
    NSUserFunctionKey         = 0xF736,
    NSSystemFunctionKey       = 0xF737,
    NSPrintFunctionKey        = 0xF738,
    NSClearLineFunctionKey    = 0xF739,
    NSClearDisplayFunctionKey = 0xF73A,
    NSInsertLineFunctionKey   = 0xF73B,
    NSDeleteLineFunctionKey   = 0xF73C,
    NSInsertCharFunctionKey   = 0xF73D,
    NSDeleteCharFunctionKey   = 0xF73E,
    NSPrevFunctionKey         = 0xF73F,
    NSNextFunctionKey         = 0xF740,
    NSSelectFunctionKey       = 0xF741,
    NSExecuteFunctionKey      = 0xF742,
    NSUndoFunctionKey         = 0xF743,
    NSRedoFunctionKey         = 0xF744,
    NSFindFunctionKey         = 0xF745,
    NSHelpFunctionKey         = 0xF746,
    NSModeSwitchFunctionKey   = 0xF747,
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
    long  icnt;
} *_MAC_Subclasses = 0;



/// OSX versions
#define MAC_10_05_PLUS (kCFCoreFoundationVersionNumber >=  476.00)
#define MAC_10_06_PLUS (kCFCoreFoundationVersionNumber >=  550.00)
#define MAC_10_07_PLUS (kCFCoreFoundationVersionNumber >=  635.00)
#define MAC_10_08_PLUS (kCFCoreFoundationVersionNumber >=  744.00)
#define MAC_10_09_PLUS (kCFCoreFoundationVersionNumber >=  855.11)
#define MAC_10_10_PLUS (kCFCoreFoundationVersionNumber >= 1151.16)

/// NSString creation macro
#define MAC_UTF8(s) CFStringCreateWithBytes(0, (s)? (uint8_t*)(s) : (uint8_t*)"", strlen((s)? (char*)(s) : (char*)""), kCFStringEncodingUTF8, false)

/// class instance variable management macros
#define MAC_GET_IVAR(inst, name, data) object_getInstanceVariable((void*)(inst), name, (void**)(data))
#define MAC_SET_IVAR(inst, name, data) object_setInstanceVariable((void*)(inst), name, (void*)(data))



__attribute__((unused))
static char *MAC_CopyUTF8(CFStringRef cfsr) {
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
#define MAC_MakeDict(k, ...) _MAC_MakeDict(k, ##__VA_ARGS__, nil)
__attribute__((unused))
static CFDictionaryRef _MAC_MakeDict(CFStringRef key1, ...) {
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
        iter = va_arg(list, CFStringRef);
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
            vals[size++] = va_arg(list, void*);
            iter = va_arg(list, CFStringRef);
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
#define MAC_FreeDict(d) CFRelease(d)



__attribute__((unused))
static CFRunLoopTimerRef MAC_MakeTimer(unsigned time, void *func, void *data) {
    CFRunLoopTimerContext ctxt = {0, data};
    CFRunLoopTimerRef retn =
        CFRunLoopTimerCreate(0, CFAbsoluteTimeGetCurrent(),
                             0.001 * time, 0, 0, func, &ctxt);

    CFRunLoopAddTimer(CFRunLoopGetCurrent(), retn, kCFRunLoopCommonModes);
    return retn;
}
#define MAC_FreeTimer(t) CFRunLoopTimerInvalidate(t)



__attribute__((unused))
static Class MAC_MakeClass(char *name, Class base, void **flds, void **mths) {
    Class retn = 0;
    long iter = 0;

    for (; _MAC_Subclasses && _MAC_Subclasses[iter].name; iter++)
        if (!strcmp(name, _MAC_Subclasses[iter].name)) {
            retn = _MAC_Subclasses[iter].uuid;
            if (base)
                _MAC_Subclasses[iter].icnt++;
            break;
        }
    if (!retn) {
        retn = objc_allocateClassPair(base, name, 0);
        _MAC_Subclasses = realloc(_MAC_Subclasses,
                                 (iter + 2) * sizeof(*_MAC_Subclasses));
        _MAC_Subclasses[iter] =
            (typeof(*_MAC_Subclasses)){retn, strdup(name), 1};
        _MAC_Subclasses[iter + 1].name = 0;

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
    return retn;
}
#define MAC_LoadClass(n) MAC_MakeClass(n, (Class)0, (void**)0, (void**)0)
#define MAC_TempArray(...) (void*[]){__VA_ARGS__, 0}



__attribute__((unused))
static void MAC_FreeClass(Class uuid) {
    long iter, size = 0;

    for (; _MAC_Subclasses && _MAC_Subclasses[size].name; size++);
    for (iter = 0; iter < size; iter++)
        if (uuid == _MAC_Subclasses[iter].uuid) {
            _MAC_Subclasses[iter].icnt--;
            if (!_MAC_Subclasses[iter].icnt) {
                objc_disposeClassPair(_MAC_Subclasses[iter].uuid);
                free(_MAC_Subclasses[iter].name);
                if (iter < --size) {
                    _MAC_Subclasses[iter] = _MAC_Subclasses[size];
                    iter = size;
                }
                _MAC_Subclasses[iter].name = 0;
            }
            break;
        }
    if (_MAC_Subclasses && !_MAC_Subclasses[0].name) {
        free(_MAC_Subclasses);
        _MAC_Subclasses = 0;
    }
}



#define _MAC_L(c, ...) \
_MAC_L4(c,1,0,,,,,,,,,,,,,##__VA_ARGS__) _MAC_L4(c,0,1,,,,,,,,,##__VA_ARGS__) \
_MAC_L4(c,0,2,,,,,        ##__VA_ARGS__) _MAC_L4(c,0,3,        ##__VA_ARGS__)

#define _MAC_L4(c, f, n, ...) \
_MAC_L3(c,f,n##0,,,,__VA_ARGS__) _MAC_L3(c,0,n##1,,,__VA_ARGS__) \
_MAC_L3(c,0,n##2,,  __VA_ARGS__) _MAC_L3(c,0,n##3,  __VA_ARGS__)

#define _MAC_L3(...) _MAC_L2(__VA_ARGS__, \
1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,  0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, )

#define _MAC_L2(c, f, \
n00,n01,n02,n03, n04,n05,n06,n07, n08,n09,n0A,n0B, n0C,n0D,n0E,n0F, \
a00,a01,a02,a03, a04,a05,a06,a07, a08,a09,a0A,a0B, a0C,a0D,a0E,a0F, \
s, ...) _MAC_L##s(c, f, n00, a00)

#define _MAC_L1(c, f, n, a) c##f(n, a)
#define _MAC_L0(c, f, n, a)

#define _MAC_C(a, b) __ ##a ##b
#define _MAC_S(a, b) _MAC_C(a, b)
#define _MAC_N(n, a) _
#define _MAC_P(n, ...) _MAC_S(_MAC_L3(_MAC_N,, ,,,, ,,,, ,,,, ,,,, \
                                      ##__VA_ARGS__), n)(__VA_ARGS__)

#define _MAC_P1(n, a) , a _##n
#define _MAC_P0(n, a) _MAC_P1(n, a)
#define _MAC_A1(n, a) _MAC_P1(n,  )
#define _MAC_A0(n, a) _MAC_P0(n,  )

#define _MAC_F(tnfv, text, retn, name, ...) __attribute__((unused)) \
static SEL __ ##name() { static SEL what = 0;                       \
    if (!what) what = sel_registerName(text); return what;          \
} __attribute__((unused))                                           \
static retn ___ ##name(void *inst _MAC_L(_MAC_P, ##__VA_ARGS__)) {  \
    retn (*func)(void*, SEL, ##__VA_ARGS__) =                       \
         (tnfv < 4)? (tnfv != 1)? (void*)objc_msgSend               \
                                : (void*)objc_msgSend_fpret         \
                                : (void*)objc_msgSend_stret;        \
    return func(inst, __ ##name() _MAC_L(_MAC_A, ##__VA_ARGS__));   \
}

#define _MAC_T(name) __attribute__((unused))                        \
static Class __ ##name() { static Class what = 0;                   \
    if (!what) what = objc_getClass(#name); return what;            \
} typedef struct name name

 _MAC_T(NSObject);
#define NSObject() \
      __NSObject()

 _MAC_T(NSApplication);
#define NSApplication() \
      __NSApplication()

 _MAC_T(NSAutoreleasePool);
#define NSAutoreleasePool() \
      __NSAutoreleasePool()

 _MAC_T(NSBundle);
#define NSBundle() \
      __NSBundle()

 _MAC_T(NSEvent);
#define NSEvent() \
      __NSEvent()

 _MAC_T(NSFont);
#define NSFont() \
      __NSFont()

 _MAC_T(NSMutableParagraphStyle);
#define NSMutableParagraphStyle() \
      __NSMutableParagraphStyle()

 _MAC_T(NSFileManager);
#define NSFileManager() \
      __NSFileManager()

 _MAC_T(NSNumberFormatter);
#define NSNumberFormatter() \
      __NSNumberFormatter()

 _MAC_T(NSGraphicsContext);
#define NSGraphicsContext() \
      __NSGraphicsContext()

 _MAC_T(NSImage);
#define NSImage() \
      __NSImage()

 _MAC_T(NSMenu);
#define NSMenu() \
      __NSMenu()

 _MAC_T(NSMenuItem);
#define NSMenuItem() \
      __NSMenuItem()

 _MAC_T(NSStatusItem);
#define NSStatusItem() \
      __NSStatusItem()

 _MAC_T(NSStatusBar);
#define NSStatusBar() \
      __NSStatusBar()

 _MAC_T(NSScreen);
#define NSScreen() \
      __NSScreen()

 _MAC_T(NSWindow);
#define NSWindow() \
      __NSWindow()

 _MAC_T(NSTextField);
#define NSTextField() \
      __NSTextField()

 _MAC_T(NSButtonCell);
#define NSButtonCell() \
      __NSButtonCell()

 _MAC_T(NSButton);
#define NSButton() \
      __NSButton()

 _MAC_T(NSProgressIndicator);
#define NSProgressIndicator() \
      __NSProgressIndicator()

 _MAC_T(NSStepper);
#define NSStepper() \
      __NSStepper()

 _MAC_T(NSView);
#define NSView() \
      __NSView()

 _MAC_T(NSCell);
#define NSCell() \
      __NSCell()

 _MAC_T(NSScrollView);
#define NSScrollView() \
      __NSScrollView()

 _MAC_T(NSTableView);
#define NSTableView() \
      __NSTableView()

 _MAC_T(NSTableColumn);
#define NSTableColumn() \
      __NSTableColumn()

 _MAC_T(NSColor);
#define NSColor() \
      __NSColor()

 _MAC_T(NSCursor);
#define NSCursor() \
      __NSCursor()

 _MAC_T(NSPanel);
#define NSPanel() \
      __NSPanel()

 _MAC_T(NSOpenGLView);
#define NSOpenGLView() \
      __NSOpenGLView()

 _MAC_T(NSOpenGLContext);
#define NSOpenGLContext() \
      __NSOpenGLContext()

 _MAC_T(NSOpenGLPixelFormat);
#define NSOpenGLPixelFormat() \
      __NSOpenGLPixelFormat()

#if __LP64__ || TARGET_OS_EMBEDDED || TARGET_OS_IPHONE || TARGET_OS_WIN32 || NS_BUILD_32_LIKE_64
    typedef long NSInteger;
    typedef unsigned long NSUInteger;
#else
    typedef int NSInteger;
    typedef unsigned int NSUInteger;
#endif

_MAC_F(0, "init", void*,
           init);
#define    init(...) \
    _MAC_P(init, ##__VA_ARGS__)

_MAC_F(0, "alloc", void*,
           alloc);
#define    alloc(...) \
    _MAC_P(alloc, ##__VA_ARGS__)

_MAC_F(0, "release", void*,
           release);
#define    release(...) \
    _MAC_P(release, ##__VA_ARGS__)

_MAC_F(0, "retain", void*,
           retain);
#define    retain(...) \
    _MAC_P(retain, ##__VA_ARGS__)

_MAC_F(0, "class", Class,
           class);
#define    class(...) \
    _MAC_P(class, ##__VA_ARGS__)

_MAC_F(0, "cell", NSCell*,
           cell);
#define    cell(...) \
    _MAC_P(cell, ##__VA_ARGS__)

_MAC_F(0, "button", NSButton*,
           button);
#define    button(...) \
    _MAC_P(button, ##__VA_ARGS__)

_MAC_F(0, "setAction:", void,
           setAction_,
           SEL);
#define    setAction_(...) \
    _MAC_P(setAction_, ##__VA_ARGS__)

_MAC_F(0, "setTarget:", void,
           setTarget_,
           void*);
#define    setTarget_(...) \
    _MAC_P(setTarget_, ##__VA_ARGS__)

_MAC_F(0, "setActivationPolicy:", bool,
           setActivationPolicy_,
           NSInteger);
#define    setActivationPolicy_(...) \
    _MAC_P(setActivationPolicy_, ##__VA_ARGS__)

_MAC_F(0, "activateIgnoringOtherApps:", void,
           activateIgnoringOtherApps_,
           bool);
#define    activateIgnoringOtherApps_(...) \
    _MAC_P(activateIgnoringOtherApps_, ##__VA_ARGS__)

_MAC_F(0, "sharedApplication", NSApplication*,
           sharedApplication);
#define    sharedApplication(...) \
    _MAC_P(sharedApplication, ##__VA_ARGS__)

_MAC_F(0, "run", void,
           run);
#define    run(...) \
    _MAC_P(run, ##__VA_ARGS__)

_MAC_F(0, "stop:", void,
           stop_,
           void*);
#define    stop_(...) \
    _MAC_P(stop_, ##__VA_ARGS__)

_MAC_F(0, "mainBundle", NSBundle*,
           mainBundle);
#define    mainBundle(...) \
    _MAC_P(mainBundle, ##__VA_ARGS__)

_MAC_F(0, "bundlePath", CFStringRef,
           bundlePath);
#define    bundlePath(...) \
    _MAC_P(bundlePath, ##__VA_ARGS__)

_MAC_F(0, "URLsForDirectory:inDomains:", CFArrayRef,
           URLsForDirectory_inDomains_,
           NSInteger, NSInteger);
#define    URLsForDirectory_inDomains_(...) \
    _MAC_P(URLsForDirectory_inDomains_, ##__VA_ARGS__)

_MAC_F(0, "separatorItem", NSMenuItem*,
           separatorItem);
#define    separatorItem(...) \
    _MAC_P(separatorItem, ##__VA_ARGS__)

_MAC_F(0, "addItem:", void,
           addItem_,
           NSMenuItem*);
#define    addItem_(...) \
    _MAC_P(addItem_, ##__VA_ARGS__)

_MAC_F(0, "setAutoenablesItems:", void,
           setAutoenablesItems_,
           bool);
#define    setAutoenablesItems_(...) \
    _MAC_P(setAutoenablesItems_, ##__VA_ARGS__)

_MAC_F(0, "imageNamed:", NSImage*,
           imageNamed_,
           CFStringRef);
#define    imageNamed_(...) \
    _MAC_P(imageNamed_, ##__VA_ARGS__)

_MAC_F(0, "setImage:", void,
           setImage_,
           NSImage*);
#define    setImage_(...) \
    _MAC_P(setImage_, ##__VA_ARGS__)

_MAC_F(0, "setOnStateImage:", void,
           setOnStateImage_,
           NSImage*);
#define    setOnStateImage_(...) \
    _MAC_P(setOnStateImage_, ##__VA_ARGS__)

_MAC_F(0, "setSubmenu:", void,
           setSubmenu_,
           NSMenu*);
#define    setSubmenu_(...) \
    _MAC_P(setSubmenu_, ##__VA_ARGS__)

_MAC_F(0, "popUpMenuPositioningItem:atLocation:inView:", bool,
           popUpMenuPositioningItem_atLocation_inView_,
           NSMenuItem*, CGPoint, NSView*);
#define    popUpMenuPositioningItem_atLocation_inView_(...) \
    _MAC_P(popUpMenuPositioningItem_atLocation_inView_, ##__VA_ARGS__)

_MAC_F(0, "initWithCGImage:size:", NSImage*,
           initWithCGImage_size_,
           CGImageRef, CGPoint);
#define    initWithCGImage_size_(...) \
    _MAC_P(initWithCGImage_size_, ##__VA_ARGS__)

_MAC_F(0, "initWithContentRect:styleMask:backing:defer:", NSWindow*,
           initWithContentRect_styleMask_backing_defer_,
           CGRect, NSInteger, NSInteger, bool);
#define    initWithContentRect_styleMask_backing_defer_(...) \
    _MAC_P(initWithContentRect_styleMask_backing_defer_, ##__VA_ARGS__)

_MAC_F(0, "initWithTitle:action:keyEquivalent:", NSMenuItem*,
           initWithTitle_action_keyEquivalent_,
           CFStringRef, SEL, CFStringRef);
#define    initWithTitle_action_keyEquivalent_(...) \
    _MAC_P(initWithTitle_action_keyEquivalent_, ##__VA_ARGS__)

_MAC_F(4, "contentRectForFrameRect:", CGRect,
           contentRectForFrameRect_,
           CGRect);
#define    contentRectForFrameRect_(...) \
    _MAC_P(contentRectForFrameRect_, ##__VA_ARGS__)

_MAC_F(4, "frameRectForContentRect:", CGRect,
           frameRectForContentRect_,
           CGRect);
#define    frameRectForContentRect_(...) \
    _MAC_P(frameRectForContentRect_, ##__VA_ARGS__)

_MAC_F(4, "visibleFrame", CGRect,
           visibleFrame);
#define    visibleFrame(...) \
    _MAC_P(visibleFrame, ##__VA_ARGS__)

_MAC_F(4, "frame", CGRect,
           frame);
#define    frame(...) \
    _MAC_P(frame, ##__VA_ARGS__)

_MAC_F(0, "setFrame:", void,
           setFrame_,
           CGRect);
#define    setFrame_(...) \
    _MAC_P(setFrame_, ##__VA_ARGS__)

_MAC_F(0, "setFrame:display:animate:", void,
           setFrame_display_animate_,
           CGRect, bool, bool);
#define    setFrame_display_animate_(...) \
    _MAC_P(setFrame_display_animate_, ##__VA_ARGS__)

_MAC_F(0, "characters", CFStringRef,
           characters);
#define    characters(...) \
    _MAC_P(characters, ##__VA_ARGS__)

_MAC_F(0, "charactersIgnoringModifiers", CFStringRef,
           charactersIgnoringModifiers);
#define    charactersIgnoringModifiers(...) \
    _MAC_P(charactersIgnoringModifiers, ##__VA_ARGS__)

_MAC_F(0, "acceptsFirstResponder", bool,
           acceptsFirstResponder);
#define    acceptsFirstResponder(...) \
    _MAC_P(acceptsFirstResponder, ##__VA_ARGS__)

_MAC_F(0, "setInitialFirstResponder:", void,
           setInitialFirstResponder_,
           NSView*);
#define    setInitialFirstResponder_(...) \
    _MAC_P(setInitialFirstResponder_, ##__VA_ARGS__)

_MAC_F(0, "setMinSize:", void,
           setMinSize_,
           CGSize);
#define    setMinSize_(...) \
    _MAC_P(setMinSize_, ##__VA_ARGS__)

_MAC_F(0, "setTitle:", void,
           setTitle_,
           CFStringRef);
#define    setTitle_(...) \
    _MAC_P(setTitle_, ##__VA_ARGS__)

_MAC_F(0, "setStringValue:", void,
           setStringValue_,
           CFStringRef);
#define    setStringValue_(...) \
    _MAC_P(setStringValue_, ##__VA_ARGS__)

_MAC_F(0, "windowShouldClose:", bool,
           windowShouldClose_,
           void*);
#define    windowShouldClose_(...) \
    _MAC_P(windowShouldClose_, ##__VA_ARGS__)

_MAC_F(0, "windowDidResize:", void,
           windowDidResize_,
           void*);
#define    windowDidResize_(...) \
    _MAC_P(windowDidResize_, ##__VA_ARGS__)

_MAC_F(0, "isKeyWindow", bool,
           isKeyWindow);
#define    isKeyWindow(...) \
    _MAC_P(isKeyWindow, ##__VA_ARGS__)

_MAC_F(0, "makeKeyWindow", void,
           makeKeyWindow);
#define    makeKeyWindow(...) \
    _MAC_P(makeKeyWindow, ##__VA_ARGS__)

_MAC_F(0, "orderFront:", void,
           orderFront_,
           void*);
#define    orderFront_(...) \
    _MAC_P(orderFront_, ##__VA_ARGS__)

_MAC_F(0, "orderOut:", void,
           orderOut_,
           void*);
#define    orderOut_(...) \
    _MAC_P(orderOut_, ##__VA_ARGS__)

_MAC_F(0, "setNeedsDisplay:", void,
           setNeedsDisplay_,
           bool);
#define    setNeedsDisplay_(...) \
    _MAC_P(setNeedsDisplay_, ##__VA_ARGS__)

_MAC_F(0, "setDelegate:", void,
           setDelegate_,
           void*);
#define    setDelegate_(...) \
    _MAC_P(setDelegate_, ##__VA_ARGS__)

_MAC_F(0, "setEnabled:", void,
           setEnabled_,
           bool);
#define    setEnabled_(...) \
    _MAC_P(setEnabled_, ##__VA_ARGS__)

_MAC_F(0, "setNextKeyView:", void,
           setNextKeyView_,
           NSView*);
#define    setNextKeyView_(...) \
    _MAC_P(setNextKeyView_, ##__VA_ARGS__)

_MAC_F(0, "setDefaultButtonCell:", void,
           setDefaultButtonCell_,
           NSButtonCell*);
#define    setDefaultButtonCell_(...) \
    _MAC_P(setDefaultButtonCell_, ##__VA_ARGS__)

_MAC_F(0, "verticalScroller", NSView*,
           verticalScroller);
#define    verticalScroller(...) \
    _MAC_P(verticalScroller, ##__VA_ARGS__)

_MAC_F(0, "setHasVerticalScroller:", void,
           setHasVerticalScroller_,
           bool);
#define    setHasVerticalScroller_(...) \
    _MAC_P(setHasVerticalScroller_, ##__VA_ARGS__)

_MAC_F(0, "isEnabled", bool,
           isEnabled);
#define    isEnabled(...) \
    _MAC_P(isEnabled, ##__VA_ARGS__)

_MAC_F(0, "state", NSInteger,
           state);
#define    state(...) \
    _MAC_P(state, ##__VA_ARGS__)

_MAC_F(0, "setState:", void,
           setState_,
           NSInteger);
#define    setState_(...) \
    _MAC_P(setState_, ##__VA_ARGS__)

_MAC_F(0, "setToolTip:", void,
           setToolTip_,
           CFStringRef);
#define    setToolTip_(...) \
    _MAC_P(setToolTip_, ##__VA_ARGS__)

_MAC_F(0, "setButtonType:", void,
           setButtonType_,
           NSInteger);
#define    setButtonType_(...) \
    _MAC_P(setButtonType_, ##__VA_ARGS__)

_MAC_F(0, "setBezelStyle:", void,
           setBezelStyle_,
           NSInteger);
#define    setBezelStyle_(...) \
    _MAC_P(setBezelStyle_, ##__VA_ARGS__)

_MAC_F(0, "setImagePosition:", void,
           setImagePosition_,
           NSInteger);
#define    setImagePosition_(...) \
    _MAC_P(setImagePosition_, ##__VA_ARGS__)

_MAC_F(0, "setSendsActionOnEndEditing:", void,
           setSendsActionOnEndEditing_,
           bool);
#define    setSendsActionOnEndEditing_(...) \
    _MAC_P(setSendsActionOnEndEditing_, ##__VA_ARGS__)

_MAC_F(0, "control:textView:doCommandBySelector:", bool,
           control_textView_doCommandBySelector_,
           void*, NSView*, SEL);
#define    control_textView_doCommandBySelector_(...) \
    _MAC_P(control_textView_doCommandBySelector_, ##__VA_ARGS__)

_MAC_F(0, "moveDown:", void,
           moveDown_,
           void*);
#define    moveDown_(...) \
    _MAC_P(moveDown_, ##__VA_ARGS__)

_MAC_F(0, "moveUp:", void,
           moveUp_,
           void*);
#define    moveUp_(...) \
    _MAC_P(moveUp_, ##__VA_ARGS__)

_MAC_F(0, "setEditable:", void,
           setEditable_,
           bool);
#define    setEditable_(...) \
    _MAC_P(setEditable_, ##__VA_ARGS__)

_MAC_F(0, "setSelectable:", void,
           setSelectable_,
           bool);
#define    setSelectable_(...) \
    _MAC_P(setSelectable_, ##__VA_ARGS__)

_MAC_F(0, "setBezeled:", void,
           setBezeled_,
           bool);
#define    setBezeled_(...) \
    _MAC_P(setBezeled_, ##__VA_ARGS__)

_MAC_F(0, "setBordered:", void,
           setBordered_,
           bool);
#define    setBordered_(...) \
    _MAC_P(setBordered_, ##__VA_ARGS__)

_MAC_F(0, "setDrawsBackground:", void,
           setDrawsBackground_,
           bool);
#define    setDrawsBackground_(...) \
    _MAC_P(setDrawsBackground_, ##__VA_ARGS__)

_MAC_F(0, "statusItemWithLength:", NSStatusItem*,
           statusItemWithLength_,
           CGFloat);
#define    statusItemWithLength_(...) \
    _MAC_P(statusItemWithLength_, ##__VA_ARGS__)

_MAC_F(0, "removeStatusItem:", void,
           removeStatusItem_,
           NSStatusItem*);
#define    removeStatusItem_(...) \
    _MAC_P(removeStatusItem_, ##__VA_ARGS__)

_MAC_F(0, "systemStatusBar", NSStatusBar*,
           systemStatusBar);
#define    systemStatusBar(...) \
    _MAC_P(systemStatusBar, ##__VA_ARGS__)

_MAC_F(0, "mainScreen", NSScreen*,
           mainScreen);
#define    mainScreen(...) \
    _MAC_P(mainScreen, ##__VA_ARGS__)

_MAC_F(1, "thickness", CGFloat,
           thickness);
#define    thickness(...) \
    _MAC_P(thickness, ##__VA_ARGS__)

_MAC_F(2, "cellSize", CGPoint,
           cellSize);
#define    cellSize(...) \
    _MAC_P(cellSize, ##__VA_ARGS__)

_MAC_F(0, "tag", NSInteger,
           tag);
#define    tag(...) \
    _MAC_P(tag, ##__VA_ARGS__)

_MAC_F(0, "setTag:", void,
           setTag_,
           NSInteger);
#define    setTag_(...) \
    _MAC_P(setTag_, ##__VA_ARGS__)

_MAC_F(0, "setHighlightMode:", void,
           setHighlightMode_,
           NSInteger);
#define    setHighlightMode_(...) \
    _MAC_P(setHighlightMode_, ##__VA_ARGS__)

_MAC_F(0, "setHidden:", void,
           setHidden_,
           bool);
#define    setHidden_(...) \
    _MAC_P(setHidden_, ##__VA_ARGS__)

_MAC_F(0, "setContentView:", void,
           setContentView_,
           NSView*);
#define    setContentView_(...) \
    _MAC_P(setContentView_, ##__VA_ARGS__)

_MAC_F(0, "setDocumentView:", void,
           setDocumentView_,
           NSView*);
#define    setDocumentView_(...) \
    _MAC_P(setDocumentView_, ##__VA_ARGS__)

_MAC_F(0, "addSubview:", void,
           addSubview_,
           NSView*);
#define    addSubview_(...) \
    _MAC_P(addSubview_, ##__VA_ARGS__)

_MAC_F(0, "isFlipped", bool,
           isFlipped);
#define    isFlipped(...) \
    _MAC_P(isFlipped, ##__VA_ARGS__)

_MAC_F(0, "drawRect:", void,
           drawRect_,
           CGRect);
#define    drawRect_(...) \
    _MAC_P(drawRect_, ##__VA_ARGS__)

_MAC_F(0, "type", NSUInteger,
           type);
#define    type(...) \
    _MAC_P(type, ##__VA_ARGS__)

_MAC_F(0, "keyUp:", void,
           keyUp_,
           NSEvent*);
#define    keyUp_(...) \
    _MAC_P(keyUp_, ##__VA_ARGS__)

_MAC_F(0, "keyDown:", void,
           keyDown_,
           NSEvent*);
#define    keyDown_(...) \
    _MAC_P(keyDown_, ##__VA_ARGS__)

_MAC_F(2, "mouseLocation", CGPoint,
           mouseLocation);
#define    mouseLocation(...) \
    _MAC_P(mouseLocation, ##__VA_ARGS__)

_MAC_F(0, "pressedMouseButtons", NSInteger,
           pressedMouseButtons);
#define    pressedMouseButtons(...) \
    _MAC_P(pressedMouseButtons, ##__VA_ARGS__)

_MAC_F(0, "setIgnoresMouseEvents:", void,
           setIgnoresMouseEvents_,
           bool);
#define    setIgnoresMouseEvents_(...) \
    _MAC_P(setIgnoresMouseEvents_, ##__VA_ARGS__)

_MAC_F(0, "graphicsPort", CGContextRef,
           graphicsPort);
#define    graphicsPort(...) \
    _MAC_P(graphicsPort, ##__VA_ARGS__)

_MAC_F(0, "currentContext", NSGraphicsContext*,
           currentContext);
#define    currentContext(...) \
    _MAC_P(currentContext, ##__VA_ARGS__)

_MAC_F(0, "defaultManager", NSFileManager*,
           defaultManager);
#define    defaultManager(...) \
    _MAC_P(defaultManager, ##__VA_ARGS__)

_MAC_F(0, "systemFontOfSize:", NSFont*,
           systemFontOfSize_,
           CGFloat);
#define    systemFontOfSize_(...) \
    _MAC_P(systemFontOfSize_, ##__VA_ARGS__)

_MAC_F(1, "systemFontSize", CGFloat,
           systemFontSize);
#define    systemFontSize(...) \
    _MAC_P(systemFontSize, ##__VA_ARGS__)

_MAC_F(2, "maximumAdvancement", CGPoint,
           maximumAdvancement);
#define    maximumAdvancement(...) \
    _MAC_P(maximumAdvancement, ##__VA_ARGS__)

_MAC_F(0, "setIndeterminate:", void,
           setIndeterminate_,
           bool);
#define    setIndeterminate_(...) \
    _MAC_P(setIndeterminate_, ##__VA_ARGS__)

_MAC_F(0, "setAlignment:", void,
           setAlignment_,
           NSInteger);
#define    setAlignment_(...) \
    _MAC_P(setAlignment_, ##__VA_ARGS__)

_MAC_F(0, "addTableColumn:", void,
           addTableColumn_,
           NSTableColumn*);
#define    addTableColumn_(...) \
    _MAC_P(addTableColumn_, ##__VA_ARGS__)

_MAC_F(0, "headerCell", NSCell*,
           headerCell);
#define    headerCell(...) \
    _MAC_P(headerCell, ##__VA_ARGS__)

_MAC_F(0, "setWantsLayer:", void,
           setWantsLayer_,
           bool);
#define    setWantsLayer_(...) \
    _MAC_P(setWantsLayer_, ##__VA_ARGS__)

_MAC_F(0, "scaleUnitSquareToSize:", void,
           scaleUnitSquareToSize_,
           CGSize);
#define    scaleUnitSquareToSize_(...) \
    _MAC_P(scaleUnitSquareToSize_, ##__VA_ARGS__)

_MAC_F(0, "drawInRect:withAttributes:", void,
           drawInRect_withAttributes_,
           CGRect, CFDictionaryRef);
#define    drawInRect_withAttributes_(...) \
    _MAC_P(drawInRect_withAttributes_, ##__VA_ARGS__)

_MAC_F(0, "textDidChange:", void,
           textDidChange_,
           void*);
#define    textDidChange_(...) \
    _MAC_P(textDidChange_, ##__VA_ARGS__)

_MAC_F(0, "stringValue", CFStringRef,
           stringValue);
#define    stringValue(...) \
    _MAC_P(stringValue, ##__VA_ARGS__)

_MAC_F(1, "doubleValue", double,
           doubleValue);
#define    doubleValue(...) \
    _MAC_P(doubleValue, ##__VA_ARGS__)

_MAC_F(0, "setDoubleValue:", void,
           setDoubleValue_,
           double);
#define    setDoubleValue_(...) \
    _MAC_P(setDoubleValue_, ##__VA_ARGS__)

_MAC_F(0, "setIntegerValue:", void,
           setIntegerValue_,
           NSInteger);
#define    setIntegerValue_(...) \
    _MAC_P(setIntegerValue_, ##__VA_ARGS__)

_MAC_F(0, "displayIfNeeded", void,
           displayIfNeeded);
#define    displayIfNeeded(...) \
    _MAC_P(displayIfNeeded, ##__VA_ARGS__)

_MAC_F(0, "setMinValue:", void,
           setMinValue_,
           double);
#define    setMinValue_(...) \
    _MAC_P(setMinValue_, ##__VA_ARGS__)

_MAC_F(0, "setMaxValue:", void,
           setMaxValue_,
           double);
#define    setMaxValue_(...) \
    _MAC_P(setMaxValue_, ##__VA_ARGS__)

_MAC_F(0, "setValueWraps:", void,
           setValueWraps_,
           bool);
#define    setValueWraps_(...) \
    _MAC_P(setValueWraps_, ##__VA_ARGS__)

_MAC_F(0, "setFormatter:", void,
           setFormatter_,
           NSNumberFormatter*);
#define    setFormatter_(...) \
    _MAC_P(setFormatter_, ##__VA_ARGS__)

_MAC_F(0, "setFormatterBehavior:", void,
           setFormatterBehavior_,
           NSInteger);
#define    setFormatterBehavior_(...) \
    _MAC_P(setFormatterBehavior_, ##__VA_ARGS__)

_MAC_F(0, "setNumberStyle:", void,
           setNumberStyle_,
           NSInteger);
#define    setNumberStyle_(...) \
    _MAC_P(setNumberStyle_, ##__VA_ARGS__)

_MAC_F(0, "setPartialStringValidationEnabled:", void,
           setPartialStringValidationEnabled_,
           bool);
#define    setPartialStringValidationEnabled_(...) \
    _MAC_P(setPartialStringValidationEnabled_, ##__VA_ARGS__)

_MAC_F(0, "isPartialStringValid:newEditingString:errorDescription:", bool,
           isPartialStringValid_newEditingString_errorDescription_,
           CFStringRef, CFStringRef, CFStringRef);
#define    isPartialStringValid_newEditingString_errorDescription_(...) \
    _MAC_P(isPartialStringValid_newEditingString_errorDescription_, ##__VA_ARGS__)

_MAC_F(0, "getObjectValue:forString:errorDescription:", bool,
           getObjectValue_forString_errorDescription_,
           void**, CFStringRef, CFStringRef);
#define    getObjectValue_forString_errorDescription_(...) \
    _MAC_P(getObjectValue_forString_errorDescription_, ##__VA_ARGS__)

_MAC_F(0, "reloadData", void,
           reloadData);
#define    reloadData(...) \
    _MAC_P(reloadData, ##__VA_ARGS__)

_MAC_F(0, "dataCell", void*,
           dataCell);
#define    dataCell(...) \
    _MAC_P(dataCell, ##__VA_ARGS__)

_MAC_F(0, "setDataCell:", void,
           setDataCell_,
           NSCell*);
#define    setDataCell_(...) \
    _MAC_P(setDataCell_, ##__VA_ARGS__)

_MAC_F(0, "setDataSource:", void,
           setDataSource_,
           void*);
#define    setDataSource_(...) \
    _MAC_P(setDataSource_, ##__VA_ARGS__)

_MAC_F(0, "setResizingMask:", void,
           setResizingMask_,
           NSInteger);
#define    setResizingMask_(...) \
    _MAC_P(setResizingMask_, ##__VA_ARGS__)

_MAC_F(0, "numberOfRowsInTableView:", NSInteger,
           numberOfRowsInTableView_,
           NSTableView*);
#define    numberOfRowsInTableView_(...) \
    _MAC_P(numberOfRowsInTableView_, ##__VA_ARGS__)

_MAC_F(0, "tableView:objectValueForTableColumn:row:", void*,
           tableView_objectValueForTableColumn_row_,
           NSTableView*, NSTableColumn*, NSInteger);
#define    tableView_objectValueForTableColumn_row_(...) \
    _MAC_P(tableView_objectValueForTableColumn_row_, ##__VA_ARGS__)

_MAC_F(0, "tableView:setObjectValue:forTableColumn:row:", void,
           tableView_setObjectValue_forTableColumn_row_,
           NSTableView*, void*, NSTableColumn*, NSInteger);
#define    tableView_setObjectValue_forTableColumn_row_(...) \
    _MAC_P(tableView_setObjectValue_forTableColumn_row_, ##__VA_ARGS__)

_MAC_F(0, "tableView:dataCellForTableColumn:row:", NSCell*,
           tableView_dataCellForTableColumn_row_,
           NSTableView*, NSTableColumn*, NSInteger);
#define    tableView_dataCellForTableColumn_row_(...) \
    _MAC_P(tableView_dataCellForTableColumn_row_, ##__VA_ARGS__)

_MAC_F(0, "tableView:viewForTableColumn:row:", NSView*,
           tableView_viewForTableColumn_row_,
           NSTableView*, NSTableColumn*, NSInteger);
#define    tableView_viewForTableColumn_row_(...) \
    _MAC_P(tableView_viewForTableColumn_row_, ##__VA_ARGS__)

_MAC_F(0, "push", void,
           push);
#define    push(...) \
    _MAC_P(push, ##__VA_ARGS__)

_MAC_F(0, "pop", void,
           pop);
#define    pop(...) \
    _MAC_P(pop, ##__VA_ARGS__)

_MAC_F(0, "pointingHandCursor", NSCursor*,
           pointingHandCursor);
#define    pointingHandCursor(...) \
    _MAC_P(pointingHandCursor, ##__VA_ARGS__)

_MAC_F(0, "flushBuffer", void,
           flushBuffer);
#define    flushBuffer(...) \
    _MAC_P(flushBuffer, ##__VA_ARGS__)

_MAC_F(0, "openGLContext", NSOpenGLContext*,
           openGLContext);
#define    openGLContext(...) \
    _MAC_P(openGLContext, ##__VA_ARGS__)

_MAC_F(0, "isOpaque", bool,
           isOpaque);
#define    isOpaque(...) \
    _MAC_P(isOpaque, ##__VA_ARGS__)

_MAC_F(0, "setOpaque:", void,
           setOpaque_,
           bool);
#define    setOpaque_(...) \
    _MAC_P(setOpaque_, ##__VA_ARGS__)

_MAC_F(0, "initWithAttributes:", NSOpenGLPixelFormat*,
           initWithAttributes_,
           int*);
#define    initWithAttributes_(...) \
    _MAC_P(initWithAttributes_, ##__VA_ARGS__)

_MAC_F(0, "initWithFrame:pixelFormat:", NSOpenGLView*,
           initWithFrame_pixelFormat_,
           CGRect, NSOpenGLPixelFormat*);
#define    initWithFrame_pixelFormat_(...) \
    _MAC_P(initWithFrame_pixelFormat_, ##__VA_ARGS__)

_MAC_F(0, "makeCurrentContext", void,
           makeCurrentContext);
#define    makeCurrentContext(...) \
    _MAC_P(makeCurrentContext, ##__VA_ARGS__)

_MAC_F(0, "setValues:forParameter:", void,
           setValues_forParameter_,
           int*, NSInteger);
#define    setValues_forParameter_(...) \
    _MAC_P(setValues_forParameter_, ##__VA_ARGS__)

_MAC_F(0, "setLevel:", void,
           setLevel_,
           NSInteger);
#define    setLevel_(...) \
    _MAC_P(setLevel_, ##__VA_ARGS__)

_MAC_F(0, "setHasShadow:", void,
           setHasShadow_,
           bool);
#define    setHasShadow_(...) \
    _MAC_P(setHasShadow_, ##__VA_ARGS__)

_MAC_F(0, "clearColor", NSColor*,
           clearColor);
#define    clearColor(...) \
    _MAC_P(clearColor, ##__VA_ARGS__)

_MAC_F(0, "setBackgroundColor:", void,
           setBackgroundColor_,
           NSColor*);
#define    setBackgroundColor_(...) \
    _MAC_P(setBackgroundColor_, ##__VA_ARGS__)

_MAC_F(0, "postEvent:atStart:", void,
           postEvent_atStart_,
           NSEvent*, bool);
#define    postEvent_atStart_(...) \
    _MAC_P(postEvent_atStart_, ##__VA_ARGS__)

_MAC_F(0, "otherEventWithType:location:modifierFlags:timestamp:windowNumber:context:subtype:data1:data2:", NSEvent*,
           otherEventWithType_location_modifierFlags_timestamp_windowNumber_context_subtype_data1_data2_,
           NSInteger, CGPoint, NSInteger, CGFloat, NSInteger, NSGraphicsContext*, short, NSInteger, NSInteger);
#define    otherEventWithType_location_modifierFlags_timestamp_windowNumber_context_subtype_data1_data2_(...) \
    _MAC_P(otherEventWithType_location_modifierFlags_timestamp_windowNumber_context_subtype_data1_data2_, ##__VA_ARGS__)

#undef _MAC_L
#undef _MAC_L4
#undef _MAC_P1
#undef _MAC_P0
#undef _MAC_A1
#undef _MAC_A0
#undef _MAC_F
#undef _MAC_T

extern void NSBeep();
extern void CGSSetConnectionProperty(int, int, CFStringRef, CFBooleanRef);
extern int _CGSDefaultConnection();

#ifdef __cplusplus
}
#endif

#endif /** MAC_LOAD **/
