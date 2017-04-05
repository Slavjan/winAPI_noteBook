#include <windows.h>

#include "MainWindow.h"

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInst, LPSTR lpCmdString, int nCmdShow)
{
    //MessageBox(NULL, "Hellow world", "Hellow message", MB_OK);

    MainWindow mw(hInstace, nCmdShow);



    return mw.ListenMessages().wParam;
}