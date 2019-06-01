// CntrItem.h : interface of the CTestCntrItem class
//

#if !defined(AFX_CNTRITEM_H__45E12B54_AEEB_4AD5_B462_3BE48BECDEB0__INCLUDED_)
#define AFX_CNTRITEM_H__45E12B54_AEEB_4AD5_B462_3BE48BECDEB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTestDoc;
class CTestView;

class CTestCntrItem : public COleClientItem
{
	DECLARE_SERIAL(CTestCntrItem)

// Constructors
public:
	CTestCntrItem(CTestDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CTestDoc* GetDocument()
		{ return (CTestDoc*)COleClientItem::GetDocument(); }
	CTestView* GetActiveView()
		{ return (CTestView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CTestCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__45E12B54_AEEB_4AD5_B462_3BE48BECDEB0__INCLUDED_)
