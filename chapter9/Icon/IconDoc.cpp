// IconDoc.cpp : implementation of the CIconDoc class
//

#include "stdafx.h"
#include "Icon.h"

#include "IconDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIconDoc

IMPLEMENT_DYNCREATE(CIconDoc, CDocument)

BEGIN_MESSAGE_MAP(CIconDoc, CDocument)
	//{{AFX_MSG_MAP(CIconDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIconDoc construction/destruction

CIconDoc::CIconDoc()
{
	// TODO: add one-time construction code here

}

CIconDoc::~CIconDoc()
{
}

BOOL CIconDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CIconDoc serialization

void CIconDoc::Serialize(CArchive& ar)
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
// CIconDoc diagnostics

#ifdef _DEBUG
void CIconDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIconDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIconDoc commands
