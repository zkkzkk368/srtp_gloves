#ifndef BLTHANDLER_H
#define BLTHANDLER_H

#include "windows.h"


class BltHandler
{
public:
    BltHandler();
    static void gotoDesktop();
    static void closeWindow();
    static void pressRightKey();
    static void pressLeftKey();
    static void pressUpKey();
    static void pressDownKey();
    static void pressPageUpKey();
    static void pressPageDownKey();
    static void moveTo(DWORD x, DWORD y);
    static void click();
    static void doubleClick();
    static void getCursorPos(int &x, int &y);

private:

};

#endif // BLTHANDLER_H
