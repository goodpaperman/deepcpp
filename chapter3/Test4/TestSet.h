// TestSet.h : interface of the CTestSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTSET_H__F74EA20F_D8B5_4DC2_AAD3_C700B4767604__INCLUDED_)
#define AFX_TESTSET_H__F74EA20F_D8B5_4DC2_AAD3_C700B4767604__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTestSet : public CRecordset
{
public:
	CTestSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTestSet)

// Field/Param Data
	//{{AFX_FIELD(CTestSet, CRecordset)
	CString	m_book_id;
	CString	m_book_name;
	CString	m_author;
	CString	m_press;
	CTime	m_press_date;
	CString	m_flag_borrow;
	CString	m_reader_id;
	CString	m_name;
	CString	m_id_card;
	long	m_maxnum_can_borrow;
	long	m_flag_borrow2;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTSET_H__F74EA20F_D8B5_4DC2_AAD3_C700B4767604__INCLUDED_)

