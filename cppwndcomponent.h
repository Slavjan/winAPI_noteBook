#ifndef COMPONENT_H
#define COMPONENT_H

#include "LabHelper.h"

class CppWndComponent
{
protected:
    PairIdComponent component;

    CppWndComponent():component(NULL)
    {
    }

public:
   // CppWndComponent( CppWndComponent* cmp );
    
    int getId();
    HWND getHWND();
    void(*OnClick)();
    
};

#endif