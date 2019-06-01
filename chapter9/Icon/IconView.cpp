// IconView.cpp : implementation of the CIconView class
//

#include "stdafx.h"
#include "Icon.h"

#include "IconDoc.h"
#include "IconView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIconView

IMPLEMENT_DYNCREATE(CIconView, CView)

BEGIN_MESSAGE_MAP(CIconView, CView)
	//{{AFX_MSG_MAP(CIconView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIconView construction/destruction

CIconView::CIconView()
{
	// TODO: add construction code here

}

CIconView::~CIconView()
{
}

BOOL CIconView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CIconView drawing

void CIconView::OnDraw(CDC* pDC)
{
	CIconDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CIconView printing

BOOL CIconView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIconView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIconView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CIconView diagnostics

#ifdef _DEBUG
void CIconView::AssertValid() const
{
	CView::AssertValid();
}

void CIconView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIconDoc* CIconView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIconDoc)));
	return (CIconDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIconView message handlers
