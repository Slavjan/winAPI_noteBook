#pragma once
// написанна€ ниже строчка позвол€ет более быструю компил€цию и загрузку visual studio
// за счЄт выкидывани€ из windows.h редко используемых компонентов.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "LabHelper.h"

class MainWindow {


	static HWND hWnd; // хэндл окна
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); // оконна€ процедура
	static void InitializeComponent(); // создание визуальных компонентов (кнопок и т.д.)
	static void CollectFractsAndOperate(char op); // обработка списка дробей из ListBox
	static void HandleEvents(WPARAM wParam); // обработка действий, произошедших на окне

	// компоненты
	static PairIdComponent hwndButtonAdd;
	static PairIdComponent hwndButtonSum;
	static PairIdComponent hwndButtonSub;
	static PairIdComponent hwndButtonMul;
	static PairIdComponent hwndButtonDiv;
	static PairIdComponent hwndEdit1;
	static PairIdComponent hwndListBox1;

public:
	// поскольку в лекци€х приведено требуемое содержание функции WinMain(), сделано под неЄ
	MainWindow(HINSTANCE hInstance, int nCmdShow);
	MSG ListenMessages();
};
