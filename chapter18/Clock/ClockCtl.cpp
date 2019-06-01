// ClockCtl.cpp : Implementation of the CClockCtrl ActiveX Control class.

#include "stdafx.h"
#include "Clock.h"
#include "ClockCtl.h"
#include "ClockPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CClockCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CClockCtrl, COleControl)
	//{{AFX_MSG_MAP(CClockCtrl)
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CClockCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CClockCtrl)
	DISP_PROPERTY_NOTIFY(CClockCtrl, "Interval", m_interval, OnIntervalChanged, VT_I2)
	DISP_FUNCTION(CClockCtrl, "Hello", Hello, VT_EMPTY, VTS_NONE)
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_FORECOLOR()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CClockCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CClockCtrl, COleControl)
	//{{AFX_EVENT_MAP(CClockCtrl)
	EVENT_CUSTOM("NewMinute", FireNewMinute, VTS_NONE)
	EVENT_STOCK_CLICK()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CClockCtrl, 2)
	PROPPAGEID(CClockPropPage::guid)
    PROPPAGEID(CLSID_CColorPropPage)
END_PROPPAGEIDS(CClockCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CClockCtrl, "CLOCK.ClockCtrl.1",
	0x762d73ca, 0xb8, 0x4f74, 0x89, 0x1, 0xa6, 0x4, 0xdc, 0xd3, 0x5f, 0xbe)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CClockCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DClock =
		{ 0x3e23ebeb, 0xa72, 0x441c, { 0xa5, 0xf, 0x52, 0x8e, 0xd9, 0xb, 0x5c, 0x3 } };
const IID BASED_CODE IID_DClockEvents =
		{ 0xed3c143, 0x8580, 0x4385, { 0xbd, 0x14, 0xb4, 0xe3, 0xe4, 0x31, 0x12, 0x2e } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwClockOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CClockCtrl, IDS_CLOCK, _dwClockOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::CClockCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CClockCtrl

BOOL CClockCtrl::CClockCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_CLOCK,
			IDB_CLOCK,
			afxRegApartmentThreading,
			_dwClockOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::CClockCtrl - Constructor

CClockCtrl::CClockCtrl()
{
	InitializeIIDs(&IID_DClock, &IID_DClockEvents);
    m_interval = 1000; 
	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::~CClockCtrl - Destructor

CClockCtrl::~CClockCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::OnDraw - Drawing function

void CClockCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
    //pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
    //pdc->Ellipse(rcBounds);

    CBrush brush(TranslateColor(GetBackColor())); 
    pdc->FillRect(rcBounds, &brush); 
    pdc->SetTextColor(TranslateColor(GetForeColor())); 
    pdc->SetBkMode(TRANSPARENT); 

    CTime time = CTime::GetCurrentTime(); 
    CString str = time.Format("%H:%M:%S"); 
    pdc->TextOut(0, 0, str); 

    if(time.GetSecond() == 0)
        FireNewMinute(); 
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::DoPropExchange - Persistence support

void CClockCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));    
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
    PX_Short(pPX, "Interval", m_interval, 1000); 
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::OnResetState - Reset control to default state

void CClockCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::AboutBox - Display an "About" box to the user

void CClockCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_CLOCK);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl message handlers

int CClockCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetTimer(1, m_interval, NULL); 
	return 0;
}

void CClockCtrl::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//Invalidate(); 
    if(AmbientUserMode())
        InvalidateControl(); 
	COleControl::OnTimer(nIDEvent);
}

void CClockCtrl::OnIntervalChanged() 
{
	// TODO: Add notification handler code
    if(m_interval < 0 || m_interval > 6000)
        m_interval = 1000; 
    else 
        m_interval = m_interval / 1000 * 1000; 

    KillTimer(1); 
    SetTimer(1, m_interval, NULL); 
	SetModifiedFlag();
    BoundPropertyChanged(0x01); 
}

void CClockCtrl::Hello() 
{
	// TODO: Add your dispatch handler code here
    MessageBox("Hello World!");
}
