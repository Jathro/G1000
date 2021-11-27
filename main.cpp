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

    HWND hwnd = CreateWindowEx(
        0,                           // Optional window styles.
        CLASS_NAME,                  // Window class
        L"Nano", // Window text
        WS_OVERLAPPEDWINDOW,         // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,      // Parent window
        NULL,      // Menu
        hInstance, // Instance handle
        NULL       // Additional application data
    );

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
    CreateWindowW(L"Button", L"VOL", WS_VISIBLE | WS_CHILD, 42, 25, 30, 30, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"NAV", WS_VISIBLE | WS_CHILD, 42, 80, 30, 30, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"HDG", WS_VISIBLE | WS_CHILD, 42, 135, 30, 30, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"ALT", WS_VISIBLE | WS_CHILD, 42, 360, 30, 30, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"AP", WS_VISIBLE | WS_CHILD, 20, 175, 35, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"FD", WS_VISIBLE | WS_CHILD, 60, 175, 35, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"HDG", WS_VISIBLE | WS_CHILD, 20, 205, 35, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"ALT", WS_VISIBLE | WS_CHILD, 60, 205, 35, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"NAV", WS_VISIBLE | WS_CHILD, 20, 235, 35, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"VNV", WS_VISIBLE | WS_CHILD, 60, 235, 35, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"APR", WS_VISIBLE | WS_CHILD, 20, 265, 35, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"BC", WS_VISIBLE | WS_CHILD, 60, 265, 35, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"VS", WS_VISIBLE | WS_CHILD, 20, 295, 35, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"NUP", WS_VISIBLE | WS_CHILD, 60, 295, 35, 20, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Button", L"FLC", WS_VISIBLE | WS_CHILD, 20, 325, 35, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"NDN", WS_VISIBLE | WS_CHILD, 60, 325, 35, 20, hWnd, NULL, NULL, NULL);

    int j = 12;
    for (int i = 0; i < j; i++)
    {
        CreateWindowW(L"Button", L"\u2BC5", WS_VISIBLE | WS_CHILD, 120 + (i * 40), 360, 30, 30, hWnd, NULL, NULL, NULL);
    }
}