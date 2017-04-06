#ifndef CPPBUTTON_H
#define CPPBUTTON_H

#include "cppwndcomponent.h"

class CppButton : CppWndComponent
{
public:
    CppButton(int x, int y, int width, int height, LPCSTR caption, void(*OnClick)(), HWND hwnd );

    int getId();
    HWND getHWND();
};

#endif