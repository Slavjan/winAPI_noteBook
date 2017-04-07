#ifndef COMPONENT_H
#define COMPONENT_H

#include "LabHelper.h"

class CppWndComponent
{
protected:
    PairIdComponent cmpnt;
    CppWndComponent();
    CppWndComponent( CppWndComponent& cmp );

public:
    virtual ~CppWndComponent();

    int getId() const;
    HWND getHWND();

    void(*OnClick)(HWND);
    
};

#endif