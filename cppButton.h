#ifndef CPPBUTTON_H
#define CPPBUTTON_H

#include "component.h"

class CppButton :
    public Component
{
public:
    CppButton(int x, int y, int width, int height, LPCSTR caption, void( *OnClickCallback ), HWND hwnd );
};

#endif