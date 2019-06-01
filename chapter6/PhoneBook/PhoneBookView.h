// PhoneBookView.h : interface of the CPhoneBookView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHONEBOOKVIEW_H__3100D42F_F140_41A0_81DD_B155DA9FF9EC__INCLUDED_)
#define AFX_PHONEBOOKVIEW_H__3100D42F_F140_41A0_81DD_B155DA9FF9EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PhoneBookDoc.h"

class CPhoneBookView : public CView
{
protected: // create from serialization only
	CPhoneBookView();
	DECLARE_DYNCREATE(CPhoneBookView)

// Attributes
public:
	CPhoneBookDoc* GetDocument();
    CMenu m_menu; 
    CString m_strLine; 
    CStringArray m_strArray; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhoneBookView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPhoneBookView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPhoneBookView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	afx_msg void OnPhone1();
	afx_msg void OnPhone2();
	afx_msg void OnPhone3();
	afx_msg void OnPhone4();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PhoneBookView.cpp
inline CPhoneBookDoc* CPhoneBookView::GetDocument()
   { return (CPhoneBookDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHONEBOOKVIEW_H__3100D42F_F140_41A0_81DD_B155DA9FF9EC__INCLUDED_)
