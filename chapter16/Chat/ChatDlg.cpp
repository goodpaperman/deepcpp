// ChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDlg dialog

CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CChatDlg::~CChatDlg()
{
    if(m_socket != NULL)
        closesocket(m_socket); 
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialog)
	//{{AFX_MSG_MAP(CChatDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	//}}AFX_MSG_MAP
    ON_MESSAGE(UM_SOCK, OnSock)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDlg message handlers

BOOL CChatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	if(!InitSocket())
        return FALSE; 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChatDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CChatDlg::InitSocket()
{
    m_socket = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, 0); 
    if(m_socket == INVALID_SOCKET)
    {
        MessageBox("�����׽���ʧ��!"); 
        return FALSE; 
    }

    SOCKADDR_IN addrSock; 
    addrSock.sin_addr.S_un.S_addr = htonl(INADDR_ANY); 
    addrSock.sin_family = AF_INET; 
    addrSock.sin_port = htons(6000); 
    if(bind(m_socket, (SOCKADDR*)&addrSock, sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
        MessageBox("��ʧ��!"); 
        return FALSE; 
    }

    if(WSAAsyncSelect(m_socket, m_hWnd, UM_SOCK, FD_READ) == SOCKET_ERROR)
    {
        MessageBox("ע�������ȡ�¼�ʧ��!"); 
        return FALSE; 
    }

    return TRUE; 
}

void CChatDlg::OnSock(WPARAM wParam, LPARAM lParam)
{
    switch(LOWORD(lParam))
    {
        case FD_READ:
            WSABUF wsabuf; 
            wsabuf.buf = new char[200]; 
            wsabuf.len = 200; 
            DWORD dwRead; 
            DWORD dwFlag = 0; 
            SOCKADDR_IN addrFrom; 
            int len = sizeof(SOCKADDR); 
            if(WSARecvFrom(m_socket, &wsabuf, 1, &dwRead, &dwFlag, (SOCKADDR*)&addrFrom, &len, NULL, NULL) == SOCKET_ERROR)
            {
                MessageBox("��������ʧ��!"); 
                delete [] wsabuf.buf; 
                return ; 
            }

            CString str; 
            CString strTemp; 
            HOSTENT* pHost = gethostbyaddr((char*)&addrFrom.sin_addr.S_un.S_addr, 4, AF_INET); 
            if(pHost == NULL)
                str.Format("%s says: %s\r\n", inet_ntoa(addrFrom.sin_addr), wsabuf.buf); 
            else 
                str.Format("%s say: %s\r\n", pHost->h_name, wsabuf.buf); 
            //str += "\r\n"; 
            GetDlgItemText(IDC_EDIT_RECV, strTemp); 
            str += strTemp; 
            SetDlgItemText(IDC_EDIT_RECV, str); 
            delete[] wsabuf.buf; 
            break; 
    }
}

void CChatDlg::OnBtnSend() 
{
	// TODO: Add your control notification handler code here
	DWORD dwIP; 
    CString strHostName; 
    GetDlgItemText(IDC_EDIT_HOSTNAME, strHostName); 
    HOSTENT* pHost = gethostbyname(strHostName); 
    if(pHost == NULL)
    {
        CIPAddressCtrl* pCtrl = (CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1); 
        pCtrl->GetAddress(dwIP); 
        dwIP = htonl(dwIP); 
    }
    else 
        dwIP = *((DWORD*)pHost->h_addr_list[0]); 

    SOCKADDR_IN addrTo; 
    addrTo.sin_addr.S_un.S_addr = dwIP; //htonl(dwIP); 
    addrTo.sin_family = AF_INET; 
    addrTo.sin_port = htons(6000); 

    CString strSend; 
    GetDlgItemText(IDC_EDIT_SEND, strSend); 
    SetDlgItemText(IDC_EDIT_SEND, ""); 
    int len = strSend.GetLength(); 
    WSABUF wsabuf; 
    wsabuf.buf = strSend.GetBuffer(len); 
    wsabuf.len = len + 1; 

    DWORD dwSend;     
    if(WSASendTo(m_socket, &wsabuf, 1, &dwSend, 0, (SOCKADDR*)&addrTo, sizeof(SOCKADDR), NULL, NULL) == SOCKET_ERROR)
    {
        MessageBox("��������ʧ��!"); 
        return; 
    }
}
