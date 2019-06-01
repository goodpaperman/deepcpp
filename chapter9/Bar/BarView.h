// BarView.h : interface of the CBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BARVIEW_H__B3A7984E_42F0_4D89_94BB_AB581CDB5FED__INCLUDED_)
#define AFX_BARVIEW_H__B3A7984E_42F0_4D89_94BB_AB581CDB5FED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBarView : public CView
{
protected: // create from serialization only
	CBarView();
	DECLARE_DYNCREATE(CBarView)

// Attributes
public:
	CBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBarView)
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
	virtual ~CBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBarView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BarView.cpp
inline CBarDoc* CBarView::GetDocument()
   { return (CBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BARVIEW_H__B3A7984E_42F0_4D89_94BB_AB581CDB5FED__INCLUDED_)
