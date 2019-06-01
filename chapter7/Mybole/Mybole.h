// Mybole.h : main header file for the MYBOLE application
//

#if !defined(AFX_MYBOLE_H__B21E0C15_D2C8_4274_AB0C_5AD0290EA25B__INCLUDED_)
#define AFX_MYBOLE_H__B21E0C15_D2C8_4274_AB0C_5AD0290EA25B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyboleApp:
// See Mybole.cpp for the implementation of this class
//

class CMyboleApp : public CWinApp
{
public:
	CMyboleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyboleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyboleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBOLE_H__B21E0C15_D2C8_4274_AB0C_5AD0290EA25B__INCLUDED_)
