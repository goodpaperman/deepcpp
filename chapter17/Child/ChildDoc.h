// ChildDoc.h : interface of the CChildDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDDOC_H__F2008412_37C6_4FE4_B44B_5D280487E98D__INCLUDED_)
#define AFX_CHILDDOC_H__F2008412_37C6_4FE4_B44B_5D280487E98D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChildDoc : public CDocument
{
protected: // create from serialization only
	CChildDoc();
	DECLARE_DYNCREATE(CChildDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChildDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDDOC_H__F2008412_37C6_4FE4_B44B_5D280487E98D__INCLUDED_)
