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
