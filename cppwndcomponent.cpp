#include "cppwndcomponent.h"




int CppWndComponent::getId()
{
    return component.id;
}

HWND CppWndComponent::getHWND()
{
    return component.component;
}
