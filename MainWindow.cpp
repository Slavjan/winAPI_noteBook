#include "MainWindow.h"

СmpWndAssocationList MainWindow::components;
HWND MainWindow::hWnd = NULL;

void MainWindow::onClick( HWND hwnd )
{
    MessageBox( hwnd, "ok button clicked", "ok msg", MB_OK );
}

MainWindow::MainWindow( HINSTANCE hInstance, int nCmdShow )
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
    wcl.hbrBackground = ( HBRUSH )GetStockObject( WHITE_BRUSH ); // белый цвет фона

    if( !RegisterClass( &wcl ) ) // try to register window class
        return;

    // positioning window
    HDC scrDC = GetDC( NULL );
    // taking screen size
    int scrWidth = GetDeviceCaps( scrDC, HORZRES ),
        scrHeight = GetDeviceCaps( scrDC, VERTRES );
    // taking screen center
    int scrHCenter = scrWidth / 2,
        scrVCenter = scrHeight / 2;
    // setting window size
    int wndHSize = 230,
        wndVSize = 180;
    // calculating window`s left, top angle coordinates
    int wndX = scrHCenter - wndHSize / 2,
        wndY = scrVCenter - wndVSize / 2;

    hWnd = CreateWindow( szClassName,
                         "Fract Calculator", WS_OVERLAPPEDWINDOW |
                         WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
                         wndX,
                         wndY,
                         wndHSize,
                         wndVSize,
                         HWND_DESKTOP,
                         NULL,
                         hInstance,
                         NULL );

    if( !hWnd )
        return;

    InitializeComponent();
    // отображаем окно
    ShowWindow( hWnd, nCmdShow );
    UpdateWindow( hWnd );
}

MainWindow::~MainWindow()
{
    for( СmpWndAssocationList::iterator i = components.begin(); i != components.end(); i++ ){
        for( СmpList::iterator j = ( i->second ).begin(); j != ( i->second ).end(); j++ ){
            delete *j;
        }
    }
}

void MainWindow::InitializeComponent()
{
    addComponent( new CppButton( 150, 110, 50, 20, "ok", &MainWindow::onClick, hWnd ) );
}

void MainWindow::addComponent( CppWndComponent* cmp )
{
    //cmp->OnClick(hWnd);
    components[hWnd].push_back( cmp );
}

MSG MainWindow::ListenMessages()
{
    MSG msg;

    while( GetMessage( &msg, NULL, 0, 0 ) ){
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }
    return msg;
}

LRESULT MainWindow::WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    switch( uMsg ){
    case WM_DESTROY:
        PostQuitMessage( EXIT_SUCCESS );
        break;
    case WM_COMMAND:
        HandleEvents( hWnd, wParam);
        break;
    default:
        return DefWindowProc( hWnd, uMsg, wParam, lParam );
    }
    return wParam;
}


void MainWindow::HandleEvents( HWND hwnd, WPARAM wParam )
{
    void( *hendler )(HWND);
  //  auto i = 0;
    auto l = LOWORD( wParam );
    auto h = HIWORD( wParam );
    

  //  hendler = NULL;
   
   // while( hendler == NULL ){
    for( size_t i = 0; i < components[hwnd].size(); i++ ){
        auto id = components[hwnd][i]->getId();
        if( components[hwnd][i]->getId() == LOWORD( wParam ) ){
            switch( HIWORD( wParam ) ){
            case BN_CLICKED:
            case LBN_DBLCLK:
                hendler = components[hwnd][i]->OnClick;
            break;
            default:
                hendler = NULL;
            }
            if( hendler != NULL)
                hendler(hwnd);
            break;
        }
       // i++;
    }
    //hendler();
}

