// PhoneBookView.cpp : implementation of the CPhoneBookView class
//

#include "stdafx.h"
#include "PhoneBook.h"
#include "PhoneBookView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookView

IMPLEMENT_DYNCREATE(CPhoneBookView, CView)

BEGIN_MESSAGE_MAP(CPhoneBookView, CView)
	//{{AFX_MSG_MAP(CPhoneBookView)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(IDM_PHONE1, OnPhone1)
	ON_COMMAND(IDM_PHONE2, OnPhone2)
	ON_COMMAND(IDM_PHONE3, OnPhone3)
	ON_COMMAND(IDM_PHONE4, OnPhone4)
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookView construction/destruction

CPhoneBookView::CPhoneBookView()
{
	// TODO: add construction code here
    m_strLine = ""; 
}

CPhoneBookView::~CPhoneBookView()
{
}

BOOL CPhoneBookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookView drawing

void CPhoneBookView::OnDraw(CDC* pDC)
{
	CPhoneBookDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    pDC->TextOut(10, 10, m_strLine); 
}

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookView printing

BOOL CPhoneBookView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPhoneBookView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPhoneBookView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookView diagnostics

#ifdef _DEBUG
void CPhoneBookView::AssertValid() const
{
	CView::AssertValid();
}

void CPhoneBookView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPhoneBookDoc* CPhoneBookView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPhoneBookDoc)));
	return (CPhoneBookDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookView message handlers

void CPhoneBookView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
    static int nIndex = 0; 
	if(nChar == VK_RETURN)
    {
        if(m_menu.GetSafeHmenu() == NULL)
        {
            m_menu.CreatePopupMenu(); 
            GetParent()->GetMenu()->AppendMenu(MF_POPUP, (UINT)m_menu.m_hMenu, "Phone Book"); 
            GetParent()->DrawMenuBar(); 
        }

        int nPos = m_strLine.Find(' '); 
        if(nPos >= 0)
        {
            CString strName = m_strLine.Left(m_strLine.Find(' ')); 
            CString strNum = m_strLine.Right(m_strLine.GetLength() - nPos - 1); 
            if(!strName.IsEmpty())
            {
                m_menu.AppendMenu(MF_STRING, IDM_PHONE1 + nIndex++, strName); 
                m_strArray.Add(m_strLine); 
            }
        }
        m_strLine = ""; 
    }
    else 
    {
        m_strLine += nChar; 
    }
    
    Invalidate(); 
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CPhoneBookView::OnPhone1() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this); 
    dc.TextOut(200, 100, m_strArray.GetAt(0));
}

void CPhoneBookView::OnPhone2() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this); 
    dc.TextOut(200, 100, m_strArray.GetAt(1));
}

void CPhoneBookView::OnPhone3() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this); 
    dc.TextOut(200, 100, m_strArray.GetAt(2));
}

void CPhoneBookView::OnPhone4() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this); 
    dc.TextOut(200, 100, m_strArray.GetAt(3));
}
