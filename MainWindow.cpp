#include "MainWindow.h"

ÑmpWndAssocationList MainWindow::components;
HWND MainWindow::hWnd = NULL;

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
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // áåëûé öâåò ôîíà

	if(!RegisterClass(&wcl)) // try to register window class
		return;

     // positioning window
    HDC scrDC = GetDC(NULL);     
        // taking screen size
    int scrWidth = GetDeviceCaps(scrDC, HORZRES),
        scrHeight = GetDeviceCaps(scrDC, VERTRES);
        // taking screen center
    int scrHCenter = scrWidth / 2,
        scrVCenter = scrHeight / 2;
        // setting window size
    int wndHSize = 230,
        wndVSize = 180;
        // calculating window`s left, top angle coordinates
    int wndX = scrHCenter - wndHSize/2,
        wndY = scrVCenter - wndVSize/2;
    
	hWnd = CreateWindow(szClassName, 
                        "Fract Calculator", WS_OVERLAPPEDWINDOW|
                         WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
                         wndX, 
                         wndY, 
                         wndHSize, 
                         wndVSize, 
                         HWND_DESKTOP, 
                         NULL, 
                         hInstance, 
                         NULL);
    
	if(!hWnd) 
        return;

	// îòîáðàæàåì îêíî
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
}

MainWindow::~MainWindow()
{       
    for( ÑmpWndAssocationList::iterator i = components.begin(); i != components.end(); i++ ){
        for( ÑmpList::iterator j = ( i->second ).begin(); j != ( i->second ).end(); j++ ){
            delete *j;
        }
    }
}

void MainWindow::addComponent( CppWndComponent * cmp )
{
    components[window->id].push_back(cmp);
}

MSG MainWindow::ListenMessages() 
{
	MSG msg;

	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg;
}

LRESULT MainWindow::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{	
    switch (uMsg) 
    {
	case WM_DESTROY:
		PostQuitMessage(EXIT_SUCCESS);
	break;
	case WM_COMMAND:
		HandleEvents(wParam);
	break;
	default: 
        return DefWindowProc( hWnd, uMsg, wParam, lParam );
	}
	return wParam;
}


void MainWindow::HandleEvents(WPARAM wParam) {

    
}

