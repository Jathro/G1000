#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void AddControls(HWND hWnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"G1000", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);

    AddControls(hwnd);

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 2));

        EndPaint(hwnd, &ps);
    }
    return 0;
    case WM_CLOSE:
        if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
        {
            DestroyWindow(hwnd);
        }
        // Else: User canceled. Do nothing.
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void AddControls(HWND hWnd)
{
    const int SMALL_BUTTON_WIDTH = 35;
    const int DIAL_SIZE = 30;

    CreateWindowW(L"Button", L"VOL", WS_VISIBLE | WS_CHILD, 42, 25, DIAL_SIZE, DIAL_SIZE, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"NAV", WS_VISIBLE | WS_CHILD, 42, 80, DIAL_SIZE, DIAL_SIZE, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"HDG", WS_VISIBLE | WS_CHILD, 42, 135, DIAL_SIZE, DIAL_SIZE, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"ALT", WS_VISIBLE | WS_CHILD, 42, 360, DIAL_SIZE, DIAL_SIZE, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"AP", WS_VISIBLE | WS_CHILD, 20, 175, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"FD", WS_VISIBLE | WS_CHILD, 60, 175, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"HDG", WS_VISIBLE | WS_CHILD, 20, 205, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"ALT", WS_VISIBLE | WS_CHILD, 60, 205, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"NAV", WS_VISIBLE | WS_CHILD, 20, 235, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"VNV", WS_VISIBLE | WS_CHILD, 60, 235, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"APR", WS_VISIBLE | WS_CHILD, 20, 265, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"BC", WS_VISIBLE | WS_CHILD, 60, 265, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"VS", WS_VISIBLE | WS_CHILD, 20, 295, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"NUP", WS_VISIBLE | WS_CHILD, 60, 295, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"FLC", WS_VISIBLE | WS_CHILD, 20, 325, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"NDN", WS_VISIBLE | WS_CHILD, 60, 325, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"COM", WS_VISIBLE | WS_CHILD, 640, 25, DIAL_SIZE, DIAL_SIZE, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"CRS", WS_VISIBLE | WS_CHILD, 640, 80, DIAL_SIZE, DIAL_SIZE, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"RNG", WS_VISIBLE | WS_CHILD, 640, 135, DIAL_SIZE, DIAL_SIZE, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"FMS", WS_VISIBLE | WS_CHILD, 640, 360, DIAL_SIZE, DIAL_SIZE, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"ENT", WS_VISIBLE | WS_CHILD, 620, 265, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"MENU", WS_VISIBLE | WS_CHILD, 660, 265, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"PPL", WS_VISIBLE | WS_CHILD, 620, 295, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"PROG", WS_VISIBLE | WS_CHILD, 660, 295, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"CLR", WS_VISIBLE | WS_CHILD, 620, 325, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"EXT", WS_VISIBLE | WS_CHILD, 660, 325, SMALL_BUTTON_WIDTH, 20, hWnd, NULL, NULL, NULL);

    int j = 12;
    for (int i = 0; i < j; i++)
    {
        CreateWindowW(L"Button", L"\u2BC5", WS_VISIBLE | WS_CHILD, 120 + (i * 40), 360, 30, 30, hWnd, NULL, NULL, NULL);
    }
}