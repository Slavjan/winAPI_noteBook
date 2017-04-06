#pragma once
// написанная ниже строчка позволяет более быструю компиляцию и загрузку visual studio
// за счёт выкидывания из windows.h редко используемых компонентов.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "LabHelper.h"
#include "cppbutton.h"
//#include "fract.h"

#include <vector>
#include <map>
#include <iterator>

typedef std::vector<CppWndComponent*> СmpList;
typedef std::map<int, СmpList > СmpWndAssocationList;

class MainWindow 
{
	static HWND hWnd; // хэндл окна
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); // оконная процедура
	static void InitializeComponent(); // создание визуальных компонентов (кнопок и т.д.)
	static void CollectFractsAndOperate(char op); // обработка списка дробей из ListBox
	static void HandleEvents(WPARAM wParam); // обработка действий, произошедших на окне

	// компоненты
    static СmpWndAssocationList components;

   // static CppButton *button;

    static void onClick();

private:
    PairIdComponent *window;

public:
	// поскольку в лекциях приведено требуемое содержание функции WinMain(), сделано под неё
	MainWindow(HINSTANCE hInstance, int nCmdShow);
    ~MainWindow();

    void addComponent(CppWndComponent* cmp);
    
    HWND getHWND() { return hWnd; }

	MSG ListenMessages();
};
