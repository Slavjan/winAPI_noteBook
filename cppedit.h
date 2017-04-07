#ifndef CPPEDIT_H
#define CPPEDIT_H
#include "cppwndcomponent.h"

class CppEdit : public CppWndComponent
{
public:
    CppEdit( HWND hwnd, int left, int top, int width, int height, void( *OnEventCallback )( HWND ) );

    int getId() const;
    HWND getHWND() const;
};

#endif