// MailslotSrvDoc.h : interface of the CMailslotSrvDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAILSLOTSRVDOC_H__48B373E8_D3B3_45A7_9903_466D843A88C1__INCLUDED_)
#define AFX_MAILSLOTSRVDOC_H__48B373E8_D3B3_45A7_9903_466D843A88C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMailslotSrvDoc : public CDocument
{
protected: // create from serialization only
	CMailslotSrvDoc();
	DECLARE_DYNCREATE(CMailslotSrvDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMailslotSrvDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMailslotSrvDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMailslotSrvDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAILSLOTSRVDOC_H__48B373E8_D3B3_45A7_9903_466D843A88C1__INCLUDED_)
