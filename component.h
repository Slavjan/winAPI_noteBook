#ifndef COMPONENT_H
#define COMPONENT_H

#include "LabHelper.h"

class Component
{
protected:
    PairIdComponent component;

    Component():component(NULL)
    {
    }

public:
    
    int getId();
    HWND getHWND();
    void( *OnClick );
    
};

#endif