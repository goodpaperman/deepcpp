// TestSet.cpp : implementation of the CTestSet class
//

#include "stdafx.h"
#include "Test.h"
#include "TestSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestSet implementation

IMPLEMENT_DYNAMIC(CTestSet, CRecordset)

CTestSet::CTestSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTestSet)
	m_book_id = _T("");
	m_book_name = _T("");
	m_author = _T("");
	m_press = _T("");
	m_press_date = 0;
	m_flag_borrow = _T("");
	m_reader_id = _T("");
	m_name = _T("");
	m_id_card = _T("");
	m_maxnum_can_borrow = 0;
	m_flag_borrow2 = 0;
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CTestSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=MS Access Database");
}

CString CTestSet::GetDefaultSQL()
{
	return _T("[book],[reader]");
}

void CTestSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTestSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[book_id]"), m_book_id);
	RFX_Text(pFX, _T("[book_name]"), m_book_name);
	RFX_Text(pFX, _T("[author]"), m_author);
	RFX_Text(pFX, _T("[press]"), m_press);
	RFX_Date(pFX, _T("[press_date]"), m_press_date);
	RFX_Text(pFX, _T("[book].[flag_borrow]"), m_flag_borrow);
	RFX_Text(pFX, _T("[reader_id]"), m_reader_id);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[id_card]"), m_id_card);
	RFX_Long(pFX, _T("[maxnum_can_borrow]"), m_maxnum_can_borrow);
	RFX_Long(pFX, _T("[reader].[flag_borrow]"), m_flag_borrow2);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTestSet diagnostics

#ifdef _DEBUG
void CTestSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTestSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
