// NamedPipeCltView.h : interface of the CNamedPipeCltView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NAMEDPIPECLTVIEW_H__7E3ABF9A_8163_457E_9F7B_20B77ECA8D0C__INCLUDED_)
#define AFX_NAMEDPIPECLTVIEW_H__7E3ABF9A_8163_457E_9F7B_20B77ECA8D0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNamedPipeCltView : public CView
{
protected: // create from serialization only
	CNamedPipeCltView();
	DECLARE_DYNCREATE(CNamedPipeCltView)

// Attributes
public:
	CNamedPipeCltDoc* GetDocument();
    HANDLE hPipe; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedPipeCltView)
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
	virtual ~CNamedPipeCltView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNamedPipeCltView)
	afx_msg void OnPipeConnect();
	afx_msg void OnPipeRead();
	afx_msg void OnPipeWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NamedPipeCltView.cpp
inline CNamedPipeCltDoc* CNamedPipeCltView::GetDocument()
   { return (CNamedPipeCltDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDPIPECLTVIEW_H__7E3ABF9A_8163_457E_9F7B_20B77ECA8D0C__INCLUDED_)
