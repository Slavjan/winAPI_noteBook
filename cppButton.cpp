#include "cppButton.h"


CppButton::CppButton( int x, int y, int width, int height, LPCSTR caption, void(*OnClick)(HWND), HWND hwnd )
{
    cmpnt.component = CreateWindow( "BUTTON", 
                                        caption, 
                                        WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                        x, y, width, height,
                                        hwnd,
                                        ( HMENU )cmpnt.id,
                                        ( HINSTANCE )GetWindowLong(hwnd, GWL_HINSTANCE),
                                        NULL
                                        );
    this->OnClick = OnClick;
}
// maybe you turn on micro?
// are you heard me?

int CppButton::getId() const
{
    return this->getId();
}

HWND CppButton::getHWND() const
{
    return this->getHWND();
}
