#include "cppButton.h"


CppButton::CppButton( int x, int y, int width, int height, LPCSTR caption, void(*OnClick)(), HWND hwnd )
{
    component.component = CreateWindow( "BUTTON", 
                                        caption, 
                                        WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                        x, y, width, height,
                                        hwnd,
                                        ( HMENU )component.id,
                                        ( HINSTANCE )GetWindowLong(hwnd, GWL_HINSTANCE),
                                        NULL
                                        );
    OnClick = OnClick;
}

int CppButton::getId()
{
    return this->getId();
}

HWND CppButton::getHWND()
{
    return this->getHWND();
}
