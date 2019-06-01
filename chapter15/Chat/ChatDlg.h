// ChatDlg.h : header file
//

#if !defined(AFX_CHATDLG_H__DEAE2F1B_4FF4_4A39_99BA_AE8E1C3D5124__INCLUDED_)
#define AFX_CHATDLG_H__DEAE2F1B_4FF4_4A39_99BA_AE8E1C3D5124__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct RECVPARAM
{
    SOCKET sock; 
    HWND hwnd; 
}; 

#define WM_RECVDATA (WM_USER + 1)

/////////////////////////////////////////////////////////////////////////////
// CChatDlg dialog

class CChatDlg : public CDialog
{
// Construction
public:
	CChatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChatDlg)
	enum { IDD = IDD_CHAT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL


// Implementation
protected:
	HICON m_hIcon;
    SOCKET m_socket; 
    //SOCKET m_socketSend; 
    BOOL InitSocket(); 
    static DWORD WINAPI RecvProc(LPVOID lpParam); 

	// Generated message map functions
	//{{AFX_MSG(CChatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnSend();
	//}}AFX_MSG
    afx_msg void OnRecvData(WPARAM wParam, LPARAM lParam); 
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATDLG_H__DEAE2F1B_4FF4_4A39_99BA_AE8E1C3D5124__INCLUDED_)
