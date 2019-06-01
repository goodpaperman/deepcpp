// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Style.h"

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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
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

    //SetWindowLong(m_hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW); 
    //UINT nStyle = GetWindowLong(m_hWnd, GWL_STYLE); 
    //SetWindowLong(m_hWnd, GWL_STYLE, nStyle & ~WS_MAXIMIZEBOX); 
    SetClassLong(m_hWnd, GCL_HICON, (LONG)LoadIcon(NULL, IDI_ERROR)); 
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

    ////cs.lpszName = "http://www.sunxin.org"; 
    ////cs.style &= ~FWS_ADDTOTITLE; 
    //cs.cx = 300;
    //cs.cy = 200; 

    //WNDCLASS wndcls; 
    //wndcls.cbClsExtra = 0; 
    //wndcls.cbWndExtra = 0; 
    //wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); 
    //wndcls.hCursor = LoadCursor(NULL, IDC_HELP); 
    //wndcls.hIcon = LoadIcon(NULL, IDI_ERROR); 
    //wndcls.hInstance = AfxGetInstanceHandle(); 
    //wndcls.lpfnWndProc = ::DefWindowProc; 
    //wndcls.lpszClassName = "sunxin.org"; 
    //wndcls.lpszMenuName = NULL; 
    //wndcls.style = CS_HREDRAW | CS_VREDRAW; 
    //RegisterClass(&wndcls); 
    //cs.lpszClass = "sunxin.org"; 

    //cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0, 0, LoadIcon(NULL, IDI_WARNING)); 
    //cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW); 
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

