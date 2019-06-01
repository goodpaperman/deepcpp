// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Mybole.h"
#include "TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog


CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
	//}}AFX_DATA_INIT
    //m_num1 = 0;
    //m_num2 = 0;
    //m_num3 = 0;
}


void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
    //DDX_Text(pDX, IDC_EDIT1, m_num1);
    ////DDV_MinMaxInt(pDX, m_num1, 0, 100);
    //DDX_Text(pDX, IDC_EDIT2, m_num2);
    ////DDV_MinMaxInt(pDX, m_num2, 0, 100);
    //DDX_Text(pDX, IDC_EDIT3, m_num3);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	ON_BN_CLICKED(IDC_NUMBER1, OnNumber1)
	ON_BN_CLICKED(IDC_BTN_SHRINK, OnBtnShrink)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

//WNDPROC prevProc; 
//LRESULT CALLBACK NewEditProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//    if(uMsg == WM_CHAR && wParam == VK_RETURN)
//    {
//        //HWND hNext = GetNextWindow(hWnd, GW_HWNDNEXT); 
//        //HWND hNext = GetWindow(hWnd, GW_HWNDNEXT); 
//        HWND hNext = GetNextDlgTabItem(GetParent(hWnd), hWnd, FALSE); 
//        ::SetFocus(hNext); 
//        return 1; 
//    }
//    else 
//        return prevProc(hWnd, uMsg, wParam, lParam); 
//}


BOOL CTestDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    //EnableWindow(FALSE); 
    //::EnableWindow(GetParent()->GetSafeHwnd(), TRUE); 

    //prevProc = (WNDPROC)SetWindowLong(GetDlgItem(IDC_EDIT1)->GetSafeHwnd(), GWL_WNDPROC, (LONG)NewEditProc); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTestDlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	//delete this; 
	CDialog::PostNcDestroy();
}

void CTestDlg::OnOK()
{
    //DestroyWindow(); 
    //CDialog::OnOK();
    //GetDlgItem(IDC_EDIT1)->GetNextWindow()->SetFocus(); 
    //GetFocus()->GetNextWindow()->SetFocus(); 
    //GetFocus()->GetWindow(GW_HWNDNEXT)->SetFocus(); 
    CWnd* pFocus = GetFocus(); 
    GetNextDlgTabItem(pFocus)->SetFocus(); 
}

void CTestDlg::OnCancel()
{
    CDialog::OnCancel();
    //DestroyWindow(); 
}


void CTestDlg::OnBtnAdd() 
{
	// TODO: Add your control notification handler code here
    //if(m_btn.GetSafeHwnd() == NULL)
    //    m_btn.Create("New", BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD, CRect(0, 0, 100, 100), this, 123); 
    //else 
    //    m_btn.DestroyWindow(); 

    //int a = GetDlgItemInt(IDC_EDIT1); 
    //int b = GetDlgItemInt(IDC_EDIT2); 
    //SetDlgItemInt(IDC_EDIT3, a + b); 

    //UpdateData(); 
    //m_num3 = m_num1 + m_num2; 
    //UpdateData(FALSE); 

    //int num1, num2, num3; 
    //char ch1[10], ch2[10], ch3[10]; 
    //m_edit1.GetWindowText(ch1, 10); 
    //m_edit2.GetWindowText(ch2, 10); 
    //num1 = atoi(ch1); 
    //num2 = atoi(ch2); 
    //num3 = num1 + num2; 
    //itoa(num3, ch3, 10); 
    //m_edit3.SetWindowText(ch3); 
    
    //int num1, num2, num3; 
    //char ch1[10], ch2[10], ch3[10]; 
    //::SendMessage(m_edit1.GetSafeHwnd(), WM_GETTEXT, 10, (LPARAM)ch1); 
    //m_edit2.SendMessage(WM_GETTEXT, 10, (LPARAM)ch2); 
    //num1 = atoi(ch1); 
    //num2 = atoi(ch2); 
    //num3 = num1 + num2; 
    //itoa(num3, ch3, 10); 
    //::SendMessage(GetDlgItem(IDC_EDIT3)->GetSafeHwnd(), WM_SETTEXT, 0, (LPARAM)ch3); 

    
    int num1, num2, num3; 
    char ch1[10], ch2[10], ch3[10]; 
    SendDlgItemMessage(IDC_EDIT1, WM_GETTEXT, 10, (LPARAM)ch1); 
    SendDlgItemMessage(IDC_EDIT2, WM_GETTEXT, 10, (LPARAM)ch2); 
    num1 = atoi(ch1); 
    num2 = atoi(ch2); 
    num3 = num1 + num2; 
    itoa(num3, ch3, 10); 
    SendDlgItemMessage(IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)ch3); 
    SendDlgItemMessage(IDC_EDIT3, EM_SETSEL, 0, -1); 
    m_edit3.SetFocus(); 
}

void CTestDlg::OnNumber1() 
{
	// TODO: Add your control notification handler code here
	CString str; 
    GetDlgItemText(IDC_NUMBER1, str); 
    if(str == "Number1:")
        SetDlgItemText(IDC_NUMBER1, "数值1:"); 
    else 
        SetDlgItemText(IDC_NUMBER1, "Number1:"); 
}

void CTestDlg::OnBtnShrink() 
{
	// TODO: Add your control notification handler code here
	BOOL bShrink; 
    CString str; 
    GetDlgItemText(IDC_BTN_SHRINK, str); 
    if(str == "收缩 <<")
    {
        bShrink = TRUE; 
        SetDlgItemText(IDC_BTN_SHRINK, "扩展 >>"); 
    }
    else 
    {
        bShrink = FALSE; 
        SetDlgItemText(IDC_BTN_SHRINK, "收缩 <<"); 
    }

    CRect rect; 
    GetWindowRect(rect); 
    if(bShrink)
    {
        CRect rectSmall; 
        GetDlgItem(IDC_SEPARATOR)->GetWindowRect(rectSmall); 
        rect.right = rectSmall.left; 
        SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(), SWP_NOMOVE | SWP_NOZORDER); //| SWP_NOREDRAW) ; //SWP_DRAWFRAME); 
    }
    else 
    {
        CRect rectLarge; 
        GetDlgItem(IDC_SEPARATOR2)->GetWindowRect(rectLarge); 
        rect.right = rectLarge.left; 
        SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(), SWP_NOMOVE | SWP_NOZORDER ); //| SWP_NOREDRAW); 
    }
}
