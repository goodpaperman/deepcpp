// KeyMsg.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "KeyMsg.h"
#include "KeyMsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKeyMsgApp

BEGIN_MESSAGE_MAP(CKeyMsgApp, CWinApp)
	//{{AFX_MSG_MAP(CKeyMsgApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyMsgApp construction

CKeyMsgApp::CKeyMsgApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CKeyMsgApp object

CKeyMsgApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CKeyMsgApp initialization

BOOL CKeyMsgApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CKeyMsgDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

BOOL CKeyMsgApp::ProcessMessageFilter(int code, LPMSG lpMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	
    HWND hDlg = AfxGetMainWnd()->GetSafeHwnd(); 
    //if(hDlg != NULL)
    //{
    //    if(lpMsg->message == WM_KEYDOWN)
    //    {
    //        if(lpMsg->hwnd == hDlg || ::IsChild(hDlg, lpMsg->hwnd))
    //        {
    //            AfxMessageBox("Key Down"); 
    //            return 1; 
    //        }
    //    }
    //}
    if(hDlg != NULL && (lpMsg->hwnd == hDlg || ::IsChild(hDlg, lpMsg->hwnd)) && lpMsg->message == WM_KEYDOWN)
    {
        SendMessage(hDlg, lpMsg->message, lpMsg->wParam, lpMsg->lParam); 
        return 1; 
    }

	return CWinApp::ProcessMessageFilter(code, lpMsg);
}
