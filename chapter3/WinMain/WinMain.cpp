// WinMain.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "stdio.h"


class CWnd
{
public:
	BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName, DWORD dwStyle, 
		int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam); 
	BOOL ShowWindow(int nCmdShow); 
	BOOL UpdateWindow(); 

public:
	HWND m_hWnd; 
}; 

LRESULT APIENTRY WinSunProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	WNDCLASS wndcls; 
	wndcls.cbClsExtra = 0; 
	wndcls.cbWndExtra = 0; 
	wndcls.hbrBackground =(HBRUSH)GetStockObject(BLACK_BRUSH);  //NULL;
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS); 
	wndcls.hIcon = LoadIcon(NULL, IDI_INFORMATION); 
	wndcls.hInstance = hInstance; 
	wndcls.lpfnWndProc = WinSunProc; 
	wndcls.lpszClassName = "sunxin2006"; 
	wndcls.lpszMenuName = NULL; 
	wndcls.style = CS_HREDRAW | CS_VREDRAW; 
	RegisterClass(&wndcls); 

	CWnd wnd; 
	wnd.CreateEx(0, "sunxin2006", "http://www.sunxin.org", WS_OVERLAPPEDWINDOW, 
		0, 0, 600, 400, NULL, NULL, hInstance, NULL); 
	wnd.ShowWindow(SW_SHOWNORMAL); 
	wnd.UpdateWindow(); 

	MSG msg; 
	while(GetMessage(&msg, NULL, 0, 0))
	{
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
	}

	return msg.wParam; 
}


LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_CHAR:
			char szChar[20]; 
			sprintf(szChar, "char code is %d", wParam); 
			MessageBox(hwnd, szChar, "char", 0); 
			break; 
		case WM_LBUTTONDOWN:
		{
            MessageBox(hwnd, "mouse clicked", "message", 0); 
            HDC hdc = GetDC(hwnd); 
            LPSTR lpszText = "程序员之家"; 
            TextOut(hdc, 0, 50, lpszText, strlen(lpszText)); 
            ReleaseDC(hwnd, hdc); 			            
			break; 
		}
		case WM_PAINT:
		{
            HDC hDC; 
            PAINTSTRUCT ps; 
            hDC = BeginPaint(hwnd, &ps); 
            LPSTR lpszStr = "http://www.sunxin.org"; 
            TextOut(hDC, 0, 0, lpszStr, strlen(lpszStr)); 
            EndPaint(hwnd, &ps); 
			break; 
		}
        case WM_DESTROY:
            PostQuitMessage(0); 
            break; 
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam); 
	}

	return 0; 
}

BOOL CWnd::CreateEx(DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName, DWORD dwStyle, int x, int y, 
					int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	m_hWnd = ::CreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle,
		x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam); 

	return m_hWnd != NULL; 
}

BOOL CWnd::ShowWindow(int nCmdShow)
{
	return ::ShowWindow(m_hWnd, nCmdShow); 
}

BOOL CWnd::UpdateWindow()
{
	return ::UpdateWindow(m_hWnd); 
}