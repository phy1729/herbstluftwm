/** Copyright 2011-2013 Thorsten Wißmann. All rights reserved.
 *
 * This software is licensed under the "Simplified BSD License".
 * See LICENSE for details */

#ifndef __HERBSTLUFT_DESKTOPWINDOW_H_
#define __HERBSTLUFT_DESKTOPWINDOW_H_

#include <X11/Xlib.h>
#include <X11/Xproto.h>
#include <X11/Xatom.h>
#include <vector>
#include <memory>

/* container for unmanaged windows like
 *  - desktop windows
 *  - panels
 */

class DesktopWindow {
public:
    DesktopWindow(Window win, bool ifBelow);
    bool below() const;
    Window window() const;
    static void registerDesktop(Window win);
    static void lowerDesktopWindows();
    static void unregisterDesktop(Window win);
private:

    // members:
    Window win;
    bool m_below;
    static std::vector<std::shared_ptr<DesktopWindow>> windows;

};

#endif

