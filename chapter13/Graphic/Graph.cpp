// Graph.cpp: implementation of the CGraph class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Graphic.h"
#include "Graph.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CGraph, CObject, 1)

CGraph::CGraph()
{
	m_nDrawType = 0; 
	m_ptOrigin = CPoint(0, 0); 
	m_ptEnd = CPoint(0, 0); 
}

CGraph::CGraph(UINT nDrawType, CPoint ptOrigin, CPoint ptEnd)
{
	m_nDrawType = nDrawType; 
	m_ptOrigin = ptOrigin; 
	m_ptEnd = ptEnd; 
}

CGraph::~CGraph()
{

}

void CGraph::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		ar << m_nDrawType << m_ptOrigin << m_ptEnd; 
	}
	else 
	{
		ar >> m_nDrawType >> m_ptOrigin >> m_ptEnd; 
	}
}

void CGraph::Draw(CDC* pDC)
{	
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH); 
    switch(m_nDrawType)
    {
    case 0:
        pDC->SetPixel(m_ptEnd, RGB(0, 0, 0)); 
        break; 
    case 1:
        pDC->MoveTo(m_ptOrigin); 
        pDC->LineTo(m_ptEnd); 
        break; 
    case 2:
        pDC->Rectangle(CRect(m_ptOrigin, m_ptEnd)); 
        break; 
    case 3:
        pDC->Ellipse(CRect(m_ptOrigin, m_ptEnd)); 
        break; 
    }
	pDC->SelectObject(pOldBrush); 
}