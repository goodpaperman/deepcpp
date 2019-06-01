// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Menu.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, OnUpdateFileNew)
	ON_COMMAND(IDM_SHOW, OnShow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	//m_bAutoMenuEnable = FALSE; 
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

    ////GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED); 
    ////GetMenu()->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW, MF_BYCOMMAND | MF_CHECKED); 

    //CMenu* pMenuFile = GetMenu()->GetSubMenu(0); 
    //pMenuFile->CheckMenuItem(ID_FILE_NEW, MF_BYCOMMAND | MF_CHECKED); 
    //pMenuFile->SetDefaultItem(ID_FILE_OPEN); 
    ////pMenuFile->SetDefaultItem(1, TRUE); 
    //pMenuFile->SetDefaultItem(5, TRUE); 

    ////CString str; 
    ////str.Format("x=%d, y=%d", GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CYMENUCHECK)); 
    ////MessageBox(str); 
    //CBitmap bitmap, bitmap2; 
    //bitmap.LoadBitmap(IDB_CHECK); 
    //bitmap2.LoadBitmap(IDB_UNCHECK); 
    //pMenuFile->SetMenuItemBitmaps(0, MF_BYPOSITION, &bitmap, &bitmap2); 
    //pMenuFile->SetMenuItemBitmaps(1, MF_BYPOSITION, &bitmap, &bitmap2); 
    //bitmap.Detach(); 
    //bitmap2.Detach();
	
	CMenu* pMenuFile = GetMenu()->GetSubMenu(0); 
	pMenuFile->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED); //MF_DISABLED); 

	SetMenu(NULL); 
	CMenu menu; 
	menu.LoadMenu(IDR_MAINFRAME); 
	SetMenu(&menu); 
	menu.Detach(); 
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnTest() 
{
	// TODO: Add your command handler code here
	MessageBox("MainFrame Clicked"); 
}

void CMainFrame::OnUpdateFileNew(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(pCmdUI->m_nID == ID_FILE_NEW)
		pCmdUI->Enable(FALSE); 
}

void CMainFrame::OnShow() 
{
	// TODO: Add your command handler code here
	MessageBox("Main Frame Show"); 
}
