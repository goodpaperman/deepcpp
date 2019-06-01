// TestBtn.cpp : implementation file
//

#include "stdafx.h"
#include "Graphic.h"
#include "TestBtn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestBtn

CTestBtn::CTestBtn()
{
}

CTestBtn::~CTestBtn()
{
}


BEGIN_MESSAGE_MAP(CTestBtn, CButton)
	//{{AFX_MSG_MAP(CTestBtn)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestBtn message handlers

void CTestBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	UINT uStyle = DFCS_BUTTONPUSH; 
    if(lpDrawItemStruct->itemState & ODS_SELECTED)
        uStyle |= DFCS_PUSHED; 

    HBRUSH hbrBk = CreateSolidBrush(RGB(0, 255, 0)); 
    HBRUSH hbrOld = (HBRUSH)::SelectObject(lpDrawItemStruct->hDC, hbrBk); 
    ::DrawFrameControl(lpDrawItemStruct->hDC, &lpDrawItemStruct->rcItem, DFC_BUTTON, uStyle); 
    ::SelectObject(lpDrawItemStruct->hDC, hbrOld); 
    

    CString strText; 
    GetWindowText(strText);     
    COLORREF clrBk = ::SetBkColor(lpDrawItemStruct->hDC, RGB(0, 0, 255)); 
    COLORREF crOldColor = ::SetTextColor(lpDrawItemStruct->hDC, RGB(255, 0, 0)); 
    ::DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(), 
        &lpDrawItemStruct->rcItem, DT_SINGLELINE | DT_CENTER | DT_VCENTER); 
    ::SetTextColor(lpDrawItemStruct->hDC, crOldColor); 
    ::SetBkColor(lpDrawItemStruct->hDC, clrBk); 
}
