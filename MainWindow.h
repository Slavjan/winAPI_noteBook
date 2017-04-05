#pragma once
// ���������� ���� ������� ��������� ����� ������� ���������� � �������� visual studio
// �� ���� ����������� �� windows.h ����� ������������ �����������.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "LabHelper.h"

class MainWindow {


	static HWND hWnd; // ����� ����
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); // ������� ���������
	static void InitializeComponent(); // �������� ���������� ����������� (������ � �.�.)
	static void CollectFractsAndOperate(char op); // ��������� ������ ������ �� ListBox
	static void HandleEvents(WPARAM wParam); // ��������� ��������, ������������ �� ����

	// ����������
	static PairIdComponent hwndButtonAdd;
	static PairIdComponent hwndButtonSum;
	static PairIdComponent hwndButtonSub;
	static PairIdComponent hwndButtonMul;
	static PairIdComponent hwndButtonDiv;
	static PairIdComponent hwndEdit1;
	static PairIdComponent hwndListBox1;

public:
	// ��������� � ������� ��������� ��������� ���������� ������� WinMain(), ������� ��� ��
	MainWindow(HINSTANCE hInstance, int nCmdShow);
	MSG ListenMessages();
};
