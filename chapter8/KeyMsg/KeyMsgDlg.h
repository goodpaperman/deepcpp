// KeyMsgDlg.h : header file
//

#if !defined(AFX_KEYMSGDLG_H__1B933ACE_07BB_4D7D_9BD5_182EC0C85A26__INCLUDED_)
#define AFX_KEYMSGDLG_H__1B933ACE_07BB_4D7D_9BD5_182EC0C85A26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CKeyMsgDlg dialog

class CKeyMsgDlg : public CDialog
{
// Construction
public:
	CKeyMsgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKeyMsgDlg)
	enum { IDD = IDD_KEYMSG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKeyMsgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYMSGDLG_H__1B933ACE_07BB_4D7D_9BD5_182EC0C85A26__INCLUDED_)
