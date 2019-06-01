
#include <windows.h>
#include <stdio.h>
//#include <iostream.h>

//int index = 0; 
int tickets = 100; 
HANDLE hMutex; 

DWORD WINAPI SunxinProc(LPVOID lpParameter); 
DWORD WINAPI HaihaiProc(LPVOID lpParameter); 

void main()
{
    //HANDLE hThread; 
    //hThread = CreateThread(NULL, 0, SunxinProc, NULL, 0, NULL); 
    //CloseHandle(hThread); 
    //while(index ++ < 1000)
    //    cout << "main thread is running" << endl; 

    ////Sleep(10); 

    //hMutex = CreateMutex(NULL, FALSE, NULL); 
    hMutex = CreateMutex(NULL, TRUE, NULL); 
    //WaitForSingleObject(hMutex, INFINITE); 

    HANDLE hThread1 = CreateThread(NULL, 0, SunxinProc, NULL, 0, NULL); 
    HANDLE hThread2 = CreateThread(NULL, 0, HaihaiProc, NULL, 0, NULL); 
    CloseHandle(hThread1); 
    CloseHandle(hThread2); 

    ReleaseMutex(hMutex); 
    ReleaseMutex(hMutex); 
    getchar(); 
    //Sleep(2000); 
}

DWORD WINAPI SunxinProc(LPVOID lpParameter)
{
    WaitForSingleObject(hMutex, INFINITE); 
    printf("Sunxin 是个大傻蛋!\n"); 
    return 0; 
    //while(index ++ < 1000)
    //    cout << "Thread is running." << endl; 
    //return 0; 
    int nCount = 0; 
    while(TRUE)
    {
        WaitForSingleObject(hMutex, INFINITE); 
        if(tickets > 0)
        {
            //Sleep(rand()%300); 
            printf("Sunxin sell ticket: %d\n", tickets--); 
            //cout << "Sunxin sell ticket: " << tickets-- << endl; 
            nCount++; 
        }
        else 
        {
            printf("Sunxin sold tickets total: %d\n", nCount); 
            ReleaseMutex(hMutex); 
            break; 
        }
        ReleaseMutex(hMutex); 
    }

    //cout << "Sunxin sell tickets : " << nCount << endl; 
    return nCount; 
}

DWORD WINAPI HaihaiProc(LPVOID lpParameter)
{
    WaitForSingleObject(hMutex, INFINITE); 
    printf("Yunhai 是个愣货?\n"); 
    return 0; 

    int nCount = 0; 
    while(TRUE)
    {
        WaitForSingleObject(hMutex, INFINITE); 
        if(tickets > 0)
        {
            //Sleep(rand()%300); 
            printf("Haihai sell ticket: %d\n", tickets--); 
            //cout << "Haihai sell ticket: " << tickets-- << endl; 
            nCount ++; 
        }
        else 
        {
            printf("Haihai sold tickets total: %d\n", nCount); 
            ReleaseMutex(hMutex); 
            break; 
        }
        ReleaseMutex(hMutex); 
    }

    //cout << "Haihai sell tickets : " << nCount << endl; 
    return nCount; 
}