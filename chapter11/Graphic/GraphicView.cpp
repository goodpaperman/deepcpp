// GraphicView.cpp : implementation of the CGraphicView class
//

#include "stdafx.h"
#include "Graphic.h"

#include "GraphicDoc.h"
#include "GraphicView.h"
#include "Graph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphicView

IMPLEMENT_DYNCREATE(CGraphicView, CScrollView)

BEGIN_MESSAGE_MAP(CGraphicView, CScrollView)
	//{{AFX_MSG_MAP(CGraphicView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_DOT, OnDot)
	ON_COMMAND(IDM_LINE, OnLine)
	ON_COMMAND(IDM_RECT, OnRect)
	ON_COMMAND(IDM_ELLIPSE, OnEllipse)
	ON_WM_PAINT()
    //ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
    //ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphicView construction/destruction

CGraphicView::CGraphicView()
{
	// TODO: add construction code here
	m_nDrawType = 0; 
	//m_dcMetaFile.Create(); 
}

CGraphicView::~CGraphicView()
{
	for(int i=0; i<m_ptrArray.GetSize(); i++)
	{
		CGraph* pGraph = (CGraph*)m_ptrArray.GetAt(i); 
		delete pGraph; 
	}
}

BOOL CGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGraphicView drawing

void CGraphicView::OnDraw(CDC* pDC)
{
	CGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    //pDC->SelectStockObject(NULL_BRUSH); 
    //for(int i=0; i<m_ptrArray.GetSize(); i++)
    //{
    //    CGraph* pGraph = (CGraph*)m_ptrArray.GetAt(i); 
    //    switch(pGraph->m_nDrawType)
    //    {
    //    case 0:
    //        pDC->SetPixel(pGraph->m_ptEnd, RGB(0, 0, 0)); 
    //        break; 
    //    case 1:
    //        pDC->MoveTo(pGraph->m_ptOrigin); 
    //        pDC->LineTo(pGraph->m_ptEnd); 
    //        break; 
    //    case 2:
    //        pDC->Rectangle(CRect(pGraph->m_ptOrigin, pGraph->m_ptEnd)); 
    //        break; 
    //    case 3:
    //        pDC->Ellipse(CRect(pGraph->m_ptOrigin, pGraph->m_ptEnd)); 
    //        break; 
    //    }
    //}

    //HMETAFILE hmetaFile = m_dcMetaFile.Close(); 
    //pDC->PlayMetaFile(hmetaFile); 
    //m_dcMetaFile.Create(); 
    //m_dcMetaFile.PlayMetaFile(hmetaFile); 
    //DeleteMetaFile(hmetaFile); 

	CRect rect; 
	GetClientRect(&rect); 
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &m_dcCompatible, 0, 0, SRCCOPY); 
}

/////////////////////////////////////////////////////////////////////////////
// CGraphicView printing

BOOL CGraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGraphicView diagnostics

#ifdef _DEBUG
void CGraphicView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CGraphicView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CGraphicDoc* CGraphicView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicDoc)));
	return (CGraphicDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphicView message handlers

void CGraphicView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptOrigin = point; 	

	CScrollView::OnLButtonDown(nFlags, point);
}

void CGraphicView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//CGraph graph(m_nDrawType, m_ptOrigin, point); 
	//m_ptrArray.Add(&graph);

    //CGraph* pGraph = new CGraph(m_nDrawType, m_ptOrigin, point); 
    //m_ptrArray.Add(pGraph); 

    //CClientDC dc(this); 
    //OnPrepareDC(&dc); 
    //dc.DPtoLP(&m_ptOrigin); 
    //dc.DPtoLP(&point); 

    //CDC* pDC = &m_dcMetaFile; 
    //pDC->SelectStockObject(NULL_BRUSH); 
    //switch(m_nDrawType)
    //{
    //case 0:
    //    pDC->SetPixel(point, RGB(0, 0, 0)); 
    //    break; 
    //case 1:
    //    pDC->MoveTo(m_ptOrigin); 
    //    pDC->LineTo(point); 
    //    break; 
    //case 2:
    //    pDC->Rectangle(CRect(m_ptOrigin, point)); 
    //    break; 
    //case 3:
    //    pDC->Ellipse(CRect(m_ptOrigin, point)); 
    //    break; 
    //}


	CDC* pDC = &m_dcCompatible; 
    switch(m_nDrawType)
    {
    case 0:
        pDC->SetPixel(point, RGB(0, 0, 0)); 
        break; 
    case 1:
        pDC->MoveTo(m_ptOrigin); 
        pDC->LineTo(point); 
        break; 
    case 2:
        pDC->Rectangle(CRect(m_ptOrigin, point)); 
        break; 
    case 3:
        pDC->Ellipse(CRect(m_ptOrigin, point)); 
        break; 
    }
	Invalidate(); 

	CScrollView::OnLButtonUp(nFlags, point);
}

void CGraphicView::OnDot() 
{
	// TODO: Add your command handler code here
	m_nDrawType = 0; 
}

void CGraphicView::OnLine() 
{
	// TODO: Add your command handler code here
	m_nDrawType = 1; 
}

void CGraphicView::OnRect() 
{
	// TODO: Add your command handler code here
	m_nDrawType = 2; 
}

void CGraphicView::OnEllipse() 
{
	// TODO: Add your command handler code here
	m_nDrawType = 3; 
}

void CGraphicView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	OnPrepareDC(&dc); 
	OnDraw(&dc);
	// Do not call CScrollView::OnPaint() for painting messages
}

void CGraphicView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SetScrollSizes(MM_TEXT, CSize(800, 600)); 

	CRect rect; 
	GetClientRect(rect); 
	CClientDC dc(this); 
	m_dcCompatible.CreateCompatibleDC(&dc); 
	CBitmap bitmap; 
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height()); 
	m_dcCompatible.SelectObject(&bitmap); 
	m_dcCompatible.BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY); 
	m_dcCompatible.SelectStockObject(NULL_BRUSH); 
	//m_dcCompatible.SelectStockObject(WHITE_BRUSH); 
}

void CGraphicView::OnFileOpen()
{
	HMETAFILE hmetaFile = GetMetaFile("meta.wmf"); 
	//HMETAFILE hmetaFile = ::GetEnhMetaFile("meta.wmf"); 
	m_dcMetaFile.PlayMetaFile(hmetaFile); 
	DeleteMetaFile(hmetaFile); 
	Invalidate(); 
}

void CGraphicView::OnFileSave()
{
	HMETAFILE hmetaFile = m_dcMetaFile.Close(); 
	CopyMetaFile(hmetaFile, "meta.wmf"); 
	m_dcMetaFile.Create(); 
	//m_dcMetaFile.PlayMetaFile(hmetaFile); 
	DeleteMetaFile(hmetaFile); 
}
