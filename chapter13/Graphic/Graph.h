// Graph.h: interface for the CGraph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPH_H__706ECE66_507E_4950_9957_F0496D694D0D__INCLUDED_)
#define AFX_GRAPH_H__706ECE66_507E_4950_9957_F0496D694D0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGraph  : public CObject
{
	DECLARE_SERIAL(CGraph)
public:
	CGraph();
	CGraph(UINT nDrawType, CPoint ptOrigin, CPoint ptEnd); 
	virtual ~CGraph();
	virtual void Serialize(CArchive& ar); 
	void Draw(CDC* pDC); 

public:
	UINT m_nDrawType; 
	CPoint m_ptOrigin; 
	CPoint m_ptEnd; 

};

#endif // !defined(AFX_GRAPH_H__706ECE66_507E_4950_9957_F0496D694D0D__INCLUDED_)
