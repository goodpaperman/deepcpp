
#include <windows.h>
#include <stdio.h>

DWORD WINAPI SunxinProc(LPVOID lpParam); 
DWORD WINAPI HaihaiProc(LPVOID lpParam); 

int tickets = 100; 
CRITICAL_SECTION g_cs; 

void main()
{
    InitializeCriticalSection(&g_cs); 

    HANDLE hThread1 = CreateThread(NULL, 0, SunxinProc, NULL, 0, NULL); 
    HANDLE hThread2 = CreateThread(NULL, 0, HaihaiProc, NULL, 0, NULL); 
    CloseHandle(hThread1); 
    CloseHandle(hThread2); 

    Sleep(1000); 
    DeleteCriticalSection(&g_cs); 
}

DWORD WINAPI SunxinProc(LPVOID lpParam)
{
    int nCount = 0; 
    while(TRUE)
    {
        EnterCriticalSection(&g_cs); 
        if(tickets > 0)
        {
            //Sleep(1); 
            printf("Sunxin sell ticket[%d].\n", tickets--); 
            nCount ++; 
            LeaveCriticalSection(&g_cs); 
        }
        else 
            break; 
    }

    printf("Sunxin sold tickets total [%d].\n", nCount); 
    LeaveCriticalSection(&g_cs); 
    return 0; 
}

DWORD WINAPI HaihaiProc(LPVOID lpParam)
{
    int nCount = 0; 
    while(TRUE)
    {
        EnterCriticalSection(&g_cs); 
        if(tickets > 0)
        {
            //Sleep(1); 
            printf("Haihai sell ticket[%d].\n", tickets--); 
            nCount ++; 
            LeaveCriticalSection(&g_cs); 
        }
        else 
            break; 
    }

    printf("Haihai sold tickets total [%d].\n", nCount); 
    LeaveCriticalSection(&g_cs); 
    return 0; 
}