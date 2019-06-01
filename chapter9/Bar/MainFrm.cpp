// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Bar.h"

#include "MainFrm.h"
#include "Splash.h"

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
	ON_COMMAND(IDM_TEST, OnTest)
	ON_COMMAND(IDM_VIEW_NEWTOOLBAR, OnViewNewtoolbar)
	ON_UPDATE_COMMAND_UI(IDM_VIEW_NEWTOOLBAR, OnUpdateViewNewtoolbar)
	ON_WM_TIMER()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
    ON_MESSAGE(UM_PROGRESS, OnProgress)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
    IDS_TIMER, 
    IDS_PROGRESS, 
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
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

    if(!m_newToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC)
        || !m_newToolBar.LoadToolBar(IDR_TOOLBAR1))
    {
        TRACE0("Failed to create toolbar\n"); 
        return -1; 
    }

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    m_newToolBar.EnableDocking(CBRS_ALIGN_ANY); 
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
    DockControlBar(&m_newToolBar); 

    ////m_progress.Create(WS_CHILD | WS_VISIBLE, CRect(100, 100, 200, 120), this, 123); 
    //m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_VERTICAL, CRect(100, 100, 120, 200), this, 123); 
    //m_progress.SetPos(50); 

    //SendMessage(UM_PROGRESS); 
    //PostMessage(UM_PROGRESS); 

    m_wndStatusBar.SetPaneInfo(2, IDS_PROGRESS, SBPS_NORMAL, 400); 

    SetTimer(1, 1000, NULL); 
    OnTimer(1); 

    //CTime t = CTime::GetCurrentTime(); 
    //CString str = t.Format("%H:%M:%S"); 
    //CClientDC dc(this); 
    //CSize size = dc.GetTextExtent(str); 

    ////m_wndStatusBar.SetPaneText(1, str); 
    //int nIndex = m_wndStatusBar.CommandToIndex(IDS_TIMER); 
    //m_wndStatusBar.SetPaneInfo(nIndex, IDS_TIMER, SBPS_NORMAL, size.cx); 
    //m_wndStatusBar.SetPaneText(nIndex, str); 

	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);
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
    //MessageBox("test"); 
    KillTimer(1); 
}

void CMainFrame::OnViewNewtoolbar() 
{
	// TODO: Add your command handler code here
    //if(m_newToolBar.IsWindowVisible())
    //    m_newToolBar.ShowWindow(SW_HIDE); 
    //else 
    //    m_newToolBar.ShowWindow(SW_SHOW); 

    //RecalcLayout(); 
    //DockControlBar(&m_newToolBar); 

    ShowControlBar(&m_newToolBar, !m_newToolBar.IsWindowVisible(), FALSE); 
}

void CMainFrame::OnUpdateViewNewtoolbar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_newToolBar.IsWindowVisible()); 
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
    CTime t = CTime::GetCurrentTime(); 
    CString str = t.Format("%H:%M:%S"); 
    CClientDC dc(this); 
    CSize size = dc.GetTextExtent(str); 

    int nIndex = m_wndStatusBar.CommandToIndex(IDS_TIMER); 
    m_wndStatusBar.SetPaneInfo(nIndex, IDS_TIMER, SBPS_NORMAL, size.cx); 
    m_wndStatusBar.SetPaneText(nIndex, str); 

    if(m_progress.GetSafeHwnd())
        m_progress.StepIt(); 

	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnProgress()
{
    CRect rect; 
    m_wndStatusBar.GetItemRect(2, rect); 
    m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH, rect, &m_wndStatusBar, 123); 
    m_progress.SetPos(50); 
}

void CMainFrame::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
    CRect rect; 
    m_wndStatusBar.GetItemRect(2, rect); 
    if(m_progress.GetSafeHwnd() == NULL)
    {
        m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH, rect, &m_wndStatusBar, 123); 
        m_progress.SetRange(0, 60); 
        m_progress.SetStep(1); 
        //m_progress.SetPos(50); 
    }
    else 
        m_progress.MoveWindow(rect); 

	// Do not call CFrameWnd::OnPaint() for painting messages
}
#include "Splash.h"
