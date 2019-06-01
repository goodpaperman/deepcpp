#if !defined(AFX_CLOCK_H__E72A639D_8ED8_42DB_84F2_C972D16EE55B__INCLUDED_)
#define AFX_CLOCK_H__E72A639D_8ED8_42DB_84F2_C972D16EE55B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Clock.h : main header file for CLOCK.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CClockApp : See Clock.cpp for implementation.

class CClockApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCK_H__E72A639D_8ED8_42DB_84F2_C972D16EE55B__INCLUDED)
