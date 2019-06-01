// File.h : main header file for the FILE application
//

#if !defined(AFX_FILE_H__401CEDD8_24DF_4DE7_A1AA_B02526C62375__INCLUDED_)
#define AFX_FILE_H__401CEDD8_24DF_4DE7_A1AA_B02526C62375__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileApp:
// See File.cpp for the implementation of this class
//

class CFileApp : public CWinApp
{
public:
	CFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFileApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILE_H__401CEDD8_24DF_4DE7_A1AA_B02526C62375__INCLUDED_)
