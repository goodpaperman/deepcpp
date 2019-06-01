

//#ifdef DLLPLUS_API
//#else 
#ifndef DLLPLUS_API
//#define DLLPLUS_API _declspec(dllimport)
#define DLLPLUS_API extern "C" _declspec(dllimport)
#endif 

//_declspec(dllimport) int add(int a, int b); 
//_declspec(dllimport) int subtract(int a, int b); 
//DLLPLUS_API int add(int a, int b); 
//DLLPLUS_API int subtract(int a, int b); 
DLLPLUS_API int _stdcall add(int a, int b); 
DLLPLUS_API int _stdcall subtract(int a, int b); 

////class DLLPLUS_API Point
//class Point
//{
//public:
//    //void output(int x, int y); 
//    void DLLPLUS_API output(int x, int y); 
//    void test(); 
//}; 