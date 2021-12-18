# mac_load
This is a public domain, single-header library that facilitates creating GUI
apps for OS X in pure C; no ObjC knowledge required.

[TODO:] describe everything

# usage

### Objective-C GUI app example:

```objective-c
/* clang /path/to/this/source.m -framework AppKit -o obj_c_example */
#include <AppKit/AppKit.h>

@interface MyView: NSView {}
@end

@implementation MyView
    - (void)drawRect:(NSRect)rect {
        [[NSColor keyboardFocusIndicatorColor] set];
        const int n = 12;
        for (double f = 0; f < 2 * M_PI; f += 2 * M_PI / n)
            for (double g = 0; g < 2 * M_PI; g += 2 * M_PI / n) {
                NSPoint begin = {(sin(f) + 1) * rect.size.width * 0.5,
                                 (cos(f) + 1) * rect.size.height * 0.5};
                NSPoint end = {(sin(g) + 1) * rect.size.width * 0.5,
                               (cos(g) + 1) * rect.size.height * 0.5};
                [NSBezierPath strokeLineFromPoint:begin toPoint:end];
            }
    }

    - (void)windowShouldClose:(NSNotification*)notification {
        [[NSApplication sharedApplication] stop:self];
    }
@end

int main() {
    NSAutoreleasePool *myPool = [[NSAutoreleasePool alloc] init];

    NSRect rect = {{100.0, 350.0}, {400.0, 400.0}};
    NSInteger mask = NSTitledWindowMask | NSClosableWindowMask
                   | NSMiniaturizableWindowMask;
    NSWindow *myWnd = [[[NSWindow alloc]
                        initWithContentRect:rect styleMask:mask
                        backing:NSBackingStoreBuffered defer:NO]
                       autorelease];
    [myWnd setTitle:@"ObjC Application Window"];

    NSView *myView = [[[MyView alloc] init] autorelease];
    [myWnd setContentView:myView];
    [myWnd setDelegate:(id)myView];
    [myWnd orderFront:nil];
    [myWnd makeKeyWindow];

    [[NSApplication sharedApplication] run];
    [myPool release];
    return EXIT_SUCCESS;
}
```

### Its full equivalent in C:

```c
/* clang /path/to/this/source.c -framework AppKit -o pure_c_example */
#include "mac_load.h"

void MAC_Handler(OnRect, NSRect rect) {
    set(keyboardFocusIndicatorColor(_(NSColor)));
    const int n = 12;
    for (double f = 0; f < 2 * M_PI; f += 2 * M_PI / n)
        for (double g = 0; g < 2 * M_PI; g += 2 * M_PI / n) {
            NSPoint begin = {(sin(f) + 1) * rect.size.width * 0.5,
                             (cos(f) + 1) * rect.size.height * 0.5};
            NSPoint end = {(sin(g) + 1) * rect.size.width * 0.5,
                           (cos(g) + 1) * rect.size.height * 0.5};
            strokeLineFromPoint_toPoint_(_(NSBezierPath), begin, end);
        }
}

void MAC_Handler(OnClose, NSNotification *notification) {
    stop_(sharedApplication(_(NSApplication)), self);
}

int main() {
    // use MAC_LoadClass("nAmE") if unable to pass MyView to where it is needed
    Class MyView = MAC_MakeClass("nAmE", _(NSView), /* extra fields = */ nil,
                                 MAC_TempArray(_(drawRect_), OnRect,
                                               _(windowShouldClose_), OnClose));

    NSAutoreleasePool *myPool = init(alloc(_(NSAutoreleasePool)));

    NSRect rect = {{100.0, 350.0}, {400.0, 400.0}};
    NSInteger mask = NSTitledWindowMask | NSClosableWindowMask
                   | NSMiniaturizableWindowMask;
    NSWindow *myWnd = autorelease(initWithContentRect_styleMask_backing_defer_(
                 alloc(_(NSWindow)), rect, mask, kCGBackingStoreBuffered, NO));
    setTitle_(myWnd, MAC_ConstString("Pure C Application Window"));

    NSView *myView = autorelease(init(alloc(MyView)));
    setContentView_(myWnd, myView);
    setDelegate_(myWnd, (id)myView);
    orderFront_(myWnd, nil);
    makeKeyWindow(myWnd);

    run(sharedApplication(_(NSApplication)));
    release(myPool);

    MAC_FreeClass(MyView); // segfaults if called before all instances get freed
    return EXIT_SUCCESS;
}
```

More advanced examples can be found [here](https://github.com/hidefromkgb/DPengine),
or [here](https://github.com/hidefromkgb/msu3-waves),
or [here](https://github.com/hidefromkgb/ogl_stub).
