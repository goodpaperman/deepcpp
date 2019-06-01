// NewButton.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "NewButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewButton

CNewButton::CNewButton()
{
}

CNewButton::~CNewButton()
{
}


BEGIN_MESSAGE_MAP(CNewButton, CButton)
	//{{AFX_MSG_MAP(CNewButton)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewButton message handlers

void CNewButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    //ShowWindow(SW_HIDE); 
    //m_pBtn->ShowWindow(SW_SHOW); 
    CRect rect; 
    GetParent()->GetClientRect(rect); 
    CRect rect2; 
    GetWindowRect(rect2); 
    GetParent()->ScreenToClient(rect2);
    CRect rect3 = rect2; 
    rect3.left = rand() % (rect.Width() - rect2.Width()); 
    rect3.top = rand() % (rect.Height() - rect2.Height()); 
    rect3.right = rect3.left + rect2.Width(); 
    rect3.bottom = rect3.top + rect2.Height(); 
    //ClientToScreen(rect2); 
    MoveWindow(rect3); 
    Invalidate(); 
	CButton::OnMouseMove(nFlags, point);
}
