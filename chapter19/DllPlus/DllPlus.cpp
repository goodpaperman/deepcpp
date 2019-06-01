
//#define DLLPLUS_API _declspec(dllexport) 
#define DLLPLUS_API extern "C" _declspec(dllexport)
#include "DllPlus.h"
#include "windows.h"
#include "stdio.h"

//_declspec(dllexport) 
//int add(int a, int b)
//{
//    return a+b; 
//}
int _stdcall add(int a, int b)
{
    return a+b; 
}

//_declspec(dllexport)
//int subtract(int a, int b)
//{
//    return a-b; 
//}
int _stdcall subtract(int a, int b)
{
    return a-b; 
}

//void Point::output(int x, int y)
//{
//    HWND hWnd = GetForegroundWindow(); 
//    HDC hdc = GetDC(hWnd); 
//    char buf[100]; 
//    memset(buf, 0, 100); 
//    sprintf(buf, "x=%d, y=%d", x, y); 
//    TextOut(hdc, 0, 0, buf, strlen(buf)); 
//    ReleaseDC(hWnd, hdc); 
//}

//void Point::test()
//{
//}