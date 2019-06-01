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
	ON_COMMAND(IDM_SERIALIZE_OUT, OnSerializeOut)
	ON_COMMAND(IDM_SERIALIZE_IN, OnSerializeIn)
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
}

CGraphicView::~CGraphicView()
{
    //for(int i=0; i<m_ptrArray.GetSize(); i++)
    //{
    //    CGraph* pGraph = (CGraph*)m_ptrArray.GetAt(i); 
    //    delete pGraph; 
    //}

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
    //    pGraph->Draw(pDC); 
    //    //switch(pGraph->m_nDrawType)
    //    //{
    //    //case 0:
    //    //    pDC->SetPixel(pGraph->m_ptEnd, RGB(0, 0, 0)); 
    //    //    break; 
    //    //case 1:
    //    //    pDC->MoveTo(pGraph->m_ptOrigin); 
    //    //    pDC->LineTo(pGraph->m_ptEnd); 
    //    //    break; 
    //    //case 2:
    //    //    pDC->Rectangle(CRect(pGraph->m_ptOrigin, pGraph->m_ptEnd)); 
    //    //    break; 
    //    //case 3:
    //    //    pDC->Ellipse(CRect(pGraph->m_ptOrigin, pGraph->m_ptEnd)); 
    //    //    break; 
    //    //}
    //}

	for(int i=0; i<pDoc->m_obArray.GetSize(); i++)
	{
		CGraph* pGraph = (CGraph*)pDoc->m_obArray.GetAt(i); 
		pGraph->Draw(pDC); 
	}
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
	CGraphicDoc* pDoc = GetDocument(); 
    CGraph* pGraph = new CGraph(m_nDrawType, m_ptOrigin, point); 
    //m_ptrArray.Add(pGraph); 
	pDoc->m_obArray.Add(pGraph); 
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

void CGraphicView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SetScrollSizes(MM_TEXT, CSize(800, 600)); 
}

void CGraphicView::OnSerializeOut() 
{
	// TODO: Add your command handler code here
	CFile file("1.txt", CFile::modeCreate | CFile::modeWrite); 
	CArchive ar(&file, CArchive::store); 
	int i = 4; 
	char ch = 'a'; 
	float f = 1.3f; 
	CString str("http://www.sunxin.org"); 
	ar << i << ch << f << str; 
	ar.Close(); 
}

void CGraphicView::OnSerializeIn() 
{
	// TODO: Add your command handler code here
	CFile file("1.txt", CFile::modeRead); 
	CArchive ar(&file, CArchive::load); 
	int i; 
	char ch; 
	float f; 
	CString str; 
	CString strResult; 
	ar >> i >> ch >> f >> str; 
	strResult.Format("%d, %c, %f, %s", i, ch, f, str); 
	MessageBox(strResult); 
	ar.Close(); 
}
