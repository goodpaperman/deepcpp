// DrawView.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
#include "Draw.h"

#include "DrawDoc.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawView construction/destruction

CDrawView::CDrawView()
{
	// TODO: add construction code here
	m_bDraw = FALSE; 
}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView drawing

void CDrawView::OnDraw(CDC* pDC)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView printing

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawView message handlers

void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox("View Clicked!"); 
	m_bDraw = TRUE; 
	m_ptOrigin = point; 
	m_ptOld = point; 
	CView::OnLButtonDown(nFlags, point);
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    //HDC hDC = ::GetDC(m_hWnd); 
    //MoveToEx(hDC, m_ptOrigin.x, m_ptOrigin.y, NULL); 
    //LineTo(hDC, point.x, point.y); 
    //::ReleaseDC(m_hWnd, hDC); 

    //CDC* pDC = GetDC(); 
    //pDC->MoveTo(m_ptOrigin); 
    //pDC->LineTo(point); 
    //ReleaseDC(pDC); 

    //CClientDC dc(this); 
    //dc.MoveTo(m_ptOrigin); 
    //dc.LineTo(point); 

    //CClientDC dc(GetParent()); 
    //dc.MoveTo(m_ptOrigin); 
    //dc.LineTo(point); 

    //CWindowDC dc(this); 
    //dc.MoveTo(m_ptOrigin); 
    //dc.LineTo(point); 

    //CWindowDC dc(GetParent()); 
    //dc.MoveTo(m_ptOrigin); 
    //dc.LineTo(point); 

    //CWindowDC dc(GetDesktopWindow()); 
    //dc.MoveTo(m_ptOrigin); 
    //dc.LineTo(point); 

    //CClientDC dc(GetDesktopWindow()); 
    //dc.MoveTo(m_ptOrigin); 
    //dc.LineTo(point); 

    //CPen pen(PS_SOLID, 10, RGB(255, 0, 0)); 
    //CClientDC dc(this); 
    //CPen* pOldPen = dc.SelectObject(&pen); 
    //dc.MoveTo(m_ptOrigin); 
    //dc.LineTo(point); 
    //dc.SelectObject(pOldPen); 

    //CPen pen(PS_DASH, 1, RGB(255, 0, 0)); 
    //CClientDC dc(this); 
    //CPen* pOldPen = dc.SelectObject(&pen); 
    //dc.MoveTo(m_ptOrigin); 
    //dc.LineTo(point); 
    //dc.SelectObject(pOldPen); 

    //CBrush brush(RGB(255, 0, 0)); 
    //CClientDC dc(this); 
    //dc.FillRect(CRect(m_ptOrigin, point), &brush); 

    //CBitmap bitmap; 
    //bitmap.LoadBitmap(IDB_DEMO); 
    //CBrush brush(&bitmap); 
    //CClientDC dc(this); 
    //dc.FillRect(CRect(m_ptOrigin, point), &brush); 

    //CClientDC dc(this); 
    //dc.Rectangle(CRect(m_ptOrigin, point)); 

    //CClientDC dc(this); 
    //CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)); 
    //CBrush* pOldBrush = dc.SelectObject(pBrush); 
    //dc.Rectangle(CRect(m_ptOrigin, point)); 
    //dc.SelectObject(pOldBrush); 
	
    //CClientDC dc(this); 
    //CBrush* pOldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH); 
    //dc.Rectangle(CRect(m_ptOrigin, point)); 
    //dc.SelectObject(pOldBrush); 

	m_bDraw = FALSE; 
	CView::OnLButtonUp(nFlags, point);
}

void CDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if(m_bDraw)
	{
		CClientDC dc(this); 
		UINT nMode = dc.SetROP2(R2_MERGEPENNOT); 
		CPen pen(PS_SOLID, 1, RGB(255, 0, 0)); 
		CPen* pOldPen = dc.SelectObject(&pen); 
		dc.MoveTo(m_ptOrigin); 
		dc.LineTo(point); 
		dc.LineTo(m_ptOld); 
		dc.SelectObject(pOldPen); 
		dc.SetROP2(nMode); 
		//m_ptOrigin = point; 
		m_ptOld = point; 
	}

	CView::OnMouseMove(nFlags, point);
}
