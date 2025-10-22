// JosephusView.h : interface of the CJosephusView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JOSEPHUSVIEW_H__9E8635D7_49DE_4FE8_BA5D_227A7C29CB6C__INCLUDED_)
#define AFX_JOSEPHUSVIEW_H__9E8635D7_49DE_4FE8_BA5D_227A7C29CB6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "JosephusDoc.h"
#include "GlobalParas.h"
#include <math.h>

class CJosephusView : public CView
{
protected: // create from serialization only
	CJosephusView();
	DECLARE_DYNCREATE(CJosephusView)

// Attributes
public:
	CJosephusDoc* GetDocument();

// Operations
public:
	CDC* m_pDC;
	int m_x,m_y;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJosephusView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawList();
	LRESULT OnReDraw(WPARAM wParam, LPARAM lParam);
	virtual ~CJosephusView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJosephusView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in JosephusView.cpp
inline CJosephusDoc* CJosephusView::GetDocument()
   { return (CJosephusDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOSEPHUSVIEW_H__9E8635D7_49DE_4FE8_BA5D_227A7C29CB6C__INCLUDED_)
