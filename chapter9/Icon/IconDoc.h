// IconDoc.h : interface of the CIconDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICONDOC_H__202ACEDF_7B6D_41EA_9F7A_C8D93911653F__INCLUDED_)
#define AFX_ICONDOC_H__202ACEDF_7B6D_41EA_9F7A_C8D93911653F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CIconDoc : public CDocument
{
protected: // create from serialization only
	CIconDoc();
	DECLARE_DYNCREATE(CIconDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIconDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIconDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONDOC_H__202ACEDF_7B6D_41EA_9F7A_C8D93911653F__INCLUDED_)
