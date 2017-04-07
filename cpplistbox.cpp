#include "cpplistbox.h"

CppListbox::CppListbox( HWND hwnd, int left, int top, int width, int height, void( *OnEventCallback )( HWND ) )
{
    cmpnt.component = CreateWindow("LISTBOX",
                                        NULL,
                                        ( WS_CHILD | WS_VISIBLE | LBS_STANDARD ) ^ LBS_SORT, // sorting OFF
                                        left, top, width, height,
                                        hwnd, 
                                        ( HMENU )cmpnt.id,
                                        ( HINSTANCE )GetWindowLong( hwnd, GWL_HINSTANCE ),
                                        NULL );
    this->OnClick = OnEventCallback;
}

int CppListbox::getId() const
{
    return this->getId();
}

HWND CppListbox::getHWND() const
{
    return this->getHWND();
}