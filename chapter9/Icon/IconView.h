// IconView.h : interface of the CIconView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICONVIEW_H__D3B393AB_EA28_451E_BBBA_4FA367F47002__INCLUDED_)
#define AFX_ICONVIEW_H__D3B393AB_EA28_451E_BBBA_4FA367F47002__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CIconView : public CView
{
protected: // create from serialization only
	CIconView();
	DECLARE_DYNCREATE(CIconView)

// Attributes
public:
	CIconDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconView)
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
	virtual ~CIconView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIconView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in IconView.cpp
inline CIconDoc* CIconView::GetDocument()
   { return (CIconDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONVIEW_H__D3B393AB_EA28_451E_BBBA_4FA367F47002__INCLUDED_)
