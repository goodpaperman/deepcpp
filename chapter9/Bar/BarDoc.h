// BarDoc.h : interface of the CBarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BARDOC_H__54495E84_6575_4505_AE9E_CD092EFC8090__INCLUDED_)
#define AFX_BARDOC_H__54495E84_6575_4505_AE9E_CD092EFC8090__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBarDoc : public CDocument
{
protected: // create from serialization only
	CBarDoc();
	DECLARE_DYNCREATE(CBarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BARDOC_H__54495E84_6575_4505_AE9E_CD092EFC8090__INCLUDED_)
