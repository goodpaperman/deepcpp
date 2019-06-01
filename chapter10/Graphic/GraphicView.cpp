// GraphicView.cpp : implementation of the CGraphicView class
//

#include "stdafx.h"
#include "Graphic.h"

#include "GraphicDoc.h"
#include "GraphicView.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphicView

IMPLEMENT_DYNCREATE(CGraphicView, CView)

BEGIN_MESSAGE_MAP(CGraphicView, CView)
	//{{AFX_MSG_MAP(CGraphicView)
	ON_COMMAND(IDM_DOT, OnDot)
	ON_COMMAND(IDM_LINE, OnLine)
	ON_COMMAND(IDM_RECTANGLE, OnRectangle)
	ON_COMMAND(IDM_ELLIPSE, OnEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_SETTING, OnSetting)
	ON_COMMAND(IDM_COLOR, OnColor)
	ON_COMMAND(IDM_FONT, OnFont)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphicView construction/destruction

CGraphicView::CGraphicView()
{
	// TODO: add construction code here
    m_nDrawType = 0; 
    m_nLineWidth = 0; 
    m_nLineStyle = 0; 
    m_clr = RGB(255, 0, 0); 
}

CGraphicView::~CGraphicView()
{
}

BOOL CGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGraphicView drawing

void CGraphicView::OnDraw(CDC* pDC)
{
	CGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    if(m_font.GetSafeHandle() != NULL)
    {
        CFont* pOldFont = pDC->SelectObject(&m_font); 
        LOGFONT lfText; 
        m_font.GetLogFont(&lfText); 
        pDC->TextOut(0, 0, lfText.lfFaceName); 
        pDC->SelectObject(pOldFont); 
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
	CView::AssertValid();
}

void CGraphicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicDoc* CGraphicView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicDoc)));
	return (CGraphicDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphicView message handlers

void CGraphicView::OnDot() 
{
	// TODO: Add your command handler code here
	m_nDrawType = 1; 
}

void CGraphicView::OnLine() 
{
	// TODO: Add your command handler code here
	m_nDrawType = 2; 
}

void CGraphicView::OnRectangle() 
{
	// TODO: Add your command handler code here
	m_nDrawType = 3; 
}

void CGraphicView::OnEllipse() 
{
	// TODO: Add your command handler code here
	m_nDrawType = 4; 
}

void CGraphicView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptOrigin = point; 

	CView::OnLButtonDown(nFlags, point);
}

void CGraphicView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this); 
    CPen pen(m_nLineStyle, m_nLineWidth, m_clr); 
    dc.SelectObject(&pen); 
    dc.SelectStockObject(NULL_BRUSH); 
    switch(m_nDrawType)
    {
    case 1:
        dc.SetPixel(point, m_clr); 
        break; 
    case 2:
        dc.MoveTo(m_ptOrigin); 
        dc.LineTo(point); 
        break; 
    case 3:
        dc.Rectangle(CRect(m_ptOrigin, point)); 
        break; 
    case 4:
        dc.Ellipse(CRect(m_ptOrigin, point)); 
        break; 
    }

	CView::OnLButtonUp(nFlags, point);
}

void CGraphicView::OnSetting() 
{
	// TODO: Add your command handler code here
	CSettingDlg dlg; 
    dlg.m_clr = m_clr; 
    dlg.m_nLineWidth = m_nLineWidth; 
    dlg.m_nLineStyle = m_nLineStyle; 
    if(dlg.DoModal() == IDOK)
    {
        m_nLineWidth = dlg.m_nLineWidth; 
        m_nLineStyle = dlg.m_nLineStyle; 
    }
}

void CGraphicView::OnColor() 
{
	// TODO: Add your command handler code here
    CColorDialog dlg; 
    dlg.m_cc.rgbResult = m_clr; 
    dlg.m_cc.Flags |= CC_RGBINIT | CC_FULLOPEN; 
    if(dlg.DoModal() == IDOK)
    {
        m_clr = dlg.m_cc.rgbResult; 
        //m_clr = dlg.GetColor(); 
    }

    //COLORREF rgbColor[16]; 
    //CHOOSECOLOR clr; 
    //memset(&clr, 0, sizeof(CHOOSECOLOR)); 
    //clr.lStructSize = sizeof(CHOOSECOLOR); 
    //clr.hwndOwner = m_hWnd;
    //clr.lpCustColors = rgbColor; 
    //::ChooseColor(&clr); 
}

void CGraphicView::OnFont() 
{
	// TODO: Add your command handler code here
    LOGFONT lfText; 
    if(m_font.GetSafeHandle() != NULL)
        m_font.GetLogFont(&lfText); 
    else 
        memset(&lfText, 0, sizeof(LOGFONT)); 

    CFontDialog dlg(&lfText); 
    if(dlg.DoModal() == IDOK) 
    {
        m_font.DeleteObject(); 
        m_font.CreateFontIndirect(dlg.m_cf.lpLogFont); 
        Invalidate(); 
    }

    //CHOOSEFONT font; 
    //memset(&font, 0, sizeof(CHOOSEFONT)); 
    //font.lStructSize = sizeof(CHOOSEFONT); 
    //font.hwndOwner = m_hWnd; 
    //font.hDC = ::GetDC(m_hWnd); 
    //::ChooseFont(&font); 
}

BOOL CGraphicView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CBitmap bitmap; 
    bitmap.LoadBitmap(IDB_BITMAP1); 
    BITMAP bm; 
    bitmap.GetBitmap(&bm); 

    CDC dcCompatible; 
    dcCompatible.CreateCompatibleDC(pDC); 
    dcCompatible.SelectObject(&bitmap); 

    CRect rect; 
    GetClientRect(rect); 
    //pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY); 
    pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY); 

    return TRUE; 
	//return CView::OnEraseBkgnd(pDC);
}
