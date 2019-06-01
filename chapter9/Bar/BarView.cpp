// BarView.cpp : implementation of the CBarView class
//

#include "stdafx.h"
#include "Bar.h"

#include "BarDoc.h"
#include "BarView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBarView

IMPLEMENT_DYNCREATE(CBarView, CView)

BEGIN_MESSAGE_MAP(CBarView, CView)
	//{{AFX_MSG_MAP(CBarView)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBarView construction/destruction

CBarView::CBarView()
{
	// TODO: add construction code here

}

CBarView::~CBarView()
{
}

BOOL CBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBarView drawing

void CBarView::OnDraw(CDC* pDC)
{
	CBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBarView printing

BOOL CBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBarView diagnostics

#ifdef _DEBUG
void CBarView::AssertValid() const
{
	CView::AssertValid();
}

void CBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBarDoc* CBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBarDoc)));
	return (CBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBarView message handlers

void CBarView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str; 
    str.Format("x=%d, y=%d", point.x, point.y); 
    
    //((CMainFrame*)GetParent())->m_wndStatusBar.SetWindowText(str); 
    //((CMainFrame*)GetParent())->SetMessageText(str); 
    //((CMainFrame*)GetParent())->GetMessageBar()->SetWindowText(str); 
    GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowText(str); 

	CView::OnMouseMove(nFlags, point);
}
