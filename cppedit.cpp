#include "cppedit.h"

CppEdit::CppEdit( HWND hwnd, int left, int top, int width, int height, void( *OnEventCallback )( HWND ) )
{
    this->cmpnt.component = CreateWindow( "EDIT",
                                          NULL,
                                          WS_BORDER | WS_VISIBLE | WS_CHILD | ES_LEFT | ES_MULTILINE,
                                          left, top, width, height,
                                          hwnd,
                                          ( HMENU )cmpnt.id,
                                          NULL,
                                          NULL);
    this->OnClick = OnEventCallback;
}

int CppEdit::getId() const
{
    return this->getId();
}

HWND CppEdit::getHWND() const
{
    return this->getHWND();
}