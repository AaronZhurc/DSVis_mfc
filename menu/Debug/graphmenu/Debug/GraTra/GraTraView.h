// GraTraView.h : interface of the CGraTraView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRATRAVIEW_H__8863009D_6695_4CC2_9D83_451168312503__INCLUDED_)
#define AFX_GRATRAVIEW_H__8863009D_6695_4CC2_9D83_451168312503__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GlobalParas.h"
#include <math.h>
#include "GraTraDoc.h"

class CGraTraView : public CView
{
protected: // create from serialization only
	CGraTraView();
	DECLARE_DYNCREATE(CGraTraView)

// Attributes
public:
	CGraTraDoc* GetDocument();

// Operations
public:
	CDC* m_pDC;
	int m_x,m_y,m_t_x,m_t_y;
	CPoint m_LBD;
	int m_flagPoint;
	CBitmap m_bmp;
	CDC m_dc;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraTraView)
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
	LRESULT OnReDraw(WPARAM wParam, LPARAM lParam);
	void DrawArc();
	void DrawVertex();
	virtual ~CGraTraView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraTraView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GraTraView.cpp
inline CGraTraDoc* CGraTraView::GetDocument()
   { return (CGraTraDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRATRAVIEW_H__8863009D_6695_4CC2_9D83_451168312503__INCLUDED_)
