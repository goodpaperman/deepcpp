
#include <windows.h>
#include <stdio.h>
#include "resource.h"

LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASS wndcls; 
	wndcls.cbClsExtra = 0; 
	wndcls.cbWndExtra = 0; 
	wndcls.hbrBackground =(HBRUSH)GetStockObject(BLACK_BRUSH);  //NULL;
	wndcls.hCursor = NULL; //LoadCursor(NULL, IDC_CROSS); 
	wndcls.hIcon = NULL; //LoadIcon(NULL, IDI_ERROR); 
	wndcls.hInstance = hInstance; 
	wndcls.lpfnWndProc = WinSunProc; 
	wndcls.lpszClassName = "sunxin2006"; 
	wndcls.lpszMenuName = MAKEINTRESOURCE(IDR_MENU_MAIN); //NULL; 
	wndcls.style = 0; //CS_NOCLOSE; //CS_HREDRAW | CS_VREDRAW; 
	RegisterClass(&wndcls); 

	HWND hwnd; 
	hwnd = CreateWindow("sunxin2006", "http://www.sunxin.org", WS_OVERLAPPEDWINDOW, 
		0, 0, 600, 400, NULL, NULL, hInstance, NULL); 
	
	ShowWindow(hwnd, SW_SHOWNORMAL); 
	UpdateWindow(hwnd); 
	//InvalidateRect(hwnd, NULL, TRUE); 

	MSG msg; 
	while(GetMessage(&msg, NULL, 0, 0))//hwnd, 0, 0)) //NULL, 0, 0))
	{
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
		//WinSunProc(hwnd, msg.message, msg.wParam, msg.lParam); 
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
			            
            //HDC hDC; 
            //PAINTSTRUCT ps; 
            //hDC = BeginPaint(hwnd, &ps); 
            //LPSTR lpszStr = "http://www.sunxin.org"; 
            //TextOut(hDC, 0, 0, lpszStr, strlen(lpszStr)); 
            //EndPaint(hwnd, &ps); 
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

            //HDC hdc = GetDC(hwnd); 
            //LPSTR lpszText = "程序员之家"; 
            //TextOut(hdc, 0, 50, lpszText, strlen(lpszText)); 
            //ReleaseDC(hwnd, hdc); 
			break; 
		}
        //case WM_CLOSE:
        //    if(MessageBox(hwnd, "是否真的结束?", "message", MB_YESNO) == IDYES)
        //        DestroyWindow(hwnd); 
        //    break; 
        case WM_DESTROY:
            PostQuitMessage(0); 
            break; 
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam); 
	}

	return 0; 
}