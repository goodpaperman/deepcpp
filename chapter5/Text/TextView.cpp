// TextView.cpp : implementation of the CTextView class
//

#include "stdafx.h"
#include "Text.h"

#include "TextDoc.h"
#include "TextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextView

IMPLEMENT_DYNCREATE(CTextView, CView)

BEGIN_MESSAGE_MAP(CTextView, CView)
	//{{AFX_MSG_MAP(CTextView)
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextView construction/destruction

CTextView::CTextView()
{
	// TODO: add construction code here
	m_strLine = ""; 
	m_ptOrigin.x = 0; 
	m_ptOrigin.y = 0; 
	m_nWidth = 0; 
}

CTextView::~CTextView()
{
}

BOOL CTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTextView drawing

void CTextView::OnDraw(CDC* pDC)
{
	CTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    //CString str("VC++ 深入编程"); 
    //pDC->TextOut(50, 50, str); 

    CString str; 
    str.LoadString(IDS_STRINGVC); 
    pDC->TextOut(500, 300, str); 

    //CSize sz = pDC->GetTextExtent(str); 
    //pDC->BeginPath(); 
    //pDC->Rectangle(500, 300, 500 + sz.cx, 300 + sz.cy); 
    //pDC->EndPath(); 
    //pDC->SelectClipPath(RGN_AND); //RGN_DIFF);  

    //for(int i=0; i<1000; i+=10)
    //{
    //    pDC->MoveTo(0, i); 
    //    pDC->LineTo(1000, i); 
    //    pDC->MoveTo(i, 0); 
    //    pDC->LineTo(i, 1000); 
    //}

	//pDC->TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine); 
}

/////////////////////////////////////////////////////////////////////////////
// CTextView printing

BOOL CTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTextView diagnostics

#ifdef _DEBUG
void CTextView::AssertValid() const
{
	CView::AssertValid();
}

void CTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextDoc* CTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextDoc)));
	return (CTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextView message handlers

int CTextView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
    CClientDC dc(this); 
    TEXTMETRIC tm; 
    dc.GetTextMetrics(&tm); 
    CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight); 
    SetCaretPos(CPoint(500, 100)); 
    ShowCaret(); 
	
    //CBitmap bitmap; 
    //bitmap.LoadBitmap(IDB_CARET); 
    //CreateCaret(&bitmap); 
    //SetCaretPos(CPoint(500, 300)); 
    //ShowCaret(); 
    //bitmap.Detach(); 

	SetTimer(1, 100, NULL); 
	return 0;
}

void CTextView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	//Invalidate(); 

	CClientDC dc(this); 	
	CFont font; 
	font.CreatePointFont(300, "华文行楷"); 
	CFont * pOldFont = dc.SelectObject(&font); 

	switch(nChar)
	{
		case VK_RETURN:
		{
			m_strLine.Empty(); 
			TEXTMETRIC tm;
			dc.GetTextMetrics(&tm); 
			m_ptOrigin.y += tm.tmHeight; 
			break; 
		}
		case VK_BACK:
		{
			COLORREF clr = dc.SetTextColor(dc.GetBkColor()); 
			dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine); 
			m_strLine = m_strLine.Left(m_strLine.GetLength() - 1); 
			dc.SetTextColor(clr); 
			break; 
		}
		default:
		{
			m_strLine += nChar; 
			break; 
		}
	}

	dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine); 
	CSize sz = dc.GetTextExtent(m_strLine); 
	SetCaretPos(CPoint(m_ptOrigin.x + sz.cx, m_ptOrigin.y)); 
	dc.SelectObject(pOldFont); 

	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CTextView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCaretPos(point); 
	m_strLine.Empty(); 
	m_ptOrigin = point; 

	CView::OnLButtonDown(nFlags, point);
}

void CTextView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	m_nWidth += 5; 
	CClientDC dc(this); 
	TEXTMETRIC tm; 
	dc.GetTextMetrics(&tm); 
	CRect rect; 
	rect.left = 500; 
	rect.top = 300; 
	rect.right = 500 + m_nWidth; 
	rect.bottom = 300 + tm.tmHeight; 

	dc.SetTextColor(RGB(255, 0, 0)); 
	CString str; 
	str.LoadString(IDS_STRINGVC); 
	dc.DrawText(str, rect, DT_LEFT); 

	rect.top = 400; 
	rect.bottom = 400 + tm.tmHeight; 
	dc.DrawText(str, rect, DT_RIGHT); 

	rect.top = 200; 
	rect.bottom = 200 + tm.tmHeight; 
	dc.DrawText(str, rect, DT_CENTER); 

	CSize size = dc.GetTextExtent(str); 
	if(m_nWidth > size.cx)
	{
		m_nWidth = 0; 
		dc.SetTextColor(RGB(0, 255, 0)); 
		dc.TextOut(500, 300, str); 
	} 

	CView::OnTimer(nIDEvent);
}
 