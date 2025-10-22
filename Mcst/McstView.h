// McstView.h : interface of the CMcstView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCSTVIEW_H__E06B2DF9_6493_41CA_B6CE_5AF6E4CB5E07__INCLUDED_)
#define AFX_MCSTVIEW_H__E06B2DF9_6493_41CA_B6CE_5AF6E4CB5E07__INCLUDED_

#include "McstDoc.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMcstView : public CView
{
protected: // create from serialization only
	CMcstView();
	DECLARE_DYNCREATE(CMcstView)

// Attributes
public:
	CMcstDoc* GetDocument();

// Operations
public:
	CDC* m_pDC;
	int m_x,m_y,m_t_x,m_t_y;
	int m_flagPoint;
	CPoint m_LBD;
	CBitmap m_bmp;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMcstView)
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
	void DrawEdge();
	void DrawVertex();
	virtual ~CMcstView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMcstView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in McstView.cpp
inline CMcstDoc* CMcstView::GetDocument()
   { return (CMcstDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCSTVIEW_H__E06B2DF9_6493_41CA_B6CE_5AF6E4CB5E07__INCLUDED_)
