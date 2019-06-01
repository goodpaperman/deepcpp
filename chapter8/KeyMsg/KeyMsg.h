// KeyMsg.h : main header file for the KEYMSG application
//

#if !defined(AFX_KEYMSG_H__F2571D9B_89E3_4C51_94DF_643413A70211__INCLUDED_)
#define AFX_KEYMSG_H__F2571D9B_89E3_4C51_94DF_643413A70211__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKeyMsgApp:
// See KeyMsg.cpp for the implementation of this class
//

class CKeyMsgApp : public CWinApp
{
public:
	CKeyMsgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyMsgApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKeyMsgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYMSG_H__F2571D9B_89E3_4C51_94DF_643413A70211__INCLUDED_)
