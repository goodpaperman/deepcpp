// Style.h : main header file for the STYLE application
//

#if !defined(AFX_STYLE_H__1CC1FCF9_FDC9_4287_A706_8A44DED9FBAD__INCLUDED_)
#define AFX_STYLE_H__1CC1FCF9_FDC9_4287_A706_8A44DED9FBAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStyleApp:
// See Style.cpp for the implementation of this class
//

class CStyleApp : public CWinApp
{
public:
	CStyleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStyleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStyleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STYLE_H__1CC1FCF9_FDC9_4287_A706_8A44DED9FBAD__INCLUDED_)
