// NamedPipeSrvView.h : interface of the CNamedPipeSrvView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NAMEDPIPESRVVIEW_H__8B15838C_35E2_49F4_97AB_E8625C6B4DAF__INCLUDED_)
#define AFX_NAMEDPIPESRVVIEW_H__8B15838C_35E2_49F4_97AB_E8625C6B4DAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNamedPipeSrvView : public CView
{
protected: // create from serialization only
	CNamedPipeSrvView();
	DECLARE_DYNCREATE(CNamedPipeSrvView)

// Attributes
public:
	CNamedPipeSrvDoc* GetDocument();
    HANDLE hPipe; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedPipeSrvView)
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
	virtual ~CNamedPipeSrvView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNamedPipeSrvView)
	afx_msg void OnPipeCreate();
	afx_msg void OnPipeRead();
	afx_msg void OnPipeWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NamedPipeSrvView.cpp
inline CNamedPipeSrvDoc* CNamedPipeSrvView::GetDocument()
   { return (CNamedPipeSrvDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDPIPESRVVIEW_H__8B15838C_35E2_49F4_97AB_E8625C6B4DAF__INCLUDED_)
