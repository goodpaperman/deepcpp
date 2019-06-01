#if !defined(AFX_TESTDLG_H__78A637A9_244A_4437_86C9_AAEC485DF369__INCLUDED_)
#define AFX_TESTDLG_H__78A637A9_244A_4437_86C9_AAEC485DF369__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

class CTestDlg : public CDialog
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_edit3;
	CEdit	m_edit2;
	CEdit	m_edit1;
	//}}AFX_DATA
    //int        m_num1;
    //int        m_num2;
    //int        m_num3;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual void OnOK();
	virtual void OnCancel();
    CButton m_btn;

	// Generated message map functions
	//{{AFX_MSG(CTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnAdd();
	afx_msg void OnNumber1();
	afx_msg void OnBtnShrink();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__78A637A9_244A_4437_86C9_AAEC485DF369__INCLUDED_)
