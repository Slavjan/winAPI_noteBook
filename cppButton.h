#ifndef CPPBUTTON_H
#define CPPBUTTON_H

#include "cppwndcomponent.h"

class CppButton : public CppWndComponent
{
public:
    CppButton(int x, int y, int width, int height, LPCSTR caption, void(*OnClick)(HWND), HWND hwnd );

    int getId() const;
    HWND getHWND() const;
};

#endif