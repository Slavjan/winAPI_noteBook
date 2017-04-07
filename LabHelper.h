#ifndef LABHELPER_H
#define LABHELPER_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <iostream>
#include <sstream>

// из лекций:
struct PairIdComponent {
	PairIdComponent(HWND hwnd) {
		component = hwnd;
		id = count++;
	}
	int id;
	HWND component;
private:
	static int count;
};

class LabHelper
{
public:
    static std::string IntToString( int value );
    static int StrToInt( std::string str );

private:
    LabHelper();
};

#endif