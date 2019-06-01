
#include <windows.h>
//#include <iostream.h>
#include <stdio.h>

DWORD WINAPI SunxinProc(LPVOID lpParam); 
DWORD WINAPI HaihaiProc(LPVOID lpParam); 

int tickets = 100; 
HANDLE g_hEvent; 

void main()
{
    //g_hEvent = CreateEvent(NULL, TRUE, TRUE, NULL); 
    //g_hEvent = CreateEvent(NULL, TRUE, FALSE, NULL); 
    //g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL); 
    g_hEvent = CreateEvent(NULL, FALSE, FALSE, "Sell Tickets"); 
    if(g_hEvent != NULL && GetLastError() == ERROR_ALREADY_EXISTS)
    {
        printf("The only instance is running...\n"); 
        return; 
    }    

    HANDLE hThread1 = CreateThread(NULL, 0, SunxinProc, NULL, 0, NULL); 
    HANDLE hThread2 = CreateThread(NULL, 0, HaihaiProc, NULL, 0, NULL); 
    CloseHandle(hThread1); 
    CloseHandle(hThread2); 

    SetEvent(g_hEvent); 
    Sleep(2000); 
    CloseHandle(g_hEvent); 
}

DWORD WINAPI SunxinProc(LPVOID lpParam)
{
    int nCount = 0; 
    while(TRUE)
    {
        WaitForSingleObject(g_hEvent, INFINITE); 
        //ResetEvent(g_hEvent); 
        if(tickets > 0)
        {
            //Sleep(1); 
            printf("Sunxin sell ticket[%d].\n", tickets--); 
            nCount ++; 
            SetEvent(g_hEvent); 
        }
        else 
            break; 
    }

    printf("Sunxin sold tickets total [%d].\n", nCount); 
    SetEvent(g_hEvent); 
    return 0; 
}

DWORD WINAPI HaihaiProc(LPVOID lpParam)
{
    int nCount = 0; 
    while(TRUE)
    {
        WaitForSingleObject(g_hEvent, INFINITE); 
        //ResetEvent(g_hEvent); 
        if(tickets > 0)
        {
            //Sleep(1); 
            printf("Haihai sell ticket[%d].\n", tickets--); 
            nCount ++; 
            SetEvent(g_hEvent); 
        }
        else 
            break; 
    }

    printf("Haihai sold tickets total [%d].\n", nCount); 
    SetEvent(g_hEvent); 
    return 0; 
}