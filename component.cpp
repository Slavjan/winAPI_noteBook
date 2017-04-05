#include "component.h"


int Component::getId()
{
    return component.id;
}

HWND Component::getHWND()
{
    return component.component;
}
