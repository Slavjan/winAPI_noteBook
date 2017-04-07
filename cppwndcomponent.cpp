#include "cppwndcomponent.h"

CppWndComponent::CppWndComponent() :cmpnt( NULL )
{
}


CppWndComponent::~CppWndComponent()
{
}

int CppWndComponent::getId() const
{
    return cmpnt.id;
}

HWND CppWndComponent::getHWND()
{
    return cmpnt.component;
}
