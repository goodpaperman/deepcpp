// MailslotCltDoc.h : interface of the CMailslotCltDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAILSLOTCLTDOC_H__139DB9BD_39FC_4339_BF95_AFC3FE8C51F6__INCLUDED_)
#define AFX_MAILSLOTCLTDOC_H__139DB9BD_39FC_4339_BF95_AFC3FE8C51F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMailslotCltDoc : public CDocument
{
protected: // create from serialization only
	CMailslotCltDoc();
	DECLARE_DYNCREATE(CMailslotCltDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMailslotCltDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMailslotCltDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMailslotCltDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAILSLOTCLTDOC_H__139DB9BD_39FC_4339_BF95_AFC3FE8C51F6__INCLUDED_)
