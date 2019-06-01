// PhoneBookDoc.cpp : implementation of the CPhoneBookDoc class
//

#include "stdafx.h"
#include "PhoneBook.h"

#include "PhoneBookDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookDoc

IMPLEMENT_DYNCREATE(CPhoneBookDoc, CDocument)

BEGIN_MESSAGE_MAP(CPhoneBookDoc, CDocument)
	//{{AFX_MSG_MAP(CPhoneBookDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookDoc construction/destruction

CPhoneBookDoc::CPhoneBookDoc()
{
	// TODO: add one-time construction code here

}

CPhoneBookDoc::~CPhoneBookDoc()
{
}

BOOL CPhoneBookDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPhoneBookDoc serialization

void CPhoneBookDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookDoc diagnostics

#ifdef _DEBUG
void CPhoneBookDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPhoneBookDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPhoneBookDoc commands
