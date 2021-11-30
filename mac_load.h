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
    NSWarningAlertStyle       = 0,
    NSInformationalAlertStyle = 1,
    NSCriticalAlertStyle      = 2,
};
enum {
    NSAlertFirstButtonReturn  = 1000,
    NSAlertSecondButtonReturn = 1001,
    NSAlertThirdButtonReturn  = 1002,
};
enum {
    NSCancelButton = 0,
    NSOKButton     = 1,
};
enum {
    NSFileHandlingPanelCancelButton = NSCancelButton,
    NSFileHandlingPanelOKButton     = NSOKButton,
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



// c - concatenator/sequencer; f - function
#define _MAC_L(c, f, ...) c( \
c(c(_MAC_L4(c,f,0,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,__VA_ARGS__),   \
    _MAC_L4(c,f,1,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,        __VA_ARGS__)),  \
  c(_MAC_L4(c,f,2,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,                __VA_ARGS__),   \
    _MAC_L4(c,f,3,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,                        __VA_ARGS__))), \
c(c(_MAC_L4(c,f,4,,,,,,,,,,,,,,,,,,,,,,,,,                                __VA_ARGS__),   \
    _MAC_L4(c,f,5,,,,,,,,,,,,,,,,,                                        __VA_ARGS__)),  \
  c(_MAC_L4(c,f,6,,,,,,,,,                                                __VA_ARGS__),   \
    _MAC_L4(c,f,7,                                                        __VA_ARGS__))))
//               ^1      ^8      ^16     ^24     ^32     ^40     ^48     ^56
#define _MAC_L4(c, f, i, ...) c( \
c(c(_MAC_L3(f,0,i,0,,,,,,,,__VA_ARGS__), _MAC_L3(f,1,i,1,,,,,,,__VA_ARGS__)),  \
  c(_MAC_L3(f,0,i,2,,,,,,  __VA_ARGS__), _MAC_L3(f,1,i,3,,,,,  __VA_ARGS__))), \
c(c(_MAC_L3(f,0,i,4,,,,    __VA_ARGS__), _MAC_L3(f,1,i,5,,,    __VA_ARGS__)),  \
  c(_MAC_L3(f,0,i,6,,      __VA_ARGS__), _MAC_L3(f,1,i,7,      __VA_ARGS__))))

#define _MAC_L3(...) _MAC_L2(__VA_ARGS__, \
1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, \
1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,  1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, \
0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,  0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, \
0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,  0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, )

// p - parity: 0 = even (0th, 2nd, ...), 1 = odd (1st, 3rd, ...)
// a00 - target argument; i##i00 - unique pseudonumeric index for a00
#define _MAC_L2(f, p, i, \
i00,i01,i02,i03, i04,i05,i06,i07, i08,i09,i0A,i0B, i0C,i0D,i0E,i0F, \
i10,i11,i12,i13, i14,i15,i16,i17, i18,i19,i1A,i1B, i1C,i1D,i1E,i1F, \
i20,i21,i22,i23, i24,i25,i26,i27, i28,i29,i2A,i2B, i2C,i2D,i2E,i2F, \
i30,i31,i32,i33, i34,i35,i36,i37, i38,i39,i3A,i3B, i3C,i3D,i3E,i3F, \
a00,a01,a02,a03, a04,a05,a06,a07, a08,a09,a0A,a0B, a0C,a0D,a0E,a0F, \
a10,a11,a12,a13, a14,a15,a16,a17, a18,a19,a1A,a1B, a1C,a1D,a1E,a1F, \
a20,a21,a22,a23, a24,a25,a26,a27, a28,a29,a2A,a2B, a2C,a2D,a2E,a2F, \
a30,a31,a32,a33, a34,a35,a36,a37, a38,a39,a3A,a3B, a3C,a3D,a3E,a3F, \
z, ...) _MAC_L##z(f, p, i##i00, a00)

#define _MAC_L1(f, p, i, a) f##p(i, a)
#define _MAC_L0(f, p, i, a)

#define _MAC_TYPE_ARG0(i, a)
#define _MAC_TYPE_ARG1(i, a) , a _##i
#define _MAC_ONLY_ARG0(i, a)
#define _MAC_ONLY_ARG1(i, a) , _##i
#define _MAC_FUNC_LEX0(i, a) a
#define _MAC_FUNC_LEX1(i, a) _
#define _MAC_FUNC_STR0(i, a) #a
#define _MAC_FUNC_STR1(i, a) ":"

#define _MAC_CAT0(a, b) a##b
#define _MAC_CAT(a, b) _MAC_CAT0(a, b)
#define _MAC_SEQ(a, b) a b

// this is needed to get selectors or classes by name
#define _(callable) _MAC_CAT(__, callable)()

// these are needed to declare functions
#define _MAC_F(type, retn, ...) __attribute__((unused)) static                 \
SEL _(_MAC_L(_MAC_CAT, _MAC_FUNC_LEX, __VA_ARGS__)) {                          \
    static SEL what = 0; if (!what) what = sel_registerName(                   \
        _MAC_L(_MAC_SEQ, _MAC_FUNC_STR, __VA_ARGS__)); return what;            \
} __attribute__((unused)) static inline                                        \
retn _MAC_L(_MAC_CAT, _MAC_FUNC_LEX, __VA_ARGS__)                              \
    (void *inst _MAC_L(_MAC_SEQ, _MAC_TYPE_ARG, __VA_ARGS__)) {                \
    return ((retn (*)(void*, SEL                                               \
        _MAC_L(_MAC_SEQ, _MAC_TYPE_ARG, __VA_ARGS__)))objc_msgSend##type)      \
        (inst, _(_MAC_L(_MAC_CAT, _MAC_FUNC_LEX, __VA_ARGS__))                 \
                 _MAC_L(_MAC_SEQ, _MAC_ONLY_ARG, __VA_ARGS__));                \
} __attribute__((unused)) static inline                                        \
retn _MAC_CAT(super_, _MAC_L(_MAC_CAT, _MAC_FUNC_LEX, __VA_ARGS__))            \
    (void *inst _MAC_L(_MAC_SEQ, _MAC_TYPE_ARG, __VA_ARGS__)) {                \
    struct objc_super s = {inst, class_getSuperclass(object_getClass(inst))};  \
    return ((retn (*)(struct objc_super*, SEL                                  \
        _MAC_L(_MAC_SEQ, _MAC_TYPE_ARG, __VA_ARGS__)))objc_msgSendSuper##type) \
        (&s, _(_MAC_L(_MAC_CAT, _MAC_FUNC_LEX, __VA_ARGS__))                   \
               _MAC_L(_MAC_SEQ, _MAC_ONLY_ARG, __VA_ARGS__));                  \
}
#define _MAC_F0(retn, ...) _MAC_F(      , retn, __VA_ARGS__)
#define _MAC_FF(retn, ...) _MAC_F(_fpret, retn, __VA_ARGS__)
#define _MAC_FS(retn, ...) _MAC_F(_stret, retn, __VA_ARGS__)
// not sure if this is correct
#define objc_msgSendSuper_fpret objc_msgSendSuper

// these are needed to declare types
#define _MAC_T(...) _MAC_T2(__VA_ARGS__, 1, 0)
#define _MAC_T2(a, b, n, ...) __attribute__((unused)) static \
Class _(a) { static Class what = 0;                          \
    if (!what) what = (Class)objc_getClass(#a); return what; \
} typedef struct _MAC_T##n(a, b) a
#define _MAC_T1(a, b) b
#define _MAC_T0(a, b) a



/// Toll-free bridged types

_MAC_T(NSArray, __CFArray);
_MAC_T(NSString, __CFString);
_MAC_T(NSAttributedString, __CFAttributedString);
_MAC_T(NSDictionary, __CFDictionary);
_MAC_T(NSTimer, __CFRunLoopTimer);
_MAC_T(NSURL, __CFURL);
_MAC_T(NSFont, __CTFont);

/// Regular types

#if __LP64__ || TARGET_OS_EMBEDDED || TARGET_OS_IPHONE || TARGET_OS_WIN32 || NS_BUILD_32_LIKE_64
    typedef long NSInteger;
    typedef unsigned long NSUInteger;
#else
    typedef int NSInteger;
    typedef unsigned int NSUInteger;
#endif

typedef double NSTimeInterval;
typedef CFRange NSRange;
typedef CGPoint NSPoint;
typedef CGSize NSSize;
typedef CGRect NSRect;

_MAC_T(NSObject);
_MAC_T(NSUserDefaults);
_MAC_T(NSRunLoop);
_MAC_T(NSApplication);
_MAC_T(NSAutoreleasePool);
_MAC_T(NSNotificationCenter);
_MAC_T(NSNotification);
_MAC_T(NSBundle);
_MAC_T(NSEvent);
_MAC_T(NSMutableParagraphStyle);
_MAC_T(NSFileManager);
_MAC_T(NSOpenPanel);
_MAC_T(NSAlert);
_MAC_T(NSNumberFormatter);
_MAC_T(NSGraphicsContext);
_MAC_T(NSImage);
_MAC_T(NSMenu);
_MAC_T(NSMenuItem);
_MAC_T(NSStatusItem);
_MAC_T(NSStatusBar);
_MAC_T(NSScreen);
_MAC_T(NSWindow);
_MAC_T(NSTextField);
_MAC_T(NSButtonCell);
_MAC_T(NSButton);
_MAC_T(NSProgressIndicator);
_MAC_T(NSStepper);
_MAC_T(NSView);
_MAC_T(NSCell);
_MAC_T(NSScrollView);
_MAC_T(NSClipView);
_MAC_T(NSTableView);
_MAC_T(NSTableColumn);
_MAC_T(NSLayoutManager);
_MAC_T(NSTextContainer);
_MAC_T(NSTextStorage);
_MAC_T(NSColor);
_MAC_T(NSCursor);
_MAC_T(NSPanel);
_MAC_T(NSOpenGLView);
_MAC_T(NSOpenGLContext);
_MAC_T(NSOpenGLPixelFormat);



_MAC_F0(void*, init);
_MAC_F0(void*, alloc);
_MAC_F0(void*, release);
_MAC_F0(void*, retain);
_MAC_F0(Class, class);
_MAC_F0(Class, subclass);
_MAC_F0(NSCell*, cell);
_MAC_F0(NSButton*, button);
_MAC_F0(void, setAction, SEL);
_MAC_F0(void, setTarget, void*);
_MAC_F0(bool, setActivationPolicy, NSInteger);
_MAC_F0(void, activateIgnoringOtherApps, bool);
_MAC_F0(NSApplication*, sharedApplication);
_MAC_F0(void, run);
_MAC_F0(NSInteger, runModal);
_MAC_F0(void, stop, void*);
_MAC_F0(NSUserDefaults*, standardUserDefaults);
_MAC_F0(NSObject*, objectForKey, NSString*);
_MAC_F0(void, setObject, NSObject*,
              forKey, NSString*);
_MAC_F0(void, setBool, bool,
              forKey, NSString*);
_MAC_F0(NSString*, localizedStringForKey, NSString*,
                   value, NSString*,
                   table, NSString*);
_MAC_F0(NSBundle*, bundleWithIdentifier, NSString*);
_MAC_F0(NSBundle*, mainBundle);
_MAC_F0(NSString*, bundlePath);
_MAC_F0(NSArray*, URLsForDirectory, NSInteger,
                  inDomains, NSInteger);
_MAC_F0(NSArray*, URLs);
_MAC_F0(NSMenuItem*, separatorItem);
_MAC_F0(void, addItem, NSMenuItem*);
_MAC_F0(void, setAutoenablesItems, bool);
_MAC_F0(NSImage*, imageNamed, NSString*);
_MAC_F0(void, setImage, NSImage*);
_MAC_F0(void, setOnStateImage, NSImage*);
_MAC_F0(void, setSubmenu, NSMenu*);
_MAC_F0(bool, popUpMenuPositioningItem, NSMenuItem*,
              atLocation, NSPoint,
              inView, NSView*);
_MAC_F0(void, lockFocus);
_MAC_F0(void, unlockFocus);
_MAC_F0(CGImageRef, CGImageForProposedRect, NSRect*,
                    context, NSGraphicsContext*,
                    hints, NSDictionary*);
_MAC_F0(NSImage*, initWithSize, NSSize);
_MAC_F0(NSImage*, initWithCGImage, CGImageRef,
                  size, NSSize);
_MAC_F0(NSWindow*, initWithContentRect, NSRect,
                   styleMask, NSInteger,
                   backing, NSInteger,
                   defer, bool);
_MAC_F0(NSMenuItem*, initWithTitle, NSString*,
                     action, SEL,
                     keyEquivalent, NSString*);
_MAC_FS(NSRect, contentRectForFrameRect, NSRect);
_MAC_FS(NSRect, frameRectForContentRect, NSRect);
_MAC_FS(NSRect, visibleFrame);
_MAC_FS(NSRect, frame);
_MAC_F0(void, setFrame, NSRect);
_MAC_F0(void, setFrame, NSRect,
              display, bool,
              animate, bool);
_MAC_F0(NSString*, characters);
_MAC_F0(NSString*, charactersIgnoringModifiers);
_MAC_F0(bool, acceptsFirstResponder);
_MAC_F0(void, setInitialFirstResponder, NSView*);
_MAC_F0(void, setMinSize, NSSize);
_MAC_F0(void, setTitle, NSString*);
_MAC_F0(void, setStringValue, NSString*);
_MAC_F0(bool, windowShouldClose, void*);
_MAC_F0(void, windowDidResize, void*);
_MAC_F0(bool, isKeyWindow);
_MAC_F0(void, makeKeyWindow);
_MAC_F0(void, orderFront, void*);
_MAC_F0(void, orderOut, void*);
_MAC_F0(void, setNeedsDisplay, bool);
_MAC_F0(void, setDelegate, void*);
_MAC_F0(void, setEnabled, bool);
_MAC_F0(void, setNextKeyView, NSView*);
_MAC_F0(void, setDefaultButtonCell, NSButtonCell*);
_MAC_F0(void, setPostsBoundsChangedNotifications, bool);
_MAC_F0(void, setPostsFrameChangedNotifications, bool);
_MAC_F0(void, addObserver, id,
              selector, SEL,
              name, NSString*,
              object, id);
_MAC_F0(void, removeObserver, id,
              name, NSString*,
              object, id);
_MAC_F0(void, scrollToPoint, NSPoint);
_MAC_F0(NSNotificationCenter*, defaultCenter);
_MAC_FS(NSRect, documentVisibleRect);
_MAC_F0(NSClipView*, contentView);
_MAC_F0(NSView*, verticalScroller);
_MAC_F0(void, setHasVerticalScroller, bool);
_MAC_F0(bool, isEnabled);
_MAC_F0(NSInteger, state);
_MAC_F0(void, setState, NSInteger);
_MAC_F0(void, setToolTip, NSString*);
_MAC_F0(void, setButtonType, NSInteger);
_MAC_F0(void, setBezelStyle, NSInteger);
_MAC_F0(void, setImagePosition, NSInteger);
_MAC_F0(void, setSendsActionOnEndEditing, bool);
_MAC_F0(bool, control, void*,
              textView, NSView*,
              doCommandBySelector, SEL);
_MAC_F0(void, moveDown, void*);
_MAC_F0(void, moveUp, void*);
_MAC_F0(void, setEditable, bool);
_MAC_F0(void, setSelectable, bool);
_MAC_F0(void, setBezeled, bool);
_MAC_F0(void, setBordered, bool);
_MAC_F0(void, setDrawsBackground, bool);
_MAC_F0(void, setScrollable, bool);
_MAC_F0(NSStatusItem*, statusItemWithLength, CGFloat);
_MAC_F0(void, removeStatusItem, NSStatusItem*);
_MAC_F0(NSStatusBar*, systemStatusBar);
_MAC_F0(NSScreen*, mainScreen);
_MAC_FF(CGFloat, thickness);
_MAC_F0(NSSize, cellSize);
_MAC_F0(NSInteger, tag);
_MAC_F0(void, setTag, NSInteger);
_MAC_F0(void, setHighlightMode, NSInteger);
_MAC_F0(void, setHidden, bool);
_MAC_F0(void, setContentView, NSView*);
_MAC_F0(void, setDocumentView, NSView*);
_MAC_F0(void, addSubview, NSView*);
_MAC_F0(bool, isFlipped);
_MAC_F0(void, drawRect, NSRect);
_MAC_F0(NSUInteger, type);
_MAC_F0(void, keyUp, NSEvent*);
_MAC_F0(void, keyDown, NSEvent*);
_MAC_F0(unsigned short, keyCode);
_MAC_F0(NSPoint, mouseLocation);
_MAC_F0(NSInteger, pressedMouseButtons);
_MAC_F0(void, setIgnoresMouseEvents, bool);
_MAC_F0(CGContextRef, graphicsPort);
_MAC_F0(NSGraphicsContext*, currentContext);
_MAC_F0(NSFileManager*, defaultManager);
_MAC_F0(NSFont*, systemFontOfSize, CGFloat);
_MAC_FF(CGFloat, systemFontSize);
_MAC_F0(NSSize, maximumAdvancement);
_MAC_F0(void, setIndeterminate, bool);
_MAC_F0(void, setAlignment, NSInteger);
_MAC_F0(void, addTableColumn, NSTableColumn*);
_MAC_F0(NSCell*, headerCell);
_MAC_F0(void, setWantsLayer, bool);
_MAC_F0(void, scaleUnitSquareToSize, NSSize);
_MAC_F0(void, addAttribute, NSString*,
              value, id,
              range, NSRange);
_MAC_F0(NSTextStorage*, initWithString, NSString*);
_MAC_F0(NSTextContainer*, initWithContainerSize, NSSize);
_MAC_F0(void, addTextContainer, NSTextContainer*);
_MAC_F0(void, addLayoutManager, NSLayoutManager*);
_MAC_F0(void, setLineFragmentPadding, CGFloat);
_MAC_F0(void, glyphRangeForTextContainer, NSTextContainer*);
_MAC_FS(NSRect, usedRectForTextContainer, NSTextContainer*);
_MAC_F0(void, drawInRect, NSRect,
              withAttributes, NSDictionary*);
_MAC_F0(NSSize, sizeWithAttributes, NSDictionary*);
_MAC_F0(void, textDidChange, void*);
_MAC_F0(NSString*, stringValue);
_MAC_FF(double, doubleValue);
_MAC_F0(void, setDoubleValue, double);
_MAC_F0(void, setIntegerValue, NSInteger);
_MAC_F0(void, displayIfNeeded);
_MAC_F0(void, display);
_MAC_F0(void, setMinValue, double);
_MAC_F0(void, setMaxValue, double);
_MAC_F0(void, setValueWraps, bool);
_MAC_F0(void, setFormatter, NSNumberFormatter*);
_MAC_F0(void, setFormatterBehavior, NSInteger);
_MAC_F0(void, setNumberStyle, NSInteger);
_MAC_F0(void, setPartialStringValidationEnabled, bool);
_MAC_F0(bool, isPartialStringValid, NSString*,
              newEditingString, NSString*,
              errorDescription, NSString*);
_MAC_F0(bool, getObjectValue, void**,
              forString, NSString*, errorDescription, NSString*);
_MAC_F0(void, reloadData);
_MAC_F0(void*, dataCell);
_MAC_F0(void, setDataCell, NSCell*);
_MAC_F0(void, setDataSource, void*);
_MAC_F0(void, setResizingMask, NSInteger);
_MAC_F0(NSInteger, numberOfRowsInTableView, NSTableView*);
_MAC_F0(void*, tableView, NSTableView*,
               objectValueForTableColumn, NSTableColumn*,
               row, NSInteger);
_MAC_F0(void, tableView, NSTableView*,
              setObjectValue, void*,
              forTableColumn, NSTableColumn*,
              row, NSInteger);
_MAC_F0(NSCell*, tableView, NSTableView*,
                 dataCellForTableColumn, NSTableColumn*,
                 row, NSInteger);
_MAC_F0(NSView*, tableView, NSTableView*,
                 viewForTableColumn, NSTableColumn*,
                 row, NSInteger);
_MAC_F0(void, push);
_MAC_F0(void, pop);
_MAC_F0(NSCursor*, pointingHandCursor);
_MAC_F0(void, flushBuffer);
_MAC_F0(NSOpenGLContext*, openGLContext);
_MAC_F0(bool, isOpaque);
_MAC_F0(void, setOpaque, bool);
_MAC_F0(NSOpenGLPixelFormat*, initWithAttributes, int*);
_MAC_F0(NSOpenGLView*, initWithFrame, NSRect,
                       pixelFormat, NSOpenGLPixelFormat*);
_MAC_F0(void, makeCurrentContext);
_MAC_F0(void, setValues, int*,
              forParameter, NSInteger);
_MAC_F0(void, setLevel, NSInteger);
_MAC_F0(void, setHasShadow, bool);
_MAC_F0(NSColor*, colorWithDeviceRed, CGFloat,
                  green, CGFloat,
                  blue, CGFloat,
                  alpha, CGFloat);
_MAC_F0(NSColor*, colorWithCGColor, CGColorRef);
_MAC_F0(NSColor*, controlTextColor);
_MAC_F0(NSColor*, disabledControlTextColor);
_MAC_F0(NSColor*, placeholderTextColor);
_MAC_F0(NSColor*, textColor);
_MAC_F0(NSColor*, clearColor);
_MAC_F0(void, setTextColor, NSColor*);
_MAC_F0(void, setBackgroundColor, NSColor*);
_MAC_F0(void, postEvent, NSEvent*, atStart, bool);
_MAC_F0(NSEvent*, otherEventWithType, NSInteger,
                  location, NSPoint,
                  modifierFlags, NSInteger,
                  timestamp, NSTimeInterval,
                  windowNumber, NSInteger,
                  context, NSGraphicsContext*,
                  subtype, short,
                  data1, NSInteger,
                  data2, NSInteger);
_MAC_F0(void, performSelector, SEL,
              target, id,
              argument, id,
              order, NSUInteger,
              modes, NSArray*);
_MAC_F0(NSRunLoop*, currentRunLoop);
_MAC_F0(NSButton*, addButtonWithTitle, NSString*);
_MAC_F0(void, setMessageText, NSString*);
_MAC_F0(void, setInformativeText, NSString*);
_MAC_F0(void, setAlertStyle, NSInteger);
_MAC_F0(NSOpenPanel*, openPanel);
_MAC_F0(void, setAllowsMultipleSelection, bool);
_MAC_F0(void, setCanChooseDirectories, bool);
_MAC_F0(void, setCanChooseFiles, bool);
_MAC_F0(void, setAllowedFileTypes, NSArray*);
_MAC_F0(void, setNameFieldStringValue, NSString*);
_MAC_F0(void, setDirectoryURL, NSURL*);
_MAC_F0(bool, wantsBestResolutionOpenGLSurface);
_MAC_F0(NSSize, convertSizeToBacking, NSSize);
_MAC_F0(NSSize, convertSizeFromBacking, NSSize);
_MAC_F0(NSPoint, convertPointToBacking, NSPoint);
_MAC_F0(NSPoint, convertPointFromBacking, NSPoint);
_MAC_FS(NSRect, convertRectToBacking, NSRect);
_MAC_FS(NSRect, convertRectFromBacking, NSRect);

#undef _MAC_L
#undef _MAC_L4
#undef _MAC_L3
#undef _MAC_L2
#undef _MAC_L1
#undef _MAC_L0
#undef _MAC_TYPE_ARG0
#undef _MAC_TYPE_ARG1
#undef _MAC_ONLY_ARG0
#undef _MAC_ONLY_ARG1
#undef _MAC_FUNC_LEX0
#undef _MAC_FUNC_LEX1
#undef _MAC_FUNC_STR0
#undef _MAC_FUNC_STR1
#undef _MAC_F
#undef _MAC_F0
#undef _MAC_FF
#undef _MAC_FS
#undef _MAC_T
#undef _MAC_T2
#undef _MAC_T1
#undef _MAC_T0



static struct {
    Class uuid;
    char *name;
    long  icnt;
} *_MAC_Subclasses = 0;



extern NSString *NSFontAttributeName;
extern NSString *NSParagraphStyleAttributeName;
extern NSString *NSForegroundColorAttributeName;
extern NSString *NSBackgroundColorAttributeName;
extern NSString *NSViewBoundsDidChangeNotification;
extern NSString *NSViewFrameDidChangeNotification;
extern NSString *NSRunLoopCommonModes;

extern void NSBeep();
extern void CGSSetConnectionProperty(int, int, CFStringRef, CFBooleanRef);
extern int _CGSDefaultConnection();



/// MacOS versions

#define MAC_10_05_PLUS (kCFCoreFoundationVersionNumber >=  476.00)
#define MAC_10_06_PLUS (kCFCoreFoundationVersionNumber >=  550.00)
#define MAC_10_07_PLUS (kCFCoreFoundationVersionNumber >=  635.00)
#define MAC_10_08_PLUS (kCFCoreFoundationVersionNumber >=  744.00)
#define MAC_10_09_PLUS (kCFCoreFoundationVersionNumber >=  855.11)
#define MAC_10_10_PLUS (kCFCoreFoundationVersionNumber >= 1151.16)
#define MAC_10_11_PLUS (kCFCoreFoundationVersionNumber >= 1253.00)



/// template for handler function prototypes; names "self" and "_cmd" taken from ObjC docs:
/// https://developer.apple.com/documentation/objectivec/1418901-class_addmethod?language=objc

#define MAC_Handler(func, ...) func(void *self, SEL _cmd, ##__VA_ARGS__)



/// class instance variable management

#define MAC_GetIvar(inst, name, data) object_getInstanceVariable((void*)(inst), name, (void**)(data))
#define MAC_SetIvar(inst, name, data) object_setInstanceVariable((void*)(inst), name, (void*)(data))



/// NSString management

__attribute__((unused))
static char *MAC_LoadString(NSString *cfsr) {
    CFIndex slen, size;
    uint8_t *retn = 0;

    if (CFStringGetBytes(cfsr, CFRangeMake(0, slen = CFStringGetLength(cfsr)),
                         kCFStringEncodingUTF8, '?', false, 0, 0, &size) > 0)
        CFStringGetBytes(cfsr, CFRangeMake(0, slen), kCFStringEncodingUTF8,
                         '?', false, retn = calloc(1, 1 + size), size, 0);
    return (char*)retn;
}
__attribute__((unused))
static NSString *MAC_MakeString(char *text) {
    CFStringRef retn = CFStringCreateWithBytes
                           (0, (text)? (uint8_t*)text : (uint8_t*)"", (text)?
                            strlen(text) : 0, kCFStringEncodingUTF8, false);
    return (NSString*)retn;
}
#define MAC_FreeString(s) CFRelease(s)
/// Constant NSString* creator.
/// If you`re using it, be sure to compile with -fconstant-cfstrings!!!
#define MAC_ConstString(s) ((NSString*)CFSTR(s))



/// When the official documentation states that there is an NSDictionary to
/// be created with some NS<Whatever> values used as keys, remember that in
/// the CoreFoundation framework their equivalents are named kCT<Whatever>.
/// If there are none in CF, just import them: "extern void *NS<Whatever>".

#define MAC_MakeDict(k, ...) _MAC_MakeDict(k, ##__VA_ARGS__, nil, nil)
__attribute__((unused))
static NSDictionary *_MAC_MakeDict(NSString *key1, ...) {
    CFDictionaryRef retn = 0;
    NSString *iter;
    va_list list;
    long size;

    NSString **keys;
    void **vals;

    size = 0;
    iter = key1;
    va_start(list, key1);
    while (iter) {
        va_arg(list, void*);
        iter = va_arg(list, NSString*);
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
            iter = va_arg(list, NSString*);
        }
        va_end(list);
        retn = CFDictionaryCreate(0, (const void**)keys, (const void**)vals,
                                  size, &kCFTypeDictionaryKeyCallBacks,
                                        &kCFTypeDictionaryValueCallBacks);
        free(vals);
        free(keys);
    }
    return (NSDictionary*)retn;
}
#define MAC_FreeDict(d) CFRelease(d)



__attribute__((unused))
static CFRunLoopTimerRef MAC_MakeTimer(unsigned time,
                                       CFRunLoopTimerCallBack func,
                                       void *data) {
    CFRunLoopTimerContext ctxt = {0, data};
    CFRunLoopTimerRef retn =
        CFRunLoopTimerCreate(0, CFAbsoluteTimeGetCurrent(),
                             0.001 * time, 0, 0, func, &ctxt);

    CFRunLoopAddTimer(CFRunLoopGetCurrent(), retn, NSRunLoopCommonModes);
    return retn;
}
#define MAC_FreeTimer(t) CFRunLoopTimerInvalidate(t)



__attribute__((unused))
static CFRunLoopObserverRef MAC_MakeIdleFunc(CFRunLoopObserverCallBack func,
                                             void *data) {
    CFRunLoopObserverContext ctxt = {0, data};
    CFRunLoopObserverRef retn =
        CFRunLoopObserverCreate(0, kCFRunLoopBeforeWaiting,
                                true, 0, func, &ctxt);

    CFRunLoopAddObserver(CFRunLoopGetCurrent(), retn, NSRunLoopCommonModes);
    return retn;
}
#define MAC_FreeIdleFunc(t) CFRunLoopObserverInvalidate(t)



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
            (__typeof__(*_MAC_Subclasses)){retn, strdup(name), 1};
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

#ifdef __cplusplus
}
#endif

#endif /** MAC_LOAD **/
