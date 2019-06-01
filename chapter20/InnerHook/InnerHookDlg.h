// InnerHookDlg.h : header file
//

#if !defined(AFX_INNERHOOKDLG_H__C6189604_0BA7_4A47_9ED9_C16D059E64C4__INCLUDED_)
#define AFX_INNERHOOKDLG_H__C6189604_0BA7_4A47_9ED9_C16D059E64C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CInnerHookDlg dialog

class CInnerHookDlg : public CDialog
{
// Construction
public:
	CInnerHookDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CInnerHookDlg)
	enum { IDD = IDD_INNERHOOK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInnerHookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CInnerHookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INNERHOOKDLG_H__C6189604_0BA7_4A47_9ED9_C16D059E64C4__INCLUDED_)
