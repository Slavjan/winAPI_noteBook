#include <windows.h>

#include "MainWindow.h"

void onClick( HWND hwnd)
{
    MessageBox( hwnd, "ok button clicked", "ok msg", MB_OK );
}

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInst, LPSTR lpCmdString, int nCmdShow)
{
    //MessageBox(NULL, "Hellow world", "Hellow message", MB_OK);

    MainWindow mw(hInstace, nCmdShow);

 //  CppButton *cb = new CppButton(150, 110, 50, 20, "ok", onClick, mw.getHWND());
 //  mw.addComponent( cb );
   // mw.addComponent( new CppButton( 150, 110, 50, 20, "ok", onClick, mw.getHWND() ) );

    return mw.ListenMessages().wParam;
}