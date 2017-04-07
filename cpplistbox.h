#pragma once
#include "cppwndcomponent.h"
class CppListbox :
    public CppWndComponent
{
public:
    CppListbox( HWND hwnd, int left, int top, int width, int height, void( *OnClickCallback )( HWND ) );

    int getId() const;
    HWND getHWND() const;
};

