#include "blthandler.h"

BltHandler::BltHandler(){

}

void BltHandler::gotoDesktop(){
    keybd_event(VK_LWIN, 0, 0, 0);
    keybd_event(0x44, 0, 0, 0);     // D
    keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);     // D
}

void BltHandler::click(){
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void BltHandler::doubleClick(){
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void BltHandler::mLeftDown(){
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
}

void BltHandler::mLeftUp(){
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void BltHandler::closeWindow(){
    keybd_event(VK_MENU, 0, 0, 0);
    keybd_event(VK_F4, 0, 0, 0);
    keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_F4, 0, KEYEVENTF_KEYUP, 0);
}

void BltHandler::moveTo(DWORD x, DWORD y){
    mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);
}

void BltHandler::pressDownKey(){
    keybd_event(VK_DOWN, 0, 0, 0);
    keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
}

void BltHandler::pressLeftKey(){
    keybd_event(VK_LEFT, 0, 0, 0);
    keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
}

void BltHandler::pressRightKey(){
    keybd_event(VK_RIGHT, 0, 0, 0);
    keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
}

void BltHandler::pressUpKey(){
    keybd_event(VK_UP, 0, 0, 0);
    keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
}


void BltHandler::pressPageDownKey(){
    keybd_event(VK_NEXT, 0, 0, 0);
    keybd_event(VK_NEXT, 0, KEYEVENTF_KEYUP, 0);
}

void BltHandler::pressPageUpKey(){
    keybd_event(VK_PRIOR, 0, 0, 0);
    keybd_event(VK_PRIOR, 0, KEYEVENTF_KEYUP, 0);
}

void BltHandler::getCursorPos(int &x, int &y){
    POINT pt;
    GetCursorPos(&pt);
    x = pt.x;
    y = pt.y;
}
