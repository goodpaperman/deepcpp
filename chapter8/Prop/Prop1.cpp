// Prop1.cpp : implementation file
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProp1 property page

IMPLEMENT_DYNCREATE(CProp1, CPropertyPage)

CProp1::CProp1() : CPropertyPage(CProp1::IDD)
{
	//{{AFX_DATA_INIT(CProp1)
	m_occupation = -1;
	m_workAdd = _T("");
	//}}AFX_DATA_INIT
}

CProp1::~CProp1()
{
}

void CProp1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProp1)
	DDX_Radio(pDX, IDC_RADIO1, m_occupation);
	DDX_LBString(pDX, IDC_LIST1, m_workAdd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProp1, CPropertyPage)
	//{{AFX_MSG_MAP(CProp1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProp1 message handlers

BOOL CProp1::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	CPropertySheet* pSheet = (CPropertySheet*)GetParent(); 
    pSheet->SetWizardButtons(PSWIZB_NEXT); 
	return CPropertyPage::OnSetActive();
}

LRESULT CProp1::OnWizardNext() 
{
	// TODO: Add your specialized code here and/or call the base class
    UpdateData(); 
	if(m_occupation == -1)
    {
        MessageBox("请选择你的职业!"); 
        return -1; 
    }

    if(m_workAdd == "")
    {
        MessageBox("请选择你的工作地点!"); 
        return -1; 
    }

	return CPropertyPage::OnWizardNext();
}

BOOL CProp1::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST1); 
    if(pList != NULL)
    {
        pList->AddString("北京"); 
        pList->AddString("天津"); 
        pList->AddString("上海"); 
    }

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
