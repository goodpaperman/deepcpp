#include <windows.h>

#pragma data_seg(".hwnd")
HWND g_hWnd = NULL; 
#pragma data_seg()
//#pragma comment(linker, "/section:.hwnd, RWS")

HHOOK g_hMouse = NULL; 
HHOOK g_hKeyboard = NULL; 
HHOOK g_hMsg = NULL; 

LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    return 1; 
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if(wParam == VK_F2)
    {
        SendMessage(g_hWnd, WM_CLOSE, 0, 0);         
    }
    return 1; 
}

LRESULT CALLBACK MsgProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    LPMSG pMsg = (LPMSG)lParam; 
    if(pMsg->message == WM_GETTEXT)
    {
        MessageBox(g_hWnd, (LPCTSTR)pMsg->lParam, "Msg", MB_OK); 
    }
    return 0; 
}

void SetHook(HWND hWnd)
{
    g_hWnd = hWnd; 
    //g_hMouse = SetWindowsHookEx(WH_MOUSE, MouseProc, GetModuleHandle("Hook.dll"), 0); 
    //g_hKeyboard = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, GetModuleHandle("Hook"), 0); 
    g_hMsg = SetWindowsHookEx(WH_GETMESSAGE, MsgProc, GetModuleHandle("Hook.dll"), 0); 
}

void UnHook()
{
    if(g_hMouse != NULL)
    {
        UnhookWindowsHookEx(g_hMouse); 
        g_hMouse = NULL; 
    }

    if(g_hKeyboard != NULL)
    {
        UnhookWindowsHookEx(g_hKeyboard); 
        g_hKeyboard = NULL; 
    }
}