// ButtonDoc.h : interface of the CButtonDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUTTONDOC_H__C161798D_F867_4C2B_85E7_3EB1534ADCF3__INCLUDED_)
#define AFX_BUTTONDOC_H__C161798D_F867_4C2B_85E7_3EB1534ADCF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CButtonDoc : public CDocument
{
protected: // create from serialization only
	CButtonDoc();
	DECLARE_DYNCREATE(CButtonDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CButtonDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CButtonDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONDOC_H__C161798D_F867_4C2B_85E7_3EB1534ADCF3__INCLUDED_)
