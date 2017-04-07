#pragma once
// ���������� ���� ������� ��������� ����� ������� ���������� � �������� visual studio
// �� ���� ����������� �� windows.h ����� ������������ �����������.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "LabHelper.h"
#include "cppbutton.h"
//#include "fract.h"

#include <vector>
#include <map>
#include <iterator>

typedef std::vector<CppWndComponent*> �mpList;
typedef std::map<HWND, �mpList > �mpWndAssocationList;

class MainWindow 
{
	static HWND hWnd; // ����� ����
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); // ������� ���������
	void InitializeComponent(); // �������� ���������� ����������� (������ � �.�.)
	static void CollectFractsAndOperate(char op); // ��������� ������ ������ �� ListBox
	static void HandleEvents( HWND hwnd, WPARAM wParam); // ��������� ��������, ������������ �� ����

	// ����������
    static �mpWndAssocationList components;

   // static CppButton *button;

    static void onClick( HWND hwnd );
    
public:
	// ��������� � ������� ��������� ��������� ���������� ������� WinMain(), ������� ��� ��
	MainWindow(HINSTANCE hInstance, int nCmdShow);
    ~MainWindow();

    void addComponent(CppWndComponent* cmp);
    
    HWND getHWND() { return hWnd; }

	MSG ListenMessages();
};
