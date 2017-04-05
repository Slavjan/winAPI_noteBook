#include "MainWindow.h"


const int BUFSIZE = 128;
char buf[BUFSIZE];

MainWindow::MainWindow(HINSTANCE hInstance, int nCmdShow) 
{

	WNDCLASS wcl;
	LPSTR szClassName = "SampleClass33"; 
	wcl.hInstance = hInstance; 
	wcl.lpszClassName = szClassName; 
	wcl.lpfnWndProc = WndProc; 
	wcl.style = CS_VREDRAW | CS_HREDRAW;
	wcl.hIcon = NULL; 
	wcl.hCursor = NULL; 
	wcl.lpszMenuName = NULL;
	wcl.cbClsExtra = NULL;
	wcl.cbWndExtra = NULL;
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ����� ���� ����

	if(!RegisterClass(&wcl)) // try to register window class
		return;

	hWnd = CreateWindow(szClassName, 
                        "Fract Calculator", WS_OVERLAPPEDWINDOW|
                         WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
                         CW_USEDEFAULT, 
                         CW_USEDEFAULT, 
                         230, 
                         180, 
                         HWND_DESKTOP, 
                         NULL, 
                         hInstance, 
                         NULL);

	if(!hWnd) return;

	InitializeComponent();
	// ���������� ����
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
}

MSG MainWindow::ListenMessages() {
	// ����������� ���� ��������� ���������
	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg;
}

LRESULT MainWindow::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		// case WM_PAINT �� �����, �.�. ������� ������ �� ������
		case WM_DESTROY:
			PostQuitMessage(EXIT_SUCCESS);
		break;
		case WM_COMMAND:
			HandleEvents(wParam);
		break;
		default: return DefWindowProc(hWnd, uMsg, wParam, lParam); //break; // ����� �� ������
	}
	return wParam;
}

void MainWindow::InitializeComponent() {
	// �������, � ������� ��������� �������� ���� ���������� �����������
    
    RECT rect;
    GetWindowRect(hWnd, &rect);

    int height = rect.bottom - rect.top;
    int windh = rect.right - rect.left;

	hwndButtonAdd.component = CreateWindow("BUTTON", // ��� ������ (�� ��� ��������������� � ��������)
		                                   "OK",  // �����
		                                   WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, //�����
		                                   150, 110, 50, 20, // ���������� � ������
		                                   hWnd, // ����� ����
		                                   HMENU(hwndButtonAdd.id), // id ��������
                                           (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), // hInstance
		                                   NULL); // ��������� �������� ��� �� �����
	
	hwndButtonSum.component = CreateWindow("BUTTON",
		                                   "+",
		                                   WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		                                   150, 10, 50, 23,
		                                   hWnd,
		                                   HMENU(hwndButtonSum.id),
		                                   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		                                   NULL);

	hwndButtonSub.component = CreateWindow("BUTTON",
		                                   "-",
		                                   WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		                                   150, 35, 50, 23,
		                                   hWnd,
		                                   HMENU(hwndButtonSub.id),
		                                   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		                                   NULL);

	hwndButtonMul.component = CreateWindow("BUTTON",
		                                   "*",
		                                   WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		                                   150, 60, 50, 23,
		                                   hWnd,
		                                   HMENU(hwndButtonMul.id),
		                                   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		                                   NULL);

	hwndButtonDiv.component = CreateWindow("BUTTON",
		                                   "/",
		                                   WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		                                   150, 85, 50, 23,
		                                   hWnd,
		                                   HMENU(hwndButtonDiv.id),
		                                   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		                                   NULL);

	hwndListBox1.component = CreateWindow("LISTBOX", 
		                                  NULL, 
		                                  WS_CHILD|WS_VISIBLE|LBS_STANDARD, 
		                                  10, 10, 130, 100, 
		                                  hWnd, 
		                                  (HMENU)hwndListBox1.id, 
		                                  NULL, 
		                                  NULL);

	hwndEdit1.component = CreateWindow("EDIT",
		                               NULL,
		                               WS_BORDER|WS_VISIBLE|WS_CHILD|ES_LEFT|ES_MULTILINE,
		                               10, 110, 130, 20,
		                               hWnd,
		                               (HMENU)hwndEdit1.id,
		                               NULL,
		                               NULL);
}

void MainWindow::CollectFractsAndOperate(char op) {
    
	int count = SendMessage(hwndListBox1.component, LB_GETCOUNT, 0, 0); // ���������� ��������� � ListBox
	if(count == 0) {
			MessageBox(hWnd, "������ ������ ����", NULL, MB_OK);
			return;
	}
	//SendMessage(hwndListBox1.component, LB_GETTEXT, 0, (LPARAM)buf); // ���� ������ ����� � ������
	//Fract fract1 = Fract(std::string(buf));
	//for(int i = 1; i < count; i++) { // ���� ������ �� ����������
	//	SendMessage(hwndListBox1.component, LB_GETTEXT, i, (LPARAM)buf); // ���� ��������� �����
	//	Fract fract2 = Fract(std::string(buf));
	//	switch(op) { // ������: fract1 = fract1 �������� fract2
	//		case '+': fract1 = Fract::Sum(fract1, fract2); break;
	//		case '-': fract1 = Fract::Sub(fract1, fract2); break;
	//		case '*': fract1 = Fract::Mul(fract1, fract2); break;
	//		case '/': fract1 = Fract::Div(fract1, fract2); break;
	//		default: MessageBox(hWnd, "������ ����������� ��������� ��������", NULL, MB_OK); break;
	//	}
	//}
	// ������� ��������� ���� ��������
	/*std::string out = fract1.toString();
	MessageBox(hWnd, out.c_str(), "���������", MB_OK);*/
}

void MainWindow::HandleEvents(WPARAM wParam) {
	// �������, � ������� ��������� �������� �� ������� ����-������ �� ����
	if(LOWORD(wParam) == hwndButtonAdd.id && HIWORD(wParam) == BN_CLICKED) {
		// ButtonAdd.OnClick(); ���������� �������� � Edit ����� � ListBox
		GetDlgItemText(hWnd, hwndEdit1.id, buf, BUFSIZE);
		//if(!Fract::IsFractString(buf)) { // ���� �� �����
			MessageBox(hWnd, "������� ����� � ������� %d/%d", NULL, MB_OK);
			return;
		//}
		SendMessage(hwndListBox1.component, LB_ADDSTRING, 0, (LPARAM)buf);

	}

	if(LOWORD(wParam) == hwndButtonSum.id && HIWORD(wParam) == BN_CLICKED) {
		// ButtonSum.OnClick(); �������� ���� ������ � ������
		CollectFractsAndOperate('+');
	}

	if(LOWORD(wParam) == hwndButtonSub.id && HIWORD(wParam) == BN_CLICKED) {
		// ButtonSub.OnClick(); ��������� ���� ������ �� ������
		CollectFractsAndOperate('-');
	}

	if(LOWORD(wParam) == hwndButtonMul.id && HIWORD(wParam) == BN_CLICKED) {
		// ButtonMul.OnClick(); ������������ ���� ������ � ������
		CollectFractsAndOperate('*');
	}

	if(LOWORD(wParam) == hwndButtonDiv.id && HIWORD(wParam) == BN_CLICKED) {
		// ButtonDiv.OnClick(); ������� ������ ����� �� ��� ���������
		CollectFractsAndOperate('/');
	}

	if(LOWORD(wParam) == hwndListBox1.id && HIWORD(wParam) == LBN_DBLCLK) {
		// ListBox1.OnDblClick(); ������� ��������� ����� �� ������
		int cur = SendMessage(hwndListBox1.component, LB_GETCURSEL, 0, 0);
		SendMessage(hwndListBox1.component, LB_DELETESTRING, cur, 0);
	}
}

HWND MainWindow::hWnd = NULL;
// ������������� ����������� ����������. oh, shi~
PairIdComponent MainWindow::hwndButtonAdd = PairIdComponent(NULL);
PairIdComponent MainWindow::hwndButtonSum = PairIdComponent(NULL);
PairIdComponent MainWindow::hwndButtonSub = PairIdComponent(NULL);
PairIdComponent MainWindow::hwndButtonMul = PairIdComponent(NULL);
PairIdComponent MainWindow::hwndButtonDiv = PairIdComponent(NULL);
PairIdComponent MainWindow::hwndEdit1 = PairIdComponent(NULL);
PairIdComponent MainWindow::hwndListBox1 = PairIdComponent(NULL);