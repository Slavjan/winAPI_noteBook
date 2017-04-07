#include "cppwndcomponent.h"

CppWndComponent::CppWndComponent() :cmpnt( NULL )//, OnClick(NULL)
{
// @d3i0 мне кажется тут надо выделить память на cmpnt
}

CppWndComponent::CppWndComponent( CppWndComponent & cmp ): cmpnt(cmp.cmpnt), OnClick(cmp.OnClick)
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
